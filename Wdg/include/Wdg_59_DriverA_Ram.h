/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Ram.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver are declared.          */
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
 * V1.0.2:  02-Jan-2014    : As per CR 334 and mantis #13043, global variable
 *                           Wdg_59_DriverA_GusTiggerCounter placed under memory
 *                           section WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16BIT.
 *
 * V1.0.3:  16-Jan-2014    : As per CR 350 and mantis #13043, pre-compile is
 *                           added for inclusion of global variable
 *                           Wdg_59_DriverA_GusTiggerCounter.
 *
 * V1.0.4:  10-Sep-2014    : As per CR 560, version information is updated to
 *                           remove QAC 8.1.1 related warning.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 * V1.0.6:  15-Mar-2016    : As part of P1x V4.01.00 release,following
 *                           changes are made:
 *                           1.As per JIRA ticket ARDAAAE-1486,
 *                             Storage specifier is changed from AUTOMATIC to
 *                             TYPEDEF.
 *                           2.As per JIRA ticket ARDAAAE-1672, memory section
 *                             for Global variable Wdg_59_DriverA_GddDriverState
 *                             updated.
 *                           3.As per JIRA ticket ARDAAAE-1593,
 *                             memory section for Global variable
 *                             Wdg_59_DriverA_GusTiggerCounter is updated.
 *                           4.Copyright information is updated.
 *
 * V1.0.7:  19-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1908,Lower version related code
 *                             is removed.
 *                           2.As per JIRA ticket ARDAAAE-1672, memory section
 *                             SEC_VAR_NOINIT_UNSPECIFIED and SEC_VAR_NOINIT_16
 *                             are renamed to SEC_VAR_NO_INIT_UNSPECIFIED and
 *                             SEC_VAR_NOINIT_16.
 *                           3.As per ARDAAAE-2090,variable type for
 *                            Wdg_59_DriverA_GusTiggerCounter is changed from
 *                            uint16 to uint32.
 *                           4.As per ARDAAAE-2075,variable
 *                            Wdg_59_DriverA_GusTiggerCounter and
 *                            Wdg_59_DriverA_GddDriverState declared volatile.
 *                           5.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.8:  07-Feb-2017    : Following changes are made:
 *                           1.As per ARDAAAE-2191,requirements tag,
 *                             'Implements'  is replaced with WDG_H_XXX.
 *                           2.Copyright information is updated.
 *                           3.As part of JIRA ID ARDAAAE-2355
 *                             The naming convention has changed from
 *                             Wdg_59_DriverA_GusTiggerCounter to
 *                             Wdg_59_DriverA_GulTiggerCounter
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_RAM_H
#define WDG_59_DRIVERA_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* WDG_H_009: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_RAM_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_RAM_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_RAM_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_59_DRIVERA_RAM_SW_MAJOR_VERSION    WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_RAM_SW_MINOR_VERSION    WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* TRACE [R4, WDG148] */
/* TRACE [R4, WDG152] */
/* Global variable to store the driver state */
extern VAR(volatile Wdg_59_DriverA_StatusType, WDG_59_DRIVERA_INIT_DATA)
                                                 Wdg_59_DriverA_GddDriverState;
#define WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* TRACE [R4, WDG154] */
/* Global variable to store the current watchdog state */
extern VAR(WdgIf_ModeType, WDG_59_DRIVERA_NOINIT_DATA)
                                                 Wdg_59_DriverA_GddCurrentMode;

/* Global variable to store pointer to Configuration */
extern P2CONST(Wdg_59_DriverA_ConfigType, TYPEDEF,
                        WDG_59_DRIVERA_CONFIG_CONST)Wdg_59_DriverA_GpConfigPtr;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

/* TRACE [R4, WDG153] */
/* Global variable to store the trigger counter value */
extern VAR(volatile uint32, WDG_59_DRIVERA_NOINIT_DATA)
                                            Wdg_59_DriverA_GulTiggerCounter;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* WDG_59_DRIVERA_RAM_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
