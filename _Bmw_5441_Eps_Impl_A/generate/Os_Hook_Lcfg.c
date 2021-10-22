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
 *              File: Os_Hook_Lcfg.c
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

#define OS_HOOK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


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

/*! Dynamic hook data: Os_CoreInitHook_OsCore_CORE0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore_CORE0_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore_CORE0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore_CORE0_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore_CORE0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore_CORE0_Dyn;

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

/*! Hook configuration data: Os_CoreInitHook_OsCore_CORE0 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore_CORE0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore_CORE0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)0,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: ShutdownHook_OsCore_CORE0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore_CORE0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_CORE0,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_CORE0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore_CORE0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)1,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore_CORE0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore_CORE0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore_CORE0,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore_CORE0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore_CORE0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SystemApplication,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)2,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for hook callbacks. */
CONSTP2CONST(Os_HookConfigType, OS_CONST, OS_CONST) OsCfg_HookRefs[OS_CFG_NUM_HOOKS + 1] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_CORE0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_CORE0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_CORE0),
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
 *  END OF FILE: Os_Hook_Lcfg.c
 *********************************************************************************************************************/
