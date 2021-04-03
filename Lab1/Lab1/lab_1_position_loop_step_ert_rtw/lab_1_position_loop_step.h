/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab_1_position_loop_step.h
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

#ifndef RTW_HEADER_lab_1_position_loop_step_h_
#define RTW_HEADER_lab_1_position_loop_step_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef lab_1_position_loop_step_COMMON_INCLUDES_
# define lab_1_position_loop_step_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialWrite.h"
#include "MW_digitalio.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* lab_1_position_loop_step_COMMON_INCLUDES_ */

#include "lab_1_position_loop_step_types.h"
#include "MW_target_hardware_resources.h"
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

/* Block signals (auto storage) */
typedef struct {
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Sum_n;                        /* '<S1>/Sum' */
  int16_T Encoder;                     /* '<S2>/Encoder' */
} BlockIO_lab_1_position_loop_ste;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_interna obj; /* '<Root>/Transmit to Computer' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T Encoder_DSTATE;               /* '<S2>/Encoder' */
  void *DigitalOutput_PWORK;           /* '<S5>/Digital Output' */
  void *DigitalOutput_PWORK_h;         /* '<S4>/Digital Output' */
  void *TransmittoComputer_PWORK;      /* '<Root>/Transmit to Computer' */
  codertarget_arduinobase_blocks_ obj_o;/* '<S5>/Digital Output' */
  codertarget_arduinobase_blocks_ obj_b;/* '<S4>/Digital Output' */
} D_Work_lab_1_position_loop_step;

/* Continuous states (auto storage) */
typedef struct {
  real_T LPF_CSTATE;                   /* '<Root>/LPF' */
} ContinuousStates_lab_1_position;

/* State derivatives (auto storage) */
typedef struct {
  real_T LPF_CSTATE;                   /* '<Root>/LPF' */
} StateDerivatives_lab_1_position;

/* State disabled  */
typedef struct {
  boolean_T LPF_CSTATE;                /* '<Root>/LPF' */
} StateDisabled_lab_1_position_lo;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_lab_1_position_loop__ {
  real_T CoulombFriction_gain;         /* Mask Parameter: CoulombFriction_gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T CoulombFriction_offset;       /* Mask Parameter: CoulombFriction_offset
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S7>/PWM'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S2>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T VoltageSource_Time;           /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_Y0;             /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T VoltageSource_YFinal;         /* Expression: 90
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  real_T Cp_Gain;                      /* Expression: 2
                                        * Referenced by: '<Root>/Cp'
                                        */
  real_T minxsamplingfreq_Value;       /* Expression: 6000
                                        * Referenced by: '<S2>/min x sampling freq'
                                        */
  real_T CPR_Value;                    /* Expression: 3200
                                        * Referenced by: '<S2>/CPR'
                                        */
  real_T degxsamplingfreq_Value;       /* Expression: 36000
                                        * Referenced by: '<S2>/deg x sampling freq'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T LPF_A;                        /* Computed Parameter: LPF_A
                                        * Referenced by: '<Root>/LPF'
                                        */
  real_T LPF_C;                        /* Computed Parameter: LPF_C
                                        * Referenced by: '<Root>/LPF'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 255
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  uint8_T Encoder_P1;                  /* Expression: uint8(0)
                                        * Referenced by: '<S2>/Encoder'
                                        */
  uint8_T Encoder_P2;                  /* Expression: uint8(2)
                                        * Referenced by: '<S2>/Encoder'
                                        */
  uint8_T Encoder_P3;                  /* Expression: uint8(3)
                                        * Referenced by: '<S2>/Encoder'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_lab_1_position_loop_ste {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  ContinuousStates_lab_1_position *contStates;
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
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_lab_1_position_loop_ lab_1_position_loop_step_P;

/* Block signals (auto storage) */
extern BlockIO_lab_1_position_loop_ste lab_1_position_loop_step_B;

/* Continuous states (auto storage) */
extern ContinuousStates_lab_1_position lab_1_position_loop_step_X;

/* Block states (auto storage) */
extern D_Work_lab_1_position_loop_step lab_1_position_loop_step_DWork;

/* Model entry point functions */
extern void lab_1_position_loop_step_initialize(void);
extern void lab_1_position_loop_step_step(void);
extern void lab_1_position_loop_step_terminate(void);

/* Real-time Model object */
extern RT_MODEL_lab_1_position_loop_st *const lab_1_position_loop_step_M;

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
 * '<Root>' : 'lab_1_position_loop_step'
 * '<S1>'   : 'lab_1_position_loop_step/Coulomb Friction'
 * '<S2>'   : 'lab_1_position_loop_step/DC Motor Plant'
 * '<S3>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm'
 * '<S4>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm/Brake'
 * '<S5>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm/Direction '
 * '<S6>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm/MATLAB Function'
 * '<S7>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm/PWM'
 * '<S8>'   : 'lab_1_position_loop_step/DC Motor Plant/Motorpwm/hardlim'
 */
#endif                                 /* RTW_HEADER_lab_1_position_loop_step_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
