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
/**        \file  FrIf_Tx.c
 *        \brief  FrIf Tx source file
 *
 *      \details  Implementation of the data transmission according to:
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

#define FRIF_TX_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of FrIf.h */
#if (   (FRIF_SW_MAJOR_VERSION != (5u)) \
     || (FRIF_SW_MINOR_VERSION != (1u)) \
     || (FRIF_SW_PATCH_VERSION != (2u)) )
# error "Version numbers of FrIf_Tx.c and FrIf.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
# define FrIf_TransmitFrameBuffer(CtrlIdx,  LPduIdx, DataPtr, Length)   Fr_TransmitTxLPdu_DBA(CtrlIdx, LPduIdx, Length)
# define FrIf_TransmitTxLPdu(CtrlIdx, LPduIdx, DataPtr, Length)         Fr_TransmitTxLPdu_ImmediateDBA(CtrlIdx, LPduIdx, DataPtr, Length)
#else
# define FrIf_TransmitFrameBuffer(CtrlIdx, LPduIdx, DataPtr, Length)    Fr_TransmitTxLPdu(CtrlIdx, LPduIdx, DataPtr, Length)
# define FrIf_TransmitTxLPdu(CtrlIdx, LPduIdx, DataPtr, Length)         Fr_TransmitTxLPdu(CtrlIdx, LPduIdx, DataPtr, Length)
#endif

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_TxConfirmation()
**********************************************************************************************************************/
/*!
 *
 * \brief        Confirms the transmission of PDUs to the corresponding upper layers.
 * \details      Iterates through the PDUs of a sent frame and confirms the transmission of the PDUs flagged as sent to
 *               the corresponding upper layers.
 * \param[in]    FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrameDescriptorPtr    Pointer to the descriptor of the frame whose PDUs will be confirmed.
 * \param[in]    Handle                Handle of the Tx frame whose PDUs will be confirmed. It shall be used as array
 *                                     index without any modifications.
 *                                     Expected range: [0, (size of FrIf_TxPduWasSentFlags[] - 1)]
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      TX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_TxConfirmation(FRIF_VCLST_ONLY,
                                            FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                            uint16 Handle);

/**********************************************************************************************************************
  FrIf_IncrementTxReqCounter()
**********************************************************************************************************************/
/*!
 *
 * \brief        Increases the request counter of a given PDU.
 * \details      Checks if request counters are enabled and if the given PDU has one. If so, the counter is increased.
 * \param[in]    FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    TxPduDescriptorPtr    Pointer to the descriptor of the PDU whose request counter will be increased.
 * \return       E_OK                  The PDU's request counter was successfully increased.
 * \return       E_NOT_OK              The PDU's request counter overflowed and was restored to its previous value.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \note         This function MUST be called within a critical section.
 * \ingroup      TX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_IncrementTxReqCounter(FRIF_VCLST_ONLY, 
                                            FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr);

/**********************************************************************************************************************
  FrIf_PrepareTxPdus()
**********************************************************************************************************************/
/*!
 *
 * \brief          Prepares the PDUs of Tx frames processed within Tx jobs.
 * \details        Assembles Tx frames by indicating the upper layers where to copy their PDUs within the frame buffer.
 * \param[in]      FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                       This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]      FrameDescriptorPtr    Pointer to the descriptor of the frame whose PDUs will be prepared.
 * \param[in,out]  FrameBuffer           Pointer to the buffer where the frame is being assembled. If DBA is disabled,
 *                                       the frame buffer is a static array defined by the FrIf. Otherwise, the buffer
 *                                       is provided by the Fr and a pointer to it is returned in this parameter.
 * \param[in,out]  CurrentPos            Pointer with the position-in-buffer before/after copying PDUs to the buffer.
 *                                       The pointer shall be dereferenced without any modifications.
 * \param[in,out]  PduUsage              Pointer to a group of flags indicating which PDUs-in-frame must be prepared.
 *                                       The pointer shall be dereferenced without any modifications.
 * \param[in,out]  FrameLayoutElIndex    Pointer to the first frame layout element of the frame being processed. The
 *                                       pointer shall be dereferenced without any modifications.
 * \param[in,out]  FrameDirty            Pointer to a flag indicating if the frame being processed must be transmitted.
 *                                       The pointer shall be dereferenced without any modifications.
 * \param[in]      Handle                Handle of the frame being processed.
 * \return         E_OK                  PDUs were successfully copied to the buffer.
 * \return         E_NOT_OK              A frame buffer couldn't be successfully requested (only if DBA is enabled).
 * \pre            -
 * \context        TASK|ISR
 * \reentrant      FALSE
 * \synchronous    TRUE
 * \ingroup        TX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(boolean, FRIF_CODE) FrIf_PrepareTxPdus(FRIF_VCLST_ONLY,
                                            FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                            P2VAR(uint8*, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer,
                                            P2VAR(uint8_least, AUTOMATIC, FRIF_VAR_NOINIT) CurrentPos,
                                            P2VAR(FrIf_NumberOfPduType, AUTOMATIC, FRIF_VAR_NOINIT) PduUsage,
                                            P2VAR(uint16_least, AUTOMATIC, FRIF_VAR_NOINIT) FrameLayoutElIndex,
                                            P2VAR(boolean, AUTOMATIC, FRIF_VAR_NOINIT) FrameDirty,
                                            uint16 Handle);

/**********************************************************************************************************************
  FrIf_PrepareFrameBuffer()
**********************************************************************************************************************/
/*!
 *
 * \brief          Finishes preparing the buffer of Tx frames processed within Tx jobs.
 * \details        Finalizes the buffer of the frames being processed by adding PDU update-bits and padding as required.
 * \param[in]      FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                       This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]      FrameDescriptorPtr    Pointer to the descriptor of the frame whose buffer will be prepared.
 * \param[in,out]  FrameBuffer           Pointer to the buffer where the frame is being assembled. If DBA is disabled,
 *                                       the frame buffer is a static array defined by the FrIf. Otherwise, the buffer
 *                                       is provided by the Fr and a pointer to it is returned in this parameter.
 * \param[in,out]  CurrentPos            Pointer with the position-in-buffer before/after finalizing the buffer. The
 *                                       pointer shall be dereferenced without any modifications.
 * \param[in]      PduUsage              Pointer to a group of flags indicating which PDUs-in-frame have been updated.
 *                                       The pointer shall be dereferenced without any modifications.
 * \param[in]      FrameLayoutElIndex    Pointer to the last frame layout element of the frame being processed. The
 *                                       pointer shall be dereferences without any modifications.
 * \param[in]      Handle                Handle of the frame being processed. It shall be used as array index without
 *                                       any modifications.
 *                                       Expected range: [0, (size of FrIf_TxPduWasSentFlags[] - 1)]
 * \param[in]      txFrameConfig         Group of flags indicating the configuration of the frame being processed.
 * \return         E_OK                  The frame buffer has been successfully prepared.
 * \return         E_NOT_OK              A frame buffer couldn't be successfully requested (only if DBA is enabled).
 * \pre            FrIf_PrepareTxPdus() has been successfully called.
 * \context        TASK|ISR
 * \reentrant      FALSE
 * \synchronous    TRUE
 * \ingroup        TX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_PrepareFrameBuffer(FRIF_VCLST_ONLY, 
                                            FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                            P2VAR(uint8*, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer,
                                            P2VAR(uint8_least, AUTOMATIC, FRIF_VAR_NOINIT) CurrentPos,
                                            P2VAR(FrIf_NumberOfPduType, AUTOMATIC, FRIF_VAR_NOINIT) PduUsage,
                                            P2VAR(uint16_least, AUTOMATIC, FRIF_VAR_NOINIT) FrameLayoutElIndex,
                                            uint16 Handle,
                                            uint8 txFrameConfig);

/**********************************************************************************************************************
  FrIf_TxRollback()
**********************************************************************************************************************/
/*!
 *
 * \brief        Rolls back the required counters and flags after a failed transmission.
 * \details      Restores the request counters and dirty flags of the PDUs-in-frame to their previous state, if the
 *               transmission of a frame fails.
 * \param[in]    FrIf_ClstIdx          Index of the cluster to be addressed. 
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrameDescriptorPtr    Pointer to the descriptor of the frame being rolled back.
 * \param[in]    Handle                Handle of the frame being rolled back. It shall be used as array index without
 *                                     any modifications.
 *                                     Expected range: [0, (size of FrIf_TxPduWasSentFlags[] - 1)]
 * \pre          FrIf_PrepareFrameBuffer() has been successfully called.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      TX
 *********************************************************************************************************************/
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_TxRollback(FRIF_VCLST_ONLY, FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                            uint16 Handle);

