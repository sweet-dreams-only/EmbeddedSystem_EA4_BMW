/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: NvM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.c
 *   Generation Time: 2018-07-30 19:49:07
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


    
/**********************************************************************************************************************
 *  MODULE SWITCH
 *********************************************************************************************************************/
/* this switch enables the header file(s) to hide some parts. */
#define NVM_CFG_SOURCE

/* multiple inclusion protection */
#define NVM_H_

/* PRQA S 5087 inclusions *//* MD_MSR_19.1 */

/* Define RTE_MICROSAR_PIM_EXPORT is necessary only when serviceports are used */
#define RTE_MICROSAR_PIM_EXPORT  


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* This tag will only be replaced, if one or more callbacks via Service Ports had been configured */
#include "Rte_NvM.h"

/**********************************************************************************************************************
 *  MODULE HEADER INCLUDES
 *********************************************************************************************************************/
/* only includes the public part of config */
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

#include "BswM_NvM.h"

/**********************************************************************************************************************
 *  VERSION CHECKS
 *********************************************************************************************************************/
#if ((NVM_CFG_MAJOR_VERSION != (5u)) \
        || (NVM_CFG_MINOR_VERSION != (7u)))
# error "Version numbers of NvM_Cfg.c and NvM_Cfg.h are inconsistent!"
#endif

#if ((NVM_PRIV_CFG_MAJOR_VERSION != NVM_CFG_MAJOR_VERSION) \
        || (NVM_PRIV_CFG_MINOR_VERSION != NVM_CFG_MINOR_VERSION))
# error "Version numbers of NvM_Cfg.c and Nvm_PrivateCfg.h.h are inconsistent!"
#endif

#if ((NVM_TYPES_MAJOR_VERSION != NVM_CFG_MAJOR_VERSION) \
        || (NVM_TYPES_MINOR_VERSION != NVM_CFG_MINOR_VERSION))
# error "Version numbers of NvM_Cfg.c and NvM_Types.h are inconsistent!"
#endif

/* include list of the callback definitions */
#include "Dem_Cbk.h" 
#include "CDD_NvMProxyDftDataGroup.h" 
#include "Vin_NvM.h" 
#include "Omc_NvM.h" 
#include "Darh_NvM.h" 
#include "Dlog_NvM.h" 
#include "Coding_Data.h" 


/* include configured file declaring or defining resource (un)locking service(s) */
#include "SchM_NvM.h"

#define NVM_SIZE_STANDARD_JOB_QUEUE  (8U) 
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE (0U) 


/**********************************************************************************************************************
 *  PUBLIC CONSTANTS
 *********************************************************************************************************************/

#define NVM_START_SEC_CONST_8
#include "MemMap.h"

/* Number of write attempts: 1 + number of retries */
CONST(uint8, NVM_PRIVATE_CONST) NvM_NoOfWrAttempts_u8 = 3U;

#define NVM_STOP_SEC_CONST_8
#include "MemMap.h"

#define NVM_START_SEC_CONST_16
#include "MemMap.h"

/* maximum number of bytes to be processed in one crc calculation step */
CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16 = 64U;

/* constant holding Crc quueue size value */
CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16 = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

#define NVM_STOP_SEC_CONST_16
#include "MemMap.h"

/* close section, to ensure unique section ends */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* constants holding the compiled queue size values */
CONST(NvM_QueueSizesType, NVM_PRIVATE_CONST) NvM_QueueSizes_t =
{
    /* MISRA wants to define a operator precedence with parentheses */
    (NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE) - 1u,
    NVM_SIZE_STANDARD_JOB_QUEUE
};

/* close section, to ensure unique section ends */
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* 8Bit Data section containing the CRC buffers, as well as the internal buffer */
#define NVM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

static VAR(uint8, NVM_PRIVATE_DATA) NvMConfigBlock_RamBlock_au8[4U];

