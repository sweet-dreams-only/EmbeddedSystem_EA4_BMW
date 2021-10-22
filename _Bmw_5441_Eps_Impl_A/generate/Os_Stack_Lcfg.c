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
 *              File: Os_Stack_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:09
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

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_STACK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Stack_Cfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Stack.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_STACK_NTWRAPS_CMNMFGSRV_CALLSVC100_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_CmnMfgSrv_CallSvc100 */
/* User: [NtWrapS_CmnMfgSrv_CallSvc10] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc100_Dyn, OS_CFG_SIZE_NTWRAPS_CMNMFGSRV_CALLSVC100_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_CMNMFGSRV_CALLSVC100_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_CMNMFGSRV_CALLSVC70_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_CmnMfgSrv_CallSvc70 */
/* User: [NtWrapS_CmnMfgSrv_CallSvc7] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc70_Dyn, OS_CFG_SIZE_NTWRAPS_CMNMFGSRV_CALLSVC70_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_CMNMFGSRV_CALLSVC70_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_ERASENVBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_EraseNvBlock0 */
/* User: [NtWrapS_NvM_EraseNvBlock] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_EraseNvBlock0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_ERASENVBLOCK0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_ERASENVBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_GETDATAINDEX0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_GetDataIndex0 */
/* User: [NtWrapS_NvM_GetDataIndex] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_GetDataIndex0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_GETDATAINDEX0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_GETDATAINDEX0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_GetErrorStatus0 */
/* User: [NtWrapS_NvM_GetErrorStatus] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_GetErrorStatus1 */
/* User: [NtWrapS_NvM_GetErrorStatus] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus1_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS1_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_GetErrorStatus2 */
/* User: [NtWrapS_NvM_GetErrorStatus] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus2_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS2_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_GetErrorStatus3 */
/* User: [NtWrapS_NvM_GetErrorStatus] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus3_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS3_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_GETERRORSTATUS3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_INVALIDATENVBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_InvalidateNvBlock0 */
/* User: [NtWrapS_NvM_InvalidateNvBlock] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_InvalidateNvBlock0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_INVALIDATENVBLOCK0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_INVALIDATENVBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_READBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_ReadBlock0 */
/* User: [NtWrapS_NvM_ReadBlock] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_ReadBlock0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_READBLOCK0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_READBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_SETBLOCKPROTECTION0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_SetBlockProtection0 */
/* User: [NtWrapS_NvM_SetBlockProtection] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_SetBlockProtection0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_SETBLOCKPROTECTION0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_SETBLOCKPROTECTION0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_SETDATAINDEX0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_SetDataIndex0 */
/* User: [NtWrapS_NvM_SetDataIndex] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_SetDataIndex0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_SETDATAINDEX0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_SETDATAINDEX0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_SETRAMBLOCKSTATUS0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_SetRamBlockStatus0 */
/* User: [NtWrapS_NvM_SetRamBlockStatus] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_SetRamBlockStatus0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_SETRAMBLOCKSTATUS0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_SETRAMBLOCKSTATUS0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_NVM_WRITEBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_NvM_WriteBlock0 */
/* User: [NtWrapS_NvM_WriteBlock] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_NvM_WriteBlock0_Dyn, OS_CFG_SIZE_NTWRAPS_NVM_WRITEBLOCK0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_NVM_WRITEBLOCK0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_Rte_Call_CopyCalPageReq_Oper0 */
/* User: [NtWrapS_Rte_Call_CopyCalPageReq_Oper] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_Rte_Call_CopyCalPageReq_Oper0_Dyn, OS_CFG_SIZE_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_Rte_Call_SetCalPageReq_Oper0 */
/* User: [NtWrapS_Rte_Call_SetCalPageReq_Oper] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_Rte_Call_SetCalPageReq_Oper0_Dyn, OS_CFG_SIZE_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_SyncCrc_GetAvlCrcHwUnit0 */
/* User: [NtWrapS_SyncCrc_GetAvlCrcHwUnit] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_SyncCrc_GetAvlCrcHwUnit0_Dyn, OS_CFG_SIZE_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_SYNCCRC_RELSCRCHWUNIT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_SyncCrc_RelsCrcHwUnit0 */
/* User: [NtWrapS_SyncCrc_RelsCrcHwUnit] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_SyncCrc_RelsCrcHwUnit0_Dyn, OS_CFG_SIZE_NTWRAPS_SYNCCRC_RELSCRCHWUNIT0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_SYNCCRC_RELSCRCHWUNIT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_NTWRAPS_XCP_EVENT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Non-trusted function stack: NtWrapS_Xcp_Event0 */
/* User: [NtWrapS_Xcp_Event] */
OS_STACK_DECLARE(OsCfg_Stack_NtWrapS_Xcp_Event0_Dyn, OS_CFG_SIZE_NTWRAPS_XCP_EVENT0_STACK);

