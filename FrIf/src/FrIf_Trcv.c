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
/**        \file  FrIf_Trcv.c
 *        \brief  FrIf Trcv source file
 *
 *      \details  Implementation of the transceiver handling according to:
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

#define FRIF_TRCV_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"        /* for GET_TRANSCEIVER_INDEX */
#include "FrIf_Cbk.h"         /* for FrIf_Cbk_WakeupByTransceiver declaration to prevent  MISRA-C:2004 8.8 violation */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrIf.h */
# if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
     || (FRIF_SW_MINOR_VERSION != (1u)) \
     || (FRIF_SW_PATCH_VERSION != (2u)) )
#  error "Version numbers of FrIf_Trcv.c and FrIf.h are inconsistent"
# endif

/* Check the version of FrIf_Cbk.h */
# if (  (FRIF_CBK_MAJOR_VERSION != (5u)) \
     || (FRIF_CBK_MINOR_VERSION != (1u)) \
     || (FRIF_CBK_PATCH_VERSION != (2u)) )
#  error "Version numbers of FrIf_Trcv.h and FrIf_Cbk.h are inconsistent"
# endif

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_USE_FRTRCV_API == STD_ON)
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrIf_SetTransceiverMode()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetTransceiverMode(FRIF_VCTRL_ONLY,
                                                       Fr_ChannelType       FrIf_ChnlIdx,
                                                       FrTrcv_TrcvModeType  FrIf_TrcvMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29843 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30128 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30068 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_SetTransceiverMode for the FrTrcv associated to the channel given as input. \trace SPEC-29916 */
    /* SPEC-29916 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_SetTransceiverMode(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_TrcvMode) == BUSTRCV_E_OK) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_SETTRANSCEIVERMODE, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_SetTransceiverMode() */

/**********************************************************************************************************************
 *  FrIf_GetTransceiverMode()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverMode(FRIF_VCTRL_ONLY,
                                            Fr_ChannelType FrIf_ChnlIdx,
                                            P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvModePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30064 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29939 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-29871 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_GetTransceiverMode for the FrTrcv associated to the channel given as input. \trace SPEC-30085 */
    /* SPEC-30085 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_GetTransceiverMode(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_TrcvModePtr) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETTRANSCEIVERMODE, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetTransceiverMode() */

/**********************************************************************************************************************
 *  FrIf_GetTransceiverWUReason()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverWUReason(FRIF_VCTRL_ONLY,
                                       Fr_ChannelType FrIf_ChnlIdx,
                                       P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvWUReasonPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30127 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30080 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30133 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_GetTransceiverWUReason for the FrTrcv associated to the channel given as input. \trace SPEC-30143 */
    /* SPEC-30143 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_GetTransceiverWUReason(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_TrcvWUReasonPtr) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETTRANSCEIVERWUREASON, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetTransceiverWUReason() */

/**********************************************************************************************************************
 *  FrIf_EnableTransceiverBranch()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableTransceiverBranch(FRIF_VCTRL_ONLY,
                                                            Fr_ChannelType FrIf_ChnlIdx,
                                                            uint8          FrIf_BranchIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29941 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30017 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30135 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_EnableTransceiverBranch for the FrTrcv associated to the channel given as input. \trace SPEC-29860 */
    /* SPEC-29860 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_EnableTransceiverBranch(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_BranchIdx) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ENABLETRANSCEIVERWAKEUP, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_EnableTransceiverBranch() */

/**********************************************************************************************************************
 *  FrIf_DisableTransceiverBranch()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableTransceiverBranch(FRIF_VCTRL_ONLY,
                                                             Fr_ChannelType FrIf_ChnlIdx,
                                                             uint8          FrIf_BranchIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30155 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29875 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-29839 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_DisableTransceiverBranch for the FrTrcv associated to the channel given as input. \trace SPEC-30070 */
    /* SPEC-30070 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_DisableTransceiverBranch(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_BranchIdx) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_DISABLETRANSCEIVERWAKEUP, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_DisableTransceiverBranch() */

/**********************************************************************************************************************
 *  FrIf_ClearTransceiverWakeup()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_ClearTransceiverWakeup(FRIF_VCTRL_ONLY,
                                                           Fr_ChannelType FrIf_ChnlIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29890 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30201 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30069 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_ClearTransceiverWakeup for the FrTrcv associated to the channel given as input. \trace SPEC-30184 */
    /* SPEC-30184 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_ClearTransceiverWakeup(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_CLEARTRANSCEIVERWAKEUP, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_ClearTransceiverWakeup() */

/**********************************************************************************************************************
 *  FrIf_GetTransceiverError()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverError(FRIF_VCTRL_ONLY,
                                                           Fr_ChannelType FrIf_ChnlIdx,
                                                           uint8 FrIf_BranchIdx,
                                                           P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_BusErrorState)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29856 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30140 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30022 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_GetTransceiverError for the FrTrcv associated to the channel given as input. \trace SPEC-30087 */
    /* SPEC-30087 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    if (FrTrcv_GetTransceiverError(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx), FrIf_BranchIdx, FrIf_BusErrorState) == BUSTRCV_E_OK ) /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
    {
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GET_TRANSCEIVER_ERROR, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetTransceiverError() */

/**********************************************************************************************************************
 *  FrIf_CheckWakeupByTransceiver()
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
 */
FUNC(void, FRIF_CODE) FrIf_CheckWakeupByTransceiver(uint8 FrIf_CtrlIdx,
                                                    Fr_ChannelType FrIf_ChnlIdx )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29893 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30061 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30040 */
  else if (   (FrIf_ChnlIdx >= FR_CHANNEL_AB)
           || (FrIf_GetTransceiverMapIdx(GET_TRANSCEIVER_INDEX(FRIF_VCTRL_IDX, FrIf_ChnlIdx)) >= FrIf_NumberOfFrTrcvs)
          )
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call FrTrcv_CheckWakeupByTransceiver for the FrTrcv associated to the channel given as input. \trace SPEC-30137 */
    /* SPEC-30137 Dev: Multiple FlexRay CCs are currently not supported, so no translation is required. */
    FrTrcv_CheckWakeupByTransceiver(GET_TRANSCEIVER_INDEX(FrIf_CtrlIdx, FrIf_ChnlIdx)); /* SBSW_FRIF_FCT_PTR_FRTRCVMAP */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_CBK_WAKEUPBYTRANSCEIVER, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* FrIf_CheckWakeupByTransceiver() */

#endif /* if defined ( FRIF_USE_FRTRCV_API ) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Trcv.c
 *********************************************************************************************************************/
