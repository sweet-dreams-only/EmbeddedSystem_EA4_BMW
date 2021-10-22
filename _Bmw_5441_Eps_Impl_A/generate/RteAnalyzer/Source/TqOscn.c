/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TqOscn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  TqOscn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <TqOscn>
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
 * u5p11
 *   
 *
 * u8p8
 *   
 *
 *********************************************************************************************************************/

#include "Rte_TqOscn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_TqOscn.h"


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
 * u5p11: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u5p11_11: Array with 11 element(s) of type u5p11
 * Ary1D_u8p8_11: Array with 11 element(s) of type u8p8
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
 *   float32 *Rte_Pim_AmpRampSt(void)
 *   float32 *Rte_Pim_PrevFallRampRate(void)
 *   float32 *Rte_Pim_PrevLimdAmp(void)
 *   float32 *Rte_Pim_PrevPhaAg(void)
 *   float32 *Rte_Pim_PrevPhaAgInc(void)
 *   float32 *Rte_Pim_PrevRisngRampRate(void)
 *   float32 *Rte_Pim_dTqOscnPreFinalCmd(void)
 *   float32 *Rte_Pim_dTqOscnRateLimdAmp(void)
 *   float32 *Rte_Pim_dTqOscnSinCmd(void)
 *   boolean *Rte_Pim_PrevActv(void)
 *   boolean *Rte_Pim_PrevDcThdExcdd(void)
 *   boolean *Rte_Pim_PrevEna(void)
 *   boolean *Rte_Pim_dTqOscnNonZeroAmpFlg(void)
 *   FilLpRec1 *Rte_Pim_PreFinalCmdLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_TqOscnFallRampRateCal_Val(void)
 *   float32 Rte_Prm_TqOscnRisngRampRateCal_Val(void)
 *   boolean Rte_Prm_TqOscnUseRampRateCal_Logl(void)
 *   u5p11 *Rte_Prm_TqOscnAmpLimY_Ary1D(void)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_11
 *   u8p8 *Rte_Prm_TqOscnFrqIn_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_11
 *
 *********************************************************************************************************************/


