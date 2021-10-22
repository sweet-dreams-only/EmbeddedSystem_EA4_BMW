/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Cfg.h                                                  */
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
 * V1.0.0:  05-Sep-2012  : Initial version
 * V1.1.0:  16-Jan-2013  : As per SCR 055,
 *                         1.Added macro PORT_PIN_STATUS_BACKUP,
 *                           PORT_PROTCMD0, PORT_IOHOLD and PORT_PROTS0.
 * V1.2.0:  18-Mar-2013  : As per SCR 091 for mantis issue #7957 and #9240,
 *                         following changes are made:
 *                         1.Generation of Configuration Set Handles is updated.
 *                         2.Macros PORT_SET_TO_DIO_ALT_MODE_API and
 *                           PORT_PIN_STATUS_BACKUP are added.
 * V1.3.0:  06-Aug-2013  : As per CR 225 and as part of E1x-F1x merge activity,
 *                         Macro PORT_JTAG_PUCC_REGS is added.
 * V1.3.1:  20-Mar-2014  : As per CR 419, Macros
 *                         PORT_SET_PIN_DEFAULT_DIRECTION_API and
 *                         PORT_SET_PIN_DEFAULT_MODE_API are added.
 * V1.3.2:  28-Jul-2014  : As per CR 106, following macros
 *                         PORT_DNFCKS_BASE_ADDRESS, PORT_DNF_CLK_SRC_AVAILABLE
 *                         are added newly.
 * V1.3.3:  14-Aug-2014  : As per CR 570, For the mantis #22971,
 *                         following changes are made:
 *                         1. uint16 is replaced with Port_PinType for handle
 *                         generation.
 *                         2. Changes are made at all relevant places
 *                         accordingly to append U or UL after numeric values.
 * V1.3.4:  12-Nov-2014  : As per CR 650 for mantis #24637, following change
 *                         is made:
 *                         1. PPROTS_32BIT_REG_AVAILABLE macro is added.
 * V1.3.5:  20-Apr-2016  : As part of P1x V4.01.01 release ,following changes
 *                         are made:
 *                         1.As per ARDAAAE-1949,macros
 *                           PORT_USE_WRITE_VERIFY_ERROR_INTERFACE
 *                           PORT_WRITE_VERIFY,PORT_E_REG_WRITE_VERIFY,
 *                           PORT_WRITE_VERIFY_ERROR_NOTIFICATION are added
 *                         2.PORT_DEM_ERROR_DETECT is removed
 *                         3.As per ARDAAAE-1908,generation of macros
 *                           PORT_AR_VERSION,PORT_PIN_STATUS_BACKUP
 *                           PORT_IOHOLD_FUNC_AVAILABLE,PORT_PROTCMD0
 *                           PPCMD_32BIT_REG_AVAILABLE,PORT_PPCMD0
 *                           PPROTS_32BIT_REG_AVAILABLE,PORT_IOHOLD
 *                           PORT_PROTS0,PORT_PPROTS0,PORT_DNFS_AVAILABLE
 *                           PORT_DNFS_BASE_ADDRESS,PORT_EDGE_DETECT_CONTROL
 *                           PORT_DNFAEN_ADDRESS_OFFSET,PORT_JTAG_PFC_REGS,
 *                           PORT_JTAG_PIPC_REGS, PORT_JTAG_PFCAE_REGS,
 *                           and all the macros related
 *                           to alphabetic,analog,input ports are removed.
 *                          4.As per ARDAAAE-912,PORT_DNFAENL_ADDRESS_OFFSET
 *                           is added
 *                          5.Copyright information is updated.
 * V1.3.6:  02-Feb-2017  : Following changes are made:
 *                         1.Added suffix 'U' to all PRECOMPILE_OPTIONS,
 *                           REGISTER_COUNT and PORT_HANDLES
 *                         2.Copyright information updated
 *                         3.Array size macros added
 */
/******************************************************************************/
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.3.15
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Component\FAAR_WE_Synergy\Port\generate\R403_PORT_P1x_BSWMDT.arxml
 *                C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Port_ECUC_1959981837513444350.arxml
 * GENERATED ON:  30 Jul 2018 - 19:59:15
 */

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define PORT_CFG_AR_RELEASE_MINOR_VERSION  0U
#define PORT_CFG_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define PORT_CFG_SW_MAJOR_VERSION  1U
#define PORT_CFG_SW_MINOR_VERSION  5U

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define PORT_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define PORT_AR_RELEASE_MINOR_VERSION_VALUE  0U
#define PORT_AR_RELEASE_REVISION_VERSION_VALUE  3U

