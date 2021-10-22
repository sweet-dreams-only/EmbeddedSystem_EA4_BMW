/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot274Bas2Repn4BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot274Bas2Repn4BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot274Bas2Repn4BusFrChA>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * BmwFltLampFlsgFrq1
 *   
 *
 * BmwFltLampReqSts1
 *   
 *
 * BmwFltLampReqTyp2
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot274Bas2Repn4BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot274Bas2Repn4BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BmwMsgSlot274Bas2Repn4BusFrChA_TestDefines(void);


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
 * ALIV_DISP_CC_EPS1: Integer in interval [0...255]
 * CHL_DISP_CC_EPS1: Integer in interval [0...255]
 * CRC_DISP_CC_EPS1: Integer in interval [0...255]
 * NO_CC_EPS1: Integer in interval [0...65535]
 * TRANF_CC_EPS1: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwFltLampFlsgFrq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPFLSGFRQ_NOFLSG (0U)
 *   BMWFLTLAMPFLSGFRQ_SLOWFLSG (1U)
 *   BMWFLTLAMPFLSGFRQ_FASTFLSG (2U)
 *   BMWFLTLAMPFLSGFRQ_INVLD (3U)
 * BmwFltLampReqSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPREQSTS_FLTLAMPRSTREQD (0U)
 *   BMWFLTLAMPREQSTS_FLTLAMPSETREQD (1U)
 *   BMWFLTLAMPREQSTS_INVLD (3U)
 * BmwFltLampReqTyp2: Enumeration of integer in interval [0...65535] with enumerators
 *   BMWFLTLAMPREQTYP_NOLAMP (0U)
 *   BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP (1U)
 *   BMWFLTLAMPREQTYP_NORMWARNLAMP (2U)
 *   BMWFLTLAMPREQTYP_THERMWARNLAMP (3U)
 * ST_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ST_CC_EPS_Ruecksetzen (0U)
 *   ST_CC_EPS_Setzen (1U)
 *   ST_CC_EPS_SignalUngueltig (3U)
 * ST_IDC_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ST_IDC_CC_EPS_KeinBlinken (0U)
 *   ST_IDC_CC_EPS_LangsamesBlinken (1U)
 *   ST_IDC_CC_EPS_SchnellesBlinken (2U)
 *   ST_IDC_CC_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_DISP_CC_EPS1: Record with elements
 *   ST_CC_EPS of type ST_CC_EPS1
 *   ALIV_DISP_CC_EPS of type ALIV_DISP_CC_EPS1
 *   ST_IDC_CC_EPS of type ST_IDC_CC_EPS1
 *   CRC_DISP_CC_EPS of type CRC_DISP_CC_EPS1
 *   CHL_DISP_CC_EPS of type CHL_DISP_CC_EPS1
 *   NO_CC_EPS of type NO_CC_EPS1
 *   TRANF_CC_EPS of type TRANF_CC_EPS1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwFltLampReqTyp2 *Rte_Pim_BmwFltLampReqTypPrev(void)
 *   BmwFltLampFlsgFrq1 *Rte_Pim_BmwFltLampFlsgFrqPrev(void)
 *   BmwFltLampReqSts1 *Rte_Pim_BmwFltLampReqStsPrev(void)
 *   uint8 *Rte_Pim_BmwFltLampReqTxTypPrev(void)
 *   uint8 *Rte_Pim_LstTxCntr(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot274Bas2Repn4BusFrChA_START_SEC_CODE
#include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAInit1
 *********************************************************************************************************************/

  BmwFltLampReqTyp2 PimBmwFltLampReqTypPrev;
  BmwFltLampFlsgFrq1 PimBmwFltLampFlsgFrqPrev;
  BmwFltLampReqSts1 PimBmwFltLampReqStsPrev;
  uint8 PimBmwFltLampReqTxTypPrev;
  uint8 PimLstTxCntr;
  uint8 PimPerdCntr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwFltLampReqTypPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev() = PimBmwFltLampReqTypPrev;
  PimBmwFltLampFlsgFrqPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev() = PimBmwFltLampFlsgFrqPrev;
  PimBmwFltLampReqStsPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev() = PimBmwFltLampReqStsPrev;
  PimBmwFltLampReqTxTypPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev() = PimBmwFltLampReqTxTypPrev;
  PimLstTxCntr = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr() = PimLstTxCntr;
  PimPerdCntr = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr() = PimPerdCntr;

  BmwMsgSlot274Bas2Repn4BusFrChA_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwFltLampFlsgFrq_Val(BmwFltLampFlsgFrq1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqSts_Val(BmwFltLampReqSts1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTxTyp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(const sigGroup_DISP_CC_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(sigGroup_DISP_CC_EPS1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwFltLampFlsgFrq1 Read_BmwFltLampFlsgFrq_Val;
  BmwFltLampReqSts1 Read_BmwFltLampReqSts_Val;
  uint8 Read_BmwFltLampReqTxTyp_Val;
  BmwFltLampReqTyp2 Read_BmwFltLampReqTyp_Val;

  BmwFltLampReqTyp2 PimBmwFltLampReqTypPrev;
  BmwFltLampFlsgFrq1 PimBmwFltLampFlsgFrqPrev;
  BmwFltLampReqSts1 PimBmwFltLampReqStsPrev;
  uint8 PimBmwFltLampReqTxTypPrev;
  uint8 PimLstTxCntr;
  uint8 PimPerdCntr;

  sigGroup_DISP_CC_EPS1 Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwFltLampReqTypPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev() = PimBmwFltLampReqTypPrev;
  PimBmwFltLampFlsgFrqPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev() = PimBmwFltLampFlsgFrqPrev;
  PimBmwFltLampReqStsPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev() = PimBmwFltLampReqStsPrev;
  PimBmwFltLampReqTxTypPrev = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev() = PimBmwFltLampReqTxTypPrev;
  PimLstTxCntr = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr() = PimLstTxCntr;
  PimPerdCntr = *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr();
  *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr() = PimPerdCntr;

  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampFlsgFrq_Val(&Read_BmwFltLampFlsgFrq_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqSts_Val(&Read_BmwFltLampReqSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTxTyp_Val(&Read_BmwFltLampReqTxTyp_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTyp_Val(&Read_BmwFltLampReqTyp_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS, 0, sizeof(Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS));
  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(&Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS();
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


#define BmwMsgSlot274Bas2Repn4BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot274Bas2Repn4BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwFltLampFlsgFrq1 Test_BmwFltLampFlsgFrq1_V_1 = BMWFLTLAMPFLSGFRQ_NOFLSG;
  BmwFltLampFlsgFrq1 Test_BmwFltLampFlsgFrq1_V_2 = BMWFLTLAMPFLSGFRQ_SLOWFLSG;
  BmwFltLampFlsgFrq1 Test_BmwFltLampFlsgFrq1_V_3 = BMWFLTLAMPFLSGFRQ_FASTFLSG;
  BmwFltLampFlsgFrq1 Test_BmwFltLampFlsgFrq1_V_4 = BMWFLTLAMPFLSGFRQ_INVLD;

  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_1 = BMWFLTLAMPREQSTS_FLTLAMPRSTREQD;
  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_2 = BMWFLTLAMPREQSTS_FLTLAMPSETREQD;
  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_3 = BMWFLTLAMPREQSTS_INVLD;

  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_1 = BMWFLTLAMPREQTYP_NOLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_2 = BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_3 = BMWFLTLAMPREQTYP_NORMWARNLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_4 = BMWFLTLAMPREQTYP_THERMWARNLAMP;

  ST_CC_EPS1 Test_ST_CC_EPS1_V_1 = ST_CC_EPS_Ruecksetzen;
  ST_CC_EPS1 Test_ST_CC_EPS1_V_2 = ST_CC_EPS_Setzen;
  ST_CC_EPS1 Test_ST_CC_EPS1_V_3 = ST_CC_EPS_SignalUngueltig;

  ST_IDC_CC_EPS1 Test_ST_IDC_CC_EPS1_V_1 = ST_IDC_CC_EPS_KeinBlinken;
  ST_IDC_CC_EPS1 Test_ST_IDC_CC_EPS1_V_2 = ST_IDC_CC_EPS_LangsamesBlinken;
  ST_IDC_CC_EPS1 Test_ST_IDC_CC_EPS1_V_3 = ST_IDC_CC_EPS_SchnellesBlinken;
  ST_IDC_CC_EPS1 Test_ST_IDC_CC_EPS1_V_4 = ST_IDC_CC_EPS_SignalUngueltig;
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
