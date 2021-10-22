/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Fls Driver Component.            */
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
 * V1.0.0:  15-Feb-2016  : Initial Version
 *
 * V1.0.1:  18-Mar-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made :
 *                         1. As part of ARDAAAE-1597, updated Fls_Init API to
 *                            remove the DET switch of the global variable
 *                            Fls_GblInitStatus and updated Fls_MainFunction API
 *                            after adding the pre-compile switch for DET inside
 *                            the check for module initialisation.
 *                         2. As part of ARDAAAE-1697, updated Fls_Cancel,
 *                            Fls_Read, Fls_Suspend, Fls_Resume APIs to correct
 *                            the saving/restoring/clearing of RFxxx bit in
 *                            ICxxx register.
 *                         3. As part of ARDAAAE-1631, updated
 *                            Fls_Init to initialise the suspend request flag,
 *                            and updated Fls_Suspend API to make it
 *                            asynchronous.
 *                         4. Function banner and comments of all APIs have
 *                            been updated.
 *                         5. Access information read, write and read-write
 *                            (R, W, RW) are provided for Global Variables
 *                            in function banner.
 *                         6. Updated Fls_Init API after removing global
 *                            pointers Fls_GpFACIRegPtr and Fls_GpECCRegPtr.
 *                         7. Fls_Init API has been updated to rename the global
 *                            variable Fls_VerifyCompletedJob to
 *                            Fls_GblVerifyCompletedJob and declaration and
 *                            initialisation of variable LenReturnValue has been
 *                            done in separate lines.
 *                         8. Fls_Cancel API is updated to report the DEM
 *                            FLS_E_HW_FAILURE when Fls_ProcessCancel function
 *                            sets Data Flash as FLS_FCU_ERR_INTERNAL.
 *                            and driver status has been updated for the same.
 *                         9. Fls_Erase and Fls_Write APIs have been updated to
 *                            load the time-out count value to
 *                            Fls_GulTimeOutCounter global variable.
 *                         10.As part of ARDAAAE-1691, added command check for
 *                            erase and write in Fls_Suspend API.
 *                         11.QAC warning START and END msgs for Msg(2:2016)
 *                            ,Msg(2:2814),Msg(2:3204),Msg(2:3892),Msg(2:3227),
 *                            Msg(2:0862) are added at the respective places.
 * V1.0.2:  05-May-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made :
 *                         1. As per Jira ID ARDAAAE-1715, to reduce exceeding
 *                            metrics values, APIs Fls_Write,Fls_BlankCheck,
 *                            Fls_Cancel and Fls_Erase divided to
 *                            Fls_WriteInternal, Fls_BlankCheckInternal,
 *                            Fls_CancelInternal and Fls_EraseInternal
 *                            respectively.
 *                         2. Critical section protection is added for IMR
 *                            register in Fls_Cancel.
 *                         3. As per Jira ID ARDAAAE-1910, the pointer analysis
 *                            tags are added.
 *                         4. As per Jira ID ARDAAAE-1908, removed dead code.
 *                         5. Initialized variable 'Fls_GulTimeOutCounter' with
 *                            FLS_TIMEOUT_INIT_VALUE macro.
 *                         6. As per Jira ID ARDAAAE-1982, address boundary
 *                            check and alignment check modified in Fls_Erase,
 *                            Fls_Write, Fls_BlankCheck, Fls_ReadImmediate,
 *                            Fls_Compare and Fls_Read APIs.
 *                         7. Pre-compile switch for DET is made inside the
 *                            condition check.
 *                         8. Return value check is added in Fls_Erase,
 *                            Fls_Write and Fls_BlankCheck APIs.
 *                         9. File "Fls_RegWrite.h" is included.
 *                         10.Updated register write verify implementation.
 *                         11.As per JIRA ID ARDAAAAE-2010, removed register
 *                            write verify for IMR register.
 *                         12.Placed the constant value on the left side of
 *                            the comparison operator.
 *                         13.QAC warning START and END msgs for Msg(2:3204)
 *                            are removed as this warning is fixed and added
 *                            justification for misra warning 4:0857.
 * V1.0.3:  31-Aug-2016  : Following changes are made:
 *                         1. As per JIRA ID ARDAAAE-1996, updated data type
 *                            for "TargetAddressPtr" in Fls_Read and
 *                            Fls_ReadImmediate APIs.
 *                         2. As per JIRA ID ARDAAAE-2029, parameter "LenMode"
 *                            check is added.
 *                         3. As per JIRA ID ARDAAAE-2026, corrected naming
 *                            convention of variables as per requirement
 *                            EAAR_PN0084_NR_0066.
 *                         4. Added justification for QAC warning Msg(2:1475).
 *                         5. As per JIRA ID ARDAAAE-2013, updated
 *                            "registers used" in function banner of
 *                            Fls_Cancel and Fls_Resume.
 *                         6. QAC warning Msg(2:3416) and Misra warning
 *                            Msg(4:3415) are added at the respective places.
 *                         7. As per JIRA ID ARDAAAE-2060, added requirement
 *                            which is missed to trace in code.
 *                         8. Incorrect requirements trace removed.
 * V1.0.4:  25-Jan-2017  : Following changes are made:
 *                         1. As part of JIRA ID ARDAAAE-2053,elements of
 *                            structure "Fls_GstVarProperties" are renamed.
 *                         2. Copyright information is updated.
 *                         3. As part of JIRA ID ARDAAAE-2289,call of
 *                            Fls_TimeOutCheckAndProcessing() is moved into the
 *                            command switch case for erase, write and blank
 *                            check.
 *                         4. As part of JIRA ID ARDAAAE-2274
 *                            removed unnecessary mapping of requirements
 *                            AR_PN0040_FR_0017 and EAAR_PN0034_FR_0017.
 *                         5. As part of JIRA ID ARDAAAE-2274
 *                            Message tag for Msg(4:0857) added in AUTOSAR
 *                            release version information and Fls_Init API.
 * V1.0.5:  27-Apr-2017 : Following change is made:
 *                        Relocated end message tag 'END Msg(4:0857)-6' as part
 *                        of fixing static analysis warning.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements FLS107,FLS159,FLS179,FLS308,FLS309,FLS248,FLS320,FLS322 */
/* Implements FLS321,FLS354 */
/* Implements EAAR_PN0034_FR_0001 */
/* Included for module version information and other types declarations */
#include "Fls.h"
/* Included for the macro declaration of supervisor mode(SV) write enabled
    Registers IMR */
#include "rh850_Types.h"
/* Included prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Internal.h"
/* Included for RAM variable declarations */
#include "Fls_Ram.h"
/* Implements FLS160 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
/* Included prototypes for FCU functions of Flash Wrapper Component */
#include "Fls_Private_Fcu.h"
/* Included for Prototype Declaration for Callback Notification functions */
#include "Fls_Cbk.h"
#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Fls.h"
#endif  /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/* Implements FLS_ESDD_UD_083,FLS163 */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
/* MISRA Violation: START Msg(4:0857)-6 */
#define FLS_C_AR_RELEASE_MAJOR_VERSION     FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_C_AR_RELEASE_MINOR_VERSION     FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_C_AR_RELEASE_REVISION_VERSION  FLS_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLS_C_SW_MAJOR_VERSION      1
#define FLS_C_SW_MINOR_VERSION      0
/* END Msg(4:0857)-6 */
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements FLS364 */
#if (FLS_AR_RELEASE_MAJOR_VERSION != FLS_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls.c : Mismatch in Release Major Version"
#endif