/**********************************************************************************************************************
 *  FrIf_IncrementTxReqCounter()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FRIF_LOCAL_INLINE FUNC (Std_ReturnType, FRIF_CODE) FrIf_IncrementTxReqCounter(FRIF_VCLST_ONLY, 
                                            FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If request counters are enabled and the PDU given as input has one:
   *       Retrieve and increase the counter.
   */
#if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
  if((TxPduDescriptorPtr->PduConfig & FrIf_TxPduHasTxRequestCounter) == FrIf_TxPduHasTxRequestCounter)
  {
    const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;
    FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, TxReqCounterIndex)++;                            /* SBSW_FRIF_REQUEST_COUNTER_WRT1 */

    /* #20 If an overflow occurred (COM could have called FrIf_Transmit faster than the job list execution):
     *       Set the counter to the initial value and set E_NOT_OK as return value.
     */
    if(FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, TxReqCounterIndex) == 0)
    {
      FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, TxReqCounterIndex)--;                          /* SBSW_FRIF_REQUEST_COUNTER_WRT1 */
      retVal = E_NOT_OK;
    }
  }
#else
  FRIF_DUMMY_STATEMENT(TxPduDescriptorPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
  return retVal;
} /* FrIf_IncrementTxReqCounter() */

/**********************************************************************************************************************
 * FrIf_TxConfirmation()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_TxConfirmation(FRIF_VCLST_ONLY, FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                                                        uint16 Handle)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least FrameLayoutElIndex = FrameDescriptorPtr->FirstFrameLayoutElementHandle;
  sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
  FrIf_NumberOfPduType PduUsage = FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle); /* Flag of the last PDU-in-frame in LSB */
  FrIf_NumberOfPduType FrIf_Mask = (FrIf_NumberOfPduType) (1 << PduNumber); /* Start from the MSB */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Flag all the PDUs-in-frame as non-sent. */
  FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) = 0;                                                /* SBSW_FRIF_SENT_FLAGS_WRT1 */

  /* #20 For each PDU-in-frame:
   *       If the PDU has been flagged as sent and Tx confirmations are configured for it:
   *         Call the TxConfirmation function provided by the PDU owner, using the PDU's upper layer ID as argument. \trace SPEC-8510
   */
  for(; PduNumber >= (sint16_least) 0; PduNumber--)
  {
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = 
                      &FrIf_GetTxPduDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxPduId(FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, FrameLayoutElIndex).PduHandle));

    if (((PduUsage & FrIf_Mask) != 0) && ((TxPduDescriptorPtr->PduConfig & FrIf_TxPduIsTxConfirmation) == FrIf_TxPduIsTxConfirmation))
    {
      FrIf_TxConfirmationFunctions(TxPduDescriptorPtr->PduConfig & FrIf_TxPduOwner, TxPduDescriptorPtr->UpperLayerPduId);
    }

    FrIf_Mask >>= 1u;
    FrameLayoutElIndex++;
  }  
} /* FrIf_TxConfirmation() */

