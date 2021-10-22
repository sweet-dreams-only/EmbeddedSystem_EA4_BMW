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
 *              File: Os_Alarm_Lcfg.h
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

#if !defined (OS_ALARM_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Alarm configuration data: Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms;

/*! Alarm configuration data: Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_Darh_QueueHandler */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Darh_QueueHandler;

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl10_0_100ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl10_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl7_0_100ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl7_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl9_0_100ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl9_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl10_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl10_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl7_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl7_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl8_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl8_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl9_0_10ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl9_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2msA_Appl10_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msA_Appl10_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2msB_Appl10_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msB_Appl10_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl7_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl7_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl8_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl8_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl9_0_2ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl9_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_Task_4ms_Appl10_0_4ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl10_0_4ms;

/*! Alarm configuration data: Rte_Al_TE_Task_4ms_Appl7_0_4ms */
extern CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl7_0_4ms;

/*! Alarm configuration data: Rte_Al_TE_Task_ComBsw_Appl10_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_ComBsw_Appl10_0_10ms;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
