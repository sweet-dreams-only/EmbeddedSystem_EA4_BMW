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
 *         File:  IpduM.c
 *      Project:  MICROSAR IpduM
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Microsar IPDU Multiplexer source file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define IPDUM_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 3109 EOF */ /* MD_MSR_19.4 */
/* PRQA S 2006 EOF */ /* MD_MSR_14.7 */
/* PRQA S 3355, 3356, 3358, 3359 EOF */ /* MD_CSL_3355_3356_3358_3359 */
/* *INDENT-ON* */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "IpduM.h"
#include "IpduM_Cbk.h"
#include "SchM_IpduM.h"
#include "vstdlib.h"

#if (IPDUM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if ((IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON) || (IPDUM_RXMUXPDU == STD_ON) || (IPDUM_CONTAINERRXBUFFER == STD_ON) || (IPDUM_CONTAINERTXBUFFER == STD_ON)) /* COV_IPDUM_EMPTY_CONFIG */
# include "PduR_IpduM.h"
#endif
#if(IPDUM_DIRECT_COM_INVOCATION == STD_ON)
# include "Com_Cbk.h"
#endif
#if(IPDUM_USE_INIT_POINTER == STD_ON)
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if ((IPDUM_SW_MAJOR_VERSION != 6U) || (IPDUM_SW_MINOR_VERSION != 6U) || (IPDUM_SW_PATCH_VERSION != 4U))
# error "IpduM.c: IpduM.c and IpduM.h versions are inconsistent!"
#endif

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
#define IPDUM_BYTESIZE                          8U

#define IPDUM_RESET                             0U

#define IPDUM_HEADERSIZE_SMALL                  4U
#define IPDUM_HEADERSIZE_LARGE                  8U

#if(IPDUM_DIRECT_COM_INVOCATION == STD_ON)
# if(IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON)
#  define PduR_IpduMTriggerTransmit   Com_TriggerTransmit    /* PRQA S 3436 */  /* MD_IpduM_3436 */
# endif
# if(IPDUM_UL_TX_CONFIRMATION_API == STD_ON)
#  define PduR_IpduMTxConfirmation    Com_TxConfirmation     /* PRQA S 3436 */  /* MD_IpduM_3436 */
# endif
# define PduR_IpduMRxIndication      Com_RxIndication       /* PRQA S 3436 */   /* MD_IpduM_3436 */
#endif

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/
#if (IPDUM_DEV_ERROR_REPORT == STD_ON)
                    /* PRQA S 3453 1 */ /* MD_MSR_19.7 */
# define IpduM_Det_ReportError(ApiId, ErrorCode)    (void)Det_ReportError(IPDUM_MODULE_ID, 0, (ApiId), (ErrorCode))
#endif

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#define IPDUM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

#if(IPDUM_USE_INIT_POINTER == STD_ON)
static P2CONST(IpduM_ConfigType, IPDUM_VAR_ZERO_INIT, IPDUM_PBCFG) IpduM_ConfigDataPtr = NULL_PTR;
#endif

#define IPDUM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

#if ((IPDUM_TXCONTAINEDPDU == STD_ON) || (IPDUM_RXCONTAINERPDU == STD_ON))
/* Stores the information about the header of a contained pdu. */
typedef struct
{
  uint32 headerId;
  uint32 dlc;
} IpduM_ContainedPduHeaderType;
#endif

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

#if (IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON || IPDUM_RXMUXPDU == STD_ON)
/*******************************************************************************************
*  IpduM_CopySegments()
*******************************************************************************************/
/*! \brief        Copies segments in PDUs
 *  \param[in]    segmentStartIdx
 *  \param[in]    segmentEndIdx
 *  \param[out]   destPtr           Pointer to target buffer
 *  \param[in]    srcPtr            Pointer to source buffer
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different segments
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void,
                        IPDUM_CODE) IpduM_CopySegments(IpduM_SegmentIterType segmentStartIdx,
                                                       IpduM_SegmentIterType segmentEndIdx, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) destPtr, P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) srcPtr);
#endif

#if((IPDUM_JITUPDATEOFTXPART == STD_ON) && (IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON))
/*******************************************************************************************
 *  IpduM_JitUpdate()
*******************************************************************************************/
/*! \brief          Updates static and dynamic parts via Trigger Transmit, if configured.
 *  \param[in]      txPathwayId       tx pathway handle
 *  \param[in,out]  pduInfoPtr        pointer and length of the provided buffer and length of the copied data on return
 *  \param[in]      isTriggerTransmit true for triggertransmit, false for direct transmission
 *  \param[in]      txPartId          id of triggered part for direct transmission, ignored for triggertransmit
 *  \return         E_OK              the trigger transmit call has been successful and data has been updated.
 *  \return         E_NOT_OK          the trigger transmit call has been rejected by the upper layer.
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different tx Pathway IDs
 *  \synchronous    TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_JitUpdate(IpduM_TxPathwayIterType txPathwayId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) pduInfoPtr, boolean isTriggerTransmit,
                                                                    IpduM_TxUpIndIdxOfTxUpInfoType txPartId);

/*******************************************************************************************
 *  IpduM_JitTriggerTransmit()
*******************************************************************************************/
/*! \brief          Updates parts via Trigger Transmit.
 *  \param[in]      PdumTxPduId     upper layer trigger transmit handle
 *  \param[in]      txPathwayId     tx pathway handle
 *  \param[in]      txPartId        tx part handle
 *  \param[in,out]  pduInfoPtr      pointer and length of the provided buffer and length of the copied data on return
 *  \return         E_OK            the trigger transmit call has been successful and data has been updated.
 *  \return         E_NOT_OK        the trigger transmit call has been rejected by the upper layer.
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different tx Pathway IDs
 *  \synchronous    TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_JitTriggerTransmit(PduIdType PdumTxPduId, IpduM_TxPathwayIterType txPathwayId, IpduM_TxPartIterType txPartId,
                                                                             P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) pduInfoPtr);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerWriteHeader()
*******************************************************************************************/
/*! \brief        Writes the header to the container PDU buffer
 *  \param[out]   pContainerBuf   Pointer to buffer containing container PDU
 *  \param[in]    header          Header information: ID and DLC
 *  \param[in]    headerSize
 *  \param[in]    freeBytes       Number of free bytes in the buffer, used to verify the header fits into the container
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different buffers
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void,
                        IPDUM_CODE) IpduM_ContainerWriteHeader(P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf,
                                                               P2CONST(IpduM_ContainedPduHeaderType, AUTOMATIC, IPDUM_APPL_DATA) header, uint32 headerSize, uint32 freeBytes);
#endif

#if ((IPDUM_TXCONTAINEDPDU == STD_ON) || (IPDUM_RXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerReadHeader()
*******************************************************************************************/
/*! \brief        Reads the header from the start position of the provided buffer
 *  \param[in]    headerSize
 *  \param[in]    pContainerBuf   Pointer to buffer containing container PDU, must be at least headerSize bytes large!
 *  \return       header          Header at the beginning of the provided container PDU buffer
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different buffers
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(IpduM_ContainedPduHeaderType, IPDUM_CODE) IpduM_ContainerReadHeader(P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf, uint32 headerSize);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_GetRxHeaderSize()
*******************************************************************************************/
/*! \brief        Gets header size for given container.
 *  \param[in]    rxContainerId
 *  \return       headerSize
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_GetRxHeaderSize(IpduM_RxContainerPduIterType rxContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_GetTxHeaderSize()
*******************************************************************************************/
/*! \brief        Gets header size for given container.
 *  \param[in]    txContainerId
 *  \return       headerSize
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_GetTxHeaderSize(IpduM_TxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitCurrContainerPdu()
*******************************************************************************************/
/*! \brief        Transmits current Container PDU.
 *  \details      Chooses next container after successful transmission.
 *  \param[in]    txContainerId
 *  \return       E_OK            Transmission was successful, current instance is marked empty.
 *  \return       E_NOT_OK        Transmission was unsuccessful, current instance is untouched.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TransmitCurrContainerPdu(IpduM_TxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitQueuedContainerPdu()
*******************************************************************************************/
/*! \brief        Transmits last Container PDU in the queue - if there is one.
 *  \param[in]    txContainerId
 *  \return       E_OK            Transmission was successful, last queue item is removed.
 *  \return       E_NOT_OK        Transmission was unsuccessful or nothing to transmit.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TransmitQueuedContainerPdu(IpduM_TxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_QueueCurrContainerPdu()
*******************************************************************************************/
/*! \brief        Queues Tx container queue.
 *  \details      If the queue is full: clears oldest item, throws DET, sets it as current.
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_QueueCurrContainerPdu(IpduM_TxContainerBufferInfoIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitOrQueueCurrContainerPdu()
*******************************************************************************************/
/*! \brief        Transmits (if direct transmission configured) or queues current container PDU.
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_TransmitOrQueueCurrContainerPdu(IpduM_TxContainerBufferInfoIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_AddTxPduToCurrContainer()
*******************************************************************************************/
/*! \brief        Adds contained PDU to current container PDU.
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr      Pointer to the PDU data to be transmitted.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_AddTxPduToCurrContainer(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_FillLastIsBestContainer()
*******************************************************************************************/
/*! \brief        Fills the last-is-best buffer with data via trigger transmit
 *  \param[in]    txContainerId   ID of the container PDU
 *  \param[in]    PduInfoPtr      Pointer to the PDU data to be transmitted.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_FillLastIsBestContainer(IpduM_TxContainerBufferInfoIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_UnpackRxContainerPdu()
*******************************************************************************************/
/*! \brief        Retrieves all contained PDUs from the container PDU and sends RxIndications where configured.
 *  \param[in]    rxContainerId
 *  \param[in]    PduInfoPtr      Pointer to the received PDU data.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_UnpackRxContainerPdu(IpduM_RxContainerPduIterType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_searchRxHeaderId()
*******************************************************************************************/
/*! \brief        Searches for the received Container PDU header ID in the list of Rx Contained PDUs.
 *  \param[in]    headerId          Header ID to be searched for.
 *  \return       rxContainedPduId  ID of the Container PDU. 0 = not found.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(uint32, IPDUM_CODE) IpduM_searchRxHeaderId(uint32 headerId);
#endif

#if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_searchTxHeaderId()
*******************************************************************************************/
/*! \brief        Searches for the Container PDU header ID in the list of Tx Contained PDUs for TriggerTransmit.
 *  \param[in]    headerId          Header ID to be searched for.
 *  \return       txContainedPduId  ID of the Container PDU.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
LOCAL_INLINE FUNC(PduIdType, IPDUM_CODE) IpduM_searchTxHeaderId(uint32 headerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_CalculateSizeOfContainer()
*******************************************************************************************/
/*! \brief        Calculates and returns the size of the container PDU in the passed buffer.
 *  \param[in]    PduInfoPtr        Pointer to the buffer where the container is stored and its max length.
 *  \param[in]    txContainerId
 *  \return       containerSize     Size of the container in bytes, including the closing zero-header.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \trace        SPEC-2068547
*******************************************************************************************/
LOCAL_INLINE FUNC(uint32, IPDUM_CODE) IpduM_CalculateSizeOfContainer(IpduM_TxContainerPduIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_TXPART == STD_ON)
/*******************************************************************************************
*  IpduM_MuxTransmit()
*******************************************************************************************/
/*! \brief        Requests the transmission of a static or dynamic part
 *  \param[in]    txPartId
 *  \param[in]    PduInfoPtr    Pointer to payload buffer
 *  \return       E_OK          Transmit request was accepted by IpduM and destination layer
 *  \return       E_NOT_OK      Transmit request was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102653, CREQ-102659, CREQ-102661
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_MuxTransmit(IpduM_TxUpIndIdxOfTxUpInfoType txPartId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXLOINFO == STD_ON)
/*******************************************************************************************
*  IpduM_MuxTriggerTransmit()
*******************************************************************************************/
/*! \brief          Requests the PDU data before transmission
 *  \param[in]      txPathwayHnd
 *  \param[in,out]  PduInfoPtr    pointer and length of the provided buffer and length of the copied data on return
 *  \return         E_OK          Data was copied correctly
 *  \return         E_NOT_OK      Data could not be copied correctly, PduInfoPtr does not contain valid data
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different handle IDs
 *  \synchronous    TRUE
 *  \trace          CREQ-102654, CREQ-102659, CREQ-102661
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_MuxTriggerTransmit(IpduM_TxPathwayIdxOfTxLoInfoType txPathwayHnd, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if ((IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON) || (IPDUM_TXCONFIRMATIONOFTXPART == STD_ON))
/*******************************************************************************************
*  IpduM_MuxTxConfirmation()
*******************************************************************************************/
/*! \brief        Indicates complete transmission of a PDU
 *  \param[in]    TxPduId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102655
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_MuxTxConfirmation(PduIdType TxPduId);
#endif

#if (IPDUM_RXMUXPDU == STD_ON)
/*******************************************************************************************
*  IpduM_MuxRxIndication()
*******************************************************************************************/
/*! \brief        Indicates complete reception of a PDU
 *  \param[in]    rxMuxPduId
 *  \param[out]   PduInfoPtr    Pointer to buffer containing PDU
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102656, CREQ-102660
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_MuxRxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxMuxPduId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTransmit()
*******************************************************************************************/
/*! \brief        Requests the transmission of a contained PDU
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr    Pointer to payload buffer
 *  \return       E_OK          Transmit request was accepted by IpduM
 *  \return       E_NOT_OK      Transmit request was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102653, CREQ-102672, CREQ-102673, SPEC-2068537, SPEC-2068538, SPEC-2068539, SPEC-2068543, SPEC-2068545, SPEC-2068549, SPEC-2068551, SPEC-2068552
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTransmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTriggerTransmit()
*******************************************************************************************/
/*! \brief          Requests the PDU data before transmission
 *  \param[in]      txContainerId
 *  \param[in,out]  PduInfoPtr    Pointer to lower layer buffer
 *  \return         E_OK          Data was copied correctly
 *  \return         E_NOT_OK      Data could not be copied correctly, PduInfoPtr does not contain valid data
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different handle IDs
 *  \synchronous    TRUE
 *  \trace          CREQ-102654
*******************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTriggerTransmit(IpduM_TxContainerPduIdxOfTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if ((IPDUM_TX_CONFIRMATION_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerTxConfirmation()
*******************************************************************************************/
/*! \brief        Indicates complete transmission of a PDU
 *  \param[in]    TxPduId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102655
*******************************************************************************************/
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTxConfirmation(PduIdType TxPduId);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerRxIndication()
*******************************************************************************************/
/*! \brief        Indicates complete reception of a PDU
 *  \param[in]    rxContainerId
 *  \param[out]   PduInfoPtr         Pointer to buffer containing PDU
 *  \return       IPDUM_E_NO_ERROR   Data was copied correctly
 *  \return       IPDUM_E_QUEUEOVFL  Data was copied correctly,
 *                                   but the oldest item in the queue has been removed.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        CREQ-102656, CREQ-102674, SPEC-2068566, SPEC-2068569, SPEC-2068570, SPEC-2068572, SPEC-2068576
*******************************************************************************************/
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerRxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/*******************************************************************************************
 *  IpduM_CopySegments()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
#if (IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON || IPDUM_RXMUXPDU == STD_ON)
LOCAL_INLINE FUNC(void,
                        IPDUM_CODE) IpduM_CopySegments(IpduM_SegmentIterType segmentStartIdx,
                                                       IpduM_SegmentIterType segmentEndIdx, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) destPtr, P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) srcPtr)
{
# if ((IPDUM_PARTIALENDBYTEOFSEGMENT == STD_ON) || (IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON))
  /* Only partial byte copy needs exclusive area for read-modify-write protection */
  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
  for(; segmentStartIdx < segmentEndIdx; segmentStartIdx++)
  {
    /* Set copy destination pointer to the start position of the provided dest buffer */
    P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pDest = &destPtr[0];
    /* Set copy source pointer to the start position of the provided source buffer */
    P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) pSrc = &srcPtr[0];

