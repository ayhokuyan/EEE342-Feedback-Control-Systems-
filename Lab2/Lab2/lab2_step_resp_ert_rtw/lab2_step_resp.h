/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab2_step_resp.h
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

#ifndef RTW_HEADER_lab2_step_resp_h_
#define RTW_HEADER_lab2_step_resp_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef lab2_step_resp_COMMON_INCLUDES_
# define lab2_step_resp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialWrite.h"
#include "MW_digitalio.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* lab2_step_resp_COMMON_INCLUDES_ */

#include "lab2_step_resp_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  int16_T Encoder;                     /* '<S1>/Encoder' */
} BlockIO_lab2_step_resp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_interna obj; /* '<Root>/Transmit to Computer' */
  real_T Encoder_DSTATE;               /* '<S1>/Encoder' */
  void *DigitalOutput_PWORK;           /* '<S4>/Digital Output' */
  void *DigitalOutput_PWORK_h;         /* '<S3>/Digital Output' */
  void *TransmittoComputer_PWORK;      /* '<Root>/Transmit to Computer' */
  codertarget_arduinobase_blocks_ obj_o;/* '<S4>/Digital Output' */
  codertarget_arduinobase_blocks_ obj_b;/* '<S3>/Digital Output' */
} D_Work_lab2_step_resp;

/* Parameters (auto storage) */
struct Parameters_lab2_step_resp_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T minxsamplingfreq_Value;       /* Expression: 6000
                                        * Referenced by: '<S1>/min x sampling freq'
                                        */
  real_T CPR_Value;                    /* Expression: 3200
                                        * Referenced by: '<S1>/CPR'
                                        */
  real_T VoltageSource_Time;           /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_Y0;             /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_YFinal;         /* Expression: 5
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 255
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  uint8_T Encoder_P1;                  /* Expression: uint8(0)
                                        * Referenced by: '<S1>/Encoder'
                                        */
  uint8_T Encoder_P2;                  /* Expression: uint8(2)
                                        * Referenced by: '<S1>/Encoder'
                                        */
  uint8_T Encoder_P3;                  /* Expression: uint8(3)
                                        * Referenced by: '<S1>/Encoder'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_lab2_step_resp {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_lab2_step_resp lab2_step_resp_P;

/* Block signals (auto storage) */
extern BlockIO_lab2_step_resp lab2_step_resp_B;

/* Block states (auto storage) */
extern D_Work_lab2_step_resp lab2_step_resp_DWork;

/* Model entry point functions */
extern void lab2_step_resp_initialize(void);
extern void lab2_step_resp_step(void);
extern void lab2_step_resp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_lab2_step_resp *const lab2_step_resp_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'lab2_step_resp'
 * '<S1>'   : 'lab2_step_resp/DC Motor Plant'
 * '<S2>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm'
 * '<S3>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm/Brake'
 * '<S4>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm/Direction '
 * '<S5>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm/MATLAB Function'
 * '<S6>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm/PWM'
 * '<S7>'   : 'lab2_step_resp/DC Motor Plant/Motorpwm/hardlim'
 */
#endif                                 /* RTW_HEADER_lab2_step_resp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
