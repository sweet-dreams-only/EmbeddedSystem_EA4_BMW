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
/**        \file  FrIf_Rx.c
 *        \brief  FrIf Rx source file
 *
 *      \details  Implementation of data reception according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FRIF_RX_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of FrIf.h */
# if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
     || (FRIF_SW_MINOR_VERSION != (1u)) \
     || (FRIF_SW_PATCH_VERSION != (2u)) )
#  error "Version numbers of FrIf_Rx.c and FrIf.h are inconsistent"
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
# define FrIf_ReceiveRxLPdu(CtrlIdx, Handle, Buffer, LPduStatus, LPduLength)  Fr_ReceiveRxLPdu_DBA((CtrlIdx), (Handle), &(Buffer), &(LPduStatus), &(LPduLength))
#else
# define FrIf_ReceiveRxLPdu(CtrlIdx, Handle, Buffer, LPduStatus, LPduLength)  Fr_ReceiveRxLPdu((CtrlIdx), (Handle), (Buffer), &(LPduStatus), &(LPduLength))
#endif

#if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) 
# if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
#  define FrIf_GetCurrentUpdateBitBytePos() FrIf_GetUpdateBitBytePos()
# else
#  define FrIf_GetCurrentUpdateBitBytePos() FrameDescriptorPtr->UpdateBitBytePos
# endif /* (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON) */
#else
#  define FrIf_GetCurrentUpdateBitBytePos() FrameLayoutElementPtr->UpdateBitBytePos
#endif /* ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) */

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_Receive()
**********************************************************************************************************************/
/*!
 *
 * \brief        Performs the reception of the given Rx frame.
 * \details      Checks the reception of the given frame. If the frame doesn't belong to a redundant pair, it also
 *               checks
 *               the validity of the received PDUs and provides Rx indications to the corresponding upper layers.
 * \param[in]    FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrameDescriptorPtr    Pointer to the frame descriptor of the frame to be processed.
 * \param[in]    Handle                Handle of the frame to be processed.
 * \return       E_OK                  The frame was successfully received.
 * \return       E_NOT_OK              The frame wasn't successfully received.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      RX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_Receive(FRIF_VCLST_ONLY, 
                                                      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                                      uint16 Handle);

#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_HandleRedundantFrame()
**********************************************************************************************************************/
/*!
 *
 * \brief        Performs the reception of the second frame of a redundant pair of Rx frames.
 * \details      Checks the reception of the second frame of a redundant pair. Also checks the validity of the received
 *               PDUs and provides Rx indications to the corresponding upper layers.
 * \param[in]    FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrameDescriptorPtr    Pointer to the frame descriptor of the main frame of the redundant pair.
 * \param[in]    receiveBuffer         Pointer to the buffer where where the main frame of the redundant pair is
 *                                     stored.
 * \param[in]    Handle                Handle of the main frame of the redundant pair.
 * \param[in]    Fr_LPduLength         Received length of the main frame of the redundant pair.
 * \param[in]    HandleIsReceived      Flag indicating if the main frame of the redundant pair has been received.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \config       Available only if FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON.
 * \ingroup      RX
**********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_HandleRedundantFrame(FRIF_VCLST_ONLY,
                                            FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                            P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer,
                                            uint16 Handle,
                                            uint8 Fr_LPduLength,
                                            boolean HandleIsReceived);

/**********************************************************************************************************************
  FrIf_FillRedundantRxPduInfo()
**********************************************************************************************************************/
/*!
 *
 * \brief        Adds a received PDU to an array of redundant Rx PDUs.
 * \details      Adds the address and length of a received PDU to an array containing the info of several redundant
 *               PDUs.
 * \param[in]    FrIf_ClstIdx             Index of the cluster to be addressed. 
 *                                        This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrameLayoutElementPtr    Pointer to the frame layout element associated to the PDU being processed.
 * \param[in]    receiveBuffer            Pointer to the buffer where the whole Rx frame is stored.
 * \param[in]    CurrentPduLength         Length of the received PDU.
 * \param[in]    Fr_LPduLength            Length of the whole Rx frame.
 * \param[in]    Index                    Index within the array of structs containing information of a pair of
 *                                        redundant Rx PDUs. It must be less than 2.
 * \param[in]    PduIsValid               Flag indicating if the PDU is considered to be valid.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \config       Available only if FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON.
 * \ingroup      RX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_FillRedundantRxPduInfo(FRIF_VCLST_ONLY,
                                            FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr,
                                            P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer,
                                            sint16_least PduNumber,
                                            uint8 UpdateBitBytePos,
                                            uint8 Fr_LPduLength,
                                            uint8 Index,
                                            boolean HandleIsReceived);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
/**********************************************************************************************************************
 *  FrIf_HandleRedundantFrame()
 *********************************************************************************************************************/
