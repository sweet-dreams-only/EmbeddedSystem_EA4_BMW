/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_PBTypes.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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
 * V1.0.1:  29-Sep-2012    : As per SCR 020, critical section macro's are
 *                           corrected.
 *
 * V1.0.2:  24-Apr-2013    : As per SCR 148 for mantis issue #9729, following
 *                           change is made:
 *                           Macro 'WDG_59_DRIVERA_75INTERRUPT_MASK' is added
 *                           for not disturbing 75% interrupt bit, NMI and
 *                           Reset mode.
 *
 * V1.0.3:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.4:  12-Mar-2014    : As per CR 422, pre-compile check
 *                           WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION is added
 *                           in global symbols section.
 *
 * V1.0.5:  13-May-2014    : As per CR 490 for mantis #21269,
 *                           following change are made:
 *                           1. Read-back macro are added in global symbols
 *                           section.
 *                           2. WUF0 and WUFC0 mask value macros are added.
 *
 * V1.0.6:  16-Jun-2014    : As per CR 520, Read-back macro is added in global
 *                           symbols section.
 *
 * V1.0.7:  10-Sep-2014    : As per CR 560, following changes are made:
 *                           1. To remove QAC 8.1.1 related warnings, necessary
 *                           changes are made throughout the file.
 *                           2. MISRA violation comments have been added for
 *                           MISRA Msg "(4:3412)-1".
 *
 * V1.0.8:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.9:  16-Mar-2016    : As part of P1x V4.01.00 release,following
 *                           changes are made:
 *                           1.As part of JIRA ticket ARDAAAE-1512,added macros
 *                           for compare with zero,one and three and
 *                           WIE bit mask value.
 *                           2.Copyright information is updated.
 *
 * V1.0.10: 18-Oct-2016    : Following changes are made:
 *                           1.As part of JIRA ticket ARDAAAE-1838,added macro
 *                           WDG_59_DRIVERA_WDTAMD_MASK,WDG_EIC_EIMK_MASK,
 *                           WDG_59_DRIVERA_WDTAWDTE_MASK,
 *                           WDG_59_DRIVERA_WDTAEVAC_MASK and removed macros
 *                           related to READBACK functionality.
 *                           2.As per ARDAAAE-1819,WDG_59_DRIVERA_THOUSAND macro
 *                           is added to convert microseconds to milliseconds.
 *                           3.As per ARDAAAE-1908,Lower version related code
 *                           is removed.
 *                           4.As per ARDAAAE-2090, value for
 *                           WDG_59_DRIVERA_ZERO,WDG_59_DRIVERA_THOUSAND updated
 *                           5.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.11:  15-Feb-2017   : Following changes are made:
 *                           1.As per ARDAAAE-2191,requirements tag,
 *                             'Implements'  is replaced with WDG_H_XXX.
 *                           2.Copyright information is updated.
 *                           3.As per ARDAAAE-2278 Dead code is removed
 *                             'WDG_59_DRIVERA_NMI_MASKVALUE,
 *                             WDG_59_DRIVERA_NMI_MODE,WDG_59_DRIVERA_RAM,
 *                             WDG_59_DRIVERA_ROM
 *                           4.As part of JIRA ID ARDAAAE-2355
 *                             The naming convention has changed from
 *                             Wdg_59_DriverA_GusTiggerCounter to
 *                             Wdg_59_DriverA_GulTiggerCounter
 *                          5.As part of JIRA ID ARDAAAE-2278
 *                             Suffix 'U' is added  for WDG_59_DRIVERA_WINDOW
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_PBTYPES_H
#define WDG_59_DRIVERA_PBTYPES_H

/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* WDG_H_007: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* Included for module version information */
#include "Wdg_59_DriverA.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* TRACE [R4, WDG159] */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_PBTYPES_SW_MAJOR_VERSION  WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_PBTYPES_SW_MINOR_VERSION  WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Type definition for trigger mode */
#define WDG_59_DRIVERA_WINDOW          1U

/* General defines */
#define WDG_59_DRIVERA_DBTOC_VALUE \
                         (((uint32)WDG_59_DRIVERA_VENDOR_ID << (uint8)22) | \
                          ((uint32)WDG_59_DRIVERA_MODULE_ID << (uint8)14) | \
                    ((uint32)WDG_59_DRIVERA_SW_MAJOR_VERSION << (uint8)8) | \
                    ((uint32)WDG_59_DRIVERA_SW_MINOR_VERSION << (uint8)3))
/*
 * Value to be written to WDTAWDTE / WDTAEVAC register to clear and restart
 * the timer.
 */
#define WDG_59_DRIVERA_RESTART         (uint8)0xAC

/* Macro for compare with zero,one,three */
#define WDG_59_DRIVERA_ZERO            (uint32)0x00000000
#define WDG_59_DRIVERA_ONE             (uint8)0x01
#define WDG_59_DRIVERA_THREE           (uint8)0x03

/* Macro for covert microseconds to milliseconds */
#define WDG_59_DRIVERA_THOUSAND           (uint32)0x000003E8

/* 75% interrupt mask values */
#define WDG_59_DRIVERA_75INTERRUPT_MASK      (uint8)0x08

/* WIE bit mask value */
#define WDTAMD_WIE_MASK                (uint8)0x08

/* Watchdog error type macro */
#define WDG_59_DRIVERA_RESET_MODE      (uint8)0x0000

/* Mask for WDTAMD Register */
#define WDG_59_DRIVERA_WDTAMD_MASK   (uint8)0x7F

/* Mask for WDTAWDTE Register */
#define WDG_59_DRIVERA_WDTAWDTE_MASK   (uint8)0xFF

/* Mask for WDTAEVAC Register */
#define WDG_59_DRIVERA_WDTAEVAC_MASK   (uint8)0xFF

/* Mask for EIC Register */
#define WDG_EIC_EIMK_MASK              (uint16)0x0080

/* WUF0 and WUFC0 register mask values for 75% Interrupt (INTWDTA0) */
#define WDG_59_DRIVERA_INT_MASKVALUE    (uint32)0x00000100

#define WDG_59_DRIVERA_DEM_TYPE Dem_EventStatusType

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* MISRA Violation: START Msg(4:3412)-1 */
#define WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Wdg_59_DriverA_##Exclusive_Area();

#define WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(Exclusive_Area) \
SchM_Exit_Wdg_59_DriverA_##Exclusive_Area();

/* END Msg(4:3412)-1 */
#endif
/*
* Value written to Wdg_59_DriverA_GulTiggerCounter to avoid scalar division
* by zero
*/
#define WDG_59_DRIVERA_COUNTER_ZERO    (uint16)0x0000u

#endif /* WDG_59_DRIVERA_PBTYPES_H */
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
