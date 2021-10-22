/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Private_Fcu.c                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains FCU related API implementations                         */
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
 * V1.0.0:  15-Feb-2016    : Initial Version
 * V1.0.1:  20-Mar-2016    : As part of P1x V4.01.00 release, following changes
 *                           are made :
 *                           1. As part of ARDAAAE-1631, updated
 *                              Fls_FcuCheckJobStatus function to invoke
 *                              Fls_ProcessSuspend function for erase and write
 *                              operations in polling mode.
 *                           2. Included Fls_Internal.h file.
 *                           3. As part of ARDAAAE-1531, updated Fls_FcuDataCopy
 *                              function to do write verification for DFERSTC
 *                              register.
 *                           4. As part of ARDAAAE-1687, updated
 *                              Fls_FcuCopytoRam and Fls_FcuGetFWParam functions
 *                              to invoke EXECUTE_SYNCP() before deactivating
 *                              BFlash.
 *                           5. Removed the global pointers usage
 *                              Fls_GpFACIRegPtr and Fls_GpECCRegPtr and instead
 *                              used local pointers in functions wherever
 *                              applicable.
 *                           6. Updated comment for #endif in all functions.
 *                           7. Access information read, write and read-write
 *                              (R, W, RW) are provided for Global Variables
 *                              in function banner.
 *                           8. Declaration and initialisation of local
 *                              variable LenReturnValue has been done in
 *                              separate lines in Fls_FcuResetErrorBits
 *                              function.
 *                           9. QAC Warning START and END msgs for
 *                              Msg(2:2814),Msg(2:2016),Msg(2:3892),Msg(2:3416),
 *                              Msg(2:3204),Msg(2:0862), Msg(3:3203) are
 *                              added at the respective places.
 *                           10.As per Jira ARDAAAE-1910, the pointer analysis
 *                              tags are added.
 * V1.0.2:  21-Jun-2016    : As part of P1x V4.01.01 release, following changes
 *                           are made :
 *                           1. As per JIRA ID ARDAAAE-1908, removed dead code.
 *                           2. As per JIRA ID ARDAAAE-1926,
 *                              a) Replaced assignment of local
 *                              variable 'LenStatus' with FLS_FCU_ERR_TIMEOUT
 *                              macro if time-out occurs in Fls_FcuSwitchMode
 *                              and Fls_FcuForcedStop functions.
 *                              b) Removed setting of local variable 'LenStatus'
 *                              with macro FLS_FCU_ERR_INTERNAL from
 *                              Fls_FcuPerformBlankCheck function.
 *                           3. File "Fls_RegWrite.h" is included.
 *                           4. As per JIRA ID ARDAAAE-1989, Fls_FcuInit() is
 *                              relocated to this file.
 *                           5. Updated register write verify implementation.
 *                           6. Placed the constant value on the left side of
 *                              the comparison operator.
 *                           7. QAC Warning START and END msgs for
 *                              Msg(4:1853) and Msg(4:1851) are
 *                              added at the respective places.
 * V1.0.3:  24-Oct-2016    : Following changes are made:
 *                           1. As per JIRA ID ARDAAAE-1978, added critical
 *                              section protection for the firmware storage area
 *                              switching in Fls_FcuGetFWParam and
 *                              Fls_FcuCopytoRam functions.
 *                           2. As per JIRA ID ARDAAAE-2001, Typecasting for
 *                              "Fls_FcuDfSize" is removed from function
 *                              "Fls_FcuPrepareEnvironment".
 *                           3. Corrected type-casting of second argument
 *                              in Fls_FcuPerformBlankCheck function.
 *                           4. As per JIRA ID ARDAAAE-2026, corrected naming
 *                              convention of variables as per requirement
 *                              EAAR_PN0084_NR_0066.
 *                           5. As per JIRA ID ARDAAAE-2042, SYNCP instruction
 *                              is added before SYNCI in Fls_FcuClearCache().
 *                           6. As per JIRA ID ARDAAAE-2111, register write
 *                              verify is done for FENTRYR register.
 * V1.0.4:  06-Feb-2017    : Following changes are made:
 *                           1. As per JIRA ID ARDAAAE-2232, Fls_FcuSwitchMode
 *                              API is updated for Write-Verify implementation
 *                              of FENTRYR register.
 *                           2. Copyright information is updated.
 *                           3. As per JIRA ID ARDAAAE-1963, Fls_FcuSwitchMode
 *                              is improved to handle mode switch to USER and
 *                              mode switch to P/E separately and
 *                              Fls_FcuCheckSequencerStatus is added to check
 *                              FENTRYR register to identify command lock state.
 *                           4. As per JIRA ID ARDAAAE-2339, Fls_FcuForcedStop
 *                              API is updated to check for CMDLK bit.
 *                           5. As per JIRA ID ARDAAAE-2112, Fls_FcuCopytoRam
 *                              Fls_FcuSwitchBFlash,Fls_FcuClearCache and
 *                              Fls_FcuGetFWParam APIs are moved to new memory
 *                              section FLS_START_SEC_PRIVATERAM_CODE.
 *                           6. As part of JIRA ID ARDAAAE-2053,elements of
 *                              structure "Fls_GstVarProperties" are renamed.
 *                           7. As part of JIRA ID ARDAAAE-2120,message tags for
 *                              Msg(4:0303) added in Fls_FcuSwitchBFlash API and
 *                              Msg(4:1290) in Fls_FcuSwitchMode API.
 *                              Justification for Msg(4:0857) added and message
 *                              tags added for Fls_FcuPrepareEnvironment and
 *                              Fls_FcuForcedStop APIs.
 *                           8. As part of JIRA ID ARDAAAE-2274
 *                              removed unnecessary mapping of requirement
 *                              AR_PN0072_FR_0017.
 *                           9. As part of JIRA ID ARDAAAE-2343,ARDAAAE-2344
 *                              Fls_FcuClearStatus API is updated to remove
 *                              error bit checking.
 *                           10.As part of JIRA ID ARDAAAE-1963
 *                              added unit design ID in the API
 *                              Fls_FcuCheckSequencerStatus.
 *                           11.As part of JIRA ID ARDAAAE-2340,
 *                              Fls_FcuForcedStop API is updated to check for
 *                              FRDY bit using FLS_FCU_FRDY_POOL_COUNT value.
 *                           12.As part of JIRA ID ARDAAAE-2274,
 *                              UT ID Tag FLS_UT_002 added for the uncovered
 *                              parts of the code during Unit Testing.
 * V1.0.5:  03-May-2017    : Following changes are made:
 *                           1. As part of JIRA ID ARDAAAE-2437,
 *                              a) In Fls_FcuGetFWParam and Fls_FcuCopytoRam
 *                                 functions,report to DEM based on hardware
 *                                 failure has been added.
 *                              b) In Fls_FcuClearCache function, a global
 *                                 variable Fls_GblDemStatusFlag to indicate
 *                                 potential HW failure has been added.
 *                              c) Removed register write-verify from
 *                                 Fls_FcuSwitchBFlash.
 *                              d) In Fls_FcuSwitchBFlash the register FCUFAREA
 *                                 is verified, and error is reported via
 *                                 call-back function
 *                                 Fls_CallSwitchBFlashErrorNotification.
 *                              e) UT ID Tag FLS_UT_003 added for the uncovered
 *                                 parts of the code during Unit Testing.
 */
/******************************************************************************/

/*******************************************************************************
**                         Include Section                                    **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0001 */
#include "Fls_Private_Fcu.h"
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Internal.h"
/* Included for RAM variable declarations */
#include "Fls_Ram.h"
/* Included for Prototype Declarations for FLS callback notification functions*/
#include "Fls_Cbk.h"
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
#if (FLS_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
/*******************************************************************************
**                         Version Information                                **
*******************************************************************************/
/* AUTOSAR release version information */
#define FLS_PRIVATE_FCU_C_AR_RELEASE_MAJOR_VERSION  \
                                              FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_PRIVATE_FCU_C_AR_RELEASE_MINOR_VERSION     \
                                              FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_PRIVATE_FCU_C_AR_RELEASE_REVISION_VERSION  \
                                           FLS_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLS_PRIVATE_FCU_C_SW_MAJOR_VERSION      FLS_SW_MAJOR_VERSION_VALUE
