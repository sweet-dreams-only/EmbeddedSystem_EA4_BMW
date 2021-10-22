/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Irq.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver A Component                                */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  29-Sep-2012    : As per SCR 020, if condition check is modified.
 *
 * V1.0.2:  23-Jan-2013    : As per SCR 068, in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR the pre-compile CAT2
 *                           interrupt condition is updated.
 *
 * V1.0.3:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.4:  27-Aug-2013    : As per CR 232 for mantis issue 12123 and 13035,
 *                           following changes are made:
 *                           1.Backslash removed for ANSI C code.
 *                           2.Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           3. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.5:  05-Mar-2014    : As per CR 422, critical section is added in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR.
 *
 * V1.0.6:  05-Jun-2014    : As per CR 490, source code has been modified in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR API to support the
 *                           functionality of clearing WUF flag in event wake
 *                           occurrence.
 *
 * V1.0.7:  10-Sep-2014    : As per CR 560 for mantis #22423, following changes
 *                           are made:
 *                           1.WdgWakeUp check is removed in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR API.
 *                           2. Renesas C coding guidelines for Equivalence
 *                           Test is taken care in comparing the variable with
 *                           constant, constant should be left hand side in
 *                           WDG_59_DRIVERA_ERROR_ISR API.
 *                           3. Macro WDG_59_DRIVERA_DEM_TYPE added in
 *                           WDG_59_DRIVERA_ERROR_ISR API for the removal of
 *                           MISRA violation with V8.1.1.
 *                           4. MISRA violation comments have been added for
 *                           MISRA Msg "(4:0303)-1".
 *
 * V1.0.8:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.9:  18-Mar-2016    : As part of P1x V4.01.00 release,the following
 *                           changes are made,
 *                           1.Added MISRA C Rule Violation for Msg(2:0862).
 *                           2.Copyright information is updated.
 *
 * V1.0.10: 19-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1838,
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR function is
 *                           updated to add WDG_59_DRIVERA_INTERRUPT_CONSISTENCY
 *                           _CHECK.
 *                           2.As per ARDAAAE-1752, WDG_59_DRIVERA_ERROR_ISR
 *                           API is updated to add pre compile check to enable
 *                           or disable E_MODE_FAILED DEM reporting.
 *                           3.As per ARDAAAE-1898, function
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR is updated with
 *                           WDG_59_DRIVERA_E_DRIVER_STATE DET reporting and WDG
 *                           driver state updation.
 *                           4.As per ARDAAAE-1908, function
 *                           WDG_59_DRIVERA_ERROR_ISR is removed and WUFC
 *                           register check is removed from
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR function, other
 *                           dead code removed.
 *                           5.Added QAC warning justification for Msg(2:3892).
 *                           6.As per ARDAAAE-1936,UD ID,requirement tags added.
 *                           7.As per ARDAAAE-2090, function
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR is updated to
 *                           remove uint16 typecast from WDG_59_DRIVERA_ZERO
 *                           macro.
 *                           8.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 *
 * V1.0.11:  07-Feb-2017  : Following changes are made:
 *                         1.As part of JIRA ID ARDAAAE-2121,added QAC warning
 *                           justification for Msg(2:3416) and Msg tags in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR API.
 *                         2.Copyright information is updated.
 *                         3.As part of JIRA ID ARDAAAE-2330,macro
 *                           WDG_59_DRIVERA_INTWDT_EIC_ADDR replaced by
 *                           WDG_59_DRIVERA_INTWDTEIC_ADDR in interrupt
 *                           consistency check.
 *                         4.As part of JIRA ID ARDAAAE-2355
 *                           The naming convention has changed from
 *                           Wdg_59_DriverA_GusTiggerCounter to
 *                           Wdg_59_DriverA_GulTiggerCounter
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG079] */
/* TRACE [R3, WDG079] */
/* TRACE [R4, WDG061] */
/* TRACE [R3, WDG061] */
/* Implements WDG169,WDG061,WDG034,WDG166 */
/* Implements EAAR_PN0034_NR_0001,EAAR_PN0034_FR_0081,EAAR_PN0034_FR_0030 */
/* Implements EAAR_PN0034_FR_0019,EAAR_PN0034_NR_0069,EAAR_PN0034_NR_0026 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* Included for ISR functions declaration */
#include "Wdg_59_DriverA_Irq.h"
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

