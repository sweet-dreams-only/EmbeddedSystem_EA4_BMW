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
 *              File: Os_Stack_Cfg.h
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

#if !defined (OS_STACK_CFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_OFF)

/* Configured stack sizes (Total: 60416 Byte) */
# define OS_CFG_SIZE_NTWRAPS_CMNMFGSRV_CALLSVC100_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_CMNMFGSRV_CALLSVC70_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_ERASENVBLOCK0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_GETDATAINDEX0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS1_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS2_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_GETERRORSTATUS3_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_INVALIDATENVBLOCK0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_READBLOCK0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_SETBLOCKPROTECTION0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_SETDATAINDEX0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_SETRAMBLOCKSTATUS0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_NVM_WRITEBLOCK0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_SYNCCRC_RELSCRCHWUNIT0_STACK     (512UL)
# define OS_CFG_SIZE_NTWRAPS_XCP_EVENT0_STACK     (512UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL1_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL4_STACK     (512UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_LEVEL5_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO1_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO10_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO11_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO12_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO13_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO17_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO18_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO19_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO2_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO20_STACK     (4096UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO22_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO23_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO25_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO3_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO4_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO5_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO8_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO9_STACK     (1024UL)
# define OS_CFG_SIZE_TASK_100MS_APPL10_STACK     (1024UL)
# define OS_CFG_SIZE_TASK_10MS_APPL10_STACK     (4096UL)
# define OS_CFG_SIZE_TASK_5MSBSW_APPL10_STACK     (2048UL)
# define OS_CFG_SIZE_TASK_CODING_APPL10_STACK     (8192UL)
# define OS_CFG_SIZE_TASK_COMBSW_APPL10_STACK     (1024UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