#if ((NVM_CRC_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_PullCmpActv_PullCmpLongTerm_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_Coding_CodingData_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_TEstimn_TFilStVal_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_ExcpnHndlg_McuDiagcData_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_LrndRackCentr_LrndRackCentr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_SysFricLrng_FricNonLrngData_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_SysFricLrng_FricLrngData_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_Darh_ErrorQueue_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_MotTqCmdSca_MotTqScaFac_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_DutyCycThermProtn_FilStVal_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_PolarityCfg_PolarityCfgSaved_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_SeedKey_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_IgnCntr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_DiRestore_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_CcaSerlNr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry_Crc_au8[2UL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk_Crc_au8[2UL]; 


/* create the internal buffer of size NVM_INTERNAL_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[NVM_INTERNAL_BUFFER_LENGTH];
#endif

/* create a test buffer of size 1 byte for testing readability of a block */
VAR(uint8, NVM_PRIVATE_DATA) NvM_TestBuffer_u8;

#define NVM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

/* PRQA S 0759 1 */ /* MD_MSR_18.4 */
CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t = {(uint16)NVM_COMPILED_CONFIG_ID};
 
/* block descriptor table that holds the static configuration parameters of the RAM, ROM and NVBlocks.
* This table has to be adjusted according to the configuration of the NVManager.
*/
     
