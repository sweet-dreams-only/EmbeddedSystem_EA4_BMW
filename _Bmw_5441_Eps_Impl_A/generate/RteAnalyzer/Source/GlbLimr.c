/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  GlbLimr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  GlbLimr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <GlbLimr>
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
 * s4p11
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_GlbLimr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_GlbLimr.h"


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s4p11: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_13: Array with 13 element(s) of type s4p11
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary2D_s4p11_10_13: Array with 10 element(s) of type Ary1D_s4p11_13
 *
 * Record Types:
 * =============
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_GlbLimrNotch1Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch1Fil2(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil2(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   s4p11 *Rte_Prm_GlbLimrBndX_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   s4p11 *Rte_Prm_GlbLimrBndY_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   u9p7 *Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   FilNotchGainRec1 *Rte_Prm_GlbLimrNotchFilStruct_Rec(void)
 *
 *********************************************************************************************************************/


#define GlbLimr_START_SEC_CODE
#include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, GlbLimr_CODE) GlbLimrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrInit1
 *********************************************************************************************************************/

  float32 PimGlbLimrNotch1Fil1;
  float32 PimGlbLimrNotch1Fil2;
  float32 PimGlbLimrNotch2Fil1;
  float32 PimGlbLimrNotch2Fil2;

  Ary2D_s4p11_10_13 GlbLimrBndX_Ary2D_data;
  Ary2D_s4p11_10_13 GlbLimrBndY_Ary2D_data;
  Ary1D_u9p7_10 GlbLimrVehSpdBilnrSeln_Ary1D_data;
  FilNotchGainRec1 GlbLimrNotchFilStruct_Rec_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimGlbLimrNotch1Fil1 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil1();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil1() = PimGlbLimrNotch1Fil1;
  PimGlbLimrNotch1Fil2 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil2();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil2() = PimGlbLimrNotch1Fil2;
  PimGlbLimrNotch2Fil1 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil1();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil1() = PimGlbLimrNotch2Fil1;
  PimGlbLimrNotch2Fil2 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil2();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil2() = PimGlbLimrNotch2Fil2;

  (void)memcpy(GlbLimrBndX_Ary2D_data, TSC_GlbLimr_Rte_Prm_GlbLimrBndX_Ary2D(), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrBndY_Ary2D_data, TSC_GlbLimr_Rte_Prm_GlbLimrBndY_Ary2D(), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrVehSpdBilnrSeln_Ary1D_data, TSC_GlbLimr_Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_10));
  GlbLimrNotchFilStruct_Rec_data = *TSC_GlbLimr_Rte_Prm_GlbLimrNotchFilStruct_Rec();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LimdMotTqCmd_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, GlbLimr_CODE) GlbLimrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_MotTqCmd_Val;
  float32 Read_VehSpd_Val;

  float32 PimGlbLimrNotch1Fil1;
  float32 PimGlbLimrNotch1Fil2;
  float32 PimGlbLimrNotch2Fil1;
  float32 PimGlbLimrNotch2Fil2;

  Ary2D_s4p11_10_13 GlbLimrBndX_Ary2D_data;
  Ary2D_s4p11_10_13 GlbLimrBndY_Ary2D_data;
  Ary1D_u9p7_10 GlbLimrVehSpdBilnrSeln_Ary1D_data;
  FilNotchGainRec1 GlbLimrNotchFilStruct_Rec_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimGlbLimrNotch1Fil1 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil1();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil1() = PimGlbLimrNotch1Fil1;
  PimGlbLimrNotch1Fil2 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil2();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil2() = PimGlbLimrNotch1Fil2;
  PimGlbLimrNotch2Fil1 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil1();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil1() = PimGlbLimrNotch2Fil1;
  PimGlbLimrNotch2Fil2 = *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil2();
  *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil2() = PimGlbLimrNotch2Fil2;

  (void)memcpy(GlbLimrBndX_Ary2D_data, TSC_GlbLimr_Rte_Prm_GlbLimrBndX_Ary2D(), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrBndY_Ary2D_data, TSC_GlbLimr_Rte_Prm_GlbLimrBndY_Ary2D(), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrVehSpdBilnrSeln_Ary1D_data, TSC_GlbLimr_Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_10));
  GlbLimrNotchFilStruct_Rec_data = *TSC_GlbLimr_Rte_Prm_GlbLimrNotchFilStruct_Rec();

  fct_status = TSC_GlbLimr_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_GlbLimr_Rte_Read_MotTqCmd_Val(&Read_MotTqCmd_Val);
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

  fct_status = TSC_GlbLimr_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_GlbLimr_Rte_Write_LimdMotTqCmd_Val(Rte_InitValue_LimdMotTqCmd_Val);
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


#define GlbLimr_STOP_SEC_CODE
#include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