#define FLS_PRIVATE_FCU_C_SW_MINOR_VERSION      FLS_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                           Version Check                                    **
*******************************************************************************/
/* Implements FLS364 */
#if (FLS_PRIVATE_FCU_AR_RELEASE_MAJOR_VERSION != \
                                     FLS_PRIVATE_FCU_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls_Private_Fcu.c : Mismatch in Release Major Version"
#endif

#if (FLS_PRIVATE_FCU_AR_RELEASE_MINOR_VERSION != \
                                     FLS_PRIVATE_FCU_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls_Private_Fcu.c : Mismatch in Release Minor Version"
#endif

#if (FLS_PRIVATE_FCU_AR_RELEASE_REVISION_VERSION != \
                                  FLS_PRIVATE_FCU_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls_Private_Fcu.c : Mismatch in Release Revision Version"
#endif

#if (FLS_PRIVATE_FCU_SW_MAJOR_VERSION != FLS_PRIVATE_FCU_C_SW_MAJOR_VERSION)
  #error "Fls_Private_Fcu.c : Mismatch in Software Major Version"
#endif

#if (FLS_PRIVATE_FCU_SW_MINOR_VERSION != FLS_PRIVATE_FCU_C_SW_MINOR_VERSION)
  #error "Fls_Private_Fcu.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
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
/* Message       : (4:1851) The left-hand operand is 'essentially unsigned'   */
/*                 (unsigned short) but will be implicitly converted to a     */
/*                 signed type (signed int) in this bitwise operation         */
/* Rule          : MISRA-C:2004 Message 1851                                  */
/* Justification : The calculated value of type (unsigned char) is used in    */
/*                 32 bit register which needs to be cast to unsigned long.   */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any safety impact.                           */
/* Reference     : Look for START Msg(4:1851)-2 and                           */
/*                 END Msg(4:1851)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1853) The left-hand operand is 'essentially unsigned'   */
/*                 (unsigned short) but will be implicitly converted to a     */
/*                 signed type (signed int) in this bitwise operation         */
/* Rule          : MISRA-C:2004 Message 1853                                  */
/* Justification : The calculated value of type (unsigned char) is used in    */
/*                 32 bit register which needs to be cast to unsigned long.   */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any safety impact.                           */
/* Reference     : Look for START Msg(4:1853)-3 and                           */
/*                 END Msg(4:1853)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1290) An integer constant of 'essentially signed' type  */
/*                 is being converted to unsigned type on assignment.         */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : This is used for write verification of a particular        */
/*                 register so even if it is unsigned or signed type it has no*/
/*                 impact.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(4:1290)-4 and                           */
/*                 END Msg(4:1290)-4 tags in the code.                        */
/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-5 and                           */
/*                 END Msg(4:0857)-5 tags in the code.                        */
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
/* Message       : (2:0862) #include "MemMap.h" directive is redundant.       */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-3 and                           */
/*                 END Msg(2:3416)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-4 and                           */
/*                 END Msg(2:2016)-4 tags in the code.                        */
/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:3204) The variable 'LulEndAddr' is only set once and so */
/*                 it could be declared with the 'const' qualifier.           */
/* Justification : LulEndAddr is set within the macro FLS_REG_WRITE as well.  */
/*                 However this local variable cannot be declared with 'const'*/
/*                 qualifier since it is subjected to change for every cycle  */
/*                 of blank check operation.                                  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3204)-5 and                           */
/*                 END Msg(2:3204)-5 tags in the code.                        */
/******************************************************************************/
/* 6. QAC Warning:                                                            */
/* Message       : (3:3203) The variable 'LucModeVal' is set but never used.  */
/* Justification : LucModeVal is used for dummy read of FCUFAREA register.    */
/*                 While switching the BFLASH area, this delay or dummy read  */
/*                 is at most required. Hence canot be avoided. However part  */
/*                 of this code has no impact on functionality.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3203)-6 and                           */
/*                 END Msg(3:3203)-6 tags in the code.                        */
/******************************************************************************/
/* 7. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type                                            */
/* Rule          : MISRA-C:2004 Message 3892                                  */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                 the post build configuration                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-7 and                           */
/*                 END Msg(2:3892)-7 tags in the code.                        */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name             : Fls_FcuSwitchMode
**
** Service ID                : NA
**
** Description               : This function Switch FCU mode to Programming/User
**                             mode and checks if the Flash sequencer operation
**                             mode switch is performed correctly
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : LddMode
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : Fls_FcuGstVar.usFcuFlashMode(W)
**
** Function(s) invoked       : Fls_FcuCheckSequencerStatus, Fls_FcuForcedStop
**
** Registers Used            : FENTRYR,FSADDR,FEADDR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements FLS_ESDD_UD_051 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0013,EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0011,EAAR_PN0034_FSR_0012 */
/* Implements EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSwitchMode
(VAR(const uint16, FLS_APPL_DATA) LddMode)
{
  Fls_FcuStatusType LenStatus;
  uint8 LucLoopCount;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  LenStatus = FLS_FCU_ERR_INTERNAL;

  /* Check if the mode is already set. If yes, setting it again would
     toggle the mode.So, don't set it again */
  /* QAC Warning: START Msg(2:2814)-1 */
  if (LddMode != LpFACIRegPtr->usFENTRYR)
  {
    /* END Msg(2:2814)-1 */
    if (FLS_FCU_MODE_PE == LddMode)
    {
      /* Clear FSADDRR and FEADDRR when entering P/E mode */
      FLS_REG_WRITE(LpFACIRegPtr->ulFSADDR,FLS_FCU_ADDR_REG_RESET)
      /* MISRA Violation: START Msg(4:1290)-4 */
      /* For write verification */
      FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->ulFSADDR, FLS_FCU_ADDR_REG_RESET,
                                 FLS_32BIT_MASK_VAL, FLS_FCUSWITCHMODE_API_ID)
      /* END Msg(4:1290)-4 */
      FLS_REG_WRITE(LpFACIRegPtr->ulFEADDR,FLS_FCU_ADDR_REG_RESET)
      /* MISRA Violation: START Msg(4:1290)-4 */
      /* For write verification */
      FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->ulFEADDR, FLS_FCU_ADDR_REG_RESET,
                                  FEADDR_REG_MASK_VAL, FLS_FCUSWITCHMODE_API_ID)
      /* END Msg(4:1290)-4 */
    }
    else /* Switch User mode */
    {
      /* check FRDY bit and cmd lock status */
      LenStatus = Fls_FcuCheckSequencerStatus();
      if (FLS_FCU_OK != LenStatus)
      {
        /* In case cmd lock, issue a forced stop */
        /* :- If any error occurs here, it will be returned */
        /* :- retVal must not be overwritten with FLS_FCU_OK */
        /* :- any other error report is ok */
        LenStatus = Fls_FcuForcedStop();
      }
      else
      {
        /* No action required */
      }
    }
    /* Set FENTRYR to switch FCU mode to User or P/E mode */
    FLS_REG_WRITE(LpFACIRegPtr->usFENTRYR,(LddMode +
                                                   FLS_FCU_REGBIT_FENTRY_KEY))
    /* Implements FLS_ESDD_UD_113 */
    Fls_FcuGstVar.usFcuFlashMode = LddMode;

    /* Implements FLS_ESDD_UD_107 */
    LucLoopCount = FLS_LOOP_COUNT;

    /* Check if value of the FENTRYD bit is set as requested */
    /* We need a dummy read as the mode is not changed immediately on
       some devices */
    /* Start : FLS_UT_002*/
    do
    {
     LucLoopCount--;
    } while ((LddMode != LpFACIRegPtr->usFENTRYR) &&
                                                (FLS_FCU_ZERO < LucLoopCount));
    /* End : FLS_UT_002*/

    /* MISRA Violation: START Msg(4:1290)-4 */
    /* For write verification of  FENTRYR register */
    FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFENTRYR,
               LddMode, FENTRYR_REG_MASK_VAL, FLS_FCUSWITCHMODE_API_ID)
    /* END Msg(4:1290)-4 */

    /* Start : FLS_UT_002*/
    /* Check if mode switch is successful or time out occurs */
    if (Fls_FcuGstVar.usFcuFlashMode == LpFACIRegPtr->usFENTRYR)
    {
      /* Mode switch is successful */
      LenStatus = FLS_FCU_OK;
    }
    else if (FLS_FCU_ZERO == LucLoopCount)
    {
      /* Error occurs due to internal error */
      LenStatus = FLS_FCU_ERR_INTERNAL;
    }
    else
    {
      /* No action required */
    }
    /* End : FLS_UT_002*/
  }
  else
  {
    /* The intended mode is already set */
    LenStatus = FLS_FCU_OK;
  }

  return(LenStatus);
}/* End of function Fls_FcuSwitchMode */
/* MISRA Violation: START Msg(4:0857)-5 */
#define FLS_STOP_SEC_PRIVATE_CODE
/* END Msg(4:0857)-5 */
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_FcuPrepareEnvironment
**
** Service ID                : NA
**
** Description               : This function initialises the FCU RAM, sets the
**                             FACI frequency, resets FCU and initialise
**                             hardware registers to default values.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : Fls_FcuGstVar.ulFcuDfSize(RW)
**
** Function(s) invoked       : Fls_FcuSwitchMode,Fls_FcuForcedStop,
**                             Fls_FcuClearStatus,Fls_FcuVerifyChecksum,
**                             Fls_FcuSetFrequency,Fls_FcuInitRam
**
** Registers Used            : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_052 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuPrepareEnvironment(void)
{
  Fls_FcuStatusType LenStatus;

  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);

  if (FLS_FCU_OK == LenStatus)
  {
    /* Reset FCU again to clear any possible ECC errors */
    LenStatus = Fls_FcuForcedStop();
  }
  else
  {
    /* No action required */
  }
  #if (FLS_FWCOPY_SUPPORTED == STD_ON)
  if (FLS_FCU_OK == LenStatus)
  {
    /* Switching to USER Mode */
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_USER);
  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_OK == LenStatus)
  {
    /* Initialize the FCU code RAM */
    Fls_FcuInitRAM();
    /* Switching to P/E Mode */
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);
  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_OK == LenStatus)
  {
    /* Reset FCU again to clear any possible ECC errors */
    LenStatus = Fls_FcuForcedStop();
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (FLS_FWCOPY_SUPPORTED == STD_ON) */

  if (FLS_FCU_OK == LenStatus)
  {
    /* Issue Clear Status command */
    Fls_FcuClearStatus();
    /* Switching to USER Mode */
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_USER);
  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_FWCOPY_SUPPORTED == STD_ON)
    /* Verify the FCURAM checksum. */
    LenStatus = Fls_FcuVerifyChecksum();
    #else
    LenStatus = FLS_FCU_BUSY;
    #endif /* #if (FLS_FWCOPY_SUPPORTED == STD_ON) */
  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_BUSY == LenStatus)
  {
    /* Implements FLS_ESDD_UD_113 */
    Fls_FcuGstVar.ulFcuDfSize = Fls_FcuGetDFSize();

    if ((uint16)FLS_DF_POOL_SIZE <=
        ((uint16)(Fls_FcuGstVar.ulFcuDfSize >> FLS_FCU_BLOCK_SIZE_2N)))
    {
      /* Configure the FCU frequency */
      LenStatus = Fls_FcuSetFrequency();
    }
    else
    {
      LenStatus = FLS_FCU_ERR_CONFIGURATION;
    }
  }
  else
  {
    /* No action required */
  }

  return(LenStatus);
} /* End of function Fls_FcuPrepareEnvironment */
/* MISRA Violation: START Msg(4:0857)-5 */
#define FLS_STOP_SEC_PRIVATE_CODE
/* END Msg(4:0857)-5 */
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_FcuForcedStop
**
** Service ID                : NA
**
** Description               : This function issues Forced Stop command and
**                             resets FCU and FACI registers.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : FLS_FCU_DF_ISSUE_BYTE_CMD
**
** Registers Used            : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_053 */
/* Implements AR_PN0072_FR_0051 */
/* Implements EAAR_PN0034_FSR_0011,EAAR_PN0034_FSR_0012,EAAR_PN0034_FSR_0013 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuForcedStop(void)
{
  uint32 LulFlsStatusRegValue;
  uint8 LucFlsAccessStatusRegValue;
  Fls_FcuStatusType LenStatus;
  uint32 LulTimeout;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Issuing Forced Stop Command */
  FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_FORCED_STOP);
  /* END Msg(4:0303)-1 */
  LenStatus = FLS_FCU_BUSY;
  /* Implements FLS_ESDD_UD_107 */
  LulTimeout = FLS_FCU_FRDY_POOL_COUNT;
  /* We need a dummy read as the mode is not changed immediately on
    some devices */
  do
  {
    /* QAC Warning: START Msg(2:2814)-1 */
    LulFlsStatusRegValue = LpFACIRegPtr->ulFSTATR;
    LucFlsAccessStatusRegValue = LpFACIRegPtr->ucFASTAT;
    /* END Msg(2:2814)-1 */
  /* QAC Warning: START Msg(2:3892)-7 */
    if ((FLS_FCU_REGBIT_FSTATR_FRDY ==
                    (FLS_FCU_REGBIT_FSTATR_FRDY & LulFlsStatusRegValue)) &&
        (FLS_ZERO ==
                    (FLS_FCU_REGBIT_FASTAT_CMDLK & LucFlsAccessStatusRegValue)))
    {
  /* END Msg(2:3892)-7 */
      LenStatus = FLS_FCU_OK;
    }
    else
    {
      LulTimeout--;
    }
  } while((FLS_FCU_BUSY == LenStatus) && (LulTimeout > FLS_FCU_ZERO));

  /* Check if time out occurs due to internal error */
  if (FLS_FCU_ZERO == LulTimeout)
  {
    LenStatus = FLS_FCU_ERR_INTERNAL;
  }
  else
  {
    /* No action required */
  }
  return(LenStatus);

}/* End of function Fls_FcuForcedStop */
/* MISRA Violation: START Msg(4:0857)-5 */
#define FLS_STOP_SEC_PRIVATE_CODE
/* END Msg(4:0857)-5 */
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_FcuClearStatus
**
** Service ID                : NA
**
** Description               : This function clears (error) status of the
**                             sequencer by issuing the clear status FCU
**                             command.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : FLS_FCU_DF_ISSUE_BYTE_CMD
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-5 */
#define FLS_START_SEC_PRIVATE_CODE
/* END Msg(4:0857)-5 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_054 */
/* Implements AR_PN0072_FR_0051 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuClearStatus(void)
{

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Issue Clear Status Command */
  FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_CLEARSTAT);
  /* END Msg(4:0303)-1 */

} /* End of function Fls_FcuClearStatus */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_FWCOPY_SUPPORTED == STD_ON)
/*******************************************************************************
** Function Name             : Fls_FcuVerifyChecksum
**
** Service ID                : NA
**
** Description               : This function verify the FCURAM checksum.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : Fls_FcuGstVar.ulFcuChksumEndAddr(R)
**                             Fls_FcuGstVar.ulFcuChksumVal(W)
**
** Function(s) invoked       : FLS_FCU_DF_ISSUE_BYTE_CMD,FLS_DF_READ16
**
** Registers Used            : FCURAME
*******************************************************************************/

