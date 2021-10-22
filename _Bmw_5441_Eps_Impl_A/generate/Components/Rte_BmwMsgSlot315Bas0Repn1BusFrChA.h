/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_BmwMsgSlot315Bas0Repn1BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot315Bas0Repn1BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT315BAS0REPN1BUSFRCHA_H
# define _RTE_BMWMSGSLOT315BAS0REPN1BUSFRCHA_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwMsgSlot315Bas0Repn1BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_EcuTMeas_EcuTFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotFetT_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotMagT_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotWidgT_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwVehCdn1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_HwTq4RawAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrPeakEstimn_MotCurrPeakEstimdFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPreLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_MotTqCmdPwrLimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelMrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BATT_VLTG_EPS_BATT_VLTG_EPS (0U)
#  define Rte_InitValue_BmwVehCdn_Val (15U)
#  define Rte_InitValue_BrdgVltg_Val (6.0F)
#  define Rte_InitValue_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2 (1U)
#  define Rte_InitValue_ECU_TEMP_EPS_ECU_TEMP_EPS (75U)
#  define Rte_InitValue_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS (0U)
#  define Rte_InitValue_EcuTFild_Val (25.0F)
#  define Rte_InitValue_HwTq4RawAdc_Val (0.0F)
#  define Rte_InitValue_HwTq5RawAdc_Val (0.0F)
#  define Rte_InitValue_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS (75U)
#  define Rte_InitValue_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS (75U)
#  define Rte_InitValue_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS (880U)
#  define Rte_InitValue_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS (880U)
#  define Rte_InitValue_MOT_VEL_EPS_MOT_VEL_EPS (27000U)
#  define Rte_InitValue_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS (75U)
#  define Rte_InitValue_MotCurrPeakEstimdFild_Val (0.0F)
#  define Rte_InitValue_MotFetT_Val (0.0F)
#  define Rte_InitValue_MotMagT_Val (0.0F)
#  define Rte_InitValue_MotTqCmdPreLim_Val (0.0F)
#  define Rte_InitValue_MotTqCmdPwrLimd_Val (0.0F)
#  define Rte_InitValue_MotVelMrf_Val (0.0F)
#  define Rte_InitValue_MotWidgT_Val (0.0F)
#  define Rte_InitValue_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS (0U)
#  define Rte_InitValue_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS (0U)
#  define Rte_InitValue_ST_CON_VEH_EPS_ST_CON_VEH_EPS (15U)
#  define Rte_InitValue_SYS_ST_EPS_SYS_ST_EPS (3U)
#  define Rte_InitValue_SysSt_Val (3U)
#  define Rte_InitValue_VEH_SPD_EPS_VEH_SPD_EPS (0U)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_BATT_VLTG_EPS_BATT_VLTG_EPS(BATT_VLTG_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2(DBG_EPS_BS_MOD_58_BYTE_ID2 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ECU_TEMP_EPS_ECU_TEMP_EPS(ECU_TEMP_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(MOT_FET_TEMP_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(MOT_MAG_TEMP_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(MOT_TQ_CMD_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(MOT_TQ_CMD_LIMD_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_VEL_EPS_MOT_VEL_EPS(MOT_VEL_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(MOT_WIDG_TEMP_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(PRIM_HW_TQ_SNSR_VLTG_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(SECDRY_HW_TQ_SNSR_VLTG_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_VEH_SPD_EPS_VEH_SPD_EPS(VEH_SPD_EPS data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwVehCdn_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_BmwVehCdn_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_BmwVehCdn_Val(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BrdgVltg_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_BrdgVltg_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_BrdgVltg_Val(data) (*(data) = Rte_BattVltg_BrdgVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EcuTFild_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_EcuTFild_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_EcuTFild_Val(data) (*(data) = Rte_EcuTMeas_EcuTFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq4RawAdc_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_HwTq4RawAdc_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_HwTq4RawAdc_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_HwTq4RawAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5RawAdc_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_HwTq5RawAdc_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_HwTq5RawAdc_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrPeakEstimdFild_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotCurrPeakEstimdFild_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotCurrPeakEstimdFild_Val(data) (*(data) = Rte_MotCurrPeakEstimn_MotCurrPeakEstimdFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotFetT_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotFetT_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotFetT_Val(data) (*(data) = Rte_TEstimn_MotFetT_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotMagT_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotMagT_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotMagT_Val(data) (*(data) = Rte_TEstimn_MotMagT_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdPreLim_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPreLim_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPreLim_Val(data) (*(data) = Rte_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPreLim_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdPwrLimd_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPwrLimd_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotTqCmdPwrLimd_Val(data) (*(data) = Rte_PwrLimr_MotTqCmdPwrLimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelMrf_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotVelMrf_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotVelMrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelMrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotWidgT_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotWidgT_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_MotWidgT_Val(data) (*(data) = Rte_TEstimn_MotWidgT_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_SysSt_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_VehSpd_Val
#  define Rte_Read_BmwMsgSlot315Bas0Repn1BusFrChA_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_BATT_VLTG_EPS_BATT_VLTG_EPS
#  define Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2 Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2
#  define Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ECU_TEMP_EPS_ECU_TEMP_EPS
#  define Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS
#  define Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS
#  define Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS
#  define Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS
#  define Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS
#  define Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_VEL_EPS_MOT_VEL_EPS
#  define Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS
#  define Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS
#  define Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS
#  define Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ST_CON_VEH_EPS_ST_CON_VEH_EPS
#  define Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_ST_CON_VEH_EPS_ST_CON_VEH_EPS(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SYS_ST_EPS_SYS_ST_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_SYS_ST_EPS_SYS_ST_EPS
#  define Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_SYS_ST_EPS_SYS_ST_EPS(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS Rte_Write_BmwMsgSlot315Bas0Repn1BusFrChA_VEH_SPD_EPS_VEH_SPD_EPS


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot315Bas0Repn1BusFrChA_PerCntrFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PerCntrFlg() \
  (&Rte_BmwMsgSlot315Bas0Repn1BusFrChA_PerCntrFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot315Bas0Repn1BusFrChA_START_SEC_CODE
# include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot315Bas0Repn1BusFrChA_Init1 BmwMsgSlot315Bas0Repn1BusFrChA_Init1
#  define RTE_RUNNABLE_BmwMsgSlot315Bas0Repn1BusFrChA_Per1 BmwMsgSlot315Bas0Repn1BusFrChA_Per1
# endif

FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Init1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Per1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot315Bas0Repn1BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT315BAS0REPN1BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
