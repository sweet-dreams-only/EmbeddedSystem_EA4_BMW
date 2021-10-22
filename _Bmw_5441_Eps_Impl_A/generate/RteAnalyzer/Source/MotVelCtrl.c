/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MotVelCtrl.c
 *        Config:  EPS.dpa
 *     SW-C Type:  MotVelCtrl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <MotVelCtrl>
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

#include "Rte_MotVelCtrl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MotVelCtrl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void MotVelCtrl_TestDefines(void);


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
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_MotVelTar(void)
 *   float32 *Rte_Pim_PrevAntiWdupCmd(void)
 *   float32 *Rte_Pim_PrevDerivtvOutp(void)
 *   float32 *Rte_Pim_PrevIntgtrInp(void)
 *   float32 *Rte_Pim_PrevIntgtrOutp(void)
 *   float32 *Rte_Pim_PrevMotVelErr(void)
 *   float32 *Rte_Pim_PrevMotVelTar(void)
 *   float32 *Rte_Pim_VelSlewRate(void)
 *   uint32 *Rte_Pim_RefTiRampDwn(void)
 *   boolean *Rte_Pim_EnaCtrl(void)
 *   boolean *Rte_Pim_EnaCtrlStVari(void)
 *   boolean *Rte_Pim_FctActvSts(void)
 *   boolean *Rte_Pim_RampDwnCmpl(void)
 *
 *********************************************************************************************************************/


