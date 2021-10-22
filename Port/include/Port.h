/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.h                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, PORT type definitions, structure data types and */
/* API function prototypes of PORT Driver                                     */
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

/* PORT_H_001: EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0060*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. Software Version is updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, two APIs
 *                         'Port_SetToDioMode' and 'Port_SetToAlternateMode'
 *                         are added.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Software Minor Version is updated.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *
 * V1.4.0:  04-Sep-2013  : As per CR 236 for mantis #12602, Software Minor
 *                         Version is updated.
 *
 * V1.4.1:  09-Dec-2013  : As per CR 338 for mantis #11214, following changes
 *                         are made:
 *                         1. Software Patch Version is updated.
 *                         2. Alternative modes are added for Port_SetPinMode()
 *                            API.
 *
 * V1.4.2:  04-Jan-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity copyright information is updated.
 *
 * V1.5.0:  21-Feb-2014  : As per CR 419 for mantis #19676, Two APIs
 *                         'Port_SetPinDefaultDirection' and
 *                         'Port_SetPinDefaultMode' are added for ID Macros and
 *                         function prototype.
 *                         2. SWS Requirements are mapped.
 *
 * V1.5.1:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, SWS Requirements are mapped.
 *
 * V1.5.2:  22-Aug-2014  : As per CR 570, MISRA C Rule Violations are added as
 *                         QAC 8.1.1.
 * V1.5.3:  28-Jan-2015  : As per mantis #24335,#23568
 *                         1.Alternative modes are added to Port_SetPinMode()API
 *                         2.Port_Cfg.h is included.
 *                         3.Copyright information is updated.
 * V1.5.4:  04-Mar-2016  : Following changes are done
 *                         1.Copyright information is updated.
 *                         2.As per ARDAAAE-1672,
 *                           PORT_START_SEC_DBTOC_DATA_UNSPECIFIED is changed to
 *                           PORT_START_SEC_CONFIG_DATA_UNSPECIFIED and
 *                           PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED changed to
 *                           PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
 * V1.5.5   08-Aug-2016  : As part of P1x v4.01.01 release, following changes
 *                         are done:
 *                         1.As per ARDAAAE-1484,Macro declaration of
 *                           Port_GetVersionInfo is replaced with function
 *                           declaration and PORT_E_PARAM_POINTER macro is added
 *                         2.Unwanted Misra violations are removed.
 *                         3.As per ARDAAAE-1908, ASR3.2.2 version information
 *                           is removed
 *                         4.As per ARDAAAE-1936,unit design ID and requirement
 *                            tags are added at applicable places.
 * V1.5.6:  31-Aug-2016 :  As per ARDAAAE-2018, macro Port_ProtectedWrite is
 *                         added.
 * V1.5.7:  01-Feb-2017 :  Following changes are made:
 *                         1.As per ARDAAAE-2191,updated the format of
 *                           requirement tags
 *                         2.As per ARDAAAE-2276, Macro Port_ProtectedWrite is
 *                           changed to upper case and added suffix "U" to all
 *                           macros
 *                         3.As per ARDAAAE-2276,Variable Port_GstConfiguration
 *                           is made dimensional to remove the QAC warning
 *                           Msg (4:3684)
 */
/******************************************************************************/
/*PORT_H_002: AR_PN0062_FR_0001, EAAR_PN0034_FR_0052, AR_PN0062_FR_0005*/
/*PORT_H_003: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018*/
/*PORT_H_004: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020*/
/*PORT_H_005: EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0007, PORT207*/
#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* To publish the standard types */
#include "Std_Types.h"
/* To include pre compile values and switches */
/*PORT_H_006: PORT130, PORT204, PORT133, PORT108, EAAR_PN0034_FR_0020, PORT129*/
#include "Port_Cfg.h"
/* To publish the type Port_ConfigType */
#include "Port_Types.h"
/* PORT_H_007: PORT100, PORT107*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Port_Debug.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Version identification */
#define PORT_VENDOR_ID              PORT_VENDOR_ID_VALUE
#define PORT_MODULE_ID              PORT_MODULE_ID_VALUE
/* PORT_H_008: PORT_ESDD_UD_105*/
#define PORT_INSTANCE_ID            PORT_INSTANCE_ID_VALUE

