/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_TSG31CfgAndUse.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_TSG31CfgAndUse
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_TSG31CfgAndUse>
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
 * MotCurrEolCalSt2
 *   
 *
 * SysSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CDD_TSG31CfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_TSG31CfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CDD_TSG31CfgAndUse_TestDefines(void);


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * MotCurrEolCalSt2: Enumeration of integer in interval [0...255] with enumerators
 *   MCECS_OFFSCMDSTRT (0U)
 *   MCECS_OFFSCMDHI (1U)
 *   MCECS_OFFSCMDLO (2U)
 *   MCECS_OFFSCMDZERO (3U)
 *   MCECS_OFFSCMDEND (4U)
 *   MCECS_GAINCMDAD (5U)
 *   MCECS_GAINCMDBE (6U)
 *   MCECS_GAINCMDCF (7U)
 *   MCECS_CMDSAFEST (8U)
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
 *   uint32 *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak(void)
 *   uint32 *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart(void)
 *   uint16 *Rte_Pim_MissUpdCoarse(void)
 *   uint16 *Rte_Pim_MissUpdFine(void)
 *   uint16 *Rte_Pim_MissUpdMaxCntr(void)
 *   uint16 *Rte_Pim_MissUpdMinCntr(void)
 *   uint8 *Rte_Pim_MissUpdIninCntr(void)
 *   boolean *Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev(void)
 *   boolean *Rte_Pim_TSG31CfgAndUseSysStEnaPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint32 Rte_Prm_CurrMeasEolFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUsePwmDbnd_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_TSG31CfgAndUse_START_SEC_CODE
