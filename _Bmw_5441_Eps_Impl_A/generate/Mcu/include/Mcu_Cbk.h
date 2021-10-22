/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for MCU callback Notification    */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  26-Aug-2013 : Initial version
 * V1.1.0:  21-Apr-2014 : Following changes are made:
 *                        1. Copyright information is updated.
 * V1.1.1:  15-Sep-2014 : As per CR 008 and mantis #19850, following change is
 *                        made:
 *                        2. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 * V1.1.2. 04-Dec-2015    1. Call back notifications McuEcmInitialNotification
 *                           are added for the implementation of
 *                           EAAR_PN0079_FSR_0102.
 * 1.1.3   29-Feb-2016 : Following changes are done as part of P1M
 *                       V4.01.00 release activity.
 *                       1. As per ticket ARDAAAE-1180, command line
 *                          option -f is added for file version display
 *                       2. Copyright Info is updated.
 * 1.1.4  29-Apr-2016  : Following changes are done as part of P1M
 *                       V4.01.01 release activity.
 *                       1. Call back notifications for
 *                          McuWVErrorNotification is added and file
 *                          inclusion is updated
 *                       2. Perl_File_Version_Hash is updated with latest
 *                          file version.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    1.1.5
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Mcu_ECUC_3350516407282010857.arxml
 *                C:\Component\FAAR_WE_Synergy\Mcu\generate\R403_MCU_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:53
 */

#ifndef MCU_CBK_H
#define MCU_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_CBK_AR_RELEASE_MINOR_VERSION  0U
#define MCU_CBK_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define MCU_CBK_C_SW_MAJOR_VERSION  1U
#define MCU_CBK_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#define MCU_START_SEC_APPL_CODE
#include "MemMap.h"

extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrSngChipInactv (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr3RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrTestModStrtd (void);
extern FUNC(void, MCU_APPL_CODE) CodFlsSngBitEcc (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr1RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiDtsEccSngBitErr (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr1RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiPeg (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr0RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiDmaRegAcsProtnErr (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr0RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) RamMemLclRamSngBitEcc (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiDmaTrf (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr2RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr3RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiEcmMstChkrCmp (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrFlsProgmModStrtd (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr2RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiWdg (void);


#define MCU_STOP_SEC_APPL_CODE
#include "MemMap.h"

#endif /* MCU_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
