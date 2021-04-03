/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab3_step_DM_data.c
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

/* Block parameters (auto storage) */
P_lab3_step_DM_T lab3_step_DM_P = {
  /*  Variable: contr_poles
   * Referenced by: '<Root>/Gc'
   */
  { 1.0, 0.0 },

  /*  Variable: contr_zeros
   * Referenced by: '<Root>/Gc'
   */
  { 0.056818181818181816, 1.0 },
  11U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  0.08,                                /* Expression: 0.08
                                        * Referenced by: '<Root>/Time Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Time Delay'
                                        */
  3200.0,                              /* Expression: 3200
                                        * Referenced by: '<S1>/CPR'
                                        */
  6000.0,                              /* Expression: 6000
                                        * Referenced by: '<S1>/min x sampling freq'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  21.25,                               /* Expression: 255/12
                                        * Referenced by: '<S2>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S1>/Encoder'
                                        */
  2U,                                  /* Expression: uint8(2)
                                        * Referenced by: '<S1>/Encoder'
                                        */
  3U                                   /* Expression: uint8(3)
                                        * Referenced by: '<S1>/Encoder'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
