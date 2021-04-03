/*
 * lab2_CL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2_CL".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Sun Apr 14 12:06:27 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lab2_CL_h_
#define RTW_HEADER_lab2_CL_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef lab2_CL_COMMON_INCLUDES_
# define lab2_CL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_SerialWrite.h"
#include "MW_digitalio.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* lab2_CL_COMMON_INCLUDES_ */

#include "lab2_CL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum;                          /* '<Root>/Sum' */
  int16_T Encoder;                     /* '<S1>/Encoder' */
  uint8_T DataTypeConversion;          /* '<S6>/Data Type Conversion' */
} B_lab2_CL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Transmit to Computer' */
  real_T Encoder_DSTATE;               /* '<S1>/Encoder' */
  void *DigitalOutput_PWORK;           /* '<S4>/Digital Output' */
  void *DigitalOutput_PWORK_p;         /* '<S3>/Digital Output' */
  void *TransmittoComputer_PWORK;      /* '<Root>/Transmit to Computer' */
  codertarget_arduinobase_block_T obj_c;/* '<S4>/Digital Output' */
  codertarget_arduinobase_block_T obj_k;/* '<S3>/Digital Output' */
  boolean_T objisempty;                /* '<S4>/Digital Output' */
  boolean_T objisempty_m;              /* '<S3>/Digital Output' */
  boolean_T objisempty_e;              /* '<Root>/Transmit to Computer' */
} DW_lab2_CL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Gc_CSTATE;                    /* '<Root>/Gc' */
} X_lab2_CL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Gc_CSTATE;                    /* '<Root>/Gc' */
} XDot_lab2_CL_T;

/* State disabled  */
typedef struct {
  boolean_T Gc_CSTATE;                 /* '<Root>/Gc' */
} XDis_lab2_CL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_lab2_CL_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  real_T minxsamplingfreq_Value;       /* Expression: 6000
                                        * Referenced by: '<S1>/min x sampling freq'
                                        */
  real_T CPR_Value;                    /* Expression: 3200
                                        * Referenced by: '<S1>/CPR'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T VoltageSource_Time;           /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_Y0;             /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_YFinal;         /* Expression: 50
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T Gc_A;                         /* Computed Parameter: Gc_A
                                        * Referenced by: '<Root>/Gc'
                                        */
  real_T Gc_C;                         /* Computed Parameter: Gc_C
                                        * Referenced by: '<Root>/Gc'
                                        */
  real_T Gc_D;                         /* Computed Parameter: Gc_D
                                        * Referenced by: '<Root>/Gc'
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
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 255
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
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
struct tag_RTM_lab2_CL_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_lab2_CL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_lab2_CL_T lab2_CL_P;

/* Block signals (auto storage) */
extern B_lab2_CL_T lab2_CL_B;

/* Continuous states (auto storage) */
extern X_lab2_CL_T lab2_CL_X;

/* Block states (auto storage) */
extern DW_lab2_CL_T lab2_CL_DW;

/* Model entry point functions */
extern void lab2_CL_initialize(void);
extern void lab2_CL_step(void);
extern void lab2_CL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_lab2_CL_T *const lab2_CL_M;

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
 * '<Root>' : 'lab2_CL'
 * '<S1>'   : 'lab2_CL/DC Motor Plant'
 * '<S2>'   : 'lab2_CL/DC Motor Plant/Motorpwm'
 * '<S3>'   : 'lab2_CL/DC Motor Plant/Motorpwm/Brake'
 * '<S4>'   : 'lab2_CL/DC Motor Plant/Motorpwm/Direction '
 * '<S5>'   : 'lab2_CL/DC Motor Plant/Motorpwm/MATLAB Function'
 * '<S6>'   : 'lab2_CL/DC Motor Plant/Motorpwm/PWM'
 * '<S7>'   : 'lab2_CL/DC Motor Plant/Motorpwm/hardlim'
 */
#endif                                 /* RTW_HEADER_lab2_CL_h_ */
