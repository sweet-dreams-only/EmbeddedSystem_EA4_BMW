/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_NxtrTi.h
* Module Description: Nxtr Time Library Complex Driver Header
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 02/04/15  1        LWW       Initial Version                                                                 EA4#101
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_NXTRTI_H
#define CDD_NXTRTI_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 8.8 [NXTRDEV 8.8.1]: Deviation allowed for functions required to be declared in two headers to be accessible via the RTE as well as outside of the RTE 
						  Function Names: GetRefTmr100MicroSec32bit_Oper, GetRefTmr1MicroSec32bit_Oper, GetTiSpan100MicroSec32bit_Oper, GetTiSpan1MicroSec32bit_Oper*/

/*********************************************** Exported Declarations ***********************************************/
extern FUNC(void, CDD_NxtrTi_CODE) NxtrTiInit0(void);
extern FUNC(void, CDD_NxtrTi_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr);
extern FUNC(void, CDD_NxtrTi_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr);
extern FUNC(void, CDD_NxtrTi_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan);
extern FUNC(void, CDD_NxtrTi_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan);

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