/**********************************************************************************************************************
 *  FrIf_PrepareTxPdus()
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
 */
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_PrepareTxPdus(FRIF_VCLST_ONLY, /* PRQA S 3673 */ /* MD_FrIf_3673 */
                             FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                             P2VAR(uint8*, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer, 
                             P2VAR(uint8_least, AUTOMATIC, FRIF_VAR_NOINIT) CurrentPos, 
                             P2VAR(FrIf_NumberOfPduType, AUTOMATIC, FRIF_VAR_NOINIT) PduUsage,
                             P2VAR(uint16_least, AUTOMATIC, FRIF_VAR_NOINIT) FrameLayoutElIndex,
                             P2VAR(boolean, AUTOMATIC, FRIF_VAR_NOINIT) FrameDirty,
                             uint16 Handle)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
  Std_ReturnType TriggerResult = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each PDU-in-frame: */
  for(; PduNumber >= (sint16_least) 0; PduNumber--)
  {
    const PduIdType FrTxPduId = FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, *FrameLayoutElIndex).PduHandle;
    const uint8_least byteOffsetInFrame = FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, *FrameLayoutElIndex).ByteOffsetInFrame;
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxPduId(FrTxPduId));
    uint8 txPduConfig = TxPduDescriptorPtr->PduConfig;
    boolean PduIsDirty = FALSE;
    *PduUsage <<= 1u;                                                                 /* SBSW_FRIF_PTR_WRT_UNCHANGED */

    /* #20 Check if the PDU has been flagged as dirty (the upper layer has requested a transmission). */
#if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
    PduIsDirty = FrIf_GetTxPduDirtyByte(FRIF_VCLST_IDX, FrTxPduId);
#else
    PduIsDirty = (boolean) FrIf_GetBit(FrIf_GetTxPduDirtyBits(FRIF_VCLST_IDX), FrTxPduId);
#endif

    /* #30 If request counters are enabled and the PDU has one:
     *       Enter FrIf_FRIF_EXCLUSIVE_AREA_0.
     *       If the request counter is greater than 0 and no Tx confirmation is pending for the frame:
     *         Decrease the request counter and consider the PDU to be dirty.
     *       Exit FrIf_FRIF_EXCLUSIVE_AREA_0.
     */
#if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
    if((txPduConfig & FrIf_TxPduHasTxRequestCounter) == FrIf_TxPduHasTxRequestCounter)
    {
      const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;
      SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /**
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
      if ((0 < FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, TxReqCounterIndex)) && (FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) == 0))
      {
        FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, TxReqCounterIndex)--;                        /* SBSW_FRIF_REQUEST_COUNTER_WRT2 */
        PduIsDirty = TRUE;
      }
      SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