/* PRQA S 0310 RamRomBlocks *//* MD_NvM_11.4 */
CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS] =
    {
      { /*  MultiBlockRequest  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0001U /*  NV block Base number (defined by FEE/EA)  */ , 
        0 /*  Length of the block in bytes  */ , 
        0U /*  Number of multiple blocks  */ , 
        255U /*  Block Priority  */ , 
        0u /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        0u /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NvMConfigBlock  */ 
        (NvM_RamAddressType)NvMConfigBlock_RamBlock_au8 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0002U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemAdminDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_AdminData /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        Dem_NvM_InitAdminData /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0004U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_PullCmpActv_PullCmpLongTerm  */ 
        (NvM_RamAddressType)&Rte_PullCmpActv_PullCmpLongTerm /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_PullCmpActv_DEFAULT_RTE_CDATA_GROUP.PullCmpLongTermDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_PullCmpActv_PullCmpLongTerm_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00D6U /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_PullCmpActv_PullCmpLongTerm) /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp  */ 
        (NvM_RamAddressType)&Rte_BmwDiagcSrvHndlg_TestStamp /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00D4U /*  NV block Base number (defined by FEE/EA)  */ , 
        3U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal  */ 
        (NvM_RamAddressType)&Rte_BmwDiagcSrvHndlg_ProgCntrMaxVal /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP.ProgCntrMaxValDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00D2U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr  */ 
        (NvM_RamAddressType)&Rte_BmwDiagcSrvHndlg_ProgCntr /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00D0U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom  */ 
        (NvM_RamAddressType)&Rte_BmwDiagcSrvHndlg_MilesKmEeprom /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00CEU /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx  */ 
        (NvM_RamAddressType)&Rte_BmwTunSetHndlr_BmwDesIninOptSetAIdx /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP.BmwDesIninOptSetAIdxDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00CCU /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx  */ 
        (NvM_RamAddressType)&Rte_BmwTunSetHndlr_BmwDesIninIdx /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP.BmwDesIninIdxDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00CAU /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_Coding_CodingData  */ 
        (NvM_RamAddressType)&Coding_CodingData /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Coding_CodingDataDefault /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_Coding_CodingData_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_Coding_CodingData_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00C8U /*  NV block Base number (defined by FEE/EA)  */ , 
        160U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_ON /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_Darh_DiagnoseMasterEnable  */ 
        (NvM_RamAddressType)&Darh_DiagnoseMasterEnable /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_Darh_DiagnoseMasterEnable_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00C6U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_DLOG_SVK_ENTRY  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NVM_BLOCK_DLOG_SVK_ENTRY_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00C4U /*  NV block Base number (defined by FEE/EA)  */ , 
        56U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_DATASET /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_TEstimn_TFilStVal  */ 
        (NvM_RamAddressType)&Rte_TEstimn_TFilStVal /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_TEstimn_TFilStVal_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00C2U /*  NV block Base number (defined by FEE/EA)  */ , 
        32U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_ExcpnHndlg_McuDiagcData  */ 
        (NvM_RamAddressType)&Rte_CDD_ExcpnHndlg_McuDiagcData /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP.McuDiagcDataDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_ExcpnHndlg_McuDiagcData_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00C0U /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_LrndRackCentr_LrndRackCentr  */ 
        (NvM_RamAddressType)&Rte_LrndRackCentr_LrndRackCentr /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_LrndRackCentr_LrndRackCentr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00BEU /*  NV block Base number (defined by FEE/EA)  */ , 
        12U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs  */ 
        (NvM_RamAddressType)&Rte_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00BCU /*  NV block Base number (defined by FEE/EA)  */ , 
        20U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo  */ 
        (NvM_RamAddressType)&Rte_CDD_VrfyCritReg_MCalReadVrfyCritRegFltNvmInfo /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00BAU /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_SysFricLrng_FricNonLrngData  */ 
        (NvM_RamAddressType)&Rte_SysFricLrng_FricNonLrngData /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_SysFricLrng_DEFAULT_RTE_CDATA_GROUP.FricNonLrngDataDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_SysFricLrng_FricNonLrngData_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00B6U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_SysFricLrng_FricLrngData  */ 
        (NvM_RamAddressType)&Rte_SysFricLrng_FricLrngData /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_SysFricLrng_DEFAULT_RTE_CDATA_GROUP.FricLrngDataDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_SysFricLrng_FricLrngData_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00B8U /*  NV block Base number (defined by FEE/EA)  */ , 
        216U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_Darh_ErrorQueue  */ 
        (NvM_RamAddressType)&Darh_ErrorQueue /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_Darh_ErrorQueue_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00B4U /*  NV block Base number (defined by FEE/EA)  */ , 
        28U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_DLOG_SVK_PLANT  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00B2U /*  NV block Base number (defined by FEE/EA)  */ , 
        57U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        0U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_ON |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_DLOG_SVK_SYS_SUPP  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00B0U /*  NV block Base number (defined by FEE/EA)  */ , 
        57U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        0U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_ON |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_BOOT_SVK_HISTORY  */ 
        (NvM_RamAddressType)&Dlog_SvkHistory /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        Rte_Call_NvM_RpNotifyInit_NVM_BLOCK_BOOT_SVK_HISTORY_InitBlock /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NVM_BLOCK_BOOT_SVK_HISTORY_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00AEU /*  NV block Base number (defined by FEE/EA)  */ , 
        12U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        0U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_ON |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_BOOT_PROG_DATA  */ 
        (NvM_RamAddressType)&Dlog_ProgData /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        Rte_Call_NvM_RpNotifyInit_NVM_BLOCK_BOOT_PROG_DATA_InitBlock /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NVM_BLOCK_BOOT_PROG_DATA_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00ACU /*  NV block Base number (defined by FEE/EA)  */ , 
        48U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        0U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_ON |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_BOOT_PROG_COUNTER  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        Rte_Call_NvM_RpNotifyInit_NVM_BLOCK_BOOT_PROG_COUNTER_InitBlock /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NVM_BLOCK_BOOT_PROG_COUNTER_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00AAU /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        0U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_ON |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_Omc  */ 
        (NvM_RamAddressType)&Omc_NvData /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Omc_DefaultNvData /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_Omc_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00A8U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_Vin  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Vin_NVStateDefault /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_Vin_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x00A6U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom  */ 
        (NvM_RamAddressType)&Rte_MotCtrlPrmEstimn_MotPrmNom /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00A4U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_MotTqCmdSca_MotTqScaFac  */ 
        (NvM_RamAddressType)&Rte_MotTqCmdSca_MotTqScaFac /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_MotTqCmdSca_MotTqScaFac_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00A2U /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_DutyCycThermProtn_FilStVal  */ 
        (NvM_RamAddressType)&Rte_DutyCycThermProtn_FilStVal /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_DutyCycThermProtn_FilStVal_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x00A0U /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt  */ 
        (NvM_RamAddressType)&Rte_HwTqCorrln_HwTqChACmnModCmpLpFilSt /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_HwTqCorrln_DEFAULT_RTE_CDATA_GROUP.HwTqChACmnModCmpLpFilStDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x009EU /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock  */ 
        (NvM_RamAddressType)&Rte_CDD_HwTq5Meas_HwTq5Sca /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x009CU /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock  */ 
        (NvM_RamAddressType)&Rte_CDD_HwTq4Meas_HwTq4Sca /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x009AU /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock  */ 
        (NvM_RamAddressType)&Rte_CDD_HwTq5Meas_HwTq5Offs /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0098U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock  */ 
        (NvM_RamAddressType)&Rte_CDD_HwTq4Meas_HwTq4Offs /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0096U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf  */ 
        (NvM_RamAddressType)&Rte_CDD_MotAgCmp_MotAgCmpMotAgBackEmf /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CDD_MotAgCmp_DEFAULT_RTE_CDATA_GROUP.MotAgCmpMotAgBackEmfDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0094U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_PolarityCfg_PolarityCfgSaved  */ 
        (NvM_RamAddressType)&Rte_PolarityCfg_PolarityCfgSaved /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_PolarityCfg_DEFAULT_RTE_CDATA_GROUP.PolarityCfgSavedDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_PolarityCfg_PolarityCfgSaved_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0092U /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_SeedKey  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_SeedKey /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP.SeedKeyDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_SeedKey_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0090U /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_MfgTmpBuf4 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x008EU /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_MfgTmpBuf3 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x008CU /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_MfgTmpBuf2 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x008AU /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_MfgTmpBuf1 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0088U /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_MfgTmpBuf0 /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0086U /*  NV block Base number (defined by FEE/EA)  */ , 
        16U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_NxtrMfgEnaCntr /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP.NvmMfgEnaCntr_DefaultValue /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0084U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_IgnCntr  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_IgnCntr /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP.NvmIgnCntr_DefaultValue /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_IgnCntr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0082U /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_EpsSysSerlNr /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0080U /*  NV block Base number (defined by FEE/EA)  */ , 
        20U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_DiRestore  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_DiRestore /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_DiRestore_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x007EU /*  NV block Base number (defined by FEE/EA)  */ , 
        8U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_CcaSerlNr  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_CcaSerlNr /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_CcaSerlNr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x007CU /*  NV block Base number (defined by FEE/EA)  */ , 
        20U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr  */ 
        (NvM_RamAddressType)&Rte_CmnMfgSrv_CcaHwPartNr /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x007AU /*  NV block Base number (defined by FEE/EA)  */ , 
        20U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  NVM_BLOCK_DCM_ROE  */ 
        NULL_PTR /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0078U /*  NV block Base number (defined by FEE/EA)  */ , 
        2U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_OFF |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC  */ 
        (NvM_RamAddressType)&Rte_CDD_CurrMeas_CurrMeasEolOffsCalSetABC /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CDD_CurrMeas_DEFAULT_RTE_CDATA_GROUP.CurrMeasEolOffsCalSetABCDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0076U /*  NV block Base number (defined by FEE/EA)  */ , 
        28U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC  */ 
        (NvM_RamAddressType)&Rte_CDD_CurrMeas_CurrMeasEolGainCalSetABC /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_CDD_CurrMeas_DEFAULT_RTE_CDATA_GROUP.CurrMeasEolGainCalSetABCDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0074U /*  NV block Base number (defined by FEE/EA)  */ , 
        12U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl  */ 
        (NvM_RamAddressType)&Rte_CDD_MotAg1Meas_MotAg1CoeffTbl /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0072U /*  NV block Base number (defined by FEE/EA)  */ , 
        104U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl  */ 
        (NvM_RamAddressType)&Rte_CDD_MotAg0Meas_MotAg0CoeffTbl /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0070U /*  NV block Base number (defined by FEE/EA)  */ , 
        104U /*  Length of the block in bytes  */ , 
        2U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc  */ 
        (NvM_RamAddressType)&Rte_DiagcMgr_DiagcMgrApplCrc /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Rte_CalprmRom_DiagcMgr_DEFAULT_RTE_CDATA_GROUP.DiagcMgrApplCrcDft /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x006EU /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry  */ 
        (NvM_RamAddressType)&Rte_DiagcMgr_DiagcMgrNtcFltAry /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x006AU /*  NV block Base number (defined by FEE/EA)  */ , 
        80U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry  */ 
        (NvM_RamAddressType)&Rte_DiagcMgr_DiagcMgrLtchCntrAry /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x006CU /*  NV block Base number (defined by FEE/EA)  */ , 
        20U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk  */ 
        (NvM_RamAddressType)&Rte_CDD_NvMProxy_ShtdwnClsChk /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        NULL_PTR /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk_Crc_au8 /*  pointer to the CRC data buffer  */ , 
        0x0068U /*  NV block Base number (defined by FEE/EA)  */ , 
        4U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_CRC_16_ON /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_OFF |
NVM_CBK_DURING_READALL_OFF |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemStatusDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_StatusData /*  pointer to the RAM data buffer  */ , 
        NULL_PTR /*  pointer to the ROM buffer  */ , 
        Dem_NvM_InitStatusData /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0006U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock0  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_0 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0008U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock1  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_1 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x000AU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock2  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_2 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x000CU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock3  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_3 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x000EU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock4  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_4 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0010U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock5  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_5 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0012U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock6  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_6 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0014U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemPrimaryDataBlock7  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_7 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0016U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock0  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_0 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0018U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock1  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_1 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x001AU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock2  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_2 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x001CU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock3  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_3 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x001EU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock4  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_4 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0066U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock5  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_5 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0020U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock6  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_6 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0022U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock7  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_7 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0024U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock8  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_8 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0026U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock9  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_9 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0028U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock10  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_10 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x002AU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock11  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_11 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x002CU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock12  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_12 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x002EU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock13  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_13 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0030U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock14  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_14 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0032U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock15  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_15 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0034U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock16  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_16 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0036U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock17  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_17 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0038U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock18  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_18 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x003AU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock19  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_19 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x003CU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock20  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_20 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x003EU /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock21  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_21 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0040U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock22  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_22 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0042U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }, 
      { /*  DemSecondaryDataBlock23  */ 
        (NvM_RamAddressType)&Dem_Cfg_SecondaryEntry_23 /*  pointer to the RAM data buffer  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  pointer to the ROM buffer  */ , 
        NULL_PTR /*  pointer to the Init Callback function  */ , 
        Dem_NvM_JobFinished /*  pointer to the job End Callback function  */ , 
        NULL_PTR /*  pointer to the ReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  pointer to the WriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  pointer to the CRC data buffer  */ , 
        0x0044U /*  NV block Base number (defined by FEE/EA)  */ , 
        1U /*  Length of the block in bytes  */ , 
        1U /*  Number of multiple blocks  */ , 
        127U /*  Block Priority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  Management Type  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  CRC Type  */ , 
        (
NVM_CALC_RAM_BLOCK_CRC_OFF |
NVM_BLOCK_WRITE_PROT_OFF |
NVM_BLOCK_WRITE_BLOCK_ONCE_OFF |
NVM_RESISTANT_TO_CHANGED_SW_ON |
NVM_SELECT_BLOCK_FOR_READALL_ON |
NVM_SELECT_BLOCK_FOR_WRITEALL_ON |
NVM_CBK_DURING_READALL_ON |
NVM_CRC_COMP_MECHANISM_OFF
) /*  Flags  */ , 
        STD_OFF /*  BswM Block Status Information enabled  */ 
      }
    };

