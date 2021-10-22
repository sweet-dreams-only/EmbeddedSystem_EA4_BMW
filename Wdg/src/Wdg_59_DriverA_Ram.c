/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Ram.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver A                      */
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
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.2:  02-Jan-2014    : As per CR 334 and mantis #13043, global variable
 *                           Wdg_59_DriverA_GusTiggerCounter placed under memory
 *                           section WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16BIT.
 *
 * V1.0.3:  16-Jan-2014    : As per CR 350 and mantis #13043, pre-compile is
 *                           added for inclusion of global variable
 *                           Wdg_59_DriverA_GusTiggerCounter.
 *
 * V1.0.4:  03-Jun-2014    : As per CR 490 for mantis 21269, following changes
 *                           are made:
 *                           1. Wdg_59_DriverA_GulIMR1Mirror and
 *                           Wdg_59_DriverA_GulIMR1Mask global variables are
 *                           added.
 *                           2. Wdg_59_DriverA_PBTypes.h and
 *                              Wdg_59_DriverA_RegReadBack.h are included.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.6:  04-Mar-2016    : As part of P1x V4.01.00 release,the following
 *                           changes are made,
 *                           1.As per JIRA ticket ARDAAAE-1486,
 *                             Storage specifier is changed from AUTOMATIC to
 *                             TYPEDEF.
 *                           2.As per JIRA ticket ARDAAAE-1672, memory section
 *                             for Global variable Wdg_59_DriverA_GddDriverState
 *                             updated.
 *                           3.As per JIRA ticket ARDAAAE-1593,
 *                             memory section for Global variable
 *                             Wdg_59_DriverA_GusTiggerCounter is updated.
 *                           4.Copyright information is updated.
 *                           5.MISRA violation START and END msgs for
 *                             Msg(2:3211),Msg(2:0862) and Msg(2:2022)
 *                             are added at the respective places.
 *
 * V1.0.7:  18-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1752,
 *                           READBACK_OPTION related code segment is removed.
 *                           2.As per ARDAAAE-1908,Dead code is removed.
 *                           3.As per JIRA ticket ARDAAAE-1672, memory section
 *                             SEC_VAR_NOINIT_UNSPECIFIED and SEC_VAR_NOINIT_16
 *                             are renamed to SEC_VAR_NO_INIT_UNSPECIFIED and
 *                             SEC_VAR_NOINIT_16.
 *                           4.As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           5.As per ARDAAAE-2090,variable type for
 *                            Wdg_59_DriverA_GusTiggerCounter is changed from
 *                            uint16 to uint32.
 *                           6.As per ARDAAAE-2075,variable
 *                            Wdg_59_DriverA_GusTiggerCounter and
 *                            Wdg_59_DriverA_GddDriverState declared volatile.
 *                           7.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.8:  07-Feb-2017    : 1.As part of JIRA ID ARDAAAE-2355
 *                             The naming conventions are changed from
 *                             Wdg_59_DriverA_GusTiggerCounter to
 *                             Wdg_59_DriverA_GulTiggerCounter
 *                           2.Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R3, WDG061] */
/* TRACE [R4, WDG168] */
/* Implements EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */
/* Included for module version information and other types declarations */
#include "Wdg_59_DriverA.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Ram.h"
/* Header file inclusion for macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_RAM_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_SW_MINOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:2022)-1 and              */
/*                 END Msg(2:2022)-1 tags in the code.                        */

/******************************************************************************/

/* 2. QAC WARNING:                                                            */
/* Message       :(2:3211) Cast between a pointer to volatile object and      */
/*                 an integral type.                                          */
/* Rule          : NA                                                         */
/* Justification : The Global Post Build variables are defined in this        */
/*                 translation unit and is used in the other files.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:3211)-2 and              */
/*                 END Msg(2:3211)-2 tags in the code.                        */

/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       :(2:0862) This #include "%s" directive is redundant.         */
/* Rule          : NA                                                         */
/* Justification : All the #include "%s" files contains C function            */
/*                 declarations or macro definitions to be shared between     */
/*                 several source files. This violation is an approved        */
/*                 exception without side effects.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Implements WDG148 */
#define WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* QAC warning: START Msg(2:3211)-2 */
/* QAC warning: START Msg(2:2022)-1 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG152 */
/* Global variable to store the current watchdog driver state */
VAR(volatile Wdg_59_DriverA_StatusType, WDG_59_DRIVERA_INIT_DATA)
                          Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_UNINIT;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */
#define WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#endif

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* QAC warning: START Msg(2:3211)-2 */
/* QAC warning: START Msg(2:2022)-1 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG154 */
/* Global variable to store the current watchdog driver mode */
VAR(WdgIf_ModeType, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GddCurrentMode;

/* Implements WDG_ESDD_UD_025 */
/* Global variable to store pointer to Configuration */
P2CONST(Wdg_59_DriverA_ConfigType, TYPEDEF,
                        WDG_59_DRIVERA_CONFIG_CONST)Wdg_59_DriverA_GpConfigPtr;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */
#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"
/* QAC warning: START Msg(2:3211)-2 */
/* QAC warning: START Msg(2:2022)-1 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG153 */
/* Global variable to store the trigger counter value */
VAR(volatile uint32, WDG_59_DRIVERA_NOINIT_DATA)
                                         Wdg_59_DriverA_GulTiggerCounter;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */
#define WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