#endif /* if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF) */

    /* #40 If the PDU is dirty or configured to always be transmitted: */
    if((PduIsDirty != FALSE) || ((txPduConfig & FrIf_TxPduIsTransmitAlways) == FrIf_TxPduIsTransmitAlways))
    {
      PduLengthType CurrentPduLength = TxPduDescriptorPtr->PduLength;

      /* #50 If DBA is enabled and the PDU is the first dirty PDU-in-frame:
       *       Request a frame buffer (this happens once per frame and only if at least 1 PDU-in-frame has to be sent).
       */
#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
      if(*PduUsage == 0)
      {
        retVal = Fr_RequestBuffer_DBA(FRIF_VCLST_IDX,                                                /* SBSW_FRIF_FCT_CALL_PTRDBA */
                                      Handle,
                                      FrameBuffer,
                                      FrameDescriptorPtr->FrameLength);
        if(retVal == E_NOT_OK)
        {
          break; /* This happens only when the requested frame belongs to an identity currently not active in the Fr */
        }
      }
#endif

      /* #60 If required, initialize the bytes between the current position-in-buffer and the PDU's offset-in-frame. \trace SPEC-8322, SPEC-30021 */
      if(byteOffsetInFrame > *CurrentPos)
      {
        VStdLib_MemSet(&(*FrameBuffer)[*CurrentPos],                                /* SBSW_FRIF_FCT_CALL_FILLFRAME1 */
                       FRIF_FILL_PATTERN,
                       (uint8) (byteOffsetInFrame - *CurrentPos));
      }

      /* #70 Flag the PDU as non-dirty. */
#if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
      FrIf_GetTxPduDirtyByte(FRIF_VCLST_IDX, FrTxPduId) = FALSE;                                       /* SBSW_FRIF_DIRTY_BYTES_WRT1 */
#else
      SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      FrIf_ClearBit(FrIf_GetTxPduDirtyBits(FRIF_VCLST_IDX), FrTxPduId);                               /* SBSW_FRIF_DIRTY_BITS_WRT1 */
      SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif

      /* #80 Call the TriggerTransmit function provided by the PDU owner, using the PDU's upper layer ID and the buffer
       *     position where the payload should be written as arguments. \trace SPEC-8343
       */
      TriggerResult = FrIf_TriggerTransmitFunctions(txPduConfig & FrIf_TxPduOwner,
                                                    TxPduDescriptorPtr->UpperLayerPduId,
                                                    (&(*FrameBuffer)[byteOffsetInFrame]), /* SBSW_FRIF_FCT_CALL_TRIGGERTX */
                                                    &CurrentPduLength);

      /* #90 If the TriggerTransmit function was successfully called:
       *       Flag the frame containing the PDU as dirty.
       *       Flag the PDU as updated, so it's taken into account during subsequent Tx processing.
       *       Update the current position-in-buffer, so the payload doesn't get overwritten later.
       */
      if (TriggerResult == E_OK)
      {
        *FrameDirty = TRUE;                                                           /* SBSW_FRIF_PTR_WRT_UNCHANGED */
        *PduUsage |= 1u;                                                              /* SBSW_FRIF_PTR_WRT_UNCHANGED */
        *CurrentPos = (uint8_least)(byteOffsetInFrame + CurrentPduLength);            /* SBSW_FRIF_PTR_WRT_UNCHANGED */
      }
      /* If the TriggerTransmit function returns E_NOT_OK, the frame will still be processed, just as if the PDU were
       * not dirty at first
       */
    }
    (*FrameLayoutElIndex)++;                                                          /* SBSW_FRIF_PTR_WRT_UNCHANGED */
  }
  return retVal;
} /* FrIf_PrepareTxPdus() */ /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  FrIf_PrepareFrameBuffer()
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
FRIF_LOCAL_INLINE FUNC(Std_ReturnType, FRIF_CODE) FrIf_PrepareFrameBuffer(FRIF_VCLST_ONLY,  
                     FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                     P2VAR(uint8*, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer, 
                     P2VAR(uint8_least, AUTOMATIC, FRIF_VAR_NOINIT) CurrentPos, 
                     P2VAR(FrIf_NumberOfPduType, AUTOMATIC, FRIF_VAR_NOINIT) PduUsage,
                     P2VAR(uint16_least, AUTOMATIC, FRIF_VAR_NOINIT) FrameLayoutElIndex,
                     uint16 Handle,
                     uint8 txFrameConfig)
{
  Std_ReturnType retVal = E_OK;

  /* #10 If DBA is enabled and the frame is configured to always be transmitted, but none of the PDUs-in-frame has
   *     been flagged as updated:
   *       Request a frame buffer (no PDU has a new payload, so the buffer wasn't requested during PDU preparation).
   */
#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
  if((*PduUsage) == 0)
  {
    if(E_NOT_OK == Fr_RequestBuffer_DBA(FRIF_VCLST_IDX,                                              /* SBSW_FRIF_FCT_CALL_PTRDBA */
                                        Handle,
                                        FrameBuffer,
                                        FrameDescriptorPtr->FrameLength))
    {
      retVal = E_NOT_OK;
    }
  }
  if (retVal == E_OK)
#endif

  /* #20 If a frame buffer is available: */
  {
    /* #30 If dynamic L-SDU length is not configured for the frame, initialize the bytes at the end of the frame. \trace SPEC-8322, SPEC-30021 */
    if(*CurrentPos < FrameDescriptorPtr->FrameLength)
    {
      if((txFrameConfig & FrIf_FrameIsDynamicLSduLength) == FALSE)
      {
        VStdLib_MemSet(&(*FrameBuffer)[*CurrentPos],                                /* SBSW_FRIF_FCT_CALL_FILLFRAME2 */
                       FRIF_FILL_PATTERN,
                       (uint8) (FrameDescriptorPtr->FrameLength - *CurrentPos));

        *CurrentPos = FrameDescriptorPtr->FrameLength;                                /* SBSW_FRIF_PTR_WRT_UNCHANGED */
      }
    }

    /**
     * Internal comment removed.
 *
 *
 *
 *
 *
     */
    /* #40 Flag the updated PDUs-in-frame as sent. */
    FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) = *PduUsage;                                      /* SBSW_FRIF_SENT_FLAGS_WRT1 */

    /* #50 If at least one of the PDUs-in-frame has an update-bit:
     *       For each PDU-in-frame:
     *         Determine the position-in-buffer of the PDU's update-bit, and set it if the PDU has been updated.
     */
    if((txFrameConfig & FrIf_FrameHasPduWithUpdateBit) == FrIf_FrameHasPduWithUpdateBit)
    {
      sint16_least PduNumber = (sint16_least)FrameDescriptorPtr->NumberOfPdus - 1;
#if (FRIF_UNIFORMUPDATEBYTEPOS == STD_ON)
# if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
      const uint8_least updateBitBytePos = FrIf_GetUpdateBitBytePos();
# else
      const uint8_least updateBitBytePos = FrameDescriptorPtr->UpdateBitBytePos;
# endif
      (*FrameBuffer)[updateBitBytePos] = 0;                                             /* SBSW_FRIF_UPDATE_BITS_WRT */
#endif
      (*FrameLayoutElIndex)--;                                                        /* SBSW_FRIF_PTR_WRT_UNCHANGED */
      for(; PduNumber >= (sint16_least) 0; PduNumber--)
      {
        const uint8 updateBitMask = FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, *FrameLayoutElIndex).UpdateBitMask;
        if(updateBitMask != (uint8_least) 0 )
        {
#if (FRIF_UNIFORMUPDATEBYTEPOS == STD_OFF)
          const uint8_least updateBitBytePos = FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, *FrameLayoutElIndex).UpdateBitBytePos;

          if((*PduUsage & (uint16) 0x01) == (uint16) 0)
          {
            (*FrameBuffer)[updateBitBytePos] &= (uint8) ~updateBitMask;                 /* SBSW_FRIF_UPDATE_BITS_WRT */
          }
#endif
          if((*PduUsage & (uint16) 0x01) != (uint16) 0 )
          {
            (*FrameBuffer)[updateBitBytePos] |= updateBitMask;                          /* SBSW_FRIF_UPDATE_BITS_WRT */
          }
        }
        *PduUsage >>= 1u;                                                             /* SBSW_FRIF_PTR_WRT_UNCHANGED */
        (*FrameLayoutElIndex)--;                                                      /* SBSW_FRIF_PTR_WRT_UNCHANGED */
      }
    }
  }
  return retVal;
} /* FrIf_PrepareFrameBuffer() */ /* PRQA S 6060, 6080, 6030 */ /* MD_MSR_STPAR */ /* MD_MSR_STMIF */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
 *  FrIf_TxRollback()
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
 */
