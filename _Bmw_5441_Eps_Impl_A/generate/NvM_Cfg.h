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
 *              File: NvM_Cfg.h
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
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (5u)
#define NVM_CFG_MINOR_VERSION    (7u)
#define NVM_CFG_PATCH_VERSION    (0u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "Rte_NvM_Type.h"

#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID
 * (see CompiledConfigurationId in NvM.h)
 */
/* Compiled Config Id Type */
/* PRQA S 0750 2 */ /* MD_MSR_18.4 */
typedef union
{
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_ON)

#define NVM_API_CONFIG_CLASS_1                (1u)
#define NVM_API_CONFIG_CLASS_2                (3u)
#define NVM_API_CONFIG_CLASS_3                (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1U)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for Crc handling */
#define NVM_CRC_INT_BUFFER                    (STD_ON)

/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS         (92UL)

/* internal buffer size */
#define NVM_INTERNAL_BUFFER_LENGTH            218UL

/* version info api switch */
#define NVM_VERSION_INFO_API                  (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API          (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS            (1U)

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET                  0x8000u

/* returns corresponding DCM BlockId of an original NVRAM Block */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define NvM_GetDcmBlockId(MyApplBlockId)      ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET)

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptorTable_at
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf___MultiBlockRequest (0U) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1UL) 
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock (2UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm (3UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp (4UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal (5UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr (6UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom (7UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx (8UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx (9UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Coding_CodingData (10UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Darh_DiagnoseMasterEnable (11UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_DLOG_SVK_ENTRY (12UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_TEstimn_TFilStVal (13UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_ExcpnHndlg_McuDiagcData (14UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_LrndRackCentr_LrndRackCentr (15UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs (16UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo (17UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_SysFricLrng_FricNonLrngData (18UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_SysFricLrng_FricLrngData (19UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Darh_ErrorQueue (20UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_DLOG_SVK_PLANT (21UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_DLOG_SVK_SYS_SUPP (22UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_BOOT_SVK_HISTORY (23UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_BOOT_PROG_DATA (24UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_BOOT_PROG_COUNTER (25UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Omc (26UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_Vin (27UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom (28UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac (29UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DutyCycThermProtn_FilStVal (30UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt (31UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock (32UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock (33UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock (34UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock (35UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf (36UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved (37UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_SeedKey (38UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4 (39UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3 (40UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2 (41UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1 (42UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0 (43UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr (44UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_IgnCntr (45UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr (46UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_DiRestore (47UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr (48UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr (49UL) 
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_DCM_ROE (50UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC (51UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC (52UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl (53UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl (54UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc (55UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry (56UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry (57UL) 
#define NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk (58UL) 
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock (59UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 (60UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 (61UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 (62UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 (63UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 (64UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 (65UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 (66UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 (67UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock0 (68UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock1 (69UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock2 (70UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock3 (71UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock4 (72UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock5 (73UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock6 (74UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock7 (75UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock8 (76UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock9 (77UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock10 (78UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock11 (79UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock12 (80UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock13 (81UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock14 (82UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock15 (83UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock16 (84UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock17 (85UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock18 (86UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock19 (87UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock20 (88UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock21 (89UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock22 (90UL) 
#define NvMConf_NvMBlockDescriptor_DemSecondaryDataBlock23 (91UL) 


/* CONST_DESCRIPTOR_TABLE contains all block relevant data, including the compiled config ID
 */
#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(uint16, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
/* PRQA S 0759 1 */ /* MD_MSR_18.4 */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t;

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_FUNCTIONS
#define NVM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_RH850_1363
#define NVM_PROCESSOR_RH850_1363
#endif
#ifndef NVM_COMP_GREENHILLS
#define NVM_COMP_GREENHILLS
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/*---- End of File ---------------------------------------------------------*/

