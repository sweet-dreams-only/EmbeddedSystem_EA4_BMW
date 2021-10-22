/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwStReqMgr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwStReqMgr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwStReqMgr>
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
 * BmwEpsFctSts1
 *   
 *
 * BmwVehCdn1
 *   
 *
 * BmwVehSpdSts1
 *   
 *
 * StsDrvrActvy1
 *   
 *
 * StsSteerAssi1
 *   
 *
 * SysSt1
 *   
 *
 * u16p0
 *   
 *
 *
 * Component Types:
 * ================
 * BmwStReqMgr
 *   
 *
 *
 * Port Prototypes:
 * ================
 * BmwEpsFctSts
 *
 * BmwVehCdn
 *
 * BmwVehCdnVld
 *
 * BmwVehSpdSts
 *
 * DiagcStsNonRcvrlReqDiFltPrsnt
 *
 * GetRefTmr100MicroSec32bit
 *
 * GetTiSpan100MicroSec32bit
 *
 * HwTq
 *
 * IoHwAb_GetGpioMcuEna
 *
 * PwrLimrRednFac
 *
 * PwrSplyEnaReq
 *
 * StsDrvrActvy
 *
 * StsSteerAssi
 *
 * SysOperMotTqCmdSca
 *
 * SysOperRampRate
 *
 * SysSt
 *
 * SysStFltOutpReqDi
 *
 * SysStReqEna
 *
 * TarEcuSt
 *
 * ThermRednFac
 *
 * VehSpd
 *
 *
 * Runnable Entities:
 * ==================
 * BmwStReqMgrInit1
 *   
 *
 * BmwStReqMgrPer1
 *   
 *
 *
 * Per-Instance Memory:
 * ====================
 * BmwVehCdnLvngDurn
 *   
 *
 * DrvrActvRefTmr
 *   
 *
 * PrevHwTq
 *   
 *
 * PrevTarEcuSt
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwStReqMgr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwStReqMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwStReqMgr_TestDefines(void);


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
 * u16p0: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwEpsFctSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWEPSFCTSTS_FCTINFALLBACK (49U)
 *   BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV (51U)
 *   BMWEPSFCTSTS_NOTAVIERR (96U)
 *   BMWEPSFCTSTS_ININ (128U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEPS (160U)
 *   BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV (162U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEAS (164U)
 *   BMWEPSFCTSTS_FCTAVIACTV24VEAS (168U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACK (176U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT (178U)
 *   BMWEPSFCTSTS_NOTAVISWDOFF (224U)
 *   BMWEPSFCTSTS_INVLD (255U)
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
 * BmwVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHSPDSTS_VLD (1U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG (4U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG (12U)
 *   BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO (14U)
 *   BMWVEHSPDSTS_INVLD (15U)
 * StsDrvrActvy1: Enumeration of integer in interval [0...255] with enumerators
 *   STSDRVRACTVY_NODRVRACTVY (0U)
 *   STSDRVRACTVY_DRVRACTVY (1U)
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevHwTq(void)
 *   uint32 *Rte_Pim_BmwVehCdnLvngDurn(void)
 *   uint32 *Rte_Pim_DrvrActvRefTmr(void)
 *   uint8 *Rte_Pim_PrevTarEcuSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwStReqMgrHwTqThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrOperRampRate_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrAllwToOffThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(void)
 *   uint8 Rte_Prm_BmwStReqMgrVehCdnOvrd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwStReqMgr_START_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimPrevHwTq;
  uint32 PimBmwVehCdnLvngDurn;
  uint32 PimDrvrActvRefTmr;
  uint8 PimPrevTarEcuSt;

  float32 BmwStReqMgrHwTqThd_Val_data;
  float32 BmwStReqMgrOperRampRate_Val_data;
  float32 BmwStReqMgrStsDrvrActvyTqChgThd_Val_data;
  float32 BmwStReqMgrSwtOffSpdLim_Val_data;
  float32 BmwStReqMgrSysProtnRednFacThd_Val_data;
  u16p0 BmwStReqMgrAllwToOffThd_Val_data;
  u16p0 BmwStReqMgrDrvrActvTmrThd_Val_data;
  uint8 BmwStReqMgrVehCdnOvrd_Val_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevHwTq = *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq();
  *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq() = PimPrevHwTq;
  PimBmwVehCdnLvngDurn = *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn();
  *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn() = PimBmwVehCdnLvngDurn;
  PimDrvrActvRefTmr = *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr();
  *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr() = PimDrvrActvRefTmr;
  PimPrevTarEcuSt = *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt();
  *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt() = PimPrevTarEcuSt;

  BmwStReqMgrHwTqThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrHwTqThd_Val();
  BmwStReqMgrOperRampRate_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrOperRampRate_Val();
  BmwStReqMgrStsDrvrActvyTqChgThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val();
  BmwStReqMgrSwtOffSpdLim_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val();
  BmwStReqMgrSysProtnRednFacThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val();
  BmwStReqMgrAllwToOffThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrAllwToOffThd_Val();
  BmwStReqMgrDrvrActvTmrThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val();
  BmwStReqMgrVehCdnOvrd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrVehCdnOvrd_Val();

  fct_status = TSC_BmwStReqMgr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  BmwStReqMgr_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrPer1
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
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_BmwVehCdnVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PwrLimrRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts1 data)
 *   Std_ReturnType Rte_Write_PwrSplyEnaReq_Logl(boolean data)
 *   Std_ReturnType Rte_Write_StsDrvrActvy_Val(StsDrvrActvy1 data)
 *   Std_ReturnType Rte_Write_StsSteerAssi_Val(StsSteerAssi1 data)
 *   Std_ReturnType Rte_Write_SysOperMotTqCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysOperRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysStReqEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TarEcuSt_Val(SysSt1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioMcuEna_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwVehCdn1 Read_BmwVehCdn_Val;
  boolean Read_BmwVehCdnVld_Logl;
  BmwVehSpdSts1 Read_BmwVehSpdSts_Val;
  boolean Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl;
  float32 Read_HwTq_Val;
  float32 Read_PwrLimrRednFac_Val;
  SysSt1 Read_SysSt_Val;
  boolean Read_SysStFltOutpReqDi_Logl;
  float32 Read_ThermRednFac_Val;
  float32 Read_VehSpd_Val;

  float32 PimPrevHwTq;
  uint32 PimBmwVehCdnLvngDurn;
  uint32 PimDrvrActvRefTmr;
  uint8 PimPrevTarEcuSt;

  float32 BmwStReqMgrHwTqThd_Val_data;
  float32 BmwStReqMgrOperRampRate_Val_data;
  float32 BmwStReqMgrStsDrvrActvyTqChgThd_Val_data;
  float32 BmwStReqMgrSwtOffSpdLim_Val_data;
  float32 BmwStReqMgrSysProtnRednFacThd_Val_data;
  u16p0 BmwStReqMgrAllwToOffThd_Val_data;
  u16p0 BmwStReqMgrDrvrActvTmrThd_Val_data;
  uint8 BmwStReqMgrVehCdnOvrd_Val_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;
  boolean Call_IoHwAb_GetGpioMcuEna_Oper_PinSt_Arg = FALSE;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevHwTq = *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq();
  *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq() = PimPrevHwTq;
  PimBmwVehCdnLvngDurn = *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn();
  *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn() = PimBmwVehCdnLvngDurn;
  PimDrvrActvRefTmr = *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr();
  *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr() = PimDrvrActvRefTmr;
  PimPrevTarEcuSt = *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt();
  *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt() = PimPrevTarEcuSt;

  BmwStReqMgrHwTqThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrHwTqThd_Val();
  BmwStReqMgrOperRampRate_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrOperRampRate_Val();
  BmwStReqMgrStsDrvrActvyTqChgThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val();
  BmwStReqMgrSwtOffSpdLim_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val();
  BmwStReqMgrSysProtnRednFacThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val();
  BmwStReqMgrAllwToOffThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrAllwToOffThd_Val();
  BmwStReqMgrDrvrActvTmrThd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val();
  BmwStReqMgrVehCdnOvrd_Val_data = TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrVehCdnOvrd_Val();

  fct_status = TSC_BmwStReqMgr_Rte_Read_BmwVehCdn_Val(&Read_BmwVehCdn_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_BmwVehCdnVld_Logl(&Read_BmwVehCdnVld_Logl);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_BmwVehSpdSts_Val(&Read_BmwVehSpdSts_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_PwrLimrRednFac_Val(&Read_PwrLimrRednFac_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_SysStFltOutpReqDi_Logl(&Read_SysStFltOutpReqDi_Logl);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_ThermRednFac_Val(&Read_ThermRednFac_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwStReqMgr_Rte_Write_BmwEpsFctSts_Val(Rte_InitValue_BmwEpsFctSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_PwrSplyEnaReq_Logl(Rte_InitValue_PwrSplyEnaReq_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_StsDrvrActvy_Val(Rte_InitValue_StsDrvrActvy_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_StsSteerAssi_Val(Rte_InitValue_StsSteerAssi_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_SysOperMotTqCmdSca_Val(Rte_InitValue_SysOperMotTqCmdSca_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_SysOperRampRate_Val(Rte_InitValue_SysOperRampRate_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_SysStReqEna_Logl(Rte_InitValue_SysStReqEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Write_TarEcuSt_Val(Rte_InitValue_TarEcuSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwStReqMgr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwStReqMgr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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

  fct_status = TSC_BmwStReqMgr_Rte_Call_IoHwAb_GetGpioMcuEna_Oper(&Call_IoHwAb_GetGpioMcuEna_Oper_PinSt_Arg);
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
    case RTE_E_GetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwStReqMgr_STOP_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwStReqMgr_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_1 = BMWEPSFCTSTS_FCTINFALLBACK;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_2 = BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_3 = BMWEPSFCTSTS_NOTAVIERR;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_4 = BMWEPSFCTSTS_ININ;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_5 = BMWEPSFCTSTS_FCTAVIACTV12VEPS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_6 = BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_7 = BMWEPSFCTSTS_FCTAVIACTV12VEAS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_8 = BMWEPSFCTSTS_FCTAVIACTV24VEAS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_9 = BMWEPSFCTSTS_FCTTMPINFALLBACK;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_10 = BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_11 = BMWEPSFCTSTS_NOTAVISWDOFF;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_12 = BMWEPSFCTSTS_INVLD;

  BmwVehCdn1 Test_BmwVehCdn1_V_1 = BMWVEHCDN_PRKGNBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_2 = BMWVEHCDN_PRKGBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_3 = BMWVEHCDN_FCTCUSTNOTINFZG;
  BmwVehCdn1 Test_BmwVehCdn1_V_4 = BMWVEHCDN_LVNG;
  BmwVehCdn1 Test_BmwVehCdn1_V_5 = BMWVEHCDN_CHKDIAGCANLS;
  BmwVehCdn1 Test_BmwVehCdn1_V_6 = BMWVEHCDN_DRVRPREPGFOROPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_7 = BMWVEHCDN_DRVG;
  BmwVehCdn1 Test_BmwVehCdn1_V_8 = BMWVEHCDN_DRVRPREPGFOREXITOPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_9 = BMWVEHCDN_INVLD;

  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_1 = BMWVEHSPDSTS_VLD;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_2 = BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_3 = BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_4 = BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_5 = BMWVEHSPDSTS_INVLD;

  StsDrvrActvy1 Test_StsDrvrActvy1_V_1 = STSDRVRACTVY_NODRVRACTVY;
  StsDrvrActvy1 Test_StsDrvrActvy1_V_2 = STSDRVRACTVY_DRVRACTVY;

  StsSteerAssi1 Test_StsSteerAssi1_V_1 = STSSTEERASSI_OFF;
  StsSteerAssi1 Test_StsSteerAssi1_V_2 = STSSTEERASSI_ON;

  SysSt1 Test_SysSt1_V_1 = SYSST_DI;
  SysSt1 Test_SysSt1_V_2 = SYSST_OFF;
  SysSt1 Test_SysSt1_V_3 = SYSST_ENA;
  SysSt1 Test_SysSt1_V_4 = SYSST_WRMININ;
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
