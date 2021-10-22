/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!
 *        \file  FrTp_Types.h
 *       \brief  Type definition header file of FrTp
 *
 *     \details  Declares all types that are used by the FrTp main-module and all sub-module of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK in file FrTp.c
 *********************************************************************************************************************/

#if !defined FRTP_TYPES_H
#define FRTP_TYPES_H

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "FrTp_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_TYPES_SW_MAJOR_VERSION (2u) /*!< Major version of the preprocessor-based version information of the FrTp. */
# define FRTP_TYPES_SW_MINOR_VERSION (4u) /*!< Minor version of the preprocessor-based version information of the FrTp. */
# define FRTP_TYPES_SW_PATCH_VERSION (4u) /*!< Patch version of the preprocessor-based version information of the FrTp. */

/* Keyword macros */
#if !defined (STATIC) /* COV_FRTP_MSR_COMPATIBILITY */
# define STATIC static /*!< Definition of STATIC in case it has not been defined, yet. */
#endif

#if !defined (LOCAL_INLINE) /* COV_FRTP_MSR_COMPATIBILITY */
# define LOCAL_INLINE INLINE STATIC /*!< Definition of LOCAL_INLINE in case it has not been defined, yet. */
#endif

#if !defined (FRTP_LOCAL) /* COV_FRTP_MSR_COMPATIBILITY */
# define FRTP_LOCAL STATIC /*!< Definition of FRTP_LOCAL in case it has not been defined, yet. */
#endif

#if !defined (FRTP_LOCAL_INLINE) /* COV_FRTP_MSR_COMPATIBILITY */
# define FRTP_LOCAL_INLINE LOCAL_INLINE /*!< Definition of FRTP_LOCAL_INLINE in case it has not been defined, yet. */
#endif

/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific items ----- */

/*!< Offsets of PCI and TP-specific fields in the pdu (PAST the C_AI) */
/*!< Frametype */
#define FrTp_FmtOffsetFrameType   0u
/*!< BC field */
#define FrTp_FmtOffsetBc          1u
/*!< ML field */
#define FrTp_Iso_MlLowByteOffset  2u
#define FrTp_Iso_MlHighByteOffset 3u
/*!< FPL field */
#define FrTp_FmtOffsetFPL         1u


#if !defined (FrTp_OkButNotEnoughBuffer) /* COV_FRTP_MSR_COMPATIBILITY */
# define FrTp_OkButNotEnoughBuffer ((BufReq_ReturnType)(BUFREQ_E_OVFL + 1u)) /*!< Definition of an internal helper buffer-status, used when upper layer indicates 0-bytes data- or buffer-length. */
#endif

# define FrTp_IsPostbuild() (    (FRTP_CONFIGURATION_VARIANT == FRTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) \
                              || (FRTP_POSTBUILD_VARIANT_SUPPORT == STD_ON)) /*!< Central decision whether the FrTp shall be capable of being initialized post-build. */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint16 FrTp_ChanTimerType; /*!< Type to be used by every state-machine's counter to track timeouts and performance requirements. */
typedef uint16 FrTp_BufReqTimerType; /*!< Type to be used by every state-machine's counter to track the number of FC.WT pdus sent to the transmitter of the FrTp message . */

/* PRQA S 3453 10 */ /* MD_MSR_19.7 */
#if (FrTp_IsPostbuild())
# define FRTP_P2CONSTCFGROOT(Type)  P2CONST(Type, AUTOMATIC, FRTP_PBCFG_ROOT)
# define FRTP_P2CONSTCFG(Type)      P2CONST(Type, AUTOMATIC, FRTP_PBCFG)

# define FRTP_P2VARCFG(Type)      P2VAR(Type, AUTOMATIC, FRTP_VAR_PBCFG)
#else
# define FRTP_P2CONSTCFGROOT(Type)  P2CONST(Type, AUTOMATIC, FRTP_CONST)
# define FRTP_P2CONSTCFG(Type)      P2CONST(Type, AUTOMATIC, FRTP_CONST)
#endif
#define FRTP_P2CONSTAPPLDATA(Type) P2CONST(Type, AUTOMATIC, FRTP_APPL_DATA)