#define PORT_SW_MAJOR_VERSION_VALUE  1U
#define PORT_SW_MINOR_VERSION_VALUE  5U
#define PORT_SW_PATCH_VERSION_VALUE  4U

#define PORT_VENDOR_ID_VALUE  59U
#define PORT_MODULE_ID_VALUE  124U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the PORT Driver Component */
#define PORT_INSTANCE_ID_VALUE               0U

/* TRACE [R4, PORT100] */
/* TRACE [R4, PORT101] */
/* TRACE [R4, PORT107] */
/* TRACE [R4, PORT123_Conf] */
/* Enables/Disables Development error detect */
#define PORT_DEV_ERROR_DETECT               STD_ON

/* TRACE [R4, PORT131_Conf] */
/* Enables/Disables Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API          STD_ON

/* TRACE [R4, PORT132_Conf] */
/* Enables/Disables Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API               STD_ON

/* TRACE [R4, PORT103] */
/* TRACE [R4, PORT133_Conf] */
/* Enables/Disables Port_GetVersionInfo API */
#define PORT_VERSION_INFO_API               STD_ON

/* Enable/Disable the enter/exit critical section functionality */
#define PORT_CRITICAL_SECTION_PROTECTION    STD_ON

/* Indicates the number of Alternative Modes  */
#define PORT_MAX_MODE                       (uint8)0x0DU

/*  Indicates offset value of PIBC0 register */
#define PORT_OS_BASE_ADDRESS_OFFSET         (uint16)0x4000U

/* Indicates availability of PINV register */
#define PORT_PINV_REG_AVAILABLE             STD_ON

/* Indicates the write access of PPCMD register */
#define PORT_WRITE_ERROR_CLEAR_VAL          0x000000A5UL

/* Pre-compile option for enable or disable version check of
   inter-module dependencies */
#define PORT_VERSION_CHECK_EXT_MODULES      STD_OFF

/*  Indicates offset value of PODC register  */
#define PORT_NUM_PODC_REG_ADD_OFFSET        (uint16)0x4014U

/*  Indicates offset value of PDSC register  */
#define PORT_NUM_PDSC_REG_ADD_OFFSET        (uint16)0x4018U

/*  Indicates offset value of PUCC register  */
#define PORT_NUM_PUCC_REG_ADD_OFFSET        (uint16)0x4028U

/*  Indicates offset value of PPROTS register  */
#define PORT_NUM_PPROTS_REG_ADD_OFFSET      (uint16)0x4034U

/*  Indicates offset value of PPCMD register  */
#define PORT_NUM_PPCMD_REG_ADD_OFFSET       (uint16)0x4030U

/*  Indicates offset value of PODCE register  */
#define PORT_NUM_PODCE_REG_ADD_OFFSET       (uint16)0x403CU

/*  Indicates offset value of PINV register  */
#define PORT_NUM_PINV_REG_ADD_OFFSET        (uint16)0x0030U

/*  Indicates offset value of JPODCE register */
#define PORT_JTAG_PODCE_REG_ADD_OFFSET      (uint16)0x0000U

/*  Indicates offset value of JPINV register */
#define PORT_JTAG_PINV_REG_ADD_OFFSET       (uint16)0x0000U

/*  Indicates offset value of JPODC register  */
#define PORT_JTAG_PODC_REG_ADD_OFFSET       (uint16)0x4014U

/*  Indicates offset value of JPDSC register  */
#define PORT_JTAG_PDSC_REG_ADD_OFFSET       (uint16)0x4018U

/*  Indicates offset value of JPUCC register  */
#define PORT_JTAG_PUCC_REG_ADD_OFFSET       (uint16)0x4028U

/*  Indicates offset value of JPPROTS register  */
#define PORT_JTAG_PPROTS_REG_ADD_OFFSET     (uint16)0x4034U

/*  Indicates offset value of JPPCMD register  */
#define PORT_JTAG_PPCMD_REG_ADD_OFFSET      (uint16)0x4030U

