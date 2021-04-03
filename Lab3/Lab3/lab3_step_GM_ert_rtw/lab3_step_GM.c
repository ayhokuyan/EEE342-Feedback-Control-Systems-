/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab3_step_GM.c
 *
 * Code generated for Simulink model 'lab3_step_GM'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Apr 27 10:25:58 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab3_step_GM.h"
#include "lab3_step_GM_private.h"
#define lab3_step_GM_PinNumber         (8.0)
#define lab3_step_GM_PinNumber_m       (13.0)

/* Block signals (auto storage) */
BlockIO_lab3_step_GM lab3_step_GM_B;

/* Continuous states */
ContinuousStates_lab3_step_GM lab3_step_GM_X;

/* Block states (auto storage) */
D_Work_lab3_step_GM lab3_step_GM_DWork;

/* Real-time model */
RT_MODEL_lab3_step_GM lab3_step_GM_M_;
RT_MODEL_lab3_step_GM *const lab3_step_GM_M = &lab3_step_GM_M_;

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
  lab3_step_GM_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab3_step_GM_step();
  lab3_step_GM_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab3_step_GM_step();
  lab3_step_GM_derivatives();

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
void lab3_step_GM_step(void)
{
  real_T currentTime;
  int16_T k;
  uint8_T dataIn;
  real_T rtb_Product;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&lab3_step_GM_M->solverInfo,
                          ((lab3_step_GM_M->Timing.clockTick0+1)*
      lab3_step_GM_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab3_step_GM_M)) {
    lab3_step_GM_M->Timing.t[0] = rtsiGetT(&lab3_step_GM_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
    /* S-Function (sfcn_encoder): '<S1>/Encoder' */
    sfcn_encoder_Outputs_wrapper( &lab3_step_GM_B.Encoder,
      &lab3_step_GM_DWork.Encoder_DSTATE, &lab3_step_GM_P.Encoder_P1, 1,
      &lab3_step_GM_P.Encoder_P2, 1, &lab3_step_GM_P.Encoder_P3, 1);

    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<S1>/CPR'
     *  Constant: '<S1>/min x sampling freq'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtb_Product = lab3_step_GM_P.minxsamplingfreq_Value * (real_T)
      lab3_step_GM_B.Encoder / lab3_step_GM_P.CPR_Value;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
     *  MATLABSystem: '<Root>/Transmit to Computer'
     */
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (lab3_step_GM_DWork.obj.inputVarSize.f1[k] != 1UL) {
        for (k = 0; k < 8; k++) {
          lab3_step_GM_DWork.obj.inputVarSize.f1[k] = 1UL;
        }

        exitg1 = true;
      } else {
        k++;
      }
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    currentTime = rt_roundd_snf(rtb_Product);
    if (rtIsNaN(currentTime) || rtIsInf(currentTime)) {
      currentTime = 0.0;
    } else {
      currentTime = fmod(currentTime, 256.0);
    }

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  MATLABSystem: '<Root>/Transmit to Computer'
     */
    dataIn = (uint8_T)(currentTime < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
                       -currentTime : (int16_T)(uint8_T)currentTime);
    MW_Serial_write(lab3_step_GM_DWork.obj.port, &dataIn, 1.0,
                    lab3_step_GM_DWork.obj.dataSizeInBytes);

    /* Step: '<Root>/Voltage Source' */
    currentTime = ((lab3_step_GM_M->Timing.clockTick1) * 0.01);
    if (currentTime < lab3_step_GM_P.VoltageSource_Time) {
      currentTime = lab3_step_GM_P.VoltageSource_Y0;
    } else {
      currentTime = lab3_step_GM_P.VoltageSource_YFinal;
    }

    /* End of Step: '<Root>/Voltage Source' */

    /* Gain: '<Root>/K' incorporates:
     *  Sum: '<Root>/Sum'
     */
    lab3_step_GM_B.K = (currentTime - rtb_Product) * lab3_step_GM_P.K_Gain;
  }

  /* TransferFcn: '<Root>/Gc' */
  currentTime = lab3_step_GM_P.contr_zeros[0] / lab3_step_GM_P.contr_poles[0] *
    (lab3_step_GM_P.contr_poles[1] / lab3_step_GM_P.contr_poles[0]);
  rtb_Product = (lab3_step_GM_P.contr_zeros[1] / lab3_step_GM_P.contr_poles[0] -
                 currentTime) * lab3_step_GM_X.Gc_CSTATE +
    lab3_step_GM_P.contr_zeros[0] / lab3_step_GM_P.contr_poles[0] *
    lab3_step_GM_B.K;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Product > lab3_step_GM_P.Saturation_UpperSat) {
    rtb_Product = lab3_step_GM_P.Saturation_UpperSat;
  } else {
    if (rtb_Product < lab3_step_GM_P.Saturation_LowerSat) {
      rtb_Product = lab3_step_GM_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S2>/Gain1' */
  rtb_Product *= lab3_step_GM_P.Gain1_Gain;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (rtb_Product >= lab3_step_GM_P.Switch_Threshold) {
    currentTime = lab3_step_GM_P.Constant_Value;
  } else {
    currentTime = lab3_step_GM_P.Constant1_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (currentTime < 256.0) {
    if (currentTime >= 0.0) {
      dataIn = (uint8_T)currentTime;
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
  writeDigitalPin((uint8_T)lab3_step_GM_PinNumber_m, dataIn);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Abs: '<S2>/Abs'
   *  Clock: '<S2>/Clock'
   */
  /* MATLAB Function 'DC Motor Plant/Motorpwm/MATLAB Function': '<S5>:1' */
  /* '<S5>:1:3' if c<10 */
  if (lab3_step_GM_M->Timing.t[0] < 10.0) {
    /* '<S5>:1:4' y = u; */
    rtb_Product = fabs(rtb_Product);
  } else {
    /* '<S5>:1:5' else */
    /* '<S5>:1:6' y=0; */
    rtb_Product = 0.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */
  if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
    /* Saturate: '<S2>/Saturation' */
    if (rtb_Product > lab3_step_GM_P.Saturation_UpperSat_l) {
      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      rtb_Product = lab3_step_GM_P.Saturation_UpperSat_l;
    } else {
      if (rtb_Product < lab3_step_GM_P.Saturation_LowerSat_g) {
        /* DataTypeConversion: '<S6>/Data Type Conversion' */
        rtb_Product = lab3_step_GM_P.Saturation_LowerSat_g;
      }
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    if (rtb_Product < 256.0) {
      if (rtb_Product >= 0.0) {
        dataIn = (uint8_T)rtb_Product;
      } else {
        dataIn = 0U;
      }
    } else {
      dataIn = MAX_uint8_T;
    }

    /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_analogWrite(lab3_step_GM_P.PWM_pinNumber, dataIn);
  }

  /* Step: '<S2>/Step' */
  currentTime = lab3_step_GM_M->Timing.t[0];
  if (currentTime < lab3_step_GM_P.Step_Time) {
    currentTime = lab3_step_GM_P.Step_Y0;
  } else {
    currentTime = lab3_step_GM_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (currentTime < 256.0) {
    if (currentTime >= 0.0) {
      dataIn = (uint8_T)currentTime;
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
  writeDigitalPin((uint8_T)lab3_step_GM_PinNumber, dataIn);
  if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
    if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
      /* S-Function "sfcn_encoder_wrapper" Block: <S1>/Encoder */
      sfcn_encoder_Update_wrapper( &lab3_step_GM_B.Encoder,
        &lab3_step_GM_DWork.Encoder_DSTATE, &lab3_step_GM_P.Encoder_P1, 1,
        &lab3_step_GM_P.Encoder_P2, 1, &lab3_step_GM_P.Encoder_P3, 1);
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(lab3_step_GM_M)) {
    rt_ertODEUpdateContinuousStates(&lab3_step_GM_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++lab3_step_GM_M->Timing.clockTick0;
    lab3_step_GM_M->Timing.t[0] = rtsiGetSolverStopTime
      (&lab3_step_GM_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      lab3_step_GM_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void lab3_step_GM_derivatives(void)
{
  StateDerivatives_lab3_step_GM *_rtXdot;
  _rtXdot = ((StateDerivatives_lab3_step_GM *) lab3_step_GM_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Gc' */
  _rtXdot->Gc_CSTATE = 0.0;
  _rtXdot->Gc_CSTATE += -lab3_step_GM_P.contr_poles[1] /
    lab3_step_GM_P.contr_poles[0] * lab3_step_GM_X.Gc_CSTATE;
  _rtXdot->Gc_CSTATE += lab3_step_GM_B.K;
}

/* Model initialize function */
void lab3_step_GM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab3_step_GM_M, 0,
                sizeof(RT_MODEL_lab3_step_GM));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab3_step_GM_M->solverInfo,
                          &lab3_step_GM_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab3_step_GM_M->solverInfo, &rtmGetTPtr(lab3_step_GM_M));
    rtsiSetStepSizePtr(&lab3_step_GM_M->solverInfo,
                       &lab3_step_GM_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab3_step_GM_M->solverInfo, &lab3_step_GM_M->derivs);
    rtsiSetContStatesPtr(&lab3_step_GM_M->solverInfo, (real_T **)
                         &lab3_step_GM_M->contStates);
    rtsiSetNumContStatesPtr(&lab3_step_GM_M->solverInfo,
      &lab3_step_GM_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab3_step_GM_M->solverInfo,
      &lab3_step_GM_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab3_step_GM_M->solverInfo,
      &lab3_step_GM_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab3_step_GM_M->solverInfo,
      &lab3_step_GM_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab3_step_GM_M->solverInfo, (&rtmGetErrorStatus
      (lab3_step_GM_M)));
    rtsiSetRTModelPtr(&lab3_step_GM_M->solverInfo, lab3_step_GM_M);
  }

  rtsiSetSimTimeStep(&lab3_step_GM_M->solverInfo, MAJOR_TIME_STEP);
  lab3_step_GM_M->intgData.y = lab3_step_GM_M->odeY;
  lab3_step_GM_M->intgData.f[0] = lab3_step_GM_M->odeF[0];
  lab3_step_GM_M->intgData.f[1] = lab3_step_GM_M->odeF[1];
  lab3_step_GM_M->intgData.f[2] = lab3_step_GM_M->odeF[2];
  lab3_step_GM_M->contStates = ((ContinuousStates_lab3_step_GM *)
    &lab3_step_GM_X);
  rtsiSetSolverData(&lab3_step_GM_M->solverInfo, (void *)
                    &lab3_step_GM_M->intgData);
  rtsiSetSolverName(&lab3_step_GM_M->solverInfo,"ode3");
  rtmSetTPtr(lab3_step_GM_M, &lab3_step_GM_M->Timing.tArray[0]);
  lab3_step_GM_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &lab3_step_GM_B), 0,
                sizeof(BlockIO_lab3_step_GM));

  /* states (continuous) */
  {
    (void) memset((void *)&lab3_step_GM_X, 0,
                  sizeof(ContinuousStates_lab3_step_GM));
  }

  /* states (dwork) */
  (void) memset((void *)&lab3_step_GM_DWork, 0,
                sizeof(D_Work_lab3_step_GM));

  {
    cell_wrap_lab3_step_GM varSizes;
    int16_T i;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' */
    lab3_step_GM_DWork.obj.isInitialized = 0L;
    lab3_step_GM_DWork.obj.isInitialized = 1L;
    varSizes.f1[0] = 1UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    lab3_step_GM_DWork.obj.inputVarSize = varSizes;
    lab3_step_GM_DWork.obj.port = 0.0;
    lab3_step_GM_DWork.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    lab3_step_GM_DWork.obj_o.isInitialized = 0L;
    lab3_step_GM_DWork.obj_o.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab3_step_GM_PinNumber_m, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(lab3_step_GM_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    lab3_step_GM_DWork.obj_b.isInitialized = 0L;
    lab3_step_GM_DWork.obj_b.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab3_step_GM_PinNumber, true);

    /* S-Function Block: <S1>/Encoder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          lab3_step_GM_DWork.Encoder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for TransferFcn: '<Root>/Gc' */
    lab3_step_GM_X.Gc_CSTATE = 0.0;
  }
}

/* Model terminate function */
void lab3_step_GM_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Transmit to Computer'
   */
  if (lab3_step_GM_DWork.obj.isInitialized == 1L) {
    lab3_step_GM_DWork.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S4>/Digital Output'
   */
  if (lab3_step_GM_DWork.obj_o.isInitialized == 1L) {
    lab3_step_GM_DWork.obj_o.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Output' */

  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S3>/Digital Output'
   */
  if (lab3_step_GM_DWork.obj_b.isInitialized == 1L) {
    lab3_step_GM_DWork.obj_b.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
