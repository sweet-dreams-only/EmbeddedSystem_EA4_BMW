/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Context_Lcfg.h
 *   Generation Time: 2018-07-30 19:49:08
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_HAL_CONTEXT_LCFG_H)                                                 /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore_CORE0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore_CORE0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore_CORE0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore_CORE0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore_CORE0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level5_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore_CORE0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore_CORE0_Dyn;

/*! HAL dynamic task context data: Task_100ms_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_100ms_Appl10_Dyn;

/*! HAL dynamic task context data: Task_100ms_Appl7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_100ms_Appl7_Dyn;

/*! HAL dynamic task context data: Task_100ms_Appl9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_100ms_Appl9_Dyn;

/*! HAL dynamic task context data: Task_10msBsw_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_10msBsw_Appl10_Dyn;

/*! HAL dynamic task context data: Task_10ms_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_10ms_Appl10_Dyn;

/*! HAL dynamic task context data: Task_10ms_Appl7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_10ms_Appl7_Dyn;

/*! HAL dynamic task context data: Task_10ms_Appl8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_10ms_Appl8_Dyn;

/*! HAL dynamic task context data: Task_10ms_Appl9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_10ms_Appl9_Dyn;

/*! HAL dynamic task context data: Task_2msA_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2msA_Appl10_Dyn;

/*! HAL dynamic task context data: Task_2msB_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2msB_Appl10_Dyn;

/*! HAL dynamic task context data: Task_2msTmplMonr_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2msTmplMonr_Appl10_Dyn;

/*! HAL dynamic task context data: Task_2ms_Appl7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2ms_Appl7_Dyn;

/*! HAL dynamic task context data: Task_2ms_Appl8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2ms_Appl8_Dyn;

/*! HAL dynamic task context data: Task_2ms_Appl9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_2ms_Appl9_Dyn;

/*! HAL dynamic task context data: Task_4msBsw_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_4msBsw_Appl10_Dyn;

/*! HAL dynamic task context data: Task_4ms_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_4ms_Appl10_Dyn;

/*! HAL dynamic task context data: Task_4ms_Appl7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_4ms_Appl7_Dyn;

/*! HAL dynamic task context data: Task_5msBsw_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_5msBsw_Appl10_Dyn;

/*! HAL dynamic task context data: Task_Coding_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_Coding_Appl10_Dyn;

/*! HAL dynamic task context data: Task_ComBsw_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_ComBsw_Appl10_Dyn;

/*! HAL dynamic task context data: Task_InitBsw_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_InitBsw_Appl10_Dyn;

/*! HAL dynamic task context data: Task_Init_Appl10 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_Init_Appl10_Dyn;

/*! HAL dynamic task context data: Task_Init_Appl7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_Init_Appl7_Dyn;

/*! HAL dynamic task context data: Task_Init_Appl8 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_Init_Appl8_Dyn;

/*! HAL dynamic task context data: Task_Init_Appl9 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Task_Init_Appl9_Dyn;

/*! HAL exception context data: OsCore_CORE0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore_CORE0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0;

/*! HAL hook context configuration data: ShutdownHook_OsCore_CORE0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore_CORE0;

/*! HAL hook context configuration data: ErrorHook_OsCore_CORE0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore_CORE0;

/*! HAL ISR2 context configuration data: CounterIsr_OsCounter */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_OsCounter;

/*! HAL ISR2 context configuration data: Fr_IrqLine0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Fr_IrqLine0;

/*! HAL ISR2 context configuration data: Fr_IrqTimer0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Fr_IrqTimer0;

/*! HAL ISR2 context configuration data: MCU_ECM_EIC_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MCU_ECM_EIC_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIG0_TIC_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIG0_TIC_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIG0_TIRE_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIG0_TIRE_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIG0_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIG0_TIR_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIH2_TIC_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH2_TIC_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIH2_TIRE_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH2_TIRE_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIH2_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH2_TIR_CAT2_ISR;

/*! HAL task context configuration data: IdleTask_OsCore_CORE0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore_CORE0;

/*! HAL task context configuration data: Task_100ms_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_100ms_Appl10;

/*! HAL task context configuration data: Task_100ms_Appl7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_100ms_Appl7;

/*! HAL task context configuration data: Task_100ms_Appl9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_100ms_Appl9;

/*! HAL task context configuration data: Task_10msBsw_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_10msBsw_Appl10;

/*! HAL task context configuration data: Task_10ms_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_10ms_Appl10;

/*! HAL task context configuration data: Task_10ms_Appl7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_10ms_Appl7;

/*! HAL task context configuration data: Task_10ms_Appl8 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_10ms_Appl8;

/*! HAL task context configuration data: Task_10ms_Appl9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_10ms_Appl9;

/*! HAL task context configuration data: Task_2msA_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2msA_Appl10;

/*! HAL task context configuration data: Task_2msB_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2msB_Appl10;

/*! HAL task context configuration data: Task_2msTmplMonr_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2msTmplMonr_Appl10;

/*! HAL task context configuration data: Task_2ms_Appl7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2ms_Appl7;

/*! HAL task context configuration data: Task_2ms_Appl8 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2ms_Appl8;

/*! HAL task context configuration data: Task_2ms_Appl9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_2ms_Appl9;

/*! HAL task context configuration data: Task_4msBsw_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_4msBsw_Appl10;

/*! HAL task context configuration data: Task_4ms_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_4ms_Appl10;

/*! HAL task context configuration data: Task_4ms_Appl7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_4ms_Appl7;

/*! HAL task context configuration data: Task_5msBsw_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_5msBsw_Appl10;

/*! HAL task context configuration data: Task_Coding_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_Coding_Appl10;

/*! HAL task context configuration data: Task_ComBsw_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_ComBsw_Appl10;

/*! HAL task context configuration data: Task_InitBsw_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_InitBsw_Appl10;

/*! HAL task context configuration data: Task_Init_Appl10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_Init_Appl10;

/*! HAL task context configuration data: Task_Init_Appl7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_Init_Appl7;

/*! HAL task context configuration data: Task_Init_Appl8 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_Init_Appl8;

/*! HAL task context configuration data: Task_Init_Appl9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Task_Init_Appl9;

/*! HAL service function context configuration data: NtWrapS_CmnMfgSrv_CallSvc10 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_CmnMfgSrv_CallSvc10;

/*! HAL service function stack configuration data: NtWrapS_CmnMfgSrv_CallSvc100 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_CmnMfgSrv_CallSvc100;

/*! HAL service function context configuration data: NtWrapS_NvM_EraseNvBlock */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_EraseNvBlock;

