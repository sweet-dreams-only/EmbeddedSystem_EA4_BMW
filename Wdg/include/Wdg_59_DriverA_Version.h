/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Version.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking release versions of        */
/* modules included by Watchdog Driver.                                       */
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
 * V1.0.1:  29-Sep-2012    : As per SCR 020, major and minor versions are
 *                           corrected for dem and det. major and minor version
 *                           added for os.
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 * V1.0.3:  14-Oct-2013    : As per CR 263, Spelling mistake is corrected.
 * V1.0.4:  27-Mar-2014    : As per CR 422, Include section updated.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 * V1.0.6:  18-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1908,Lower version related code
 *                           is removed.
 *                           2.Copyright information is updated.
 *                           3.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.7:  15-Feb-2017    : Following changes are made:
 *                           1.As per ARDAAAE-2191,requirements tag,
 *                             'Implements'  is replaced with WDG_H_XXX.
 *                           2.Copyright information is updated.
 *                           3.As part of JIRA ID ARDAAAE-2278
 *                             Suffix 'U' is added  for AutoSAR Macros
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_VERSION_H
#define WDG_59_DRIVERA_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* WDG_H_014: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* Included for module version information */
#include "Wdg_59_DriverA.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* DEM module version information is required */
#include "Dem.h"

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"
#endif

/* OS module version information is required */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_VERSION_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_VERSION_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_VERSION_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

/* Included Files Autosar Specification Version */
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
#define WDG_59_DRIVERA_DET_AR_MAJOR_VERSION  2U
#define WDG_59_DRIVERA_DET_AR_MINOR_VERSION  2U
#endif

#define WDG_59_DRIVERA_DEM_AR_MAJOR_VERSION  3U
#define WDG_59_DRIVERA_DEM_AR_MINOR_VERSION  3U

#define WDG_59_DRIVERA_OS_AR_MAJOR_VERSION  0U
#define WDG_59_DRIVERA_OS_AR_MINOR_VERSION  2U

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
#define WDG_59_DRIVERA_SCHM_AR_MAJOR_VERSION     1U
#define WDG_59_DRIVERA_SCHM_AR_MINOR_VERSION     2U
#endif

/* Module Software version information */
#define WDG_59_DRIVERA_VERSION_SW_MAJOR_VERSION  WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_VERSION_SW_MINOR_VERSION  WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#endif /* WDG_59_DRIVERA_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