#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_055 */
/* Implements AR_PN0072_FR_0051 */
/* Implements EAAR_PN0034_FSR_0002 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuVerifyChecksum(void)
{
  Fls_FcuStatusType LenStatus;
  uint32 LulAddr;
  uint32 LulAddrEnd;
  uint32 LulChkSum;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  LulChkSum = (uint32)(FLS_FCU_NULL);
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  /* Check if critical section protection is required */
  /* Implements FLS_ESDD_UD_084 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /*Writing to FCRME bit of FCURAME register is enabled only when
  FLS_FCU_REGBIT_FCURAME_KEY is written to it.
  However, while reading this register, the key shall not be present.
  Hence for write verification, we pass the actual written value and
  key is not passed as it may lead to erroneous output*/
  /* Activate FCU RAM R/W access */
  /* QAC Warning: START Msg(2:2814)-1 */
  FLS_REG_WRITE(LpFACIRegPtr->usFCURAME,
                   (FLS_FCU_REGBIT_FCURAME_FCRME + FLS_FCU_REGBIT_FCURAME_KEY))
  /* END Msg(2:2814)-1 */
  /* MISRA Violation: START Msg(4:1290)-4 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFCURAME,
      FLS_FCU_REGBIT_FCURAME_FCRME, FCURAME_REG_MASK_VAL, FLS_INIT_API_ID)
  /* END Msg(4:1290)-4 */
  /* Implements FLS_ESDD_UD_084 */
  /* Check if critical section protection is required */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Implements FLS_ESDD_UD_113 */
  /* Calculate and compare FCU RAM checksum */
  LulAddrEnd = Fls_FcuGstVar.ulFcuChksumEndAddr;

  /* MISRA Violation: START Msg(4:0303)-1 */
  for (LulAddr = FLS_FCU_RAM_ADD; LulAddr < LulAddrEnd; LulAddr +=
                                                        (uint32)(FLS_FCU_TWO))
  {
    LulChkSum += (uint32)(FLS_DF_READ16(LulAddr));
  }
  /* END Msg(4:0303)-1 */
  /* Implements FLS_ESDD_UD_113 */
  /* Check if the calculated and Stored CheckSum are same */
  if (Fls_FcuGstVar.ulFcuChksumVal == LulChkSum)
  {
    LenStatus = FLS_FCU_BUSY;
  }
  else
  {
    LenStatus = FLS_FCU_ERR_INTERNAL;
  }

  /* Implements FLS_ESDD_UD_084 */
  /* Check if critical section protection is required */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif  /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /*Writing to FCRME bit of FCURAME register is enabled only when
  FLS_FCU_REGBIT_FCURAME_KEY is written to it.
  However, while reading this register, the key shall not be present.
  Hence for write verification, we pass the actual written value and
  key is not passed as it may lead to erroneous output*/

  /* Deactivate FCU RAM access */
  FLS_REG_WRITE(LpFACIRegPtr->usFCURAME,
                   (FLS_FCU_REGBIT_FCURAME_RESET + FLS_FCU_REGBIT_FCURAME_KEY))
  /* MISRA Violation: START Msg(4:1290)-4 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFCURAME,
           FLS_FCU_REGBIT_FCURAME_RESET, FCURAME_REG_MASK_VAL, FLS_INIT_API_ID)
  /* END Msg(4:1290)-4 */
  /* Implements FLS_ESDD_UD_084 */
  /* Check if critical section protection is required */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  return(LenStatus);

} /*End of function Fls_FcuVerifyChecksum */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif  /* #if (FLS_FWCOPY_SUPPORTED == STD_ON) */
/*******************************************************************************
** Function Name             : Fls_FcuGetFWParam
**
** Service ID                : NA
**
** Description               : This function reads the out a firmware parameter
**                             from the Extra area
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : LulAddress
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : LulValue
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : Fls_FcuSwitchBFlash,FLS_DF_READ32,
**                             Fls_FcuClearCache,EXECUTE_SYNCP
**
** Registers Used            : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATERAM_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_056 */
/* Implements EAAR_PN0034_FR_0068 */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuGetFWParam(const uint32 LulAddress)
{
  uint32 LulValue;
  #if (FLS_FWCOPY_SUPPORTED == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_CODE_FLASH_DISABLED);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Activate BFlash */
  Fls_FcuSwitchBFlash(FLS_FCU_ENABLE_BFLASH);
  /* MISRA Violation: START Msg(4:0303)-1 */
  Fls_FcuClearCache();
  /* QAC Warning: START Msg(2:2814)-1 */
  LulValue = FLS_DF_READ32(LulAddress);
  /* END Msg(2:2814)-1 */
  /* END Msg(4:0303)-1 */
  EXECUTE_SYNCP();
  /* Deactivate BFlash */
  Fls_FcuSwitchBFlash(FLS_FCU_DISABLE_BFLASH);

  /* Report DEM by checking the status of Global variable Fls_GblDemStatusFlag
  */
  if (FLS_TRUE == Fls_GblDemStatusFlag)
  {
    Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear the status flags */
    Fls_GblDemStatusFlag = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }

  Fls_FcuClearCache();

  /* Report DEM by checking the status of Global variable Fls_GblDemStatusFlag
  */
  if (FLS_TRUE == Fls_GblDemStatusFlag)
  {
    Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear the status flag */
    Fls_GblDemStatusFlag = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_CODE_FLASH_DISABLED);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #else
  LulValue = (*(uint32*)LulAddress);
  #endif /* #if (FLS_FWCOPY_SUPPORTED == STD_ON) */

  return(LulValue);

}/*End of function Fls_FcuGetFWParam */

