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
 *            Module: FrIf
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrIf_Types.h
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

/**        \file  FrIf_Types.h
 *        \brief  FrIf Types header file
 *
 *      \details  Types header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/
 
#if (!defined FRIF_TYPES_H)
# define FRIF_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "Fr_GeneralTypes.h"
# include "FrIf_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Keyword macros */
# if !defined (STATIC)                                                                 /* COV_FRIF_MSR_COMPATIBILITY */
#  define STATIC static
# endif

# if !defined (LOCAL_INLINE)                                                           /* COV_FRIF_MSR_COMPATIBILITY */
#  define LOCAL_INLINE INLINE STATIC
# endif

# if !defined (FRIF_LOCAL)                                                             /* COV_FRIF_MSR_COMPATIBILITY */
#  define FRIF_LOCAL STATIC
# endif

# if !defined (FRIF_LOCAL_INLINE)                                                      /* COV_FRIF_MSR_COMPATIBILITY */
#  define FRIF_LOCAL_INLINE LOCAL_INLINE
# endif

/* JobConfigMasks */
# define FrIf_JobDataIsRxTask                  ((uint8)0x04u)
# define FrIf_JobDataIsLastFrIfRxTaskForNm     ((uint8)0x08u)
# define FrIf_JobDataIsLastFrIfRxTaskForTp     ((uint8)0x10u)
# define FrIf_JobIsConfirmedBeforeTx           ((uint8)0x20u)

/* TxPduConfigMasks */
# define FrIf_TxPduOwner                       ((uint8)0x0Fu)
# define FrIf_TxPduIsTxConfirmation            ((uint8)0x10u)
# define FrIf_TxPduIsImmediateTx               ((uint8)0x20u)
# define FrIf_TxPduIsTransmitAlways            ((uint8)0x40u)
# define FrIf_TxPduHasTxRequestCounter         ((uint8)0x80u)

/* RxPduConfigMasks */
# define FrIf_RxPduOwner                       ((uint8)0x0Fu)
# define FrIf_RxPduIsNullRxIndication          ((uint8)0x10u)

/* FrameConfigMasks */
# define FrIf_FrameIsTxConfirmation            ((uint8)0x01u)
# define FrIf_FrameIsImmediateTx               ((uint8)0x02u)
# define FrIf_FrameIsTransmitAlways            ((uint8)0x04u)
# define FrIf_FrameIsNullRxIndication          ((uint8)0x08u)
# define FrIf_FrameIsDynamicLSduLength         ((uint8)0x10u)
# define FrIf_FrameIsInterruptMode             ((uint8)0x20u)
# define FrIf_FrameHasPduWithUpdateBit         ((uint8)0x40u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

 # define FrIf_IsPostbuild() (   (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) \
                              || (FRIF_POSTBUILD_VARIANT_SUPPORT == STD_ON))

# define FRIF_P2CONSTCFGROOT(Type)       P2CONST(Type, AUTOMATIC, FRIF_CONST)
# define FRIF_P2CONSTCFG(Type)           P2CONST(Type, AUTOMATIC, FRIF_CONST)
# define FRIF_P2CONSTAPPLDATA(Type)      P2CONST(Type, AUTOMATIC, FRIF_APPL_DATA)

  
# define FrTrcv_SetTransceiverMode(ChnlIdx, TrcvMode)               FrTrcv_SetTransceiverModeFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), TrcvMode)
# define FrTrcv_GetTransceiverMode(ChnlIdx, TrcvModePtr)            FrTrcv_GetTransceiverModeFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), TrcvModePtr)
# define FrTrcv_GetTransceiverWUReason(ChnlIdx, TrcvWUReasonPtr)    FrTrcv_GetTransceiverWUReasonFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), TrcvWUReasonPtr)
# define FrTrcv_EnableTransceiverBranch(ChnlIdx, BranchIdx)         FrTrcv_EnableTransceiverBranchFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), BranchIdx)
# define FrTrcv_DisableTransceiverBranch(ChnlIdx, BranchIdx)        FrTrcv_DisableTransceiverBranchFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), BranchIdx)
# define FrTrcv_CheckWakeupByTransceiver(ChnlIdx)                   FrTrcv_CheckWakeupByTransceiverFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx))
# define FrTrcv_GetTransceiverError(ChnlIdx, BranchIdx, ErrorState) FrTrcv_GetTransceiverErrorFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx), BranchIdx, ErrorState)
# define FrTrcv_ClearTransceiverWakeup(ChnlIdx)                     FrTrcv_ClearTransceiverWakeupFctMap[FrIf_GetTransceiverMapIdx(ChnlIdx)](FrIf_GetTransceiverTrcvIdx(ChnlIdx))


