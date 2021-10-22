/* Contract file for CM108A */

#define MCUDIAGCERRINJ  STD_OFF

#if (MCUDIAGCERRINJ == STD_ON)
#include "intc_regs.h"
#include "lockstep_regs.h"
#include "adcd_regs.h"
#include "tsg3_regs.h"
#include "tauj_regs.h"
#include "taud_regs.h"
#include "ostm_regs.h"
#include "enca_regs.h"
#include "csih_regs.h"
#include "rsent_regs.h"
#include "psi5_regs.h"
#endif

#if (MCUDIAGCERRINJ == STD_ON)

extern void ClrErrInjReg_Oper(void);
extern void ReadErrInjReg_Oper(uint32* ErrId);
extern FUNC(void, CDD_DataAndAdrPar_CODE)InjDataParErr(void);

extern uint32 McuDiagcTestVar1_G;
#endif

