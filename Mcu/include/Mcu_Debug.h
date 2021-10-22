/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Debug.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of global variables for debugging purpose.                       */
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
 * V1.0.0:  02-Sep-2013 : Initial Version
 *
 * V1.0.1:  08-Oct-2014 : As per CR008 and mantis #19850, Following changes
 *                        is made,
 *                        1. Trace marking is added in the file
 *
 * V1.0.2:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 * V1.0.3:  21-Apr-2016 : Following changes are done as part of P1M 4.01.01
 *                        release,
 *                        1. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        2. Copyright year updated.
 *                        3. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 * V1.0.4:  11-Jan-2017 : Following changes are done
 *                        1. As per ARDAAAE-2191, requirement tag 'implements'
 *                           changed to MCU_H_00x.
 */
/******************************************************************************/
/* MCU_H_008: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0069 */
/* MCU_H_009: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0018 */
#ifndef MCU_DEBUG_H
/*Defining MCU_DEBUG_H to avoid multiple inclusion*/
#define MCU_DEBUG_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for macro definitions and structure declarations */
#include "Mcu_PBTypes.h"
/*
 * Since all the debug variables will be available in Mcu_Ram.h it
 * is included.
 */
/* MCU_H_010: MCU203 */
#include "Mcu_Ram.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_DEBUG_AR_RELEASE_MAJOR_VERSION MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_DEBUG_AR_RELEASE_MINOR_VERSION MCU_AR_RELEASE_MINOR_VERSION
#define MCU_DEBUG_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_DEBUG_SW_MAJOR_VERSION   MCU_SW_MAJOR_VERSION
#define MCU_DEBUG_SW_MINOR_VERSION   MCU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_DEBUG_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