FRIF_LOCAL_INLINE FUNC(void, FRIF_CODE) FrIf_TxRollback(FRIF_VCLST_ONLY, FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                                    uint16 Handle)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
  uint16_least FrameLayoutElIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle + PduNumber);
  FrIf_NumberOfPduType PduUsage = FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter FRIF_EXCLUSIVE_AREA_0. */
  SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #20 For each PDU-in-frame:
   *       If the PDU has been flagged as sent:
   *         Flag the PDU as dirty (the upper layer has requested a transmission).
   *         Increment the PDU's request counter.
   */
  for(; PduNumber >= (sint16_least) 0; PduNumber--)
  {
    const PduIdType FrTxPduId = FrIf_GetTxFrameLayoutElement(FRIF_VCLST_IDX, FrameLayoutElIndex).PduHandle;
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxPduId(FrTxPduId));
    
    if((PduUsage & (uint16) 0x01) != (uint16) 0)
    {
#if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
      FrIf_GetTxPduDirtyByte(FRIF_VCLST_IDX, FrTxPduId) = TRUE;                                        /* SBSW_FRIF_DIRTY_BYTES_WRT1 */
#else
      FrIf_SetBit(FrIf_GetTxPduDirtyBits(FRIF_VCLST_IDX), FrTxPduId);                                 /* SBSW_FRIF_DIRTY_BITS_WRT1 */
#endif
    (void)FrIf_IncrementTxReqCounter(FRIF_VCLST_IDX, TxPduDescriptorPtr);                       /* SBSW_FRIF_FCT_CALL_PTR2TXPDUDESC2 */
    }

    PduUsage >>= 1u;
    FrameLayoutElIndex--;
  }

  /* #30 Exit FRIF_EXCLUSIVE_AREA_0. */
  SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #40 Flag all the PDUs-in-frame as non-sent. */
  FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) = 0;                                                /* SBSW_FRIF_SENT_FLAGS_WRT1 */

} /* FrIf_TxRollback() */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrIf_TxConfTask()
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
 */
