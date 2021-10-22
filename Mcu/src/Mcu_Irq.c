/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the MCU Driver Component                                  */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version
 *
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. MCU_ENTER_CRITICAL_SECTION and
 *                           MCU_EXIT_CRITICAL_SECTION are added
 *                        2. __asm("feret") is added in MCU_FEINT_ISR to avoid
 *                           improper exiting from the function
 *                        3. Mcu_GblRAMInitStatus is updating with values in
 *                           enum 'Mcu_RamStateType'
 *                        4. ISR APIs MCU_FEINT_ISR, MCU_ECM_EIC_ISR are
 *                           updated for addition of switch case for clearing
 *                           the ERROROUT pulse generated
 *
 * V1.0.2:  26-Sep-2014 : As per CR008 and mantis #19850, Following changes
 *                        are made,
 *                        1. MCU_FEINT_ISR API is updated for adding
 *                           MCU_FENMI_ENTRY, MCU_FENMI_LEAVE &
 *                           PRAGMA(NO_PROLOGUE) for proper returning from
 *                           FE level interrupts
 *                        2. Mcu_ProtectedWriteRetNone macro is invoked instead
 *                           of 'Mcu_ProtectedWrite' to avoid compilation
 *                           warnings
 *                        3. Trace marking is added throughout the file
 *                        4. Notification index calculation and delay timer
 *                           stop sections are updated in both ISR routine to
 *                           improve the throughput
 *
 * V1.0.5:  11-Feb-2014 : As per mantis #26305 ,following changes are made:
 *                        1. REG_DATA_PROTECTION is renamed to
 *                           MCU_REGISTER_PROTECTION.
 *                        2. Copyright information is updated.
 *
 * V1.0.6:  20-May-2015 : 1. Added code comments as per MO Review in Mantis
 *                           #27515
 *                        2. Added justification for MISRA warning Msg(4:3138)
 *                        3. Added compiler switch,
 *                           #ifndef Os_MCU_FEINT_CAT2_ISR and
 *                           #ifndef MCU_FEINT_CAT2_ISR for MCU_FENMI_ENTRY
 *                           and MCU_FENMI_LEAVE as per mantis #27723
 *                        4. Removed _INTERRUPT_ keyword from MCU_FEINT_ISR as
 *                           per Mantis #27723
 *                        5. Removed PRAGMA(NO_PROLOGUE) as per Mantis #27723
 *
 * V1.0.7:  12-Nov-2015 : As part of P1M 4.00.05 ASILD release, following
 *                        changes are made :
 *                        1. As per ARDAAAE-1464, redesigned ISRs.
 *                        2. As per ARDAAAE-1562 Variable GulEcmNmiDelayTimerReg
 *                           is changed to local.
 *                        3. Implemented general safety requirement interrupt
 *                           Consistency check.
 *                        4. Acceptance comments(QAC comments) are fixed.
 *                        5. As per ARDAAAE-1464, following APIs are
 *                            introduced. Mcu_IrqHandling, Mcu_IrqRamHandling,
 * V1.0.8:  29-Feb-2016 : Following changes are done as part of P1M 4.01.00
 *                        release
 *                        1. As per ticket ARDAAAE-1486, the local pointers
 *                           and variable are declared with memory class
 *                           AUTOMATIC
 *                        2. As per ticket ARDAAAE-1593, the code section is
 *                           updated for APIs.
 * V1.0.9:  21-Apr-2016 : Following changes are done as part of P1M 4.01.01
 *                        release
 *                        1. Removed some of the MISRA violations.
 *                        2. MISRA violations and QAC warnings are separated.
 *                        3. As per ticket ARDAAAE-1689 Mcu_IrqHandling and
 *                           Mcu_IrqRamHandling are merged.
 *                        4. As per REE MO review comment modified
 *                           MCU_ECM_EIC_ISR for interrupt consistency check.
 *                        5. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        6. As per ticket ARDAAAE-1995, updated Mcu_IrqHandling
 *                           for correcting the clearing of ECM status registers
 *                        7. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 * V1.0.10:  01-Feb-2017 : Following changes are done
 *                         1. As per ARDAAAE-2358, following changes are done:
 *                            a. Declaration of local variables are changed for
 *                               using macros.
 *                            b. Updated macros MCU_PROTECTEDWRITE and
 *                               MCU_PROTECTEDWRITERETNONE as per naming
 *                               convention.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0001 */
/* Implements EAAR_PN0034_NR_0002 */
/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Included for module version information definitions required for Mcu_Irq.c */
/* Implements MCU213 */
#include "Mcu.h"

/* Included for ISR functions declaration */
#include "Mcu_Irq.h"

/* Included for ram variable declaration */
#include "Mcu_Ram.h"