/* Enables/Disables Port_SetToDioMode and Port_SetToAlternateMode API */
#define PORT_SET_TO_DIO_ALT_MODE_API        STD_ON

/* User define value for Endless Loop. */
#define PORT_LOOP_TIMEOUT                   (uint8)0x05U

/* Enables/Disables Port_SetPinDefaultDirection API */
#define PORT_SET_PIN_DEFAULT_DIRECTION_API  STD_ON

/* Enables/Disables Port_SetPinDefaultMode API */
#define PORT_SET_PIN_DEFAULT_MODE_API       STD_ON

/* Enable/Disable the register write-verify check
   WV_DISABLE          0x0U
   WV_INIT_ONLY        0x1U
   WV_INIT_RUNTIME     0x2U */
#define PORT_WRITE_VERIFY                   0x01U

/* Enable/Disable Reg Write-verify Failure Error Interface  */
#define PORT_USE_WRITE_VERIFY_ERROR_INTERFACE STD_ON


/* Availability of numeric port groups */
#define PORT_NUM_PORT_GROUPS_AVAILABLE      STD_ON

/* Availability of jtag port groups */
#define PORT_JTAG_PORT_GROUPS_AVAILABLE     STD_ON

/* The following constant contains total number of pins configured */
#define PORT_TOTAL_NUMBER_OF_PINS           (uint16)88U

/* DEM for Port register write timeout failure  */
#define PORT_E_WRITE_TIMEOUT_FAILURE        \
        DemConf_DemEventParameter_PORT_E_WRITE_TIMEOUT_FAILURE

/* DEM for Write Verify */
#define PORT_E_REG_WRITE_VERIFY             \
        DemConf_DemEventParameter_PORT_E_REG_WRITE_VERIFY

 /* Write Verify Error Notification Macro*/
 #define PORT_WRITE_VERIFY_ERROR_NOTIFICATION HndlMcalWrVrfyErr

/* Base Address of numeric port */
#define PORT_USER_BASE_ADDRESS_NUMERIC      (uint32)0xFFC10000UL

/* Os Address of numeric port */
#define PORT_OS_BASE_ADDRESS_NUMERIC        (uint32)0xFFC14000UL

/* Base Address of JTAG port */
#define PORT_USER_BASE_ADDRESS_JTAG         (uint32)0xFFC20000UL

/* Os Address of JTAG port */
#define PORT_OS_BASE_ADDRESS_JTAG           (uint32)0xFFC24000UL



/* Availability of DNFA noise elimination registers. */
#define PORT_DNFA_REG_CONFIG                STD_ON

/* Availability of FCLA noise elimination registers. */
#define PORT_FCLA_REG_CONFIG                STD_OFF

/* Availability of DNFAnEN noise elimination registers. */
#define PORT_DNFAEN_REG_AVAILABLE           STD_ON

/* Availability of DNFCKS noise elimination sampling clock
  source selection register. */
#define PORT_DNF_CLK_SRC_AVAILABLE          STD_ON


/* Starting address for DNFA noise elimination registers */
#define PORT_DNFA_BASE_ADDRESS              (uint32)0xffc31400UL

/* Address offset for Digital noise elimination enable register DNFAENL */
#define PORT_DNFAENL_ADDRESS_OFFSET         (uint32)0xCUL

/* Starting address of Digital noise filter sampling clock
  source selection register */
#define PORT_DNFCKS_BASE_ADDRESS            (uint32)0xFFF89100UL


/* The Total number of Numeric PSR registers configured */
#define PORT_NUM_PSR_REGS                   (uint8)0x06U

/* The Total number of Numeric PMCSR registers configured */
#define PORT_NUM_PMCSR_REGS                 (uint8)0x06U

/* The Total number of Numeric other 16-Bit registers configured */
#define PORT_NUM_OTHER_16BIT_REGS           (uint8)0x22U

/* The Total number of Numeric PODC registers configured */
#define PORT_NUM_PODC_REGS                  (uint8)0x06U

/* The Total number of Numeric PODCE registers configured */
#define PORT_NUM_PODCE_REGS                 (uint8)0x06U

/* The Total number of Numeric PINV registers configured */
#define PORT_NUM_PINV_REGS                  (uint8)0x06U

/* The Total number of Numeric PDSC registers configured  */
#define PORT_NUM_PDSC_REGS                  (uint8)0x06U

