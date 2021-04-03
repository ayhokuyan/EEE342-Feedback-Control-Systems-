/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab_1_position_loop_step.c
 *
 * Code generated for Simulink model 'lab_1_position_loop_step'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Mar 02 11:11:20 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_1_position_loop_step.h"
#include "lab_1_position_loop_step_private.h"
#define lab_1_position_loop_PinNumber_n (13.0)
#define lab_1_position_loop_s_PinNumber (8.0)

/* Block signals (auto storage) */
BlockIO_lab_1_position_loop_ste lab_1_position_loop_step_B;

/* Continuous states */
ContinuousStates_lab_1_position lab_1_position_loop_step_X;

/* Block states (auto storage) */
D_Work_lab_1_position_loop_step lab_1_position_loop_step_DWork;

/* Real-time model */
RT_MODEL_lab_1_position_loop_st lab_1_position_loop_step_M_;
RT_MODEL_lab_1_position_loop_st *const lab_1_position_loop_step_M =
  &lab_1_position_loop_step_M_;

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
  lab_1_position_loop_step_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  lab_1_position_loop_step_step();
  lab_1_position_loop_step_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  lab_1_position_loop_step_step();
  lab_1_position_loop_step_derivatives();

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
void lab_1_position_loop_step_step(void)
{
  /* local block i/o variables */
  real_T rtb_Product1;
  int16_T k;
  uint8_T dataIn;
  real_T rtb_Gain1_p;
  real_T rtb_Gain1_d;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&lab_1_position_loop_step_M->solverInfo,
                          ((lab_1_position_loop_step_M->Timing.clockTick0+1)*
      lab_1_position_loop_step_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab_1_position_loop_step_M)) {
    lab_1_position_loop_step_M->Timing.t[0] = rtsiGetT
      (&lab_1_position_loop_step_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
    /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
     *  MATLABSystem: '<Root>/Transmit to Computer'
     */
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (lab_1_position_loop_step_DWork.obj.inputVarSize.f1[k] != 1UL) {
        for (k = 0; k < 8; k++) {
          lab_1_position_loop_step_DWork.obj.inputVarSize.f1[k] = 1UL;
        }

        exitg1 = true;
      } else {
        k++;
      }
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     */
    rtb_Gain1_p = rt_roundd_snf
      (lab_1_position_loop_step_DWork.DiscreteTimeIntegrator_DSTATE);
    if (rtIsNaN(rtb_Gain1_p) || rtIsInf(rtb_Gain1_p)) {
      rtb_Gain1_p = 0.0;
    } else {
      rtb_Gain1_p = fmod(rtb_Gain1_p, 256.0);
    }

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  MATLABSystem: '<Root>/Transmit to Computer'
     */
    dataIn = (uint8_T)(rtb_Gain1_p < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
                       -rtb_Gain1_p : (int16_T)(uint8_T)rtb_Gain1_p);
    MW_Serial_write(lab_1_position_loop_step_DWork.obj.port, &dataIn, 1.0,
                    lab_1_position_loop_step_DWork.obj.dataSizeInBytes);

    /* S-Function (sfcn_encoder): '<S2>/Encoder' */
    sfcn_encoder_Outputs_wrapper( &lab_1_position_loop_step_B.Encoder,
      &lab_1_position_loop_step_DWork.Encoder_DSTATE,
      &lab_1_position_loop_step_P.Encoder_P1, 1,
      &lab_1_position_loop_step_P.Encoder_P2, 1,
      &lab_1_position_loop_step_P.Encoder_P3, 1);

    /* Step: '<Root>/Voltage Source' */
    if (((lab_1_position_loop_step_M->Timing.clockTick1) * 0.01) <
        lab_1_position_loop_step_P.VoltageSource_Time) {
      rtb_Gain1_p = lab_1_position_loop_step_P.VoltageSource_Y0;
    } else {
      rtb_Gain1_p = lab_1_position_loop_step_P.VoltageSource_YFinal;
    }

    /* End of Step: '<Root>/Voltage Source' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<S2>/CPR'
     *  Constant: '<S2>/min x sampling freq'
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     *  Gain: '<Root>/Cp'
     *  Product: '<S2>/Product'
     *  Sum: '<Root>/Sum1'
     */
    lab_1_position_loop_step_B.Sum = (rtb_Gain1_p -
      lab_1_position_loop_step_DWork.DiscreteTimeIntegrator_DSTATE) *
      lab_1_position_loop_step_P.Cp_Gain -
      lab_1_position_loop_step_P.minxsamplingfreq_Value * (real_T)
      lab_1_position_loop_step_B.Encoder / lab_1_position_loop_step_P.CPR_Value;

    /* Signum: '<S1>/Sign' */
    if (lab_1_position_loop_step_B.Sum < 0.0) {
      rtb_Gain1_p = -1.0;
    } else if (lab_1_position_loop_step_B.Sum > 0.0) {
      rtb_Gain1_p = 1.0;
    } else if (lab_1_position_loop_step_B.Sum == 0.0) {
      rtb_Gain1_p = 0.0;
    } else {
      rtb_Gain1_p = lab_1_position_loop_step_B.Sum;
    }

    /* End of Signum: '<S1>/Sign' */

    /* Sum: '<S1>/Sum' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain1'
     */
    lab_1_position_loop_step_B.Sum_n =
      lab_1_position_loop_step_P.CoulombFriction_offset * rtb_Gain1_p +
      lab_1_position_loop_step_P.CoulombFriction_gain *
      lab_1_position_loop_step_B.Sum;

    /* Product: '<S2>/Product1' incorporates:
     *  Constant: '<S2>/CPR'
     *  Constant: '<S2>/deg x sampling freq'
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    rtb_Product1 = (real_T)lab_1_position_loop_step_B.Encoder *
      lab_1_position_loop_step_P.degxsamplingfreq_Value /
      lab_1_position_loop_step_P.CPR_Value;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  TransferFcn: '<Root>/LPF'
   */
  rtb_Gain1_p = lab_1_position_loop_step_P.LPF_C *
    lab_1_position_loop_step_X.LPF_CSTATE + lab_1_position_loop_step_B.Sum_n;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Gain1_p > lab_1_position_loop_step_P.Saturation_UpperSat) {
    rtb_Gain1_p = lab_1_position_loop_step_P.Saturation_UpperSat;
  } else {
    if (rtb_Gain1_p < lab_1_position_loop_step_P.Saturation_LowerSat) {
      rtb_Gain1_p = lab_1_position_loop_step_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Gain: '<S3>/Gain1' */
  rtb_Gain1_p *= lab_1_position_loop_step_P.Gain1_Gain;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   */
  if (rtb_Gain1_p >= lab_1_position_loop_step_P.Switch_Threshold) {
    rtb_Gain1_d = lab_1_position_loop_step_P.Constant_Value;
  } else {
    rtb_Gain1_d = lab_1_position_loop_step_P.Constant1_Value;
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  if (rtb_Gain1_d < 256.0) {
    if (rtb_Gain1_d >= 0.0) {
      dataIn = (uint8_T)rtb_Gain1_d;
    } else {
      dataIn = 0U;
    }
  } else {
    dataIn = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* Start for MATLABSystem: '<S5>/Digital Output' incorporates:
   *  MATLABSystem: '<S5>/Digital Output'
   */
  writeDigitalPin((uint8_T)lab_1_position_loop_PinNumber_n, dataIn);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Abs: '<S3>/Abs'
   *  Clock: '<S3>/Clock'
   */
  /* MATLAB Function 'DC Motor Plant/Motorpwm/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:3' if c<10 */
  if (lab_1_position_loop_step_M->Timing.t[0] < 10.0) {
    /* '<S6>:1:4' y = u; */
    rtb_Gain1_p = fabs(rtb_Gain1_p);
  } else {
    /* '<S6>:1:5' else */
    /* '<S6>:1:6' y=0; */
    rtb_Gain1_p = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
  if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
    /* Saturate: '<S3>/Saturation' */
    if (rtb_Gain1_p > lab_1_position_loop_step_P.Saturation_UpperSat_l) {
      /* DataTypeConversion: '<S7>/Data Type Conversion' */
      rtb_Gain1_p = lab_1_position_loop_step_P.Saturation_UpperSat_l;
    } else {
      if (rtb_Gain1_p < lab_1_position_loop_step_P.Saturation_LowerSat_g) {
        /* DataTypeConversion: '<S7>/Data Type Conversion' */
        rtb_Gain1_p = lab_1_position_loop_step_P.Saturation_LowerSat_g;
      }
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    if (rtb_Gain1_p < 256.0) {
      if (rtb_Gain1_p >= 0.0) {
        dataIn = (uint8_T)rtb_Gain1_p;
      } else {
        dataIn = 0U;
      }
    } else {
      dataIn = MAX_uint8_T;
    }

    /* S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
    MW_analogWrite(lab_1_position_loop_step_P.PWM_pinNumber, dataIn);
  }

  /* Step: '<S3>/Step' */
  if (lab_1_position_loop_step_M->Timing.t[0] <
      lab_1_position_loop_step_P.Step_Time) {
    rtb_Gain1_p = lab_1_position_loop_step_P.Step_Y0;
  } else {
    rtb_Gain1_p = lab_1_position_loop_step_P.Step_YFinal;
  }

  /* End of Step: '<S3>/Step' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Gain1_p < 256.0) {
    if (rtb_Gain1_p >= 0.0) {
      dataIn = (uint8_T)rtb_Gain1_p;
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
  writeDigitalPin((uint8_T)lab_1_position_loop_s_PinNumber, dataIn);
  if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
    if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
      lab_1_position_loop_step_DWork.DiscreteTimeIntegrator_DSTATE +=
        lab_1_position_loop_step_P.DiscreteTimeIntegrator_gainval * rtb_Product1;

      /* S-Function "sfcn_encoder_wrapper" Block: <S2>/Encoder */
      sfcn_encoder_Update_wrapper( &lab_1_position_loop_step_B.Encoder,
        &lab_1_position_loop_step_DWork.Encoder_DSTATE,
        &lab_1_position_loop_step_P.Encoder_P1, 1,
        &lab_1_position_loop_step_P.Encoder_P2, 1,
        &lab_1_position_loop_step_P.Encoder_P3, 1);
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(lab_1_position_loop_step_M)) {
    rt_ertODEUpdateContinuousStates(&lab_1_position_loop_step_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++lab_1_position_loop_step_M->Timing.clockTick0;
    lab_1_position_loop_step_M->Timing.t[0] = rtsiGetSolverStopTime
      (&lab_1_position_loop_step_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      lab_1_position_loop_step_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void lab_1_position_loop_step_derivatives(void)
{
  StateDerivatives_lab_1_position *_rtXdot;
  _rtXdot = ((StateDerivatives_lab_1_position *)
             lab_1_position_loop_step_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/LPF' */
  _rtXdot->LPF_CSTATE = 0.0;
  _rtXdot->LPF_CSTATE += lab_1_position_loop_step_P.LPF_A *
    lab_1_position_loop_step_X.LPF_CSTATE;
  _rtXdot->LPF_CSTATE += lab_1_position_loop_step_B.Sum;
}

/* Model initialize function */
void lab_1_position_loop_step_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab_1_position_loop_step_M, 0,
                sizeof(RT_MODEL_lab_1_position_loop_st));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_1_position_loop_step_M->solverInfo,
                          &lab_1_position_loop_step_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_1_position_loop_step_M->solverInfo, &rtmGetTPtr
                (lab_1_position_loop_step_M));
    rtsiSetStepSizePtr(&lab_1_position_loop_step_M->solverInfo,
                       &lab_1_position_loop_step_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab_1_position_loop_step_M->solverInfo,
                 &lab_1_position_loop_step_M->derivs);
    rtsiSetContStatesPtr(&lab_1_position_loop_step_M->solverInfo, (real_T **)
                         &lab_1_position_loop_step_M->contStates);
    rtsiSetNumContStatesPtr(&lab_1_position_loop_step_M->solverInfo,
      &lab_1_position_loop_step_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab_1_position_loop_step_M->solverInfo,
      &lab_1_position_loop_step_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab_1_position_loop_step_M->solverInfo,
      &lab_1_position_loop_step_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab_1_position_loop_step_M->solverInfo,
      &lab_1_position_loop_step_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab_1_position_loop_step_M->solverInfo,
                          (&rtmGetErrorStatus(lab_1_position_loop_step_M)));
    rtsiSetRTModelPtr(&lab_1_position_loop_step_M->solverInfo,
                      lab_1_position_loop_step_M);
  }

  rtsiSetSimTimeStep(&lab_1_position_loop_step_M->solverInfo, MAJOR_TIME_STEP);
  lab_1_position_loop_step_M->intgData.y = lab_1_position_loop_step_M->odeY;
  lab_1_position_loop_step_M->intgData.f[0] = lab_1_position_loop_step_M->odeF[0];
  lab_1_position_loop_step_M->intgData.f[1] = lab_1_position_loop_step_M->odeF[1];
  lab_1_position_loop_step_M->intgData.f[2] = lab_1_position_loop_step_M->odeF[2];
  lab_1_position_loop_step_M->contStates = ((ContinuousStates_lab_1_position *)
    &lab_1_position_loop_step_X);
  rtsiSetSolverData(&lab_1_position_loop_step_M->solverInfo, (void *)
                    &lab_1_position_loop_step_M->intgData);
  rtsiSetSolverName(&lab_1_position_loop_step_M->solverInfo,"ode3");
  rtmSetTPtr(lab_1_position_loop_step_M,
             &lab_1_position_loop_step_M->Timing.tArray[0]);
  lab_1_position_loop_step_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &lab_1_position_loop_step_B), 0,
                sizeof(BlockIO_lab_1_position_loop_ste));

  /* states (continuous) */
  {
    (void) memset((void *)&lab_1_position_loop_step_X, 0,
                  sizeof(ContinuousStates_lab_1_position));
  }

  /* states (dwork) */
  (void) memset((void *)&lab_1_position_loop_step_DWork, 0,
                sizeof(D_Work_lab_1_position_loop_step));

  {
    cell_wrap_lab_1_position_loop_s varSizes;
    int16_T i;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' */
    lab_1_position_loop_step_DWork.obj.isInitialized = 0L;
    lab_1_position_loop_step_DWork.obj.isInitialized = 1L;
    varSizes.f1[0] = 1UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    lab_1_position_loop_step_DWork.obj.inputVarSize = varSizes;
    lab_1_position_loop_step_DWork.obj.port = 0.0;
    lab_1_position_loop_step_DWork.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    lab_1_position_loop_step_DWork.obj_o.isInitialized = 0L;
    lab_1_position_loop_step_DWork.obj_o.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab_1_position_loop_PinNumber_n, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
    MW_pinModeOutput(lab_1_position_loop_step_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    lab_1_position_loop_step_DWork.obj_b.isInitialized = 0L;
    lab_1_position_loop_step_DWork.obj_b.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab_1_position_loop_s_PinNumber, true);

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    lab_1_position_loop_step_DWork.DiscreteTimeIntegrator_DSTATE =
      lab_1_position_loop_step_P.DiscreteTimeIntegrator_IC;

    /* S-Function Block: <S2>/Encoder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          lab_1_position_loop_step_DWork.Encoder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for TransferFcn: '<Root>/LPF' */
    lab_1_position_loop_step_X.LPF_CSTATE = 0.0;
  }
}

/* Model terminate function */
void lab_1_position_loop_step_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Transmit to Computer'
   */
  if (lab_1_position_loop_step_DWork.obj.isInitialized == 1L) {
    lab_1_position_loop_step_DWork.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

  /* Start for MATLABSystem: '<S5>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S5>/Digital Output'
   */
  if (lab_1_position_loop_step_DWork.obj_o.isInitialized == 1L) {
    lab_1_position_loop_step_DWork.obj_o.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S5>/Digital Output' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S4>/Digital Output'
   */
  if (lab_1_position_loop_step_DWork.obj_b.isInitialized == 1L) {
    lab_1_position_loop_step_DWork.obj_b.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
