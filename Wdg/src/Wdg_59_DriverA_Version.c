/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Version.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Watchdog Driver A                                                          */
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
 * V1.0.1:  29-Sep-2012    : As per SCR 020, version check added for Os.h file
 *                           in lower version.
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 * V1.0.3:  26-Mar-2014    : As per CR 422, version check section updated.
 *
 * V1.0.4:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.5:  18-Mar-2016    : As part of P1x V4.01.00 release,following
 *                           changes are made:
 *                           1.MISRA C Rule Violation for Msg(2:0553) is added.
 *                           2.Copyright information is updated.
 *
 * V1.0.6:  18-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           2.As per ARDAAAE-2060,requirements are mapped
 *                             to code.
 * V1.0.7:  07-Feb-2017    : Following changes are made:
 *                           1.As per ARDAAAE-2278 for QAC Warning
 *                             Rule has been changed to NA.
 *                           2.Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG099] */
/* TRACE [R3, WDG099] */
/* Implements EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* Header file inclusion */
#include "Wdg_59_DriverA_Version.h"

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       : (2:0553)  Translation unit contains no object or           */
/*                 function definitions with external linkage.                */
/* Rule          : NA                                                         */
/* Justification : As per AUTOSAR, file should be required to include.        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* TRACE [R4, WDG109] */
/* TRACE [R3, WDG109] */
/* TRACE [R4, WDG174] */
/* TRACE [R4, WDG174] */
/* TRACE [R3, WDG067] */
/* TRACE [R4, WDG068] */
/* TRACE [R3, WDG068] */
/* TRACE [R3, WDG087] */
/* Implements WDG087 */
/* Implements EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_VERSION_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_VERSION_SW_MINOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Software Minor Version"
#endif


/* Implements WDG_ESDD_UD_012 */
#if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON)
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

#if ((DEM_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif

#if ((OS_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (OS_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif

#endif /* #if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
