/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the ISR implementations for FLS module.                 */
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
 * V1.0.0:  15-Feb-2016  : Initial Version.
 * V1.0.1:  18-Mar-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made :
 *                         1. As part of ARDAAAE-1631, updated Fls_Irq.c to
 *                            invoke Fls_ProcessSuspend function from
 *                            FLS_FLENDNM_ISR function and included
 *                            rh850_Types.h.
 *                         2. Updated Function banner of FLS_FLENDNM_ISR.
 *                         3. QAC Warning START and END msgs for Msg(2:2814)
 *                            ,Msg(2:2016),Msg(2:3892) are added at the
 *                            respective places.
 * V1.0.2:  05-May-2016    : As part of P1x V4.01.01 release, following changes
 *                           are made :
 *                           1. Critical section protection is added for IMR
 *                              register in FLS_FLENDNM_ISR function.
 *                           2. Included header file SchM_Fls.h.
 *                           3. As per Jira ARDAAAE-1910, the pointer analysis
 *                              tags are added.
 *                           4. Modified the code to skip execution of ISR if
 *                              the consistency check fails.
 *                           5. As per ARDAAAE-1908, removed dead code.
 *                           6. Added QAC Warning START and END tag.
 *                           7. File "Fls_RegWrite.h" is included.
 *                           8. Updated register write verify implementation.
 *                           9. As per JIRA ID ARDAAAAE-2010, removed register
 *                              write verify for IMR register.
 *                           10.Placed the constant value on the left side of
 *                              the comparison operator.
 *                           11.QAC warning START and END msgs for Msg(4:0857)
 *                              are removed as this warning is fixed.
 * V1.0.3:  31-Aug-2016    : Following change is made:
 *                           1. As per JIRA ID ARDAAAE-2026, corrected naming
 *                              convention of variables as per requirement
 *                              EAAR_PN0084_NR_0066.
 *                           2. As per JIRA ID ARDAAAE-2013, updated
 *                              "registers used" in function banner of
 *                              FLS_FLENDNM_ISR.
 * V1.0.4:  25-Jan-2017    : Following changes are made:
 *                           1. As part of JIRA ID ARDAAAE-2053,elements of
 *                              structure "Fls_GstVarProperties" are renamed.
 *                           2. Copyright information is updated.
 *                           3. As part of JIRA ID ARDAAAE-2274
 *                             justification for Misra warning 4:0857 is added.
 * V1.0.5:  27-Apr-2017    : Following change is made:
 *                           Relocated end message tag 'END Msg(4:0857)-3' as
 *                           part of fixing static analysis warning.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0001 */
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Internal.h"
/* Included for module version information and other types declarations */
#include "Fls.h"
#include "Fls_Irq.h"
#include "rh850_Types.h"
/* Included for Prototype Declarations for FLS callback notification functions*/
#include "Fls_Cbk.h"
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Fls.h"
#endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
/* MISRA Violation: START Msg(4:0857)-3 */
#define FLS_IRQ_C_AR_RELEASE_MAJOR_VERSION FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_IRQ_C_AR_RELEASE_MINOR_VERSION FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                        FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* END Msg(4:0857)-3 */
/* File version information */
#define FLS_IRQ_C_SW_MAJOR_VERSION    FLS_SW_MAJOR_VERSION_VALUE
#define FLS_IRQ_C_SW_MINOR_VERSION    FLS_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements FLS364 */
#if (FLS_IRQ_AR_RELEASE_MAJOR_VERSION != FLS_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Major Version"
#endif

#if (FLS_IRQ_AR_RELEASE_MINOR_VERSION != FLS_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Minor Version"
#endif

#if (FLS_IRQ_AR_RELEASE_REVISION_VERSION != \
                                          FLS_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Revision Version"
#endif

#if (FLS_IRQ_SW_MAJOR_VERSION != FLS_IRQ_C_SW_MAJOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Software Major Version"
#endif

