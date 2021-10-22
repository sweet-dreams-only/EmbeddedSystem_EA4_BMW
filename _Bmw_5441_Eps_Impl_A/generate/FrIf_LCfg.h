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
 *              File: FrIf_LCfg.h
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

/**        \file  FrIf_Lcfg.h
 *        \brief  FrIf link-time configuration header file
 *
 *      \details  Header file for the link-time configuration data of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *********************************************************************************************************************/

#if (!defined FRIF_L_CFG_H_)
# define FRIF_L_CFG_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */
#    define FRIF_GET_FRAMEBUFFER(ClstIdx)                 ((P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT))FrIf_Ctrl2FrameBuffer[(ClstIdx)])
#  define FRIF_INITIALIZE_FRAMEBUFFER_START(ClstIdx)     (((P2VAR(uint32, AUTOMATIC, FRIF_VAR_NOINIT))FRIF_GET_FRAMEBUFFER(ClstIdx))[0] = FRIF_FILL_PATTERN_DWORD)

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* declarations of the FrIf upperlayer wrapper functions */

/***********************************************************************************************************************
 *  FrIf_TriggerTransmitFunctions()
 **********************************************************************************************************************/
/*!
 *
 * \brief          Wraps the TriggerTransmit functions provided by the upper layer modules.
 * \details        Calls the right TriggerTransmit function, based on the PDU owner given as input.
 * \param[in]      PduOwner     Upper layer associated to the PDU being processed.
 * \param[in]      FrTxPduId    Upper layer id of the PDU being processed.
 * \param[in]      Payload      Pointer to the address where the PDU's payload shall be written.
 * \param[in,out]  Length       Pointer to the PDU's maximum configured length/Length of the payload actually copied by
 *                              the upper layer.
 * \return         E_OK         The TriggerTransmit function was successfully called.
 * \return         E_NOT_OK     The TriggerTransmit function wasn't successfully called.
 * \pre            -
 * \context        TASK|ISR
 * \synchronous    TRUE
 * \reentrant      FALSE
 * \ingroup        TX
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_TriggerTransmitFunctions(uint8 PduOwner,
                                               PduIdType FrTxPduId,
                                               P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload,
                                               P2VAR(PduLengthType, AUTOMATIC, FRIF_VAR_NOINIT) Length);

/***********************************************************************************************************************
 *  FrIf_RxIndicationFunctions()
 **********************************************************************************************************************/
/*!
 *
 * \brief        Wraps the RxIndication functions provided the upper layer modules.
 * \details      Calls the right RxIndication function, based on the PDU owner given as input.
 * \param[in]    PduOwner     Upper layer associated to the PDU being processed.
 * \param[in]    FrTxPduId    Upper layer id of the PDU being processed.
 * \param[in]    Payload      Pointer to the address where the received payload is stored.
 * \param[in]    Length       Length of the received payload.
 * \pre          -
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      RX
 **********************************************************************************************************************/
extern FUNC(void, FRIF_CODE) FrIf_RxIndicationFunctions(uint8 PduOwner,
                                               PduIdType FrRxPduId,
                                               P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload,
                                               PduLengthType Length);

/***********************************************************************************************************************
 *  FrIf_TxConfirmationFunctions()
 **********************************************************************************************************************/
/*!
 *
 * \brief        Wraps the TxConfirmation functions provided the upper layer modules.
 * \details      Calls the right TxConfirmation function, based on the PDU owner given as input.
 * \param[in]    PduOwner     Upper layer associated to the PDU being processed.
 * \param[in]    FrTxPduId    Upper layer id of the PDU being processed.
 * \pre          -
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      TX
 **********************************************************************************************************************/
extern FUNC(void, FRIF_CODE) FrIf_TxConfirmationFunctions(uint8 PduOwner, PduIdType FrTxPduId);

/***********************************************************************************************************************
 *  FrIf_CheckChannelStatus()
 **********************************************************************************************************************/
/*!
 *
 * \brief        Checks the status of the given FlexRay channel.
 * \details      Checks the given channel status information and reports errors as required.
 * \param[in]    FrChannel        FlexRay channel whose status will be checked.
 * \param[in]    ChannelStatus    Group of flags indicating the status of the FlexRay channel.
 * \pre          Fr_GetChannelStatus() has been successfully called.
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      Generic
 **********************************************************************************************************************/
extern FUNC(void, FRIF_CODE) FrIf_CheckChannelStatus(uint8 ClstIdx, Fr_ChannelType FrChannel, uint16 ChannelStatus);