# if ((IPDUM_PARTIALENDBYTEOFSEGMENT == STD_ON) && ((IPDUM_FULLBYTESPRESENTOFSEGMENT == STD_ON) || (IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON)))
    if(IpduM_IsPartialEndByteOfSegment(segmentStartIdx))
# endif
# if (IPDUM_PARTIALENDBYTEOFSEGMENT == STD_ON)
    {
      /* copy the last (partial) byte from source to destination */
      pDest[IpduM_GetLastBytePosOfSegment(segmentStartIdx)] &= IpduM_GetEndByteMaskClearOfSegment(segmentStartIdx);     /* SBSW_IPDUM_COPYSEGMENTS */
      pDest[IpduM_GetLastBytePosOfSegment(segmentStartIdx)] |= (pSrc[IpduM_GetLastBytePosOfSegment(segmentStartIdx)] & IpduM_GetEndByteMaskWriteOfSegment(segmentStartIdx));    /* SBSW_IPDUM_COPYSEGMENTS */
    }
# endif

# if((IPDUM_FULLBYTESPRESENTOFSEGMENT == STD_ON) && (IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON))
    if(IpduM_IsFullBytesPresentOfSegment(segmentStartIdx))
# endif
# if(IPDUM_FULLBYTESPRESENTOFSEGMENT == STD_ON)
    {
      IpduM_LastFullBytePosOfSegmentType pos;
      for(pos = IpduM_GetFirstFullBytePosOfSegment(segmentStartIdx); pos <= IpduM_GetLastFullBytePosOfSegment(segmentStartIdx); pos++)
      {
        pDest[pos] = pSrc[pos]; /* SBSW_IPDUM_COPYSEGMENTS */
      }
    }
# endif

# if((IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON) && ((IPDUM_PARTIALENDBYTEOFSEGMENT == STD_ON) || (IPDUM_FULLBYTESPRESENTOFSEGMENT == STD_ON)))
    if(IpduM_IsPartialStartByteOfSegment(segmentStartIdx))
# endif
# if(IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON)
    {
      /* copy the first (partial) byte from source to destination */
      pDest[IpduM_GetFirstBytePosOfSegment(segmentStartIdx)] &= IpduM_GetStartByteMaskClearOfSegment(segmentStartIdx);  /* SBSW_IPDUM_COPYSEGMENTS */
      pDest[IpduM_GetFirstBytePosOfSegment(segmentStartIdx)] |= (pSrc[IpduM_GetFirstBytePosOfSegment(segmentStartIdx)] & IpduM_GetStartByteMaskWriteOfSegment(segmentStartIdx));        /* SBSW_IPDUM_COPYSEGMENTS */
    }
# endif
  }
# if ((IPDUM_PARTIALENDBYTEOFSEGMENT == STD_ON) || (IPDUM_PARTIALSTARTBYTEOFSEGMENT == STD_ON))
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
}
#endif

#if(IPDUM_JITUPDATEOFTXPART == STD_ON && IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON)
/*******************************************************************************************
 *  IpduM_JitUpdate()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_JitUpdate(IpduM_TxPathwayIterType txPathwayId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) pduInfoPtr, boolean isTriggerTransmit,
                                                                    IpduM_TxUpIndIdxOfTxUpInfoType txPartId)
{
  Std_ReturnType retVal = E_OK;
# if(IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON)
  if((IpduM_IsTxPartStaticPartUsedOfTxPathway(txPathwayId)) && (IpduM_IsJitUpdateOfTxPart(IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayId))))
  {
    if(((txPartId == IpduM_GetDynamicPduIdx(txPathwayId)) && (!isTriggerTransmit)) || isTriggerTransmit) /* COV_IPDUM_INVALID_CONFIG */
    {
      retVal = IpduM_JitTriggerTransmit(IpduM_GetUlPduRefOfTxPart(IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayId)), txPathwayId, IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayId), pduInfoPtr);        /* SBSW_IPDUM_JITUPDATE_CALL_JITTRIGGERTRANSMIT */
    }
  }
# endif
  {
    IpduM_TxPartIterType txDynamicPartId;
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    txDynamicPartId = (IpduM_TxPartIterType) IpduM_GetDynamicPduIdx(txPathwayId);
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

    if(IpduM_IsJitUpdateOfTxPart(txDynamicPartId))
    {
# if ((IPDUM_TRIGGEREVENTOFTXPART == STD_ON) && (IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON))
      if((isTriggerTransmit == TRUE) || ((txPartId == IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayId)) && (!isTriggerTransmit))) /* COV_IPDUM_INVALID_CONFIG */
# endif
      {
        retVal = IpduM_JitTriggerTransmit(IpduM_GetUlPduRefOfTxPart(txDynamicPartId), txPathwayId, txDynamicPartId, pduInfoPtr);        /* SBSW_IPDUM_JITUPDATE_CALL_JITTRIGGERTRANSMIT */
      }
    }
  }
# if(IPDUM_TXSTATICPDUREFOFTXPATHWAY != STD_ON)
  IPDUM_DUMMY_STATEMENT(txPartId);      /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
  return retVal;
}

/*******************************************************************************************
 *  IpduM_JitTriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_JitTriggerTransmit(PduIdType PdumTxPduId, IpduM_TxPathwayIterType txPathwayId, IpduM_TxPartIterType txPartId,
                                                                             P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) pduInfoPtr)
{
  Std_ReturnType retVal = E_OK;
  if(PduR_IpduMTriggerTransmit(PdumTxPduId, pduInfoPtr) == E_OK)        /* SBSW_IPDUM_JITTRIGGERTRANSMIT_CALL_PDURTRIGGERTRANSMIT */
  {
    IpduM_CopySegments(IpduM_GetSegmentStartIdxOfTxPart(txPartId), IpduM_GetSegmentEndIdxOfTxPart(txPartId), IpduM_GetAddrTxBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathwayId)), pduInfoPtr->SduDataPtr);      /* SBSW_IPDUM_JITTRIGGERTRANSMIT_CALL_COPYSEGMENTS */
  }
  else
  {
    retVal = E_NOT_OK;
  }
  return retVal;
}
#endif

/*******************************************************************************************
 *  IpduM_ContainerWriteHeader()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
#if (IPDUM_TXCONTAINEDPDU == STD_ON)
LOCAL_INLINE FUNC(void,
                        IPDUM_CODE) IpduM_ContainerWriteHeader(P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf,
                                                               P2CONST(IpduM_ContainedPduHeaderType, AUTOMATIC, IPDUM_APPL_DATA) header, uint32 headerSize, uint32 freeBytes)
{
  if((freeBytes >= IPDUM_HEADERSIZE_SMALL) 
# if (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON)
     && (headerSize == IPDUM_HEADERSIZE_SMALL)
# endif
    )
  {
# if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    pContainerBuf[0] = ((uint8) (header->headerId >> 0));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[1] = ((uint8) (header->headerId >> 8));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[2] = ((uint8) (header->headerId >> 16));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[3] = ((uint8) (header->dlc >> 0));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
# else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    pContainerBuf[0] = ((uint8) (header->headerId >> 16));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[1] = ((uint8) (header->headerId >> 8));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[2] = ((uint8) (header->headerId >> 0));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[3] = ((uint8) (header->dlc >> 0));    /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
# endif
  }
# if (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON)
  if((headerSize == IPDUM_HEADERSIZE_LARGE) && (freeBytes >= IPDUM_HEADERSIZE_LARGE))
  {
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    pContainerBuf[0] = ((uint8) (header->headerId >> 0));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[1] = ((uint8) (header->headerId >> 8));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[2] = ((uint8) (header->headerId >> 16));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[3] = ((uint8) (header->headerId >> 24));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[4] = ((uint8) (header->dlc >> 0));    /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[5] = ((uint8) (header->dlc >> 8));    /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[6] = ((uint8) (header->dlc >> 16));   /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[7] = ((uint8) (header->dlc >> 24));   /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    pContainerBuf[0] = ((uint8) (header->headerId >> 24));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[1] = ((uint8) (header->headerId >> 16));      /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[2] = ((uint8) (header->headerId >> 8));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[3] = ((uint8) (header->headerId >> 0));       /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[4] = ((uint8) (header->dlc >> 24));   /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[5] = ((uint8) (header->dlc >> 16));   /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[6] = ((uint8) (header->dlc >> 8));    /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
    pContainerBuf[7] = ((uint8) (header->dlc >> 0));    /* SBSW_IPDUM_CONTAINER_WRITE_HEADER */
#  endif
  }
# endif
# if (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON)
  IPDUM_DUMMY_STATEMENT(headerSize);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */  
# endif
}
#endif

#if ((IPDUM_TXCONTAINEDPDU == STD_ON) || (IPDUM_RXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerReadHeader()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(IpduM_ContainedPduHeaderType, IPDUM_CODE) IpduM_ContainerReadHeader(P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf, uint32 headerSize)
{
  IpduM_ContainedPduHeaderType header;

# if((IPDUM_LONGHEADERSOFRXCONTAINERPDU == STD_ON) || (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON))
  if(headerSize == IPDUM_HEADERSIZE_SMALL)
# endif
  {
    /* short header */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 0) |
      (((uint32) pContainerBuf[1]) << 8) |
      (((uint32) pContainerBuf[2]) << 16);
    header.dlc = ((uint32) pContainerBuf[3]);
    /* *INDENT-ON* */
# else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 16) |
      (((uint32) pContainerBuf[1]) << 8) |
      (((uint32) pContainerBuf[2]) << 0);
    header.dlc = (((uint32) pContainerBuf[3]) << 0);
    /* *INDENT-ON* */
# endif
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
# if((IPDUM_LONGHEADERSOFRXCONTAINERPDU == STD_ON) || (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON))
  else
  {
    /* long header */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 0) |
      (((uint32) pContainerBuf[1]) << 8) |
      (((uint32) pContainerBuf[2]) << 16) |
      (((uint32) pContainerBuf[3]) << 24);
    header.dlc =
      (((uint32) pContainerBuf[4]) << 0) |
      (((uint32) pContainerBuf[5]) << 8) |
      (((uint32) pContainerBuf[6]) << 16) |
      (((uint32) pContainerBuf[7]) << 24);
    /* *INDENT-ON* */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 24) |
      (((uint32) pContainerBuf[1]) << 16) |
      (((uint32) pContainerBuf[2]) << 8) |
      (((uint32) pContainerBuf[3]) << 0);
    header.dlc =
      (((uint32) pContainerBuf[4]) << 24) |
      (((uint32) pContainerBuf[5]) << 16) |
      (((uint32) pContainerBuf[6]) << 8) |
      (((uint32) pContainerBuf[7]) << 0);
    /* *INDENT-ON* */
#  endif
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
# else
  IPDUM_DUMMY_STATEMENT(headerSize);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */  
# endif
  
  return header;
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_GetRxHeaderSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_GetRxHeaderSize(IpduM_RxContainerPduIterType rxContainerId)
{
  uint8 headerSize;
# if (IPDUM_LONGHEADERSOFRXCONTAINERPDU == STD_ON)
  if(IpduM_IsLongHeadersOfRxContainerPdu(rxContainerId))
  {
    headerSize = IPDUM_HEADERSIZE_LARGE;
  }
  else
# endif
  {
    headerSize = IPDUM_HEADERSIZE_SMALL;
  }
  return headerSize;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_GetTxHeaderSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_GetTxHeaderSize(IpduM_TxContainerPduIterType txContainerId)
{
  uint8 headerSize;
# if (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON)
  if(IpduM_IsLongHeadersOfTxContainerPdu(txContainerId))
  {
    headerSize = IPDUM_HEADERSIZE_LARGE;
  }
  else
# endif
  {
    headerSize = IPDUM_HEADERSIZE_SMALL;
  }
  return headerSize;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitCurrContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TransmitCurrContainerPdu(IpduM_TxContainerPduIterType txContainerId)
{
  /** Initialize return value with "not ok" */
  Std_ReturnType transmitResult = E_NOT_OK;

# if ((IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  if((IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId) == 0u) || (IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId) && (IpduM_GetTxConfTimeoutCnt(IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId))) == 0u))) /* COV_IPDUM_DEPENDENT_VALUES */ /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
# endif
  {
    IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
    IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);
    IpduM_ContainerWriteIdxOfTxContainerBufferIdxInfoType containerWriteIdx;
    IpduM_ContainedPduWriteIdxOfTxContainerBufferIdxInfoType containedPduWriteIdx;
    
    uint8 *pContainerTxBuf;

    IpduM_ContainedPduHeaderType header;
    
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    containerWriteIdx = IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
    containedPduWriteIdx = IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

    pContainerTxBuf = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (containerWriteIdx * bufferInstanceLength) + containedPduWriteIdx);
    header.headerId = 0u;
    header.dlc = 0u;

# if (IPDUM_CONTAINERTXBUFFER==STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    {
      PduInfoType pduInfo;

      /* Add zero-header */
      IpduM_ContainerWriteHeader(pContainerTxBuf, &header, IpduM_GetTxHeaderSize(txContainerId), (bufferInstanceLength - containedPduWriteIdx));      /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_CONTAINERWRITEHEADER */
      /* Transmit container PDU */
      pduInfo.SduDataPtr = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (containerWriteIdx * bufferInstanceLength));
      pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
# if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
      if((IpduM_GetContainerTypeOfTxContainerPdu(txContainerId) == IPDUM_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU)
#  if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON) /* COV_IPDUM_LAST_IS_BEST_TRIGGERTRANSMIT */
        && (!IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
#  endif
      )
      {
        // last-is-best PDU: load data to last-is-best buffer via TriggerTransmit, then use this buffer for transmission
        IpduM_FillLastIsBestContainer(txContainerId, &pduInfo); /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_FILLLASTISBESTCONTAINER */
        pduInfo.SduDataPtr = IpduM_GetAddrContainerTxLIBBuffer(0);
      }
# endif
      pduInfo.SduLength = (PduLengthType)IpduM_CalculateSizeOfContainer(txContainerId, &pduInfo);      /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_CALCULATESIZEOFCONTAINER */
      transmitResult = PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo); /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_PDURTRANSMIT */
      if((transmitResult == E_OK)
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
        && (!IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
# endif
      )
      {
        /* Current instance transmitted successfully, this slot in queue is empty again */
        IpduM_ContainerTxConfBufStartIdxOfTxContainerPduType bufferStartIdx = IpduM_GetContainerTxConfBufStartIdxOfTxContainerPdu(txContainerId);
        IpduM_ContainerWriteIdxOfTxContainerBufferIdxInfoType currentInstance = IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
        IpduM_ContainerTxConfBuInLenType confirmationBufferInstanceLength = IpduM_GetContainerTxConfBuInLen(IpduM_GetContainerTxConfBuInLenStartIdxOfTxContainerPdu(txContainerId));
        IpduM_ContainerTxConfBufType *txConfirmationIdBuffer = IpduM_GetAddrContainerTxConfBuf(bufferStartIdx + (currentInstance * confirmationBufferInstanceLength));
        IpduM_ContainerTxConfLastType *lastTxConfirmationIdBuffer = IpduM_GetAddrContainerTxConfLast(IpduM_GetContainerTxConfLastStartIdxOfTxContainerPdu(txContainerId));
        
        /* copy transmitted PDU IDs to the "last transmitted ID buffer" and reset the source buffer */
        VStdMemCpyRamToRam(lastTxConfirmationIdBuffer, txConfirmationIdBuffer, confirmationBufferInstanceLength); /* SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU_MEMCPY */
        IpduM_SetContainerTxConfLaId(IpduM_GetContainerTxConfLaIdIdxOfTxContainerPdu(txContainerId), IpduM_GetContainerTxConfBuId(IpduM_GetTxContainerBufferInfoStartIdxOfTxContainerPdu(txContainerId) + currentInstance)); /* SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU */
        IpduM_SetContainerTxConfBuId(IpduM_GetTxContainerBufferInfoStartIdxOfTxContainerPdu(txContainerId) + currentInstance, 0); /* SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU */

#  if ((IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
        if(IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
        {
          /* Load timeout counter */
          IpduM_SetTxConfTimeoutCnt(IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId)), IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId)); /* SBSW_IPDUM_CSL03 */ /* SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU */
        }
#  endif
        /* Reset contained indices for re-use of current instance */
        IpduM_SetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);      /* SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU */
      }
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
  }

  return transmitResult;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitQueuedContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TransmitQueuedContainerPdu(IpduM_TxContainerPduIterType txContainerId)
{
  /* Initialize return value with "not ok" */
  Std_ReturnType transmitResult = E_NOT_OK;

# if ((IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  if((IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId) == 0u) || (IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId) && (IpduM_GetTxConfTimeoutCnt(IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId))) == 0u))) /* COV_IPDUM_DEPENDENT_VALUES */ /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
# endif
  {
    IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType containerWriteCount;
    IpduM_ContainerReadCountOfTxContainerBufferIdxInfoType containerReadCount;
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    containerWriteCount = IpduM_GetContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId);
    containerReadCount = IpduM_GetContainerReadCountOfTxContainerBufferIdxInfo(txContainerId);
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    if((IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType)(containerWriteCount - containerReadCount) >= 1u)
    {
      /* At least 1 item in the queue */

      PduInfoType pduInfo;
      IpduM_CountOfTxContainerBufferInfoType bufferInstanceCount = IpduM_GetCountOfTxContainerBufferInfo(txContainerId);
      IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
      IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);

      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();

      /* Transmit container PDU */
      pduInfo.SduDataPtr = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) * bufferInstanceLength));
      pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
