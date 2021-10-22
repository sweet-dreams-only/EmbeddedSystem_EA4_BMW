/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  EpsStEstimn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  EpsStEstimn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <EpsStEstimn>
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
 * Component Types:
 * ================
 * EpsStEstimn
 *   
 *
 *
 * Port Prototypes:
 * ================
 * HwTq
 *
 * MotTqEstimd
 *
 * MotVelCrf
 *
 * PinionTqToRackFInstsRat
 *
 * RackFEstimd
 *
 * SysKineRat
 *
 * SysTqRat
 *
 * TorsBarStEstimd
 *
 *
 * Runnable Entities:
 * ==================
 * EpsStEstimnInit1
 *   
 *
 * EpsStEstimnPer1
 *   
 *
 *
 * Per-Instance Memory:
 * ====================
 * StEstimrStPrev
 *   
 *
 *********************************************************************************************************************/

#include "Rte_EpsStEstimn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_EpsStEstimn.h"


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
 *
 * Array Types:
 * ============
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary2D_f32_5_3: Array with 5 element(s) of type Ary1D_f32_3
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
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
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_StEstimrStPrev(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 *Rte_Prm_EpsStEstimnMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *   float32 *Rte_Prm_EpsStEstimnMtrxC_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxD_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *
 *********************************************************************************************************************/


#define EpsStEstimn_START_SEC_CODE
#include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EpsStEstimn_CODE) EpsStEstimnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnInit1
 *********************************************************************************************************************/

  Ary1D_f32_5 PimStEstimrStPrev;

  Ary2D_f32_5_5 EpsStEstimnMtrxA_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxB_Ary2D_data;
  Ary2D_f32_5_5 EpsStEstimnMtrxC_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxD_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimStEstimrStPrev, TSC_EpsStEstimn_Rte_Pim_StEstimrStPrev(), sizeof(Ary1D_f32_5));
  (void)memcpy(TSC_EpsStEstimn_Rte_Pim_StEstimrStPrev(), PimStEstimrStPrev, sizeof(Ary1D_f32_5));


  (void)memcpy(EpsStEstimnMtrxA_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxA_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxB_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxB_Ary2D(), sizeof(Ary2D_f32_5_3));
  (void)memcpy(EpsStEstimnMtrxC_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxC_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxD_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxD_Ary2D(), sizeof(Ary2D_f32_5_3));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnPer1
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
 *   Std_ReturnType Rte_Read_MotTqEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionTqToRackFInstsRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysKineRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysTqRat_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RackFEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_TorsBarStEstimd_Rec(const TorsBarStEstimdRec1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EpsStEstimn_CODE) EpsStEstimnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_MotTqEstimd_Val;
  float32 Read_MotVelCrf_Val;
  float32 Read_PinionTqToRackFInstsRat_Val;
  float32 Read_SysKineRat_Val;
  float32 Read_SysTqRat_Val;

  Ary1D_f32_5 PimStEstimrStPrev;

  Ary2D_f32_5_5 EpsStEstimnMtrxA_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxB_Ary2D_data;
  Ary2D_f32_5_5 EpsStEstimnMtrxC_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxD_Ary2D_data;

  TorsBarStEstimdRec1 Write_TorsBarStEstimd_Rec;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimStEstimrStPrev, TSC_EpsStEstimn_Rte_Pim_StEstimrStPrev(), sizeof(Ary1D_f32_5));
  (void)memcpy(TSC_EpsStEstimn_Rte_Pim_StEstimrStPrev(), PimStEstimrStPrev, sizeof(Ary1D_f32_5));


  (void)memcpy(EpsStEstimnMtrxA_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxA_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxB_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxB_Ary2D(), sizeof(Ary2D_f32_5_3));
  (void)memcpy(EpsStEstimnMtrxC_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxC_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxD_Ary2D_data, TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxD_Ary2D(), sizeof(Ary2D_f32_5_3));

  fct_status = TSC_EpsStEstimn_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Read_MotTqEstimd_Val(&Read_MotTqEstimd_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Read_PinionTqToRackFInstsRat_Val(&Read_PinionTqToRackFInstsRat_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Read_SysKineRat_Val(&Read_SysKineRat_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Read_SysTqRat_Val(&Read_SysTqRat_Val);
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

  fct_status = TSC_EpsStEstimn_Rte_Write_RackFEstimd_Val(Rte_InitValue_RackFEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_TorsBarStEstimd_Rec, 0, sizeof(Write_TorsBarStEstimd_Rec));
  fct_status = TSC_EpsStEstimn_Rte_Write_TorsBarStEstimd_Rec(&Write_TorsBarStEstimd_Rec);
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


#define EpsStEstimn_STOP_SEC_CODE
#include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
