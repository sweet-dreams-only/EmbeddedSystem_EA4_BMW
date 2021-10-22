/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  LrnPinionCentr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  LrnPinionCentr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <LrnPinionCentr>
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

#include "Rte_LrnPinionCentr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_LrnPinionCentr.h"


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
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
 *   float32 *Rte_Pim_MaxHwPosnPrev(void)
 *   float32 *Rte_Pim_MinHwPosnPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwCentrPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwTrvlPrev(void)
 *   float32 *Rte_Pim_StCtrl1PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl2TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl4TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5IntglEnaOutpPrev(void)
 *   float32 *Rte_Pim_StCtrl5PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5TqErrRateLim(void)
 *   float32 *Rte_Pim_TarHwAg(void)
 *   float32 *Rte_Pim_TarMotVel(void)
 *   float32 *Rte_Pim_TqCmdEstimdPrev(void)
 *   float32 *Rte_Pim_dLrnPinionCentrHwPosnCmd(void)
 *   uint32 *Rte_Pim_StCtrl1TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl1TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrBRefTi(void)
 *   uint8 *Rte_Pim_StEstimdPrev(void)
 *   boolean *Rte_Pim_PinionCentrLrnEnaPrev(void)
 *   FilLpRec1 *Rte_Pim_StCtrl1RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl2RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl4RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdTqErrLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_LrnPinionCentrDampgCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqRateLim_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHwPosnErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrIntglCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMaxTqCmd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMinMotTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMotVelThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrPropCtrlGain_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiOutThd_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiThd_Val(void)
 *
 *********************************************************************************************************************/