/*!
 *
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
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_HandleRedundantFrame(FRIF_VCLST_ONLY,
                                        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                        P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer,
                                        uint16 Handle,
                                        uint8 Fr_LPduLength,
                                        boolean HandleIsReceived)
{
  /* ----- Local Variables ---------------------------------------------- */
  Fr_RxLPduStatusType Fr_RedundantLPduStatus = FR_NOT_RECEIVED;
  /* PRQA S 0310 1 */ /* MD_FrIf_0310 */
  P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) redundantReceiveBuffer = FRIF_GET_REDUNDANT_FRAMEBUFFER(FRIF_VCLST_IDX);
  uint8 Fr_RedundantLPduLength = FrameDescriptorPtr->FrameLength;  
  FrIf_TxHandleType RedundantHandle = FrameDescriptorPtr->FrameHandle;  
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the redundant match of the frame given as input has been received by the Fr.
   *     Flag the redundant match as received, if its check succeeded and its status is not FR_NOT_RECEIVED.
   */
  Std_ReturnType redundantResult = FrIf_ReceiveRxLPdu(FRIF_VCLST_IDX, /* SBSW_FRIF_FCT_CALL_BUFFRRX */ /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
                                                      RedundantHandle,
                                                      redundantReceiveBuffer,
                                                      Fr_RedundantLPduStatus,
                                                      Fr_RedundantLPduLength);

  boolean RedundantHandleIsReceived = (boolean)((Fr_RedundantLPduStatus != FR_NOT_RECEIVED) && (redundantResult == E_OK));

  /* #20 If any of the two frames was received: */
  if((HandleIsReceived == TRUE) || (RedundantHandleIsReceived == TRUE))
  {
    sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
    uint16_least FrameLayoutElementIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle);

    /* This macro can be defined for debugging */
#if defined (FRIF_FRAME_RECEIVED) /* COV_FRIF_TESTSUITE_INSTRUMENTATION */
    if (HandleIsReceived == TRUE)
    {
      FRIF_FRAME_RECEIVED(Handle, receiveBuffer, Fr_LPduLength, &PduNumber); /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */
    }
    if (RedundantHandleIsReceived == TRUE)
    {
      FRIF_FRAME_RECEIVED(RedundantHandle, redundantReceiveBuffer, Fr_RedundantLPduStatus, &PduNumber); /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */
    }
#endif

    /* #30 For each PDU-in-frame: */
    for(; PduNumber >= (sint16_least) 0; PduNumber--)
    {
      FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr = &FrIf_GetRxFrameLayoutElement(FRIF_VCLST_IDX, FrameLayoutElementIndex);
      uint8 selectedPduIndex = 0;

      /* #40 Fill the array containing the information of the redundant Rx PDU pair required by the RxVotingfunction. */
        FrIf_FillRedundantRxPduInfo(FRIF_VCLST_IDX, FrameLayoutElementPtr,            /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */
                                    receiveBuffer,                                   
                                    PduNumber, FrIf_GetCurrentUpdateBitBytePos(),
                                    Fr_LPduLength, 0, HandleIsReceived);

        FrIf_FillRedundantRxPduInfo(FRIF_VCLST_IDX, FrameLayoutElementPtr,            /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */
                                    redundantReceiveBuffer,                          
                                    PduNumber, FrIf_GetCurrentUpdateBitBytePos(),
                                    Fr_RedundantLPduLength, 1, RedundantHandleIsReceived);

      /* #50 If the RxVotingFunction succeeds:
       *       Call the RxIndication function provided by the PDU owner, using the PDU's upper layer ID and the
       *       address and size of the voted payload as arguments. \trace SPEC-40188
       */
      if (FrIf_RxVotingFunction((P2CONST(P2VAR(PduInfoType, AUTOMATIC, FRIF_VAR_NOINIT), AUTOMATIC, FRIF_DATA))&FrIf_P2RedundantRxPduInfo[FRIF_VCLST_IDX], FRIF_MAX_NUMBER_OF_REDUNDANT_PDUS, &selectedPduIndex) == E_OK) /* SBSW_FRIF_FCT_CALL_REDPDUINFO */
      {
        FrIf_RxIndicationFunctions(FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduConfig & FrIf_RxPduOwner,
           FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).Id,
            FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[selectedPduIndex].SduDataPtr,              /* SBSW_FRIF_FCT_CALL_REDRXINDICATION */
            (PduLengthType)FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[selectedPduIndex].SduLength
            );
      }
      FrameLayoutElementIndex++;
    }

    /* #60 If DBA is enabled, request the Fr to unlock the buffers where the main and redundant frames are stored. */
