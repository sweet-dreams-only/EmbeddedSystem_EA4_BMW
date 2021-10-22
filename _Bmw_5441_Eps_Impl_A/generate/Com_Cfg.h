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
 *            Module: Com
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cfg.h
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


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
# include "Com_PBcfg.h"
# include "Com_Cbk.h"
# include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_FUNCTIONS
#define COM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_RH850_1363
#define COM_PROCESSOR_RH850_1363
#endif
#ifndef COM_COMP_GREENHILLS
#define COM_COMP_GREENHILLS
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCDataSwitches  Com Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ACTIVATABLERXCOMIPDUS                                     STD_ON
#define COM_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                       STD_ON
#define COM_ACTIVATABLETXCOMIPDUS                                     STD_ON
#define COM_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                       STD_ON
#define COM_ALWAYSACTIVERXCOMIPDUS                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_RXPDUINFOIDXOFALWAYSACTIVERXCOMIPDUS                      STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ALWAYSACTIVETXCOMIPDUS                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveTxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                      STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveTxComIPdus.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTR                                          STD_ON
#define COM_CBKRXTOUTFUNCPTRIND                                       STD_ON
#define COM_CBKTXACKDEFFUNCPTR                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTRIND                                     STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTR                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTRIND                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTR                                           STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTRIND                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                          STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRIND                                       STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONFIGID                                                  STD_ON
#define COM_CONSTVALUEARRAYBASED                                      STD_ON
#define COM_CONSTVALUESINT16                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT32                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT64                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT8                                           STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESS                               STD_OFF  /**< Deactivateable: 'Com_ConstValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT16                                          STD_ON
#define COM_CONSTVALUEUINT32                                          STD_ON
#define COM_CONSTVALUEUINT64                                          STD_ON
#define COM_CONSTVALUEUINT8                                           STD_ON
#define COM_CURRENTTXMODE                                             STD_ON
#define COM_CYCLETIMECNT                                              STD_ON
#define COM_CYCLICSENDREQUEST                                         STD_ON
#define COM_DEFERREDGWMAPPINGEVENT                                    STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingEvent' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFO                                     STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFDEFERREDGWMAPPINGINFO                       STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DELAYTIMECNT                                              STD_ON
#define COM_DIRECTTRIGGER                                             STD_OFF  /**< Deactivateable: 'Com_DirectTrigger' Reason: 'the parameter is only needed if ComEnableMDTForCyclicTransmission is equals FALSE.' */
#define COM_FILTERINFO_SINT16                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT32                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT64                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT8                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT16                                         STD_ON
#define COM_FILTERALGOOFFILTERINFO_UINT16                             STD_ON
#define COM_FILTERMASKOFFILTERINFO_UINT16                             STD_ON
#define COM_FILTERMAXOFFILTERINFO_UINT16                              STD_ON
#define COM_FILTERMINOFFILTERINFO_UINT16                              STD_ON
#define COM_FILTERXOFFILTERINFO_UINT16                                STD_ON
#define COM_FILTERINFO_UINT32                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT64                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8                                          STD_ON
#define COM_FILTERALGOOFFILTERINFO_UINT8                              STD_ON
#define COM_FILTERMASKOFFILTERINFO_UINT8                              STD_ON
#define COM_FILTERMAXOFFILTERINFO_UINT8                               STD_ON
#define COM_FILTERMINOFFILTERINFO_UINT8                               STD_ON
#define COM_FILTERXOFFILTERINFO_UINT8                                 STD_ON
#define COM_FILTERINFO_UINT8_N                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8_N                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8_N                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8_N                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8_N                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8_N                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTER                STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockCounter' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLD              STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockThreshold' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTER                           STD_ON
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLD                         STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway either not licensed or not configured.' */
#define COM_GWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo' Reason: 'Gateway description feature is not licensed' */
#define COM_BITOFFSETOFGWDESCRIPTIONACCESSINFO                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitOffset' Reason: 'Gateway description feature is not licensed' */
#define COM_BITSIZEOFGWDESCRIPTIONACCESSINFO                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitSize' Reason: 'Gateway description feature is not licensed' */
#define COM_COPYTYPEOFGWDESCRIPTIONACCESSINFO                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_GWSOURCESTARTBITINDEXOFGWDESCRIPTIONACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.GwSourceStartBitIndex' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBIDXOFGWDESCRIPTIONACCESSINFO                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKIDXOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKUSEDOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKIDXOFGWDESCRIPTIONACCESSINFO         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCESTARTBYTEPOSITIONOFGWDESCRIPTIONACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceStartBytePosition' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERENDIDXOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERLENGTHOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferLength' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERSTARTIDXOFGWDESCRIPTIONACCESSINFO                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERUBIDXOFGWDESCRIPTIONACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERUBUSEDOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_TXPDUINFOIDXOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxPduInfoIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_TYPEOFGWDESCRIPTIONACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_VALIDDLCOFGWDESCRIPTIONACCESSINFO                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.ValidDlc' Reason: 'Gateway description feature is not licensed' */
#define COM_GWEVENT                                                   STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWEVENTCACHE                                              STD_OFF  /**< Deactivateable: 'Com_GwEventCache' Reason: 'Gateway description feature is not licensed' */
#define COM_GWEVENTCACHEINDEX                                         STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex' Reason: 'Gateway description feature is not licensed' */
#define COM_GWGRPSIGMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                          STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWGRPSIGMAPPING                                  STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                               STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWROUTINGTIMEOUTCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_GwRoutingTimeoutCounter' Reason: 'Gateway is not licensed.' */
#define COM_GWSIGGRPMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                    STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPIDOFGWSIGGRPMAPPING                               STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                              STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                             STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWSIGMAPPING                                     STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWTIMEOUTINFO                                             STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo' Reason: 'Gateway is not licensed.' */
#define COM_GWROUTINGTIMEOUTFACTOROFGWTIMEOUTINFO                     STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.GwRoutingTimeoutFactor' Reason: 'Gateway is not licensed.' */
#define COM_TXPDUINFOIDXOFGWTIMEOUTINFO                               STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.TxPduInfoIdx' Reason: 'Gateway is not licensed.' */
#define COM_GWTXPDUDESCRIPTIONINFO                                    STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo' Reason: 'Gateway description feature is not licensed' */
#define COM_GWDESCRIPTIONACCESSINFOENDIDXOFGWTXPDUDESCRIPTIONINFO     STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWDESCRIPTIONACCESSINFOSTARTIDXOFGWTXPDUDESCRIPTIONINFO   STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTION                             STD_OFF  /**< Deactivateable: 'Com_HandleRxDeferredGwDescription' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXPDUDEFERRED                                       STD_ON
#define COM_HANDLETXPDUDEFERRED                                       STD_ON
#define COM_IPDUGROUPINFO                                             STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO      STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO    STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO        STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INVALIDHNDOFIPDUGROUPINFO                                 STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfRxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfTxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoToSubIPduGroupsInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPSTATE                                            STD_OFF  /**< Deactivateable: 'Com_IPduGroupState' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZED                                               STD_ON
#define COM_PDUGRPCNT                                                 STD_ON
#define COM_PDUGRPVECTOR                                              STD_ON
#define COM_REPCNT                                                    STD_ON
#define COM_REPCYCLECNT                                               STD_ON
#define COM_RXACCESSINFO                                              STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                    STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                   STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                 STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                   STD_ON
#define COM_BUFFERUSEDOFRXACCESSINFO                                  STD_ON
#define COM_BUSACCOFRXACCESSINFO                                      STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                  STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO         STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO         STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO       STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO           STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFRXACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEENDIDXOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUELENGTHOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUESTARTIDXOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWINFOIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                STD_ON
#define COM_INITVALUEUSEDOFRXACCESSINFO                               STD_ON
#define COM_INVVALUEIDXOFRXACCESSINFO                                 STD_ON
#define COM_INVVALUEUSEDOFRXACCESSINFO                                STD_ON
#define COM_INVALIDHNDOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ISGROUPSIGNALOFRXACCESSINFO                               STD_ON
#define COM_ROUTINGBUFFERIDXOFRXACCESSINFO                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferIdx' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFERUSEDOFRXACCESSINFO                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO           STD_ON
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO          STD_ON
#define COM_RXPDUINFOIDXOFRXACCESSINFO                                STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO           STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO           STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO         STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO             STD_ON
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERLENGTHOFRXACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferLength' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERUSEDOFRXACCESSINFO      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERENDIDXOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERLENGTHOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERSTARTIDXOFRXACCESSINFO      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERUSEDOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXACCESSINFO                               STD_ON
#define COM_RXTOUTINFOUSEDOFRXACCESSINFO                              STD_ON
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                STD_ON
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                               STD_ON
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                      STD_ON
#define COM_TMPBUFFERIDXOFRXACCESSINFO                                STD_ON
#define COM_TMPBUFFERUSEDOFRXACCESSINFO                               STD_ON
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERENDIDXOFRXACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferEndIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERLENGTHOFRXACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferLength' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERSTARTIDXOFRXACCESSINFO   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferStartIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERUSEDOFRXACCESSINFO       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOGRPSIGIND                                     STD_ON
#define COM_RXACCESSINFOIND                                           STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTR                                              STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTER                        STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLD                      STD_ON
#define COM_RXDEFPDUBUFFER                                            STD_ON
#define COM_RXDEFERREDEVENTCACHE                                      STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHE                                     STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTER                        STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLD                      STD_ON
#define COM_RXDLMONDIVISOR                                            STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDLMONDIVISORCOUNTER                                     STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXIPDUGROUPISRLOCKCOUNTER                                 STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLD                               STD_ON
#define COM_RXNEXTEVENTCACHEENTY                                      STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEnty' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUDMSTATE                                              STD_ON
#define COM_RXPDUGRPACTIVE                                            STD_ON
#define COM_RXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFRXPDUGRPINFO                            STD_ON
#define COM_RXPDUINFO                                                 STD_ON
#define COM_DEFERREDGWMAPPINGINFOIDXOFRXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFOUSEDOFRXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_GWINFOENDIDXOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWTXPDUDESCRIPTIONINFOENDIDXOFRXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWTXPDUDESCRIPTIONINFOSTARTIDXOFRXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWTXPDUDESCRIPTIONINFOUSEDOFRXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONIDXOFRXPDUINFO               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONUSEDOFRXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                         STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                        STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                          STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                        STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                            STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                         STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                             STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                          STD_ON
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                        STD_ON
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                            STD_ON
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                              STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                  STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                  STD_ON
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                            STD_ON
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                          STD_ON
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                              STD_ON
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                 STD_ON
#define COM_RXTPINFOIDXOFRXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGNALPROCESSINGOFRXPDUINFO                               STD_ON
#define COM_TYPEOFRXPDUINFO                                           STD_ON
#define COM_RXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_RxPduInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFER                              STD_OFF  /**< Deactivateable: 'Com_RxSigArrayAccessSigGrpBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERARRAYBASED                                     STD_ON
#define COM_RXSIGBUFFERSINT16                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT32                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT64                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT8                                          STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT16                                         STD_ON
#define COM_RXSIGBUFFERUINT32                                         STD_ON
#define COM_RXSIGBUFFERUINT64                                         STD_ON
#define COM_RXSIGBUFFERUINT8                                          STD_ON
#define COM_RXSIGBUFFERZEROBIT                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferZeroBit' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFO                                              STD_ON
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUESIGGRPARRAYACCESSENDIDXOFRXSIGGRPINFO           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessEndIdx' Reason: 'the optional indirection is deactivated because ConstValueSigGrpArrayAccessUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUESIGGRPARRAYACCESSLENGTHOFRXSIGGRPINFO           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessLength' Reason: 'the optional indirection is deactivated because ConstValueSigGrpArrayAccessUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUESIGGRPARRAYACCESSSTARTIDXOFRXSIGGRPINFO         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessStartIdx' Reason: 'the optional indirection is deactivated because ConstValueSigGrpArrayAccessUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUESIGGRPARRAYACCESSUSEDOFRXSIGGRPINFO             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessUsed' Reason: 'the optional indirection is deactivated because ConstValueSigGrpArrayAccessUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8ENDIDXOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8EndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8LENGTHOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Length' Reason: 'the optional indirection is deactivated because ConstValueUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8STARTIDXOFRXSIGGRPINFO                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8StartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8USEDOFRXSIGGRPINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Used' Reason: 'the optional indirection is deactivated because ConstValueUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the value of Com_FilterEventOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                    STD_ON
#define COM_INVALIDHNDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO                 STD_ON
#define COM_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO               STD_ON
#define COM_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO                   STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                          STD_ON
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                         STD_ON
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                STD_ON
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERENDIDXOFRXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigArrayAccessSigGrpBufferUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERLENGTHOFRXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferLength' Reason: 'the optional indirection is deactivated because RxSigArrayAccessSigGrpBufferUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERSTARTIDXOFRXSIGGRPINFO        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigArrayAccessSigGrpBufferUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERUSEDOFRXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferUsed' Reason: 'the optional indirection is deactivated because RxSigArrayAccessSigGrpBufferUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERUINT8ENDIDXOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8EndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERUINT8LENGTHOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Length' Reason: 'the optional indirection is deactivated because RxSigBufferUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERUINT8STARTIDXOFRXSIGGRPINFO                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8StartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERUINT8USEDOFRXSIGGRPINFO                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Used' Reason: 'the optional indirection is deactivated because RxSigBufferUInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                               STD_ON
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                              STD_ON
#define COM_SHDBUFFERREQUIREDOFRXSIGGRPINFO                           STD_ON
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                            STD_ON
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                           STD_ON
#define COM_UBIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigGrpInfo is always 'COM_NO_UBIDXOFRXSIGGRPINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                    STD_ON
#define COM_RXSIGGRPINFOIND                                           STD_ON
#define COM_RXSIGINFO                                                 STD_ON
#define COM_GWINFOIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGINFO                             STD_ON
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                            STD_ON
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                  STD_ON
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                 STD_ON
#define COM_SIGNALPROCESSINGOFRXSIGINFO                               STD_ON
#define COM_UBIDXOFRXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                       STD_ON
#define COM_RXTOUTCNT                                                 STD_ON
#define COM_RXTOUTINFO                                                STD_ON
#define COM_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                     STD_ON
#define COM_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                   STD_ON
#define COM_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                       STD_ON
#define COM_FACTOROFRXTOUTINFO                                        STD_ON
#define COM_FIRSTFACTOROFRXTOUTINFO                                   STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO              STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO               STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                 STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                  STD_ON
#define COM_RXTOUTINFOIND                                             STD_ON
#define COM_RXTPBUFFER                                                STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFRXTPINFO                            STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFO                                     STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKENDIDXOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKLENGTHOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKSTARTIDXOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKUSEDOFSIGGRPARRAYFILTERINFO      STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXENDIDXOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXLENGTHOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXSTARTIDXOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXUSEDOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_FILTERALGOOFSIGGRPARRAYFILTERINFO                         STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_OFFSETINSIGNALGROUPOFSIGGRPARRAYFILTERINFO                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.OffsetInSignalGroup' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                           STD_ON
#define COM_SIZEOFACTIVATABLERXCOMIPDUS                               STD_ON
#define COM_SIZEOFACTIVATABLETXCOMIPDUS                               STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTR                                    STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRIND                                 STD_ON
#define COM_SIZEOFCONSTVALUEARRAYBASED                                STD_ON
#define COM_SIZEOFCONSTVALUEUINT16                                    STD_ON
#define COM_SIZEOFCONSTVALUEUINT32                                    STD_ON
#define COM_SIZEOFCONSTVALUEUINT64                                    STD_ON
#define COM_SIZEOFCONSTVALUEUINT8                                     STD_ON
#define COM_SIZEOFCURRENTTXMODE                                       STD_ON
#define COM_SIZEOFCYCLETIMECNT                                        STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                   STD_ON
#define COM_SIZEOFDELAYTIMECNT                                        STD_ON
#define COM_SIZEOFFILTERINFO_UINT16                                   STD_ON
#define COM_SIZEOFFILTERINFO_UINT8                                    STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                 STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERRED                                 STD_ON
#define COM_SIZEOFPDUGRPVECTOR                                        STD_ON
#define COM_SIZEOFREPCNT                                              STD_ON
#define COM_SIZEOFREPCYCLECNT                                         STD_ON
#define COM_SIZEOFRXACCESSINFO                                        STD_ON
#define COM_SIZEOFRXACCESSINFOGRPSIGIND                               STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                     STD_ON
#define COM_SIZEOFRXCBKFUNCPTR                                        STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                      STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHE                               STD_ON
#define COM_SIZEOFRXPDUDMSTATE                                        STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFRXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFRXPDUINFO                                           STD_ON
#define COM_SIZEOFRXSIGBUFFERARRAYBASED                               STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT32                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT64                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8                                    STD_ON
#define COM_SIZEOFRXSIGGRPINFO                                        STD_ON
#define COM_SIZEOFRXSIGGRPINFOIND                                     STD_ON
#define COM_SIZEOFRXSIGINFO                                           STD_ON
#define COM_SIZEOFRXTOUTCNT                                           STD_ON
#define COM_SIZEOFRXTOUTINFO                                          STD_ON
#define COM_SIZEOFRXTOUTINFOIND                                       STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAG                                     STD_ON
#define COM_SIZEOFTMPRXBUFFER                                         STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT16                                STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT32                                STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT8                                 STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                     STD_ON
#define COM_SIZEOFTXBUFFER                                            STD_ON
#define COM_SIZEOFTXFILTERINITVALUEUINT16                             STD_ON
#define COM_SIZEOFTXFILTERINITVALUEUINT8                              STD_ON
#define COM_SIZEOFTXFILTEROLDVALUEUINT16                              STD_ON
#define COM_SIZEOFTXFILTEROLDVALUEUINT8                               STD_ON
#define COM_SIZEOFTXMODEINFO                                          STD_ON
#define COM_SIZEOFTXMODETRUE                                          STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFTXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFTXPDUINFO                                           STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                      STD_ON
#define COM_SIZEOFTXSDULENGTH                                         STD_ON
#define COM_SIZEOFTXSIGGRPINFO                                        STD_ON
#define COM_SIZEOFTXSIGGRPINFOIND                                     STD_ON
#define COM_SIZEOFTXSIGGRPMASK                                        STD_ON
#define COM_SIZEOFTXSIGINFO                                           STD_ON
#define COM_SIZEOFTXSIGINFOFILTERINITVALUEIND                         STD_ON
#define COM_SIZEOFTXSIGINFOINVVALUEIND                                STD_ON
#define COM_SIZEOFWAITINGFORCONFIRMATION                              STD_ON
#define COM_SOURCEDESCRIPTIONMASK                                     STD_OFF  /**< Deactivateable: 'Com_SourceDescriptionMask' Reason: 'Gateway description feature is not licensed' */
#define COM_TMPRXBUFFER                                               STD_ON
#define COM_TMPRXSHDBUFFERARRAYBASED                                  STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferArrayBased' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT16                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT32                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT64                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT8                                       STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT16                                      STD_ON
#define COM_TMPRXSHDBUFFERUINT32                                      STD_ON
#define COM_TMPRXSHDBUFFERUINT64                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT8                                       STD_ON
#define COM_TRANSMITREQUEST                                           STD_ON
#define COM_TXBUFFER                                                  STD_ON
#define COM_TXCYCLECOUNTERDIVISOR                                     STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLECOUNTERDIVISORCOUNTER                              STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTER                          STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLD                        STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTER                        STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLD                      STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOR                                            STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDLMONDIVISORCOUNTER                                     STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                         STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASED                               STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT16                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT64                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT8                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESIGGRPARRAYACCESS                        STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT16                                   STD_ON
#define COM_TXFILTERINITVALUEUINT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT64                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT8                                    STD_ON
#define COM_TXFILTEROLDVALUEARRAYBASED                                STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueArrayBased' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT16                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT32                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT64                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT8                                     STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT16                                    STD_ON
#define COM_TXFILTEROLDVALUEUINT32                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT64                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT8                                     STD_ON
#define COM_TXFILTERSTATE                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXIPDUGROUPISRLOCKCOUNTER                                 STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLD                               STD_ON
#define COM_TXMODEFALSE                                               STD_OFF  /**< Deactivateable: 'Com_TxModeFalse' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_DIRECTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the value of Com_DirectOfTxModeFalse is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODEFALSE                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Periodic' Reason: 'the value of Com_PeriodicOfTxModeFalse is always 'false' due to this, the array is deactivated.' */
#define COM_REPCNTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the value of Com_RepCntOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODEFALSE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                   STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeFalse is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODEFALSE                                   STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimePeriod' Reason: 'the value of Com_TimePeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TXMODEINFO                                                STD_ON
#define COM_INITMODEOFTXMODEINFO                                      STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxModeInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINIMUMDELAYOFTXMODEINFO                                  STD_ON
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_TXMODEFALSEUSEDOFTXMODEINFO                               STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseUsed' Reason: 'All indirection targets are deactivated in all variants.' */
#define COM_TXMODETRUEIDXOFTXMODEINFO                                 STD_ON
#define COM_TXMODETRUEUSEDOFTXMODEINFO                                STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO             STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO           STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO               STD_ON
#define COM_TXMODETRUE                                                STD_ON
#define COM_DIRECTOFTXMODETRUE                                        STD_ON
#define COM_PERIODICOFTXMODETRUE                                      STD_ON
#define COM_REPCNTOFTXMODETRUE                                        STD_ON
#define COM_REPPERIODOFTXMODETRUE                                     STD_ON
#define COM_TIMEOFFSETOFTXMODETRUE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                    STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUGRPACTIVE                                            STD_ON
#define COM_TXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFTXPDUGRPINFO                            STD_ON
#define COM_TXPDUINFO                                                 STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: '/ActiveEcuC/PduR/Com[0:PduRCancelTransmit] is configured to 'false'' */
#define COM_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDENDIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDSTARTIDXOFTXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDUSEDOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDENDIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDSTARTIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDUSEDOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKENDIDXOFTXPDUINFO               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKSTARTIDXOFTXPDUINFO             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKUSEDOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                     STD_ON
#define COM_GWTIMEOUTINFOIDXOFTXPDUINFO                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoIdx' Reason: 'Gateway is not licensed.' */
#define COM_GWTIMEOUTINFOUSEDOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoUsed' Reason: 'Gateway is not licensed.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFTXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFTXPDUINFO                                 STD_ON
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                          STD_ON
#define COM_TXBUFFERENDIDXOFTXPDUINFO                                 STD_ON
#define COM_TXBUFFERLENGTHOFTXPDUINFO                                 STD_ON
#define COM_TXBUFFERMETADATAENDIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATALENGTHOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATASTARTIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATAUSEDOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXPDUINFO                               STD_ON
#define COM_TXBUFFERUSEDOFTXPDUINFO                                   STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                           STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                         STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                             STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                          STD_ON
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                        STD_ON
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                            STD_ON
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_TxPduInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINITVALUE                                            STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                     STD_OFF  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPROCESSINGISRLOCKCOUNTER                                STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLD                              STD_ON
#define COM_TXSDULENGTH                                               STD_ON
#define COM_TXSIGGRPINFO                                              STD_ON
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_PDUOFFSETOFTXSIGGRPINFO                                   STD_ON
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOENDIDXOFTXSIGGRPINFO                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOSTARTIDXOFTXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOUSEDOFTXSIGGRPINFO                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                            STD_ON
#define COM_TXBUFFERENDIDXOFTXSIGGRPINFO                              STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGGRPINFO                              STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO                STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO                STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO              STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGGRPINFO                            STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGGRPINFO                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGGRPINFO                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGGRPINFO                                STD_ON
#define COM_TXFILTERINITSTATEENDIDXOFTXSIGGRPINFO                     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXSIGGRPINFO                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGGRPINFO                                STD_ON
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                        STD_ON
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                            STD_ON
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                  STD_ON
#define COM_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                STD_ON
#define COM_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                    STD_ON
#define COM_UBMASKIDXOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOIND                                           STD_ON
#define COM_TXSIGGRPMASK                                              STD_ON
#define COM_TXSIGGRPONCHANGEMASK                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                 STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                       STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                      STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                    STD_ON
#define COM_BUSACCOFTXSIGINFO                                         STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                     STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                   STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXSIGINFO             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXSIGINFO             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXSIGINFO           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXSIGINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFTXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                             STD_ON
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                            STD_ON
#define COM_INVVALUEIDXOFTXSIGINFO                                    STD_ON
#define COM_INVVALUEUSEDOFTXSIGINFO                                   STD_ON
#define COM_INVALIDHNDOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ONCHANGEIDXOFTXSIGINFO                                    STD_ON
#define COM_ONCHANGEUSEDOFTXSIGINFO                                   STD_ON
#define COM_STARTBYTEINPDUPOSITIONOFTXSIGINFO                         STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXBUFFERENDIDXOFTXSIGINFO                                 STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGINFO                                 STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGINFO                               STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGINFO                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGINFO                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGINFO                                   STD_ON
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGINFO                                   STD_ON
#define COM_TXSIGGRPINFOIDXOFTXSIGINFO                                STD_ON
#define COM_TXSIGGRPINFOUSEDOFTXSIGINFO                               STD_ON
#define COM_UBMASKIDXOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                               STD_ON
#define COM_TXSIGINFOINVVALUEIND                                      STD_ON
#define COM_TXTOUTCNT                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKTXTOUTFUNCPTRINDENDIDXOFTXTOUTINFO                     STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDSTARTIDXOFTXTOUTINFO                   STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDUSEDOFTXTOUTINFO                       STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MODEOFTXTOUTINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTMPTPPDULENGTH                                          STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFTXTPINFO                            STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFTXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFTXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXTPINFO                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERUSEDOFTXTPINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGIDXOFTXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGUSEDOFTXTPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_WAITINGFORCONFIRMATION                                    STD_ON
#define COM_PCCONFIG                                                  STD_ON
#define COM_ACTIVATABLERXCOMIPDUSOFPCCONFIG                           STD_ON
#define COM_ACTIVATABLETXCOMIPDUSOFPCCONFIG                           STD_ON
#define COM_CBKRXTOUTFUNCPTRINDOFPCCONFIG                             STD_ON
#define COM_CBKRXTOUTFUNCPTROFPCCONFIG                                STD_ON
#define COM_CONFIGIDOFPCCONFIG                                        STD_ON
#define COM_CONSTVALUEARRAYBASEDOFPCCONFIG                            STD_ON
#define COM_CONSTVALUEUINT16OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEUINT32OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEUINT64OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEUINT8OFPCCONFIG                                 STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                   STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                    STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                               STD_ON
#define COM_DELAYTIMECNTOFPCCONFIG                                    STD_ON
#define COM_FILTERINFO_UINT16OFPCCONFIG                               STD_ON
#define COM_FILTERINFO_UINT8OFPCCONFIG                                STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG    STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayDescriptionProcessingISRLockThreshold' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG               STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway either not licensed or not configured.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                             STD_ON
#define COM_HANDLETXPDUDEFERREDOFPCCONFIG                             STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                     STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                       STD_ON
#define COM_PDUGRPVECTOROFPCCONFIG                                    STD_ON
#define COM_REPCNTOFPCCONFIG                                          STD_ON
#define COM_REPCYCLECNTOFPCCONFIG                                     STD_ON
#define COM_RXACCESSINFOGRPSIGINDOFPCCONFIG                           STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                 STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                    STD_ON
#define COM_RXCBKFUNCPTROFPCCONFIG                                    STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG            STD_ON
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                  STD_ON
#define COM_RXDEFERREDFCTPTRCACHEOFPCCONFIG                           STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG            STD_ON
#define COM_RXDLMONDIVISOROFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                       STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                     STD_ON
#define COM_RXPDUDMSTATEOFPCCONFIG                                    STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_RXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_RXSIGBUFFERARRAYBASEDOFPCCONFIG                           STD_ON
#define COM_RXSIGBUFFERUINT16OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERUINT32OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERUINT64OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERUINT8OFPCCONFIG                                STD_ON
#define COM_RXSIGGRPINFOINDOFPCCONFIG                                 STD_ON
#define COM_RXSIGGRPINFOOFPCCONFIG                                    STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                       STD_ON
#define COM_RXTOUTCNTOFPCCONFIG                                       STD_ON
#define COM_RXTOUTINFOINDOFPCCONFIG                                   STD_ON
#define COM_RXTOUTINFOOFPCCONFIG                                      STD_ON
#define COM_SIGGRPEVENTFLAGOFPCCONFIG                                 STD_ON
#define COM_SIZEOFACTIVATABLERXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_SIZEOFACTIVATABLETXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRINDOFPCCONFIG                       STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTROFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEARRAYBASEDOFPCCONFIG                      STD_ON
#define COM_SIZEOFCONSTVALUEUINT16OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEUINT32OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEUINT64OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEUINT8OFPCCONFIG                           STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_SIZEOFDELAYTIMECNTOFPCCONFIG                              STD_ON
#define COM_SIZEOFFILTERINFO_UINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFFILTERINFO_UINT8OFPCCONFIG                          STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_SIZEOFPDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_SIZEOFREPCNTOFPCCONFIG                                    STD_ON
#define COM_SIZEOFREPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_SIZEOFRXACCESSINFOGRPSIGINDOFPCCONFIG                     STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXCBKFUNCPTROFPCCONFIG                              STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHEOFPCCONFIG                     STD_ON
#define COM_SIZEOFRXPDUDMSTATEOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFRXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXSIGBUFFERARRAYBASEDOFPCCONFIG                     STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT32OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT64OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8OFPCCONFIG                          STD_ON
#define COM_SIZEOFRXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFRXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXTOUTCNTOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXTOUTINFOINDOFPCCONFIG                             STD_ON
#define COM_SIZEOFRXTOUTINFOOFPCCONFIG                                STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_SIZEOFTMPRXBUFFEROFPCCONFIG                               STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT16OFPCCONFIG                      STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT32OFPCCONFIG                      STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERUINT8OFPCCONFIG                       STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXBUFFEROFPCCONFIG                                  STD_ON
#define COM_SIZEOFTXFILTERINITVALUEUINT16OFPCCONFIG                   STD_ON
#define COM_SIZEOFTXFILTERINITVALUEUINT8OFPCCONFIG                    STD_ON
#define COM_SIZEOFTXFILTEROLDVALUEUINT16OFPCCONFIG                    STD_ON
#define COM_SIZEOFTXFILTEROLDVALUEUINT8OFPCCONFIG                     STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_SIZEOFTXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGINFOFILTERINITVALUEINDOFPCCONFIG               STD_ON
#define COM_SIZEOFTXSIGINFOINVVALUEINDOFPCCONFIG                      STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFWAITINGFORCONFIRMATIONOFPCCONFIG                    STD_ON
#define COM_TMPRXBUFFEROFPCCONFIG                                     STD_ON
#define COM_TMPRXSHDBUFFERUINT16OFPCCONFIG                            STD_ON
#define COM_TMPRXSHDBUFFERUINT32OFPCCONFIG                            STD_ON
#define COM_TMPRXSHDBUFFERUINT8OFPCCONFIG                             STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                 STD_ON
#define COM_TXBUFFEROFPCCONFIG                                        STD_ON
#define COM_TXCYCLECOUNTERDIVISOROFPCCONFIG                           STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG              STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG            STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOROFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXFILTERINITVALUEUINT16OFPCCONFIG                         STD_ON
#define COM_TXFILTERINITVALUEUINT8OFPCCONFIG                          STD_ON
#define COM_TXFILTEROLDVALUEUINT16OFPCCONFIG                          STD_ON
#define COM_TXFILTEROLDVALUEUINT8OFPCCONFIG                           STD_ON
#define COM_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                       STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                     STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                      STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                      STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_TXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                  STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                      STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                    STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                     STD_ON
#define COM_TXSIGGRPINFOINDOFPCCONFIG                                 STD_ON
#define COM_TXSIGGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXSIGGRPMASKOFPCCONFIG                                    STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDOFPCCONFIG                     STD_ON
#define COM_TXSIGINFOINVVALUEINDOFPCCONFIG                            STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                       STD_ON
#define COM_WAITINGFORCONFIRMATIONOFPCCONFIG                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMinNumericValueDefines  Com Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COM_MIN_CYCLETIMECNT                                          0U
#define COM_MIN_DELAYTIMECNT                                          0U
#define COM_MIN_GATEWAYPROCESSINGISRLOCKCOUNTER                       0U
#define COM_MIN_HANDLERXPDUDEFERRED                                   0U
#define COM_MIN_REPCNT                                                0U
#define COM_MIN_REPCYCLECNT                                           0U
#define COM_MIN_RXDEADLINEMONITORINGISRLOCKCOUNTER                    0U
#define COM_MIN_RXDEFPDUBUFFER                                        0U
#define COM_MIN_RXDEFERREDFCTPTRCACHE                                 0UL
#define COM_MIN_RXDEFERREDPROCESSINGISRLOCKCOUNTER                    0U
#define COM_MIN_RXIPDUGROUPISRLOCKCOUNTER                             0U
#define COM_MIN_RXSIGBUFFERARRAYBASED                                 0U
#define COM_MIN_RXSIGBUFFERUINT16                                     0U
#define COM_MIN_RXSIGBUFFERUINT32                                     0UL
#define COM_MIN_RXSIGBUFFERUINT64                                     0ULL
#define COM_MIN_RXSIGBUFFERUINT8                                      0U
#define COM_MIN_RXTOUTCNT                                             0U
#define COM_MIN_SIGGRPEVENTFLAG                                       0U
#define COM_MIN_TMPRXBUFFER                                           0U
#define COM_MIN_TMPRXSHDBUFFERUINT16                                  0U
#define COM_MIN_TMPRXSHDBUFFERUINT32                                  0UL
#define COM_MIN_TMPRXSHDBUFFERUINT8                                   0U
#define COM_MIN_TXBUFFER                                              0U
#define COM_MIN_TXCYCLICPROCESSINGISRLOCKCOUNTER                      0U
#define COM_MIN_TXDEADLINEMONITORINGISRLOCKCOUNTER                    0U
#define COM_MIN_TXFILTEROLDVALUEUINT16                                0U
#define COM_MIN_TXFILTEROLDVALUEUINT8                                 0U
#define COM_MIN_TXIPDUGROUPISRLOCKCOUNTER                             0U
#define COM_MIN_TXPROCESSINGISRLOCKCOUNTER                            0U
#define COM_MIN_TXSDULENGTH                                           0U
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMaxNumericValueDefines  Com Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COM_MAX_CYCLETIMECNT                                          65535U
#define COM_MAX_DELAYTIMECNT                                          255U
#define COM_MAX_GATEWAYPROCESSINGISRLOCKCOUNTER                       65535U
#define COM_MAX_HANDLERXPDUDEFERRED                                   65535U
#define COM_MAX_REPCNT                                                65535U
#define COM_MAX_REPCYCLECNT                                           65535U
#define COM_MAX_RXDEADLINEMONITORINGISRLOCKCOUNTER                    65535U
#define COM_MAX_RXDEFPDUBUFFER                                        255U
#define COM_MAX_RXDEFERREDFCTPTRCACHE                                 4294967295UL
#define COM_MAX_RXDEFERREDPROCESSINGISRLOCKCOUNTER                    65535U
#define COM_MAX_RXIPDUGROUPISRLOCKCOUNTER                             65535U
#define COM_MAX_RXSIGBUFFERARRAYBASED                                 255U
#define COM_MAX_RXSIGBUFFERUINT16                                     65535U
#define COM_MAX_RXSIGBUFFERUINT32                                     4294967295UL
#define COM_MAX_RXSIGBUFFERUINT64                                     18446744073709551615ULL
#define COM_MAX_RXSIGBUFFERUINT8                                      255U
#define COM_MAX_RXTOUTCNT                                             65535U
#define COM_MAX_SIGGRPEVENTFLAG                                       255U
#define COM_MAX_TMPRXBUFFER                                           255U
#define COM_MAX_TMPRXSHDBUFFERUINT16                                  65535U
#define COM_MAX_TMPRXSHDBUFFERUINT32                                  4294967295UL
#define COM_MAX_TMPRXSHDBUFFERUINT8                                   255U
#define COM_MAX_TXBUFFER                                              255U
#define COM_MAX_TXCYCLICPROCESSINGISRLOCKCOUNTER                      65535U
#define COM_MAX_TXDEADLINEMONITORINGISRLOCKCOUNTER                    65535U
#define COM_MAX_TXFILTEROLDVALUEUINT16                                65535U
#define COM_MAX_TXFILTEROLDVALUEUINT8                                 255U
#define COM_MAX_TXIPDUGROUPISRLOCKCOUNTER                             65535U
#define COM_MAX_TXPROCESSINGISRLOCKCOUNTER                            65535U
#define COM_MAX_TXSDULENGTH                                           65535U
/** 
  \}
*/ 