/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/** BusTrcvErrorType (*FrTrcv_SetTransceiverModeFctType)(uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvModeType FrTrcv_TrcvMode)); */
typedef P2FUNC(BusTrcvErrorType, FRIF_APPL_CODE, FrTrcv_SetTransceiverModeFctType) (uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvModeType FrTrcv_TrcvMode);

/** BusTrcvErrorType (*FrTrcv_GetTransceiverModeFctType)(uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvModeType* FrTrcv_TrcvModePtr)); */
typedef P2FUNC(BusTrcvErrorType, FRIF_APPL_CODE, FrTrcv_GetTransceiverModeFctType) (uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRIF_APPL_DATA) FrTrcv_TrcvModePtr);

/** BusTrcvErrorType (*FrTrcv_GetTransceiverWUReasonFctType)(uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvWUReasonType* FrTrcv_TrcvWUReasonPtr)); */
typedef P2FUNC(BusTrcvErrorType, FRIF_APPL_CODE, FrTrcv_GetTransceiverWUReasonFctType) (uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRIF_APPL_DATA) FrTrcv_TrcvWUReasonPtr);

/** Std_ReturnType (*FrTrcv_EnableTransceiverBranchFctType)(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx); */
typedef P2FUNC(Std_ReturnType, FRIF_APPL_CODE, FrTrcv_EnableTransceiverBranchFctType) (uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx);

/** Std_ReturnType (*FrTrcv_DisableTransceiverBranchFctType)(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx); */
typedef P2FUNC(Std_ReturnType, FRIF_APPL_CODE, FrTrcv_DisableTransceiverBranchFctType) (uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx);

/** void (*FrTrcv_CheckWakeupByTransceiverFctType)(uint8 FrTrcv_TrcvIdx); */
typedef P2FUNC(void, FRIF_APPL_CODE, FrTrcv_CheckWakeupByTransceiverFctType) (uint8 FrTrcv_TrcvIdx);

/** Std_ReturnType (*FrTrcv_GetTransceiverErrorFctType)(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrTrcv_BusErrorStatePtr); */
typedef P2FUNC(Std_ReturnType, FRIF_APPL_CODE, FrTrcv_GetTransceiverErrorFctType) (uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrTrcv_BusErrorStatePtr);

/** BusTrcvErrorType (*FrTrcv_ClearTransceiverWakeupFctType)(uint8 FrTrcv_TrcvIdx); */
typedef P2FUNC(BusTrcvErrorType, FRIF_APPL_CODE, FrTrcv_ClearTransceiverWakeupFctType) (uint8 FrTrcv_TrcvIdx);


/** Variables of this type are used to represent the FrIf state of a FlexRay cluster \trace SPEC-8414 */
typedef uint8 FrIf_StateType;
# define FRIF_STATE_OFFLINE ((FrIf_StateType)0x00)  /**< The FlexRay CC is not ready for communication, the FlexRay cluster is not synchronized. */
# define FRIF_STATE_ONLINE  ((FrIf_StateType)0x01)  /**< The FlexRay CC is ready for communication, the FlexRay cluster is synchronized. */

/** Variables of this type are used to represent the FrIf transition state (requested by the FrSM) of a FlexRay cluster \trace SPEC-8351 */
typedef uint8 FrIf_StateTransitionType;
# define FRIF_GOTO_OFFLINE ((FrIf_StateTransitionType)0x00)  /**< Request transition to FRIF_STATE_OFFLINE */
# define FRIF_GOTO_ONLINE  ((FrIf_StateTransitionType)0x01)  /**< Request transition to FRIF_STATE_ONLINE */

/** Variables of this type are used to represent the DET Error IDs reported by the FlexRay Interface \trace SPEC-30078, SPEC-29972 */
typedef uint8 FrIf_ErrorCodes;
# define FRIF_E_NO_ERROR            ((FrIf_ErrorCodes)0xFF)  /**< No error */
# define FRIF_E_INV_POINTER         ((FrIf_ErrorCodes)0x01)  /**< Invalid pointer */
# define FRIF_E_INV_CTRL_IDX        ((FrIf_ErrorCodes)0x02)  /**< Invalid Controller index */
# define FRIF_E_INV_CLST_IDX        ((FrIf_ErrorCodes)0x03)  /**< Invalid Cluster index */
# define FRIF_E_INV_CHNL_IDX        ((FrIf_ErrorCodes)0x04)  /**< Invalid Channel index */
# define FRIF_E_INV_TIMER_IDX       ((FrIf_ErrorCodes)0x05)  /**< Invalid timer index */
# define FRIF_E_INV_TXPDUID         ((FrIf_ErrorCodes)0x06)  /**< Invalid FrIf_TxPdu Index */
# define FRIF_E_NOT_INITIALIZED     ((FrIf_ErrorCodes)0x08)  /**< FrIf not initialized */
# define FRIF_E_JLE_SYNC            ((FrIf_ErrorCodes)0x09)  /**< Job List Execution not synchronized with the FlexRay Global Time */
# define FRIF_E_TASK_RET_E_NOT_OK   ((FrIf_ErrorCodes)0x26)  /**< FrIf_TxTask_0 returned E_NOT_OK */
# define FRIF_E_INVALID_PDU_OWNER   ((FrIf_ErrorCodes)0x27)  /**< FrIf_TxTask_0 returned E_NOT_OK */

