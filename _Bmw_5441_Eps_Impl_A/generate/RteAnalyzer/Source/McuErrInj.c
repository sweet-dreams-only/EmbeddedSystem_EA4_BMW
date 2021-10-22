/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  McuErrInj.c
 *        Config:  EPS.dpa
 *     SW-C Type:  McuErrInj
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <McuErrInj>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_McuErrInj.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_McuErrInj.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_ErrInjActvCntr(void)
 *   boolean *Rte_Pim_StrtErrInj(void)
 *
 *********************************************************************************************************************/


#define McuErrInj_START_SEC_CODE
#include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrErrInjReg_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrErrInjReg_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) ClrErrInjReg_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrErrInjReg_Oper
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) McuErrInjInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjInit1
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) McuErrInjPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjPer1
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadErrInjReg_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ReadErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadErrInjReg_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadErrInjReg_Oper
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtErrInjCntr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <StrtErrInjCntr>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void StrtErrInjCntr_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtErrInjCntr_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) StrtErrInjCntr_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtErrInjCntr_Oper
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: UpdErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <UpdErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: UpdErrInjReg_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: UpdErrInjReg_Oper
 *********************************************************************************************************************/

  uint8 PimErrInjActvCntr;
  boolean PimStrtErrInj;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimErrInjActvCntr = *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr();
  *TSC_McuErrInj_Rte_Pim_ErrInjActvCntr() = PimErrInjActvCntr;
  PimStrtErrInj = *TSC_McuErrInj_Rte_Pim_StrtErrInj();
  *TSC_McuErrInj_Rte_Pim_StrtErrInj() = PimStrtErrInj;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define McuErrInj_STOP_SEC_CODE
#include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
