/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Private_Fcu.h                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API Declarations of Flash Control Unit specific         */
/* functions                                                                  */
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
 * V1.0.1:  21-Jun-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made:
 *                         1. As per JIRA ID ARDAAAE-1908, removed dead code.
 *                         2. As per JIRA ID ARDAAAE-1989, relocated declaration
 *                            of Fls_FcuInit function to this file.
 * V1.0.2:  31-Aug-2016  : Following change is made:
 *                         1. Corrected type-casting of second argument in
 *                            "Fls_FcuPerformBlankCheck" function.
 * V1.0.3:  31-Jan-2017  : Following changes are made:
 *                         1. As part of JIRA ID ARDAAAE-1963,added
 *                            Fls_FcuCheckSequencerStatus API declaration.
 *                         2. Copyright information is updated.
 *                         3. As per JIRA ID ARDAAAE-2112, Fls_FcuCopytoRam
 *                            Fls_FcuSwitchBFlash,Fls_FcuClearCache and
 *                            Fls_FcuGetFWParam APIs are moved to new memory
 *                            section FLS_START_SEC_PRIVATERAM_CODE.
 */
/******************************************************************************/

#ifndef FLS_PRIVATE_FCU_H
#define FLS_PRIVATE_FCU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fls.h"
#include "SchM_Fls.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define FLS_PRIVATE_FCU_AR_RELEASE_MAJOR_VERSION   \
                                                    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_PRIVATE_FCU_AR_RELEASE_MINOR_VERSION    \
                                                    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_PRIVATE_FCU_AR_RELEASE_REVISION_VERSION  \
                                                 FLS_AR_RELEASE_REVISION_VERSION
/* Module Software version information */
#define FLS_PRIVATE_FCU_SW_MAJOR_VERSION   FLS_SW_MAJOR_VERSION
#define FLS_PRIVATE_FCU_SW_MINOR_VERSION   FLS_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                     Extern Function Declarations                           **
*******************************************************************************/
#define FLS_START_SEC_PRIVATERAM_CODE
#include "MemMap.h"

#if (FLS_FWCOPY_SUPPORTED == STD_ON)
extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuCopytoRam(void);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuSwitchBFlash(const uint8 LucMode);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuClearCache(void);

#endif
extern FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuGetFWParam(const uint32
                                                                    LulAddress);

#define FLS_STOP_SEC_PRIVATERAM_CODE
#include "MemMap.h"

#define FLS_START_SEC_PRIVATE_CODE
#include "MemMap.h"

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuErasePreCheck(void);
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuWritePreCheck(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSwitchMode
                                     (VAR(const uint16, FLS_APPL_DATA) LddMode);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE)
                                                Fls_FcuPrepareEnvironment(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuForcedStop(void);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuClearStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuVerifyChecksum(void);

extern FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuGetDFSize(void);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuInitRAM(void);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuInit(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSetFrequency(void);

extern FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuDataCopy
                          (const uint32 LulSrcAddr, const uint32 LulBufferAddr);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_FcuOffsetDataCopy
               (uint32 LulSrcAddr, uint32 LulBufferAddr, const uint8 LucOffset);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckJobStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckBCJobStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuBlankCheckResult(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuPerformBlankCheck
                             (const uint32 LulStartAddr, const uint32 Lulcount);

extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_FcuResetErrorBits(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckSequencerStatus
                                                                         (void);

#define FLS_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* FLS_PRIVATE_FCU_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
