/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Irq.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver Component.                                 */
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
 * V1.0.1:  23-Jan-2013    : As per SCR 068, in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR the pre-compile CAT2
 *                           interrupt condition is updated.
 *
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.3:  27-Aug-2013    : As per CR 232 for mantis issue 12123 and 13035,
 *                           following changes are made:
 *                           1.Backslash removed for ANSI C code.
 *                           2.Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           3. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.4:  14-Oct-2013    : As per CR 263, Spelling mistake is corrected.
 *
 * V1.0.5:  02-Jun-2014    : As per CR 490, Pre-compile check is added in
 *                           function prototypes section.
 *
 * V1.0.6:  18-Oct-2016    : Following changes are made:
 *                           1.As part of JIRA ticket ARDAAAE-1838,added macro
 *                           WDG_59_DRIVERA_INTWDT_EIC_ADDR to support interrupt
 *                           consistency check.
 *                           2.Copyright information is updated.
 *                           3.As per ARDAAAE-1908,Lower version related code
 *                           is removed.
 *                           4.As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           5.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.7:  07-Feb-2017    : Following changes are made:
 *                           1.As part of JIRA ticket ARDAAAE-2330, macro
 *                           WDG_59_DRIVERA_INTWDT_EIC_ADDR is removed.
 *                           2.Copyright information is updated.
 *                           3.As per ARDAAAE-2191,requirements tag,
 *                            'Implements'  is replaced with WDG_H_XXX.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_IRQ_H
#define WDG_59_DRIVERA_IRQ_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* WDG_H_005: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/*
 * Included for module version information from Wdg_59_DriverA.h and macro
 * definitions required for Wdg_59_DriverA_Irq.c
 */
#include "Wdg_59_DriverA_PBTypes.h"
/* Included for global variable visibility for Wdg_59_DriverA_Irq.c */
#include "Wdg_59_DriverA_Ram.h"

/* WDG_H_006: EAAR_PN0034_FR_0024 */
/* Included for interrupt category definitions */
#include "Os.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_IRQ_SW_MAJOR_VERSION    WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_IRQ_SW_MINOR_VERSION    WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                 WDG_59_DRIVERA_TRIGGERFUNCTION_ISR(void);
#endif

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* WDG_59_DRIVERA_IRQ_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