#if (FLS_AR_RELEASE_MINOR_VERSION != FLS_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls.c : Mismatch in Release Minor Version"
#endif

#if (FLS_AR_RELEASE_REVISION_VERSION != FLS_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls.c : Mismatch in Release Revision Version"
#endif

#if (FLS_SW_MAJOR_VERSION != FLS_C_SW_MAJOR_VERSION)
  #error "Fls.c : Mismatch in Software Major Version"
#endif

#if (FLS_SW_MINOR_VERSION != FLS_C_SW_MINOR_VERSION)
  #error "Fls.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : The expression has no reliance on the effects of integral  */
/*                 promotion.                                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-1 and                           */
/*                 END Msg(4:4397)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0310)-2 and                           */
/*                 END Msg(4:0310)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) [I] Cast between a pointer to object and an       */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : The input addresses specified by the pointers are converted*/
/*                 to addresses for storing into the registers and for        */
/*                 reading purposes.                                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-3 and                           */
/*                 END Msg(4:0306)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 13.7                                          */
/* Justification : Condition check is for all use cases and the warning is    */
/*                 for only particular configuration.                         */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:2996)-4 and                           */
/*                 END Msg(4:2996)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation appears to be redundant because a  */
/*                 given constant value can always be used instead.           */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The result of the operation depends on the configuration   */
/*                 parameters, the value of the result may vary depending on  */
/*                 the configuration used.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-5 and                           */
/*                 END Msg(4:2984)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-6 and                           */
/*                 END Msg(4:0857)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3673)The object addressed by the pointer parameter      */
/*                 is not modified and so the pointer could be of type        */
/*                 'pointer to const'.                                        */
/* Rule          : MISRA-C:2004 Rule 16.7                                     */
/* Justification : pointer variable is used to modify the value at the address*/
/*                 so the pointer cannot be declared as 'pointer to const'    */
/*                 type.                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3673)-7 and END Msg(4:3673)-7 tags    */
/*                 in the code.                                               */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3415)Right hand operand of '&&' or '||' is an           */
/*                 expression with possible side effects.                     */
/* Rule          : MISRA-C:2004 Rule 12.4                                     */
/* Justification : The left hand operand of '&&' is not always false and left */
/*                 hand operand of '||' is not always true.                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3415)-8 and END Msg(4:3415)-8 tags    */
/*                 in the code.                                               */
/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Justification : The function parameters of AUTOSAR APIs cannot be modified */
/*                 to be made as constant.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-1 and END Msg(2:3227)-1 tags in */
/*                 the code.                                                  */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Justification : The Pointers generated using Post Build configurations may */
/*                 not be NULL.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-2 and END Msg(2:2814)-2 tags in */
/*                 the code.                                                  */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-3 and END Msg(2:2016)-3 tags in */
/*                 the code.                                                  */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:0862) #include "MemMap.h" directive is redundant.       */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(2:3892)-5 and END Msg(2:3892)-5 tags in */
/*                 the code.                                                  */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : Msg(2:1475) Range of possible enum values suggests this    */
/*                 test is always true.                                       */
/* Justification : Value of this variable depends on user input that may make */
/*                 this test false.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1475)-6 and END Msg(2:1475)-6 tags    */
/*                 in the code.                                               */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-7 and END Msg(2:3416)-7         */
/*                 tags in the code.                                          */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name             : Fls_Init
**
** Service ID                : 0x00
**
** Description               : This API performs the initialization of the FLS
**                             Driver Component.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : ConfigPtr
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GenState(RW), Fls_GenJobResult(RW),
**                             Fls_GstVar.enGenCommand(W), Fls_GpConfigPtr(W),
**                             Fls_GstVar.ulRequestedLength(W),
**                             Fls_GstVar.ulCurrentLength(W),
**                             Fls_GblFlashEnable(W), Fls_GblInitStatus(W),
**                             Fls_GstVar.ucOffset(W),
**                             Fls_GstVar.enReadType(W),Fls_GenCurrentMode(W)
**                             Fls_GblVerifyCompletedJob,
**                             Fls_GstVar.enDFStatus(RW)
**                             Fls_GulTimeOutCounter(W),
**                             Fls_GblJobSuspendRequest(W)
**
** Function(s) invoked       : Det_ReportError,Fls_FcuInit,Fls_PreFcuInitCheck,
**                             Fls_SetFHVE,Fls_ClearBackUpData
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-6 */
#define FLS_START_SEC_PUBLIC_CODE
/* END Msg(4:0857)-6 */
#include "MemMap.h"
/* Implements FLS_ESDD_UD_001 */
/* Implements FLS_ESDD_UD_110 */
/* Implements FLS_ESDD_UD_136 */
/* Implements FLS_ESDD_UD_112 */
/* Implements FLS_ESDD_UD_135 */
/* Implements FLS014,FLS249,FLS268,FLS323,FLS015,FLS351,FLS324,FLS086,FLS191 */
/* Implements FLS015,FLS048,FLS109,FLS287_Conf,FLS077,FLS162,FLS310,FLS311 */
/* Implements FLS312,FLS261,FLS355,FLS350,FLS144,FLS163,FLS161,FLS164 */
/* Implements AR_PN0072_FR_0010,AR_PN0072_FR_0009,AR_PN0072_FR_0022 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0059, AR_PN0072_FR_0023 */
/* Implements EAAR_PN0034_FR_0025 */
FUNC(void, FLS_PUBLIC_CODE) Fls_Init
/* QAC Warning: START Msg(2:3227)-1*/
(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST) ConfigPtr)
{
  /* END Msg(2:3227)-1*/
  /* Implements FLS_ESDD_UD_083 */
  /* Local variable to hold the return value */
  Std_ReturnType LenReturnValue;
  /* Implements FLS_ESDD_UD_141 */
  /* Local variable to hold the ECC status during Fls_PreFcuInitCheck() */
  Fls_FcuStatusType LenECCStatus;
  Fls_GstVar.enDFStatus = FLS_FCU_ERR_REJECTED;
  LenReturnValue = E_OK;
  /* Check if the Configuration pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements FLS_ESDD_UD_115 */
    /* Implements FLS_ESDD_UD_094 */
    /* Report Error to Det */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                            FLS_INIT_SID, FLS_E_PARAM_CONFIG);
    #endif
    /* Reset return value to E_NOT_OK due to failure */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* MISRA Violation: START Msg(4:4397)-1 */
    if (FLS_DBTOC_VALUE != (ConfigPtr->ulStartOfDbToc))
    {
     /* END Msg(4:4397)-1 */
      /* Implements FLS_ESDD_UD_124 */
      /* Report Error to DET */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                             FLS_INIT_SID, FLS_E_INVALID_DATABASE);
      #endif
      /* Reset return value to E_NOT_OK due to failure */
      LenReturnValue = E_NOT_OK;
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
  /* QAC Warning: START Msg(2:3416)-7 */
  if (MEMIF_BUSY == Fls_GenState)
  /* END Msg(2:3416)-7 */
  {
    /* Implements FLS_ESDD_UD_120 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET that the driver is currently busy */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                  FLS_INIT_SID, FLS_E_BUSY);
    #endif
    /* Reset return value to E_NOT_OK due to failure */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
     /* No action required */
  }
  if (E_OK == LenReturnValue)
  {
    /* Assign the Config pointer value to global pointer */
    Fls_GpConfigPtr  = ConfigPtr;
    /* Verify ECC control register settings */
    LenECCStatus = Fls_PreFcuInitCheck();
    /* Data flash initialization */
    Fls_FcuInit();
    /* Check the Result of Environment Preparation */
    if ((FLS_FCU_OK == Fls_GstVar.enDFStatus)&&(FLS_FCU_OK == LenECCStatus))
    {
      /* Initialize the global variable offset to zero */
      Fls_GstVar.ucOffset = FLS_ZERO;
      Fls_GstVar.enReadType = FLS_MISALIGNED_READ;
      /* Set the driver status to idle */
      Fls_GenState = MEMIF_IDLE;
      /* set the job result as OK */
      Fls_GenJobResult = MEMIF_JOB_OK;
      /* Initialize the global variable general command to None */
      Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Initialize the Driver Mode with configured Default Mode */
      Fls_GenCurrentMode = Fls_GpConfigPtr->ddDefaultMode;
      /* END Msg(2:2814)-2 */
      #if (FLS_TIMEOUT_MONITORING == STD_ON)
      Fls_GulTimeOutCounter = FLS_TIMEOUT_INIT_VALUE;
      #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON)*/
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      Fls_GblVerifyCompletedJob = FLS_FALSE;
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */

      /* Initialize the global variables requested length and current length
         length to zero. */
      Fls_GstVar.ulRequestedLength = (uint32)FLS_ZERO;
      Fls_GstVar.ulCurrentLength = (uint32)FLS_ZERO;
      #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
      Fls_GblJobSuspended = FLS_FALSE;
      Fls_ClearBackUpData();
      #endif /* #if ((FLS_SUSPEND_API == STD_ON) || \
                                                (FLS_RESUME_API == STD_ON)) */
      #if (FLS_SUSPEND_API == STD_ON)
      Fls_GblJobSuspendRequest = FLS_FALSE;
      #endif /* #if (FLS_SUSPEND_API == STD_ON) */
      /* Enable Write/Erase protection settings */
      #if (FLS_FHVE_REGS == SUPPORTED)
      /* Enable the flash memory software protection */
      Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
      /* Initialize the global variable flash enable to False */
      Fls_GblFlashEnable = FLS_FALSE;
      #endif /* #if (FLS_FHVE_REGS == SUPPORTED) */
      /*
      * Set the driver initialization status as completed.
      */
      Fls_GblInitStatus = FLS_INITIALIZED;
    }
    else
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET if the component is not initialized */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                          FLS_INIT_SID, FLS_E_UNINIT);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
    }
  }
  else
  {
    /* No action required */
  }
} /* End of API Fls_Init */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_Erase
**
** Service ID                : 0x01
**
** Description               : This API will erase the one or more complete
**                             flash sectors.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : TargetAddress, Length
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: If Erase command has been accepted.
**                             E_NOT_OK: If Erase command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GstVar.ulJobStartAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GstVar.enGenCommand(W)
**
** Function(s) invoked       : Det_ReportError,Fls_DetErrorCheck
**                             Fls_EraseInternal
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-6 */
#define FLS_START_SEC_PUBLIC_CODE
/* END Msg(4:0857)-6 */
#include "MemMap.h"
/* Implements FLS_ESDD_UD_002 */
/* Implements FLS218,FLS221,FLS020,FLS015,FLS217,FLS209,FLS001,FLS250,FLS021 */
/* Implements FLS216,FLS330,FLS287_Conf,FLS077,FLS162,FLS298_Conf,FLS283_Conf */
/* Implements FLS280_Conf,FLS282_Conf,FLS208,FLS310,FLS328,FLS329,FLS065 */
/* Implements FLS145,FLS036,FLS345,FLS261,FLS163,FLS161,FLS267,FLS164 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements AR_PN0072_FR_0005,AR_PN0072_FR_0022,AR_PN0072_FR_0023 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0048 */
/* QAC Warning: START Msg(2:3227)-1*/
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Erase
        (Fls_AddressType TargetAddress, Fls_LengthType Length)
{
  /* END Msg(2:3227)-1*/
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Implements FLS_ESDD_UD_074 */
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_ERASE_SID);
  if (E_OK == LenReturnValue)
  {
    /* Implements FLS_ESDD_UD_086 */
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Implements FLS_ESDD_UD_085 */
    /* Implements FLS_ESDD_UD_087 */
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    /* Implements FLS_ESDD_UD_086  */
    /* Implements FLS_ESDD_UD_085  */
    /* Implements FLS_ESDD_UD_087  */
    /* MISRA Violation: START Msg(4:2996)-4 */
    if ((LulLowerTargetAddr > TargetAddress) || \
        (LulUpperTargetAddr < TargetAddress) || ((uint32)FLS_ZERO != \
        (TargetAddress & ((uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE))))
    {
      /* END Msg(4:2996)-4 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
       /* Implements FLS_ESDD_UD_116 */
       /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                        FLS_ERASE_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Calculate the erase start and end addresses */
      Fls_GstVar.ulJobStartAddress = TargetAddress;
      Fls_GstVar.ulJobEndAddress = (TargetAddress + Length) - \
                                                               (uint32)FLS_ONE;

      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Implements FLS_ESDD_UD_086  */
      /* Implements FLS_ESDD_UD_085  */
      /* Implements FLS_ESDD_UD_087  */
      /* check if the erase length is greater than 0 and the erase end address
         is aligned to a flash sector boundary and that it lies within the
         specified upper flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((Fls_GstVar.ulJobEndAddress - \
          (uint32)FLS_DF_SECTOR_START_ADDRESS) + (uint32)FLS_ONE) > \
          (uint32)FLS_DF_TOTAL_SIZE) || ((uint32)FLS_ZERO !=  \
          ((TargetAddress + Length) & \
                                ((uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE))))
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Implements FLS_ESDD_UD_117 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                             FLS_ERASE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Reset return value to E_NOT_OK due to failure */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      if (E_OK == LenReturnValue)
      {
        /* Invoke Fls_EraseInternal to do the remaining processing required
           after DET check for Erase functionality */
        LenReturnValue = Fls_EraseInternal(TargetAddress, Length);
        /* Check for the status is FLS_FCU_OK */
        if (E_NOT_OK == LenReturnValue)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        }
        else
        {
          /* Set the job result to Job pending */
          Fls_GenJobResult = MEMIF_JOB_PENDING;
          /* Set the driver state as Busy */
          Fls_GenState = MEMIF_BUSY;
        }
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
}/* End of API Fls_Erase */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name             : Fls_Write
**
** Service ID                : 0x02
**
** Description               : This API performs programming of one or more
**                             complete flash pages of the flash device. The
**                             data from input buffer (source address) is
**                             written to the flash pointed by the target offset
**                             .The target address must be aligned to flash page
**                             boundary.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : TargetAddress, SourceAddressPtr, Length
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
** Global Variables Used     : Fls_GstVar.pBufferAddress(W),
**                             Fls_GstVar.ulRequestedLength(W),
**                             Fls_GstVar.ulJobStartAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GstVar.ulCurrentLength(W)
**
** Function(s) invoked       : Det_ReportError, Fls_DetErrorCheck,
**                             Fls_WriteInternal
**
** Registers Used            : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-6 */
#define FLS_START_SEC_PUBLIC_CODE
/* END Msg(4:0857)-6 */
#include "MemMap.h"
/* Implements FLS_ESDD_UD_003 */
/* Implements FLS_ESDD_UD_137 */
/* Implements FLS_ESDD_UD_138 */
/* Implements FLS001,FLS209,FLS223,FLS251,FLS332,FLS333,FLS334,FLS002,FLS226 */
/* Implements FLS026,FLS027,FLS157,FLS146,FLS003,FLS287_Conf,FLS077,FLS162 */
/* Implements FLS283_Conf,FLS281_Conf,FLS282_Conf,FLS208,FLS310,FLS036,FLS345 */
/* Implements FLS261,FLS163,FLS161,FLS267,FLS164 */
/* Implements AR_PN0072_NR_0004,AR_PN0072_NR_0011,AR_PN0072_FR_0022 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0044,AR_PN0072_FR_0023,AR_PN0072_FR_0048 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FR_0013 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Write
/* QAC Warning: START Msg(2:3227)-1*/
(Fls_AddressType TargetAddress,
P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) SourceAddressPtr,
Fls_LengthType Length)
/* END Msg(2:3227)-1*/
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_WRITE_SID);
  if (E_OK == LenReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the write start address is aligned to a flash page boundary
     * and lies within the specified lower and upper flash address
     * boundaries
     */
    /* MISRA Violation: START Msg(4:2996)-4 */
    /* Implements FLS_ESDD_UD_088 */
    if ((LulLowerTargetAddr > TargetAddress) || \
        (LulUpperTargetAddr < TargetAddress) || ((uint32)FLS_ZERO != \
                 (TargetAddress & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE))))
    {
      /* END Msg(4:2996)-4 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Implements FLS_ESDD_UD_116 */
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                          FLS_WRITE_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Get the write start and end address */
      Fls_GstVar.ulJobStartAddress = TargetAddress;
      Fls_GstVar.ulJobEndAddress = (TargetAddress + Length) - \
                                                               (uint32)FLS_ONE;
      /* Set the global variable with length */
      Fls_GstVar.ulCurrentLength = Length;
      /* Set the global variable with application buffer pointer */
      Fls_GstVar.pBufferAddress = SourceAddressPtr;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Implements FLS_ESDD_UD_088 */
      /* Implements FLS_ESDD_UD_085 */
      /* Implements FLS_ESDD_UD_087 */
      /* check if the write length is greater than 0 and the write end address
         is aligned to a flash page boundary and that it lies within the
         specified upper flash address boundary.
       */
      if ((Length == (uint32)FLS_ZERO) || (((TargetAddress + Length) & \
          ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE)) != (uint32)FLS_ZERO) || \
          (((Fls_GstVar.ulJobEndAddress -  \
          (uint32)FLS_DF_SECTOR_START_ADDRESS) + (uint32)FLS_ONE) > \
                                                     (uint32)FLS_DF_TOTAL_SIZE))
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Implements FLS_ESDD_UD_117 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                           FLS_WRITE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Check whether the application buffer is a null pointer */
      if (NULL_PTR == SourceAddressPtr)
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Implements FLS_ESDD_UD_118 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                             FLS_WRITE_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Check whether any error is reported to DET */
      if (E_OK == LenReturnValue)
      {
        /* Invoke Fls_WriteInternal to do the remaining processing required
           after DET check for Write functionality */
        LenReturnValue = Fls_WriteInternal();
        /* Check for the status is FLS_FCU_OK */
        if (E_NOT_OK == LenReturnValue)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED);
        }
        else
        {
          /* Set the job result to Job pending */
          Fls_GenJobResult = MEMIF_JOB_PENDING;
          /* Set the driver state as Busy */
          Fls_GenState = MEMIF_BUSY;
        }
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
}/* End of API Fls_Write */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_090 */
#if (FLS_CANCEL_API == STD_ON)
/*******************************************************************************
** Function Name             : Fls_Cancel
**
** Service ID                : 0x03
**
** Description               : This API cancels the on going job.
**
** Sync/Async                : Synchronous
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
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GblInitStatus(R),Fls_GpConfigPtr(W),
**                             Fls_GenJobResult(R),Fls_GblJobSuspended(W),
**                             Fls_GstBackUpVar.enGenCommand(R)
**
** Function(s) invoked       : Det_ReportError, Fls_CancelInternal,
**                             Fls_CallJobNotification,
**                             Fls_ClearIntReq, Fls_ClearBackUpData
**
** Registers Used            : IMRn
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_004 */
/* Implements FLS229,FLS252,FLS356,FLS147,FLS183,FLS287_Conf,FLS077,FLS162 */
/* Implements FLS285_Conf,FLS310,FLS311,FLS230,FLS335,FLS261,FLS144,FLS163 */
/* Implements FLS267,FLS164 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0011 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0067 */
/* Implements EAAR_PN0034_FR_0023,EAAR_PN0034_FR_0013 */
FUNC(void, FLS_PUBLIC_CODE) Fls_Cancel(void)
{
  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    /* Implements FLS_ESDD_UD_119 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                  FLS_CANCEL_SID, FLS_E_UNINIT);
    #endif
  }
  else
  {
    /* Cancel Job only if the job is pending */
    #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
    /* QAC Warning: START Msg(2:3416)-7 */
    if ((MEMIF_JOB_PENDING == Fls_GenJobResult)  ||
                 (FLS_COMMAND_NONE != Fls_GstBackUpVar.enGenCommand))
    #else
    if (MEMIF_JOB_PENDING == Fls_GenJobResult)
    /* END Msg(2:3416)-7 */
    #endif /* #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON)) */
    {
      #if (FLS_INTERRUPT_MODE == STD_ON)
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:4397)-1 */
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Disable interrupt processing */
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                                 ~(Fls_GpConfigPtr->usFlEndImrMask));
      /* END Msg(2:2814)-2 */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_REGISTER_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* END Msg(4:4397)-1 */
      Fls_ClearIntReq();
      #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
      /* Invoke Fls_CancelInternal to do the remaining processing required for
      Cancel functionality */
      Fls_CancelInternal();
      #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
      /* If job ended with error and call the JOB end call back function */
      Fls_CallJobNotification();
      #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
      #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
      /* Clear any Suspended Job */
      Fls_GblJobSuspended = FLS_FALSE;
      Fls_ClearBackUpData();
      #endif /* #if ((FLS_SUSPEND_API == STD_ON) || \
                                                 (FLS_RESUME_API == STD_ON)) */
    }
    else
    {
      /* No action required */
    }
  }
} /* End of API Fls_Cancel */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_CANCEL_API == STD_ON) */

