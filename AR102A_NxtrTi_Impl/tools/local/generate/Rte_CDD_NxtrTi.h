/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_NxtrTi.h
 *        Config:  E:/EA4NewTemplate/AR102A_NxtrTi_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_NxtrTi
 *  Generated at:  Wed Aug 16 14:32:48 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_NxtrTi> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_NXTRTI_H
# define _RTE_CDD_NXTRTI_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_NxtrTi_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_NxtrTi
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_NxtrTi, RTE_CONST, RTE_CONST) Rte_Inst_CDD_NxtrTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_NxtrTi, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_NxtrTi_ClrErrInjReg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_NxtrTi_ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) ErrId_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_NxtrTi_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC(void, RTE_CODE) Rte_Enter_CDD_NxtrTi_NxtrTiExclusiveArea(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_Exit_CDD_NxtrTi_NxtrTiExclusiveArea(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ClrErrInjReg_Oper Rte_Call_CDD_NxtrTi_ClrErrInjReg_Oper
# define Rte_Call_ReadErrInjReg_Oper Rte_Call_CDD_NxtrTi_ReadErrInjReg_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_NxtrTi_SetNtcSts_Oper


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_NxtrTiExclusiveArea Rte_Enter_CDD_NxtrTi_NxtrTiExclusiveArea /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
# define Rte_Exit_NxtrTiExclusiveArea Rte_Exit_CDD_NxtrTi_NxtrTiExclusiveArea /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */




# define CDD_NxtrTi_START_SEC_CODE
# include "CDD_NxtrTi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetRefTmr100MicroSec32bit_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetRefTmr100MicroSec32bit>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetRefTmr100MicroSec32bit_Oper GetRefTmr100MicroSec32bit_Oper
FUNC(void, CDD_NxtrTi_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetRefTmr1MicroSec32bit_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetRefTmr1MicroSec32bit>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetRefTmr1MicroSec32bit_Oper GetRefTmr1MicroSec32bit_Oper
FUNC(void, CDD_NxtrTi_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetTiSpan100MicroSec32bit_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetTiSpan100MicroSec32bit>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetTiSpan100MicroSec32bit_Oper GetTiSpan100MicroSec32bit_Oper
FUNC(void, CDD_NxtrTi_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetTiSpan1MicroSec32bit_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetTiSpan1MicroSec32bit>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetTiSpan1MicroSec32bit_Oper GetTiSpan1MicroSec32bit_Oper
FUNC(void, CDD_NxtrTi_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrTiInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_NxtrTiInit1 NxtrTiInit1
FUNC(void, CDD_NxtrTi_CODE) NxtrTiInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrTiPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ClrErrInjReg_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_NxtrTiExclusiveArea(void)
 *   void Rte_Exit_NxtrTiExclusiveArea(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_NxtrTiPer1 NxtrTiPer1
FUNC(void, CDD_NxtrTi_CODE) NxtrTiPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_NxtrTi_STOP_SEC_CODE
# include "CDD_NxtrTi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_NXTRTI_H */