typedef P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTp_PduInfoTypeApplPtr; /*!< This type implements the compiler abstraction for a pointer to a pointer to an PduInfoType in the applications memory area. */


/**********************************************************************************************************************
* ADMIN DATA IN RAM
**********************************************************************************************************************/

typedef struct
{
  VAR(uint8, AUTOMATIC) NumFreePdus; /*!< Number of tx-pdus of this pool that have not been requested to be sent using FrIf_Transmit() */
  VAR(uint8, AUTOMATIC) NumTxConfs; /*!< Number of tx-pdus of this pool that have not been requested to be sent using FrIf_Transmit() */
} FrTp_TxPduPoolDataType; /*!< This type combines all runtime values of an FrTpTxPduPool. */

/**********************************************************************************************************************
* CONFIG DATA IN FLASH/ROM
**********************************************************************************************************************/

typedef struct
{
  P2CONST(uint8, FRTP_CONST, FRTP_CONST) ConnOffsetsPtr; /*!< Ponter to the array of offsets to connections whose rx-pdu-pool uses this rx-pdu */
  VAR(PduIdType, AUTOMATIC) NumConns; /*!< Number of connections whose rx-pdu-pool uses this rx-pdu */
  VAR(uint8, AUTOMATIC) Length; /*!< Length of this rx-pdu */
} FrTp_RxPduInfoType; /*!< This type combines all configuration items of an FrTpRxPdu */

typedef struct
{
  CONST(uint8, FRTP_CONST) MinPduLen; /*!< Length of the smallest rx-pdu in this rx-pdu-pool */
} FrTp_RxPduPoolType; /*!< This type combines all configuration items of an FrTpRxPduPool. */

typedef struct
{
  P2CONST(uint8, FRTP_CONST, FRTP_CONST) PoolOffsetsPtr; /*!< Pointer to the array of offsets to rx-pdu-pools that use this rx-pdu in the overall list of tx-pdu-pools */
  VAR(PduIdType, AUTOMATIC) PduId; /*!< PduId to be passed to FrIf_Transmit() when sending this tx-pdu */
  VAR(uint8, AUTOMATIC) DecoupPduAdminDataOffset; /*! This tx-pdus' offset in the array of admin data for decoupled tx-pdus */
  VAR(uint8, AUTOMATIC) Length; /*!< Length in bytes of this tx-pdu */
  VAR(uint8, AUTOMATIC) NumPools; /*!< Number of tx-pdu-pools using (i.e. containing) this tx-pdu */
} FrTp_TxPduInfoType; /*!< This type combines all configuration items of an FrTpTxPdu. */

typedef struct
{
  P2CONST(uint8, FRTP_CONST, FRTP_CONST) PduOffsetsPtr; /*!< Pointer to the array of offsets to tx-pdus that are contained in this tx-pdu-pool */
  CONST(uint8, FRTP_CONST) NumPdus; /*!< Number of tx-pdus that are contained in this tx-pdu-pool */
  CONST(uint8, FRTP_CONST) MinPduLen; /*!< Length of the smallest tx-pdu contained in this tx-pdu-pool */
} FrTp_TxPduPoolType; /*!< This type combines all configuration items of an FrTpTxPduPool. */

typedef struct
{
  VAR(uint16, AUTOMATIC) TimeoutAs; /*!< Parameter C_TIMEOUT_As of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) TimeoutAr; /*!< Parameter C_TIMEOUT_Ar of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) TimeoutBs; /*!< Parameter C_TIMEOUT_Bs of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) TimeoutCr; /*!< Parameter C_TIMEOUT_Cr of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) TimeBr; /*!< Parameter C_TIME_Br of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) TimeCs; /*!< Parameter C_TIME_Cs of the ISO 10681-2 using the unit of measurement "main function cycles". */
  VAR(uint16, AUTOMATIC) MaxBfs; /*!< Max. value that may be used by the receiver for the ISO 10681-2 Parameter BFS in FC_WT C_PDUs. */
  VAR(uint16, AUTOMATIC) MaxWft; /*!< Parameter WFTmax of the ISO 10681-2 */
  VAR(uint8, AUTOMATIC) BandwidthCtrl; /*!< Parameter BC of the ISO 10681-2 */
} FrTp_ConnCtrlType; /*!< This type defines the behavior of the state-machine that conducts a transfer for a FrTpConnection. Each FrTpConnection references exactly one parameter-set of this type. */

