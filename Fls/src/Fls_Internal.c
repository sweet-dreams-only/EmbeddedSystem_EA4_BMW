/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Internal.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Internal functions implementation of Flash              */
/* Wrapper Component.                                                         */
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
 * V1.0.1:  18-Mar-2016    : As part of P1x V4.01.00 release, following changes
 *                           are made :
 *                           1. As part of ARDAAAE-1697, updated Fls_MainRead,
 *                              Fls_ProcessJobResult, and
 *                              Fls_TimeOutCheckAndProcessing functions to
 *                              correct the saving/restoring/clearing of RFxxx
 *                              bit in ICxxx register.
 *                           2. As part of ARDAAAE-1631, updated
 *                              Fls_MainErase, Fls_MainWrite and
 *                              Fls_ProcessSuspend functions to correct the
 *                              suspend operation in polling and interrupt mode.
 *                           3. Function banner and comments of all functions
 *                              have been updated.
 *                           4. Access information read, write and read-write
 *                              (R, W, RW) are provided for Global Variables
 *                              in function banner.
 *                           5. Declaration and initialisation of local
 *                              variables have been made in separate lines.
 *                           6. Updated Fls_ProcessRead function to move disable
 *                              protection to Fls_PerformBlankCheckForReadOp
 *                              function.
 *                           7. Fls_ProcessReadImm function has been updated to
 *                              invoke Fls_FastReadCheckECC which is a newly
 *                              added internal function in-order to reduce the
 *                              cyclomatic complexity of Fls_ProcessReadImm
 *                              function.
 *                           8. Fls_InitiateEraseJob and Fls_InitiateWriteJob
 *                              functions have been updated to add conditional
 *                              check before loading time out count value.
 *                           9. Removed the global pointers usage
 *                              Fls_GpFACIRegPtr and Fls_GpECCRegPtr and used
 *                              local pointers instead in functions wherever
 *                              applicable.
 *                           10.Updated Fls_TimeOutCheckAndProcessing function
 *                              to report DEM FLS_E_HW_FAILURE when the
 *                              function Fls_ProcessCancel sets Data Flash
 *                              status as FLS_FCU_ERR_INTERNAL.
 *                           11.QAC warning START and END msgs for
 *                              Msg(2:2814),Msg(2:2824),Msg(2:1252),Msg(2:3892),
 *                              Msg(2:3227),Msg(2:2016),Msg(2:3204) and
 *                              Msg(3:3305),Msg(2:0862) are added at the
 *                              respective places.
 *                           12.Renamed Fls_VerifyCompletedJob variable to
 *                              Fls_GblVerifyCompletedJob and renamed
 *                              local variable LddLoopCount to LulLoopCount as
 *                              per coding standards.
 *                           13.Updated logic of loading LusBCLoopCount with
 *                              Blank Check count in
 *                              Fls_PerformBlankCheckForReadOp function.
 * V1.0.2:  05-May-2016    : As part of P1x V4.01.01 release, following changes
 *                           are made :
 *                           1. Added functions Fls_WriteInternal,
 *                              Fls_BlankCheckInternal,Fls_CancelInternal,
 *                              Fls_EraseInternal,Fls_SetStartEndAddr.
 *                           2. Critical section protection added in
 *                              Fls_TimeOutCheckAndProcessing and
 *                              Fls_ProcessJobResult functions for IMR register.
 *                           3. Declaration of 'LpFACIRegPtr' is made inside a
 *                              a pre-compile switch FLS_TIMEOUT_MONITORING in
 *                              Fls_InitiateWriteJob and Fls_InitiateEraseJob.
 *                           4. As per JIRA ID ARDAAAE-1901, added check
 *                              (FLS_COMMAND_WRITE !=
 *                              Fls_GstBackUpVar.enGenCommand) in
 *                              Fls_MainWrite().
 *                           5. As per Jira ARDAAAE-1910, the pointer analysis
 *                              tags are added.
 *                           6. UT ID Tag added for the uncovered parts of the
 *                              code.
 *                           7. As per ARDAAAE-1908, removed dead code.
 *                           8. As per ARDAAAE-1926,
 *                              a) condition check for time-out status is added
 *                                 in Fls_ProcessJobResult, Fls_ProcessRead,
 *                                 and Fls_TimeOutCheckAndProcessing functions.
 *                              b) Replaced assignment of local variable
 *                                 'LenStatus' with FLS_FCU_ERR_TIMEOUT macro in
 *                                 'Fls_ProcessCancel' function.
 *                           9. File "Fls_RegWrite.h" is included.
 *                           10.As per JIRA ID ARDAAAE-1989,
 *                              a) Updated status check in
 *                                 Fls_InitiateBlankCheckJob().
 *                              b) Fls_FcuInit() is relocated to
 *                                 Fls_Private_Fcu.c file.
 *                              c) Enabling of flash memory software protection
 *                                 in Fls_ProcessRead() is moved to
 *                                 Fls_PerformBlankCheckForReadOp().
 *                              d) In Fls_PreFcuInitCheck() updated reporting
 *                                 of DEM to report failure of both FACI and
 *                                 DF ECC control registers.
 *                              e) Renamed function Fls_FcuSuspendCheck() as
 *                                 Fls_SuspendPreCheck().
 *                           11.Updated register write verify implementation.
 *                           12.As per JIRA ID ARDAAAAE-2010, removed register
 *                              write verify for IMR register.
 *                           13.As per JIRA ID ARDAAAE-2026, corrected naming
 *                              convention of variables as per requirement
 *                              EAAR_PN0084_NR_0066.
 *                           14.Placed the constant value on the left side of
 *                              the comparison operator.
 *                           15.QAC warning START and END msgs for Msg(4:2742),
 *                              Msg(2:1252) and Msg(4:2880) are removed as
 *                              these warnings are fixed and justification for
 *                              misra warning 4:0857 is added.
 * V1.0.3:  24-Oct-2016    : Following change are made:
 *                           1. As per JIRA ID ARDAAAE-2001, corrected
 *                              type-casting of second argument in
 *                              Fls_FcuPerformBlankCheck function.
 *                           2. As per JIRA ID ARDAAAE-2013, updated
 *                              "registers used" in function banner of
 *                              Fls_ProcessJobResult, Fls_EraseInternal,
 *                              Fls_TimeOutCheckAndProcessing,
 *                              Fls_BlankCheckInternal and Fls_WriteInternal.
 *                           3. Added "volatile" where ever pBufferAddress
 *                              and pTempBufferAddress are typecasted to avoid
 *                              MISRA violation.
 *                           4. As per JIRA ID ARDAAAE-2060, added requirement
 *                              which is missed to trace in code.
 *                           5. Justification for misra warning 4:2984 is added.
 * V1.0.4:  01-Feb-2017    : Following changes are made:
 *                           1. Copyright information is updated.
 *                           2. As part of JIRA ID ARDAAAE-2053,elements of
 *                              structure "Fls_GstVarProperties" are renamed.
 *                           3. As part of JIRA ID ARDAAAE-2120,message tag for
 *                              Msg(4:0857) added in Fls_InitiateWriteJob API.
 *                           4. As per JIRA ID ARDAAAE-2340, Fls_ProcessCancel,
 *                              Fls_TimeOutCheckAndProcessing,
 *                              Fls_ProcessRead and Fls_ProcessJobResult
 *                              APIs are improved to report FLS_FCU_ERR_INTERNAL
 *                              in case of malfunctioning of Fls_FcuSwitchMode
 *                              API.
 *                           5. As per JIRA ID ARDAAAE-2289, Global variable
 *                              Fls_GblTimeOutMonitor is cleared in functions
 *                              Fls_ProcessJobResult,Fls_ProcessSuspend and
 *                              Fls_CancelInternal APIs. Also
 *                              Fls_TimeOutCheckAndProcessing is modified
 *                              regarding DET report in case of timeout error.
 *                           6. As part of JIRA ID ARDAAAE-2274
 *                              Message tag for Msg(4:0857) added in AUTOSAR
 *                              release version information and
 *                              Fls_PreFcuInitCheck API.
 * V1.0.5:  27-Apr-2017    : Following change is made:
 *                           Relocated end message tag 'END Msg(4:0857)-8' as
 *                           part of fixing static analysis warning.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0001 */
/* Included for macro definitions and API prototypes */
#include "Fls.h"
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Internal.h"
/* Included for Flash Wrapper Component specific types used within the module */
#include "Fls_Types.h"
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
/* Included for the macro declaration of supervisor mode(SV) write enabled
    Registers IMR */
#include "rh850_Types.h"
#include "Fls_Private_Fcu.h"
#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Fls.h"
#endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
/* MISRA Violation: START Msg(4:0857)-8 */
#define FLS_INTERNAL_C_AR_RELEASE_MAJOR_VERSION \
                                        FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_INTERNAL_C_AR_RELEASE_MINOR_VERSION \
                                        FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_INTERNAL_C_AR_RELEASE_REVISION_VERSION \
                                     FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_INTERNAL_C_SW_MAJOR_VERSION    FLS_SW_MAJOR_VERSION_VALUE
#define FLS_INTERNAL_C_SW_MINOR_VERSION    FLS_SW_MINOR_VERSION_VALUE
/* END Msg(4:0857)-8 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements FLS364 */
#if (FLS_INTERNAL_AR_RELEASE_MAJOR_VERSION != \
                                        FLS_INTERNAL_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls_Internal.c : Mismatch in Release Major Version"
#endif

#if (FLS_INTERNAL_AR_RELEASE_MINOR_VERSION != \
                                        FLS_INTERNAL_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls_Internal.c : Mismatch in Release Minor Version"
#endif

#if (FLS_INTERNAL_AR_RELEASE_REVISION_VERSION != \
                                     FLS_INTERNAL_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls_Internal.c : Mismatch in Release Revision Version"
#endif

#if (FLS_INTERNAL_SW_MAJOR_VERSION != FLS_INTERNAL_C_SW_MAJOR_VERSION)
  #error "Fls_Internal.c : Mismatch in Software Major Version"
#endif

#if (FLS_INTERNAL_SW_MINOR_VERSION != FLS_INTERNAL_C_SW_MINOR_VERSION)
  #error "Fls_Internal.c : Mismatch in Software Minor Version"
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
/* Message       : (4:0306) [I] Cast between a pointer to object and an       */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : The input addresses specified by the pointers are converted*/
/*                 to addresses for storing into the registers and for        */
/*                 reading purposes.                                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-2 and                           */
/*                 END Msg(4:0306)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing Pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This addresses pointed by the pointers needs to be         */
/*                 incremented after each cycle.                              */
/* Verification  : However, part of code is verified manually and it is not   */
/*                 having any impact.                                         */
/* Reference     : Look for START Msg(4:0488)-3 and                           */
/*                 END Msg(4:0488)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) The integer value 1 is being added or subtracted  */
/*                 from a pointer.                                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is to get the next address value by incrementing      */
/*                 the pointers.                                              */
/* Verification  : However, part of code is verified manually and it is not   */
/*                 having any impact.                                         */
/* Reference     : Look for START Msg(4:0489)-4 and                           */
/*                 END Msg(4:0489)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0310)-5 and                           */
/*                 END Msg(4:0310)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0311) Dangerous pointer cast results in loss of const   */
/*                 qualification.                                             */
/* Rule          : MISRA-C:2004 Rule 11.5                                     */
/* Justification : In this instance, it is verified that the address stored in*/
/*                 the global pointer is not a constant value address.        */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0311)-6 and                           */
/*                 END Msg(4:0311)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : The expression has no reliance on the effects of integral  */
/*                 promotion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-7 and                           */
/*                 END Msg(4:4397)-7 tags in the code.                        */
/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-8 and                           */
/*                 END Msg(4:0857)-8 tags in the code.                        */
/******************************************************************************/
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1290) An integer constant of 'essentially signed' type  */
/*                 is being converted to unsigned type on assignment.         */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : This is used for write verification of a particular        */
/*                 register so even if it is unsigned or signed type it has no*/
/*                 impact.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(4:1290)-9 and END Msg(4:1290)-9         */
/*                 tags in the code.                                          */
/******************************************************************************/
/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2984) This operation appears to be redundant because a  */
/*                 given constant value can always be used instead.           */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The result of the operation depends on the configuration   */
/*                 parameters, the value of the result may vary depending on  */
/*                 the configuration used.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-10 and                          */
/*                 END Msg(4:2984)-10 tags in the code.                       */
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
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-2 and                           */
/*                 END Msg(2:2824)-2  tags in the code.                       */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:0862) #include "MemMap.h" directive is redundant.       */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Justification : This is used for write verification of a particular        */
/*                 register so even if it is unsigned or signed type it has no*/
/*                 impact.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(2:3892)-4 and                           */
/*                 END Msg(2:3892)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter '' is never modified and so         */
/*                 it could be declared with the 'const' qualifier.           */
/*                 another type.                                              */
/*                 different integer type.                                    */
/* Justification : These variables cannot be declared with 'const' qualifier  */
/*                 since these variables are subjected to change in each      */
/*                 cycle of mainfunction call and boolean parameters don't    */
/*                 don't require 'const' qualifier.                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(2:3227)-5 and                           */
/*                 END Msg(2:3227)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-6 and                           */
/*                 END Msg(2:2016)-6 tags in the code.                        */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3204) This variable is only set once and so it could    */
/*                 be declared with the 'const' qualifier.                    */
/* Justification : These variables cannot be declared with 'const' qualifier  */
/*                 since these variables are subjected to change in each      */
/*                 cycle of Fls_MainFunction call.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any safety impact.                              */
/* Reference     : Look for START Msg(2:3204)-7 and                           */
/*                 END Msg(2:3204)-7 tags in the code.                        */
/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (3:3305) Pointer cast to stricter alignment.               */
/* Justification : In this instance, it is verified that the address stored in*/
/*                 the global pointer is not a constant value address.        */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(3:3305)-8 and                           */
/*                 END Msg(3:3305)-8 tags in the code.                        */
/******************************************************************************/

