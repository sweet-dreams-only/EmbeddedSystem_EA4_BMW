/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwTqOvrlCdngAndDrvgDynFac.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwTqOvrlCdngAndDrvgDynFac
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwTqOvrlCdngAndDrvgDynFac>
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
 * DrvgDynIfSt1
 *   
 *
 * u11p5
 *   
 *
 * u1p15
 *   
 *
 * u2p14
 *   
 *
 * u4p12
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwTqOvrlCdngAndDrvgDynFac.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwTqOvrlCdngAndDrvgDynFac.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwTqOvrlCdngAndDrvgDynFac_TestDefines(void);


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
 * u11p5: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
 *
 * Array Types:
 * ============
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u1p15_12: Array with 12 element(s) of type u1p15
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u1p15_12_12: Array with 12 element(s) of type Ary1D_u1p15_12
 * Ary2D_u2p14_12_12: Array with 12 element(s) of type Ary1D_u2p14_12
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
 *   float32 *Rte_Pim_BmwOutpTqOvrlCmdStVari(void)
 *   float32 *Rte_Pim_DampgCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_EffortCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_FrznBmwTarSteerTqDrvrActr(void)
 *   float32 *Rte_Pim_LimdCdndTqOvrl(void)
 *   float32 *Rte_Pim_RtnCmdScaRateLimrStVari(void)
 *   uint32 *Rte_Pim_MsgCycTmr(void)
 *   DrvgDynIfSt1 *Rte_Pim_PrevDrvgDynIfSt(void)
 *   boolean *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl(void)
 *   boolean *Rte_Pim_FrznSigActv(void)
 *   boolean *Rte_Pim_PrevDampgSlewInProgs(void)
 *   boolean *Rte_Pim_PrevDrvgDynActv(void)
 *   boolean *Rte_Pim_PrevEffortSlewInProgs(void)
 *   boolean *Rte_Pim_PrevRtnSlewInProgs(void)
 *   boolean *Rte_Pim_RampToZeroEnad(void)
 *   FilLpRec1 *Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void)
 *   u11p5 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u1p15 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u2p14 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u9p7 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwTqOvrlCdngAndDrvgDynFac_START_SEC_CODE