typedef struct
{
  P2CONST(FrTp_ConnCtrlType, FRTP_CONST, FRTP_CONST) ConnCtrlPtr;

  VAR(uint16, AUTOMATIC) LocalAddress; /*!< Parameter C_TA of the ISO 10681-2. */
  VAR(uint16, AUTOMATIC) RemoteAddress; /*!< Parameter C_SA of the ISO 10681-2. */

  VAR(PduIdType, AUTOMATIC) ConnIdx; /*!< Index of this array element in the array of type FrTp_ConnCfgType[]. */
  VAR(PduIdType, AUTOMATIC) FrTpSduRxId; /*!< Symbolic Name Value of the FrTpRxSdu of this FrTpConnection. Contains FRTP_INVALID_SNV if there is no FrTpRxSdu. */
  VAR(PduIdType, AUTOMATIC) FrTpSduTxId; /*!< Symbolic Name Value of the FrTpTxSdu of this FrTpConnection. Contains FRTP_INVALID_SNV if there is no FrTpTxSdu. */

  VAR(uint8, AUTOMATIC) RxPduPoolOffset; /*!< Index of the FrTpRxPduPool used by this FrTpConnection in the overall array of FrTpRxPduPools. */
  VAR(uint8, AUTOMATIC) TxPduPoolOffset; /*!< Index of the FrTpTxPduPool used by this FrTpConnection in the overall array of FrTpTxPduPools. */
  VAR(uint8, AUTOMATIC) MultRec; /*!< Flag that indicates whether this connection is allowed to be used for unsegmented transfers only. */
  VAR(uint8, AUTOMATIC) FrTpBandwidthLimitation; /*!< Flag that indicates whether transmissions on this connection shall be done using the BandwidthLimitation mechanism. */
} FrTp_ConnCfgType; /*!< Configuration items of one FrTpConnection. */

/**********************************************************************************************************************
* ADMIN DATA IN RAM
**********************************************************************************************************************/

typedef struct
{
  VAR(uint8, AUTOMATIC) CurrBC; /*!< Current value of the "Bandwidth Control" parameter for this connection */
  VAR(uint8, AUTOMATIC) CurrRxSmIdx; /*!< Current index in the array of rx-state-machines of the rx-state-machine that this connection is currently active in */
  VAR(uint8, AUTOMATIC) CurrTxSmIdx; /*!< Current index in the array of tx-state-machines of the tx-state-machine that this connection is currently active in */
} FrTp_ConnStateType; /*!< This type contains all items that are related to a FrTpConnection that can change during runtime. */

typedef struct 
{
  P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) ConnCfgPtr; /*!< Pointer to the configuration of the FrTpConnection that is currently operated in this state-machine. */

  VAR(PduLengthType, AUTOMATIC) DataIndex; /*!< Current amount of data that has been received successfully up to now. */
  VAR(PduLengthType, AUTOMATIC) DataLength; /*!< Overall amount of data that was announced by the transmitter to be transferred. */
  VAR(PduLengthType, AUTOMATIC) AvailableRxBuffer; /*!< Current amount of data that the PduR is still able to copy into its rx-buffer according to the call to a StartOfReception or CopyRxData function. */
  VAR(PduLengthType, AUTOMATIC) RemainingBytesInBlock; /*!< Current amount of data that the transmitter is still allowed to send according to the last FC C_PDU sent by this state-machine. */

  VAR(FrTp_ChanTimerType, AUTOMATIC) Timer; /*!< Variable to implement a time- and timeout-measurement-system in the unit of measurement "main function cycles". */
  VAR(FrTp_BufReqTimerType, AUTOMATIC) CounterWft; /*!< Counter that limits the number of FC_WT C_PDUs to not exceed the ISO 10681-2 parameter WFTmax. */

  VAR(uint8, AUTOMATIC) CurrPCI; /*!< Last PCI byte of the last valid FrTp Pdu received in the current reception. */
  VAR(uint8, AUTOMATIC) State; /*!< Current state of this rx-state-machine. */
  VAR(uint8, AUTOMATIC) ExpectedSN; /*!< Value of the SN that is expected to be contained in the next CF C_PDU that will be received from the transmitter. */
  VAR(uint8, AUTOMATIC) RxStartedAtUpperLayer; /*!< Flag that stores the fact whether the PduR has accepted the start of the current reception. The flag is required to fulfill the contract of the generic PduR TP interface. */
  VAR(uint8, AUTOMATIC) ReceivedPduLen; /*!< Amount of rx-data that has just been received in a FrTp Pdu from the transmitter. In case of FC_WT transmission exactly that amount has been copied to the Pdu-buffer that is assigned to this rx-state-machine. */
  VAR(uint8, AUTOMATIC) NxtFreePduIdx; /*!< Index of the next FrTpTxPdu to be used in case this rx-state-machine requires to send a FC C_PDU. The index points to an currently unused FrTpTxPdu in the global list of all FrTpTxPdus. */
} FrTp_RxStateType; /*!< This type combines all admin data of an rx-state-machine. */

