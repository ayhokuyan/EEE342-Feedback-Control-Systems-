/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab2_CL.c
 *
 * Code generated for Simulink model 'lab2_CL'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sun Apr 14 12:14:18 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2_CL.h"
#include "lab2_CL_private.h"
#define lab2_CL_PinNumber              (8.0)
#define lab2_CL_PinNumber_o            (13.0)

/* Block signals (auto storage) */
B_lab2_CL_T lab2_CL_B;

/* Continuous states */
X_lab2_CL_T lab2_CL_X;

/* Block states (auto storage) */
DW_lab2_CL_T lab2_CL_DW;

/* Real-time model */
RT_MODEL_lab2_CL_T lab2_CL_M_;
RT_MODEL_lab2_CL_T *const lab2_CL_M = &lab2_CL_M_;

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
  lab2_CL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab2_CL_step();
  lab2_CL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab2_CL_step();
  lab2_CL_derivatives();

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
void lab2_CL_step(void)
{
  real_T currentTime;
  int16_T k;
  uint8_T dataIn;
  real_T rtb_Product;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(lab2_CL_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&lab2_CL_M->solverInfo,((lab2_CL_M->Timing.clockTick0+
      1)*lab2_CL_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab2_CL_M)) {
    lab2_CL_M->Timing.t[0] = rtsiGetT(&lab2_CL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab2_CL_M)) {
    /* S-Function (sfcn_encoder): '<S1>/Encoder' */
    sfcn_encoder_Outputs_wrapper( &lab2_CL_B.Encoder, &lab2_CL_DW.Encoder_DSTATE,
      &lab2_CL_P.Encoder_P1, 1, &lab2_CL_P.Encoder_P2, 1, &lab2_CL_P.Encoder_P3,
      1);

    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<S1>/CPR'
     *  Constant: '<S1>/min x sampling freq'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtb_Product = lab2_CL_P.minxsamplingfreq_Value * (real_T)lab2_CL_B.Encoder /
      lab2_CL_P.CPR_Value;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
     *  MATLABSystem: '<Root>/Transmit to Computer'
     */
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (lab2_CL_DW.obj.inputVarSize.f1[k] != 1UL) {
        for (k = 0; k < 8; k++) {
          lab2_CL_DW.obj.inputVarSize.f1[k] = 1UL;
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
    MW_Serial_write(lab2_CL_DW.obj.port, &dataIn, 1.0,
                    lab2_CL_DW.obj.dataSizeInBytes);

    /* Step: '<Root>/Voltage Source' */
    currentTime = ((lab2_CL_M->Timing.clockTick1) * 0.01);
    if (currentTime < lab2_CL_P.VoltageSource_Time) {
      currentTime = lab2_CL_P.VoltageSource_Y0;
    } else {
      currentTime = lab2_CL_P.VoltageSource_YFinal;
    }

    /* End of Step: '<Root>/Voltage Source' */

    /* Sum: '<Root>/Sum' */
    lab2_CL_B.Sum = currentTime - rtb_Product;
  }

  /* TransferFcn: '<Root>/Gc' */
  rtb_Product = lab2_CL_P.Gc_C * lab2_CL_X.Gc_CSTATE + lab2_CL_P.Gc_D *
    lab2_CL_B.Sum;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Product > lab2_CL_P.Saturation_UpperSat) {
    rtb_Product = lab2_CL_P.Saturation_UpperSat;
  } else {
    if (rtb_Product < lab2_CL_P.Saturation_LowerSat) {
      rtb_Product = lab2_CL_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S2>/Gain1' */
  rtb_Product *= lab2_CL_P.Gain1_Gain;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (rtb_Product >= lab2_CL_P.Switch_Threshold) {
    currentTime = lab2_CL_P.Constant_Value;
  } else {
    currentTime = lab2_CL_P.Constant1_Value;
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
  writeDigitalPin((uint8_T)lab2_CL_PinNumber_o, dataIn);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Abs: '<S2>/Abs'
   *  Clock: '<S2>/Clock'
   */
  /* MATLAB Function 'DC Motor Plant/Motorpwm/MATLAB Function': '<S5>:1' */
  /* '<S5>:1:3' if c<10 */
  if (lab2_CL_M->Timing.t[0] < 10.0) {
    /* '<S5>:1:4' y = u; */
    rtb_Product = fabs(rtb_Product);
  } else {
    /* '<S5>:1:5' else */
    /* '<S5>:1:6' y=0; */
    rtb_Product = 0.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */
  if (rtmIsMajorTimeStep(lab2_CL_M)) {
    /* Saturate: '<S2>/Saturation' */
    if (rtb_Product > lab2_CL_P.Saturation_UpperSat_c) {
      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      rtb_Product = lab2_CL_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Product < lab2_CL_P.Saturation_LowerSat_d) {
        /* DataTypeConversion: '<S6>/Data Type Conversion' */
        rtb_Product = lab2_CL_P.Saturation_LowerSat_d;
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
    MW_analogWrite(lab2_CL_P.PWM_pinNumber, dataIn);
  }

  /* Step: '<S2>/Step' */
  currentTime = lab2_CL_M->Timing.t[0];
  if (currentTime < lab2_CL_P.Step_Time) {
    currentTime = lab2_CL_P.Step_Y0;
  } else {
    currentTime = lab2_CL_P.Step_YFinal;
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
  writeDigitalPin((uint8_T)lab2_CL_PinNumber, dataIn);
  if (rtmIsMajorTimeStep(lab2_CL_M)) {
    if (rtmIsMajorTimeStep(lab2_CL_M)) {
      /* S-Function "sfcn_encoder_wrapper" Block: <S1>/Encoder */
      sfcn_encoder_Update_wrapper( &lab2_CL_B.Encoder,
        &lab2_CL_DW.Encoder_DSTATE, &lab2_CL_P.Encoder_P1, 1,
        &lab2_CL_P.Encoder_P2, 1, &lab2_CL_P.Encoder_P3, 1);
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(lab2_CL_M)) {
    rt_ertODEUpdateContinuousStates(&lab2_CL_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++lab2_CL_M->Timing.clockTick0;
    lab2_CL_M->Timing.t[0] = rtsiGetSolverStopTime(&lab2_CL_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      lab2_CL_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void lab2_CL_derivatives(void)
{
  XDot_lab2_CL_T *_rtXdot;
  _rtXdot = ((XDot_lab2_CL_T *) lab2_CL_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Gc' */
  _rtXdot->Gc_CSTATE = 0.0;
  _rtXdot->Gc_CSTATE += lab2_CL_P.Gc_A * lab2_CL_X.Gc_CSTATE;
  _rtXdot->Gc_CSTATE += lab2_CL_B.Sum;
}

/* Model initialize function */
void lab2_CL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_CL_M, 0,
                sizeof(RT_MODEL_lab2_CL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_CL_M->solverInfo, &lab2_CL_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_CL_M->solverInfo, &rtmGetTPtr(lab2_CL_M));
    rtsiSetStepSizePtr(&lab2_CL_M->solverInfo, &lab2_CL_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab2_CL_M->solverInfo, &lab2_CL_M->derivs);
    rtsiSetContStatesPtr(&lab2_CL_M->solverInfo, (real_T **)
                         &lab2_CL_M->contStates);
    rtsiSetNumContStatesPtr(&lab2_CL_M->solverInfo,
      &lab2_CL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab2_CL_M->solverInfo,
      &lab2_CL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab2_CL_M->solverInfo,
      &lab2_CL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab2_CL_M->solverInfo,
      &lab2_CL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab2_CL_M->solverInfo, (&rtmGetErrorStatus(lab2_CL_M)));
    rtsiSetRTModelPtr(&lab2_CL_M->solverInfo, lab2_CL_M);
  }

  rtsiSetSimTimeStep(&lab2_CL_M->solverInfo, MAJOR_TIME_STEP);
  lab2_CL_M->intgData.y = lab2_CL_M->odeY;
  lab2_CL_M->intgData.f[0] = lab2_CL_M->odeF[0];
  lab2_CL_M->intgData.f[1] = lab2_CL_M->odeF[1];
  lab2_CL_M->intgData.f[2] = lab2_CL_M->odeF[2];
  lab2_CL_M->contStates = ((X_lab2_CL_T *) &lab2_CL_X);
  rtsiSetSolverData(&lab2_CL_M->solverInfo, (void *)&lab2_CL_M->intgData);
  rtsiSetSolverName(&lab2_CL_M->solverInfo,"ode3");
  rtmSetTPtr(lab2_CL_M, &lab2_CL_M->Timing.tArray[0]);
  lab2_CL_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &lab2_CL_B), 0,
                sizeof(B_lab2_CL_T));

  /* states (continuous) */
  {
    (void) memset((void *)&lab2_CL_X, 0,
                  sizeof(X_lab2_CL_T));
  }

  /* states (dwork) */
  (void) memset((void *)&lab2_CL_DW, 0,
                sizeof(DW_lab2_CL_T));

  {
    cell_wrap_lab2_CL_T varSizes;
    int16_T i;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' */
    lab2_CL_DW.obj.isInitialized = 0L;
    lab2_CL_DW.obj.isInitialized = 1L;
    varSizes.f1[0] = 1UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    lab2_CL_DW.obj.inputVarSize = varSizes;
    lab2_CL_DW.obj.port = 0.0;
    lab2_CL_DW.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    lab2_CL_DW.obj_c.isInitialized = 0L;
    lab2_CL_DW.obj_c.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab2_CL_PinNumber_o, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(lab2_CL_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    lab2_CL_DW.obj_k.isInitialized = 0L;
    lab2_CL_DW.obj_k.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab2_CL_PinNumber, true);

    /* S-Function Block: <S1>/Encoder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          lab2_CL_DW.Encoder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for TransferFcn: '<Root>/Gc' */
    lab2_CL_X.Gc_CSTATE = 0.0;
  }
}

/* Model terminate function */
void lab2_CL_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Transmit to Computer'
   */
  if (lab2_CL_DW.obj.isInitialized == 1L) {
    lab2_CL_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S4>/Digital Output'
   */
  if (lab2_CL_DW.obj_c.isInitialized == 1L) {
    lab2_CL_DW.obj_c.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Output' */

  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S3>/Digital Output'
   */
  if (lab2_CL_DW.obj_k.isInitialized == 1L) {
    lab2_CL_DW.obj_k.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
