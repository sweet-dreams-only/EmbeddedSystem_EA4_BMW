/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
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
 * V1.0.0:  23-Aug-2012  : Initial Version
 * V1.0.1:  05-Mar-2013  : As per SCR 090,
 *                         1. DIO_SW_PATCH_VERSION_VALUE macro is added.
 *                         2. In R4.0.3,CONFIG_HANDLES are updated.
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  02-Jan-2014  : As per CR 331,
 *                         %BswHdrTpl::Precompile_Parameters and
 *                         %BswHdrTpl::Template_Hash are updated.
 * V1.0.4:  17-Mar-2014  : As per CR 413,
 *                         1. DIO_CRITICAL_SECTION_PROTECTION Macro is added.
 *                         2. CONFIG_HANDLES are updated.
 * V1.0.5:  27-Jul-2014  : As per CR 103 and 563, following change is made:
 *                         1. Marker IDs are added newly.
 * V1.0.6:  02-Sep-2014  : As per CR 569, Changes are made at all relevant
 *                         places accordingly to append U or UL unsigned values.
 * V1.0.7:  22-Feb-2016  : As per the ticket ARDAAAE-1052, the following macros
 *                         are added:
 *                         1. DIO_SIZE_OF_CHGRP_STRUCT
 * V1.0.8:  18-Apr-2016  : As part of V4.01.01 Release activity, following
 *                         changes are made.
 *                         1. Dem parameters DIO_E_REG_WRITE_VERIFY
 *                            is added.
 *                         2. Macro DIO_WRITE_VERIFY are added.
 * V1.0.9:  02-Feb-2017  : As part of V4.02.01.D Release activity, following
 *                         changes are made.
 *                         1. Numeric values are appended with 'U'
 *                            for macro definitions.
 *                         2. Copyright year is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.19
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Component\FAAR_WE_Synergy\Dio\generate\R403_DIO_P1x_BSWMDT.arxml
 *                C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Dio_ECUC_4706985623408333761.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:08
 */


#ifndef DIO_CFG_H
#define DIO_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_CFG_AR_RELEASE_MINOR_VERSION  0U
#define DIO_CFG_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define DIO_CFG_SW_MAJOR_VERSION   1U
#define DIO_CFG_SW_MINOR_VERSION   0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define DIO_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define DIO_AR_RELEASE_MINOR_VERSION_VALUE  0U
#define DIO_AR_RELEASE_REVISION_VERSION_VALUE  3U

#define DIO_SW_MAJOR_VERSION_VALUE  1U
#define DIO_SW_MINOR_VERSION_VALUE  0U
#define DIO_SW_PATCH_VERSION_VALUE  12U

#define DIO_VENDOR_ID_VALUE  59U
#define DIO_MODULE_ID_VALUE  120U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the DIO Driver */
#define DIO_INSTANCE_ID_VALUE               0U

/*  Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                STD_ON

/*  Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                STD_OFF

/* Pre-compile option for presence ofDio_MaskedWritePort API */
#define DIO_MASKED_WRITE_PORT_API           STD_OFF

/*  Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                STD_OFF

/* Pre-compile option for presence of Channel */
#define DIO_CHANNEL_CONFIGURED              STD_ON

/* Pre-compile option for presence of Channel Group */
#define DIO_CHANNELGROUP_CONFIGURED         STD_OFF

/* Pre-compile option for enable or disable version check of inter-module
   dependencies */
#define DIO_VERSION_CHECK_EXT_MODULES       STD_OFF

/* Pre-compile option for critical section protection */
#define DIO_CRITICAL_SECTION_PROTECTION     STD_ON

/* Enable/Disable Error Interface */
#define DIO_USE_WV_ERROR_INTERFACE          STD_ON

/* Offset for getting PPR register address from PSR
    register address for Numeric and Alphabetic ports. */
#define DIO_PPR_OFFSET_NONJTAG              (uint8)0x02U

/* Offset for getting PNOT register address
    from PSR register address for Numeric and Alphabetic ports. */
#define DIO_PNOT_OFFSET_NONJTAG             (uint16)0x01U

/* Offset for getting PPR register address from PSR
    register address for JTAG ports  */
#define DIO_PPR_OFFSET_JTAG                 (uint8)0x02U

/* Offset for getting JPNOT register address from JPSR
    register address for JTAG ports. */
#define DIO_PNOT_OFFSET_JTAG                (uint16)0x01U

/* Offset for getting PMSR register address from PMSR
    register address for JTAG ports  */
#define DIO_PMSR_OFFSET_JTAG                (uint16)0x07U

/* Offset for getting PMSR register address from
    PMSR register address for NONJTAG ports. */
#define DIO_PMSR_OFFSET_NONJTAG             (uint16)0x07U


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Total number of configured ports */
#define DIO_MAXNOOFPORT                     (Dio_PortType)5U