#  if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
      if(IpduM_GetContainerTypeOfTxContainerPdu(txContainerId) == IPDUM_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU){
        /* last-is-best PDU: load data to last-is-best buffer via TriggerTransmit, then use this buffer for transmission */
        IpduM_FillLastIsBestContainer(txContainerId, &pduInfo); /* SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_FILLLASTISBESTCONTAINER */
        pduInfo.SduDataPtr = IpduM_GetAddrContainerTxLIBBuffer(0);
      }
#  endif
      pduInfo.SduLength = (PduLengthType)IpduM_CalculateSizeOfContainer(txContainerId, &pduInfo);      /* SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_CALCULATESIZEOFCONTAINER */
      transmitResult = PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo); /* SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_PDURTRANSMIT */

      /* If transmission successful, update read pointer and read count */
      if((transmitResult == E_OK)
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
        && (!IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
# endif
      )
      {
# if ((IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
        if(IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId))
        {
          /* Load timeout counter */
          IpduM_SetTxConfTimeoutCnt(IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId)), IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId)); /* SBSW_IPDUM_CSL03 */ /* SBSW_IPDUM_TRANSMIT_QUEUED_CONTAINER_PDU */
        }
# endif
        IpduM_IncContainerReadCountOfTxContainerBufferIdxInfo(txContainerId);   /* SBSW_IPDUM_TRANSMIT_QUEUED_CONTAINER_PDU */
        IpduM_IncContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId);     /* SBSW_IPDUM_TRANSMIT_QUEUED_CONTAINER_PDU */
        if(IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) >= bufferInstanceCount)
        {
          IpduM_SetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);        /* SBSW_IPDUM_TRANSMIT_QUEUED_CONTAINER_PDU */
        }
      }
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
      if(IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
      {
        /* If a TriggerTransmit PDU is in the queue, it must stay there.
         * The MainFunctionTx loops until the queue is empty or E_NOT_OK
         * is returned. This avoids endless loops. */
        transmitResult = E_NOT_OK;
      }
# endif

      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }
  }
  return transmitResult;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_QueueCurrContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_QueueCurrContainerPdu(IpduM_TxContainerBufferInfoIterType txContainerId)
{
  uint8 errorId = IPDUM_E_NO_ERROR;

  IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
  IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);
  IpduM_CountOfTxContainerBufferInfoType bufferInstanceCount = IpduM_GetCountOfTxContainerBufferInfo(txContainerId);
  IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType containerWriteCount;
  IpduM_ContainerReadCountOfTxContainerBufferIdxInfoType containerReadCount;
  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  containerWriteCount = IpduM_GetContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId);
  containerReadCount = IpduM_GetContainerReadCountOfTxContainerBufferIdxInfo(txContainerId);
  
  if((IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType)(containerWriteCount - containerReadCount) >= bufferInstanceCount)
  {
    /* Queue is full, throw a DET error (increment of write ptr will overwrite oldest item). */
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
    errorId = IPDUM_E_QUEUEOVFL;
# endif
    /* increment read pointer */
    IpduM_IncContainerReadCountOfTxContainerBufferIdxInfo(txContainerId);       /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    IpduM_IncContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId); /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    if(IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) >= bufferInstanceCount)
    {
      IpduM_SetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);    /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    }
  }

  {
    IpduM_ContainedPduHeaderType header;
    uint8 *pContainerTxBuf;
    IpduM_ContainerWriteIdxOfTxContainerBufferIdxInfoType containerWriteIdx;
    IpduM_ContainedPduWriteIdxOfTxContainerBufferIdxInfoType containedPduWriteIdx;
    containerWriteIdx = IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
    containedPduWriteIdx = IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId);

    header.headerId = 0u;
    header.dlc = 0u;

    pContainerTxBuf =
      IpduM_GetAddrContainerTxBuffer(bufferStartPos + (containerWriteIdx * bufferInstanceLength) + containedPduWriteIdx);

    /* before adding the PDU to the queue, add a zero-header */
    IpduM_ContainerWriteHeader(pContainerTxBuf, &header, IpduM_GetTxHeaderSize(txContainerId), (bufferInstanceLength - containedPduWriteIdx));        /* SBSW_IPDUM_QUEUECURRCONTAINERPDU_CALL_CONTAINERWRITEHEADER */

    /* Queue the container PDU (i.e. increment write pointer). */
    IpduM_IncContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId);      /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    IpduM_IncContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId);        /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    if(IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId) >= bufferInstanceCount)
    {
      IpduM_SetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);   /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
    }
    /* The new instance is empty, clear contained indices */
    IpduM_SetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);  /* SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU */
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_TRANSMIT, (errorId));
  }
# else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_TransmitOrQueueCurrContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_TransmitOrQueueCurrContainerPdu(IpduM_TxContainerBufferInfoIterType txContainerId)
{
  Std_ReturnType transmitResult = E_NOT_OK;
  /* Direct transmission is configured: transmit current container PDU. */
  transmitResult = IpduM_TransmitCurrContainerPdu(txContainerId);

  if((transmitResult == E_NOT_OK)
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
    || IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId)
# endif
  )
  {
    /* Triggertransmit is configured or direct transmission failed: queue the container PDU. With the optimization of the current container being inside the queue, too, this means increase write ptr */
    IpduM_QueueCurrContainerPdu(txContainerId);
  }

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  IpduM_SetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId, 0u); /* SBSW_IPDUM_TRANSMIT_OR_QUEUE_CURR_CONTAINER_PDU */
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_AddTxPduToCurrContainer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_AddTxPduToCurrContainer(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  IpduM_TxContainerBufferInfoIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
  IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);

  uint8 headerSize = IpduM_GetTxHeaderSize(txContainerId);

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  {
    uint8 *pContainerTxBuf;
    IpduM_ContainedPduHeaderType header;
    pContainerTxBuf =
      IpduM_GetAddrContainerTxBuffer(bufferStartPos +
                                     (IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId) *
                                      bufferInstanceLength) + IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId));

    header.headerId = IpduM_GetHeaderIdOfTxContainedPdu(txContainedId);
    header.dlc = PduInfoPtr->SduLength;

    /* Write the header to the buffer */
    IpduM_ContainerWriteHeader(pContainerTxBuf, &header, headerSize, (bufferInstanceLength - IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId)));  /* SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_CALL_CONTAINERWRITEHEADER */

    /* Write the sdu to the buffer */
    VStdMemCpyRamToRam(&pContainerTxBuf[headerSize], PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);    /* SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_CALL_MEMCPY */
    IpduM_SetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId, IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId) + headerSize + PduInfoPtr->SduLength);        /* SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_INDIRECT_ACCESS */
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
}
#endif

#if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_FillLastIsBestContainer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_FillLastIsBestContainer(IpduM_TxContainerBufferInfoIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  uint8 *lastIsBestBuffer;
  PduLengthType lastIsBestWriteIdx = 0u;
  PduLengthType requestReadIdx = 0u;
  IpduM_ContainedPduHeaderType currentHeader;
  IpduM_ContainerTxConfLastIterType txConfLastId = 0u;
  IpduM_ContainerTxConfLastType *txConfLast;
  PduIdType containedPduId;
  IpduM_SizeOfContainerTxLIBBufferType bufferInstanceLength = IpduM_GetSizeOfContainerTxLIBBuffer();
  PduLengthType containerBufId;
  
  PduLengthType headerSize = (PduLengthType) IpduM_GetTxHeaderSize(txContainerId);
  
  lastIsBestBuffer = IpduM_GetAddrContainerTxLIBBuffer(0);
  txConfLast = IpduM_GetAddrContainerTxConfLast(IpduM_GetContainerTxConfLastStartIdxOfTxContainerPdu(txContainerId));
  
  /* this loop implicitly drops all contained PDUs that don't fit into the container anymore after TriggerTransmit */
  while((requestReadIdx + headerSize) < PduInfoPtr->SduLength)
  {
    PduInfoType pduInfo;
    /* read header to get ID for trigger transmit */
    currentHeader = IpduM_ContainerReadHeader(&(PduInfoPtr->SduDataPtr[requestReadIdx]), headerSize); /* SBSW_IPDUM_ANY_CALL_CONTAINERREADHEADER */
    
    /* detect end of container */
    if(currentHeader.headerId == 0u)
    {
      break;
    }
    
    /* fetch data by trigger transmit */
    pduInfo.SduDataPtr = &lastIsBestBuffer[(headerSize + lastIsBestWriteIdx)]; /* data starts after the header */
    pduInfo.SduLength = (PduInfoPtr->SduLength - requestReadIdx - headerSize); /* available size left in buffer */
    containedPduId = IpduM_searchTxHeaderId(currentHeader.headerId);
    if(PduR_IpduMTriggerTransmit(IpduM_GetTxContainedPduRefOfTxContainedPdu(containedPduId), &pduInfo) == E_OK) /* SBSW_IPDUM_FILLLASTISBEST_CALL_PDURTRIGGERTRANSMIT */
    {
      /* triggertransmit was successful, write header with correct size and increment write IDX */
      IpduM_ContainedPduHeaderType newHeader;
      newHeader.headerId = currentHeader.headerId;
      
      /* write id to TxConfirmation last ID buffer */
      txConfLast[txConfLastId] = containedPduId; /* SBSW_IPDUM_FILLLASTISBEST_ARRAY_ACCESS */
      txConfLastId++;
      
      newHeader.dlc = pduInfo.SduLength; /* updated value from TriggerTransmit call */
      IpduM_ContainerWriteHeader(&lastIsBestBuffer[lastIsBestWriteIdx], &newHeader, headerSize, (PduInfoPtr->SduLength - requestReadIdx)); /* SBSW_IPDUM_FILLLASTISBEST_CALL_CONTAINERWRITEHEADER */
      lastIsBestWriteIdx += (PduLengthType)(headerSize + newHeader.dlc);
    }
    
    /* always increment read IDX, safe termination of the while-loop */
    requestReadIdx += (PduLengthType)(headerSize + currentHeader.dlc);/* using old DLC before trigger transmit update for the request queue read IDX */
  }
  /* add zero header for safe PDU termination */
  for(containerBufId = lastIsBestWriteIdx; (containerBufId<bufferInstanceLength) && (containerBufId < (lastIsBestWriteIdx + headerSize));containerBufId++) /* COV_IPDUM_TERMINATION_ZEROES */
  {
    lastIsBestBuffer[containerBufId] = 0; /* SBSW_IPDUM_FILLLASTISBEST_MEMORY_WRITE */
  }
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_UnpackRxContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_UnpackRxContainerPdu(IpduM_RxContainerPduIterType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  PduLengthType containedPduIdx = 0u;
  uint8 headerSize = IpduM_GetRxHeaderSize(rxContainerId);

  /* loop over all contained-pdus */
  while((containedPduIdx + headerSize) < PduInfoPtr->SduLength) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_ContainedPduHeaderType header;        /* header.headerId; header.dlc */

    /* get header id and dlc of the contained PDU */
    header = IpduM_ContainerReadHeader(&(PduInfoPtr->SduDataPtr[containedPduIdx]), headerSize); /* SBSW_IPDUM_ANY_CALL_CONTAINERREADHEADER */

    /* Increment read idx to begin of pdu */
    containedPduIdx += headerSize;

    /* if header id == 0: break loop */
    if(header.headerId == 0u)
    {
      break;
    }
    if(((containedPduIdx) + header.dlc) <= PduInfoPtr->SduLength) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
    {
      /* look up the header id in IpduM_RxContainedPdu */
      uint32 rxContainedPduId = IpduM_searchRxHeaderId(header.headerId);
      /* check if either "accept all" is configured or PDU is configured for this container */
      if((IpduM_IsRxContainerPduUsedOfRxContainedPdu(rxContainedPduId) && (IpduM_GetRxContainerPduIdxOfRxContainedPdu(rxContainedPduId) == rxContainerId))
# if (IPDUM_ACCEPTALLPDUSOFRXCONTAINERPDU == STD_ON)
         || IpduM_IsAcceptAllPdusOfRxContainerPdu(rxContainerId)
# endif
        )
      {
        if(rxContainedPduId < IpduM_GetSizeOfRxContainedPdu())
        {
          /* header id exists */
          PduInfoType pduInfo;
          pduInfo.SduDataPtr = &(PduInfoPtr->SduDataPtr[containedPduIdx]);
          pduInfo.SduLength = (PduLengthType) header.dlc;
          /* send RxIndication for the referenced PduR-PDU to PduR module */
          PduR_IpduMRxIndication(IpduM_GetContainedPduRefOfRxContainedPdu(rxContainedPduId), &pduInfo); /* SBSW_IPDUM_UNPACKRXCONTAINERPDU_CALL_PDURRXINDICATION */
        }
      }
    }

    /* increment contained pdu read idx by dlc */
    containedPduIdx += (PduLengthType) header.dlc;
  }
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_searchRxHeaderId()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(uint32, IPDUM_CODE) IpduM_searchRxHeaderId(uint32 headerId)
{
  uint32 rxContainedPduId;
  for(rxContainedPduId = 0u; rxContainedPduId < IpduM_GetSizeOfRxContainedPdu(); rxContainedPduId++) /* COV_IPDUM_SEARCH_HEADER_ID_LOOP_ABORT */
  {
    if(IpduM_GetHeaderIdOfRxContainedPdu(rxContainedPduId) == headerId)
    {
      break;
    }
  }
  return rxContainedPduId;
}
#endif

