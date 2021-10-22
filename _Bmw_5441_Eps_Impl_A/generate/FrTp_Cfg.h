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
 *            Module: FrTp
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTp_Cfg.h
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


#if !defined(FRTP_CFG_H)
#define FRTP_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ FrTp_ModuleSpecificGeneralDefines
 ----------------------------------------------------------------------------- */
 
#ifndef FRTP_USE_DUMMY_FUNCTIONS
#define FRTP_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FRTP_USE_DUMMY_STATEMENT
#define FRTP_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FRTP_DUMMY_STATEMENT
#define FRTP_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTP_DUMMY_STATEMENT_CONST
#define FRTP_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRTP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FRTP_ATOMIC_VARIABLE_ACCESS
#define FRTP_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FRTP_PROCESSOR_RH850_1363
#define FRTP_PROCESSOR_RH850_1363
#endif
#ifndef FRTP_COMP_GREENHILLS
#define FRTP_COMP_GREENHILLS
#endif
#ifndef FRTP_GEN_GENERATOR_MSR
#define FRTP_GEN_GENERATOR_MSR
#endif
#ifndef FRTP_CPUTYPE_BITORDER_LSB2MSB
#define FRTP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FRTP_CONFIGURATION_VARIANT_PRECOMPILE
#define FRTP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FRTP_CONFIGURATION_VARIANT_LINKTIME
#define FRTP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FRTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FRTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FRTP_CONFIGURATION_VARIANT
#define FRTP_CONFIGURATION_VARIANT FRTP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FRTP_POSTBUILD_VARIANT_SUPPORT
#define FRTP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifndef FRTP_DEV_ERROR_DETECT
# define FRTP_DEV_ERROR_DETECT      STD_ON
#endif
#ifndef FRTP_DEV_ERROR_REPORT
# define FRTP_DEV_ERROR_REPORT      STD_ON
#endif

/* -----------------------------------------------------------------------------
    &&&~ Collection of all preprocessor switches
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Vector preprocessor switches
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ AUTOSAR preprocessor switches
 ----------------------------------------------------------------------------- */
#define FRTP_VERSION_INFO_API STD_OFF 
#define FRTP_HAVE_TC STD_OFF 
#define FRTP_HAVE_RC STD_OFF 
#define FRTP_RUNTIME_MEASUREMENT_SUPPORT STD_OFF
#define FRTP_INVALID_SNV 0xFFU /*    */ 

/* -----------------------------------------------------------------------------
    &&&~ MICROSAR preprocessor switches
 ----------------------------------------------------------------------------- */
 
#define FRTP_RX_IND_EARLIER_THAN_TX_CONF STD_OFF 
 
#define FRTP_FULL_AR421 STD_OFF /*!< This switch is always generated 'STD_OFF' because the Vector DCM does not support 'full AUTOSAR 4.2.1' regarding the PduR generic TP API */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_Cfg
 ----------------------------------------------------------------------------- */
 
#define FrTp_MaxRxSduId                   28U
#define FrTp_MaxTxSduId                   14U
#define FrTp_MaxFrIfRxPduId               2U
#define FrTp_MaxFrIfTxPduId               1U
#define FrTp_MaxLengthRxPdus              254U
#define FrTp_MaxLengthTxPdus              32U
#define FrTp_NumConn                      28U

#define FrTp_NumRxChan                    28U 
#define FrTp_NumTxChan                    14U 
#define FrTp_InstanceId                   0U
#define FrTp_NumFrIfRxPdus                2U
#define FrTp_NumFrIfTxPdus                1U
#define FrTp_NumDecoupPdus                1U
#define FrTp_NumRxPools                   2U
#define FrTp_NumTxPools                   1U

 

/* -----------------------------------------------------------------------------
    &&&~ SymbolicNameValues
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ SymbolicNameValues for FrTpTxSduId
 ----------------------------------------------------------------------------- */



/**
 * \defgroup FrTpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF0                   0
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF1                   1
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF2                   2
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF3                   3
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF4                   4
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF5                   5
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF6                   6
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF7                   7
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF8                   8
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF9                   9
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFA                   10
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFB                   11
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFC                   12
#define FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFD                   13
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ SymbolicNameValues for FrTpRxSduId
 ----------------------------------------------------------------------------- */



/**
 * \defgroup FrTpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF0                             0
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF1                             1
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF2                             2
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF3                             3
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF4                             4
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF5                             5
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF6                             6
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF7                             7
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF8                             8
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xF9                             9
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xFA                             10
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xFB                             11
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xFC                             12
#define FrTpConf_FrTpRxSdu_FrTpRxBRC_0xFD                             13
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF0                   14
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF1                   15
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF2                   16
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF3                   17
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF4                   18
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF5                   19
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF6                   20
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF7                   21
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF8                   22
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xF9                   23
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xFA                   24
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xFB                   25
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xFC                   26
#define FrTpConf_FrTpRxSdu_FrTpRxSduGwTrnsm254_0xFD                   27
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ SymbolicNameValues for FrTpRxPduId
 ----------------------------------------------------------------------------- */



/**
 * \defgroup FrTpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrTpConf_FrTpRxPdu_FrTpRxPduBRC                               0
#define FrTpConf_FrTpRxPdu_FrTpRxPduTRNSM                             1
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ SymbolicNameValues for FrTpTxConfirmationPduId
 ----------------------------------------------------------------------------- */



/**
 * \defgroup FrTpHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrTpConf_FrTpTxPdu_FrTpTxPduTRNSM                             0
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ FrTp AUTOSAR VERSION
 ----------------------------------------------------------------------------- */
#define FRTP_AUTOSARVERSION4




/* end Fileversion check */

#endif /* FRTP_CFG_H */