#if (FLS_IRQ_SW_MINOR_VERSION != FLS_IRQ_C_SW_MINOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) [I] Cast between a pointer to volatile object     */
/*                 and an integral type.                                      */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : This macro is used to write or read values from hardware   */
/*                 addresses.                                                 */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : The expression has no reliance on the effects of integral  */
/*                 promotion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-2 and                           */
/*                 END Msg(4:4397)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-3 and                           */
/*                 END Msg(4:0857)-3 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-1 and                           */
/*                 END Msg(2:2814)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Justification : This is used for write verification of a particular        */
/*                 register so even if it is unsigned or signed type it has no*/
/*                 impact.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(2:3892)-2 and                           */
/*                 END Msg(2:3892)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-3 and                           */
/*                 END Msg(2:2016)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:0862) #include "MemMap.h" directive is redundant.       */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*                                                                            */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:0553) Translation unit contains no object or function   */
/*                 definitions with external linkage.                         */
/* Justification : Interrupt is disabled for particular configuration, Hence  */
/*                 no object or function definitions are available.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : FLS_FLENDNM_ISR
**
** Service ID            : NA
**
** Description           : Interrupt Service Routine for flash sequencer end
**                         interrupt.
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : NA
**
** Global Variable       : Fls_GblJobSuspendRequest(R)
**
** Function invoked      : Fls_MainErase,Fls_MainWrite,Fls_MainBlankCheck,
**                         Dem_ReportErrorStatus,Fls_ProcessSuspend
**
** Registers Used        : ICFLENDNM,IMRn
*******************************************************************************/

/* Implements FLS_ESDD_UD_100 */
#if (FLS_INTERRUPT_MODE == STD_ON)
#define FLS_START_SEC_CODE_FAST
#include "MemMap.h"

/* Implements FLS_ESDD_UD_075 */
/* Implements AR_PN0072_FR_0047,AR_PN0072_FR_0050 */
/* Implements EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0060 */
/* Implements EAAR_PN0034_FR_0066,EAAR_PN0034_FSR_0008,EAAR_PN0034_FSR_0010 */
/* Implements EAAR_PN0034_FSR_0009,EAAR_PN0034_FR_0024 */
/* Implements FLS193,FLS292_Conf,FLS352,FLS260,FLS006,FLS233 */
/* Defines the CAT2 interrupt mapping */
#if defined (Os_FLS_FLENDNM_CAT2_ISR) || defined (FLS_FLENDNM_CAT2_ISR)
ISR(FLS_FLENDNM_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, FLS_FAST_CODE) FLS_FLENDNM_ISR(void)
#endif
{
  /* Implements FLS_ESDD_UD_104 */
  #if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
   /* MISRA Violation: START Msg(4:0303)-1 */
   /* QAC Warning: START Msg(2:3892)-2 */
  if (FLS_EIC_EIMK_MASK == (FLS_ICFLENDNM & FLS_EIC_EIMK_MASK))
  {
    /* END Msg(2:3892)-2 */
    /* END Msg(4:0303)-1 */
    /* Implements FLS_ESDD_UD_134 */
    /* Reporting to DEM that interrupt from unknown source */
    Dem_ReportErrorStatus(FLS_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    #if (FLS_SUSPEND_API == STD_ON)
    /* QAC Warning: START Msg(2:3416)-9 */
    if (FLS_TRUE == Fls_GblJobSuspendRequest)
    {
      /* END Msg(2:3416)-9 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:4397)-2 */
      /* QAC Warning: START Msg(2:2814)-1 */
      /* Disable interrupt processing */
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                             ~(Fls_GpConfigPtr->usFlEndImrMask));
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* END Msg(2:2814)-1 */
      /* END Msg(4:4397)-2 */
      Fls_ProcessSuspend();
    }
    else
    {
      /*No action Required */
    }
    #endif
    switch (Fls_GstVar.enGenCommand)
    {
         /* In case of Erase Operation */
    case FLS_COMMAND_ERASE:
         Fls_MainErase();
    break;
    case FLS_COMMAND_WRITE:
         Fls_MainWrite();
    break;
    case FLS_COMMAND_BLANKCHECK:
         Fls_MainBlankCheck();
    break;
    case FLS_COMMAND_READ:
    case FLS_COMMAND_COMPARE:
    case FLS_COMMAND_READ_IMM:
    /* QAC Warning: START Msg(2:2016)-3 */
    default:
           /* No action required */
    break;
    }
    /* END Msg(2:2016)-3 */
  }
}
/* MISRA Violation: START Msg(4:0857)-3 */
#define FLS_STOP_SEC_CODE_FAST
/* END Msg(4:0857)-3 */
#include "MemMap.h"
#endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
