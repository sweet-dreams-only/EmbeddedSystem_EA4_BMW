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
 *              File: Os_Counter_Lcfg.c
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

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_COUNTER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_PriorityQueue.h"
#include "Os_Timer.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Timer_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic counter data: FrCycleCounter */
OS_LOCAL VAR(Os_TimerSwType, OS_VAR_NOINIT) OsCfg_Counter_FrCycleCounter_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_FrCycleCounter_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_FrCycleCounter_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_FRCYCLECOUNTER_JOBS + 1];

/*! Dynamic counter data: OsCounter */
OS_LOCAL VAR(Os_TimerSwType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_OsCounter_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_OSCOUNTER_JOBS + 1];

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Counter configuration data: FrCycleCounter */
CONST(Os_TimerSwConfigType, OS_CONST) OsCfg_Counter_FrCycleCounter =
{
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_FrCycleCounter,
      /* .MaxCountingValue     = */ OS_TIMERSW_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_FrCycleCounter),
      /* .MaxDifferentialValue = */ OS_TIMERSW_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_FrCycleCounter),
      /* .MinCycle             = */ OSMINCYCLE_FrCycleCounter,
      /* .TicksPerBase         = */ OSTICKSPERBASE_FrCycleCounter
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_FrCycleCounter_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_FrCycleCounter_JobQueue_Dyn,
      /* .QueueSize = */ OS_CFG_NUM_COUNTER_FRCYCLECOUNTER_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_SOFTWARE,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .OwnerApplication      = */ &OsCfg_App_Appl10,
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication))
  },
  /* .Dyn     = */ &OsCfg_Counter_FrCycleCounter_Dyn
};

/*! Counter configuration data: OsCounter */
CONST(Os_TimerPitConfigType, OS_CONST) OsCfg_Counter_OsCounter =
{
  /* .SwCounter = */
  {
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_OsCounter,
      /* .MaxCountingValue     = */ OS_TIMERPIT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_OsCounter),
      /* .MaxDifferentialValue = */ OS_TIMERPIT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_OsCounter),
      /* .MinCycle             = */ OSMINCYCLE_OsCounter,
      /* .TicksPerBase         = */ OSTICKSPERBASE_OsCounter
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_OsCounter_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_OsCounter_JobQueue_Dyn,
      /* .QueueSize = */ OS_CFG_NUM_COUNTER_OSCOUNTER_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_PERIODIC_TICK,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .OwnerApplication      = */ &OsCfg_App_Appl10,
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication))
  },
  /* .Dyn     = */ &OsCfg_Counter_OsCounter_Dyn
},
  /* .HwConfig  = */ &OsCfg_Hal_TimerPit_OsCounter
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for counters. */
CONSTP2CONST(Os_CounterConfigType, OS_CONST, OS_CONST) OsCfg_CounterRefs[OS_COUNTERID_COUNT + 1] =
{
  OS_COUNTER_CASTCONFIG_TIMERSW_2_COUNTER(OsCfg_Counter_FrCycleCounter),
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Counter_Lcfg.c
 *********************************************************************************************************************/
