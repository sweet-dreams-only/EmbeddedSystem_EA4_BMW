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
 *          File:  Os_Cfg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define Task_100ms_Appl10 (0U)
# define Task_100ms_Appl7 (1U)
# define Task_100ms_Appl9 (2U)
# define Task_10msBsw_Appl10 (3U)
# define Task_10ms_Appl10 (4U)
# define Task_10ms_Appl7 (5U)
# define Task_10ms_Appl8 (6U)
# define Task_10ms_Appl9 (7U)
# define Task_2msA_Appl10 (8U)
# define Task_2msB_Appl10 (9U)
# define Task_2msTmplMonr_Appl10 (10U)
# define Task_2ms_Appl7 (11U)
# define Task_2ms_Appl8 (12U)
# define Task_2ms_Appl9 (13U)
# define Task_4msBsw_Appl10 (14U)
# define Task_4ms_Appl10 (15U)
# define Task_4ms_Appl7 (16U)
# define Task_5msBsw_Appl10 (17U)
# define Task_Coding_Appl10 (18U)
# define Task_ComBsw_Appl10 (19U)
# define Task_Init_Appl10 (20U)
# define Task_Init_Appl7 (21U)
# define Task_Init_Appl8 (22U)
# define Task_Init_Appl9 (23U)

/* Alarms */
# define Rte_Al_TE_Darh_QueueHandler (0U)
# define Rte_Al_TE_Task_100ms_Appl10_0_100ms (1U)
# define Rte_Al_TE_Task_100ms_Appl7_0_100ms (2U)
# define Rte_Al_TE_Task_100ms_Appl9_0_100ms (3U)
# define Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms (4U)
# define Rte_Al_TE_Task_10ms_Appl10_0_10ms (5U)
# define Rte_Al_TE_Task_10ms_Appl7_0_10ms (6U)
# define Rte_Al_TE_Task_10ms_Appl8_0_10ms (7U)
# define Rte_Al_TE_Task_10ms_Appl9_0_10ms (8U)
# define Rte_Al_TE_Task_2msA_Appl10_0_2ms (9U)
# define Rte_Al_TE_Task_2msB_Appl10_0_2ms (10U)
# define Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms (11U)
# define Rte_Al_TE_Task_2ms_Appl7_0_2ms (12U)
# define Rte_Al_TE_Task_2ms_Appl8_0_2ms (13U)
# define Rte_Al_TE_Task_2ms_Appl9_0_2ms (14U)
# define Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms (15U)
# define Rte_Al_TE_Task_4ms_Appl10_0_4ms (16U)
# define Rte_Al_TE_Task_4ms_Appl7_0_4ms (17U)
# define Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms (18U)
# define Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms (19U)
# define Rte_Al_TE_Task_ComBsw_Appl10_0_10ms (20U)

/* Events */
# define Rte_Ev_Cyclic2_Task_5msBsw_Appl10_0_5ms (0x01)
# define Rte_Ev_Cyclic2_Task_ComBsw_Appl10_0_5ms (0x02)
# define Rte_Ev_Cyclic_Task_100ms_Appl10_0_100ms (0x02)
# define Rte_Ev_Cyclic_Task_10ms_Appl10_0_10ms (0x200)
# define Rte_Ev_Cyclic_Task_ComBsw_Appl10_0_10ms (0x01)
# define Rte_Ev_MS_Task_100ms_Appl10 (0x04)
# define Rte_Ev_MS_Task_10ms_Appl10 (0x04)
# define Rte_Ev_Run1_Darh_QueueHandler (0x80)
# define Rte_Ev_Run1_Stm_Runnable_InitialCELSupervision (0x2000)
# define Rte_Ev_Run1_Stm_Runnable_StopCentralErrorLockSupervision (0x40000)
# define Rte_Ev_Run1_SysTime_ReceiveSignal (0x100000000)
# define Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Missing_Oper (0x400000000)
# define Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Received_Oper (0x40000000)
# define Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Missing_Oper (0x10000)
# define Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Received_Oper (0x1000000000)
# define Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Missing_Oper (0x200)
# define Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Received_Oper (0x08)
# define Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Missing (0x80)
# define Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Received (0x100)
# define Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Missing_Oper (0x2000000)
# define Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Received_Oper (0x800)
# define Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Miss (0x10)
# define Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Rxd (0x08)
# define Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Missing_Oper (0x80000)
# define Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Received_Oper (0x8000000000)
# define Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Missing_Oper (0x100)
# define Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Received_Oper (0x40)
# define Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Missing_Oper (0x2000000000)
# define Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Received_Oper (0x100000)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Miss (0x8000)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Rxd (0x02)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Miss (0x20)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Rxd (0x200000)
# define Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Missing_Oper (0x400000)
# define Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Received_Oper (0x1000000)
# define Rte_Ev_Run_BswM_BswM_Read_StdDiag_ComControlModeRequest (0x10000000000)
# define Rte_Ev_Run_Coding_LifeCycleHandler (0x10000000)
# define Rte_Ev_Run_Coding_R_CheckNCD (0x10)
# define Rte_Ev_Run_Coding_R_ConditionCheckReadCPS (0x20)
# define Rte_Ev_Run_Coding_R_ReadCPS (0x04)
# define Rte_Ev_Run_Coding_R_ReadNCD (0x02)
# define Rte_Ev_Run_Coding_R_ReadProtocolData (0x08)
# define Rte_Ev_Run_Coding_R_WriteNCD (0x01)
# define Rte_Ev_Run_Coding_SessionChange (0x20000000)
# define Rte_Ev_Run_Coding_VinReceiveHandler (0x4000)
# define Rte_Ev_Run_Darh_LifeCycleHandler (0x80000000)
# define Rte_Ev_Run_Dlog_Dlog_ModeSwitchAckLifeCycle (0x40)
# define Rte_Ev_Run_Dlog_Dlog_ModeSwitchRequestLifeCycle (0x400)
# define Rte_Ev_Run_Omc_LifeCycleHandler (0x01)
# define Rte_Ev_Run_Rmh_RxRequestMsg (0x20000)
# define Rte_Ev_Run_StdDiag_LifeCycleHandler (0x1000)
# define Rte_Ev_Run_StdDiag_SessionChange_DefaultSession (0x200000000)
# define Rte_Ev_Run_StdDiag_SessionChange_OtherSession (0x800000000)
# define Rte_Ev_Run_Stm_Runnable_ErrorCentralErrorLock (0x4000000000)
# define Rte_Ev_Run_Stm_Runnable_ErrorEnergyMode (0x800000)
# define Rte_Ev_Run_Stm_Runnable_ReceiveCentralErrorLock (0x8000000)
# define Rte_Ev_Run_Stm_Runnable_ReceiveEnergyMode (0x4000000)
# define Rte_Ev_Run_SysTime_LifeCycleHandler (0x20000000000)
# define Rte_Ev_Run_Vin_Vin_LifeCycleModeRequest (0x400)
# define Rte_Ev_Run_Vin_Vin_OnComOff (0x10)
# define Rte_Ev_Run_Vin_Vin_OnComOn (0x800)
# define Rte_Ev_Run_Vin_Vin_OnVinChangeIndicatorAck (0x01)
# define Rte_Ev_Run_Vin_Vin_ReceiveFromCom (0x20)
# define Rte_Ev_WP_Task_5msBsw_Appl10 (0x02)

/* Spinlocks */

/* Resources */
# define Rte_Res_Vin_VinState (0U)

/* ScheduleTables */

/* Cores */
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