/* PRQA L:RamRomBlocks */

/* Permanent RAM and ROM block length checks - compile time (only available for blocks with enabled length check */

/* How does it work:
 * data length = sizeof(ramBlock - CrcLength 
 *     - CRC internal buffer enabled: CRC length == 0, RAM blocks store only data, CRC is handles internally
 *     - CRC internal buffer disabled: CRC length is the number of CRC bytes, for blocks without CRC the length == 0
 *     - for ROM blocks the CRC does not matter
 * Data length has to be > or < or == to configured NvM block length, depending on configuration (see above). 
 * In case the lengths do not match a bitfield with length -1 will be created and shall cause a compiler error.
 * The compiler error shall mark the line with invalid bitfield (bitfield length == -1) - the line includes all required information:
 *     - Block_ + NvM block name
 *     - length error description
 *     - RAM block name, CRC length and configured NvM block length
 */

typedef unsigned int NvM_LengthCheck;
 
/* Block Length Check and Automatic Block Length enabled: error if sizeof RAM block is greater than the configured block length */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRamBlockGreaterThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) > (blockLength)) ? -1 : 1)
/* Block Length Check and Strict Length Check enabled: error if the sizeof RAM block does not match the configured block length */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRamBlockDoesNotMatchConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) != (blockLength)) ? -1 : 1)
/* Block Length Check enabled and Strict Length Check disabled: error if the sizeof RAM block is less than the configured block length */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRamBlockLessThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) < (blockLength)) ? -1 : 1)

