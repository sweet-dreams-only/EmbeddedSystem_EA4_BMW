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
 *              File: Os_Isr_Lcfg.c
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

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

/*! Dynamic ISR data: CounterIsr_OsCounter */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_OsCounter_Dyn;

/*! Dynamic ISR data: Fr_IrqLine0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Fr_IrqLine0_Dyn;

/*! Dynamic ISR data: Fr_IrqTimer0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Fr_IrqTimer0_Dyn;

/*! Dynamic ISR data: MCU_ECM_EIC_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_MCU_ECM_EIC_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIG0_TIC_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIG0_TIC_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIG0_TIRE_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIG0_TIRE_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIG0_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIG0_TIR_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIH2_TIC_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH2_TIC_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIH2_TIRE_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH2_TIRE_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIH2_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_Dyn;

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

/*! ISR configuration data: AlgnErrIrq */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_AlgnErrIrq =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_AlgnErrIrq,
};
/*! ISR configuration data: CounterIsr_OsCounter */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_OsCounter,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level4,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_OsCounter_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CounterIsr_OsCounter,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CounterIsr_OsCounter,
  /* .IsrId    = */ CounterIsr_OsCounter
},
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter)
};
/*! ISR configuration data: FpuErrIrq */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_FpuErrIrq =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_FpuErrIrq,
};
/*! ISR configuration data: Fr_IrqLine0 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Fr_IrqLine0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Fr_IrqLine0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Fr_IrqLine0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Fr_IrqLine0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Fr_IrqLine0,
  /* .IsrId    = */ Fr_IrqLine0
};
/*! ISR configuration data: Fr_IrqTimer0 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Fr_IrqTimer0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Fr_IrqTimer0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Fr_IrqTimer0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl10,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Fr_IrqTimer0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Fr_IrqTimer0,
  /* .IsrId    = */ Fr_IrqTimer0
};
/*! ISR configuration data: MCU_ECM_EIC_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_MCU_ECM_EIC_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MCU_ECM_EIC_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level5,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_MCU_ECM_EIC_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_MCU_ECM_EIC_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_MCU_ECM_EIC_CAT2_ISR,
  /* .IsrId    = */ MCU_ECM_EIC_CAT2_ISR
};
/*! ISR configuration data: MCU_FEINT_ISR */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_MCU_FEINT_ISR =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_MCU_FEINT_ISR,
};
/*! ISR configuration data: MotCtrlMgrIrq */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_MotCtrlMgrIrq =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_MotCtrlMgrIrq,
};
/*! ISR configuration data: ResdOperIrq */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_ResdOperIrq =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_ResdOperIrq,
};
/*! ISR configuration data: SPI_CSIG0_TIC_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIG0_TIC_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIG0_TIC_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level1,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIG0_TIC_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIG0_TIC_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIG0_TIC_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIG0_TIC_CAT2_ISR
};
/*! ISR configuration data: SPI_CSIG0_TIRE_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIG0_TIRE_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIG0_TIRE_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level1,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIG0_TIRE_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIG0_TIRE_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIG0_TIRE_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIG0_TIRE_CAT2_ISR
};
/*! ISR configuration data: SPI_CSIG0_TIR_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIG0_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIG0_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIG0_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIG0_TIR_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIG0_TIR_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIG0_TIR_CAT2_ISR
};
/*! ISR configuration data: SPI_CSIH2_TIC_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIC_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH2_TIC_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level1,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH2_TIC_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIH2_TIC_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIH2_TIC_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIH2_TIC_CAT2_ISR
};
/*! ISR configuration data: SPI_CSIH2_TIRE_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIRE_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH2_TIRE_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Level1,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH2_TIRE_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIH2_TIRE_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIH2_TIRE_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIH2_TIRE_CAT2_ISR
};
/*! ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH2_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Appl0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIH2_TIR_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SPI_CSIH2_TIR_CAT2_ISR,
  /* .IsrId    = */ SPI_CSIH2_TIR_CAT2_ISR
};
/*! ISR configuration data: SysErrIrq */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_SysErrIrq =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_SysErrIrq,
};
/*! ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_ISR */
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_ISR =
{
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_WDG_59_DRIVERA_TRIGGERFUNCTION_ISR,
};
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Fr_IrqLine0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Fr_IrqTimer0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ECM_EIC_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIG0_TIC_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIG0_TIRE_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIG0_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH2_TIC_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH2_TIRE_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