#if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_searchTxHeaderId()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(PduIdType, IPDUM_CODE) IpduM_searchTxHeaderId(uint32 headerId)
{
  PduIdType txContainedPduId;
  for(txContainedPduId = 0u; txContainedPduId < IpduM_GetSizeOfTxContainedPdu(); txContainedPduId++) /* COV_IPDUM_SEARCH_HEADER_ID_LOOP_ABORT */
  {
    if(IpduM_GetHeaderIdOfTxContainedPdu(txContainedPduId) == headerId)
    {
      break;
    }
  }
  return txContainedPduId;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_CalculateSizeOfContainer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(uint32, IPDUM_CODE) IpduM_CalculateSizeOfContainer(IpduM_TxContainerPduIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  PduLengthType containerSize = 0u;
  PduLengthType headerSize = (PduLengthType) IpduM_GetTxHeaderSize(txContainerId);
  IpduM_ContainedPduHeaderType currentHeader;

  while(containerSize <= (PduInfoPtr->SduLength - headerSize)) /* stop iterating one headersize before the end to avoid reading a partial header */
  {
    /* read header, add current contained PDU's length (including header) to containerSize */
    currentHeader = IpduM_ContainerReadHeader(&(PduInfoPtr->SduDataPtr[containerSize]), headerSize);    /* SBSW_IPDUM_ANY_CALL_CONTAINERREADHEADER */

    /* detect end of container */
    if(currentHeader.headerId == 0u)
    {
      break;
    }

    containerSize += headerSize + (PduLengthType) currentHeader.dlc;
  }

  return containerSize;
}
#endif

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/*******************************************************************************************
 *  IpduM_Init()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_Init(P2CONST(IpduM_ConfigType, AUTOMATIC, IPDUM_PBCFG) config)
{
  uint8 errorId = IPDUM_E_NO_ERROR;
#if(IPDUM_USE_INIT_POINTER == STD_ON)
  IpduM_ConfigDataPtr = config;
  if(IpduM_ConfigDataPtr == NULL_PTR)
  {
# if(IPDUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    EcuM_BswErrorHook(IPDUM_MODULE_ID, ECUM_BSWERROR_NULLPTR);
# endif
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
    errorId = IPDUM_E_PARAM_POINTER;
# endif
  }
# if (IPDUM_FINALMAGICNUMBER == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  else if(IpduM_GetFinalMagicNumber() != IPDUM_FINAL_MAGIC_NUMBER)
  {
    IpduM_ConfigDataPtr = NULL_PTR;
#  if(IPDUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    EcuM_BswErrorHook(IPDUM_MODULE_ID, ECUM_BSWERROR_MAGICNUMBER);
#  endif
#  if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
    errorId = IPDUM_E_PARAM_POINTER;
#  endif
  }
# endif
#else
  if(config != NULL_PTR) /* COV_IPDUM_PRECOMPILE_CONFIG */
  {
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
    errorId = IPDUM_E_PARAM_POINTER;
# endif
  }
#endif
#if((IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON) || (IPDUM_RXMUXPDU == STD_ON) || (IPDUM_CONTAINERRXBUFFER == STD_ON) || (IPDUM_CONTAINERTXBUFFER == STD_ON)) /* COV_IPDUM_EMPTY_CONFIG */
  else
  {
# if (IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON)
    {
      /* Initialize multiplex PDU handle / index for "for" loop */
      IpduM_TxPathwayIterType muxTxPduHnd;

      /* initialize all the Tx multiplex PDUs, reset the timeout counters and set the IpduM state to initialized */
      for(muxTxPduHnd = 0u; muxTxPduHnd < IpduM_GetSizeOfTxPathway(); muxTxPduHnd++)
      {
#  if(IPDUM_DYNAMICPDUIDX == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
        /* record the dynamic PDU id */
        IpduM_SetDynamicPduIdx(muxTxPduHnd, IpduM_GetTxPartInitialDynPartIdxOfTxPathway(muxTxPduHnd));  /* SBSW_IPDUM_CSL01 */ /* SBSW_IPDUM_CSL03 */
#  endif
      }
#  if(IPDUM_TXINITVALUES == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      /* This check avoids copying from an empty buffer in Post-Build RxOnly configurations */
      if(IpduM_GetSizeOfTxInitValues() > 0) /* COV_IPDUM_INIT_MEMCPY */
      {
        VStdMemCpyRomToRam(IpduM_GetAddrTxBuffer(0), IpduM_GetAddrTxInitValues(0), IpduM_GetSizeOfTxInitValues());        /* SBSW_IPDUM_INIT_MEMCPY */
      }
#  endif
    }
# endif

# if(IPDUM_TXCONFTIMEOUTCNT == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      IpduM_TxConfTimeoutCntIterType txConfTimeoutCntIdx;
      for(txConfTimeoutCntIdx = 0u; txConfTimeoutCntIdx < IpduM_GetSizeOfTxConfTimeoutCnt(); txConfTimeoutCntIdx++)
      {
        /* Reset timeout counter for given multiplex handle in this loop iteration */
        IpduM_SetTxConfTimeoutCnt(txConfTimeoutCntIdx, IPDUM_RESET); /* SBSW_IPDUM_CSL01 */
      }
    }
# endif

# if(IPDUM_TXCONTAINEDPDU == STD_ON)
    {
      IpduM_ContainerTxConfLaIdIterType confirmationId;
      for(confirmationId = 0u; confirmationId < IpduM_GetSizeOfContainerTxConfLaId(); confirmationId++)
      {
        /* Reset write offsets for "last transmitted" ID buffer */
        IpduM_SetContainerTxConfLaId(confirmationId, 0u); /* SBSW_IPDUM_CSL01 */
      }
    }
# endif

    /* Initialize BufferInfoIdx */
    {
# if(IPDUM_TXCONTAINERBUFFERIDXINFO == STD_ON || IPDUM_RXCONTAINERBUFFERIDXINFO == STD_ON)
      uint32_least containerId;
# endif
# if(IPDUM_TXCONTAINERBUFFERIDXINFO == STD_ON)
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      for(containerId = 0u; containerId < IpduM_GetSizeOfTxContainerBufferIdxInfo(); containerId++)
      {
        IpduM_SetContainedPduWriteIdxOfTxContainerBufferIdxInfo(containerId, 0u);        /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerReadIdxOfTxContainerBufferIdxInfo(containerId, 0u);    /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerWriteIdxOfTxContainerBufferIdxInfo(containerId, 0u);   /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(containerId, 0u);     /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerReadCountOfTxContainerBufferIdxInfo(containerId, 0u);  /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerWriteCountOfTxContainerBufferIdxInfo(containerId, 0u); /* SBSW_IPDUM_CSL01 */
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
# if(IPDUM_RXCONTAINERBUFFERIDXINFO == STD_ON)
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      for(containerId = 0u; containerId < IpduM_GetSizeOfRxContainerBufferIdxInfo(); containerId++)
      {
        IpduM_SetContainedPduWriteIdxOfRxContainerBufferIdxInfo(containerId, 0u);        /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerReadIdxOfRxContainerBufferIdxInfo(containerId, 0u);    /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerWriteIdxOfRxContainerBufferIdxInfo(containerId, 0u);   /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerPduSendTimeoutOfRxContainerBufferIdxInfo(containerId, 0u);     /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerReadCountOfRxContainerBufferIdxInfo(containerId, 0u);  /* SBSW_IPDUM_CSL01 */
        IpduM_SetContainerWriteCountOfRxContainerBufferIdxInfo(containerId, 0u); /* SBSW_IPDUM_CSL01 */
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
    }
# if (IPDUM_CONTAINERTXBUFFER == STD_ON)
    {
      IpduM_ContainerTxConfBuIdIterType txConfirmationBufferInfoIdx = 0u;
      for(; txConfirmationBufferInfoIdx < IpduM_GetSizeOfContainerTxConfBuId(); txConfirmationBufferInfoIdx++)
      {
        IpduM_SetContainerTxConfBuId(txConfirmationBufferInfoIdx, 0u); /* SBSW_IPDUM_CSL01 */
      }
    }
# endif
    IpduM_SetInitialized(TRUE);
  }
#endif
#if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR) /* COV_IPDUM_NO_DEV_ERROR */
  {
    IpduM_Det_ReportError(IPDUM_APIID_INIT, (errorId));
  }
#else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
}  /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

/*******************************************************************************************
 *  IpduM_InitMemory()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_InitMemory(void)
{
  /* Set the IpduM to "uninitialized" */
  IpduM_SetInitialized(FALSE);
#if(IPDUM_USE_INIT_POINTER == STD_ON)
  IpduM_ConfigDataPtr = NULL_PTR;
#endif
}

/*******************************************************************************************
*  IpduM_MainFunctionTx()
*******************************************************************************************/
/*! \brief        Performs actions not directly initiated by calls from the PduR.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_MainFunctionTx(void)
{
#if ((IPDUM_TXCONFTIMEOUTCNT == STD_ON)||(IPDUM_TXCONTAINEDPDU == STD_ON))
  if(IpduM_IsInitialized())
  {
# if ((IPDUM_TXCONFTIMEOUTCNT == STD_ON) && (IPDUM_TXLOINFO == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      IpduM_TxLoInfoIterType txLoInfoIdx;
      for(txLoInfoIdx = 0; txLoInfoIdx < IpduM_GetSizeOfTxLoInfo(); txLoInfoIdx++)
      {
#  if (IPDUM_INVALIDHNDOFTXLOINFO == STD_ON)
        if(!IpduM_IsInvalidHndOfTxLoInfo(txLoInfoIdx))
#  endif
        {
          IpduM_TxConfTimeoutCntIdxOfTxLoInfoType txConfTimeoutCntIdx = IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(txLoInfoIdx);
#  if ((IPDUM_TXCONTAINEDPDU == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON))
          if((IpduM_GetTxConfTimeoutCnt(txConfTimeoutCntIdx) == 1u)
#   if (IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXLOINFO == STD_ON)
               && (IpduM_GetPathwayTypeOfTxLoInfo(txLoInfoIdx) == IPDUM_CONTAINER_PATHWAYTYPEOFTXLOINFO)
#   endif
             ) /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
          {
            /* it is a container PDU about to time-out */
            IpduM_TxContainerPduIdxOfTxLoInfoType containerPduId = IpduM_GetTxContainerPduIdxOfTxLoInfo(txLoInfoIdx);
            
            /* reset write index */
            SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
            IpduM_SetContainerTxConfLaId(IpduM_GetContainerTxConfLaIdIdxOfTxContainerPdu(containerPduId), 0u); /* SBSW_IPDUM_CSL03 */
            SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
          }
#  endif
          SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
          if(0u != IpduM_GetTxConfTimeoutCnt(txConfTimeoutCntIdx)) /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
          {
            IpduM_DecTxConfTimeoutCnt(txConfTimeoutCntIdx); /* SBSW_IPDUM_CSL03 */
          }
          SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();        
        }
      }
    }
# endif
# if (IPDUM_TXCONTAINEDPDU == STD_ON)
    {
      IpduM_TxContainerPduIterType txContainerId;
#  if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
      IpduM_ContainerPduSendTimeoutOfTxContainerBufferIdxInfoType containerPduSendTimeout;
#  endif
      for(txContainerId = 0u; txContainerId < IpduM_GetSizeOfTxContainerBufferInfo(); txContainerId++)
      {
        Std_ReturnType transmitResult = E_OK;

#  if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
        SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
        containerPduSendTimeout = IpduM_GetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId);
        SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  endif
      
        while(transmitResult == E_OK)
        {
          /* returns E_NOT_OK for empty queue and transmission failure */
          transmitResult = IpduM_TransmitQueuedContainerPdu(txContainerId);
        }
      
#  if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
        if(containerPduSendTimeout == 1u)
        {
          IpduM_TransmitOrQueueCurrContainerPdu(txContainerId);
          /* The above function call changes the value, so re-fetch it. */
          SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
          containerPduSendTimeout = IpduM_GetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId);
          SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
        }
        if(containerPduSendTimeout > 0u)
        {
          SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
          IpduM_DecContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId);      /* SBSW_IPDUM_CSL01 */
          SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
        }
#  endif
      }
    }
# endif
  }
#endif
}

/*******************************************************************************************
*  IpduM_MainFunctionRx()
*******************************************************************************************/
/*! \brief        Performs actions not directly initiated by calls from the PduR.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_MainFunctionRx(void)
{
#if (IPDUM_RXCONTAINERPDU == STD_ON)
  if(IpduM_IsInitialized())
  {
    IpduM_RxContainerBufferInfoIterType rxContainerId;
    PduInfoType pduInfo;

    for(rxContainerId = 0u; rxContainerId < IpduM_GetSizeOfRxContainerBufferInfo(); rxContainerId++)
    {
      IpduM_CountOfRxContainerBufferInfoType bufferInstanceCount = IpduM_GetCountOfRxContainerBufferInfo(rxContainerId);
      IpduM_LengthOfRxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfRxContainerBufferInfo(rxContainerId);
      /* the while statement checks for empty queue */
      while((IpduM_ContainerWriteCountOfRxContainerBufferIdxInfoType)(IpduM_GetContainerWriteCountOfRxContainerBufferIdxInfo(rxContainerId) - IpduM_GetContainerReadCountOfRxContainerBufferIdxInfo(rxContainerId)) > 0u)
      {
        pduInfo.SduDataPtr =
          IpduM_GetAddrContainerRxBuffer(IpduM_GetStartPosOfRxContainerBufferInfo(rxContainerId) + (IpduM_GetContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId) * bufferInstanceLength));
        pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
        IpduM_UnpackRxContainerPdu(rxContainerId, &pduInfo);    /* SBSW_IPDUM_MAINFUNCTIONRX_CALL_UNPACKRXCONTAINERPDU */

        /* increment read pointer */
        SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
        IpduM_IncContainerReadCountOfRxContainerBufferIdxInfo(rxContainerId);   /* SBSW_IPDUM_CSL01 */
        IpduM_IncContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId);     /* SBSW_IPDUM_CSL01 */
        if(IpduM_GetContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId) >= bufferInstanceCount)
        {
          IpduM_SetContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId, 0u);        /* SBSW_IPDUM_CSL01 */
        }
        SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      }
    }
  }
#endif
}

/*******************************************************************************************
 *  IpduM_Transmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_Transmit(PduIdType PdumTxPduId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* Parameters are checked in functions below because different checks are necessary. */
  /* Initialize return value with "not ok" */
  Std_ReturnType retVal = E_NOT_OK;

#if (IPDUM_TXUPINFO == STD_ON)
  uint8 errorId = IPDUM_E_NO_ERROR;
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if(!IpduM_IsInitialized())
  {
    errorId = IPDUM_E_UNINIT;
  }
  else if(PdumTxPduId >= IpduM_GetSizeOfTxUpInfo())
  {
    errorId = IPDUM_E_PARAM;
  }
  else if((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = IPDUM_E_PARAM_POINTER;
  }
  else
# endif
  {
    IpduM_TxUpIndIdxOfTxUpInfoType txUpIndIdx = IpduM_GetTxUpIndIdxOfTxUpInfo(PdumTxPduId);
    switch (IpduM_GetPathwayTypeOfTxUpInfo(PdumTxPduId))
    {
# if (IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXUPINFO == STD_ON)
      case IPDUM_MUX_PATHWAYTYPEOFTXUPINFO:
      {
        retVal = IpduM_MuxTransmit(txUpIndIdx, PduInfoPtr);     /* SBSW_IPDUM_TRANSMIT_CALL_MUXTRANSMIT */
        break;
      }
# endif
# if (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXUPINFO == STD_ON)
      case IPDUM_CONTAINER_PATHWAYTYPEOFTXUPINFO:
      {
        retVal = IpduM_ContainerTransmit(txUpIndIdx, PduInfoPtr);       /* SBSW_IPDUM_TRANSMIT_CALL_CONTAINERTRANSMIT */
        break;
      }
# endif
      default: /* COV_IPDUM_MISRA */ /* PRQA S 2018 */ /* MD_CSL_2018 */ 
      {
        break;
      }
    }
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_TRANSMIT, (errorId));
  }
# else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

#else
  IPDUM_DUMMY_STATEMENT(PdumTxPduId);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
  return retVal;
}

#if (IPDUM_TRIGGER_TRANSMIT_API == STD_ON)
/*******************************************************************************************
 *  IpduM_TriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* Parameters are checked in functions below because different checks are necessary. */
  /* Initialize return value with "not ok" */
  Std_ReturnType retVal = E_NOT_OK;