#  if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
    if (HandleIsReceived == TRUE)
    {
      (void)Fr_UnlockRxLPdu_DBA(FRIF_VCLST_IDX, Handle);
    }
    if (RedundantHandleIsReceived == TRUE)
    {
      (void)Fr_UnlockRxLPdu_DBA(FRIF_VCLST_IDX, RedundantHandle);
    }
#  else
    FRIF_DUMMY_STATEMENT(Handle); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif /* (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

    /* Redundant frames are not allowed within FIFO ranges. No further processing will take place even if Fr_LPduStatus
     * or Fr_RedundantLPduStatus are set to FR_RECEIVED_MORE_DATA_AVAILABLE.
     */
  }
} /* FrIf_HandleRedundantFrame() */ /* PRQA S 6010, 6030, 6060 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR */

/**********************************************************************************************************************
  FrIf_FillRedundantRxPduInfo
 *********************************************************************************************************************/
/*!
 *
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
 */
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_FillRedundantRxPduInfo(FRIF_VCLST_ONLY,
                                        FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr,
                                        P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer,
                                        sint16_least PduNumber,
                                        uint8 UpdateBitBytePos,
                                        uint8 Fr_LPduLength,
                                        uint8 Index,
                                        boolean HandleIsReceived)
{
  /* #10 If the frame containing the PDU was received, consider the PDU to be valid.
   *     Initially consider the amount of bytes between the PDU's configured offset-in-frame and the frame's end as
   *     the current length of the PDU (dynamic-length frame).
   */
  boolean PduIsValid = HandleIsReceived;
  uint8 CurrentPduLength = Fr_LPduLength - FrameLayoutElementPtr->ByteOffsetInFrame;

  /* #20 If the frame has been received and the PDU is configured to have an update-bit: \trace SPEC-8298, SPEC-8281
   *       If the PDU's update-bit is set, flag the PDU as valid. 
   *       Otherwise, flag the PDU as invalid.
   */
  if(HandleIsReceived && (FrameLayoutElementPtr->UpdateBitMask != (uint8_least) 0))
  {
      PduIsValid = (boolean)(receiveBuffer[UpdateBitBytePos] & FrameLayoutElementPtr->UpdateBitMask);
  }

  /* #30 If the PDU is valid and the PDU's offset-in-frame is less than the frame's length: \trace SPEC-8326
   *       If the PDU is not the last PDU-in-frame or its configured maximal length is less than the amount of
   *       bytes between its configured offset-in-frame and the frame's end:
   *         Consider the PDU's configured maximal length as the current PDU length.
   *       Add a pointer to the data and its size to the RedundantRxPduInfo array.
   *     Otherwise:
   *       Fill the RedundantRxPduInfo array with a NULL_PTR and length 0.
   */
  if((PduIsValid != FALSE) && (Fr_LPduLength > FrameLayoutElementPtr->ByteOffsetInFrame))
  {
    if (     (PduNumber != 0)
         || (CurrentPduLength > (FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduLength))
       )
    {
      CurrentPduLength = FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduLength;
    }

    FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[Index].SduDataPtr = &receiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame]; /* SBSW_FRIF_FILL_REDUNDANT_INFO */
    FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[Index].SduLength = CurrentPduLength;              /* SBSW_FRIF_FILL_REDUNDANT_INFO */
  }
  else
  {
    FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[Index].SduDataPtr = NULL_PTR;                    /* SBSW_FRIF_FILL_REDUNDANT_INFO */
    FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX)[Index].SduLength = 0;                            /* SBSW_FRIF_FILL_REDUNDANT_INFO */
  }
} /* FrIf_FillRedundantRxPduInfo() */ /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  FrIf_Receive()
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 *
 */
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_Receive(FRIF_VCLST_ONLY,
                                          FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                          uint16 Handle)
{
  /* ----- Local Variables ---------------------------------------------- */
  Fr_RxLPduStatusType Fr_LPduStatus = FR_NOT_RECEIVED;
  P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer = FRIF_GET_FRAMEBUFFER(FRIF_VCLST_IDX); /* PRQA S 0310 */ /* MD_FrIf_0310 */
  uint8 Fr_LPduLength = FrameDescriptorPtr->FrameLength; /* This length is used by the Fr to avoid buffer overflows */

  /* #10 Check if the frame given as input has been received by the Fr. */
  Std_ReturnType Result = FrIf_ReceiveRxLPdu(FRIF_VCLST_IDX,     /* SBSW_FRIF_FCT_CALL_BUFFRRX */ /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
                                             Handle,
                                             receiveBuffer,
                                             Fr_LPduStatus,
                                             Fr_LPduLength);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If redundancy is enabled and a redundant match is configured for the frame given as input:
   *       Perform a redundant reception, taking into account the results from the previous check.
   */
#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
  if(FrameDescriptorPtr->FrameHandle != FrIf_GetInvalidRxHandle(FRIF_VCLST_IDX))
  {
    boolean HandleIsReceived = (boolean)((Fr_LPduStatus != FR_NOT_RECEIVED) && (Result == E_OK));

    FrIf_HandleRedundantFrame(FRIF_VCLST_IDX,                                           /* SBSW_FRIF_FCT_CALL_PTRFWD */
                              FrameDescriptorPtr,                                    /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */   
                              receiveBuffer,                                         
                              Handle,
                              Fr_LPduLength,
                              HandleIsReceived);
  }
  else  
#endif /* (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON) */

  /* #30 Otherwise, if the frame status check succeeded: */
  if(Result == E_OK)
  {
    /* #40 While the frame status is not FR_NOT_RECEIVED: (if FIFO support is enabled, the Rx processing is in a loop)
     *     or
     *     If the frame status is FR_RECEIVED: (if FIFO support is disabled, the Rx processing occurs only once):
     */
#if (FRIF_FIFO_SUPPORT_ENABLE == STD_ON)
    while(Fr_LPduStatus != FR_NOT_RECEIVED)
#else
    if(Fr_LPduStatus == FR_RECEIVED)
#endif

    {
      sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
      uint16_least FrameLayoutElementIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle);

      /* This macro can be defined for debugging */
#if defined (FRIF_FRAME_RECEIVED) /* COV_FRIF_TESTSUITE_INSTRUMENTATION */
      FRIF_FRAME_RECEIVED(Handle, receiveBuffer, Fr_LPduLength, &PduNumber); /* SBSW_FRIF_FCT_CALL_BUFFRIFRX */
#endif

      /* #50 For each PDU-in-frame: */
      for(; PduNumber >= (sint16_least) 0; PduNumber--)
      {
        FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr = &FrIf_GetRxFrameLayoutElement(FRIF_VCLST_IDX, FrameLayoutElementIndex);

        /* #60 If the PDU is configured to have an update-bit but it isn't set, flag the PDU as invalid.
         *     Otherwise, flag the PDU as valid. \trace SPEC-8298, SPEC-8281
         */
        boolean PduIsValid = TRUE;
        if(FrameLayoutElementPtr->UpdateBitMask != (uint8_least) 0)
        {
          PduIsValid = (boolean)(receiveBuffer[FrIf_GetCurrentUpdateBitBytePos()] & FrameLayoutElementPtr->UpdateBitMask);
        }

        /* #70 If the PDU is valid and its configured offset-in-frame is less than the frame length returned by the Fr: \trace SPEC-8326
         *       If the PDU is not the last PDU-in-frame or its configured maximal length is less than the amount of
         *       bytes between its configured offset-in-frame and the frame's end:
         *         Consider the PDU's configured maximal length as the current PDU length.
         *       Otherwise:
         *         Consider the amount of bytes between the PDU's configured offset-in-frame and the frame's end as the
         *         current PDU length (dynamic-length frame).
         */
        if ((PduIsValid != FALSE) && (FrameLayoutElementPtr->ByteOffsetInFrame < Fr_LPduLength))
        {
          uint8 CurrentPduLength;
          if (     (PduNumber != 0) 
               || ((Fr_LPduLength - (FrameLayoutElementPtr->ByteOffsetInFrame)) > (FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduLength))
             )
          {
            CurrentPduLength = FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduLength;
          }
          else
          {
            CurrentPduLength = Fr_LPduLength - FrameLayoutElementPtr->ByteOffsetInFrame;
          }

          /* #80 Call the RxIndication function provided by the PDU owner, using the PDU's upper layer ID and the
           *     address and size of the received payload as arguments. \trace SPEC-40188
           */
          FrIf_RxIndicationFunctions(FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).PduConfig & FrIf_RxPduOwner,
                                     FrIf_GetRxPduDescriptor(FRIF_VCLST_IDX, FrameLayoutElementPtr->PduHandle).Id,
                                     &receiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame], /* SBSW_FRIF_FCT_CALL_RXINDICATION */
                                     CurrentPduLength);
        }
        FrameLayoutElementIndex++;
      }

      /* #90 If DBA is enabled, request the Fr to unlock the buffer where the received frame is stored. */