/* 9. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-9 and END Msg(2:3416)-9         */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 10. QAC Warning:                                                           */
/* Message       : (2:3206) The parameter 'LucServiceId' is not used in this  */
/*                 function.                                                  */
/* Justification : The parameter is used in this function when                */
/*                 FLS_DEV_ERROR_DETECT switch is enabled.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-10 and END Msg(2:3206)-10       */
/*                 tags in the code.                                          */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name             : Fls_PreFcuInitCheck
**
** Service ID                : NA
**
** Description               : This function checks there are no ECC errors
**                             during FLS initialisation
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
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
** Global Variables used     : Fls_GpConfigPtr(R)
**
** Function(s) invoked       : Dem_ReportErrorStatus
**
** Registers Used            : DFECCCTL,DFERRINT,DFTSTCTL,FRTEINT
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-8 */
#define FLS_START_SEC_PRIVATE_CODE
/* END Msg(4:0857)-8 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_016 */
/* Implements FLS_ESDD_UD_025 */
/* Implements FLS_ESDD_UD_068 */
/* Implements FLS352,FLS260,FLS006 */
/* Implements AR_PN0072_FSR_0052 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PreFcuInitCheck(void)
{
  /* Implements FLS_ESDD_UD_111 */
  /* local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, FLS_CONFIG_DATA) LpECCRegPtr;

  /* QAC Warning: START Msg(2:2814)-1 */
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;
  /* Initialise the local variable to hold the FCU Status */
  LenStatus = FLS_FCU_ERR_INTERNAL;
  if ((FLS_DFECCCTL_RESET_VAL == LpECCRegPtr->usDFECCCTL)&&
     (FLS_DFERRINT_RESET_VAL == LpECCRegPtr->ucDFERRINT)&&
     (FLS_DFTSTCTL_RESET_VAL == LpECCRegPtr->usDFTSTCTL))
  {
    /* END Msg(2:2814)-1 */
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* Check if any ECC errors are occured in FACI register */
    #if (FLS_FACI_ECC_CHECK == STD_ON)
    if (FLS_FACI_FRTEINT_RESET_VAL == FLS_FACIFRTEINT)
    #endif /* #if (FLS_FACI_ECC_CHECK == STD_ON) */
    /*  END Msg(4:0303)-1 */
    {
      LenStatus = FLS_FCU_OK;
    }
    #if (FLS_FACI_ECC_CHECK == STD_ON)
    else
    {
      /* No action required */
    }
    #endif /* #if (FLS_FACI_ECC_CHECK == STD_ON) */
  }
  else
  {
    /* No action required */
  }
  if (FLS_FCU_OK != LenStatus)
  {
    /* Implements FLS_ESDD_UD_132 */
    Dem_ReportErrorStatus(FLS_E_ECC_FAILED, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }
  return(LenStatus);
} /* End of function Fls_PreFcuInitCheck */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_InitiateEraseJob
**
** Service ID                : Asynchronous
**
** Description               : This function initiates the Erase Job for
**                             configured Data Flash Blocks.
**
** Sync/Async                : Synchronous
**
** Re-entrancy               : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Std_ReturnType
**
** Return parameter          : LenReturn
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.ulJobStartAddress(RW),
**                             Fls_GstVar.enDFStatus(W),Fls_GblFlashEnable(RW),
**                             Fls_GblTimeOutMonitor(W),Fls_GulTimeOutCounter(W)
**                             Fls_GpConfigPtr(R)
**
** Function(s) invoked       : Fls_FcuSwitchMode,Fls_FcuErasePreCheck,
**                             FLS_FCU_DF_ISSUE_BYTE_CMD,Fls_SetStartEndAddr
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-8 */
#define FLS_START_SEC_PRIVATE_CODE
/* END Msg(4:0857)-8 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_017 */
/* Implements FLS298_Conf,FLS327,FLS272 */
/* Implements AR_PN0072_FR_0051,AR_PN0072_FR_0059,AR_PN0072_FR_0023 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateEraseJob(void)
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LenReturn;
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Local variables to hold current start address */
  uint32 LulCurrentStartAddr;
  /* Local variables to hold current end address */
  uint32 LulCurrentEndAddr;
  LenReturn = E_NOT_OK;
  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
  /* Check if FCU is ready to initiate Erase Job */
  LenStatus = Fls_FcuErasePreCheck();

  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    /* Implements FLS_ESDD_UD_102 */
    Fls_GulTimeOutCounter = FLS_ERASE_TIMEOUT_COUNT;
    #else
    Fls_GulTimeOutCounter = FLS_ISR_TIMEOUT_COUNT;
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */
    /* Set Time Out Monitor Flag to TRUE */
    Fls_GblTimeOutMonitor = FLS_TRUE;
    #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    /* Switching to P/E Mode */
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);

    if (FLS_FCU_OK == LenStatus)
    {
      LulCurrentStartAddr = Fls_GstVar.ulJobStartAddress - \
                                                            FLS_DF_BASE_ADDRESS;
      LulCurrentEndAddr = ((LulCurrentStartAddr + \
                                     (uint32)FLS_FCU_BLOCK_SIZE) - FLS_FCU_ONE);
      Fls_SetStartEndAddr(LulCurrentStartAddr, LulCurrentEndAddr);
      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Issuing ERASE Command */
      FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_ERASE);
      /* Issuing Confirmation Command */
      FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_EXE);
      /*  END Msg(4:0303)-1 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      Fls_GstVar.ulJobStartAddress += (uint32)FLS_FCU_BLOCK_SIZE;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Set E_OK since Job Initiation Success */
      LenReturn = E_OK;
    }
    else
    {
      /*No Action required */
    }
  }
  else
  {
    /*No Action required */
  }

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return(LenReturn);
} /* End of function Fls_InitiateEraseJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_MainErase
**
** Service ID                : NA
**
** Description               : This function is called from Fls_MainFunction,
**                             when the command is Erase Operation.
**
** Sync/Async                : NA
**
** Reentrancy                : Non Re-entrant
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
** Global Variables Used     : Fls_GstVar.enGenCommand(W),
**                             Fls_GstVar.ulJobStartAddress(R),
**                             Fls_GstVar.ulJobEndAddress(R),
**                             Fls_GblJobSuspended(R),
**                             Fls_GblVerifyCompletedJob(W)
**
** Function(s) invoked       : Fls_FcuCheckJobStatus,Fls_InitiateBlankCheckJob,
**                             Fls_ProcessJobResult,Fls_InitiateEraseJob
**
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-8 */
#define FLS_START_SEC_PRIVATE_CODE
/* END Msg(4:0857)-8 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_018 */
/* Implements FLS104 */
/* Implements AR_PN0072_FR_0023,AR_PN0072_FR_0048 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainErase(void)
{

  /* Local variable to hold the return from Fls_InitiateBlankCheckJob
     Function */
  Std_ReturnType LenReturnValue;
  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;
  /* Get the Data Flash Status */
  LenStatus = Fls_FcuCheckJobStatus();

  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_SUSPEND_API == STD_ON)
    /* QAC Warning: START Msg(2:3416)-9 */
    if (FLS_FALSE == Fls_GblJobSuspended)
    {
    /* END Msg(2:3416)-9 */
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
      if (Fls_GstVar.ulJobStartAddress < Fls_GstVar.ulJobEndAddress)
      {
        /* For subsequent blocks of erase, invoke Fls_InitiateEraseJob */
        LenReturnValue = Fls_InitiateEraseJob();
        /* If Initiate Erase is failed due to Switch Mode Failure */
        if (E_NOT_OK == LenReturnValue)
        {
          /* Process Job Failure */
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        }
        else
        {
           /* No action Required */
        }
      }
      else
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Set the command to blank check */
        Fls_GstVar.enGenCommand = FLS_COMMAND_BLANKCHECK;
        Fls_GblVerifyCompletedJob = FLS_TRUE;
        /* Initiate Blank Check */
        LenReturnValue = Fls_InitiateBlankCheckJob();
        /* If Initiate Blank Check is failed due to Switch Mode Failure */
        if (E_NOT_OK == LenReturnValue)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        }
        else
        {
          /* No action Required */
        }
        #else
        Fls_ProcessJobResult(MEMIF_JOB_OK);
        #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      }
    #if (FLS_SUSPEND_API == STD_ON)
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
    #if (FLS_SUSPEND_API == STD_ON)
    else
    {
      /* No Action required */
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  }
  else if (FLS_FCU_ERR_ERASE == LenStatus)
  {
    /* Process Job Failure */
    Fls_ProcessJobResult(MEMIF_JOB_FAILED);
  }
  else
  {
    /* No action Required */
  }
} /* End of function Fls_MainErase */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_InitiateWriteJob
**
** Service ID                : NA
**
** Description               : This function initiates the write Job for
**                             each word.
**
** Sync/Async                : Asynchronous
**
** Re-entrancy               : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : Std_ReturnType
**
** Return parameter          : LenReturn
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.ulJobStartAddress(RW),
**                             Fls_GblTimeOutMonitor(W),
**                             Fls_GstVar.enDFStatus(W),Fls_GblFlashEnable(RW),
**                             Fls_GulTimeOutCounter(W),
**                             Fls_GstVar.pBufferAddress(W),Fls_GpConfigPtr(R)
**
** Function(s) invoked       : Fls_FcuSwitchMode,Fls_FcuWritePreCheck,
**                             FLS_FCU_DF_ISSUE_BYTE_CMD,FLS_DF_READ8,
**                             FLS_FCU_DF_ISSUE_WORD_CMD,Fls_SetStartEndAddr
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-8 */
#define FLS_START_SEC_PRIVATE_CODE
/* END Msg(4:0857)-8 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_019 */
/* Implements FLS_ESDD_UD_025 */
/* Implements FLS_ESDD_UD_068 */
/* Implements FLS331,FLS272 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023 */
/* Implements AR_PN0072_FR_0051,AR_PN0072_FR_0006,AR_PN0072_FR_0059 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateWriteJob(void)
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LenReturn;
  /* local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Local Variable to hold the Data */
  uint16 LusData;
  uint32 LulWriteCount;
  uint32 LulReadAddress;
  uint32 LulCurrentStartAddr;
  uint32 LulCurrentEndAddr;
  LenReturn = E_NOT_OK;
  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (FLS_FHVE_REGS == SUPPORTED) */
  /* Check if FCU is ready to initiate write Job */
  LenStatus = Fls_FcuWritePreCheck();
  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    /* Implements FLS_ESDD_UD_101 */
    Fls_GulTimeOutCounter = FLS_WRITE_TIMEOUT_COUNT;
    #else
    Fls_GulTimeOutCounter = FLS_ISR_TIMEOUT_COUNT;
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

    /* Set Time Out Monitor Flag to TRUE */
    Fls_GblTimeOutMonitor = FLS_TRUE;
    #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    /* Switching to P/E Mode */
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);

    if (FLS_FCU_OK == LenStatus)
    {
      LulCurrentStartAddr = Fls_GstVar.ulJobStartAddress - \
                                                           FLS_DF_BASE_ADDRESS;
      LulCurrentEndAddr = ((LulCurrentStartAddr + \
                                     (uint32)FLS_FCU_WRITE_SIZE) - FLS_FCU_ONE);
      Fls_SetStartEndAddr(LulCurrentStartAddr, LulCurrentEndAddr);
      /* MISRA Violation: START Msg(4:0303)-1 */
      /* MISRA Violation: START Msg(4:0306)-2 */
      LulReadAddress = ((uint32)Fls_GstVar.pBufferAddress);
      /* END Msg(4:0306)-2 */
      /* Issuing WRITE Command */
      FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_WRITE);
      /* Issue 0x02 as 4B Program Operation is performed */
      FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_TWO);
      for (LulWriteCount = (uint32)FLS_ZERO; LulWriteCount < (uint32)FLS_TWO;
                                                               LulWriteCount++)
      {
        /* assume reading of unaligned source buffer */
        LusData = ((uint16)(FLS_DF_READ8(LulReadAddress+FLS_FCU_ONE)));
        LusData <<= FLS_EIGHT;
        /* QAC Warning: START Msg(2:2814)-1 */
        LusData += ((uint16)(FLS_DF_READ8(LulReadAddress)));
        /* END Msg(2:2814)-1 */
        /* Write the formed Data in the Issue command area */
        FLS_FCU_DF_ISSUE_WORD_CMD(LusData);
        /* END Msg(4:0303)-1 */
        LulReadAddress += (uint32)FLS_TWO;
      }
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      Fls_GstVar.ulJobStartAddress+= (uint32)FLS_FCU_WRITE_SIZE;

      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-2 */
      Fls_GstVar.pBufferAddress+= FLS_FCU_WRITE_SIZE;
      /* END Msg(2:2824)-2 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* END Msg(4:0488)-3 */
      /* Issue D0 command to execute the write*/
      /* MISRA Violation: START Msg(4:0303)-1 */
      FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_EXE);
      /*  END Msg(4:0303)-1 */
      /* Set E_OK since Job Initiation Success */
      LenReturn = E_OK;
    }
    else
    {
      /*No Action required */
    }
  }
  else
  {
    /*No Action required */
  }

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return(LenReturn);
} /* End of function Fls_InitiateWriteJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_MainWrite
**
** Service ID                : NA
**
** Description               : This function is called from Fls_MainFunction,
**                             when the command is Write Operation.
**
** Sync/Async                : NA
**
** Reentrancy                : Non Re-entrant
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
** Global Variables Used     : Fls_GstVar.pBufferAddress(RW),
**                             Fls_GstVar.ulJobStartAddress(RW),
**                             Fls_GstVar.ulJobEndAddress(R),
**                             Fls_GstVar.ulCurrentLength(R)
**
** Function(s) invoked       : Fls_FcuCheckJobStatus,Fls_InitiateWriteJob,
**                             Fls_ProcessJobResult,Det_ReportError
**
** Registers Used            : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_021 */
/* Implements FLS225,FLS105,FLS056,FLS314,FLS261,FLS163,FLS161,FLS164 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023,AR_PN0072_FR_0048 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainWrite(void)
{
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  boolean LblWriteVerify;
  uint32 LulCurrentLength;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  /* Variable to return Job Initiation status */
  Std_ReturnType LenReturn;
  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  LblWriteVerify = FLS_TRUE;
  LulCurrentLength = FLS_FCU_ZERO;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  /* Get the DF Status */
  LenStatus = Fls_FcuCheckJobStatus();

  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_SUSPEND_API == STD_ON)
    /* QAC Warning: START Msg(2:3416)-9 */
    if ((FLS_FALSE == Fls_GblJobSuspended) ||
                         (FLS_COMMAND_WRITE != Fls_GstBackUpVar.enGenCommand))
    {
    /* END Msg(2:3416)-9 */
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
      if (Fls_GstVar.ulJobStartAddress < Fls_GstVar.ulJobEndAddress)
      {
        /* For issuing write command for remaining blocks */
        LenReturn = Fls_InitiateWriteJob();
        if (E_NOT_OK == LenReturn)
        {
          /* Process Job Failure */
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        }
        else
        {
          /*No Action required */
        }
      }
      else
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Disable relevant interrupts to protect this critical section */
        FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Restore the Start address of Write Job for verification */
        Fls_GstVar.ulJobStartAddress = Fls_GstVar.ulJobStartAddress -
                                                Fls_GstVar.ulCurrentLength;
        /* QAC Warning: START Msg(2:2824)-2 */
        /* MISRA Violation: START Msg(4:0488)-3 */
        Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress -
                                                Fls_GstVar.ulCurrentLength;
        /* END Msg(4:0488)-3 */
        /* END Msg(2:2824)-2 */
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enable relevant interrupts to exit this critical section */
        FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

        while (LulCurrentLength < Fls_GstVar.ulCurrentLength)
        {
          /* QAC Warning: START Msg(2:2814)-1 */
          /* MISRA Violation: START Msg(4:0306)-2 */
          /* Check if the target memory matches with the application buffer */
          if (*(Fls_GstVar.pBufferAddress) !=
                                  *((uint8 *)Fls_GstVar.ulJobStartAddress))
          /* END Msg(4:0306)-2 */
          /* END Msg(2:2814)-1 */
          {
            LulCurrentLength = Fls_GstVar.ulCurrentLength;
            /* Set LblWriteVerify as FLS_FALSE if comparison failed */
            LblWriteVerify = FLS_FALSE;
          }
          else /* Target memory value matches with the application buffer */
          {
            #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Disable relevant interrupts to protect this critical section */
            FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
            #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
            /* MISRA Violation: START Msg(4:0489)-4 */
            /* Increment the pointers to point to the next locations */
            Fls_GstVar.pBufferAddress++;
            /* END Msg(4:0489)-4 */
            Fls_GstVar.ulJobStartAddress++;
            #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enable relevant interrupts to exit this critical section */
            FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
            #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
            /*
             * Increment the number of bytes and the total number of bytes
             * processing in this cycle.
             */
            /* MISRA Violation: START Msg(4:2984)-10 */
            LulCurrentLength++;
            /* END Msg(4:2984)-10 */
          }
        }
        if (FLS_FALSE == LblWriteVerify)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
          /* Implements FLS_ESDD_UD_122 */
          /* Report error to DET */
          (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                              FLS_MAINFUNCTION_SID, FLS_E_VERIFY_WRITE_FAILED);
        }
        else
        #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
        {
          Fls_ProcessJobResult(MEMIF_JOB_OK);
        }
      }
    #if (FLS_SUSPEND_API == STD_ON)
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
    #if (FLS_SUSPEND_API == STD_ON)
    else
    {
      /* No Action required */
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  }
  else if (FLS_FCU_ERR_WRITE == LenStatus)
  {
    /* Process Job Failure */
    Fls_ProcessJobResult(MEMIF_JOB_FAILED);
  }
  else
  {
    /* No Action required */
  }

} /* End of function Fls_MainWrite */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ProcessRead
**
** Service ID               : NA
**
** Description              : This function processes the read command for
**                            data flash
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenJobResult
**
** Preconditions            : None
**
** Global Variable(s) Used  : Fls_GVar.ulCurrentLength(RW),
**                            Fls_GVar.ulRequestedLength(RW),
**                            Fls_GVar.ucOffset(R),
**                            Fls_GVar.ulReadAddress(RW),
**                            Fls_GVar.pTempBufferAddress(RW),
**                            Fls_GVar.ulSrcDestAddress(R),
**                            Fls_GstVar.enDFStatus(W),
**                            Fls_GVar.enReadType(W)
**
** Function(s) invoked      : Fls_PerformBlankCheckForReadOp,Fls_SetFHVE,
**                            Fls_PerformReadCheckECC,Fls_CopyToTargetBuff
**                            Fls_GetMaxReadBytes,Dem_ReportErrorStatus,
**                            Fls_ReportECCErrorToCbk
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_022 */
/* Implements AR_PN0072_FR_0023 */
/* Implements FLS106,FLS313,FLS352,FLS317,FLS260,FLS006,FLS313_Conf */
/* Implements FLS314_Conf*/
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessRead(void)
{
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  MemIf_JobResultType LenJobResult;
  /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;
  boolean LblLastRead;
  /* Local variable to hold the loop count */
  uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  uint32 LulReadAddress;
  LblLastRead = FLS_FALSE;
  LblSECError = FLS_FALSE;
  LenJobResult = MEMIF_JOB_OK;
  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulLoopCount = (LulMaxReadBytes / (uint32)FLS_FOUR);
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength =
                            Fls_GstVar.ulCurrentLength - LulMaxReadBytes;
    Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength -
                                  (LulMaxReadBytes - Fls_GstVar.ucOffset);
  }
  else
  {
    /* Calculate the length for remaining bytes */
    LulLoopCount = (Fls_GstVar.ulCurrentLength / (uint32)FLS_FOUR);
    /* Set the Last Read variable to True */
    LblLastRead = FLS_TRUE;
  }
  do
  {

    LulReadAddress = Fls_GstVar.ulReadAddress - FLS_DF_BASE_ADDRESS;

    LenStatus = Fls_PerformBlankCheckForReadOp((uint32)(LulReadAddress),
                                                  (uint16)(FLS_FCU_WRITE_SIZE));

    if (FLS_FCU_OK == LenStatus)
    {
      /* MISRA Violation: START Msg(4:0310)-5 */
      /* MISRA Violation: START Msg(4:0311)-6 */
      /* QAC Warning: START Msg(2:2814)-1 */
      /* QAC Warning: START Msg(3:3305)-8 */
      /* Writing the fixed pattern data to application buffer */
      *((volatile uint32 *) Fls_GstVar.pTempBufferAddress) = FLS_ERASED_VALUE;
      /* END Msg(3:3305)-8 */
      /* END Msg(2:2814)-1 */
      /* END Msg(4:0311)-6 */
      /* END Msg(4:0310)-5 */
    }
    else if (FLS_FCU_ERR_BLANKCHECK == LenStatus)
    {
      /* MISRA Violation: START Msg(4:0303)-1 */
      LenStatus =
            Fls_PerformReadCheckECC ((uint32)Fls_GstVar.ulReadAddress,
                             (uint32)Fls_GstVar.pTempBufferAddress);
      /* END Msg(4:0303)-1 */
      /* Check if the single bit error occurred from Data Flash read */
      if (FLS_FCU_ERR_ECC_SED == LenStatus)
      {
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulReadAddress;
       /* Set the local variable of SEC error occurrence status to true */
        LblSECError = FLS_TRUE;
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
    /* MISRA Violation: START Msg(4:0488)-3 */
    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress +
                                                    FLS_FCU_WRITE_SIZE;
    /* END Msg(4:0488)-3 */
    LulLoopCount--;
    Fls_GstVar.ulReadAddress = Fls_GstVar.ulReadAddress +
                                                    FLS_FCU_WRITE_SIZE;
  } while ((LulLoopCount > (uint32)FLS_ZERO) &&
          ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)));

  /* Read Process Completed*/
  /* Check the Request Status and set Job status to return */
  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Set Read Type to MISALIGNED since data is to be copied from Temporary
       Buffer to Target Buffer */
    Fls_GstVar.enReadType = FLS_MISALIGNED_READ;
    /* Copy Data from Temporary Buffer to Target Buffer */
    LenJobResult = Fls_CopyToTargetBuff(LblLastRead);
  }
  /* Report Job Failed if DED has occurred */
  else if (FLS_FCU_ERR_ECC_DED == LenStatus)
  {
    /* Implements FLS_ESDD_UD_130 */
    /* Report error to DEM that read job failed due to double bit error */
    Dem_ReportErrorStatus(FLS_E_READ_FAILED_DED, DEM_EVENT_STATUS_FAILED);
    /* Set Job Status as failed */
    LenJobResult = MEMIF_JOB_FAILED;
  }
  else if (FLS_FCU_ERR_INTERNAL == LenStatus)
  {
    /* Implements FLS_ESDD_UD_128 */
    /* Report error to DEM that read job failed due to internal hardware
    error during blank check operation */
    Dem_ReportErrorStatus(FLS_E_READ_FAILED, DEM_EVENT_STATUS_FAILED);
    /* Set Job Status as failed */
    LenJobResult = MEMIF_JOB_FAILED;
  }
  else
  {
    /* No action Required */
  }
  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);

  Fls_GstVar.enDFStatus = LenStatus;

  return(LenJobResult);
} /* End of function Fls_ProcessRead */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_MainRead
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Read Operation.
**
** Sync/Async               : NA
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
** Global Variable(s) Used  : Fls_GstVar.enGenCommand(W),
**                            Fls_GenJobResult(W) and Fls_GenState(W)
**
** Function(s) invoked      : Fls_ProcessRead,Fls_CallJobNotification,
**                            Fls_RestoreIntReq
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_023 */
/* Implements FLS106,FLS346 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
FUNC(void, FLS_PUBLIC_CODE)Fls_MainRead(void)
{
  /* Local variable to hold the return from ProcessRead Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Read Process Function */
  LenInternalJobResult = Fls_ProcessRead();
  /* Check the internal job result */
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the driver state to idle */
    Fls_GenState = MEMIF_IDLE;
    /* Set the job result to internal job status */
    Fls_GenJobResult = LenInternalJobResult;
    #if (FLS_INTERRUPT_MODE == STD_ON)
    Fls_RestoreIntReq();
    #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification();
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  }
  else
  {
    /* No Action required */
  }
} /* End of function Fls_MainRead */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_PerformBlankCheckForReadOp
**
** Service ID               : NA
**
** Description              : This function performs the blank check operation
**                            when the command is FLS_COMMAND_READ.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulStartAddr, Luscount
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_FcuStatusType
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R),Fls_GblFlashEnable(RW),
**                            Fls_GstVar.enGenCommand(W),Fls_GenState(W),
**                            Fls_GenJobResult(W)
**
** Function(s) invoked      : Fls_FcuSwitchMode,FLS_FCU_DF_ISSUE_BYTE_CMD,
**                            Fls_ProcessCancel,Fls_CallJobNotification,
**                            Det_ReportError,Fls_SetFHVE,
**                            Fls_FcuBlankCheckResult
**
** Registers Used           : FSADDR,FEADDR,FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_076 */
/* Implements FLS361,FLS346,FLS359,FLS360,FLS362,FLS261,FLS163,FLS161,FLS164 */
/* Implements AR_PN0072_FR_0051,AR_PN0072_FR_0022,AR_PN0072_FR_0059 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
/* Implements AR_PN0072_FR_0059,AR_PN0072_FR_0023 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformBlankCheckForReadOp
(const uint32 LulStartAddr, const uint16 Luscount)
{
  Fls_FcuStatusType LenStatus;
  uint32 LulEndAddr;
  volatile uint32 LulRegValue;

  #if (FLS_TIMEOUT_MONITORING == STD_ON)
  uint32 LulBCLoopCount;
  #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
  /* Implements FLS_ESDD_UD_114 */
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  LulEndAddr = ((LulStartAddr + (uint32)Luscount) - FLS_FCU_ONE);
  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);
  if (FLS_FCU_OK == LenStatus)
  {
    /* QAC Warning: START Msg(2:2814)-1 */
    /* Setting BlankCheck Start and End Address */
    FLS_REG_WRITE(LpFACIRegPtr->ulFSADDR, LulStartAddr)
    /* END Msg(2:2814)-1 */
    /* For write verification */
    /* Implements FLS_ESDD_UD_108 */
    /* MISRA Violation: START Msg(4:1290)-9 */
    FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFSADDR, LulStartAddr, \
                      FLS_32BIT_MASK_VAL, FLS_PERFORMBLANKCHECKFORREADOP_API_ID)
    /* END Msg(4:1290)-9 */
    FLS_REG_WRITE(LpFACIRegPtr->ulFEADDR,(LulEndAddr & FEADDR_REG_MASK_VAL))
    /* For write verification */
    /* Implements FLS_ESDD_UD_108 */
    /* MISRA Violation: START Msg(4:1290)-9 */
    FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFEADDR,
    (LulEndAddr & FEADDR_REG_MASK_VAL), FEADDR_REG_MASK_VAL,
                                          FLS_PERFORMBLANKCHECKFORREADOP_API_ID)
    /* END Msg(4:1290)-9 */
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* Issuing Blank Check Command */
    FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_BLANKCHECK);
    /* Issuing Confirmation Command */
    FLS_FCU_DF_ISSUE_BYTE_CMD(FLS_FACI_CMD_EXE);
    /* END Msg(4:0303)-1 */

    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    LulBCLoopCount = (uint32)FLS_FCU_BLANKCHECK_COUNT;
    #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    do
    {
      LulRegValue = LpFACIRegPtr->ulFSTATR;
      #if (FLS_TIMEOUT_MONITORING == STD_ON)
      LulBCLoopCount--;
      #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    }
    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    while((LulBCLoopCount > (uint32)FLS_FCU_ZERO) &&
         (FLS_FCU_REGBIT_FSTATR_FRDY != (FLS_FCU_REGBIT_FSTATR_FRDY &
                                                                 LulRegValue)));
    #else
    /* Start : FLS_UT_001*/
    while (FLS_FCU_REGBIT_FSTATR_FRDY != (FLS_FCU_REGBIT_FSTATR_FRDY &
                                                                  LulRegValue));
    /* End : FLS_UT_001*/
    #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    if ((uint16)FLS_FCU_ZERO == (uint16)LulBCLoopCount)
    {
      Fls_ProcessCancel();
      /* Set the command as None */
      Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
      /* Set the driver state to idle */
      Fls_GenState = MEMIF_IDLE;
      /* Set the Job result to failed */
      Fls_GenJobResult = MEMIF_JOB_FAILED;
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Implements FLS_ESDD_UD_123 */
      /* Report FLS_E_TIMEOUT to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,FLS_MAINFUNCTION_SID,
                                                                 FLS_E_TIMEOUT);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
      Fls_CallJobNotification();
      #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
    }
    else
    #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
    {
      /*No action Required */
    } /* End of ((uint16)FLS_FCU_ZERO == LulBCLoopCount) */

   LenStatus = Fls_FcuBlankCheckResult();
   /* Switching to User Mode */
   (void)Fls_FcuSwitchMode(FLS_FCU_MODE_USER);
  } /* End of Switch Mode */
  else
  {
    /*No action Required */
  }
  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_TRUE == Fls_GblFlashEnable)
  {
    /* Enable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
    Fls_GblFlashEnable = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
  return(LenStatus);

} /* End of function Fls_PerformBlankCheckForReadOp */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_PerformReadCheckECC
**
** Service ID               : NA
**
** Description              : This function reads data from the Data Flash.
**                            Doing so, it disables the ECC error interrupts to
**                            avoid interrupt generation on accepted ECC errors
**                            when reading e.g. blank or partly written Flash
**                            words.Instead,the error and fail address is
**                            returned to the calling function.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulDestAddr, LulSrcAddr
**
** InOut Parameters         : NA
**
** Output Parameters        : Fls_FcuStatusType
**
** Return parameter         : LenStatus
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R)
**
** Function(s) invoked      : FLS_DF_READ32,FLS_DF_READ32,FLS_DF_WRITE32
**
** Registers Used           : DFERSTC,DFERRINT,DFERSTR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
  /* QAC Warning: START Msg(2:3227)-5 */
  /* Implements FLS_ESDD_UD_024 */
  /* Implements EAAR_PN0034_FR_0013,EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformReadCheckECC
(uint32 LulSrcAddr, uint32 LulDestAddr)
{
  /* END Msg(2:3227)-5 */
  /* Local variable to hold the read data */
  uint32 LulData;
  uint8  LucRegValue;
  uint32 LulErrorRegValue;
  /*Local variable to hold the FCU status*/
  Fls_FcuStatusType LenStatus = FLS_FCU_OK;
  /* Implements FLS_ESDD_UD_111 */
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, FLS_CONFIG_DATA) LpECCRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;
  /* END Msg(2:2814)-1 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
   /* Clear ECC errors */
  /* QAC Warning: START Msg(2:2814)-1 */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC,FLS_FCU_REGBIT_DFERSTC_ERRCLR)
  /* END Msg(2:2814)-1 */
  /* Implements FLS_ESDD_UD_106 */
  /* Implements FLS_ESDD_UD_131 */
  /* Implements FLS_ESDD_UD_109 */
  /* QAC Warning: START Msg(2:3892)-4 */
  /* MISRA Warning: START Msg(4:1290)-9 */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ulDFERSTR,              \
              FLS_FCU_REGVAL_DFERSTR_NOERR, FLS_08BIT_MASK_VAL,     \
              FLS_PERFORMREADCHECKECC_API_ID)
  /* END Msg(4:1290)-9 */
  /* END Msg(2:3892)-4 */
  /* BackUp and Clear ECC Interrupts */
  LucRegValue = LpECCRegPtr->ucDFERRINT;
  FLS_REG_WRITE(LpECCRegPtr->ucDFERRINT,FLS_FCU_REGVAL_DFERRINT_NOINT)
  /* Implements FLS_ESDD_UD_106 */
  /* Implements FLS_ESDD_UD_131 */
  /* Implements FLS_ESDD_UD_109 */
  /* For write verification */
  /* MISRA Warning: START Msg(4:1290)-9 */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ucDFERRINT, \
                        FLS_FCU_REGVAL_DFERRINT_NOINT, DFERRINT_REG_MASK_VAL, \
                        FLS_PERFORMREADCHECKECC_API_ID)
  /* END Msg(4:1290)-9 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* QAC Warning: START Msg(2:2814)-1 */
  /* Read 32-Bit Data from source address */
  LulData = FLS_DF_READ32(LulSrcAddr);
  /* Write the Data into the Destination Buffer Address */
  FLS_DF_WRITE32(LulDestAddr,LulData);
  /* END Msg(2:2814)-1 */
  /* END Msg(4:0303)-1 */
  LulErrorRegValue = LpECCRegPtr->ulDFERSTR;
  if (FLS_FCU_REGVAL_DFERSTR_NOERR != LulErrorRegValue)
  {
    if (FLS_FCU_REGBIT_DFERSTR_DEDF == (FLS_FCU_REGBIT_DFERSTR_DEDF &
                                                  LulErrorRegValue))
    {
      LenStatus = FLS_FCU_ERR_ECC_DED;
    }
    else
    {
      LenStatus = FLS_FCU_ERR_ECC_SED;
    }
  }
  else
  {
    /* No Action required */
  }

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Restore the Error Interrupt Register value */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERRINT,LucRegValue)
  /* For write verification */
  /* MISRA Violation: START Msg(4:1290)-9 */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ucDFERRINT, LucRegValue, \
         DFERRINT_REG_MASK_VAL, FLS_PERFORMREADCHECKECC_API_ID)
  /* END Msg(4:1290)-9 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  return(LenStatus);

} /* End of function Fls_PerformReadCheckECC */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_091 */
#if (FLS_COMPARE_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_MainCompare
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Compare Operation.
**
** Sync/Async               : NA
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
** Global Variables Used    : Fls_GstVar.enGenCommand(W),Fls_GenJobResult(W)
**                            and Fls_GenState(W)
**
** Function(s) invoked      : Fls_ProcessCompare,Fls_CallJobNotification
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_026 */
/* Implements FLS243 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainCompare(void)
{
  /* Local variable to hold the return from ProcessCompare Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Compare Process Function */
  LenInternalJobResult = Fls_ProcessCompare();
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the job result to internal job result */
    Fls_GenJobResult = LenInternalJobResult;
    /* Set the driver state to idle */
    Fls_GenState = MEMIF_IDLE;
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification();
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  }
  else
  {
    /* No Action required */
  }

} /* End of function Fls_MainCompare */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_CompareWithTargetBuff
**
** Service ID               : NA
**
** Description              : This function is used to compare data between
**                            Temporary Buffer and Target Buffer.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LblLastRead
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ucOffset(RW),
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.pBufferAddress(RW),
**                            Fls_GstVar.ulRequestedLength(R)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Dem_ReportErrorStatus
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
  /* QAC Warning: START Msg(2:3227)-5 */