# if (IPDUM_TXLOINFO == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  uint8 errorId = IPDUM_E_NO_ERROR;
#  if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if(!IpduM_IsInitialized())
  {
    errorId = IPDUM_E_UNINIT;
  }
  else if((TxPduId >= IpduM_GetSizeOfTxLoInfo())
#   if (IPDUM_INVALIDHNDOFTXLOINFO == STD_ON)
          || (IpduM_IsInvalidHndOfTxLoInfo(TxPduId))
#   endif
    )
  {
    errorId = IPDUM_E_PARAM;
  }
  else if((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = IPDUM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    switch (IpduM_GetPathwayTypeOfTxLoInfo(TxPduId))
    {
#  if (IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXLOINFO == STD_ON)
      case IPDUM_MUX_PATHWAYTYPEOFTXLOINFO:
      {
        retVal = IpduM_MuxTriggerTransmit(IpduM_GetTxPathwayIdxOfTxLoInfo(TxPduId), PduInfoPtr);        /* SBSW_IPDUM_TRIGGERTRANSMIT_CALL_MUXTRIGGERTRANSMIT */
        break;
      }
#  endif
#  if (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
      case IPDUM_CONTAINER_PATHWAYTYPEOFTXLOINFO:
      {
        retVal = IpduM_ContainerTriggerTransmit(IpduM_GetTxContainerPduIdxOfTxLoInfo(TxPduId), PduInfoPtr);     /* SBSW_IPDUM_TRIGGERTRANSMIT_CALL_CONTAINERTRIGGERTRANSMIT */
        break;
      }
#  endif
      default: /* COV_IPDUM_MISRA */ /* PRQA S 2018 */ /* MD_CSL_2018 */ 
      {
        break;
      }
    }
  }
#  if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_TRIGGERTRANSMIT, (errorId));
  }
#  else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#  endif
# else
  IPDUM_DUMMY_STATEMENT(TxPduId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if(IPDUM_TX_CONFIRMATION_API == STD_ON)
/*******************************************************************************************
 *  IpduM_TxConfirmation()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_TxConfirmation(PduIdType TxPduId)
{
# if (IPDUM_TXLOINFO == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  uint8 errorId = IPDUM_E_NO_ERROR;
#  if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if(!IpduM_IsInitialized())
  {
    errorId = IPDUM_E_UNINIT;
  }
  else if(TxPduId >= IpduM_GetSizeOfTxLoInfo())
  {
    errorId = IPDUM_E_PARAM;
  }
#   if (IPDUM_INVALIDHNDOFTXLOINFO == STD_ON)
  else if(IpduM_IsInvalidHndOfTxLoInfo(TxPduId))
  {
    errorId = IPDUM_E_PARAM;
  }
#   endif
  else
#  endif
  {
    switch (IpduM_GetPathwayTypeOfTxLoInfo(TxPduId))
    {
#  if ((IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON) || (IPDUM_TXCONFIRMATIONOFTXPART == STD_ON))
      case IPDUM_MUX_PATHWAYTYPEOFTXLOINFO:
      {
        IpduM_MuxTxConfirmation(TxPduId);
        break;
      }
#  endif
#  if (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
      case IPDUM_CONTAINER_PATHWAYTYPEOFTXLOINFO:
      {
        IpduM_ContainerTxConfirmation(TxPduId);
        break;
      }
#  endif
      default: /* COV_IPDUM_MISRA */ /* PRQA S 2018 */ /* MD_CSL_2018 */ 
      {
        break;
      }
    }
  }
#  if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_TXCONFIRMATION, (errorId));
  }
#  else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#  endif

# else
  IPDUM_DUMMY_STATEMENT(TxPduId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
}
#endif

/*******************************************************************************************
 *  IpduM_RxIndication()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
#if (IPDUM_RXINFO == STD_ON)
  uint8 errorId = IPDUM_E_NO_ERROR;
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if(!IpduM_IsInitialized())
  {
    errorId = IPDUM_E_UNINIT;
  }
  else if(RxPduId >= IpduM_GetSizeOfRxInfo())
  {
    errorId = IPDUM_E_PARAM;
  }
  else if((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = IPDUM_E_PARAM_POINTER;
  }
  else
# endif
  {
    IpduM_RxPathwayIndIdxOfRxInfoType rxPathwayIndIdx = IpduM_GetRxPathwayIndIdxOfRxInfo(RxPduId);
    switch (IpduM_GetPathwayTypeOfRxInfo(RxPduId))
    {
# if (IPDUM_EXISTS_MUX_PATHWAYTYPEOFRXINFO == STD_ON)
      case IPDUM_MUX_PATHWAYTYPEOFRXINFO:
      {
        IpduM_MuxRxIndication(rxPathwayIndIdx, PduInfoPtr);     /* SBSW_IPDUM_RXINDICATION_CALL_MUXRXINDICATION */
        break;
      }
# endif
# if (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFRXINFO == STD_ON)
      case IPDUM_CONTAINER_PATHWAYTYPEOFRXINFO:
      {
        errorId = IpduM_ContainerRxIndication(rxPathwayIndIdx, PduInfoPtr);     /* SBSW_IPDUM_RXINDICATION_CALL_CONTAINERRXINDICATION */
        break;
      }
# endif
      default: /* COV_IPDUM_MISRA */ /* PRQA S 2018 */ /* MD_CSL_2018 */ 
      {
        break;
      }
    }
  }

# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_RXINDICATION, (errorId));
  }
# else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

#else
  IPDUM_DUMMY_STATEMENT(RxPduId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
}

#if (IPDUM_TXPART == STD_ON)
/*******************************************************************************************
 *  IpduM_MuxTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_MuxTransmit(IpduM_TxUpIndIdxOfTxUpInfoType txPartId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* Initialize multiplex PDU handle for copying to */
  IpduM_TxPathwayIterType txPathway = IpduM_GetTxPathwayIdxOfTxPart(txPartId);

# if((IPDUM_TXCONFTIMEOUTCNT == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  /* TxLoInfo exists if a txConfirmation is configured. If not, 0 is a safe default for txConfTimeoutCntIdx. */
  IpduM_TxConfTimeoutCntIdxOfTxLoInfoType txConfTimeoutCntIdx = 0;
  if(IpduM_IsTxLoInfoUsedOfTxPathway(txPathway))
  {
    IpduM_TxLoInfoIdxOfTxPathwayType txLoInfoIdx = IpduM_GetTxLoInfoIdxOfTxPathway(txPathway);
    txConfTimeoutCntIdx = IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(txLoInfoIdx);
  }

  if((IpduM_GetTxConfirmationTimeoutOfTxPathway(txPathway) == 0u) || (IpduM_GetTxConfTimeoutCnt(txConfTimeoutCntIdx) == 0u))
# endif
  {
    /* multiplex PDU buffer not engaged and accept transmission */
    /* jit update not required, assign associated multiplex buffer, multiplex data */
    /* as an optimization copying a source part requiring jit update can be avoided in this context */

    /* Copy data from the given buffer (function argument) to the TX buffer */
    IpduM_CopySegments(IpduM_GetSegmentStartIdxOfTxPart(txPartId), IpduM_GetSegmentEndIdxOfTxPart(txPartId), IpduM_GetAddrTxBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathway)), PduInfoPtr->SduDataPtr);        /* SBSW_IPDUM_MUXTRANSMIT_CALL_COPYSEGMENTS */

    /* set retVal to "OK" for successfully storing the non-triggering part for later transmission */
    retVal = E_OK;
    
# if((IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON) && (IPDUM_DYNAMICPDUIDX == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    if((!IpduM_IsTxPartStaticPartUsedOfTxPathway(txPathway)) || (IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathway) != txPartId))
# endif
    {
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      IpduM_SetDynamicPduIdx(txPathway, (IpduM_DynamicPduIdxType) txPartId);    /* SBSW_IPDUM_MUX_TRANSMIT_INDIRECT_ACCESS */ /* SBSW_IPDUM_CSL03 */
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }

# if (IPDUM_TRIGGEREVENTOFTXPART == STD_ON)
    if(IpduM_IsTriggerEventOfTxPart(txPartId))
    {
      /* do transmit, a trigger triggered */
#  if ((IPDUM_JITUPDATEOFTXPART == STD_ON) && (IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON))
      PduInfoType jitUpdatePduInfo;
      jitUpdatePduInfo.SduDataPtr = IpduM_GetAddrJitUpdateBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathway));
      jitUpdatePduInfo.SduLength = IpduM_GetLengthOfTxPathway(txPathway);
      if(IpduM_JitUpdate(txPathway, &jitUpdatePduInfo, FALSE, txPartId) == E_OK)        /* SBSW_IPDUM_MUXTRANSMIT_CALL_JITUPDATE */
#  endif
      {
        /* Interrupt disabling is required to avoid the timeout timer being reset by a tx confirmation of a previous transmission. The tx confirmation timeout is loaded before triggering transmission, because the If can confirm a previous transmission of the multiplex Pdu in the current tranmission trigger context, before the timer for the current transmission is loaded.  */
        SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  if((IPDUM_TXCONFTIMEOUTCNT == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
        /* Load timeout counter - encapsulation necessary to secure write access using optional variable txConfTimeoutCntIdx. */
        if(IpduM_IsTxLoInfoUsedOfTxPathway(txPathway))
        {
          IpduM_SetTxConfTimeoutCnt(txConfTimeoutCntIdx, IpduM_GetTxConfirmationTimeoutOfTxPathway(txPathway));        /* SBSW_IPDUM_MUX_TRANSMIT_INDIRECT_ACCESS */ /* SBSW_IPDUM_CSL03 */
        }
#  endif
        {
          PduInfoType pduInfo;
          pduInfo.SduDataPtr = IpduM_GetAddrTxBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathway));
          pduInfo.SduLength = IpduM_GetLengthOfTxPathway(txPathway);
          retVal = PduR_IpduMTransmit(IpduM_GetLlPduRefOfTxPathway(txPathway), &pduInfo);       /* SBSW_IPDUM_MUXTRANSMIT_CALL_PDURTRANSMIT */
        }
#  if((IPDUM_TXCONFTIMEOUTCNT == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
        if((retVal != E_OK) && IpduM_IsTxLoInfoUsedOfTxPathway(txPathway))
        {
          /* transmission failed. Reset the confirmation timeout time - encapsulation necessary to secure write access using optional variable txConfTimeoutCntIdx. */
          IpduM_SetTxConfTimeoutCnt(txConfTimeoutCntIdx, IPDUM_RESET); /* SBSW_IPDUM_MUX_TRANSMIT_INDIRECT_ACCESS */ /* SBSW_IPDUM_CSL03 */
        }
#  endif
        SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      }
#  if ((IPDUM_JITUPDATEOFTXPART == STD_ON) && (IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON))
      else
      {
        /* jit update failed */
        retVal = E_NOT_OK;
      }
#  endif
    }
# endif
  }
  return retVal;
}
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXLOINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_MuxTriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_MuxTriggerTransmit(IpduM_TxPathwayIdxOfTxLoInfoType txPathwayHnd, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* Initialize return value with "ok" */
  Std_ReturnType retVal = E_NOT_OK;
# if (IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  /* Initialize copy destination pointer */
  P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pMuxPduBuf = IpduM_GetAddrTxBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathwayHnd));
#  if(IPDUM_JITUPDATEOFTXPART == STD_ON && IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  PduInfoType jitUpdatePduInfo;
  jitUpdatePduInfo.SduDataPtr = IpduM_GetAddrTriggerTransmitBuffer(IpduM_GetTxBufferIdxOfTxPathway(txPathwayHnd));
  jitUpdatePduInfo.SduLength = PduInfoPtr->SduLength;
#  endif
  if(PduInfoPtr->SduLength >= IpduM_GetLengthOfTxPathway(txPathwayHnd))
  {
#  if(IPDUM_JITUPDATEOFTXPART == STD_ON && IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    if(IpduM_JitUpdate(txPathwayHnd, &jitUpdatePduInfo, TRUE, 0u) == E_OK)       /* SBSW_IPDUM_MUXTRIGGERTRANSMIT_CALL_JITUPDATE */
    {
#  endif
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      {
        /* Copy PDU from mux buffer to provided destination buffer */
        VStdMemCpyRamToRam(PduInfoPtr->SduDataPtr, pMuxPduBuf, IpduM_GetLengthOfTxPathway(txPathwayHnd));       /* SBSW_IPDUM_MUXTRIGGERTRANSMIT_CALL_MEMCPY */
        PduInfoPtr->SduLength = IpduM_GetLengthOfTxPathway(txPathwayHnd);       /* SBSW_IPDUM_MUXTRIGGERTRANSMIT_PDUINFO_WRITE */
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      retVal = E_OK;
#  if(IPDUM_JITUPDATEOFTXPART == STD_ON && IPDUM_UL_TRIGGER_TRANSMIT_API == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    }
#  endif
  }
# else
  IPDUM_DUMMY_STATEMENT(txPathwayHnd);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if ((IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON) || (IPDUM_TXCONFIRMATIONOFTXPART == STD_ON))
/*******************************************************************************************
 *  IpduM_MuxTxConfirmation()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_MuxTxConfirmation(PduIdType TxPduId)
{
  {
# if (IPDUM_TXBUFFERIDXOFTXPATHWAY == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    /* get handle of multiplex PDU */
    IpduM_TxPathwayIterType txPathwayHnd = IpduM_GetTxPathwayIdxOfTxLoInfo(TxPduId);
#  if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    IpduM_TxConfTimeoutCntIdxOfTxLoInfoType txConfTimeoutCntIdx = IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(TxPduId);
    /* Initialize the "we have a confirmation to forward" flag with "nothing to forward" */
    boolean txConf = FALSE;

    if(0u != IpduM_GetTxConfirmationTimeoutOfTxPathway(txPathwayHnd))
    {
      /* IPDUM019: transmission confirmation timeout time configured for the multiplex PDU */
      if(0u != IpduM_GetTxConfTimeoutCnt(txConfTimeoutCntIdx))
      {
        /* transmission confirmation timer not elapsed yet, transmission confirmation is expected */
        txConf = TRUE;  /* We have a confirmation to forward */
        IpduM_SetTxConfTimeoutCnt(txConfTimeoutCntIdx, IPDUM_RESET);   /* Clear counter */ /* SBSW_IPDUM_MUX_TX_CONFIRMATION_INDIRECT_ACCESS */ /* SBSW_IPDUM_CSL03 */
      }
    }
    else
    {
      /* no transmission confirmation time configured */
      txConf = TRUE;    /* We have a confirmation to forward */
    }

    if(txConf == TRUE)
#  endif
    {
#  if(IPDUM_TXCONFIRMATIONOFTXPART == STD_ON && IPDUM_UL_TX_CONFIRMATION_API == STD_ON)
      IpduM_TxPartIterType txDynamicPartId;    
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      txDynamicPartId = (IpduM_TxPartIterType) IpduM_GetDynamicPduIdx(txPathwayHnd);
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      if(IpduM_IsTxConfirmationOfTxPart(txDynamicPartId))
      {
        /* Forward confirmation to PduR */
        PduR_IpduMTxConfirmation(IpduM_GetUlPduRefOfTxPart(txDynamicPartId));
      }
#   if(IPDUM_TXSTATICPDUREFOFTXPATHWAY == STD_ON)
      if(IpduM_IsTxPartStaticPartUsedOfTxPathway(txPathwayHnd))
      {
        if(IpduM_IsTxConfirmationOfTxPart(IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayHnd)))
        {
          /* Forward confirmation to PduR */
          PduR_IpduMTxConfirmation(IpduM_GetUlPduRefOfTxPart(IpduM_GetTxPartStaticPartIdxOfTxPathway(txPathwayHnd)));
        }
      }
#   endif
#  endif
    }
# endif
  }
}
#endif

