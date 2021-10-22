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
 *              File: Os_Types_Lcfg.h
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

#if !defined (OS_TYPES_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Application identifier. */
typedef enum
{
  Appl0 = 0, /* 0x00000001 */
  Appl10 = 1, /* 0x00000002 */
  Appl7 = 2, /* 0x00000004 */
  Appl8 = 3, /* 0x00000008 */
  Appl9 = 4, /* 0x00000010 */
  SystemApplication = 5, /* 0x00000020 */
  OS_APPID_COUNT = 6,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifier. */
typedef enum
{
  Os_ServiceCallee_Adc0OutpInin = 0,
  Os_ServiceCallee_CritRegInitChk = 1,
  Os_ServiceCallee_CritRegPerChk = 2,
  Os_ServiceCallee_DmaRegInin = 3,
  Os_ServiceCallee_DtsClnUp = 4,
  Os_ServiceCallee_DtsInin = 5,
  Os_ServiceCallee_EcuM_GoDown = 6,
  Os_ServiceCallee_Fls_MainFunction = 7,
  Os_ServiceCallee_IpgInin = 8,
  Os_ServiceCallee_NvM_MainFunction = 9,
  Os_ServiceCallee_NxtrWdgM_Init = 10,
  Os_ServiceCallee_RstRackCentrMotAg_Oper = 11,
  Os_ServiceCallee_RstRackCentrMotRev_Oper = 12,
  Os_ServiceCallee_SetInpPrm_Oper = 13,
  Os_ServiceCallee_Spi_AsyncTransmit = 14,
  Os_ServiceCallee_XcpAppl_CalibrationWriteTrustd = 15,
  OS_TRUSTEDFUNCTIONID_COUNT = 16
} TrustedFunctionIndexType;

/*! Non-Trusted function identifier. */
typedef enum
{
  NtWrapS_CmnMfgSrv_CallSvc10 = 0,
  NtWrapS_NvM_EraseNvBlock = 1,
  NtWrapS_NvM_GetDataIndex = 2,
  NtWrapS_NvM_GetErrorStatus = 3,
  NtWrapS_NvM_InvalidateNvBlock = 4,
  NtWrapS_NvM_ReadBlock = 5,
  NtWrapS_NvM_SetBlockProtection = 6,
  NtWrapS_NvM_SetDataIndex = 7,
  NtWrapS_NvM_SetRamBlockStatus = 8,
  NtWrapS_NvM_WriteBlock = 9,
  NtWrapS_Rte_Call_CopyCalPageReq_Oper = 10,
  NtWrapS_Rte_Call_SetCalPageReq_Oper = 11,
  NtWrapS_SyncCrc_GetAvlCrcHwUnit = 12,
  NtWrapS_SyncCrc_RelsCrcHwUnit = 13,
  NtWrapS_Xcp_Event = 14,
  NtWrapS_CmnMfgSrv_CallSvc7 = 15,
  OS_NONTRUSTEDFUNCTIONID_COUNT = 16
} Os_NonTrustedFunctionIndexType;

/*! Fast Trusted function identifier. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifier. */
typedef enum
{
  IdleTask_OsCore_CORE0 = 0,
  Task_100ms_Appl10 = 1,
  Task_100ms_Appl7 = 2,
  Task_100ms_Appl9 = 3,
  Task_10msBsw_Appl10 = 4,
  Task_10ms_Appl10 = 5,
  Task_10ms_Appl7 = 6,
  Task_10ms_Appl8 = 7,
  Task_10ms_Appl9 = 8,
  Task_2msA_Appl10 = 9,
  Task_2msB_Appl10 = 10,
  Task_2msTmplMonr_Appl10 = 11,
  Task_2ms_Appl7 = 12,
  Task_2ms_Appl8 = 13,
  Task_2ms_Appl9 = 14,
  Task_4msBsw_Appl10 = 15,
  Task_4ms_Appl10 = 16,
  Task_4ms_Appl7 = 17,
  Task_5msBsw_Appl10 = 18,
  Task_Coding_Appl10 = 19,
  Task_ComBsw_Appl10 = 20,
  Task_InitBsw_Appl10 = 21,
  Task_Init_Appl10 = 22,
  Task_Init_Appl7 = 23,
  Task_Init_Appl8 = 24,
  Task_Init_Appl9 = 25,
  OS_TASKID_COUNT = 26,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifier. */
typedef enum
{
  CounterIsr_OsCounter = 0,
  Fr_IrqLine0 = 1,
  Fr_IrqTimer0 = 2,
  MCU_ECM_EIC_CAT2_ISR = 3,
  SPI_CSIG0_TIC_CAT2_ISR = 4,
  SPI_CSIG0_TIRE_CAT2_ISR = 5,
  SPI_CSIG0_TIR_CAT2_ISR = 6,
  SPI_CSIH2_TIC_CAT2_ISR = 7,
  SPI_CSIH2_TIRE_CAT2_ISR = 8,
  SPI_CSIH2_TIR_CAT2_ISR = 9,
  OS_ISRID_COUNT = 10,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifier. */
typedef enum
{
  Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms = 0,
  Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms = 1,
  Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms = 2,
  Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms = 3,
  Rte_Al_TE_Darh_QueueHandler = 4,
  Rte_Al_TE_Task_100ms_Appl10_0_100ms = 5,
  Rte_Al_TE_Task_100ms_Appl7_0_100ms = 6,
  Rte_Al_TE_Task_100ms_Appl9_0_100ms = 7,
  Rte_Al_TE_Task_10ms_Appl10_0_10ms = 8,
  Rte_Al_TE_Task_10ms_Appl7_0_10ms = 9,
  Rte_Al_TE_Task_10ms_Appl8_0_10ms = 10,
  Rte_Al_TE_Task_10ms_Appl9_0_10ms = 11,
  Rte_Al_TE_Task_2msA_Appl10_0_2ms = 12,
  Rte_Al_TE_Task_2msB_Appl10_0_2ms = 13,
  Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms = 14,
  Rte_Al_TE_Task_2ms_Appl7_0_2ms = 15,
  Rte_Al_TE_Task_2ms_Appl8_0_2ms = 16,
  Rte_Al_TE_Task_2ms_Appl9_0_2ms = 17,
  Rte_Al_TE_Task_4ms_Appl10_0_4ms = 18,
  Rte_Al_TE_Task_4ms_Appl7_0_4ms = 19,
  Rte_Al_TE_Task_ComBsw_Appl10_0_10ms = 20,
  OS_ALARMID_COUNT = 21
} AlarmType;

/*! Counter identifier. */
typedef enum
{
  FrCycleCounter = 0,
  OsCounter = 1,
  OS_COUNTERID_COUNT = 2
} CounterType;

/*! ScheduleTable identifier. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifier. */
typedef enum
{
  OsResource = 0,
  Rte_Res_Vin_VinState = 1,
  OS_RESOURCEID_COUNT = 2
} ResourceType;

/*! Spinlock identifier. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifier. */
typedef enum
{
  InterruptController = 0,
  OS_PERIPHERALID_COUNT = 1
} Os_PeripheralIdType;

/*! Trace thread identifier (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifier (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
