/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwDrvgDynStMac.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwDrvgDynStMac
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwDrvgDynStMac>
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
 * BmwOvrlCmdQlfr1
 *   
 *
 * BmwTrfcJamAssiDampgStReq1
 *   
 *
 * BmwVehCdn1
 *   
 *
 * DrvgDynIfSt1
 *   
 *
 * StsSteerAssi1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwDrvgDynStMac.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwDrvgDynStMac.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwDrvgDynStMac_TestDefines(void);


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
 * Enumeration Types:
 * ==================
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWOVRLCMDQLFR_IMPLSP (2U)
 *   BMWOVRLCMDQLFR_SPNOTAVL (7U)
 *   BMWOVRLCMDQLFR_STBDONOTCNVSP (14U)
 *   BMWOVRLCMDQLFR_INVLDSIG (15U)
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG (1U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG (2U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG (15U)
 * BmwVehCdn1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHCDN_PRKGNBNOK (1U)
 *   BMWVEHCDN_PRKGBNOK (2U)
 *   BMWVEHCDN_FCTCUSTNOTINFZG (3U)
 *   BMWVEHCDN_LVNG (5U)
 *   BMWVEHCDN_CHKDIAGCANLS (7U)
 *   BMWVEHCDN_DRVRPREPGFOROPER (8U)
 *   BMWVEHCDN_DRVG (10U)
 *   BMWVEHCDN_DRVRPREPGFOREXITOPER (12U)
 *   BMWVEHCDN_INVLD (15U)
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
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_AssiLvlActvtTi(void)
 *   uint32 *Rte_Pim_AssiLvlDeactvtTi(void)
 *   uint32 *Rte_Pim_ErrIfTi(void)
 *   uint32 *Rte_Pim_VehCdnTi(void)
 *   uint8 *Rte_Pim_StMacSt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnActvt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwDrvgDynStMac_START_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacInit1
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
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_MotTqCmdPwrLimd_Val;

  uint32 PimAssiLvlActvtTi;
  uint32 PimAssiLvlDeactvtTi;
  uint32 PimErrIfTi;
  uint32 PimVehCdnTi;
  uint8 PimStMacSt;
  boolean PimMotTqCmdPwrLimdCdnActvt;
  boolean PimMotTqCmdPwrLimdCdnDeactvt;

  float32 BmwDrvgDynStMacDampgCmdScaDft_Val_data;
  float32 BmwDrvgDynStMacEffortCmdScaDft_Val_data;
  float32 BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val_data;
  float32 BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val_data;
  float32 BmwDrvgDynStMacRtnCmdScaDft_Val_data;
  uint16 BmwDrvgDynStMacAssiLvlThd_Val_data;
  uint16 BmwDrvgDynStMacErrIfTmrThd_Val_data;
  uint16 BmwDrvgDynStMacVehCdnTmrThd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAssiLvlActvtTi = *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi() = PimAssiLvlActvtTi;
  PimAssiLvlDeactvtTi = *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi() = PimAssiLvlDeactvtTi;
  PimErrIfTi = *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi() = PimErrIfTi;
  PimVehCdnTi = *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi() = PimVehCdnTi;
  PimStMacSt = *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt() = PimStMacSt;
  PimMotTqCmdPwrLimdCdnActvt = *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt() = PimMotTqCmdPwrLimdCdnActvt;
  PimMotTqCmdPwrLimdCdnDeactvt = *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() = PimMotTqCmdPwrLimdCdnDeactvt;

  BmwDrvgDynStMacDampgCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val();
  BmwDrvgDynStMacEffortCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val();
  BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val();
  BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val();
  BmwDrvgDynStMacRtnCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val();
  BmwDrvgDynStMacAssiLvlThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val();
  BmwDrvgDynStMacErrIfTmrThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val();
  BmwDrvgDynStMacVehCdnTmrThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val();

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_MotTqCmdPwrLimd_Val(&Read_MotTqCmdPwrLimd_Val);
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

  BmwDrvgDynStMac_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynEnaReq_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_DampgCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EffortCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DrvgDynActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt1 data)
 *   Std_ReturnType Rte_Write_OutpTqOvrlRampInEna_Logl(boolean data)
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
 * Symbol: BmwDrvgDynStMacPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_BmwDrvgDynEnaReq_Logl;
  BmwOvrlCmdQlfr1 Read_BmwDrvgDynFacQlfr_Val;
  boolean Read_BmwDrvgDynFacQlfrVld_Logl;
  BmwOvrlCmdQlfr1 Read_BmwTarHwTqOvrlQlfr_Val;
  boolean Read_BmwTarHwTqOvrlQlfrVld_Logl;
  BmwOvrlCmdQlfr1 Read_BmwTarSteerTqDrvrActrQlfr_Val;
  boolean Read_BmwTarSteerTqDrvrActrQlfrVld_Logl;
  BmwTrfcJamAssiDampgStReq1 Read_BmwTrfcJamAssiDampgStReq_Val;
  boolean Read_BmwTrfcJamAssiDampgStReqVld_Logl;
  BmwVehCdn1 Read_BmwVehCdn_Val;
  float32 Read_DampgCmdSca_Val;
  boolean Read_DiagcStsCtrldShtDwnFltPrsnt_Logl;
  boolean Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl;
  float32 Read_EffortCmdSca_Val;
  float32 Read_MotTqCmdPwrLimd_Val;
  float32 Read_MotTqOvrlCmd_Val;
  float32 Read_RtnCmdSca_Val;
  StsSteerAssi1 Read_StsSteerAssi_Val;
  boolean Read_SysStFltOutpReqDi_Logl;

  uint32 PimAssiLvlActvtTi;
  uint32 PimAssiLvlDeactvtTi;
  uint32 PimErrIfTi;
  uint32 PimVehCdnTi;
  uint8 PimStMacSt;
  boolean PimMotTqCmdPwrLimdCdnActvt;
  boolean PimMotTqCmdPwrLimdCdnDeactvt;

  float32 BmwDrvgDynStMacDampgCmdScaDft_Val_data;
  float32 BmwDrvgDynStMacEffortCmdScaDft_Val_data;
  float32 BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val_data;
  float32 BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val_data;
  float32 BmwDrvgDynStMacRtnCmdScaDft_Val_data;
  uint16 BmwDrvgDynStMacAssiLvlThd_Val_data;
  uint16 BmwDrvgDynStMacErrIfTmrThd_Val_data;
  uint16 BmwDrvgDynStMacVehCdnTmrThd_Val_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAssiLvlActvtTi = *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi() = PimAssiLvlActvtTi;
  PimAssiLvlDeactvtTi = *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi() = PimAssiLvlDeactvtTi;
  PimErrIfTi = *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi() = PimErrIfTi;
  PimVehCdnTi = *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi();
  *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi() = PimVehCdnTi;
  PimStMacSt = *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt() = PimStMacSt;
  PimMotTqCmdPwrLimdCdnActvt = *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt() = PimMotTqCmdPwrLimdCdnActvt;
  PimMotTqCmdPwrLimdCdnDeactvt = *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt();
  *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() = PimMotTqCmdPwrLimdCdnDeactvt;

  BmwDrvgDynStMacDampgCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val();
  BmwDrvgDynStMacEffortCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val();
  BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val();
  BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val();
  BmwDrvgDynStMacRtnCmdScaDft_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val();
  BmwDrvgDynStMacAssiLvlThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val();
  BmwDrvgDynStMacErrIfTmrThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val();
  BmwDrvgDynStMacVehCdnTmrThd_Val_data = TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val();

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynEnaReq_Logl(&Read_BmwDrvgDynEnaReq_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfr_Val(&Read_BmwDrvgDynFacQlfr_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfrVld_Logl(&Read_BmwDrvgDynFacQlfrVld_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfr_Val(&Read_BmwTarHwTqOvrlQlfr_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(&Read_BmwTarHwTqOvrlQlfrVld_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(&Read_BmwTarSteerTqDrvrActrQlfr_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(&Read_BmwTarSteerTqDrvrActrQlfrVld_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(&Read_BmwTrfcJamAssiDampgStReq_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(&Read_BmwTrfcJamAssiDampgStReqVld_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_BmwVehCdn_Val(&Read_BmwVehCdn_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_DampgCmdSca_Val(&Read_DampgCmdSca_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(&Read_DiagcStsCtrldShtDwnFltPrsnt_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_EffortCmdSca_Val(&Read_EffortCmdSca_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_MotTqCmdPwrLimd_Val(&Read_MotTqCmdPwrLimd_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_MotTqOvrlCmd_Val(&Read_MotTqOvrlCmd_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_RtnCmdSca_Val(&Read_RtnCmdSca_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_StsSteerAssi_Val(&Read_StsSteerAssi_Val);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Read_SysStFltOutpReqDi_Logl(&Read_SysStFltOutpReqDi_Logl);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynActv_Logl(Rte_InitValue_DrvgDynActv_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynIfSt_Val(Rte_InitValue_DrvgDynIfSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDrvgDynStMac_Rte_Write_OutpTqOvrlRampInEna_Logl(Rte_InitValue_OutpTqOvrlRampInEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDrvgDynStMac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwDrvgDynStMac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwDrvgDynStMac_STOP_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwDrvgDynStMac_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_1 = BMWOVRLCMDQLFR_IMPLSP;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_2 = BMWOVRLCMDQLFR_SPNOTAVL;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_3 = BMWOVRLCMDQLFR_STBDONOTCNVSP;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_4 = BMWOVRLCMDQLFR_INVLDSIG;

  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_1 = BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG;
  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_2 = BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG;
  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_3 = BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG;

  BmwVehCdn1 Test_BmwVehCdn1_V_1 = BMWVEHCDN_PRKGNBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_2 = BMWVEHCDN_PRKGBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_3 = BMWVEHCDN_FCTCUSTNOTINFZG;
  BmwVehCdn1 Test_BmwVehCdn1_V_4 = BMWVEHCDN_LVNG;
  BmwVehCdn1 Test_BmwVehCdn1_V_5 = BMWVEHCDN_CHKDIAGCANLS;
  BmwVehCdn1 Test_BmwVehCdn1_V_6 = BMWVEHCDN_DRVRPREPGFOROPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_7 = BMWVEHCDN_DRVG;
  BmwVehCdn1 Test_BmwVehCdn1_V_8 = BMWVEHCDN_DRVRPREPGFOREXITOPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_9 = BMWVEHCDN_INVLD;

  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_1 = DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_2 = DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_3 = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_4 = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_5 = DRVGDYNIFST_SRVNOTAVLERR;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_6 = DRVGDYNIFST_IFINID;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_7 = DRVGDYNIFST_SRVNOTAVLSTBPMA;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_8 = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_9 = DRVGDYNIFST_INVLDSIG;

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