#define MotVelCtrl_START_SEC_CODE
#include "MotVelCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetCtrlPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetCtrlPrm>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupGain(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupLim(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_DerivtvGain(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_DerivtvLpFilTiCon(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_IntgtrGain(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_PropGain(void)
 *   float32 Rte_IrvRead_GetCtrlPrm_Oper_TqCmdLim(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetCtrlPrm_Oper(float32 *MotVelCtrlPropGain_Arg, float32 *MotVelCtrlIntgtrGain_Arg, float32 *MotVelCtrlDerivtvGain_Arg, float32 *MotVelCtrlAntiWdupLim_Arg, float32 *MotVelCtrlAntiWdupGain_Arg, float32 *MotVelCtrlDerivtvLpFilTiCon_Arg, float32 *MotVelCtrlTqCmdLim_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCtrlPrm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) GetCtrlPrm_Oper(P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlPropGain_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlIntgtrGain_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlDerivtvGain_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlAntiWdupLim_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlAntiWdupGain_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlDerivtvLpFilTiCon_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTVELCTRL_APPL_VAR) MotVelCtrlTqCmdLim_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetCtrlPrm_Oper
 *********************************************************************************************************************/

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  float32 GetCtrlPrm_Oper_AntiWdupGain;
  float32 GetCtrlPrm_Oper_AntiWdupLim;
  float32 GetCtrlPrm_Oper_DerivtvGain;
  float32 GetCtrlPrm_Oper_DerivtvLpFilTiCon;
  float32 GetCtrlPrm_Oper_IntgtrGain;
  float32 GetCtrlPrm_Oper_PropGain;
  float32 GetCtrlPrm_Oper_TqCmdLim;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;

  GetCtrlPrm_Oper_AntiWdupGain = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupGain();
  GetCtrlPrm_Oper_AntiWdupLim = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupLim();
  GetCtrlPrm_Oper_DerivtvGain = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvGain();
  GetCtrlPrm_Oper_DerivtvLpFilTiCon = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvLpFilTiCon();
  GetCtrlPrm_Oper_IntgtrGain = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_IntgtrGain();
  GetCtrlPrm_Oper_PropGain = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_PropGain();
  GetCtrlPrm_Oper_TqCmdLim = TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_TqCmdLim();

  MotVelCtrl_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVelCtrlInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelCtrlInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) MotVelCtrlInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelCtrlInit1
 *********************************************************************************************************************/

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVelCtrlPer1
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
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_MotVelCtrlPer1_AntiWdupGain(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_AntiWdupLim(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_DerivtvGain(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_DerivtvLpFilTiCon(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_IntgtrGain(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_PropGain(void)
 *   float32 Rte_IrvRead_MotVelCtrlPer1_TqCmdLim(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetManTqCmd_Oper(float32 ManTqCmd, boolean ManTqCmdEna)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetManTqCmd1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelCtrlPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) MotVelCtrlPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelCtrlPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_MotVelCrf_Val;

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  float32 MotVelCtrlPer1_AntiWdupGain;
  float32 MotVelCtrlPer1_AntiWdupLim;
  float32 MotVelCtrlPer1_DerivtvGain;
  float32 MotVelCtrlPer1_DerivtvLpFilTiCon;
  float32 MotVelCtrlPer1_IntgtrGain;
  float32 MotVelCtrlPer1_PropGain;
  float32 MotVelCtrlPer1_TqCmdLim;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;

  fct_status = TSC_MotVelCtrl_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  MotVelCtrlPer1_AntiWdupGain = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupGain();
  MotVelCtrlPer1_AntiWdupLim = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupLim();
  MotVelCtrlPer1_DerivtvGain = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvGain();
  MotVelCtrlPer1_DerivtvLpFilTiCon = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvLpFilTiCon();
  MotVelCtrlPer1_IntgtrGain = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_IntgtrGain();
  MotVelCtrlPer1_PropGain = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_PropGain();
  MotVelCtrlPer1_TqCmdLim = TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_TqCmdLim();

  fct_status = TSC_MotVelCtrl_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_MotVelCtrl_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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

  fct_status = TSC_MotVelCtrl_Rte_Call_SetManTqCmd_Oper(0.0F, FALSE);
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
    case RTE_E_SetManTqCmd1_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetCtrlPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetCtrlPrm>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupGain(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupLim(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvGain(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvLpFilTiCon(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_IntgtrGain(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_PropGain(float32 data)
 *   void Rte_IrvWrite_SetCtrlPrm_Oper_TqCmdLim(float32 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetCtrlPrm_Oper(float32 MotVelCtrlPropGain_Arg, float32 MotVelCtrlIntgtrGain_Arg, float32 MotVelCtrlDerivtvGain_Arg, float32 MotVelCtrlAntiWdupLim_Arg, float32 MotVelCtrlAntiWdupGain_Arg, float32 MotVelCtrlDerivtvLpFilTiCon_Arg, float32 MotVelCtrlTqCmdLim_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetCtrlPrm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) SetCtrlPrm_Oper(float32 MotVelCtrlPropGain_Arg, float32 MotVelCtrlIntgtrGain_Arg, float32 MotVelCtrlDerivtvGain_Arg, float32 MotVelCtrlAntiWdupLim_Arg, float32 MotVelCtrlAntiWdupGain_Arg, float32 MotVelCtrlDerivtvLpFilTiCon_Arg, float32 MotVelCtrlTqCmdLim_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetCtrlPrm_Oper
 *********************************************************************************************************************/

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;

  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupGain(1.0F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupLim(5.0F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvGain(0.004F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvLpFilTiCon(0.008F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_IntgtrGain(0.15F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_PropGain(0.2F);
  TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_TqCmdLim(8.8F);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StopCtrl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <StopCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void StopCtrl_Oper(float32 MotVelCtrlVelSlewRate_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StopCtrl_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) StopCtrl_Oper(float32 MotVelCtrlVelSlewRate_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StopCtrl_Oper
 *********************************************************************************************************************/

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtCtrl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <StrtCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void StrtCtrl_Oper(float32 MotVelCtrlMotVelTar_Arg, float32 MotVelCtrlVelSlewRate_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtCtrl_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotVelCtrl_CODE) StrtCtrl_Oper(float32 MotVelCtrlMotVelTar_Arg, float32 MotVelCtrlVelSlewRate_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtCtrl_Oper
 *********************************************************************************************************************/

  float32 PimMotVelTar;
  float32 PimPrevAntiWdupCmd;
  float32 PimPrevDerivtvOutp;
  float32 PimPrevIntgtrInp;
  float32 PimPrevIntgtrOutp;
  float32 PimPrevMotVelErr;
  float32 PimPrevMotVelTar;
  float32 PimVelSlewRate;
  uint32 PimRefTiRampDwn;
  boolean PimEnaCtrl;
  boolean PimEnaCtrlStVari;
  boolean PimFctActvSts;
  boolean PimRampDwnCmpl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimMotVelTar = *TSC_MotVelCtrl_Rte_Pim_MotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_MotVelTar() = PimMotVelTar;
  PimPrevAntiWdupCmd = *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd();
  *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd() = PimPrevAntiWdupCmd;
  PimPrevDerivtvOutp = *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp() = PimPrevDerivtvOutp;
  PimPrevIntgtrInp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp() = PimPrevIntgtrInp;
  PimPrevIntgtrOutp = *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp();
  *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp() = PimPrevIntgtrOutp;
  PimPrevMotVelErr = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr() = PimPrevMotVelErr;
  PimPrevMotVelTar = *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar();
  *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar() = PimPrevMotVelTar;
  PimVelSlewRate = *TSC_MotVelCtrl_Rte_Pim_VelSlewRate();
  *TSC_MotVelCtrl_Rte_Pim_VelSlewRate() = PimVelSlewRate;
  PimRefTiRampDwn = *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn();
  *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn() = PimRefTiRampDwn;
  PimEnaCtrl = *TSC_MotVelCtrl_Rte_Pim_EnaCtrl();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrl() = PimEnaCtrl;
  PimEnaCtrlStVari = *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari();
  *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari() = PimEnaCtrlStVari;
  PimFctActvSts = *TSC_MotVelCtrl_Rte_Pim_FctActvSts();
  *TSC_MotVelCtrl_Rte_Pim_FctActvSts() = PimFctActvSts;
  PimRampDwnCmpl = *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl();
  *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl() = PimRampDwnCmpl;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MotVelCtrl_STOP_SEC_CODE
#include "MotVelCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MotVelCtrl_TestDefines(void)
{
  /* Primitive Types */

  float32 Test_float32_LL_1 = Tq1_LowerLimit;
  float32 Test_float32_UL_1 = Tq1_UpperLimit;
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
