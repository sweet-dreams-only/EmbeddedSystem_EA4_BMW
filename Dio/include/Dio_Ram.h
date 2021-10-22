/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Dio Driver are declared.               */
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
 * V1.0.1:  14-Sep-2012  : As per SCR 013, updated the Alignment.
 *
 * V1.0.2:  18-Apr-2013  : Copyright information is updated.
 *
 * V1.0.3:  08-Aug-2013  : As per CR 225, Device name and Project name are
 *                         updated as part of merge activity.
 *
 * V1.0.4:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.5:  04-Feb-2014   : As per CR 394 and merge activity code is updated.
 *
 * V1.0.6:  08-Apr-2014   : As per CR 475, code is updated for spell check.
 *
 * V1.0.7:  14-Jul-2014   : As per CR 545, code is updated to correct the
 *                          alignment of revision history.
 *
 * V1.0.8:  05-Aug-2014  : As per CR 564, following changes are made:
 *                         1. Section DIO_START_SEC_VAR_1BIT
 *                         is added for lower version check of variable
 *                         Dio_GblDriverStatus.
 *                         2.Dio_GusNoOfChannelGroups variable is declared under
 *                         DIO_START_SEC_VAR_NOINIT_16 for higher version check
 *                         and under DIO_START_SEC_VAR_NOINIT_16BIT for lower
 *                         version check.
 *
 * V1.0.9: 25-Aug-2014   : As per CR 569, Extra space present before == is
 *                         removed.
 * V1.0.10: 16-Jan-2015  : Precompile options for global variables
 *                         Dio_GpPortGroup,Dio_GpPortChannel are added to
 *                         avoid MISRA warnings.
 * V1.0.11: 22-Feb-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made:
 *                         1. As per the ticket ARDAAAE-1053,
 *                            The variable Dio_GusNoOfChannelGroups is renamed
 *                            as Dio_GusChannelGroupsOffset.
 * V1.0.12: 28-Jun-2016  : Following changes are made:
 *                         1. As per ARDAAAE-1908, removed dead code.
 *                         2. As per ARDAAAE-1672,Memory sections
 *                            SEC_VAR_NOINIT_UNSPECIFIED and
 *                            SEC_VAR_NOINIT_16 changed to
 *                            SEC_VAR_NO_INIT_UNSPECIFIED and SEC_VAR_NO_INIT_16
 * V1.0.13: 07-Feb-2017  : Following changes are made:
 *                         1. As per ARDAAAE-2191, requirement tag
 *                           'implements' changed to 'DIO_H_00x :'.
 *                         2. Copyright information is updated.
 */
/******************************************************************************/
/* DIO_H_004: EAAR_PN0034_FR_0001 */
#ifndef DIO_RAM_H
#define DIO_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define DIO_RAM_AR_RELEASE_MAJOR_VERSION     DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_RAM_AR_RELEASE_MINOR_VERSION     DIO_AR_RELEASE_MINOR_VERSION
#define DIO_RAM_AR_RELEASE_REVISION_VERSION  DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_RAM_SW_MAJOR_VERSION    DIO_SW_MAJOR_VERSION
#define DIO_RAM_SW_MINOR_VERSION    DIO_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define DIO_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store the Dio driver initialization state */
extern VAR(boolean, DIO_INIT_DATA) Dio_GblDriverStatus;
#endif

#define DIO_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#define DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* Constant Global pointer to store structure Dio_PortGroup */
extern P2CONST(Dio_PortGroup, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortGroup;

#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/* Constant Global pointer to store structure Dio_PortChannel */
extern P2CONST(Dio_PortChannel, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortChannel;
#endif

#define DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define DIO_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
extern VAR(uint16, DIO_CONFIG_CONST) Dio_GusChannelGroupsOffset;
#endif

#define DIO_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif
/* DIO_RAM_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
