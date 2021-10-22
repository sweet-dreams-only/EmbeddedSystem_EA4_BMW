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
 *              File: Os_Lcfg.h
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

#if !defined (OS_LCFG_H)                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */
#include "TrustdFctDefn.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Backward compatibility API defines for trusted function stubs. */
# define Call_Adc0OutpInin     Os_Call_Adc0OutpInin
# define Call_CritRegInitChk     Os_Call_CritRegInitChk
# define Call_CritRegPerChk     Os_Call_CritRegPerChk
# define Call_DmaRegInin     Os_Call_DmaRegInin
# define Call_DtsClnUp     Os_Call_DtsClnUp
# define Call_DtsInin     Os_Call_DtsInin
# define Call_EcuM_GoDown     Os_Call_EcuM_GoDown
# define Call_Fls_MainFunction     Os_Call_Fls_MainFunction
# define Call_IpgInin     Os_Call_IpgInin
# define Call_NvM_MainFunction     Os_Call_NvM_MainFunction
# define Call_NxtrWdgM_Init     Os_Call_NxtrWdgM_Init
# define Call_RstRackCentrMotAg_Oper     Os_Call_RstRackCentrMotAg_Oper
# define Call_RstRackCentrMotRev_Oper     Os_Call_RstRackCentrMotRev_Oper
# define Call_SetInpPrm_Oper     Os_Call_SetInpPrm_Oper
# define Call_Spi_AsyncTransmit     Os_Call_Spi_AsyncTransmit
# define Call_XcpAppl_CalibrationWriteTrustd     Os_Call_XcpAppl_CalibrationWriteTrustd


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_Task_100ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_100ms_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_100MS_APPL10_CODE) Os_Task_Task_100ms_Appl10(void);

# define OS_STOP_SEC_Task_100ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_100ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_100ms_Appl7()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_100MS_APPL7_CODE) Os_Task_Task_100ms_Appl7(void);

# define OS_STOP_SEC_Task_100ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_100ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_100ms_Appl9()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_100MS_APPL9_CODE) Os_Task_Task_100ms_Appl9(void);

# define OS_STOP_SEC_Task_100ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_10msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_10msBsw_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_10MSBSW_APPL10_CODE) Os_Task_Task_10msBsw_Appl10(void);

# define OS_STOP_SEC_Task_10msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_10ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_10ms_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_10MS_APPL10_CODE) Os_Task_Task_10ms_Appl10(void);

# define OS_STOP_SEC_Task_10ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_10ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_10ms_Appl7()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_10MS_APPL7_CODE) Os_Task_Task_10ms_Appl7(void);

# define OS_STOP_SEC_Task_10ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_10ms_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_10ms_Appl8()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_10MS_APPL8_CODE) Os_Task_Task_10ms_Appl8(void);

# define OS_STOP_SEC_Task_10ms_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_10ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_10ms_Appl9()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_10MS_APPL9_CODE) Os_Task_Task_10ms_Appl9(void);

# define OS_STOP_SEC_Task_10ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2msA_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2msA_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MSA_APPL10_CODE) Os_Task_Task_2msA_Appl10(void);

# define OS_STOP_SEC_Task_2msA_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2msB_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2msB_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MSB_APPL10_CODE) Os_Task_Task_2msB_Appl10(void);

# define OS_STOP_SEC_Task_2msB_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2msTmplMonr_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2msTmplMonr_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MSTMPLMONR_APPL10_CODE) Os_Task_Task_2msTmplMonr_Appl10(void);

# define OS_STOP_SEC_Task_2msTmplMonr_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2ms_Appl7()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MS_APPL7_CODE) Os_Task_Task_2ms_Appl7(void);

# define OS_STOP_SEC_Task_2ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2ms_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2ms_Appl8()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MS_APPL8_CODE) Os_Task_Task_2ms_Appl8(void);

# define OS_STOP_SEC_Task_2ms_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_2ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_2ms_Appl9()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_2MS_APPL9_CODE) Os_Task_Task_2ms_Appl9(void);

