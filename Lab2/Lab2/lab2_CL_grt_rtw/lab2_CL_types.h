/*
 * lab2_CL_types.h
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

#ifndef RTW_HEADER_lab2_CL_types_h_
#define RTW_HEADER_lab2_CL_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 /*struct_tag_saG5948SFTrUFnIbVUb0TZH*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_cell_wrap_lab2_CL_T
#define typedef_cell_wrap_lab2_CL_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_lab2_CL_T;

#endif                                 /*typedef_cell_wrap_lab2_CL_T*/

#ifndef typedef_struct_T_lab2_CL_T
#define typedef_struct_T_lab2_CL_T

typedef struct {
  real_T f0[2];
} struct_T_lab2_CL_T;

#endif                                 /*typedef_struct_T_lab2_CL_T*/

#ifndef typedef_struct_T_lab2_CL_o_T
#define typedef_struct_T_lab2_CL_o_T

typedef struct {
  char_T f0[5];
  char_T f1[4];
  char_T f2[6];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
} struct_T_lab2_CL_o_T;

#endif                                 /*typedef_struct_T_lab2_CL_o_T*/

#ifndef typedef_struct_T_lab2_CL_o4_T
#define typedef_struct_T_lab2_CL_o4_T

typedef struct {
  char_T f0[6];
  char_T f1[6];
} struct_T_lab2_CL_o4_T;

#endif                                 /*typedef_struct_T_lab2_CL_o4_T*/

#ifndef typedef_struct_T_lab2_CL_o4k_T
#define typedef_struct_T_lab2_CL_o4k_T

typedef struct {
  char_T f0[7];
} struct_T_lab2_CL_o4k_T;

#endif                                 /*typedef_struct_T_lab2_CL_o4k_T*/

#ifndef typedef_struct_T_lab2_CL_o4kh_T
#define typedef_struct_T_lab2_CL_o4kh_T

typedef struct {
  char_T f0[4];
  char_T f1[11];
  char_T f2[7];
  char_T f3[6];
} struct_T_lab2_CL_o4kh_T;

#endif                                 /*typedef_struct_T_lab2_CL_o4kh_T*/

#ifndef struct_tag_sEdQZg2EfqFk2ctA6t1ByNE
#define struct_tag_sEdQZg2EfqFk2ctA6t1ByNE

struct tag_sEdQZg2EfqFk2ctA6t1ByNE
{
  int32_T isInitialized;
  cell_wrap_lab2_CL_T inputVarSize;
  real_T port;
  real_T dataSizeInBytes;
};

#endif                                 /*struct_tag_sEdQZg2EfqFk2ctA6t1ByNE*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_sEdQZg2EfqFk2ctA6t1ByNE codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (auto storage) */
typedef struct P_lab2_CL_T_ P_lab2_CL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_lab2_CL_T RT_MODEL_lab2_CL_T;

#endif                                 /* RTW_HEADER_lab2_CL_types_h_ */
