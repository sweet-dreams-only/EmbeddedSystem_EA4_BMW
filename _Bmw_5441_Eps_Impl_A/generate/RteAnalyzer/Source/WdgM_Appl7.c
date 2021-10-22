/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  WdgM_Appl7.c
 *        Config:  EPS.dpa
 *     SW-C Type:  WdgM_Appl7
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <WdgM_Appl7>
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
 * WdgM_CheckpointIdType
 *   
 *
 * WdgM_LocalStatusType
 *   
 *
 * WdgM_SupervisedEntityIdType
 *   
 *
 *
 * Port Prototypes:
 * ================
 * alive_SE_100ms_Appl7_ChkPt_100ms_Appl7_End
 *
 * alive_SE_100ms_Appl7_ChkPt_100ms_Appl7_Strt
 *
 * alive_SE_10ms_Appl7_ChkPt_10ms_Appl7_End
 *
 * alive_SE_10ms_Appl7_ChkPt_10ms_Appl7_Strt
 *
 * alive_SE_2ms_Appl7_ChkPt_2ms_Appl7_End
 *
 * alive_SE_2ms_Appl7_ChkPt_2ms_Appl7_Strt
 *
 * alive_SE_4ms_Appl7_ChkPt_4ms_Appl7_End
 *
 * alive_SE_4ms_Appl7_ChkPt_4ms_Appl7_Strt
 *
 * localStatus_SE_100ms_Appl7
 *
 * localStatus_SE_10ms_Appl7
 *
 * localStatus_SE_2ms_Appl7
 *
 * localStatus_SE_4ms_Appl7
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   
 *
 * GetLocalStatus of Port Interface WdgM_LocalStatus
 *   
 *
 *********************************************************************************************************************/

#include "Rte_WdgM_Appl7.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_WdgM_Appl7.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void WdgM_Appl7_TestDefines(void);


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
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   WDGM_LOCAL_STATUS_OK (0U)
 *   WDGM_LOCAL_STATUS_FAILED (1U)
 *   WDGM_LOCAL_STATUS_EXPIRED (2U)
 *   WDGM_LOCAL_STATUS_DEACTIVATED (4U)
 *
 *********************************************************************************************************************/


#define WdgM_Appl7_START_SEC_CODE
#include "WdgM_Appl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define WdgM_Appl7_STOP_SEC_CODE
#include "WdgM_Appl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void WdgM_Appl7_TestDefines(void)
{
  /* Enumeration Data Types */

  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_1 = WDGM_LOCAL_STATUS_OK;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_2 = WDGM_LOCAL_STATUS_FAILED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_3 = WDGM_LOCAL_STATUS_EXPIRED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_4 = WDGM_LOCAL_STATUS_DEACTIVATED;
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
