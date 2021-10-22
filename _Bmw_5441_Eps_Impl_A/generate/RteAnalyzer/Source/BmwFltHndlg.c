/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwFltHndlg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwFltHndlg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwFltHndlg>
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
 * BmwFltLampReqSts1
 *   
 *
 * BmwFltLampReqTyp2
 *   
 *
 *
 * Component Types:
 * ================
 * BmwFltHndlg
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwFltHndlg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwFltHndlg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BmwFltHndlg_TestDefines(void);


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwFltLampReqSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPREQSTS_FLTLAMPRSTREQD (0U)
 *   BMWFLTLAMPREQSTS_FLTLAMPSETREQD (1U)
 *   BMWFLTLAMPREQSTS_INVLD (3U)
 * BmwFltLampReqTyp2: Enumeration of integer in interval [0...65535] with enumerators
 *   BMWFLTLAMPREQTYP_NOLAMP (0U)
 *   BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP (1U)
 *   BMWFLTLAMPREQTYP_NORMWARNLAMP (2U)
 *   BMWFLTLAMPREQTYP_THERMWARNLAMP (3U)
 *
 *********************************************************************************************************************/


#define BmwFltHndlg_START_SEC_CODE
#include "BmwFltHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwFltHndlgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwFltHndlg_CODE) BmwFltHndlgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgInit1
 *********************************************************************************************************************/

  BmwFltHndlg_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwFltHndlgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwFltLampReqSts_Val(BmwFltLampReqSts1 data)
 *   Std_ReturnType Rte_Write_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwFltHndlg_CODE) BmwFltHndlgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_BmwFltHndlg_Rte_Write_BmwFltLampReqSts_Val(Rte_InitValue_BmwFltLampReqSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwFltHndlg_Rte_Write_BmwFltLampReqTyp_Val(Rte_InitValue_BmwFltLampReqTyp_Val);
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


#define BmwFltHndlg_STOP_SEC_CODE
#include "BmwFltHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwFltHndlg_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_1 = BMWFLTLAMPREQSTS_FLTLAMPRSTREQD;
  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_2 = BMWFLTLAMPREQSTS_FLTLAMPSETREQD;
  BmwFltLampReqSts1 Test_BmwFltLampReqSts1_V_3 = BMWFLTLAMPREQSTS_INVLD;

  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_1 = BMWFLTLAMPREQTYP_NOLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_2 = BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_3 = BMWFLTLAMPREQTYP_NORMWARNLAMP;
  BmwFltLampReqTyp2 Test_BmwFltLampReqTyp2_V_4 = BMWFLTLAMPREQTYP_THERMWARNLAMP;
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