/* Implements FLS_ESDD_UD_027 */
/* Implements FLS154,FLS200,FLS352,FLS318,FLS260,FLS006 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CompareWithTargetBuff
(boolean LblLastRead)
{
  /* END Msg(2:3227)-5 */
  /* Local variable to store the processed bytes count */
  uint32 LulBytesProcessed;
  /* Local variable to hold the loop count */
  uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenReturnValue;
  /* Local variable to hold the compare operation status */
  boolean LblCompareStatus;
  LblCompareStatus = E_OK;
  LulLoopCount = (uint32)FLS_ZERO;
  if (FLS_TRUE != LblLastRead)
  {
    /* Get the Maximum Read bytes */
    LulMaxReadBytes = Fls_GetMaxReadBytes();
    /* Set the bytes to be processed to maximum read bytes per cycle */
    LulBytesProcessed = (LulMaxReadBytes - Fls_GstVar.ucOffset);
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-2 */
    /* Reset the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress -
                                                       LulBytesProcessed);
    /* END Msg(2:2824)-2 */
    /* END Msg(4:0488)-3 */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    /* Set the bytes to be processed to remaining read bytes */
    LulBytesProcessed = Fls_GstVar.ulCurrentLength;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* Reset the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress +
                                 Fls_GstVar.ucOffset) - LulBytesProcessed;
    /* END Msg(4:0488)-3 */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    LulBytesProcessed = Fls_GstVar.ulRequestedLength;
  }
  /* Loop until the number of bytes read in one cycle */
  while (LulLoopCount < LulBytesProcessed)
  {
   /* QAC Warning: START Msg(2:2814)-1 */
    /* Check if read data and buffer data are same */
    if (*(Fls_GstVar.pBufferAddress) !=
                                *(Fls_GstVar.pTempBufferAddress))
    {
      /* END Msg(2:2814)-1 */
      /* Set the loop count to maximum number of bytes processed */
      LulLoopCount = LulBytesProcessed;
      LblCompareStatus = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
    /* Increment the loop count, buffer address and temp buffer address */
    LulLoopCount++;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0489)-4 */
    Fls_GstVar.pBufferAddress++;
    Fls_GstVar.pTempBufferAddress++;
    /* END Msg(4:0489)-4 */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* End of while */
  if (E_OK == LblCompareStatus)
  {
    if (FLS_TRUE != LblLastRead)
    {
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0488)-3 */
      /* Reset the buffer pointer by number of bytes it processes */
      Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress -
                            (Fls_GstVar.ucOffset + LulBytesProcessed);
      /* END Msg(4:0488)-3 */
      /* Set the global variable offset to zero */
      Fls_GstVar.ucOffset = FLS_ZERO;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else /* Compare done successfully  */
    {
      /* Set the job result */
      LenReturnValue = MEMIF_JOB_OK;
    }
  }
  else /* compare mismatches */
  {
    /* Implements FLS_ESDD_UD_129 */
    /* Report error to DEM that compare job has failed */
    Dem_ReportErrorStatus(FLS_E_COMPARE_FAILED, DEM_EVENT_STATUS_FAILED);
    /* Set the job result to Block Inconsistent */
    LenReturnValue = MEMIF_BLOCK_INCONSISTENT;
  }

  return(LenReturnValue);
} /* End of function Fls_CompareWithTargetBuff */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ProcessCompare
**
** Service ID               : NA
**
** Description              : This function processes the compare command for
**                            data flash.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenJobResult
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulCurrentLength(RW),
**                            Fls_GstVar.ulReadAddress(RW),
**                            Fls_GstVar.ucOffset(R),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulRequestedLength(RW)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Fls_PerformReadCheckECC,
**                            Fls_CompareWithTargetBuff,Dem_ReportErrorStatus,
**                            Fls_ReportECCErrorToCbk
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_028 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023 */
/* Implements FLS352,FLS260 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessCompare(void)
{
  /* Local variable to hold the status of the FCU status */
  Fls_FcuStatusType LenStatus;
  /* Local variable to denote if this is last read cycle */
  boolean LblLastRead;
  /* Local variable to hold the loop count */
  uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenJobResult;
  /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;
  LblLastRead = FLS_FALSE;
  LblSECError = FLS_FALSE;
  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulLoopCount = (LulMaxReadBytes / (uint32)FLS_FOUR);
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength =
                            Fls_GstVar.ulCurrentLength - LulMaxReadBytes;

    Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength -
                                   (LulMaxReadBytes - Fls_GstVar.ucOffset);
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    /* Calculate the length for remaining bytes */
    LulLoopCount = (Fls_GstVar.ulCurrentLength / (uint32)FLS_FOUR);

    /* Set the Last Read variable to False */
    LblLastRead = FLS_TRUE;
  }
  do
  {
    /* MISRA Violation: START Msg(4:0303)-1 */
    LenStatus = Fls_PerformReadCheckECC((uint32)Fls_GstVar.ulReadAddress,
                             (uint32)Fls_GstVar.pTempBufferAddress);
    /* END Msg(4:0303)-1 */
    /* Check if the single bit error occurred from Data Flash read */
    if (FLS_FCU_ERR_ECC_SED == LenStatus)
    {
      /* Global variable to hold the ECC error occurrence address */
      Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulReadAddress;

      /* Set the local variable of SEC error occurrence status to true */
      LblSECError = FLS_TRUE;
    }
    else
    {
      /* No action required */
    }
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* QAC Warning: START Msg(2:2824)-2 */
    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress +
                                                            FLS_FCU_WRITE_SIZE;
    /* END Msg(2:2824)-2 */
    /* END Msg(4:0488)-3 */
    Fls_GstVar.ulReadAddress = Fls_GstVar.ulReadAddress +
                                                            FLS_FCU_WRITE_SIZE;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    LulLoopCount--;
  } while ((LulLoopCount > (uint32)FLS_ZERO) &&
          ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)));

  /* Check the Request Status and set Job status to return */
  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Compare the Data Read with the Target Buffer data */
    LenJobResult = Fls_CompareWithTargetBuff(LblLastRead);
  }
  /* Report Job Failed if DED has occurred */
  else
  {
    /* Implements FLS_ESDD_UD_130 */
    /* Report error to DEM that read job failed due to double bit error */
    Dem_ReportErrorStatus(FLS_E_READ_FAILED_DED, DEM_EVENT_STATUS_FAILED);
    /* Set Job Status as failed */
    LenJobResult = MEMIF_JOB_FAILED;
  }

  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);
  /* Return the Job status */
  return(LenJobResult);
} /* End of function Fls_ProcessCompare */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_COMPARE_API == STD_ON) */

