/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  HwTqTrakgCtrl.c
 *        Config:  EPS.dpa
 *     SW-C Type:  HwTqTrakgCtrl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <HwTqTrakgCtrl>
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
 * s14p1
 *   
 *
 * s3p12
 *   
 *
 * s7p8
 *   
 *
 * s8p7
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_HwTqTrakgCtrl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_HwTqTrakgCtrl.h"


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
 * s14p1: Integer in interval [-32768...32767]
 * s3p12: Integer in interval [-32768...32767]
 * s7p8: Integer in interval [-32768...32767]
 * s8p7: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s14p1_4: Array with 4 element(s) of type s14p1
 * Ary1D_s3p12_4: Array with 4 element(s) of type s3p12
 * Ary1D_s7p8_4: Array with 4 element(s) of type s7p8
 * Ary1D_s8p7_4: Array with 4 element(s) of type s8p7
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 *
 * Record Types:
 * =============
 * TorsBarStEstimdRec1: Record with elements
 *   MotVelEstimd of type float32
 *   TorsBarTqEstimd of type float32
 *   TorsBarRotatmEstimd of type float32
 *   DrvrTqEstimd of type float32
 *   RackTqEstimd of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val(void)
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s14p1 *Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(void)
 *     Returnvalue: s14p1* is of type Ary1D_s14p1_4
 *   s8p7 *Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(void)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s7p8 *Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(void)
 *     Returnvalue: s7p8* is of type Ary1D_s7p8_4
 *   u9p7 *Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *
 *********************************************************************************************************************/


#define HwTqTrakgCtrl_START_SEC_CODE
#include "HwTqTrakgCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqTrakgCtrlInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqTrakgCtrlInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqTrakgCtrlInit1
 *********************************************************************************************************************/

  float32 HwTqTrakgCtrlMotTqCmdOvrlGain_Val_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain1_Ary1D_data;
  Ary1D_s14p1_4 HwTqTrakgCtrlFbGain2_Ary1D_data;
  Ary1D_s8p7_4 HwTqTrakgCtrlFbGain3_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain4_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain5_Ary1D_data;
  Ary1D_s7p8_4 HwTqTrakgCtrlFfGainScaY_Ary1D_data;
  Ary1D_u9p7_4 HwTqTrakgCtrlVehSpdScaX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  HwTqTrakgCtrlMotTqCmdOvrlGain_Val_data = TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val();
  (void)memcpy(HwTqTrakgCtrlFbGain1_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain2_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(), sizeof(Ary1D_s14p1_4));
  (void)memcpy(HwTqTrakgCtrlFbGain3_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(), sizeof(Ary1D_s8p7_4));
  (void)memcpy(HwTqTrakgCtrlFbGain4_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain5_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFfGainScaY_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(), sizeof(Ary1D_s7p8_4));
  (void)memcpy(HwTqTrakgCtrlVehSpdScaX_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), sizeof(Ary1D_u9p7_4));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqTrakgCtrlPer1
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
 *   Std_ReturnType Rte_Read_HwTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysTqRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TorsBarStEstimd_Rec(TorsBarStEstimdRec1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqCmdTrakgCtrl_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqTrakgCtrlPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqTrakgCtrlPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTqCmd_Val;
  float32 Read_MotTqCmdOvrl_Val;
  float32 Read_SysTqRat_Val;
  TorsBarStEstimdRec1 Read_TorsBarStEstimd_Rec;
  float32 Read_VehSpd_Val;

  float32 HwTqTrakgCtrlMotTqCmdOvrlGain_Val_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain1_Ary1D_data;
  Ary1D_s14p1_4 HwTqTrakgCtrlFbGain2_Ary1D_data;
  Ary1D_s8p7_4 HwTqTrakgCtrlFbGain3_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain4_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain5_Ary1D_data;
  Ary1D_s7p8_4 HwTqTrakgCtrlFfGainScaY_Ary1D_data;
  Ary1D_u9p7_4 HwTqTrakgCtrlVehSpdScaX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  HwTqTrakgCtrlMotTqCmdOvrlGain_Val_data = TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val();
  (void)memcpy(HwTqTrakgCtrlFbGain1_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain2_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(), sizeof(Ary1D_s14p1_4));
  (void)memcpy(HwTqTrakgCtrlFbGain3_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(), sizeof(Ary1D_s8p7_4));
  (void)memcpy(HwTqTrakgCtrlFbGain4_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain5_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFfGainScaY_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(), sizeof(Ary1D_s7p8_4));
  (void)memcpy(HwTqTrakgCtrlVehSpdScaX_Ary1D_data, TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), sizeof(Ary1D_u9p7_4));

  fct_status = TSC_HwTqTrakgCtrl_Rte_Read_HwTqCmd_Val(&Read_HwTqCmd_Val);
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

  fct_status = TSC_HwTqTrakgCtrl_Rte_Read_MotTqCmdOvrl_Val(&Read_MotTqCmdOvrl_Val);
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

  fct_status = TSC_HwTqTrakgCtrl_Rte_Read_SysTqRat_Val(&Read_SysTqRat_Val);
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

  fct_status = TSC_HwTqTrakgCtrl_Rte_Read_TorsBarStEstimd_Rec(&Read_TorsBarStEstimd_Rec);
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

  fct_status = TSC_HwTqTrakgCtrl_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_HwTqTrakgCtrl_Rte_Write_MotTqCmdTrakgCtrl_Val(Rte_InitValue_MotTqCmdTrakgCtrl_Val);
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


#define HwTqTrakgCtrl_STOP_SEC_CODE
#include "HwTqTrakgCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