#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
      (void)Fr_UnlockRxLPdu_DBA(FRIF_VCLST_IDX, Handle);
#endif

      /* #95 If FIFO support is enabled:
       *       If the frame status is FR_RECEIVED_MORE_DATA_AVAILABLE:
       *         Request the next instance of the frame to the Fr.
       *         If the request fails, set the frame status as FR_NOT_RECEIVED (break out of the FIFO loop).
       *       Otherwise:
       *         Break out of the FIFO loop (no more data is available).
       */
#if (FRIF_FIFO_SUPPORT_ENABLE == STD_ON)
      if(Fr_LPduStatus == FR_RECEIVED_MORE_DATA_AVAILABLE)
      {
        Result = FrIf_ReceiveRxLPdu(FRIF_VCLST_IDX,              /* SBSW_FRIF_FCT_CALL_BUFFRRX */ /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
                                    Handle,
                                    receiveBuffer,
                                    Fr_LPduStatus,
                                    Fr_LPduLength);
        if (Result == E_NOT_OK)
        {
          Fr_LPduStatus = FR_NOT_RECEIVED;
        }
      }
      else
      {
        break;
      }
#endif /* if (FRIF_FIFO_SUPPORT_ENABLE == STD_ON) */
    }
  }
  else
  {
    /* Nothing to be done if FrIf_ReceiveRxLPdu() returned E_NOT_OK. */
  }
  return Result;
} /* FrIf_Receive() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrIf_RxTask()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_RxTask(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType Result = E_OK;

  /* #10 Determine which columns of the communication matrix are relevant to the current job. */
  const uint16 maxColumn = FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber).MaxColumnNumber;
  uint16_least columnNumber = FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber).MinColumnNumber; /* ESCAN00076433 */

  /* ----- Implementation ----------------------------------------------- */
  /* #20 For each relevant column: */
  for(; columnNumber <= maxColumn; columnNumber++)
  {
    /* #30 Retrieve the frame handle stored at the row corresponding to the current local cycle. */
    const uint16 Handle = FrIf_GetRxColumn(FRIF_VCLST_IDX, columnNumber) [FrIf_Status[FRIF_VCLST_IDX].CurrentCycle & FrIf_GetRxCycleMask(FRIF_VCLST_IDX, columnNumber)];

    /* #40 If the handle is valid:*/
    if(Handle != FrIf_GetInvalidRxHandle(FRIF_VCLST_IDX))
    {
      /* #50 Retrieve the frame descriptor associated to the handle. */
#if (FRIF_3RD_PARTY_DRIVER_SUPPORT == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetRxFrameDescriptor(FRIF_VCLST_IDX, Handle - FrIf_GetInvalidTxHandle(FRIF_VCLST_IDX));
#else  
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetRxFrameDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalRxLPduIdx(FRIF_VCLST_IDX, Handle));
#endif

      /* #60 Perform the reception of the frame associated to the handle. */
      Result = FrIf_Receive(FRIF_VCLST_IDX, FrameDescriptorPtr, Handle);                       /* SBSW_FRIF_FCT_CALL_PTR2RXFRAMEDESC */
    }
  }
  return Result;
} /* FrIf_RxTask() */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Rx.c
 *********************************************************************************************************************/