/* Included for declaration of the function Wdg_59_DriverA_TriggerFunc() */
#include "Wdg_59_DriverA_Private.h"
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* Included for type definitions and macros */
#include "Wdg_59_DriverA_PBTypes.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_IRQ_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERA_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_IRQ_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERA_IRQ_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_IRQ_SW_MINOR_VERSION != \
                                         WDG_59_DRIVERA_IRQ_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) [I] Cast between a pointer to volatile object and */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : NA                                                         */
/* Justification : This is done to change the behaviour of  the expression    */
/*                 so as to get the correct value(of similar size) assigned   */
/*                 to the RHS.                                                */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-1 and              */
/*                 QAC Warning: END Msg(2:3892)-1 tags in the code.           */

/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       :(2:0862) This #include "%s" directive is redundant.         */
/* Rule          : NA                                                         */
/* Justification : All the #include "%s" files contains C function            */
/*                 declarations or macro definitions to be shared between     */
/*                 several source files. This violation is an approved        */
/*                 exception without side effects.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/* 3. QAC WARNING:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : NA                                                         */
/* Justification : Logical operation accesses global objects as per AUTOSAR   */
/*                 requirements WDG035 and WDG134.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:3416)-3 and              */
/*                 END Msg(2:3416)-3 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : WDG_59_DRIVERA_TRIGGERFUNCTION_ISR
**
** Service ID            : NA
**
** Description           : This is 75 % Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GulTiggerCounter.
**                         Wdg_59_DriverA_GddDriverState
**
** Functions Invoked     : Wdg_59_DriverA_TriggerFunc
**                         Det_ReportError, Dem_ReportErrorStatus
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**
** Registers Used        : None
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* TRACE [R4, WDG134] */
/* TRACE [R4, WDG135] */
/* Implements WDG_ESDD_UD_009 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG_ESDD_UD_005 */
/* Implements WDG079,WDG144,WDG134,WDG135,WDG035,WDG052 */
/* Implements EAAR_PN0034_FSR_0008,EAAR_PN0034_FSR_0009,EAAR_PN0034_FSR_0010 */
/* Implements EAAR_PN0034_NR_0002,EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0049 */
/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
ISR(WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                  WDG_59_DRIVERA_TRIGGERFUNCTION_ISR(void)
#endif
{
  /* Implements WDG_ESDD_UD_023 */
  /* Implements WDG_ESDD_UD_029 */
  /* QAC warning: START Msg(2:3416)-3 */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  if (WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState)
  {
    /* QAC warning: END Msg(2:3416)-3 */

    /* TRACE [R4, WDG035] */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
          WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_ID, WDG_59_DRIVERA_E_DRIVER_STATE);
  }
  else
  #endif
  {

    #if (WDG_59_DRIVERA_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
     /* MISRA Violation: START Msg(4:0303)-1 */
     /* QAC Warning: START Msg(2:3892)-1 */
     /* Implements WDG_ESDD_UD_008 */
     /* Implements WDG_ESDD_UD_027 */
    if (WDG_EIC_EIMK_MASK == (uint16)((*WDG_59_DRIVERA_INTWDTEIC_ADDR) &
                                            WDG_EIC_EIMK_MASK))
    {
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0303)-1 */
      /* Reporting to DEM that interrupt from unknown source */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_INT_INCONSISTENT,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
    }
    else
    #endif
    {

      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R4, WDG052] */
      /* Implements WDG_ESDD_UD_029 */
      /* Set the state of Watchdog as Busy */
      Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
      #endif

      /* Implements WDG_ESDD_UD_008 */
      /* Implements WDG_ESDD_UD_026 */
      /* QAC warning: START Msg(2:3416)-3 */
      /* Check if the trigger counter completed the requested timeout value  */
      if (Wdg_59_DriverA_GulTiggerCounter > WDG_59_DRIVERA_ZERO)
      {
        /* QAC warning: END Msg(2:3416)-3 */

        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        /* Implements WDG_ESDD_UD_013 */
        /* Check if critical section protection is required */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

        /* Decrement the trigger counter */
        Wdg_59_DriverA_GulTiggerCounter--;

        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        /* Implements WDG_ESDD_UD_013 */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

        /* Restart the WDG hardware */
        Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_API_ID);
      }
      else
      {
        /* No action required */
      }

      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R4, WDG052] */
      /* Implements WDG_ESDD_UD_029 */
      /* Set the state of Watchdog as Idle */
      Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
      #endif

    }
  }

}

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
