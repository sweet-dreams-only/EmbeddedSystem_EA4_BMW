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
 *          File:  TSC_BmwMsgSlot315Bas0Repn1BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_HwTq4RawAdc_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_HwTq5RawAdc_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotCurrPeakEstimdFild_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotFetT_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotMagT_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotTqCmdPreLim_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotVelMrf_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_MotWidgT_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS(BATT_VLTG_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2(DBG_EPS_BS_MOD_58_BYTE_ID2 data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS(ECU_TEMP_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(ESTIMD_PEAK_MOT_CURR_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(MOT_FET_TEMP_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(MOT_MAG_TEMP_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(MOT_TQ_CMD_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(MOT_TQ_CMD_LIMD_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS(MOT_VEL_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(MOT_WIDG_TEMP_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(PRIM_HW_TQ_SNSR_VLTG_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(SECDRY_HW_TQ_SNSR_VLTG_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS(ST_CON_VEH_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_SYS_ST_EPS_SYS_ST_EPS(SYS_ST_EPS data);
Std_ReturnType TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS(VEH_SPD_EPS data);

/** Per Instance Memories */
boolean *TSC_BmwMsgSlot315Bas0Repn1BusFrChA_Rte_Pim_PerCntrFlg(void);