/* PORT_H_009: PORT114*/

/* AUTOSAR release version information */
#define PORT_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_AR_RELEASE_MINOR_VERSION    0U
#define PORT_AR_RELEASE_REVISION_VERSION 3U

/* Module Software version information */
#define PORT_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE
#define PORT_SW_PATCH_VERSION    PORT_SW_PATCH_VERSION_VALUE
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* PORT_H_010: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:3412)-1 and          */
/*                 MISRA Violation: END Msg(4:3412)-1 tags in the code.       */

/*******************************************************************************
**                      API service ID Macros                                 **
*******************************************************************************/
/* Service ID for PORT Initialization */
#define PORT_INIT_SID                            (uint8)0x00U
/* Service ID for setting the Direction of PORT Pin */
#define PORT_SET_PIN_DIR_SID                     (uint8)0x01U
/* Service ID for refreshing the Direction of PORT Pin */
#define PORT_REFRESH_PORT_DIR_SID                (uint8)0x02U
/* Service ID for PORT getting Version Information */
#define PORT_GET_VERSION_INFO_SID                (uint8)0x03U
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_PIN_MODE_SID                    (uint8)0x04U
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_DIO_MODE_SID                 (uint8)0x05U
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_ALT_MODE_SID                 (uint8)0x06U
/* Service ID for setting the Default Mode of PORT Pin */
#define PORT_SET_PIN_DEFAULT_MODE_SID            (uint8)0x07U
/* Service ID for setting the Default Direction of PORT Pin */
#define PORT_SET_PIN_DEFAULT_DIR_SID             (uint8)0x08U


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* PORT_H_011: PORT116*/
/* Development error values are of type uint8 */

/* DET error type, values and related error codes */
/* PORT_H_012: PORT116, PORT051*/

/* Invalid Port Pin ID requested */
/* PORT_H_013: PORT051*/
#define PORT_E_PARAM_PIN                         (uint8)0x0AU

/* Port Pin Direction not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0BU

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                      (uint8)0x0CU

/* When valid Mode is not available */
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0DU

/* When valid Mode is not configured as changeable  */
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0EU

/* When PORT APIs are invoked before PORT Module Initialization */
#define PORT_E_UNINIT                            (uint8)0x0FU

/* When valid Database is not available */
#define PORT_E_INVALID_DATABASE                  (uint8)0xEFU

/* When GetVersionInfo is called with NULL pointer */
#define PORT_E_PARAM_POINTER                     (uint8)0x10U

/* PORT_H_014: PORT208, PORT212*/
/* Alternative modes for Port_SetPinMode() API */
#define APP_ALT1_OUT                 (Port_PinModeType)0x02U
#define APP_ALT1_IN                  (Port_PinModeType)0x03U
#define APP_ALT2_OUT                 (Port_PinModeType)0x04U
#define APP_ALT2_IN                  (Port_PinModeType)0x05U
#define APP_ALT3_OUT                 (Port_PinModeType)0x06U
#define APP_ALT3_IN                  (Port_PinModeType)0x07U
#define APP_ALT4_OUT                 (Port_PinModeType)0x08U
#define APP_ALT4_IN                  (Port_PinModeType)0x09U
#define APP_ALT5_OUT                 (Port_PinModeType)0x0AU
#define APP_ALT5_IN                  (Port_PinModeType)0x0BU
#define APP_ALT6_OUT                 (Port_PinModeType)0x0CU
#define APP_ALT6_IN                  (Port_PinModeType)0x0DU

