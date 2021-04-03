/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab2_step_resp.c
 *
 * Code generated for Simulink model 'lab2_step_resp'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sun Apr 14 10:38:44 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2_step_resp.h"
#include "lab2_step_resp_private.h"
#define lab2_step_resp_PinNumber       (8.0)
#define lab2_step_resp_PinNumber_a     (13.0)

/* Block signals (auto storage) */
BlockIO_lab2_step_resp lab2_step_resp_B;

/* Block states (auto storage) */
D_Work_lab2_step_resp lab2_step_resp_DWork;

/* Real-time model */
RT_MODEL_lab2_step_resp lab2_step_resp_M_;
RT_MODEL_lab2_step_resp *const lab2_step_resp_M = &lab2_step_resp_M_;
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
void lab2_step_resp_step(void)
{
  int16_T k;
  uint8_T dataIn;
  real_T rtb_Gain1_0;
  real_T rtb_Gain1_1;
  boolean_T exitg1;

  /* S-Function (sfcn_encoder): '<S1>/Encoder' */
  sfcn_encoder_Outputs_wrapper( &lab2_step_resp_B.Encoder,
    &lab2_step_resp_DWork.Encoder_DSTATE, &lab2_step_resp_P.Encoder_P1, 1,
    &lab2_step_resp_P.Encoder_P2, 1, &lab2_step_resp_P.Encoder_P3, 1);

  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  MATLABSystem: '<Root>/Transmit to Computer'
   */
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (lab2_step_resp_DWork.obj.inputVarSize.f1[k] != 1UL) {
      for (k = 0; k < 8; k++) {
        lab2_step_resp_DWork.obj.inputVarSize.f1[k] = 1UL;
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<S1>/CPR'
   *  Constant: '<S1>/min x sampling freq'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Product: '<S1>/Product'
   */
  rtb_Gain1_0 = rt_roundd_snf(lab2_step_resp_P.minxsamplingfreq_Value * (real_T)
    lab2_step_resp_B.Encoder / lab2_step_resp_P.CPR_Value);
  if (rtIsNaN(rtb_Gain1_0) || rtIsInf(rtb_Gain1_0)) {
    rtb_Gain1_0 = 0.0;
  } else {
    rtb_Gain1_0 = fmod(rtb_Gain1_0, 256.0);
  }

  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Transmit to Computer'
   */
  dataIn = (uint8_T)(rtb_Gain1_0 < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
                     -rtb_Gain1_0 : (int16_T)(uint8_T)rtb_Gain1_0);
  MW_Serial_write(lab2_step_resp_DWork.obj.port, &dataIn, 1.0,
                  lab2_step_resp_DWork.obj.dataSizeInBytes);

  /* Step: '<Root>/Voltage Source' */
  if (((lab2_step_resp_M->Timing.clockTick1) * 0.01) <
      lab2_step_resp_P.VoltageSource_Time) {
    rtb_Gain1_0 = lab2_step_resp_P.VoltageSource_Y0;
  } else {
    rtb_Gain1_0 = lab2_step_resp_P.VoltageSource_YFinal;
  }

  /* End of Step: '<Root>/Voltage Source' */

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Gain1_0 > lab2_step_resp_P.Saturation_UpperSat) {
    rtb_Gain1_0 = lab2_step_resp_P.Saturation_UpperSat;
  } else {
    if (rtb_Gain1_0 < lab2_step_resp_P.Saturation_LowerSat) {
      rtb_Gain1_0 = lab2_step_resp_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1_0 *= lab2_step_resp_P.Gain1_Gain;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (rtb_Gain1_0 >= lab2_step_resp_P.Switch_Threshold) {
    rtb_Gain1_1 = lab2_step_resp_P.Constant_Value;
  } else {
    rtb_Gain1_1 = lab2_step_resp_P.Constant1_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Gain1_1 < 256.0) {
    if (rtb_Gain1_1 >= 0.0) {
      dataIn = (uint8_T)rtb_Gain1_1;
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
  writeDigitalPin((uint8_T)lab2_step_resp_PinNumber_a, dataIn);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Abs: '<S2>/Abs'
   *  Clock: '<S2>/Clock'
   */
  /* MATLAB Function 'DC Motor Plant/Motorpwm/MATLAB Function': '<S5>:1' */
  /* '<S5>:1:3' if c<10 */
  if (lab2_step_resp_M->Timing.t[0] < 10.0) {
    /* '<S5>:1:4' y = u; */
    rtb_Gain1_0 = fabs(rtb_Gain1_0);
  } else {
    /* '<S5>:1:5' else */
    /* '<S5>:1:6' y=0; */
    rtb_Gain1_0 = 0.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Gain1_0 > lab2_step_resp_P.Saturation_UpperSat_l) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    rtb_Gain1_0 = lab2_step_resp_P.Saturation_UpperSat_l;
  } else {
    if (rtb_Gain1_0 < lab2_step_resp_P.Saturation_LowerSat_g) {
      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      rtb_Gain1_0 = lab2_step_resp_P.Saturation_LowerSat_g;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtb_Gain1_0 < 256.0) {
    if (rtb_Gain1_0 >= 0.0) {
      dataIn = (uint8_T)rtb_Gain1_0;
    } else {
      dataIn = 0U;
    }
  } else {
    dataIn = MAX_uint8_T;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_analogWrite(lab2_step_resp_P.PWM_pinNumber, dataIn);

  /* Step: '<S2>/Step' */
  if (lab2_step_resp_M->Timing.t[0] < lab2_step_resp_P.Step_Time) {
    rtb_Gain1_0 = lab2_step_resp_P.Step_Y0;
  } else {
    rtb_Gain1_0 = lab2_step_resp_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_Gain1_0 < 256.0) {
    if (rtb_Gain1_0 >= 0.0) {
      dataIn = (uint8_T)rtb_Gain1_0;
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
  writeDigitalPin((uint8_T)lab2_step_resp_PinNumber, dataIn);

  /* S-Function "sfcn_encoder_wrapper" Block: <S1>/Encoder */
  sfcn_encoder_Update_wrapper( &lab2_step_resp_B.Encoder,
    &lab2_step_resp_DWork.Encoder_DSTATE, &lab2_step_resp_P.Encoder_P1, 1,
    &lab2_step_resp_P.Encoder_P2, 1, &lab2_step_resp_P.Encoder_P3, 1);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  lab2_step_resp_M->Timing.t[0] =
    (++lab2_step_resp_M->Timing.clockTick0) * lab2_step_resp_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    lab2_step_resp_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void lab2_step_resp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_step_resp_M, 0,
                sizeof(RT_MODEL_lab2_step_resp));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_step_resp_M->solverInfo,
                          &lab2_step_resp_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_step_resp_M->solverInfo, &rtmGetTPtr(lab2_step_resp_M));
    rtsiSetStepSizePtr(&lab2_step_resp_M->solverInfo,
                       &lab2_step_resp_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&lab2_step_resp_M->solverInfo, (&rtmGetErrorStatus
      (lab2_step_resp_M)));
    rtsiSetRTModelPtr(&lab2_step_resp_M->solverInfo, lab2_step_resp_M);
  }

  rtsiSetSimTimeStep(&lab2_step_resp_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&lab2_step_resp_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(lab2_step_resp_M, &lab2_step_resp_M->Timing.tArray[0]);
  lab2_step_resp_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &lab2_step_resp_B), 0,
                sizeof(BlockIO_lab2_step_resp));

  /* states (dwork) */
  (void) memset((void *)&lab2_step_resp_DWork, 0,
                sizeof(D_Work_lab2_step_resp));

  {
    cell_wrap_lab2_step_resp varSizes;
    int16_T i;

    /* Start for MATLABSystem: '<Root>/Transmit to Computer' */
    lab2_step_resp_DWork.obj.isInitialized = 0L;
    lab2_step_resp_DWork.obj.isInitialized = 1L;
    varSizes.f1[0] = 1UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    lab2_step_resp_DWork.obj.inputVarSize = varSizes;
    lab2_step_resp_DWork.obj.port = 0.0;
    lab2_step_resp_DWork.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    lab2_step_resp_DWork.obj_o.isInitialized = 0L;
    lab2_step_resp_DWork.obj_o.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab2_step_resp_PinNumber_a, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(lab2_step_resp_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    lab2_step_resp_DWork.obj_b.isInitialized = 0L;
    lab2_step_resp_DWork.obj_b.isInitialized = 1L;
    digitalIOSetup((uint8_T)lab2_step_resp_PinNumber, true);

    /* S-Function Block: <S1>/Encoder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          lab2_step_resp_DWork.Encoder_DSTATE = initVector[0];
        }
      }
    }
  }
}

/* Model terminate function */
void lab2_step_resp_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Transmit to Computer' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Transmit to Computer'
   */
  if (lab2_step_resp_DWork.obj.isInitialized == 1L) {
    lab2_step_resp_DWork.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<Root>/Transmit to Computer' */

  /* Start for MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S4>/Digital Output'
   */
  if (lab2_step_resp_DWork.obj_o.isInitialized == 1L) {
    lab2_step_resp_DWork.obj_o.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Output' */

  /* Start for MATLABSystem: '<S3>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S3>/Digital Output'
   */
  if (lab2_step_resp_DWork.obj_b.isInitialized == 1L) {
    lab2_step_resp_DWork.obj_b.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
