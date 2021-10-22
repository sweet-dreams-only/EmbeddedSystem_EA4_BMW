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
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr_Timer.c
 *        \brief  FlexRay Driver Timer source file
 *
 *      \details  Implementation of AUTOSAR FlexRay Driver Timer Services according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
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

#define FR_TIMER_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0303 EOF */ /* MD_Fr_0306 */
/* PRQA S 1503 EOF */ /* MD_MSR_14.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fr_Priv.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

#if ( (FR_SW_MAJOR_VERSION != 0x5u) || (FR_SW_MINOR_VERSION != 0x00u) || (FR_SW_PATCH_VERSION != 0x01u) )
# error "Fr_Timer.c: Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/**************************************************************************************************
                                      A  U  T  O  S  A  R
**************************************************************************************************/
# define FR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  Fr_SetAbsoluteTimer()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 uint8 Fr_AbsTimerIdx,
 uint8 Fr_Cycle,
 uint16 Fr_Offset
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32         RegValue;
  uint32         pocState;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If required, check that Fr_Cycle is less than FR_VMAX_NUM_CYCLE. */
  else if (Fr_Cycle >= FR_VMAX_NUM_CYCLE)
  {
    errorId = FR_E_INV_CYCLE;
  }
  /* #50 If required, check that Fr_Offset is less than or equal to the value gMacroPerCycle. */
  else if (Fr_Offset > Fr_VCCReadBits(FR_VCTRL_IDX, FR_GTUC2, FR_GTUC2_MPC_MASK))
  {
    errorId = FR_E_INV_OFFSET;
  }
  /* #60 If required, check that communication controller is either in POCstate NORMAL_ACTIVE or in NORMAL_PASSIVE. */
  else if (((pocState != CCPOCS_NORMAL_ACTIVE) & (pocState != CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #70 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #80 Correct the given Fr_Offset if its value is 0 due to ERAY Errata Sheet (REL20100215) No. 8. */
    if (Fr_Offset == 0)
    {
      Fr_Offset = 1;
    }

    /* #90 Set the Timer 0 Macrotick Offset (T0MO) and Timer 0 Cycle Code (T0CC) flags of the Timer 0 Configuration
     *      register (T0C) to stop and configure the absolute timer. */
    RegValue  = (((uint32)(Fr_Offset) & FR_T0C_T0MO_MASK) << FR_T0C_T0MO_SHIFT);
    RegValue |= (((0x40UL | ((uint32)Fr_Cycle)) & FR_T0C_T0CC_MASK) << FR_T0C_T0CC_SHIFT);
    /**
     * Internal comment removed.
 *
 *
 *
     */
    Fr_VCCWriteValue(FR_VCTRL_IDX, FR_T0C, RegValue);  /* HALT Timer to be able to configure */ /* SBSW_FR_WriteHwReg */

    /* #100 Set the Timer 0 Run Control (T0RC) flag of the Timer 0 Configuration register (T0C) to re-start the absolute
     *      timer. */
    Fr_VCCWriteValue(FR_VCTRL_IDX, FR_T0C, RegValue + FR_T0C_T0RC); /* START Timer */ /* SBSW_FR_WriteHwReg */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_SET_ABSOLUTE_TIMER, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 3 */ /* MD_MSR_STMIF */ 
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
   /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
}  /* Fr_SetAbsoluteTimer() */

/**********************************************************************************************************************
 *  Fr_CancelAbsoluteTimer()
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
FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(FR_VCTRL_SYSTEMTYPE_ONLY, uint8 Fr_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */ 

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than or equal to FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Clear the Timer 0 Run Control (T0RC) flag of the Timer 0 Configuration register (T0C) to stop the absolute
     *     timer. */
    Fr_VCCResetBits(FR_VCTRL_IDX, FR_T0C, FR_T0C_T0RC); /* SBSW_FR_WriteHwReg */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_CANCEL_ABSOLUTE_TIMER, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}  /* Fr_CancelAbsoluteTimer() */

/**********************************************************************************************************************
 *  Fr_EnableAbsoluteTimerIRQ()
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
FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_ONLY, uint8 Fr_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than or equal to FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Do nothing and return E_OK because absolute timer is enabled by Fr_ControllerInit() and it may not be
     *     disabled at runtime.
     *     Otherwise the FRIF job list execution would not work. */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_ENABLE_ABSOLUTE_TIMER_IRQ, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}  /* Fr_EnableAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  Fr_AckAbsoluteTimerIRQ()
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
# if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_ONLY, uint8 Fr_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#  if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than or equal to FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Clear the Timer Interrupt 0 flag (TI0) of the Status Interrupt Register (SIR) to acknowledge the absolute timer. */
    Fr_VCCClearIrqStatusFlag(FR_VCTRL_IDX, FR_SIR_TI0); /* SBSW_FR_WriteHwReg */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_ACK_ABSOLUTE_TIMER_IRQ, errorId);
  }
#  else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif

  return retVal;
}  /* Fr_AckAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  Fr_DisableAbsoluteTimerIRQ()
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
FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_ONLY, uint8 Fr_AbsTimerIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#  if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than or equal to FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Do nothing and return E_OK because absolute timer may not be disabled at runtime.
     *     Otherwise the FRIF job list execution would not work. */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_DISABLE_ABSOLUTE_TIMER_IRQ, errorId);
  }
#  else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif

  return retVal;
}  /* Fr_DisableAbsoluteTimerIRQ() */

/**********************************************************************************************************************
 *  Fr_GetAbsoluteTimerIRQStatus()
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
FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  uint8 Fr_AbsTimerIdx,
  P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#  if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check number of controllers. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that Fr_AbsTimerIdx is less than or equal to FR_MAX_NUM_ABS_TIMER. */
  else if (Fr_AbsTimerIdx >= FR_MAX_NUM_ABS_TIMER)
  {
    errorId = FR_E_INV_TIMER_IDX;
  }
  /* #40 If required, check that Fr_IRQStatusPtr points to a valid address. */
  else if (Fr_IRQStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  else
  /* #50 If the initial checks are passed or not required: */
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Return the Timer Interrupt 0 flag (TI0) of the Status Interrupt Register (SIR) to indicate whether an absolute timer interrupt occurred. */
    *Fr_IRQStatusPtr = (boolean)(FR_SIR_TI0 == Fr_VCCReadBits(FR_VCTRL_IDX, FR_SIR, FR_SIR_TI0)); /* SBSW_FR_WritePtr */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_ABSOLUTE_TIMER_IRQ_STATUS, errorId);
  }
#  else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif

  return retVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif
/* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

# define FR_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