/* Implements FLS_ESDD_UD_093 */
#if (FLS_GET_STATUS_API == STD_ON)
/*******************************************************************************
** Function Name             : Fls_GetStatus
**
** Service ID                : 0x04
**
** Description               : This API Returns the FLS module state
**                             synchronously.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : MemIf_StatusType
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GblInitStatus(R),Fls_GenState(R)
**
** Function(s) invoked       : Det_ReportError
**
** Registers Used            : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements FLS_ESDD_UD_005 */
/* Implements FLS253,FLS034,FLS357,FLS184,FLS287_Conf,FLS077,FLS162 */
/* Implements FLS290_Conf,FLS311,FLS261,FLS144,FLS163,FLS161,FLS164 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0012 */
FUNC(MemIf_StatusType, FLS_PUBLIC_CODE) Fls_GetStatus(void)
{
  /* Local variable to hold the driver status */
  MemIf_StatusType LenStatus;
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Set local variable with the default return value */
  LenStatus = MEMIF_UNINIT;
  /* Set local variable with the default DET return value */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    /* Implements FLS_ESDD_UD_119 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                            FLS_GET_STATUS_SID, FLS_E_UNINIT);
    #endif
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (LenReturnValue == E_OK)
  {
    /* Read the current state of the driver */
    LenStatus = Fls_GenState;
  }
  else
  {
    /* No action required */
  }
  /* return the current state of the driver */
  return(LenStatus);
} /* End of API Fls_GetStatus */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* End of #if (FLS_GET_STATUS_API == STD_ON) */

