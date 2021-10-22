/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  PullCmpActv.c
 *        Config:  EPS.dpa
 *     SW-C Type:  PullCmpActv
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <PullCmpActv>
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
 * u2p14
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_PullCmpActv.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_PullCmpActv.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void PullCmpActv_TestDefines(void);


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
 * u2p14: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
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
 *   float32 *Rte_Pim_CmpLrnTiDecShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiIncShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiLongTerm(void)
 *   float32 *Rte_Pim_IntgtrGainDecShoTerm(void)
 *   float32 *Rte_Pim_IntgtrGainIncShoTerm(void)
 *   float32 *Rte_Pim_PrevLrnTiLongTerm(void)
 *   float32 *Rte_Pim_PullCmpCmdRateLimPrev(void)
 *   float32 *Rte_Pim_PullCmpCmdTot(void)
 *   float32 *Rte_Pim_PullCmpLongTerm(void)
 *   float32 *Rte_Pim_PullCmpShoTerm(void)
 *   float32 *Rte_Pim_VehSpdPrev(void)
 *   float32 *Rte_Pim_VehSpdRate(void)
 *   float32 *Rte_Pim_dPullCmpActvIntgtrGainShoTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrLongTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrShoTerm(void)
 *   uint32 *Rte_Pim_RefTiEnaLrng(void)
 *   uint32 *Rte_Pim_RefTiOpstSign(void)
 *   boolean *Rte_Pim_LrngEnaPrev(void)
 *   boolean *Rte_Pim_LrngEnad(void)
 *   boolean *Rte_Pim_OpstSignPrev(void)
 *   boolean *Rte_Pim_PullCmpActvDi(void)
 *   boolean *Rte_Pim_PullCmpLongTermRst(void)
 *   boolean *Rte_Pim_PullCmpShoTermRst(void)
 *   boolean *Rte_Pim_dPullCmpActvShoTermRst(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLongTerm(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLrngEna(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilShoTerm(void)
 *   FilLpRec1 *Rte_Pim_VehYawRateLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 Rte_CData_PullCmpLongTermDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvLongTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaTiThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvOutpMaxRate_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpTotLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrMgnThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvShoTermRampTi_Val(void)
 *   float32 Rte_Prm_PullCmpActvYawRateFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_PullCmpActvEna_Logl(void)
 *   u9p7 *Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u2p14 *Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


#define PullCmpActv_START_SEC_CODE
#include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetPullCmpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetPullCmpPrm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetPullCmpPrm_Oper(float32 *PullCmpCmdTot_Arg, float32 *PullCmpShoTerm_Arg, float32 *PullCmpLongTerm_Arg, boolean *LrngEnad_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetPullCmpPrm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) GetPullCmpPrm_Oper(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpCmdTot_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpShoTerm_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpLongTerm_Arg, P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) LrngEnad_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetPullCmpPrm_Oper
 *********************************************************************************************************************/

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));

  PullCmpActv_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  NvM_RequestResultType Call_PullCmpLongTerm_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));

  TSC_PullCmpActv_Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(0.0F);

  fct_status = TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_GetErrorStatus(&Call_PullCmpLongTerm_GetErrorStatus_ErrorStatus_Arg);
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
    case RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_SetRamBlockStatus(FALSE);
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
    case RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PullCmpActvDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCustLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehLatA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehYawRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehYawRateVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PullCmpCmd_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;
  float32 Read_HwTq_Val;
  float32 Read_HwVel_Val;
  float32 Read_PinionAgConf_Val;
  boolean Read_PullCmpActvDi_Logl;
  boolean Read_PullCmpCmdDi_Logl;
  boolean Read_PullCmpCustLrngDi_Logl;
  boolean Read_PullCmpLrngDi_Logl;
  float32 Read_VehLatA_Val;
  float32 Read_VehSpd_Val;
  boolean Read_VehSpdVld_Logl;
  float32 Read_VehYawRate_Val;
  boolean Read_VehYawRateVld_Logl;

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  float32 PullCmpActvPer1_RampDwnStepSize;

  float32 Call_FltInj_f32_Oper_SigPah_Arg = 0.0F;
  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));

  fct_status = TSC_PullCmpActv_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_PinionAgConf_Val(&Read_PinionAgConf_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_PullCmpActvDi_Logl(&Read_PullCmpActvDi_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Read_PullCmpCmdDi_Logl(&Read_PullCmpCmdDi_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Read_PullCmpCustLrngDi_Logl(&Read_PullCmpCustLrngDi_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Read_PullCmpLrngDi_Logl(&Read_PullCmpLrngDi_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehLatA_Val(&Read_VehLatA_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehSpdVld_Logl(&Read_VehSpdVld_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehYawRate_Val(&Read_VehYawRate_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehYawRateVld_Logl(&Read_VehYawRateVld_Logl);
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

  fct_status = TSC_PullCmpActv_Rte_Write_PullCmpCmd_Val(Rte_InitValue_PullCmpCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  PullCmpActvPer1_RampDwnStepSize = TSC_PullCmpActv_Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize();

  fct_status = TSC_PullCmpActv_Rte_Call_FltInj_f32_Oper(&Call_FltInj_f32_Oper_SigPah_Arg, 0U);
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

  fct_status = TSC_PullCmpActv_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_PullCmpActv_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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
 * Runnable Entity Name: PullCmpActvPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_VehSpd_Val;

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));

  fct_status = TSC_PullCmpActv_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_PullCmpActv_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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
 * Runnable Entity Name: RstPullCmp_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstPullCmp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstPullCmp_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstPullCmp_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) RstPullCmp_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstPullCmp_Oper
 *********************************************************************************************************************/

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpLongTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpLongTerm>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpLongTerm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpLongTerm_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));

  fct_status = TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_SetRamBlockStatus(FALSE);
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
    case RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpShoTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpShoTerm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpShoTerm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpShoTerm_Oper
 *********************************************************************************************************************/

  float32 PimCmpLrnTiDecShoTerm;
  float32 PimCmpLrnTiIncShoTerm;
  float32 PimCmpLrnTiLongTerm;
  float32 PimIntgtrGainDecShoTerm;
  float32 PimIntgtrGainIncShoTerm;
  float32 PimPrevLrnTiLongTerm;
  float32 PimPullCmpCmdRateLimPrev;
  float32 PimPullCmpCmdTot;
  float32 PimPullCmpLongTerm;
  float32 PimPullCmpShoTerm;
  float32 PimVehSpdPrev;
  float32 PimVehSpdRate;
  float32 PimdPullCmpActvIntgtrGainShoTerm;
  float32 PimdPullCmpActvPullErrLongTerm;
  float32 PimdPullCmpActvPullErrShoTerm;
  uint32 PimRefTiEnaLrng;
  uint32 PimRefTiOpstSign;
  boolean PimLrngEnaPrev;
  boolean PimLrngEnad;
  boolean PimOpstSignPrev;
  boolean PimPullCmpActvDi;
  boolean PimPullCmpLongTermRst;
  boolean PimPullCmpShoTermRst;
  boolean PimdPullCmpActvShoTermRst;
  FilLpRec1 PimHwTqLpFilLongTerm;
  FilLpRec1 PimHwTqLpFilLrngEna;
  FilLpRec1 PimHwTqLpFilShoTerm;
  FilLpRec1 PimVehYawRateLpFil;

  float32 PullCmpLongTermDft_data;

  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean PullCmpActvEna_Logl_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmpLrnTiDecShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm() = PimCmpLrnTiDecShoTerm;
  PimCmpLrnTiIncShoTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm() = PimCmpLrnTiIncShoTerm;
  PimCmpLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm() = PimCmpLrnTiLongTerm;
  PimIntgtrGainDecShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm() = PimIntgtrGainDecShoTerm;
  PimIntgtrGainIncShoTerm = *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm();
  *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm() = PimIntgtrGainIncShoTerm;
  PimPrevLrnTiLongTerm = *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm() = PimPrevLrnTiLongTerm;
  PimPullCmpCmdRateLimPrev = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev() = PimPullCmpCmdRateLimPrev;
  PimPullCmpCmdTot = *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot();
  *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot() = PimPullCmpCmdTot;
  PimPullCmpLongTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm() = PimPullCmpLongTerm;
  PimPullCmpShoTerm = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm() = PimPullCmpShoTerm;
  PimVehSpdPrev = *TSC_PullCmpActv_Rte_Pim_VehSpdPrev();
  *TSC_PullCmpActv_Rte_Pim_VehSpdPrev() = PimVehSpdPrev;
  PimVehSpdRate = *TSC_PullCmpActv_Rte_Pim_VehSpdRate();
  *TSC_PullCmpActv_Rte_Pim_VehSpdRate() = PimVehSpdRate;
  PimdPullCmpActvIntgtrGainShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = PimdPullCmpActvIntgtrGainShoTerm;
  PimdPullCmpActvPullErrLongTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm() = PimdPullCmpActvPullErrLongTerm;
  PimdPullCmpActvPullErrShoTerm = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm() = PimdPullCmpActvPullErrShoTerm;
  PimRefTiEnaLrng = *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng();
  *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng() = PimRefTiEnaLrng;
  PimRefTiOpstSign = *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign();
  *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign() = PimRefTiOpstSign;
  PimLrngEnaPrev = *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev();
  *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev() = PimLrngEnaPrev;
  PimLrngEnad = *TSC_PullCmpActv_Rte_Pim_LrngEnad();
  *TSC_PullCmpActv_Rte_Pim_LrngEnad() = PimLrngEnad;
  PimOpstSignPrev = *TSC_PullCmpActv_Rte_Pim_OpstSignPrev();
  *TSC_PullCmpActv_Rte_Pim_OpstSignPrev() = PimOpstSignPrev;
  PimPullCmpActvDi = *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi();
  *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi() = PimPullCmpActvDi;
  PimPullCmpLongTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst() = PimPullCmpLongTermRst;
  PimPullCmpShoTermRst = *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst() = PimPullCmpShoTermRst;
  PimdPullCmpActvShoTermRst = *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst();
  *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst() = PimdPullCmpActvShoTermRst;
  PimHwTqLpFilLongTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm() = PimHwTqLpFilLongTerm;
  PimHwTqLpFilLrngEna = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna() = PimHwTqLpFilLrngEna;
  PimHwTqLpFilShoTerm = *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm();
  *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm() = PimHwTqLpFilShoTerm;
  PimVehYawRateLpFil = *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil();
  *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil() = PimVehYawRateLpFil;

  PullCmpLongTermDft_data = TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft();

  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
  PullCmpActvLongTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val();
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
  PullCmpActvLrngEnaTiThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
  PullCmpActvOutpMaxRate_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val();
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
  PullCmpActvPullCmpTotLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val();
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
  PullCmpActvPullErrMgnThd_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val();
  PullCmpActvPullErrShoTermLim_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
  PullCmpActvShoTermRampTi_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val();
  PullCmpActvYawRateFilFrq_Val_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val();
  PullCmpActvEna_Logl_data = TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl();
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(), sizeof(Ary1D_u2p14_4));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define PullCmpActv_STOP_SEC_CODE
#include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void PullCmpActv_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;
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