FUNC(void, FRIF_CODE) FrIf_TxConfTask(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  const uint8_least  MinJobNumber = FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber).MinTxConfJobNo;
  const uint8_least  MaxJobNumber = FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber).MaxTxConfJobNo;
  uint8_least JobNumber = MinJobNumber;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate through the range of jobs that contain Tx operations relevant to the current job (confirming-job): */
  for(; JobNumber <= MaxJobNumber; JobNumber++)
  {
    FRIF_P2CONSTCFG(FrIf_JobDescriptorType) JobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, JobNumber);

    if((JobDataPtr->JobConfig & FrIf_JobDataIsRxTask) == FALSE)
    {
      /* #20 Determine which columns of the communication matrix are relevant to the job being confirmed. */
      const uint16_least MaxColumn = JobDataPtr->MaxColumnNumber;
      uint16_least ColumnNumber = JobDataPtr->MinColumnNumber;
      uint8_least  cycleToConfirm;

      /* #30 If delayed Tx confirmations are supported and enabled for the job being confirmed: (Tx confirmations ALAP)
       *       If the confirming-job lies after the job being confirmed and its protected range:
       *         Consider the next cycle as the cycle to be confirmed.
       *       Otherwise:
       *         Consider the current local cycle as a the cycle to be confirmed.
       *     Otherwise: (Tx confirmations ASAP)
       *       If the confirming-job lies after the job being confirmed and its protected range:
       *         Consider the current cycle as the cycle to be confirmed.
       *       Otherwise:
       *         Consider the previous cycle as the cycle to be confirmed.
       */
#if (FRIF_DELAYEDTXCONFSUPPORT == STD_ON)
      if ((JobDataPtr->JobConfig & FrIf_JobIsConfirmedBeforeTx) == FrIf_JobIsConfirmedBeforeTx ) 
      {
        cycleToConfirm = (uint8_least)((JobNumber < FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber) ?
                                                    NEXT_CYCLE(FrIf_Status[FRIF_VCLST_IDX].CurrentCycle) : FrIf_Status[FRIF_VCLST_IDX].CurrentCycle);
      }
      else
#endif
      {
        cycleToConfirm = (uint8_least)((JobNumber < FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber) ?
                                                    FrIf_Status[FRIF_VCLST_IDX].CurrentCycle : PREVIOUS_CYCLE(FrIf_Status[FRIF_VCLST_IDX].CurrentCycle));
      }

      /* #40 For each column relevant to the job being confirmed: */
      for(; ColumnNumber <= MaxColumn; ColumnNumber++)
      {
        /* #50 Retrieve the frame handle stored at the row corresponding to the cycle to be confirmed. */
        const uint16 Handle = FrIf_GetTxColumn(FRIF_VCLST_IDX, ColumnNumber)[cycleToConfirm & FrIf_GetTxCycleMask(FRIF_VCLST_IDX, ColumnNumber)];

        /* #60 If the frame handle is valid, retrieve the frame's descriptor. */
        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr;
        if (Handle != FrIf_GetInvalidTxHandle(FRIF_VCLST_IDX))
        {
          FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxLPduIdx(FRIF_VCLST_IDX, Handle));
        }
        else
        {
          FrameDescriptorPtr = NULL_PTR;
        }

        /* #70 If at least one of the PDUs-in-frame requires confirmations and has been flagged as sent (non-confirmed):
         *       Retrieve the frame's Tx status from the Fr.
         *       If the check succeeds and the status is FR_TRANSMITTED (any of them if redundancy is enabled):
         *         Confirm the required PDUs-in-frame and flag all the PDUs-in-frame as non-sent (confirmed).
         *       Otherwise, if the status check failed (both of them if redundancy is enabled):
         *         Don't confirm any PDU-in-frame and flag all the PDUs-in-frame as non-sent.
         *       Otherwise:
         *         Don't confirm any PDU-in-frame and leave the flags unchanged (a confirmation should happen later).
         */
        if (   (FrameDescriptorPtr != NULL_PTR)
            && (FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) != FALSE)
            && ((FrameDescriptorPtr->FrameConfig & FrIf_FrameIsTxConfirmation) == FrIf_FrameIsTxConfirmation)
           )
        {
          Fr_TxLPduStatusType TxLPduStatus;
          Std_ReturnType retVal = Fr_CheckTxLPduStatus(FRIF_VCLST_IDX, Handle, &TxLPduStatus);    /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */

#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
          /* This redundant Tx confirmation method is reliable as long as both frames are successfully requested for
           * transmission (i.e., Fr_TransmitTxLPdu returns E_OK for both frames and the TxLPduStatus of both frames is
           * initially switched to FR_NOT_TRANSMITTED). Fr_TransmitTxLPdu returns E_NOT_OK only when invalid parameters
           * are given as input.
           */
          if (((retVal == E_NOT_OK) || (TxLPduStatus == FR_NOT_TRANSMITTED)) && (FrameDescriptorPtr->FrameHandle != FrIf_GetInvalidTxHandle(FRIF_VCLST_IDX)))
          {
            retVal &= Fr_CheckTxLPduStatus(FRIF_VCLST_IDX, FrameDescriptorPtr->FrameHandle, &TxLPduStatus); /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
          }
#endif /* (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON) */

          if ((retVal == E_OK) && (TxLPduStatus == FR_TRANSMITTED))
          {
            FrIf_TxConfirmation(FRIF_VCLST_IDX, FrameDescriptorPtr, Handle);                   /* SBSW_FRIF_FCT_CALL_PTR2TXFRAMEDESC */
          }
          else if(retVal == E_NOT_OK)
          {
            /* The FrIf shall not keep polling the TxLPduStatus. In case of buffer reconfiguration, it could happen
             * that the FrIf keeps polling the TxLPduStatus until the frame is transmitted again, but the frame might
             * never be transmitted. The Fr reconfigures the message buffers on each Fr_TransmitTxLPdu call. If a frame
             * has been requested for transmission, gets preempted and then another frame sharing the message buffer is
             * requested, the message buffer will be reconfigured and the information will be lost. It's OK not to give
             * a Tx confirmation, since the data was never transmitted. If the Fr_CheckTxLPduStatus is called for the
             * preempted frame before a new reconfiguration, the Fr will return E_NOT_OK.
             */
            FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) = 0;                                      /* SBSW_FRIF_SENT_FLAGS_WRT1 */
          }
          else
          {
              /* Do nothing. The confirmation should happen later. */
          }
        }
      }
    }
  }
} /* FrIf_TxConfTask() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  FrIf_TxTask()
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
 */
