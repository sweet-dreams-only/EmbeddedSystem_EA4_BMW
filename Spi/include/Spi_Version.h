/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by SPI Driver                                                     */
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
 * V1.0.0:  29-Aug-2012  : Initial Version
 *
 * V1.0.1:  01-Oct-2012  : As per SCR 021 following changes are made
 *                         1. SPI_SCHM_AR_MAJOR_VERSION,
 *                            SPI_SCHM_AR_MINOR_VERSION and
 *                            SPI_DEM_AR_MAJOR_VERSION values are updated.
 *                         2. SPI_OS_AR_MAJOR_VERSION , SPI_OS_AR_MINOR_VERSION
 *                            are added.
 *
 * V1.0.2:  19-Oct-2012  : As per SCR 029, SPI_DET_AR_MINOR_VERSION changed.
 *
 * V1.0.3:  27-Nov-2012  : As per SCR 042, SPI_SCHM_AR_MAJOR_VERSION and
 *                         SPI_SCHM_AR_MINOR_VERSION are changed.
 *
 * V1.0.4:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.0.5:  15-Jan-2014  : As per CR 330, following changes are made:
 *                          1. Updated as per C coding guideline.
 *                          2. Copyright information is updated.
 *
 * V1.0.6:  20-Sep-2014  : As per CR 601, for mantis 23821, following changes
 *                         are made:
 *                         1. Suffix 'U' is added for scalar values.
 * V1.0.7:  10-Aug-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made :
 *                        1.As part of ARDAAAE-1908,removed AR 3.2.2
 *                          related version checks, removed the
 *                          the switch
 *                          #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION).
 *                        2.Updated copyright information.
 */
/******************************************************************************/
#ifndef SPI_VERSION_H
#define SPI_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Dem.h"
#include "Os.h"
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
#if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */

/* OS module version information is required */

#include "Rte.h"
#endif /*END of SPI_CRITICAL_SECTION_PROTECTION*/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define SPI_VERSION_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_VERSION_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_VERSION_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION



/* File version information */
#define SPI_VERSION_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_VERSION_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* SPI_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
