#ifndef __CvDDrgzKCMUBtsbzOngNU_h__
#define __CvDDrgzKCMUBtsbzOngNU_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"

/* Type Definitions */
#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct {
  uint32_T f1[8];
} cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef struct_tag_skKPNRc6PePVJRHrGzynZvG
#define struct_tag_skKPNRc6PePVJRHrGzynZvG

struct tag_skKPNRc6PePVJRHrGzynZvG
{
  int32_T isInitialized;
  cell_wrap inputVarSize[1];
};

#endif                                 /*struct_tag_skKPNRc6PePVJRHrGzynZvG*/

#ifndef typedef_codertarget_arduinobase_internal_arduino_SerialWrite
#define typedef_codertarget_arduinobase_internal_arduino_SerialWrite

typedef struct tag_skKPNRc6PePVJRHrGzynZvG
  codertarget_arduinobase_internal_arduino_SerialWrite;

#endif                                 /*typedef_codertarget_arduinobase_internal_arduino_SerialWrite*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T f0[2];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  char_T f0[5];
  char_T f1[4];
  char_T f2[6];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  char_T f0[6];
  char_T f1[6];
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_InstanceStruct_CvDDrgzKCMUBtsbzOngNU
#define typedef_InstanceStruct_CvDDrgzKCMUBtsbzOngNU

typedef struct {
  SimStruct *S;
  codertarget_arduinobase_internal_arduino_SerialWrite sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  uint8_T *u0;
} InstanceStruct_CvDDrgzKCMUBtsbzOngNU;

#endif                                 /*typedef_InstanceStruct_CvDDrgzKCMUBtsbzOngNU*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_CvDDrgzKCMUBtsbzOngNU(SimStruct *S, int_T method,
  void* data);

#endif