FUNC(void, FRIF_CODE) FrIf_TxTask(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  
  /* #10 Determine which columns of the communication matrix are relevant to the current job. */
  FRIF_P2CONSTCFG(FrIf_JobDescriptorType) JobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);  
  const uint16_least MaxColumn = JobDataPtr->MaxColumnNumber;
  uint16_least ColumnNumber = JobDataPtr->MinColumnNumber;
  
  /* ----- Implementation ----------------------------------------------- */
  /* #20 For each relevant column: */
  for(; ColumnNumber <= MaxColumn; ColumnNumber++)
  {
    /* #30 Retrieve the frame handle stored at the row corresponding to the current local cycle. */
    const uint16 Handle = FrIf_GetTxColumn(FRIF_VCLST_IDX, ColumnNumber)[FrIf_Status[FRIF_VCLST_IDX].CurrentCycle & FrIf_GetTxCycleMask(FRIF_VCLST_IDX, ColumnNumber)];

    /* #35 If the frame handle is valid, retrieve the frame's configuration.
     *     Otherwise, set the frame configuration as an immediate Tx frame, to avoid any further processing.
     */
    uint8 txFrameConfig;
    if (Handle != FrIf_GetInvalidTxHandle(FRIF_VCLST_IDX))
    {
      txFrameConfig = FrIf_GetTxFrameDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxLPduIdx(FRIF_VCLST_IDX, Handle)).FrameConfig;
    }
    else
    {
      txFrameConfig = FrIf_FrameIsImmediateTx; /* Immediate Tx frames are ignored within the TxTask */
    }

    /* #40 If the frame doesn't contain any PDU configured as immediate: */
    if ((txFrameConfig & FrIf_FrameIsImmediateTx) == FALSE)
    {
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxLPduIdx(FRIF_VCLST_IDX, Handle));
      P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer = NULL_PTR;
      uint16_least FrameLayoutElIndex = FrameDescriptorPtr->FirstFrameLayoutElementHandle;
      FrIf_NumberOfPduType PduUsage = 0;
      uint8_least CurrentPos = 0;

      /* #50 If the frame is configured to always be transmitted, flag it as dirty (a transmission must be requested
       *     to the Fr).
       */
      boolean FrameDirty = (boolean) ((txFrameConfig & FrIf_FrameIsTransmitAlways) == FrIf_FrameIsTransmitAlways);

      /* If DBA is disabled, a local temporary frame buffer will be used, so initialize it. */
#if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF)
      /* PRQA S 0310 2 */ /* MD_FrIf_0310 */
      FrameBuffer = FRIF_GET_FRAMEBUFFER(FRIF_VCLST_IDX);
      FRIF_INITIALIZE_FRAMEBUFFER_START(FRIF_VCLST_IDX);                                          /* SBSW_FRIF_FCT_CALL_FILLFRAME3 */
      CurrentPos = 4; /* First 4 bytes of the buffer are now initialized. */
