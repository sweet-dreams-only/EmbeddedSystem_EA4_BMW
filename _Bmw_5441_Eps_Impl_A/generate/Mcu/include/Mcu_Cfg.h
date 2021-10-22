/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
/* intellectual, merchantability and/or fitness for the particular            */
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
 * V1.0.0:  26-Aug-2013 : Initial Version
 * V1.1.0:  21-Apr-2014 : Following changes are made:
 *                        1. Copyright information is updated.
 * V1.1.1:  15-Sep-2014 : As per CR 008 for mantis #19850, following changes
 *                        are made:
 *                        1. Marker IDs are added newly.
 *                        2. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 *                        3. Section Global Data Types is updated for addition
 *                           of MAX_NUM_MODE.
 * V1.1.2:  09-Nov-2015 : 1. As part of P1M V4.00.05 ASIL-D release, as per
 *                        ARDAAAE-1464, macros for CLMA operation and CLMA
 *                        diagnostic test of different CLMA modules are
 *                        unified as single macro. Added macro
 *                        TOTAL_CLMA_CONFIGURED.
 *                        2. As per fusa requirements
 *                        EAAR_PN0079_FSR_0099 EAAR_PN0079_FSR_0100, and
 *                        EAAR_PN0079_FSR_0101, DEM definition
 *                        MCU_E_RESETCONTROLLER_STARTUP_FAILURE and
 *                        MCU_RESETCONTROLLER_STARTUP_TEST precompile
 *                        switch are added and  template is modified.
 *                        2. As per general safety requirements, DEM definition
 *                        MCU_E_INT_INCONSISTENT, macros MCU_WRITE_VERIFY
 *                        and MCU_INTERRUPT_CONSISTENCY_CHK  are added and
 *                        template is modified.
 * 1.1.3:  29-Feb-2016 :  Following changes are done as part of P1M
 *                        V4.01.00 release activity.
 *                        1. As per ticket ARDAAAE-1180, command line
 *                           option -f is added for file version display
 *                        2. Copyright Info is updated.
 * 1.1.4:  02-Jun-2016 :  Following changes are done as part of P1M
 *                        V4.01.01 release activity.
 *                        1. As per ticket ARDAAAE-1909, updated
 *                           warranty disclaimer.
 *                        2. Perl_File_Version_Hash is updated with latest
 *                           file version.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.1.5
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Mcu_ECUC_3350516407282010857.arxml
 *                C:\Component\FAAR_WE_Synergy\Mcu\generate\R403_MCU_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:53
 */


#ifndef MCU_CFG_H
#define MCU_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_CFG_AR_RELEASE_MINOR_VERSION  0U
#define MCU_CFG_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define MCU_CFG_SW_MAJOR_VERSION  1U
#define MCU_CFG_SW_MINOR_VERSION  0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define MCU_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define MCU_AR_RELEASE_MINOR_VERSION_VALUE  0U
#define MCU_AR_RELEASE_REVISION_VERSION_VALUE 3U

#define MCU_SW_MAJOR_VERSION_VALUE          1U
#define MCU_SW_MINOR_VERSION_VALUE          0U
#define MCU_SW_PATCH_VERSION_VALUE          8U

#define MCU_VENDOR_ID_VALUE                 59U
#define MCU_MODULE_ID_VALUE                 101U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the MCU Driver */
#define MCU_INSTANCE_ID_VALUE               0U

/* TRACE [R4, MCU166_Conf] */
/* TRACE [R4, MCU100] */
/* Pre-compile option for the development error detection and reporting */
#define MCU_DEV_ERROR_DETECT                STD_ON

/* TRACE [R4, MCU168_Conf] */
/* Pre-compile option for Mcu_GetVersion API */
#define MCU_VERSION_INFO_API                STD_OFF

/* TRACE [R4, MCU167_Conf] */
/* Pre-compile option for Mcu_PerformReset API */
#define MCU_PERFORM_RESET_API               STD_ON

/* Pre-compile option for the critical section functionality */
#define MCU_CRITICAL_SECTION_PROTECTION     STD_ON

/* Pre-compile option for availability of CLMA */
#define MCU_CLMA_OPERATION                  STD_ON

/* Pre-compile option for enable or disable inter-module dependencies */
#define MCU_VERSION_CHECK_EXT_MODULES       STD_OFF

/* TRACE [R4, MCU181_Conf] */
/* Pre-compile option for Mcu_GetRamState API */
#define MCU_GET_RAM_STATE_API               STD_OFF

/* TRACE [R4, MCU182_Conf] */
/* Pre-compile option for Mcu_InitClock API */
#define MCU_INIT_CLOCK                      STD_ON

/* TRACE [R4, MCU180_Conf] */
/* Pre-compile option for availability of PLL */
#define MCU_NO_PLL                          STD_ON

/* Pre-compile option for MCU_RESET_CALLOUT API */
#define MCU_SW_RESET_CALL_API               STD_OFF