typedef struct
{
  P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) ConnCfgPtr; /*!< Pointer to configuration of the connection that is currently handled by this tx-state-machine */
  VAR(PduLengthType, AUTOMATIC) DataIndex; /*!< Current position of the txn */
  VAR(PduLengthType, AUTOMATIC) DataLength; /*!< Overall length of the txn */
  VAR(PduLengthType, AUTOMATIC) AvailableTxData; /*!< Amount of tx-data that was indicated by PduR to be available */
  VAR(PduLengthType, AUTOMATIC) CurrDecTxDataPending; /*!< Amount of tx-data that will be put in to FrTp-pdus in the context of calls to FrTp_TriggerTransmit() */
  VAR(PduLengthType, AUTOMATIC) RemainingBytesInBlock; /*!< Countdown of bytes in block which is used in case the receiver has indicated a BfS-value != 0 */
  VAR(FrTp_ChanTimerType, AUTOMATIC) Timer; /*!< Timer for all actions of the tx-state-machine that have a temporal limit */
  VAR(uint8, AUTOMATIC) CurrPCI; /*!< PCI of the next FrTp-pdu to be sent */
  VAR(uint8, AUTOMATIC) State; /*!< Current state of the tx-state-machine */
  VAR(uint8, AUTOMATIC) SeqNumber; /*!< Sequence number counter for this transmission */
  VAR(uint8, AUTOMATIC) RobsRound; /*!< Flag, whether this tx-state-machine currently takes part in the round robbing in the context of the FrTp_MainFunction() */
  VAR(uint8, AUTOMATIC) CounterMNPC; /*!< Counter of FrTp-pdus sent in the current FlexRay-cycle */
  VAR(uint8, AUTOMATIC) CurrMNPC; /*!< Maximum Number of Pdus per Cycle indicated by the receiver */
  VAR(uint8, AUTOMATIC) TimerVal4CurrSC; /*!< Reload-value of the Timer-variable of this tx-state-machine in case the receiver has indicated an effective value of separation cycles */
  VAR(uint8, AUTOMATIC) CounterWT; /*!< Counter of FC.WT FrTp-Pdus sent by the receiver */
  VAR(uint8, AUTOMATIC) CopiedTxDataLen; /*!< Amount of tx-data copied by the PduR into this tx-state-machines' own pdu-buffer */
  VAR(uint8, AUTOMATIC) PendingTxConfs; /*!< Number of FrIf-tx-pdus that this tx-state-machine has sent using FrIf_Transmit() */
  VAR(uint8, AUTOMATIC) NxtFreePduIdx; /*!< Index of the next free FrIf-tx-pdu that may be used by this tx-state-machine */
  VAR(uint8, AUTOMATIC) IsBlockMode; /*!< Flag that indicates whether the receiver has indicated a BfS-value != 0 */
  VAR(uint8, AUTOMATIC) CurrDecPdusPending; /*!< Number of FrTp-pdus to be fetched by FrIf for this tx-state-machine using FrTp_TriggerTransmit() */
} FrTp_TxStateType;