#endif

      /* #60 Copy the payloads of the PDUs-in-frame with pending transmission requests to a temporary frame buffer.
       *     If at least one of the PDUs-in-frame was updated, flag the frame as dirty. \trace SPEC-8420 
       */
      retVal = FrIf_PrepareTxPdus(FRIF_VCLST_IDX, FrameDescriptorPtr,                          /* SBSW_FRIF_FCT_CALL_PTR2TXFRAMEDESC */
                                  &FrameBuffer, &CurrentPos, &PduUsage,              /* SBSW_FRIF_FCT_CALL_BUFFRIFTX */
                                  &FrameLayoutElIndex, &FrameDirty, Handle);

      /* #70 If the frame has been flagged as dirty: */
      if((retVal == E_OK) && (FrameDirty == TRUE)) /* COV_FRIF_DBA_BUFFER_REQUEST_FAILED */
      {
        /* #80 Flag the updated PDUs-in-frame as sent (non-confirmed).
         *     Add the update-bits related to the processed PDUs to the temporary frame buffer.
         */
        retVal = FrIf_PrepareFrameBuffer(FRIF_VCLST_IDX, FrameDescriptorPtr,                   /* SBSW_FRIF_FCT_CALL_PTR2TXFRAMEDESC */
                                         &FrameBuffer, &CurrentPos, &PduUsage,       /* SBSW_FRIF_FCT_CALL_BUFFRIFTX */
                                         &FrameLayoutElIndex, Handle, txFrameConfig);

        /* #90 If the temporary frame buffer was successfully prepared: */
        /* A rollback won't take place if retVal != E_OK */ 
        if (retVal == E_OK) /* COV_FRIF_DBA_BUFFER_REQUEST_FAILED */
        {
          /* #92 Request the transmission of the frame to the Fr, using the prepared buffer as payload. */
          retVal = FrIf_TransmitFrameBuffer(FRIF_VCLST_IDX,            /* SBSW_FRIF_FCT_CALL_BUFFRTX */
                                            Handle,
                                            FrameBuffer,
                                            (uint8)CurrentPos);

          /* #94 If redundancy is enabled and the current frame has a redundant match: */
#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
          if(FrameDescriptorPtr->FrameHandle != FrIf_GetInvalidTxHandle(FRIF_VCLST_IDX))
          {
            /* If DBA is enabled, request a 2nd temporary frame buffer and copy the prepared buffer there */
# if (FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
            Std_ReturnType bufferStatus = E_NOT_OK;
            P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) FrameBufferToCopy = FrameBuffer;
            bufferStatus = Fr_RequestBuffer_DBA(FRIF_VCLST_IDX,                                   /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
                                                FrameDescriptorPtr->FrameHandle,
                                                &FrameBuffer,
                                                FrameDescriptorPtr->FrameLength);
            if (bufferStatus == E_OK)
            {
              VStdLib_MemCpy(FrameBuffer, FrameBufferToCopy, (uint8)(CurrentPos));     /* SBSW_FRIF_FCT_CALL_REDCOPY */
            }
            
            if(bufferStatus == E_OK)
# endif
            /* #96 Request the transmission of the redundant frame to the Fr, using the prepared buffer as payload. */
            {
              retVal &= FrIf_TransmitFrameBuffer(FRIF_VCLST_IDX,       /* SBSW_FRIF_FCT_CALL_BUFFRTX */
                                                 FrameDescriptorPtr->FrameHandle,
                                                 FrameBuffer,
                                                 (uint8)CurrentPos);
            } 
          } 
#endif
          /* #98 If the transmission request fails (both of them if redundancy is enabled):
           *        Roll back the modified counters and flags.
           */
          if(retVal == E_OK)
          {
            /* This macro can be defined for debugging */
#if defined (FRIF_FRAME_TRANSMITTED) /* COV_FRIF_TESTSUITE_INSTRUMENTATION */
            FRIF_FRAME_TRANSMITTED(Handle, FrameBuffer, FrIf_GetTxFrameDescriptor(FRIF_VCLST_IDX, Handle).FrameLength);
#endif
          }
          else
          {
            FrIf_TxRollback(FRIF_VCLST_IDX, FrameDescriptorPtr, Handle);                       /* SBSW_FRIF_FCT_CALL_PTR2TXFRAMEDESC */
          }
        }
      }
    }
  }
} /* FrIf_TxTask() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  FrIf_Transmit()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_Transmit(PduIdType FrTxPduId, 
                                              FRIF_P2CONSTAPPLDATA(PduInfoType) PduInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 If error detection is enabled:
   *       Check that the FrIf is initialized. \trace SPEC-29911
   *       Check the validity of FrTxPduId. \trace SPEC-30065
   *       Check the validity of PduInfoPtr. \trace SPEC-30009
   *       Check the validity of PduInfoPtr->SduDataPtr. \trace SPEC-30131
   */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  else if (FrIf_IsFrTxPduIdInvalid(FrTxPduId))
  {
    errorId = FRIF_E_INV_TXPDUID;
  }
  else if ((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = FRIF_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 If the initial checks are passed or not required, and the cluster related to the PDU is online: */
#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
    uint8 FrIf_ClstIdx = FrIf_GetClusterIndex(FrTxPduId);
#endif
    if (FrIf_IsOnline(FRIF_VCLST_IDX))
    {
      FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FRIF_VCLST_IDX, FrIf_GetInternalTxPduId(FrTxPduId));

      /* #30 If the PDU is configured as immediate: \trace SPEC-29989
       *       Retrieve the handle of the frame containing the PDU.
       *       Request the transmission of the frame to the Fr, using the data from PduInfo as arguments. \trace SPEC-29966
       *       If the transmission request succeeds, flag the PDU as sent (non-confirmed).
       */
      if((TxPduDescriptorPtr->PduConfig & FrIf_TxPduIsImmediateTx) == FrIf_TxPduIsImmediateTx)
      {
        /* In non-variant configurations, the ID of the immediate PDUs is always the same as the handle of the frames
         * that contain them. The sorting done by the FrIf generator guarantees it.
         */
        const uint16 Handle = FrIf_GetTxFrameHandle(FRIF_VCLST_IDX, FrTxPduId);

        /* It's OK to give the Fr the PDU length given by the upper layer without any padding, because the generator
         * guarantees that immediate PDUs are contained in frames configured with dynamic length.
         */
        retVal = FrIf_TransmitTxLPdu(FRIF_VCLST_IDX,                    /* SBSW_FRIF_FCT_CALL_PTRFWD */
                                     Handle,
                                     PduInfoPtr->SduDataPtr,
                                     (uint8)PduInfoPtr->SduLength); /* Avoid warning if PduLengthType != uint8 */

        if(retVal == E_OK)
        {
           /* Immediate PDUs don't share frames with other PDUs. */
           FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, Handle) = 0x01u;                                   /* SBSW_FRIF_SENT_FLAGS_WRT2 */
        }
      }
      /* #40 Otherwise: (the transmission request will occur within the job list execution)
       *       Enter FrIf_FRIF_EXCLUSIVE_AREA_0.
       *       Flag the PDU as dirty (the upper layer has requested a transmission).
       *       Increment the PDU's request counter.
       *       Exit FrIf_FRIF_EXCLUSIVE_AREA_0.
       */
      else
      {
        SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
        FrIf_GetTxPduDirtyByte(FRIF_VCLST_IDX, FrTxPduId) = TRUE;                                      /* SBSW_FRIF_DIRTY_BYTES_WRT2 */
#else
        FrIf_SetBit(FrIf_GetTxPduDirtyBits(FRIF_VCLST_IDX), FrTxPduId);                               /* SBSW_FRIF_DIRTY_BITS_WRT2 */
#endif
        retVal = FrIf_IncrementTxReqCounter(FRIF_VCLST_IDX, TxPduDescriptorPtr);                /* SBSW_FRIF_FCT_CALL_PTR2TXPDUDESC1 */

        SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
    }
  } 
  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_TRANSMIT, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_Transmit() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Tx.c
 *********************************************************************************************************************/