#include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUseInit1
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
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUseInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimTSG31CfgAndUseAdcStrtOfCnvnPeak;
  uint32 PimTSG31CfgAndUseMotAg0SPIStart;
  uint16 PimMissUpdCoarse;
  uint16 PimMissUpdFine;
  uint16 PimMissUpdMaxCntr;
  uint16 PimMissUpdMinCntr;
  uint8 PimMissUpdIninCntr;
  boolean PimTSG31CfgAndUsePhaDiscntActvdStPrev;
  boolean PimTSG31CfgAndUseSysStEnaPrev;

  uint32 CurrMeasEolFixdPwmPerd_Val_data;
  uint32 CurrMeasEolOffsHiCmuOffs_Val_data;
  uint32 CurrMeasEolOffsLoCmuOffs_Val_data;
  uint32 PhaDiscnctFixdPhaOnTi_Val_data;
  uint32 PhaDiscnctFixdPwmPerd_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val_data;
  uint32 TSG31CfgAndUseMtrAg0SPIStart_Val_data;
  uint32 TSG31CfgAndUsePwmDbnd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimTSG31CfgAndUseAdcStrtOfCnvnPeak = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() = PimTSG31CfgAndUseAdcStrtOfCnvnPeak;
  PimTSG31CfgAndUseMotAg0SPIStart = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseMotAg0SPIStart();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() = PimTSG31CfgAndUseMotAg0SPIStart;
  PimMissUpdCoarse = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdCoarse();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdCoarse() = PimMissUpdCoarse;
  PimMissUpdFine = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdFine();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdFine() = PimMissUpdFine;
  PimMissUpdMaxCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMaxCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMaxCntr() = PimMissUpdMaxCntr;
  PimMissUpdMinCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMinCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMinCntr() = PimMissUpdMinCntr;
  PimMissUpdIninCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdIninCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdIninCntr() = PimMissUpdIninCntr;
  PimTSG31CfgAndUsePhaDiscntActvdStPrev = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() = PimTSG31CfgAndUsePhaDiscntActvdStPrev;
  PimTSG31CfgAndUseSysStEnaPrev = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseSysStEnaPrev();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseSysStEnaPrev() = PimTSG31CfgAndUseSysStEnaPrev;

  CurrMeasEolFixdPwmPerd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
  CurrMeasEolOffsHiCmuOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
  CurrMeasEolOffsLoCmuOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
  PhaDiscnctFixdPhaOnTi_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
  PhaDiscnctFixdPwmPerd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPwmPerd_Val();
  TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val();
  TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val();
  TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val();
  TSG31CfgAndUseMtrAg0SPIStart_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val();
  TSG31CfgAndUsePwmDbnd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUsePwmDbnd_Val();

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  CDD_TSG31CfgAndUse_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUsePer2
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
 *   Std_ReturnType Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data)
 *   Std_ReturnType Rte_Read_PhaDiscnctDiagcActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUsePer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUsePer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUsePer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  MotCurrEolCalSt2 Read_MotCurrEolCalSt_Val;
  boolean Read_PhaDiscnctDiagcActv_Logl;
  SysSt1 Read_SysSt_Val;

  uint32 PimTSG31CfgAndUseAdcStrtOfCnvnPeak;
  uint32 PimTSG31CfgAndUseMotAg0SPIStart;
  uint16 PimMissUpdCoarse;
  uint16 PimMissUpdFine;
  uint16 PimMissUpdMaxCntr;
  uint16 PimMissUpdMinCntr;
  uint8 PimMissUpdIninCntr;
  boolean PimTSG31CfgAndUsePhaDiscntActvdStPrev;
  boolean PimTSG31CfgAndUseSysStEnaPrev;

  uint32 CurrMeasEolFixdPwmPerd_Val_data;
  uint32 CurrMeasEolOffsHiCmuOffs_Val_data;
  uint32 CurrMeasEolOffsLoCmuOffs_Val_data;
  uint32 PhaDiscnctFixdPhaOnTi_Val_data;
  uint32 PhaDiscnctFixdPwmPerd_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val_data;
  uint32 TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val_data;
  uint32 TSG31CfgAndUseMtrAg0SPIStart_Val_data;
  uint32 TSG31CfgAndUsePwmDbnd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimTSG31CfgAndUseAdcStrtOfCnvnPeak = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() = PimTSG31CfgAndUseAdcStrtOfCnvnPeak;
  PimTSG31CfgAndUseMotAg0SPIStart = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseMotAg0SPIStart();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() = PimTSG31CfgAndUseMotAg0SPIStart;
  PimMissUpdCoarse = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdCoarse();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdCoarse() = PimMissUpdCoarse;
  PimMissUpdFine = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdFine();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdFine() = PimMissUpdFine;
  PimMissUpdMaxCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMaxCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMaxCntr() = PimMissUpdMaxCntr;
  PimMissUpdMinCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMinCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMinCntr() = PimMissUpdMinCntr;
  PimMissUpdIninCntr = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdIninCntr();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdIninCntr() = PimMissUpdIninCntr;
  PimTSG31CfgAndUsePhaDiscntActvdStPrev = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() = PimTSG31CfgAndUsePhaDiscntActvdStPrev;
  PimTSG31CfgAndUseSysStEnaPrev = *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseSysStEnaPrev();
  *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseSysStEnaPrev() = PimTSG31CfgAndUseSysStEnaPrev;

  CurrMeasEolFixdPwmPerd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
  CurrMeasEolOffsHiCmuOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
  CurrMeasEolOffsLoCmuOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
  PhaDiscnctFixdPhaOnTi_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
  PhaDiscnctFixdPwmPerd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPwmPerd_Val();
  TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val();
  TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val();
  TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val();
  TSG31CfgAndUseMtrAg0SPIStart_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val();
  TSG31CfgAndUsePwmDbnd_Val_data = TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUsePwmDbnd_Val();

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Read_MotCurrEolCalSt_Val(&Read_MotCurrEolCalSt_Val);
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

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Read_PhaDiscnctDiagcActv_Logl(&Read_PhaDiscnctDiagcActv_Logl);
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

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper();
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
    case RTE_E_SetFctGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper();
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
    case RTE_E_SetFctPeriph_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_TSG31CfgAndUse_STOP_SEC_CODE
#include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CDD_TSG31CfgAndUse_TestDefines(void)
{
  /* Enumeration Data Types */

  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_1 = MCECS_OFFSCMDSTRT;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_2 = MCECS_OFFSCMDHI;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_3 = MCECS_OFFSCMDLO;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_4 = MCECS_OFFSCMDZERO;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_5 = MCECS_OFFSCMDEND;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_6 = MCECS_GAINCMDAD;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_7 = MCECS_GAINCMDBE;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_8 = MCECS_GAINCMDCF;
  MotCurrEolCalSt2 Test_MotCurrEolCalSt2_V_9 = MCECS_CMDSAFEST;

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
