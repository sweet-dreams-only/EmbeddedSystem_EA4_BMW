/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Internal.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of prototypes for internal functions of Flash Wrapper Component. */
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
 * V1.0.1:  20-Mar-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made :
 *                         1. QAC Warning START and END msgs for
 *                            Msg(2:3210) and Msg(4:3447) are added.
 *                         2. Extern declaration added for Fls_FastReadCheckECC
 *                            function.
 * V1.0.2:  20-Mar-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made :
 *                         1. Added external declarations of Fls_CancelInternal,
 *                            Fls_SetStartEndAddr, Fls_ProcessReadImmInternal,
 *                            Fls_WriteInternal, Fls_BlankCheckInternal,
 *                            Fls_EraseInternal.
 *                         2. As per JIRA ID ARDAAAE-1908, removed dead code.
 *                         3. As per JIRA ID ARDAAAE-1989,
 *                            a) Renamed function Fls_FcuSuspendCheck() as
 *                               Fls_SuspendPreCheck().
 *                            b) Moved declaration of Fls_FcuInit function
 *                               to Fls_Private_Fcu.h.
 */
/******************************************************************************/
#ifndef FLS_INTERNAL_H
#define FLS_INTERNAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version information macros */
#include "Fls.h"
#include "Fls_Types.h"
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define FLS_INTERNAL_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_INTERNAL_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_INTERNAL_AR_RELEASE_REVISION_VERSION \
                                     FLS_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define FLS_INTERNAL_SW_MAJOR_VERSION    FLS_SW_MAJOR_VERSION
#define FLS_INTERNAL_SW_MINOR_VERSION    FLS_SW_MINOR_VERSION

/*******************************************************************************
**                         MISRA C Rule Violations                            **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3447) 'Function' is being declared with external        */
/*                 linkage but this declaration is not in a header file.      */
/* Rule          : MISRA-C:2004 Message 3210                                  */
/* Justification : All private APIs should be declared in corresponding       */
/*                 include files even though they are not used in the same    */
/*                 file and in that case extern declaration shall be given.   */
/*                 Fls.h should contain only AUTOSAR API's declarations       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3447)-1 and                           */
/*                 END Msg(4:3447)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/******************************************************************************/

/* 1. QAC Warning :                                                           */
/* Message       : (2:3210) The global identifier 'Function' is declared here */
/*                 but is not used in this translation unit.                  */
/* Justification : All private APIs should be declared in corresponding       */
/*                 include files even though they are not used in the same    */
/*                 file. Fls.h should contain only AUTOSAR APIs declarations  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3210)-1 and                           */
/*                 END Msg(2:3210)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3210)-1 */
/* MISRA Violation: START Msg(4:3447)-1 */
/* Declaration of API "Fls_PreFcuInitCheck". */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PreFcuInitCheck(void);
/* Declaration of API "Fls_InitiateEraseJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateEraseJob(void);
/* Declaration of API "Fls_MainErase". */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainErase(void);
/* Declaration of API "Fls_InitiateWriteJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateWriteJob(void);
/* Declaration of API "Fls_MainWrite" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainWrite(void);
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_SuspendPreCheck
                                              (Fls_CommandType LenRequestedCmd);
#if (FLS_COMPARE_API == STD_ON)
/* Declaration of API "Fls_MainCompare" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainCompare(void);
/* Declaration of API "Fls_ProcessCompare" */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessCompare(void);
/* Declaration of API "Fls_CompareWithTargetBuff" */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CompareWithTargetBuff
                                                          (boolean LblLastRead);
#endif
/* Declaration of API "Fls_MainRead" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainRead(void);
/* Declaration of API "Fls_PerformReadCheckECC" */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformReadCheckECC
                                        (uint32 LulSrcAddr, uint32 LulDestAddr);

extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessRead(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformBlankCheckForReadOp
                             (const uint32 LulStartAddr, const uint16 Luscount);

#if (FLS_READIMMEDIATE_API == STD_ON)
/* Declaration of API "Fls_MainReadImm" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainReadImm(void);
/* Declaration of API "Fls_ProcessReadImm" */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessReadImm(void);
/* Declaration of API "Fls_ReadMisAlignHandler" */
extern FUNC(Fls_LengthType, FLS_PRIVATE_CODE) Fls_ReadMisAlignHandler
(const uint32 SourceAddress, const uint32 TargetAddress, Fls_LengthType Length);

#endif
/* Declaration of API "Fls_GetMaxReadBytes" */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_GetMaxReadBytes(void);
/* Declaration of API "Fls_ReportECCErrorToCbk" */
FUNC(void, FLS_PRIVATE_CODE) Fls_ReportECCErrorToCbk
                             (Fls_FcuStatusType LenStatus, boolean LblSECError);
/* Declaration of API "Fls_CopyToTargetBuff" */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CopyToTargetBuff
                                                          (boolean LblLastRead);

/* Declaration of API "Fls_InitiateBlankCheckJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateBlankCheckJob(void);

/* Declaration of API "Fls_MainBlankCheck" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainBlankCheck(void);
/* Declaration of API "Fls_ProcessCancel" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessCancel(void);

#if (FLS_FHVE_REGS == SUPPORTED)
/* Declaration of API "Fls_SetFHVE" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetFHVE(boolean value);
#endif /* END of #if (FLS_FHVE_REGS == SUPPORTED) */
#if (FLS_JOB_NOTIF_CONFIG == STD_ON)
/* Declaration of API "Fls_CallJobNotification" */
FUNC(void, FLS_PRIVATE_CODE) Fls_CallJobNotification(void);
#endif

#if (FLS_INTERRUPT_MODE == STD_ON)
/* Declaration of API "Fls_SetResetIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetIntReq(void);
/* Declaration of API "Fls_RestoreIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreIntReq(void);
/* Declaration of API "Fls_ClearIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ClearIntReq(void);
/* Declaration of API "Fls_GetIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_GetIntReq(void);
#endif

#if (FLS_SUSPEND_API == STD_ON)
/* Declaration of API "Fls_ProcessSuspend" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessSuspend(void);
/* Declaration of API "Fls_BackupJobData" */
FUNC(void, FLS_PRIVATE_CODE) Fls_BackupJobData(void);
#endif

#if (FLS_RESUME_API == STD_ON)
/* Declaration of API "Fls_ProcessResume" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessResume(void);
/* Declaration of API "Fls_RestoreJobData" */
FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreJobData(void);
#endif

#if (FLS_TIMEOUT_MONITORING == STD_ON)
/* Declaration of API "Fls_TimeOutCheckAndProcessing" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_TimeOutCheckAndProcessing(void);
#endif
/* Declaration of API "Fls_ProcessJobResult" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessJobResult(MemIf_JobResultType
                                                                     LenResult);
#if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON))
/* Declaration of API "Fls_ClearBackUpData" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ClearBackUpData(void);
#endif

/* Declaration of API "Fls_DetErrorCheck" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_DetErrorCheck
                                                           (uint8 LucServiceId);
/* Declaration of API "Fls_FastReadCheckECC" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_FastReadCheckECC
                                    (uint32 LulErrorStatus,boolean LblLastRead);
/* Declaration of API "Fls_SetStartEndAddr" */
extern FUNC(void,FLS_PRIVATE_CODE)Fls_SetStartEndAddr
                                    (uint32 LulStartAdd, uint32 LulEndAdd);
/* Declaration of API "Fls_CancelInternal" */
extern FUNC(void,FLS_PRIVATE_CODE)Fls_CancelInternal(void);
/* Declaration of API "Fls_EraseInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE)Fls_EraseInternal
                         (Fls_AddressType TargetAddress, Fls_LengthType Length);
/* Declaration of API "Fls_WriteInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_WriteInternal(void);
/* Declaration of API "Fls_BlankCheckInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_BlankCheckInternal(void);
/* END Msg(2:3210)-1 */
/* END Msg(4:3447)-1 */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif  /* FLS_INTERNAL_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