#define FLS_STOP_SEC_PRIVATERAM_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_FcuGetDFSize
**
** Service ID                : NA
**
** Description               : This function is used to get the Data Flash size
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Size of data flash
**
** Return parameter          : LulReturn
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : Fls_FcuGetFWParam,FLS_DF_READ32
**
** Registers Used            : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_057 */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuGetDFSize(void)
{
  uint32 LulReturn;
  uint32 LulData;
  uint32 LulDataAddr;

  /* Entry tells where to find the PRD* information */
  LulDataAddr = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_SCDSADD);
  /* MISRA Violation: START Msg(4:0303)-1 */
  LulData = FLS_DF_READ32(LulDataAddr + FLS_FCU_PRDSEL3_OFFSET);
  /* END Msg(4:0303)-1 */
  /* Lower 16Byte are the DF size in kB. So, multiply accordingly */
  LulData &= FLS_FCU_DF_SIZE_MASK;
  LulReturn = LulData * FLS_FCU_ONE_KB;

  return(LulReturn);
} /*End of function Fls_FcuGetDFSize */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_FWCOPY_SUPPORTED == STD_ON)
/*******************************************************************************
** Function Name             : Fls_FcuInitRAM
**
** Service ID                : NA
**
** Description               : This function copies the firmware to the FCU RAM.
**                             Prepares the parameter structure for the function
**                             to be executed in RAM, calls the function to copy
**                             and execute the code in RAM, saves the checksum
**                             related values for later processing and clears
**                             the cache.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : Fls_FcuCopytoRam
**
** Registers Used            : FCURAME
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_058 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuInitRAM(void)
{
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  /* Check if critical section protection is required */
  /* Implements FLS_ESDD_UD_084 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Writing to FCRME bit of FCURAME register is enabled only when
  FLS_FCU_REGBIT_FCURAME_KEY is written to it.
  However, while reading this register, the key shall not be present.
  Hence for write verification, we pass the actual written value and
  key is not passed as it may lead to erroneous output */
  /* QAC Warning: START Msg(2:2814)-1 */
  /* Activate FCU RAM access */
  FLS_REG_WRITE(LpFACIRegPtr->usFCURAME,( FLS_FCU_REGBIT_FCURAME_FCRME +
                 FLS_FCU_REGBIT_FCURAME_FRAMTRAN + FLS_FCU_REGBIT_FCURAME_KEY))
  /* END Msg(2:2814)-1 */
  /* MISRA Violation: START Msg(4:1290)-4 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFCURAME, \
  (FLS_FCU_REGBIT_FCURAME_FCRME + FLS_FCU_REGBIT_FCURAME_FRAMTRAN), \
                                         FCURAME_REG_MASK_VAL, FLS_INIT_API_ID)
  /* END Msg(4:1290)-4 */
  /* Implements FLS_ESDD_UD_084 */
  /* Check if critical section protection is required */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Invoke the function to copy firmware to FCURAM */
  Fls_FcuCopytoRam();

  /* Check if critical section protection is required */
  /* Implements FLS_ESDD_UD_084 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /*Writing to FCRME bit of FCURAME register is enabled only when
  FLS_FCU_REGBIT_FCURAME_KEY is written to it.
  However, while reading this register, the key shall not be present.
  Hence for write verification, we pass the actual written value and
  key is not passed as it may lead to erroneous output*/

  /* Deactivate FCU RAM access */
  FLS_REG_WRITE(LpFACIRegPtr->usFCURAME,
                   (FLS_FCU_REGBIT_FCURAME_RESET + FLS_FCU_REGBIT_FCURAME_KEY))
  /* MISRA Violation: START Msg(4:1290)-4 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFCURAME,
       FLS_FCU_REGBIT_FCURAME_RESET, FCURAME_REG_MASK_VAL, FLS_INIT_API_ID)
  /* END Msg(4:1290)-4 */
  /* Implements FLS_ESDD_UD_084 */
  /* Check if critical section protection is required */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

} /*End of function Fls_FcuInitRAM */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_FWCOPY_SUPPORTED == STD_ON) */
/*******************************************************************************
** Function Name             : Fls_FcuSetFrequency
**
** Service ID                : NA
**
** Description               : This function is used to set the FCU frequency.
**                             FCU frequency, set in MHz is needed.
**                             The function may return an error if the
**                             frequency could not be set.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : NA
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GpConfigPtr(R),
**                             Fls_FcuGstVar.ulFcuBaseAddrECC(W)
**
** Function(s) invoked       : Fls_FcuGetFWParam
**
** Registers Used            : FPCKAR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_059 */
/* Implements EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
/* Implements EAAR_PN0034_FSR_0001 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSetFrequency(void)
{
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* Implements FLS_ESDD_UD_111 */
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, FLS_CONFIG_DATA) LpECCRegPtr;
  Fls_FcuStatusType LenStatus;
  uint16 LusFaciFreq;
  uint32 LulFwVal;
  uint8  LucFwVer;
  uint8  LucFreqDivider;
  uint32 LulMinFreq;
  uint32 LulMaxFreq;
  uint32 LulPClkFreq;
  uint32 LulFreqData;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;
  /* END Msg(2:2814)-1 */
  LenStatus = FLS_FCU_OK;

  /* Get firmware parameters */
  /* FW version is 1 Byte on not word aligned address,
     so we read word aligned and calculate the correct byte */
  LulFwVal  = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FWVER &
                                               (~FLS_FCU_FWVER_VAL_MASK));
  LucFwVer  = (uint8)((LulFwVal >> FLS_FCU_EIGHT) & (uint32)FLS_FCU_BYTE_RESET);

  LulFreqData = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FDIV_FWVER);

  if (FLS_FCU_BYTE_RESET != LucFwVer)
  {
    /* Frequency is 32bit value in Hz. We need to calculate MHz from that */
    LulFwVal  = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FMIN);
    LulMinFreq     = LulFwVal / FLS_FCU_ONE_MHZ;

    LulFwVal  = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FMAX);
    LulMaxFreq     = LulFwVal / FLS_FCU_ONE_MHZ;

    if (LucFwVer < FLS_FCU_FWVER_04)
    {
      /* Divider 1 Byte only but on a word aligned address,
         so we read word aligned and calculate the correct byte */
      LucFreqDivider = (uint8)(LulFreqData & (uint32)FLS_FCU_BYTE_RESET);

      /* PCLK Frequency is 32bit value in Hz.
         We need to calculate MHz from that */
      LulFwVal  = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FPCLK_FWVER_03);
      LulPClkFreq    = LulFwVal / FLS_FCU_ONE_MHZ;

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* ECC Base Address value is generated by Tool.
         Need not be calculated */
      Fls_FcuGstVar.ulFcuBaseAddrECC = (uint32)LpECCRegPtr;
      /* END Msg(4:0303)-1 */
    }
    else
    {
      /* Divider 1 Byte only but on a word aligned address,
         so we read word aligned and calculate the correct byte */
      LulFwVal = (uint32)(LulFreqData >> FLS_FCU_EIGHT);
      LucFreqDivider = (uint8)(LulFwVal & (uint32)FLS_FCU_BYTE_RESET);

      /* PCLK Frequency is 32bit value in Hz.
         We need to calculate MHz from that */
      LulFwVal  = Fls_FcuGetFWParam(FLS_FCU_EXTRA3_FPCLK_FWVER_04);
      LulPClkFreq    = LulFwVal / FLS_FCU_ONE_MHZ;
      Fls_FcuGstVar.ulFcuBaseAddrECC =
                                      Fls_FcuGetFWParam(FLS_FCU_EXTRA3_ECCADDR);
    }

    if (((uint32)FLS_CPU_FREQUENCY_MHZ >= LulMinFreq) && \
                              ((uint32)FLS_CPU_FREQUENCY_MHZ <= LulMaxFreq))
    {
      if ((FLS_FCU_BYTE_RESET != LucFreqDivider) && \
         (FLS_FCU_ZERO != LucFreqDivider))
      {
        /* FCU frequency calculation (including frequency round up) */
        LusFaciFreq = (uint16)(((uint16)(FLS_CPU_FREQUENCY_MHZ) + \
        (uint16)LucFreqDivider) - (uint16)FLS_FCU_ONE)/(uint16) LucFreqDivider;
      }
      else
      {
        /* FCU frequency is fix and independent from the CPU frequency*/
        LusFaciFreq = (uint16)LulPClkFreq;
      }
      /* Implements FLS_ESDD_UD_084 */
      /* Check if critical section protection is required */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
      #endif

      /*Writing to FPCKAR register is enabled only when
       FLS_FCU_REGBIT_FPCKAR_KEY is written to it.
       However, while reading this register, the key shall not be present.
       Hence for write verification, we pass the actual written value and
       key is not passed as it may lead to erroneous output*/
       /* QAC Warning: START Msg(2:2814)-1 */
       /* Set frequency */
       FLS_REG_WRITE(LpFACIRegPtr->usFPCKAR,
                                      (FLS_FCU_REGBIT_FPCKAR_KEY + LusFaciFreq))
       /* END Msg(2:2814)-1 */
       /* MISRA Violation: START Msg(4:1851)-2 */
       /* MISRA Violation: START Msg(4:1853)-3 */
       /* MISRA Violation: START Msg(4:1290)-4 */
       /* For write verification */
       FLS_REG_WRITE_VERIFY_INIT(LpFACIRegPtr->usFPCKAR, LusFaciFreq, \
                                           FLS_16BIT_MASK_VAL, FLS_INIT_API_ID)
       /* END Msg(4:1290)-4 */
       /* END Msg(4:1853)-3 */
       /* END Msg(4:1851)-2 */
       /* Implements FLS_ESDD_UD_084 */
       /* Check if critical section protection is required */
       #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
       /* Enable relevant interrupts to exit this critical section */
       FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
       #endif
    }
    else
    {
      LenStatus = FLS_FCU_ERR_CONFIGURATION;
    }
  }
  else
  {
    /* No action required */
  }

  return(LenStatus);
} /*End of function Fls_FcuSetFrequency */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name            : Fls_FcuDataCopy
**
** Service ID               : None
**
** Description              : This function copies the Read data from Temporary
**                            Buffer to Application Buffer.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : LulSrcAddr, LulBufferAddr
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : LulDFERStatus
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulSrcDestAddress(W)
**
** Function(s) invoked      : FLS_DF_READ32,FLS_DF_WRITE32
**
** Registers Used           : DFERSTR,DFERSTC
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_061 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* Implements AR_PN0072_FR_0023 */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuDataCopy
(const uint32 LulSrcAddr, const uint32 LulBufferAddr)
{
  /* Implements FLS_ESDD_UD_111 */
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, FLS_CONFIG_DATA) LpECCRegPtr;
  uint32 LulReadData;
  /* Local variable to hold the value of Data Flash error status register */
  uint32 LulDFERStatus;

  /* QAC Warning: START Msg(2:2814)-1 */
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;
  /* MISRA Violation : START Msg(4:0303)-1 */
  /* Reading the data from source address */
  LulReadData = FLS_DF_READ32(LulSrcAddr);
  /* Writing the data to application buffer */
  FLS_DF_WRITE32(LulBufferAddr, LulReadData);
  /* END Msg(4:0303)-1 */
  /* Get the Data Flash error status register value */
  LulDFERStatus = LpECCRegPtr->ulDFERSTR;
  /* END Msg(2:2814)-1 */
  if (FLS_FCU_REGVAL_DFERSTR_NOERR != LulDFERStatus)
  {
    /* Global variable to hold the ECC error occurrence address */
    Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC,FLS_FCU_REGBIT_DFERSTC_ERRCLR)
    /* QAC Warning: START Msg(2:3892)-7 */
    /* MISRA Violation: START Msg(4:1290)-9 */
    FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ulDFERSTR, \
              FLS_FCU_REGVAL_DFERSTR_NOERR, FLS_08BIT_MASK_VAL, \
                                                       FLS_FCUDATACOPY_API_ID)
    /* END Msg(4:1290)-9 */
    /* END Msg(2:3892)-7 */
  }
  else
  {
    /* No Action Required */
  }
  return(LulDFERStatus);
}/* End of function Fls_FcuDataCopy */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuOffsetDataCopy
**
** Service ID               : None
**
** Description              : This function is used to copy the data from
**                            Temporary Buffer to Application Buffer in case of
**                            Misaligned address or length is input.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : LulSrcAddr, LulBufferAddr, LucOffset
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : Read operation address/length are not page
**                            aligned.
**
** Global Variables Used    : None
**
** Function(s) invoked      : FLS_DF_READ8,FLS_DF_READ16,FLS_DF_WRITE8,
**                            FLS_DF_WRITE16
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_062 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuOffsetDataCopy
(uint32 LulSrcAddr, uint32 LulBufferAddr, const uint8 LucOffset)
{
  uint8 LucReadData;
  uint16 LusReadData;

  switch (LucOffset)
  {
      /* QAC Warning: START Msg(2:2814)-1 */
  case FLS_ONE:
      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Reading the data from source address */
      LucReadData = FLS_DF_READ8(LulSrcAddr);
      /* Writing the data to application buffer */
      FLS_DF_WRITE8(LulBufferAddr, LucReadData);

  break;
  case FLS_TWO:
      /* Reading the data from source address */
      LusReadData = FLS_DF_READ16(LulSrcAddr);
      /* Writing the data to application buffer */
      FLS_DF_WRITE16(LulBufferAddr, LusReadData);

  break;
  case FLS_THREE:
      /* Reading the data from source address */
      LusReadData = FLS_DF_READ16(LulSrcAddr);
      /* Writing the data to application buffer */
      FLS_DF_WRITE16(LulBufferAddr, LusReadData);
      LulBufferAddr = LulBufferAddr + (uint32)FLS_TWO;
      LulSrcAddr = LulSrcAddr + (uint32)FLS_TWO;
      /* Reading the data from source address */
      LucReadData = FLS_DF_READ8(LulSrcAddr);
      /* Writing the data to application buffer */
      FLS_DF_WRITE8(LulBufferAddr, LucReadData);
      /* END Msg(4:0303)-1 */
  break;
      /* END Msg(2:2814)-1 */
      /* QAC Warning: START Msg(2:2016)-4 */
  default:
            break;
  }
      /* END Msg(2:2016)-4 */
}/* End of function Fls_FcuOffsetDataCopy */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuErasePreCheck
**
** Service ID               : NA
**
** Description              : Function to Check if Erase Job shall be initiated
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_FcuStatusType
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : None
**
** Registers Used           : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_063 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuErasePreCheck(void)
{
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  Fls_FcuStatusType LenStatus;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* Checking against error bits */
  if (FLS_FCU_REGBIT_FSTATR_FRDY != (LpFACIRegPtr->ulFSTATR &
                                                    FLS_FCU_ERASE_ERROR_CHECK))
  /* END Msg(2:2814)-1 */
  {
     /* Setting the status as Erase error as error bits are set and
    flash sequencer is in command lock state.*/
    LenStatus = FLS_FCU_ERR_ERASE;
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }

  return(LenStatus);
}
/* End of function Fls_FcuErasePreCheck */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuCheckJobStatus
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Erase Operation/ Write
**                            operation.This function checks if the FACI is
**                            ready to accept a new command and checks if any
**                            error bits are set after completion of a job.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_FcuStatusType(FLS_FCU_BUSY, FLS_FCU_OK,
**                            FLS_FCU_ERR_WRITE, FLS_FCU_ERR_ERASE)
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),
**                            Fls_GblJobSuspendRequest(R),
**                            Fls_GstVar.enGenCommand(R)
**
** Function(s) invoked      : Fls_FcuSwitchMode,Fls_ProcessSuspend
**
** Registers Used           : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_064 */
/* Implements AR_PN0072_FR_0023 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckJobStatus(void)
{
  /* Variable to hold the Register value */
  volatile uint32 LulRegValue;
  /* Return variable to store DF Status*/
  Fls_FcuStatusType LenStatus = FLS_FCU_BUSY;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* Get the register value */
  LulRegValue = LpFACIRegPtr->ulFSTATR;
  /* END Msg(2:2814)-1 */
  /* Check if the Job is completed */
  if (FLS_FCU_REGBIT_FSTATR_FRDY == (FLS_FCU_REGBIT_FSTATR_FRDY & LulRegValue))
  {
    LenStatus = FLS_FCU_OK;
    /* Switching Back to User Mode */
    (void)Fls_FcuSwitchMode(FLS_FCU_MODE_USER);

    #if (FLS_SUSPEND_API == STD_ON) && (FLS_INTERRUPT_MODE == STD_OFF)
    /* QAC Warning: START Msg(2:3416)-3 */
    if (FLS_TRUE == Fls_GblJobSuspendRequest)
    /* END Msg(2:3416)-3 */
    {
      Fls_ProcessSuspend();
    }
    else
    {
      /* No action required */
    }
    #endif
  }
  /* Check if there is any error(Program/Erasure) */
  else if ((uint32)FLS_ZERO != (FLS_FCU_FSTATR_PE_ERROR & LulRegValue))
  {
    if (FLS_COMMAND_ERASE == Fls_GstVar.enGenCommand)
    {
      LenStatus = FLS_FCU_ERR_ERASE;
    }
    else
    {
      LenStatus = FLS_FCU_ERR_WRITE;
    }
  }
  /* FCU is busy */
  else
  {
    /* No action required */
  }
  /* Store the DF Status */
  Fls_GstVar.enDFStatus = LenStatus;

  return(LenStatus);
}/* End of function Fls_FcuCheckJobStatus */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuCheckBCJobStatus
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Blank Check operation.
**                            This function checks if the FACI is ready to
**                            accept a new command.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_FcuStatusType
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W)
**
** Function(s) invoked      : None
**
** Registers Used           : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_065 */
/* Implements AR_PN0072_FR_0023 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckBCJobStatus(void)
{
  /* Variable to hold the Register value */
  volatile uint32 LulRegValue;
  /* Return variable to store DF Status*/
  Fls_FcuStatusType LenStatus;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* Get the register value */
  LulRegValue = LpFACIRegPtr->ulFSTATR;
  /* END Msg(2:2814)-1 */
  /* Check if the Job is completed */
  if (FLS_FCU_REGBIT_FSTATR_FRDY == (FLS_FCU_REGBIT_FSTATR_FRDY & LulRegValue))
  {
    LenStatus = FLS_FCU_OK;
  }
  /* FCU is busy */
  else
  {
    LenStatus = FLS_FCU_BUSY;
  }

  /* Store the DF Status */
  Fls_GstVar.enDFStatus = LenStatus;

  return(LenStatus);
}/* End of function Fls_FcuCheckBCJobStatus */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuBlankCheckResult
**
** Service ID               : NA
**
** Description              : This function is to the status of Blank Check
**                            Operation
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : LenBCStatus
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : None
**
** Registers Used           : FBCSTAT
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_066 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuBlankCheckResult(void)
{
  /* Variable to hold the Register value */
  volatile uint32 LulRegValue;
  /* Variable to hold the status of Blank Check Job*/
  Fls_FcuStatusType LenBCStatus;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* Get the status of Blank Check Operation */
  LulRegValue = LpFACIRegPtr->ucFBCSTAT;
  /* END Msg(2:2814)-1 */

  if ((uint32)FLS_FCU_REGBIT_FBCSTAT_BCST != (LulRegValue &
                                          (uint32)FLS_FCU_REGBIT_FBCSTAT_BCST))
  {
    LenBCStatus = FLS_FCU_OK;
  }
  else
  {
    LenBCStatus = FLS_FCU_ERR_BLANKCHECK;
  }

  return(LenBCStatus);

}/* End of function Fls_FcuBlankCheckResult */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuPerformBlankCheck
**
** Service ID               : NA
**
** Description              : This function performs the blank check operation.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : NA
**
** Input Parameters         : LulStartAddr,Lulcount
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuSwitchMode,FLS_FCU_DF_ISSUE_BYTE_CMD
**
** Registers Used           : FSADDR,FEADDR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_067 */
/* Implements AR_PN0072_FR_0051 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuPerformBlankCheck
(const uint32 LulStartAddr, const uint32 Lulcount)
{
  Fls_FcuStatusType LenStatus;
  /* QAC Warning: START Msg(2:3204)-5 */
  uint32 LulEndAddr;
  /* END Msg(2:3204)-5 */
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  LulEndAddr = ((LulStartAddr + Lulcount) - FLS_FCU_ONE);
  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);
  if (FLS_FCU_OK == LenStatus)
  {
    /* Setting BlankCheck Start and End Address */
    FLS_REG_WRITE(LpFACIRegPtr->ulFSADDR,LulStartAddr)
    /* MISRA Violation: START Msg(4:1290)-4 */
    /* For write verification */
    FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFSADDR, LulStartAddr, \
                          FLS_32BIT_MASK_VAL, FLS_FCUPERFORMBLANKCHECK_API_ID)
    /* END Msg(4:1290)-4 */
    FLS_REG_WRITE(LpFACIRegPtr->ulFEADDR,(LulEndAddr & FEADDR_REG_MASK_VAL))
    /* MISRA Violation: START Msg(4:1290)-4 */
    /* For write verification */
    FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFEADDR, \
    (LulEndAddr & FEADDR_REG_MASK_VAL), FEADDR_REG_MASK_VAL, \
                                              FLS_FCUPERFORMBLANKCHECK_API_ID)
    /* END Msg(4:1290)-4 */
    /* END Msg(2:2814)-1 */
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* Issuing ERASE Command */
    FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_BLANKCHECK);
    /* Issuing Confirmation Command */
    FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_EXE);
    /* END Msg(4:0303)-1 */
  }
  else
  {
    /* No action required */
  }
  return(LenStatus);
}/* End of function Fls_FcuPerformBlankCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuResetErrorBits
**
** Service ID               : NA
**
** Description              : This function clears the error bits
**                           (erasure error or program error) by issuing Status
**                            Clear Command
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non-Reentrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Std_ReturnType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuSwitchMode,Fls_FcuClearStatus
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_070 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_FcuResetErrorBits(void)
{
  /* Variable to store return variable */
  Std_ReturnType LenReturnValue;
  Fls_FcuStatusType LenStatus;
  LenReturnValue = E_OK;
  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);

  if (FLS_FCU_OK == LenStatus)
  {
    /* Issue Clear Status command */
    Fls_FcuClearStatus();

    /* Switching to USER Mode */
    (void)Fls_FcuSwitchMode(FLS_FCU_MODE_USER);
  }
  else
  {
    LenReturnValue = E_NOT_OK;
  }

  return(LenReturnValue);
} /* End of function Fls_FcuResetErrorBits */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_FWCOPY_SUPPORTED == STD_ON)
/*******************************************************************************
** Function Name            : Fls_FcuCopytoRam
**
** Service ID               : NA
**
** Description              : This function copies the FCU Firmware to the
**                            FCURAM and reads the device specific info.
**                            As BFLASH need to be activated to copy code from
**                            firmware to FCU RAM, this function needs to be
**                            mapped in RAM.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_FcuGstVar.ulFcuChksumEndAddr(RW)
**                            Fls_FcuGstVar.ulFcuChksumVal(W)
**
** Function(s) invoked      : FLS_DF_WRITE32,FLS_DF_READ32,Fls_FcuSwitchBFlash
**                            Fls_FcuClearCache,EXECUTE_SYNCP
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATERAM_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_071 */
/* Implements EAAR_PN0034_FR_0068 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuCopytoRam(void)
{
  uint32 LulFWSrcAddr;
  uint32 LulRAMDestStartAddr;
  uint32 LulData;
  volatile uint32 LulFWSize;
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_CODE_FLASH_DISABLED);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Activate BFlash */
  Fls_FcuSwitchBFlash(FLS_FCU_ENABLE_BFLASH);
  /* MISRA Violation: START Msg(4:0303)-1 */
  Fls_FcuClearCache();
  LulFWSize = FLS_DF_READ32(FLS_FCU_RAM_ADD_CHKSUM_END);
  /*  END Msg(4:0303)-1 */
  /* Implements FLS_ESDD_UD_113 */
  Fls_FcuGstVar.ulFcuChksumEndAddr = LulFWSize << FLS_FCU_TWO;
  /* Read FCU RAM checksum and FCU code size */
  Fls_FcuGstVar.ulFcuChksumEndAddr = Fls_FcuGstVar.ulFcuChksumEndAddr +
                                                              FLS_FCU_RAM_ADD;

  /* MISRA Violation: START Msg(4:0303)-1 */
  Fls_FcuGstVar.ulFcuChksumVal  = FLS_DF_READ32(FLS_FCU_RAM_ADD_CHKSUM);
  /*  END Msg(4:0303)-1 */

  /* Copy firmware to RAM - Initialize the complete RAM */
  LulFWSrcAddr       = FLS_FCU_RAM_SRC_ADD;

  for (LulRAMDestStartAddr = FLS_FCU_RAM_ADD;
       LulRAMDestStartAddr < (FLS_FCU_RAM_ADD + FLS_FCU_RAM_SIZE);
                                         LulRAMDestStartAddr += FLS_FCU_FOUR)
  {
    /* MISRA Violation: START Msg(4:0303)-1 */
    LulData = FLS_DF_READ32(LulFWSrcAddr);
    FLS_DF_WRITE32(LulRAMDestStartAddr,LulData);
    /*  END Msg(4:0303)-1 */
    LulFWSrcAddr += FLS_FCU_FOUR;
  }
  EXECUTE_SYNCP();
  /* Deactivate BFlash */
  Fls_FcuSwitchBFlash(FLS_FCU_DISABLE_BFLASH);

  /* Report DEM by checking the status of Global variable Fls_GblDemStatusFlag
  */
  if (FLS_TRUE == Fls_GblDemStatusFlag)
  {
    Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear the status flags */
    Fls_GblDemStatusFlag = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }
  Fls_FcuClearCache();

  /* Report DEM by checking the status of Global variable Fls_GblDemStatusFlag
  */
  if (FLS_TRUE == Fls_GblDemStatusFlag)
  {
    Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear the status flag */
    Fls_GblDemStatusFlag = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_CODE_FLASH_DISABLED);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
} /* End of function Fls_FcuCopytoRam */