/* Implements FLS_ESDD_UD_098 */
#if (FLS_READIMMEDIATE_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_MainReadImm
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is ReadImmediate Operation.
**
** Sync/Async               : NA
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
** Global Variables Used    : Fls_GstVar.enGenCommand(W),Fls_GenJobResult(W),
**                            and Fls_GenState(W)
**
** Function(s) invoked      : Fls_ProcessReadImm,Fls_CallJobNotification
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_029 */
/* Implements FLS346 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainReadImm(void)
{
  /* Local variable to hold the return from ProcessReadImm Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Read Immediate Process Function */
  LenInternalJobResult = Fls_ProcessReadImm();
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the job result to internal job status */
    Fls_GenJobResult = LenInternalJobResult;
    /* Set the driver state to idle */
    Fls_GenState = MEMIF_IDLE;
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification();
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  }
  else
  {
    /* No Action required */
  }

} /* End of function Fls_MainReadImm */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ProcessReadImm
**
** Service ID               : NA
**
** Description              : This function processes the read immediate
**                            command for data flash.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulCurrentLength(RW),
**                            Fls_GstVar.ulReadAddress(RW),
**                            Fls_GstVar.enReadType(R),
**                            Fls_GstVar.pBufferAddress(RW)
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulRequestedLength(RW),
**                            Fls_GstVar.ucOffset(RW),
**                            Fls_GstVar.ulSrcDestAddress(RW),
**                            Fls_GpConfigPtr(R)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Fls_FcuDataCopy,
**                            Fls_FcuOffsetDataCopy,Fls_FastReadCheckECC
**
** Registers Used           : DFERRINT,DFERSTC,DFERSTR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_030 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* Implements FLS281_Conf */
/* Implements AR_PN0072_FR_0023 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessReadImm(void)
{
  /* Local variable to hold internal Job Status */
  MemIf_JobResultType LenReturnValue;
  /* Local variable to hold the length */
  uint32 LulDFLength;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to hold the read start and end addresses */
  uint32 LulReadStartAddress;
  uint32 LulReadEndAddress;
  /* Local variable to hold the backup of ECC error interrupt value */
  uint8 LucDFERRInt;
  uint8 LucLenOffset;
  /* Local variable to hold the value of Data Flash error status register */
  uint32 LulErrorStatus;
  /* Local variable to denote if this is last read cycle */
  boolean LblLastRead;
  /* Implements FLS_ESDD_UD_111 */
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, FLS_CONFIG_DATA) LpECCRegPtr;
  LucLenOffset = FLS_ZERO;
  LblLastRead = FLS_FALSE;
  LulErrorStatus = (uint32)FLS_ZERO;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;
  /* END Msg(2:2814)-1 */
  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulDFLength = LulMaxReadBytes;
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength = Fls_GstVar.ulCurrentLength -
                                                             LulMaxReadBytes;

    if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
    {
      Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength -
                                   (LulMaxReadBytes - Fls_GstVar.ucOffset);
    }
    else
    {
      /* No Action Required */
    }
  }
  else
  {
    if (FLS_MISALIGNED_READ != Fls_GstVar.enReadType)
    {
      /* QAC Warning: START Msg(2:3892)-4 */
      LucLenOffset = (uint8)((uint8)Fls_GstVar.ulCurrentLength &
                                            (FLS_PAGE_SIZE - FLS_ONE));
      /* END Msg(2:3892)-4 */
      /* Calculate the length for remaining bytes */
      LulDFLength = Fls_GstVar.ulCurrentLength - LucLenOffset;
    }
    else
    {
      /* Calculate the length for remaining bytes */
      LulDFLength = Fls_GstVar.ulCurrentLength;
    }
    LblLastRead = FLS_TRUE;
  }
  /* Get the read start and end addresses */
  LulReadStartAddress = Fls_GstVar.ulReadAddress;
  LulReadEndAddress = (LulReadStartAddress + LulDFLength) - (uint32)FLS_ONE;
  /* Clear ECC errors */
  /* QAC Warning: START Msg(2:2814)-1 */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC,FLS_FCU_REGBIT_DFERSTC_ERRCLR)
  /* END Msg(2:2814)-1 */
  /* QAC Warning: START Msg(2:3892)-4 */
  /* MISRA Violation: START Msg(4:1290)-9 */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ulDFERSTR, \
    FLS_FCU_REGVAL_DFERSTR_NOERR, FLS_08BIT_MASK_VAL, FLS_PROCESSREADIMM_API_ID)
  /* END Msg(4:1290)-9 */
  /* END Msg(2:3892)-4 */
  /* BackUp and Clear ECC Interrupts */
  LucDFERRInt = LpECCRegPtr->ucDFERRINT;
  FLS_REG_WRITE(LpECCRegPtr->ucDFERRINT,FLS_FCU_REGVAL_DFERRINT_NOINT)
  /* MISRA Violation: START Msg(4:1290)-9 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ucDFERRINT,                 \
                FLS_FCU_REGVAL_DFERRINT_NOINT, DFERRINT_REG_MASK_VAL,   \
                FLS_PROCESSREADIMM_API_ID)
  /* END Msg(4:1290)-9 */
  /* Implements FLS_ESDD_UD_140 */
  if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
  {
    do
    {
      /* MISRA Violation: START Msg(4:0303)-1 */
      LulErrorStatus = Fls_FcuDataCopy(LulReadStartAddress,
                                    (uint32)Fls_GstVar.pTempBufferAddress);
      /* END Msg(4:0303)-1 */
      /* Incrementing the address pointers */
      LulReadStartAddress = LulReadStartAddress + FLS_FCU_WRITE_SIZE;
      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-2 */
      Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress +
                                                          FLS_FCU_WRITE_SIZE;
      /* END Msg(2:2824)-2 */
      /* END Msg(4:0488)-3 */
      /* Check for the read address reached the end address */
    } while (LulReadStartAddress <= LulReadEndAddress);

    /* Global variable to hold the ECC error occurrence address */
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress -
                                                            FLS_FCU_WRITE_SIZE;
  }
  else
  {
    /* Check for the read address reached the end address */
    while (LulReadStartAddress < LulReadEndAddress)
    {
      /* MISRA Violation: START Msg(4:0303)-1 */
      LulErrorStatus = Fls_FcuDataCopy(LulReadStartAddress,
                                    (uint32)Fls_GstVar.pBufferAddress);
      /* END Msg(4:0303)-1 */
      /* MISRA Violation: START Msg(4:0488)-3 */
      /* QAC Warning: START Msg(2:2824)-2 */
      Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress +
                                                           FLS_FCU_WRITE_SIZE;
      /* END Msg(2:2824)-2 */
      /* END Msg(4:0488)-3 */
      LulReadStartAddress = LulReadStartAddress + FLS_FCU_WRITE_SIZE;
    }
    /* MISRA Violation: START Msg(4:0303)-1 */
    /* Copying Offset Data */
    Fls_FcuOffsetDataCopy(LulReadStartAddress,(uint32)Fls_GstVar.pBufferAddress,
                                                              LucLenOffset);
    /* END Msg(4:0303)-1 */
    /* MISRA Violation: START Msg(4:0488)-3 */
    Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress + LucLenOffset;
    /* END Msg(4:0488)-3 */
    LulReadStartAddress = LulReadStartAddress + LucLenOffset;
  }

  /* Get the updated read start address value to the global variable  */
  Fls_GstVar.ulReadAddress = LulReadStartAddress;
  if (FLS_TRUE != LblLastRead)
  {
    /* Set the global variable offset to zero */
    Fls_GstVar.ucOffset = FLS_ZERO;
  }
  else
  {
    /* No Action required */
  }
  LenReturnValue = Fls_FastReadCheckECC(LulErrorStatus,LblLastRead);
    /* Restore the Error Interrupt Register value */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERRINT,LucDFERRInt)
  /* MISRA Violation: START Msg(4:1290)-9 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpECCRegPtr->ucDFERRINT, \
              LucDFERRInt, DFERRINT_REG_MASK_VAL, FLS_PROCESSREADIMM_API_ID)
  /* END Msg(4:1290)-9 */
  /* Return the Job status */
  return(LenReturnValue);
} /* End of function Fls_ProcessReadImm */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ReadMisAlignHandler
**
** Service ID               : NA
**
** Description              : This function is used to adjust the Read Source
**                            Address and length when the Source Address,
**                            Target Address or Length values are not aligned.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress,TargetAddress,Length
**
** InOut Parameters         : None
**
** Output Parameters        : Fls_LengthType
**
** Return parameter         : Length
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enReadType(RW),
**                            Fls_GstVar.ucOffset(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
 /* Implements FLS_ESDD_UD_031 */
 /* Implements FLS_ESDD_UD_084 */
 /* Implements AR_PN0072_FR_0023 */
 /* Implements EAAR_PN0034_FR_0013 */
 /* Implements FLS281_Conf,FLS282_Conf */
FUNC(Fls_LengthType, FLS_PRIVATE_CODE) Fls_ReadMisAlignHandler
(const uint32 SourceAddress, const uint32 TargetAddress,
 Fls_LengthType Length)
{
  /* QAC Warning: START Msg(2:3204)-7 */
  /* Local variable to hold offset of source address when not word-aligned */
  uint8 LucSrcOffset;
  /* Local variable to hold offset of target address when not word-aligned */
  uint8 LucTgtOffset;
  /* END Msg(2:3204)-7 */
  /* Get the offset value by masking the source address with page size */
  LucSrcOffset = (uint8)(SourceAddress &(FLS_PAGE_SIZE - FLS_ONE));
  /* Get offset value by masking the target address with page size */
  LucTgtOffset = (uint8)(TargetAddress & (FLS_PAGE_SIZE - FLS_ONE));
  /* Set the Read Type to FLS_MISALIGNED_READ */
  Fls_GstVar.enReadType = FLS_MISALIGNED_READ;
  /* Check whether offset value is not zero */
  if (FLS_ZERO != LucSrcOffset)
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Set the global variable with length of bytes to be processed */
    Fls_GstVar.ulRequestedLength = Length;
    /*
     * Round off the source address value to the page boundary by
     * subtracting the offset value.
     */
    Fls_GstVar.ulReadAddress = SourceAddress - LucSrcOffset;
    /* Increment the length with offset value */
    Length = Length + LucSrcOffset;
    Fls_GstVar.ucOffset = LucSrcOffset;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  /* TargetAddress is not aligned */
  else if (FLS_ZERO != LucTgtOffset)
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Set the global variable with length of bytes to be processed */
    Fls_GstVar.ulRequestedLength = Length;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    /* Set the Read Type to FLS_ALIGNED_READ */
    Fls_GstVar.enReadType = FLS_ALIGNED_READ;
  }
  /* Implements FLS_ESDD_UD_140 */
  /* Check whether length is not aligned to the page boundary */
  if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0310)-5 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* Assign Temporary Buffer Address */
    Fls_GstVar.pTempBufferAddress = (const uint8 *)&Fls_GulTempBuffer[FLS_ZERO];
    /* END Msg(2:3892)-4 */
    /* END Msg(4:0310)-5 */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Implements FLS_ESDD_UD_088 */
    if ((uint32)FLS_ZERO != (Length & ((uint32)FLS_PAGE_SIZE-(uint32)FLS_ONE)))
    {
      /* Round off the length value to the page boundary */
      Length = Length + ((uint32)FLS_PAGE_SIZE - (Length &
                                    ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE)));
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
  return(Length);
} /* End of function Fls_ReadMisAlignHandler */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