/* The Total number of Numeric PUCC registers configured  */
#define PORT_NUM_PUCC_REGS                  (uint8)0x06U

/* The Total number of Numeric Function Control registers configured */
#define PORT_NUM_FUNC_CTRL_REGS             (uint8)0x12U

/* The Total number of Numeric PISA registers configured  */
#define PORT_NUM_PISA_REGS                  (uint8)0x05U

/* The Total number of Numeric PIBC registers configured  */
#define PORT_NUM_PIBC_REGS                  (uint8)0x06U

/* The Total number of Numeric PIPC registers configured  */
#define PORT_NUM_PIPC_REGS                  (uint8)0x05U

/* The Total number of Numeric PU registers configured  */
#define PORT_NUM_PU_REGS                    (uint8)0x06U

/* The Total number of Numeric PD registers configured  */
#define PORT_NUM_PD_REGS                    (uint8)0x06U

/* The Total number of Numeric PBDC registers configured  */
#define PORT_NUM_PBDC_REGS                  (uint8)0x06U

/* The Total number of Numeric PFCE registers configured  */
#define PORT_NUM_PFCE_REGS                  (uint8)0x06U

/* The Total number of Numeric PFC registers configured  */
#define PORT_NUM_PFC_REGS                   (uint8)0x06U

/* The Total number of Numeric PFCAE registers configured  */
#define PORT_NUM_PFCAE_REGS                 (uint8)0x06U

/* The Total number of Numeric PMSR registers configured  */
#define PORT_NUM_PMSR_REGS                  (uint8)0x06U

/* The following constant contains total number of JPSR registers */
#define PORT_JTAG_PSR_REGS                  (uint8)0x01U

/* The following constant contains total number of  JPMCSR registers */
#define PORT_JTAG_PMCSR_REGS                (uint8)0x01U

/* The following constant contains total number of  JPODC registers */
#define PORT_JTAG_PODC_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPODCE registers */
#define PORT_JTAG_PODCE_REGS                (uint8)0x00U

/* The following constant contains total number of  JPINV registers */
#define PORT_JTAG_PINV_REGS                 (uint8)0x00U

/* The following constant contains total number of  JPDSC registers */
#define PORT_JTAG_PDSC_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPUCC registers */
#define PORT_JTAG_PUCC_REGS                 (uint8)0x01U

/* The following constant contains total number of 8 bit JTAG registers */
#define PORT_JTAG_OTHER_8BIT_REGS           (uint8)0x05U

/* The Total number of JTAG Function Control registers configured  */
#define PORT_JTAG_FUNC_CTRL_REGS            (uint8)0x01U

/* The following constant contains total number of  JPISA registers */
#define PORT_JTAG_PISA_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPIBC registers */
#define PORT_JTAG_PIBC_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPU registers */
#define PORT_JTAG_PU_REGS                   (uint8)0x01U

/* The following constant contains total number of  JPD registers */
#define PORT_JTAG_PD_REGS                   (uint8)0x01U

/* The following constant contains total number of  JPBDC registers */
#define PORT_JTAG_PBDC_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPFCE registers */
#define PORT_JTAG_PFCE_REGS                 (uint8)0x01U

/* The following constant contains total number of  JPMSR registers */
#define PORT_JTAG_PMSR_REGS                 (uint8)0x01U


/* Size of Port_GstNumRegs array */
#define PORT_NUM_REGS_ARRAY_SIZE            (uint8)0x46U

/* Size of Port_GstNumFuncCtrlRegs array */
#define PORT_NUM_FUNC_REGS_ARRAY_SIZE       (uint8)0x18U

/* Size of Port_GstNumPMSRRegs array */
#define PORT_NUM_PMSR_REGS_ARRAY_SIZE       (uint8)0x06U

/* Size of Port_GstJTAGRegs array */
#define PORT_JTAG_REGS_ARRAY_SIZE           (uint8)0x09U

/* Size of Port_GstJTAGFuncCtrlRegs array */
#define PORT_JTAG_FUNC_REGS_ARRAY_SIZE      (uint8)0x02U

/* Size of Port_GstJTAGPMSRRegs array */
#define PORT_JTAG_PMSR_REGS_ARRAY_SIZE      (uint8)0x01U

/* Size of Port_GstSetDioAltPinDetails array */
#define PORT_DIO_ALT_CHANGE_ARRAY_SIZE      (uint8)0x0CU

