/* header file for contract folder of CM112A */

#ifndef NXTRMCUSUPRTLIB_H
#define NXTRMCUSUPRTLIB_H


extern FUNC(void, NxtrMcuSuprtLib_CODE) WrProtdRegSys_u08(uint8 WrVal_Arg, P2VAR(volatile uint8, AUTOMATIC, NxtrMcuSuprtLib_APPL_VAR) WrAddr_Arg);
extern FUNC(void, NxtrMcuSuprtLib_CODE) WrProtdRegSys_u32(uint32 WrVal_Arg, P2VAR(volatile uint32, AUTOMATIC, NxtrMcuSuprtLib_APPL_VAR) WrAddr_Arg);

#endif