/*******************************************************************************
** Function Name            : Fls_GetMaxReadBytes
**
** Service ID               : NA
**
** Description              : This function returns the maximum number of read
**                            bytes based on the current Driver Mode.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : Mode
**
** InOut Parameters         : None
**
** Output Parameters        : Maximum Read bytes
**
** Return parameter         : LulMaxReadBytes
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenCurrentMode(R),Fls_GpConfigPtr(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_032 */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_GetMaxReadBytes(void)
{
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Check if the FAST Mode is Set */
  /* QAC Warning: START Msg(2:2814)-1 */
  if (MEMIF_MODE_FAST == Fls_GenCurrentMode)
  {
    LulMaxReadBytes = Fls_GpConfigPtr->ulFlsFastModeMaxReadBytes;
  }
  else
  {
    LulMaxReadBytes = Fls_GpConfigPtr->ulFlsSlowModeMaxReadBytes;
  }
  /* END Msg(2:2814)-1 */
  return(LulMaxReadBytes);
} /* End of function Fls_GetMaxReadBytes */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ReportECCErrorToCbk
**
** Service ID               : NA
**
** Description              : This function checks and reports ECC Error.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LenStatus, LblSECError
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulSrcDestAddress(RW),
**                            Fls_GstVar.ulReadAddress(R),
**                            Fls_GpConfigPtr(RW)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
  /* QAC Warning: START Msg(2:3227)-5 */
/* Implements FLS_ESDD_UD_033 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ReportECCErrorToCbk
       (Fls_FcuStatusType LenStatus, boolean LblSECError)
{
  /* END Msg(2:3227)-5 */
  if (FLS_FCU_ERR_ECC_DED == LenStatus)
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Global variable to hold the ECC error occurrence address */
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulReadAddress -
                                                           FLS_FCU_WRITE_SIZE;
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress -
                                                        FLS_DF_BASE_ADDRESS;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* QAC Warning: START Msg(2:2814)-1 */
    /* Check for ECC DED notification pointer is configured as null */
    if (NULL_PTR != Fls_GpConfigPtr->pEccDEDNotificationPointer)
    {
      /* END Msg(2:2814)-1 */
      /* ECC double bit error notification to the upper layer */
      Fls_GpConfigPtr->pEccDEDNotificationPointer
                                         (Fls_GstVar.ulSrcDestAddress);
    }
    else
    {
      /* No action required */
    }
  }
  else if ((FLS_FCU_ERR_ECC_SED == LenStatus) && (FLS_TRUE == LblSECError))
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress -
                                                        FLS_DF_BASE_ADDRESS;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Report SEC if Error has occurred and Notification pointer is NULL */
    if (NULL_PTR != Fls_GpConfigPtr->pEccSEDNotificationPointer)
    {
      /* ECC single bit error notification to the upper layer */
      Fls_GpConfigPtr->pEccSEDNotificationPointer
                                             (Fls_GstVar.ulSrcDestAddress);
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

} /* End of function Fls_ReportECCErrorToCbk */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_CopyToTargetBuff
**
** Service ID               : NA
**
** Description              : This function is used to copy data from Temporary
**                            Buffer to Target Buffer when the command is
**                            FLS_COMMAND_READ_IMM or FLS_COMMAND_READ.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LblLastRead
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ucOffset(RW),
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.ulRequestedLength(R),
**                            Fls_GstVar.pBufferAddress(RW)
**
** Function(s) invoked      : Fls_GetMaxReadBytes
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
   /* QAC Warning: START Msg(2:3227)-5 */
/* Implements FLS_ESDD_UD_034 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CopyToTargetBuff
                                                      (boolean LblLastRead)
{
  /* END Msg(2:3227)-5 */
  /* Local variable to store the processed bytes count */
  uint32 LulBytesProcessed;
  /* Local variable to hold the loop count */
  uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenReturnValue;
  LulLoopCount = (uint32)FLS_ZERO;
  /* Get the Maximum Read bytes */
  LulMaxReadBytes = Fls_GetMaxReadBytes();
  /* Implements FLS_ESDD_UD_140 */
  if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
  {
    if (FLS_TRUE != LblLastRead)
    {
    /* Set the bytes to be processed to maximum read bytes per cycle */
      LulBytesProcessed = (LulMaxReadBytes - Fls_GstVar.ucOffset);
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* QAC Warning: START Msg(2:2824)-2 */
      /* MISRA Violation: START Msg(4:0488)-3 */
      /* Reset the buffer pointer with number of bytes it processed */
      Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress -
                                                        LulBytesProcessed);
      /* END Msg(4:0488)-3 */
      /* END Msg(2:2824)-2 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Set the Job Status to Pending */
      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set the bytes to be processed to remaining read bytes */
      LulBytesProcessed = Fls_GstVar.ulCurrentLength;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0488)-3 */
      /* Reset the buffer pointer with number of bytes it processed */
      Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress +
                                 Fls_GstVar.ucOffset) - LulBytesProcessed;
      /* END Msg(4:0488)-3 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      LulBytesProcessed = Fls_GstVar.ulRequestedLength;
      /* Set the Job Status to OK */
      LenReturnValue = MEMIF_JOB_OK;
    }

    /* Loop until the number of bytes read in one cycle */
    while (LulLoopCount < LulBytesProcessed)
    {
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0311)-6 */
      /* QAC Warning: START Msg(2:2814)-1 */
      *((volatile uint8 *) Fls_GstVar.pBufferAddress) =
                             *((volatile uint8 *)Fls_GstVar.pTempBufferAddress);
      /* END Msg(2:2814)-1 */
      /* END Msg(4:0311)-6 */
      LulLoopCount++;
      /* MISRA Violation: START Msg(4:0489)-4 */
      Fls_GstVar.pBufferAddress++;
      Fls_GstVar.pTempBufferAddress++;
      /* END Msg(4:0489)-4 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* Increment the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress -
                               (Fls_GstVar.ucOffset + LulBytesProcessed);
    /* END Msg(4:0488)-3 */
    /* Set the global variable offset to zero */
    Fls_GstVar.ucOffset = FLS_ZERO;
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to protect this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    if (FLS_TRUE != LblLastRead)
    {
      /* Set the Job Status to Pending */
      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set the Job Status to OK */
      LenReturnValue = MEMIF_JOB_OK;
    }
  }

  return(LenReturnValue);
} /* End of function Fls_CopyToTargetBuff */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ProcessCancel
**
** Service ID               : NA
**
** Description              : This function invokes issues the Forced Stop
**                            Command to stop the ongoing FCU operation.
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
** Global Variables Used    : Fls_GstVar.enDFStatus(W)
**
** Function(s) invoked      : Fls_FcuSwitchMode, Fls_FcuForcedStop,
**                            Fls_FcuClearStatus
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_035 */
/* Implements AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessCancel(void)
{
  Fls_FcuStatusType LenStatus;

  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_PE);
  if (FLS_FCU_OK == LenStatus)
  {
    /* Issuing Forced Stop Command */
    LenStatus = Fls_FcuForcedStop();
  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_OK == LenStatus)
  {
    /* Issue Clear Status command */
    Fls_FcuClearStatus();
    LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_USER);

  }
  else
  {
    /* No action required */
  }

  if (FLS_FCU_OK == LenStatus)
  {
    LenStatus = FLS_FCU_CANCELED;
  }
  else
  {
    LenStatus = FLS_FCU_ERR_INTERNAL;
  }
  Fls_GstVar.enDFStatus = LenStatus;
} /* End of function Fls_ProcessCancel */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_FHVE_REGS == SUPPORTED)
/*******************************************************************************
** Function Name            : Fls_SetFHVE
**
** Service ID               : NA
**
** Description              : Pull FHVE3 and FHVE15 registers pin to VDD or VSS
**                            to Enable or to Disable the flash memory software
**                            protection.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : NA
**
** Input Parameters         : value (protection enable or disable)
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GblFlashEnable(RW)
**
** Function(s) invoked      : None
**
** Registers Used           : FHVE3,FHVE15
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
   /* QAC Warning: START Msg(2:3227)-5 */