#define LrnPinionCentr_START_SEC_CODE
#include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;

  float32 PimMaxHwPosnPrev;
  float32 PimMinHwPosnPrev;
  float32 PimPinionCentrLrnHwCentrPrev;
  float32 PimPinionCentrLrnHwTrvlPrev;
  float32 PimStCtrl1PosnErrRateLim;
  float32 PimStCtrl2TqErrRateLim;
  float32 PimStCtrl3PosnErrRateLim;
  float32 PimStCtrl3TqErrRateLim;
  float32 PimStCtrl4TqErrRateLim;
  float32 PimStCtrl5IntglEnaOutpPrev;
  float32 PimStCtrl5PosnErrRateLim;
  float32 PimStCtrl5TqErrRateLim;
  float32 PimTarHwAg;
  float32 PimTarMotVel;
  float32 PimTqCmdEstimdPrev;
  float32 PimdLrnPinionCentrHwPosnCmd;
  uint32 PimStCtrl1TmrARefTi;
  uint32 PimStCtrl1TmrBRefTi;
  uint32 PimStCtrl2TmrARefTi;
  uint32 PimStCtrl2TmrBRefTi;
  uint32 PimStCtrl3TmrARefTi;
  uint32 PimStCtrl3TmrBRefTi;
  uint32 PimStCtrl4TmrARefTi;
  uint32 PimStCtrl4TmrBRefTi;
  uint32 PimStCtrl5TmrARefTi;
  uint32 PimStCtrl5TmrBRefTi;
  uint8 PimStEstimdPrev;
  boolean PimPinionCentrLrnEnaPrev;
  FilLpRec1 PimStCtrl1RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl2RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl4RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdTqErrLpFil;

  float32 LrnPinionCentrDampgCtrlGain_Val_data;
  float32 LrnPinionCentrHldTq_Val_data;
  float32 LrnPinionCentrHldTqErrThd_Val_data;
  float32 LrnPinionCentrHldTqRateLim_Val_data;
  float32 LrnPinionCentrHwPosnErrThd_Val_data;
  float32 LrnPinionCentrIntglCtrlGain_Val_data;
  float32 LrnPinionCentrMaxTqCmd_Val_data;
  float32 LrnPinionCentrMinMotTq_Val_data;
  float32 LrnPinionCentrMotVelThd_Val_data;
  float32 LrnPinionCentrPropCtrlGain_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrnPinionCentrTiOutThd_Val_data;
  uint16 LrnPinionCentrTiThd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMaxHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev() = PimMaxHwPosnPrev;
  PimMinHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev() = PimMinHwPosnPrev;
  PimPinionCentrLrnHwCentrPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev() = PimPinionCentrLrnHwCentrPrev;
  PimPinionCentrLrnHwTrvlPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev() = PimPinionCentrLrnHwTrvlPrev;
  PimStCtrl1PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim() = PimStCtrl1PosnErrRateLim;
  PimStCtrl2TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim() = PimStCtrl2TqErrRateLim;
  PimStCtrl3PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim() = PimStCtrl3PosnErrRateLim;
  PimStCtrl3TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim() = PimStCtrl3TqErrRateLim;
  PimStCtrl4TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim() = PimStCtrl4TqErrRateLim;
  PimStCtrl5IntglEnaOutpPrev = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev() = PimStCtrl5IntglEnaOutpPrev;
  PimStCtrl5PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim() = PimStCtrl5PosnErrRateLim;
  PimStCtrl5TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim() = PimStCtrl5TqErrRateLim;
  PimTarHwAg = *TSC_LrnPinionCentr_Rte_Pim_TarHwAg();
  *TSC_LrnPinionCentr_Rte_Pim_TarHwAg() = PimTarHwAg;
  PimTarMotVel = *TSC_LrnPinionCentr_Rte_Pim_TarMotVel();
  *TSC_LrnPinionCentr_Rte_Pim_TarMotVel() = PimTarMotVel;
  PimTqCmdEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev() = PimTqCmdEstimdPrev;
  PimdLrnPinionCentrHwPosnCmd = *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd();
  *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd() = PimdLrnPinionCentrHwPosnCmd;
  PimStCtrl1TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi() = PimStCtrl1TmrARefTi;
  PimStCtrl1TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi() = PimStCtrl1TmrBRefTi;
  PimStCtrl2TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi() = PimStCtrl2TmrARefTi;
  PimStCtrl2TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi() = PimStCtrl2TmrBRefTi;
  PimStCtrl3TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi() = PimStCtrl3TmrARefTi;
  PimStCtrl3TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi() = PimStCtrl3TmrBRefTi;
  PimStCtrl4TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi() = PimStCtrl4TmrARefTi;
  PimStCtrl4TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi() = PimStCtrl4TmrBRefTi;
  PimStCtrl5TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi() = PimStCtrl5TmrARefTi;
  PimStCtrl5TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi() = PimStCtrl5TmrBRefTi;
  PimStEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev() = PimStEstimdPrev;
  PimPinionCentrLrnEnaPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev() = PimPinionCentrLrnEnaPrev;
  PimStCtrl1RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil() = PimStCtrl1RateLimdPosnErrLpFil;
  PimStCtrl2RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil() = PimStCtrl2RateLimdTqErrLpFil;
  PimStCtrl3RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil() = PimStCtrl3RateLimdPosnErrLpFil;
  PimStCtrl3RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil() = PimStCtrl3RateLimdTqErrLpFil;
  PimStCtrl4RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil() = PimStCtrl4RateLimdTqErrLpFil;
  PimStCtrl5RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil() = PimStCtrl5RateLimdPosnErrLpFil;
  PimStCtrl5RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil() = PimStCtrl5RateLimdTqErrLpFil;

  LrnPinionCentrDampgCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrDampgCtrlGain_Val();
  LrnPinionCentrHldTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTq_Val();
  LrnPinionCentrHldTqErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqErrThd_Val();
  LrnPinionCentrHldTqRateLim_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqRateLim_Val();
  LrnPinionCentrHwPosnErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHwPosnErrThd_Val();
  LrnPinionCentrIntglCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrIntglCtrlGain_Val();
  LrnPinionCentrMaxTqCmd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMaxTqCmd_Val();
  LrnPinionCentrMinMotTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMinMotTq_Val();
  LrnPinionCentrMotVelThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMotVelThd_Val();
  LrnPinionCentrPropCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrPropCtrlGain_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrnPinionCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrnPinionCentrTiOutThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiOutThd_Val();
  LrnPinionCentrTiThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiThd_Val();

  fct_status = TSC_LrnPinionCentr_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PinionCentrLrnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwCentr_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwTrvl_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnSt_Val(uint8 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarA(void)
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarVel(void)
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
 * Symbol: LrnPinionCentrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;
  float32 Read_MotVelCrf_Val;
  boolean Read_PinionCentrLrnEna_Logl;

  float32 PimMaxHwPosnPrev;
  float32 PimMinHwPosnPrev;
  float32 PimPinionCentrLrnHwCentrPrev;
  float32 PimPinionCentrLrnHwTrvlPrev;
  float32 PimStCtrl1PosnErrRateLim;
  float32 PimStCtrl2TqErrRateLim;
  float32 PimStCtrl3PosnErrRateLim;
  float32 PimStCtrl3TqErrRateLim;
  float32 PimStCtrl4TqErrRateLim;
  float32 PimStCtrl5IntglEnaOutpPrev;
  float32 PimStCtrl5PosnErrRateLim;
  float32 PimStCtrl5TqErrRateLim;
  float32 PimTarHwAg;
  float32 PimTarMotVel;
  float32 PimTqCmdEstimdPrev;
  float32 PimdLrnPinionCentrHwPosnCmd;
  uint32 PimStCtrl1TmrARefTi;
  uint32 PimStCtrl1TmrBRefTi;
  uint32 PimStCtrl2TmrARefTi;
  uint32 PimStCtrl2TmrBRefTi;
  uint32 PimStCtrl3TmrARefTi;
  uint32 PimStCtrl3TmrBRefTi;
  uint32 PimStCtrl4TmrARefTi;
  uint32 PimStCtrl4TmrBRefTi;
  uint32 PimStCtrl5TmrARefTi;
  uint32 PimStCtrl5TmrBRefTi;
  uint8 PimStEstimdPrev;
  boolean PimPinionCentrLrnEnaPrev;
  FilLpRec1 PimStCtrl1RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl2RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl4RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdTqErrLpFil;

  float32 LrnPinionCentrDampgCtrlGain_Val_data;
  float32 LrnPinionCentrHldTq_Val_data;
  float32 LrnPinionCentrHldTqErrThd_Val_data;
  float32 LrnPinionCentrHldTqRateLim_Val_data;
  float32 LrnPinionCentrHwPosnErrThd_Val_data;
  float32 LrnPinionCentrIntglCtrlGain_Val_data;
  float32 LrnPinionCentrMaxTqCmd_Val_data;
  float32 LrnPinionCentrMinMotTq_Val_data;
  float32 LrnPinionCentrMotVelThd_Val_data;
  float32 LrnPinionCentrPropCtrlGain_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrnPinionCentrTiOutThd_Val_data;
  uint16 LrnPinionCentrTiThd_Val_data;

  float32 LrnPinionCentrPer1_TarA;
  float32 LrnPinionCentrPer1_TarVel;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMaxHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev() = PimMaxHwPosnPrev;
  PimMinHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev() = PimMinHwPosnPrev;
  PimPinionCentrLrnHwCentrPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev() = PimPinionCentrLrnHwCentrPrev;
  PimPinionCentrLrnHwTrvlPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev() = PimPinionCentrLrnHwTrvlPrev;
  PimStCtrl1PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim() = PimStCtrl1PosnErrRateLim;
  PimStCtrl2TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim() = PimStCtrl2TqErrRateLim;
  PimStCtrl3PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim() = PimStCtrl3PosnErrRateLim;
  PimStCtrl3TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim() = PimStCtrl3TqErrRateLim;
  PimStCtrl4TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim() = PimStCtrl4TqErrRateLim;
  PimStCtrl5IntglEnaOutpPrev = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev() = PimStCtrl5IntglEnaOutpPrev;
  PimStCtrl5PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim() = PimStCtrl5PosnErrRateLim;
  PimStCtrl5TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim() = PimStCtrl5TqErrRateLim;
  PimTarHwAg = *TSC_LrnPinionCentr_Rte_Pim_TarHwAg();
  *TSC_LrnPinionCentr_Rte_Pim_TarHwAg() = PimTarHwAg;
  PimTarMotVel = *TSC_LrnPinionCentr_Rte_Pim_TarMotVel();
  *TSC_LrnPinionCentr_Rte_Pim_TarMotVel() = PimTarMotVel;
  PimTqCmdEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev() = PimTqCmdEstimdPrev;
  PimdLrnPinionCentrHwPosnCmd = *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd();
  *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd() = PimdLrnPinionCentrHwPosnCmd;
  PimStCtrl1TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi() = PimStCtrl1TmrARefTi;
  PimStCtrl1TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi() = PimStCtrl1TmrBRefTi;
  PimStCtrl2TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi() = PimStCtrl2TmrARefTi;
  PimStCtrl2TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi() = PimStCtrl2TmrBRefTi;
  PimStCtrl3TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi() = PimStCtrl3TmrARefTi;
  PimStCtrl3TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi() = PimStCtrl3TmrBRefTi;
  PimStCtrl4TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi() = PimStCtrl4TmrARefTi;
  PimStCtrl4TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi() = PimStCtrl4TmrBRefTi;
  PimStCtrl5TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi() = PimStCtrl5TmrARefTi;
  PimStCtrl5TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi() = PimStCtrl5TmrBRefTi;
  PimStEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev() = PimStEstimdPrev;
  PimPinionCentrLrnEnaPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev() = PimPinionCentrLrnEnaPrev;
  PimStCtrl1RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil() = PimStCtrl1RateLimdPosnErrLpFil;
  PimStCtrl2RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil() = PimStCtrl2RateLimdTqErrLpFil;
  PimStCtrl3RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil() = PimStCtrl3RateLimdPosnErrLpFil;
  PimStCtrl3RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil() = PimStCtrl3RateLimdTqErrLpFil;
  PimStCtrl4RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil() = PimStCtrl4RateLimdTqErrLpFil;
  PimStCtrl5RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil() = PimStCtrl5RateLimdPosnErrLpFil;
  PimStCtrl5RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil() = PimStCtrl5RateLimdTqErrLpFil;

  LrnPinionCentrDampgCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrDampgCtrlGain_Val();
  LrnPinionCentrHldTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTq_Val();
  LrnPinionCentrHldTqErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqErrThd_Val();
  LrnPinionCentrHldTqRateLim_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqRateLim_Val();
  LrnPinionCentrHwPosnErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHwPosnErrThd_Val();
  LrnPinionCentrIntglCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrIntglCtrlGain_Val();
  LrnPinionCentrMaxTqCmd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMaxTqCmd_Val();
  LrnPinionCentrMinMotTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMinMotTq_Val();
  LrnPinionCentrMotVelThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMotVelThd_Val();
  LrnPinionCentrPropCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrPropCtrlGain_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrnPinionCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrnPinionCentrTiOutThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiOutThd_Val();
  LrnPinionCentrTiThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiThd_Val();

  fct_status = TSC_LrnPinionCentr_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_LrnPinionCentr_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_LrnPinionCentr_Rte_Read_PinionCentrLrnEna_Logl(&Read_PinionCentrLrnEna_Logl);
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

  fct_status = TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnCmd_Val(Rte_InitValue_PinionCentrLrnCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwCentr_Val(Rte_InitValue_PinionCentrLrnHwCentr_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwTrvl_Val(Rte_InitValue_PinionCentrLrnHwTrvl_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnSt_Val(Rte_InitValue_PinionCentrLrnSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  LrnPinionCentrPer1_TarA = TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarA();
  LrnPinionCentrPer1_TarVel = TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarVel();

  fct_status = TSC_LrnPinionCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_LrnPinionCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetInpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetInpPrm>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarA(float32 data)
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarVel(float32 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetInpPrm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetInpPrm_Oper
 *********************************************************************************************************************/

  float32 PimMaxHwPosnPrev;
  float32 PimMinHwPosnPrev;
  float32 PimPinionCentrLrnHwCentrPrev;
  float32 PimPinionCentrLrnHwTrvlPrev;
  float32 PimStCtrl1PosnErrRateLim;
  float32 PimStCtrl2TqErrRateLim;
  float32 PimStCtrl3PosnErrRateLim;
  float32 PimStCtrl3TqErrRateLim;
  float32 PimStCtrl4TqErrRateLim;
  float32 PimStCtrl5IntglEnaOutpPrev;
  float32 PimStCtrl5PosnErrRateLim;
  float32 PimStCtrl5TqErrRateLim;
  float32 PimTarHwAg;
  float32 PimTarMotVel;
  float32 PimTqCmdEstimdPrev;
  float32 PimdLrnPinionCentrHwPosnCmd;
  uint32 PimStCtrl1TmrARefTi;
  uint32 PimStCtrl1TmrBRefTi;
  uint32 PimStCtrl2TmrARefTi;
  uint32 PimStCtrl2TmrBRefTi;
  uint32 PimStCtrl3TmrARefTi;
  uint32 PimStCtrl3TmrBRefTi;
  uint32 PimStCtrl4TmrARefTi;
  uint32 PimStCtrl4TmrBRefTi;
  uint32 PimStCtrl5TmrARefTi;
  uint32 PimStCtrl5TmrBRefTi;
  uint8 PimStEstimdPrev;
  boolean PimPinionCentrLrnEnaPrev;
  FilLpRec1 PimStCtrl1RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl2RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl3RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl4RateLimdTqErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdPosnErrLpFil;
  FilLpRec1 PimStCtrl5RateLimdTqErrLpFil;

  float32 LrnPinionCentrDampgCtrlGain_Val_data;
  float32 LrnPinionCentrHldTq_Val_data;
  float32 LrnPinionCentrHldTqErrThd_Val_data;
  float32 LrnPinionCentrHldTqRateLim_Val_data;
  float32 LrnPinionCentrHwPosnErrThd_Val_data;
  float32 LrnPinionCentrIntglCtrlGain_Val_data;
  float32 LrnPinionCentrMaxTqCmd_Val_data;
  float32 LrnPinionCentrMinMotTq_Val_data;
  float32 LrnPinionCentrMotVelThd_Val_data;
  float32 LrnPinionCentrPropCtrlGain_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrnPinionCentrTiOutThd_Val_data;
  uint16 LrnPinionCentrTiThd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMaxHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev() = PimMaxHwPosnPrev;
  PimMinHwPosnPrev = *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev();
  *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev() = PimMinHwPosnPrev;
  PimPinionCentrLrnHwCentrPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev() = PimPinionCentrLrnHwCentrPrev;
  PimPinionCentrLrnHwTrvlPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev() = PimPinionCentrLrnHwTrvlPrev;
  PimStCtrl1PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim() = PimStCtrl1PosnErrRateLim;
  PimStCtrl2TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim() = PimStCtrl2TqErrRateLim;
  PimStCtrl3PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim() = PimStCtrl3PosnErrRateLim;
  PimStCtrl3TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim() = PimStCtrl3TqErrRateLim;
  PimStCtrl4TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim() = PimStCtrl4TqErrRateLim;
  PimStCtrl5IntglEnaOutpPrev = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev() = PimStCtrl5IntglEnaOutpPrev;
  PimStCtrl5PosnErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim() = PimStCtrl5PosnErrRateLim;
  PimStCtrl5TqErrRateLim = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim() = PimStCtrl5TqErrRateLim;
  PimTarHwAg = *TSC_LrnPinionCentr_Rte_Pim_TarHwAg();
  *TSC_LrnPinionCentr_Rte_Pim_TarHwAg() = PimTarHwAg;
  PimTarMotVel = *TSC_LrnPinionCentr_Rte_Pim_TarMotVel();
  *TSC_LrnPinionCentr_Rte_Pim_TarMotVel() = PimTarMotVel;
  PimTqCmdEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev() = PimTqCmdEstimdPrev;
  PimdLrnPinionCentrHwPosnCmd = *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd();
  *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd() = PimdLrnPinionCentrHwPosnCmd;
  PimStCtrl1TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi() = PimStCtrl1TmrARefTi;
  PimStCtrl1TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi() = PimStCtrl1TmrBRefTi;
  PimStCtrl2TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi() = PimStCtrl2TmrARefTi;
  PimStCtrl2TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi() = PimStCtrl2TmrBRefTi;
  PimStCtrl3TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi() = PimStCtrl3TmrARefTi;
  PimStCtrl3TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi() = PimStCtrl3TmrBRefTi;
  PimStCtrl4TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi() = PimStCtrl4TmrARefTi;
  PimStCtrl4TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi() = PimStCtrl4TmrBRefTi;
  PimStCtrl5TmrARefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi() = PimStCtrl5TmrARefTi;
  PimStCtrl5TmrBRefTi = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi() = PimStCtrl5TmrBRefTi;
  PimStEstimdPrev = *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev();
  *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev() = PimStEstimdPrev;
  PimPinionCentrLrnEnaPrev = *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev();
  *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev() = PimPinionCentrLrnEnaPrev;
  PimStCtrl1RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil() = PimStCtrl1RateLimdPosnErrLpFil;
  PimStCtrl2RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil() = PimStCtrl2RateLimdTqErrLpFil;
  PimStCtrl3RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil() = PimStCtrl3RateLimdPosnErrLpFil;
  PimStCtrl3RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil() = PimStCtrl3RateLimdTqErrLpFil;
  PimStCtrl4RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil() = PimStCtrl4RateLimdTqErrLpFil;
  PimStCtrl5RateLimdPosnErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil() = PimStCtrl5RateLimdPosnErrLpFil;
  PimStCtrl5RateLimdTqErrLpFil = *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil();
  *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil() = PimStCtrl5RateLimdTqErrLpFil;

  LrnPinionCentrDampgCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrDampgCtrlGain_Val();
  LrnPinionCentrHldTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTq_Val();
  LrnPinionCentrHldTqErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqErrThd_Val();
  LrnPinionCentrHldTqRateLim_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqRateLim_Val();
  LrnPinionCentrHwPosnErrThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHwPosnErrThd_Val();
  LrnPinionCentrIntglCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrIntglCtrlGain_Val();
  LrnPinionCentrMaxTqCmd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMaxTqCmd_Val();
  LrnPinionCentrMinMotTq_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMinMotTq_Val();
  LrnPinionCentrMotVelThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMotVelThd_Val();
  LrnPinionCentrPropCtrlGain_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrPropCtrlGain_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrnPinionCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrnPinionCentrTiOutThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiOutThd_Val();
  LrnPinionCentrTiThd_Val_data = TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiThd_Val();

  TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarA(0.0F);
  TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarVel(0.0F);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define LrnPinionCentr_STOP_SEC_CODE
#include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