/* RAM block length checks */
struct PermanentRamBlockLengthChecks {
  NvM_LengthCheck Block_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm : SizeOfRamBlockGreaterThanConfiguredLength(Rte_PullCmpActv_PullCmpLongTerm, 0, 4U);
  NvM_LengthCheck Block_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo : SizeOfRamBlockDoesNotMatchConfiguredLength(Rte_CDD_VrfyCritReg_MCalReadVrfyCritRegFltNvmInfo, 0, 4U);
};

/* Block Length Check and Automatic Block Length enabled: error if sizeof ROM block is less than sizeof RAM block */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRomBlockLessThanSizeOfRamBlock(romBlock, ramBlock) ((sizeof(romBlock) < sizeof(ramBlock)) ? -1 : 1)
/* Block Length Check and Strict Length Check enabled: error if the sizeof ROM block does not match the configured block length */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRomBlockDoesNotMatchConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) != (blockLength)) ? -1 : 1)
/* Block Length Check enabled, Strict Length disabled: error if the sizeof ROM block is less than the configured block length */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define SizeOfRomBlockLessThanConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) < (blockLength)) ? -1 : 1)

/* ROM block length checks */
struct PermRomBlockLengthCheck {
  NvM_LengthCheck Block_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalprmRom_PullCmpActv_DEFAULT_RTE_CDATA_GROUP.PullCmpLongTermDft, Rte_PullCmpActv_PullCmpLongTerm);
};

