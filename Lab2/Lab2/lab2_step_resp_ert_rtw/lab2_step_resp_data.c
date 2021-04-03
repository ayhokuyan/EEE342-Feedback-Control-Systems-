/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab2_step_resp_data.c
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

/* Block parameters (auto storage) */
Parameters_lab2_step_resp lab2_step_resp_P = {
  11U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  6000.0,                              /* Expression: 6000
                                        * Referenced by: '<S1>/min x sampling freq'
                                        */
  3200.0,                              /* Expression: 3200
                                        * Referenced by: '<S1>/CPR'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  5.0,                                 /* Expression: 5
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