#if (IPDUM_RXMUXPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_MuxRxIndication()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_MuxRxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxMuxPduId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  PduInfoType pduInfo;
  /* Point to copy target buffer */
  pduInfo.SduDataPtr = IpduM_GetAddrRxBuffer(IpduM_GetRxMuxBufferIdxOfRxMuxPdu(rxMuxPduId));
  pduInfo.SduLength = PduInfoPtr->SduLength;    /* Set length of pdu */

  {     /* block for encapsulation */
    IpduM_RxDynPduIterType ipduMDynPduIdx;
    /* loop over dynamic parts */
    for(ipduMDynPduIdx = IpduM_GetRxDynPduStartIdxOfRxMuxPdu(rxMuxPduId); ipduMDynPduIdx < IpduM_GetRxDynPduEndIdxOfRxMuxPdu(rxMuxPduId); ipduMDynPduIdx++)
    {
      IpduM_RxSelectorPatternIterType ipduMSubPatternIdx;
      boolean patternMatch = TRUE;      /* Initialize with true, turn false on any sub-pattern mismatch. */
      uint8 inputOffset = 0;    /* Offset of initial pointer to current pattern position (valid values: 0, 1, 2). */
      /* loop over subpatterns */
      for(ipduMSubPatternIdx = IpduM_GetRxSelectorPatternStartIdxOfRxDynPdu(ipduMDynPduIdx); ipduMSubPatternIdx < IpduM_GetRxSelectorPatternEndIdxOfRxDynPdu(ipduMDynPduIdx); ipduMSubPatternIdx++)
      {
        /* mask input data and compare with pattern */
        uint8 selectorSubPattern = PduInfoPtr->SduDataPtr[(IpduM_GetSelectorFieldBytePositionOfRxMuxPdu(rxMuxPduId)
                                                           + inputOffset)] & IpduM_GetSelectorFieldSubMaskOfRxSelectorPattern(ipduMSubPatternIdx);
        if(selectorSubPattern != IpduM_GetSelectorFieldSubPatternOfRxSelectorPattern(ipduMSubPatternIdx))
        {
          patternMatch = FALSE;
        }
        inputOffset++;
      }
      if((patternMatch == TRUE)
# if(IPDUM_MINDLCOFRXDYNPDU == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
         && (pduInfo.SduLength >= IpduM_GetMinDLCOfRxDynPdu(ipduMDynPduIdx))
# endif
        )
      {
        /* on match: copy data */
        /* copy dynamic part to target buffer */
        IpduM_CopySegments(IpduM_GetSegmentStartIdxOfRxDynPdu(ipduMDynPduIdx), IpduM_GetSegmentEndIdxOfRxDynPdu(ipduMDynPduIdx), pduInfo.SduDataPtr, PduInfoPtr->SduDataPtr);   /* SBSW_IPDUM_MUXRXINDICATION_CALL_COPYSEGMENTS */
        /* Indicate reception of dynamic part to PduR, hand over the buffer containing received data */
        PduR_IpduMRxIndication(IpduM_GetUlPduRefOfRxDynPdu(ipduMDynPduIdx), &pduInfo);  /* SBSW_IPDUM_MUXRXINDICATION_CALL_PDURRXINDICATION */
      }
    }
  }

# if(IPDUM_RXSTATICPDUIDXOFRXMUXPDU == STD_ON)
  if(IpduM_IsRxStaticPduUsedOfRxMuxPdu(rxMuxPduId))
  {
    /* get index of static PDU */
    IpduM_RxStaticPduIterType ipduMStaticPduIdx = IpduM_GetRxStaticPduIdxOfRxMuxPdu(rxMuxPduId);
#  if(IPDUM_MINDLCOFRXSTATICPDU == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    if(pduInfo.SduLength >= IpduM_GetMinDLCOfRxStaticPdu(ipduMStaticPduIdx))
#  endif
    {
      /* a static part is configured, its id assigned its sub parts/bit fields indicies extracted */
      /* Copy received data to receive buffer */
      IpduM_CopySegments(IpduM_GetSegmentStartIdxOfRxStaticPdu(ipduMStaticPduIdx), IpduM_GetSegmentEndIdxOfRxStaticPdu(ipduMStaticPduIdx), pduInfo.SduDataPtr, PduInfoPtr->SduDataPtr); /* SBSW_IPDUM_MUXRXINDICATION_CALL_COPYSEGMENTS */
      /* Indicate reception of static part to PduR, hand over the buffer containing received data */
      PduR_IpduMRxIndication(IpduM_GetUlPduRefOfRxStaticPdu(ipduMStaticPduIdx), &pduInfo);      /* SBSW_IPDUM_MUXRXINDICATION_CALL_PDURRXINDICATION */
    }
  }
# endif
}
#endif /* (IPDUM_RXMUXPDU == STD_ON) */

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTransmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  uint8 errorId = IPDUM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;
  IpduM_TxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);
# if ((IPDUM_LASTISBESTOFTXCONTAINEDPDU == STD_ON) || (IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU == STD_ON))
  IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
# endif
  PduLengthType pduLength = PduInfoPtr->SduLength;

/* *INDENT-OFF* */
  /* Long headers are 8 bytes, short headers are 4 bytes in size.
     Long headers have 4 bytes ID and 4 bytes DLC.
     Short headers have 3 bytes ID and 1 byte DLC. */
/* *INDENT-ON* */
  uint8 headerSize = IpduM_GetTxHeaderSize(txContainerId);

# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if((IpduM_LengthOfTxContainerBufferInfoType)(pduLength + headerSize) > bufferInstanceLength)
  {
    errorId = IPDUM_E_PARAM;
  }
  else if((pduLength > 255) 
#  if (IPDUM_LONGHEADERSOFTXCONTAINERPDU == STD_ON)
    && (headerSize == IPDUM_HEADERSIZE_SMALL)
#  endif
         )
  {
    /* For short headers, only 8 bits are available for DLC. So values >255 are not allowed here. */
    errorId = IPDUM_E_PARAM;
  }
  else
# endif
  {
    IpduM_ContainedPduWriteIdxOfTxContainerBufferIdxInfoType containedPduWriteIdx;
# if (IPDUM_LASTISBESTOFTXCONTAINEDPDU == STD_ON)
    boolean pduIsInContainer;
# endif
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    containedPduWriteIdx = IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# if (IPDUM_LASTISBESTOFTXCONTAINEDPDU == STD_ON)
    pduIsInContainer = FALSE;
    /* If pdu is queued and last is best semantics are applied: replace pdu */
    if(IpduM_IsLastIsBestOfTxContainedPdu(txContainedId))
    {
      /* Find pdu in queue and replace its content (size and ID must be identical). */

      uint8 *pContainerTxBuf;
      uint32 containedPduBufferIdx = 0u;
      IpduM_ContainedPduHeaderType header;

      /* start position of current container instance */
      pContainerTxBuf = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId) * bufferInstanceLength));

      /* loop over all contained-pdus */
      while(containedPduBufferIdx < containedPduWriteIdx)
      {
        /* get header id and dlc of the contained PDU */
        header = IpduM_ContainerReadHeader(&pContainerTxBuf[containedPduBufferIdx], headerSize);        /* SBSW_IPDUM_ANY_CALL_CONTAINERREADHEADER */

        /* If header id matches, break loop. Data is replaced later. */
        if(header.headerId == IpduM_GetHeaderIdOfTxContainedPdu(txContainedId))
        {
          pduIsInContainer = TRUE;
          retVal = E_OK;
          break;
        }
        /* increment to next contained-pdu */
        containedPduBufferIdx += (headerSize + header.dlc);
      }
    }
    /* If the last-is-best PDU is not in the container or it was not a "last is best" PDU. Proceed with a normal transmission for this PDU. */
    if(pduIsInContainer == FALSE)
    {
# endif
      if((containedPduWriteIdx + headerSize + pduLength) > bufferInstanceLength)
      {
        /* PDU does not fit into container. Transmit/queue container, choose next container instance as current. */
        IpduM_TransmitOrQueueCurrContainerPdu(txContainerId);
      }

# if(IPDUM_CONTAINERTXBUFFER==STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      /* PDU now does fit into current container instance: add PDU. */
      IpduM_AddTxPduToCurrContainer(txContainedId, PduInfoPtr); /* SBSW_IPDUM_CONTAINERTRANSMIT_CALL_ADDTXPDUTOCURRCONTAINER */
#  if (IPDUM_TX_CONFIRMATION_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
      /* add contained PDU ID to buffer */
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      {
        IpduM_ContainerTxConfBufStartIdxOfTxContainerPduType bufferStartIdx = IpduM_GetContainerTxConfBufStartIdxOfTxContainerPdu(txContainerId);
        IpduM_ContainerWriteIdxOfTxContainerBufferIdxInfoType currentInstance = IpduM_GetContainerWriteIdxOfTxContainerBufferIdxInfo(txContainerId);
        IpduM_ContainerTxConfBuInLenType confirmationBufferInstanceLength = IpduM_GetContainerTxConfBuInLen(IpduM_GetContainerTxConfBuInLenStartIdxOfTxContainerPdu(txContainerId));
        IpduM_ContainerTxConfBuIdType bufferInstanceWriteOffset = IpduM_GetContainerTxConfBuId(IpduM_GetTxContainerBufferInfoStartIdxOfTxContainerPdu(txContainerId) + currentInstance);

        IpduM_SetContainerTxConfBuf((bufferStartIdx + (currentInstance * confirmationBufferInstanceLength) + bufferInstanceWriteOffset), (PduIdType)txContainedId); /* SBSW_IPDUM_CONTAINER_TRANSMIT_INDIRECT_ACCESS */
        if(bufferInstanceWriteOffset < (IpduM_ContainerTxConfBuIdType)(confirmationBufferInstanceLength - 1))
        {
            /* buffer not yet full: increment to next position */
            IpduM_IncContainerTxConfBuId(IpduM_GetTxContainerBufferInfoStartIdxOfTxContainerPdu(txContainerId) + currentInstance); /* SBSW_IPDUM_CONTAINER_TRANSMIT_INCREMENT_CALCULATED_POSITION */
        }
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  endif
      retVal = E_OK;
# endif
# if (IPDUM_LASTISBESTOFTXCONTAINEDPDU == STD_ON)
    }
# endif
# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
    /* Start timeout */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    if(IpduM_GetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId) == 0u)
    {
      if(IpduM_IsSendToDefOfTxContainerPdu(txContainerId))
      {
        IpduM_SetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId, IpduM_GetSendTimeoutOfTxContainerPdu(txContainerId)); /* SBSW_IPDUM_CONTAINER_TRANSMIT_INDIRECT_ACCESS */
      }
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif
# if (IPDUM_SENDTODEFOFTXCONTAINEDPDU == STD_ON)
    /* adapt timeout */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    if((IpduM_IsSendToDefOfTxContainedPdu(txContainedId) && (IpduM_GetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId) > IpduM_GetSendTimeoutOfTxContainedPdu(txContainedId)))
       || (IpduM_GetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId) == 0u))
    {
      IpduM_SetContainerPduSendTimeoutOfTxContainerBufferIdxInfo(txContainerId, IpduM_GetSendTimeoutOfTxContainedPdu(txContainedId));   /* SBSW_IPDUM_CONTAINER_TRANSMIT_INDIRECT_ACCESS */
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
# endif

    if((IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId) >= (IpduM_GetTxSizeThresholdOfTxContainerPdu(txContainerId)))
# if (IPDUM_TXPDUTRIGGEROFTXCONTAINEDPDU == STD_ON)
       || (IpduM_IsTxPduTriggerOfTxContainedPdu(txContainedId))
# endif
      )
# if(IPDUM_CONTAINERTXBUFFER==STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      /* If container size threshold reached or trigger always is set: transmit/queue container, choose next container */
      IpduM_TransmitOrQueueCurrContainerPdu(txContainerId);
    }
# endif
# if (IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU == STD_ON)
    if(IpduM_IsFirstContainedPduTriggerOfTxContainerPdu(txContainerId))
    {
      /* If first contained pdu trigger = true, call PduR_IpduMTransmit */
      PduInfoType pduInfo;
      pduInfo.SduDataPtr = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) * bufferInstanceLength));
      pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
      pduInfo.SduLength = (PduLengthType)IpduM_CalculateSizeOfContainer(txContainerId, &pduInfo); /* SBSW_IPDUM_CONTAINER_TRANSMIT_CALL_CALCULATESIZEOFCONTAINER */
      PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo); /* PRQA S 3200 */ /* MD_IpduM_3200 */ /* SBSW_IPDUM_CONTAINER_TRANSMIT_CALL_PDURTRANSMIT */
    }
# endif
  }

# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_TRANSMIT, (errorId));
  }
# else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;
}  /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTriggerTransmit(IpduM_TxContainerPduIdxOfTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* Initialize return value with "not ok" */
  Std_ReturnType retVal = E_NOT_OK;
# if (IPDUM_TXCONTAINERPDU == STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  IpduM_StartPosOfTxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfTxContainerBufferInfo(txContainerId);
  IpduM_CountOfTxContainerBufferInfoType bufferInstanceCount = IpduM_GetCountOfTxContainerBufferInfo(txContainerId);
  IpduM_LengthOfTxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfTxContainerBufferInfo(txContainerId);

  /* If a non-empty instance of this container exists: Calculate payload size, transmit container, delete from queue, E_OK */
  /* Else: E_NOT_OK */
  if((PduInfoPtr->SduLength >= bufferInstanceLength) /* buffer match */
     && (((IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType)(IpduM_GetContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId) - IpduM_GetContainerReadCountOfTxContainerBufferIdxInfo(txContainerId)) > 0u) /* queued instance exists */
        || (IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId) > 0u)) /* current instance is non-empty */
    )
  {
#  if(IPDUM_CONTAINERTXBUFFER==STD_ON) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    /* Queue is non-empty */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    {
      /* get pointer to copy destination (provided target buffer) */
      P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pSrc = IpduM_GetAddrContainerTxBuffer(bufferStartPos + (IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) * bufferInstanceLength));
      /* if the queue is empty, the current instance is used for transmission and needs padding zeroes */
      if((IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType)(IpduM_GetContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId) - IpduM_GetContainerReadCountOfTxContainerBufferIdxInfo(txContainerId)) == 0u)
      {
        IpduM_ContainerTxBufferIterType containerBufId;
        uint8 headerSize = IpduM_GetTxHeaderSize(txContainerId);
        /* add zero header for safe PDU termination */
        for(containerBufId = IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId); (containerBufId<bufferInstanceLength) && (containerBufId < (IpduM_GetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId) + headerSize));containerBufId++) /* COV_IPDUM_TERMINATION_ZEROES */
        {
          pSrc[containerBufId] = 0; /* SBSW_IPDUM_CONTAINERRXINDICATION_MEMORY_WRITE */
        }
      }
#   if (IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU == STD_ON)
      if(IpduM_GetContainerTypeOfTxContainerPdu(txContainerId) == IPDUM_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU){
        /* last-is-best PDU: load data to last-is-best buffer via TriggerTransmit, then use this buffer for transmission */
        PduInfoType pduInfo;
        pduInfo.SduDataPtr = pSrc;
        pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
        IpduM_FillLastIsBestContainer(txContainerId, &pduInfo); /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_CALL_FILLLASTISBESTCONTAINER */
        pSrc = IpduM_GetAddrContainerTxLIBBuffer(0);
      }
#   endif
      /* Copy PDU from container buffer to provided destination buffer */
      VStdMemCpyRamToRam(PduInfoPtr->SduDataPtr, pSrc, bufferInstanceLength);   /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_MEMCPY */
      PduInfoPtr->SduLength = (PduLengthType)bufferInstanceLength;     /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_PTR_WRITE */
      /* return actual size of read container Pdu */
      PduInfoPtr->SduLength = (PduLengthType)IpduM_CalculateSizeOfContainer(txContainerId, PduInfoPtr); /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_PTR_WRITE */ /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_CALCULATESIZEOFCONTAINER */

      /* update pointers and counters */
      if((IpduM_ContainerWriteCountOfTxContainerBufferIdxInfoType)(IpduM_GetContainerWriteCountOfTxContainerBufferIdxInfo(txContainerId) - IpduM_GetContainerReadCountOfTxContainerBufferIdxInfo(txContainerId)) > 0u)
      {
        /* this instance is queued, increment pointers */
        IpduM_IncContainerReadCountOfTxContainerBufferIdxInfo(txContainerId);     /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_INDIRECT_ACCESS */
        IpduM_IncContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId);       /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_INDIRECT_ACCESS */
        if(IpduM_GetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId) >= bufferInstanceCount)
        {
          IpduM_SetContainerReadIdxOfTxContainerBufferIdxInfo(txContainerId, 0u);  /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_INDIRECT_ACCESS */
        }
      }
      else
      {
        /* this is the current instance, clear it */
        IpduM_SetContainedPduWriteIdxOfTxContainerBufferIdxInfo(txContainerId, 0u); /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_INDIRECT_ACCESS */
      }
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    retVal = E_OK;
#  endif
  }