#define FLS_STOP_SEC_PRIVATERAM_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuSwitchBFlash
**
** Service ID               : NA
**
** Description              : This function is used to select and deselect
**                            FCU firmware storage area
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non-Reentrant
**
** Input Parameters         : LucMode
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : EXECUTE_SYNCI,EXECUTE_SYNCP
**
** Registers Used           : FCUFAREA
*******************************************************************************/
#define FLS_START_SEC_PRIVATERAM_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_072 */
/* Implements EAAR_PN0034_FR_0068 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuSwitchBFlash(const uint8 LucMode)
{
  /* MISRA Violation: START Msg(3:3203)-6 */
  volatile uint8 LucModeVal;
  /* MISRA Violation: START Msg(4:0303)-1 */
  FLS_REG_WRITE(FLS_FCUFAREA,LucMode)

  /* Dummy read to the register to ensure data reached the register
    (wait one APB access cycle) */
  LucModeVal = FLS_FCUFAREA;
  /* END Msg(3:3203)-6 */
  /* Start : FLS_UT_003*/
  /* Check if FCUFAREA is set correctly */
  if ((FLS_FCUFAREA & FLS_FCU_ENABLE_BFLASH) != LucMode)
  /* END Msg(4:0303)-1 */
  {
    /* Report error via call-back function */
    Fls_CallSwitchBFlashErrorNotification();
  }
  /* End : FLS_UT_003*/
  else
  {
    /* No action required */
  }
  EXECUTE_SYNCP();
  EXECUTE_SYNCI();
} /* End of function Fls_FcuSwitchBFlash */

