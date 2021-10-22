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
 *              File: Os_Scheduler_Cfg.h
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

#if !defined (OS_SCHEDULER_CFG_H)                                                    /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (26UL)

/* Number of task queue activation slots: OsCore_CORE0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE8_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE9_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE10_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE11_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE12_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE13_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE14_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE15_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE16_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE17_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE18_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE19_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE20_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE21_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE22_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE23_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE24_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE25_OSCORE_CORE0_SLOTS     (2UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