# else
  IPDUM_DUMMY_STATEMENT(TxPduId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
  return retVal;
}
#endif

#if (IPDUM_TX_CONFIRMATION_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTxConfirmation()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTxConfirmation(PduIdType TxPduId)
{
  IpduM_TxLoInfoIterType containerPduId = IpduM_GetTxContainerPduIdxOfTxLoInfo(TxPduId);
  IpduM_TxConfTimeoutCntIdxOfTxLoInfoType txConfTimeoutCntIdx = IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(TxPduId);
#  if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
  IpduM_TxContainerPduIdxOfTxLoInfoType txContainerId = IpduM_GetTxContainerPduIdxOfTxLoInfo(TxPduId);
#  endif

#  if ((IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  if(0u != IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(containerPduId))
  {
    if(0u != IpduM_GetTxConfTimeoutCnt(txConfTimeoutCntIdx))
    {
#   if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
      IpduM_ContainerTxConfLastIterType readOffset;
      IpduM_ContainerTxConfLastStartIdxOfTxContainerPduType bufferStartIdx = IpduM_GetContainerTxConfLastStartIdxOfTxContainerPdu(txContainerId);
      for(readOffset = 0u; readOffset < IpduM_GetContainerTxConfLaId(IpduM_GetContainerTxConfLaIdIdxOfTxContainerPdu(txContainerId)); readOffset++)
      {
        IpduM_ContainerTxConfLastType currentContainedPdu = IpduM_GetContainerTxConfLast(bufferStartIdx + readOffset);
        if(IpduM_IsTxConfirmationOfTxContainedPdu(currentContainedPdu))
        {
          PduR_IpduMTxConfirmation(IpduM_GetTxContainedPduRefOfTxContainedPdu(currentContainedPdu));
        }
      }
#   endif

      IpduM_SetTxConfTimeoutCnt(txConfTimeoutCntIdx, IPDUM_RESET);     /* Clear counter */ /* SBSW_IPDUM_CSL03 */
    }
  }
#   endif

  IPDUM_DUMMY_STATEMENT(TxPduId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRxIndication()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerRxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  uint8 errorId = IPDUM_E_NO_ERROR;

  IpduM_StartPosOfRxContainerBufferInfoType bufferStartPos = IpduM_GetStartPosOfRxContainerBufferInfo(rxContainerId);
  IpduM_CountOfRxContainerBufferInfoType bufferInstanceCount = IpduM_GetCountOfRxContainerBufferInfo(rxContainerId);
  IpduM_LengthOfRxContainerBufferInfoType bufferInstanceLength = IpduM_GetLengthOfRxContainerBufferInfo(rxContainerId);
  uint8 headerSize = IpduM_GetRxHeaderSize(rxContainerId);

# if (IPDUM_IMMEDIATEPROCESSINGOFRXCONTAINERPDU == STD_ON)
  /* If immediate processing is active: loop through all contained-pdus, send rxindications if configured or accept all */
  if(IpduM_IsImmediateProcessingOfRxContainerPdu(rxContainerId))
  {
    /* Immediate processing. Send RxIndications for all received contained-PDUs. */

    uint8 *pContainerRxBuf;
    PduInfoType pduInfo;

    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    {
      IpduM_ContainerRxBufferIterType containerBufId;
      /* Copy to Rx Buffer */
      pContainerRxBuf = IpduM_GetAddrContainerRxBuffer(bufferStartPos + (IpduM_GetContainerWriteIdxOfRxContainerBufferIdxInfo(rxContainerId) * bufferInstanceLength));
      VStdMemCpyRamToRam(pContainerRxBuf, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);       /* SBSW_IPDUM_CONTAINERRXINDICATION_CALL_MEMCPY */
      /* add zero header for safe PDU termination */
      for(containerBufId = PduInfoPtr->SduLength; (containerBufId<bufferInstanceLength) && (containerBufId < (PduInfoPtr->SduLength + headerSize));containerBufId++) /* COV_IPDUM_TERMINATION_ZEROES */
      {
        pContainerRxBuf[containerBufId] = 0; /* SBSW_IPDUM_CONTAINERRXINDICATION_MEMORY_WRITE */
      }
      pduInfo.SduDataPtr = pContainerRxBuf;
      pduInfo.SduLength = (PduLengthType)bufferInstanceLength;
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

    /* Data is now at container write pointer position, send rxIndications */
    IpduM_UnpackRxContainerPdu(rxContainerId, &pduInfo);        /* SBSW_IPDUM_CONTAINERRXINDICATION_CALL_UNPACKRXCONTAINERPDU */

    /* do NOT increment the write buffer as the PDU is not queued. */
  }
  else
# endif
  {
    /* Deferred processing. Enqueue PDU for later reception handling. */

    /* If the PDU does not fit into container: DET, oldest entry will be overwritten while enqueueing */
    if((IpduM_ContainerWriteCountOfRxContainerBufferIdxInfoType)(IpduM_GetContainerWriteCountOfRxContainerBufferIdxInfo(rxContainerId) - IpduM_GetContainerReadCountOfRxContainerBufferIdxInfo(rxContainerId)) >= bufferInstanceCount)
    {
      /* Queue is full, return an error */
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
      errorId = IPDUM_E_QUEUEOVFL;
# endif
      /* increment read pointer, this overwrites the oldest item */
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      IpduM_IncContainerReadCountOfRxContainerBufferIdxInfo(rxContainerId);     /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      IpduM_IncContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId);       /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      if(IpduM_GetContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId) >= bufferInstanceCount)
      {
        IpduM_SetContainerReadIdxOfRxContainerBufferIdxInfo(rxContainerId, 0u);  /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }

    /* Enqueue PDU */
    {
      IpduM_ContainerRxBufferIterType containerBufId;
      uint8 *pContainerRxBuf = IpduM_GetAddrContainerRxBuffer(bufferStartPos + (IpduM_GetContainerWriteIdxOfRxContainerBufferIdxInfo(rxContainerId) * bufferInstanceLength));
      VStdMemCpyRamToRam(pContainerRxBuf, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);        /* SBSW_IPDUM_CONTAINERRXINDICATION_CALL_MEMCPY */
      /* add zero header for safe PDU termination */
      for(containerBufId = PduInfoPtr->SduLength; (containerBufId<bufferInstanceLength) && (containerBufId < (PduInfoPtr->SduLength + headerSize));containerBufId++) /* COV_IPDUM_TERMINATION_ZEROES */
      {
        pContainerRxBuf[containerBufId] = 0; /* SBSW_IPDUM_CONTAINERRXINDICATION_MEMORY_WRITE */
      }

      /* update write pointers */
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      IpduM_IncContainerWriteCountOfRxContainerBufferIdxInfo(rxContainerId);    /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      IpduM_IncContainerWriteIdxOfRxContainerBufferIdxInfo(rxContainerId);      /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      if(IpduM_GetContainerWriteIdxOfRxContainerBufferIdxInfo(rxContainerId) >= bufferInstanceCount)
      {
        IpduM_SetContainerWriteIdxOfRxContainerBufferIdxInfo(rxContainerId, 0u); /* SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS */
      }
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }
  }
  return errorId;
}
#endif

#if (IPDUM_VERSION_INFO_API == STD_ON)
/*******************************************************************************************
 *  IpduM_GetVersionInfo()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, IPDUM_APPL_DATA) versioninfo)
{
  uint8 errorId = IPDUM_E_NO_ERROR;
# if (IPDUM_DEV_ERROR_DETECT == STD_ON) /* COV_IPDUM_VAR_DEV_ERROR_DETECT */
  if(versioninfo == NULL_PTR)
  {
    errorId = IPDUM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* Set version info / fill struct */
    versioninfo->vendorID = (uint16) IPDUM_VENDOR_ID; /* SBSW_IPDUM_GETVERSION_PARAM */
    versioninfo->moduleID = (uint8) IPDUM_MODULE_ID; /* SBSW_IPDUM_GETVERSION_PARAM */
    versioninfo->sw_major_version = (uint8) IPDUM_SW_MAJOR_VERSION; /* SBSW_IPDUM_GETVERSION_PARAM */
    versioninfo->sw_minor_version = (uint8) IPDUM_SW_MINOR_VERSION; /* SBSW_IPDUM_GETVERSION_PARAM */
    versioninfo->sw_patch_version = (uint8) IPDUM_SW_PATCH_VERSION; /* SBSW_IPDUM_GETVERSION_PARAM */
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_VERSIONINFO, (errorId));
  }
# else
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif
}
#endif

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* module specific MISRA deviations:
   MD_IpduM_3436:
     Reason:      The upper layer module interface API can be switched between Com and PduR as specified by AUTOSAR.
     Risk:        Invalid function call with invalid handles.
     Prevention:  The module test is performed with IPDUM_DIRECT_COM_INVOCATION STD_ON and STD_OFF.
   
   MD_IpduM_3200:
     Reason:      The result of the PduR call is not checked.
     Risk:        A negative result would be unnoticed.
     Prevention:  This is ok because this call is just an indication for a time-triggered bus, no data is lost.
