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
/**        \file  FrIf_AbsTimer.c
 *        \brief  FrIf Absolute Timer source file
 *
 *      \details  Implementation of the handling of absolute timers, according to:
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

#define FRIF_ABSTIMER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrIf.h */
#if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
    || (FRIF_SW_MINOR_VERSION != (1u)) \
    || (FRIF_SW_PATCH_VERSION != (2u)) )
# error "Version numbers of FrIf_Abstimer.c and FrIf.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_API_AS_MACRO == STD_OFF)
# if (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF)
/**********************************************************************************************************************
 *  FrIf_SetAbsoluteTimer()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetAbsoluteTimer(FRIF_VCTRL_ONLY, 
                                                     uint8   FrIf_AbsTimerIdx, 
                                                     uint8   FrIf_Cycle,
                                                     uint16  FrIf_Offset)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30192 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30193 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_SetAbsoluteTimer with the input parameters and untranslated CC index as arguments. \trace SPEC-30073 */
    /* SPEC-30073 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_SetAbsoluteTimer(
        FRIF_VCTRL_IDX, 
        FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx), 
        FrIf_Cycle,
        FrIf_Offset);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_SETABSOLUTETIMER, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_SetAbsoluteTimer() */

/**********************************************************************************************************************
 *  FrIf_CancelAbsoluteTimer()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelAbsoluteTimer(FRIF_VCTRL_ONLY, 
                                                        uint8  FrIf_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30178 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29891 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
    /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_CancelAbsoluteTimer with the given TimerIdx and untranslated CC index as arguments. \trace SPEC-29964 */
    /* SPEC-29964 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_CancelAbsoluteTimer(FRIF_VCTRL_IDX, FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_CANCELABSOLUTETIMER, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_CancelAbsoluteTimer() */

/**********************************************************************************************************************
 *  FrIf_EnableAbsoluteTimerIRQ()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                           uint8   FrIf_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30058 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29954 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_EnableAbsoluteTimerIRQ with the given TimerIdx and untranslated CC index as arguments. \trace SPEC-29940 */
    /* SPEC-29940 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_EnableAbsoluteTimerIRQ(FRIF_VCTRL_IDX, FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ENABLEABSOLUTETIMERIRQ, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_EnableAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  FrIf_DisableAbsoluteTimerIRQ()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                            uint8  FrIf_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29981 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29826 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_DisableAbsoluteTimerIRQ with the given TimerIdx and untranslated CC index as arguments */
    /* Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_DisableAbsoluteTimerIRQ(FRIF_VCTRL_IDX, FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_DISABLEABSOLUTETIMERIRQ, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_DisableAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  FrIf_AckAbsoluteTimerIRQ()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AckAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                        uint8   FrIf_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29988 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30147 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_AckAbsoluteTimerIRQ with the given TimerIdx and untranslated CC index as arguments. \trace SPEC-30092 */
    /* SPEC-30092 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_AckAbsoluteTimerIRQ(FRIF_VCTRL_IDX, FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ACKABSOLUTETIMERIRQ, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_AckAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  FrIf_GetAbsoluteTimerIRQStatus()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetAbsoluteTimerIRQStatus(FRIF_VCTRL_ONLY, 
                                                       uint8               FrIf_AbsTimerIdx, 
                                                       P2VAR(boolean, AUTOMATIC, FRIF_APPL_DATA) FrIf_IRQStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30190 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30200 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetAbsoluteTimerIRQStatus using the input parameters and untranslated CC index. \trace SPEC-29963 */
        /* SPEC-29963 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_GetAbsoluteTimerIRQStatus(                                              /* SBSW_FRIF_FCT_CALL_PTRFWD */
        FRIF_VCTRL_IDX, 
        FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx), 
        FrIf_IRQStatusPtr);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETABSOLUTETIMERIRQSTATUS, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetAbsoluteTimerIRQStatus() */
# endif /* if (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF) */
#endif /* if (FRIF_API_AS_MACRO == STD_OFF) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_AbsTimer.c
 *********************************************************************************************************************/