/* Implements FLS_ESDD_UD_036 */
/* Implements EAAR_PN0034_FSR_0002 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetFHVE(boolean value)
{
   /*END Msg(2:3227)-5 */
  if (Fls_GblFlashEnable != value)
  {
    /* MISRA Violation: START Msg(4:0303)-1*/
    /* QAC Warning: START Msg(2:3892)-4 */
    FLS_REG_WRITE(FLS_FHVE3,(uint8)value)
    /* MISRA Violation: START Msg(4:1290)-9 */
    /* For write verification */
    FLS_REG_WRITE_VERIFY_RUNTIME(FLS_FHVE3,((uint8)value), FHVE_REG_MASK_VAL, \
                                                            FLS_SETFHVE_API_ID)
    /* END Msg(4:1290)-9 */
    FLS_REG_WRITE(FLS_FHVE15,(uint8)value)
    /* MISRA Violation: START Msg(4:1290)-9 */
    /* For write verification */
    FLS_REG_WRITE_VERIFY_RUNTIME(FLS_FHVE15,((uint8)value), FHVE_REG_MASK_VAL, \
                                                            FLS_SETFHVE_API_ID)
    /* END Msg(4:1290)-9 */
    /* END Msg(2:3892)-4 */
    /* END Msg(4:0303)-1 */
    Fls_GblFlashEnable = value;
  }
  else
  {
    /* No Action required */
  }

} /* End of function Fls_SetFHVE */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
/*******************************************************************************
** Function Name            : Fls_InitiateBlankCheckJob
**
** Service ID               : NA
**
** Description              : This function initiates the Blank Check Job
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Std_ReturnType
**
** Return parameter         : LenReturn
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),
**                            Fls_GblTimeOutMonitor(W),Fls_GulTimeOutCounter(W),
**                            Fls_GstVar.ulSrcDestAddress(R)
**
** Function(s) invoked      : Fls_FcuPerformBlankCheck
**
** Registers Used           : FSTATR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_037 */
/* Implements AR_PN0072_FR_0059 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateBlankCheckJob(void)
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LenReturn;
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Variable to save the address for Blank Check */
  uint32 LulBCAddress;
  #if (FLS_TIMEOUT_MONITORING == STD_ON)
  uint32 LulRegValue;
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  LulRegValue = LpFACIRegPtr->ulFSTATR;
  #endif
  LenReturn = E_OK;
  /* END Msg(2:2814)-1 */
  /* Get the address for Blank Check Job */
  LulBCAddress = Fls_GstVar.ulSrcDestAddress - FLS_DF_BASE_ADDRESS;
  #if (FLS_TIMEOUT_MONITORING == STD_ON)
  if (FLS_FCU_REGBIT_FSTATR_FRDY == (FLS_FCU_REGBIT_FSTATR_FRDY & LulRegValue))
  {
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    /* Implements FLS_ESDD_UD_103 */
    Fls_GulTimeOutCounter = (uint32)((uint32)FLS_BLANKCHECK_TIMEOUT_COUNT * \
                    ( Fls_GstVar.ulRequestedLength / FLS_FCU_WRITE_SIZE));
    #else
    Fls_GulTimeOutCounter = (uint32)((uint32)FLS_ISR_TIMEOUT_COUNT * \
                    ( Fls_GstVar.ulRequestedLength / FLS_FCU_WRITE_SIZE));
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */
  }
  else
  {
    /*No action Required */
  }
  /* Set Time Out Monitor Flag to TRUE */
  Fls_GblTimeOutMonitor = FLS_TRUE;
  #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */

  /* Call Fls_FcuPerformBlankCheck to perform Blank Check */
  LenStatus = Fls_FcuPerformBlankCheck(LulBCAddress,
                                     (uint32)Fls_GstVar.ulRequestedLength);
  if (FLS_FCU_OK != LenStatus)
  {
    LenReturn = E_NOT_OK;
  }
  else
  {
    /* No Action required */
  }

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return(LenReturn);
} /* End of function Fls_InitiateBlankCheckJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_MainBlankCheck
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is BlankCheck Operation.
**
** Sync/Async               : NA
**
** Re-entrancy              : Non Re-entrant
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
** Global Variables Used    : Fls_GblVerifyCompletedJob(R)
**
** Function(s) invoked      : Fls_FcuCheckBCJobStatus,Fls_FcuBlankCheckResult,
**                            Fls_ProcessJobResult,Fls_FcuSwitchMode,
**                            Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_038 */
/* Implements FLS055,FLS104,FLS022,FLS261,FLS163,FLS161,FLS164 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainBlankCheck(void)
{
  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;

  /* Get the Data flash Status */
  LenStatus = Fls_FcuCheckBCJobStatus();

  if (FLS_FCU_OK == LenStatus)
  {
    /* Switching Back to User Mode */
    (void)Fls_FcuSwitchMode(FLS_FCU_MODE_USER);

    /* Check if Block is inconsistent or Erased */
    LenStatus = Fls_FcuBlankCheckResult();

    /* Check Blank Check Status and process accordingly */
    if (FLS_FCU_OK == LenStatus)
    {
      /* Data Flash is Erased */
      Fls_ProcessJobResult(MEMIF_JOB_OK);
    }
    else
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* QAC Warning: START Msg(2:3416)-9 */
      if (FLS_TRUE == Fls_GblVerifyCompletedJob)
      /* END Msg(2:3416)-9 */
      {
        /* Process Job Failure in case of verification after Erase operation
           Failed */
        Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        /* Implements FLS_ESDD_UD_121 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                             FLS_MAINFUNCTION_SID, FLS_E_VERIFY_ERASE_FAILED);
      }
      else
      #endif /* End of #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      {
        /* Set Job result as Block Consistent */
        Fls_ProcessJobResult(MEMIF_BLOCK_INCONSISTENT);
      }
    }
  }
  else
  {
    /* No Action required */
  }

} /* End of function Fls_MainBlankCheck */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_ProcessJobResult
**
** Service ID               : NA
**
** Description              : Function to process in case of Job Success/
**                            Failure for erase, write and read operations.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Re-entrant
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
** Global Variables Used    : Fls_GenJobResult(W),Fls_GstVar.enGenCommand(W)
**                            Fls_GenState(W),Fls_GblFlashEnable(RW),
**                            Fls_GblVerifyCompletedJob(W),Fls_GpConfigPtr(R)
**                            Fls_GblTimeOutMonitor(W)
**
** Function(s) invoked      : Fls_SetFHVE,Fls_RestoreIntReq,
**                            Fls_FcuResetErrorBits,Fls_CallJobNotification
**                            Dem_ReportErrorStatus
**
** Registers Used           : IMRn
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"
   /* QAC Warning: START Msg(2:3227)-5 */
/* Implements FLS_ESDD_UD_039 */
/* Implements FLS104,FLS352,FLS315,FLS316,FLS260,FLS006 */
/* Implements EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FSR_0002 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessJobResult
                                      (MemIf_JobResultType LenResult)
{
  /* END Msg(2:3227)-5 */
  Std_ReturnType LenReturn;
  #if (FLS_INTERRUPT_MODE == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* MISRA Violation: START Msg(4:4397)-7 */
  /* QAC Warning: START Msg(2:2814)-1 */
  /* Disable interrupt processing */
  RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                             ~(Fls_GpConfigPtr->usFlEndImrMask));
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* END Msg(2:2814)-1 */
  /* END Msg(4:4397)-7 */
  Fls_RestoreIntReq();
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_TRUE == Fls_GblFlashEnable)
  {
    /* Enable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
    Fls_GblFlashEnable = FLS_FALSE;
  }
  else
  {
    /* No action required */
  }
  #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
  /* Set the job result to Job Failed */
  Fls_GenJobResult = LenResult;
  /* Set the command as None */
  Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
  /* Set the driver state to idle */
  Fls_GenState = MEMIF_IDLE;
  #if (FLS_TIMEOUT_MONITORING == STD_ON)
  /* Clear the Global Time out Monitor */
  Fls_GblTimeOutMonitor = FLS_FALSE;
  #endif /* FLS_TIMEOUT_MONITORING == STD_ON */

  /* Check for the status FLS_FCU_ERR_INTERNAL */
  if (FLS_FCU_ERR_INTERNAL == Fls_GstVar.enDFStatus)
  {
    /* Implements FLS_ESDD_UD_133 */
    Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
  }
  else if (FLS_FCU_ERR_ERASE == Fls_GstVar.enDFStatus)
  {
    /* Report DEM as Erase Job Failed */
    /* Implements FLS_ESDD_UD_126 */
    Dem_ReportErrorStatus(FLS_E_ERASE_FAILED, DEM_EVENT_STATUS_FAILED);

    /*Invoke Fls_FcuResetErrorBits to clear error bits */
    LenReturn = Fls_FcuResetErrorBits();
    if (E_NOT_OK == LenReturn)
    {
      /* Implements FLS_ESDD_UD_133 */
      Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No action required */
    }
  }
  else if (FLS_FCU_ERR_WRITE == Fls_GstVar.enDFStatus)
  {
    /* Implements FLS_ESDD_UD_127 */
    /* Report DEM as Write Job Failed */
    Dem_ReportErrorStatus(FLS_E_WRITE_FAILED, DEM_EVENT_STATUS_FAILED);

    /*Invoke Fls_FcuResetErrorBits to clear error bits */
    LenReturn = Fls_FcuResetErrorBits();
    if (E_NOT_OK == LenReturn)
    {
      Dem_ReportErrorStatus(FLS_E_HW_FAILURE, DEM_EVENT_STATUS_FAILED);
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
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  Fls_GblVerifyCompletedJob = FLS_FALSE;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
  Fls_CallJobNotification();
  #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
} /* End of function Fls_ProcessJobResult */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_JOB_NOTIF_CONFIG == STD_ON)
/*******************************************************************************
** Function Name            : Fls_CallJobNotification
**
** Service ID               : NA
**
** Description              : This function calls the required Notification
**                            function based on the Job result.
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
** Global Variables Used    : Fls_GenJobResult(R),Fls_GpConfigPtr(R)
**
** Function(s) invoked      : Fls_GpConfigPtr->pJobEndNotificationPointer,
**                            Fls_GpConfigPtr->pJobErrorNotificationPointer
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_040 */
/* Implements FLS347,FLS167,FLS348,FLS349,FLS262,FLS263,FLS110 */
FUNC(void, FLS_PRIVATE_CODE) Fls_CallJobNotification(void)
{

  /* QAC Warning: START Msg(2:2814)-1 */
  /* QAC Warning: START Msg(2:3416)-9 */
  /* Call the Job Notification corresponding to the Job result */
  if ((MEMIF_JOB_OK == Fls_GenJobResult) &&
      (NULL_PTR != Fls_GpConfigPtr->pJobEndNotificationPointer))
  {
    /* END Msg(2:3416)-9 */
    /* END Msg(2:2814)-1 */
    /* If job ended with success and call the job end call back function */
    Fls_GpConfigPtr->pJobEndNotificationPointer();
  }
  /* Job ended with an error */
  else if (NULL_PTR != Fls_GpConfigPtr->pJobErrorNotificationPointer)
  {
    /* If job ended with error and call the job error call back function */
    Fls_GpConfigPtr->pJobErrorNotificationPointer();
  }
  else
  {
    /* No action required */
  }

} /* End of function Fls_CallJobNotification */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */

