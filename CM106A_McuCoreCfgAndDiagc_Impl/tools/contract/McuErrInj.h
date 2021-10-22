/* Contract file for CM106A */
#include "Os.h"

#define MCUDIAGCERRINJ STD_OFF

extern void ClrErrInjReg_Oper(void);
extern void ReadErrInjReg_Oper(uint32* ErrId);

#define MCUDIAGC_MCUDIAGCTEST 0x0U

#if (MCUDIAGCERRINJ == STD_ON)
extern FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjDmaErr_Oper(void);
extern FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjMcuDiagcErr_Oper(void);
extern uint32 McuDiagcTestVar1_G;
#endif

