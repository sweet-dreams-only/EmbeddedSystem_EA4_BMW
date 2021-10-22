/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  VehSigCdng.c
 *        Config:  EPS.dpa
 *     SW-C Type:  VehSigCdng
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <VehSigCdng>
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

#include "Rte_VehSigCdng.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_VehSigCdng.h"


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevLatA(void)
 *   float32 *Rte_Pim_PrevLtgA(void)
 *   float32 *Rte_Pim_PrevVehSpd(void)
 *   float32 *Rte_Pim_PrevYawRate(void)
 *   boolean *Rte_Pim_PrevLatAVld(void)
 *   boolean *Rte_Pim_PrevLtgAVld(void)
 *   boolean *Rte_Pim_PrevVehSpdVld(void)
 *   boolean *Rte_Pim_PrevYawRateVld(void)
 *   FilLpRec1 *Rte_Pim_HwTqFilRec(void)
 *   FilLpRec1 *Rte_Pim_LatAFilRec(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_VehSigCdngDftLatA_Val(void)
 *   float32 Rte_Prm_VehSigCdngDftLgtA_Val(void)
 *   float32 Rte_Prm_VehSigCdngDftVehSpd_Val(void)
 *   float32 Rte_Prm_VehSigCdngDftYawRate_Val(void)
 *   float32 Rte_Prm_VehSigCdngLatADifThd_Val(void)
 *   float32 Rte_Prm_VehSigCdngLatAFilFrq_Val(void)
 *   float32 Rte_Prm_VehSigCdngLatASlewRate_Val(void)
 *   float32 Rte_Prm_VehSigCdngLtgADifThd_Val(void)
 *   float32 Rte_Prm_VehSigCdngLtgASlewRate_Val(void)
 *   float32 Rte_Prm_VehSigCdngVehSpdDifThd_Val(void)
 *   float32 Rte_Prm_VehSigCdngVehSpdSlewRate_Val(void)
 *   float32 Rte_Prm_VehSigCdngVehYawSlewRate_Val(void)
 *   float32 Rte_Prm_VehSigCdngYawRateDifThd_Val(void)
 *
 *********************************************************************************************************************/


#define VehSigCdng_START_SEC_CODE
#include "VehSigCdng_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehSigCdngInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VehSigCdngInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, VehSigCdng_CODE) VehSigCdngInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehSigCdngInit1
 *********************************************************************************************************************/

  float32 PimPrevLatA;
  float32 PimPrevLtgA;
  float32 PimPrevVehSpd;
  float32 PimPrevYawRate;
  boolean PimPrevLatAVld;
  boolean PimPrevLtgAVld;
  boolean PimPrevVehSpdVld;
  boolean PimPrevYawRateVld;
  FilLpRec1 PimHwTqFilRec;
  FilLpRec1 PimLatAFilRec;

  float32 VehSigCdngDftLatA_Val_data;
  float32 VehSigCdngDftLgtA_Val_data;
  float32 VehSigCdngDftVehSpd_Val_data;
  float32 VehSigCdngDftYawRate_Val_data;
  float32 VehSigCdngLatADifThd_Val_data;
  float32 VehSigCdngLatAFilFrq_Val_data;
  float32 VehSigCdngLatASlewRate_Val_data;
  float32 VehSigCdngLtgADifThd_Val_data;
  float32 VehSigCdngLtgASlewRate_Val_data;
  float32 VehSigCdngVehSpdDifThd_Val_data;
  float32 VehSigCdngVehSpdSlewRate_Val_data;
  float32 VehSigCdngVehYawSlewRate_Val_data;
  float32 VehSigCdngYawRateDifThd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevLatA = *TSC_VehSigCdng_Rte_Pim_PrevLatA();
  *TSC_VehSigCdng_Rte_Pim_PrevLatA() = PimPrevLatA;
  PimPrevLtgA = *TSC_VehSigCdng_Rte_Pim_PrevLtgA();
  *TSC_VehSigCdng_Rte_Pim_PrevLtgA() = PimPrevLtgA;
  PimPrevVehSpd = *TSC_VehSigCdng_Rte_Pim_PrevVehSpd();
  *TSC_VehSigCdng_Rte_Pim_PrevVehSpd() = PimPrevVehSpd;
  PimPrevYawRate = *TSC_VehSigCdng_Rte_Pim_PrevYawRate();
  *TSC_VehSigCdng_Rte_Pim_PrevYawRate() = PimPrevYawRate;
  PimPrevLatAVld = *TSC_VehSigCdng_Rte_Pim_PrevLatAVld();
  *TSC_VehSigCdng_Rte_Pim_PrevLatAVld() = PimPrevLatAVld;
  PimPrevLtgAVld = *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld();
  *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld() = PimPrevLtgAVld;
  PimPrevVehSpdVld = *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld();
  *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld() = PimPrevVehSpdVld;
  PimPrevYawRateVld = *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld();
  *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld() = PimPrevYawRateVld;
  PimHwTqFilRec = *TSC_VehSigCdng_Rte_Pim_HwTqFilRec();
  *TSC_VehSigCdng_Rte_Pim_HwTqFilRec() = PimHwTqFilRec;
  PimLatAFilRec = *TSC_VehSigCdng_Rte_Pim_LatAFilRec();
  *TSC_VehSigCdng_Rte_Pim_LatAFilRec() = PimLatAFilRec;

  VehSigCdngDftLatA_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLatA_Val();
  VehSigCdngDftLgtA_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLgtA_Val();
  VehSigCdngDftVehSpd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftVehSpd_Val();
  VehSigCdngDftYawRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftYawRate_Val();
  VehSigCdngLatADifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatADifThd_Val();
  VehSigCdngLatAFilFrq_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatAFilFrq_Val();
  VehSigCdngLatASlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatASlewRate_Val();
  VehSigCdngLtgADifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgADifThd_Val();
  VehSigCdngLtgASlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgASlewRate_Val();
  VehSigCdngVehSpdDifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdDifThd_Val();
  VehSigCdngVehSpdSlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdSlewRate_Val();
  VehSigCdngVehYawSlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehYawSlewRate_Val();
  VehSigCdngYawRateDifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngYawRateDifThd_Val();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehSigCdngPer1
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
 *   Std_ReturnType Rte_Read_VehLatASerlCom_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehLatAVldSerlCom_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehLgtASerlCom_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehLgtAVldSerlCom_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpdOvrd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdOvrdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpdSerlCom_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVldSerlCom_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehYawRateSerlCom_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehYawRateVldSerlCom_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VehLatA_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehLatAEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehLatAEstimdVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_VehLatAVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_VehLgtA_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehLgtAVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_VehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehSpdVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_VehYawRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehYawRateVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VehSigCdngPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, VehSigCdng_CODE) VehSigCdngPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehSigCdngPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_VehLatASerlCom_Val;
  boolean Read_VehLatAVldSerlCom_Logl;
  float32 Read_VehLgtASerlCom_Val;
  boolean Read_VehLgtAVldSerlCom_Logl;
  float32 Read_VehSpdOvrd_Val;
  boolean Read_VehSpdOvrdEna_Logl;
  float32 Read_VehSpdSerlCom_Val;
  boolean Read_VehSpdVldSerlCom_Logl;
  float32 Read_VehYawRateSerlCom_Val;
  boolean Read_VehYawRateVldSerlCom_Logl;

  float32 PimPrevLatA;
  float32 PimPrevLtgA;
  float32 PimPrevVehSpd;
  float32 PimPrevYawRate;
  boolean PimPrevLatAVld;
  boolean PimPrevLtgAVld;
  boolean PimPrevVehSpdVld;
  boolean PimPrevYawRateVld;
  FilLpRec1 PimHwTqFilRec;
  FilLpRec1 PimLatAFilRec;

  float32 VehSigCdngDftLatA_Val_data;
  float32 VehSigCdngDftLgtA_Val_data;
  float32 VehSigCdngDftVehSpd_Val_data;
  float32 VehSigCdngDftYawRate_Val_data;
  float32 VehSigCdngLatADifThd_Val_data;
  float32 VehSigCdngLatAFilFrq_Val_data;
  float32 VehSigCdngLatASlewRate_Val_data;
  float32 VehSigCdngLtgADifThd_Val_data;
  float32 VehSigCdngLtgASlewRate_Val_data;
  float32 VehSigCdngVehSpdDifThd_Val_data;
  float32 VehSigCdngVehSpdSlewRate_Val_data;
  float32 VehSigCdngVehYawSlewRate_Val_data;
  float32 VehSigCdngYawRateDifThd_Val_data;

  float32 Call_FltInj_f32_Oper_SigPah_Arg = 0.0F;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevLatA = *TSC_VehSigCdng_Rte_Pim_PrevLatA();
  *TSC_VehSigCdng_Rte_Pim_PrevLatA() = PimPrevLatA;
  PimPrevLtgA = *TSC_VehSigCdng_Rte_Pim_PrevLtgA();
  *TSC_VehSigCdng_Rte_Pim_PrevLtgA() = PimPrevLtgA;
  PimPrevVehSpd = *TSC_VehSigCdng_Rte_Pim_PrevVehSpd();
  *TSC_VehSigCdng_Rte_Pim_PrevVehSpd() = PimPrevVehSpd;
  PimPrevYawRate = *TSC_VehSigCdng_Rte_Pim_PrevYawRate();
  *TSC_VehSigCdng_Rte_Pim_PrevYawRate() = PimPrevYawRate;
  PimPrevLatAVld = *TSC_VehSigCdng_Rte_Pim_PrevLatAVld();
  *TSC_VehSigCdng_Rte_Pim_PrevLatAVld() = PimPrevLatAVld;
  PimPrevLtgAVld = *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld();
  *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld() = PimPrevLtgAVld;
  PimPrevVehSpdVld = *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld();
  *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld() = PimPrevVehSpdVld;
  PimPrevYawRateVld = *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld();
  *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld() = PimPrevYawRateVld;
  PimHwTqFilRec = *TSC_VehSigCdng_Rte_Pim_HwTqFilRec();
  *TSC_VehSigCdng_Rte_Pim_HwTqFilRec() = PimHwTqFilRec;
  PimLatAFilRec = *TSC_VehSigCdng_Rte_Pim_LatAFilRec();
  *TSC_VehSigCdng_Rte_Pim_LatAFilRec() = PimLatAFilRec;

  VehSigCdngDftLatA_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLatA_Val();
  VehSigCdngDftLgtA_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLgtA_Val();
  VehSigCdngDftVehSpd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftVehSpd_Val();
  VehSigCdngDftYawRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngDftYawRate_Val();
  VehSigCdngLatADifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatADifThd_Val();
  VehSigCdngLatAFilFrq_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatAFilFrq_Val();
  VehSigCdngLatASlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLatASlewRate_Val();
  VehSigCdngLtgADifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgADifThd_Val();
  VehSigCdngLtgASlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgASlewRate_Val();
  VehSigCdngVehSpdDifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdDifThd_Val();
  VehSigCdngVehSpdSlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdSlewRate_Val();
  VehSigCdngVehYawSlewRate_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngVehYawSlewRate_Val();
  VehSigCdngYawRateDifThd_Val_data = TSC_VehSigCdng_Rte_Prm_VehSigCdngYawRateDifThd_Val();

  fct_status = TSC_VehSigCdng_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehLatASerlCom_Val(&Read_VehLatASerlCom_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehLatAVldSerlCom_Logl(&Read_VehLatAVldSerlCom_Logl);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehLgtASerlCom_Val(&Read_VehLgtASerlCom_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehLgtAVldSerlCom_Logl(&Read_VehLgtAVldSerlCom_Logl);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehSpdOvrd_Val(&Read_VehSpdOvrd_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehSpdOvrdEna_Logl(&Read_VehSpdOvrdEna_Logl);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehSpdSerlCom_Val(&Read_VehSpdSerlCom_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehSpdVldSerlCom_Logl(&Read_VehSpdVldSerlCom_Logl);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehYawRateSerlCom_Val(&Read_VehYawRateSerlCom_Val);
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

  fct_status = TSC_VehSigCdng_Rte_Read_VehYawRateVldSerlCom_Logl(&Read_VehYawRateVldSerlCom_Logl);
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

  fct_status = TSC_VehSigCdng_Rte_Write_VehLatA_Val(Rte_InitValue_VehLatA_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehLatAEstimd_Val(Rte_InitValue_VehLatAEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehLatAEstimdVld_Logl(Rte_InitValue_VehLatAEstimdVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehLatAVld_Logl(Rte_InitValue_VehLatAVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehLgtA_Val(Rte_InitValue_VehLgtA_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehLgtAVld_Logl(Rte_InitValue_VehLgtAVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehSpd_Val(Rte_InitValue_VehSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehSpdVld_Logl(Rte_InitValue_VehSpdVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehYawRate_Val(Rte_InitValue_VehYawRate_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Write_VehYawRateVld_Logl(Rte_InitValue_VehYawRateVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_VehSigCdng_Rte_Call_FltInj_f32_Oper(&Call_FltInj_f32_Oper_SigPah_Arg, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define VehSigCdng_STOP_SEC_CODE
#include "VehSigCdng_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