#define FLS_STOP_SEC_PRIVATERAM_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_FcuClearCache
**
** Service ID               : NA
**
** Description              : This function clears the cache, depending on the
**                            available core
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : STSR, LDSR, EXECUTE_SYNCI, EXECUTE_SYNCP
**
** Registers Used           : ICCTRL,CDBCR
*******************************************************************************/
#define FLS_START_SEC_PRIVATERAM_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_073 */
/* Implements EAAR_PN0034_FSR_0013,EAAR_PN0034_FSR_0012,EAAR_PN0034_FSR_0011 */
/* Implements EAAR_PN0034_FR_0068 */
/* Implements FLS352,FLS260,FLS006 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuClearCache(void)
{
  uint32 LulSrVal;
  uint8 LucLoopCount;
  /* Implements FLS_ESDD_UD_107 */
  LucLoopCount = FLS_LOOP_COUNT;
  /* clear instruction cache */
  LulSrVal = STSR (FLS_FCU_SYSTEM_REGISTER_ICCTRL);
  /* set bit 8 (ICHCLR) of system register ICCTRL to 1 to clear instruction
   cache */
  LulSrVal |= FLS_FCU_REGBIT_ICHCLR;
  LDSR(FLS_FCU_SYSTEM_REGISTER_ICCTRL, LulSrVal);
  do
  {
    /* Dummy read to system register to complete the operation*/
    LulSrVal = STSR(FLS_FCU_SYSTEM_REGISTER_ICCTRL);
    /* Check value of bit 8. If it changes to zero again, the cache is
    cleared. */
    LulSrVal &= FLS_FCU_REGBIT_ICHCLR;
    LucLoopCount--;
  } while ((FLS_FCU_ZERO != LulSrVal)&&(LucLoopCount > FLS_FCU_ZERO));
  /* If Time out occurs */
  if (FLS_FCU_ZERO == LucLoopCount)
  {
    /* Set global variable to indicate potential HW failure */
    Fls_GblDemStatusFlag = FLS_TRUE;
  }
  else
  {
    /* No action required */
  }
  EXECUTE_SYNCP();
  EXECUTE_SYNCI();

  /* G3M core -> clear sharing data buffer */
  LulSrVal = STSR(FLS_FCU_SYSTEM_REGISTER_CDBCR);
  /* set bit 1 (CDBCLR) of system register CDBCR to 1 to clear the buffer */
  LulSrVal |= FLS_FCU_TWO;
  LDSR(FLS_FCU_SYSTEM_REGISTER_CDBCR, LulSrVal);
  /* Dummy read to system register to complete the operation*/
  (void)STSR(FLS_FCU_SYSTEM_REGISTER_CDBCR);

} /* End of function Fls_FcuClearCache */
#define FLS_STOP_SEC_PRIVATERAM_CODE
#include "MemMap.h"
#endif /* #if (FLS_FWCOPY_SUPPORTED == STD_ON) */
/*******************************************************************************
** Function Name            : Fls_FcuWritePreCheck
**
** Service ID               : NA
**
** Description              : This Function checks if Write Job shall be
**                            initiated
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_FcuStatusType
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : None
**
** Registers Used           : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_020 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuWritePreCheck(void)
{
  Fls_FcuStatusType LenStatus;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* Checking against error bits */
  if (FLS_FCU_REGBIT_FSTATR_FRDY != (LpFACIRegPtr->ulFSTATR &
                                                    FLS_FCU_WRITE_ERROR_CHECK))
   /* END Msg(2:2814)-1 */
  {
    /* Setting the status as Write error as error bits are set and
    flash sequencer is in command lock state.*/
    LenStatus = FLS_FCU_ERR_WRITE;
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }

  return(LenStatus);
} /* End of function Fls_FcuWritePreCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name            : Fls_FcuInit
**
** Service ID               : NA
**
** Description              : This function initialises FCU Global Variable
**                            Structure and prepares the environment
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_FcuGstVar.usCpuFrequencyMHz(W),
**                            Fls_FcuGstVar.usFcuFlashMode(W),
**                            Fls_FcuGstVar.ulFcuDfSize(W),
**                            Fls_FcuGstVar.ulFcuBaseAddrECC(W),
**                            Fls_FcuGstVar.ulFcuChksumEndAddr(W),
**                            Fls_FcuGstVar.ulFcuChksumVal(W),
**                            Fls_FcuGstVar.usDFPoolSize(W),
**                            Fls_GstVar.enDFStatus(W)
**
** Function(s) invoked      : Fls_FcuPrepareEnvironment
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_060 */
/* Implements AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_FcuInit(void)
{
  Fls_FcuStatusType LenStatus;
  /* Initializing the FCU Global Variable Structure */
  /* Implements FLS_ESDD_UD_105 */
  /* Implements FLS_ESDD_UD_113 */
  Fls_FcuGstVar.usCpuFrequencyMHz   = FLS_CPU_FREQUENCY_MHZ;
  Fls_FcuGstVar.usDFPoolSize        = FLS_DF_POOL_SIZE;
  Fls_FcuGstVar.usFcuFlashMode      = FLS_FCU_MODE_USER;
  Fls_FcuGstVar.ulFcuDfSize         = (uint32)(FLS_FCU_NULL);
  Fls_FcuGstVar.ulFcuBaseAddrECC    = (uint32)(FLS_FCU_NULL);
  Fls_FcuGstVar.ulFcuChksumEndAddr  = (uint32)(FLS_FCU_NULL);
  Fls_FcuGstVar.ulFcuChksumVal      = (uint32)(FLS_FCU_NULL);

  /* Preparing Environment */
  LenStatus = Fls_FcuPrepareEnvironment();
  /* Returning Status after Prepare Environment */
  Fls_GstVar.enDFStatus = LenStatus;

} /* End of function Fls_FcuInit */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name             : Fls_FcuCheckSequencerStatus
**
** Service ID                : NA
**
** Description               : This function checks the FRDY bit and if
**                             there is a cmd lock based on timeout values.

