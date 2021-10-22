/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Cfg.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  29-Aug-2012  : Initial Version
 * V1.0.1:  23-Jan-2013  : As per SCR 068,
 *                         1. Macro WDG_59_DRIVERA_SW_PATCH_VERSION_VALUE is
 *                            added.
 *                         2. "Wdg_" prefix is removed from configuration set
 *                            handles macro.
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  04-Feb-2014  : As per CR 400 and mantis #19208, for P1x-F1x merge
 *                         activity following changes are made:
 *                         1. Copyright information is updated.
 *                         2. Template_Hash is updated.
 * V1.0.4:  28-Feb-2014  : As per CR 422 and mantis #19537, following changes
 *                         are made:
 *                         1. Hash BswHdrTpl::Template_Hash is updated.
 *                         2. COPYRIGHT section is updated.
 * V1.0.5:  16-May-2014  : As per CR 490 and mantis issue #21269, Macros
 *                         WDG_READBACK_OPTION, WAKEUP_FACTOR_CLEAR_ISR, WUF0,
 *                         WUFC0 are added and ENB_NMI_INT is removed.
 * V1.0.6:  02-Sep-2014 :  As per CR 560 and mantis #22252, Changes are made at
 *                         all relevant places accordingly to append U or UL
 *                         after numeric values.
 * V1.0.7:  23-May-2016 :  The following changes are made :
 *                         1. As per JIRA ticket ARDAAAE-1877, the macro
 *                         WDG_59_DRIVERA_DISABLE_ALLOWED is removed.
 *                         2. As per JIRA ticket ARDAAAE-1908, the macro
 *                         WDG_59_DRIVERA_AR_VERSION is removed.
 * V1.0.8:  12-Jan-2017 :  Following changes are made
 *                         1.Copyright information is updated.
 *                         2.As per ARDAAAE-2330,
 *                          WDG_59_DRIVERA_INTWDTEIC_ADDR macro is added.
 */
/******************************************************************************/
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.21
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Wdg_ECUC_6258906692274713601.arxml
 *                C:\Component\FAAR_WE_Synergy\Wdg\generate\R403_WDG_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 20:00:11
 */

#ifndef WDG_59_DRIVERA_CFG_H
#define WDG_59_DRIVERA_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_CFG_AR_RELEASE_MAJOR_VERSION      4U
#define WDG_59_DRIVERA_CFG_AR_RELEASE_MINOR_VERSION      0U
#define WDG_59_DRIVERA_CFG_AR_RELEASE_REVISION_VERSION   3U


/* File version information */
#define WDG_59_DRIVERA_CFG_SW_MAJOR_VERSION  1U
#define WDG_59_DRIVERA_CFG_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE    4U
#define WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE    0U
#define WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE 3U

#define WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE            1U
#define WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE            0U
#define WDG_59_DRIVERA_SW_PATCH_VERSION_VALUE            12U

#define WDG_59_DRIVERA_VENDOR_ID_VALUE                   59U
#define WDG_59_DRIVERA_MODULE_ID_VALUE                   102U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* TRACE [R4, WDG115_Conf] */
/* TRACE [R4, WDG045] */
/* TRACE [R4, WDG064] */
/* TRACE [R4, WDG066] */
/* Pre-compile option for development error detect. */
#define WDG_59_DRIVERA_DEV_ERROR_DETECT     STD_ON

/* TRACE [R4, WDG131_Conf] */
/* Maximum timeout in msec to which the watchdog trigger condition can
   be initialized. */
#define WDG_59_DRIVERA_MAXIMUM_TIMEOUT      (uint16)10000

/* TRACE [R4, WDG130_Conf] */
/* Initial timeout in msec for the trigger condition to be initialized
   during Init or set mode function. */
#define WDG_59_DRIVERA_INITIAL_TIMEOUT      (uint32)10000

/* Represents the watchdog driver execution area is either from
   ROM(Flash) or RAM as required with the particular microcontroller. */
#define WDG_59_DRIVERA_RUN_AREA             WDG_59_DRIVERA_ROM

/* TRACE [R4, WDG109] */
/* Pre-compile option for version info API. */
#define WDG_59_DRIVERA_VERSION_INFO_API     STD_ON

/* Compile switch to allow/forbid VAC. */
#define WDG_59_DRIVERA_VAC_ALLOWED          STD_ON

/* Pre-compile option for error mode switching */
#define WDG_59_DRIVERA_ERR_MODE_SET         WDG_59_DRIVERA_RESET_MODE

/* Pre-compile option for enable or disable inter-module dependencies. */
#define WDG_59_DRIVERA_VER_CHECK_EXT        STD_OFF

/* Pre-compile option for critical section protection */
#define WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION STD_ON

/* Watchdog Driver Id */
#define WDG_59_DRIVERA_INDEX                (uint8)0

/* If error during mode switch failed, the following error is reported to DEM */
#define WDG_59_DRIVERA_E_DISABLE_REJECTED   \
  DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED

/* If switching between the modes is failed, the following error is reported
   to DEM */
#define WDG_59_DRIVERA_E_MODE_FAILED        \
  DemConf_DemEventParameter_WDG_E_MODE_FAILED

/* Enable/Disable the register write verify check
   WV_DISABLE          0U
   WV_INIT_ONLY        1U
   WV_INIT_RUNTIME     2U */
#define WDG_59_DRIVERA_WRITE_VERIFY         0U

/* Enables/Disables the interrupt consistency check functionality */
#define WDG_59_DRIVERA_INTERRUPT_CONSISTENCY_CHECK STD_OFF

/* Pre-compile option to enable or disable mode switching
 error reporting to Dem */
#define WDG_59_DRIVERA_E_MODE_FAILED_REPORTING STD_ON

/* Pre-compile option for enable or disable following
 error reporting to Dem. */
#define WDG_59_DRIVERA_E_DISABLE_REJECTED_REPORTING STD_ON


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Instance ID of the WDG Component */
#define WDG_59_DRIVERA_INSTANCE_ID_VALUE              0U

/* TRACE [R4, WDG127_Conf] */
/* Watchdog trigger mode */
#define WDG_59_DRIVERA_TRIGGER_MODE                   WDG_59_DRIVERA_WINDOW

/* Configuration Set Handles */
#define WdgSettingsConfig         (&Wdg_59_DriverA_GstConfiguration)

/* Address of Trigger Register when VAC is ON */
#define WDG_59_DRIVERA_WDTAEVAC_ADDRESS     (*((volatile uint8*)0xFFD74004UL))
/* Address of Reference Register */
#define WDG_59_DRIVERA_WDTAREF_ADDRESS      (*((volatile uint8*)0xFFD74008UL))
/* Address of Trigger Register */
#define WDG_59_DRIVERA_WDTAWDTE_ADDRESS     (*((volatile uint8*)0xFFD74000UL))

/* Address of Mode Register */
#define WDG_59_DRIVERA_WDTAMD_ADDRESS       (*((volatile uint8*)0xFFD7400CUL))

/* Address of INTWDT IMR Register */
#define WDG_59_DRIVERA_INTWDTIMR_ADDR       ((volatile uint32*)0xFFFEEAF0UL)

/* INTWDT Interrupt enable IMR mask */
#define WDG_59_DRIVERA_INTWDTIMR_MASK       (uint32)0xFFFFFDFFUL

/* Address of INTWDT EIC Register */
#define WDG_59_DRIVERA_INTWDTEIC_ADDR       (volatile uint16*)0xFFFEEA12U

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* WDG_59_DRIVERA_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