#define TqOscn_START_SEC_CODE
#include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TqOscnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TqOscn_CODE) TqOscnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TqOscnInit1
 *********************************************************************************************************************/

  float32 PimAmpRampSt;
  float32 PimPrevFallRampRate;
  float32 PimPrevLimdAmp;
  float32 PimPrevPhaAg;
  float32 PimPrevPhaAgInc;
  float32 PimPrevRisngRampRate;
  float32 PimdTqOscnPreFinalCmd;
  float32 PimdTqOscnRateLimdAmp;
  float32 PimdTqOscnSinCmd;
  boolean PimPrevActv;
  boolean PimPrevDcThdExcdd;
  boolean PimPrevEna;
  boolean PimdTqOscnNonZeroAmpFlg;
  FilLpRec1 PimPreFinalCmdLpFil;

  float32 TqOscnFallRampRateCal_Val_data;
  float32 TqOscnRisngRampRateCal_Val_data;
  boolean TqOscnUseRampRateCal_Logl_data;
  Ary1D_u5p11_11 TqOscnAmpLimY_Ary1D_data;
  Ary1D_u8p8_11 TqOscnFrqIn_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAmpRampSt = *TSC_TqOscn_Rte_Pim_AmpRampSt();
  *TSC_TqOscn_Rte_Pim_AmpRampSt() = PimAmpRampSt;
  PimPrevFallRampRate = *TSC_TqOscn_Rte_Pim_PrevFallRampRate();
  *TSC_TqOscn_Rte_Pim_PrevFallRampRate() = PimPrevFallRampRate;
  PimPrevLimdAmp = *TSC_TqOscn_Rte_Pim_PrevLimdAmp();
  *TSC_TqOscn_Rte_Pim_PrevLimdAmp() = PimPrevLimdAmp;
  PimPrevPhaAg = *TSC_TqOscn_Rte_Pim_PrevPhaAg();
  *TSC_TqOscn_Rte_Pim_PrevPhaAg() = PimPrevPhaAg;
  PimPrevPhaAgInc = *TSC_TqOscn_Rte_Pim_PrevPhaAgInc();
  *TSC_TqOscn_Rte_Pim_PrevPhaAgInc() = PimPrevPhaAgInc;
  PimPrevRisngRampRate = *TSC_TqOscn_Rte_Pim_PrevRisngRampRate();
  *TSC_TqOscn_Rte_Pim_PrevRisngRampRate() = PimPrevRisngRampRate;
  PimdTqOscnPreFinalCmd = *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd();
  *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd() = PimdTqOscnPreFinalCmd;
  PimdTqOscnRateLimdAmp = *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp();
  *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp() = PimdTqOscnRateLimdAmp;
  PimdTqOscnSinCmd = *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd();
  *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd() = PimdTqOscnSinCmd;
  PimPrevActv = *TSC_TqOscn_Rte_Pim_PrevActv();
  *TSC_TqOscn_Rte_Pim_PrevActv() = PimPrevActv;
  PimPrevDcThdExcdd = *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd();
  *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd() = PimPrevDcThdExcdd;
  PimPrevEna = *TSC_TqOscn_Rte_Pim_PrevEna();
  *TSC_TqOscn_Rte_Pim_PrevEna() = PimPrevEna;
  PimdTqOscnNonZeroAmpFlg = *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg();
  *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg() = PimdTqOscnNonZeroAmpFlg;
  PimPreFinalCmdLpFil = *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil();
  *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil() = PimPreFinalCmdLpFil;

  TqOscnFallRampRateCal_Val_data = TSC_TqOscn_Rte_Prm_TqOscnFallRampRateCal_Val();
  TqOscnRisngRampRateCal_Val_data = TSC_TqOscn_Rte_Prm_TqOscnRisngRampRateCal_Val();
  TqOscnUseRampRateCal_Logl_data = TSC_TqOscn_Rte_Prm_TqOscnUseRampRateCal_Logl();
  (void)memcpy(TqOscnAmpLimY_Ary1D_data, TSC_TqOscn_Rte_Prm_TqOscnAmpLimY_Ary1D(), sizeof(Ary1D_u5p11_11));
  (void)memcpy(TqOscnFrqIn_Ary1D_data, TSC_TqOscn_Rte_Prm_TqOscnFrqIn_Ary1D(), sizeof(Ary1D_u8p8_11));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnPer1
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
 *   Std_ReturnType Rte_Read_HwOscnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnFallRampRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnFrq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnMotAmp_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnRisngRampRate_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwOscnActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnDcThdExcdd_Logl(boolean data)
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
 * Symbol: TqOscnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TqOscn_CODE) TqOscnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TqOscnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_HwOscnEna_Logl;
  float32 Read_HwOscnFallRampRate_Val;
  float32 Read_HwOscnFrq_Val;
  float32 Read_HwOscnMotAmp_Val;
  float32 Read_HwOscnRisngRampRate_Val;

  float32 PimAmpRampSt;
  float32 PimPrevFallRampRate;
  float32 PimPrevLimdAmp;
  float32 PimPrevPhaAg;
  float32 PimPrevPhaAgInc;
  float32 PimPrevRisngRampRate;
  float32 PimdTqOscnPreFinalCmd;
  float32 PimdTqOscnRateLimdAmp;
  float32 PimdTqOscnSinCmd;
  boolean PimPrevActv;
  boolean PimPrevDcThdExcdd;
  boolean PimPrevEna;
  boolean PimdTqOscnNonZeroAmpFlg;
  FilLpRec1 PimPreFinalCmdLpFil;

  float32 TqOscnFallRampRateCal_Val_data;
  float32 TqOscnRisngRampRateCal_Val_data;
  boolean TqOscnUseRampRateCal_Logl_data;
  Ary1D_u5p11_11 TqOscnAmpLimY_Ary1D_data;
  Ary1D_u8p8_11 TqOscnFrqIn_Ary1D_data;

  float32 Call_FltInj_f32_Oper_SigPah_Arg = 0.0F;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAmpRampSt = *TSC_TqOscn_Rte_Pim_AmpRampSt();
  *TSC_TqOscn_Rte_Pim_AmpRampSt() = PimAmpRampSt;
  PimPrevFallRampRate = *TSC_TqOscn_Rte_Pim_PrevFallRampRate();
  *TSC_TqOscn_Rte_Pim_PrevFallRampRate() = PimPrevFallRampRate;
  PimPrevLimdAmp = *TSC_TqOscn_Rte_Pim_PrevLimdAmp();
  *TSC_TqOscn_Rte_Pim_PrevLimdAmp() = PimPrevLimdAmp;
  PimPrevPhaAg = *TSC_TqOscn_Rte_Pim_PrevPhaAg();
  *TSC_TqOscn_Rte_Pim_PrevPhaAg() = PimPrevPhaAg;
  PimPrevPhaAgInc = *TSC_TqOscn_Rte_Pim_PrevPhaAgInc();
  *TSC_TqOscn_Rte_Pim_PrevPhaAgInc() = PimPrevPhaAgInc;
  PimPrevRisngRampRate = *TSC_TqOscn_Rte_Pim_PrevRisngRampRate();
  *TSC_TqOscn_Rte_Pim_PrevRisngRampRate() = PimPrevRisngRampRate;
  PimdTqOscnPreFinalCmd = *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd();
  *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd() = PimdTqOscnPreFinalCmd;
  PimdTqOscnRateLimdAmp = *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp();
  *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp() = PimdTqOscnRateLimdAmp;
  PimdTqOscnSinCmd = *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd();
  *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd() = PimdTqOscnSinCmd;
  PimPrevActv = *TSC_TqOscn_Rte_Pim_PrevActv();
  *TSC_TqOscn_Rte_Pim_PrevActv() = PimPrevActv;
  PimPrevDcThdExcdd = *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd();
  *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd() = PimPrevDcThdExcdd;
  PimPrevEna = *TSC_TqOscn_Rte_Pim_PrevEna();
  *TSC_TqOscn_Rte_Pim_PrevEna() = PimPrevEna;
  PimdTqOscnNonZeroAmpFlg = *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg();
  *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg() = PimdTqOscnNonZeroAmpFlg;
  PimPreFinalCmdLpFil = *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil();
  *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil() = PimPreFinalCmdLpFil;

  TqOscnFallRampRateCal_Val_data = TSC_TqOscn_Rte_Prm_TqOscnFallRampRateCal_Val();
  TqOscnRisngRampRateCal_Val_data = TSC_TqOscn_Rte_Prm_TqOscnRisngRampRateCal_Val();
  TqOscnUseRampRateCal_Logl_data = TSC_TqOscn_Rte_Prm_TqOscnUseRampRateCal_Logl();
  (void)memcpy(TqOscnAmpLimY_Ary1D_data, TSC_TqOscn_Rte_Prm_TqOscnAmpLimY_Ary1D(), sizeof(Ary1D_u5p11_11));
  (void)memcpy(TqOscnFrqIn_Ary1D_data, TSC_TqOscn_Rte_Prm_TqOscnFrqIn_Ary1D(), sizeof(Ary1D_u8p8_11));

  fct_status = TSC_TqOscn_Rte_Read_HwOscnEna_Logl(&Read_HwOscnEna_Logl);
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

  fct_status = TSC_TqOscn_Rte_Read_HwOscnFallRampRate_Val(&Read_HwOscnFallRampRate_Val);
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

  fct_status = TSC_TqOscn_Rte_Read_HwOscnFrq_Val(&Read_HwOscnFrq_Val);
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

  fct_status = TSC_TqOscn_Rte_Read_HwOscnMotAmp_Val(&Read_HwOscnMotAmp_Val);
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

  fct_status = TSC_TqOscn_Rte_Read_HwOscnRisngRampRate_Val(&Read_HwOscnRisngRampRate_Val);
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

  fct_status = TSC_TqOscn_Rte_Write_HwOscnActv_Logl(Rte_InitValue_HwOscnActv_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TqOscn_Rte_Write_HwOscnCmd_Val(Rte_InitValue_HwOscnCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TqOscn_Rte_Write_HwOscnDcThdExcdd_Logl(Rte_InitValue_HwOscnDcThdExcdd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TqOscn_Rte_Call_FltInj_f32_Oper(&Call_FltInj_f32_Oper_SigPah_Arg, 0U);
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


#define TqOscn_STOP_SEC_CODE
#include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
