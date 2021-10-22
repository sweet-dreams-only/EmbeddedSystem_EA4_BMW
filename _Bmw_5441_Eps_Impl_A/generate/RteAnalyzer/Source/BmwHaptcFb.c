/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHaptcFb.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwHaptcFb
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHaptcFb>
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
 * BmwHaptcFbIntenNr1
 *   
 *
 * BmwHaptcFbPatNr1
 *   
 *
 * HaptcFbSt1
 *   
 *
 * StsSteerAssi1
 *   
 *
 * u4p12
 *   
 *
 * u6p10
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwHaptcFb.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwHaptcFb.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwHaptcFb_TestDefines(void);


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwHaptcFbIntenNr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWHAPTCFBINTENNR_INTEN0 (0U)
 *   BMWHAPTCFBINTENNR_INTEN1 (1U)
 *   BMWHAPTCFBINTENNR_INTEN2 (2U)
 *   BMWHAPTCFBINTENNR_INTEN3 (3U)
 *   BMWHAPTCFBINTENNR_INTEN4 (4U)
 *   BMWHAPTCFBINTENNR_INTEN5 (5U)
 *   BMWHAPTCFBINTENNR_INTEN6 (6U)
 *   BMWHAPTCFBINTENNR_INTEN7 (7U)
 *   BMWHAPTCFBINTENNR_INTEN8 (8U)
 *   BMWHAPTCFBINTENNR_INTEN9 (9U)
 *   BMWHAPTCFBINTENNR_INTEN10 (10U)
 *   BMWHAPTCFBINTENNR_INTEN11 (11U)
 *   BMWHAPTCFBINTENNR_INTEN12 (12U)
 *   BMWHAPTCFBINTENNR_RESD1 (13U)
 *   BMWHAPTCFBINTENNR_RESD2 (14U)
 *   BMWHAPTCFBINTENNR_INVLDSIG (15U)
 * BmwHaptcFbPatNr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWHAPTCFBPATNR_NOHAPTCWARN (0U)
 *   BMWHAPTCFBPATNR_PAT1 (1U)
 *   BMWHAPTCFBPATNR_PAT2 (2U)
 *   BMWHAPTCFBPATNR_PAT3 (3U)
 *   BMWHAPTCFBPATNR_PAT4 (4U)
 *   BMWHAPTCFBPATNR_PAT5 (5U)
 *   BMWHAPTCFBPATNR_PAT6 (6U)
 *   BMWHAPTCFBPATNR_PAT7 (7U)
 *   BMWHAPTCFBPATNR_PAT8 (8U)
 *   BMWHAPTCFBPATNR_PAT9 (9U)
 *   BMWHAPTCFBPATNR_PAT10 (10U)
 *   BMWHAPTCFBPATNR_FCTIFNOTAVL (13U)
 *   BMWHAPTCFBPATNR_FCTRPRTERR (14U)
 *   BMWHAPTCFBPATNR_INVLDSIG (15U)
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 *   HAPTCFBST_FCTAVLNOTACTV (1U)
 *   HAPTCFBST_ERR (6U)
 *   HAPTCFBST_FCTAVLACTV (9U)
 *   HAPTCFBST_FCTNOTAVL (14U)
 *   HAPTCFBST_INVLDSIG (15U)
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 *
 * Array Types:
 * ============
 * Ary1D_f32_11: Array with 11 element(s) of type float32
 * Ary1D_u16_13: Array with 13 element(s) of type uint16
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u4p12_13: Array with 13 element(s) of type u4p12
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_13: Array with 13 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u4p12_12_12: Array with 12 element(s) of type Ary1D_u4p12_12
 * Ary2D_u4p12_13_13: Array with 13 element(s) of type Ary1D_u4p12_13
 * Ary2D_u6p10_12_12: Array with 12 element(s) of type Ary1D_u6p10_12
 * Ary2D_u6p10_13_13: Array with 13 element(s) of type Ary1D_u6p10_13
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TqOscnEnaTmr(void)
 *   BmwHaptcFbIntenNr1 *Rte_Pim_CurrInten(void)
 *   BmwHaptcFbPatNr1 *Rte_Pim_CurrPat(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_13
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_12
 *   uint16 *Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(void)
 *     Returnvalue: uint16* is of type Ary1D_u16_13
 *   u4p12 *Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   float32 *Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwHaptcFb_START_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbInit1
 *********************************************************************************************************************/

  uint32 PimTqOscnEnaTmr;
  BmwHaptcFbIntenNr1 PimCurrInten;
  BmwHaptcFbPatNr1 PimCurrPat;

  float32 BmwHaptcFbEpsDegradedFltThd_Val_data;
  Ary1D_u4p12_12 BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D_data;
  Ary1D_u4p12_13 BmwHaptcFbAmpBilnrSeln_Ary1D_data;
  Ary2D_u4p12_13_13 BmwHaptcFbAmpSelnTblY_Ary2D_data;
  Ary1D_u6p10_13 BmwHaptcFbFrqBilnrSeln_Ary1D_data;
  Ary2D_u6p10_13_13 BmwHaptcFbFrqSelnTblY_Ary2D_data;
  Ary2D_u6p10_12_12 BmwHaptcFbHwTqFrqTblY_Ary2D_data;
  Ary1D_u16_13 BmwHaptcFbIntenSelnTblX_Ary1D_data;
  Ary2D_u4p12_12_12 BmwHaptcFbMotTqAmpTblY_Ary2D_data;
  Ary1D_f32_11 BmwHaptcFbPatActvTiTblY_Ary1D_data;
  Ary1D_f32_11 BmwHaptcFbPatPasTiTblY_Ary1D_data;
  Ary1D_f32_11 BmwHaptcFbPatRisngSlewTblY_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimTqOscnEnaTmr = *TSC_BmwHaptcFb_Rte_Pim_TqOscnEnaTmr();
  *TSC_BmwHaptcFb_Rte_Pim_TqOscnEnaTmr() = PimTqOscnEnaTmr;
  PimCurrInten = *TSC_BmwHaptcFb_Rte_Pim_CurrInten();
  *TSC_BmwHaptcFb_Rte_Pim_CurrInten() = PimCurrInten;
  PimCurrPat = *TSC_BmwHaptcFb_Rte_Pim_CurrPat();
  *TSC_BmwHaptcFb_Rte_Pim_CurrPat() = PimCurrPat;

  BmwHaptcFbEpsDegradedFltThd_Val_data = TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val();
  (void)memcpy(BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(), sizeof(Ary1D_u4p12_12));
  (void)memcpy(BmwHaptcFbAmpBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(), sizeof(Ary1D_u4p12_13));
  (void)memcpy(BmwHaptcFbAmpSelnTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(), sizeof(Ary2D_u4p12_13_13));
  (void)memcpy(BmwHaptcFbFrqBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(), sizeof(Ary1D_u6p10_13));
  (void)memcpy(BmwHaptcFbFrqSelnTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(), sizeof(Ary2D_u6p10_13_13));
  (void)memcpy(BmwHaptcFbHwTqFrqTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(), sizeof(Ary2D_u6p10_12_12));
  (void)memcpy(BmwHaptcFbIntenSelnTblX_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(), sizeof(Ary1D_u16_13));
  (void)memcpy(BmwHaptcFbMotTqAmpTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(), sizeof(Ary2D_u4p12_12_12));
  (void)memcpy(BmwHaptcFbPatActvTiTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(BmwHaptcFbPatPasTiTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(BmwHaptcFbPatRisngSlewTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  BmwHaptcFb_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbPer1
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
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HaptcFbEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HaptcFbSt_Val(HaptcFbSt1 data)
 *   Std_ReturnType Rte_Write_HwOscnEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnFallRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnFrq_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnMotAmp_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnRisngRampRate_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwHaptcFbIntenNr1 Read_BmwHaptcFbIntenNr_Val;
  boolean Read_BmwHaptcFbIntenNrVld_Logl;
  BmwHaptcFbPatNr1 Read_BmwHaptcFbPatNr_Val;
  boolean Read_BmwHaptcFbPatNrVld_Logl;
  boolean Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl;
  boolean Read_HaptcFbEna_Logl;
  boolean Read_HwOscnActv_Logl;
  boolean Read_HwOscnDcThdExcdd_Logl;
  float32 Read_HwTq_Val;
  StsSteerAssi1 Read_StsSteerAssi_Val;
  float32 Read_ThermRednFac_Val;
  float32 Read_VehSpd_Val;
  boolean Read_VehSpdVld_Logl;

  uint32 PimTqOscnEnaTmr;
  BmwHaptcFbIntenNr1 PimCurrInten;
  BmwHaptcFbPatNr1 PimCurrPat;

  float32 BmwHaptcFbEpsDegradedFltThd_Val_data;
  Ary1D_u4p12_12 BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D_data;
  Ary1D_u4p12_13 BmwHaptcFbAmpBilnrSeln_Ary1D_data;
  Ary2D_u4p12_13_13 BmwHaptcFbAmpSelnTblY_Ary2D_data;
  Ary1D_u6p10_13 BmwHaptcFbFrqBilnrSeln_Ary1D_data;
  Ary2D_u6p10_13_13 BmwHaptcFbFrqSelnTblY_Ary2D_data;
  Ary2D_u6p10_12_12 BmwHaptcFbHwTqFrqTblY_Ary2D_data;
  Ary1D_u16_13 BmwHaptcFbIntenSelnTblX_Ary1D_data;
  Ary2D_u4p12_12_12 BmwHaptcFbMotTqAmpTblY_Ary2D_data;
  Ary1D_f32_11 BmwHaptcFbPatActvTiTblY_Ary1D_data;
  Ary1D_f32_11 BmwHaptcFbPatPasTiTblY_Ary1D_data;
  Ary1D_f32_11 BmwHaptcFbPatRisngSlewTblY_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimTqOscnEnaTmr = *TSC_BmwHaptcFb_Rte_Pim_TqOscnEnaTmr();
  *TSC_BmwHaptcFb_Rte_Pim_TqOscnEnaTmr() = PimTqOscnEnaTmr;
  PimCurrInten = *TSC_BmwHaptcFb_Rte_Pim_CurrInten();
  *TSC_BmwHaptcFb_Rte_Pim_CurrInten() = PimCurrInten;
  PimCurrPat = *TSC_BmwHaptcFb_Rte_Pim_CurrPat();
  *TSC_BmwHaptcFb_Rte_Pim_CurrPat() = PimCurrPat;

  BmwHaptcFbEpsDegradedFltThd_Val_data = TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val();
  (void)memcpy(BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(), sizeof(Ary1D_u4p12_12));
  (void)memcpy(BmwHaptcFbAmpBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(), sizeof(Ary1D_u4p12_13));
  (void)memcpy(BmwHaptcFbAmpSelnTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(), sizeof(Ary2D_u4p12_13_13));
  (void)memcpy(BmwHaptcFbFrqBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(), sizeof(Ary1D_u6p10_13));
  (void)memcpy(BmwHaptcFbFrqSelnTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(), sizeof(Ary2D_u6p10_13_13));
  (void)memcpy(BmwHaptcFbHwTqFrqTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(), sizeof(Ary2D_u6p10_12_12));
  (void)memcpy(BmwHaptcFbIntenSelnTblX_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(), sizeof(Ary1D_u16_13));
  (void)memcpy(BmwHaptcFbMotTqAmpTblY_Ary2D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(), sizeof(Ary2D_u4p12_12_12));
  (void)memcpy(BmwHaptcFbPatActvTiTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(BmwHaptcFbPatPasTiTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(BmwHaptcFbPatRisngSlewTblY_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(), sizeof(Ary1D_f32_11));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwHaptcFb_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbIntenNr_Val(&Read_BmwHaptcFbIntenNr_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbIntenNrVld_Logl(&Read_BmwHaptcFbIntenNrVld_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbPatNr_Val(&Read_BmwHaptcFbPatNr_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbPatNrVld_Logl(&Read_BmwHaptcFbPatNrVld_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_HaptcFbEna_Logl(&Read_HaptcFbEna_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_HwOscnActv_Logl(&Read_HwOscnActv_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_HwOscnDcThdExcdd_Logl(&Read_HwOscnDcThdExcdd_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_StsSteerAssi_Val(&Read_StsSteerAssi_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_ThermRednFac_Val(&Read_ThermRednFac_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwHaptcFb_Rte_Read_VehSpdVld_Logl(&Read_VehSpdVld_Logl);
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

  fct_status = TSC_BmwHaptcFb_Rte_Write_HaptcFbSt_Val(Rte_InitValue_HaptcFbSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Write_HwOscnEna_Logl(Rte_InitValue_HwOscnEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Write_HwOscnFallRampRate_Val(Rte_InitValue_HwOscnFallRampRate_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Write_HwOscnFrq_Val(Rte_InitValue_HwOscnFrq_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Write_HwOscnMotAmp_Val(Rte_InitValue_HwOscnMotAmp_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Write_HwOscnRisngRampRate_Val(Rte_InitValue_HwOscnRisngRampRate_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHaptcFb_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwHaptcFb_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwHaptcFb_STOP_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwHaptcFb_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_1 = BMWHAPTCFBINTENNR_INTEN0;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_2 = BMWHAPTCFBINTENNR_INTEN1;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_3 = BMWHAPTCFBINTENNR_INTEN2;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_4 = BMWHAPTCFBINTENNR_INTEN3;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_5 = BMWHAPTCFBINTENNR_INTEN4;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_6 = BMWHAPTCFBINTENNR_INTEN5;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_7 = BMWHAPTCFBINTENNR_INTEN6;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_8 = BMWHAPTCFBINTENNR_INTEN7;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_9 = BMWHAPTCFBINTENNR_INTEN8;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_10 = BMWHAPTCFBINTENNR_INTEN9;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_11 = BMWHAPTCFBINTENNR_INTEN10;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_12 = BMWHAPTCFBINTENNR_INTEN11;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_13 = BMWHAPTCFBINTENNR_INTEN12;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_14 = BMWHAPTCFBINTENNR_RESD1;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_15 = BMWHAPTCFBINTENNR_RESD2;
  BmwHaptcFbIntenNr1 Test_BmwHaptcFbIntenNr1_V_16 = BMWHAPTCFBINTENNR_INVLDSIG;

  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_1 = BMWHAPTCFBPATNR_NOHAPTCWARN;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_2 = BMWHAPTCFBPATNR_PAT1;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_3 = BMWHAPTCFBPATNR_PAT2;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_4 = BMWHAPTCFBPATNR_PAT3;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_5 = BMWHAPTCFBPATNR_PAT4;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_6 = BMWHAPTCFBPATNR_PAT5;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_7 = BMWHAPTCFBPATNR_PAT6;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_8 = BMWHAPTCFBPATNR_PAT7;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_9 = BMWHAPTCFBPATNR_PAT8;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_10 = BMWHAPTCFBPATNR_PAT9;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_11 = BMWHAPTCFBPATNR_PAT10;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_12 = BMWHAPTCFBPATNR_FCTIFNOTAVL;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_13 = BMWHAPTCFBPATNR_FCTRPRTERR;
  BmwHaptcFbPatNr1 Test_BmwHaptcFbPatNr1_V_14 = BMWHAPTCFBPATNR_INVLDSIG;

  HaptcFbSt1 Test_HaptcFbSt1_V_1 = HAPTCFBST_FCTAVLNOTACTV;
  HaptcFbSt1 Test_HaptcFbSt1_V_2 = HAPTCFBST_ERR;
  HaptcFbSt1 Test_HaptcFbSt1_V_3 = HAPTCFBST_FCTAVLACTV;
  HaptcFbSt1 Test_HaptcFbSt1_V_4 = HAPTCFBST_FCTNOTAVL;
  HaptcFbSt1 Test_HaptcFbSt1_V_5 = HAPTCFBST_INVLDSIG;

  StsSteerAssi1 Test_StsSteerAssi1_V_1 = STSSTEERASSI_OFF;
  StsSteerAssi1 Test_StsSteerAssi1_V_2 = STSSTEERASSI_ON;
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
