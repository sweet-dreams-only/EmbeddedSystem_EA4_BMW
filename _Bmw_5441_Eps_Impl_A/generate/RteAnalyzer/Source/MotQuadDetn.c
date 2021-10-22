/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MotQuadDetn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  MotQuadDetn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <MotQuadDetn>
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
 * MotQuad1
 *   
 *
 * s18p13
 *   
 *
 *********************************************************************************************************************/

#include "Rte_MotQuadDetn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MotQuadDetn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void MotQuadDetn_TestDefines(void);


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s18p13: Integer in interval [-2147483648...2147483647]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * MotQuad1: Enumeration of integer in interval [0...255] with enumerators
 *   MOTQUAD_QUAD1 (1U)
 *   MOTQUAD_QUAD2 (2U)
 *   MOTQUAD_QUAD3 (3U)
 *   MOTQUAD_QUAD4 (4U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   s18p13 *Rte_Pim_MotAgCumvPrev(void)
 *   s18p13 *Rte_Pim_dMotQuadDetnMotAgCumvDelta(void)
 *   sint8 *Rte_Pim_MotDirInstsPrev(void)
 *   sint8 *Rte_Pim_MotTqCmdSignPrev(void)
 *   sint8 *Rte_Pim_dMotQuadDetnTqCmdSign(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   s18p13 Rte_Prm_MotQuadDetnMotDirHysInsts_Val(void)
 *
 *********************************************************************************************************************/


#define MotQuadDetn_START_SEC_CODE
#include "MotQuadDetn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotQuadDetnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotQuadDetnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotQuadDetn_CODE) MotQuadDetnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotQuadDetnInit1
 *********************************************************************************************************************/

  s18p13 PimMotAgCumvPrev;
  s18p13 PimdMotQuadDetnMotAgCumvDelta;
  sint8 PimMotDirInstsPrev;
  sint8 PimMotTqCmdSignPrev;
  sint8 PimdMotQuadDetnTqCmdSign;

  s18p13 MotQuadDetnMotDirHysInsts_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotAgCumvPrev = *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev() = PimMotAgCumvPrev;
  PimdMotQuadDetnMotAgCumvDelta = *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta();
  *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta() = PimdMotQuadDetnMotAgCumvDelta;
  PimMotDirInstsPrev = *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev() = PimMotDirInstsPrev;
  PimMotTqCmdSignPrev = *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev() = PimMotTqCmdSignPrev;
  PimdMotQuadDetnTqCmdSign = *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign();
  *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign() = PimdMotQuadDetnTqCmdSign;

  MotQuadDetnMotDirHysInsts_Val_data = TSC_MotQuadDetn_Rte_Prm_MotQuadDetnMotDirHysInsts_Val();

  MotQuadDetn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotQuadDetnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotDirInsts_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotQuad_Val(MotQuad1 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotQuadDetnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotQuadDetn_CODE) MotQuadDetnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotQuadDetnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  s18p13 Read_MotAgCumvAlgndMrf_Val;
  float32 Read_MotTqCmd_Val;

  s18p13 PimMotAgCumvPrev;
  s18p13 PimdMotQuadDetnMotAgCumvDelta;
  sint8 PimMotDirInstsPrev;
  sint8 PimMotTqCmdSignPrev;
  sint8 PimdMotQuadDetnTqCmdSign;

  s18p13 MotQuadDetnMotDirHysInsts_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotAgCumvPrev = *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev() = PimMotAgCumvPrev;
  PimdMotQuadDetnMotAgCumvDelta = *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta();
  *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta() = PimdMotQuadDetnMotAgCumvDelta;
  PimMotDirInstsPrev = *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev() = PimMotDirInstsPrev;
  PimMotTqCmdSignPrev = *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev();
  *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev() = PimMotTqCmdSignPrev;
  PimdMotQuadDetnTqCmdSign = *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign();
  *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign() = PimdMotQuadDetnTqCmdSign;

  MotQuadDetnMotDirHysInsts_Val_data = TSC_MotQuadDetn_Rte_Prm_MotQuadDetnMotDirHysInsts_Val();

  fct_status = TSC_MotQuadDetn_Rte_Read_MotAgCumvAlgndMrf_Val(&Read_MotAgCumvAlgndMrf_Val);
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

  fct_status = TSC_MotQuadDetn_Rte_Read_MotTqCmd_Val(&Read_MotTqCmd_Val);
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

  fct_status = TSC_MotQuadDetn_Rte_Write_MotDirInsts_Val(Rte_InitValue_MotDirInsts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotQuadDetn_Rte_Write_MotQuad_Val(Rte_InitValue_MotQuad_Val);
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


#define MotQuadDetn_STOP_SEC_CODE
#include "MotQuadDetn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MotQuadDetn_TestDefines(void)
{
  /* Enumeration Data Types */

  MotQuad1 Test_MotQuad1_V_1 = MOTQUAD_QUAD1;
  MotQuad1 Test_MotQuad1_V_2 = MOTQUAD_QUAD2;
  MotQuad1 Test_MotQuad1_V_3 = MOTQUAD_QUAD3;
  MotQuad1 Test_MotQuad1_V_4 = MOTQUAD_QUAD4;
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