# define OS_STOP_SEC_Task_2ms_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_4msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_4msBsw_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_4MSBSW_APPL10_CODE) Os_Task_Task_4msBsw_Appl10(void);

# define OS_STOP_SEC_Task_4msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_4ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_4ms_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_4MS_APPL10_CODE) Os_Task_Task_4ms_Appl10(void);

# define OS_STOP_SEC_Task_4ms_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_4ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_4ms_Appl7()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_4MS_APPL7_CODE) Os_Task_Task_4ms_Appl7(void);

# define OS_STOP_SEC_Task_4ms_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_5msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_5msBsw_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_5MSBSW_APPL10_CODE) Os_Task_Task_5msBsw_Appl10(void);

# define OS_STOP_SEC_Task_5msBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_Coding_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_Coding_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_CODING_APPL10_CODE) Os_Task_Task_Coding_Appl10(void);

# define OS_STOP_SEC_Task_Coding_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_ComBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_ComBsw_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_COMBSW_APPL10_CODE) Os_Task_Task_ComBsw_Appl10(void);

# define OS_STOP_SEC_Task_ComBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_InitBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_InitBsw_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_INITBSW_APPL10_CODE) Os_Task_Task_InitBsw_Appl10(void);

# define OS_STOP_SEC_Task_InitBsw_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_Init_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_Init_Appl10()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_INIT_APPL10_CODE) Os_Task_Task_Init_Appl10(void);

# define OS_STOP_SEC_Task_Init_Appl10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_Init_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_Init_Appl7()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_INIT_APPL7_CODE) Os_Task_Task_Init_Appl7(void);

# define OS_STOP_SEC_Task_Init_Appl7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_Init_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_Init_Appl8()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_INIT_APPL8_CODE) Os_Task_Task_Init_Appl8(void);

# define OS_STOP_SEC_Task_Init_Appl8_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Task_Init_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Task_Init_Appl9()
 *********************************************************************************************************************/
extern FUNC(void, OS_TASK_INIT_APPL9_CODE) Os_Task_Task_Init_Appl9(void);

# define OS_STOP_SEC_Task_Init_Appl9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Fr_IrqLine0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Fr_IrqLine0()
 *********************************************************************************************************************/
extern FUNC(void, OS_FR_IRQLINE0_CODE) Os_Isr_Fr_IrqLine0(void);

# define OS_STOP_SEC_Fr_IrqLine0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Fr_IrqTimer0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Fr_IrqTimer0()
 *********************************************************************************************************************/
extern FUNC(void, OS_FR_IRQTIMER0_CODE) Os_Isr_Fr_IrqTimer0(void);

# define OS_STOP_SEC_Fr_IrqTimer0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_MCU_ECM_EIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  MCU_ECM_EIC_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_MCU_ECM_EIC_CAT2_ISR_CODE) Os_Isr_MCU_ECM_EIC_CAT2_ISR(void);