/* Implements FLS_ESDD_UD_097 */
#if (FLS_GET_JOB_RESULT_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_GetJobResult
**
** Service ID               : 0x05
**
** Description              : This API returns the result of the last job.
**                            All erase, write, read and compare jobs share the
**                            same job result. Every new job accepted by the
**                            flash driver  overwrites the job result with
**                            MEMIF_JOB_PENDING.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GblInitStatus(R),Fls_GenJobResult(R)
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_006 */
/* Implements FLS254,FLS358,FLS035,FLS185,FLS287_Conf,FLS077,FLS162 */
/* Implements FLS289_Conf,FLS261,FLS164 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0013 */
FUNC(MemIf_JobResultType, FLS_PUBLIC_CODE) Fls_GetJobResult(void)
{
  /* Local variable to hold the job result */
  MemIf_JobResultType LenJobResult;
  /* Declare the variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Set local variable with the default value */
  LenJobResult = MEMIF_JOB_FAILED;
  /* Set the default DET return value */
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    /* Implements FLS_ESDD_UD_119 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                         FLS_GET_JOB_RESULT_SID, FLS_E_UNINIT);
    #endif
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  {
    /* Read the job status */
    LenJobResult = Fls_GenJobResult;
  }
  else
  {
    /* No action required */
  }
  /* Return the job result */
  return(LenJobResult);
} /* End of API Fls_GetJobResult */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* End of #if (FLS_GET_JOB_RESULT_API == STD_ON)*/
/*******************************************************************************
** Function Name            : Fls_MainFunction
**
** Service ID               : 0x06
**
** Description              : This API performs the job processing of erase,
**                            write, read and compare jobs. This API is called
**                            cyclically until the job is processed completely.
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
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GblInitStatus(R),Fls_GblTimeOutMonitor(R),
**                            Fls_GenState(R),Fls_GstVar.enGenCommand(R)
**
** Function(s) invoked      : Det_ReportError,Fls_MainErase,Fls_MainWrite
**                            Fls_MainBlankCheck,Fls_MainRead,Fls_MainCompare
**                            Fls_MainReadImm,Fls_TimeOutCheckAndProcessing
**
** Registers Used           : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-6 */
#define FLS_START_SEC_PUBLIC_CODE
/* END Msg(4:0857)-6 */
#include "MemMap.h"

