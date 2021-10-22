/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the global RAM variable of MCU Driver                   */
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
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. Mcu_GblRAMInitStatus is updated with values in
 *                           enum 'Mcu_RamStateType'
 *                        2. Mcu_GblResetStatusSaved is added since it is using
 *                           for internal API Mcu_SaveResetReason()
 *
 * V1.0.2:  08-Oct-2014 : As per CR008 and mantis #19850, Following change
 *                        is made,
 *                        1. Trace marking is added in the file
 *
 * V1.0.3:  05-Dec-2014 : As per CR076 and mantis #21577,#25069, following
 *                        changes are made,
 *                        1.Trailing spaces are removed from the file.
 *                        2.Mcu_GblResetStatusSaved moved to
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
 * V1.0.6:  24-Oct-2016 : Following changes are done as part of P1M
 *                        1. Removed unwanted declaration of Mcu_GpRamSetting.
 *                        2. As per ARDAAAE-1672, memory section
 *                           _NOINIT_  changed to _NO_INIT_ to follow
 *                           initialization policy of variables.
 *                        3. Moved global variables Mcu_GblDriverStatus,
 *                           Mcu_GblResetStatusSaved, Mcu_GulMcuSavedResfStatus,
 *                           Mcu_GulLastResetReasonStatus to Mcu.c file.
 *                        4. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        5. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 *                        6. As per ticket ARDAAAE-2043, volatile declaration is
 *                           added for Mcu_GblRAMInitStatus.
 *                        7. QAC warning Message 0862 justification added.
 *                        8. As per ticket ARDAAAE-2060, unmapped design
 *                           requirements mapped.
 */
/******************************************************************************/



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0001 */
/* Implements EAAR_PN0034_NR_0002 */
/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Header file inclusion */
#include "Mcu_Ram.h"

/* Included for version check macro definitions and type definitions */
#include "Mcu.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*Implements EAAR_PN0034_FR_0055,EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002,
             EAAR_PN0034_NR_0018
*/
/* AUTOSAR release version information */
#define MCU_RAM_C_AR_RELEASE_MAJOR_VERSION    \
                                           MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_MINOR_VERSION    \
                                           MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_REVISION_VERSION  \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_RAM_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_RAM_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (MCU_RAM_AR_RELEASE_MAJOR_VERSION != MCU_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Major Version"
#endif /* (MCU_RAM_AR_RELEASE_MAJOR_VERSION !=
        *                              MCU_RAM_C_AR_RELEASE_MAJOR_VERSION)
        */

#if (MCU_RAM_AR_RELEASE_MINOR_VERSION != MCU_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Minor Version"
#endif /* (MCU_RAM_AR_RELEASE_MINOR_VERSION !=
        *                              MCU_RAM_C_AR_RELEASE_MINOR_VERSION)
        */

#if (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
                                   MCU_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Revision Version"
#endif /* (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
        *                           MCU_RAM_C_AR_RELEASE_REVISION_VERSION)
        */

#if (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Major Version"
#endif /* (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION) */

#if (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Minor Version"
#endif /* (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION) */
/*Implements EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message      : (2:2022) This is a tentative definition and according to    */
/*                the ISO:C Standard, the object will automatically be        */
/*                initialized to zero.                                        */
/* Rule         : MISRA-C:2004 Rule 1.1                                       */
/* Justification: The object's initialisation to zero will not affect the     */
/*                functionality.                                              */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:2022)-1 and                            */
/*                END Msg(2:2022)-1 tags in the code.                         */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier 'Mcu_GpConfigPtr' is defined */
/*                here but is not used in this translation unit.              */
/* Rule         : MISRA-C:2004 Message 3211                                   */
/* Justification: As per AUTOSAR, all global variables extern declaration     */
/*                shall be given in Mcu_Ram.h                                 */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-2 and                            */
/*                END Msg(2:3211)-2 tags in the code.                         */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : MISRA-C:2004 Message 0862                                  */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/******************************************************************************
**                         Global Data                                       **
******************************************************************************/
/* Implements MCU200, EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045*/
/* Implements EAAR_PN0034_NR_0069, EAAR_PN0034_FR_0019, MCU202 */

/*To use VAR_NO_INIT section in the Memory*/
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* START Msg(2:2022)-1 */
/* START Msg(2:3211)-2 */
/* Implements MCU_ESDD_UD_090 */
/* Implements MCU_ESDD_UD_101 */
/* Global variable to store the config pointer */
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Implements MCU_ESDD_UD_092 */
/* Implements MCU_ESDD_UD_103 */
/* Global pointer variable for MCU Clock Setting configuration */
P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpClockSetting;

/* Implements MCU_ESDD_UD_090 */
/* Implements MCU_ESDD_UD_105 */
/* Global pointer variable for MCU ECM Setting configuration */
P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpEcmSetting;

/* Implements MCU_ESDD_UD_104 */
VAR(Mcu_ExtnClkSettingReg, MCU_VAR) Mcu_GpExtnClkSettingReg;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */

/*Exit VAR_NO_INIT section in the Memory*/
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*To use VAR_BOOLEAN section in the Memory*/
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* START Msg(2:3211)-2 */
/* Implements MCU_ESDD_UD_091 */
/* Implements EAAR_PN0079_FR_0008*/
/* Global variable to store ram status of MCU Driver */
VAR(volatile boolean, MCU_INIT_DATA) Mcu_GblRAMInitStatus =
                                                   (boolean) MCU_RAMSTATE_VALID;
/* END Msg(2:3211)-2 */
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*Exit VAR_BOOLEAN section in the Memory*/
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
