/* header file for contract folder of CM103A */

#ifndef NXTRMCUSUPRTLIB_H
#define NXTRMCUSUPRTLIB_H

#include "CDD_ExcpnHndlg.h"
#include "ecm_regs.h"

extern FUNC(void, NxtrMcuSuprtLib_CODE) WrProtdRegEcm_u32(uint32 WrVal_Arg, P2VAR(volatile uint32, AUTOMATIC, NxtrMcuSuprtLib_APPL_VAR) WrAddr_Arg);
extern FUNC(void, NxtrMcuSuprtLib_CODE) NxtrSwRstFromExcpn(McuDiagc1 McuDiagcData0_Arg, uint32 McuDiagcData1_Arg);

#endif