#define APP_ALT1_OUT_SET_PIPC        (Port_PinModeType)0x82U
#define APP_ALT1_IN_SET_PIPC         (Port_PinModeType)0x83U
#define APP_ALT2_OUT_SET_PIPC        (Port_PinModeType)0x84U
#define APP_ALT2_IN_SET_PIPC         (Port_PinModeType)0x85U
#define APP_ALT3_OUT_SET_PIPC        (Port_PinModeType)0x86U
#define APP_ALT3_IN_SET_PIPC         (Port_PinModeType)0x87U
#define APP_ALT4_OUT_SET_PIPC        (Port_PinModeType)0x88U
#define APP_ALT4_IN_SET_PIPC         (Port_PinModeType)0x89U
#define APP_ALT5_OUT_SET_PIPC        (Port_PinModeType)0x8AU
#define APP_ALT5_IN_SET_PIPC         (Port_PinModeType)0x8BU
#define APP_ALT6_OUT_SET_PIPC        (Port_PinModeType)0x8CU
#define APP_ALT6_IN_SET_PIPC         (Port_PinModeType)0x8DU

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* PORT_H_015: PORT201 */
/* Type definition for Port_PinType used by the API Port_SetPinDirection() */
/* PORT_H_016: PORT013, PORT013, PORT219 */
/* PORT_H_017: PORT_ESDD_UD_109*/
typedef uint16 Port_PinType;

/* Type definition for Port_PinDirectionType used by the API
 * Port_SetPinDirection()
 */
/* PORT_H_018: PORT046, PORT046 */
/* PORT_H_019: PORT_ESDD_UD_110*/
typedef enum ETag_Port_PinDirectionType
{
  /* The type Port_PinDirectionType shall be of enumeration type */
  /* PORT_H_020: PORT220 */
  PORT_PIN_OUT,
  PORT_PIN_IN
} Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the API
 * Port_SetPinMode()
 */
/* PORT_H_021: PORT124, PORT124, PORT221, PORT212 */
/* PORT_H_022: PORT_ESDD_UD_111*/
typedef uint8 Port_PinModeType;


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* External Declaration for Port Initialization API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_Init
           (P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDirection
                     (Port_PinType Pin, Port_PinDirectionType Direction);
#endif

#if (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection
                                  (Port_PinType Pin);
#endif

#if (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode
                                  (Port_PinType Pin);
#endif

/* External Declaration for Port refresh port direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_RefreshPortDirection(void);

#if (PORT_VERSION_INFO_API == STD_ON)
/* Declaration of API "Port_GetVersionInfo" */

extern FUNC(void, PORT_PUBLIC_CODE) Port_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA)versioninfo);

#endif /*(PORT_VERSION_INFO_API == STD_ON)*/

#if (PORT_SET_PIN_MODE_API == STD_ON)
/* External Declaration for Port set pin mode API. */
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
                                   (Port_PinType Pin, Port_PinModeType Mode);
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin);

extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin);
#endif

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* Structure for PORT Init configuration */
/* This global variable cannot be avoided as it is used to get the external
 * data for Port database configuration set.
 */
/*PORT_H_083: PORT_ESDD_UD_135*/
extern CONST(Port_ConfigType, PORT_CONST)
                              Port_GstConfiguration[PORT_NO_OF_CONFIG_SETS];

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* MISRA Violation: START Msg(4:3412)-1 */
/*Macro definition for Protected register write*/
#define PORT_PROTECTEDWRITE(reg, value, preg, sreg, loopcount) \
  do  \
  { \
    (preg) = PORT_WRITE_ERROR_CLEAR_VAL;  \
    (reg) = (value);  \
    (reg) = ~(value); \
    (reg) = (value);  \
    (loopcount) = (loopcount) - PORT_ONE;  \
  }while ((PORT_LONG_WORD_ONE == (sreg)) && (PORT_ZERO <(loopcount)));
/* MISRA Violation: END Msg(4:3412)-1 */

#endif /* PORT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
