/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IpduM.h
 *      Project:  MICROSAR IpduM
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Microsar IPDU Multiplexer header file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Safiulla Shakir               visssa        Vctr Informatik GmbH
 *  Gunnar Meiss                  visms         Vctr Informatik GmbH
 *  Sebastian Waldvogel           visswa        Vctr Informatik GmbH
 *  Markus Bart                   visbms        Vctr Informatik GmbH
 *  Florian Roehm                 visfrm        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date          Author    Change Id         Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2011-11-25    visms     -                 initial CFG5 version derived from Il_AsrIpduM Version 1.05.00
 *  01.00.01  2012-04-02    visms     ESCAN00058067     Compiler error: Undefined symbol TxMuxPduCnt in IpduM_Init
 *  02.00.00  2012-05-24    visms     ESCAN00058315     AR4-160: Support AUTOSAR 4.0.3
 *  02.00.00  2012-06-18    visbms    ESCAN00059468     Extend Comments and Improve Comment Coverage
 *  02.00.01  2012-09-17    visbms    ESCAN00061444     Feature not functional
 *  02.00.01  2012-09-24    visbms    ESCAN00061650     Det is called in IpduM_Init()
 *  02.00.01  2012-09-24    visbms    ESCAN00061652     Linker error: could not find symbol
 *  02.00.01  2012-10-05    visbms    ESCAN00061971     Possible access of out-of-bounds pointer
 *  02.01.00  2012-11-06    visms     ESCAN00062696     Tx Confirmation Callback is always called with the Initial
 *                                                      Dynamic Part Handle
 *  02.01.00  2012-11-06    visms     ESCAN00062763     IpduM_GetVersionInfo returns incorrect SW-VERSION
 *  02.01.00  2012-11-26    visbms    ESCAN00061785     AR4-197: Support BIG_ENDIAN Copy Segments in IpduM
 *  02.01.00  2013-01-31    visbms    ESCAN00064703     Compiler error: undeclared identifier:
 *                                                      IpduM_TxPathwayRefOfTxPartType
 *  02.02.00  2013-02-14    visms     ESCAN00064366     AR4-325: Implement Post-Build Loadable
 *  02.02.00  2013-03-19    visms     ESCAN00064646     AR4-282: Export BSW DBG Data
 *  02.02.00  2013-03-27    visbms    ESCAN00065331     Memory overwritten, unpredictable ECU behavior
 *  02.02.00  2013-04-19    visbms    ESCAN00061116     Compiler warning: variable (...) was set but never used
 *  02.02.00  2013-04-22    visbms    ESCAN00065881     IpduM does not work with DirectComInvocation
 *  02.02.00  2013-05-13    visbms    ESCAN00067297     Access Violation: array read index out of bounds with PDUs with
 *                                                      no static part
 *  02.02.00  2013-05-13    visbms    ESCAN00067309     Wrong TxConfirmations forwarded for static parts
 *  02.03.00  2013-08-16    visms     ESCAN00069872     The prefix of VAR data shall be <Msn> followed by '_'
 *  02.03.00  2013-08-23    visms     ESCAN00069148     Include "SchM_IpduM.h" only in source files
 *  02.03.00  2013-10-08    visms     ESCAN00070960     AR4-89: Support Optional Confirmation
 *  02.03.01  2014-02-07    visbms    ESCAN00073555     HIS metrics violation
 *  02.03.02  2014-05-07    visbms    ESCAN00074501     IpduM_Transmit() returning E_OK on failed transmission
 *  03.00.00  2014-05-14    visms     ESCAN00074121     AR4-642: Deleting container at post-build time
 *  04.00.00  2014-06-30    visbms    ESCAN00076406     MISRA deviation: MISRA-C:2004 Rule 4:3746 Implicit conversion:
 *                                                      unsigned short to unsigned char.
 *  05.00.00  2014-11-17    visbms    ESCAN00079611     Corrupt data is forwarded to Com
 *  05.00.00  2014-11-17    visbms    ESCAN00079622     Code Rework
 *  05.00.00  2014-11-28    visbms    ESCAN00079874     FEAT-229: Support 16bit selector in IpduM [AR4-927]
 *  05.00.00  2015-01-09    visbms    ESCAN00080477     Just-in-time update for multiplex I-PDUs not working correctly
 *  05.01.00  2015-04-29    visbms    ESCAN00079850     FEAT-1315: IPDUM for CAN-FD supporting nPdu2Frame-Mapping
 *  05.01.01  2015-04-29    visbms    ESCAN00082757     Compiler error: undeclared identifiers if standard multiplexed
 *                                                      PDUs are not configured
 *  05.01.02  2015-04-29    visbms    ESCAN00082763     IpduM does not initialize without multiplex I-PDUs
 *  05.01.03  2015-05-04    visbms    ESCAN00082896     Reception of Container PDUs is not functional
 *  05.01.04  2015-05-28    visbms    ESCAN00083164     Symbol IpduM_IsImmediateProcessingOfRxContainerPdu not found
 *  05.01.05  2015-06-24    visbms    ESCAN00083546     Compiler error: Linkage Error:Undefined symbol
 *                                                      'EcuM_BswErrorHook' in file 'obj\IpduM.o'
 *  05.01.05  2015-06-29    visbms    ESCAN00083693     Compiler error: IpduM.obj : error LNK2019: unresolved external
 *                                                      symbol _IpduM_GetSizeOfRxInfo referenced in function
 *                                                      _IpduM_RxIndication
 *  05.01.06  2015-09-01    visbms    ESCAN00084929     Compiler warning/error: function IpduM_GetAddrContainerTxBuffer
 *                                                      not declared
 *  05.01.06  2015-09-02    visbms    ESCAN00084620     Wrong data copied on Container PDU reception
 *  06.00.00  2015-11-05    visbms    ESCAN00086291     Support Initialization without TriggerTransmit
 *  06.00.00  2015-11-21    visbms    ESCAN00084944     Additional (wrong) Contained-PDUs are received
 *  06.01.00  2016-02-17    visms     ESCAN00087830     FEAT-1631: Trigger Transmit API with SduLength In/Out according
 *                                                      to ASR4.2.2
 *  06.01.00  2016-02-24    visbms    ESCAN00088515     Wrong TxConfirmations for configurations including multiplex
 *                                                      PDUs and container PDUs at the same time
 *  06.01.00  2016-03-14    visbms    ESCAN00088285     Compiler warning: IpduM_JitUpdate declared static but never
 *                                                      defined
 *  06.01.01  2016-03-31    visbms    ESCAN00089162     MISRA deviation: MISRA-C:2004 multiple Rules
 *  06.01.02  2016-04-15    visbms    ESCAN00089535     Container PDUs are transmitted immediately after the first
 *                                                      Contained PDU is added
 *  06.01.02  2016-04-15    visbms    ESCAN00089431     Compiler error: IpduM_TxPathwayIdxOfTxLoInfoType undefined
 *  06.01.02  2016-04-18    visbms    ESCAN00089347     Update Bits not showing on Flexray
 *  06.01.03  2016-05-09    visbms    ESCAN00089814     Linker error: unresolved external symbol
 *                                                      _IpduM_GetTxPartStaticPartIdxOfTxPathway referenced in function
 *                                                      _IpduM_JitUpdate
 *  06.01.04  2016-06-14    visbms    ESCAN00090476     Unexpected ECU behavior on transmission of a multiplexed PDU
 *                                                      without configured TxConfirmationPduId
 *  06.02.00  2016-06-21    visbms    ESCAN00090576     FEAT-1896: Missing part of FEAT-1503
 *  06.03.00  2016-10-13    visfrm    FEATC-276         FEAT-1920: SafeBSW Step 6
 *            2016-10-20    visbms    ESCAN00092160     Unexpected ECU behavior on transmission of container PDU in
 *                                                      non-safeBSW stack
 *            2016-10-20    visbms    ESCAN00092429     Changed return value to E_OK for accepting the non-triggering
 *                                                      multiplex TX part
 *            2016-10-21    visfrm    ESCAN00092431     Unexpected ECU behavior for too large (misconfigured) Contained PDUs
 *            2016-11-03    visbms    ESCAN00092631     Container PDUs stop being transmitted after 255 transmissions
 *            2016-11-03    visbms    ESCAN00089392     MISRA deviation: MISRA-C:2004 Rule 14.1
 *            2016-11-03    visfrm    ESCAN00092299     Compiler error: C4013: 'IpduM_IsSendTimeoutDefinedOfTxContainedPdu' undefined
 *  06.04.00  2016-11-04    visbms    ESCAN00092676     Container PDU Tx Confirmation not working
 *            2016-11-11    visfrm    ESCAN00092765     Endless loop for Container PDU transmission
 *            2016-11-17    visbms    ESCAN00092828     Out of bounds array write access for Container PDUs without TxConfirmation
 *  06.04.01  2016-12-02    visbms    ESCAN00093020     Container Tx Confirmation does not work for immediate transmitted PDUs
 *  06.05.00  2017-01-12    visbms    FEATC-955         FEAT-2072: Introduce separate main functions for reception and transmission for IPDUM
 *            2017-01-27    visbms    ESCAN00093682     Contained PDU is completely not received or routed if it is
 *                                                      the last one in a container which is completely filled
 *            2017-01-27    visbms    ESCAN00093762     Large delay between first and second Container PDU transmissions using send timeouts
 *            2017-03-30    visbms    ESCAN00094014     Container PDUs fetched with TriggerTransmit do not appear on the bus
 *  06.05.01  2017-05-17    visbms    ESCAN00094970     Possible out of bounds write access with Tx Container PDUs
 *            2017-05-17    visbms    ESCAN00089599     DET error in Postbuild-Selectable Rx-only variant
 *  06.06.00  2017-07-07    visbms    STORYC-1913       Add Request Queue for TriggerTransmit of Container PDUs according to 4.2.2 Spec
 *  06.06.01  2017-08-28    visbms    ESCAN00096424     Unexpected behavior during Container PDU reception
 *            2017-08-28    visbms    ESCAN00096344     Endless loop during reception of different size Container PDUs with the same PDU ID
 *            2017-08-31    visbms    ESCAN00096366     Wrong data received during Container PDU reception
 *            2017-09-20    visbms    ESCAN00096743     TriggerTransmit Container PDU not appearing on the bus
 *  06.06.02  2017-09-18    visbms    STORYC-2530       Remove unused code if Container TriggerTransmit is not active
 *            2017-09-20    visbms    ESCAN00096618     Container PDUs lost on transmission
 *            2017-09-20    visbms    ESCAN00096611     Wrong container PDU transmission on queue overflow
 *  06.06.03  2017-09-22    visbms    ESCAN00096804     Linker error: Undefined Symbol IpduM_GetTxConfirmationTimeoutOfTxContainerPdu
 *  06.06.04  2017-12-04    visbms    ESCAN00097478     Container TriggerTransmit: some Contained PDUs missing or DET for invalid handle ID or invalid DLC value
 *            2017-12-06    visbms    ESCAN00096610     Container PDU with IpduMContainerTxFirstContainedPduTrigger always contains one PDU
 *********************************************************************************************************************/