#include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacInit1
 *********************************************************************************************************************/

  float32 PimBmwOutpTqOvrlCmdStVari;
  float32 PimDampgCmdScaRateLimrStVari;
  float32 PimEffortCmdScaRateLimrStVari;
  float32 PimFrznBmwTarSteerTqDrvrActr;
  float32 PimLimdCdndTqOvrl;
  float32 PimRtnCmdScaRateLimrStVari;
  uint32 PimMsgCycTmr;
  DrvgDynIfSt1 PimPrevDrvgDynIfSt;
  boolean PimBmwOutpTqOvrlCmdRampCmpl;
  boolean PimFrznSigActv;
  boolean PimPrevDampgSlewInProgs;
  boolean PimPrevDrvgDynActv;
  boolean PimPrevEffortSlewInProgs;
  boolean PimPrevRtnSlewInProgs;
  boolean PimRampToZeroEnad;
  FilLpRec1 PimBmwTarSteerTqDrvrActrLpFilStVari;

  float32 BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val_data;
  Ary1D_u11p5_12 BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D_data;
  Ary2D_u1p15_12_12 BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D_data;
  Ary1D_u4p12_12 BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D_data;
  Ary2D_u2p14_12_12 BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D_data;
  Ary1D_u4p12_10 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D_data;
  Ary1D_u9p7_10 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwOutpTqOvrlCmdStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari() = PimBmwOutpTqOvrlCmdStVari;
  PimDampgCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari() = PimDampgCmdScaRateLimrStVari;
  PimEffortCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari() = PimEffortCmdScaRateLimrStVari;
  PimFrznBmwTarSteerTqDrvrActr = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr() = PimFrznBmwTarSteerTqDrvrActr;
  PimLimdCdndTqOvrl = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl() = PimLimdCdndTqOvrl;
  PimRtnCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari() = PimRtnCmdScaRateLimrStVari;
  PimMsgCycTmr = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr() = PimMsgCycTmr;
  PimPrevDrvgDynIfSt = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt() = PimPrevDrvgDynIfSt;
  PimBmwOutpTqOvrlCmdRampCmpl = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() = PimBmwOutpTqOvrlCmdRampCmpl;
  PimFrznSigActv = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv() = PimFrznSigActv;
  PimPrevDampgSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs() = PimPrevDampgSlewInProgs;
  PimPrevDrvgDynActv = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv() = PimPrevDrvgDynActv;
  PimPrevEffortSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs() = PimPrevEffortSlewInProgs;
  PimPrevRtnSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs() = PimPrevRtnSlewInProgs;
  PimRampToZeroEnad = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad() = PimRampToZeroEnad;
  PimBmwTarSteerTqDrvrActrLpFilStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari() = PimBmwTarSteerTqDrvrActrLpFilStVari;

  BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val();
  BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val();
  BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val();
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(), sizeof(Ary2D_u1p15_12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(), sizeof(Ary1D_u4p12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(), sizeof(Ary2D_u2p14_12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(), sizeof(Ary1D_u9p7_10));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  BmwTqOvrlCdngAndDrvgDynFac_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynDampgFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynEffortFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynRtnFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynFacEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_OutpTqOvrlRampInEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_EffortCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_RtnCmdSca_Val(float32 data)
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
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwDrvgDynDampgFacReq_Val;
  float32 Read_BmwDrvgDynEffortFacReq_Val;
  boolean Read_BmwDrvgDynErrIfActv_Logl;
  float32 Read_BmwDrvgDynRtnFacReq_Val;
  boolean Read_BmwOutpTqOvrlCmdEna_Logl;
  float32 Read_BmwTarSteerTqDrvrActr_Val;
  boolean Read_DrvgDynActv_Logl;
  boolean Read_DrvgDynFacEna_Logl;
  DrvgDynIfSt1 Read_DrvgDynIfSt_Val;
  float32 Read_HwTq_Val;
  float32 Read_MotVelCrf_Val;
  boolean Read_OutpTqOvrlRampInEna_Logl;
  float32 Read_VehSpd_Val;

  float32 PimBmwOutpTqOvrlCmdStVari;
  float32 PimDampgCmdScaRateLimrStVari;
  float32 PimEffortCmdScaRateLimrStVari;
  float32 PimFrznBmwTarSteerTqDrvrActr;
  float32 PimLimdCdndTqOvrl;
  float32 PimRtnCmdScaRateLimrStVari;
  uint32 PimMsgCycTmr;
  DrvgDynIfSt1 PimPrevDrvgDynIfSt;
  boolean PimBmwOutpTqOvrlCmdRampCmpl;
  boolean PimFrznSigActv;
  boolean PimPrevDampgSlewInProgs;
  boolean PimPrevDrvgDynActv;
  boolean PimPrevEffortSlewInProgs;
  boolean PimPrevRtnSlewInProgs;
  boolean PimRampToZeroEnad;
  FilLpRec1 PimBmwTarSteerTqDrvrActrLpFilStVari;

  float32 BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val_data;
  float32 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val_data;
  Ary1D_u11p5_12 BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D_data;
  Ary2D_u1p15_12_12 BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D_data;
  Ary1D_u4p12_12 BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D_data;
  Ary2D_u2p14_12_12 BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D_data;
  Ary1D_u4p12_10 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D_data;
  Ary1D_u9p7_10 BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  float32 Call_FltInj_f32_Oper_SigPah_Arg = 0.0F;
  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwOutpTqOvrlCmdStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari() = PimBmwOutpTqOvrlCmdStVari;
  PimDampgCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari() = PimDampgCmdScaRateLimrStVari;
  PimEffortCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari() = PimEffortCmdScaRateLimrStVari;
  PimFrznBmwTarSteerTqDrvrActr = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr() = PimFrznBmwTarSteerTqDrvrActr;
  PimLimdCdndTqOvrl = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl() = PimLimdCdndTqOvrl;
  PimRtnCmdScaRateLimrStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari() = PimRtnCmdScaRateLimrStVari;
  PimMsgCycTmr = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr() = PimMsgCycTmr;
  PimPrevDrvgDynIfSt = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt() = PimPrevDrvgDynIfSt;
  PimBmwOutpTqOvrlCmdRampCmpl = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() = PimBmwOutpTqOvrlCmdRampCmpl;
  PimFrznSigActv = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv() = PimFrznSigActv;
  PimPrevDampgSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs() = PimPrevDampgSlewInProgs;
  PimPrevDrvgDynActv = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv() = PimPrevDrvgDynActv;
  PimPrevEffortSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs() = PimPrevEffortSlewInProgs;
  PimPrevRtnSlewInProgs = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs() = PimPrevRtnSlewInProgs;
  PimRampToZeroEnad = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad() = PimRampToZeroEnad;
  PimBmwTarSteerTqDrvrActrLpFilStVari = *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari();
  *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari() = PimBmwTarSteerTqDrvrActrLpFilStVari;

  BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val();
  BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val();
  BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val();
  BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val_data = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val();
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(), sizeof(Ary2D_u1p15_12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(), sizeof(Ary1D_u4p12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(), sizeof(Ary2D_u2p14_12_12));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(), sizeof(Ary1D_u9p7_10));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynDampgFacReq_Val(&Read_BmwDrvgDynDampgFacReq_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynEffortFacReq_Val(&Read_BmwDrvgDynEffortFacReq_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynErrIfActv_Logl(&Read_BmwDrvgDynErrIfActv_Logl);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynRtnFacReq_Val(&Read_BmwDrvgDynRtnFacReq_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwOutpTqOvrlCmdEna_Logl(&Read_BmwOutpTqOvrlCmdEna_Logl);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwTarSteerTqDrvrActr_Val(&Read_BmwTarSteerTqDrvrActr_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynActv_Logl(&Read_DrvgDynActv_Logl);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynFacEna_Logl(&Read_DrvgDynFacEna_Logl);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynIfSt_Val(&Read_DrvgDynIfSt_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_OutpTqOvrlRampInEna_Logl(&Read_OutpTqOvrlRampInEna_Logl);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_BmwOutpTqOvrlCmd_Val(Rte_InitValue_BmwOutpTqOvrlCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_DampgCmdSca_Val(Rte_InitValue_DampgCmdSca_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_EffortCmdSca_Val(Rte_InitValue_EffortCmdSca_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_RtnCmdSca_Val(Rte_InitValue_RtnCmdSca_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_FltInj_f32_Oper(&Call_FltInj_f32_Oper_SigPah_Arg, 0U);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwTqOvrlCdngAndDrvgDynFac_STOP_SEC_CODE
#include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwTqOvrlCdngAndDrvgDynFac_TestDefines(void)
{
  /* Enumeration Data Types */

  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_1 = DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_2 = DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_3 = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_4 = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_5 = DRVGDYNIFST_SRVNOTAVLERR;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_6 = DRVGDYNIFST_IFINID;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_7 = DRVGDYNIFST_SRVNOTAVLSTBPMA;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_8 = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_9 = DRVGDYNIFST_INVLDSIG;
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
