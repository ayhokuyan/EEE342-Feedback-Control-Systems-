/*
 * lab2_CL_data.c
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

#include "lab2_CL.h"
#include "lab2_CL_private.h"

/* Block parameters (auto storage) */
P_lab2_CL_T lab2_CL_P = {
  11U,                                 /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  6000.0,                              /* Expression: 6000
                                        * Referenced by: '<S1>/min x sampling freq'
                                        */
  3200.0,                              /* Expression: 3200
                                        * Referenced by: '<S1>/CPR'
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
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Voltage Source'
                                        */
  -0.0,                                /* Computed Parameter: Gc_A
                                        * Referenced by: '<Root>/Gc'
                                        */
  15.2,                                /* Computed Parameter: Gc_C
                                        * Referenced by: '<Root>/Gc'
                                        */
  0.86363636363636354,                 /* Computed Parameter: Gc_D
                                        * Referenced by: '<Root>/Gc'
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
