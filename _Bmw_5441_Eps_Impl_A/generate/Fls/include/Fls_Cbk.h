/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for FLS callback Notification    */
/* Functions.                                                                 */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  05-Dec-2012 : Initial version
 * v1.0.1:  08-Aug-2013 : As per CR 225, F1x is renamed to X1x.
 * V1.0.2:  10-Jan-2014 : As per CR 066, for mantis issue #14560
 *                        1. Each line is limited to 80 columns.
 *                        2. COPYRIGHT information is updated.
 * V1.0.3:  28-Aug-2014 : As per CR 594 and mantis #22252, following change is
 *                        made:
 *                        1. Changes are made at all relevant places
 *                        accordingly to append U or UL after numeric values.
 * V1.0.4:  17-Nov-2014 : As per CR 652 and mantis #24328, following change
 *                        is made:
 *                        1.Hash BswCbkTpl::Template_Hash is updated.
 * V1.0.5:  15-Feb-2016 : For P1x V4.00.05 following changes are made:
 *                        1. CopyRight information is updated.
 *                        2. Included Dem.h file.
*******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    1.3.11
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Fls_ECUC_6743099085102707083.arxml
 *                C:\Component\FAAR_WE_Synergy\Fls\generate\R403_FLS_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:31
 */

#ifndef FLS_CBK_H
#define FLS_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define FLS_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define FLS_CBK_AR_RELEASE_MINOR_VERSION  0U
#define FLS_CBK_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define FLS_CBK_SW_MAJOR_VERSION  1U
#define FLS_CBK_SW_MINOR_VERSION  0U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#define FLS_START_SEC_APPL_CODE
#include "MemMap.h"

extern FUNC(void, FLS_APPL_CODE) HndlMcalWrVrfyErr
                               (Dem_EventIdType WVErrId, uint8 uiApiId);


#define FLS_STOP_SEC_APPL_CODE
#include "MemMap.h"

#endif /* FLS_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