typedef uint8 FrIf_RxHandleType;

typedef uint8 FrIf_TxHandleType;

typedef FRIF_P2CONSTCFG(FrIf_RxHandleType)              FrIf_RxHandlePtrType;
typedef FRIF_P2CONSTCFG(FrIf_TxHandleType)              FrIf_TxHandlePtrType;
typedef uint8											FrIf_CycleMaskType;
/** FrIf_JobDescriptorType */
typedef struct
{
  uint16 StartTimeInMacroTicks;   /**< Macrotick when the job is supposed to start */
  uint16 StartTimeProtectedRange; /**< Start of the macrotick range when the job's frames actually are in the bus */
  uint16 EndTimeProtectedRange;   /**< End of the macrotick range when the job's frames actually are in the bus */
  uint16 MaxDelay;                /**< Maximum delay (in macroticks) allowed before the actual start of the job */
  uint16 MinColumnNumber;         /**< First column of the communication matrix related to the job */
  uint16 MaxColumnNumber;         /**< Last column of the communication matrix related to the job */
  uint8 MinTxConfJobNo;           /**< First Tx job configured to be confirmed by the job */
  uint8 MaxTxConfJobNo;           /**< Last Tx Job configured to be confirmed by the job */
  uint8 JobConfig;                /**< Bit array containing information about the job */
} FrIf_JobDescriptorType;

/** FrIf_TxPduDescriptorType */
typedef struct
{
  PduIdType TxRequestCounterIndex; /**< Index of the request counter related to the PDU */
  PduIdType UpperLayerPduId;       /**< PDU's handle within the handle space of the upper layer */
  uint8 PduLength;                 /**< PDU's configured length */
  uint8 PduConfig;                 /**< Bit array containing information about the PDU */
} FrIf_TxPduDescriptorType;

/** FrIf_TxPduTranslationTupleType */
typedef struct
{
  PduIdType InternalTxPduId;       /**< Index of the PDU descriptor related to the PDU */
  uint8 ControllerIdx;             /**< Index of the controller related to the PDU */
} FrIf_TxPduTranslationTupleType;

/** FrIf_RxPduDescriptorType */
typedef struct
{
  PduIdType Id;             /**< PDU's handle within the handle space of the upper layer */
  uint8 PduLength;          /**< PDU's configured length */
  uint8 PduConfig;          /**< Bit array containing information about the PDU */
} FrIf_RxPduDescriptorType;

/** FrIf_FrameLayoutElementType */
typedef struct
{
  PduIdType PduHandle;         /**< Index of the PDU descriptor related to the FLE */
  uint8 ByteOffsetInFrame;     /**< PDU's position within the frame */
  uint8 UpdateBitBytePos;      /**< Position within the frame of the byte containing the PDU's update-bit */
  uint8 UpdateBitMask;         /**< Mask used to access the PDU's update-bit */
} FrIf_FrameLayoutElementType;

/** FrIf_FrameDescriptorType */
typedef struct
{
  FrIf_FLEIdxType FirstFrameLayoutElementHandle; /**< Index of the first FLE related to the frame */
  FrIf_NumberOfPduType NumberOfPdus;             /**< Number of PDUs contained in the frame */
  uint8 FrameLength;                             /**< Frame's configured length */
  uint8 FrameConfig;                             /**< Bit array containing information about the frame */
} FrIf_FrameDescriptorType;

/** FrIf_TransceiverDescriptorType */
typedef struct
{
  uint8 TrcvFctMapIdx; /**< Index of the functions related to the transceiver within the different function maps */
  uint8 TrcvIdx;       /**< Transceiver's handle within the handle space of the related FlexRay Transceiver Driver */
} FrIf_TransceiverDescriptorType;

typedef FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType)       FrIf_TxPduDescriptorPtrType;
typedef FRIF_P2CONSTCFG(FrIf_RxPduDescriptorType)       FrIf_RxPduDescriptorPtrType;
typedef FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType)    FrIf_FrameLayoutElementPtrType;
typedef FRIF_P2CONSTCFG(FrIf_FrameDescriptorType)       FrIf_FrameDescriptorPtrType;
typedef FRIF_P2CONSTCFG(FrIf_JobDescriptorType)         FrIf_JobDescriptorPtrType;
typedef FRIF_P2CONSTCFG(FrIf_CycleMaskType)             FrIf_CycleMaskPtrType;

typedef uint8 FrIf_ConfigType;

#endif
/* FRIF_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Types.h
 *********************************************************************************************************************/
