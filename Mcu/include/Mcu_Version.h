/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by MCU Driver                                                     */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version.
 *
 * V1.0.1:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 * V1.0.2:  21-Apr-2016 : Following changes are done as part of P1M 4.01.01
 *                        release,
 *                        1. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        2. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 *                        3. Copyright year updated.
 * V1.0.3:  11-Jan-2017 : Following changes are done
 *                        1. As per ARDAAAE-2191, requirement tag 'implements'
 *                           changed to MCU_H_00x.
 */
/******************************************************************************/
/* MCU_H_040: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0069 */
/* MCU_H_041: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0018 */
/* To define Mcu Version */
#ifndef MCU_VERSION_H
/*Defining MCU_VERSION_H to avoid multiple inclusion*/
#define MCU_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Mcu.h"

/*Included for DEM module version information */
#include "Dem.h"

/* DET module version information is required only when DET is enabled */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)

/* Rte module version information is required */
#include "Rte.h"
#include "SchM_Mcu.h"

#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* OS module version information is required */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* MCU_H_042: EAAR_PN0034_FR_0055*/
/* AUTOSAR specification version information */

#define MCU_VERSION_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_VERSION_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_VERSION_AR_RELEASE_REVISION_VERSION    \
                                               MCU_AR_RELEASE_REVISION_VERSION

/* Included Files AUTOSAR Specification Version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#define MCU_DET_AR_MAJOR_VERSION      2
#define MCU_DET_AR_MINOR_VERSION      2
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#define MCU_SCHM_AR_MAJOR_VERSION     1
#define MCU_SCHM_AR_MINOR_VERSION     2
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

#define MCU_OS_AR_MAJOR_VERSION     3
#define MCU_OS_AR_MINOR_VERSION     2

#define MCU_DEM_AR_MAJOR_VERSION    3
#define MCU_DEM_AR_MINOR_VERSION    3

/* File version information */
#define MCU_VERSION_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_VERSION_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