#define FrTp_TPCIMaxLength 4u /*!< Max length of the PCI section in a ISO 10681-2 conform N-Pdu */

typedef struct
{
  P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) ConnCfgPtr; /*!< Pointer to the configuration of the connection that is currently using this decoupled Pdu for a FrTp message transfer. */
  VAR(PduInfoType, AUTOMATIC) PduInfoPayload; /*!< C-struct describing the payload of the decoupled Pdu used for the current FrTp message transfer. */
  VAR(uint8, AUTOMATIC) PduLengthTPCI; /*!< Length of the PCI-info of the decoupled Pdu used for the current FrTp message transfer. */
  VAR(uint8, AUTOMATIC) TPCIData[FrTp_TPCIMaxLength]; /*!< Array containing the PCI-info of the decoupled Pdu used for the current FrTp message transfer. */
} FrTp_DecoupPduAdminType; /*!< C-struct-type to store the data required to assemble a ISO10681-2 conform N-Pdu when FrTp_TriggerTransmit() is called. */

typedef P2VAR(uint8, TYPEDEF, AUTOSAR_COMSTACKDATA) FrTpVarBufPtrType;

#if (FrTp_IsPostbuild())
typedef struct
{
  P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) FrTp_ConnCfg; /*!< Pointer to the array of all configured connections. */
  P2CONST(FrTp_RxPduPoolType, FRTP_CONST, FRTP_CONST) FrTp_RxPduPools; /*!< Pointer to the array of all configured FrTpRxPduPools. */
  P2CONST(FrTp_TxPduPoolType, FRTP_CONST, FRTP_CONST) FrTp_TxPduPools; /*!< Pointer to the array of all configured FrTpTxPduPools. */
  P2CONST(FrTp_RxPduInfoType, FRTP_CONST, FRTP_CONST) FrTp_FrIfRxPdus; /*!< Pointer to the array of all configured FrTpRxPdus. */
  P2CONST(FrTp_TxPduInfoType, FRTP_CONST, FRTP_CONST) FrTp_FrIfTxPdus; /*!< Pointer to the array of all configured FrTpTxPdus. */
  P2CONST(PduIdType, FRTP_CONST, FRTP_CONST) FrTp_RxSduSnv2ConnIdx; /*!< Pointer to the map of the external SNV of an FrTpRxSdu to the internal index of the related FrTpConnection. */
  P2CONST(PduIdType, FRTP_CONST, FRTP_CONST) FrTp_TxSduSnv2ConnIdx; /*!< Pointer to the map of the external SNV of an FrTpTxSdu to the internal index of the related FrTpConnection. */
  P2CONST(PduIdType, FRTP_CONST, FRTP_CONST) FrTp_RxPduSnv2RxPduIdx; /*!< Pointer to the map of the external SNV of an FrTpRxPdu to the internal index of the FrTpRxPdu. */
  P2CONST(PduIdType, FRTP_CONST, FRTP_CONST) FrTp_TxPduSnv2TxPduIdx; /*!< Pointer to the map of the external SNV of an FrTpTxPdu to the internal index of the FrTpTxPdu. */
# if (FRTP_CONFIGURATION_VARIANT == 3) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
  FRTP_P2CONSTCFG(FrTpVarBufPtrType) FrTp_RxBufPtr; /*!< Pointer to the array of pdu-buffers of all rx-state-machines. */
  FRTP_P2CONSTCFG(FrTpVarBufPtrType) FrTp_TxBufPtr; /*!< Pointer to the array of pdu-buffers of all tx-state-machines. */
  FRTP_P2VARCFG(uint8) FrTp_FrIfTxBufPtr; /*!< Pointer to the one and only buffer to assemble FrTpTxPdus to be sent by the FrIf. */

  FRTP_P2VARCFG(FrTp_RxStateType) FrTp_RxStatePtr; /*!< Pointer to the array of rx-state-machine C-structs.*/
  FRTP_P2VARCFG(FrTp_TxStateType) FrTp_TxStatePtr; /*!< Pointer to the array of tx-state-machine C-structs.*/
  FRTP_P2VARCFG(FrTp_ConnStateType)  FrTp_ConnStatePtr; /*!< Pointer to the array of C-structs holding the runtime information of each FrTpConnection (i.e. of each FrTpRxSdu and TxSdu) configured.*/
  FRTP_P2VARCFG(uint8) FrTp_RxFrIfPendingPtr; /*!< Pointer to the array of index values of rx-state-machines that use a particular FrTpTxPdu. */
  FRTP_P2VARCFG(uint8) FrTp_TxFrIfPendingPtr; /*!< Pointer to the array of index values of rx-state-machines that use a particular FrTpTxPdu. */
  FRTP_P2VARCFG(FrTp_DecoupPduAdminType) FrTp_DecoupPduAdminDataPtr; /*!< Pointer to the array of C-structs holding the admin data for the transmission of all FrTpTxPdus of type "decoupled". */
  FRTP_P2VARCFG(FrTp_TxPduPoolDataType) FrTp_PoolDataPtr; /*!< Pointer to the array of C-structs holding the admin data of all FrTpTxPduPools. */
