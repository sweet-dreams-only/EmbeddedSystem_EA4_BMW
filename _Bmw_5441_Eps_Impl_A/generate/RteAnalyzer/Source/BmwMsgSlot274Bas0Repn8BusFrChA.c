/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot274Bas0Repn8BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot274Bas0Repn8BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot274Bas0Repn8BusFrChA>
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

#include "Rte_BmwMsgSlot274Bas0Repn8BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot274Bas0Repn8BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BmwMsgSlot274Bas0Repn8BusFrChA_TestDefines(void);


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
 * ALIV_SU_EPS1: Integer in interval [0...255]
 * CRC_SU_EPS1: Integer in interval [0...255]
 * SU_EPS_dummy_14_191: Integer in interval [0...255]
 * SU_EPS_dummy_20_511: Integer in interval [0...4294967295]
 * TOT_STR_EPS1: Integer in interval [0...65535]
 *   Factor: 0.012213, Offset: 0
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * UN_TOT_STR_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   UN_TOT_STR_EPS_Ritzelschnittstelle (0U)
 *   UN_TOT_STR_EPS_Zahnstangenhubschnittstelle (1U)
 *   UN_TOT_STR_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_SU_EPS1: Record with elements
 *   CRC_SU_EPS of type CRC_SU_EPS1
 *   UN_TOT_STR_EPS of type UN_TOT_STR_EPS1
 *   ALIV_SU_EPS of type ALIV_SU_EPS1
 *   TOT_STR_EPS of type TOT_STR_EPS1
 *   SU_EPS_dummy_20_51 of type SU_EPS_dummy_20_511
 *   SU_EPS_dummy_14_19 of type SU_EPS_dummy_14_191
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_SuEpsPerCntr(void)
 *   uint8 *Rte_Pim_SuEpsBurstCntr(void)
 *   uint8 *Rte_Pim_SuEpsDebCntr(void)
 *   sigGroup_SU_EPS1 *Rte_Pim_SigGroupSuEps(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot274Bas0Repn8BusFrChA_START_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAInit1
 *********************************************************************************************************************/

  uint16 PimSuEpsPerCntr;
  uint8 PimSuEpsBurstCntr;
  uint8 PimSuEpsDebCntr;
  sigGroup_SU_EPS1 PimSigGroupSuEps;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimSuEpsPerCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr() = PimSuEpsPerCntr;
  PimSuEpsBurstCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr() = PimSuEpsBurstCntr;
  PimSuEpsDebCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr() = PimSuEpsDebCntr;
  PimSigGroupSuEps = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps() = PimSigGroupSuEps;

  BmwMsgSlot274Bas0Repn8BusFrChA_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(const sigGroup_SU_EPS1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(sigGroup_SU_EPS1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint16 PimSuEpsPerCntr;
  uint8 PimSuEpsBurstCntr;
  uint8 PimSuEpsDebCntr;
  sigGroup_SU_EPS1 PimSigGroupSuEps;

  sigGroup_SU_EPS1 Write_sigGroup_SU_EPS_sigGroup_SU_EPS;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimSuEpsPerCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr() = PimSuEpsPerCntr;
  PimSuEpsBurstCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr() = PimSuEpsBurstCntr;
  PimSuEpsDebCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr() = PimSuEpsDebCntr;
  PimSigGroupSuEps = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps() = PimSigGroupSuEps;

  (void)memset(&Write_sigGroup_SU_EPS_sigGroup_SU_EPS, 0, sizeof(Write_sigGroup_SU_EPS_sigGroup_SU_EPS));
  fct_status = TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(&Write_sigGroup_SU_EPS_sigGroup_SU_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CfgMsgTxReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <CfgMsgTxReq>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CfgMsgTxReq_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CfgMsgTxReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) CfgMsgTxReq_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CfgMsgTxReq_Oper
 *********************************************************************************************************************/

  uint16 PimSuEpsPerCntr;
  uint8 PimSuEpsBurstCntr;
  uint8 PimSuEpsDebCntr;
  sigGroup_SU_EPS1 PimSigGroupSuEps;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimSuEpsPerCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsPerCntr() = PimSuEpsPerCntr;
  PimSuEpsBurstCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsBurstCntr() = PimSuEpsBurstCntr;
  PimSuEpsDebCntr = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SuEpsDebCntr() = PimSuEpsDebCntr;
  PimSigGroupSuEps = *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps();
  *TSC_BmwMsgSlot274Bas0Repn8BusFrChA_Rte_Pim_SigGroupSuEps() = PimSigGroupSuEps;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot274Bas0Repn8BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot274Bas0Repn8BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  UN_TOT_STR_EPS1 Test_UN_TOT_STR_EPS1_V_1 = UN_TOT_STR_EPS_Ritzelschnittstelle;
  UN_TOT_STR_EPS1 Test_UN_TOT_STR_EPS1_V_2 = UN_TOT_STR_EPS_Zahnstangenhubschnittstelle;
  UN_TOT_STR_EPS1 Test_UN_TOT_STR_EPS1_V_3 = UN_TOT_STR_EPS_SignalUngueltig;
}

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
