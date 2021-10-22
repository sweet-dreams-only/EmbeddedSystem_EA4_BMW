/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Dio Driver                                                                 */
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
 * V1.0.0:  23-Aug-2012  : Initial Version
 *
 * V1.0.1:  17-Sep-2012  : As per SCR 013, updated the Alignment.
 *
 * V1.0.2:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.3:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.4:  06-Mar-2014  : As per CR 428, errors related to critical section
 *                         protection are added in version check section.
 *
 * V1.0.5:  06-Aug-2014  : As per mantis #22811, code is updated for Renesas
 *                         C coding Guidelines.
 *
 * V1.0.6:  25-Aug-2014  : As per CR 569, Extra space present before ==
 *                         is removed.
 * V1.0.7:  20-Sep-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made:
 *                         1. As per ARDAAAE-1908, removed dead code.
 *                         2. As per ARDAAAE-1726,errors related to Dem version
 *                            check is added.
 *                         3. MISRA justification for Msg(2:0553) is added.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Header file inclusion */
#include "Dio_Version.h"
/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       : (2:0553)  Translation unit contains no object or           */
/*                 function definitions with external linkage.                */
/* Rule          : MISRA-C:2004 Message 0553                                  */
/* Justification : As per AUTOSAR, file should be required to include.        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define DIO_VERSION_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Release Major Version"
#endif

#if (DIO_VERSION_AR_RELEASE_MINOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Release Minor Version"
#endif

#if (DIO_VERSION_AR_RELEASE_REVISION_VERSION != \
                           DIO_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_Version.c : Mismatch in Release Revision Version"
#endif

#if (DIO_VERSION_SW_MAJOR_VERSION != DIO_VERSION_C_SW_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Software Major Version"
#endif

#if (DIO_VERSION_SW_MINOR_VERSION != DIO_VERSION_C_SW_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Software Minor Version"
#endif

#if (DIO_VERSION_CHECK_EXT_MODULES == STD_ON)

#if ((DEM_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DEM_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) \
              || (RTE_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of DIO_CRITICAL_SECTION_PROTECTION */

/* START of DIO_DEV_ERROR_DETECT */
#if (DIO_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif
#endif
/* END of (DIO_VERSION_CHECK_EXT_MODULES == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