/** 
  \defgroup  ComPCNoReferenceDefines  Com No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_BUFFERIDXOFRXACCESSINFO                                255U
#define COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO      255U
#define COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO    255U
#define COM_NO_INITVALUEIDXOFRXACCESSINFO                             255U
#define COM_NO_INVVALUEIDXOFRXACCESSINFO                              255U
#define COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO        255U
#define COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO        255U
#define COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO      255U
#define COM_NO_RXTOUTINFOIDXOFRXACCESSINFO                            255U
#define COM_NO_SHDBUFFERIDXOFRXACCESSINFO                             255U
#define COM_NO_TMPBUFFERIDXOFRXACCESSINFO                             255U
#define COM_NO_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                       255U
#define COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                     255U
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                      255U
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                       255U
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                     255U
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                        255U
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                      255U
#define COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                       255U
#define COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                     255U
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                             255U
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                           255U
#define COM_NO_RXTOUTINFOIDXOFRXPDUINFO                               255U
#define COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO                         255U
#define COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                       255U
#define COM_NO_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO              255U
#define COM_NO_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO            255U
#define COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                       255U
#define COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO                            255U
#define COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO                          255U
#define COM_NO_RXTOUTINFOIDXOFRXSIGINFO                               255U
#define COM_NO_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                  255U
#define COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                255U
#define COM_NO_TXMODETRUEIDXOFTXMODEINFO                              255U
#define COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO          255U
#define COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO        255U
#define COM_NO_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                       255U
#define COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                     255U
#define COM_NO_TXBUFFERENDIDXOFTXPDUINFO                              255U
#define COM_NO_TXBUFFERSTARTIDXOFTXPDUINFO                            255U
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                        255U
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                      255U
#define COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                       255U
#define COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                     255U
#define COM_NO_TXBUFFERENDIDXOFTXSIGGRPINFO                           65535U
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGGRPINFO                         65535U
#define COM_NO_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                       255U
#define COM_NO_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                     255U
#define COM_NO_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO               255U
#define COM_NO_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO             255U
#define COM_NO_FILTERINITVALUEIDXOFTXSIGINFO                          255U
#define COM_NO_INVVALUEIDXOFTXSIGINFO                                 255U
#define COM_NO_ONCHANGEIDXOFTXSIGINFO                                 255U
#define COM_NO_TXBUFFERENDIDXOFTXSIGINFO                              65535U
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGINFO                            65535U
#define COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO                             255U
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumExistsDefines  Com Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT16               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT16                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT16  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT16       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT16        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT16                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT32               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT32                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT32  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT32       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT32        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT32                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT64               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT64                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT64  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT64       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT64        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT64                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT8                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT8                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT8 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT8  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT8   STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT8        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT8         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT8                  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT16               STD_OFF
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT16                STD_OFF
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16 STD_ON
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT16 STD_OFF
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT16  STD_OFF
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT16       STD_OFF
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT16        STD_OFF
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT16                 STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT32               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT32                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT32  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT32       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT32        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT32                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT64               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT64                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT64  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT64       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT64        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT64                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8                STD_OFF
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8                 STD_OFF
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8 STD_ON
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8  STD_OFF
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8   STD_OFF
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8        STD_OFF
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8         STD_OFF
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8                  STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8_N              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8_N               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8_N      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8_N       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8_N                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DIRECT_COPYTYPEOFGWDESCRIPTIONACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_RIGHTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_LEFTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_BIG_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_LITTLE_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                       STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                       STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_SINT64_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                     STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                   STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                         STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                     STD_ON
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                  STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFRXACCESSINFO                   STD_ON
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO               STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO              STD_OFF
#define COM_EXISTS_NORMAL_TYPEOFRXPDUINFO                             STD_ON
#define COM_EXISTS_TP_TYPEOFRXPDUINFO                                 STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO            STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO           STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO               STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO              STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFSIGGRPARRAYFILTERINFO           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEVER_FILTERALGOOFSIGGRPARRAYFILTERINFO            STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFSIGGRPARRAYFILTERINFO   STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NONE_FILTERALGOOFSIGGRPARRAYFILTERINFO             STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO             STD_ON
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO           STD_OFF
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                          STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                          STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT64_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                      STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                            STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                        STD_ON
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                     STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXSIGINFO                      STD_OFF
#define COM_EXISTS_NORMAL_MODEOFTXTOUTINFO                            STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_MODEOFTXTOUTINFO                              STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumDefines  Com Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16 0x02U
#define COM_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8 0x02U
#define COM_UINT8_APPLTYPEOFRXACCESSINFO                              0x00U
#define COM_UINT16_APPLTYPEOFRXACCESSINFO                             0x02U
#define COM_UINT32_APPLTYPEOFRXACCESSINFO                             0x04U
#define COM_UINT64_APPLTYPEOFRXACCESSINFO                             0x06U
#define COM_UINT8_N_APPLTYPEOFRXACCESSINFO                            0x08U
#define COM_NBIT_BUSACCOFRXACCESSINFO                                 0x00U
#define COM_BYTE_BUSACCOFRXACCESSINFO                                 0x01U
#define COM_NBYTE_BUSACCOFRXACCESSINFO                                0x02U
#define COM_NBITNBYTE_BUSACCOFRXACCESSINFO                            0x04U
#define COM_ARRAY_BASED_BUSACCOFRXACCESSINFO                          0x06U
#define COM_INACTIVE_RXPDUDMSTATE                                     0x00U
#define COM_ACTIVE_RXPDUDMSTATE                                       0x01U
#define COM_PURE_DM_STATE_MASK_RXPDUDMSTATE                           0x01U
#define COM_OCCURRED_RXPDUDMSTATE                                     0x03U
#define COM_OCCURRED_FLAG_RXPDUDMSTATE                                0x02U
#define COM_CLEAR_OCCURRED_FLAG_RXPDUDMSTATE                          0xFDU
#define COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                      0x00U
#define COM_NORMAL_TYPEOFRXPDUINFO                                    0x00U
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO                   0x00U
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                      0x00U
#define COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                    0x00U
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                 0x00U
#define COM_UINT16_APPLTYPEOFTXSIGINFO                                0x02U
#define COM_UINT32_APPLTYPEOFTXSIGINFO                                0x04U
#define COM_UINT64_APPLTYPEOFTXSIGINFO                                0x06U
#define COM_NBIT_BUSACCOFTXSIGINFO                                    0x00U
#define COM_BYTE_BUSACCOFTXSIGINFO                                    0x01U
#define COM_NBYTE_BUSACCOFTXSIGINFO                                   0x02U
#define COM_NBITNBYTE_BUSACCOFTXSIGINFO                               0x04U
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIsReducedToDefineDefines  Com Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                 STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                 STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTR                                    STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRIND                                 STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASED                                STD_OFF
#define COM_ISDEF_CONSTVALUEUINT16                                    STD_OFF
#define COM_ISDEF_CONSTVALUEUINT32                                    STD_OFF
#define COM_ISDEF_CONSTVALUEUINT64                                    STD_OFF
#define COM_ISDEF_CONSTVALUEUINT8                                     STD_OFF
#define COM_ISDEF_FILTERALGOOFFILTERINFO_UINT16                       STD_OFF
#define COM_ISDEF_FILTERMASKOFFILTERINFO_UINT16                       STD_OFF
#define COM_ISDEF_FILTERMAXOFFILTERINFO_UINT16                        STD_OFF
#define COM_ISDEF_FILTERMINOFFILTERINFO_UINT16                        STD_OFF
#define COM_ISDEF_FILTERXOFFILTERINFO_UINT16                          STD_OFF
#define COM_ISDEF_FILTERALGOOFFILTERINFO_UINT8                        STD_OFF
#define COM_ISDEF_FILTERMASKOFFILTERINFO_UINT8                        STD_OFF
#define COM_ISDEF_FILTERMAXOFFILTERINFO_UINT8                         STD_OFF
#define COM_ISDEF_FILTERMINOFFILTERINFO_UINT8                         STD_OFF
#define COM_ISDEF_FILTERXOFFILTERINFO_UINT8                           STD_OFF
#define COM_ISDEF_PDUGRPVECTOR                                        STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                              STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                           STD_OFF
#define COM_ISDEF_BUFFERIDXOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BUFFERUSEDOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO   STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO   STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO     STD_OFF
#define COM_ISDEF_INITVALUEIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_INITVALUEUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_INVVALUEIDXOFRXACCESSINFO                           STD_OFF
#define COM_ISDEF_INVVALUEUSEDOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_ISGROUPSIGNALOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO     STD_OFF
#define COM_ISDEF_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO    STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO     STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO     STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO   STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO       STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXACCESSINFO                        STD_OFF
#define COM_ISDEF_SHDBUFFERIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_SHDBUFFERUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                STD_OFF
#define COM_ISDEF_TMPBUFFERIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_TMPBUFFERUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_RXACCESSINFOGRPSIGIND                               STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                     STD_OFF
#define COM_ISDEF_RXCBKFUNCPTR                                        STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFRXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                       STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDUSEDOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                          STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                        STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXPDUINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOINDENDIDXOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXTOUTINFOINDUSEDOFRXPDUINFO                        STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXPDUINFO                           STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXPDUINFO                         STD_OFF
#define COM_ISDEF_TYPEOFRXPDUINFO                                     STD_OFF
#define COM_ISDEF_INVEVENTOFRXSIGGRPINFO                              STD_OFF
#define COM_ISDEF_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO           STD_OFF
#define COM_ISDEF_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO         STD_OFF
#define COM_ISDEF_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO             STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                   STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGGRPINFO                         STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_SHDBUFFERREQUIREDOFRXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_STARTBYTEPOSITIONOFRXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGGRPINFO                              STD_OFF
#define COM_ISDEF_RXSIGGRPINFOIND                                     STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                          STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKIDXOFRXSIGINFO                       STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                      STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGINFO                           STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                         STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                 STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO               STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO             STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                 STD_OFF
#define COM_ISDEF_FACTOROFRXTOUTINFO                                  STD_OFF
#define COM_ISDEF_FIRSTFACTOROFRXTOUTINFO                             STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXTOUTINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOIND                                       STD_OFF
#define COM_ISDEF_TXFILTERINITVALUEUINT16                             STD_OFF
#define COM_ISDEF_TXFILTERINITVALUEUINT8                              STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                STD_OFF
#define COM_ISDEF_MINIMUMDELAYOFTXMODEINFO                            STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                           STD_OFF
#define COM_ISDEF_TXMODETRUEUSEDOFTXMODEINFO                          STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO       STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO     STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO         STD_OFF
#define COM_ISDEF_DIRECTOFTXMODETRUE                                  STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                STD_OFF
#define COM_ISDEF_REPCNTOFTXMODETRUE                                  STD_OFF
#define COM_ISDEF_REPPERIODOFTXMODETRUE                               STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                              STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFTXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                               STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXPDUINFO                         STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXPDUINFO                             STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                     STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                       STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDUSEDOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                      STD_OFF
#define COM_ISDEF_PDUOFFSETOFTXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO        STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO            STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO              STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIND                                     STD_OFF
#define COM_ISDEF_TXSIGGRPMASK                                        STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                 STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                   STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_FILTERINITVALUEIDXOFTXSIGINFO                       STD_OFF
#define COM_ISDEF_FILTERINITVALUEUSEDOFTXSIGINFO                      STD_OFF
#define COM_ISDEF_INVVALUEIDXOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_INVVALUEUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_ONCHANGEIDXOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_ONCHANGEUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFTXSIGINFO                   STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGINFO                         STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIDXOFTXSIGINFO                          STD_OFF
#define COM_ISDEF_TXSIGGRPINFOUSEDOFTXSIGINFO                         STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEIND                         STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEIND                                STD_OFF
#define COM_ISDEF_ACTIVATABLERXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_ISDEF_ACTIVATABLETXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDOFPCCONFIG                       STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTROFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEARRAYBASEDOFPCCONFIG                      STD_ON
#define COM_ISDEF_CONSTVALUEUINT16OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEUINT32OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEUINT64OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEUINT8OFPCCONFIG                           STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_ISDEF_DELAYTIMECNTOFPCCONFIG                              STD_ON
#define COM_ISDEF_FILTERINFO_UINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_FILTERINFO_UINT8OFPCCONFIG                          STD_ON
#define COM_ISDEF_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG           STD_ON
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_ISDEF_HANDLETXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                               STD_ON
#define COM_ISDEF_PDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_ISDEF_REPCNTOFPCCONFIG                                    STD_ON
#define COM_ISDEF_REPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_ISDEF_RXACCESSINFOGRPSIGINDOFPCCONFIG                     STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXCBKFUNCPTROFPCCONFIG                              STD_ON
#define COM_ISDEF_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_ISDEF_RXDEFERREDFCTPTRCACHEOFPCCONFIG                     STD_ON
#define COM_ISDEF_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_ISDEF_RXPDUDMSTATEOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_RXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDOFPCCONFIG                     STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT32OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT64OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT8OFPCCONFIG                          STD_ON
#define COM_ISDEF_RXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_RXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXTOUTCNTOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXTOUTINFOINDOFPCCONFIG                             STD_ON
#define COM_ISDEF_RXTOUTINFOOFPCCONFIG                                STD_ON
#define COM_ISDEF_SIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_ISDEF_TMPRXBUFFEROFPCCONFIG                               STD_ON
#define COM_ISDEF_TMPRXSHDBUFFERUINT16OFPCCONFIG                      STD_ON
#define COM_ISDEF_TMPRXSHDBUFFERUINT32OFPCCONFIG                      STD_ON
#define COM_ISDEF_TMPRXSHDBUFFERUINT8OFPCCONFIG                       STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXBUFFEROFPCCONFIG                                  STD_ON
#define COM_ISDEF_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG          STD_ON
#define COM_ISDEF_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_TXFILTERINITVALUEUINT16OFPCCONFIG                   STD_ON
#define COM_ISDEF_TXFILTERINITVALUEUINT8OFPCCONFIG                    STD_ON
#define COM_ISDEF_TXFILTEROLDVALUEUINT16OFPCCONFIG                    STD_ON
#define COM_ISDEF_TXFILTEROLDVALUEUINT8OFPCCONFIG                     STD_ON
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_ISDEF_TXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDOFPCCONFIG               STD_ON
#define COM_ISDEF_TXSIGINFOINVVALUEINDOFPCCONFIG                      STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_WAITINGFORCONFIRMATIONOFPCCONFIG                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEqualsAlwaysToDefines  Com Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                   
#define COM_EQ2_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                   
#define COM_EQ2_CBKRXTOUTFUNCPTR                                      
#define COM_EQ2_CBKRXTOUTFUNCPTRIND                                   
#define COM_EQ2_CONSTVALUEARRAYBASED                                  
#define COM_EQ2_CONSTVALUEUINT16                                      
#define COM_EQ2_CONSTVALUEUINT32                                      
#define COM_EQ2_CONSTVALUEUINT64                                      
#define COM_EQ2_CONSTVALUEUINT8                                       
#define COM_EQ2_FILTERALGOOFFILTERINFO_UINT16                         
#define COM_EQ2_FILTERMASKOFFILTERINFO_UINT16                         
#define COM_EQ2_FILTERMAXOFFILTERINFO_UINT16                          
#define COM_EQ2_FILTERMINOFFILTERINFO_UINT16                          
#define COM_EQ2_FILTERXOFFILTERINFO_UINT16                            
#define COM_EQ2_FILTERALGOOFFILTERINFO_UINT8                          
#define COM_EQ2_FILTERMASKOFFILTERINFO_UINT8                          
#define COM_EQ2_FILTERMAXOFFILTERINFO_UINT8                           
#define COM_EQ2_FILTERMINOFFILTERINFO_UINT8                           
#define COM_EQ2_FILTERXOFFILTERINFO_UINT8                             
#define COM_EQ2_PDUGRPVECTOR                                          
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                               
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                             
#define COM_EQ2_BUFFERIDXOFRXACCESSINFO                               
#define COM_EQ2_BUFFERUSEDOFRXACCESSINFO                              
#define COM_EQ2_BUSACCOFRXACCESSINFO                                  
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                              
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                            
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO     
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO     
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO   
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO       
#define COM_EQ2_INITVALUEIDXOFRXACCESSINFO                            
#define COM_EQ2_INITVALUEUSEDOFRXACCESSINFO                           
#define COM_EQ2_INVVALUEIDXOFRXACCESSINFO                             
#define COM_EQ2_INVVALUEUSEDOFRXACCESSINFO                            
#define COM_EQ2_ISGROUPSIGNALOFRXACCESSINFO                           
#define COM_EQ2_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO       
#define COM_EQ2_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO      
#define COM_EQ2_RXPDUINFOIDXOFRXACCESSINFO                            
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO       
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO       
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO     
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO         
#define COM_EQ2_RXTOUTINFOIDXOFRXACCESSINFO                           
#define COM_EQ2_RXTOUTINFOUSEDOFRXACCESSINFO                          
#define COM_EQ2_SHDBUFFERIDXOFRXACCESSINFO                            
#define COM_EQ2_SHDBUFFERUSEDOFRXACCESSINFO                           
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                  
#define COM_EQ2_TMPBUFFERIDXOFRXACCESSINFO                            
#define COM_EQ2_TMPBUFFERUSEDOFRXACCESSINFO                           
#define COM_EQ2_RXACCESSINFOGRPSIGIND                                 
#define COM_EQ2_RXACCESSINFOIND                                       
#define COM_EQ2_RXCBKFUNCPTR                                          
#define COM_EQ2_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFRXPDUGRPINFO                        
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                     
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                    
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                      
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                    
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                        
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                     
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                         
#define COM_EQ2_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                      
#define COM_EQ2_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                    
#define COM_EQ2_RXSIGGRPINFOINDUSEDOFRXPDUINFO                        
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                            
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                          
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                              
#define COM_EQ2_RXTOUTINFOIDXOFRXPDUINFO                              
#define COM_EQ2_RXTOUTINFOINDENDIDXOFRXPDUINFO                        
#define COM_EQ2_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                      
#define COM_EQ2_RXTOUTINFOINDUSEDOFRXPDUINFO                          
#define COM_EQ2_RXTOUTINFOUSEDOFRXPDUINFO                             
#define COM_EQ2_SIGNALPROCESSINGOFRXPDUINFO                           
#define COM_EQ2_TYPEOFRXPDUINFO                                       
#define COM_EQ2_INVEVENTOFRXSIGGRPINFO                                
#define COM_EQ2_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO             
#define COM_EQ2_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO           
#define COM_EQ2_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO               
#define COM_EQ2_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                      
#define COM_EQ2_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                     
#define COM_EQ2_RXPDUINFOIDXOFRXSIGGRPINFO                            
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGGRPINFO                           
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGGRPINFO                          
#define COM_EQ2_SHDBUFFERREQUIREDOFRXSIGGRPINFO                       
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGGRPINFO                        
#define COM_EQ2_STARTBYTEPOSITIONOFRXSIGGRPINFO                       
#define COM_EQ2_VALIDDLCOFRXSIGGRPINFO                                
#define COM_EQ2_RXSIGGRPINFOIND                                       
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                            
#define COM_EQ2_RXCBKFUNCPTRACKIDXOFRXSIGINFO                         
#define COM_EQ2_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                        
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGINFO                              
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGINFO                             
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                           
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                   
#define COM_EQ2_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                 
#define COM_EQ2_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO               
#define COM_EQ2_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                   
#define COM_EQ2_FACTOROFRXTOUTINFO                                    
#define COM_EQ2_FIRSTFACTOROFRXTOUTINFO                               
#define COM_EQ2_RXPDUINFOIDXOFRXTOUTINFO                              
#define COM_EQ2_RXTOUTINFOIND                                         
#define COM_EQ2_TXFILTERINITVALUEUINT16                               
#define COM_EQ2_TXFILTERINITVALUEUINT8                                
#define COM_EQ2_INITMODEOFTXMODEINFO                                  
#define COM_EQ2_MINIMUMDELAYOFTXMODEINFO                              
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                             
#define COM_EQ2_TXMODETRUEUSEDOFTXMODEINFO                            
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO         
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO       
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO           
#define COM_EQ2_DIRECTOFTXMODETRUE                                    
#define COM_EQ2_PERIODICOFTXMODETRUE                                  
#define COM_EQ2_REPCNTOFTXMODETRUE                                    
#define COM_EQ2_REPPERIODOFTXMODETRUE                                 
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                
#define COM_EQ2_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFTXPDUGRPINFO                        
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                 
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                             
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                      
#define COM_EQ2_TXBUFFERENDIDXOFTXPDUINFO                             
#define COM_EQ2_TXBUFFERLENGTHOFTXPDUINFO                             
#define COM_EQ2_TXBUFFERSTARTIDXOFTXPDUINFO                           
#define COM_EQ2_TXBUFFERUSEDOFTXPDUINFO                               
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                       
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                     
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                         
#define COM_EQ2_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                      
#define COM_EQ2_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                    
#define COM_EQ2_TXSIGGRPINFOINDUSEDOFTXPDUINFO                        
#define COM_EQ2_TXPDUINITVALUE                                        
#define COM_EQ2_PDUOFFSETOFTXSIGGRPINFO                               
#define COM_EQ2_TRANSFERPROPERTYOFTXSIGGRPINFO                        
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGGRPINFO                          
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGGRPINFO                          
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO            
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO            
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO          
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGGRPINFO                        
#define COM_EQ2_TXBUFFERUSEDOFTXSIGGRPINFO                            
#define COM_EQ2_TXPDUINFOIDXOFTXSIGGRPINFO                            
#define COM_EQ2_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                    
#define COM_EQ2_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                        
#define COM_EQ2_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO              
#define COM_EQ2_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO            
#define COM_EQ2_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                
#define COM_EQ2_TXSIGGRPINFOIND                                       
#define COM_EQ2_TXSIGGRPMASK                                          
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                   
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                  
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                
#define COM_EQ2_BUSACCOFTXSIGINFO                                     
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                 
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                               
#define COM_EQ2_FILTERINITVALUEIDXOFTXSIGINFO                         
#define COM_EQ2_FILTERINITVALUEUSEDOFTXSIGINFO                        
#define COM_EQ2_INVVALUEIDXOFTXSIGINFO                                
#define COM_EQ2_INVVALUEUSEDOFTXSIGINFO                               
#define COM_EQ2_ONCHANGEIDXOFTXSIGINFO                                
#define COM_EQ2_ONCHANGEUSEDOFTXSIGINFO                               
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFTXSIGINFO                     
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGINFO                             
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGINFO                             
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGINFO                           
#define COM_EQ2_TXBUFFERUSEDOFTXSIGINFO                               
#define COM_EQ2_TXPDUINFOIDXOFTXSIGINFO                               
#define COM_EQ2_TXSIGGRPINFOIDXOFTXSIGINFO                            
#define COM_EQ2_TXSIGGRPINFOUSEDOFTXSIGINFO                           
#define COM_EQ2_TXSIGINFOFILTERINITVALUEIND                           
#define COM_EQ2_TXSIGINFOINVVALUEIND                                  
#define COM_EQ2_ACTIVATABLERXCOMIPDUSOFPCCONFIG                       Com_ActivatableRxComIPdus
#define COM_EQ2_ACTIVATABLETXCOMIPDUSOFPCCONFIG                       Com_ActivatableTxComIPdus
#define COM_EQ2_CBKRXTOUTFUNCPTRINDOFPCCONFIG                         Com_CbkRxTOutFuncPtrInd
#define COM_EQ2_CBKRXTOUTFUNCPTROFPCCONFIG                            Com_CbkRxTOutFuncPtr
#define COM_EQ2_CONSTVALUEARRAYBASEDOFPCCONFIG                        Com_ConstValueArrayBased
#define COM_EQ2_CONSTVALUEUINT16OFPCCONFIG                            Com_ConstValueUInt16
#define COM_EQ2_CONSTVALUEUINT32OFPCCONFIG                            Com_ConstValueUInt32
#define COM_EQ2_CONSTVALUEUINT64OFPCCONFIG                            Com_ConstValueUInt64
#define COM_EQ2_CONSTVALUEUINT8OFPCCONFIG                             Com_ConstValueUInt8
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                               Com_CurrentTxMode
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                Com_CycleTimeCnt
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                           Com_CyclicSendRequest
#define COM_EQ2_DELAYTIMECNTOFPCCONFIG                                Com_DelayTimeCnt
#define COM_EQ2_FILTERINFO_UINT16OFPCCONFIG                           Com_FilterInfo_UInt16
#define COM_EQ2_FILTERINFO_UINT8OFPCCONFIG                            Com_FilterInfo_UInt8
#define COM_EQ2_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG             Com_GatewayProcessingISRLockCounter
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                         Com_HandleRxPduDeferred.raw
#define COM_EQ2_HANDLETXPDUDEFERREDOFPCCONFIG                         Com_HandleTxPduDeferred
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                 Com_Initialized
#define COM_EQ2_PDUGRPVECTOROFPCCONFIG                                Com_PduGrpVector
#define COM_EQ2_REPCNTOFPCCONFIG                                      Com_RepCnt
#define COM_EQ2_REPCYCLECNTOFPCCONFIG                                 Com_RepCycleCnt
#define COM_EQ2_RXACCESSINFOGRPSIGINDOFPCCONFIG                       Com_RxAccessInfoGrpSigInd
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                             Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                Com_RxAccessInfo
#define COM_EQ2_RXCBKFUNCPTROFPCCONFIG                                Com_RxCbkFuncPtr
#define COM_EQ2_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG          Com_RxDeadlineMonitoringISRLockCounter
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                              Com_RxDefPduBuffer.raw
#define COM_EQ2_RXDEFERREDFCTPTRCACHEOFPCCONFIG                       Com_RxDeferredFctPtrCache
#define COM_EQ2_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG          Com_RxDeferredProcessingISRLockCounter
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                   Com_RxIPduGroupISRLockCounter
#define COM_EQ2_RXPDUDMSTATEOFPCCONFIG                                Com_RxPduDmState
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                              Com_RxPduGrpActive
#define COM_EQ2_RXPDUGRPINFOOFPCCONFIG                                Com_RxPduGrpInfo
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                   Com_RxPduInfo
#define COM_EQ2_RXSIGBUFFERARRAYBASEDOFPCCONFIG                       Com_RxSigBufferArrayBased
#define COM_EQ2_RXSIGBUFFERUINT16OFPCCONFIG                           Com_RxSigBufferUInt16
#define COM_EQ2_RXSIGBUFFERUINT32OFPCCONFIG                           Com_RxSigBufferUInt32
#define COM_EQ2_RXSIGBUFFERUINT64OFPCCONFIG                           Com_RxSigBufferUInt64
#define COM_EQ2_RXSIGBUFFERUINT8OFPCCONFIG                            Com_RxSigBufferUInt8
#define COM_EQ2_RXSIGGRPINFOINDOFPCCONFIG                             Com_RxSigGrpInfoInd
#define COM_EQ2_RXSIGGRPINFOOFPCCONFIG                                Com_RxSigGrpInfo
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                   Com_RxSigInfo
#define COM_EQ2_RXTOUTCNTOFPCCONFIG                                   Com_RxTOutCnt
#define COM_EQ2_RXTOUTINFOINDOFPCCONFIG                               Com_RxTOutInfoInd
#define COM_EQ2_RXTOUTINFOOFPCCONFIG                                  Com_RxTOutInfo
#define COM_EQ2_SIGGRPEVENTFLAGOFPCCONFIG                             Com_SigGrpEventFlag
#define COM_EQ2_TMPRXBUFFEROFPCCONFIG                                 Com_TmpRxBuffer
#define COM_EQ2_TMPRXSHDBUFFERUINT16OFPCCONFIG                        Com_TmpRxShdBufferUInt16
#define COM_EQ2_TMPRXSHDBUFFERUINT32OFPCCONFIG                        Com_TmpRxShdBufferUInt32
#define COM_EQ2_TMPRXSHDBUFFERUINT8OFPCCONFIG                         Com_TmpRxShdBufferUInt8
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                             Com_TransmitRequest
#define COM_EQ2_TXBUFFEROFPCCONFIG                                    Com_TxBuffer
#define COM_EQ2_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG            Com_TxCyclicProcessingISRLockCounter
#define COM_EQ2_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG          Com_TxDeadlineMonitoringISRLockCounter
#define COM_EQ2_TXFILTERINITVALUEUINT16OFPCCONFIG                     Com_TxFilterInitValueUInt16
#define COM_EQ2_TXFILTERINITVALUEUINT8OFPCCONFIG                      Com_TxFilterInitValueUInt8
#define COM_EQ2_TXFILTEROLDVALUEUINT16OFPCCONFIG                      Com_TxFilterOldValueUInt16
#define COM_EQ2_TXFILTEROLDVALUEUINT8OFPCCONFIG                       Com_TxFilterOldValueUInt8
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                   Com_TxIPduGroupISRLockCounter
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                  Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                  Com_TxModeTrue
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                              Com_TxPduGrpActive
#define COM_EQ2_TXPDUGRPINFOOFPCCONFIG                                Com_TxPduGrpInfo
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                   Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                              Com_TxPduInitValue
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                  Com_TxProcessingISRLockCounter
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                 Com_TxSduLength
#define COM_EQ2_TXSIGGRPINFOINDOFPCCONFIG                             Com_TxSigGrpInfoInd
#define COM_EQ2_TXSIGGRPINFOOFPCCONFIG                                Com_TxSigGrpInfo
#define COM_EQ2_TXSIGGRPMASKOFPCCONFIG                                Com_TxSigGrpMask
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDOFPCCONFIG                 Com_TxSigInfoFilterInitValueInd
#define COM_EQ2_TXSIGINFOINVVALUEINDOFPCCONFIG                        Com_TxSigInfoInvValueInd
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                   Com_TxSigInfo
#define COM_EQ2_WAITINGFORCONFIRMATIONOFPCCONFIG                      Com_WaitingForConfirmation
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicInitializationPointers  Com Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCInitializationSymbols  Com Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGeneral  Com General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                        0x321EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                 COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                       -2111758871L  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321EU' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 



/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */
#define COM_IPDUCALLOUT_USEPDUINFOPTR        STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComAdvancedIPduCallouts] */

/* Optimization */
#define COM_RECEIVE_SIGNAL_MACRO_API         STD_OFF

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */
#define COM_GENERATED_DESCRIPTION_ROUTING    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] */

#define COM_LMGT_MAXIPDUGROUPVECTORBYTECNT   2U
#define COM_SUPPORTED_IPDU_GROUPS            13UL  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_ACLNY_COG_1311692d                     0
#define ComConf_ComGroupSignal_ACLNY_COG_ERR_AMP_1311692d             1
#define ComConf_ComGroupSignal_ACLNY_MASSCNTR_dummy_12_15_1311692d    2
#define ComConf_ComGroupSignal_ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b       3
#define ComConf_ComGroupSignal_ALIV_ACLNY_COG_1311692d                4
#define ComConf_ComGroupSignal_ALIV_AVL_RPM_WHL_c59967bf              5
#define ComConf_ComGroupSignal_ALIV_CON_VEH_c1ae6ae9                  6
#define ComConf_ComGroupSignal_ALIV_ENERG_DGR_DRDY_6d50c911           7
#define ComConf_ComGroupSignal_ALIV_ENSU_SFY_db9b6687                 8
#define ComConf_ComGroupSignal_ALIV_OFFS_QUAD_EPS_1a5f7888            9
#define ComConf_ComGroupSignal_ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b       11
#define ComConf_ComGroupSignal_ALIV_TAR_QTA_STMOM_DV_54d7ae59         12
#define ComConf_ComGroupSignal_ALIV_TAR_STMOM_DV_ACT_56e1c987         13
#define ComConf_ComGroupSignal_ALIV_VYAW_VEH_dc9eeb12                 14
#define ComConf_ComGroupSignal_ALIV_V_VEH_579a99a0                    15
#define ComConf_ComGroupSignal_AVL_PO_IDX_ICM_1a5f7888                17
#define ComConf_ComGroupSignal_AVL_RPM_WHL_FLH_c59967bf               18
#define ComConf_ComGroupSignal_AVL_RPM_WHL_FRH_c59967bf               19
#define ComConf_ComGroupSignal_AVL_RPM_WHL_RLH_c59967bf               20
#define ComConf_ComGroupSignal_AVL_RPM_WHL_RRH_c59967bf               21
#define ComConf_ComGroupSignal_AVL_RPM_WHL_dummy_12_15_c59967bf       22
#define ComConf_ComGroupSignal_CHL_ENSU_SFY_db9b6687                  24
#define ComConf_ComGroupSignal_CON_VEH_dummy_56_63_c1ae6ae9           25
#define ComConf_ComGroupSignal_CRC_ACLNY_COG_1311692d                 27
#define ComConf_ComGroupSignal_CRC_AVL_RPM_WHL_c59967bf               28
#define ComConf_ComGroupSignal_CRC_CON_VEH_c1ae6ae9                   29
#define ComConf_ComGroupSignal_CRC_ENERG_DGR_DRDY_6d50c911            30
#define ComConf_ComGroupSignal_CRC_ENSU_SFY_db9b6687                  31
#define ComConf_ComGroupSignal_CRC_OFFS_QUAD_EPS_1a5f7888             32
#define ComConf_ComGroupSignal_CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b        33
#define ComConf_ComGroupSignal_CRC_TAR_QTA_STMOM_DV_54d7ae59          34
#define ComConf_ComGroupSignal_CRC_TAR_STMOM_DV_ACT_56e1c987          35
#define ComConf_ComGroupSignal_CRC_VYAW_VEH_dc9eeb12                  36
#define ComConf_ComGroupSignal_CRC_V_VEH_579a99a0                     37
#define ComConf_ComGroupSignal_CTR_BS_PRTNT_c1ae6ae9                  38
#define ComConf_ComGroupSignal_CTR_DEAC_EPS_FNS_54d7ae59              39
#define ComConf_ComGroupSignal_CTR_FKTN_PRTNT_c1ae6ae9                41
#define ComConf_ComGroupSignal_DVCO_VEH_579a99a0                      45
#define ComConf_ComGroupSignal_ENERG_AVAI_ARS_6d50c911                46
#define ComConf_ComGroupSignal_ENERG_DGR_DRDY_dummy_12_15_6d50c911    47
#define ComConf_ComGroupSignal_ENSU_SFY_dummy_28_31_db9b6687          48
#define ComConf_ComGroupSignal_ENSU_SFY_dummy_32_63_db9b6687          49
#define ComConf_ComGroupSignal_FACT_ASS_STMOM_FTAX_54d7ae59           50
#define ComConf_ComGroupSignal_FACT_CTRR_STMOM_FTAX_54d7ae59          51
#define ComConf_ComGroupSignal_FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987   52
#define ComConf_ComGroupSignal_FACT_DMPNG_STMOM_FTAX_54d7ae59         53
#define ComConf_ComGroupSignal_MAX_I_LD_SPEC_ARS_6d50c911             56
#define ComConf_ComGroupSignal_MAX_I_RECUP_SPEC_ARS_6d50c911          57
#define ComConf_ComGroupSignal_MAX_I_SPEC_BAX_STE_6d50c911            58
#define ComConf_ComGroupSignal_MAX_I_SPEC_EPS_6d50c911                59
#define ComConf_ComGroupSignal_OFFS_QUAD_RTR_EPS_1a5f7888             68
#define ComConf_ComGroupSignal_QU_ACLNY_COG_1311692d                  69
#define ComConf_ComGroupSignal_QU_AVL_RPM_WHL_FLH_c59967bf            70
#define ComConf_ComGroupSignal_QU_AVL_RPM_WHL_FRH_c59967bf            71
#define ComConf_ComGroupSignal_QU_AVL_RPM_WHL_RLH_c59967bf            72
#define ComConf_ComGroupSignal_QU_AVL_RPM_WHL_RRH_c59967bf            73
#define ComConf_ComGroupSignal_QU_DGR_AISP_ENERG_6d50c911             74
#define ComConf_ComGroupSignal_QU_FN_ENSU_SFY_db9b6687                75
#define ComConf_ComGroupSignal_QU_ST_CON_VEH_c1ae6ae9                 77
#define ComConf_ComGroupSignal_QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987 78
#define ComConf_ComGroupSignal_QU_TAR_FACT_STMOM_FTAX_54d7ae59        79
#define ComConf_ComGroupSignal_QU_TAR_QTA_STMOM_DV_54d7ae59           80
#define ComConf_ComGroupSignal_QU_TAR_STMOM_DV_ACT_56e1c987           81
#define ComConf_ComGroupSignal_QU_VYAW_VEH_dc9eeb12                   82
#define ComConf_ComGroupSignal_QU_V_VEH_COG_579a99a0                  83
#define ComConf_ComGroupSignal_RQ_CULI_EST_SFY_6d50c911               84
#define ComConf_ComGroupSignal_RQ_CULI_db9b6687                       85
#define ComConf_ComGroupSignal_ST_CON_VEH_c1ae6ae9                    93
#define ComConf_ComGroupSignal_ST_OFFS_QUAD_EPS_1a5f7888              100
#define ComConf_ComGroupSignal_ST_V_VEH_NSS_579a99a0                  103
#define ComConf_ComGroupSignal_TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b 105
#define ComConf_ComGroupSignal_TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b 106
#define ComConf_ComGroupSignal_TAR_QTA_STMOM_DV_54d7ae59              107
#define ComConf_ComGroupSignal_TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59 108
#define ComConf_ComGroupSignal_TAR_STMOM_DV_ACT_56e1c987              109
#define ComConf_ComGroupSignal_TAR_STMOM_DV_ACT_dummy_12_15_56e1c987  110
#define ComConf_ComGroupSignal_TAR_STMOM_DV_ACT_dummy_32_51_56e1c987  111
#define ComConf_ComGroupSignal_VYAW_VEH_ERR_AMP_dc9eeb12              114
#define ComConf_ComGroupSignal_VYAW_VEH_dc9eeb12                      115
#define ComConf_ComGroupSignal_VYAW_VEH_dummy_12_15_dc9eeb12          116
#define ComConf_ComGroupSignal_V_VEH_COG_579a99a0                     117
#define ComConf_ComGroupSignal_V_VEH_dummy_39_39_579a99a0             118
#define ComConf_ComSignal_ALIV_ST_CENG_43f592b4                       10
#define ComConf_ComSignal_ANFRAGE_ID2_fbd80461_In                     16
#define ComConf_ComSignal_AVL_STEA_PNI_OFFS_9678c0e9                  23
#define ComConf_ComSignal_COU_BS_RESP_d377025e                        26
#define ComConf_ComSignal_CTR_ERRM_BN_U_d46c15e6                      40
#define ComConf_ComSignal_CTR_WARN_DIR_VIB_EPS_66c73f8f               42
#define ComConf_ComSignal_CTR_WARN_ILVL_VIB_EPS_66c73f8f              43
#define ComConf_ComSignal_CTR_WARN_PTRN_VIB_EPS_66c73f8f              44
#define ComConf_ComSignal_FACT_MO_STE_SO_DXP_59dc6376                 54
#define ComConf_ComSignal_ID_FN_INQY_fbd80461_In                      55
#define ComConf_ComSignal_MILE_KM_a6dd5496                            60
#define ComConf_ComSignal_NO_VECH_1_13b7b7e4                          61
#define ComConf_ComSignal_NO_VECH_2_13b7b7e4                          62
#define ComConf_ComSignal_NO_VECH_3_13b7b7e4                          63
#define ComConf_ComSignal_NO_VECH_4_13b7b7e4                          64
#define ComConf_ComSignal_NO_VECH_5_13b7b7e4                          65
#define ComConf_ComSignal_NO_VECH_6_13b7b7e4                          66
#define ComConf_ComSignal_NO_VECH_7_13b7b7e4                          67
#define ComConf_ComSignal_QU_FN_FDR_d5c7d03c                          76
#define ComConf_ComSignal_RQ_RST_OBD_DIAG_DRDY_85fd80d4               86
#define ComConf_ComSignal_SECU_RESP_ID2_d377025e                      87
#define ComConf_ComSignal_SSV_IDENT_RESP_d377025e                     88
#define ComConf_ComSignal_STU_8_BYTE_347be560                         89
#define ComConf_ComSignal_STU_RESP_d377025e                           90
#define ComConf_ComSignal_ST_ANO_MSA_ENG_STOP_43f592b4                91
#define ComConf_ComSignal_ST_CENG_DRV_43f592b4                        92
#define ComConf_ComSignal_ST_ENERG_FZM_e7ce1a0c                       94
#define ComConf_ComSignal_ST_ENERG_SUPY_43f592b4                      95
#define ComConf_ComSignal_ST_ILK_ERRM_FZM_e7ce1a0c                    96
#define ComConf_ComSignal_ST_LDREL_GEN_3319a82a                       97
#define ComConf_ComSignal_ST_MOT_DRV_43f592b4                         98
#define ComConf_ComSignal_ST_OBD_CYC_f0d11ff9                         99
#define ComConf_ComSignal_ST_SEP_STOR_3319a82a                        101
#define ComConf_ComSignal_ST_UDP_43f592b4                             102
#define ComConf_ComSignal_SU_CLU_STMOM_SFE_DXP_59dc6376               104
#define ComConf_ComSignal_TEMP_EX_4b857050                            112
#define ComConf_ComSignal_T_SEC_COU_REL_0b27fbfe                      113
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_ALIV_AVL_FORC_GRD_c0f3c255             0
#define ComConf_ComGroupSignal_ALIV_AVL_PO_EPS_4bf7fe20               1
#define ComConf_ComGroupSignal_ALIV_AVL_STMOM_DV_ACT_3ef6286e         2
#define ComConf_ComGroupSignal_ALIV_DISP_CC_EPS_8a192f9a              3
#define ComConf_ComGroupSignal_ALIV_DT_EST_dcba517d                   4
#define ComConf_ComGroupSignal_ALIV_ST_EST_FTAX_eef8e21d              6
#define ComConf_ComGroupSignal_ALIV_SU_EPS_f544de28                   7
#define ComConf_ComGroupSignal_AVL_FORC_GRD_c0f3c255                  9
#define ComConf_ComGroupSignal_AVL_FORC_GRD_dummy_12_15_c0f3c255      10
#define ComConf_ComGroupSignal_AVL_I_ACT_EST_dcba517d                 11
#define ComConf_ComGroupSignal_AVL_PO_EPS_4bf7fe20                    12
#define ComConf_ComGroupSignal_AVL_PO_IDX_EPS_4bf7fe20                13
#define ComConf_ComGroupSignal_AVL_PWR_EL_EPS_COOD_c0f3c255           14
#define ComConf_ComGroupSignal_AVL_STMOM_DV_ACT_3ef6286e              15
#define ComConf_ComGroupSignal_AVL_STMOM_DV_ACT_dummy_12_15_3ef6286e  16
#define ComConf_ComGroupSignal_CHL_DISP_CC_EPS_8a192f9a               18
#define ComConf_ComGroupSignal_CRC_AVL_FORC_GRD_c0f3c255              19
#define ComConf_ComGroupSignal_CRC_AVL_PO_EPS_4bf7fe20                20
#define ComConf_ComGroupSignal_CRC_AVL_STMOM_DV_ACT_3ef6286e          21
#define ComConf_ComGroupSignal_CRC_DISP_CC_EPS_8a192f9a               22
#define ComConf_ComGroupSignal_CRC_DT_EST_dcba517d                    23
#define ComConf_ComGroupSignal_CRC_ST_EST_FTAX_eef8e21d               24
#define ComConf_ComGroupSignal_CRC_SU_EPS_f544de28                    25
#define ComConf_ComGroupSignal_DT_EST_dummy_12_15_dcba517d            37
#define ComConf_ComGroupSignal_DT_EST_dummy_16_47_dcba517d            38
#define ComConf_ComGroupSignal_DT_EST_dummy_64_95_dcba517d            39
#define ComConf_ComGroupSignal_DT_EST_dummy_96_127_dcba517d           40
#define ComConf_ComGroupSignal_IDX_TORQ_SEN_4bf7fe20                  43
#define ComConf_ComGroupSignal_NO_CC_EPS_8a192f9a                     53
#define ComConf_ComGroupSignal_OFFS_GRD_MID_EPS_4bf7fe20              54
#define ComConf_ComGroupSignal_QU_AVL_FORC_GRD_c0f3c255               56
#define ComConf_ComGroupSignal_QU_AVL_I_ACT_EST_dcba517d              57
#define ComConf_ComGroupSignal_QU_AVL_PO_EPS_4bf7fe20                 58
#define ComConf_ComGroupSignal_QU_AVL_STMOM_DV_ACT_3ef6286e           59
#define ComConf_ComGroupSignal_QU_FN_EST_eef8e21d                     60
#define ComConf_ComGroupSignal_QU_FN_VIB_EPS_eef8e21d                 61
#define ComConf_ComGroupSignal_QU_SER_STMOM_DV_ACT_eef8e21d           62
#define ComConf_ComGroupSignal_ST_CC_EPS_8a192f9a                     70
#define ComConf_ComGroupSignal_ST_CULI_EST_dcba517d                   72
#define ComConf_ComGroupSignal_ST_EST_dummy_16_23_eef8e21d            75
#define ComConf_ComGroupSignal_ST_IDC_CC_EPS_8a192f9a                 76
#define ComConf_ComGroupSignal_SU_EPS_dummy_14_19_f544de28            77
#define ComConf_ComGroupSignal_SU_EPS_dummy_20_51_f544de28            78
#define ComConf_ComGroupSignal_TOT_STR_EPS_f544de28                   81
#define ComConf_ComGroupSignal_TRANF_CC_EPS_8a192f9a                  82
#define ComConf_ComGroupSignal_UN_PO_EPS_4bf7fe20                     84
#define ComConf_ComGroupSignal_UN_TOT_STR_EPS_f544de28                85
#define ComConf_ComSignal_ALIV_ST_DIAG_OBD_3_DRDY_65e49c1b            5
#define ComConf_ComSignal_ANFRAGE_ID2_fbd80461_Out                    8
#define ComConf_ComSignal_BATT_VLTG_EPS_df324712                      17
#define ComConf_ComSignal_DBG_EPS_BS_MOD_58_BYTE_ID2_df324712         26
#define ComConf_ComSignal_DBG_EPS_MOD_EXT_120_BYTE_58e47270           27
#define ComConf_ComSignal_DBG_EPS_MOD_EXT_120_BYTE_ID2_58e47270       28
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_1_65e49c1b               29
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_2_65e49c1b               30
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_3_65e49c1b               31
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_4_65e49c1b               32
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_5_65e49c1b               33
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_6_65e49c1b               34
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_7_65e49c1b               35
#define ComConf_ComSignal_DIAG_ST_OBD_3_DRDY_8_65e49c1b               36
#define ComConf_ComSignal_ECU_TEMP_EPS_df324712                       41
#define ComConf_ComSignal_ESTIMD_PEAK_MOT_CURR_EPS_df324712           42
#define ComConf_ComSignal_ID_FN_INQY_fbd80461_Out                     44
#define ComConf_ComSignal_ID_FN_RQ_STG_EFAN_862c1b6d                  45
#define ComConf_ComSignal_ID_TEMP_CPO_HET_MNG_862c1b6d                46
#define ComConf_ComSignal_MOT_FET_TEMP_EPS_df324712                   47
#define ComConf_ComSignal_MOT_MAG_TEMP_EPS_df324712                   48
#define ComConf_ComSignal_MOT_TQ_CMD_EPS_df324712                     49
#define ComConf_ComSignal_MOT_TQ_CMD_LIMD_EPS_df324712                50
#define ComConf_ComSignal_MOT_VEL_EPS_df324712                        51
#define ComConf_ComSignal_MOT_WIDG_TEMP_EPS_df324712                  52
#define ComConf_ComSignal_PRIM_HW_TQ_SNSR_VLTG_EPS_df324712           55
#define ComConf_ComSignal_RQ_STG_EFAN_862c1b6d                        63
#define ComConf_ComSignal_RQ_STG_EFAN_ID2_862c1b6d                    64
#define ComConf_ComSignal_SECDRY_HW_TQ_SNSR_VLTG_EPS_df324712         65
#define ComConf_ComSignal_SECU_CHAL_5fff8d6b                          66
#define ComConf_ComSignal_SECU_CHAL_ID2_5fff8d6b                      67
#define ComConf_ComSignal_SSS_IDENT_CHAL_5fff8d6b                     68
#define ComConf_ComSignal_SSV_IDENT_CHAL_5fff8d6b                     69
#define ComConf_ComSignal_ST_CON_VEH_EPS_df324712                     71
#define ComConf_ComSignal_ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1b        73
#define ComConf_ComSignal_ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b         74
#define ComConf_ComSignal_SYS_ST_EPS_df324712                         79
#define ComConf_ComSignal_TEMP_CPO_HET_MNG_862c1b6d                   80
#define ComConf_ComSignal_TRGG_ENGTORQ_EPS_4e565a26                   83
#define ComConf_ComSignal_VEH_SPD_EPS_df324712                        86
/**\} */