#if (FLS_INTERRUPT_MODE == STD_ON)
/*******************************************************************************
** Function Name            : Fls_ClearIntReq
**
** Service ID               : NA
**
** Description              : This function clears interrupt request flag from
**                            ICFLENDNM
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : None
**
** Function(s) invoked      : None
**
** Registers Used           : ICFLENDNM
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_041 */
/* Implements EAAR_PN0034_FSR_0002 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ClearIntReq(void)
{
  volatile uint16 LusRegvalue;
  /* MISRA Violation: START Msg(4:0303)-1 */
  LusRegvalue = FLS_ICFLENDNM;
  /*Clear the Interrupt Request Bit */
  LusRegvalue &= FLS_RESET_INT_REQ;
  FLS_REG_WRITE(FLS_ICFLENDNM,LusRegvalue)
  /* MISRA Violation: START Msg(4:1290)-9 */
  /* QAC Warning: START Msg(2:3416)-9 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_RUNTIME(FLS_ICFLENDNM, LusRegvalue, \
                         FLENDNM_REG_MASK_VAL, FLS_CLEARINTREQ_API_ID)
  /* END Msg(2:3416)-9 */
  /* END Msg(4:1290)-9 */
  /* END Msg(4:0303)-1 */
} /* End of function Fls_ClearIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_SetIntReq
**
** Service ID               : NA
**
** Description              : This function sets interrupt request flag from
**                            ICFLENDNM
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : None
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_042 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetIntReq(void)
{

  volatile uint16 LusRegvalue;
  /* MISRA Violation: START Msg(4:0303)-1 */
  LusRegvalue = FLS_ICFLENDNM;
  /*Set the Interrupt Request Bit */
  LusRegvalue |= FLS_SET_INT_REQ;
  FLS_REG_WRITE(FLS_ICFLENDNM,LusRegvalue)
  /* MISRA Warning: START Msg(4:1290)-9 */
  /* QAC Warning: START Msg(2:3416)-9 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_RUNTIME(FLS_ICFLENDNM, LusRegvalue, \
                                   FLENDNM_REG_MASK_VAL, FLS_SETINTREQ_API_ID)
  /* END Msg(2:3416)-9 */
  /* END Msg(4:1290)-9 */
  /* END Msg(4:0303)-1 */
} /* End of function Fls_SetIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_RestoreIntReq
**
** Service ID               : NA
**
** Description              : This function restores interrupt pending bit from
**                            Fls_GblIntrRqstFlag
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GblIntrRqstFlag(R)
**
** Function(s) invoked      : Fls_SetIntReq,Fls_ClearIntReq
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_043 */
FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreIntReq(void)
{
  if (FLS_TRUE == Fls_GblIntrRqstFlag)
  {
    /* Set the Interrupt Flag if the TRUE */
    Fls_SetIntReq();
  }
  else
  {
    /* Clear the Interrupt Flag if the FALSE */
    Fls_ClearIntReq();
  }
} /* End of function Fls_RestoreIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_GetIntReq
**
** Service ID               : NA
**
** Description              : This function gets interrupt request flag from
**                            ICFLENDNM
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GblIntrRqstFlag(W)
**
** Function(s) invoked      : None
**
** Registers Used           : ICFLENDNM
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_044 */
FUNC(void, FLS_PRIVATE_CODE) Fls_GetIntReq(void)
{
  uint16 LusRegvalue;
  /* QAC Warning: START Msg(2:3892)-4 */
  /* MISRA Violation: START Msg(4:0303)-1 */
  LusRegvalue = FLS_ICFLENDNM;
  /* Get the Value of Interrupt Request Bit */
  LusRegvalue = (uint16)((LusRegvalue >> (uint16)FLS_INTERRUPT_BIT_NUM) & \
                                                            (uint16)FLS_ONE);
  Fls_GblIntrRqstFlag = (boolean)LusRegvalue;
  /*  END Msg(4:0303)-1 */
  /*  END  Msg(2:3892)-4 */
} /* End of function Fls_GetIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_ProcessResume
**
** Service ID               : NA
**
** Description              : The function restores the job data and resumes
**                            the job
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GenState(W),Fls_GenJobResult(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GblJobSuspended(R),
**                            Fls_GblFlashEnable(RW)
**
** Function(s) invoked      : Fls_RestoreJobData,Fls_InitiateEraseJob,
**                            Fls_InitiateWriteJob,Fls_MainRead,
**                            Fls_InitiateBlankCheckJob,
**                            Fls_SetFHVE
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_045 */
/* Implements AR_PN0072_FR_0022 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessResume(void)
{
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:3416)-9 */
  /* Check if any Job is Suspended */
  if (FLS_TRUE == Fls_GblJobSuspended)
  /* END Msg(2:3416)-9 */
  {
    /* Restore the Job Variables from the back-up structure */
    Fls_RestoreJobData();
    /* Set the Driver status to Busy */
    Fls_GenState = MEMIF_BUSY;
    /* Set the Job Status to Pending */
    Fls_GenJobResult = MEMIF_JOB_PENDING;
    /* Clear the Flag*/
    Fls_GblJobSuspended = FLS_FALSE;
    #if (FLS_FHVE_REGS == SUPPORTED)
    if (FLS_FALSE == Fls_GblFlashEnable)
    {
      /* Disable the flash memory software protection */
      Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
      Fls_GblFlashEnable = FLS_TRUE;
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
    switch (Fls_GstVar.enGenCommand)
    {
    /* In case of Erase Operation */
    case FLS_COMMAND_ERASE:
         LenReturnValue = Fls_InitiateEraseJob();
    break;
    case FLS_COMMAND_WRITE:
         LenReturnValue = Fls_InitiateWriteJob();
    break;
    /* QAC Warning: START Msg(2:2016)-6 */
    default:
           /* No action required */
    break;
    }
    /* END Msg(2:2016)-6 */

    /* Check for the status is FLS_FCU_OK */
    if (E_NOT_OK == LenReturnValue)
    {
      Fls_ProcessJobResult(MEMIF_JOB_FAILED);
    }
    else
    {
      /* No action Required */
    }
  }
  else
  {
    /* No action required */
  }

} /* End of function Fls_ProcessResume */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_RestoreJobData
**
** Service ID               : NA
**
** Description              : This function takes the job result from the back
**                            up global job structure and restores it into
**                            the original job structure when suspend operation
**                            occurs
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.ulJobStartAddress(W),
**                            Fls_GstVar.ulJobEndAddress(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ucOffset(W),
**                            Fls_GstVar.enReadType(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GstBackUpVar.pBufferAddress(R),
**                            Fls_GstBackUpVar.ulSrcDestAddress(R),
**                            Fls_GstBackUpVar.ulReadAddress(R),
**                            Fls_GstBackUpVar.ulJobStartAddress(R),
**                            Fls_GstBackUpVar.ulJobEndAddress(R),
**                            Fls_GstBackUpVar.ulCurrentLength,(R),
**                            Fls_GstBackUpVar.ulRequestedLength(R),
**                            Fls_GstBackUpVar.ucOffset(R),
**                            Fls_GstBackUpVar.enReadType(R),
**                            Fls_GstBackUpVar.enGenCommand(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_046 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreJobData(void)
{
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Store the source address */
  Fls_GstVar.pBufferAddress = Fls_GstBackUpVar.pBufferAddress;
  /* Store the target address */
  Fls_GstVar.ulSrcDestAddress = Fls_GstBackUpVar.ulSrcDestAddress;
  /* Store the read address */
  Fls_GstVar.ulReadAddress = Fls_GstBackUpVar.ulReadAddress;
  /* Store the erase/write start address */
  Fls_GstVar.ulJobStartAddress = Fls_GstBackUpVar.ulJobStartAddress;
  /* Store the erase/write end address */
  Fls_GstVar.ulJobEndAddress = Fls_GstBackUpVar.ulJobEndAddress;
  /* Store the adjusted length */
  Fls_GstVar.ulCurrentLength = Fls_GstBackUpVar.ulCurrentLength;
  /* Store the requested number of bytes to be processed */
  Fls_GstVar.ulRequestedLength = Fls_GstBackUpVar.ulRequestedLength;
  /* Store offset by masking the source address with page size */
  Fls_GstVar.ucOffset = Fls_GstBackUpVar.ucOffset;
  /* Store the Flash read type */
  Fls_GstVar.enReadType = Fls_GstBackUpVar.enReadType;
  /* Store the requested commands */
  Fls_GstVar.enGenCommand = Fls_GstBackUpVar.enGenCommand;
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
} /* End of function Fls_RestoreJobData */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON))
/*******************************************************************************
** Function Name            : Fls_ClearBackUpData
**
** Service ID               : NA
**
** Description              : This function clears the job data from the back
**                            up global job structure.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GstBackUpVar.pBufferAddress(W),
**                            Fls_GstBackUpVar.ulSrcDestAddress(W),
**                            Fls_GstBackUpVar.ulReadAddress(W),
**                            Fls_GstBackUpVar.ulJobStartAddress(W),
**                            Fls_GstBackUpVar.ulJobEndAddress(W),
**                            Fls_GstBackUpVar.ulCurrentLength(W),
**                            Fls_GstBackUpVar.ulRequestedLength(W),
**                            Fls_GstBackUpVar.ucOffset(W),
**                            Fls_GstBackUpVar.enReadType(W),
**                            Fls_GstBackUpVar.enGenCommand(W)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_047 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ClearBackUpData(void)
{
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:3892)-4 */
  /* Store the source address */
  Fls_GstBackUpVar.pBufferAddress = FLS_NULL;
  /* END Msg(2:3892)-4 */
  /* Store the target address */
  Fls_GstBackUpVar.ulSrcDestAddress = (uint32)FLS_ZERO;
  /* Store the read address */
  Fls_GstBackUpVar.ulReadAddress = (uint32)FLS_ZERO;
  /* Store the erase/write start address */
  Fls_GstBackUpVar.ulJobStartAddress = (uint32)FLS_ZERO;
  /* Store the erase/write end address */
  Fls_GstBackUpVar.ulJobEndAddress = (uint32)FLS_ZERO;
  /* Store the adjusted length */
  Fls_GstBackUpVar.ulCurrentLength = (uint32)FLS_ZERO;
  /* Store the requested number of bytes to be processed */
  Fls_GstBackUpVar.ulRequestedLength = (uint32)FLS_ZERO;
  /* Store offset by masking the source address with page size */
  Fls_GstBackUpVar.ucOffset = FLS_ZERO;
  /* Store the Flash read type */
  /* Implements FLS_ESDD_UD_140 */
  Fls_GstBackUpVar.enReadType = FLS_MISALIGNED_READ;
  /* Store the requested commands */
  Fls_GstBackUpVar.enGenCommand = FLS_COMMAND_NONE;
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

} /* End of function Fls_ClearBackUpData */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON)) */

#if (FLS_SUSPEND_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_ProcessSuspend
**
** Service ID               : NA
**
** Description              : This function backs up the Job structure and
**                            clears original job structure
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GenState(W),Fls_GenJobResult(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GblJobSuspended(W),Fls_GblJobSuspendRequest(W)
**                            Fls_GblTimeOutMonitor(W)
**
** Function(s) invoked      : Fls_BackupJobData,Fls_FcuSwitchMode
**                            Fls_ProcessJobResult
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_048 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessSuspend(void)
{
  Fls_FcuStatusType LenStatus;

  LenStatus = Fls_FcuSwitchMode(FLS_FCU_MODE_USER);

  if (FLS_FCU_OK == LenStatus)
  {
    /* Backup the required data in the Job Structure*/
    Fls_BackupJobData();
    /* Set the driver state to idle */
    Fls_GenState = MEMIF_IDLE;
    /* Set the job Result to OK */
    Fls_GenJobResult = MEMIF_JOB_OK;
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    #if (FLS_TIMEOUT_MONITORING == STD_ON)
    /* Clear the Global Time out Monitor after servicing */
    Fls_GblTimeOutMonitor = FLS_FALSE;
    #endif /* FLS_TIMEOUT_MONITORING == STD_ON */
    Fls_GblJobSuspended = FLS_TRUE;
    Fls_GblJobSuspendRequest = FLS_FALSE;
  }
  else
  {
    Fls_ProcessJobResult(MEMIF_JOB_FAILED);
  }
} /* End of function Fls_ProcessSuspend */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_BackupJobData
**
** Service ID               : NA
**
** Description              : This function takes the job result from the
**                            global job structure and stores it into the
**                            backup structure when suspend operation occurs
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
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
** Global Variables Used    : Fls_GstVar.pBufferAddress(R),
**                            Fls_GstVar.ulSrcDestAddress(R),
**                            Fls_GstVar.ulReadAddress(R),
**                            Fls_GstVar.ulJobStartAddress(R),
**                            Fls_GstVar.ulJobEndAddress(R),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.ulRequestedLength(R),
**                            Fls_GstVar.ucOffset(R),
**                            Fls_GstVar.enReadType(R),
**                            Fls_GstVar.enGenCommand(R),
**                            Fls_GstBackUpVar.pBufferAddress(W),
**                            Fls_GstBackUpVar.ulSrcDestAddress(W),
**                            Fls_GstBackUpVar.ulReadAddress(W),
**                            Fls_GstBackUpVar.ulJobStartAddress(W),
**                            Fls_GstBackUpVar.ulJobEndAddress(W),
**                            Fls_GstBackUpVar.ulCurrentLength(W),
**                            Fls_GstBackUpVar.ulRequestedLength(W),
**                            Fls_GstBackUpVar.ucOffset(W),
**                            Fls_GstBackUpVar.enReadType(W),
**                            Fls_GstBackUpVar.enGenCommand(W)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_049 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_BackupJobData(void)
{
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Store the source address */
  Fls_GstBackUpVar.pBufferAddress = Fls_GstVar.pBufferAddress;
  /* Store the target address */
  Fls_GstBackUpVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress;
  /* Store the read address */
  Fls_GstBackUpVar.ulReadAddress = Fls_GstVar.ulReadAddress;
  /* Store the erase/write start address */
  Fls_GstBackUpVar.ulJobStartAddress = Fls_GstVar.ulJobStartAddress;
  /* Store the erase/write end address */
  Fls_GstBackUpVar.ulJobEndAddress = Fls_GstVar.ulJobEndAddress;
  /* Store the adjusted length */
  Fls_GstBackUpVar.ulCurrentLength = Fls_GstVar.ulCurrentLength;
  /* Store the requested number of bytes to be processed */
  Fls_GstBackUpVar.ulRequestedLength = Fls_GstVar.ulRequestedLength;
  /* Store offset by masking the source address with page size */
  Fls_GstBackUpVar.ucOffset = Fls_GstVar.ucOffset;
  /* Store the Flash read type */
  Fls_GstBackUpVar.enReadType = Fls_GstVar.enReadType;
  /* Store the requested commands */
  Fls_GstBackUpVar.enGenCommand = Fls_GstVar.enGenCommand;
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

} /* End of function Fls_BackupJobData */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_SUSPEND_API == STD_ON) */

#if (FLS_TIMEOUT_MONITORING == STD_ON)
/*******************************************************************************
** Function Name            : Fls_TimeOutCheckAndProcessing
**
** Service ID               : NA
**
** Description              : This Function checks for Time out and performs
**                            further processing in case of time-out.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : Time Out Processing shall be configured by User.
**
** Global Variables Used    : Fls_GulTimeOutCounter(RW),Fls_GpConfigPtr(R)
**                            Fls_GenJobResult(W),Fls_GenState(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GblTimeOutMonitor(W)
**
** Function(s) invoked      : Fls_ProcessCancel,Fls_CallJobNotification,
**                            Det_ReportError,Fls_ClearIntReq,
**                            Dem_ReportErrorStatus
**
** Registers Used           : IMRn
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_050 */
/* Implements FLS362,FLS360,FLS346,FLS359,FLS352,FLS260,FLS006,FLS164 */
/* Implements EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013,EAAR_PN0034_FSR_0002 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0059,AR_PN0072_FR_0023 */
FUNC(void, FLS_PRIVATE_CODE) Fls_TimeOutCheckAndProcessing(void)
{
  if ((uint32)FLS_ZERO == Fls_GulTimeOutCounter)
  {
    /* Cancel the ongoing job in case of Time-out */
    Fls_ProcessCancel();
    #if (FLS_INTERRUPT_MODE == STD_ON)
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* MISRA Violation: START Msg(4:4397)-7 */
    /* QAC Warning: START Msg(2:2814)-1 */
    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                              ~(Fls_GpConfigPtr->usFlEndImrMask));
    /* END Msg(2:2814)-1 */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* END Msg(4:4397)-7 */
    Fls_ClearIntReq();
    #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
    /* Set the JOB result as failed */
    Fls_GenJobResult = MEMIF_JOB_FAILED;
    Fls_GenState = MEMIF_IDLE;
    /* Set the command to none. */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Clear the Global Time out Monitor after servicing */
    Fls_GblTimeOutMonitor = FLS_FALSE;
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification();
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
    /* Check for the status FLS_FCU_ERR_INTERNAL */
    if (FLS_FCU_ERR_INTERNAL == Fls_GstVar.enDFStatus)
    {
      /* Implements FLS_ESDD_UD_133 */
      Dem_ReportErrorStatus(FLS_E_HW_FAILURE,DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* No Action Required */
    }

    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_123 */
    /* Report FLS_E_TIMEOUT to DET */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                          FLS_MAINFUNCTION_SID, FLS_E_TIMEOUT);
    #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Decrement the Time Out Counter */
    Fls_GulTimeOutCounter--;
  }

} /* End of function Fls_TimeOutCheckAndProcessing */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */

/*******************************************************************************
** Function Name            : Fls_DetErrorCheck
**
** Service ID               : NA
**
** Description              : This function is used to check whether the driver
**                            is initialised or busy and report DET accordingly
**                            depending on the service id of each API.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : LucServiceId
**
** InOut Parameters         : None
**
** Output Parameters        : Std_ReturnType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GblInitStatus(R),Fls_GenState(R)
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_074 */
/* Implements FLS066,FLS030,FLS152,FLS153,FLS156,FLS311,FLS312,FLS261,FLS144 */
/* Implements FLS164 */
/* QAC Warning: START Msg(2:3227)-5 */
/* QAC Warning: START Msg(2:3206)-10 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_DetErrorCheck(uint8 LucServiceId)
{
  /* END Msg(2:3206)-10 */
  /* END Msg(2:3227)-5 */
  /* Local Variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;

  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    /* Implements FLS_ESDD_UD_119 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET if the component is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                    LucServiceId, FLS_E_UNINIT);
    #endif
    /* Reset return value to E_NOT_OK due to failure */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if the driver is busy by servicing another request */
  /* QAC Warning: START Msg(2:3416)-9 */
  if (MEMIF_BUSY == Fls_GenState)
  {
    /* END Msg(2:3416)-9 */
    /* Implements FLS_ESDD_UD_120 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET if the driver is currently busy */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                      LucServiceId, FLS_E_BUSY);
    #endif
    /* Reset return value to E_NOT_OK due to failure */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  return(LenReturnValue);
} /* End of function Fls_DetErrorCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (FLS_SUSPEND_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_SuspendPreCheck
**
** Service ID               : NA
**
** Description              : This function checks for whether different
**                            sequences of requests for suspension is to be
**                            allowed or not
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : NA
**
** Input Parameters         : LenRequestedCmd
**
** InOut Parameters         : None
**
** Output Parameters        : Std_ReturnType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),
**                            Fls_GstBackUpVar.enGenCommand(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_069 */
/* Implements FLS_ESDD_UD_139 */
/* Implements AR_PN0072_FR_0023 */
   /* QAC Warning: START Msg(2:3227)-5 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_SuspendPreCheck
                                               (Fls_CommandType LenRequestedCmd)
{
  /* END Msg(2:3227)-5 */
  /* Variable to store return variable */
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;
  /*
    Following sequences of requests shall be rejected.
    Erase -> Suspend -> Erase
    Write -> Suspend -> Erase
  */
  /* QAC Warning: START Msg(2:3416)-9 */
  if (FLS_TRUE == Fls_GblJobSuspended)
  {
    /* END Msg(2:3416)-9 */
    if ((FLS_COMMAND_ERASE  == LenRequestedCmd) &&
       ((FLS_COMMAND_ERASE == Fls_GstBackUpVar.enGenCommand) ||
        (FLS_COMMAND_WRITE == Fls_GstBackUpVar.enGenCommand)))
    {
      LenReturnValue = E_NOT_OK;
    }
    /* Sequence Write -> Suspend -> Write not allowed */
    else if ((FLS_COMMAND_WRITE  == LenRequestedCmd) &&
            (FLS_COMMAND_WRITE == Fls_GstBackUpVar.enGenCommand))
    {
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No Action required */
    }
  }
  else
  {
    /* No Action required */
  }

  if (E_NOT_OK == LenReturnValue)
  {
    /* Set request status as rejected */
    Fls_GstVar.enDFStatus = FLS_FCU_ERR_REJECTED;
  }
  else
  {
    /* No Action required */
  }
  return(LenReturnValue);
} /* End of function Fls_SuspendPreCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (FLS_SUSPEND_API == STD_ON) */
/*******************************************************************************
** Function Name            : Fls_FastReadCheckECC
**
** Service ID               : NA
**
** Description              : This function checks for ECC errors in data flash
**                            when fast read is performed.
**
** Sync/Async               : NA
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LulErrorStatus,LblLastRead
**
** InOut Parameters         : None
**
** Output Parameters        : MemIf_JobResultType
**
** Return parameter         : LenReturnValue
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_CopyToTargetBuff,Dem_ReportErrorStatus,
**                            Fls_ReportECCErrorToCbk
**
** Registers Used           : DFERSTR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_077 */
/* Implements FLS352,FLS260,FLS006 */
  /* QAC Warning: START Msg(2:3227)-5 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_FastReadCheckECC
                                     (uint32 LulErrorStatus,boolean LblLastRead)
 {
  /* END Msg(2:3227)-5 */
  /* Local variable to hold internal Job Status */
  MemIf_JobResultType LenReturnValue;
  /* Local variable to hold the status of the FCU */
  Fls_FcuStatusType LenStatus;
   /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;
  LblSECError = FLS_FALSE;
  /* Check ECC Status Register for Read Errors and set the status */
  if ((uint32)FLS_FCU_REGVAL_DFERSTR_NOERR != LulErrorStatus)
  {
    if ((uint32)FLS_FCU_REGBIT_DFERSTR_DEDF ==
                         ((uint32)FLS_FCU_REGBIT_DFERSTR_DEDF & LulErrorStatus))
    {
      LenStatus = FLS_FCU_ERR_ECC_DED;
    }
    else
    {
      LenStatus = FLS_FCU_ERR_ECC_SED;
      LblSECError = FLS_TRUE;
    }
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }
  /* Check the Request Status and set Job status to return */
  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Copy Data from Temporary Buffer to Target Buffer */
    LenReturnValue = Fls_CopyToTargetBuff(LblLastRead);
  }
  /* Report Job Failed if DED has occurred */
  else
  {
    /* Implements FLS_ESDD_UD_130 */
    /* Report error to DEM that read job failed due to double bit error */
    Dem_ReportErrorStatus(FLS_E_READ_FAILED_DED, DEM_EVENT_STATUS_FAILED);
    /* Set Job Status as failed */
    LenReturnValue = MEMIF_JOB_FAILED;
  }

  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);

  return(LenReturnValue);
 } /* End of function Fls_FastReadCheckECC */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_SetStartEndAddr
**
** Service ID               : NA
**
** Description              : This function will Set Erase/Write Start and End
**                            Address
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulStartAdd,LulEndAdd
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R)
**
** Function(s) invoked      : None
**
** Registers Used           : FSADDR,FEADDR
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_082 */
/* Implements EAAR_PN0034_FR_0013,EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0001 */
/* QAC Warning: START Msg(2:3227)-5 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetStartEndAddr(uint32 LulStartAdd,
                                                               uint32 LulEndAdd)
/* END Msg(2:3227)-5 */
{
  P2VAR(volatile Fls_FACIRegType, AUTOMATIC, FLS_CONFIG_DATA) LpFACIRegPtr;
  /* QAC Warning: START Msg(2:2814)-1 */
  LpFACIRegPtr = Fls_GpConfigPtr->pFACIRegPtr;
  /* END Msg(2:2814)-1 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:2814)-1 */
  /* Setting Erase/Write Start and End Address */
  FLS_REG_WRITE(LpFACIRegPtr->ulFSADDR, LulStartAdd)
  /* END Msg(2:2814)-1 */
  /* For write verification */
  /* MISRA Violation: START Msg(4:1290)-9 */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFSADDR, LulStartAdd,
                                FLS_32BIT_MASK_VAL, FLS_SETSTARTENDADDR_API_ID)
  /* END Msg(4:1290)-9 */
  FLS_REG_WRITE(LpFACIRegPtr->ulFEADDR, (LulEndAdd & FEADDR_REG_MASK_VAL))
  /* MISRA Violation: START Msg(4:1290)-9 */
  /* For write verification */
  FLS_REG_WRITE_VERIFY_RUNTIME(LpFACIRegPtr->ulFEADDR,
                      (LulEndAdd & FEADDR_REG_MASK_VAL), FEADDR_REG_MASK_VAL,
                                                   FLS_SETSTARTENDADDR_API_ID)
  /* END Msg(4:1290)-9 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
}
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_CancelInternal
**
** Service ID               : NA
**
** Description              : This Function cancels the on going job. The driver
**                            state is set to MEMIF_IDLE and the job result to
**                            MEMIF_JOB_CANCELED if a job is currently
**                            being processed.
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
** Global Variables Used    : Fls_GstBackUpVar.enGenCommand(RW),
**                            Fls_GenJobResult(RW),Fls_GblTimeOutMonitor(W)
**
** Function(s) invoked      : Fls_ProcessCancel, Dem_ReportErrorStatus
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_080 */
/* Implements FLS336,FLS033,FLS352,FLS260,FLS006 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0022 */
FUNC(void, FLS_PRIVATE_CODE) Fls_CancelInternal(void)
{
  /* Implements FLS_ESDD_UD_139 */
  /* Local variable to hold the FLS command to be cancelled */
  Fls_CommandType LenCmdToCancel;

  /* Determine the FLS command to be cancelled */
  #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
  if (FLS_COMMAND_NONE != Fls_GstBackUpVar.enGenCommand)
  {
    LenCmdToCancel = Fls_GstBackUpVar.enGenCommand;
  }
  else
  #endif /* #if ((FLS_SUSPEND_API == STD_ON) || \
                                      (FLS_RESUME_API == STD_ON))) */
  {
    LenCmdToCancel = Fls_GstVar.enGenCommand;
  }
  switch (LenCmdToCancel)
  {
  case FLS_COMMAND_ERASE:
  case FLS_COMMAND_WRITE:
  case FLS_COMMAND_BLANKCHECK:
         /* Call Fls_ProcessCancel to Stop the FCU processing */
         Fls_ProcessCancel();
         #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
         /* Disable relevant interrupts to protect this critical section */
         FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
         #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
         /* Set the Driver State to IDLE */
         Fls_GenState = MEMIF_IDLE;
         if (FLS_FCU_CANCELED == Fls_GstVar.enDFStatus)
         {
           /* Set the Job Result to MEMIF_JOB_CANCELED */
           Fls_GenJobResult = MEMIF_JOB_CANCELED;
         }
         else
         {
           Dem_ReportErrorStatus(FLS_E_HW_FAILURE,DEM_EVENT_STATUS_FAILED);
           /* Set the Job Result to MEMIF_JOB_FAILED */
           Fls_GenJobResult = MEMIF_JOB_FAILED;
         }

         #if (FLS_TIMEOUT_MONITORING == STD_ON)
         /* Clear the Global Time out Monitor */
         Fls_GblTimeOutMonitor = FLS_FALSE;
         #endif /* FLS_TIMEOUT_MONITORING == STD_ON */

         #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
         /* Enable relevant interrupts to exit this critical section */
         FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
         #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
         break;
  case FLS_COMMAND_READ:
  case FLS_COMMAND_COMPARE:
  case FLS_COMMAND_READ_IMM:
         #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
         /* Disable relevant interrupts to protect this critical section */
         FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
         #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
         /* Set the Driver State to IDLE */
         Fls_GenState = MEMIF_IDLE;
         /* Set the Job Result to MEMIF_JOB_CANCELED */
         Fls_GenJobResult = MEMIF_JOB_CANCELED;
         #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
         /* Enable relevant interrupts to exit this critical section */
         FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
         #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
         break;
  /* MISRA Violation: START Msg(2:2016)-6 */
  default:
         /* No action required */
         break;
  }
  /* END Msg(2:2016)-6 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Clear the Command Variable */
  Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
}
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_EraseInternal
**
** Service ID               : NA
**
** Description              : This function will initiate Erase job and
**                            also does further processing required when the
**                            sequences of requests for suspension is allowed
**                            when SUSPEND API is ON.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : TargetAddress, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: If Erase command has been accepted.
**                            E_NOT_OK: If Erase command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.ulJobEndAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.ulJobStartAddress(R),
**                            Fls_GpConfigPtr(R),Fls_GenJobResult(W)
**                            Fls_GenState(W)
**
** Function(s) invoked      : Det_ReportError,Fls_GetIntReq,Fls_ClearIntReq,
**                            Fls_SuspendPreCheck,Fls_InitiateEraseJob,
**                            Fls_ProcessJobResult
**
** Registers Used           : IMRn
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_081 */
/* Implements FLS023,FLS282_Conf,FLS312,FLS261,FLS164 */
/* Implements EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023 */
/* QAC Warning: START Msg(2:3227)-5 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE)Fls_EraseInternal
                          (Fls_AddressType TargetAddress, Fls_LengthType Length)
/* END Msg(2:3227)-5 */
{
  /* Local variable to hold the return value */
  Std_ReturnType LenReturnValue;

  /* Adjusting the End Address to multiples of Block Size */
  if ((uint32)FLS_ZERO != (Length & ((uint32)FLS_DF_BLOCK_SIZE -
                                                    (uint32)FLS_ONE)))
  {
    Length = (Length + ((uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE)) &
                            (~((uint32)(FLS_DF_BLOCK_SIZE - FLS_ONE)));
    Fls_GstVar.ulJobEndAddress = (TargetAddress + Length) -
                                                            (uint32)FLS_ONE;
  }
  else
  {
    /* No action required */
  }

  /* Copy the adjusted Job length to Fls_GstVar structure */
  Fls_GstVar.ulRequestedLength = Length;

  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  /* Store the Job address for Fls_InitiateBlankCheckJob() */
  Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulJobStartAddress;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */

  #if (FLS_INTERRUPT_MODE == STD_ON)
  Fls_GetIntReq();
  Fls_ClearIntReq();
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Enable interrupt processing */
  RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                                             (Fls_GpConfigPtr->usFlEndImrMask));
  /* END Msg(2:2814)-2 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
  /* Set the command as Erase command */
  Fls_GstVar.enGenCommand = FLS_COMMAND_ERASE;
  #if (FLS_SUSPEND_API == STD_ON)
  LenReturnValue = Fls_SuspendPreCheck(FLS_COMMAND_ERASE);

  if (E_OK == LenReturnValue)
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  {
    /* Implements FLS_ESDD_UD_102 */
    /* Initiate Erase Job */
    LenReturnValue = Fls_InitiateEraseJob();
  }
  #if (FLS_SUSPEND_API == STD_ON)
  else
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_120 */
    /* Report to DET if Write/Erase Job is previously suspended */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                     FLS_ERASE_SID, FLS_E_BUSY);
    #endif
  }
  #endif /* #if ((FLS_SUSPEND_API == STD_ON) && \
                                            (FLS_DEV_ERROR_DETECT == STD_ON)) */

  return(LenReturnValue);
}/* End of function Fls_EraseInternal */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name             : Fls_WriteInternal
**
** Service ID                : NA
**
** Description               : This function will initiate write job when the
**                             sequences of requests for suspension is allowed.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: if Write command has been accepted.
**                             E_NOT_OK: if Write command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GpConfigPtr(R),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GenJobResult(W),Fls_GenState(W)
**
** Function(s) invoked       : Det_ReportError,Fls_InitiateWriteJob,
**                             Fls_ProcessJobResult,Fls_SuspendPreCheck,
**                             Fls_GetIntReq,Fls_ClearIntReq
**
** Registers Used            : IMRn
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_078 */
/* Implements FLS312,FLS261,FLS163,FLS161,FLS164 */
/* Implements EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0023 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_WriteInternal(void)
{
  /* Local variable to hold the return value */
  Std_ReturnType LenReturnValue;

  /* Set the command as Write command */
  Fls_GstVar.enGenCommand = FLS_COMMAND_WRITE;

  #if (FLS_INTERRUPT_MODE == STD_ON)
  /* Get interrupt request flag */
  /* Clear interrupt request flag */
  Fls_GetIntReq();
  Fls_ClearIntReq();
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Enable interrupt processing */
  RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                                             (Fls_GpConfigPtr->usFlEndImrMask));
  /* END Msg(2:2814)-2 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_SUSPEND_API == STD_ON)
  LenReturnValue = Fls_SuspendPreCheck(FLS_COMMAND_WRITE);

  if (E_OK == LenReturnValue)
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  {
    /* Initiate Write Job */
    LenReturnValue = Fls_InitiateWriteJob();
  }
  #if (FLS_SUSPEND_API == STD_ON)
  else
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_120 */
    /* Report to DET if Write Job is previously suspended */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                     FLS_WRITE_SID, FLS_E_BUSY);
    #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  }
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */

  return(LenReturnValue);
}/* End of function Fls_WriteInternal */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_BlankCheckInternal
**
** Service ID                : NA
**
** Description               : This function will initiate process required to
**                             perform blank check operation on a specified Data
**                             Flash area.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: if Read command has been accepted.
**                             E_NOT_OK: if Read command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GblFlashEnable(W),Fls_GpConfigPtr(R)
**                             Fls_GulTimeOutCounter(W)
**
** Function(s) invoked       : Fls_SetFHVE,Fls_GetIntReq,Fls_ClearIntReq,
**                             Fls_InitiateBlankCheckJob,Fls_ProcessJobResult
**
** Registers Used            : IMRn
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_079 */
/* Implements EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_BlankCheckInternal(void)
{
  /* Local variable to hold the return value */
  Std_ReturnType LenReturnValue;

  #if (FLS_FHVE_REGS == SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (FLS_FHVE_REGS == SUPPORTED) */
  #if (FLS_INTERRUPT_MODE == STD_ON)
  Fls_GetIntReq();
  Fls_ClearIntReq();
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* QAC Warning: START Msg(2:2814)-2 */
  /* Enable interrupt processing */
  RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                                             (Fls_GpConfigPtr->usFlEndImrMask));
  /* END Msg(2:2814)-2 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */

  /* Initiate blank check Job */
  LenReturnValue = Fls_InitiateBlankCheckJob();

  /* Check for the status is FLS_FCU_OK */
  if (E_NOT_OK == LenReturnValue)
  {
    Fls_ProcessJobResult(MEMIF_JOB_FAILED);
  }
  else
  {
  /* No action required */
  }
  return(LenReturnValue);
}
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
**                           End of File                                      **
*******************************************************************************/