#define OS_STOP_SEC_STACK_NTWRAPS_XCP_EVENT0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_CORE0_Error */
/* User: [ErrorHook_OsCore_CORE0, OsCore_CORE0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_CORE0_Init */
/* User: [OsCore_CORE0, Os_CoreInitHook_OsCore_CORE0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_CORE0_Isr_Core */
/* User: [SPI_CSIG0_TIR_CAT2_ISR, SPI_CSIH2_TIR_CAT2_ISR, Fr_IrqLine0, Fr_IrqTimer0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ISR_LEVEL1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared ISR level stack: OsCore_CORE0_Isr_Level1 */
/* User: [SPI_CSIG0_TIRE_CAT2_ISR, SPI_CSIH2_TIC_CAT2_ISR, SPI_CSIH2_TIRE_CAT2_ISR, SPI_CSIG0_TIC_CAT2_ISR] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Isr_Level1_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL1_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_LEVEL1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ISR_LEVEL4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared ISR level stack: OsCore_CORE0_Isr_Level4 */
/* User: [CounterIsr_OsCounter] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Isr_Level4_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL4_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_LEVEL4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_ISR_LEVEL5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared ISR level stack: OsCore_CORE0_Isr_Level5 */
/* User: [MCU_ECM_EIC_CAT2_ISR] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Isr_Level5_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL5_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_LEVEL5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_CORE0_Kernel */
/* User: [OsCore_CORE0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core shutdown stack: OsCore_CORE0_Shutdown */
/* User: [OsCore_CORE0, ShutdownHook_OsCore_CORE0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio0 */
/* User: [Task_Init_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio1 */
/* User: [Task_Init_Appl9] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio1_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO1_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio10 */
/* User: [Task_2ms_Appl9] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio10_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO10_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO11_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio11 */
/* User: [Task_2msB_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio11_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO11_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO11_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO12_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio12 */
/* User: [Task_4ms_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio12_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO12_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO12_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO13_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio13 */
/* User: [Task_4ms_Appl7] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio13_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO13_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO13_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO17_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio17 */
/* User: [Task_10ms_Appl9] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio17_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO17_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO17_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO18_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio18 */
/* User: [Task_10ms_Appl8] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio18_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO18_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO18_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO19_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio19 */
/* User: [Task_10ms_Appl7] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio19_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO19_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO19_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio2 */
/* User: [Task_Init_Appl8] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio2_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO2_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio20 */
/* User: [Task_10msBsw_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO20_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO22_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio22 */
/* User: [Task_100ms_Appl9] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio22_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO22_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO22_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO23_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio23 */
/* User: [Task_100ms_Appl7] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio23_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO23_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO23_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO25_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio25 */
/* User: [IdleTask_OsCore_CORE0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio25_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO25_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO25_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio3 */
/* User: [Task_Init_Appl7] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio3_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO3_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio4 */
/* User: [Task_InitBsw_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio4_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO4_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio5 */
/* User: [Task_4msBsw_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio5_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO5_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio6 */
/* User: [Task_2msTmplMonr_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio6_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio7 */
/* User: [Task_2msA_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO8_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio8 */
/* User: [Task_2ms_Appl8] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio8_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO8_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO8_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_CORE0_Task_Prio9 */
/* User: [Task_2ms_Appl7] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore_CORE0_Task_Prio9_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO9_STACK);

#define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_TASK_100MS_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Task_100ms_Appl10 */
/* User: [Task_100ms_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_Task_100ms_Appl10_Dyn, OS_CFG_SIZE_TASK_100MS_APPL10_STACK);

#define OS_STOP_SEC_STACK_TASK_100MS_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_TASK_10MS_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Task_10ms_Appl10 */
/* User: [Task_10ms_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_Task_10ms_Appl10_Dyn, OS_CFG_SIZE_TASK_10MS_APPL10_STACK);

#define OS_STOP_SEC_STACK_TASK_10MS_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_TASK_5MSBSW_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Task_5msBsw_Appl10 */
/* User: [Task_5msBsw_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_Task_5msBsw_Appl10_Dyn, OS_CFG_SIZE_TASK_5MSBSW_APPL10_STACK);

#define OS_STOP_SEC_STACK_TASK_5MSBSW_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_TASK_CODING_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Task_Coding_Appl10 */
/* User: [Task_Coding_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_Task_Coding_Appl10_Dyn, OS_CFG_SIZE_TASK_CODING_APPL10_STACK);

#define OS_STOP_SEC_STACK_TASK_CODING_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_STACK_TASK_COMBSW_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Task_ComBsw_Appl10 */
/* User: [Task_ComBsw_Appl10] */
OS_STACK_DECLARE(OsCfg_Stack_Task_ComBsw_Appl10_Dyn, OS_CFG_SIZE_TASK_COMBSW_APPL10_STACK);

#define OS_STOP_SEC_STACK_TASK_COMBSW_APPL10_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: NtWrapS_CmnMfgSrv_CallSvc100 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc100 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc100_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc100_Dyn)
};