/**
 * \defgroup ComHandleIdscomRxSigGrp Handle IDs of handle space comRxSigGrp.
 * \brief Rx SignalGroups
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_sigGroup_ACLNY_MASSCNTR_461c64b1       0
#define ComConf_ComSignalGroup_sigGroup_AVL_RPM_WHL_eba9ae07          1
#define ComConf_ComSignalGroup_sigGroup_CON_VEH_675e7344              2
#define ComConf_ComSignalGroup_sigGroup_ENERG_DGR_DRDY_3f76efd3       3
#define ComConf_ComSignalGroup_sigGroup_ENSU_SFY_dfa36b36             4
#define ComConf_ComSignalGroup_sigGroup_OFFS_QUAD_EPS_cc150a52        5
#define ComConf_ComSignalGroup_sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c   6
#define ComConf_ComSignalGroup_sigGroup_TAR_QTA_STRMOM_DV_231dfb08    7
#define ComConf_ComSignalGroup_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3     8
#define ComConf_ComSignalGroup_sigGroup_VYAW_VEH_fc66be94             9
#define ComConf_ComSignalGroup_sigGroup_V_VEH_2fe00c20                10
/**\} */

/**
 * \defgroup ComHandleIdscomTxSigGrp Handle IDs of handle space comTxSigGrp.
 * \brief Tx SignalGroups
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_sigGroup_AVL_FORC_GRD_19621f3f         0
#define ComConf_ComSignalGroup_sigGroup_AVL_PO_EPS_290f0f6e           1
#define ComConf_ComSignalGroup_sigGroup_AVL_STMOM_DV_ACT_744f32e2     2
#define ComConf_ComSignalGroup_sigGroup_DISP_CC_EPS_ad160a0a          3
#define ComConf_ComSignalGroup_sigGroup_DT_EST_68b5ac35               4
#define ComConf_ComSignalGroup_sigGroup_ST_EST_76669e16               5
#define ComConf_ComSignalGroup_sigGroup_SU_EPS_fe4f71c6               6
/**\} */




