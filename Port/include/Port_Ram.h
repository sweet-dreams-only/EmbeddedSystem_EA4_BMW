/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Ram.h                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of PORT */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*PORT_H_047: EAAR_PN0034_NR_0045*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  05-Aug-2013  : As per CR 225, as part of merging activity, Header
 *                         and Environment sections are updated to change the
 *                         device name.
 * V1.0.2:  04-Mar-2016  : Following changes are done
 *                         1.Copyright information is updated.
 *                         2.As per ARDAAAE-1672,
 *                           PORT_START_SEC_VAR_NOINIT_UNSPECIFIED is changed to
 *                           PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED and
 *                           PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED changed to
 *                           PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
 *                           PORT_START_SEC_VAR_BOOLEAN changed to
 *                           PORT_START_SEC_VAR_INIT_BOOLEAN and
 *                           PORT_STOP_SEC_VAR_BOOLEAN changed to
 *                           PORT_STOP_SEC_VAR_INIT_BOOLEAN
 * V1.0.3:  08-Aug-2016  : As Part of V4.01.01 release,following changes are
 *                         done:
 *                         1.As per ARDAAAE-1908, ASR3.2.2 version information
 *                           is removed.
 *                         2.As per ARDAAAE-1936, requirement tags are added at
 *                           applicable places.
 * V1.0.4:  24-Jan-2017 :  As per ARDAAAE-2191,updated the format of requirement
 *                         tags
 */
/******************************************************************************/
/*PORT_H_048: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018*/
/*PORT_H_049: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020*/
/*PORT_H_050: EAAR_PN0034_FR_0001, EAAR_PN0034_FR_0052, AR_PN0062_FR_0005*/
/*PORT_H_051: EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0007, PORT207*/
#ifndef PORT_RAM_H
#define PORT_RAM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define PORT_RAM_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_RAM_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_RAM_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_RAM_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_RAM_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*PORT_H_052: PORT100, PORT107*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#define PORT_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/* Global variable to store Initialization status of Port Driver Component */
/* Declaration of this variable is needed as it is used to check the driver
 * initialization status in APIs other than Port_Init()
 */
extern VAR (boolean, PORT_INIT_DATA) Port_GblDriverStatus;

#define PORT_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

#define PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store pointer to Configuration */
/* Declaration of this variable is needed as it stores the pointer to
 * external data configuration which will be used as reference
 * in all Driver APIs
 */
extern P2CONST(Port_ConfigType, PORT_VAR, PORT_CONFIG_CONST)
                                             Port_GpConfigPtr;
#define PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