/*! Stack configuration data: NtWrapS_CmnMfgSrv_CallSvc70 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc70 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc70_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_CmnMfgSrv_CallSvc70_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_EraseNvBlock0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_EraseNvBlock0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_EraseNvBlock0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_EraseNvBlock0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_GetDataIndex0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_GetDataIndex0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_GetDataIndex0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_GetDataIndex0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_GetErrorStatus0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_GetErrorStatus0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_GetErrorStatus1 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_GetErrorStatus1 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus1_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus1_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_GetErrorStatus2 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_GetErrorStatus2 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus2_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus2_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_GetErrorStatus3 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_GetErrorStatus3 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus3_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_GetErrorStatus3_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_InvalidateNvBlock0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_InvalidateNvBlock0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_InvalidateNvBlock0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_InvalidateNvBlock0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_ReadBlock0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_ReadBlock0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_ReadBlock0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_ReadBlock0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_SetBlockProtection0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_SetBlockProtection0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_SetBlockProtection0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_SetBlockProtection0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_SetDataIndex0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_SetDataIndex0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_SetDataIndex0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_SetDataIndex0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_SetRamBlockStatus0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_SetRamBlockStatus0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_SetRamBlockStatus0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_SetRamBlockStatus0_Dyn)
};

/*! Stack configuration data: NtWrapS_NvM_WriteBlock0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_NvM_WriteBlock0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_NvM_WriteBlock0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_NvM_WriteBlock0_Dyn)
};

/*! Stack configuration data: NtWrapS_Rte_Call_CopyCalPageReq_Oper0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_Rte_Call_CopyCalPageReq_Oper0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_Rte_Call_CopyCalPageReq_Oper0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_Rte_Call_CopyCalPageReq_Oper0_Dyn)
};

/*! Stack configuration data: NtWrapS_Rte_Call_SetCalPageReq_Oper0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_Rte_Call_SetCalPageReq_Oper0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_Rte_Call_SetCalPageReq_Oper0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_Rte_Call_SetCalPageReq_Oper0_Dyn)
};

/*! Stack configuration data: NtWrapS_SyncCrc_GetAvlCrcHwUnit0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_SyncCrc_GetAvlCrcHwUnit0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_SyncCrc_GetAvlCrcHwUnit0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_SyncCrc_GetAvlCrcHwUnit0_Dyn)
};

/*! Stack configuration data: NtWrapS_SyncCrc_RelsCrcHwUnit0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_SyncCrc_RelsCrcHwUnit0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_SyncCrc_RelsCrcHwUnit0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_SyncCrc_RelsCrcHwUnit0_Dyn)
};

/*! Stack configuration data: NtWrapS_Xcp_Event0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_NtWrapS_Xcp_Event0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_NtWrapS_Xcp_Event0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_NtWrapS_Xcp_Event0_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Error */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Error =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Error_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Error_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Init */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Init =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Init_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Init_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Isr_Core */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Isr_Core =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Core_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Core_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Isr_Level1 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Isr_Level1 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level1_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level1_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Isr_Level4 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Isr_Level4 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level4_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level4_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Isr_Level5 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Isr_Level5 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level5_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Isr_Level5_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Kernel */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Kernel =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Kernel_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Kernel_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Shutdown */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Shutdown =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Shutdown_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Shutdown_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio0_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio1 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio1 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio1_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio1_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio10_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio11 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio11 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio11_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio11_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio12 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio12 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio12_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio12_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio13 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio13 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio13_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio13_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio17 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio17 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio17_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio17_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio18 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio18 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio18_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio18_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio19 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio19 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio19_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio19_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio2 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio2 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio2_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio2_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio20 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio20 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio20_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio20_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio22 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio22 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio22_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio22_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio23 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio23 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio23_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio23_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio25 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio25 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio25_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio25_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio3 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio3 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio3_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio3_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio4 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio4 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio4_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio4_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio5 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio5 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio5_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio5_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio6 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio6 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio6_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio6_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio7 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio7 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio7_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio7_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio8 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio8 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio8_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio8_Dyn)
};

/*! Stack configuration data: OsCore_CORE0_Task_Prio9 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_CORE0_Task_Prio9 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio9_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore_CORE0_Task_Prio9_Dyn)
};

/*! Stack configuration data: Task_100ms_Appl10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Task_100ms_Appl10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Task_100ms_Appl10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Task_100ms_Appl10_Dyn)
};

/*! Stack configuration data: Task_10ms_Appl10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Task_10ms_Appl10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Task_10ms_Appl10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Task_10ms_Appl10_Dyn)
};

/*! Stack configuration data: Task_5msBsw_Appl10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Task_5msBsw_Appl10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Task_5msBsw_Appl10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Task_5msBsw_Appl10_Dyn)
};

/*! Stack configuration data: Task_Coding_Appl10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Task_Coding_Appl10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Task_Coding_Appl10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Task_Coding_Appl10_Dyn)
};

/*! Stack configuration data: Task_ComBsw_Appl10 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Task_ComBsw_Appl10 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Task_ComBsw_Appl10_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Task_ComBsw_Appl10_Dyn)
};


#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.c
 *********************************************************************************************************************/
