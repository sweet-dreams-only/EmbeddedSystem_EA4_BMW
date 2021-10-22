/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot315Bas0Repn1BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot315Bas0Repn1BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot315Bas0Repn1BusFrChA>
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
 * BmwVehCdn1
 *   
 *
 * SysSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot315Bas0Repn1BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot315Bas0Repn1BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwMsgSlot315Bas0Repn1BusFrChA_TestDefines(void);


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
 * BATT_VLTG_EPS: Integer in interval [0...65535]
 * DBG_EPS_BS_MOD_58_BYTE_ID2: Integer in interval [0...255]
 * ECU_TEMP_EPS: Integer in interval [0...255]
 * ESTIMD_PEAK_MOT_CURR_EPS: Integer in interval [0...4294967295]
 * MOT_FET_TEMP_EPS: Integer in interval [0...255]
 * MOT_MAG_TEMP_EPS: Integer in interval [0...255]
 * MOT_TQ_CMD_EPS: Integer in interval [0...65535]
 * MOT_TQ_CMD_LIMD_EPS: Integer in interval [0...65535]
 * MOT_VEL_EPS: Integer in interval [0...65535]
 * MOT_WIDG_TEMP_EPS: Integer in interval [0...65535]
 * PRIM_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * SECDRY_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * ST_CON_VEH_EPS: Integer in interval [0...255]
 * SYS_ST_EPS: Integer in interval [0...255]
 * VEH_SPD_EPS: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 *   boolean *Rte_Pim_PerCntrFlg(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot315Bas0Repn1BusFrChA_START_SEC_CODE
#include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot315Bas0Repn1BusFrChA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Init1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Init1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Init1
 *********************************************************************************************************************/

  boolean PimPerCntrFlg;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPerCntrFlg = *TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Pim_PerCntrFlg();
  *TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Pim_PerCntrFlg() = PimPerCntrFlg;

  BmwMsgSlot315Bas0Repn1BusFrChA_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot315Bas0Repn1BusFrChA_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_BrdgVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EcuTFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq5RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrPeakEstimdFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotFetT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotMagT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPreLim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelMrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotWidgT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS(BATT_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2(DBG_EPS_BS_MOD_58_BYTE_ID2 data)
 *   Std_ReturnType Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS(ECU_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(ESTIMD_PEAK_MOT_CURR_EPS data)
 *   Std_ReturnType Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(MOT_FET_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(MOT_MAG_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(MOT_TQ_CMD_EPS data)
 *   Std_ReturnType Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(MOT_TQ_CMD_LIMD_EPS data)
 *   Std_ReturnType Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS(MOT_VEL_EPS data)
 *   Std_ReturnType Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(MOT_WIDG_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(PRIM_HW_TQ_SNSR_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(SECDRY_HW_TQ_SNSR_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS(ST_CON_VEH_EPS data)
 *   Std_ReturnType Rte_Write_SYS_ST_EPS_SYS_ST_EPS(SYS_ST_EPS data)
 *   Std_ReturnType Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS(VEH_SPD_EPS data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Per1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Per1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Per1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwVehCdn1 Read_BmwVehCdn_Val;
  float32 Read_BrdgVltg_Val;
  float32 Read_EcuTFild_Val;
  float32 Read_HwTq4RawAdc_Val;
  float32 Read_HwTq5RawAdc_Val;
  float32 Read_MotCurrPeakEstimdFild_Val;
  float32 Read_MotFetT_Val;
  float32 Read_MotMagT_Val;
  float32 Read_MotTqCmdPreLim_Val;
  float32 Read_MotTqCmdPwrLimd_Val;
  float32 Read_MotVelMrf_Val;
  float32 Read_MotWidgT_Val;
  SysSt1 Read_SysSt_Val;
  float32 Read_VehSpd_Val;

  boolean PimPerCntrFlg;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPerCntrFlg = *TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Pim_PerCntrFlg();
  *TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Pim_PerCntrFlg() = PimPerCntrFlg;

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_BmwVehCdn_Val(&Read_BmwVehCdn_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_BrdgVltg_Val(&Read_BrdgVltg_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_EcuTFild_Val(&Read_EcuTFild_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_HwTq4RawAdc_Val(&Read_HwTq4RawAdc_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_HwTq5RawAdc_Val(&Read_HwTq5RawAdc_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotCurrPeakEstimdFild_Val(&Read_MotCurrPeakEstimdFild_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotFetT_Val(&Read_MotFetT_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotMagT_Val(&Read_MotMagT_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotTqCmdPreLim_Val(&Read_MotTqCmdPreLim_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotTqCmdPwrLimd_Val(&Read_MotTqCmdPwrLimd_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotVelMrf_Val(&Read_MotVelMrf_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotWidgT_Val(&Read_MotWidgT_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS(Rte_InitValue_BATT_VLTG_EPS_BATT_VLTG_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2(Rte_InitValue_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS(Rte_InitValue_ECU_TEMP_EPS_ECU_TEMP_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(Rte_InitValue_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(Rte_InitValue_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(Rte_InitValue_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(Rte_InitValue_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(Rte_InitValue_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS(Rte_InitValue_MOT_VEL_EPS_MOT_VEL_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(Rte_InitValue_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(Rte_InitValue_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(Rte_InitValue_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS(Rte_InitValue_ST_CON_VEH_EPS_ST_CON_VEH_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_SYS_ST_EPS_SYS_ST_EPS(Rte_InitValue_SYS_ST_EPS_SYS_ST_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS(Rte_InitValue_VEH_SPD_EPS_VEH_SPD_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot315Bas0Repn1BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot315Bas0Repn1BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwVehCdn1 Test_BmwVehCdn1_V_1 = BMWVEHCDN_PRKGNBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_2 = BMWVEHCDN_PRKGBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_3 = BMWVEHCDN_FCTCUSTNOTINFZG;
  BmwVehCdn1 Test_BmwVehCdn1_V_4 = BMWVEHCDN_LVNG;
  BmwVehCdn1 Test_BmwVehCdn1_V_5 = BMWVEHCDN_CHKDIAGCANLS;
  BmwVehCdn1 Test_BmwVehCdn1_V_6 = BMWVEHCDN_DRVRPREPGFOROPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_7 = BMWVEHCDN_DRVG;
  BmwVehCdn1 Test_BmwVehCdn1_V_8 = BMWVEHCDN_DRVRPREPGFOREXITOPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_9 = BMWVEHCDN_INVLD;

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