/* Total number of configured channels */
#define DIO_MAXNOOFCHANNEL                  (Dio_ChannelType)46U

/* The Array size of the configuredConfig Structure */
#define DIO_CONFIG_ARRAY_SIZE               (Dio_PortType)1U

/* The Array size of the configured PortStructure */
#define DIO_PORT_ARRAY_SIZE                 (uint8)5U

/* The Array size of the configured Channel Structure */
#define DIO_CHANNEL_ARRAY_SIZE              46U

/* The Array size of the configured Channel Group Structure */
#define DIO_CHANNEL_GROUP_ARRAY_SIZE        (Dio_PortType)0U

/* Total number of channel groups configuredper configset */
#define DIO_NO_OF_CHGRP_PER_CFGSET          (Dio_PortType)0U

/* Configuration Set Handles */
#define DioConfig                           (&Dio_GstConfiguration[0])

/* DIO Port Configuration Handles */
#define DioConf_DioPort_Port0               (Dio_PortType)0U
#define DioConf_DioPort_Port2               (Dio_PortType)1U
#define DioConf_DioPort_Port3               (Dio_PortType)2U
#define DioConf_DioPort_Port4               (Dio_PortType)3U
#define DioConf_DioPort_Port5               (Dio_PortType)4U

/* The Pointer to Port Group name */

/* DIO Channel Configuration Handles */
#define DioConf_DioChannel_PhaFbB           (Dio_ChannelType)0U
#define DioConf_DioChannel_DebPin0          (Dio_ChannelType)1U
#define DioConf_DioChannel_DebPin1          (Dio_ChannelType)2U
#define DioConf_DioChannel_PwrTurnOffCtrl   (Dio_ChannelType)3U
#define DioConf_DioChannel_PhaDiscnctC      (Dio_ChannelType)4U
#define DioConf_DioChannel_GateDrv0Diagc    (Dio_ChannelType)5U
#define DioConf_DioChannel_SysFlt2A         (Dio_ChannelType)6U
#define DioConf_DioChannel_MotAg2Mosi       (Dio_ChannelType)7U
#define DioConf_DioChannel_MotAg2Miso       (Dio_ChannelType)8U
#define DioConf_DioChannel_MotAg2Clk        (Dio_ChannelType)9U
#define DioConf_DioChannel_MotAg0Mosi       (Dio_ChannelType)10U
#define DioConf_DioChannel_MotAg0Clk        (Dio_ChannelType)11U
#define DioConf_DioChannel_FrCs             (Dio_ChannelType)12U
#define DioConf_DioChannel_DebPin2          (Dio_ChannelType)13U
#define DioConf_DioChannel_DebPin3          (Dio_ChannelType)14U
#define DioConf_DioChannel_FrErr            (Dio_ChannelType)15U
#define DioConf_DioChannel_MotAg0Miso       (Dio_ChannelType)16U
#define DioConf_DioChannel_PhaCUpprCmd      (Dio_ChannelType)17U
#define DioConf_DioChannel_PhaCLowrCmd      (Dio_ChannelType)18U
#define DioConf_DioChannel_PhaBLowrCmd      (Dio_ChannelType)19U
#define DioConf_DioChannel_PhaBUpprCmd      (Dio_ChannelType)20U
#define DioConf_DioChannel_PhaALowrCmd      (Dio_ChannelType)21U
#define DioConf_DioChannel_PhaAUpprCmd      (Dio_ChannelType)22U
#define DioConf_DioChannel_PwrOutpEnaFb     (Dio_ChannelType)23U
#define DioConf_DioChannel_GateDrv0Rst      (Dio_ChannelType)24U
#define DioConf_DioChannel_MotAg2Cs         (Dio_ChannelType)25U
#define DioConf_DioChannel_FrMosi           (Dio_ChannelType)26U
#define DioConf_DioChannel_FrClk            (Dio_ChannelType)27U
#define DioConf_DioChannel_PhaFbC           (Dio_ChannelType)28U
#define DioConf_DioChannel_MotAg0Cs         (Dio_ChannelType)29U
#define DioConf_DioChannel_FrTxData         (Dio_ChannelType)30U
#define DioConf_DioChannel_FrRxData         (Dio_ChannelType)31U
#define DioConf_DioChannel_FrTxEna          (Dio_ChannelType)32U
#define DioConf_DioChannel_FrStb            (Dio_ChannelType)33U
#define DioConf_DioChannel_MotAg3_ENCA_I    (Dio_ChannelType)34U
#define DioConf_DioChannel_MotAg4_ENCA_I    (Dio_ChannelType)35U
#define DioConf_DioChannel_PwrSplyMiso      (Dio_ChannelType)36U
#define DioConf_DioChannel_PwrSplyMosi      (Dio_ChannelType)37U
#define DioConf_DioChannel_PwrSplyClk       (Dio_ChannelType)38U
#define DioConf_DioChannel_PwrSplyNotFlt    (Dio_ChannelType)39U
#define DioConf_DioChannel_McuEna           (Dio_ChannelType)40U
#define DioConf_DioChannel_PwrSplyCs        (Dio_ChannelType)41U
#define DioConf_DioChannel_TmplMonrWdg      (Dio_ChannelType)42U
#define DioConf_DioChannel_PhaDiscnctA      (Dio_ChannelType)43U
#define DioConf_DioChannel_PhaDiscnctB      (Dio_ChannelType)44U
#define DioConf_DioChannel_PhaFbA           (Dio_ChannelType)45U