# define FRIF_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* PRQA S 3684 DECLWITHOUTSIZE */ /* MD_FrIf_0812 */

     extern CONSTP2VAR(uint8, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduDirtyBits[];

     extern CONSTP2VAR(FrIf_NumberOfPduType, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduWasSentFlags[];

     extern CONSTP2VAR(uint32, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2FrameBuffer[];

# if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
     extern CONSTP2VAR(uint32, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2RedundantFrameBuffer[];
     extern CONSTP2VAR(PduInfoType, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2RedundantRxPduInfo[];
# endif

     extern CONSTP2VAR(uint8, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduTxRequestCounters[];

     extern VAR(PduInfoType, FRIF_VAR_NOINIT) FrIf_PduInfo;

# define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# define FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# define FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# define FRIF_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */


# if (FRIF_USE_FRTRCV_API == STD_ON)
     extern CONST(FrTrcv_SetTransceiverModeFctType, FRIF_CONST) FrTrcv_SetTransceiverModeFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_GetTransceiverModeFctType, FRIF_CONST) FrTrcv_GetTransceiverModeFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_GetTransceiverWUReasonFctType, FRIF_CONST) FrTrcv_GetTransceiverWUReasonFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_EnableTransceiverBranchFctType, FRIF_CONST) FrTrcv_EnableTransceiverBranchFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_DisableTransceiverBranchFctType, FRIF_CONST) FrTrcv_DisableTransceiverBranchFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_CheckWakeupByTransceiverFctType, FRIF_CONST) FrTrcv_CheckWakeupByTransceiverFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_GetTransceiverErrorFctType, FRIF_CONST) FrTrcv_GetTransceiverErrorFctMap[FrIf_NumberOfFrTrcvs];
     extern CONST(FrTrcv_ClearTransceiverWakeupFctType, FRIF_CONST) FrTrcv_ClearTransceiverWakeupFctMap[FrIf_NumberOfFrTrcvs];
# endif /* (FRIF_USE_FRTRCV_API == STD_ON) */

     extern CONST(FrIf_ConfigType, FRIF_CONST) FrIf_Config;
     extern CONST(FrIf_TransceiverDescriptorType, FRIF_CONST) FrIf_TransceiverDescriptors[];
     extern CONST(FrIf_TxPduTranslationTupleType, FRIF_CONST) FrIf_TxPduTranslationTable[];
     extern CONSTP2CONST(FrIf_TxPduDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxPduDescriptors[];
     extern CONSTP2CONST(FrIf_RxPduDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxPduDescriptors[];
     extern CONSTP2CONST(FrIf_FrameLayoutElementType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxFrameLayoutElements[];
     extern CONSTP2CONST(FrIf_FrameLayoutElementType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxFrameLayoutElements[];
     extern CONSTP2CONST(FrIf_FrameDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxFrameDescriptors[];
     extern CONSTP2CONST(FrIf_FrameDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxFrameDescriptors[];
     extern CONSTP2CONST(FrIf_JobDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Clst2JobDescriptors[];
     extern CONSTP2CONST(FrIf_TxHandlePtrType, FRIF_CONST, FRIF_CONST) FrIf_Clst2TxComHandleTable[];
     extern CONSTP2CONST(FrIf_RxHandlePtrType, FRIF_CONST, FRIF_CONST) FrIf_Clst2RxComHandleTable[];
     extern CONSTP2CONST(FrIf_CycleMaskType, FRIF_CONST, FRIF_CONST) FrIf_Clst2TxCycleMasks[];
     extern CONSTP2CONST(FrIf_CycleMaskType, FRIF_CONST, FRIF_CONST) FrIf_Clst2RxCycleMasks[];
     extern CONST(PduIdType, FRIF_CONST) FrIf_Ctrl2MaxTxPduId[];
     extern CONST(FrIf_TxHandleType, FRIF_CONST) FrIf_Ctrl2MaxTxFrameId[];
     extern CONST(PduIdType, FRIF_CONST) FrIf_Ctrl2NumberOfTxRequestCounters[];
     extern CONST(FrIf_TxHandleType, FRIF_CONST) FrIf_Ctrl2InvalidTxHandle[];
     extern CONST(FrIf_RxHandleType, FRIF_CONST) FrIf_Ctrl2InvalidRxHandle[];
     extern CONST(uint16, FRIF_CONST) FrIf_Clst2MacroTicksPerCycle[];
     extern CONST(uint16, FRIF_CONST) FrIf_Clst2MacroTickLengthInNanoSeconds[];
     extern CONST(uint8, FRIF_CONST) FrIf_Clst2NumberOfJobs[];

/* PRQA L:DECLWITHOUTSIZE */ /* MD_FrIf_0812 */

# if    (FRIF_CONFIGURATION_VARIANT != FRIF_CONFIGURATION_VARIANT_PRECOMPILE) \
     || (FRIF_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */

/*! \var The highest Tx PDU ID present among all the configuration variants. */
     extern CONST(uint16, FRIF_CONST) FrIf_CommonMaxTxPduId;

/*! \var The highest Tx frame ID present among all the configuration variants. */
     extern CONST(uint16, FRIF_CONST) FrIf_CommonMaxTxFrameId;

/*! \var The maximum length in bytes of tx and rx frames that can be used by any post-build configuration.
    This value is used to dimension the variable FrIf_FrameBuffer.
  */
     extern CONST(uint16, FRIF_CONST) FrIf_FramebufferLengthInBytes;
     /*! \var The highest number of Tx PDU request counters among all the configuration variants */
     extern CONST(uint16, FRIF_CONST) FrIf_CommonMaxNumberOfTxRequestCounters;

# endif

# if (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_LINKTIME)
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxPDUs;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxFLEs;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxFrames;
     extern CONST(PduIdType, FRIF_CONST) FrIf_InvalidTxPduHandle;
     extern CONST(uint8, FRIF_CONST) FrIf_NumberOfChannels;
#  if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
     extern CONST(uint8, FRIF_CONST) FrIf_UpdateBitBytePos;
#  endif
# endif/* (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_LINKTIME) */

# define FRIF_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#endif
/* FRIF_L_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Lcfg.h
 *********************************************************************************************************************/

