/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of MCU  */
/* Driver                                                                     */
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
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. Mcu_GblResetStatusSaved is added since it is using
 *                           for internal API Mcu_SaveResetReason()
 *
 * V1.0.2:  07-Oct-2014 : As per CR008 and mantis #19850, Following
 *                        changes is made,
 *                        1. Pre-compile checking for variable
 *                           Mcu_GblDriverStatus is removed.
 *
 * V1.0.3:  08-Dec-2014 : As per CR076 and mantis #25069,#21577, following
 *                        changes are made,
 *                        1.Mcu_GblResetStatusSaved moved to
 *                        section MCU_START_SEC_VAR_BOOLEAN from
 *                        MCU_START_SEC_VAR_NOINIT_UNSPECIFIED.
 *
 * V1.0.4:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 * V1.0.5:  29-Feb-2016 : Following changes are done as part of P1M 4.01.00
 *                        release
 *                        1. As per ticket ARDAAAE-1593, the memory section is
 *                           updated for variables.
 *                        2. Copyright information is updated.
 * V1.0.6:  21-Apr-2016 : Following changes are done as part of P1M 4.01.01
 *                        release
 *                        1. Removed unwanted declaration of Mcu_GpRamSetting.
 *                        2. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        3. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 *                        4. As per ticket ARDAAAE-2043, volatile declaration is
 *                           added for Mcu_GblRAMInitStatus
 * V1.0.7:  11-Jan-2017 : Following changes are done
 *                        1. As per ARDAAAE-2191, requirement tag 'implements'
 *                           changed to MCU_H_00x.
 */
/******************************************************************************/
/* MCU_H_021: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0069 */
/* MCU_H_022: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0018 */
#ifndef MCU_RAM_H
/*Defining RAM_H to avoid multiple inclusion*/
#define MCU_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* MCU_H_023: EAAR_PN0034_FR_0055*/
/* AUTOSAR specification version information */

#define MCU_RAM_AR_RELEASE_MAJOR_VERSION      MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_AR_RELEASE_MINOR_VERSION      MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_AR_RELEASE_REVISION_VERSION   MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_RAM_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_RAM_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*To use VAR NO_INIT UNSPECIFIED section in the Memory*/
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpClockSetting;

/* Global pointer variable for MCU ECM Setting configuration */
extern P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpEcmSetting;

extern VAR(Mcu_ExtnClkSettingReg, MCU_VAR) Mcu_GpExtnClkSettingReg;

/*Exit VAR NO_INIT UNSPECIFIED section in the Memory*/
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*To use VAR BOOLEAN section in the Memory*/
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Global variable to store ram state of MCU Driver */
extern VAR(volatile boolean, MCU_INIT_DATA) Mcu_GblRAMInitStatus;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*Exit VAR BOOLEAN section in the Memory*/
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