# define OS_STOP_SEC_MCU_ECM_EIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIG0_TIC_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIG0_TIC_CAT2_ISR_CODE) Os_Isr_SPI_CSIG0_TIC_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIG0_TIRE_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE) Os_Isr_SPI_CSIG0_TIRE_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIG0_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIG0_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIG0_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIH2_TIC_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH2_TIC_CAT2_ISR_CODE) Os_Isr_SPI_CSIH2_TIC_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIH2_TIRE_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE) Os_Isr_SPI_CSIH2_TIRE_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SPI_CSIH2_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH2_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIH2_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_Adc0OutpInin
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Adc0OutpInin
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_CritRegInitChk
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_CritRegInitChk
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_CritRegPerChk
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_CritRegPerChk
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_DmaRegInin
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_DmaRegInin
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_DtsClnUp
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_DtsClnUp
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_DtsInin
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_DtsInin
(
  uint32 Arg1,
  uint32 Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_EcuM_GoDown
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_EcuM_GoDown
(
  uint16 Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_Fls_MainFunction
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_Fls_MainFunction
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_IpgInin
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_IpgInin
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_NvM_MainFunction
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_NvM_MainFunction
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_NxtrWdgM_Init
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_NxtrWdgM_Init
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_RstRackCentrMotAg_Oper
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_RstRackCentrMotAg_Oper
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_RstRackCentrMotRev_Oper
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_RstRackCentrMotRev_Oper
(
  void
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_SetInpPrm_Oper
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Call_SetInpPrm_Oper
(
  float32 Arg1,
  float32 Arg2
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_Spi_AsyncTransmit
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Call_Spi_AsyncTransmit
(
  Spi_SequenceType Arg1
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Os_Call_XcpAppl_CalibrationWriteTrustd
 *********************************************************************************************************************/
/*! \brief        Packing part of call stub for service functions.
 *  \details      This function performs the packing. It's signature is identical to the configured function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *
 *  \note         Can be inlined.
 *********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Call_XcpAppl_CalibrationWriteTrustd
(
  Xcp_AddressPtrType Arg1,
  const uint8* Arg2,
  uint8 Arg3
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_CmnMfgSrv_CallSvc10
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_CMNMFGSRV_CALLSVC10_CODE) NONTRUSTED_NtWrapS_CmnMfgSrv_CallSvc10
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_EraseNvBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_EraseNvBlock
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_ERASENVBLOCK_CODE) NONTRUSTED_NtWrapS_NvM_EraseNvBlock
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_EraseNvBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_GetDataIndex_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_GetDataIndex
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_GETDATAINDEX_CODE) NONTRUSTED_NtWrapS_NvM_GetDataIndex
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_GetDataIndex_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_GetErrorStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_GetErrorStatus
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_GETERRORSTATUS_CODE) NONTRUSTED_NtWrapS_NvM_GetErrorStatus
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_GetErrorStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_InvalidateNvBlock
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_INVALIDATENVBLOCK_CODE) NONTRUSTED_NtWrapS_NvM_InvalidateNvBlock
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_ReadBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_ReadBlock
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_READBLOCK_CODE) NONTRUSTED_NtWrapS_NvM_ReadBlock
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_ReadBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_SetBlockProtection_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_SetBlockProtection
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_SETBLOCKPROTECTION_CODE) NONTRUSTED_NtWrapS_NvM_SetBlockProtection
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_SetBlockProtection_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_SetDataIndex_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_SetDataIndex
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_SETDATAINDEX_CODE) NONTRUSTED_NtWrapS_NvM_SetDataIndex
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_SetDataIndex_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_SetRamBlockStatus
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_SETRAMBLOCKSTATUS_CODE) NONTRUSTED_NtWrapS_NvM_SetRamBlockStatus
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_NvM_WriteBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_NvM_WriteBlock
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_NVM_WRITEBLOCK_CODE) NONTRUSTED_NtWrapS_NvM_WriteBlock
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_NvM_WriteBlock_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_Rte_Call_CopyCalPageReq_Oper
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER_CODE) NONTRUSTED_NtWrapS_Rte_Call_CopyCalPageReq_Oper
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_Rte_Call_SetCalPageReq_Oper
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER_CODE) NONTRUSTED_NtWrapS_Rte_Call_SetCalPageReq_Oper
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_SyncCrc_GetAvlCrcHwUnit
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT_CODE) NONTRUSTED_NtWrapS_SyncCrc_GetAvlCrcHwUnit
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_SyncCrc_RelsCrcHwUnit
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_SYNCCRC_RELSCRCHWUNIT_CODE) NONTRUSTED_NtWrapS_SyncCrc_RelsCrcHwUnit
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_Xcp_Event_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_Xcp_Event
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_XCP_EVENT_CODE) NONTRUSTED_NtWrapS_Xcp_Event
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_Xcp_Event_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  NONTRUSTED_NtWrapS_CmnMfgSrv_CallSvc7
 *********************************************************************************************************************/
FUNC(void, OS_NTWRAPS_CMNMFGSRV_CALLSVC7_CODE) NONTRUSTED_NtWrapS_CmnMfgSrv_CallSvc7
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);

# define OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