/* Permanent RAM and ROM block length checks - END */

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* Job Queue used for normal and high prio jobs */
VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

/* array of RAM Block Management areas, defined to be usable in block descriptor table */
VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_BlockMngmtArea_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS];

/* management area for DCM blocks */
VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_DcmBlockMngmt_t;

#define NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
*  NvM_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 enter SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void)
{
    /* do what ever was defined to do for locking the resources */
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/**********************************************************************************************************************
*  NvM_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 exit SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void)
{
    /* do what ever was defined to do for unlocking the resources */
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/* PRQA S 3453 2 */ /* MD_MSR_19.7 */ 
#define NvM_invokeMultiBlockMode(serv, res) BswM_NvM_CurrentJobMode((serv),(res)) /*  if NvMBswMMultiBlockJobStatusInformation is TRUE  */ 
#define NvM_invokeMultiCbk(serv, res)  BswM_NvM_CurrentJobMode((serv), (res)) /*  if Multi Block Callback is configured  */ 

/**********************************************************************************************************************
*  NvM_MultiBlockCbk
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 invoke the BSWM notification if any is configured
 *  - #20 in case the given job result isn't set to pending, invoke the multi block job end notification
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockCbk(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    /* The complete function body is designed to be optimized away by the compiler, if it is not needed    *
     * If the used macro is empty, the compiler may decide to remove code because it would contain         *
     * emtpy execution blocks (it does not matter whether conditions were TRUE or FALSE                    */
    NvM_invokeMultiBlockMode(ServiceId, JobResult);

    if(JobResult != NVM_REQ_PENDING)
    {
        NvM_invokeMultiCbk(ServiceId, JobResult);
    }   
}

 /* PRQA S 3453 2 */ /* MD_MSR_19.7 */ 
