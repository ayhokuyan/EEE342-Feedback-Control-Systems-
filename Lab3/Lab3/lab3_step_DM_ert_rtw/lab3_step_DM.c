/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab3_step_DM.c
 *
 * Code generated for Simulink model 'lab3_step_DM'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Apr 27 10:52:02 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab3_step_DM.h"
#include "lab3_step_DM_private.h"
#define lab3_step_DM_PinNumber         (8.0)
#define lab3_step_DM_PinNumber_k       (13.0)

/* Block signals (auto storage) */
B_lab3_step_DM_T lab3_step_DM_B;

/* Continuous states */
X_lab3_step_DM_T lab3_step_DM_X;

/* Block states (auto storage) */
DW_lab3_step_DM_T lab3_step_DM_DW;

/* Real-time model */
RT_MODEL_lab3_step_DM_T lab3_step_DM_M_;
RT_MODEL_lab3_step_DM_T *const lab3_step_DM_M = &lab3_step_DM_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lab3_step_DM_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab3_step_DM_step();
  lab3_step_DM_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab3_step_DM_step();
  lab3_step_DM_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void lab3_step_DM_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain1;
  int16_T k;
  uint8_T dataIn;
  real_T rtb_y;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&lab3_step_DM_M->solverInfo,
                          ((lab3_step_DM_M->Timing.clockTick0+1)*
      lab3_step_DM_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab3_step_DM_M)) {
    lab3_step_DM_M->Timing.t[0] = rtsiGetT(&lab3_step_DM_M->solverInfo);
  }

  /* TransportDelay: '<Root>/Time Delay' */
  {
    real_T **uBuffer = (real_T**)&lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = lab3_step_DM_M->Timing.t[0];
    real_T tMinusDelay = simTime - lab3_step_DM_P.TimeDelay_Delay;
    rtb_Gain1 = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      lab3_step_DM_DW.TimeDelay_IWORK.CircularBufSize,
      &lab3_step_DM_DW.TimeDelay_IWORK.Last,
      lab3_step_DM_DW.TimeDelay_IWORK.Tail,
      lab3_step_DM_DW.TimeDelay_IWORK.Head,
      lab3_step_DM_P.TimeDelay_InitOutput,
      1,
      0);
  }

  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  MATLABSystem: '<Root>/Transmit to Computer'
   */
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (lab3_step_DM_DW.obj.inputVarSize.f1[k] != 1UL) {
      for (k = 0; k < 8; k++) {
        lab3_step_DM_DW.obj.inputVarSize.f1[k] = 1UL;
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_y = rt_roundd_snf(rtb_Gain1);
  if (rtIsNaN(rtb_y) || rtIsInf(rtb_y)) {
    rtb_y = 0.0;
  } else {
    rtb_y = fmod(rtb_y, 256.0);
  }

  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Transmit to Computer'
   */
  dataIn = (uint8_T)(rtb_y < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-rtb_y :
                     (int16_T)(uint8_T)rtb_y);
  MW_Serial_write(lab3_step_DM_DW.obj.port, &dataIn, 1.0,
                  lab3_step_DM_DW.obj.dataSizeInBytes);
  if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
    /* S-Function (sfcn_encoder): '<S1>/Encoder' */
    sfcn_encoder_Outputs_wrapper( &lab3_step_DM_B.Encoder,
      &lab3_step_DM_DW.Encoder_DSTATE, &lab3_step_DM_P.Encoder_P1, 1,
      &lab3_step_DM_P.Encoder_P2, 1, &lab3_step_DM_P.Encoder_P3, 1);

    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<S1>/CPR'
     *  Constant: '<S1>/min x sampling freq'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    lab3_step_DM_B.Product = lab3_step_DM_P.minxsamplingfreq_Value * (real_T)
      lab3_step_DM_B.Encoder / lab3_step_DM_P.CPR_Value;

    /* Step: '<Root>/Voltage Source' */
    if (((lab3_step_DM_M->Timing.clockTick1) * 0.01) <
        lab3_step_DM_P.VoltageSource_Time) {
      lab3_step_DM_B.VoltageSource = lab3_step_DM_P.VoltageSource_Y0;
    } else {
      lab3_step_DM_B.VoltageSource = lab3_step_DM_P.VoltageSource_YFinal;
    }

    /* End of Step: '<Root>/Voltage Source' */
  }

  /* Sum: '<Root>/Sum' */
  lab3_step_DM_B.Sum = lab3_step_DM_B.VoltageSource - rtb_Gain1;

  /* TransferFcn: '<Root>/Gc' */
  rtb_Gain1 = 0.0;
  rtb_Gain1 += lab3_step_DM_P.contr_zeros[0] / lab3_step_DM_P.contr_poles[0] *
    lab3_step_DM_B.Sum;
  rtb_Gain1 += (lab3_step_DM_P.contr_zeros[1] / lab3_step_DM_P.contr_poles[0] -
                lab3_step_DM_P.contr_zeros[0] / lab3_step_DM_P.contr_poles[0] *
                (lab3_step_DM_P.contr_poles[1] / lab3_step_DM_P.contr_poles[0]))
    * lab3_step_DM_X.Gc_CSTATE;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Gain1 > lab3_step_DM_P.Saturation_UpperSat) {
    rtb_y = lab3_step_DM_P.Saturation_UpperSat;
  } else if (rtb_Gain1 < lab3_step_DM_P.Saturation_LowerSat) {
    rtb_y = lab3_step_DM_P.Saturation_LowerSat;
  } else {
    rtb_y = rtb_Gain1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1 = lab3_step_DM_P.Gain1_Gain * rtb_y;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (rtb_Gain1 >= lab3_step_DM_P.Switch_Threshold) {
    rtb_y = lab3_step_DM_P.Constant_Value;
  } else {
    rtb_y = lab3_step_DM_P.Constant1_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_y < 256.0) {
    if (rtb_y >= 0.0) {
      dataIn = (uint8_T)rtb_y;
    } else {
      dataIn = 0U;
    }
  } else {
    dataIn = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  MATLABSystem: '<S4>/Digital Output'
   */
  writeDigitalPin((uint8_T)lab3_step_DM_PinNumber_k, dataIn);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Abs: '<S2>/Abs'
   *  Clock: '<S2>/Clock'
   */
  /* MATLAB Function 'DC Motor Plant/Motorpwm/MATLAB Function': '<S5>:1' */
  /* '<S5>:1:3' if c<10 */
  if (lab3_step_DM_M->Timing.t[0] < 10.0) {
    /* '<S5>:1:4' y = u; */
    rtb_y = fabs(rtb_Gain1);
  } else {
    /* '<S5>:1:5' else */
    /* '<S5>:1:6' y=0; */
    rtb_y = 0.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */
  if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
    /* Saturate: '<S2>/Saturation' */
    if (rtb_y > lab3_step_DM_P.Saturation_UpperSat_c) {
      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      rtb_y = lab3_step_DM_P.Saturation_UpperSat_c;
    } else {
      if (rtb_y < lab3_step_DM_P.Saturation_LowerSat_d) {
        /* DataTypeConversion: '<S6>/Data Type Conversion' */
        rtb_y = lab3_step_DM_P.Saturation_LowerSat_d;
      }
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    if (rtb_y < 256.0) {
      if (rtb_y >= 0.0) {
        dataIn = (uint8_T)rtb_y;
      } else {
        dataIn = 0U;
      }
    } else {
      dataIn = MAX_uint8_T;
    }

    /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_analogWrite(lab3_step_DM_P.PWM_pinNumber, dataIn);
  }

  /* Step: '<S2>/Step' */
  if (lab3_step_DM_M->Timing.t[0] < lab3_step_DM_P.Step_Time) {
    rtb_y = lab3_step_DM_P.Step_Y0;
  } else {
    rtb_y = lab3_step_DM_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_y < 256.0) {
    if (rtb_y >= 0.0) {
      dataIn = (uint8_T)rtb_y;
    } else {
      dataIn = 0U;
    }
  } else {
    dataIn = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  MATLABSystem: '<S3>/Digital Output'
   */
  writeDigitalPin((uint8_T)lab3_step_DM_PinNumber, dataIn);
  if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
    /* Update for TransportDelay: '<Root>/Time Delay' */
    {
      real_T **uBuffer = (real_T**)
        &lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = lab3_step_DM_M->Timing.t[0];
      lab3_step_DM_DW.TimeDelay_IWORK.Head =
        ((lab3_step_DM_DW.TimeDelay_IWORK.Head <
          (lab3_step_DM_DW.TimeDelay_IWORK.CircularBufSize-1)) ?
         (lab3_step_DM_DW.TimeDelay_IWORK.Head+1) : 0);
      if (lab3_step_DM_DW.TimeDelay_IWORK.Head ==
          lab3_step_DM_DW.TimeDelay_IWORK.Tail) {
        lab3_step_DM_DW.TimeDelay_IWORK.Tail =
          ((lab3_step_DM_DW.TimeDelay_IWORK.Tail <
            (lab3_step_DM_DW.TimeDelay_IWORK.CircularBufSize-1)) ?
           (lab3_step_DM_DW.TimeDelay_IWORK.Tail+1) : 0);
      }

      (*tBuffer)[lab3_step_DM_DW.TimeDelay_IWORK.Head] = simTime;
      (*uBuffer)[lab3_step_DM_DW.TimeDelay_IWORK.Head] = lab3_step_DM_B.Product;
    }

    if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
      /* S-Function "sfcn_encoder_wrapper" Block: <S1>/Encoder */
      sfcn_encoder_Update_wrapper( &lab3_step_DM_B.Encoder,
        &lab3_step_DM_DW.Encoder_DSTATE, &lab3_step_DM_P.Encoder_P1, 1,
        &lab3_step_DM_P.Encoder_P2, 1, &lab3_step_DM_P.Encoder_P3, 1);
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(lab3_step_DM_M)) {
    rt_ertODEUpdateContinuousStates(&lab3_step_DM_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++lab3_step_DM_M->Timing.clockTick0;
    lab3_step_DM_M->Timing.t[0] = rtsiGetSolverStopTime
      (&lab3_step_DM_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      lab3_step_DM_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void lab3_step_DM_derivatives(void)
{
  XDot_lab3_step_DM_T *_rtXdot;
  _rtXdot = ((XDot_lab3_step_DM_T *) lab3_step_DM_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Gc' */
  _rtXdot->Gc_CSTATE = 0.0;
  _rtXdot->Gc_CSTATE += -lab3_step_DM_P.contr_poles[1] /
    lab3_step_DM_P.contr_poles[0] * lab3_step_DM_X.Gc_CSTATE;
  _rtXdot->Gc_CSTATE += lab3_step_DM_B.Sum;
}

/* Model initialize function */
void lab3_step_DM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab3_step_DM_M, 0,
                sizeof(RT_MODEL_lab3_step_DM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab3_step_DM_M->solverInfo,
                          &lab3_step_DM_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab3_step_DM_M->solverInfo, &rtmGetTPtr(lab3_step_DM_M));
    rtsiSetStepSizePtr(&lab3_step_DM_M->solverInfo,
                       &lab3_step_DM_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab3_step_DM_M->solverInfo, &lab3_step_DM_M->derivs);
    rtsiSetContStatesPtr(&lab3_step_DM_M->solverInfo, (real_T **)
                         &lab3_step_DM_M->contStates);
    rtsiSetNumContStatesPtr(&lab3_step_DM_M->solverInfo,
      &lab3_step_DM_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab3_step_DM_M->solverInfo,
      &lab3_step_DM_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab3_step_DM_M->solverInfo,
      &lab3_step_DM_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab3_step_DM_M->solverInfo,
      &lab3_step_DM_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab3_step_DM_M->solverInfo, (&rtmGetErrorStatus
      (lab3_step_DM_M)));
    rtsiSetRTModelPtr(&lab3_step_DM_M->solverInfo, lab3_step_DM_M);
  }

  rtsiSetSimTimeStep(&lab3_step_DM_M->solverInfo, MAJOR_TIME_STEP);
  lab3_step_DM_M->intgData.y = lab3_step_DM_M->odeY;
  lab3_step_DM_M->intgData.f[0] = lab3_step_DM_M->odeF[0];
  lab3_step_DM_M->intgData.f[1] = lab3_step_DM_M->odeF[1];
  lab3_step_DM_M->intgData.f[2] = lab3_step_DM_M->odeF[2];
  lab3_step_DM_M->contStates = ((X_lab3_step_DM_T *) &lab3_step_DM_X);
  rtsiSetSolverData(&lab3_step_DM_M->solverInfo, (void *)
                    &lab3_step_DM_M->intgData);
  rtsiSetSolverName(&lab3_step_DM_M->solverInfo,"ode3");
  rtmSetTPtr(lab3_step_DM_M, &lab3_step_DM_M->Timing.tArray[0]);
  lab3_step_DM_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &lab3_step_DM_B), 0,
                sizeof(B_lab3_step_DM_T));

  /* states (continuous) */
  {
    (void) memset((void *)&lab3_step_DM_X, 0,
                  sizeof(X_lab3_step_DM_T));
  }

  /* states (dwork) */
  (void) memset((void *)&lab3_step_DM_DW, 0,
                sizeof(DW_lab3_step_DM_T));

  {
    cell_wrap_lab3_step_DM_T varSizes;
    int16_T i;

    /* Start for TransportDelay: '<Root>/Time Delay' */
    {
      real_T *pBuffer = &lab3_step_DM_DW.TimeDelay_RWORK.TUbufferArea[0];
      lab3_step_DM_DW.TimeDelay_IWORK.Tail = 0;
      lab3_step_DM_DW.TimeDelay_IWORK.Head = 0;
      lab3_step_DM_DW.TimeDelay_IWORK.Last = 0;
      lab3_step_DM_DW.TimeDelay_IWORK.CircularBufSize = 128;
      pBuffer[0] = lab3_step_DM_P.TimeDelay_InitOutput;
      pBuffer[128] = lab3_step_DM_M->Timing.t[0];
      lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
      lab3_step_DM_DW.TimeDelay_PWORK.TUbufferPtrs[1] = (void *) &pBuffer[128];
    }

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' */
    lab3_step_DM_DW.obj.isInitialized = 0L;
    lab3_step_DM_DW.obj.isInitialized = 1L;
    varSizes.f1[0] = 1UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    lab3_step_DM_DW.obj.inputVarSize = varSizes;
    lab3_step_DM_DW.obj.port = 0.0;
    lab3_step_DM_DW.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    lab3_step_DM_DW.obj_c.isInitialized = 0L;
    lab3_step_DM_DW.obj_c.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab3_step_DM_PinNumber_k, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(lab3_step_DM_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    lab3_step_DM_DW.obj_k.isInitialized = 0L;
    lab3_step_DM_DW.obj_k.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab3_step_DM_PinNumber, true);

    /* S-Function Block: <S1>/Encoder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          lab3_step_DM_DW.Encoder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for TransferFcn: '<Root>/Gc' */
    lab3_step_DM_X.Gc_CSTATE = 0.0;
  }
}

/* Model terminate function */
void lab3_step_DM_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Transmit to Computer'
   */
  if (lab3_step_DM_DW.obj.isInitialized == 1L) {
    lab3_step_DM_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S4>/Digital Output'
   */
  if (lab3_step_DM_DW.obj_c.isInitialized == 1L) {
    lab3_step_DM_DW.obj_c.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Output' */

  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S3>/Digital Output'
   */
  if (lab3_step_DM_DW.obj_k.isInitialized == 1L) {
    lab3_step_DM_DW.obj_k.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