*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_IPDUM_COPYSEGMENTS
    \DESCRIPTION The memory location is used for an array write access using the IDs.
    \COUNTERMEASURE \N The destPtr and srcPtr are not checked against NULL_PTR. The caller of this local function checks them.
                       The segmentStartIdx and segmentEndIdx are checked by the caller of this local function.

  \ID SBSW_IPDUM_JITTRIGGERTRANSMIT_CALL_PDURTRIGGERTRANSMIT
    \DESCRIPTION PduR_IpduMTriggerTransmit is called with an ID and a pointer.
    \COUNTERMEASURE \N Both the ID and the pointer are checked by the caller of this local function.

  \ID SBSW_IPDUM_JITTRIGGERTRANSMIT_CALL_COPYSEGMENTS
    \DESCRIPTION IpduM_CopySegments is called with two indices and two pointers.
    \COUNTERMEASURE \N The indices and the first pointer are calculated using ComStackLib indirections
                       based on the function parameters txPartId and txPathwayId. These parameters and
                       the second pointer are checked by the caller of this local function.

  \ID SBSW_IPDUM_CONTAINER_WRITE_HEADER
    \DESCRIPTION The memory location is used for an array write acess over multiple bytes.
    \COUNTERMEASURE \N The parameter freeBytes is used to ensure the values can be written to the pointer.
                       The caller of this local function ensures the freeBytes parameter contains the correct
                       amount of free bytes at the pointer position.

  \ID SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU
    \DESCRIPTION The parameter txContainerId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller of this local function ensures the txContainerId parameter contains the correct value.

  \ID SBSW_IPDUM_TRANSMIT_CURR_CONTAINER_PDU_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length.
    \COUNTERMEASURE \N The first pointer is generated large enough for the largest possible number of items, ensured during
                       generation. The second pointer and length always match as they are generated using the ComStackLib.

  \ID SBSW_IPDUM_TRANSMIT_QUEUED_CONTAINER_PDU
    \DESCRIPTION The parameter txContainerId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller of this local function ensures the txContainerId parameter contains the correct value.

  \ID SBSW_IPDUM_QUEUE_CURR_CONTAINER_PDU
    \DESCRIPTION The parameter txContainerId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller of this local function ensures the txContainerId parameter contains the correct value.

  \ID SBSW_IPDUM_TRANSMIT_OR_QUEUE_CURR_CONTAINER_PDU
    \DESCRIPTION The parameter txContainerId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller of this local function ensures the txContainerId parameter contains the correct value.

  \ID SBSW_IPDUM_FILLLASTISBEST_CALL_PDURTRIGGERTRANSMIT
    \DESCRIPTION PduR_IpduMTriggerTransmit is called with an ID and a pointer.
    \COUNTERMEASURE \N The ID is generated from callee configuration data, the pointer is generated large enough for any configured PDU.

  \ID SBSW_IPDUM_FILLLASTISBEST_ARRAY_ACCESS
    \DESCRIPTION Array txConfLast is accessed with an index within a loop.
    \COUNTERMEASURE \N The index is initialized with zero and the loop increments it by 1 each time. The loop is designed
                       to iterate over all PDUs contained in one container PDU. The array written here is generated large
                       enough to contain the maximum number of PDUs in one container PDU, which is the maximum number of
                       possible loops.

  \ID SBSW_IPDUM_FILLLASTISBEST_CALL_CONTAINERWRITEHEADER
    \DESCRIPTION IpduM_ContainerWriteHeader is called with two pointers, and two lengths. The header
                 pointer is local/static and always correct and the headersize always matches.
    \COUNTERMEASURE \N The parameter lastIsBestBuffer is generated large enough to fit any configured PDU
                       and the last parameter, freeBytes, is calculated using the size of the buffer passed
                       to this function. The caller verifies the size matches.

  \ID SBSW_IPDUM_FILLLASTISBEST_MEMORY_WRITE
    \DESCRIPTION An array is written using a calculated index.
    \COUNTERMEASURE \N The index is the iterator in a for-loop that always starts at or after the start
                       position of the buffer and always ends at its end at the latest.

  \ID SBSW_IPDUM_MUX_TRANSMIT_INDIRECT_ACCESS
    \DESCRIPTION The parameter txPartId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller of this local function ensures the txPartId parameter contains the correct value.

  \ID SBSW_IPDUM_MUXTRANSMIT_CALL_JITUPDATE
    \DESCRIPTION IpduM_JitUpdate is called with two indices, a pointer and a boolean value.
    \COUNTERMEASURE \N One index is a function parameter, the other one derived from it using
                       ComStackLib indirections, the pointer is also created using ComStackLib
                       indirections based on the parameter txPartId and the boolean value is
                       always right. The caller checks the parameter txPartId.

  \ID SBSW_IPDUM_MUXTRIGGERTRANSMIT_CALL_JITUPDATE
    \DESCRIPTION IpduM_JitUpdate is called with two indices, a pointer and a boolean value.
    \COUNTERMEASURE \N One index is a function parameter, the other one is static, the pointer
                       is created using ComStackLib indirections based on the parameter txPathwayHnd
                       and the boolean value is always right. The caller checks the parameter txPathwayHnd.

  \ID SBSW_IPDUM_MUX_TX_CONFIRMATION_INDIRECT_ACCESS
    \DESCRIPTION The parameter TxPduId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller ensures the TxPduId parameter contains the correct value.

  \ID SBSW_IPDUM_CONTAINER_TRANSMIT_INDIRECT_ACCESS
    \DESCRIPTION The parameter txContainedId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller ensures the txContainedId parameter contains the correct value.

  \ID SBSW_IPDUM_CONTAINER_TRANSMIT_CALL_CALCULATESIZEOFCONTAINER
    \DESCRIPTION IpduM_CalculateSizeOfContainer is called with an ID and a pointer.
    \COUNTERMEASURE \N The pointer is built using ComStackLib indirections based on the function parameter
                       txContainerId, which also is the ID used here. This parameter is checked prior to
                       calling this local function (IpduM_TransmitQueuedContainerPdu).

  \ID SBSW_IPDUM_CONTAINER_TRANSMIT_CALL_PDURTRANSMIT
    \DESCRIPTION PduR_IpduMTransmit is called with an ID and a pointer. The pointer is built using
                 ComStackLib-generated data structures based on the function parameter txContainerId.
                 This parameter is checked prior to calling this local function (IpduM_TransmitQueuedContainerPdu).
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.

  \ID SBSW_IPDUM_CONTAINER_TRANSMIT_INCREMENT_CALCULATED_POSITION
    \DESCRIPTION A value in an array is incremented, the position in the array is calculated.
    \COUNTERMEASURE \N The position is calculated using the start position and an offset (currentInstance). The
                       start position is retrieved using ComStackLib functions and a parameter (verified by caller),
                       the offset is a write index within a cyclic buffer, the code parts setting this index were
                       reviewed and tested, and the maximum value matches the array size, ensured during generation.

  \ID SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length.
    \COUNTERMEASURE \N The second pointer and length always match as they are generated using the
                       ComStackLib, the first pointer is checked by the caller calling this local function.

  \ID SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_PTR_WRITE
    \DESCRIPTION Data is written to a pointer.
    \COUNTERMEASURE \N The caller of this local function ensures this is a valid pointer.

  \ID SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_INDIRECT_ACCESS
    \DESCRIPTION The parameter txContainedId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller ensures the txContainedId parameter contains the correct value.

  \ID SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_CALL_FILLLASTISBESTCONTAINER
    \DESCRIPTION IpduM_FillLastIsBestContainer is called with an index and a pointer.
    \COUNTERMEASURE \N The index is passed to the function, the caller verifies it is a valid TxContainerId.
                       The pointer is a buffer with a calculated offset based on the given index. During
                       generation, it is ensured that these values always match.

  \ID SBSW_IPDUM_CONTAINER_RX_INDICATION_INDIRECT_ACCESS
    \DESCRIPTION The parameter rxContainerId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller ensures the rxContainerId parameter contains the correct value.

  \ID SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_INDIRECT_ACCESS
    \DESCRIPTION The parameter txContainedId is used as an ID to access generated structures.
    \COUNTERMEASURE \N The caller ensures the txContainedId parameter contains the correct value.

  \ID SBSW_IPDUM_INIT_MEMCPY
    \DESCRIPTION The memory location is used for a function call (and lastly, for an array access)
    \COUNTERMEASURE \N The generator uses the same function to get the size, TxBuffer and TxInitValues
                       always have the same size.

  \ID SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_CONTAINERWRITEHEADER
    \DESCRIPTION IpduM_ContainerWriteHeader is called with two pointers, and two lengths. The header
                 pointer is local/static and always correct and the headersize always matches.
    \COUNTERMEASURE \N The parameters pContainerTxBuf and freeBytes are calculated using ComStackLib
                       indirections based on the function parameter txContainerId. The parameters are
                       checked prior to calling this local function (IpduM_TransmitCurrContainerPdu).

  \ID SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_FILLLASTISBESTCONTAINER
    \DESCRIPTION IpduM_FillLastIsBestContainer is called with an index and a pointer.
    \COUNTERMEASURE \N The index is passed to the function, the caller verifies it is a valid TxContainerId.
                       The pointer is a buffer with a calculated offset based on the given index. During
                       generation, it is ensured that these values always match.

  \ID SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_CALCULATESIZEOFCONTAINER
    \DESCRIPTION IpduM_CalculateSizeOfContainer is called with an ID and a pointer.
    \COUNTERMEASURE \N The pointer is built using ComStackLib indirections based on the function parameter
                       txContainerId, which also is the ID used here. This parameter is checked prior to
                       calling this local function (IpduM_TransmitCurrContainerPdu).

  \ID SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_PDURTRANSMIT
    \DESCRIPTION PduR_IpduMTransmit is called with an ID and a pointer. The pointer is built using
                 ComStackLib-generated data structures based on the function parameter txContainerId.
                 This parameter is checked prior to calling this local function (IpduM_TransmitCurrContainerPdu).
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.

  \ID SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_CALCULATESIZEOFCONTAINER
    \DESCRIPTION IpduM_CalculateSizeOfContainer is called with an ID and a pointer.
    \COUNTERMEASURE \N The pointer is built using ComStackLib indirections based on the function parameter
                       txContainerId, which also is the ID used here. This parameter is checked prior to
                       calling this local function (IpduM_TransmitQueuedContainerPdu).

  \ID SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_PDURTRANSMIT
    \DESCRIPTION PduR_IpduMTransmit is called with an ID and a pointer. The pointer is built using
                 ComStackLib-generated data structures based on the function parameter txContainerId.
                 This parameter is checked prior to calling this local function (IpduM_TransmitQueuedContainerPdu).
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.

  \ID SBSW_IPDUM_TRANSMITQUEUEDCONTAINERPDU_CALL_FILLLASTISBESTCONTAINER
    \DESCRIPTION IpduM_FillLastIsBestContainer is called with an index and a pointer.
    \COUNTERMEASURE \N The index is passed to the function, the caller verifies it is a valid TxContainerId.
                       The pointer is a buffer with a calculated offset based on the given index. During
                       generation, it is ensured that these values always match.

  \ID SBSW_IPDUM_QUEUECURRCONTAINERPDU_CALL_CONTAINERWRITEHEADER
    \DESCRIPTION IpduM_ContainerWriteHeader is called with two pointers, and two lengths. The header
                 pointer is local/static and always correct and the headersize always matches.
    \COUNTERMEASURE \N The parameters pContainerTxBuf and freeBytes are calculated using ComStackLib
                       indirections based on the function parameter txContainerId. The parameters are
                       checked prior to calling this local function (IpduM_QueueCurrContainerPdu).

  \ID SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_CALL_CONTAINERWRITEHEADER
    \DESCRIPTION IpduM_ContainerWriteHeader is called with two pointers, and two lengths.
    \COUNTERMEASURE \N The parameters pContainerTxBuf, header and freeBytes are calculated using
                       ComStackLib indirections based on the function parameter txContainedId. The
                       parameter headerSize is calculated using the local function IpduM_GetTxHeaderSize()
                       using ComStackLib indirections based on the function parameter txContainedId. The
                       calculated headerSize is one of two possible, pre-defined values and both are safe
                       because of the freeBytes parameter verifying there is sufficient space. The input
                       parameters are checked prior to calling this local function
                       (IpduM_AddTxPduToCurrContainer).

  \ID SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_CALL_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length.
    \COUNTERMEASURE \N The second pointer and length always match as part of PduInfoPtr, the first pointer is
                       checked by the caller calling this local function.

  \ID SBSW_IPDUM_JITUPDATE_CALL_JITTRIGGERTRANSMIT
    \DESCRIPTION IpduM_JitTriggerTransmit is called with three IDs and a pointer. The caller of this local
                 function checks all parameters.
    \COUNTERMEASURE \N The first parameter is an SNV provided by the UL (upper layer). The UL ensures
                       that the SNV is valid.

  \ID SBSW_IPDUM_ANY_CALL_CONTAINERREADHEADER
    \DESCRIPTION IpduM_ContainerReadHeader is called with a pointer and a size.
    \COUNTERMEASURE \N The function accesses the pointer read-only.

  \ID SBSW_IPDUM_UNPACKRXCONTAINERPDU_CALL_PDURRXINDICATION
    \DESCRIPTION PduR_IpduMRxIndication is called with an ID and a pointer. The pointer is given by
                 the calling function that ensures it is correct.
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.

  \ID SBSW_IPDUM_MAINFUNCTIONRX_CALL_UNPACKRXCONTAINERPDU
    \DESCRIPTION IpduM_UnpackRxContainerPdu is called with an ID and a pointer.
    \COUNTERMEASURE \N The ID is verified by ComStackLib, the pointer is calculated using generated
                       ComStackLib structures and the ID.

  \ID SBSW_IPDUM_TRANSMIT_CALL_MUXTRANSMIT
    \DESCRIPTION IpduM_MuxTransmit is called with an ID and a pointer. The ID is a SNV provided by the UL (upper layer). The UL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_TRANSMIT_CALL_CONTAINERTRANSMIT
    \DESCRIPTION IpduM_ContainerTransmit is called with an ID and a pointer. The ID is a SNV provided by the UL (upper layer). The UL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_TRIGGERTRANSMIT_CALL_MUXTRIGGERTRANSMIT
    \DESCRIPTION IpduM_MuxTriggerTransmit is called with an ID and a pointer. The ID is a SNV provided by the LL (upper layer). The LL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_TRIGGERTRANSMIT_CALL_CONTAINERTRIGGERTRANSMIT
    \DESCRIPTION IpduM_ContainerTriggerTransmit is called with an ID and a pointer. The ID is a SNV provided by the LL (upper layer). The LL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_RXINDICATION_CALL_MUXRXINDICATION
    \DESCRIPTION IpduM_MuxRxIndication is called with an ID and a pointer. The ID is a SNV provided by the LL (lower layer). The LL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_RXINDICATION_CALL_CONTAINERRXINDICATION
    \DESCRIPTION IpduM_ContainerRxIndication is called with an ID and a pointer. The ID is a SNV provided by the LL (lower layer). The LL ensures that the SNV is valid.
    \COUNTERMEASURE \R The PduInfoPtr is checked against NULL_PTR.

  \ID SBSW_IPDUM_MUXTRANSMIT_CALL_COPYSEGMENTS
    \DESCRIPTION IpduM_CopySegments is called with two IDs and two pointers.
    \COUNTERMEASURE \N The IDs and the first pointer are generated structures using the ComStackLib based on
                       the same objects, they always match. The PduInfoPtr is not checked against NULL_PTR
                       and must be checked by the caller.

  \ID SBSW_IPDUM_MUXTRANSMIT_CALL_PDURTRANSMIT
    \DESCRIPTION PduR_IpduMTransmit is called with an ID and a pointer. The pointer is built using
                 ComStackLib-generated data structures and is always valid.
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.

  \ID SBSW_IPDUM_MUXTRIGGERTRANSMIT_CALL_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length. The second pointer and the index are based
                 on ComStackLib generated structures and always match.
    \COUNTERMEASURE \N The first pointer is verified by the caller of this local function.

  \ID SBSW_IPDUM_MUXTRIGGERTRANSMIT_PDUINFO_WRITE
    \DESCRIPTION The PduInfoPtr length value is written to.
    \COUNTERMEASURE \N The caller of this local function ensures a valid pointer is given.

  \ID SBSW_IPDUM_MUXRXINDICATION_CALL_COPYSEGMENTS
    \DESCRIPTION IpduM_CopySegments is called with two IDs and two pointers.
    \COUNTERMEASURE \N The IDs and the first pointer are generated structures using the ComStackLib based on
                       the same objects, they always match. The PduInfoPtr is not checked against NULL_PTR
                       and must be checked by the caller.

  \ID SBSW_IPDUM_MUXRXINDICATION_CALL_PDURRXINDICATION
    \DESCRIPTION PduR_IpduMRxIndication is called with an ID and a pointer.
    \COUNTERMEASURE \N The ID is a SNV provided by PduR. The PduR ensures that the SNV is valid.
                       The PduInfoPtr is built using ComStackLib-generated data structures and is
                       always valid. The length however is taken from the parameter PduInfoPtr and
                       is checked by the caller of this local function.

  \ID SBSW_IPDUM_CONTAINERTRANSMIT_CALL_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length.
    \COUNTERMEASURE \N The second pointer and length always match as part of PduInfoPtr, the first pointer is
                       built using ComStackLib indirections based on the function parameter TxContainedId. The
                       caller verifies this parameter is valid.

  \ID SBSW_IPDUM_CONTAINERTRANSMIT_CALL_ADDTXPDUTOCURRCONTAINER
    \DESCRIPTION IpduM_AddTxPduToCurrContainer is called with an ID and a pointer.
    \COUNTERMEASURE \N The ID and pointer are verified by the caller. The pointer is used read-only by the called function.

  \ID SBSW_IPDUM_CONTAINERRXINDICATION_CALL_MEMCPY
    \DESCRIPTION MemCpy is called with two pointers and a length.
    \COUNTERMEASURE \N The second pointer and length always match as part of PduInfoPtr, the first pointer is
                       built using ComStackLib indirections based on the function parameter rxContainerId. The
                       caller verifies this parameter is valid.

  \ID SBSW_IPDUM_CONTAINERRXINDICATION_MEMORY_WRITE
    \DESCRIPTION An array is written using a calculated index.
    \COUNTERMEASURE \N The index is the iterator in a for-loop that always starts at or after the start
                       position of the buffer and always ends at its end at the latest.

  \ID SBSW_IPDUM_CONTAINERRXINDICATION_CALL_UNPACKRXCONTAINERPDU
    \DESCRIPTION IpduM_UnpackRxContainerPdu is called with an ID and a pointer.
    \COUNTERMEASURE \N The ID is verified by the caller, the pointer is built using ComStackLib indirections
                       and a passed pointer from the caller. The caller verifies the pointer.

  \ID SBSW_IPDUM_CSL01
    \DESCRIPTION Index Access is using ComStackLib
    \COUNTERMEASURE  \N Qualified use-case CSL01 of ComStackLib.

  \ID SBSW_IPDUM_CSL02
    \DESCRIPTION  Access of Table1, via indirection over Table2 with same index using ComStackLib.
    \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

  \ID SBSW_IPDUM_CSL03
    \DESCRIPTION Access to Table1 via indirection over Table2.
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib
    
  \ID SBSW_IPDUM_GETVERSION_PARAM
    \DESCRIPTION    The IpduM_GetVersionInfo writes to the 'versioninfo' pointer parameter. It is checked against NULL,
                    but this does not guarantee that the referenced memory is valid.
    \COUNTERMEASURE \N  Pointers passed to public IpduM APIs point to a valid memory range. A general countermeasure is included in the safety manual.

   SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

  \ID COV_IPDUM_MISRA
    \ACCEPT X
    \ACCEPT TX
    \REASON [MSR_COV_MISRA]
  
  \ID COV_IPDUM_VAR_DEV_ERROR_DETECT
    \ACCEPT TX
    \REASON Det error detection must always be enabled for SafeBsw.

  \ID COV_IPDUM_VAR_DEPENDENT_SWITCH
    \ACCEPT TX
    \ACCEPT TF tf tx
    \ACCEPT TF tx tf
    \ACCEPT TX tx tx
    \REASON The nested switch depends on a previous switch.
    
  \ID COV_IPDUM_EMPTY_CONFIG
    \ACCEPT TX tf tf tf tf
    \REASON Empty configurations are excluded.
  
  \ID COV_IPDUM_INVALID_CONFIG
    \ACCEPT TF tf tx tf
    \ACCEPT TF tf tf tx
    \REASON Coverage of this code section would require an invalid configuration.
    
  \ID COV_IPDUM_DEPENDENT_VALUES
    \ACCEPT TF tf tx tf
    \REASON Generated values depend on each other.
    
  \ID COV_IPDUM_TXCONF_ALWAYS_ZERO
    \ACCEPT XF
    \ACCEPT TX tx xx xx
    \ACCEPT TF tf tx tf
    \REASON A TxConfirmation Timeout of zero is a special value which is used for unused TxConfirmation Timeouts.

  \ID COV_IPDUM_INIT_MEMCPY
    \ACCEPT TX
    \REASON This "if" statement was added to avoid illegal calls to Memcpy with a NULL ptr as the source
            address. The behavior without this "if" is always correct because the length is always zero
            in these cases, but a DET is thrown because of the NULL ptr. This "if" statement avoids the
            DET call but doesn't change any functionality.
    
  \ID COV_IPDUM_SEARCH_HEADER_ID_LOOP_ABORT
    \ACCEPT TX
    \REASON This is a search function, normal termination of the loop would only occur if the searched item was not found.
  
  \ID COV_IPDUM_PRECOMPILE_CONFIG
    \ACCEPT XF
    \REASON Precompile configurations are always initialized with a NULL config pointer.
  
  \ID COV_IPDUM_NO_DEV_ERROR
    \ACCEPT XF
    \REASON Only tests with erroneous configurations would cover this.
    
  \ID COV_IPDUM_DEFENSIVE_PROGRAMMING
    \ACCEPT TX
    \REASON This condition is used because of safe programming.
    
  \ID COV_IPDUM_TERMINATION_ZEROES
    \ACCEPT TF tx tf
    \REASON Double condition in the loop for safe programming reasons
    
  \ID COV_IPDUM_LAST_IS_BEST_TRIGGERTRANSMIT
    \ACCEPT TX
    \REASON Last-is-best PDUs need TriggerTransmit to update their PDUs.
  
COV_JUSTIFICATION_END */

/* *INDENT-ON* */

/**********************************************************************************************************************
  END OF FILE: IpduM.c
**********************************************************************************************************************/