/* Size of Port_GstDNFARegs array */
#define PORT_DNFA_REGS_ARRAY_SIZE           (uint8)0x03U

/* Size of Port_GstFCLARegs array */
#define PORT_FCLA_REGS_ARRAY_SIZE           (uint8)0x00U

/* Size of Port_GstDNFCKSRegs array */
#define PORT_DNFCKS_REGS_ARRAY_SIZE         (uint8)0x0DU

/* Size of Port_GstConfigType array */
#define PORT_NO_OF_CONFIG_SETS              (uint8)0x01U


/* TRACE [R4, PORT006] */
/* TRACE [R4, PORT076] */
/* TRACE [R4, PORT207] */
/* TRACE [R4, PORT208] */
/* Port Pin Handles */
#define Port_PortGroup0_PortPin12    (Port_PinType)0U
#define Port_PortGroup0_PortPin5    (Port_PinType)1U
#define Port_PortGroup0_PortPin13_McuTOD    (Port_PinType)2U
#define Port_PortGroup0_PortPin14    (Port_PinType)3U
#define Port_PortGroup0_PortPin0_PhaFbB    (Port_PinType)4U
#define Port_PortGroup0_PortPin11    (Port_PinType)5U
#define Port_PortGroup0_PortPin1    (Port_PinType)6U
#define Port_PortGroup0_PortPin6    (Port_PinType)7U
#define Port_PortGroup0_PortPin7    (Port_PinType)8U
#define Port_PortGroup0_PortPin2    (Port_PinType)9U
#define Port_PortGroup0_PortPin8_PhaDiscnctC    (Port_PinType)10U
#define Port_PortGroup0_PortPin10    (Port_PinType)11U
#define Port_PortGroup0_PortPin9    (Port_PinType)12U
#define Port_PortGroup0_PortPin4_DebPin0    (Port_PinType)13U
#define Port_PortGroup0_PortPin3_DebPin0    (Port_PinType)14U
#define Port_PortGroup1_PortPin0    (Port_PinType)15U
#define Port_PortGroup1_PortPin3_GateDrv0Mosi    (Port_PinType)16U
#define Port_PortGroup1_PortPin2_GateDrv0Miso    (Port_PinType)17U
#define Port_PortGroup1_PortPin1_GateDrv0Cs    (Port_PinType)18U
#define Port_PortGroup1_PortPin4_GateDrv0Clk    (Port_PinType)19U
#define Port_PortGroup2_PortPin15    (Port_PinType)20U
#define Port_PortGroup2_PortPin14_FrCs    (Port_PinType)21U
#define Port_PortGroup2_PortPin12_DebPin3    (Port_PinType)22U
#define Port_PortGroup2_PortPin10    (Port_PinType)23U
#define Port_PortGroup2_PortPin4_SysFlt2A    (Port_PinType)24U
#define Port_PortGroup2_PortPin13    (Port_PinType)25U
#define Port_PortGroup2_PortPin11_DebPin2    (Port_PinType)26U
#define Port_PortGroup2_PortPin6_MotAg2Miso    (Port_PinType)27U
#define Port_PortGroup2_PortPin5_MotAg2Mosi    (Port_PinType)28U
#define Port_PortGroup2_PortPin9_MotAg0Clk    (Port_PinType)29U
#define Port_PortGroup2_PortPin1    (Port_PinType)30U
#define Port_PortGroup2_PortPin7_MotAg2Clk    (Port_PinType)31U
#define Port_PortGroup2_PortPin2_GateDrv0Diagc    (Port_PinType)32U
#define Port_PortGroup2_PortPin8_MotAg0Mosi    (Port_PinType)33U
#define Port_PortGroup2_PortPin3_FrErr    (Port_PinType)34U
#define Port_PortGroup2_PortPin0    (Port_PinType)35U
#define Port_PortGroup3_PortPin14_MotAg0Miso    (Port_PinType)36U
#define Port_PortGroup3_PortPin8_PhaALowrCmd    (Port_PinType)37U
#define Port_PortGroup3_PortPin6_PwrOutEnaFb    (Port_PinType)38U
#define Port_PortGroup3_PortPin3_MotAg2Cs    (Port_PinType)39U
#define Port_PortGroup3_PortPin1_FrClk    (Port_PinType)40U
#define Port_PortGroup3_PortPin0    (Port_PinType)41U
#define Port_PortGroup3_PortPin7_PhaAUpprCmd    (Port_PinType)42U
#define Port_PortGroup3_PortPin11_PhaFbC    (Port_PinType)43U
#define Port_PortGroup3_PortPin13_PhaCLowrCmd    (Port_PinType)44U
#define Port_PortGroup3_PortPin9_PhaBUpprCmd    (Port_PinType)45U
#define Port_PortGroup3_PortPin2_FrMosi    (Port_PinType)46U
#define Port_PortGroup3_PortPin12_PhaCUpprCmd    (Port_PinType)47U
#define Port_PortGroup3_PortPin4    (Port_PinType)48U
#define Port_PortGroup3_PortPin5_GateDrv0Rst    (Port_PinType)49U
#define Port_PortGroup3_PortPin10_PhaBLowrCmd    (Port_PinType)50U
#define Port_PortGroup4_PortPin1_MotAg3_ENCA_B    (Port_PinType)51U
#define Port_PortGroup4_PortPin12    (Port_PinType)52U
#define Port_PortGroup4_PortPin5_MotAg4_ENCA_B    (Port_PinType)53U
#define Port_PortGroup4_PortPin11    (Port_PinType)54U
#define Port_PortGroup4_PortPin10_FrTxEna    (Port_PinType)55U
#define Port_PortGroup4_PortPin14    (Port_PinType)56U
#define Port_PortGroup4_PortPin13    (Port_PinType)57U
#define Port_PortGroup4_PortPin7    (Port_PinType)58U
#define Port_PortGroup4_PortPin3_MotAg0Cs    (Port_PinType)59U
#define Port_PortGroup4_PortPin0_MotAg3_ENCA_A    (Port_PinType)60U
#define Port_PortGroup4_PortPin9_FrTxData    (Port_PinType)61U
#define Port_PortGroup4_PortPin8_FrTxData    (Port_PinType)62U
#define Port_PortGroup4_PortPin4_MotAg4_ENCA_A    (Port_PinType)63U
#define Port_PortGroup4_PortPin6_MotAg4_ENCA_I    (Port_PinType)64U
#define Port_PortGroup4_PortPin2_MotAg3_ENCA_I    (Port_PinType)65U
#define Port_PortGroup5_PortPin7_McuEna    (Port_PinType)66U
#define Port_PortGroup5_PortPin13_PhaDiscnctA    (Port_PinType)67U
#define Port_PortGroup5_PortPin5    (Port_PinType)68U
#define Port_PortGroup5_PortPin4_PwrSplyClk    (Port_PinType)69U
#define Port_PortGroup5_PortPin15_PhaDiscnctB    (Port_PinType)70U
#define Port_PortGroup5_PortPin6_PwrSplyNonFlt    (Port_PinType)71U
#define Port_PortGroup5_PortPin0_PwrSplyMiso    (Port_PinType)72U
#define Port_PortGroup5_PortPin10_TmplMonrWdg    (Port_PinType)73U
#define Port_PortGroup5_PortPin1_PwrSplyMosi    (Port_PinType)74U
#define Port_PortGroup5_PortPin14_PhaFbA    (Port_PinType)75U
#define Port_PortGroup5_PortPin3    (Port_PinType)76U
#define Port_PortGroup5_PortPin9_PwrSplyCs    (Port_PinType)77U
#define Port_PortGroup5_PortPin2    (Port_PinType)78U
#define Port_PortGroup5_PortPin11    (Port_PinType)79U
#define Port_PortGroup5_PortPin12    (Port_PinType)80U
#define Port_PortGroup5_PortPin8    (Port_PinType)81U
#define Port_PortGroupJtag0_PortPin4_TDI    (Port_PinType)82U
#define Port_PortGroupJtag0_PortPin0_nRDY    (Port_PinType)83U
#define Port_PortGroupJtag0_PortPin5_nTRST    (Port_PinType)84U
#define Port_PortGroupJtag0_PortPin2_TCK    (Port_PinType)85U
#define Port_PortGroupJtag0_PortPin1_TMS    (Port_PinType)86U
#define Port_PortGroupJtag0_PortPin3_TDO    (Port_PinType)87U

/* Configuration Set Handles */
#define PortConfigSet  (&Port_GstConfiguration[0])

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