# endif
  VAR(PduIdType, AUTOMATIC) FrTp_NumConn; /*!< Length of the FrTp_ConnCfg array. */
  VAR(PduIdType, AUTOMATIC) FrTp_MaxRxSduId; /*!< Length of the FrTp_RxSduSnv2ConnIdx array. */
  VAR(PduIdType, AUTOMATIC) FrTp_MaxTxSduId; /*!< Length of the FrTp_TxSduSnv2ConnIdx array. */
  VAR(uint8, AUTOMATIC) FrTp_NumFrIfRxPdus; /*!< Length of the FrTp_FrIfTxPdus array. */
  VAR(uint8, AUTOMATIC) FrTp_NumFrIfTxPdus; /*!< Length of the  array. */
  VAR(uint8, AUTOMATIC) FrTp_MaxFrIfRxPduId; /*!< Length of the FrTp_RxPduSnv2RxPduIdx array. */
  VAR(uint8, AUTOMATIC) FrTp_MaxFrIfTxPduId; /*!< Length of the FrTp_TxPduSnv2TxPduIdx array. */
  VAR(uint8, AUTOMATIC) FrTp_MaxLengthRxPdus; /*!< Length of the longest of all FrTpRxPdus. */
  VAR(uint8, AUTOMATIC) FrTp_MaxLengthTxPdus; /*!< Length of the longest of all FrTpTxPdus. */
  VAR(uint8, AUTOMATIC) FrTp_NumDecoupPdus; /*!< Length of the  array. */
  VAR(uint8, AUTOMATIC) FrTp_NumRxChan; /*!< Length of the  array. */
  VAR(uint8, AUTOMATIC) FrTp_NumTxChan; /*!< Length of the  array. */
  VAR(uint8, AUTOMATIC) FrTp_InstanceId; /*!< Instance ID of this instance of the FrTp. */
  VAR(uint8, AUTOMATIC) FrTp_NumRxPools; /*!< Length of the FrTp_RxPduPools array.*/
  VAR(uint8, AUTOMATIC) FrTp_NumTxPools; /*!< Length of the FrTp_TxPduPools array.*/
# if (FRTP_CONFIGURATION_VARIANT == 3) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
  VAR(uint16, AUTOMATIC) GeneratorCompatibilityVersion; /*!< Version of the CFG5 generator that has created the current configuration-struct.*/
  VAR(uint16, AUTOMATIC) FinalMagicNumber; /*!< Configuration element that has to be there in any case to identify a valid FrTp-configuration.*/
# endif
} FrTp_ConfigType; /*!< C-struct-type used to pass the overall configuration of the FrTp to FrTp_Init() */

typedef FRTP_P2CONSTCFGROOT(FrTp_ConfigType) FrTp_ConfigPtrType;

typedef FrTp_ConfigType FrTpPbConfigType; /*!< Alias for FrTp_ConfigType */
# else
typedef uint8 FrTp_ConfigType; /*!< Type to satisfy FrTp_Init() in case no C-struct is required to initialize the FrTp. */
typedef FrTp_ConfigType FrTpPbConfigType; /*!< Alias for FrTp_ConfigType */

# endif

/*********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* FRTP_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Types.h
 *********************************************************************************************************************/