/* Channel Mapping for DioChannelBitPosition */
#define DioConfig_PhaFbB_bit                (uint8)0x00U
#define DioConfig_DebPin0_bit               (uint8)0x03U
#define DioConfig_DebPin1_bit               (uint8)0x04U
#define DioConfig_PwrTurnOffCtrl_bit        (uint8)0x0DU
#define DioConfig_PhaDiscnctC_bit           (uint8)0x08U
#define DioConfig_GateDrv0Diagc_bit         (uint8)0x02U
#define DioConfig_SysFlt2A_bit              (uint8)0x04U
#define DioConfig_MotAg2Mosi_bit            (uint8)0x05U
#define DioConfig_MotAg2Miso_bit            (uint8)0x06U
#define DioConfig_MotAg2Clk_bit             (uint8)0x07U
#define DioConfig_MotAg0Mosi_bit            (uint8)0x08U
#define DioConfig_MotAg0Clk_bit             (uint8)0x09U
#define DioConfig_FrCs_bit                  (uint8)0x0EU
#define DioConfig_DebPin2_bit               (uint8)0x0BU
#define DioConfig_DebPin3_bit               (uint8)0x0CU
#define DioConfig_FrErr_bit                 (uint8)0x03U
#define DioConfig_MotAg0Miso_bit            (uint8)0x0EU
#define DioConfig_PhaCUpprCmd_bit           (uint8)0x0CU
#define DioConfig_PhaCLowrCmd_bit           (uint8)0x0DU
#define DioConfig_PhaBLowrCmd_bit           (uint8)0x0AU
#define DioConfig_PhaBUpprCmd_bit           (uint8)0x09U
#define DioConfig_PhaALowrCmd_bit           (uint8)0x08U
#define DioConfig_PhaAUpprCmd_bit           (uint8)0x07U
#define DioConfig_PwrOutpEnaFb_bit          (uint8)0x06U
#define DioConfig_GateDrv0Rst_bit           (uint8)0x05U
#define DioConfig_MotAg2Cs_bit              (uint8)0x03U
#define DioConfig_FrMosi_bit                (uint8)0x02U
#define DioConfig_FrClk_bit                 (uint8)0x01U
#define DioConfig_PhaFbC_bit                (uint8)0x0BU
#define DioConfig_MotAg0Cs_bit              (uint8)0x03U
#define DioConfig_FrTxData_bit              (uint8)0x09U
#define DioConfig_FrRxData_bit              (uint8)0x08U
#define DioConfig_FrTxEna_bit               (uint8)0x0AU
#define DioConfig_FrStb_bit                 (uint8)0x05U
#define DioConfig_MotAg3_ENCA_I_bit         (uint8)0x02U
#define DioConfig_MotAg4_ENCA_I_bit         (uint8)0x06U
#define DioConfig_PwrSplyMiso_bit           (uint8)0x00U
#define DioConfig_PwrSplyMosi_bit           (uint8)0x01U
#define DioConfig_PwrSplyClk_bit            (uint8)0x04U
#define DioConfig_PwrSplyNotFlt_bit         (uint8)0x06U
#define DioConfig_McuEna_bit                (uint8)0x07U
#define DioConfig_PwrSplyCs_bit             (uint8)0x09U
#define DioConfig_TmplMonrWdg_bit           (uint8)0x0AU
#define DioConfig_PhaDiscnctA_bit           (uint8)0x0DU
#define DioConfig_PhaDiscnctB_bit           (uint8)0x0FU
#define DioConfig_PhaFbA_bit                (uint8)0x0EU

/* The Pointer to Port Channel name */

/* DIO Channel Group Configuration Handles */

/* DIO Write Verify User Interface Notification */
/* Enable/Disable the register write check 
 WV_DISABLE - 0 , WV_INIT_RUNTIME - 2 */
#define DIO_WRITE_VERIFY                    2U

/* User configured error notification */
#define DIO_ERROR_NOTIFICATION              HndlMcalWrVrfyErr


/* DIO Dem interfaces */
/*The register write verify failure is reported using the
 following error code*/
#define DIO_E_REG_WRITE_VERIFY              \
  DemConf_DemEventParameter_DIO_E_REG_WRITE_VERIFY




/* Size of the Dio Channel Group Structure */
#define DIO_SIZE_OF_CHGRP_STRUCT 4U
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* DIO_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