/* Implements FLS_ESDD_UD_007 */
/* Implements FLS117,FLS196,FLS255,FLS037,FLS038,FLS039,FLS040,FLS235,FLS269 */
/* Implements FLS306_Conf,FLS287_Conf,FLS077,FLS162,FLS292_Conf,FLS311,FLS220 */
/* Implements FLS238,FLS144,FLS164 */
/* Implements AR_PN0072_FR_0015,AR_PN0072_FR_0021,AR_PN0072_FR_0005 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0007,AR_PN0072_FR_0059 */
FUNC(void, FLS_PUBLIC_CODE) Fls_MainFunction(void)
{
  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_119 */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                           FLS_MAINFUNCTION_SID, FLS_E_UNINIT);
    #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* QAC Warning: START Msg(2:3416)-7 */
    /* Check if any job is being processed */
    if (MEMIF_BUSY == Fls_GenState)
    /* END Msg(2:3416)-7 */
    {

      switch (Fls_GstVar.enGenCommand)
      {
      case FLS_COMMAND_ERASE :
              #if (FLS_INTERRUPT_MODE == STD_OFF)
              Fls_MainErase();
              #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

              /* Implements FLS_ESDD_UD_096 */
              #if (FLS_TIMEOUT_MONITORING == STD_ON)
              if (FLS_TRUE == Fls_GblTimeOutMonitor)
              {
                Fls_TimeOutCheckAndProcessing();
              }
              else
              {
                /* No action Required */
              }
              #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
              break;

      case FLS_COMMAND_WRITE :
              #if (FLS_INTERRUPT_MODE == STD_OFF)
              Fls_MainWrite();
              #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

              /* Implements FLS_ESDD_UD_096 */
              #if (FLS_TIMEOUT_MONITORING == STD_ON)
              if (FLS_TRUE == Fls_GblTimeOutMonitor)
              {
                Fls_TimeOutCheckAndProcessing();
              }
              else
              {
                /* No action Required */
              }
              #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
              break;

      case FLS_COMMAND_BLANKCHECK :
              #if (FLS_INTERRUPT_MODE == STD_OFF)
              Fls_MainBlankCheck();
             #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

              /* Implements FLS_ESDD_UD_096 */
              #if (FLS_TIMEOUT_MONITORING == STD_ON)
              if (FLS_TRUE == Fls_GblTimeOutMonitor)
              {
                Fls_TimeOutCheckAndProcessing();
              }
              else
              {
                /* No action Required */
              }
              #endif /* #if (FLS_TIMEOUT_MONITORING == STD_ON) */
              break;

      case FLS_COMMAND_READ :
              Fls_MainRead();
              break;
      /* Implements FLS_ESDD_UD_091 */
      #if (FLS_COMPARE_API == STD_ON)
      case FLS_COMMAND_COMPARE :
              Fls_MainCompare();
              break;
      #endif /* #if (FLS_COMPARE_API == STD_ON) */

      /* Implements FLS_ESDD_UD_098 */
      #if (FLS_READIMMEDIATE_API == STD_ON)
      case FLS_COMMAND_READ_IMM :
              Fls_MainReadImm();
              break;
      #endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */
      /* QAC Warning: START Msg(2:2016)-3 */
      default:
              /* No action required */
              break;
      }
      /* END Msg(2:2016)-3 */
    }
    else
    {
      /* No action required */
    }
  }
} /* End of API Fls_MainFunction */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name            : Fls_Read
**
** Service ID               : 0x07
**
** Description              : This API performs the reading of the flash memory
**                            The data from flash memory (source address) is
**                            read to the data buffer (Target address) of the
**                            application.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, TargetAddressPtr, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W), Fls_GenState(W),
**                            Fls_GenJobResult(W),Fls_GstVar.ucOffset(RW)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheck,Fls_GetIntReq
**                            Fls_ClearIntReq
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_008 */
/* Implements FLS097,FLS339,FLS256,FLS002,FLS236,FLS340,FLS217,FLS001,FLS100 */
/* Implements FLS216,FLS239,FLS338,FLS158,FLS209,FLS240,FLS098,FLS099,FLS003 */
/* Implements FLS287_Conf,FLS077,FLS162,FLS283_Conf,FLS280_Conf,FLS281_Conf */
/* Implements FLS282_Conf,FLS208,FLS310,FLS036,FLS337,FLS345,FLS261,FLS163*/
/* Implements FLS164 */
/* Implements AR_PN0072_FSR_0029,AR_PN0072_FR_0007,AR_PN0072_FR_0008 */
/* Implements AR_PN0072_FR_0022,AR_PN0072_FR_0043,AR_PN0072_FR_0023 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008,AR_PN0072_FR_0048 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Read
/* QAC Warning: START Msg(2:3227)-1*/
/* MISRA Warning: START Msg(4:3673)-7 */
(Fls_AddressType SourceAddress,
P2VAR(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
Fls_LengthType Length)
/* END Msg(4:3673)-7 */
/* END Msg(2:3227)-1*/
{
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_READ_SID);

  if (E_OK == LenReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    /* MISRA Violation: START Msg(4:2996)-4 */
    if ((LulLowerSourceAddr > SourceAddress) || \
                                         (LulUpperSourceAddr < SourceAddress))
    {
      /* END Msg(4:2996)-4 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Implements FLS_ESDD_UD_116 */
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                           FLS_READ_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Reset return value to E_NOT_OK due to failure */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Global variable to hold the read start address */
      Fls_GstVar.ulReadAddress = SourceAddress;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Check if the read length is greater than 0 and that the read end
       * address (read start address + length) lies within the specified upper
       * flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((Fls_GstVar.ulReadAddress - \
          (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > \
                                                     (uint32)FLS_DF_TOTAL_SIZE))
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Implements FLS_ESDD_UD_117 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                              FLS_READ_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        /* Implements FLS_ESDD_UD_118 */
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                FLS_READ_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Check whether any error is reported to DET */
      if (E_OK == LenReturnValue)
      {
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Disable relevant interrupts to protect this critical section */
        FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Set the global variable with length of bytes to be processed */
        Fls_GstVar.ulRequestedLength = Length;
        /* Implements FLS_ESDD_UD_088 */
        /* Get the offset value by masking the source address with page size */
        Fls_GstVar.ucOffset = (uint8)(SourceAddress &
                                          (FLS_PAGE_SIZE - FLS_ONE));
        /* Check whether offset value is not zero */
        if (FLS_ZERO != Fls_GstVar.ucOffset)
        {
          /*
           * Round off the source address value to the page boundary by
           * subtracting the offset value.
           */
          Fls_GstVar.ulReadAddress = SourceAddress -
                                                     Fls_GstVar.ucOffset;
          /* Increment the length with offset value */
          Length = Length + Fls_GstVar.ucOffset;
        }
        else
        {
          /* No action required */
        }
        /* Check whether length is not aligned to the page boundary */
        if ((uint32)FLS_ZERO != (Length & ((uint32)FLS_PAGE_SIZE -
                                                         (uint32)FLS_ONE)))
        {
          /* Implements FLS_ESDD_UD_088 */
          /* Round off the length value to the page boundary */
          Length = Length + ((uint32)FLS_PAGE_SIZE -
                          (Length & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE)));
        }
        else
        {
          /* No action required */
        }
        /* MISRA Violation: START Msg(4:0310)-2 */
        /* QAC Warning: START Msg(2:3892)-5 */
        Fls_GstVar.pTempBufferAddress = (const uint8 *) &
                                               Fls_GulTempBuffer[FLS_ZERO];
        /* END Msg(2:3892)-5 */
        /* END Msg(4:0310)-2 */
        #if (FLS_INTERRUPT_MODE == STD_ON)
        Fls_GetIntReq();
        Fls_ClearIntReq();
        #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the command for Read operation */
        Fls_GstVar.enGenCommand = FLS_COMMAND_READ;
        /* set the driver state to busy */
        Fls_GenState = MEMIF_BUSY;
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enable relevant interrupts to exit this critical section */
        FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
} /* End of API Fls_Read */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_091 */
#if (FLS_COMPARE_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_Compare
**
** Service ID               : 0x08
**
** Description              : This API Fls_Compare shall compare the contents
**                            of an area of flash memory with that of an
**                            application data buffer.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, TargetAddressPtr, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Compare command has been accepted.
**                            E_NOT_OK: if Compare command has not been
**                            accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GenState(W),Fls_GstVar.ulReadAddress(W)
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W),Fls_GenJobResult(W),
**                            Fls_GstVar.ucOffset(RW),
**                            Fls_GstVar.pTempBufferAddress(W)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheck
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_009 */
/* Implements FLS257,FLS241,FLS341,FLS342,FLS343,FLS344,FLS244,FLS150,FLS151 */
/* Implements FLS273,FLS186,FLS209,FLS003,FLS287_Conf,FLS077,FLS162,FLS208 */
/* Implements FLS286_Conf,FLS283_Conf,FLS280_Conf,FLS281_Conf,FLS282_Conf */
/* Implements FLS310,FLS036,FLS345,FLS261,FLS163,FLS161,FLS267,FLS164 */
/* Implements AR_PN0072_FR_0014,AR_PN0072_FSR_0029,AR_PN0072_FR_0022 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0043,AR_PN0072_FR_0023 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Compare
/* QAC Warning: START Msg(2:3227)-1*/
(Fls_AddressType SourceAddress,
P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
Fls_LengthType Length)
/* END Msg(2:3227)-1*/
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_COMPARE_SID);

  if (E_OK == LenReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    /* MISRA Violation: START Msg(4:2996)-4 */
    if ((LulLowerSourceAddr > SourceAddress) || \
                                         (LulUpperSourceAddr < SourceAddress))
    {
      /* END Msg(4:2996)-4 */
      /* Implements FLS_ESDD_UD_116 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                        FLS_COMPARE_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Reset return value to E_NOT_OK due to failure */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;
      /* Initialize the global variable with the source address */
      Fls_GstVar.ulReadAddress = SourceAddress;
      /*
       * Check if the compare length is greater than zero and that the
       * compare end address (compare start address + length) lies
       * within the specified upper flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((Fls_GstVar.ulReadAddress - \
          (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length)
                                                   > (uint32)FLS_DF_TOTAL_SIZE))
      {
        /* Implements FLS_ESDD_UD_117 */
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                           FLS_COMPARE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        /* Implements FLS_ESDD_UD_118 */
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                            FLS_COMPARE_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Check whether any error is reported to DET */
      if (E_OK == LenReturnValue)
      {
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Disable relevant interrupts to protect this critical section */
        FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Set the global variable with length of bytes to be processed */
        Fls_GstVar.ulRequestedLength = Length;

        /* Implements FLS_ESDD_UD_088 */
        /* Get the offset value by masking the source address with page size */
        Fls_GstVar.ucOffset = (uint8)(SourceAddress &
                                          (FLS_PAGE_SIZE - FLS_ONE));
        /* Check whether offset value is not zero */
        if (FLS_ZERO != Fls_GstVar.ucOffset)
        {
          /*
           * Round off the source address value to the page boundary by
           * subtracting the offset value.
           */
          Fls_GstVar.ulReadAddress = SourceAddress -
                                                     Fls_GstVar.ucOffset;
          /* Increment the length with offset value */
          Length = Length + Fls_GstVar.ucOffset;
        }
        else
        {
          /* No action required */
        }
        /* Implements FLS_ESDD_UD_088*/
        /* Check whether length is not aligned to the page boundary */
        if ((uint32)FLS_ZERO != (Length & ((uint32)FLS_PAGE_SIZE -
                                                           (uint32)FLS_ONE)))
        {
          /* Implements FLS_ESDD_UD_088 */
          /* Round off the length value to the page boundary */
          Length = Length + ((uint32)FLS_PAGE_SIZE -
                          (Length & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE)));
        }
        else
        {
          /* No action required */
        }
        /* MISRA Violation: START Msg(4:0310)-2 */
        /* QAC Warning: START Msg(2:3892)-5 */
        Fls_GstVar.pTempBufferAddress = (const uint8 *) &
                                               Fls_GulTempBuffer[FLS_ZERO];
        /* END Msg(2:3892)-5 */
        /* END Msg(4:0310)-2 */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the command as compare command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_COMPARE;
        /* set the driver state to busy */
        Fls_GenState = MEMIF_BUSY;
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enable relevant interrupts to exit this critical section */
        FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
} /* End of API Fls_Compare */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_COMPARE_API == STD_ON) */

/* Implements FLS_ESDD_UD_092 */
#if (FLS_SET_MODE_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_SetMode
**
** Service ID               : 0x09
**
** Description              : This API sets the flash driver operation mode.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : NA
**
** Input Parameters         : Mode
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenCurrentMode(W)
**
** Function(s) invoked      : Fls_DetErrorCheck, Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements FLS_ESDD_UD_010 */
/* Implements FLS258,FLS155,FLS187,FLS291_Conf,FLS318_Conf,FLS164 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0020 */
/* QAC Warning: START Msg(2:3227)-1*/
FUNC(void, FLS_PUBLIC_CODE) Fls_SetMode(MemIf_ModeType LenMode)
/* END Msg(2:3227)-1*/
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_SET_MODE_SID);
  /* Set the Mode if no DET is reported */
  if (E_OK == LenReturnValue)
  {
    /* QAC Warning: START Msg(2:1475)-6*/
    /* Check LenMode has a value within the range */
    if (LenMode <= MEMIF_MODE_FAST)
    /* END Msg(2:1475)-6*/
    {
      Fls_GenCurrentMode = LenMode;
    }
    else
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                         FLS_SET_MODE_SID, FLS_E_PARAM_CONFIG);
      #endif
    }
  }
  else
  {
    /* No action required */
  }
}/* End of API Fls_SetMode */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_SET_MODE_API == STD_ON) */