/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"

/* Included for Register access */
#include "Mcu_Reg.h"

#include "Mcu_RegWrite.h"

/* Implements MCU_ESDD_UD_058 */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_IRQ_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_IRQ_AR_RELEASE_MAJOR_VERSION != MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Major Version"
#endif /* (MCU_IRQ_AR_RELEASE_MAJOR_VERSION !=  \
        *                                MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
        */

#if (MCU_IRQ_AR_RELEASE_MINOR_VERSION != MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Minor Version"
#endif  /* (MCU_IRQ_AR_RELEASE_MINOR_VERSION != \
         *                               MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
         */

#if (MCU_IRQ_AR_RELEASE_REVISION_VERSION != \
                                        MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Revision Version"
#endif  /* (MCU_IRQ_AR_RELEASE_REVISION_VERSION !=  \
         *                            MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
         */

#if (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Major Version"
#endif  /* (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION) */

#if (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Minor Version"
#endif  /* (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION) */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*Implement EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
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

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316) An integer constant expression with negative      */
/*                 value is being converted to an unsigned type               */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/*                 REFERENCE - ISO-6.2.1.2                                    */
/* Justification : Typecasting is not done because it is a common macro       */
/*                 function used for hardware registers of all sizes          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-2 and                           */
/*                 END Msg(4:0316)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) The integer value 1 is being added or subtracted  */
/*                 from a pointer.                                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-3 and                           */
/*                 END Msg(4:0489)-3 tags in the code.                        */

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                  to another type                                           */
/* Rule          : MISRA-C:2004 Message 3892                                  */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                  the post build configuration                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-1 and                           */
/*                 END Msg(2:3892)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : MISRA-C:2004 Message 2814                                  */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-2 and                           */
/*                 END Msg(2:2814)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : MISRA-C:2004 Message 0862                                  */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0021*/
/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

STATIC FUNC(void, MCU_FAST_CODE) Mcu_IrqHandling (const uint8 IrqType);

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
** Function Name         : MCU_FEINT_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM NMI
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
** Global Variables Used : None
**
** Functions Invoked     : MCU_ENTER_CRITICAL_SECTION, Mcu_IrqHandling
**                         MCU_EXIT_CRITICAL_SECTION, MCU_FENMI_ENTRY
**                         MCU_FENMI_LEAVE
**
** Registers Used        : None
*******************************************************************************/

