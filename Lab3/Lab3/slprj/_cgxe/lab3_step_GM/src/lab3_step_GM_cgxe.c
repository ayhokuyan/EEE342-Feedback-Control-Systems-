/* Include files */

#include "lab3_step_GM_cgxe.h"
#include "m_CvDDrgzKCMUBtsbzOngNU.h"

unsigned int cgxe_lab3_step_GM_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 3810890698 &&
      ssGetChecksum1(S) == 2816051824 &&
      ssGetChecksum2(S) == 690620799 &&
      ssGetChecksum3(S) == 4134144592) {
    method_dispatcher_CvDDrgzKCMUBtsbzOngNU(S, method, data);
    return 1;
  }

  return 0;
}
