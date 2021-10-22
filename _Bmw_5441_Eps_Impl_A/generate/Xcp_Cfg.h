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
 *            Module: Xcp
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Xcp_Cfg.h
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

    
#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__

#ifndef XCP_USE_DUMMY_FUNCTIONS
#define XCP_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef XCP_USE_DUMMY_STATEMENT
#define XCP_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT_CONST
#define XCP_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XCP_ATOMIC_VARIABLE_ACCESS
#define XCP_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XCP_PROCESSOR_RH850_1363
#define XCP_PROCESSOR_RH850_1363
#endif
#ifndef XCP_COMP_GREENHILLS
#define XCP_COMP_GREENHILLS
#endif
#ifndef XCP_GEN_GENERATOR_MSR
#define XCP_GEN_GENERATOR_MSR
#endif
#ifndef XCP_CPUTYPE_BITORDER_LSB2MSB
#define XCP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef XCP_CONFIGURATION_VARIANT_PRECOMPILE
#define XCP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XCP_CONFIGURATION_VARIANT_LINKTIME
#define XCP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XCP_CONFIGURATION_VARIANT
#define XCP_CONFIGURATION_VARIANT XCP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XCP_POSTBUILD_VARIANT_SUPPORT
#define XCP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Development error detecting and reporting */
#define XCP_DEV_ERROR_DETECT                 STD_ON
#define XCP_DEV_ERROR_REPORT                 STD_ON

/* General settings */
#define XCP_BOOTLOADER_DOWNLOAD              STD_OFF
#define XCP_CONTROL                          STD_ON
#define XCP_AMD_RUNTIME_MEASUREMENT          STD_OFF
#define XCP_VERSION_INFO_API                 STD_OFF 
#define XCP_GET_SESSION_STATUS_API           STD_OFF
#define XCP_TYPESAVE_COPY                    STD_OFF
#define XCP_DAQ_MEM_ACCESS_BY_APPL			 STD_OFF
/* Legacy settings */
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE

/* Service Request Message */
#define XCP_SERV_TEXT                        STD_OFF
#define XCP_SEND_EVENT                       STD_OFF

/* Commands */
#define XCP_OPEN_COMMAND_IF                  STD_OFF

/*  - Standard Commands */
#define XCP_BLOCK_UPLOAD                     STD_OFF
#define XCP_COMM_MODE_INFO                   STD_OFF
#define XCP_USER_COMMAND                     STD_ON
#define XCP_SEED_KEY                         STD_OFF
#define XCP_READ_PROTECTION                  STD_OFF
#define XCP_GET_ID_GENERIC                   STD_OFF
#define kXcpStationIdLength                  (0u)

/*    - CRC */
#define XCP_CHECKSUM                         STD_OFF
#define XCP_CUSTOM_CRC                       STD_OFF
#define XCP_AUTOSAR_CRC_MODULE               STD_OFF
#define kXcpChecksumMethod                   XCP_CHECKSUM_TYPE_NONE
#define kXcpChecksumBlockSize                (0u)

/*  - Calibration commands */
#define XCP_CALIBRATION                      STD_ON
#define XCP_BLOCK_DOWNLOAD                   STD_OFF
#define XCP_MODIFY_BITS                      STD_OFF
#define XCP_SHORT_DOWNLOAD                   STD_OFF
#define XCP_BLOCK_DOWNLOAD_MIN_ST            (0U)

/*  - Synchronous Data Acquisition (DAQ) commands */
#define XCP_DAQ                              STD_ON
#define XCP_NUMBER_OF_CORES                  (1U)
#define XCP_STIM                             STD_ON
#define XCP_DAQ_PRESCALER                    STD_ON
#define XCP_DAQ_OVERRUN_INDICATION           STD_ON
#define XCP_WRITE_DAQ_MULTIPLE               STD_ON
#define XCP_DAQ_HDR_ODT_DAQ                  STD_OFF
#define XCP_DAQ_RESUME                       STD_OFF
#define XCP_DAQ_PROCESSOR_INFO               STD_ON
#define XCP_DAQ_RESOLUTION_INFO              STD_ON

#define XCP_MAX_DAQ                          1U
#define XCP_MAX_ODT_DAQ                      (5U)
#define XCP_MAX_ODT_ENTRIES                  (20U)
#define XCP_MAX_ODT_STIM                     (3U)

/*    - DAQ event Info */
#define XCP_DAQ_EVENT_INFO                   STD_ON
#define XCP_MAX_EVENT                        (1U)

/*    - DAQ Timestamp */
#define XCP_DAQ_TIMESTAMP_FIXED              STD_ON
#define XCP_DAQ_TIMESTAMP_SIZE               XCP_DAQ_TIMESTAMP_WORD
#define XCP_DAQ_TIMESTAMP_UNIT               XCP_DAQ_TIMESTAMP_UNIT_1US
#define XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT     (1U)

/*  - Page switching */
#define XCP_CALIBRATION_PAGE                 STD_ON
#define XCP_MAX_SEGMENT                      (1u)
#define XCP_PAGE_INFO                        STD_ON
#define XCP_MAX_PAGES                        (2u)
#define XCP_COPY_CAL_PAGE                    STD_ON
#define XCP_PAGE_FREEZE                      STD_OFF

/*  - Programming */
#define XCP_PROGRAM                          STD_OFF
#define XCP_PROGRAMMING_WRITE_PROTECTION     STD_OFF
#define XCP_MAX_SECTOR                       (0u)
#define XCP_PROGRAM_INFO                     STD_OFF
#define kXcpProgramMinStPgm                  (0u)

#ifndef XCP_AUTOSARVERSION
#define XCP_AUTOSARVERSION                   (4u) 
#endif

#define XCP_CANOE_EMU                        STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Multiple transport layer support
 ----------------------------------------------------------------------------- */

#define XCP_MAX_CTO_MAX                      (28U)
#define XCP_MAX_DTO_MAX                      (12U)
/* Multiple transport layer support */
#define XCP_NUMBER_OF_TRANSPORTLAYERS        (1U)
#define XCP_NUMBER_OF_CHANNELS               ((1U))               

#define XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR
#define XCP_TRANSPORT_LAYER_FR               (0U)

/* -----------------------------------------------------------------------------
    &&&~ FlexRay parameter access
 ----------------------------------------------------------------------------- */

#define XCP_READCCCONFIG                     STD_OFF
#define XCP_ADDR_EXT_READCCCONFIG            (0u)
    
/* User Config File Start */
#undef kXcpMaxSegment
#define kXcpMaxSegment 4U
#undef XCP_MAX_SEGMENT
#define XCP_MAX_SEGMENT 4U
/* User Config File End */


/* end Fileversion check */

#endif /* __XCP_CFG_H__ */