#define NvM_invokeCbk(descr, serv, res) (descr)->CallbackFunc_pt((serv), (res)) /*  if any Block has a Single Block Job End Notifications  */ 
#define NvM_invokeCurrentBlockMode(id, res) BswM_NvM_CurrentBlockMode((id),(res)) /*  if any block has NotifyBswM == TRUE  */ 

/**********************************************************************************************************************
*  NvM_BlockNotification
**********************************************************************************************************************/
/*!
 * \internal
 *  - #100 only for normal blocks (no DCM blocks)
 *      - #110 only when
 *        single block callback configured and
 *        the job is done (result != NVM_REQ_PENDING) and
 *        current job is not WriteAll (do not invoke any callbacks during WriteAll) and
 *        for ReadAll as current job the callback invoking is enabled
 *      - #111 invoke the single block callback
 *  - #120 block has enabled BswM callback
 *      - #121 invoke BswM callback
 * \endinternal
 */
void NvM_BlockNotification(NvM_BlockIdType BlockId, NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    /* The complete function body is designed to be optimized away by the compiler, if it is not needed    *
     * If the used macros are empty, the compiler may decide to remove code because it would contain       *
     * empty execution blocks (it does not matter whether conditions were TRUE or FALSE                    */
    const NvM_BlockIdType orgBlockId = NVM_BLOCK_FROM_DCM_ID(BlockId);
    const NvM_BlockDescrPtrType blockDescriptorPtr = &NvM_BlockDescriptorTable_at[orgBlockId];
    /* #100 only for normal blocks (no DCM blocks) */
    if (orgBlockId == BlockId)
    {
        /* #110 only when
         * single block callback configured and
         * the job is done (result != NVM_REQ_PENDING) and
         * current job is not WriteAll (do not invoke any callbacks during WriteAll) and
         * for ReadAll as current job the callback invoking is enabled */
        if((blockDescriptorPtr->CallbackFunc_pt != NULL_PTR) && (JobResult != NVM_REQ_PENDING) &&
            (ServiceId != NVM_WRITE_ALL) &&
            (!((ServiceId == NVM_READ_ALL) && ((blockDescriptorPtr->Flags_u8 & NVM_CBK_DURING_READALL_ON) != NVM_CBK_DURING_READALL_ON))))
        {
            /* #111 invoke the single block callback */
            NvM_invokeCbk(blockDescriptorPtr, ServiceId, JobResult); /* SBSW_NvM_FuncPtrCall_UserCallbacks */
        }
        /* #120 block has enabled BswM callback */
        /* PRQA S 3760 1 */ /* MD_NvM_10.1 */
        if(blockDescriptorPtr->NotifyBswM == TRUE)
        {
            /* #121 invoke BswM callback */
            NvM_invokeCurrentBlockMode(BlockId, JobResult);
        }
    }      
}

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA L:inclusions */

/* ---- End of File ------------------------------------------------------- */