#ifndef IPDUM_H
# define IPDUM_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "IpduM_Cfg.h"
# include "IpduM_Lcfg.h"
# include "IpduM_PBcfg.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**
  \defgroup  IpduMIdentification IpduM Identification
  \brief  Vendor and module identification of this implementation.
  \{
*/
# define IPDUM_VENDOR_ID              30U              /**< the vendor ID of this implementation. */
# define IPDUM_MODULE_ID              52U              /**< the module ID of this implementation. */
/**
  \}
*/

/**
  \defgroup  IpduMSWVersion IpduM version number
  \brief  Version number of this implementation.
  \{
*/
# define IPDUM_SW_MAJOR_VERSION       6U
# define IPDUM_SW_MINOR_VERSION       6U
# define IPDUM_SW_PATCH_VERSION       4U
/**
  \}
*/

/**
  \defgroup  IpduMARReleaseVersion IpduM AUTOSAR release version number
  \brief  Version number of AUTOSAR release on which the appropriate implementation is based on.
  \{
*/
# define IPDUM_AR_RELEASE_MAJOR_VERSION       4U
# define IPDUM_AR_RELEASE_MINOR_VERSION       0U
# define IPDUM_AR_RELEASE_REVISION_VERSION    3U
/**
  \}
*/

/**
  \defgroup  IpduMDetErrorCodes IpduM Det Error Codes
  \brief  IpduM development error IDs.
  \{
*/
/* Always neccessary as init value! */
# define IPDUM_E_NO_ERROR                      0U   /**< this code is used to detect that no error occurred. Det_ReportError() is not called.  */

# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */

#  define IPDUM_E_PARAM                         16U /**< the API service has been with a wrong parameter. */
#  define IPDUM_E_PARAM_POINTER                 17U /**< the API service has been called with a not expected NULL pointer */
#  define IPDUM_E_UNINIT                        32U /**< the API service has been called before IPDUM was initialized with IpduM_Init() */
#  define IPDUM_E_INIT_FAILED                   33U /**< the API service has been called with a not expected NULL pointer */
#  define IPDUM_E_TRIGGERTRANSMITFAILED         34U /**< the call of PduR_IpduMTriggerTransmit hs been returned with != E_OK */
#  define IPDUM_E_HEADER                        48U /**< errorneous container header detected */
#  define IPDUM_E_QUEUEOVFL                     49U /**< container queue overfow occured */
/**
  \}
*/

/**
  \defgroup  IpduMApiIds IpduM Module Service Identifiers
  \brief  Unique identifier of a IPDUM module service.
  \{
*/
#  define IPDUM_APIID_INIT                      0U
#  define IPDUM_APIID_VERSIONINFO               1U
#  define IPDUM_APIID_RXINDICATION              2U
#  define IPDUM_APIID_TRANSMIT                  3U
#  define IPDUM_APIID_TXCONFIRMATION            4U
#  define IPDUM_APIID_TRIGGERTRANSMIT           5U
#  define IPDUM_APIID_MAINFUNCTION              16U
/**
  \}
*/
# endif

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define IPDUM_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */

/*******************************************************************************************
*  IpduM_Init()
*******************************************************************************************/
/*! \brief        Initializes component
 *  \details      Initializes all component variables and sets the component state to initialized
 *  \param[in]    config    Component configuration structure
 *  \pre          Interrupts are disabled
 *  \pre          Module is uninitialized
 *  \pre          IpduM_InitMemory has been called unless IpduM_ModuleInitialized is initialized by start-up code
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        CREQ-102610, SPEC-2914519, SPEC-2914520, SPEC-2914521, SPEC-2068173
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_Init(P2CONST(IpduM_ConfigType, AUTOMATIC, IPDUM_PBCFG) config);

/*******************************************************************************************
*  IpduM_InitMemory()
*******************************************************************************************/
/*! \brief        Power-up memory initialization
 *  \details      Initializes component variables in *_INIT_* sections at power up.
 *  \pre          Module is uninitialized
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         Use this function in case these variables are not initialized by the startup code
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_InitMemory(void);

# if (IPDUM_VERSION_INFO_API == STD_ON)
/*******************************************************************************************
*  IpduM_GetVersionInfo()
*******************************************************************************************/
/*! \brief        Returns the version information
 *  \details      Returns version information, vendor ID and AUTOSAR module ID of the component
 *  \param[out]   versioninfo    Pointer to where to store the version information. Parameter must not be NULL
 *  \pre          none
 *  \context      TASK|ISR2
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        CREQ-102612, SPEC-2068177
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, IPDUM_APPL_DATA) versioninfo);
# endif

/*******************************************************************************************
*  IpduM_Transmit()
*******************************************************************************************/
/*! \brief        Requests the transmission of a static or dynamic part or a contained PDU.
 *  \details
 *  \param[in]    PdumTxPduId
 *  \param[in]    PduInfoPtr    Pointer to payload buffer
 *  \return       E_OK          Transmit request was accepted by IpduM and destination layer
 *  \return       E_NOT_OK      Transmit request was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \note         Called by PduR module
 *  \trace        CREQ-102653, SPEC-2068156, SPEC-2068157, SPEC-2068181
*******************************************************************************************/
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_Transmit(PduIdType PdumTxPduId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);

# define IPDUM_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */

/*!
* \exclusivearea IPDUM_EXCLUSIVE_AREA_0
* Ensures consistency of global RAM variables.
* \protects All affected global RAM variables.
* \usedin IpduM_Init, IpduM_MainFunctionTx, IpduM_MainFunctionRx, IpduM_Transmit, IpduM_TriggerTransmit, IpduM_TxConfirmation, IpduM_RxIndication
* \exclude All functions provided by IpduM.
* \length SHORT depending on the API and the call graph.
* \endexclusivearea
*/

#endif /* IPDUM_H */

/**********************************************************************************************************************
 *  END OF FILE: IpduM.h
 *********************************************************************************************************************/