/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_EPS_IN_PduGroup                          1
#define ComConf_ComIPduGroup_EPS_IN_PduGroup2                         2
#define ComConf_ComIPduGroup_EPS_IN_PduGroup3                         3
#define ComConf_ComIPduGroup_EPS_IN_PduGroup4                         4
#define ComConf_ComIPduGroup_EPS_IN_PduGroup5                         5
#define ComConf_ComIPduGroup_EPS_IN_PduGroup6                         6
#define ComConf_ComIPduGroup_EPS_IN_PduGroup7                         7
#define ComConf_ComIPduGroup_EPS_IN_PduGroup8                         8
#define ComConf_ComIPduGroup_EPS_IN_PduGroup9                         9
#define ComConf_ComIPduGroup_EPS_IN_PduGroup10                        10
#define ComConf_ComIPduGroup_EPS_OUT_PduGroup                         11
#define ComConf_ComIPduGroup_EPS_OUT_PduGroup2                        12
#define ComConf_ComIPduGroup_EPS_OUT_PduGroup3                        0
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCGetConstantDuplicatedRootDataMacros  Com Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Com_GetActivatableRxComIPdusOfPCConfig()                      Com_ActivatableRxComIPdus  /**< the pointer to Com_ActivatableRxComIPdus */
#define Com_GetActivatableTxComIPdusOfPCConfig()                      Com_ActivatableTxComIPdus  /**< the pointer to Com_ActivatableTxComIPdus */
#define Com_GetCbkRxTOutFuncPtrIndOfPCConfig()                        Com_CbkRxTOutFuncPtrInd  /**< the pointer to Com_CbkRxTOutFuncPtrInd */
#define Com_GetCbkRxTOutFuncPtrOfPCConfig()                           Com_CbkRxTOutFuncPtr  /**< the pointer to Com_CbkRxTOutFuncPtr */
#define Com_GetConfigIdOfPCConfig()                                   0UL  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueArrayBasedOfPCConfig()                       Com_ConstValueArrayBased  /**< the pointer to Com_ConstValueArrayBased */
#define Com_GetConstValueUInt16OfPCConfig()                           Com_ConstValueUInt16  /**< the pointer to Com_ConstValueUInt16 */
#define Com_GetConstValueUInt32OfPCConfig()                           Com_ConstValueUInt32  /**< the pointer to Com_ConstValueUInt32 */
#define Com_GetConstValueUInt64OfPCConfig()                           Com_ConstValueUInt64  /**< the pointer to Com_ConstValueUInt64 */
#define Com_GetConstValueUInt8OfPCConfig()                            Com_ConstValueUInt8  /**< the pointer to Com_ConstValueUInt8 */
#define Com_GetCurrentTxModeOfPCConfig()                              Com_CurrentTxMode  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                               Com_CycleTimeCnt  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                          Com_CyclicSendRequest  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetDelayTimeCntOfPCConfig()                               Com_DelayTimeCnt  /**< the pointer to Com_DelayTimeCnt */
#define Com_GetFilterInfo_UInt16OfPCConfig()                          Com_FilterInfo_UInt16  /**< the pointer to Com_FilterInfo_UInt16 */
#define Com_GetFilterInfo_UInt8OfPCConfig()                           Com_FilterInfo_UInt8  /**< the pointer to Com_FilterInfo_UInt8 */
#define Com_GetGatewayProcessingISRLockCounterOfPCConfig()            Com_GatewayProcessingISRLockCounter  /**< the pointer to Com_GatewayProcessingISRLockCounter */
#define Com_GetHandleRxPduDeferredOfPCConfig()                        Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetHandleTxPduDeferredOfPCConfig()                        Com_HandleTxPduDeferred  /**< the pointer to Com_HandleTxPduDeferred */
#define Com_GetInitializedOfPCConfig()                                Com_Initialized  /**< the pointer to Com_Initialized */
#define Com_GetPduGrpCntOfPCConfig()                                  13UL
#define Com_GetPduGrpVectorOfPCConfig()                               Com_PduGrpVector  /**< the pointer to Com_PduGrpVector */
#define Com_GetRepCntOfPCConfig()                                     Com_RepCnt  /**< the pointer to Com_RepCnt */
#define Com_GetRepCycleCntOfPCConfig()                                Com_RepCycleCnt  /**< the pointer to Com_RepCycleCnt */
#define Com_GetRxAccessInfoGrpSigIndOfPCConfig()                      Com_RxAccessInfoGrpSigInd  /**< the pointer to Com_RxAccessInfoGrpSigInd */
#define Com_GetRxAccessInfoIndOfPCConfig()                            Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                               Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxCbkFuncPtrOfPCConfig()                               Com_RxCbkFuncPtr  /**< the pointer to Com_RxCbkFuncPtr */
#define Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig()         Com_RxDeadlineMonitoringISRLockCounter  /**< the pointer to Com_RxDeadlineMonitoringISRLockCounter */
#define Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()       1U
#define Com_GetRxDefPduBufferOfPCConfig()                             Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxDeferredFctPtrCacheOfPCConfig()                      Com_RxDeferredFctPtrCache  /**< the pointer to Com_RxDeferredFctPtrCache */
#define Com_GetRxDeferredProcessingISRLockCounterOfPCConfig()         Com_RxDeferredProcessingISRLockCounter  /**< the pointer to Com_RxDeferredProcessingISRLockCounter */
#define Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()       1U
#define Com_GetRxIPduGroupISRLockCounterOfPCConfig()                  Com_RxIPduGroupISRLockCounter  /**< the pointer to Com_RxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockThresholdOfPCConfig()                1U
#define Com_GetRxPduDmStateOfPCConfig()                               Com_RxPduDmState  /**< the pointer to Com_RxPduDmState */
#define Com_GetRxPduGrpActiveOfPCConfig()                             Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduGrpInfoOfPCConfig()                               Com_RxPduGrpInfo  /**< the pointer to Com_RxPduGrpInfo */
#define Com_GetRxPduInfoOfPCConfig()                                  Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxSigBufferArrayBasedOfPCConfig()                      Com_RxSigBufferArrayBased  /**< the pointer to Com_RxSigBufferArrayBased */
#define Com_GetRxSigBufferUInt16OfPCConfig()                          Com_RxSigBufferUInt16  /**< the pointer to Com_RxSigBufferUInt16 */
#define Com_GetRxSigBufferUInt32OfPCConfig()                          Com_RxSigBufferUInt32  /**< the pointer to Com_RxSigBufferUInt32 */
#define Com_GetRxSigBufferUInt64OfPCConfig()                          Com_RxSigBufferUInt64  /**< the pointer to Com_RxSigBufferUInt64 */
#define Com_GetRxSigBufferUInt8OfPCConfig()                           Com_RxSigBufferUInt8  /**< the pointer to Com_RxSigBufferUInt8 */
#define Com_GetRxSigGrpInfoIndOfPCConfig()                            Com_RxSigGrpInfoInd  /**< the pointer to Com_RxSigGrpInfoInd */
#define Com_GetRxSigGrpInfoOfPCConfig()                               Com_RxSigGrpInfo  /**< the pointer to Com_RxSigGrpInfo */
#define Com_GetRxSigInfoOfPCConfig()                                  Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetRxTOutCntOfPCConfig()                                  Com_RxTOutCnt  /**< the pointer to Com_RxTOutCnt */
#define Com_GetRxTOutInfoIndOfPCConfig()                              Com_RxTOutInfoInd  /**< the pointer to Com_RxTOutInfoInd */
#define Com_GetRxTOutInfoOfPCConfig()                                 Com_RxTOutInfo  /**< the pointer to Com_RxTOutInfo */
#define Com_GetSigGrpEventFlagOfPCConfig()                            Com_SigGrpEventFlag  /**< the pointer to Com_SigGrpEventFlag */
#define Com_GetSizeOfActivatableRxComIPdusOfPCConfig()                28U  /**< the number of accomplishable value elements in Com_ActivatableRxComIPdus */
#define Com_GetSizeOfActivatableTxComIPdusOfPCConfig()                14U  /**< the number of accomplishable value elements in Com_ActivatableTxComIPdus */
#define Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                  17U  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtrInd */
#define Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()                     17U  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtr */
#define Com_GetSizeOfConstValueArrayBasedOfPCConfig()                 1U  /**< the number of accomplishable value elements in Com_ConstValueArrayBased */
#define Com_GetSizeOfConstValueUInt16OfPCConfig()                     4U  /**< the number of accomplishable value elements in Com_ConstValueUInt16 */
#define Com_GetSizeOfConstValueUInt32OfPCConfig()                     4U  /**< the number of accomplishable value elements in Com_ConstValueUInt32 */
#define Com_GetSizeOfConstValueUInt64OfPCConfig()                     2U  /**< the number of accomplishable value elements in Com_ConstValueUInt64 */
#define Com_GetSizeOfConstValueUInt8OfPCConfig()                      7U  /**< the number of accomplishable value elements in Com_ConstValueUInt8 */
#define Com_GetSizeOfFilterInfo_UInt16OfPCConfig()                    1U  /**< the number of accomplishable value elements in Com_FilterInfo_UInt16 */
#define Com_GetSizeOfFilterInfo_UInt8OfPCConfig()                     1U  /**< the number of accomplishable value elements in Com_FilterInfo_UInt8 */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                  28U  /**< the number of accomplishable value elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfPduGrpVectorOfPCConfig()                         13U  /**< the number of accomplishable value elements in Com_PduGrpVector */
#define Com_GetSizeOfRxAccessInfoGrpSigIndOfPCConfig()                82U  /**< the number of accomplishable value elements in Com_RxAccessInfoGrpSigInd */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                      119U  /**< the number of accomplishable value elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                         119U  /**< the number of accomplishable value elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxCbkFuncPtrOfPCConfig()                         19U  /**< the number of accomplishable value elements in Com_RxCbkFuncPtr */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                       196U  /**< the number of accomplishable value elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()                3U  /**< the number of accomplishable value elements in Com_RxDeferredFctPtrCache */
#define Com_GetSizeOfRxPduGrpInfoOfPCConfig()                         28U  /**< the number of accomplishable value elements in Com_RxPduGrpInfo */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                            28U  /**< the number of accomplishable value elements in Com_RxPduInfo */
#define Com_GetSizeOfRxSigBufferArrayBasedOfPCConfig()                7U  /**< the number of accomplishable value elements in Com_RxSigBufferArrayBased */
#define Com_GetSizeOfRxSigBufferUInt16OfPCConfig()                    28U  /**< the number of accomplishable value elements in Com_RxSigBufferUInt16 */
#define Com_GetSizeOfRxSigBufferUInt32OfPCConfig()                    14U  /**< the number of accomplishable value elements in Com_RxSigBufferUInt32 */
#define Com_GetSizeOfRxSigBufferUInt64OfPCConfig()                    1U  /**< the number of accomplishable value elements in Com_RxSigBufferUInt64 */
#define Com_GetSizeOfRxSigBufferUInt8OfPCConfig()                     151U  /**< the number of accomplishable value elements in Com_RxSigBufferUInt8 */
#define Com_GetSizeOfRxSigGrpInfoIndOfPCConfig()                      11U  /**< the number of accomplishable value elements in Com_RxSigGrpInfoInd */
#define Com_GetSizeOfRxSigGrpInfoOfPCConfig()                         11U  /**< the number of accomplishable value elements in Com_RxSigGrpInfo */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                            37U  /**< the number of accomplishable value elements in Com_RxSigInfo */
#define Com_GetSizeOfRxTOutInfoIndOfPCConfig()                        13U  /**< the number of accomplishable value elements in Com_RxTOutInfoInd */
#define Com_GetSizeOfRxTOutInfoOfPCConfig()                           13U  /**< the number of accomplishable value elements in Com_RxTOutInfo */
#define Com_GetSizeOfTmpRxBufferOfPCConfig()                          8U  /**< the number of accomplishable value elements in Com_TmpRxBuffer */
#define Com_GetSizeOfTmpRxShdBufferUInt16OfPCConfig()                 4U  /**< the number of accomplishable value elements in Com_TmpRxShdBufferUInt16 */
#define Com_GetSizeOfTmpRxShdBufferUInt32OfPCConfig()                 2U  /**< the number of accomplishable value elements in Com_TmpRxShdBufferUInt32 */
#define Com_GetSizeOfTmpRxShdBufferUInt8OfPCConfig()                  10U  /**< the number of accomplishable value elements in Com_TmpRxShdBufferUInt8 */
#define Com_GetSizeOfTxBufferOfPCConfig()                             258U  /**< the number of accomplishable value elements in Com_TxBuffer */
#define Com_GetSizeOfTxFilterInitValueUInt16OfPCConfig()              1U  /**< the number of accomplishable value elements in Com_TxFilterInitValueUInt16 */
#define Com_GetSizeOfTxFilterInitValueUInt8OfPCConfig()               20U  /**< the number of accomplishable value elements in Com_TxFilterInitValueUInt8 */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                           14U  /**< the number of accomplishable value elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                           8U  /**< the number of accomplishable value elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduGrpInfoOfPCConfig()                         14U  /**< the number of accomplishable value elements in Com_TxPduGrpInfo */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                            14U  /**< the number of accomplishable value elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                       207U  /**< the number of accomplishable value elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()                      7U  /**< the number of accomplishable value elements in Com_TxSigGrpInfoInd */
#define Com_GetSizeOfTxSigGrpInfoOfPCConfig()                         7U  /**< the number of accomplishable value elements in Com_TxSigGrpInfo */
#define Com_GetSizeOfTxSigGrpMaskOfPCConfig()                         16U  /**< the number of accomplishable value elements in Com_TxSigGrpMask */
#define Com_GetSizeOfTxSigInfoFilterInitValueIndOfPCConfig()          21U  /**< the number of accomplishable value elements in Com_TxSigInfoFilterInitValueInd */
#define Com_GetSizeOfTxSigInfoInvValueIndOfPCConfig()                 31U  /**< the number of accomplishable value elements in Com_TxSigInfoInvValueInd */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                            87U  /**< the number of accomplishable value elements in Com_TxSigInfo */
#define Com_GetTmpRxBufferOfPCConfig()                                Com_TmpRxBuffer  /**< the pointer to Com_TmpRxBuffer */
#define Com_GetTmpRxShdBufferUInt16OfPCConfig()                       Com_TmpRxShdBufferUInt16  /**< the pointer to Com_TmpRxShdBufferUInt16 */
#define Com_GetTmpRxShdBufferUInt32OfPCConfig()                       Com_TmpRxShdBufferUInt32  /**< the pointer to Com_TmpRxShdBufferUInt32 */
#define Com_GetTmpRxShdBufferUInt8OfPCConfig()                        Com_TmpRxShdBufferUInt8  /**< the pointer to Com_TmpRxShdBufferUInt8 */
#define Com_GetTransmitRequestOfPCConfig()                            Com_TransmitRequest  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxBufferOfPCConfig()                                   Com_TxBuffer  /**< the pointer to Com_TxBuffer */
#define Com_GetTxCyclicProcessingISRLockCounterOfPCConfig()           Com_TxCyclicProcessingISRLockCounter  /**< the pointer to Com_TxCyclicProcessingISRLockCounter */
#define Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()         1U
#define Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig()         Com_TxDeadlineMonitoringISRLockCounter  /**< the pointer to Com_TxDeadlineMonitoringISRLockCounter */
#define Com_GetTxFilterInitValueUInt16OfPCConfig()                    Com_TxFilterInitValueUInt16  /**< the pointer to Com_TxFilterInitValueUInt16 */
#define Com_GetTxFilterInitValueUInt8OfPCConfig()                     Com_TxFilterInitValueUInt8  /**< the pointer to Com_TxFilterInitValueUInt8 */
#define Com_GetTxFilterOldValueUInt16OfPCConfig()                     Com_TxFilterOldValueUInt16  /**< the pointer to Com_TxFilterOldValueUInt16 */
#define Com_GetTxFilterOldValueUInt8OfPCConfig()                      Com_TxFilterOldValueUInt8  /**< the pointer to Com_TxFilterOldValueUInt8 */
#define Com_GetTxIPduGroupISRLockCounterOfPCConfig()                  Com_TxIPduGroupISRLockCounter  /**< the pointer to Com_TxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockThresholdOfPCConfig()                1U
#define Com_GetTxModeInfoOfPCConfig()                                 Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                 Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduGrpActiveOfPCConfig()                             Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduGrpInfoOfPCConfig()                               Com_TxPduGrpInfo  /**< the pointer to Com_TxPduGrpInfo */
#define Com_GetTxPduInfoOfPCConfig()                                  Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                             Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxProcessingISRLockCounterOfPCConfig()                 Com_TxProcessingISRLockCounter  /**< the pointer to Com_TxProcessingISRLockCounter */
#define Com_GetTxProcessingISRLockThresholdOfPCConfig()               1U
#define Com_GetTxSduLengthOfPCConfig()                                Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxSigGrpInfoIndOfPCConfig()                            Com_TxSigGrpInfoInd  /**< the pointer to Com_TxSigGrpInfoInd */
#define Com_GetTxSigGrpInfoOfPCConfig()                               Com_TxSigGrpInfo  /**< the pointer to Com_TxSigGrpInfo */
#define Com_GetTxSigGrpMaskOfPCConfig()                               Com_TxSigGrpMask  /**< the pointer to Com_TxSigGrpMask */
#define Com_GetTxSigInfoFilterInitValueIndOfPCConfig()                Com_TxSigInfoFilterInitValueInd  /**< the pointer to Com_TxSigInfoFilterInitValueInd */
#define Com_GetTxSigInfoInvValueIndOfPCConfig()                       Com_TxSigInfoInvValueInd  /**< the pointer to Com_TxSigInfoInvValueInd */
#define Com_GetTxSigInfoOfPCConfig()                                  Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
#define Com_GetWaitingForConfirmationOfPCConfig()                     Com_WaitingForConfirmation  /**< the pointer to Com_WaitingForConfirmation */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDuplicatedRootDataMacros  Com Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                        Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                         Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                    Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CyclicSendRequest */
#define Com_GetSizeOfDelayTimeCntOfPCConfig()                         Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_DelayTimeCnt */
#define Com_GetSizeOfHandleTxPduDeferredOfPCConfig()                  Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_HandleTxPduDeferred */
#define Com_GetSizeOfRepCntOfPCConfig()                               Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RepCnt */
#define Com_GetSizeOfRepCycleCntOfPCConfig()                          Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RepCycleCnt */
#define Com_GetSizeOfRxPduDmStateOfPCConfig()                         Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduDmState */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                       Com_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduGrpActive */
#define Com_GetSizeOfRxTOutCntOfPCConfig()                            Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxTOutCnt */
#define Com_GetSizeOfSigGrpEventFlagOfPCConfig()                      Com_GetSizeOfTxSigGrpInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_SigGrpEventFlag */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                      Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TransmitRequest */
#define Com_GetSizeOfTxFilterOldValueUInt16OfPCConfig()               Com_GetSizeOfTxFilterInitValueUInt16OfPCConfig()  /**< the number of accomplishable value elements in Com_TxFilterOldValueUInt16 */
#define Com_GetSizeOfTxFilterOldValueUInt8OfPCConfig()                Com_GetSizeOfTxFilterInitValueUInt8OfPCConfig()  /**< the number of accomplishable value elements in Com_TxFilterOldValueUInt8 */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                       Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                          Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxSduLength */
#define Com_GetSizeOfWaitingForConfirmationOfPCConfig()               Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_WaitingForConfirmation */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDataMacros  Com Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetCbkRxTOutFuncPtr(Index)                                (Com_GetCbkRxTOutFuncPtrOfPCConfig()[(Index)])
#define Com_GetConstValueArrayBased(Index)                            (Com_GetConstValueArrayBasedOfPCConfig()[(Index)])
#define Com_GetConstValueUInt16(Index)                                (Com_GetConstValueUInt16OfPCConfig()[(Index)])
#define Com_GetConstValueUInt32(Index)                                (Com_GetConstValueUInt32OfPCConfig()[(Index)])
#define Com_GetConstValueUInt64(Index)                                (Com_GetConstValueUInt64OfPCConfig()[(Index)])
#define Com_GetConstValueUInt8(Index)                                 (Com_GetConstValueUInt8OfPCConfig()[(Index)])
#define Com_IsCurrentTxMode(Index)                                    ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                    (Com_GetCycleTimeCntOfPCConfig()[(Index)])
#define Com_IsCyclicSendRequest(Index)                                ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetDelayTimeCnt(Index)                                    (Com_GetDelayTimeCntOfPCConfig()[(Index)])
#define Com_GetGatewayProcessingISRLockCounter()                      (Com_GetGatewayProcessingISRLockCounterOfPCConfig())
#define Com_GetHandleRxPduDeferred(Index)                             (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)])
#define Com_IsHandleTxPduDeferred(Index)                              ((Com_GetHandleTxPduDeferredOfPCConfig()[(Index)]) != FALSE)
#define Com_IsInitialized()                                           ((Com_GetInitializedOfPCConfig()) != FALSE)
#define Com_GetPduGrpVector(Index)                                    (Com_GetPduGrpVectorOfPCConfig()[(Index)])
#define Com_GetRepCnt(Index)                                          (Com_GetRepCntOfPCConfig()[(Index)])
#define Com_GetRepCycleCnt(Index)                                     (Com_GetRepCycleCntOfPCConfig()[(Index)])
#define Com_GetApplTypeOfRxAccessInfo(Index)                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo)
#define Com_GetBitLengthOfRxAccessInfo(Index)                         (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitLengthOfRxAccessInfo)
#define Com_GetBitPositionOfRxAccessInfo(Index)                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitPositionOfRxAccessInfo)
#define Com_GetBufferIdxOfRxAccessInfo(Index)                         (Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferIdxOfRxAccessInfo)
#define Com_GetBusAccOfRxAccessInfo(Index)                            (Com_GetRxAccessInfoOfPCConfig()[(Index)].BusAccOfRxAccessInfo)
#define Com_GetByteLengthOfRxAccessInfo(Index)                        (Com_GetRxAccessInfoOfPCConfig()[(Index)].ByteLengthOfRxAccessInfo)
#define Com_GetConstValueArrayBasedInitValueEndIdxOfRxAccessInfo(Index) (Com_GetRxAccessInfoOfPCConfig()[(Index)].ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo)
#define Com_GetConstValueArrayBasedInitValueStartIdxOfRxAccessInfo(Index) (Com_GetRxAccessInfoOfPCConfig()[(Index)].ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo)
#define Com_IsInitValueUsedOfRxAccessInfo(Index)                      ((Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueUsedOfRxAccessInfo) != FALSE)
#define Com_GetInvValueIdxOfRxAccessInfo(Index)                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].InvValueIdxOfRxAccessInfo)
#define Com_GetRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo(Index) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo)
#define Com_GetRxPduInfoIdxOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxAccessInfo)
#define Com_GetRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo(Index) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo)
#define Com_GetRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo(Index) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo)
#define Com_IsRxSigBufferArrayBasedBufferUsedOfRxAccessInfo(Index)    ((Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferUsedOfRxAccessInfo) != FALSE)
#define Com_GetRxTOutInfoIdxOfRxAccessInfo(Index)                     (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxAccessInfo)
#define Com_GetShdBufferIdxOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].ShdBufferIdxOfRxAccessInfo)
#define Com_IsShdBufferUsedOfRxAccessInfo(Index)                      ((Com_GetRxAccessInfoOfPCConfig()[(Index)].ShdBufferUsedOfRxAccessInfo) != FALSE)
#define Com_GetStartByteInPduPositionOfRxAccessInfo(Index)            (Com_GetRxAccessInfoOfPCConfig()[(Index)].StartByteInPduPositionOfRxAccessInfo)
#define Com_GetTmpBufferIdxOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].TmpBufferIdxOfRxAccessInfo)
#define Com_GetRxAccessInfoGrpSigInd(Index)                           (Com_GetRxAccessInfoGrpSigIndOfPCConfig()[(Index)])
#define Com_GetRxAccessInfoInd(Index)                                 (Com_GetRxAccessInfoIndOfPCConfig()[(Index)])
#define Com_GetRxCbkFuncPtr(Index)                                    (Com_GetRxCbkFuncPtrOfPCConfig()[(Index)])
#define Com_GetRxDeadlineMonitoringISRLockCounter()                   (Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())
#define Com_GetRxDefPduBuffer(Index)                                  (Com_GetRxDefPduBufferOfPCConfig()[(Index)])
#define Com_GetRxDeferredFctPtrCache(Index)                           (Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)])
#define Com_GetRxDeferredProcessingISRLockCounter()                   (Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())
#define Com_GetRxIPduGroupISRLockCounter()                            (Com_GetRxIPduGroupISRLockCounterOfPCConfig())
#define Com_GetRxPduDmState(Index)                                    (Com_GetRxPduDmStateOfPCConfig()[(Index)])
#define Com_IsRxPduGrpActive(Index)                                   ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorEndIdxOfRxPduGrpInfo(Index)                (Com_GetRxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorEndIdxOfRxPduGrpInfo)
#define Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index)              (Com_GetRxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfRxPduGrpInfo)
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                (Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndEndIdxOfRxPduInfo)
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)              (Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndStartIdxOfRxPduInfo)
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                   ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndUsedOfRxPduInfo) != FALSE)
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                 (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferEndIdxOfRxPduInfo)
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)               (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo)
#define Com_GetRxSigGrpInfoIndEndIdxOfRxPduInfo(Index)                (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigGrpInfoIndEndIdxOfRxPduInfo)
#define Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Index)              (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigGrpInfoIndStartIdxOfRxPduInfo)
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                      (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoEndIdxOfRxPduInfo)
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                    (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoStartIdxOfRxPduInfo)
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                         ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Index)                  (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndEndIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)                (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndStartIdxOfRxPduInfo)
#define Com_IsRxTOutInfoUsedOfRxPduInfo(Index)                        ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetTypeOfRxPduInfo(Index)                                 (Com_GetRxPduInfoOfPCConfig()[(Index)].TypeOfRxPduInfo)
#define Com_GetRxSigBufferArrayBased(Index)                           (Com_GetRxSigBufferArrayBasedOfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt16(Index)                               (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt32(Index)                               (Com_GetRxSigBufferUInt32OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt64(Index)                               (Com_GetRxSigBufferUInt64OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt8(Index)                                (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)])
#define Com_IsInvEventOfRxSigGrpInfo(Index)                           ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].InvEventOfRxSigGrpInfo) != FALSE)
#define Com_GetRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo(Index)       (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo)
#define Com_GetRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(Index)     (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo)
#define Com_GetRxCbkFuncPtrAckIdxOfRxSigGrpInfo(Index)                (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxCbkFuncPtrAckIdxOfRxSigGrpInfo)
#define Com_GetRxPduInfoIdxOfRxSigGrpInfo(Index)                      (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxSigGrpInfo)
#define Com_GetRxTOutInfoIdxOfRxSigGrpInfo(Index)                     (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigGrpInfo)
#define Com_IsRxTOutInfoUsedOfRxSigGrpInfo(Index)                     ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxTOutInfoUsedOfRxSigGrpInfo) != FALSE)
#define Com_IsShdBufferRequiredOfRxSigGrpInfo(Index)                  ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].ShdBufferRequiredOfRxSigGrpInfo) != FALSE)
#define Com_GetStartBytePositionOfRxSigGrpInfo(Index)                 (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].StartBytePositionOfRxSigGrpInfo)
#define Com_GetValidDlcOfRxSigGrpInfo(Index)                          (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].ValidDlcOfRxSigGrpInfo)
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                      (Com_GetRxSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxSigInfo)
#define Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index)                   (Com_GetRxSigInfoOfPCConfig()[(Index)].RxCbkFuncPtrAckIdxOfRxSigInfo)
#define Com_GetRxTOutInfoIdxOfRxSigInfo(Index)                        (Com_GetRxSigInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigInfo)
#define Com_GetSignalProcessingOfRxSigInfo(Index)                     (Com_GetRxSigInfoOfPCConfig()[(Index)].SignalProcessingOfRxSigInfo)
#define Com_GetValidDlcOfRxSigInfo(Index)                             (Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo)
#define Com_GetRxTOutCnt(Index)                                       (Com_GetRxTOutCntOfPCConfig()[(Index)])
#define Com_GetCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo(Index)           (Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo)
#define Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index)         (Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo)
#define Com_GetFactorOfRxTOutInfo(Index)                              (Com_GetRxTOutInfoOfPCConfig()[(Index)].FactorOfRxTOutInfo)
#define Com_GetFirstFactorOfRxTOutInfo(Index)                         (Com_GetRxTOutInfoOfPCConfig()[(Index)].FirstFactorOfRxTOutInfo)
#define Com_GetRxPduInfoIdxOfRxTOutInfo(Index)                        (Com_GetRxTOutInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxTOutInfo)
#define Com_GetSigGrpEventFlag(Index)                                 (Com_GetSigGrpEventFlagOfPCConfig()[(Index)])
#define Com_GetTmpRxBuffer(Index)                                     (Com_GetTmpRxBufferOfPCConfig()[(Index)])
#define Com_GetTmpRxShdBufferUInt16(Index)                            (Com_GetTmpRxShdBufferUInt16OfPCConfig()[(Index)])
#define Com_GetTmpRxShdBufferUInt32(Index)                            (Com_GetTmpRxShdBufferUInt32OfPCConfig()[(Index)])
#define Com_GetTmpRxShdBufferUInt8(Index)                             (Com_GetTmpRxShdBufferUInt8OfPCConfig()[(Index)])
#define Com_IsTransmitRequest(Index)                                  ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxBuffer(Index)                                        (Com_GetTxBufferOfPCConfig()[(Index)])
#define Com_GetTxCyclicProcessingISRLockCounter()                     (Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())
#define Com_GetTxDeadlineMonitoringISRLockCounter()                   (Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig())
#define Com_GetTxFilterInitValueUInt16(Index)                         (Com_GetTxFilterInitValueUInt16OfPCConfig()[(Index)])
#define Com_GetTxFilterInitValueUInt8(Index)                          (Com_GetTxFilterInitValueUInt8OfPCConfig()[(Index)])
#define Com_GetTxFilterOldValueUInt16(Index)                          (Com_GetTxFilterOldValueUInt16OfPCConfig()[(Index)])
#define Com_GetTxFilterOldValueUInt8(Index)                           (Com_GetTxFilterOldValueUInt8OfPCConfig()[(Index)])
#define Com_GetTxIPduGroupISRLockCounter()                            (Com_GetTxIPduGroupISRLockCounterOfPCConfig())
#define Com_GetMinimumDelayOfTxModeInfo(Index)                        (Com_GetTxModeInfoOfPCConfig()[(Index)].MinimumDelayOfTxModeInfo)
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                       (Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueIdxOfTxModeInfo)
#define Com_IsTxModeTrueUsedOfTxModeInfo(Index)                       ((Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueUsedOfTxModeInfo) != FALSE)
#define Com_GetTxSigInfoFilterInitValueIndEndIdxOfTxModeInfo(Index)   (Com_GetTxModeInfoOfPCConfig()[(Index)].TxSigInfoFilterInitValueIndEndIdxOfTxModeInfo)
#define Com_GetTxSigInfoFilterInitValueIndStartIdxOfTxModeInfo(Index) (Com_GetTxModeInfoOfPCConfig()[(Index)].TxSigInfoFilterInitValueIndStartIdxOfTxModeInfo)
#define Com_IsDirectOfTxModeTrue(Index)                               ((Com_GetTxModeTrueOfPCConfig()[(Index)].DirectOfTxModeTrue) != FALSE)
#define Com_GetRepCntOfTxModeTrue(Index)                              (Com_GetTxModeTrueOfPCConfig()[(Index)].RepCntOfTxModeTrue)
#define Com_GetRepPeriodOfTxModeTrue(Index)                           (Com_GetTxModeTrueOfPCConfig()[(Index)].RepPeriodOfTxModeTrue)
#define Com_GetTimePeriodOfTxModeTrue(Index)                          (Com_GetTxModeTrueOfPCConfig()[(Index)].TimePeriodOfTxModeTrue)
#define Com_IsTxPduGrpActive(Index)                                   ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorEndIdxOfTxPduGrpInfo(Index)                (Com_GetTxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorEndIdxOfTxPduGrpInfo)
#define Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index)              (Com_GetTxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfTxPduGrpInfo)
#define Com_GetExternalIdOfTxPduInfo(Index)                           (Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo)
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                       (Com_GetTxPduInfoOfPCConfig()[(Index)].MetaDataLengthOfTxPduInfo)
#define Com_GetTxBufferLengthOfTxPduInfo(Index)                       (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferLengthOfTxPduInfo)
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                 (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo)
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)               (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo)
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                    ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueUsedOfTxPduInfo) != FALSE)
#define Com_GetTxSigGrpInfoIndEndIdxOfTxPduInfo(Index)                (Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndEndIdxOfTxPduInfo)
#define Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index)              (Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndStartIdxOfTxPduInfo)
#define Com_GetTxPduInitValue(Index)                                  (Com_GetTxPduInitValueOfPCConfig()[(Index)])
#define Com_GetTxProcessingISRLockCounter()                           (Com_GetTxProcessingISRLockCounterOfPCConfig())
#define Com_GetTxSduLength(Index)                                     (Com_GetTxSduLengthOfPCConfig()[(Index)])
#define Com_GetTransferPropertyOfTxSigGrpInfo(Index)                  (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TransferPropertyOfTxSigGrpInfo)
#define Com_GetTxBufferEndIdxOfTxSigGrpInfo(Index)                    (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxSigGrpInfo)
#define Com_GetTxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo(Index)      (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo)
#define Com_GetTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo(Index)    (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo)
#define Com_GetTxBufferStartIdxOfTxSigGrpInfo(Index)                  (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigGrpInfo)
#define Com_GetTxPduInfoIdxOfTxSigGrpInfo(Index)                      (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigGrpInfo)
#define Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)                   ((Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigGrpMaskUsedOfTxSigGrpInfo) != FALSE)
#define Com_GetTxSigInfoInvValueIndEndIdxOfTxSigGrpInfo(Index)        (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigInfoInvValueIndEndIdxOfTxSigGrpInfo)
#define Com_GetTxSigInfoInvValueIndStartIdxOfTxSigGrpInfo(Index)      (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigInfoInvValueIndStartIdxOfTxSigGrpInfo)
#define Com_GetTxSigGrpMask(Index)                                    (Com_GetTxSigGrpMaskOfPCConfig()[(Index)])
#define Com_GetApplTypeOfTxSigInfo(Index)                             (Com_GetTxSigInfoOfPCConfig()[(Index)].ApplTypeOfTxSigInfo)
#define Com_GetBitLengthOfTxSigInfo(Index)                            (Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo)
#define Com_GetBitPositionOfTxSigInfo(Index)                          (Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo)
#define Com_GetBusAccOfTxSigInfo(Index)                               (Com_GetTxSigInfoOfPCConfig()[(Index)].BusAccOfTxSigInfo)
#define Com_GetByteLengthOfTxSigInfo(Index)                           (Com_GetTxSigInfoOfPCConfig()[(Index)].ByteLengthOfTxSigInfo)
#define Com_GetFilterInitValueIdxOfTxSigInfo(Index)                   (Com_GetTxSigInfoOfPCConfig()[(Index)].FilterInitValueIdxOfTxSigInfo)
#define Com_GetInvValueIdxOfTxSigInfo(Index)                          (Com_GetTxSigInfoOfPCConfig()[(Index)].InvValueIdxOfTxSigInfo)
#define Com_GetOnChangeIdxOfTxSigInfo(Index)                          (Com_GetTxSigInfoOfPCConfig()[(Index)].OnChangeIdxOfTxSigInfo)
#define Com_IsOnChangeUsedOfTxSigInfo(Index)                          ((Com_GetTxSigInfoOfPCConfig()[(Index)].OnChangeUsedOfTxSigInfo) != FALSE)
#define Com_GetStartByteInPduPositionOfTxSigInfo(Index)               (Com_GetTxSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxSigInfo)
#define Com_GetTxBufferEndIdxOfTxSigInfo(Index)                       (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxSigInfo)
#define Com_GetTxBufferStartIdxOfTxSigInfo(Index)                     (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigInfo)
#define Com_GetTxPduInfoIdxOfTxSigInfo(Index)                         (Com_GetTxSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigInfo)
#define Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index)                      (Com_GetTxSigInfoOfPCConfig()[(Index)].TxSigGrpInfoIdxOfTxSigInfo)
#define Com_GetTxSigInfoFilterInitValueInd(Index)                     (Com_GetTxSigInfoFilterInitValueIndOfPCConfig()[(Index)])
#define Com_GetTxSigInfoInvValueInd(Index)                            (Com_GetTxSigInfoInvValueIndOfPCConfig()[(Index)])
#define Com_IsWaitingForConfirmation(Index)                           ((Com_GetWaitingForConfirmationOfPCConfig()[(Index)]) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDeduplicatedDataMacros  Com Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetRxPduInfoIdxOfActivatableRxComIPdus(Index)             ((Com_RxPduInfoIdxOfActivatableRxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
#define Com_GetTxPduInfoIdxOfActivatableTxComIPdus(Index)             ((Com_TxPduInfoIdxOfActivatableTxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetCbkRxTOutFuncPtrInd(Index)                             ((Com_CbkRxTOutFuncPtrIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_CbkRxTOutFuncPtr */
#define Com_GetConfigId()                                             Com_GetConfigIdOfPCConfig()
#define Com_GetFilterAlgoOfFilterInfo_UInt16(Index)                   ((Com_FilterAlgoOfFilterInfo_UInt16Type)(((Index) + 0x02U)))  /**< Configured filter algorithm. */
#define Com_GetFilterMaskOfFilterInfo_UInt16(Index)                   ((Com_FilterMaskOfFilterInfo_UInt16Type)(((Index) + 0xFFFFU)))
#define Com_GetFilterMaxOfFilterInfo_UInt16(Index)                    ((Com_FilterMaxOfFilterInfo_UInt16Type)((Index)))
#define Com_GetFilterMinOfFilterInfo_UInt16(Index)                    ((Com_FilterMinOfFilterInfo_UInt16Type)((Index)))
#define Com_GetFilterXOfFilterInfo_UInt16(Index)                      ((Com_FilterXOfFilterInfo_UInt16Type)((Index)))
#define Com_GetFilterAlgoOfFilterInfo_UInt8(Index)                    ((Com_FilterAlgoOfFilterInfo_UInt8Type)(((Index) + 0x02U)))  /**< Configured filter algorithm. */
#define Com_GetFilterMaskOfFilterInfo_UInt8(Index)                    ((Com_FilterMaskOfFilterInfo_UInt8Type)(((Index) + 0xFFU)))
#define Com_GetFilterMaxOfFilterInfo_UInt8(Index)                     ((Com_FilterMaxOfFilterInfo_UInt8Type)((Index)))
#define Com_GetFilterMinOfFilterInfo_UInt8(Index)                     ((Com_FilterMinOfFilterInfo_UInt8Type)((Index)))
#define Com_GetFilterXOfFilterInfo_UInt8(Index)                       ((Com_FilterXOfFilterInfo_UInt8Type)((Index)))
#define Com_GetPduGrpCnt()                                            Com_GetPduGrpCntOfPCConfig()
#define Com_IsBufferUsedOfRxAccessInfo(Index)                         Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64 */
#define Com_GetBytePositionOfRxAccessInfo(Index)                      Com_GetStartByteInPduPositionOfRxAccessInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_GetConstValueArrayBasedInitValueLengthOfRxAccessInfo(Index) ((Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfoType)((Com_GetConstValueArrayBasedInitValueEndIdxOfRxAccessInfo(Index) - Com_GetConstValueArrayBasedInitValueStartIdxOfRxAccessInfo(Index))))  /**< the number of relations pointing to Com_ConstValueArrayBased */
#define Com_IsConstValueArrayBasedInitValueUsedOfRxAccessInfo(Index)  Com_IsRxSigBufferArrayBasedBufferUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_ConstValueArrayBased */
#define Com_GetInitValueIdxOfRxAccessInfo(Index)                      Com_GetRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo(Index)  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
#define Com_IsInvValueUsedOfRxAccessInfo(Index)                       (((boolean)(Com_GetInvValueIdxOfRxAccessInfo(Index) != COM_NO_INVVALUEIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
#define Com_IsIsGroupSignalOfRxAccessInfo(Index)                      Com_IsShdBufferUsedOfRxAccessInfo(Index)
#define Com_IsRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo(Index) Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
#define Com_GetRxSigBufferArrayBasedBufferLengthOfRxAccessInfo(Index) ((Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfoType)((Com_GetRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo(Index) - Com_GetRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo(Index))))  /**< the number of relations pointing to Com_RxSigBufferArrayBased */
#define Com_IsRxTOutInfoUsedOfRxAccessInfo(Index)                     (((boolean)(Com_GetRxTOutInfoIdxOfRxAccessInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_IsTmpBufferUsedOfRxAccessInfo(Index)                      Com_IsShdBufferUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TmpRxShdBufferUInt8,Com_TmpRxShdBufferUInt16,Com_TmpRxShdBufferUInt32,Com_TmpRxShdBufferUInt64,Com_TmpRxShdBufferSInt8,Com_TmpRxShdBufferSInt16,Com_TmpRxShdBufferSInt32,Com_TmpRxShdBufferSInt64 */
#define Com_GetRxDeadlineMonitoringISRLockThreshold()                 Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()
#define Com_GetRxDeferredProcessingISRLockThreshold()                 Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()
#define Com_GetRxIPduGroupISRLockThreshold()                          Com_GetRxIPduGroupISRLockThresholdOfPCConfig()
#define Com_IsPduGrpVectorUsedOfRxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)               ((Com_HandleRxPduDeferredIdxOfRxPduInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)               Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                 ((Com_RxDefPduBufferLengthOfRxPduInfoType)((Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index) - Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index))))  /**< the number of relations pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                    Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_IsRxSigGrpInfoIndUsedOfRxPduInfo(Index)                   (((!(Com_IsRxSigInfoUsedOfRxPduInfo(Index)))) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigGrpInfoInd */
#define Com_GetRxTOutInfoIdxOfRxPduInfo(Index)                        Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
#define Com_IsRxTOutInfoIndUsedOfRxPduInfo(Index)                     Com_IsRxTOutInfoUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxTOutInfoInd */
#define Com_GetSignalProcessingOfRxPduInfo(Index)                     Com_GetTypeOfRxPduInfo(Index)  /**< Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion. */
#define Com_IsRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo(Index)          Com_IsShdBufferRequiredOfRxSigGrpInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoGrpSigInd */
#define Com_IsRxCbkFuncPtrAckUsedOfRxSigGrpInfo(Index)                Com_IsRxTOutInfoUsedOfRxSigGrpInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxCbkFuncPtr */
#define Com_GetSignalProcessingOfRxSigGrpInfo(Index)                  Com_GetStartBytePositionOfRxSigGrpInfo(Index)
#define Com_GetRxSigGrpInfoInd(Index)                                 ((Com_RxSigGrpInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxSigGrpInfo */
#define Com_IsRxCbkFuncPtrAckUsedOfRxSigInfo(Index)                   (((boolean)(Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index) != COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxCbkFuncPtr */
#define Com_IsRxTOutInfoUsedOfRxSigInfo(Index)                        (((boolean)(Com_GetRxTOutInfoIdxOfRxSigInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_IsCbkRxTOutFuncPtrIndUsedOfRxTOutInfo(Index)              (((boolean)(Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index) != COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_CbkRxTOutFuncPtrInd */
#define Com_GetRxTOutInfoInd(Index)                                   ((Com_RxTOutInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxTOutInfo */
#define Com_GetSizeOfActivatableRxComIPdus()                          Com_GetSizeOfActivatableRxComIPdusOfPCConfig()
#define Com_GetSizeOfActivatableTxComIPdus()                          Com_GetSizeOfActivatableTxComIPdusOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtr()                               Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtrInd()                            Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()
#define Com_GetSizeOfConstValueArrayBased()                           Com_GetSizeOfConstValueArrayBasedOfPCConfig()
#define Com_GetSizeOfConstValueUInt16()                               Com_GetSizeOfConstValueUInt16OfPCConfig()
#define Com_GetSizeOfConstValueUInt32()                               Com_GetSizeOfConstValueUInt32OfPCConfig()
#define Com_GetSizeOfConstValueUInt64()                               Com_GetSizeOfConstValueUInt64OfPCConfig()
#define Com_GetSizeOfConstValueUInt8()                                Com_GetSizeOfConstValueUInt8OfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                  Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                   Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                              Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfDelayTimeCnt()                                   Com_GetSizeOfDelayTimeCntOfPCConfig()
#define Com_GetSizeOfFilterInfo_UInt16()                              Com_GetSizeOfFilterInfo_UInt16OfPCConfig()
#define Com_GetSizeOfFilterInfo_UInt8()                               Com_GetSizeOfFilterInfo_UInt8OfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                            Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfHandleTxPduDeferred()                            Com_GetSizeOfHandleTxPduDeferredOfPCConfig()
#define Com_GetSizeOfPduGrpVector()                                   Com_GetSizeOfPduGrpVectorOfPCConfig()
#define Com_GetSizeOfRepCnt()                                         Com_GetSizeOfRepCntOfPCConfig()
#define Com_GetSizeOfRepCycleCnt()                                    Com_GetSizeOfRepCycleCntOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                   Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoGrpSigInd()                          Com_GetSizeOfRxAccessInfoGrpSigIndOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxCbkFuncPtr()                                   Com_GetSizeOfRxCbkFuncPtrOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                 Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxDeferredFctPtrCache()                          Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()
#define Com_GetSizeOfRxPduDmState()                                   Com_GetSizeOfRxPduDmStateOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                 Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduGrpInfo()                                   Com_GetSizeOfRxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                      Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxSigBufferArrayBased()                          Com_GetSizeOfRxSigBufferArrayBasedOfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt16()                              Com_GetSizeOfRxSigBufferUInt16OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt32()                              Com_GetSizeOfRxSigBufferUInt32OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt64()                              Com_GetSizeOfRxSigBufferUInt64OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt8()                               Com_GetSizeOfRxSigBufferUInt8OfPCConfig()
#define Com_GetSizeOfRxSigGrpInfo()                                   Com_GetSizeOfRxSigGrpInfoOfPCConfig()
#define Com_GetSizeOfRxSigGrpInfoInd()                                Com_GetSizeOfRxSigGrpInfoIndOfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                      Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfRxTOutCnt()                                      Com_GetSizeOfRxTOutCntOfPCConfig()
#define Com_GetSizeOfRxTOutInfo()                                     Com_GetSizeOfRxTOutInfoOfPCConfig()
#define Com_GetSizeOfRxTOutInfoInd()                                  Com_GetSizeOfRxTOutInfoIndOfPCConfig()
#define Com_GetSizeOfSigGrpEventFlag()                                Com_GetSizeOfSigGrpEventFlagOfPCConfig()
#define Com_GetSizeOfTmpRxBuffer()                                    Com_GetSizeOfTmpRxBufferOfPCConfig()
#define Com_GetSizeOfTmpRxShdBufferUInt16()                           Com_GetSizeOfTmpRxShdBufferUInt16OfPCConfig()
#define Com_GetSizeOfTmpRxShdBufferUInt32()                           Com_GetSizeOfTmpRxShdBufferUInt32OfPCConfig()
#define Com_GetSizeOfTmpRxShdBufferUInt8()                            Com_GetSizeOfTmpRxShdBufferUInt8OfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxBuffer()                                       Com_GetSizeOfTxBufferOfPCConfig()
#define Com_GetSizeOfTxFilterInitValueUInt16()                        Com_GetSizeOfTxFilterInitValueUInt16OfPCConfig()
#define Com_GetSizeOfTxFilterInitValueUInt8()                         Com_GetSizeOfTxFilterInitValueUInt8OfPCConfig()
#define Com_GetSizeOfTxFilterOldValueUInt16()                         Com_GetSizeOfTxFilterOldValueUInt16OfPCConfig()
#define Com_GetSizeOfTxFilterOldValueUInt8()                          Com_GetSizeOfTxFilterOldValueUInt8OfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                     Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                     Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                 Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduGrpInfo()                                   Com_GetSizeOfTxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                      Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                 Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                    Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfo()                                   Com_GetSizeOfTxSigGrpInfoOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfoInd()                                Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()
#define Com_GetSizeOfTxSigGrpMask()                                   Com_GetSizeOfTxSigGrpMaskOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                      Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_GetSizeOfTxSigInfoFilterInitValueInd()                    Com_GetSizeOfTxSigInfoFilterInitValueIndOfPCConfig()
#define Com_GetSizeOfTxSigInfoInvValueInd()                           Com_GetSizeOfTxSigInfoInvValueIndOfPCConfig()
#define Com_GetSizeOfWaitingForConfirmation()                         Com_GetSizeOfWaitingForConfirmationOfPCConfig()
#define Com_GetTxCyclicProcessingISRLockThreshold()                   Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()
#define Com_GetTxIPduGroupISRLockThreshold()                          Com_GetTxIPduGroupISRLockThresholdOfPCConfig()
#define Com_IsInitModeOfTxModeInfo(Index)                             Com_IsTxModeTrueUsedOfTxModeInfo(Index)  /**< Initial transmission mode selector of the Tx I-PDU. */
#define Com_IsTxSigInfoFilterInitValueIndUsedOfTxModeInfo(Index)      (((boolean)(Com_GetTxSigInfoFilterInitValueIndStartIdxOfTxModeInfo(Index) != COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigInfoFilterInitValueInd */
#define Com_IsPeriodicOfTxModeTrue(Index)                             (((boolean)(Com_GetTimePeriodOfTxModeTrue(Index) != 0U)) != FALSE)  /**< TRUE if transmission mode contains a cyclic part. */
#define Com_IsPduGrpVectorUsedOfTxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                Com_GetTxBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxBufferEndIdxOfTxPduInfo(Index)                       Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferStartIdxOfTxPduInfo(Index)                     Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxPduInfo(Index)                          Com_IsTxPduInitValueUsedOfTxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_IsTxSigGrpInfoIndUsedOfTxPduInfo(Index)                   (((boolean)(Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpInfoInd */
#define Com_GetTxProcessingISRLockThreshold()                         Com_GetTxProcessingISRLockThresholdOfPCConfig()
#define Com_GetPduOffsetOfTxSigGrpInfo(Index)                         Com_GetTransferPropertyOfTxSigGrpInfo(Index)  /**< Byte offset relative to the PDU the signal group is starting. */
#define Com_GetTxBufferLengthOfTxSigGrpInfo(Index)                    ((Com_TxBufferLengthOfTxSigGrpInfoType)((Com_GetTxBufferEndIdxOfTxSigGrpInfo(Index) - Com_GetTxBufferStartIdxOfTxSigGrpInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)      ((Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfoType)((Com_GetTxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo(Index) - Com_GetTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigGrpInfo(Index)                       Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_GetTxSigGrpMaskEndIdxOfTxSigGrpInfo(Index)                Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpMaskLengthOfTxSigGrpInfo(Index)                Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)  /**< the number of relations pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpMaskStartIdxOfTxSigGrpInfo(Index)              Com_GetTransferPropertyOfTxSigGrpInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxSigGrpMask */
#define Com_IsTxSigInfoInvValueIndUsedOfTxSigGrpInfo(Index)           Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigInfoInvValueInd */
#define Com_GetTxSigGrpInfoInd(Index)                                 ((Com_TxSigGrpInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxSigGrpInfo */
#define Com_GetBytePositionOfTxSigInfo(Index)                         Com_GetStartByteInPduPositionOfTxSigInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_IsFilterInitValueUsedOfTxSigInfo(Index)                   Com_IsOnChangeUsedOfTxSigInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxFilterInitValueUInt8,Com_TxFilterInitValueUInt16,Com_TxFilterInitValueUInt32,Com_TxFilterInitValueUInt64,Com_TxFilterInitValueSInt8,Com_TxFilterInitValueSInt16,Com_TxFilterInitValueSInt32,Com_TxFilterInitValueSInt64 */
#define Com_IsInvValueUsedOfTxSigInfo(Index)                          (((boolean)(Com_GetInvValueIdxOfTxSigInfo(Index) != COM_NO_INVVALUEIDXOFTXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
#define Com_GetTxBufferLengthOfTxSigInfo(Index)                       ((Com_TxBufferLengthOfTxSigInfoType)((Com_GetTxBufferEndIdxOfTxSigInfo(Index) - Com_GetTxBufferStartIdxOfTxSigInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigInfo(Index)                          (((boolean)(Com_GetTxBufferLengthOfTxSigInfo(Index) != 0)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_IsTxSigGrpInfoUsedOfTxSigInfo(Index)                      (((boolean)(Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index) != COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxSigGrpInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSetDataMacros  Com Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                            Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                             Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                        Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetDelayTimeCnt(Index, Value)                             Com_GetDelayTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetGatewayProcessingISRLockCounter(Value)                 Com_GetGatewayProcessingISRLockCounterOfPCConfig() = (Value)
#define Com_SetHandleRxPduDeferred(Index, Value)                      Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleTxPduDeferred(Index, Value)                      Com_GetHandleTxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetInitialized(Value)                                     Com_GetInitializedOfPCConfig() = (Value)
#define Com_SetRepCnt(Index, Value)                                   Com_GetRepCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRepCycleCnt(Index, Value)                              Com_GetRepCycleCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeadlineMonitoringISRLockCounter(Value)              Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig() = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                           Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredFctPtrCache(Index, Value)                    Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredProcessingISRLockCounter(Value)              Com_GetRxDeferredProcessingISRLockCounterOfPCConfig() = (Value)
#define Com_SetRxIPduGroupISRLockCounter(Value)                       Com_GetRxIPduGroupISRLockCounterOfPCConfig() = (Value)
#define Com_SetRxPduDmState(Index, Value)                             Com_GetRxPduDmStateOfPCConfig()[(Index)] = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                           Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferArrayBased(Index, Value)                    Com_GetRxSigBufferArrayBasedOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt16(Index, Value)                        Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt32(Index, Value)                        Com_GetRxSigBufferUInt32OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt64(Index, Value)                        Com_GetRxSigBufferUInt64OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt8(Index, Value)                         Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetRxTOutCnt(Index, Value)                                Com_GetRxTOutCntOfPCConfig()[(Index)] = (Value)
#define Com_SetSigGrpEventFlag(Index, Value)                          Com_GetSigGrpEventFlagOfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxBuffer(Index, Value)                              Com_GetTmpRxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxShdBufferUInt16(Index, Value)                     Com_GetTmpRxShdBufferUInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxShdBufferUInt32(Index, Value)                     Com_GetTmpRxShdBufferUInt32OfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxShdBufferUInt8(Index, Value)                      Com_GetTmpRxShdBufferUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                          Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxBuffer(Index, Value)                                 Com_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxCyclicProcessingISRLockCounter(Value)                Com_GetTxCyclicProcessingISRLockCounterOfPCConfig() = (Value)
#define Com_SetTxDeadlineMonitoringISRLockCounter(Value)              Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig() = (Value)
#define Com_SetTxFilterOldValueUInt16(Index, Value)                   Com_GetTxFilterOldValueUInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetTxFilterOldValueUInt8(Index, Value)                    Com_GetTxFilterOldValueUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetTxIPduGroupISRLockCounter(Value)                       Com_GetTxIPduGroupISRLockCounterOfPCConfig() = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                           Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxProcessingISRLockCounter(Value)                      Com_GetTxProcessingISRLockCounterOfPCConfig() = (Value)
#define Com_SetTxSduLength(Index, Value)                              Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
#define Com_SetWaitingForConfirmation(Index, Value)                   Com_GetWaitingForConfirmationOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetAddressOfDataMacros  Com Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueArrayBased(Index)                        &Com_GetConstValueArrayBased(Index)
#define Com_GetAddrConstValueUInt16(Index)                            &Com_GetConstValueUInt16(Index)
#define Com_GetAddrConstValueUInt32(Index)                            &Com_GetConstValueUInt32(Index)
#define Com_GetAddrConstValueUInt64(Index)                            &Com_GetConstValueUInt64(Index)
#define Com_GetAddrConstValueUInt8(Index)                             &Com_GetConstValueUInt8(Index)
#define Com_GetAddrRxDefPduBuffer(Index)                              &Com_GetRxDefPduBuffer(Index)
#define Com_GetAddrRxDeferredFctPtrCache(Index)                       &Com_GetRxDeferredFctPtrCache(Index)
#define Com_GetAddrRxSigBufferArrayBased(Index)                       &Com_GetRxSigBufferArrayBased(Index)
#define Com_GetAddrRxSigBufferUInt16(Index)                           &Com_GetRxSigBufferUInt16(Index)
#define Com_GetAddrRxSigBufferUInt32(Index)                           &Com_GetRxSigBufferUInt32(Index)
#define Com_GetAddrRxSigBufferUInt64(Index)                           &Com_GetRxSigBufferUInt64(Index)
#define Com_GetAddrRxSigBufferUInt8(Index)                            &Com_GetRxSigBufferUInt8(Index)
#define Com_GetAddrTmpRxBuffer(Index)                                 &Com_GetTmpRxBuffer(Index)
#define Com_GetAddrTmpRxShdBufferUInt16(Index)                        &Com_GetTmpRxShdBufferUInt16(Index)
#define Com_GetAddrTmpRxShdBufferUInt32(Index)                        &Com_GetTmpRxShdBufferUInt32(Index)
#define Com_GetAddrTmpRxShdBufferUInt8(Index)                         &Com_GetTmpRxShdBufferUInt8(Index)
#define Com_GetAddrTxBuffer(Index)                                    &Com_GetTxBuffer(Index)
#define Com_GetAddrTxFilterInitValueUInt16(Index)                     &Com_GetTxFilterInitValueUInt16(Index)
#define Com_GetAddrTxFilterInitValueUInt8(Index)                      &Com_GetTxFilterInitValueUInt8(Index)
#define Com_GetAddrTxFilterOldValueUInt16(Index)                      &Com_GetTxFilterOldValueUInt16(Index)
#define Com_GetAddrTxFilterOldValueUInt8(Index)                       &Com_GetTxFilterOldValueUInt8(Index)
#define Com_GetAddrTxPduInitValue(Index)                              &Com_GetTxPduInitValue(Index)
#define Com_GetAddrTxSigGrpMask(Index)                                &Com_GetTxSigGrpMask(Index)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCHasMacros  Com Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasActivatableRxComIPdus()                                (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfActivatableRxComIPdus()                  (TRUE != FALSE)
#define Com_HasActivatableTxComIPdus()                                (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfActivatableTxComIPdus()                  (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtr()                                     (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrInd()                                  (TRUE != FALSE)
#define Com_HasConfigId()                                             (TRUE != FALSE)
#define Com_HasConstValueArrayBased()                                 (TRUE != FALSE)
#define Com_HasConstValueUInt16()                                     (TRUE != FALSE)
#define Com_HasConstValueUInt32()                                     (TRUE != FALSE)
#define Com_HasConstValueUInt64()                                     (TRUE != FALSE)
#define Com_HasConstValueUInt8()                                      (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                        (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                         (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                    (TRUE != FALSE)
#define Com_HasDelayTimeCnt()                                         (TRUE != FALSE)
#define Com_HasFilterInfo_UInt16()                                    (TRUE != FALSE)
#define Com_HasFilterAlgoOfFilterInfo_UInt16()                        (TRUE != FALSE)
#define Com_HasFilterMaskOfFilterInfo_UInt16()                        (TRUE != FALSE)
#define Com_HasFilterMaxOfFilterInfo_UInt16()                         (TRUE != FALSE)
#define Com_HasFilterMinOfFilterInfo_UInt16()                         (TRUE != FALSE)
#define Com_HasFilterXOfFilterInfo_UInt16()                           (TRUE != FALSE)
#define Com_HasFilterInfo_UInt8()                                     (TRUE != FALSE)
#define Com_HasFilterAlgoOfFilterInfo_UInt8()                         (TRUE != FALSE)
#define Com_HasFilterMaskOfFilterInfo_UInt8()                         (TRUE != FALSE)
#define Com_HasFilterMaxOfFilterInfo_UInt8()                          (TRUE != FALSE)
#define Com_HasFilterMinOfFilterInfo_UInt8()                          (TRUE != FALSE)
#define Com_HasFilterXOfFilterInfo_UInt8()                            (TRUE != FALSE)
#define Com_HasGatewayProcessingISRLockCounter()                      (TRUE != FALSE)
#define Com_HasHandleRxPduDeferred()                                  (TRUE != FALSE)
#define Com_HasHandleTxPduDeferred()                                  (TRUE != FALSE)
#define Com_HasInitialized()                                          (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                            (TRUE != FALSE)
#define Com_HasPduGrpVector()                                         (TRUE != FALSE)
#define Com_HasRepCnt()                                               (TRUE != FALSE)
#define Com_HasRepCycleCnt()                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                         (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                               (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                            (TRUE != FALSE)
#define Com_HasBufferIdxOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBufferUsedOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                 (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueEndIdxOfRxAccessInfo()    (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueLengthOfRxAccessInfo()    (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueStartIdxOfRxAccessInfo()  (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueUsedOfRxAccessInfo()      (TRUE != FALSE)
#define Com_HasInitValueIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasInitValueUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasInvValueIdxOfRxAccessInfo()                            (TRUE != FALSE)
#define Com_HasInvValueUsedOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasIsGroupSignalOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo()      (TRUE != FALSE)
#define Com_HasRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo()     (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo()      (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferLengthOfRxAccessInfo()      (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo()    (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferUsedOfRxAccessInfo()        (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxAccessInfo()                         (TRUE != FALSE)
#define Com_HasShdBufferIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasShdBufferUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfRxAccessInfo()                 (TRUE != FALSE)
#define Com_HasTmpBufferIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasTmpBufferUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasRxAccessInfoGrpSigInd()                                (TRUE != FALSE)
#define Com_HasRxAccessInfoInd()                                      (TRUE != FALSE)
#define Com_HasRxCbkFuncPtr()                                         (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounter()                   (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThreshold()                 (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                       (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCache()                                (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounter()                   (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThreshold()                 (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounter()                            (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThreshold()                          (TRUE != FALSE)
#define Com_HasRxPduDmState()                                         (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasRxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfRxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfRxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfRxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasRxPduInfo()                                            (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                        (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndUsedOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                           (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                         (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxPduInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoIndEndIdxOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxTOutInfoIndStartIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIndUsedOfRxPduInfo()                         (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxPduInfo()                            (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxPduInfo()                          (TRUE != FALSE)
#define Com_HasTypeOfRxPduInfo()                                      (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBased()                                (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferUInt32()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferUInt64()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8()                                     (TRUE != FALSE)
#define Com_HasRxSigGrpInfo()                                         (TRUE != FALSE)
#define Com_HasInvEventOfRxSigGrpInfo()                               (TRUE != FALSE)
#define Com_HasRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo()            (TRUE != FALSE)
#define Com_HasRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo()          (TRUE != FALSE)
#define Com_HasRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo()              (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckIdxOfRxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckUsedOfRxSigGrpInfo()                    (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxSigGrpInfo()                          (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxSigGrpInfo()                         (TRUE != FALSE)
#define Com_HasShdBufferRequiredOfRxSigGrpInfo()                      (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasStartBytePositionOfRxSigGrpInfo()                      (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigGrpInfo()                               (TRUE != FALSE)
#define Com_HasRxSigGrpInfoInd()                                      (TRUE != FALSE)
#define Com_HasRxSigInfo()                                            (TRUE != FALSE)
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                           (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckIdxOfRxSigInfo()                        (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckUsedOfRxSigInfo()                       (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxSigInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxSigInfo()                            (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                          (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigInfo()                                  (TRUE != FALSE)
#define Com_HasRxTOutCnt()                                            (TRUE != FALSE)
#define Com_HasRxTOutInfo()                                           (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo()                (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo()              (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndUsedOfRxTOutInfo()                  (TRUE != FALSE)
#define Com_HasFactorOfRxTOutInfo()                                   (TRUE != FALSE)
#define Com_HasFirstFactorOfRxTOutInfo()                              (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxTOutInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoInd()                                        (TRUE != FALSE)
#define Com_HasSigGrpEventFlag()                                      (TRUE != FALSE)
#define Com_HasSizeOfActivatableRxComIPdus()                          (TRUE != FALSE)
#define Com_HasSizeOfActivatableTxComIPdus()                          (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtr()                               (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrInd()                            (TRUE != FALSE)
#define Com_HasSizeOfConstValueArrayBased()                           (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt32()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt64()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8()                                (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                  (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                   (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                              (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCnt()                                   (TRUE != FALSE)
#define Com_HasSizeOfFilterInfo_UInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfFilterInfo_UInt8()                               (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                            (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferred()                            (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVector()                                   (TRUE != FALSE)
#define Com_HasSizeOfRepCnt()                                         (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCnt()                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoGrpSigInd()                          (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtr()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCache()                          (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmState()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferArrayBased()                          (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt32()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt64()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8()                               (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCnt()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfo()                                     (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoInd()                                  (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlag()                                (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBuffer()                                    (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt16()                           (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt32()                           (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt8()                            (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                (TRUE != FALSE)
#define Com_HasSizeOfTxBuffer()                                       (TRUE != FALSE)
#define Com_HasSizeOfTxFilterInitValueUInt16()                        (TRUE != FALSE)
#define Com_HasSizeOfTxFilterInitValueUInt8()                         (TRUE != FALSE)
#define Com_HasSizeOfTxFilterOldValueUInt16()                         (TRUE != FALSE)
#define Com_HasSizeOfTxFilterOldValueUInt8()                          (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMask()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoFilterInitValueInd()                    (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoInvValueInd()                           (TRUE != FALSE)
#define Com_HasSizeOfWaitingForConfirmation()                         (TRUE != FALSE)
#define Com_HasTmpRxBuffer()                                          (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt16()                                 (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt32()                                 (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt8()                                  (TRUE != FALSE)
#define Com_HasTransmitRequest()                                      (TRUE != FALSE)
#define Com_HasTxBuffer()                                             (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounter()                     (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThreshold()                   (TRUE != FALSE)
#define Com_HasTxDeadlineMonitoringISRLockCounter()                   (TRUE != FALSE)
#define Com_HasTxFilterInitValueUInt16()                              (TRUE != FALSE)
#define Com_HasTxFilterInitValueUInt8()                               (TRUE != FALSE)
#define Com_HasTxFilterOldValueUInt16()                               (TRUE != FALSE)
#define Com_HasTxFilterOldValueUInt8()                                (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounter()                            (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThreshold()                          (TRUE != FALSE)
#define Com_HasTxModeInfo()                                           (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                 (TRUE != FALSE)
#define Com_HasMinimumDelayOfTxModeInfo()                             (TRUE != FALSE)
#define Com_HasTxModeTrueIdxOfTxModeInfo()                            (TRUE != FALSE)
#define Com_HasTxModeTrueUsedOfTxModeInfo()                           (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueIndEndIdxOfTxModeInfo()        (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueIndStartIdxOfTxModeInfo()      (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueIndUsedOfTxModeInfo()          (TRUE != FALSE)
#define Com_HasTxModeTrue()                                           (TRUE != FALSE)
#define Com_HasDirectOfTxModeTrue()                                   (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeTrue()                                 (TRUE != FALSE)
#define Com_HasRepCntOfTxModeTrue()                                   (TRUE != FALSE)
#define Com_HasRepPeriodOfTxModeTrue()                                (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeTrue()                               (TRUE != FALSE)
#define Com_HasTxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasTxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfTxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfTxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfTxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxPduInfo()                                            (TRUE != FALSE)
#define Com_HasExternalIdOfTxPduInfo()                                (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxPduInfo()                          (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxPduInfo()                              (TRUE != FALSE)
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                      (TRUE != FALSE)
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                    (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                        (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndEndIdxOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndStartIdxOfTxPduInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndUsedOfTxPduInfo()                       (TRUE != FALSE)
#define Com_HasTxPduInitValue()                                       (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounter()                           (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThreshold()                         (TRUE != FALSE)
#define Com_HasTxSduLength()                                          (TRUE != FALSE)
#define Com_HasTxSigGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduOffsetOfTxSigGrpInfo()                              (TRUE != FALSE)
#define Com_HasTransferPropertyOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigGrpInfo()                         (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigGrpInfo()                         (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo()           (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo()           (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo()         (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasTxSigGrpMaskEndIdxOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskLengthOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskStartIdxOfTxSigGrpInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpMaskUsedOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxSigInfoInvValueIndEndIdxOfTxSigGrpInfo()             (TRUE != FALSE)
#define Com_HasTxSigInfoInvValueIndStartIdxOfTxSigGrpInfo()           (TRUE != FALSE)
#define Com_HasTxSigInfoInvValueIndUsedOfTxSigGrpInfo()               (TRUE != FALSE)
#define Com_HasTxSigGrpInfoInd()                                      (TRUE != FALSE)
#define Com_HasTxSigGrpMask()                                         (TRUE != FALSE)
#define Com_HasTxSigInfo()                                            (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                  (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                 (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                               (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                    (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasFilterInitValueIdxOfTxSigInfo()                        (TRUE != FALSE)
#define Com_HasFilterInitValueUsedOfTxSigInfo()                       (TRUE != FALSE)
#define Com_HasInvValueIdxOfTxSigInfo()                               (TRUE != FALSE)
#define Com_HasInvValueUsedOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasOnChangeIdxOfTxSigInfo()                               (TRUE != FALSE)
#define Com_HasOnChangeUsedOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfTxSigInfo()                    (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigInfo()                          (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIdxOfTxSigInfo()                           (TRUE != FALSE)
#define Com_HasTxSigGrpInfoUsedOfTxSigInfo()                          (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueInd()                          (TRUE != FALSE)
#define Com_HasTxSigInfoInvValueInd()                                 (TRUE != FALSE)
#define Com_HasWaitingForConfirmation()                               (TRUE != FALSE)
#define Com_HasPCConfig()                                             (TRUE != FALSE)
#define Com_HasActivatableRxComIPdusOfPCConfig()                      (TRUE != FALSE)
#define Com_HasActivatableTxComIPdusOfPCConfig()                      (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndOfPCConfig()                        (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrOfPCConfig()                           (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasConstValueArrayBasedOfPCConfig()                       (TRUE != FALSE)
#define Com_HasConstValueUInt16OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueUInt32OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueUInt64OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueUInt8OfPCConfig()                            (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                              (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                          (TRUE != FALSE)
#define Com_HasDelayTimeCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasFilterInfo_UInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasFilterInfo_UInt8OfPCConfig()                           (TRUE != FALSE)
#define Com_HasGatewayProcessingISRLockCounterOfPCConfig()            (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredOfPCConfig()                        (TRUE != FALSE)
#define Com_HasHandleTxPduDeferredOfPCConfig()                        (TRUE != FALSE)
#define Com_HasInitializedOfPCConfig()                                (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasPduGrpVectorOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRepCntOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRepCycleCntOfPCConfig()                                (TRUE != FALSE)
#define Com_HasRxAccessInfoGrpSigIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThresholdOfPCConfig()       (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCacheOfPCConfig()                      (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThresholdOfPCConfig()       (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterOfPCConfig()                  (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThresholdOfPCConfig()                (TRUE != FALSE)
#define Com_HasRxPduDmStateOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedOfPCConfig()                      (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferUInt32OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferUInt64OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8OfPCConfig()                           (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasRxSigGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxTOutCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxTOutInfoIndOfPCConfig()                              (TRUE != FALSE)
#define Com_HasRxTOutInfoOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasSigGrpEventFlagOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfActivatableRxComIPdusOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfActivatableTxComIPdusOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrOfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueArrayBasedOfPCConfig()                 (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt32OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt64OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8OfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                        (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCntOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfFilterInfo_UInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfFilterInfo_UInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferredOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVectorOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRepCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCntOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoGrpSigIndOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtrOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCacheOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmStateOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferArrayBasedOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt32OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt64OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCntOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoIndOfPCConfig()                        (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlagOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBufferOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt16OfPCConfig()                 (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt32OfPCConfig()                 (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferUInt8OfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxBufferOfPCConfig()                             (TRUE != FALSE)
#define Com_HasSizeOfTxFilterInitValueUInt16OfPCConfig()              (TRUE != FALSE)
#define Com_HasSizeOfTxFilterInitValueUInt8OfPCConfig()               (TRUE != FALSE)
#define Com_HasSizeOfTxFilterOldValueUInt16OfPCConfig()               (TRUE != FALSE)
#define Com_HasSizeOfTxFilterOldValueUInt8OfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMaskOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoFilterInitValueIndOfPCConfig()          (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoInvValueIndOfPCConfig()                 (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfWaitingForConfirmationOfPCConfig()               (TRUE != FALSE)
#define Com_HasTmpRxBufferOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt16OfPCConfig()                       (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt32OfPCConfig()                       (TRUE != FALSE)
#define Com_HasTmpRxShdBufferUInt8OfPCConfig()                        (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxBufferOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounterOfPCConfig()           (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThresholdOfPCConfig()         (TRUE != FALSE)
#define Com_HasTxDeadlineMonitoringISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasTxFilterInitValueUInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasTxFilterInitValueUInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasTxFilterOldValueUInt16OfPCConfig()                     (TRUE != FALSE)
#define Com_HasTxFilterOldValueUInt8OfPCConfig()                      (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterOfPCConfig()                  (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThresholdOfPCConfig()                (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterOfPCConfig()                 (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThresholdOfPCConfig()               (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxSigGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigGrpMaskOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueIndOfPCConfig()                (TRUE != FALSE)
#define Com_HasTxSigInfoInvValueIndOfPCConfig()                       (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasWaitingForConfirmationOfPCConfig()                     (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIncrementDataMacros  Com Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)++
#define Com_IncDelayTimeCnt(Index)                                    Com_GetDelayTimeCnt(Index)++
#define Com_IncGatewayProcessingISRLockCounter()                      Com_GetGatewayProcessingISRLockCounter()++
#define Com_IncHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRepCnt(Index)                                          Com_GetRepCnt(Index)++
#define Com_IncRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)++
#define Com_IncRxDeadlineMonitoringISRLockCounter()                   Com_GetRxDeadlineMonitoringISRLockCounter()++
#define Com_IncRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxDeferredFctPtrCache(Index)                           Com_GetRxDeferredFctPtrCache(Index)++
#define Com_IncRxDeferredProcessingISRLockCounter()                   Com_GetRxDeferredProcessingISRLockCounter()++
#define Com_IncRxIPduGroupISRLockCounter()                            Com_GetRxIPduGroupISRLockCounter()++
#define Com_IncRxSigBufferArrayBased(Index)                           Com_GetRxSigBufferArrayBased(Index)++
#define Com_IncRxSigBufferUInt16(Index)                               Com_GetRxSigBufferUInt16(Index)++
#define Com_IncRxSigBufferUInt32(Index)                               Com_GetRxSigBufferUInt32(Index)++
#define Com_IncRxSigBufferUInt64(Index)                               Com_GetRxSigBufferUInt64(Index)++
#define Com_IncRxSigBufferUInt8(Index)                                Com_GetRxSigBufferUInt8(Index)++
#define Com_IncRxTOutCnt(Index)                                       Com_GetRxTOutCnt(Index)++
#define Com_IncSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)++
#define Com_IncTmpRxBuffer(Index)                                     Com_GetTmpRxBuffer(Index)++
#define Com_IncTmpRxShdBufferUInt16(Index)                            Com_GetTmpRxShdBufferUInt16(Index)++
#define Com_IncTmpRxShdBufferUInt32(Index)                            Com_GetTmpRxShdBufferUInt32(Index)++
#define Com_IncTmpRxShdBufferUInt8(Index)                             Com_GetTmpRxShdBufferUInt8(Index)++
#define Com_IncTxBuffer(Index)                                        Com_GetTxBuffer(Index)++
#define Com_IncTxCyclicProcessingISRLockCounter()                     Com_GetTxCyclicProcessingISRLockCounter()++
#define Com_IncTxDeadlineMonitoringISRLockCounter()                   Com_GetTxDeadlineMonitoringISRLockCounter()++
#define Com_IncTxFilterOldValueUInt16(Index)                          Com_GetTxFilterOldValueUInt16(Index)++
#define Com_IncTxFilterOldValueUInt8(Index)                           Com_GetTxFilterOldValueUInt8(Index)++
#define Com_IncTxIPduGroupISRLockCounter()                            Com_GetTxIPduGroupISRLockCounter()++
#define Com_IncTxProcessingISRLockCounter()                           Com_GetTxProcessingISRLockCounter()++
#define Com_IncTxSduLength(Index)                                     Com_GetTxSduLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComPCDecrementDataMacros  Com Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)--
#define Com_DecDelayTimeCnt(Index)                                    Com_GetDelayTimeCnt(Index)--
#define Com_DecGatewayProcessingISRLockCounter()                      Com_GetGatewayProcessingISRLockCounter()--
#define Com_DecHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRepCnt(Index)                                          Com_GetRepCnt(Index)--
#define Com_DecRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)--
#define Com_DecRxDeadlineMonitoringISRLockCounter()                   Com_GetRxDeadlineMonitoringISRLockCounter()--
#define Com_DecRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxDeferredFctPtrCache(Index)                           Com_GetRxDeferredFctPtrCache(Index)--
#define Com_DecRxDeferredProcessingISRLockCounter()                   Com_GetRxDeferredProcessingISRLockCounter()--
#define Com_DecRxIPduGroupISRLockCounter()                            Com_GetRxIPduGroupISRLockCounter()--
#define Com_DecRxSigBufferArrayBased(Index)                           Com_GetRxSigBufferArrayBased(Index)--
#define Com_DecRxSigBufferUInt16(Index)                               Com_GetRxSigBufferUInt16(Index)--
#define Com_DecRxSigBufferUInt32(Index)                               Com_GetRxSigBufferUInt32(Index)--
#define Com_DecRxSigBufferUInt64(Index)                               Com_GetRxSigBufferUInt64(Index)--
#define Com_DecRxSigBufferUInt8(Index)                                Com_GetRxSigBufferUInt8(Index)--
#define Com_DecRxTOutCnt(Index)                                       Com_GetRxTOutCnt(Index)--
#define Com_DecSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)--
#define Com_DecTmpRxBuffer(Index)                                     Com_GetTmpRxBuffer(Index)--
#define Com_DecTmpRxShdBufferUInt16(Index)                            Com_GetTmpRxShdBufferUInt16(Index)--
#define Com_DecTmpRxShdBufferUInt32(Index)                            Com_GetTmpRxShdBufferUInt32(Index)--
#define Com_DecTmpRxShdBufferUInt8(Index)                             Com_GetTmpRxShdBufferUInt8(Index)--
#define Com_DecTxBuffer(Index)                                        Com_GetTxBuffer(Index)--
#define Com_DecTxCyclicProcessingISRLockCounter()                     Com_GetTxCyclicProcessingISRLockCounter()--
#define Com_DecTxDeadlineMonitoringISRLockCounter()                   Com_GetTxDeadlineMonitoringISRLockCounter()--
#define Com_DecTxFilterOldValueUInt16(Index)                          Com_GetTxFilterOldValueUInt16(Index)--
#define Com_DecTxFilterOldValueUInt8(Index)                           Com_GetTxFilterOldValueUInt8(Index)--
#define Com_DecTxIPduGroupISRLockCounter()                            Com_GetTxIPduGroupISRLockCounter()--
#define Com_DecTxProcessingISRLockCounter()                           Com_GetTxProcessingISRLockCounter()--
#define Com_DecTxSduLength(Index)                                     Com_GetTxSduLength(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCIterableTypes  Com Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Com_ActivatableRxComIPdus */
typedef uint8_least Com_ActivatableRxComIPdusIterType;

/**   \brief  type used to iterate Com_ActivatableTxComIPdus */
typedef uint8_least Com_ActivatableTxComIPdusIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtr */
typedef uint8_least Com_CbkRxTOutFuncPtrIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtrInd */
typedef uint8_least Com_CbkRxTOutFuncPtrIndIterType;

/**   \brief  type used to iterate Com_ConstValueArrayBased */
typedef uint8_least Com_ConstValueArrayBasedIterType;

/**   \brief  type used to iterate Com_ConstValueUInt16 */
typedef uint8_least Com_ConstValueUInt16IterType;

/**   \brief  type used to iterate Com_ConstValueUInt32 */
typedef uint8_least Com_ConstValueUInt32IterType;

/**   \brief  type used to iterate Com_ConstValueUInt64 */
typedef uint8_least Com_ConstValueUInt64IterType;

/**   \brief  type used to iterate Com_ConstValueUInt8 */
typedef uint8_least Com_ConstValueUInt8IterType;

/**   \brief  type used to iterate Com_FilterInfo_UInt16 */
typedef uint8_least Com_FilterInfo_UInt16IterType;

/**   \brief  type used to iterate Com_FilterInfo_UInt8 */
typedef uint8_least Com_FilterInfo_UInt8IterType;

/**   \brief  type used to iterate Com_HandleRxPduDeferred */
typedef uint8_least Com_HandleRxPduDeferredIterType;

/**   \brief  type used to iterate Com_PduGrpVector */
typedef uint8_least Com_PduGrpVectorIterType;

/**   \brief  type used to iterate Com_RxAccessInfo */
typedef uint8_least Com_RxAccessInfoIterType;

/**   \brief  type used to iterate Com_RxAccessInfoGrpSigInd */
typedef uint8_least Com_RxAccessInfoGrpSigIndIterType;

/**   \brief  type used to iterate Com_RxAccessInfoInd */
typedef uint8_least Com_RxAccessInfoIndIterType;

/**   \brief  type used to iterate Com_RxCbkFuncPtr */
typedef uint8_least Com_RxCbkFuncPtrIterType;

/**   \brief  type used to iterate Com_RxDefPduBuffer */
typedef uint8_least Com_RxDefPduBufferIterType;

/**   \brief  type used to iterate Com_RxDeferredFctPtrCache */
typedef uint8_least Com_RxDeferredFctPtrCacheIterType;

/**   \brief  type used to iterate Com_RxPduGrpInfo */
typedef uint8_least Com_RxPduGrpInfoIterType;

/**   \brief  type used to iterate Com_RxPduInfo */
typedef uint8_least Com_RxPduInfoIterType;

/**   \brief  type used to iterate Com_RxSigBufferArrayBased */
typedef uint8_least Com_RxSigBufferArrayBasedIterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt16 */
typedef uint8_least Com_RxSigBufferUInt16IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt32 */
typedef uint8_least Com_RxSigBufferUInt32IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt64 */
typedef uint8_least Com_RxSigBufferUInt64IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt8 */
typedef uint8_least Com_RxSigBufferUInt8IterType;

/**   \brief  type used to iterate Com_RxSigGrpInfo */
typedef uint8_least Com_RxSigGrpInfoIterType;

/**   \brief  type used to iterate Com_RxSigGrpInfoInd */
typedef uint8_least Com_RxSigGrpInfoIndIterType;

/**   \brief  type used to iterate Com_RxSigInfo */
typedef uint8_least Com_RxSigInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfo */
typedef uint8_least Com_RxTOutInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfoInd */
typedef uint8_least Com_RxTOutInfoIndIterType;

/**   \brief  type used to iterate Com_TmpRxBuffer */
typedef uint8_least Com_TmpRxBufferIterType;

/**   \brief  type used to iterate Com_TmpRxShdBufferUInt16 */
typedef uint8_least Com_TmpRxShdBufferUInt16IterType;

/**   \brief  type used to iterate Com_TmpRxShdBufferUInt32 */
typedef uint8_least Com_TmpRxShdBufferUInt32IterType;

/**   \brief  type used to iterate Com_TmpRxShdBufferUInt8 */
typedef uint8_least Com_TmpRxShdBufferUInt8IterType;

/**   \brief  type used to iterate Com_TxBuffer */
typedef uint16_least Com_TxBufferIterType;

/**   \brief  type used to iterate Com_TxFilterInitValueUInt16 */
typedef uint8_least Com_TxFilterInitValueUInt16IterType;

/**   \brief  type used to iterate Com_TxFilterInitValueUInt8 */
typedef uint8_least Com_TxFilterInitValueUInt8IterType;

/**   \brief  type used to iterate Com_TxModeInfo */
typedef uint8_least Com_TxModeInfoIterType;

/**   \brief  type used to iterate Com_TxModeTrue */
typedef uint8_least Com_TxModeTrueIterType;

/**   \brief  type used to iterate Com_TxPduGrpInfo */
typedef uint8_least Com_TxPduGrpInfoIterType;

/**   \brief  type used to iterate Com_TxPduInfo */
typedef uint8_least Com_TxPduInfoIterType;

/**   \brief  type used to iterate Com_TxPduInitValue */
typedef uint8_least Com_TxPduInitValueIterType;

/**   \brief  type used to iterate Com_TxSigGrpInfo */
typedef uint8_least Com_TxSigGrpInfoIterType;

/**   \brief  type used to iterate Com_TxSigGrpInfoInd */
typedef uint8_least Com_TxSigGrpInfoIndIterType;

/**   \brief  type used to iterate Com_TxSigGrpMask */
typedef uint8_least Com_TxSigGrpMaskIterType;

/**   \brief  type used to iterate Com_TxSigInfo */
typedef uint8_least Com_TxSigInfoIterType;

/**   \brief  type used to iterate Com_TxSigInfoFilterInitValueInd */
typedef uint8_least Com_TxSigInfoFilterInitValueIndIterType;

/**   \brief  type used to iterate Com_TxSigInfoInvValueInd */
typedef uint8_least Com_TxSigInfoInvValueIndIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCIterableTypesWithSizeRelations  Com Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Com_CurrentTxMode */
typedef Com_TxPduInfoIterType Com_CurrentTxModeIterType;

/**   \brief  type used to iterate Com_CycleTimeCnt */
typedef Com_TxPduInfoIterType Com_CycleTimeCntIterType;

/**   \brief  type used to iterate Com_CyclicSendRequest */
typedef Com_TxPduInfoIterType Com_CyclicSendRequestIterType;

/**   \brief  type used to iterate Com_DelayTimeCnt */
typedef Com_TxPduInfoIterType Com_DelayTimeCntIterType;

/**   \brief  type used to iterate Com_HandleTxPduDeferred */
typedef Com_TxPduInfoIterType Com_HandleTxPduDeferredIterType;

/**   \brief  type used to iterate Com_RepCnt */
typedef Com_TxPduInfoIterType Com_RepCntIterType;

/**   \brief  type used to iterate Com_RepCycleCnt */
typedef Com_TxPduInfoIterType Com_RepCycleCntIterType;

/**   \brief  type used to iterate Com_RxPduDmState */
typedef Com_RxTOutInfoIterType Com_RxPduDmStateIterType;

/**   \brief  type used to iterate Com_RxPduGrpActive */
typedef Com_RxPduInfoIterType Com_RxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_RxTOutCnt */
typedef Com_RxTOutInfoIterType Com_RxTOutCntIterType;

/**   \brief  type used to iterate Com_SigGrpEventFlag */
typedef Com_TxSigGrpInfoIterType Com_SigGrpEventFlagIterType;

/**   \brief  type used to iterate Com_TransmitRequest */
typedef Com_TxPduInfoIterType Com_TransmitRequestIterType;

/**   \brief  type used to iterate Com_TxFilterOldValueUInt16 */
typedef Com_TxFilterInitValueUInt16IterType Com_TxFilterOldValueUInt16IterType;

/**   \brief  type used to iterate Com_TxFilterOldValueUInt8 */
typedef Com_TxFilterInitValueUInt8IterType Com_TxFilterOldValueUInt8IterType;

/**   \brief  type used to iterate Com_TxPduGrpActive */
typedef Com_TxPduInfoIterType Com_TxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TxSduLength */
typedef Com_TxPduInfoIterType Com_TxSduLengthIterType;

/**   \brief  type used to iterate Com_WaitingForConfirmation */
typedef Com_TxPduInfoIterType Com_WaitingForConfirmationIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCValueTypes  Com Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Com_RxPduInfoIdxOfActivatableRxComIPdus */
typedef uint8 Com_RxPduInfoIdxOfActivatableRxComIPdusType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfActivatableTxComIPdus */
typedef uint8 Com_TxPduInfoIdxOfActivatableTxComIPdusType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrInd */
typedef uint8 Com_CbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  value based type definition for Com_ConstValueArrayBased */
typedef uint8 Com_ConstValueArrayBasedType;

/**   \brief  value based type definition for Com_ConstValueUInt16 */
typedef uint16 Com_ConstValueUInt16Type;

/**   \brief  value based type definition for Com_ConstValueUInt32 */
typedef uint32 Com_ConstValueUInt32Type;

/**   \brief  value based type definition for Com_ConstValueUInt64 */
typedef uint64 Com_ConstValueUInt64Type;

/**   \brief  value based type definition for Com_ConstValueUInt8 */
typedef uint8 Com_ConstValueUInt8Type;

/**   \brief  value based type definition for Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  value based type definition for Com_CycleTimeCnt */
typedef uint16 Com_CycleTimeCntType;

/**   \brief  value based type definition for Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  value based type definition for Com_DelayTimeCnt */
typedef uint8 Com_DelayTimeCntType;

/**   \brief  value based type definition for Com_FilterAlgoOfFilterInfo_UInt16 */
typedef uint8 Com_FilterAlgoOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_FilterMaskOfFilterInfo_UInt16 */
typedef uint16 Com_FilterMaskOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_FilterMaxOfFilterInfo_UInt16 */
typedef uint16 Com_FilterMaxOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_FilterMinOfFilterInfo_UInt16 */
typedef uint16 Com_FilterMinOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_FilterXOfFilterInfo_UInt16 */
typedef uint16 Com_FilterXOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_FilterAlgoOfFilterInfo_UInt8 */
typedef uint8 Com_FilterAlgoOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_FilterMaskOfFilterInfo_UInt8 */
typedef uint8 Com_FilterMaskOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_FilterMaxOfFilterInfo_UInt8 */
typedef uint8 Com_FilterMaxOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_FilterMinOfFilterInfo_UInt8 */
typedef uint8 Com_FilterMinOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_FilterXOfFilterInfo_UInt8 */
typedef uint8 Com_FilterXOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_GatewayProcessingISRLockCounter */
typedef uint16 Com_GatewayProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  value based type definition for Com_HandleTxPduDeferred */
typedef boolean Com_HandleTxPduDeferredType;

/**   \brief  value based type definition for Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  value based type definition for Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  value based type definition for Com_PduGrpVector */
typedef uint8 Com_PduGrpVectorType;

/**   \brief  value based type definition for Com_RepCnt */
typedef uint16 Com_RepCntType;

/**   \brief  value based type definition for Com_RepCycleCnt */
typedef uint16 Com_RepCycleCntType;

/**   \brief  value based type definition for Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitLengthOfRxAccessInfo */
typedef uint8 Com_BitLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferIdxOfRxAccessInfo */
typedef uint8 Com_BufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferUsedOfRxAccessInfo */
typedef boolean Com_BufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo */
typedef uint8 Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfo */
typedef uint8 Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo */
typedef uint8 Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueUsedOfRxAccessInfo */
typedef boolean Com_ConstValueArrayBasedInitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueIdxOfRxAccessInfo */
typedef uint8 Com_InitValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueUsedOfRxAccessInfo */
typedef boolean Com_InitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InvValueIdxOfRxAccessInfo */
typedef uint8 Com_InvValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InvValueUsedOfRxAccessInfo */
typedef boolean Com_InvValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_IsGroupSignalOfRxAccessInfo */
typedef boolean Com_IsGroupSignalOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo */
typedef uint8 Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo */
typedef boolean Com_RxDataTimeoutSubstitutionValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxPduInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo */
typedef uint8 Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfo */
typedef uint8 Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo */
typedef uint8 Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfo */
typedef boolean Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxAccessInfo */
typedef boolean Com_RxTOutInfoUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ShdBufferIdxOfRxAccessInfo */
typedef uint8 Com_ShdBufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ShdBufferUsedOfRxAccessInfo */
typedef boolean Com_ShdBufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfRxAccessInfo */
typedef uint8 Com_StartByteInPduPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_TmpBufferIdxOfRxAccessInfo */
typedef uint8 Com_TmpBufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_TmpBufferUsedOfRxAccessInfo */
typedef boolean Com_TmpBufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoGrpSigInd */
typedef uint8 Com_RxAccessInfoGrpSigIndType;

/**   \brief  value based type definition for Com_RxAccessInfoInd */
typedef uint8 Com_RxAccessInfoIndType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_RxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockThreshold */
typedef uint8 Com_RxDeadlineMonitoringISRLockThresholdType;

/**   \brief  value based type definition for Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  value based type definition for Com_RxDeferredFctPtrCache */
typedef uint32 Com_RxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockCounter */
typedef uint16 Com_RxDeferredProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockThreshold */
typedef uint8 Com_RxDeferredProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounter */
typedef uint16 Com_RxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockThreshold */
typedef uint8 Com_RxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_RxPduDmState */
typedef uint8 Com_RxPduDmStateType;

/**   \brief  value based type definition for Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  value based type definition for Com_PduGrpVectorEndIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorStartIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorUsedOfRxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigGrpInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigGrpInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigGrpInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxSigGrpInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxPduInfo */
typedef uint8 Com_SignalProcessingOfRxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfRxPduInfo */
typedef uint8 Com_TypeOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBased */
typedef uint8 Com_RxSigBufferArrayBasedType;

/**   \brief  value based type definition for Com_RxSigBufferUInt16 */
typedef uint16 Com_RxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt32 */
typedef uint32 Com_RxSigBufferUInt32Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt64 */
typedef uint64 Com_RxSigBufferUInt64Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt8 */
typedef uint8 Com_RxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_InvEventOfRxSigGrpInfo */
typedef boolean Com_InvEventOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo */
typedef uint8 Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo */
typedef uint8 Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoGrpSigIndUsedOfRxSigGrpInfo */
typedef boolean Com_RxAccessInfoGrpSigIndUsedOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckIdxOfRxSigGrpInfo */
typedef uint8 Com_RxCbkFuncPtrAckIdxOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckUsedOfRxSigGrpInfo */
typedef boolean Com_RxCbkFuncPtrAckUsedOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxSigGrpInfo */
typedef uint8 Com_RxPduInfoIdxOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxSigGrpInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxSigGrpInfo */
typedef boolean Com_RxTOutInfoUsedOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_ShdBufferRequiredOfRxSigGrpInfo */
typedef boolean Com_ShdBufferRequiredOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigGrpInfo */
typedef uint8 Com_SignalProcessingOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_StartBytePositionOfRxSigGrpInfo */
typedef uint8 Com_StartBytePositionOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigGrpInfo */
typedef uint8 Com_ValidDlcOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_RxSigGrpInfoInd */
typedef uint8 Com_RxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckIdxOfRxSigInfo */
typedef uint8 Com_RxCbkFuncPtrAckIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckUsedOfRxSigInfo */
typedef boolean Com_RxCbkFuncPtrAckUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxSigInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxSigInfo */
typedef boolean Com_RxTOutInfoUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutCnt */
typedef uint16 Com_RxTOutCntType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfo */
typedef boolean Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FactorOfRxTOutInfo */
typedef uint16 Com_FactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FirstFactorOfRxTOutInfo */
typedef uint8 Com_FirstFactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxTOutInfo */
typedef uint8 Com_RxPduInfoIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoInd */
typedef uint8 Com_RxTOutInfoIndType;

/**   \brief  value based type definition for Com_SigGrpEventFlag */
typedef uint8 Com_SigGrpEventFlagType;

/**   \brief  value based type definition for Com_SizeOfActivatableRxComIPdus */
typedef uint8 Com_SizeOfActivatableRxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfActivatableTxComIPdus */
typedef uint8 Com_SizeOfActivatableTxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtr */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtrInd */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_SizeOfConstValueArrayBased */
typedef uint8 Com_SizeOfConstValueArrayBasedType;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt16 */
typedef uint8 Com_SizeOfConstValueUInt16Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt32 */
typedef uint8 Com_SizeOfConstValueUInt32Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt64 */
typedef uint8 Com_SizeOfConstValueUInt64Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt8 */
typedef uint8 Com_SizeOfConstValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  value based type definition for Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  value based type definition for Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  value based type definition for Com_SizeOfDelayTimeCnt */
typedef uint8 Com_SizeOfDelayTimeCntType;

/**   \brief  value based type definition for Com_SizeOfFilterInfo_UInt16 */
typedef uint8 Com_SizeOfFilterInfo_UInt16Type;

/**   \brief  value based type definition for Com_SizeOfFilterInfo_UInt8 */
typedef uint8 Com_SizeOfFilterInfo_UInt8Type;

/**   \brief  value based type definition for Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfHandleTxPduDeferred */
typedef uint8 Com_SizeOfHandleTxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfPduGrpVector */
typedef uint8 Com_SizeOfPduGrpVectorType;

/**   \brief  value based type definition for Com_SizeOfRepCnt */
typedef uint8 Com_SizeOfRepCntType;

/**   \brief  value based type definition for Com_SizeOfRepCycleCnt */
typedef uint8 Com_SizeOfRepCycleCntType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfo */
typedef uint8 Com_SizeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoGrpSigInd */
typedef uint8 Com_SizeOfRxAccessInfoGrpSigIndType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoInd */
typedef uint8 Com_SizeOfRxAccessInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxCbkFuncPtr */
typedef uint8 Com_SizeOfRxCbkFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfRxDefPduBuffer */
typedef uint8 Com_SizeOfRxDefPduBufferType;

/**   \brief  value based type definition for Com_SizeOfRxDeferredFctPtrCache */
typedef uint8 Com_SizeOfRxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_SizeOfRxPduDmState */
typedef uint8 Com_SizeOfRxPduDmStateType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpInfo */
typedef uint8 Com_SizeOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferArrayBased */
typedef uint8 Com_SizeOfRxSigBufferArrayBasedType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt16 */
typedef uint8 Com_SizeOfRxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt32 */
typedef uint8 Com_SizeOfRxSigBufferUInt32Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt64 */
typedef uint8 Com_SizeOfRxSigBufferUInt64Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt8 */
typedef uint8 Com_SizeOfRxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_SizeOfRxSigGrpInfo */
typedef uint8 Com_SizeOfRxSigGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfRxSigGrpInfoInd */
typedef uint8 Com_SizeOfRxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxSigInfo */
typedef uint8 Com_SizeOfRxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutCnt */
typedef uint8 Com_SizeOfRxTOutCntType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfo */
typedef uint8 Com_SizeOfRxTOutInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfoInd */
typedef uint8 Com_SizeOfRxTOutInfoIndType;

/**   \brief  value based type definition for Com_SizeOfSigGrpEventFlag */
typedef uint8 Com_SizeOfSigGrpEventFlagType;

/**   \brief  value based type definition for Com_SizeOfTmpRxBuffer */
typedef uint8 Com_SizeOfTmpRxBufferType;

/**   \brief  value based type definition for Com_SizeOfTmpRxShdBufferUInt16 */
typedef uint8 Com_SizeOfTmpRxShdBufferUInt16Type;

/**   \brief  value based type definition for Com_SizeOfTmpRxShdBufferUInt32 */
typedef uint8 Com_SizeOfTmpRxShdBufferUInt32Type;

/**   \brief  value based type definition for Com_SizeOfTmpRxShdBufferUInt8 */
typedef uint8 Com_SizeOfTmpRxShdBufferUInt8Type;

/**   \brief  value based type definition for Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  value based type definition for Com_SizeOfTxBuffer */
typedef uint16 Com_SizeOfTxBufferType;

/**   \brief  value based type definition for Com_SizeOfTxFilterInitValueUInt16 */
typedef uint8 Com_SizeOfTxFilterInitValueUInt16Type;

/**   \brief  value based type definition for Com_SizeOfTxFilterInitValueUInt8 */
typedef uint8 Com_SizeOfTxFilterInitValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfTxFilterOldValueUInt16 */
typedef uint8 Com_SizeOfTxFilterOldValueUInt16Type;

/**   \brief  value based type definition for Com_SizeOfTxFilterOldValueUInt8 */
typedef uint8 Com_SizeOfTxFilterOldValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  value based type definition for Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpInfo */
typedef uint8 Com_SizeOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInitValue */
typedef uint8 Com_SizeOfTxPduInitValueType;

/**   \brief  value based type definition for Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpInfo */
typedef uint8 Com_SizeOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpInfoInd */
typedef uint8 Com_SizeOfTxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpMask */
typedef uint8 Com_SizeOfTxSigGrpMaskType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfoFilterInitValueInd */
typedef uint8 Com_SizeOfTxSigInfoFilterInitValueIndType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfoInvValueInd */
typedef uint8 Com_SizeOfTxSigInfoInvValueIndType;

/**   \brief  value based type definition for Com_SizeOfWaitingForConfirmation */
typedef uint8 Com_SizeOfWaitingForConfirmationType;

/**   \brief  value based type definition for Com_TmpRxBuffer */
typedef uint8 Com_TmpRxBufferType;

/**   \brief  value based type definition for Com_TmpRxShdBufferUInt16 */
typedef uint16 Com_TmpRxShdBufferUInt16Type;

/**   \brief  value based type definition for Com_TmpRxShdBufferUInt32 */
typedef uint32 Com_TmpRxShdBufferUInt32Type;

/**   \brief  value based type definition for Com_TmpRxShdBufferUInt8 */
typedef uint8 Com_TmpRxShdBufferUInt8Type;

/**   \brief  value based type definition for Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  value based type definition for Com_TxBuffer */
typedef uint8 Com_TxBufferType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockCounter */
typedef uint16 Com_TxCyclicProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockThreshold */
typedef uint8 Com_TxCyclicProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_TxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_TxFilterInitValueUInt16 */
typedef uint16 Com_TxFilterInitValueUInt16Type;

/**   \brief  value based type definition for Com_TxFilterInitValueUInt8 */
typedef uint8 Com_TxFilterInitValueUInt8Type;

/**   \brief  value based type definition for Com_TxFilterOldValueUInt16 */
typedef uint16 Com_TxFilterOldValueUInt16Type;

/**   \brief  value based type definition for Com_TxFilterOldValueUInt8 */
typedef uint8 Com_TxFilterOldValueUInt8Type;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounter */
typedef uint16 Com_TxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockThreshold */
typedef uint8 Com_TxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  value based type definition for Com_MinimumDelayOfTxModeInfo */
typedef uint8 Com_MinimumDelayOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueUsedOfTxModeInfo */
typedef boolean Com_TxModeTrueUsedOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxSigInfoFilterInitValueIndEndIdxOfTxModeInfo */
typedef uint8 Com_TxSigInfoFilterInitValueIndEndIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxSigInfoFilterInitValueIndStartIdxOfTxModeInfo */
typedef uint8 Com_TxSigInfoFilterInitValueIndStartIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxSigInfoFilterInitValueIndUsedOfTxModeInfo */
typedef boolean Com_TxSigInfoFilterInitValueIndUsedOfTxModeInfoType;

/**   \brief  value based type definition for Com_DirectOfTxModeTrue */
typedef boolean Com_DirectOfTxModeTrueType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  value based type definition for Com_RepCntOfTxModeTrue */
typedef uint8 Com_RepCntOfTxModeTrueType;

/**   \brief  value based type definition for Com_RepPeriodOfTxModeTrue */
typedef uint8 Com_RepPeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeTrue */
typedef uint16 Com_TimePeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  value based type definition for Com_PduGrpVectorEndIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorStartIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorUsedOfTxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxPduInfo */
typedef uint8 Com_TxBufferEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxPduInfo */
typedef uint8 Com_TxBufferLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxPduInfo */
typedef uint8 Com_TxBufferStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxPduInfo */
typedef boolean Com_TxBufferUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndUsedOfTxPduInfo */
typedef boolean Com_TxSigGrpInfoIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounter */
typedef uint16 Com_TxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxProcessingISRLockThreshold */
typedef uint8 Com_TxProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  value based type definition for Com_PduOffsetOfTxSigGrpInfo */
typedef uint8 Com_PduOffsetOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TransferPropertyOfTxSigGrpInfo */
typedef uint8 Com_TransferPropertyOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigGrpInfo */
typedef uint8 Com_TxBufferLengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo */
typedef uint8 Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigGrpInfo */
typedef boolean Com_TxBufferUsedOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigGrpInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskLengthOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskLengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskUsedOfTxSigGrpInfo */
typedef boolean Com_TxSigGrpMaskUsedOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigInfoInvValueIndEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigInfoInvValueIndEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigInfoInvValueIndStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigInfoInvValueIndStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigInfoInvValueIndUsedOfTxSigGrpInfo */
typedef boolean Com_TxSigInfoInvValueIndUsedOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoInd */
typedef uint8 Com_TxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_TxSigGrpMask */
typedef uint8 Com_TxSigGrpMaskType;

/**   \brief  value based type definition for Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitLengthOfTxSigInfo */
typedef uint8 Com_BitLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitPositionOfTxSigInfo */
typedef uint8 Com_BitPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_FilterInitValueIdxOfTxSigInfo */
typedef uint8 Com_FilterInitValueIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_FilterInitValueUsedOfTxSigInfo */
typedef boolean Com_FilterInitValueUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_InvValueIdxOfTxSigInfo */
typedef uint8 Com_InvValueIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_InvValueUsedOfTxSigInfo */
typedef boolean Com_InvValueUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_OnChangeIdxOfTxSigInfo */
typedef uint8 Com_OnChangeIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_OnChangeUsedOfTxSigInfo */
typedef boolean Com_OnChangeUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfTxSigInfo */
typedef uint8 Com_StartByteInPduPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigInfo */
typedef uint16 Com_TxBufferEndIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigInfo */
typedef uint8 Com_TxBufferLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigInfo */
typedef uint16 Com_TxBufferStartIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigInfo */
typedef boolean Com_TxBufferUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIdxOfTxSigInfo */
typedef uint8 Com_TxSigGrpInfoIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoUsedOfTxSigInfo */
typedef boolean Com_TxSigGrpInfoUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxSigInfoFilterInitValueInd */
typedef uint8 Com_TxSigInfoFilterInitValueIndType;

/**   \brief  value based type definition for Com_TxSigInfoInvValueInd */
typedef uint8 Com_TxSigInfoInvValueIndType;

/**   \brief  value based type definition for Com_WaitingForConfirmation */
typedef boolean Com_WaitingForConfirmationType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCStructTypes  Com Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Com_ActivatableRxComIPdus */
typedef struct sCom_ActivatableRxComIPdusType
{
  uint8 Com_ActivatableRxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_ActivatableRxComIPdusType;

/**   \brief  type used in Com_ActivatableTxComIPdus */
typedef struct sCom_ActivatableTxComIPdusType
{
  uint8 Com_ActivatableTxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_ActivatableTxComIPdusType;

/**   \brief  type used in Com_FilterInfo_UInt16 */
typedef struct sCom_FilterInfo_UInt16Type
{
  uint8 Com_FilterInfo_UInt16NeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_FilterInfo_UInt16Type;

/**   \brief  type used in Com_FilterInfo_UInt8 */
typedef struct sCom_FilterInfo_UInt8Type
{
  uint8 Com_FilterInfo_UInt8NeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_FilterInfo_UInt8Type;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_InitValueUsedOfRxAccessInfoType InitValueUsedOfRxAccessInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
  Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfoType RxSigBufferArrayBasedBufferUsedOfRxAccessInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased */
  Com_ShdBufferUsedOfRxAccessInfoType ShdBufferUsedOfRxAccessInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64 */
  Com_ApplTypeOfRxAccessInfoType ApplTypeOfRxAccessInfo;  /**< Application data type. */
  Com_BitLengthOfRxAccessInfoType BitLengthOfRxAccessInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfRxAccessInfoType BitPositionOfRxAccessInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BufferIdxOfRxAccessInfoType BufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64 */
  Com_BusAccOfRxAccessInfoType BusAccOfRxAccessInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfRxAccessInfoType ByteLengthOfRxAccessInfo;  /**< Byte length of the signal or group signal. */
  Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfoType ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo;  /**< the end index of the 0:n relation pointing to Com_ConstValueArrayBased */
  Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfoType ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo;  /**< the start index of the 0:n relation pointing to Com_ConstValueArrayBased */
  Com_InvValueIdxOfRxAccessInfoType InvValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
  Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfoType RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
  Com_RxPduInfoIdxOfRxAccessInfoType RxPduInfoIdxOfRxAccessInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
  Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfoType RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased */
  Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfoType RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased */
  Com_RxTOutInfoIdxOfRxAccessInfoType RxTOutInfoIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_ShdBufferIdxOfRxAccessInfoType ShdBufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64 */
  Com_StartByteInPduPositionOfRxAccessInfoType StartByteInPduPositionOfRxAccessInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TmpBufferIdxOfRxAccessInfoType TmpBufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_TmpRxShdBufferUInt8,Com_TmpRxShdBufferUInt16,Com_TmpRxShdBufferUInt32,Com_TmpRxShdBufferUInt64,Com_TmpRxShdBufferSInt8,Com_TmpRxShdBufferSInt16,Com_TmpRxShdBufferSInt32,Com_TmpRxShdBufferSInt64 */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxPduGrpInfo */
typedef struct sCom_RxPduGrpInfoType
{
  Com_PduGrpVectorEndIdxOfRxPduGrpInfoType PduGrpVectorEndIdxOfRxPduGrpInfo;  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
  Com_PduGrpVectorStartIdxOfRxPduGrpInfoType PduGrpVectorStartIdxOfRxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_RxPduGrpInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_RxAccessInfoIndUsedOfRxPduInfoType RxAccessInfoIndUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
  Com_RxSigInfoUsedOfRxPduInfoType RxSigInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
  Com_RxTOutInfoUsedOfRxPduInfoType RxTOutInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
  Com_RxAccessInfoIndEndIdxOfRxPduInfoType RxAccessInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
  Com_RxAccessInfoIndStartIdxOfRxPduInfoType RxAccessInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
  Com_RxDefPduBufferEndIdxOfRxPduInfoType RxDefPduBufferEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxDefPduBufferStartIdxOfRxPduInfoType RxDefPduBufferStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType RxSigGrpInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigGrpInfoInd */
  Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType RxSigGrpInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigGrpInfoInd */
  Com_RxSigInfoEndIdxOfRxPduInfoType RxSigInfoEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxSigInfoStartIdxOfRxPduInfoType RxSigInfoStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxTOutInfoIndEndIdxOfRxPduInfoType RxTOutInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_RxTOutInfoIndStartIdxOfRxPduInfoType RxTOutInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_TypeOfRxPduInfoType TypeOfRxPduInfo;  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxSigGrpInfo */
typedef struct sCom_RxSigGrpInfoType
{
  Com_InvEventOfRxSigGrpInfoType InvEventOfRxSigGrpInfo;  /**< Boolean flag indicating if any invalid action is configured for the signal group. */
  Com_RxTOutInfoUsedOfRxSigGrpInfoType RxTOutInfoUsedOfRxSigGrpInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
  Com_ShdBufferRequiredOfRxSigGrpInfoType ShdBufferRequiredOfRxSigGrpInfo;
  Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfoType RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo;  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd */
  Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfoType RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo;  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd */
  Com_RxCbkFuncPtrAckIdxOfRxSigGrpInfoType RxCbkFuncPtrAckIdxOfRxSigGrpInfo;  /**< the index of the 0:1 relation pointing to Com_RxCbkFuncPtr */
  Com_RxPduInfoIdxOfRxSigGrpInfoType RxPduInfoIdxOfRxSigGrpInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
  Com_RxTOutInfoIdxOfRxSigGrpInfoType RxTOutInfoIdxOfRxSigGrpInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_StartBytePositionOfRxSigGrpInfoType StartBytePositionOfRxSigGrpInfo;  /**< Least significant byte position of first group signal within the ComIPdu. */
  Com_ValidDlcOfRxSigGrpInfoType ValidDlcOfRxSigGrpInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigGrpInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_RxAccessInfoIdxOfRxSigInfoType RxAccessInfoIdxOfRxSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_RxCbkFuncPtrAckIdxOfRxSigInfoType RxCbkFuncPtrAckIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxCbkFuncPtr */
  Com_RxTOutInfoIdxOfRxSigInfoType RxTOutInfoIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_SignalProcessingOfRxSigInfoType SignalProcessingOfRxSigInfo;
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigInfoType;

/**   \brief  type used in Com_RxTOutInfo */
typedef struct sCom_RxTOutInfoType
{
  Com_FactorOfRxTOutInfoType FactorOfRxTOutInfo;  /**< Deadline monitoring timeout factor. */
  Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo;  /**< the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
  Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo;  /**< the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
  Com_FirstFactorOfRxTOutInfoType FirstFactorOfRxTOutInfo;  /**< Timeout factor for first deadline monitoring. */
  Com_RxPduInfoIdxOfRxTOutInfoType RxPduInfoIdxOfRxTOutInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
} Com_RxTOutInfoType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_TxModeTrueUsedOfTxModeInfoType TxModeTrueUsedOfTxModeInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeTrue */
  Com_MinimumDelayOfTxModeInfoType MinimumDelayOfTxModeInfo;  /**< Minimum delay factor of the Tx I-PDU. */
  Com_TxModeTrueIdxOfTxModeInfoType TxModeTrueIdxOfTxModeInfo;  /**< the index of the 0:1 relation pointing to Com_TxModeTrue */
  Com_TxSigInfoFilterInitValueIndEndIdxOfTxModeInfoType TxSigInfoFilterInitValueIndEndIdxOfTxModeInfo;  /**< the end index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd */
  Com_TxSigInfoFilterInitValueIndStartIdxOfTxModeInfoType TxSigInfoFilterInitValueIndStartIdxOfTxModeInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd */
} Com_TxModeInfoType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_TimePeriodOfTxModeTrueType TimePeriodOfTxModeTrue;  /**< Cycle time factor. */
  Com_DirectOfTxModeTrueType DirectOfTxModeTrue;  /**< TRUE if transmission mode contains a direct part. */
  Com_RepCntOfTxModeTrueType RepCntOfTxModeTrue;  /**< Repetition count for replication of transmission requests plus one initial transmit. */
  Com_RepPeriodOfTxModeTrueType RepPeriodOfTxModeTrue;  /**< Repetition period factor for replication of transmission requests. */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduGrpInfo */
typedef struct sCom_TxPduGrpInfoType
{
  Com_PduGrpVectorEndIdxOfTxPduGrpInfoType PduGrpVectorEndIdxOfTxPduGrpInfo;  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
  Com_PduGrpVectorStartIdxOfTxPduGrpInfoType PduGrpVectorStartIdxOfTxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_TxPduGrpInfoType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_TxPduInitValueUsedOfTxPduInfoType TxPduInitValueUsedOfTxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
  Com_ExternalIdOfTxPduInfoType ExternalIdOfTxPduInfo;  /**< External ID used to call PduR_ComTransmit(). */
  Com_MetaDataLengthOfTxPduInfoType MetaDataLengthOfTxPduInfo;  /**< Length of MetaData. */
  Com_TxBufferLengthOfTxPduInfoType TxBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType TxSigGrpInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
  Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType TxSigGrpInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxSigGrpInfo */
typedef struct sCom_TxSigGrpInfoType
{
  Com_TxBufferEndIdxOfTxSigGrpInfoType TxBufferEndIdxOfTxSigGrpInfo;  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigGrpInfoType TxBufferStartIdxOfTxSigGrpInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxSigGrpMaskUsedOfTxSigGrpInfoType TxSigGrpMaskUsedOfTxSigGrpInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask */
  Com_TransferPropertyOfTxSigGrpInfoType TransferPropertyOfTxSigGrpInfo;
  Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfoType TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo;  /**< the end index of the 1:n relation pointing to Com_TxBuffer */
  Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfoType TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo;  /**< the start index of the 1:n relation pointing to Com_TxBuffer */
  Com_TxPduInfoIdxOfTxSigGrpInfoType TxPduInfoIdxOfTxSigGrpInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
  Com_TxSigInfoInvValueIndEndIdxOfTxSigGrpInfoType TxSigInfoInvValueIndEndIdxOfTxSigGrpInfo;  /**< the end index of the 0:n relation pointing to Com_TxSigInfoInvValueInd */
  Com_TxSigInfoInvValueIndStartIdxOfTxSigGrpInfoType TxSigInfoInvValueIndStartIdxOfTxSigGrpInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigInfoInvValueInd */
} Com_TxSigGrpInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_TxBufferEndIdxOfTxSigInfoType TxBufferEndIdxOfTxSigInfo;  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigInfoType TxBufferStartIdxOfTxSigInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_OnChangeUsedOfTxSigInfoType OnChangeUsedOfTxSigInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N */
  Com_ApplTypeOfTxSigInfoType ApplTypeOfTxSigInfo;  /**< Application data type. */
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BusAccOfTxSigInfoType BusAccOfTxSigInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfTxSigInfoType ByteLengthOfTxSigInfo;  /**< Byte length of the signal or group signal. */
  Com_FilterInitValueIdxOfTxSigInfoType FilterInitValueIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_TxFilterInitValueUInt8,Com_TxFilterInitValueUInt16,Com_TxFilterInitValueUInt32,Com_TxFilterInitValueUInt64,Com_TxFilterInitValueSInt8,Com_TxFilterInitValueSInt16,Com_TxFilterInitValueSInt32,Com_TxFilterInitValueSInt64 */
  Com_InvValueIdxOfTxSigInfoType InvValueIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64 */
  Com_OnChangeIdxOfTxSigInfoType OnChangeIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N */
  Com_StartByteInPduPositionOfTxSigInfoType StartByteInPduPositionOfTxSigInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TxPduInfoIdxOfTxSigInfoType TxPduInfoIdxOfTxSigInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
  Com_TxSigGrpInfoIdxOfTxSigInfoType TxSigGrpInfoIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_TxSigGrpInfo */
} Com_TxSigInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicStructTypes  Com Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct Com_HandleRxPduDeferredStructSTag
{
  Com_HandleRxPduDeferredType ACLNY_MASSCNTR_19255f18[1];
  Com_HandleRxPduDeferredType ANFRAGE_fbd80461_In[1];
  Com_HandleRxPduDeferredType AVL_RPM_WHL_19255f18[1];
  Com_HandleRxPduDeferredType A_TEMP_19255f18[1];
  Com_HandleRxPduDeferredType CON_VEH_19255f18[1];
  Com_HandleRxPduDeferredType CTR_DIAG_OBD_DRDY_19255f18[1];
  Com_HandleRxPduDeferredType CTR_VIB_STW_DISP_EXMI_SP2015_19255f18[1];
  Com_HandleRxPduDeferredType DIAG_OBD_ENG_19255f18[1];
  Com_HandleRxPduDeferredType ENERG_DGR_DRDY_19255f18[1];
  Com_HandleRxPduDeferredType ENSU_SFY_19255f18[1];
  Com_HandleRxPduDeferredType ERRM_BN_U_19255f18[1];
  Com_HandleRxPduDeferredType FAHRGESTELLNUMMER_19255f18[1];
  Com_HandleRxPduDeferredType FZZSTD_19255f18[1];
  Com_HandleRxPduDeferredType KILOMETERSTAND_19255f18[1];
  Com_HandleRxPduDeferredType OFFS_QUAD_EPS_19255f18[1];
  Com_HandleRxPduDeferredType RELATIVZEIT_19255f18[1];
  Com_HandleRxPduDeferredType SECU_FAHRGESTELLNUMMER_19255f18[1];
  Com_HandleRxPduDeferredType SECU_RESP_19255f18[1];
  Com_HandleRxPduDeferredType STEA_OFFS_19255f18[1];
  Com_HandleRxPduDeferredType ST_CENG_19255f18[1];
  Com_HandleRxPduDeferredType ST_ENERG_GEN_19255f18[1];
  Com_HandleRxPduDeferredType ST_STAB_DSC_19255f18[1];
  Com_HandleRxPduDeferredType SU_CLE_DRDY_DXP_19255f18[1];
  Com_HandleRxPduDeferredType TAR_ESTP_VIRT_FTAX_19255f18[1];
  Com_HandleRxPduDeferredType TAR_QTA_STRMOM_DV_19255f18[1];
  Com_HandleRxPduDeferredType TAR_STMOM_DV_ACT_19255f18[1];
  Com_HandleRxPduDeferredType VYAW_VEH_19255f18[1];
  Com_HandleRxPduDeferredType V_VEH_19255f18[1];
} Com_HandleRxPduDeferredStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct Com_RxDefPduBufferStructSTag
{
  Com_RxDefPduBufferType ACLNY_MASSCNTR_19255f18[6];
  Com_RxDefPduBufferType ANFRAGE_fbd80461_In[8];
  Com_RxDefPduBufferType AVL_RPM_WHL_19255f18[12];
  Com_RxDefPduBufferType A_TEMP_19255f18[2];
  Com_RxDefPduBufferType CON_VEH_19255f18[8];
  Com_RxDefPduBufferType CTR_DIAG_OBD_DRDY_19255f18[2];
  Com_RxDefPduBufferType CTR_VIB_STW_DISP_EXMI_SP2015_19255f18[8];
  Com_RxDefPduBufferType DIAG_OBD_ENG_19255f18[7];
  Com_RxDefPduBufferType ENERG_DGR_DRDY_19255f18[8];
  Com_RxDefPduBufferType ENSU_SFY_19255f18[8];
  Com_RxDefPduBufferType ERRM_BN_U_19255f18[2];
  Com_RxDefPduBufferType FAHRGESTELLNUMMER_19255f18[7];
  Com_RxDefPduBufferType FZZSTD_19255f18[8];
  Com_RxDefPduBufferType KILOMETERSTAND_19255f18[8];
  Com_RxDefPduBufferType OFFS_QUAD_EPS_19255f18[5];
  Com_RxDefPduBufferType RELATIVZEIT_19255f18[6];
  Com_RxDefPduBufferType SECU_FAHRGESTELLNUMMER_19255f18[8];
  Com_RxDefPduBufferType SECU_RESP_19255f18[8];
  Com_RxDefPduBufferType STEA_OFFS_19255f18[8];
  Com_RxDefPduBufferType ST_CENG_19255f18[8];
  Com_RxDefPduBufferType ST_ENERG_GEN_19255f18[8];
  Com_RxDefPduBufferType ST_STAB_DSC_19255f18[8];
  Com_RxDefPduBufferType SU_CLE_DRDY_DXP_19255f18[8];
  Com_RxDefPduBufferType TAR_ESTP_VIRT_FTAX_19255f18[8];
  Com_RxDefPduBufferType TAR_QTA_STRMOM_DV_19255f18[8];
  Com_RxDefPduBufferType TAR_STMOM_DV_ACT_19255f18[8];
  Com_RxDefPduBufferType VYAW_VEH_19255f18[6];
  Com_RxDefPduBufferType V_VEH_19255f18[5];
} Com_RxDefPduBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCUnionIndexAndSymbolTypes  Com Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Com_HandleRxPduDeferred in an index and symbol based style. */
typedef union Com_HandleRxPduDeferredUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_HandleRxPduDeferredType raw[28];
  Com_HandleRxPduDeferredStructSType str;
} Com_HandleRxPduDeferredUType;

/**   \brief  type to access Com_RxDefPduBuffer in an index and symbol based style. */
typedef union Com_RxDefPduBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxDefPduBufferType raw[196];
  Com_RxDefPduBufferStructSType str;
} Com_RxDefPduBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootValueTypes  Com Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 Com_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[17];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueArrayBased
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueArrayBasedType, COM_CONST) Com_ConstValueArrayBased[1];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[4];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[4];
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt64
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt64
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT64)
*/ 
#define COM_START_SEC_CONST_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueUInt64Type, COM_CONST) Com_ConstValueUInt64[2];
#define COM_STOP_SEC_CONST_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[7];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[13];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                                  Description
  InitValueUsed                            TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxSigBufferArrayBasedBufferUsed          TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased
  ShdBufferUsed                            TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  ApplType                                 Application data type.
  BitLength                                Bit length of the signal or group signal.
  BitPosition                              Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                                the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  BusAcc                                   BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                               Byte length of the signal or group signal.
  ConstValueArrayBasedInitValueEndIdx      the end index of the 0:n relation pointing to Com_ConstValueArrayBased
  ConstValueArrayBasedInitValueStartIdx    the start index of the 0:n relation pointing to Com_ConstValueArrayBased
  InvValueIdx                              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxDataTimeoutSubstitutionValueIdx        the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxPduInfoIdx                             the index of the 1:1 relation pointing to Com_RxPduInfo
  RxSigBufferArrayBasedBufferEndIdx        the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedBufferStartIdx      the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxTOutInfoIdx                            the index of the 0:1 relation pointing to Com_RxTOutInfo
  ShdBufferIdx                             the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  StartByteInPduPosition                   Start Byte position of the signal or group signal within the I-PDU.
  TmpBufferIdx                             the index of the 0:1 relation pointing to Com_TmpRxShdBufferUInt8,Com_TmpRxShdBufferUInt16,Com_TmpRxShdBufferUInt32,Com_TmpRxShdBufferUInt64,Com_TmpRxShdBufferSInt8,Com_TmpRxShdBufferSInt16,Com_TmpRxShdBufferSInt32,Com_TmpRxShdBufferSInt64
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[119];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoGrpSigInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoGrpSigInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxAccessInfoGrpSigIndType, COM_CONST) Com_RxAccessInfoGrpSigInd[82];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[119];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[19];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[28];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                    Description
  RxAccessInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxSigInfoUsed              TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo
  RxTOutInfoUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  RxAccessInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxAccessInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferEndIdx       the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx     the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigInfoEndIdx            the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx          the start index of the 0:n relation pointing to Com_RxSigInfo
  RxTOutInfoIndEndIdx        the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx      the start index of the 0:n relation pointing to Com_RxTOutInfoInd
  Type                       Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[28];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigGrpInfo
  \brief  Contains all relevant information for Rx signal groups.
  \details
  Element                          Description
  InvEvent                         Boolean flag indicating if any invalid action is configured for the signal group.
  RxTOutInfoUsed                   TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  ShdBufferRequired            
  RxAccessInfoGrpSigIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxAccessInfoGrpSigIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxCbkFuncPtrAckIdx               the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxPduInfoIdx                     the index of the 1:1 relation pointing to Com_RxPduInfo
  RxTOutInfoIdx                    the index of the 0:1 relation pointing to Com_RxTOutInfo
  StartBytePosition                Least significant byte position of first group signal within the ComIPdu.
  ValidDlc                         Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxSigGrpInfoType, COM_CONST) Com_RxSigGrpInfo[11];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element               Description
  RxAccessInfoIdx       the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxCbkFuncPtrAckIdx    the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxTOutInfoIdx         the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing  
  ValidDlc              Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[37];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring.
  \details
  Element                        Description
  Factor                         Deadline monitoring timeout factor.
  CbkRxTOutFuncPtrIndEndIdx      the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  CbkRxTOutFuncPtrIndStartIdx    the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  FirstFactor                    Timeout factor for first deadline monitoring.
  RxPduInfoIdx                   the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[13];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterInitValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterInitValueUInt16
  \brief  Contains the initial values used for initialization of the old value to evaluate the filter algorithm. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxFilterInitValueUInt16Type, COM_CONST) Com_TxFilterInitValueUInt16[1];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterInitValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterInitValueUInt8
  \brief  Contains the initial values used for initialization of the old value to evaluate the filter algorithm. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxFilterInitValueUInt8Type, COM_CONST) Com_TxFilterInitValueUInt8[20];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element                                Description
  TxModeTrueUsed                         TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeTrue
  MinimumDelay                           Minimum delay factor of the Tx I-PDU.
  TxModeTrueIdx                          the index of the 0:1 relation pointing to Com_TxModeTrue
  TxSigInfoFilterInitValueIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd
  TxSigInfoFilterInitValueIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[14];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
  Direct        TRUE if transmission mode contains a direct part.
  RepCnt        Repetition count for replication of transmission requests plus one initial transmit.
  RepPeriod     Repetition period factor for replication of transmission requests.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[8];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[14];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                    Description
  TxPduInitValueUsed         TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                 External ID used to call PduR_ComTransmit().
  MetaDataLength             Length of MetaData.
  TxBufferLength             the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx       the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx     the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd
  TxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[14];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[207];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups.
  \details
  Element                           Description
  TxBufferEndIdx                    the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx                  the start index of the 0:n relation pointing to Com_TxBuffer
  TxSigGrpMaskUsed                  TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
  TransferProperty              
  TxBufferSigGrpInTxIPDUEndIdx      the end index of the 1:n relation pointing to Com_TxBuffer
  TxBufferSigGrpInTxIPDUStartIdx    the start index of the 1:n relation pointing to Com_TxBuffer
  TxPduInfoIdx                      the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigInfoInvValueIndEndIdx        the end index of the 0:n relation pointing to Com_TxSigInfoInvValueInd
  TxSigInfoInvValueIndStartIdx      the start index of the 0:n relation pointing to Com_TxSigInfoInvValueInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[7];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[16];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  OnChangeUsed              TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  FilterInitValueIdx        the index of the 0:1 relation pointing to Com_TxFilterInitValueUInt8,Com_TxFilterInitValueUInt16,Com_TxFilterInitValueUInt32,Com_TxFilterInitValueUInt64,Com_TxFilterInitValueSInt8,Com_TxFilterInitValueSInt16,Com_TxFilterInitValueSInt32,Com_TxFilterInitValueSInt64
  InvValueIdx               the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  OnChangeIdx               the index of the 0:1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpInfoIdx           the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[87];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfoFilterInitValueInd
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfoFilterInitValueInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxSigInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigInfoFilterInitValueIndType, COM_CONST) Com_TxSigInfoFilterInitValueInd[21];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfoInvValueInd
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfoInvValueInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxSigInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigInfoInvValueIndType, COM_CONST) Com_TxSigInfoInvValueInd[31];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[14];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[14];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[14];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[3];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[13];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[28];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferArrayBased
  \brief  Rx Signal and Group Signal Buffer. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxSigBufferArrayBasedType, COM_VAR_NOINIT) Com_RxSigBufferArrayBased[7];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[28];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[14];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt64
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt64
  \brief  Rx Signal and Group Signal Buffer. (UINT64)
*/ 
#define COM_START_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt64Type, COM_VAR_NOINIT) Com_RxSigBufferUInt64[1];
#define COM_STOP_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[151];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[13];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[7];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxBuffer
  \brief  Temporary buffer for Rx UINT8_N and UINT8_DYN signals.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TmpRxBufferType, COM_VAR_NOINIT) Com_TmpRxBuffer[8];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt16
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TmpRxShdBufferUInt16Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt16[4];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt32
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TmpRxShdBufferUInt32Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt32[2];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt8
  \brief  Temporary Rx Group Signal Shadow Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TmpRxShdBufferUInt8Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt8[10];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[258];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterOldValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterOldValueUInt16
  \brief  This buffer holds the old signal values for filter MASKED_NEW_DIFFERS_MASKED_OLD and for transfer property TRIGGERED_ON_CHANGE_* evaluation. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxFilterOldValueUInt16Type, COM_VAR_NOINIT) Com_TxFilterOldValueUInt16[1];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterOldValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterOldValueUInt8
  \brief  This buffer holds the old signal values for filter MASKED_NEW_DIFFERS_MASKED_OLD and for transfer property TRIGGERED_ON_CHANGE_* evaluation. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxFilterOldValueUInt8Type, COM_VAR_NOINIT) Com_TxFilterOldValueUInt8[20];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[14];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[14];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  RECEIVE MACRO API
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* User Config File Start */

/* User Config File End */


#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

