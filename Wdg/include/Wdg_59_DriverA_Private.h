/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API and database declaration, Service Id and DET error Macros */
/* and Module version information Macros.                                     */
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
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.2:  12-Sep-2013    : As per CR 232 for mantis issue 13035,
 *                           following changes are made:
 *                           1. Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           2. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.3:  03-Feb-2015     : As part of merging activity(#26024) alignment of
 *                            revision history is updated.
 * V1.0.4:  16-Mar-2016     : As part of P1x V4.01.00 release,following
 *                            changes are made:
 *                            1.As per JIRA ticket ARDAAAE-1512,external
 *                            declaration for API Wdg_59_DriverA_InitDetCheck
 *                            added.
 *                            2.Copyright information is updated.
 *                            3.As per ARDAAAE-1908,Lower version related code
 *                            is removed.
 * V1.0.5:  18-Oct-2016     : Following change is made
 *                            1.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.6:  07-Feb-2017     : Following changes are made:
 *                            1.As per ARDAAAE-2191,requirements tag,
 *                             'Implements'  is replaced with WDG_H_XXX.
 *                            2.Copyright information is updated.
 *                            3.As per ARDAAAE-2355 The naming convention has
 *                              changed from uiApiId to ucApiId
 *                            4.As part of JIRA ID ARDAAAE-2278 The value of
 *                              function parameter is declared
 *                              with the 'const' type Qualifier,to avoid QAC
 *                              warning Msg(2:3227).
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_PRIVATE_H
#define WDG_59_DRIVERA_PRIVATE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* WDG_H_008: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION  WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION  WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

extern FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc
                                         (CONST(uint8,AUTOMATIC) ucApiId);

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

#define WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* External Declaration for Watchdog InitDetCheck API */
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_PRIVATE_CODE)
                                       Wdg_59_DriverA_InitDetCheck
(CONSTP2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr);

/* External Declaration for Watchdog SetModeDetCheck API */
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_PRIVATE_CODE)
Wdg_59_DriverA_SetModeDetCheck(CONST(WdgIf_ModeType,AUTOMATIC) Mode);
#define WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* WDG_59_DRIVERA_PRIVATE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