** Sync/Async                : Synchronous
**
** Re-entrancy               : Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Fls_FcuStatusType
**
** Return parameter          : LenStatus
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : None
**
** Registers Used            : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements FLS_ESDD_UD_142 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckSequencerStatus(void)
{
  Fls_FcuStatusType LenStatus;
  uint32 LulTimeout;
  boolean LblFrdyCheck;
  /* Flash sequencer 'Command Lock' state */
  boolean LblCmdLockCheck;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;

  LenStatus = FLS_FCU_ERR_INTERNAL;
  LulTimeout = FLS_FCU_FRDY_POOL_COUNT;
  /* Processing of command in progress in flash sequencer */
  LblFrdyCheck = FLS_FALSE;

  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  do
  {
    /* QAC Warning: START Msg(2:2814)-1 */
    /* Check if FRDY bit in FSTATR register is set */
    if ((LpFACIRegPtr->ulFSTATR & FLS_FCU_REGBIT_FSTATR_FRDY) != FLS_FCU_ZERO)
    {
  /* END Msg(2:2814)-1 */
      LblFrdyCheck = FLS_TRUE;
    }
    else
    {
      LulTimeout--;
    }
  } while ((FLS_FALSE == LblFrdyCheck) && (FLS_FCU_ZERO < LulTimeout));

  /* If FRDY bit is set, check for CMDLK bit */
  if (FLS_TRUE == LblFrdyCheck)
  {
    /* QAC Warning: START Msg(2:3892)-7 */
    /* QAC Warning: START Msg(2:2814)-1 */
    /* Check if CMDLK bit in FASTAT register is set */
    if ((LpFACIRegPtr->ucFASTAT & FLS_FCU_REGBIT_FASTAT_CMDLK) != FLS_ZERO)
    {
    /* END Msg(2:2814)-1 */
    /* END Msg(2:3892)-7 */
      LblCmdLockCheck = FLS_TRUE;
    }
    else
    {
      LblCmdLockCheck = FLS_FALSE;
    }
  }
  else
  {
    /*do nothing */
  }

  if ((FLS_TRUE == LblFrdyCheck) && (FLS_FALSE == LblCmdLockCheck))
  {
    LenStatus = FLS_FCU_OK;
  }
  else
  {
    /* FLS_FCU_ERR_INTERNAL */
  }

  return(LenStatus);
} /* End of function Fls_FcuCheckSequencerStatus */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
**                           End of File                                      **
*******************************************************************************/
