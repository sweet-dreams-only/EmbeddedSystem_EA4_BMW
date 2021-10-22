/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains prototype declarations for SPI callback notification    */
/* functions.                                                                 */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  31-Aug-2012  : Initial version
 * V1.0.1:  08-Aug-2013  : As per CR 225, following changes are made:
 *                         1. Document is updated as per new template
 *                            attached in mantis #11710.
 *                         2. Copyright information is updated.
 * V1.0.2:  02-Jan-2014  : As per CR 330, for the mantis issue #15705,
 *                         Copyright information is updated.
 * V1.0.3:  28-Aug-2014  : As per CR 601, for the mantis 22252,
 *                         Changes are made at all relevant places
 *                         accordingly to append U or UL after numeric values.
 * V1.0.4:  26-Apr-2016    As part of P1x V4.01.01 release, following
 *                         changes are made.
 *                         1.As part of Write-verify user interface
 *                           implementation, updated the template to add the
 *                           generation of SPI_WVERROR_NOTIFICATION and added
 *                           Dem.h header file.
 */

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.2.17
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Spi_ECUC_9161016338772377939.arxml
 *                C:\Component\FAAR_WE_Synergy\Spi\generate\R403_SPI_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:59:38
 */

#ifndef SPI_CBK_H
#define SPI_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi_Cfg.h"
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define SPI_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define SPI_CBK_AR_RELEASE_MINOR_VERSION  0U
#define SPI_CBK_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define SPI_CBK_SW_MAJOR_VERSION  1U
#define SPI_CBK_SW_MINOR_VERSION  6U

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define SPI_START_SEC_APPL_CODE
#include "MemMap.h"



extern FUNC(void, SPI_APPL_CODE)
          HndlMcalWrVrfyErr (Dem_EventIdType WVErrId, uint8 uiApiId);


#define SPI_STOP_SEC_APPL_CODE
#include "MemMap.h"

#endif /* SPI_CBK_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