/* Implements FLS_ESDD_UD_089 */
/* Implements FLS_ESDD_UD_095 */
#if (FLS_VERSION_INFO_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_GetVersionInfo
**
** Service ID               : 0x10
**
** Description              : This API returns the version information of
**                            this module.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : VersioninfoPtr - Pointer to where to store the
**                            version information of this module.
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_011 */
/* Implements FLS259,FLS363,FLS165,FLS166,FLS206,FLS287_Conf,FLS077,FLS162 */
/* Implements FLS293_Conf,FLS267,FLS164 */
/* Implements EAAR_PN0034_FR_0055,EAAR_PN0034_FR_0051 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
FUNC(void, FLS_PUBLIC_CODE) Fls_GetVersionInfo
/* QAC Warning: START Msg(2:3227)-1*/
(P2VAR(Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA)versioninfo)
/* END Msg(2:3227)-1*/
{
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Implements FLS_ESDD_UD_125 */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET  */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                 FLS_GET_VERSION_INFO_SID, FLS_E_PARAM_POINTER);
    #endif
  }
  else
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)FLS_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)FLS_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = FLS_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = FLS_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = FLS_SW_PATCH_VERSION;
  }
}/* End of API Fls_GetVersionInfo */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_VERSION_INFO_API == STD_ON) */