/*! HAL service function stack configuration data: NtWrapS_NvM_EraseNvBlock0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_EraseNvBlock0;

/*! HAL service function context configuration data: NtWrapS_NvM_GetDataIndex */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_GetDataIndex;

/*! HAL service function stack configuration data: NtWrapS_NvM_GetDataIndex0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_GetDataIndex0;

/*! HAL service function context configuration data: NtWrapS_NvM_GetErrorStatus */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_GetErrorStatus;

/*! HAL service function stack configuration data: NtWrapS_NvM_GetErrorStatus0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_GetErrorStatus0;

/*! HAL service function stack configuration data: NtWrapS_NvM_GetErrorStatus1 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_GetErrorStatus1;

/*! HAL service function stack configuration data: NtWrapS_NvM_GetErrorStatus2 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_GetErrorStatus2;

/*! HAL service function stack configuration data: NtWrapS_NvM_GetErrorStatus3 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_GetErrorStatus3;

/*! HAL service function context configuration data: NtWrapS_NvM_InvalidateNvBlock */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_InvalidateNvBlock;

/*! HAL service function stack configuration data: NtWrapS_NvM_InvalidateNvBlock0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_InvalidateNvBlock0;

/*! HAL service function context configuration data: NtWrapS_NvM_ReadBlock */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_ReadBlock;

/*! HAL service function stack configuration data: NtWrapS_NvM_ReadBlock0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_ReadBlock0;

/*! HAL service function context configuration data: NtWrapS_NvM_SetBlockProtection */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_SetBlockProtection;

/*! HAL service function stack configuration data: NtWrapS_NvM_SetBlockProtection0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_SetBlockProtection0;

/*! HAL service function context configuration data: NtWrapS_NvM_SetDataIndex */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_SetDataIndex;

/*! HAL service function stack configuration data: NtWrapS_NvM_SetDataIndex0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_SetDataIndex0;

/*! HAL service function context configuration data: NtWrapS_NvM_SetRamBlockStatus */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_SetRamBlockStatus;

/*! HAL service function stack configuration data: NtWrapS_NvM_SetRamBlockStatus0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_SetRamBlockStatus0;

/*! HAL service function context configuration data: NtWrapS_NvM_WriteBlock */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_NvM_WriteBlock;

/*! HAL service function stack configuration data: NtWrapS_NvM_WriteBlock0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_NvM_WriteBlock0;

/*! HAL service function context configuration data: NtWrapS_Rte_Call_CopyCalPageReq_Oper */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_Rte_Call_CopyCalPageReq_Oper;

/*! HAL service function stack configuration data: NtWrapS_Rte_Call_CopyCalPageReq_Oper0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_Rte_Call_CopyCalPageReq_Oper0;

/*! HAL service function context configuration data: NtWrapS_Rte_Call_SetCalPageReq_Oper */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_Rte_Call_SetCalPageReq_Oper;

/*! HAL service function stack configuration data: NtWrapS_Rte_Call_SetCalPageReq_Oper0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_Rte_Call_SetCalPageReq_Oper0;

/*! HAL service function context configuration data: NtWrapS_SyncCrc_GetAvlCrcHwUnit */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_SyncCrc_GetAvlCrcHwUnit;

/*! HAL service function stack configuration data: NtWrapS_SyncCrc_GetAvlCrcHwUnit0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_SyncCrc_GetAvlCrcHwUnit0;

/*! HAL service function context configuration data: NtWrapS_SyncCrc_RelsCrcHwUnit */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_SyncCrc_RelsCrcHwUnit;

/*! HAL service function stack configuration data: NtWrapS_SyncCrc_RelsCrcHwUnit0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_SyncCrc_RelsCrcHwUnit0;

/*! HAL service function context configuration data: NtWrapS_Xcp_Event */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_Xcp_Event;

/*! HAL service function stack configuration data: NtWrapS_Xcp_Event0 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_Xcp_Event0;

/*! HAL service function context configuration data: NtWrapS_CmnMfgSrv_CallSvc7 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_NtWrapS_CmnMfgSrv_CallSvc7;

/*! HAL service function stack configuration data: NtWrapS_CmnMfgSrv_CallSvc70 */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_NtWrapS_CmnMfgSrv_CallSvc70;

/*! HAL kernel stack configuration data: OsCore_CORE0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore_CORE0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
