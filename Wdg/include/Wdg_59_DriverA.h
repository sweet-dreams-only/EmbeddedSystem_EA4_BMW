/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA.h                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API and database declaration, Service Id and DET error Macros */
/* and Module version information Macros.                                     */
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
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  23-Jan-2013    : As per SCR 068, software version macros are
 *                           updated to get the version from BSWMDT file.
 *
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.3:  06-Feb-2014    : As per CR 391, WDG_59_DRIVERA_E_PARAM_POINTER DET
 *                           error macro is removed as part of merging activity.
 *
 * V1.0.4:  09-Apr-2014    : As per CR 477 for mantis 20567, pre-compile switch
 *                           added for WDG_59_DRIVERA_E_PARAM_TIMEOUT macro.
 *
 * V1.0.5:  10-Sep-2014    : As per CR 560, following changes are made:
 *                           1. To remove QAC 8.1 related warnings, necessary
 *                           changes are made throughout the file.
 *                           2. MISRA violation comments have been added for
 *                            MISRA Msg "(4:3458)-1".
 *
 * V1.0.6:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.7:  14-Mar-2016    : As part of P1x V4.01.00 release,following
 *                           changes are made:
 *                           1.As part of JIRA ticket ARDAAAE-1672,
 *                             memory section changed for
 *                             Wdg_59_DriverA_GstConfiguration.
 *                           2.Copyright information is updated.
 *
 * V1.0.8:  18-Oct-2016    : Following changes are made:
 *                           1.Added new DET macro,
 *                             WDG_59_DRIVERA_E_PARAM_POINTER
 *                           2.As per ARDAAAE-811,
 *                           Macro implementation of function
 *                           Wdg_59_DriverA_GetVersionInfo is removed.
 *                           3.As per ARDAAAE-1898, new macro
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_ID is added to
 *                           support DEM reporting from WDG servicing routine.
 *                           4.As per ARDAAAE-1908,Lower version related code
 *                           is removed.
 *                           5.As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           6.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.9:  15-Feb-2017   : Following changes are made:
 *                           1.As per ARDAAAE-2191,requirements tag,
 *                             'Implements'  is replaced with WDG_H_XXX.
 *                           2.Copyright information is updated.
 *                           3.As part of JIRA ID ARDAAAE-2278
 *                            Suffix 'U' is added  for AutoSAR Macros
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_H
#define WDG_59_DRIVERA_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG149] */
/* TRACE [R4, WDG150] */
/* TRACE [R4, WDG151] */
/* WDG_H_001: WDG149,WDG150 */
/* WDG_H_002: EAAR_PN0034_FR_0001 */
/* WDG_H_003: EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* To publish the type Wdg_59_DriverA_ConfigType */
#include "Wdg_59_DriverA_Types.h"
/* Inclusion for the tool generated macros */
#include "Wdg_59_DriverA_Cfg.h"
/* Included for Notification declarations */
#include "Wdg_59_DriverA_Cbk.h"
/* Included for Register Write Verify options */
#include "Wdg_59_DriverA_RegWrite.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Wdg_59_DriverA_Debug.h"
#endif

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#define WDG_59_DRIVERA_VENDOR_ID    WDG_59_DRIVERA_VENDOR_ID_VALUE
#define WDG_59_DRIVERA_MODULE_ID    WDG_59_DRIVERA_MODULE_ID_VALUE
#define WDG_59_DRIVERA_INSTANCE_ID  WDG_59_DRIVERA_INSTANCE_ID_VALUE

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION    0U
#define WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION 3U

/* Module Software version information */
#define WDG_59_DRIVERA_SW_MAJOR_VERSION   WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_SW_MINOR_VERSION   WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_SW_PATCH_VERSION   WDG_59_DRIVERA_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      DET ERROR CODES                                       **
*******************************************************************************/
/* WDG_H_004: WDG010 */
/*
 * Following error will be reported when API service is used in wrong context
 * (For e.g. When Trigger / SetMode function is invoked without initialization).
 */
#define WDG_59_DRIVERA_E_DRIVER_STATE       (uint8)0x10

/*
 * Following error will be reported when API service is called with wrong /
 * inconsistent parameter(s).
 */
#define WDG_59_DRIVERA_E_PARAM_MODE         (uint8)0x11

/*
 * Following error will be reported when API service is called with wrong /
 * inconsistent parameter(s).
 */
#define WDG_59_DRIVERA_E_PARAM_CONFIG       (uint8)0x12

/*
 * Following error will be reported when API service is called with wrong /
 * pointer value(e.g. NULL pointer).
 */
#define WDG_59_DRIVERA_E_PARAM_POINTER       (uint8)0x14

/*
 * Following error will be reported when API Wdg_SetTriggerCondition is called
 * with timeout value greater than the maximum timeout value.
 */
#define WDG_59_DRIVERA_E_PARAM_TIMEOUT      (uint8)0x13

/*
 * Following error will be reported when Watchdog driver database does not
 * exist or exist in invalid location.
 */
#define WDG_59_DRIVERA_E_INVALID_DATABASE   (uint8)0xF1

/*******************************************************************************
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service ID of Watchdog Driver Initialization API. */
#define WDG_59_DRIVERA_INIT_SID              (uint8)0x00

/*
 * Service ID of SetMode API which switches current watchdog mode to the
 * Watchdog mode defined by the parameter ModeSet.
 */
#define WDG_59_DRIVERA_SETMODE_SID           (uint8)0x01

/* Service ID of Trigger condition API which triggers the Watchdog Hardware. */
#define WDG_59_DRIVERA_SETTRIGGERCONDITION_SID     (uint8)0x03

/* Service ID of Version Information API. */
#define WDG_59_DRIVERA_GETVERSIONINFO_SID    (uint8)0x04

/* Api ID of TRIGGERFUNCTION_ISR. */
#define WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_ID    (uint8)0x06

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* External Declaration for Watchdog Initialization API. */
extern FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Init
  (P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
                                                                    ConfigPtr);

/* External Declaration for Watchdog SetMode API. */
extern FUNC(Std_ReturnType, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetMode
  (WdgIf_ModeType Mode);

/* External Declaration for Watchdog Set Trigger Condition API. */
extern FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE)
                          Wdg_59_DriverA_SetTriggerCondition(uint16 timeout);

/* External Declaration for Watchdog GetVersionInfo API. */
#if (WDG_59_DRIVERA_VERSION_INFO_API == STD_ON)
extern FUNC(void,WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_GetVersionInfo(P2VAR
       (Std_VersionInfoType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST) versioninfo);
#endif
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#define WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* External Declaration for Watchdog database configuration set. */
extern CONST(Wdg_59_DriverA_ConfigType, WDG_59_DRIVERA_CONFIG_CONST)
                                               Wdg_59_DriverA_GstConfiguration;

#define WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* WDG_59_DRIVERA_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
