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
 *              File: Os_Task_Lcfg.h
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

#if !defined (OS_TASK_LCFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
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

/*! Task configuration data: IdleTask_OsCore_CORE0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore_CORE0;

/*! Task configuration data: Task_100ms_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_100ms_Appl10;

/*! Task configuration data: Task_100ms_Appl7 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_100ms_Appl7;

/*! Task configuration data: Task_100ms_Appl9 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_100ms_Appl9;

/*! Task configuration data: Task_10msBsw_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_10msBsw_Appl10;

/*! Task configuration data: Task_10ms_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_10ms_Appl10;

/*! Task configuration data: Task_10ms_Appl7 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_10ms_Appl7;

/*! Task configuration data: Task_10ms_Appl8 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_10ms_Appl8;

/*! Task configuration data: Task_10ms_Appl9 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_10ms_Appl9;

/*! Task configuration data: Task_2msA_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2msA_Appl10;

/*! Task configuration data: Task_2msB_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2msB_Appl10;

/*! Task configuration data: Task_2msTmplMonr_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2msTmplMonr_Appl10;

/*! Task configuration data: Task_2ms_Appl7 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2ms_Appl7;

/*! Task configuration data: Task_2ms_Appl8 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2ms_Appl8;

/*! Task configuration data: Task_2ms_Appl9 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_2ms_Appl9;

/*! Task configuration data: Task_4msBsw_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_4msBsw_Appl10;

/*! Task configuration data: Task_4ms_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_4ms_Appl10;

/*! Task configuration data: Task_4ms_Appl7 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_4ms_Appl7;

/*! Task configuration data: Task_5msBsw_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_5msBsw_Appl10;

/*! Task configuration data: Task_Coding_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_Coding_Appl10;

/*! Task configuration data: Task_ComBsw_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_ComBsw_Appl10;

/*! Task configuration data: Task_InitBsw_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_InitBsw_Appl10;

/*! Task configuration data: Task_Init_Appl10 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_Init_Appl10;

/*! Task configuration data: Task_Init_Appl7 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_Init_Appl7;

/*! Task configuration data: Task_Init_Appl8 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_Init_Appl8;

/*! Task configuration data: Task_Init_Appl9 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Task_Init_Appl9;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
