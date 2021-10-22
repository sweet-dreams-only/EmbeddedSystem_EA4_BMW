/**********************************************************************************************************************
Contract file for CM102A                  
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef NXTRMCUSUPRTLIB_H
#define NXTRMCUSUPRTLIB_H
#include "ecm_regs.h"

extern FUNC(void, NxtrMcuSuprtLib_CODE) NxtrSwRstFromExcpn(uint32 McuDiagcData0_Arg, uint32 McuDiagcData1_Arg);
extern FUNC(void, NxtrMcuSuprtLib_CODE) WrProtdRegEcm_u32(uint32 WrVal_Arg, P2VAR(volatile uint32, AUTOMATIC, NxtrMcuSuprtLib_APPL_VAR) WrAddr_Arg);

#endif