/* Implements FLS_ESDD_UD_098 */
#if (FLS_READIMMEDIATE_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_ReadImmediate
**
** Service ID               : 0x11
**
** Description              : This API performs the reading of the flash
**                            memory. The data from flash memory
**                            (source address) is read to the data buffer
**                            (Target address) of application without
**                            performing blank check before read.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, Length
**
** InOut Parameters         : None
**
** Output Parameters        : TargetAddressPtr
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W),Fls_GenState(W),
**                            Fls_GenJobResult(W),
**
** Function(s) invoked      : Det_ReportError,Fls_ReadMisAlignHandler,
**                            Fls_DetErrorCheck
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_012 */
/* Implements AR_PN0072_FR_0049,AR_PN0072_FSR_0029,AR_PN0072_FR_0022 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0023,AR_PN0072_FR_0048 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
/* Implements FLS287_Conf,FLS077,FLS162,FLS283_Conf,FLS280_Conf,FLS208 */
/* Implements FLS310,FLS345,FLS261,FLS163,FLS161,FLS267,FLS164 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_ReadImmediate
/* QAC Warning: START Msg(2:3227)-1*/
/* MISRA Warning: START Msg(4:3673)-7 */
(Fls_AddressType SourceAddress,
P2VAR(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
Fls_LengthType Length)
/* END Msg(4:3673)-7 */
/* END Msg(2:3227)-1*/
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_READ_IMM_SID);

  if (E_OK == LenReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    /* MISRA Violation: START Msg(4:2996)-4 */
    if ((LulLowerSourceAddr > SourceAddress) || \
                                         (LulUpperSourceAddr < SourceAddress))
    {
      /* END Msg(4:2996)-4 */
      /* Implements FLS_ESDD_UD_116 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                       FLS_READ_IMM_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Local variable to hold the read start address */
      Fls_GstVar.ulReadAddress = SourceAddress;

      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Check if the read length is greater than 0 and that the read end
       * address(read start address + length) lies within the specified upper
       * flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((Fls_GstVar.ulReadAddress - \
          (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > \
                                                     (uint32)FLS_DF_TOTAL_SIZE))
      {
        /* Implements FLS_ESDD_UD_117 */
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                          FLS_READ_IMM_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        /* Implements FLS_ESDD_UD_118 */
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                           FLS_READ_IMM_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }

      /* Check whether any error is reported to DET */
      if (E_OK == LenReturnValue)
      {
        /* MISRA Violation: START Msg(4:0306)-3 */
        /* Adjust the Source Address and Length if Mis-Aligned */
        Length = Fls_ReadMisAlignHandler(SourceAddress,
                                    (uint32)TargetAddressPtr, Length);
        /* END Msg(4:0306)-3 */
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Disable relevant interrupts to protect this critical section */
        FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the command to Read Immediate */
        Fls_GstVar.enGenCommand = FLS_COMMAND_READ_IMM;
        /* set the driver state to busy */
        Fls_GenState = MEMIF_BUSY;
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enable relevant interrupts to exit this critical section */
        FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
} /* End of API Fls_ReadImmediate */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

/* Implements FLS_ESDD_UD_099 */
#if (FLS_BLANKCHECK_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_BlankCheck
**
** Service ID               : 0x12
**
** Description              : This API performs the blank check of flash
**                            memory.
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : TargetAddress, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.enGenCommand(W),Fls_GenJobResult(W),
**                            Fls_GenState(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulSrcDestAddress(W)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheck,
**                            Fls_BlankCheckInternal
**
** Registers Used           : None
******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements FLS_ESDD_UD_013 */
/* Implements AR_PN0072_FR_0040,AR_PN0072_FR_0049,AR_PN0072_FR_0022 */
/* Implements AR_PN0072_FR_0041,AR_PN0072_FR_0003,AR_PN0072_FR_0004 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0023,AR_PN0072_FR_0048 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0013 */
/* Implements FLS287_Conf,FLS077,FLS162,FLS283_Conf,FLS280_Conf,FLS208 */
/* Implements FLS345,FLS261,FLS163,FLS161,FLS267,FLS164 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_BlankCheck
/* QAC Warning: START Msg(2:3227)-1 */
(Fls_AddressType TargetAddress, Fls_LengthType Length)
/* END Msg(2:3227)-1*/
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LenReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LenReturnValue = Fls_DetErrorCheck(FLS_BLANK_CHECK_SID);
  if (E_OK == LenReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* MISRA Violation: START Msg(4:2984)-5 */
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - \
                                                               (uint32)FLS_ONE);
    /* END Msg(4:2984)-5 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    /* MISRA Violation: START Msg(4:2996)-4 */
    if ((LulLowerTargetAddr > TargetAddress) ||
                                         (LulUpperTargetAddr < TargetAddress))
    {
      /* END Msg(4:2996)-4 */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Implements FLS_ESDD_UD_116 */
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                    FLS_BLANK_CHECK_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;
      /* Set the global variable with length */
      Fls_GstVar.ulRequestedLength = Length;
      /* Local variable to hold the blank check start address */
      Fls_GstVar.ulSrcDestAddress = TargetAddress;

      /* Check if the length is greater than 0 and that the end address
       * (start address + length) lies within the specified upper flash
       * address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((TargetAddress - \
         (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > \
                                                   (uint32)FLS_DF_TOTAL_SIZE))
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Implements FLS_ESDD_UD_117 */
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                     FLS_BLANK_CHECK_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* Check whether any error is reported to DET */
      if (E_OK == LenReturnValue)
      {
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Disable relevant interrupts to protect this critical section */
        FLS_ENTER_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* End of #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
        /* Set the command as blank check command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_BLANKCHECK;
        /* Set the job result to Job pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* Set the driver state as Busy */
        Fls_GenState = MEMIF_BUSY;
        #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enable relevant interrupts to exit this critical section */
        FLS_EXIT_CRITICAL_SECTION(FLS_DRIVERSTATE_DATA_PROTECTION);
        #endif /* End of #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* Invoke Fls_BlankCheck to do the remaining processing required
         after DET check for Blankcheck functionality */
        LenReturnValue = Fls_BlankCheckInternal();
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
} /* End of API Fls_BlankCheck */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_BLANKCHECK_API == STD_ON) */

#if (FLS_SUSPEND_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_Suspend
**
** Service ID               : 0x13
**
** Description              : This API performs the suspend of the on going
**                            job. This function shall return E_NOT_OK,
**                            if the suspend request is rejected.
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
** Return parameter         : LenReturnValue
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GblInitStatus(R),Fls_GenState(R),
**                            Fls_GstVar.enDFStatus(W),Fls_GblJobSuspended(R),
**                            Fls_GblJobSuspendRequest(W)
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_014 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0049,AR_PN0072_FR_0045 */
/* Implements FLS287_Conf,FLS077,FLS162,FLS311,FLS144,FLS267,FLS164 */
FUNC(Std_ReturnType , FLS_PUBLIC_CODE) Fls_Suspend(void)
{
  /* Declare the variable to store the return value */
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;
  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_119 */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                 FLS_SUSPEND_SID, FLS_E_UNINIT);
    #endif
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
   /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  {
    if ((FLS_COMMAND_ERASE == Fls_GstVar.enGenCommand) || \
                              (FLS_COMMAND_WRITE == Fls_GstVar.enGenCommand))
    {
      /* MISRA Violation: START Msg(4:3415)-8 */
      /* QAC Warning: START Msg(2:3416)-7 */
      /* Check if the driver state is not Idle */
      if ((MEMIF_BUSY == Fls_GenState) && (FLS_FALSE == Fls_GblJobSuspended))
      {
        /* END Msg(2:3416)-7 */
        /* END Msg(4:3415)-8 */
        Fls_GblJobSuspendRequest = FLS_TRUE;
      }
      else
      {
        Fls_GstVar.enDFStatus = FLS_FCU_ERR_REJECTED;
        LenReturnValue = E_NOT_OK;
      }
    }
    else
    {
      LenReturnValue = E_NOT_OK;
    }
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);

} /* End of API Fls_Suspend */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_SUSPEND_API == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/*******************************************************************************
** Function Name            : Fls_Resume
**
** Service ID               : 0x14
**
** Description              : This API resumes the suspended job.
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
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GblInitStatus(R),Fls_GenState(R),
**                            Fls_GblJobSuspended(R),
**                            Fls_GstVar.enDFStatus(W),Fls_GpConfigPtr(R)
**
** Function(s) invoked      : Det_ReportError,Fls_ProcessResume
**
** Registers Used           : IMRn
*******************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements FLS_ESDD_UD_015 */
/* Implements AR_PN0072_NR_0007,AR_PN0072_NR_0008 */
/* Implements AR_PN0072_FR_0049,AR_PN0072_FR_0046, */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0023 */
/* Implements EAAR_PN0034_FR_0013 */
/* Implements FLS287_Conf,FLS077,FLS162,FLS311,FLS261,FLS144,FLS163,FLS161 */
/* Implements FLS267,FLS164 */
FUNC(void, FLS_PUBLIC_CODE) Fls_Resume(void)
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenReturnValue = E_OK;

  /* Check if the module is initialized */
  if (FLS_UNINITIALIZED == Fls_GblInitStatus)
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Implements FLS_ESDD_UD_119 */
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID,
                                                 FLS_RESUME_SID, FLS_E_UNINIT);
    #endif
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether any error reported to DET */
  if (E_OK == LenReturnValue)
  {
    /* MISRA Violation: START Msg(4:3415)-8 */
    /* QAC Warning: START Msg(2:3416)-7 */
    /* Check if currently the Driver is in Idle State */
    if ((FLS_TRUE == Fls_GblJobSuspended) && \
                                        (MEMIF_IDLE == Fls_GenState))
    {
      /* END Msg(2:3416)-7 */
      /* END Msg(4:3415)-8 */
      #if (FLS_INTERRUPT_MODE == STD_ON)
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
      Fls_ProcessResume();
    }
    else
    {
      Fls_GstVar.enDFStatus = FLS_FCU_ERR_REJECTED;
    }
  }
  else
  {
    /* No action required */
  }
} /* End of API Fls_Resume */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (FLS_RESUME_API == STD_ON) */
/*******************************************************************************
**                           End of File                                      **
*******************************************************************************/
