/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab_1_position_loop_step_data.c
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

/* Block parameters (auto storage) */
Parameters_lab_1_position_loop_ lab_1_position_loop_step_P = {
  0.0,                                 /* Mask Parameter: CoulombFriction_gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  2.0,                                 /* Mask Parameter: CoulombFriction_offset
                                        * Referenced by: '<S1>/Gain1'
                                        */
  11U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S7>/PWM'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Cp'
                                        */
  6000.0,                              /* Expression: 6000
                                        * Referenced by: '<S2>/min x sampling freq'
                                        */
  3200.0,                              /* Expression: 3200
                                        * Referenced by: '<S2>/CPR'
                                        */
  36000.0,                             /* Expression: 36000
                                        * Referenced by: '<S2>/deg x sampling freq'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  -20.0,                               /* Computed Parameter: LPF_A
                                        * Referenced by: '<Root>/LPF'
                                        */
  2.0,                                 /* Computed Parameter: LPF_C
                                        * Referenced by: '<Root>/LPF'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S2>/Saturation'
                                        */
  21.25,                               /* Expression: 255/12
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S2>/Encoder'
                                        */
  2U,                                  /* Expression: uint8(2)
                                        * Referenced by: '<S2>/Encoder'
                                        */
  3U                                   /* Expression: uint8(3)
                                        * Referenced by: '<S2>/Encoder'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