/* Pre-compile option for Ram Sector */
#define MCU_RAM_SECTOR_SETTING_CONFIGURED   STD_OFF

/* Pre-compile option for CVM Self Diagnostic function */
#define MCU_CVM_SELFDIAGNOSTIC_TEST         STD_OFF

/* Pre-compile option for CLMA Self Diagnostic Test */
#define MCU_CLMA_SELFDIAGNOSTIC_TEST        STD_OFF

/* Pre-compile option for ECM Self Diagnostic function */
#define MCU_ECM_SELFDIAGNOSTIC_TEST         STD_OFF

/* Pre-compile option for LockStep Self Diagnostic Test */
#define MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST    STD_OFF

/* Pre-compile option for Software Reset StartUp Diagnostic Test */
#define MCU_SW_STARTUP_TEST                 STD_OFF

/* Pre-compile option for Ecm Reset StartUp Diagnostic Test */
#define MCU_ECM_STARTUP_TEST                STD_OFF

/* Pre-compile option for Interrupt Consistency Check  */
#define MCU_INTERRUPT_CONSISTENCY_CHK       STD_OFF

/* Pre-compile option for Error Interface */
#define MCU_USE_WRITE_VERIFY_ERROR_INTERFACE STD_ON

/* Pre-compile option for Write Verify  */
#define MCU_WRITE_VERIFY                    0

/* Pre-compile option for Ecm Delay Timer */
#define MCU_ECM_DLYTIMER_VALUE              (uint16)0xFFFF

/* Mcu ecm error output mode dynamic/non-dynamic */
#define MCU_ECM_ERROUT_MODE                 (uint8)0x00

/* Maximum number of Clock setting */
#define MCU_MAX_CLK_SET                     (uint8)0x01

/* Maximum number of Loop Counter */
#define MCU_LOOPCOUNT                       (uint8)0x05

/* Pre-compile option for Error Pulse Control Register */
#define MCU_ECM_ERROUT_TIMER                (uint8)0x00

/* Total number of CLMA configured */
#define TOTAL_CLMA_CONFIGURED               (uint8)0x04

/* TRACE [R4, MCU188_Conf] */
/* The failure in stabilization of Clock sources and failure in
 * switching of clock sources for clock domains is reported to DEM
 */
#define MCU_E_CLOCK_FAILURE                 \
  DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE

/* The failure of writing to write-protected register is reported to DEM */
#define MCU_E_WRITE_TIMEOUT_FAILURE         \
  DemConf_DemEventParameter_MCU_E_WRITE_TIMEOUT_FAILURE

/* User configured error notification during write verification failure*/
#define MCU_WRITE_VERIFY_ERROR_NOTIFICATION HndlMcalWrVrfyErr



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Maximum number of RAM Settings */

/* TRACE [R4, MCU171_Conf] */
/* Maximum number of MODE Settings */
#define MCU_MAX_MODESETTING                 (Mcu_ModeType)1

/* Handles for RAM sector setting */

/* Configuration Set Handles */
#define McuModuleConfiguration              (&Mcu_GstConfiguration[0])

/* Clock Configuration Handles */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig (Mcu_ClockType)0x00

/* Mode Setting Handles */
#define McuConf_McuModeSettingConf_McuModeSettingConf (Mcu_ModeType)0x00

