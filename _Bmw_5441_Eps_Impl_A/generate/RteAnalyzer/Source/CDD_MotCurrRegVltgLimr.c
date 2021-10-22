/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotCurrRegVltgLimr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_MotCurrRegVltgLimr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotCurrRegVltgLimr>
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

#include "Rte_CDD_MotCurrRegVltgLimr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_MotCurrRegVltgLimr.h"


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
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
 *   float32 *Rte_Pim_AntiWdupCmdScaDax(void)
 *   float32 *Rte_Pim_AntiWdupCmdScaQax(void)
 *   float32 *Rte_Pim_CurrLoaScarPrev(void)
 *   float32 *Rte_Pim_DualEcuLoaScarPrev(void)
 *   float32 *Rte_Pim_FETLoaScarPrev(void)
 *   float32 *Rte_Pim_IvtrLoaScarPrev(void)
 *   float32 *Rte_Pim_MotCtrlMotVltgDaxPrev(void)
 *   float32 *Rte_Pim_MotCtrlMotVltgQaxPrev(void)
 *   float32 *Rte_Pim_MotVltgIntglCmdDaxPrev(void)
 *   float32 *Rte_Pim_MotVltgIntglCmdQaxPrev(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgBrdgFild(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdFinal(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdPreLim(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxFb(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxIntglPreLim(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdDax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdQax(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFb(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFfFild(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxIntglPreLim(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnIvsRat(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnRat(void)
 *   float32 *Rte_Pim_dMotCurrRegVltgLimrPhaAdvPreDly(void)
 *   FilLpRec1 *Rte_Pim_MotVltgBrdgLpFil(void)
 *   FilLpRec1 *Rte_Pim_MotVltgQaxFfLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(void)
 *   float32 Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotCurrPredTi_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val(void)
 *   float32 Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val(void)
 *   float32 Rte_Prm_MotRefMdlIvtrDeadTiBrdgVltgSca_Val(void)
 *   boolean Rte_Prm_MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl(void)
 *   boolean Rte_Prm_MotCurrRegVltgLimrMotCurrPredEna_Logl(void)
 *   boolean Rte_Prm_MotCurrRegVltgLimrMotCurrQaxRefMdfnRplEna_Logl(void)
 *   boolean Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgFilEna_Logl(void)
 *   boolean Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfFilEna_Logl(void)
 *   boolean Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl(void)
 *   boolean Rte_Prm_MotRefMdlFbCtrlDi_Logl(void)
 *
 *********************************************************************************************************************/


#define CDD_MotCurrRegVltgLimr_START_SEC_CODE
#include "CDD_MotCurrRegVltgLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotCurrRegVltgLimrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCurrRegVltgLimrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotCurrRegVltgLimr_CODE) MotCurrRegVltgLimrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCurrRegVltgLimrInit1
 *********************************************************************************************************************/

  float32 PimAntiWdupCmdScaDax;
  float32 PimAntiWdupCmdScaQax;
  float32 PimCurrLoaScarPrev;
  float32 PimDualEcuLoaScarPrev;
  float32 PimFETLoaScarPrev;
  float32 PimIvtrLoaScarPrev;
  float32 PimMotCtrlMotVltgDaxPrev;
  float32 PimMotCtrlMotVltgQaxPrev;
  float32 PimMotVltgIntglCmdDaxPrev;
  float32 PimMotVltgIntglCmdQaxPrev;
  float32 PimdMotCurrRegVltgLimrAntiWdupCmdScaDax;
  float32 PimdMotCurrRegVltgLimrAntiWdupCmdScaQax;
  float32 PimdMotCurrRegVltgLimrMotCurrCmdErrDax;
  float32 PimdMotCurrRegVltgLimrMotCurrCmdErrQax;
  float32 PimdMotCurrRegVltgLimrMotCurrCmdScaDax;
  float32 PimdMotCurrRegVltgLimrMotCurrCmdScaQax;
  float32 PimdMotCurrRegVltgLimrMotVltgBrdgFild;
  float32 PimdMotCurrRegVltgLimrMotVltgCmdFinal;
  float32 PimdMotCurrRegVltgLimrMotVltgCmdPreLim;
  float32 PimdMotCurrRegVltgLimrMotVltgDampgDax;
  float32 PimdMotCurrRegVltgLimrMotVltgDampgQax;
  float32 PimdMotCurrRegVltgLimrMotVltgDaxFb;
  float32 PimdMotCurrRegVltgLimrMotVltgDaxIntglPreLim;
  float32 PimdMotCurrRegVltgLimrMotVltgDecoupldFbDax;
  float32 PimdMotCurrRegVltgLimrMotVltgDecoupldFbQax;
  float32 PimdMotCurrRegVltgLimrMotVltgDircFbDax;
  float32 PimdMotCurrRegVltgLimrMotVltgDircFbQax;
  float32 PimdMotCurrRegVltgLimrMotVltgPreLimDax;
  float32 PimdMotCurrRegVltgLimrMotVltgPreLimQax;
  float32 PimdMotCurrRegVltgLimrMotVltgPropCmdDax;
  float32 PimdMotCurrRegVltgLimrMotVltgPropCmdQax;
  float32 PimdMotCurrRegVltgLimrMotVltgQaxFb;
  float32 PimdMotCurrRegVltgLimrMotVltgQaxFfFild;
  float32 PimdMotCurrRegVltgLimrMotVltgQaxIntglPreLim;
  float32 PimdMotCurrRegVltgLimrMotVltgSatnIvsRat;
  float32 PimdMotCurrRegVltgLimrMotVltgSatnRat;
  float32 PimdMotCurrRegVltgLimrPhaAdvPreDly;
  FilLpRec1 PimMotVltgBrdgLpFil;
  FilLpRec1 PimMotVltgQaxFfLpFil;

  float32 MotCurrRegCfgMotRVirtDax_Val_data;
  float32 MotCurrRegCfgMotRVirtQax_Val_data;
  float32 MotCurrRegVltgLimrCurrLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrDaxAntiWdupCoeff_Val_data;
  float32 MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrFETLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrMotCurrPredTi_Val_data;
  float32 MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val_data;
  float32 MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val_data;
  float32 MotCurrRegVltgLimrQaxAntiWdupCoeff_Val_data;
  float32 MotRefMdlIvtrDeadTiBrdgVltgSca_Val_data;
  boolean MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl_data;
  boolean MotCurrRegVltgLimrMotCurrPredEna_Logl_data;
  boolean MotCurrRegVltgLimrMotCurrQaxRefMdfnRplEna_Logl_data;
  boolean MotCurrRegVltgLimrMotVltgBrdgFilEna_Logl_data;
  boolean MotCurrRegVltgLimrMotVltgQaxFfFilEna_Logl_data;
  boolean MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl_data;
  boolean MotRefMdlFbCtrlDi_Logl_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAntiWdupCmdScaDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaDax() = PimAntiWdupCmdScaDax;
  PimAntiWdupCmdScaQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaQax() = PimAntiWdupCmdScaQax;
  PimCurrLoaScarPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_CurrLoaScarPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_CurrLoaScarPrev() = PimCurrLoaScarPrev;
  PimDualEcuLoaScarPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_DualEcuLoaScarPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_DualEcuLoaScarPrev() = PimDualEcuLoaScarPrev;
  PimFETLoaScarPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_FETLoaScarPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_FETLoaScarPrev() = PimFETLoaScarPrev;
  PimIvtrLoaScarPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_IvtrLoaScarPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_IvtrLoaScarPrev() = PimIvtrLoaScarPrev;
  PimMotCtrlMotVltgDaxPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgDaxPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgDaxPrev() = PimMotCtrlMotVltgDaxPrev;
  PimMotCtrlMotVltgQaxPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgQaxPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgQaxPrev() = PimMotCtrlMotVltgQaxPrev;
  PimMotVltgIntglCmdDaxPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdDaxPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdDaxPrev() = PimMotVltgIntglCmdDaxPrev;
  PimMotVltgIntglCmdQaxPrev = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdQaxPrev();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdQaxPrev() = PimMotVltgIntglCmdQaxPrev;
  PimdMotCurrRegVltgLimrAntiWdupCmdScaDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaDax() = PimdMotCurrRegVltgLimrAntiWdupCmdScaDax;
  PimdMotCurrRegVltgLimrAntiWdupCmdScaQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaQax() = PimdMotCurrRegVltgLimrAntiWdupCmdScaQax;
  PimdMotCurrRegVltgLimrMotCurrCmdErrDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrDax() = PimdMotCurrRegVltgLimrMotCurrCmdErrDax;
  PimdMotCurrRegVltgLimrMotCurrCmdErrQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrQax() = PimdMotCurrRegVltgLimrMotCurrCmdErrQax;
  PimdMotCurrRegVltgLimrMotCurrCmdScaDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaDax() = PimdMotCurrRegVltgLimrMotCurrCmdScaDax;
  PimdMotCurrRegVltgLimrMotCurrCmdScaQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaQax() = PimdMotCurrRegVltgLimrMotCurrCmdScaQax;
  PimdMotCurrRegVltgLimrMotVltgBrdgFild = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgBrdgFild();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgBrdgFild() = PimdMotCurrRegVltgLimrMotVltgBrdgFild;
  PimdMotCurrRegVltgLimrMotVltgCmdFinal = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdFinal();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdFinal() = PimdMotCurrRegVltgLimrMotVltgCmdFinal;
  PimdMotCurrRegVltgLimrMotVltgCmdPreLim = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdPreLim();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdPreLim() = PimdMotCurrRegVltgLimrMotVltgCmdPreLim;
  PimdMotCurrRegVltgLimrMotVltgDampgDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgDax() = PimdMotCurrRegVltgLimrMotVltgDampgDax;
  PimdMotCurrRegVltgLimrMotVltgDampgQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgQax() = PimdMotCurrRegVltgLimrMotVltgDampgQax;
  PimdMotCurrRegVltgLimrMotVltgDaxFb = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxFb();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxFb() = PimdMotCurrRegVltgLimrMotVltgDaxFb;
  PimdMotCurrRegVltgLimrMotVltgDaxIntglPreLim = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxIntglPreLim();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxIntglPreLim() = PimdMotCurrRegVltgLimrMotVltgDaxIntglPreLim;
  PimdMotCurrRegVltgLimrMotVltgDecoupldFbDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbDax() = PimdMotCurrRegVltgLimrMotVltgDecoupldFbDax;
  PimdMotCurrRegVltgLimrMotVltgDecoupldFbQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbQax() = PimdMotCurrRegVltgLimrMotVltgDecoupldFbQax;
  PimdMotCurrRegVltgLimrMotVltgDircFbDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbDax() = PimdMotCurrRegVltgLimrMotVltgDircFbDax;
  PimdMotCurrRegVltgLimrMotVltgDircFbQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbQax() = PimdMotCurrRegVltgLimrMotVltgDircFbQax;
  PimdMotCurrRegVltgLimrMotVltgPreLimDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimDax() = PimdMotCurrRegVltgLimrMotVltgPreLimDax;
  PimdMotCurrRegVltgLimrMotVltgPreLimQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimQax() = PimdMotCurrRegVltgLimrMotVltgPreLimQax;
  PimdMotCurrRegVltgLimrMotVltgPropCmdDax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdDax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdDax() = PimdMotCurrRegVltgLimrMotVltgPropCmdDax;
  PimdMotCurrRegVltgLimrMotVltgPropCmdQax = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdQax();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdQax() = PimdMotCurrRegVltgLimrMotVltgPropCmdQax;
  PimdMotCurrRegVltgLimrMotVltgQaxFb = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFb();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFb() = PimdMotCurrRegVltgLimrMotVltgQaxFb;
  PimdMotCurrRegVltgLimrMotVltgQaxFfFild = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFfFild();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFfFild() = PimdMotCurrRegVltgLimrMotVltgQaxFfFild;
  PimdMotCurrRegVltgLimrMotVltgQaxIntglPreLim = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxIntglPreLim();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxIntglPreLim() = PimdMotCurrRegVltgLimrMotVltgQaxIntglPreLim;
  PimdMotCurrRegVltgLimrMotVltgSatnIvsRat = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnIvsRat();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnIvsRat() = PimdMotCurrRegVltgLimrMotVltgSatnIvsRat;
  PimdMotCurrRegVltgLimrMotVltgSatnRat = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnRat();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnRat() = PimdMotCurrRegVltgLimrMotVltgSatnRat;
  PimdMotCurrRegVltgLimrPhaAdvPreDly = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrPhaAdvPreDly();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrPhaAdvPreDly() = PimdMotCurrRegVltgLimrPhaAdvPreDly;
  PimMotVltgBrdgLpFil = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgBrdgLpFil();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgBrdgLpFil() = PimMotVltgBrdgLpFil;
  PimMotVltgQaxFfLpFil = *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgQaxFfLpFil();
  *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgQaxFfLpFil() = PimMotVltgQaxFfLpFil;

  MotCurrRegCfgMotRVirtDax_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgMotRVirtDax_Val();
  MotCurrRegCfgMotRVirtQax_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgMotRVirtQax_Val();
  MotCurrRegVltgLimrCurrLoaScarSlewRate_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val();
  MotCurrRegVltgLimrDaxAntiWdupCoeff_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val();
  MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val();
  MotCurrRegVltgLimrFETLoaScarSlewRate_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val();
  MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val();
  MotCurrRegVltgLimrMotCurrPredTi_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrPredTi_Val();
  MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val();
  MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val();
  MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val();
  MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val();
  MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val();
  MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val();
  MotCurrRegVltgLimrQaxAntiWdupCoeff_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val();
  MotRefMdlIvtrDeadTiBrdgVltgSca_Val_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotRefMdlIvtrDeadTiBrdgVltgSca_Val();
  MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl();
  MotCurrRegVltgLimrMotCurrPredEna_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrPredEna_Logl();
  MotCurrRegVltgLimrMotCurrQaxRefMdfnRplEna_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrQaxRefMdfnRplEna_Logl();
  MotCurrRegVltgLimrMotVltgBrdgFilEna_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgFilEna_Logl();
  MotCurrRegVltgLimrMotVltgQaxFfFilEna_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfFilEna_Logl();
  MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl();
  MotRefMdlFbCtrlDi_Logl_data = TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotRefMdlFbCtrlDi_Logl();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_MotCurrRegVltgLimr_STOP_SEC_CODE
#include "CDD_MotCurrRegVltgLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
