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
 *              File: Os_Alarm_Lcfg.c
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

#define OS_ALARM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic alarm data: Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Darh_QueueHandler */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Darh_QueueHandler_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_100ms_Appl10_0_100ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl10_0_100ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_100ms_Appl7_0_100ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl7_0_100ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_100ms_Appl9_0_100ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl9_0_100ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_10ms_Appl10_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl10_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_10ms_Appl7_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl7_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_10ms_Appl8_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl8_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_10ms_Appl9_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl9_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2msA_Appl10_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2msA_Appl10_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2msB_Appl10_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2msB_Appl10_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2ms_Appl7_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl7_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2ms_Appl8_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl8_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_2ms_Appl9_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl9_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_4ms_Appl10_0_4ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl10_0_4ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_4ms_Appl7_0_4ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl7_0_4ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_Task_ComBsw_Appl10_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_Task_ComBsw_Appl10_0_10ms_Dyn;

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

/*! Alarm configuration data: Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_10msBsw_Appl10
};

/*! Alarm configuration data: Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_4msBsw_Appl10
};

/*! Alarm configuration data: Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_5msBsw_Appl10,
  /* .Mask  = */ Rte_Ev_Cyclic2_Task_5msBsw_Appl10_0_5ms
};

/*! Alarm configuration data: Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERSW_2_COUNTER(OsCfg_Counter_FrCycleCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_ComBsw_Appl10,
  /* .Mask  = */ Rte_Ev_Cyclic2_Task_ComBsw_Appl10_0_5ms
};

/*! Alarm configuration data: Rte_Al_TE_Darh_QueueHandler */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Darh_QueueHandler =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Darh_QueueHandler_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_100ms_Appl10,
  /* .Mask  = */ Rte_Ev_Run1_Darh_QueueHandler
};

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl10_0_100ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl10_0_100ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl10_0_100ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_100ms_Appl10,
  /* .Mask  = */ Rte_Ev_Cyclic_Task_100ms_Appl10_0_100ms
};

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl7_0_100ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl7_0_100ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl7_0_100ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl7)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl7
  },
  /* .Task  = */ &OsCfg_Task_Task_100ms_Appl7
};

/*! Alarm configuration data: Rte_Al_TE_Task_100ms_Appl9_0_100ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl9_0_100ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl9_0_100ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl9)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl9
  },
  /* .Task  = */ &OsCfg_Task_Task_100ms_Appl9
};

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl10_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl10_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl10_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_10ms_Appl10,
  /* .Mask  = */ Rte_Ev_Cyclic_Task_10ms_Appl10_0_10ms
};

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl7_0_10ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl7_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl7_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl7)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl7
  },
  /* .Task  = */ &OsCfg_Task_Task_10ms_Appl7
};

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl8_0_10ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl8_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl8_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl8)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl8
  },
  /* .Task  = */ &OsCfg_Task_Task_10ms_Appl8
};

/*! Alarm configuration data: Rte_Al_TE_Task_10ms_Appl9_0_10ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl9_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl9_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl9)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl9
  },
  /* .Task  = */ &OsCfg_Task_Task_10ms_Appl9
};

/*! Alarm configuration data: Rte_Al_TE_Task_2msA_Appl10_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msA_Appl10_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2msA_Appl10_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_2msA_Appl10
};

/*! Alarm configuration data: Rte_Al_TE_Task_2msB_Appl10_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msB_Appl10_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2msB_Appl10_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_2msB_Appl10
};

/*! Alarm configuration data: Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_2msTmplMonr_Appl10
};

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl7_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl7_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl7_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl7)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl7
  },
  /* .Task  = */ &OsCfg_Task_Task_2ms_Appl7
};

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl8_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl8_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl8_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl8)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl8
  },
  /* .Task  = */ &OsCfg_Task_Task_2ms_Appl8
};

/*! Alarm configuration data: Rte_Al_TE_Task_2ms_Appl9_0_2ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl9_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl9_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl9)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl9
  },
  /* .Task  = */ &OsCfg_Task_Task_2ms_Appl9
};

/*! Alarm configuration data: Rte_Al_TE_Task_4ms_Appl10_0_4ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl10_0_4ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl10_0_4ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_4ms_Appl10
};

/*! Alarm configuration data: Rte_Al_TE_Task_4ms_Appl7_0_4ms */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl7_0_4ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl7_0_4ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(Appl7)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl7
  },
  /* .Task  = */ &OsCfg_Task_Task_4ms_Appl7
};

/*! Alarm configuration data: Rte_Al_TE_Task_ComBsw_Appl10_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Task_ComBsw_Appl10_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_Task_ComBsw_Appl10_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERSW_2_COUNTER(OsCfg_Counter_FrCycleCounter),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(Appl10)
        | OS_APPID2MASK(SystemApplication)),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10
  },
  /* .Task  = */ &OsCfg_Task_Task_ComBsw_Appl10,
  /* .Mask  = */ Rte_Ev_Cyclic_Task_ComBsw_Appl10_0_10ms
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for alarms. */
CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Darh_QueueHandler),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl10_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl7_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_100ms_Appl9_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl10_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl7_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl8_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_10ms_Appl9_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2msA_Appl10_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2msB_Appl10_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl7_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl8_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_2ms_Appl9_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl10_0_4ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_4ms_Appl7_0_4ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Task_ComBsw_Appl10_0_10ms),
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
 *  END OF FILE: Os_Alarm_Lcfg.c
 *********************************************************************************************************************/