/* Reset Reason Handles */
#define McuConf_McuRstRsnConfPowOnClr_McuRstRsnConfPowOnClr (Mcu_ResetType)0x00
#define McuConf_McuRstRsnConfPinRst_McuRstRsnConfPinRst (Mcu_ResetType)0x01
#define McuConf_McuRstRsnConfSwRst_McuRstRsnConfSwRst (Mcu_ResetType)0x02
#define McuConf_McuRstRsnConfWdta_McuRstRsnConfWdta (Mcu_ResetType)0x03
#define McuConf_McuRstRsnConfLockStepCompare_McuRstRsnConfLockStepCompare (Mcu_ResetType)0x04
#define McuConf_McuRstRsnConfClkMonUprLimErMosc_McuRstRsnConfClkMonUprLimErMosc (Mcu_ResetType)0x05
#define McuConf_McuRstRsnConfClkMonLwrLimErMosc_McuRstRsnConfClkMonLwrLimErMosc (Mcu_ResetType)0x06
#define McuConf_McuRstRsnConfClkMonUprLimErWdt_McuRstRsnConfClkMonUprLimErWdt (Mcu_ResetType)0x07
#define McuConf_McuRstRsnConfClkMonLwrLimErWdt_McuRstRsnConfClkMonLwrLimErWdt (Mcu_ResetType)0x08
#define McuConf_McuRstRsnConfClkMonUprLimErPclk_McuRstRsnConfClkMonUprLimErPclk (Mcu_ResetType)0x09
#define McuConf_McuRstRsnConfClkMonLwrLimErPclk_McuRstRsnConfClkMonLwrLimErPclk (Mcu_ResetType)0x0A
#define McuConf_McuRstRsnConfClkMonUprLimErPe1_McuRstRsnConfClkMonUprLimErPe1 (Mcu_ResetType)0x0B
#define McuConf_McuRstRsnConfClkMonLwrLimErPe1_McuRstRsnConfClkMonLwrLimErPe1 (Mcu_ResetType)0x0C
#define McuConf_McuRstRsnConfLRamEcc2AddPrty_McuRstRsnConfLRamEcc2AddPrty (Mcu_ResetType)0x0D
#define McuConf_McuRstRsnConfInstCacheRamEcc2_McuRstRsnConfInstCacheRamEcc2 (Mcu_ResetType)0x0E
#define McuConf_McuRstRsnConfCodeFlsEcc2AddPrty_McuRstRsnConfCodeFlsEcc2AddPrty (Mcu_ResetType)0x0F
#define McuConf_McuRstRsnConfDataFlsEcc2_McuRstRsnConfDataFlsEcc2 (Mcu_ResetType)0x10
#define McuConf_McuRstRsnConfDtsRamEcc2_McuRstRsnConfDtsRamEcc2 (Mcu_ResetType)0x11
#define McuConf_McuRstRsnConfCsihRamEcc2_McuRstRsnConfCsihRamEcc2 (Mcu_ResetType)0x12
#define McuConf_McuRstRsnConfCanRamEcc2_McuRstRsnConfCanRamEcc2 (Mcu_ResetType)0x13
#define McuConf_McuRstRsnConfFrRamEcc2_McuRstRsnConfFrRamEcc2 (Mcu_ResetType)0x14
#define McuConf_McuRstRsnConfFlsProgMode_McuRstRsnConfFlsProgMode (Mcu_ResetType)0x15
#define McuConf_McuRstRsnConfTestMode_McuRstRsnConfTestMode (Mcu_ResetType)0x16
#define McuConf_McuRstRsnConfSingChipModInact_McuRstRsnConfSingChipModInact (Mcu_ResetType)0x17
#define McuConf_McuRstRsnConfPeGuard_McuRstRsnConfPeGuard (Mcu_ResetType)0x18
#define McuConf_McuRstRsnConfPBusGuard_McuRstRsnConfPBusGuard (Mcu_ResetType)0x19
#define McuConf_McuRstRsnConfSarAdcPrty_McuRstRsnConfSarAdcPrty (Mcu_ResetType)0x1A
#define McuConf_McuRstRsnConfBusDataPrty_McuRstRsnConfBusDataPrty (Mcu_ResetType)0x1B
#define McuConf_McuRstRsnConfEcmCompare_McuRstRsnConfEcmCompare (Mcu_ResetType)0x1C
#define McuConf_McuRstRsnConfLvi_McuRstRsnConfLvi (Mcu_ResetType)0x1D
#define McuConf_McuRstRsnConfTempSensor_McuRstRsnConfTempSensor (Mcu_ResetType)0x1E
#define McuConf_McuRstRsnConfDmaTrans_McuRstRsnConfDmaTrans (Mcu_ResetType)0x1F
#define McuConf_McuRstRsnConfDmaViol_McuRstRsnConfDmaViol (Mcu_ResetType)0x20
#define McuConf_McuRstRsnConfLRamEcc1_McuRstRsnConfLRamEcc1 (Mcu_ResetType)0x21
#define McuConf_McuRstRsnConfCodeFlsEcc1_McuRstRsnConfCodeFlsEcc1 (Mcu_ResetType)0x22
#define McuConf_McuRstRsnConfDataFlsEcc1_McuRstRsnConfDataFlsEcc1 (Mcu_ResetType)0x23
#define McuConf_McuRstRsnConfDtsRamEcc1_McuRstRsnConfDtsRamEcc1 (Mcu_ResetType)0x24
#define McuConf_McuRstRsnConfPeriRamEcc1_McuRstRsnConfPeriRamEcc1 (Mcu_ResetType)0x25
#define McuConf_McuRstRsnConfBistCodeEcc1_McuRstRsnConfBistCodeEcc1 (Mcu_ResetType)0x26
#define McuConf_McuRstRsnConfBistCodeEcc2_McuRstRsnConfBistCodeEcc2 (Mcu_ResetType)0x27
#define McuConf_McuRstRsnConfFaci_McuRstRsnConfFaci (Mcu_ResetType)0x28
#define McuConf_McuRstRsnConfEcmDelayOverFlow_McuRstRsnConfEcmDelayOverFlow (Mcu_ResetType)0x29
#define McuConf_McuRstRsnConfRstUndefined_McuRstRsnConfRstUndefined (Mcu_ResetType)0x2B
#define McuConf_McuRstRsnConfRstUnknown_McuRstRsnConfRstUnknown (Mcu_ResetType)0x2C

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