/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined  (Os_MCU_FEINT_CAT2_ISR) || defined (MCU_FEINT_CAT2_ISR)
 ISR(MCU_FEINT_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements MCU_ESDD_UD_028 */
FUNC(void, MCU_FAST_CODE) MCU_FEINT_ISR(void)
#endif
{

  #ifndef Os_MCU_FEINT_CAT2_ISR
  #ifndef MCU_FEINT_CAT2_ISR
  MCU_FENMI_ENTRY();
  #endif /* MCU_FEINT_CAT2_ISR is not defined */
  #endif /* Os_MCU_FEINT_CAT2_ISR is not defined */

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */


  Mcu_IrqHandling(MCU_ZERO);

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #ifndef Os_MCU_FEINT_CAT2_ISR
  #ifndef MCU_FEINT_CAT2_ISR
  MCU_FENMI_LEAVE();
  #endif /* MCU_FEINT_CAT2_ISR is not defined */
  #endif /* Os_MCU_FEINT_CAT2_ISR is not defined */
}

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
** Function Name         : MCU_ECM_EIC_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM MI
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
** Global Variables Used : None
**
** Functions Invoked     : MCU_ENTER_CRITICAL_SECTION, Mcu_IrqHandling
**                         MCU_EXIT_CRITICAL_SECTION, Dem_ReportErrorStatus
**
** Registers Used        : EIC8
*******************************************************************************/

/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined  (Os_MCU_ECM_EIC_CAT2_ISR) || defined (MCU_ECM_EIC_CAT2_ISR)
ISR(MCU_ECM_EIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
/* Implements MCU_ESDD_UD_029 */
_INTERRUPT_ FUNC(void, MCU_FAST_CODE) MCU_ECM_EIC_ISR(void)
#endif
{

  /* Implements MCU_ESDD_UD_089 */
  /* Implements EAAR_PN0034_FSR_0008, EAAR_PN0034_FSR_0009,
                EAAR_PN0034_FSR_0010
  */
  #if(MCU_INTERRUPT_CONSISTENCY_CHK == STD_ON)
  /* START Msg(2:3892)-1 */
  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Check whether the EIMK bit of EIC8 is set */
  if(MCU_EIC_EIMK_MASK == (MCU_INTC1EIC8 & MCU_EIC_EIMK_MASK))
  {
    /* END Msg(2:3892)-1 */
    /* END Msg(4:0303)-1 */
    /* Implements MCU_ESDD_UD_112 */
    /* Reporting to DEM that interrupt from unknown source */
    Dem_ReportErrorStatus(MCU_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  /* START Msg(2:3892)-1 */
  /* START Msg(2:2814)-2 */
  /* MISRA Violation: START Msg(4:0303)-1 */
  else if((MCU_ZERO != (MCU_ECMMESSTR0 &
    ~(Mcu_GpEcmSetting->ulEcmMaskInterReg0value))) || (MCU_ZERO !=
     ((MCU_ECMMESSTR1 & ~(Mcu_GpEcmSetting->ulEcmMaskInterReg1value)) &
                                                        MCU_ESSTR1_INTR_MASK)))
  {
    /* END Msg(2:3892)-1 */
    /* END Msg(2:2814)-2 */
    /* END Msg(4:0303)-1 */
    /* Implements MCU_ESDD_UD_112 */
    /* Reporting to DEM that interrupt from unknown source */
    Dem_ReportErrorStatus(MCU_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    /* Implements MCU_ESDD_UD_058 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    Mcu_IrqHandling(MCU_ONE);

    /* Implements MCU_ESDD_UD_058 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
}

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Mcu_IrqHandling
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM MI & NMI
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
** Global Variables Used : Mcu_GpConfigPtr, Mcu_GpEcmSetting,
**
** Functions Invoked     : MCU_PROTECTEDWRITERETNONE,
**                         Mcu_IrqRamHandling
**
** Registers Used        : ECMMESSTR0, ECMESSTC0, ECMMESSTR1, ECMDTMCTL,
**                         ECMESSTC1, ECMPCMD1, ECMPS
*******************************************************************************/
/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

/* Implements MCU_ESDD_UD_040 */
/* Implements EAAR_PN0079_FSR_0041, EAAR_PN0079_FSR_0037, EAAR_PN0079_FSR_0038*/
/* Implements EAAR_PN0034_FSR_0004 */
STATIC FUNC(void, MCU_FAST_CODE) Mcu_IrqHandling (const uint8 IrqType)
{
  /* Implements MCU_ESDD_UD_107 */
  /* Pointer to Ecm notify map configuration */
  P2CONST (Mcu_EcmNotifMap, AUTOMATIC, MCU_CONFIG_CONST)
                                                    LpEcmNotifMap;
  VAR(uint32, AUTOMATIC) LulEcmDelayTimerReg[MCU_TWO];
  VAR(uint32, AUTOMATIC) LulEcmStatusData[MCU_TWO];
  VAR(uint32, AUTOMATIC) LulEcmErrSourceMask;
  VAR(uint8, AUTOMATIC) LucLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucTotalErrSrcCnt;
  VAR(uint8, AUTOMATIC) LucRegIndex;

  /* MCU_ZERO for NMI Irq and MCU_One for MI Irq and*/
  if (MCU_ZERO == IrqType)
  {
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* MISRA Violation: START Msg(4:0316)-2 */
    /* START Msg(2:3892)-1 */
    /* START Msg(2:2814)-2 */
    /* Get the total number of error sources configured */
    LucTotalErrSrcCnt = Mcu_GpConfigPtr->ucNmiErrSrcCnt;
    /* Store the error value to be checked in the ISR */
    LulEcmStatusData[MCU_ZERO] =
          (MCU_ECMMESSTR0 & (Mcu_GpEcmSetting->ulEcmNonMaskInterReg0value));
    /* END Msg(2:2814)-2 */
    LulEcmStatusData[MCU_ONE] =
          (MCU_ECMMESSTR1 & (Mcu_GpEcmSetting->ulEcmNonMaskInterReg1value));
    LulEcmDelayTimerReg[MCU_ZERO] = Mcu_GpEcmSetting->ulEcmDelayTimerReg2Value;
    LulEcmDelayTimerReg[MCU_ONE] =  Mcu_GpEcmSetting->ulEcmDelayTimerReg3Value;
    LpEcmNotifMap = (P2CONST(Mcu_EcmNotifMap, AUTOMATIC, MCU_CONFIG_CONST))
                                      (Mcu_GpConfigPtr->pEcmNmiNotifMap);
    /* END Msg(2:3892)-1 */
    /* END Msg(4:0303)-1 */
    /* END Msg(4:0316)-2 */

  }
  else
  {
    /* MISRA Violation: START Msg(4:0316)-2 */
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* START Msg(2:3892)-1 */
    /* Get the total number of error sources configured */
    LucTotalErrSrcCnt = Mcu_GpConfigPtr->ucMiErrSrcCnt;
        /* Store the error value to be checked in the ISR */
    LulEcmStatusData[MCU_ZERO] =
           (MCU_ECMMESSTR0 & (Mcu_GpEcmSetting->ulEcmMaskInterReg0value));
    LulEcmStatusData[MCU_ONE] =
           (MCU_ECMMESSTR1 & (Mcu_GpEcmSetting->ulEcmMaskInterReg1value));
    LulEcmDelayTimerReg[MCU_ZERO] = Mcu_GpEcmSetting->ulEcmDelayTimerReg0Value;
    LulEcmDelayTimerReg[MCU_ONE] = Mcu_GpEcmSetting->ulEcmDelayTimerReg1Value;
    LpEcmNotifMap = (P2CONST(Mcu_EcmNotifMap, AUTOMATIC, MCU_CONFIG_CONST))
                                      (Mcu_GpConfigPtr->pEcmMiNotifMap);
    /* END Msg(2:3892)-1 */
    /* END Msg(4:0303)-1 */
    /* END Msg(4:0316)-2 */
  }
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* START Msg(2:3892)-1 */
  /* Clear the status register */
  MCU_PROTECTEDWRITERETNONE(MCU_ECMESSTC0, LulEcmStatusData[MCU_ZERO],
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
  /* END Msg(2:3892)-1 */
  /* END Msg(4:0303)-1 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR0, MCU_LONG_WORD_ZERO,
  MCU_FULL_MASK, MCU_ISR_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */
   /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* START Msg(2:3892)-1 */
  /* Clear the status register */
  MCU_PROTECTEDWRITERETNONE(MCU_ECMESSTC1, LulEcmStatusData[MCU_ONE],
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
  /* END Msg(2:3892)-1 */
  /* END Msg(4:0303)-1 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR1, MCU_ERROROUT_STATUS,
  MCU_FULL_MASK, MCU_ISR_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */

  /* Check if any error sources are configured */
  if(LpEcmNotifMap != NULL_PTR)
  {
    for (LucLoopCount = MCU_ZERO; LucLoopCount < LucTotalErrSrcCnt;
                                                         LucLoopCount++)
    {
      /* Get error source register index */
      LucRegIndex = LpEcmNotifMap->ucErrSrcRegIdx;
      /* Get the mask value for corresponding error source */
      LulEcmErrSourceMask = LpEcmNotifMap->ulErrorSrcMask;
      /*  Check if error source caused interrupt */
      if ((LulEcmStatusData[LucRegIndex] & LulEcmErrSourceMask) ==
                                                    LulEcmErrSourceMask)
      {
        /* Check the delay timer start is configured for this source and
         * running, if yes stop timer to avoid restart and error output mask.
         */
        /* Implements MCU_ESDD_UD_071 */
        if ((LulEcmDelayTimerReg[LucRegIndex] & LulEcmErrSourceMask) ==
                                                         LulEcmErrSourceMask)
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Stop the delay timer */
          MCU_PROTECTEDWRITERETNONE(MCU_ECMDTMCTL, MCU_TWO, MCU_ECMPCMD1,
                                 MCU_ECMPS, LucRetryCount)
          /* END Msg(4:0303)-1 */
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Reconfigure delay control register to start timer
           * on next interrupt
           */
          MCU_PROTECTEDWRITERETNONE(MCU_ECMDTMCTL, MCU_ONE, MCU_ECMPCMD1,
                                 MCU_ECMPS, LucRetryCount)
          /* END Msg(4:0303)-1 */
        }
        else
        {
          /* No action required */
        }

        /* Check whether notification function  configured or not */
        if ((LpEcmNotifMap->pNotiFuncPtr) != NULL_PTR)
        {
          /* Invoke the configured notification function */
          LpEcmNotifMap->pNotiFuncPtr();
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
      /* MISRA Violation: START Msg(4:0489)-3 */
      /* Increment the pointer to next Error Source Status Register structure */
      LpEcmNotifMap++;
      /* END Msg(4:0489)-3 */
    }
  }
  else
  {
    /* No action required */
  }
  /*Implements EAAR_PN0079_FR_0007 */
  #if (MCU_GET_RAM_STATE_API == STD_ON)
  /* Check local and global ram error */
  /* START Msg(2:3892)-1 */
  if ((MCU_ZERO != (LulEcmStatusData[MCU_ZERO] & MCU_RAM_MASK0_VALUE)) ||
      (MCU_ZERO != (LulEcmStatusData[MCU_ONE] & MCU_RAM_MASK1_VALUE)))
  /* END Msg(2:3892)-1 */
  {
    /* Set the ram state variable  */
    Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_INVALID;
  }
  else
  {
    /* No action required */
  }
  #endif /* (MCU_GET_RAM_STATE_API == STD_ON) */
}

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
