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
/**        \file  FrIf.c
 *        \brief  FrIf source file
 *
 *      \details  Implementation of the AUTOSAR FlexRay Interface according to:
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

#define FRIF_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"
#if (FRIF_MEASURE_JLETASKTIMES == STD_ON) || (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
# include "FrIf_Ext.h"
#endif

#if (FrIf_IsPostbuild())
# include "EcuM_Error.h"
#endif

#if (FRIF_AMD_RUNTIME_MEASUREMENT == STD_ON)
# include "Rtm.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrIf.h  \trace SPEC-30086 */
#if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
    || (FRIF_SW_MINOR_VERSION != (1u)) \
    || (FRIF_SW_PATCH_VERSION != (2u)) )
# error "Version numbers of FrIf.c and FrIf.h are inconsistent"
#endif

/* Check the version of FrIf_Ext.h \trace SPEC-30086 */
#if (FRIF_MEASURE_JLETASKTIMES == STD_ON) || (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
# if (  (FRIF_EXT_MAJOR_VERSION != (5u)) \
     || (FRIF_EXT_MINOR_VERSION != (1u)) \
     || (FRIF_EXT_PATCH_VERSION != (2u)) )
#  error "Version numbers of FrIf.c and FrIf_Ext.h are inconsistent"
# endif
#endif /* (FRIF_MEASURE_JLETASKTIMES == STD_ON) || (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#define FRIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_PDUDIRTYBYTE_USAGE == STD_OFF)
CONST(uint8, FRIF_CONST) FrIf_SetBitMask[8] =
  {0x01u, 0x02u, 0x04u, 0x08u,
   0x10u, 0x20u, 0x40u, 0x80u
  };

CONST(uint8, FRIF_CONST) FrIf_ClearBitMask[8] =
  {0xFEu, 0xFDu, 0xFBu, 0xF7u,
   0xEFu, 0xDFu, 0xBFu, 0x7Fu
  };
#endif

#define FRIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
# if (FrIf_CommonMaxNumberOfClusters == 1) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
P2VAR(PduInfoType, AUTOMATIC, FRIF_VAR_NOINIT) FrIf_P2RedundantRxPduInfo[1];
# else
P2VAR(PduInfoType, AUTOMATIC, FRIF_VAR_NOINIT) FrIf_P2RedundantRxPduInfo[2];
# endif
#endif

#define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#define FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

VAR(FrIf_StateDataType, FRIF_VAR_ZERO_INIT) FrIf_Status[] = {
  {
# if (!FrIf_IsPostbuild())
  0U, /* IsInitialized */
# else
  NULL_PTR, /* FrIf_PostBuildConfigType */
  NULL_PTR, /* FrIf_FrameDescriptorType */
  NULL_PTR, /* FrIf_FrameLayoutElementType */
  NULL_PTR, /* FrIf_TxPduDescriptorType */
  NULL_PTR, /* FrIf_TxPduTranslationTupleType */
  NULL_PTR, /* FrIf_TxHandleType */
  NULL_PTR, /* FrIf_RxHandleType */
  NULL_PTR, /* FrIf_FrameDescriptorType */
  NULL_PTR, /* FrIf_FrameLayoutElementType */
  NULL_PTR, /* FrIf_RxPduDescriptorType */
# endif
  0U, /* InvalidTxHandle */
  0U, /* InvalidRxHandle */
  0U, /* InvalidTxPduHandle */
  FRIF_STATE_OFFLINE, /* State */
  0U, /* CurrentJobNumber */
  0U, /* CurrentCycle */
  0U, /* JobListExecutionEnabled */
  }
#if (FrIf_CommonMaxNumberOfClusters != 1)
  , {
# if (!FrIf_IsPostbuild()) /* !FrIf_IsPostbuild() && (FrIf_CommonMaxNumberOfClusters != 1) */ /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
  0U, /* IsInitialized */
# else
  NULL_PTR, /* FrIf_PostBuildConfigType */
  NULL_PTR, /* FrIf_FrameDescriptorType */
  NULL_PTR, /* FrIf_FrameLayoutElementType */
  NULL_PTR, /* FrIf_TxPduDescriptorType */
  NULL_PTR, /* FrIf_TxPduTranslationTupleType */
  NULL_PTR, /* FrIf_TxHandleType */
  NULL_PTR, /* FrIf_RxHandleType */
  NULL_PTR, /* FrIf_FrameDescriptorType */
  NULL_PTR, /* FrIf_FrameLayoutElementType */
  NULL_PTR, /* FrIf_RxPduDescriptorType */
# endif
  0U, /* InvalidTxHandle */
  0U, /* InvalidRxHandle */
  0U, /* InvalidTxPduHandle */
  FRIF_STATE_OFFLINE, /* State */
  0U, /* CurrentJobNumber */
  0U, /* CurrentCycle */
  0U, /* JobListExecutionEnabled */
  }
#endif
};

#if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
VAR(sint16_least, FRIF_VAR_ZERO_INIT) FrIf_MaxTaskDelay = 0U;
VAR(sint16_least, FRIF_VAR_ZERO_INIT) FrIf_MaxTaskOverlap = 0U;
#endif

#define FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* ESCAN00067721 */
/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

#if (FRIF_AMD_RUNTIME_MEASUREMENT == STD_ON)
# define FrIf_Rtm_Start(measurement) Rtm_Start(RtmConf_RtmMeasurementPoint_##measurement) /* PRQA S 0342 */ /* MD_FrIf_0342 */
# define FrIf_Rtm_Stop(measurement)  Rtm_Stop(RtmConf_RtmMeasurementPoint_##measurement)  /* PRQA S 0342 */ /* MD_FrIf_0342 */
#else
# define FrIf_Rtm_Start(measurement)
# define FrIf_Rtm_Stop(measurement)
#endif

#if defined(FRIF_CUSTOM_JLE_SCHEDULING) && (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */

# define FRIF_ENABLE_JLE_TIMER(ClusterIdx) \
        FrIf_Enable_JLE_Timer(ClusterIdx)
# define FRIF_DISABLE_JLE_TIMER(ClusterIdx) \
        FrIf_Disable_JLE_Timer(ClusterIdx)
# define FRIF_SET_JLE_TIMER(ClusterIdx, FrCycle, FrMacrotickOffset, RepeatJLE)  \
        FrIf_Set_JLE_Timer(ClusterIdx, FrCycle, FrMacrotickOffset, RepeatJLE)
#else
/* By default the Absolute Timer 0 is used to schedule the FrIf Job List */
# if (!defined FRIF_ENABLE_JLE_TIMER ) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FRIF_ENABLE_JLE_TIMER(TimerIdx)   (void)Fr_EnableAbsoluteTimerIRQ(FrIf_TimerIndex2FrCtrlIndex(TimerIdx), 0)
# endif
# if (!defined FRIF_DISABLE_JLE_TIMER ) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FRIF_DISABLE_JLE_TIMER(TimerIdx)  (void)Fr_CancelAbsoluteTimer(FrIf_TimerIndex2FrCtrlIndex(TimerIdx), 0)
# endif
# if (!defined FRIF_SET_JLE_TIMER ) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FRIF_SET_JLE_TIMER(TimerIdx, FrCycle, FrMacrotickOffset,  RepeatJLE)  \
                                             Fr_SetAbsoluteTimer(FrIf_TimerIndex2FrCtrlIndex(TimerIdx), \
                                                                0, \
                                                                FrCycle, \
                                                                FrMacrotickOffset)
# endif
#endif

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */  /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_InitializeTransmission()
**********************************************************************************************************************/
/*!
 *
 * \brief        Initializes all the flags and counters related to the transmission of PDUs.
 * \details      Sets all the Tx request counters to 0 and flags all the Tx PDUs as non-sent and non-dirty (not
 *               requested to be sent).
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      Generic
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_InitializeTransmission(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_JobListOutOfSync()
**********************************************************************************************************************/
/*!
 *
 * \brief        Handles the loss of synchronization of the job list execution.
 * \details      Disables, synchronizes and re-enables the job list execution.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      Generic
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_JobListOutOfSync(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_DisableJobListExecution()
**********************************************************************************************************************/
/*!
 *
 * \brief        Disables the job list execution.
 * \details      Cancels the absolute timer interrupt and flags the job list execution as disabled.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      StateH
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_DisableJobListExecution(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_EnableJobListExecution()
**********************************************************************************************************************/
/*!
 *
 * \brief        Enables the job list execution.
 * \details      Sets the absolute timer based on the next possible FrIf job and flags the job list execution as
 *               enabled.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      StateH
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_EnableJobListExecution(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_ExecCurrentJob()
**********************************************************************************************************************/
/*!
 *
 * \brief        Processes the currently active FrIf job.
 * \details      Checks the synchronization of the job list execution, performs the communication operations associated
 *               to the current FrIf job and sets the absolute timer based on the next FrIf job.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      PDU
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_ExecCurrentJob(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_DiffTime()
**********************************************************************************************************************/
/*!
 *
 * \brief        Calculates the difference between two FlexRay time values.
 * \details      Calculates the difference in macroticks between two FlexRay time values, taking into account the wrap
 *               around of the FlexRay cycles.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    MacroTickDiff    Difference between the macroticks of the two time values.
 * \param[in]    CycleDiff        Difference between the cycles of the two time values.
 * \return       The Difference in macroticks between the two time values.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      Generic
 *********************************************************************************************************************/
FRIF_LOCAL FUNC(sint16_least, FRIF_CODE) FrIf_DiffTime(FRIF_VCLST_ONLY, sint16_least MacroTickDiff, sint16_least CycleDiff);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrIf_ExecCurrentJob()
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
FRIF_LOCAL FUNC(void, FRIF_CODE)FrIf_ExecCurrentJob(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 uint8Cycle = 0;
  uint16 uint16MacroTicks = 0;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  FrIf_Rtm_Start(FrIf_ExecCurrentJob_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #10 Retrieve the FlexRay global time. */
  retVal = Fr_GetGlobalTime(FRIF_VCLST_IDX, &uint8Cycle, &uint16MacroTicks);                      /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */

  /* #20 If the FlexRay global time was successfully retrieved: */
  if(retVal == E_OK)
  {
    /* #30 Calculate the macroticks remaining/elapsed between the current global time and the configured start of
     *     the current job.
     */
    FRIF_P2CONSTCFG(FrIf_JobDescriptorType) JobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);
    sint16_least FrIf_Delay = FrIf_DiffTime(FRIF_VCLST_IDX, 
                          (sint16_least)uint16MacroTicks - (sint16_least)(JobDataPtr->StartTimeInMacroTicks),
                          (sint16_least) uint8Cycle - (sint16_least) (FrIf_Status[FRIF_VCLST_IDX].CurrentCycle));

    /* #40 If the job list execution behavior is being tracked, check if the maximum delay must be updated. */
#if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
    if((FrIf_Delay > FrIf_MaxTaskDelay) || (0 == FrIf_MaxTaskDelay))
    {
      FrIf_MaxTaskDelay = FrIf_Delay;
    }
#endif

    /* #50 If the current job is supposed to be started and the delay is within the configured limit for the job: */
    if((0 <= FrIf_Delay) && ((sint16_least)JobDataPtr->MaxDelay > FrIf_Delay))
    {
      /* #60 If the current job handles TX_CONFIRMATION communication operations, perform a Tx confirmation task. */
      if(JobDataPtr->MinTxConfJobNo != FRIF_INVALID_JOB_NUMBER)
      {
        FrIf_Rtm_Start(FrIf_TxConfTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        FrIf_TxConfTask(FRIF_VCLST_OPT);
        FrIf_Rtm_Stop(FrIf_TxConfTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }

      /* #70 If the current job is flagged as Rx job, perform an Rx task.
       *     Otherwise, perform a Tx task.
       */
      if((JobDataPtr->JobConfig & FrIf_JobDataIsRxTask) == FrIf_JobDataIsRxTask)
      {
        FrIf_Rtm_Start(FrIf_RxTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        retVal = FrIf_RxTask(FRIF_VCLST_OPT);
        FrIf_Rtm_Stop(FrIf_RxTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        FrIf_Rtm_Start(FrIf_TxTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        FrIf_TxTask(FRIF_VCLST_OPT);
        FrIf_Rtm_Stop(FrIf_TxTask_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }

      if (retVal == E_NOT_OK)
      {
        errorId = FRIF_E_TASK_RET_E_NOT_OK;
      }
      /* #80 Update the FrIf status, by increasing the current job number. In case of job wrap-around, increase also
       *     the current local cycle.
       */
      FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber++;                                                     /* SBSW_FRIF_STATUS_WRT */
      if(FrIf_GetNumberOfJobs(FRIF_VCLST_IDX) <= FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber)
      {
        FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber = 0;                                                 /* SBSW_FRIF_STATUS_WRT */
        FrIf_Status[FRIF_VCLST_IDX].CurrentCycle = NEXT_CYCLE(FrIf_Status[FRIF_VCLST_IDX].CurrentCycle);  /* SBSW_FRIF_STATUS_WRT */
      }
    }
    /* #90 Otherwise, resync the job list execution (the timer interrupt might have been blocked for too long). */
    else
    {
        FrIf_JobListOutOfSync(FRIF_VCLST_OPT);
    }
  }
  /* #95 Otherwise, resync the job list execution. */
  else
  {
    FrIf_JobListOutOfSync(FRIF_VCLST_OPT);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_EXEC_CURRENT_JOB, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  FrIf_Rtm_Stop(FrIf_ExecCurrentJob_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrIf_ExecCurrentJob() */ /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  FrIf_DiffTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FRIF_LOCAL FUNC(sint16_least, FRIF_CODE) FrIf_DiffTime(FRIF_VCLST_ONLY, sint16_least MacroTickDiff, sint16_least CycleDiff)
{
  /**
   * Internal comment removed.
 *
 *
   */
  /* ----- Implementation ----------------------------------------------- */
  /* Cycles are modulo 64, treat e.g., -63 as +1  etc. */
  /* #10 Calculate the difftime in macroticks. */
  if(CycleDiff < -32)
  {
    CycleDiff += 64;
  }
  if(MacroTickDiff < 0)
  {
    CycleDiff -= 1;
    MacroTickDiff = MacroTickDiff + (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX); /* ESCAN00066875 */
  }
  if(CycleDiff > 0)
  {
    MacroTickDiff = MacroTickDiff + (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX); /* ESCAN00066875 */
  }
  else
  {
    if(CycleDiff < 0)
    {
      MacroTickDiff = MacroTickDiff - (sint16_least) FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX); /* ESCAN00066875 */
    }
  }
  return MacroTickDiff;
} /* FrIf_DiffTime() */

/**********************************************************************************************************************
 *  FrIf_EnableJobListExecution()
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
 */
FRIF_LOCAL FUNC(void, FRIF_CODE)FrIf_EnableJobListExecution(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least i;
  uint8 uint8Cycle = 0;
  uint16 uint16MacroTicks = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset transmission-related flags and counters. */
  FrIf_InitializeTransmission(FRIF_VCLST_OPT);

  /* #20 Enter FRIF_EXCLUSIVE_AREA_1. */
  SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #30 Retrieve the FlexRay global time. */
  retVal = Fr_GetGlobalTime(FRIF_VCLST_IDX, &uint8Cycle, &uint16MacroTicks);                      /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */

  /* #40 If the FlexRay global time was successfully retrieved: */
  if(retVal == E_OK)
  {
    /* #50 Update the FrIf status, by initially setting the next global cycle as current local cycle and the first job
     *     of the list as current job.
     */
    FrIf_Status[FRIF_VCLST_IDX].CurrentCycle = NEXT_CYCLE(uint8Cycle);                            /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber = 0;                                             /* SBSW_FRIF_STATUS_WRT */

    /* #60 For each job:
     *       Get the macroticks remaining/elapsed between the current global time and the configured start of the job.
     *       If there's enough time before the job is supposed to start:
     *         Update the FrIf status again, by setting the current global cycle as current local cycle and the found
     *         job as current job.
     *         Break out of the loop.
     */
    for (i = 0; i < FrIf_GetNumberOfJobs(FRIF_VCLST_IDX); i++)
    {
      sint16_least FrIf_Delay = FrIf_DiffTime(FRIF_VCLST_IDX, (sint16_least)(FrIf_GetJobDescriptor(FRIF_VCLST_IDX, i).StartTimeInMacroTicks) - (sint16_least)uint16MacroTicks, 0);

      if(FrIf_Delay > (sint16_least)FRIF_SYNC_THRESHOLD)
      {
        FrIf_Status[FRIF_VCLST_IDX].CurrentCycle = uint8Cycle;                                    /* SBSW_FRIF_STATUS_WRT */
        FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber = i;                                         /* SBSW_FRIF_STATUS_WRT */
        break;
      }
    }
    /* #70 Flag the job list execution as enabled. */
    FrIf_Status[FRIF_VCLST_IDX].JobListExecutionEnabled = TRUE;                                   /* SBSW_FRIF_STATUS_WRT */

    /**
     * Internal comment removed.
 *
 *
 *
 *
 *
     */

    /* #80 Set the next absolute timer interrupt according to the cycle and job stored in the FrIf status. */
    retVal |= FRIF_SET_JLE_TIMER(
      FRIF_VCLST_IDX,
      FrIf_Status[FRIF_VCLST_IDX].CurrentCycle,
      FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber).StartTimeInMacroTicks,
      FALSE);
    FRIF_ENABLE_JLE_TIMER(FRIF_VCLST_IDX);
  }

  /* #90 Exit FRIF_EXCLUSIVE_AREA_1. */
  SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #95 If setting the timer failed:
   *        Disable the job list execution.
   */
  if(retVal == E_NOT_OK)
  {
    FrIf_DisableJobListExecution(FRIF_VCLST_OPT);
  }
} /* FrIf_EnableJobListExecution() */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  FrIf_DisableJobListExecution()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_DisableJobListExecution(FRIF_VCLST_ONLY)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Flag the job list execution as disabled. */
  FrIf_Status[FRIF_VCLST_IDX].JobListExecutionEnabled = FALSE;                                    /* SBSW_FRIF_STATUS_WRT */

  /* #20 Disable the absolute timer interrupts. */
  FRIF_DISABLE_JLE_TIMER(FRIF_VCLST_IDX);
  
} /* FrIf_DisableJobListExecution() */

/**********************************************************************************************************************
 *  FrIf_JobListOutOfSync()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_JobListOutOfSync(FRIF_VCLST_ONLY)
{
  /* ----- Implementation ----------------------------------------------- */

  /* #10 Disable the job list execution. */
  FrIf_DisableJobListExecution(FRIF_VCLST_OPT);

  /* #20 If required, report the job list execution as out of sync. */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_JOBLISTEXEC, FRIF_E_JLE_SYNC);
#endif

  /* #30 Resync and enable the job list execution. */
  FrIf_EnableJobListExecution(FRIF_VCLST_OPT);
} /* FrIf_JobListOutOfSync() */

/**********************************************************************************************************************
 *  FrIf_InitializeTransmission()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FRIF_LOCAL FUNC(void, FRIF_CODE) FrIf_InitializeTransmission(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint16_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Flag all the FlexRay PDUs as non-dirty. */
#if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
  for(i = (sint16_least) FrIf_GetMaxTxPduId(FRIF_VCLST_IDX); i >= (sint16_least) 0; i--)
  {
    FrIf_GetTxPduDirtyByte(FRIF_VCLST_IDX, i) = 0;                                     /* SBSW_FRIF_DIRTY_BYTES_RST */
  }
#else
  for(i = (sint16_least) FrIf_GetDirtyBitByteIdx(FrIf_GetMaxTxPduId(FRIF_VCLST_IDX)); i >= (sint16_least) 0; i--)
  {
    FrIf_GetTxPduDirtyBits(FRIF_VCLST_IDX)[i] = 0;                                    /* SBSW_FRIF_DIRTY_BITS_RST */
  }
#endif

  /* #20 Flag all the FlexRay PDUs as non-sent. */
  for(i = (sint16_least) FrIf_GetMaxTxFrameId(FRIF_VCLST_IDX); i >= (sint16_least) 0; i--)
  {
    FrIf_GetTxPduWasSentFlags(FRIF_VCLST_IDX, i) = 0;                                 /* SBSW_FRIF_SENT_FLAGS_RST1 */
  }

  /* #30 If Tx request counters are enabled and used, set them to 0. */
#if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
  for(i = (sint16_least) FrIf_GetNumberOfTxRequestCounters(FRIF_VCLST_IDX) - 1; i >= (sint16_least) 0; i--) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
  { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */
    FrIf_GetTxPduTxRequestCounter(FRIF_VCLST_IDX, i) = 0;                             /* SBSW_FRIF_REQUEST_COUNTERS_RST */
  }
#endif /* (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF) */
} /* FrIf_InitializeTransmission() */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FrIf_InitMemory()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FRIF_CODE) FrIf_InitMemory(void)
{
  /* #10 Flag the FrIf as uninitialized and reset the FrIf status. */
#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
# if (!FrIf_IsPostbuild())
  FrIf_Status[FRIF_VCLST_IDX].IsInitialized = 0U;                                            /* SBSW_FRIF_STATUS_WRT */
# else
  FrIf_Status[FRIF_VCLST_IDX].pConfigData = NULL_PTR;                                        /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pTxFrameDescriptors = NULL_PTR;                                /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pTxFrameLayoutElements = NULL_PTR;                             /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pTxPduDescriptors = NULL_PTR;                                  /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pTxPduTranslationTable = NULL_PTR;                             /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pTxLPduTranslationTable = NULL_PTR;                            /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pRxLPduTranslationTable = NULL_PTR;                            /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pRxFrameDescriptors = NULL_PTR;                                /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pRxFrameLayoutElements = NULL_PTR;                             /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].pRxPduDescriptors = NULL_PTR;                                  /* SBSW_FRIF_STATUS_WRT */
# endif
  FrIf_Status[FRIF_VCLST_IDX].InvalidTxHandle = 0U;                                          /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].InvalidRxHandle = 0U;                                          /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].InvalidTxPduHandle = 0U;                                       /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].State = FRIF_STATE_OFFLINE;                                    /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber = 0U;                                         /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].CurrentCycle = 0U;                                             /* SBSW_FRIF_STATUS_WRT */
  FrIf_Status[FRIF_VCLST_IDX].JobListExecutionEnabled = 0U;                                  /* SBSW_FRIF_STATUS_WRT */
#else /* FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON */
  uint8_least i;
  for (i = 0; i < FrIf_CommonMaxNumberOfClusters; i++)
  {
# if (!FrIf_IsPostbuild())
    FrIf_Status[i].IsInitialized = 0U;                                                       /* SBSW_FRIF_STATUS_WRT */
# else
    FrIf_Status[i].pConfigData = NULL_PTR;                                                   /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pTxFrameDescriptors = NULL_PTR;                                           /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pTxFrameLayoutElements = NULL_PTR;                                        /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pTxPduDescriptors = NULL_PTR;                                             /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pTxPduTranslationTable = NULL_PTR;                                        /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pTxLPduTranslationTable = NULL_PTR;                                       /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pRxLPduTranslationTable = NULL_PTR;                                       /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pRxFrameDescriptors = NULL_PTR;                                           /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pRxFrameLayoutElements = NULL_PTR;                                        /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].pRxPduDescriptors = NULL_PTR;                                             /* SBSW_FRIF_STATUS_WRT */
# endif
    FrIf_Status[i].InvalidTxHandle = 0U;                                                     /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].InvalidRxHandle = 0U;                                                     /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].InvalidTxPduHandle = 0U;                                                  /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].State = FRIF_STATE_OFFLINE;                                               /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].CurrentJobNumber = 0U;                                                    /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].CurrentCycle = 0U;                                                        /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[i].JobListExecutionEnabled = 0U;                                             /* SBSW_FRIF_STATUS_WRT */
  }
#endif /* FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON */

  /* #20 If required, reset the variables used to track the job list execution behavior. */
#if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
  FrIf_ResetMaxTaskDelay();
  FrIf_ResetMaxTaskOverlap();
#endif
} /* FrIf_InitMemory() */

/**********************************************************************************************************************
 *  FrIf_Init()
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
FUNC(void, FRIF_CODE) FrIf_Init(FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr)
{  
  /* ----- Local Variables ---------------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FRIF_E_NO_ERROR;
#endif
#if (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  uint8 ecumErrorId = FRIF_E_NO_ERROR;
#endif  

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check the validity of the FrIf_ConfigPtr given as input. \trace SPEC-29948 */
  if (FrIf_ConfigPtr == NULL_PTR)
  {
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
    errorId = FRIF_E_INV_POINTER;
#endif
  /* #20 If the configuration variant is post-build loadable: */
#if (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
    ecumErrorId = ECUM_BSWERROR_NULLPTR;
  }
    /* #30 Check compatibility with the FrIf generator. */
  else if (FrIf_ConfigPtr->GeneratorCompatibilityVersion != FRIF_GENERATOR_COMPATIBILITY_VERSION)
  {
    ecumErrorId = ECUM_BSWERROR_COMPATIBILITYVERSION;
  }
    /* #40 Use the magic number to proof the validity of the configuration given as input. */
  else if (FrIf_ConfigPtr->FinalMagicNumber != FRIF_FINAL_MAGICNUMBER)
  {
    ecumErrorId = ECUM_BSWERROR_MAGICNUMBER;
#endif
  }
  else

  /* ----- Implementation ----------------------------------------------- */
  /* #50 If the initial checks are passed or not required: */
  {
    /* #60 For each FlexRay cluster (there's no loop if the single CC optimization is enabled):
     *       Flag the FrIf as initialized and cache frequently used data in RAM (FrIf_Status global variable). \trace SPEC-30166 
     *       Flag the FrIf as offline. \trace SPEC-29934
     *       Flag the job list execution as disabled.
     *       Reset transmission-related flags and counters.
     *       If redundancy is enabled, define the global pointer to the array used to store redundant Rx PDU info.
     */
#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
# if (!FrIf_IsPostbuild())
    FrIf_Status[FRIF_VCLST_IDX].IsInitialized = FRIF_IS_INITIALIZED_MAGIC_NUMBER;            /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].InvalidTxPduHandle = FrIf_InvalidTxPduHandle;                /* SBSW_FRIF_STATUS_WRT */
# else
    FrIf_Status[FRIF_VCLST_IDX].pConfigData = (FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType)) FrIf_ConfigPtr;               /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pTxFrameDescriptors = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pTxFrameDescriptors;         /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pTxFrameLayoutElements = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pTxFrameLayoutElements;   /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pTxPduDescriptors = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pTxPduDescriptors;             /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pTxPduTranslationTable = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pTxPduTranslationTable;   /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pTxLPduTranslationTable = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pTxLPduTranslationTable; /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pRxLPduTranslationTable = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pRxLPduTranslationTable; /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].InvalidTxPduHandle = FrIf_Status[FRIF_VCLST_IDX].pConfigData->InvalidTxPduHandle;           /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pRxFrameDescriptors = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pRxFrameDescriptors;         /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pRxFrameLayoutElements = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pRxFrameLayoutElements;   /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].pRxPduDescriptors = FrIf_Status[FRIF_VCLST_IDX].pConfigData->pRxPduDescriptors;             /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].InvalidTxHandle = FrIf_Status[FRIF_VCLST_IDX].pConfigData->InvalidTxHandle;                 /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].InvalidRxHandle = FrIf_Status[FRIF_VCLST_IDX].pConfigData->InvalidRxHandle;                 /* SBSW_FRIF_STATUS_WRT */
# endif /* !FrIf_IsPostbuild() */

    FrIf_Status[FRIF_VCLST_IDX].State = FRIF_STATE_OFFLINE;                                  /* SBSW_FRIF_STATUS_WRT */
    FrIf_Status[FRIF_VCLST_IDX].JobListExecutionEnabled = FALSE;                             /* SBSW_FRIF_STATUS_WRT */
    FrIf_InitializeTransmission();
# if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
    FrIf_P2RedundantRxPduInfo[FRIF_VCLST_IDX] = FrIf_GetRedundantRxPduInfo(FRIF_VCLST_IDX); /* SBSW_FRIF_P2REDUNDANT_INFO_WRT */
# endif

#else /* FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON */
    uint8_least i;
# if (!FrIf_IsPostbuild())
    for (i = 0; i < FrIf_GetNumberOfClusters(); i++)
    {
      FrIf_Status[i].IsInitialized = FRIF_IS_INITIALIZED_MAGIC_NUMBER;                       /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].InvalidTxPduHandle = FrIf_InvalidTxPduHandle;                           /* SBSW_FRIF_STATUS_WRT */
# else
    for (i = 0; i < FrIf_ConfigPtr->NumberOfClusters; i++)
    {
      FrIf_Status[i].pConfigData = (FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType)) FrIf_ConfigPtr;          /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pTxFrameDescriptors = FrIf_Status[i].pConfigData->pCtrl2TxFrameDescriptors[i];         /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pTxFrameLayoutElements = FrIf_Status[i].pConfigData->pCtrl2TxFrameLayoutElements[i];   /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pTxPduDescriptors = FrIf_Status[i].pConfigData->pCtrl2TxPduDescriptors[i];             /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pTxPduTranslationTable = FrIf_Status[i].pConfigData->pTxPduTranslationTable;           /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pTxLPduTranslationTable = FrIf_Status[i].pConfigData->pCtrl2TxLPduTranslationTable[i]; /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pRxLPduTranslationTable = FrIf_Status[i].pConfigData->pCtrl2RxLPduTranslationTable[i]; /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].InvalidTxPduHandle = FrIf_Status[i].pConfigData->InvalidTxPduHandle;                   /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pRxFrameDescriptors = FrIf_Status[i].pConfigData->pCtrl2RxFrameDescriptors[i];         /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pRxFrameLayoutElements = FrIf_Status[i].pConfigData->pCtrl2RxFrameLayoutElements[i];   /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].pRxPduDescriptors = FrIf_Status[i].pConfigData->pCtrl2RxPduDescriptors[i];             /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].InvalidTxHandle = FrIf_Status[i].pConfigData->pCtrl2InvalidTxHandle[i];                /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].InvalidRxHandle = FrIf_Status[i].pConfigData->pCtrl2InvalidRxHandle[i];                /* SBSW_FRIF_STATUS_WRT */
# endif /* !FrIf_IsPostbuild() */

      FrIf_Status[i].State = FRIF_STATE_OFFLINE;                                             /* SBSW_FRIF_STATUS_WRT */
      FrIf_Status[i].JobListExecutionEnabled = FALSE;                                        /* SBSW_FRIF_STATUS_WRT */
      FrIf_InitializeTransmission((uint8) i);
      
# if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
      FrIf_P2RedundantRxPduInfo[i] = FrIf_GetRedundantRxPduInfo(i);                /* SBSW_FRIF_P2REDUNDANT_INFO_WRT */
# endif
    }
#endif /* FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON */
  }

  /* ----- Error Reporting --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_INIT, errorId);
  }
#endif
  /* #90 If the configuration variant is post-build loadable and an invalid configuration was given as input:
   *       Report the error to the EcuM. */
#if (FRIF_CONFIGURATION_VARIANT == FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  if (ecumErrorId != FRIF_E_NO_ERROR)
  {
    EcuM_BswErrorHook((uint16) FRIF_MODULE_ID, ecumErrorId);
  }
#endif
} /* FrIf_Init() */

/**********************************************************************************************************************
 *  FrIf_SetState()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetState(FRIF_VCLST_ONLY, 
                                             FrIf_StateTransitionType  FrIf_State)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29991 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay cluster index given as input. \trace SPEC-29854 */
  else if (FRIF_VCLST_IDX >= FrIf_GetNumberOfClusters()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CLST_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 If a transition to the online state is requested and the FrIf is offline: */
    if ((FrIf_State == FRIF_GOTO_ONLINE) && (FrIf_Status[FRIF_VCLST_IDX].State == FRIF_STATE_OFFLINE))
    {

      /* #50 Enter FrIf_FRIF_EXCLUSIVE_AREA_2. */
      SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_2();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #60 Try to synchronize and enable the job list execution. */
      FrIf_EnableJobListExecution(FRIF_VCLST_OPT);

      /* #70 If the job list execution was successfully enabled:
       *       Flag the FrIf as online.
       */
      if(FrIf_Status[FRIF_VCLST_IDX].JobListExecutionEnabled == TRUE)
      {
        FrIf_Status[FRIF_VCLST_IDX].State = FRIF_STATE_ONLINE;                                    /* SBSW_FRIF_STATUS_WRT */
        retVal = E_OK;
      }

      /* #80 Exit FrIf_FRIF_EXCLUSIVE_AREA_2. */
      SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_2(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    /* #90 Otherwise, if a transition to the offline state is requested and the FrIf is online:
     *       Disable the job list execution.
     *       Flag the FrIf as offline.
     */
    else if ((FrIf_State == FRIF_GOTO_OFFLINE) && (FrIf_Status[FRIF_VCLST_IDX].State == FRIF_STATE_ONLINE))
    {
      FrIf_DisableJobListExecution(FRIF_VCLST_OPT);
      FrIf_Status[FRIF_VCLST_IDX].State = FRIF_STATE_OFFLINE;                                     /* SBSW_FRIF_STATUS_WRT */
      retVal = E_OK;
    }
    else
    {
      /* No transition will take place and E_NOT_OK will be returned. */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_SETSTATE, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_SetState() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  FrIf_GetState()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetState(FRIF_VCLST_ONLY, 
                                              P2VAR(FrIf_StateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_StatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30008 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay cluster index given as input. \trace SPEC-29949 */
  else if (FRIF_VCLST_IDX >= FrIf_GetNumberOfClusters()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CLST_IDX;
  }
  /* #30 If required, check the validity of the FrIf_StatePtr given as input. \trace SPEC-29833 */
  else if (FrIf_StatePtr == NULL_PTR)
  {
    errorId = FRIF_E_INV_POINTER;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Store the current state in the address given as input. */
    *FrIf_StatePtr = FrIf_Status[FRIF_VCLST_IDX].State;                                               /* SBSW_FRIF_PTR_WRT_UNCHANGED */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETSTATE, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetState() */

/**********************************************************************************************************************
 *  FrIf_GetMacroticksPerCycle()
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
FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksPerCycle(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;
  uint16 retVal = 0;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29971 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30093 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#else
  /* Multiple FlexRay CCs are currently not supported, so no index translation is required. */
  FRIF_DUMMY_STATEMENT_CONST(FRIF_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Return the number of macroticks per cycle from the configuration. */
    retVal = FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETMACROTICKSPERCYCLE, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* #50 Otherwise, return 0. */
  return retVal;
} /* FrIf_GetMacroticksPerCycle() */

/**********************************************************************************************************************
 *  FrIf_GetMacrotickDuration()
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
FUNC(uint16, FRIF_CODE) FrIf_GetMacrotickDuration(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;
  uint16 retVal = 0;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29886 */
  if (!FRIF_IS_INITIALIZED()) 
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30113 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#else
  /* Multiple FlexRay CCs are currently not supported, so no index translation is required. */
  FRIF_DUMMY_STATEMENT_CONST(FRIF_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Return the duration of a macrotick in nanoseconds from the configuration. */
    retVal = FrIf_GetMacroTickLengthInNanoSeconds(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETMACROTICKDURATION, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* #50 Otherwise, return 0. */
  return retVal;
} /* FrIf_GetMacrotickDuration() */

#if (FRIF_VERSION_INFO_API == STD_ON) 
/**********************************************************************************************************************
 *  FrIf_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FRIF_CODE)FrIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRIF_APPL_DATA) FrIf_VersionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check the validity of the FrIf_VersionInfoPtr given as input. \trace SPEC-29909 */
  if (FrIf_VersionInfoPtr == NULL_PTR)
  {
    errorId = FRIF_E_INV_POINTER;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If the initial check is passed or not required: */
  {
    /* #30 Fill the version information struct using the macros from the component header. \trace SPEC-30114 */
    FrIf_VersionInfoPtr->vendorID = FRIF_VENDOR_ID;                                /* SBSW_FRIF_STRUCT_WRT_UNCHANGED */
    FrIf_VersionInfoPtr->moduleID = FRIF_MODULE_ID;                                /* SBSW_FRIF_STRUCT_WRT_UNCHANGED */
    FrIf_VersionInfoPtr->sw_major_version = FRIF_SW_MAJOR_VERSION;                 /* SBSW_FRIF_STRUCT_WRT_UNCHANGED */
    FrIf_VersionInfoPtr->sw_minor_version = FRIF_SW_MINOR_VERSION;                 /* SBSW_FRIF_STRUCT_WRT_UNCHANGED */
    FrIf_VersionInfoPtr->sw_patch_version = FRIF_SW_PATCH_VERSION;                 /* SBSW_FRIF_STRUCT_WRT_UNCHANGED */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETVERSIONINFO, errorId);
  }
# else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* FrIf_GetVersionInfo() */
#endif /* (FRIF_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  FrIf_MainFunction()
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
FUNC(void, FRIF_CODE) FrIf_MainFunction(FRIF_VCLST_ONLY)
{
  /* #10 If the FrIf is initialized and online: \trace SPEC-30044, SPEC-29953 */
  if(FRIF_IS_INITIALIZED() && (FrIf_Status[FRIF_VCLST_IDX].State == FRIF_STATE_ONLINE))
  {    
    uint8 uint8CycleDiffTime = 0;
    uint8 uint8Cycle = 0;
    uint16 uint16MacroTicks = 0;
    Std_ReturnType retVal = E_NOT_OK;
    
    /* #20 If the detection of production errors is enabled: */
#if (FRIF_PROD_ERROR_DETECT == STD_ON)
    uint16 ChannelAStatus = 0;
    uint16 ChannelBStatus = 0;

    retVal = Fr_GetChannelStatus(FRIF_VCLST_IDX, &ChannelAStatus, &ChannelBStatus);               /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
    if(retVal == E_OK)
    {
      /* #30 Retrieve and check the status of both FlexRay channels. \trace SPEC-30099 */
      FrIf_CheckChannelStatus(FRIF_VCLST_IDX, FR_CHANNEL_A, ChannelAStatus);
      FrIf_CheckChannelStatus(FRIF_VCLST_IDX, FR_CHANNEL_B, ChannelBStatus);
    }
#endif /* (FRIF_PROD_ERROR_DETECT == STD_ON) */

    /* #40 Calculate the difference between the current global cycle and the current local cycle.  */
    retVal = Fr_GetGlobalTime(FRIF_VCLST_IDX, &uint8Cycle, &uint16MacroTicks);                    /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */
    uint8CycleDiffTime = (uint8)((((FrIf_Status[FRIF_VCLST_IDX].CurrentCycle) - uint8Cycle) + 0x40u) & 0x3Fu);

    /* #50 If the difference is greater than 2 cycles (positive or negative): */
    if ((retVal != E_OK) || ((2 < uint8CycleDiffTime) && (62 > uint8CycleDiffTime)))
    {
      /* #60 Resync the job list execution. \trace SPEC-30174 */
      FrIf_JobListOutOfSync(FRIF_VCLST_OPT);
    }
  }
} /* FrIf_MainFunction() */

/**********************************************************************************************************************
 *  FrIf_MainFunction_0()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRIF_CODE) FrIf_MainFunction_0(void)
{
#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
  FrIf_MainFunction();
#else
  FrIf_MainFunction(0);
#endif
}

#if (FrIf_CommonMaxNumberOfClusters > 1)
/**********************************************************************************************************************
 *  FrIf_MainFunction_1()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRIF_CODE) FrIf_MainFunction_1(void)
{
  FrIf_MainFunction(1);
}
#endif

/**********************************************************************************************************************
 *  FrIf_JobListExec_0()
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
 *
 */
FUNC(void, FRIF_CODE) FrIf_JobListExec(FRIF_VCLST_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29880 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #20 If the initial check is passed or not required: */
  {
    FrIf_Rtm_Start(FrIf_JobListExec_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #30 If the FrIf is online: \trace SPEC-30123, SPEC-29840, SPEC-29884 */
    if(FrIf_IsOnline(FRIF_VCLST_IDX))
    {
      uint8 uint8Cycle = 0;
      uint16 uint16MacroTicks = 0;
      Std_ReturnType retVal = E_NOT_OK;

      FRIF_P2CONSTCFG(FrIf_JobDescriptorType) NextJobDataPtr;
      FRIF_P2CONSTCFG(FrIf_JobDescriptorType) JobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);
      FRIF_DUMMY_STATEMENT(JobDataPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

      /* #40 Execute the job stored as current in the FrIf status, and update the status by increasing the current
       *     job number.
       */
      FrIf_ExecCurrentJob(FRIF_VCLST_OPT);

      /* #45 If job concatenation is enabled, and the configured start time of both the just-executed-job and the new
       *     current job match:
       *         Execute the new current job (without setting a new timer interrupt) and increase again the current
       *         job number in the FrIf status.
       */
#if (FRIF_JOB_CONCATENATION_ENABLE == STD_ON)
      NextJobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);
      if(JobDataPtr->StartTimeInMacroTicks == NextJobDataPtr->StartTimeInMacroTicks)
      {
        JobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);
        FrIf_ExecCurrentJob(FRIF_VCLST_OPT);
      }
#endif

      /* #50 Enter FRIF_EXCLUSIVE_AREA_1. */
      SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #55 Retrieve the FlexRay global time. */
      retVal = Fr_GetGlobalTime(FRIF_VCLST_IDX, &uint8Cycle, &uint16MacroTicks);                  /* SBSW_FRIF_FCT_CALL_PTR2LOCAL */

      /* #60 If the FlexRay global time was successfully retrieved: */
      if(retVal == E_OK)
      {
        /* #65 If protected range checks are enabled, verify that the last job was finished outside its own slot
         *     range.
         */
#if (FRIF_SUPPRESS_PROTECTED_RANGE_CHECK == STD_OFF) /* ESCAN00075484 */
        if ((uint16MacroTicks >= JobDataPtr->StartTimeProtectedRange)
             && (uint16MacroTicks <= JobDataPtr->EndTimeProtectedRange))
        {
          retVal = E_NOT_OK;
        }

        /* #70 If the protected range check was passed: */
        if(retVal == E_OK)
#endif
        {
          sint16_least FrIf_Delay;
          NextJobDataPtr = &FrIf_GetJobDescriptor(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentJobNumber);

          /* #75 Get the macroticks remaining/elapsed between the current global time and the configured start of the
           *     job stored as current in the FrIf status.
           */
          FrIf_Delay = FrIf_DiffTime(FRIF_VCLST_IDX, 
            (sint16_least)(NextJobDataPtr->StartTimeInMacroTicks) - (sint16_least)uint16MacroTicks,
                                             (sint16_least) (FrIf_Status[FRIF_VCLST_IDX].CurrentCycle) - (sint16_least) uint8Cycle);

          /* #80 If the job list execution behavior is being tracked, check if the maximum overlap must be updated. */
  #if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
          if((FrIf_Delay < FrIf_MaxTaskOverlap) || (FrIf_MaxTaskOverlap == 0))
          {
            FrIf_MaxTaskOverlap = FrIf_Delay;
          }
  #endif

          /* #85 If there's enough time before the job is supposed to start:
           *        Set the next absolute timer interrupt according to the cycle and job stored as current in the FrIf
           *        status.
           *      Otherwise:
           *        Set the next interrupt to happen as soon as possible, expecting the job will start within the
           *        allowed delay.
           */
          if((FrIf_Delay > (sint16_least)FRIF_SYNC_THRESHOLD) && (FrIf_Delay < (sint16_least)FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX)))
          {
            retVal = FRIF_SET_JLE_TIMER(FRIF_VCLST_IDX, FrIf_Status[FRIF_VCLST_IDX].CurrentCycle, NextJobDataPtr->StartTimeInMacroTicks, FALSE);
          }
          else
          {
            uint16MacroTicks += FRIF_SYNC_THRESHOLD;
            if(uint16MacroTicks >= FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX))
            {
              uint16MacroTicks = uint16MacroTicks - FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCLST_IDX); /* ESCAN00066875 */
              uint8Cycle = NEXT_CYCLE(uint8Cycle);
            }
            retVal = FRIF_SET_JLE_TIMER(FRIF_VCLST_IDX, uint8Cycle, uint16MacroTicks, TRUE);
          }
        }
      }

      /* #90 Exit FRIF_EXCLUSIVE_AREA_1. */
      SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #95 If retrieving the FlexRay global time, setting the timer or the protected range check failed, resync the
       *     job list execution.
       */
      if (retVal == E_NOT_OK)
      {
        FrIf_JobListOutOfSync(FRIF_VCLST_OPT);
      }
    }
    FrIf_Rtm_Stop(FrIf_JobListExec_0); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_JOBLISTEXEC, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* FrIf_JobListExec_0() */ /* PRQA S 6010, 6050, 6080, 6030 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */ /* MD_MSR_STCYC */ /* MD_MSR_STPTH */

/**********************************************************************************************************************
 *  FrIf_JobListExec_0()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRIF_CODE) FrIf_JobListExec_0(void)
{
#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
  FrIf_JobListExec();
#else
  FrIf_JobListExec(0);
#endif
}

#if (FrIf_CommonMaxNumberOfClusters > 1)
/**********************************************************************************************************************
 *  FrIf_JobListExec_1()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRIF_CODE) FrIf_JobListExec_1(void)
{
  FrIf_JobListExec(1);
}
#endif

#if (FRIF_API_AS_MACRO == STD_OFF)
/**********************************************************************************************************************
 *  FrIf_GetCycleLength()
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
FUNC(uint32, FRIF_CODE) FrIf_GetCycleLength(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRIF_E_NO_ERROR;
  uint32 retVal = 0;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30015 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30057 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#else
  /* Multiple FlexRay CCs are currently not supported, so no index translation is required. */
  FRIF_DUMMY_STATEMENT_CONST(FRIF_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Return the duration of a FlexRay cycle in nanoseconds. */
    uint16 numberOfMacroTicksPerCycle = FrIf_GetNumberOfMacroTicksPerCycle(FRIF_VCTRL_IDX);
    uint16 macroTickLengthInNanoSec = FrIf_GetMacroTickLengthInNanoSeconds(FRIF_VCTRL_IDX);

    retVal = (uint32)(numberOfMacroTicksPerCycle * macroTickLengthInNanoSec);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GET_CYCLE_LENGTH, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* #50 Otherwise, return 0. */
  return retVal;
} /* FrIf_GetCycleLength() */

/**********************************************************************************************************************
 *  FrIf_ControllerInit()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_ControllerInit(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29862 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30146 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_ControllerInit with the untranslated CC index as argument. \trace SPEC-30073 */
    /* SPEC-30073 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_ControllerInit(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_CONTROLLERINIT, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_ControllerInit() */

/**********************************************************************************************************************
 *  FrIf_StartCommunication()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_StartCommunication(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30100 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29835 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_StartCommunication with the untranslated CC index as argument. \trace SPEC-29973 */
    /* SPEC-29973 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_StartCommunication(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_STARTCOMMUNICATION, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_StartCommunication() */

/**********************************************************************************************************************
 *  FrIf_HaltCommunication()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_HaltCommunication(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30197 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29937 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
  /* #40 Call Fr_HaltCommunication with the untranslated CC index as argument. \trace SPEC-30199 */
  /* SPEC-30199 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_HaltCommunication(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_HALTCOMMUNICATION, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_HaltCommunication() */

# if (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF)
/**********************************************************************************************************************
 *  FrIf_AbortCommunication()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AbortCommunication(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30002 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30050 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_AbortCommunication with the untranslated CC index as argument. \trace SPEC-29919 */
    /* SPEC-29919 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_AbortCommunication(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ABORTCOMMUNICATION, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_AbortCommunication() */
# endif/* (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF) */

/**********************************************************************************************************************
 *  FrIf_SendWUP()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SendWUP(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30153 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29992 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_SendWUP with the untranslated CC index as argument. \trace SPEC-29983 */
    /* SPEC-29983 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_SendWUP(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_SENDWUP, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_SendWUP() */

# if (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
/**********************************************************************************************************************
 *  FrIf_SetWakeupChannel()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetWakeupChannel(FRIF_VCTRL_ONLY,  
                                                      Fr_ChannelType  FrIf_ChnlIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29977 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29962 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-30144 */
  else if (FrIf_ChnlIdx >= FR_CHANNEL_AB)
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #40 If the initial checks are passed or not required: */
  {
    /* #50 Call Fr_SetWakeupChannel with the channel index and the untranslated CC index as arguments. \trace SPEC-29907 */
    /* SPEC-29907 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_SetWakeupChannel(FRIF_VCTRL_IDX, FrIf_ChnlIdx);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_SETWAKEUPCHANNEL, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_SetWakeupChannel() */
# endif /* (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF) */

/**********************************************************************************************************************
 *  FrIf_AllowColdstart()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AllowColdstart(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29967 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30030 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_AllowColdstart with the untranslated CC index as argument. \trace SPEC-29848 */
    /* SPEC-29848 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_AllowColdstart(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ALLOWCOLDSTART, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_AllowColdstart() */

/**********************************************************************************************************************
 *  FrIf_GetPOCStatus()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetPOCStatus(FRIF_VCTRL_ONLY, 
                                                  P2VAR(Fr_POCStatusType, AUTOMATIC, FRIF_APPL_DATA) FrIf_POCStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30111 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30011 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetPOCStatus with the FrIf_POCStatusPtr and the untranslated CC index as arguments. \trace SPEC-29898 */
    /* SPEC-29898 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required. */
    retVal = Fr_GetPOCStatus(FRIF_VCTRL_IDX, FrIf_POCStatusPtr);                        /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETPOCSTATUS, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetPOCStatus() */

# if (FRIF_CHANNEL_STATUS_ENABLE == STD_ON) /* SPEC-8335 */
/**********************************************************************************************************************
 *  FrIf_GetChannelStatus()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetChannelStatus(FRIF_VCTRL_ONLY, 
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAStatusPtr,
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-8470 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-8317 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetChannelStatus with the channel status pointers and the CC index as arguments */
    retVal = Fr_GetChannelStatus(FRIF_VCTRL_IDX, FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr); /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GET_CHANNEL_STATUS, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetChannelStatus() */
# endif
/* (FRIF_CHANNEL_STATUS_ENABLE == STD_ON) */

# if (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON) /* SPEC-8412 */
/**********************************************************************************************************************
 *  FrIf_GetClockCorrection()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetClockCorrection(FRIF_VCTRL_ONLY,
                                                  P2VAR(sint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_RateCorrectionPtr,
                                                  P2VAR(sint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_OffsetCorrectionPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-8341 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-8361 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetClockCorrection with FrIf_RateCorrectionPtr, FrIf_OffsetCorrectionPtr and the CC index as arguments */
    retVal = Fr_GetClockCorrection(FRIF_VCTRL_IDX, FrIf_RateCorrectionPtr, FrIf_OffsetCorrectionPtr); /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GET_CLOCK_CORRECTION, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetClockCorrection() */
# endif
/* ( FRIF_CLOCK_CORRECTION_ENABLE == STD_ON ) */

# if ( FRIF_NMVECTORSUPPORT == STD_ON ) /* [SPEC-29849] */
/**********************************************************************************************************************
 *  FrIf_GetNmVector()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetNmVector(FRIF_VCTRL_ONLY, 
                                                 P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NmVectorPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30134 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30162 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetNmVector with the FrIf_NmVectorPtr and the CC index as arguments. \trace SPEC-30120 */
    retVal = Fr_GetNmVector(FRIF_VCTRL_IDX, FrIf_NmVectorPtr);                          /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETNMVECTOR, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetNmVector() */
# endif /* ( FRIF_NMVECTORSUPPORT == STD_ON ) */

# if (FRIF_READCCCONFIGSUPPORT == STD_ON)
/**********************************************************************************************************************
 *  FrIf_ReadCCConfig()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_ReadCCConfig(FRIF_VCTRL_ONLY, 
                                                  uint8 FrIf_CCLLParamIndex,
                                                  P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_CCLLParamValue)
{ 
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-8304 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_ReadCCConfig with FrIf_CCLLParamIndex, FrIf_CCLLParamValue and the CC index as arguments. \trace SPEC-8454 */
    retVal = Fr_ReadCCConfig(FRIF_VCTRL_IDX, FrIf_CCLLParamIndex, FrIf_CCLLParamValue); /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_READCCCONFIG, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_ReadCCConfig() */
# endif /* ( STD_ON == FRIF_READCCCONFIGSUPPORT ) */

# if (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON) /* SPEC-30187 */
/**********************************************************************************************************************
 *  FrIf_GetSyncFrameList()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetSyncFrameList(FRIF_VCTRL_ONLY, 
                                                  uint8 FrIf_ListSize,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAEvenListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBEvenListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAOddListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBOddListPtr)
{ 
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29834 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29936 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetSyncFrameList with FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr,
     *     FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr and the CC index as arguments
     */
    retVal = Fr_GetSyncFrameList(FRIF_VCTRL_IDX, FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr); /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETSYNCFRAMELISTSUPPORT, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetSyncFrameList() */ /* PRQA S 6060 */ /* MD_MSR_STPAR */
# endif /* ( FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON ) */

# if (FRIF_RECONFIGLPDUSUPPORT == STD_ON) /* SPEC-29942 */
/**********************************************************************************************************************
 *  FrIf_ReconfigLPdu()
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
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_ReconfigLPdu(FRIF_VCTRL_ONLY, 
                                                  uint16 FrIf_LPduIdx,
                                                  uint16 FrIf_FrameId,
                                                  Fr_ChannelType FrIf_ChnlIdx,
                                                  uint8 FrIf_CycleRepetition,
                                                  uint8 FrIf_CycleOffset,
                                                  uint8 FrIf_PayloadLength,
                                                  uint16 FrIf_HeaderCRC)
{ 
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30090 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  /* #30 If required, check the validity of the FlexRay channel index given as input. \trace SPEC-29990 */
  else if (FrIf_ChnlIdx > FR_CHANNEL_AB)
  {
    errorId = FRIF_E_INV_CHNL_IDX;
  }
  /* #40 If required, check the validity of the L-PDU index given as input. \trace SPEC-30150 */
  else if (FrIf_LPduIdx > ((FrIf_GetInvalidRxHandle(FRIF_VCTRL_IDX) + FrIf_GetInvalidTxHandle(FRIF_VCTRL_IDX)) - 1))
  {
    errorId = FRIF_E_INV_LPDU_IDX;
  }
  /* #50 If required, check the validity of the FlexRay frame ID given as input. \trace SPEC-30129 */
  else if (FrIf_FrameId > 2047)
  {
    errorId = FRIF_E_INV_FRAME_ID;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #60 If the initial checks are passed or not required: */
  {
    /* #70 Call Fr_ReconfigLPdu with FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset,
     *     FrIf_PayloadLength, FrIf_HeaderCRC and the CC index as arguments
     */
    retVal = Fr_ReconfigLPdu(FRIF_VCTRL_IDX, FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset, FrIf_PayloadLength, FrIf_HeaderCRC);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_RECONFIG_LPDU, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_ReconfigLPdu() */ /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
# endif /* ( FRIF_RECONFIGLPDUSUPPORT == STD_ON ) */

# if (FRIF_DISABLELPDUSUPPORT == STD_ON) /* SPEC-30121 */
/**********************************************************************************************************************
 *  FrIf_DisableLPdu()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableLPdu(FRIF_VCTRL_ONLY, uint16 FrIf_LPduIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29997 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30001 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_DisableLPdu with the L-PDU and CC indexes as arguments */
    retVal = Fr_DisableLPdu(FRIF_VCTRL_IDX, FrIf_LPduIdx);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_DISABLE_LPDU, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_DisableLPdu() */
# endif /* ( FRIF_DISABLELPDUSUPPORT == STD_ON) */

#if (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON) /* SPEC-29975 */
/**********************************************************************************************************************
 *  FrIf_GetNumOfStartupFrames()
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
FUNC(Std_ReturnType, FRIF_CODE)FrIf_GetNumOfStartupFrames(FRIF_VCTRL_ONLY, P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NumOfStartupFramesPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29958 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29952 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetNumOfStartupFrames with the FrIf_NumOfStartupFramesPtr and the CC index as arguments */
    retVal = Fr_GetNumOfStartupFrames(FRIF_VCTRL_IDX, FrIf_NumOfStartupFramesPtr);      /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETNUMOFSTARTUPFRAMES, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetNumOfStartupFrames() */
#endif /* (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON) */

#if (FRIF_ALLSLOTSSUPPORT == STD_ON) /* SPEC-30066 */
/**********************************************************************************************************************
 *  FrIf_AllSlots()
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
FUNC(Std_ReturnType, FRIF_CODE)FrIf_AllSlots(FRIF_VCTRL_ONLY)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30004 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29993 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_AllSlots with the CC index as argument */
    retVal = Fr_AllSlots(FRIF_VCTRL_IDX);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_ALLSLOTS, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_AllSlots() */
#endif /* (FRIF_ALLSLOTSSUPPORT == STD_ON) */

#if (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON) /* SPEC-30116 */
/**********************************************************************************************************************
 *  FrIf_GetWakeupRxStatus()
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
FUNC(Std_ReturnType, FRIF_CODE)FrIf_GetWakeupRxStatus(FRIF_VCTRL_ONLY, P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_WakeupRxStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30016 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-30117 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetWakeupRxStatus with the FrIf_WakeupRxStatusPtr and CC index as arguments */
    retVal = Fr_GetWakeupRxStatus(FRIF_VCTRL_IDX, FrIf_WakeupRxStatusPtr);              /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETWAKEUPRXSTATUS, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_GetWakeupRxStatus() */
#endif /* (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON) */

#endif /* (FRIF_API_AS_MACRO == STD_ON) */

#if (FRIF_CANCELTRANSMITSUPPORT == STD_ON) /* SPEC-30148 */
/**********************************************************************************************************************
 *  FrIf_CancelTransmit()
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
FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelTransmit(PduIdType FrTxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;
  sint16_least Handle;

#if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #05 Derive the index of the cluster related to the PDU. \trace SPEC-29968 */
  uint8 FrIf_CtrlIdx = FrIf_GetClusterIndex(FrTxPduId);
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-30149 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay PDU ID given as input. \trace SPEC-30056 */
  else if (FrIf_IsFrTxPduIdInvalid(FrTxPduId))
  {
    errorId = FRIF_E_INV_TXPDUID;
  }
  else
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #30 If the initial checks are passed or not required: */
  {
# if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FRIF_VCTRL_IDX, FrIf_GetInternalTxPduId(FrTxPduId));
# endif 

    /* #40 Enter FrIf_FRIF_EXCLUSIVE_AREA_0. */
    SchM_Enter_FrIf_FRIF_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #50 Flag the FlexRay PDU as non-dirty. */
# if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
    FrIf_GetTxPduDirtyByte(FRIF_VCTRL_IDX, FrTxPduId) = FALSE;                                         /* SBSW_FRIF_DIRTY_BYTES_WRT2 */
# else
    FrIf_ClearBit(FrIf_GetTxPduDirtyBits(FRIF_VCTRL_IDX), FrTxPduId);                                 /* SBSW_FRIF_DIRTY_BITS_WRT2 */
# endif

    /* #60 If request counters are enabled and the PDU has one:
     *       Set the PDU's request counter to 0. */
# if (FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF)
    if((TxPduDescriptorPtr->PduConfig & FrIf_TxPduHasTxRequestCounter) == FrIf_TxPduHasTxRequestCounter)
    {
      const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;
      FrIf_GetTxPduTxRequestCounter(FRIF_VCTRL_IDX, TxReqCounterIndex) = 0;                        /* SBSW_FRIF_REQUEST_COUNTER_WRT3 */
    }
# endif

    /* #70 Exit FrIf_FRIF_EXCLUSIVE_AREA_0. */
    SchM_Exit_FrIf_FRIF_EXCLUSIVE_AREA_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /**
     * Internal comment removed.
 *
 *
 *
     */

    /* #80 For each FlexRay frame: */
    for (Handle = (sint16_least)(FrIf_GetInvalidTxHandle(FRIF_VCTRL_IDX) - 1); Handle >= (sint16_least) 0; Handle--)
    {
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(FRIF_VCTRL_IDX, Handle);
      sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
      uint16_least FrameLayoutElIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle);

      /* #90 If the frame contains the PDU requested to be cancelled and the PDU has been flagged as sent (non-confirmed):
       *       Request the Fr to cancel any pending transmission of the FlexRay frame for the derived cluster index.
       *       Flag all PDUs in frame as non-sent.
       */
      for(; PduNumber >= (sint16_least) 0; PduNumber--) 
      {
        PduIdType TmpFrTxPduId = FrIf_GetTxFrameLayoutElement(FRIF_VCTRL_IDX, FrameLayoutElIndex).PduHandle;
        if (    (FrTxPduId == TmpFrTxPduId) 
             && (FrIf_GetTxPduWasSentFlags(FRIF_VCTRL_IDX, Handle) != FALSE))
        {
          retVal = Fr_CancelTxLPdu(FRIF_VCTRL_IDX, (uint16)Handle);
          FrIf_GetTxPduWasSentFlags(FRIF_VCTRL_IDX, Handle) = FALSE;                                    /* SBSW_FRIF_SENT_FLAGS_RST2 */
          break;
        }
        FrameLayoutElIndex++;
      }
    }
  }   

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_CANCEL_TRANSMIT, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrIf_CancelTransmit() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* ( FRIF_CANCELTRANSMITSUPPORT == STD_ON ) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* Justification for module-specific MISRA deviations:
 MD_FrIf_0310:    Rule 11.4
      Reason:     The downcast between pointer and integral type is required for efficient implementation.
      Risk:       There is no risk as the cast is a downcast.
      Prevention: Covered by code review.
 MD_FrIf_3408:    Rule 8.8
      Reason:     FrIf_RxHandles and FrIf_TxHandles have external linkage but are being defined without any previous declaration.
      Risk:       There is no risk since these structs are only used in either FrIf_Lcfg.c or FrIf_PBcfg.c.
      Prevention: Covered by code review.
 MD_FrIf_3356:    Rule 13.7
      Reason:     The result of this logical operation is always 'false' depending on the FrIf configuration.
      Risk:       There is no risk that dead code is untested, because these conditions are fullfilled in other (processor equivalent) config variants.
      Prevention: Not required.
 MD_FrIf_3673:    Rule 16.7
      Reason:     The object addressed by the pointer parameter is not modified and so the pointer could be of type 'pointer to const' depending on the configuration.
      Risk:       The function interface could not be defined more precisely because the usage of the FrameBuffer is config dependent.
      Prevention: Not required.
 MD_FrIf_0812:    No rule applicable
      Reason:     The arrays in file FrIf_PBcfg.h and FrIf_Lcfg.h are declared as extern without size specification since their size depend on the configuration in GENy.
      Risk:       There is no risk because these arrays are only used by FrIf.
      Prevention: Covered by code review.
 MD_FrIf_0342:    Rule: 19.13: K&R compilers do not support the ISO glue operator ##.
     Reason:      Identifier has to be a combination of both IDs
     Risk:        Compile error.
     Prevention:  Not required.
 MD_FrIf_5102:    Rule 17.5: The declaration of objects should contain no more than 2 levels of pointer indirection.
     Reason:      The indirection level is required in configurations were single-controller optimization is disabled and a root structure is used.
     Risk:        Resulting code is difficult to understand or may not work as expected.
     Prevention:  Code review and testing of the affected configuration variant.
 MD_FrIf_3410:    Rule 19.10: Macro parameter not enclosed in ().
     Reason:      Enclosing the macro parameter in parentheses leads to a syntax error.
     Risk:        None since the parameter is expected to be the name of a struct member and not a number.
     Prevention:  Code review and testing using configurations where the macro is actually used.
*/

/* COV_JUSTIFICATION_BEGIN

--- Preprocessor Coverage Justifications ------------------------------------------------------------------------------

\ID COV_FRIF_MSR_COMPATIBILITY
\ACCEPT TX 
\ACCEPT XF 
\REASON [COV_MSR_COMPATIBILITY]

\ID COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE
\ACCEPT TX 
\ACCEPT XF 
\ACCEPT XF xf xf 
\ACCEPT XF tx xf 
\ACCEPT XF tx xx
\ACCEPT TF tf xf
\REASON [COV_MSR_UNSUPPORTED] The following features are not supported by FrIf in SafeBSW usecase and the corresponding preprocessor switches must be configured according to CM_FRIF_QMDEFINES and CM_FRIF_MAX_NUM_CLST. This is guaranteed by the MSSV plugin.

\ID COV_FRIF_TESTSUITE_INSTRUMENTATION
\ACCEPT TX 
\ACCEPT XF 
\REASON Not all branches covered because the following preprocessor macros and defines are necessary for proper test execution with FrTestSuite: FRIF_FRAME_TRANSMITTED, FRIF_FRAME_RECEIVED, FRIF_UNIT_TEST

\ID COV_FRIF_SOURCE
\ACCEPT XF 
\REASON Only False branch is covered because FRIF_SOURCE is only defined in FrIf.c and the macros shall only be redefined in the C-file (not in the header). Otherwise the single channel API optimization does not work properly.

\ID COV_FRIF_DBA_BUFFER_REQUEST_FAILED
  \ACCEPT TF tx tf
  \ACCEPT TX
  \REASON In configurations with FRIF_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON it is possible that the Fr driver provides no message buffer for transmission. In this case a dirty flagged frame shall not be  transmitted by the FrIf.

--- Condition Coverage Justifications ---------------------------------------------------------------------------------

\ID COV_FRIF_CTRL_OPTIMIZATION
    \ACCEPT XF
    \REASON If FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON, the given ClstIdx/CtrlIdx is 0 and always valid.

COV_JUSTIFICATION_END */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_FRIF_FCT_CALL_PTR2LOCAL
  \DESCRIPTION    Function call with a pointer to a local variable as argument.
  \COUNTERMEASURE \N Pointers to local variables can be safely considered to be valid.

\ID SBSW_FRIF_FCT_CALL_PTRFWD
  \DESCRIPTION    Function call with an unchanged pointer forwarded as argument.
  \COUNTERMEASURE \N The original caller guarantees the validity of the forwarded pointer.

\ID SBSW_FRIF_FCT_CALL_BUFFRTX
  \DESCRIPTION    An Fr Tx function is called with a pointer to a frame buffer as argument.
  \COUNTERMEASURE \R If DBA is disabled, the pointer references a static array defined by the FrIf. Otherwise, the
                  pointer has been provided by the Fr and assumed to be valid only if the frame buffer has been
                  successfully acquired.

\ID SBSW_FRIF_FCT_CALL_BUFFRRX
  \DESCRIPTION    An Fr Rx function is called with a pointer to a frame buffer as argument.
  \COUNTERMEASURE \N If DBA is disabled, the pointer references a static array defined by the FrIf. Otherwise, the
                  pointer is provided by the Fr within the function.

\ID SBSW_FRIF_FCT_CALL_BUFFRIFTX
  \DESCRIPTION    A FrIf Tx internal function is called with a pointer to a local variable as argument.
  \COUNTERMEASURE \R If DBA is disabled, the local variable is a pointer to a static buffer defined by the FrIf.
                  Otherwise, the buffer is provided by the Fr within the internal function and assumed to be valid only
                  if it is successfully acquired.

\ID SBSW_FRIF_FCT_CALL_PTRDBA
  \DESCRIPTION    An unchanged pointer is forwarded the Fr in order to obtain a pointer to a frame buffer. The buffer
                  returned by the Fr is assumed to be valid only if it is successfully acquired.
  \COUNTERMEASURE \N The original caller guarantees the validity of the forwarded pointer.

\ID SBSW_FRIF_FCT_CALL_BUFFRIFRX
  \DESCRIPTION    A FrIf Rx internal function is called with a pointer to a frame buffer as argument.
  \COUNTERMEASURE \R If DBA is disabled, the pointer references a static array defined by the FrIf. Otherwise, the
                  pointer has been provided by the Fr and the internal function will assume it is valid only if the
                  frame has been flagged as received.

\ID SBSW_FRIF_FCT_CALL_REDPDUINFO
  \DESCRIPTION    RxVoting function call with a pointer to a pointer to the FrIf's array of redundant Rx PDU info
                  structs as argument.
  \COUNTERMEASURE \R The pointer can be considered to be valid, since it's set during initialization and the array of
                  redundant Rx PDU info is defined by the FrIf . The pointers within the structs contained in the
                  referenced array can also be considered to be valid or NULL, since the function
                  FrIf_FillRedundantRxPduInfo checks if the received PDUs are contained within the frame buffer.

\ID SBSW_FRIF_FCT_CALL_REDRXINDICATION
  \DESCRIPTION    Rx indication function call with a pointer to the payload of a redundant Rx PDU and its length.
  \COUNTERMEASURE \S The RxVoting function shall return E_NOT_OK if all the redundant Rx PDUs are invalid (NULL payload
                  pointer and length 0).
                  \R The function call occurs only if the RxVotingFunction returns E_OK. (filters NULL payload pointers)
                  \R The pointer to the PDU's payload and the length can be considered to be valid, since the function
                  FrIf_FillRedundantRxPduInfo checks if the received PDUs are contained within the frame buffer.

\ID SBSW_FRIF_FCT_CALL_RXINDICATION
  \DESCRIPTION    Rx indication function call with a pointer to the payload of a non-redundant Rx PDU and its length.
  \COUNTERMEASURE \R [CM_FRIF_PDU_INFO]

\ID SBSW_FRIF_FCT_CALL_TRIGGERTX
  \DESCRIPTION    Trigger Tx function call with a pointer to the memory location within a frame buffer where the
                  payload of a Tx PDU shall be written, and a pointer to a local variable to store the length of the
                  written payload.
  \COUNTERMEASURE \M [CM_FRIF_PDU_FIT]

\ID SBSW_FRIF_FCT_CALL_FILLFRAME1
  \DESCRIPTION    MemSet function call to initialize the bytes between a given memory location within a frame buffer
                  and the start of a PDU-in-frame. If DBA is disabled, the pointer references a static array defined by
                  the FrIf. Otherwise, the validity of the pointer must be guaranteed by the Fr.
  \COUNTERMEASURE \R The function call occurs only if the given memory location is located before the start of the PDU.
                  \M [CM_FRIF_PDU_FIT]

\ID SBSW_FRIF_FCT_CALL_FILLFRAME2
  \DESCRIPTION    MemSet function call to initialize the bytes between a given memory location within a frame buffer
                  and the buffer's end. If DBA is disabled, the pointer references a static array defined by the FrIf.
                  Otherwise, the validity of the pointer must be guaranteed by the Fr.
  \COUNTERMEASURE \R The function call occurs only if the given memory location is located before the frame's end.

\ID SBSW_FRIF_FCT_CALL_FILLFRAME3
  \DESCRIPTION    Array write access to initialize the first 4 bytes the frame buffer. In this case, the frame buffer
                  is a static array defined by the FrIf.
  \COUNTERMEASURE \M [CM_FRIF_FBUFF_SIZE]

\ID SBSW_FRIF_FCT_CALL_REDCOPY
  \DESCRIPTION    MemCpy function call to copy the payload of a redundant pair of Tx frames.
  \COUNTERMEASURE \R The frame buffers are provided by the Fr and the FrIf checks if the buffers were succesfully acquired
                  before using them.

\ID SBSW_FRIF_FCT_CALL_PTR2TXPDUDESC1
  \DESCRIPTION    Function call with a pointer to a Tx PDU descriptor. The Tx PDU descriptor is obtained from a Tx PDU
                  handle given as input
  \COUNTERMEASURE \R [CM_FRIF_INVTXPDU]
                  \M [CM_FRIF_TXPDUTRANS]
                  \M [CM_FRIF_TXPDUDESC_SIZE]

\ID SBSW_FRIF_FCT_CALL_PTR2TXPDUDESC2
  \DESCRIPTION    Function call with a pointer to a Tx PDU descriptor. The Tx PDU descriptor is obtained from a Tx
                  frame handle given as input
  \COUNTERMEASURE \M [CM_FRIF_FLE_SIZE]
                  \M [CM_FRIF_TXPDUTRANS]
                  \M [CM_FRIF_TXPDUDESC_SIZE]

\ID SBSW_FRIF_FCT_CALL_PTR2TXFRAMEDESC
  \DESCRIPTION    Function call with a pointer to a Tx frame descriptor.
  \COUNTERMEASURE \R [CM_FRIF_INVTXFRAME]
                  \M [CM_FRIF_FRAMETRANS]
                  \M [CM_FRIF_FRAMEDESC_SIZE]

\ID SBSW_FRIF_FCT_CALL_PTR2RXFRAMEDESC
  \DESCRIPTION    Function call with a pointer to an Rx frame descriptor.
  \COUNTERMEASURE \R [CM_FRIF_INVRXFRAME]
                  \M [CM_FRIF_FRAMETRANS]
                  \M [CM_FRIF_FRAMEDESC_SIZE]

\ID SBSW_FRIF_FCT_CALL_PTR2PDUINFO
  \DESCRIPTION    Function call with a pointer to a PduInfo struct.
  \COUNTERMEASURE \N The struct is a local variable, so the pointer to it can be considered to be valid. The length and
                  the pointer to the payload contained in the struct are just forwarded unchanged, since the original
                  caller guarantees their validity.

\ID SBSW_FRIF_FCT_PTR_FRTRCVMAP
  \DESCRIPTION    A CC index and channel index pair given as input is used by the FrIf to determine the right FrTrcv
                  function to be called. Since multiple CCs are currently not supported, no real translation takes
                  place and the channel index given as input is used unchanged as transceiver index.
  \COUNTERMEASURE \R [CM_FRIF_INVCHIDX]
                  \R [CM_FRIF_INVFRTRCVMAPIDX]
                  \M [CM_FRIF_TRCVDESC_SIZE]
                  \S It is expected that the FrTrcv checks if the TrcvIdx passed to the FrTrcv_* functions are within
                  a valid range. The FrIf can't guarantee the validity of this parameter, since several FrTrcv modules
                  containing a different number of channels could be referenced.

\ID SBSW_FRIF_PTR_WRT_UNCHANGED
  \DESCRIPTION    Pointer write access by dereferencing a pointer given as input without any changes.
  \COUNTERMEASURE \N The original caller guarantees the validity of the pointer.

\ID SBSW_FRIF_STRUCT_WRT_UNCHANGED
  \DESCRIPTION    Write access to the members of a struct using an unchanged pointer.
  \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID SBSW_FRIF_DIRTY_BYTES_RST
  \DESCRIPTION    Array write access to all the dirty bytes (1 byte per Tx PDU, all grouped in FrIf_TxPduDirtyBytes[]).
                  The used index used in the loop ranges from 0 to FrIf_CommonMaxTxPduId (if single controller
                  optimization is enabled) or the maximum Tx PDU Id related to each controller (if single controller
                  optimization is disabled).
  \COUNTERMEASURE \M [CM_FRIF_DIRTYBYTES_SIZE]

\ID SBSW_FRIF_DIRTY_BITS_RST
  \DESCRIPTION    Array write access to all the dirty bits (1 bit per Tx PDU, all grouped in FrIf_TxPduDirtyBits[]).
                  Since the writing is done bytewise, the index used in the loop ranges from 0 to
                  FrIf_CommonMaxTxPduId / 8 (if single controller optimization is enabled) or the maximum Tx PDU Id
                  related to each controller divided by 8 (if single controller optimization is disabled).
  \COUNTERMEASURE \M [CM_FRIF_DIRTYBITS_SIZE]

\ID SBSW_FRIF_DIRTY_BYTES_WRT1
  \DESCRIPTION    Array write access to the dirty byte of a specific Tx PDU. The index used to access
                  FrIf_TxPduDirtyBytes[] is obtained from a Tx frame layout element and used unchanged.
  \COUNTERMEASURE \M [CM_FRIF_DIRTYBYTES_SIZE]

\ID SBSW_FRIF_DIRTY_BYTES_WRT2
  \DESCRIPTION    Array write access to the dirty byte of a specific Tx PDU. The index used to access
                  FrIf_TxPduDirtyBytes[] is given as input by the caller and used unchanged.
  \COUNTERMEASURE \R [CM_FRIF_INVTXPDU]

\ID SBSW_FRIF_DIRTY_BITS_WRT1
  \DESCRIPTION    Array write access to the dirty bit of a specific Tx PDU. The index used to access
                  FrIf_TxPduDirtyBits[] is equal to FrTxPduId / 8, where FrTxPduId is obtained from a Tx frame layout
                  element.
  \COUNTERMEASURE \M [CM_FRIF_DIRTYBITS_SIZE]

\ID SBSW_FRIF_DIRTY_BITS_WRT2
  \DESCRIPTION    Array write access to the dirty bit of a specific Tx PDU. The index used to access
                  FrIf_TxPduDirtyBits[] is equal to FrTxPduId / 8, where FrTxPduId is given as input by the caller.
  \COUNTERMEASURE \R [CM_FRIF_INVTXPDU]
                  \M [CM_FRIF_DIRTYBITS_SIZE]

\ID SBSW_FRIF_SENT_FLAGS_RST1
  \DESCRIPTION    Array write access to all the was-sent flags (1 byte per Tx frame, all grouped in
                  FrIf_TxPduWasSentFlags[]). The index used in the loop ranges from 0 to FrIf_CommonMaxTxFrameId (if
                  single controller optimization is enabled) or the maximum Tx frame Id related to each controller (if
                  single controller optimization is disabled).
  \COUNTERMEASURE \M [CM_FRIF_SENTFLAGS_SIZE]

\ID SBSW_FRIF_SENT_FLAGS_RST2
  \DESCRIPTION    Array write access to all the was-sent flags of a configuration variant. The index used in the loop
                  ranges from 0 to InvalidTxHandle - 1.
  \COUNTERMEASURE \M [CM_FRIF_SENTFLAGS_SIZE]

\ID SBSW_FRIF_SENT_FLAGS_WRT1
  \DESCRIPTION    Array write access to the was-sent flags of a specific Tx frame. The index used to access the array
                  FrIf_TxPduWasSentFlags[] is obtained by the caller from the communication matrix.
  \COUNTERMEASURE \M [CM_FRIF_JOBDATA_SIZE]
                  \M [CM_FRIF_JOBDATA_COLUMNS]
                  \M [CM_FRIF_JOBDATA_TXCONF]
                  \M [CM_FRIF_CYCLE_MASKS]
                  \R [CM_FRIF_INVTXFRAME]
                  \M [CM_FRIF_SENTFLAGS_SIZE]

\ID SBSW_FRIF_SENT_FLAGS_WRT2
  \DESCRIPTION    Array write access to the was-sent flags of a specific Tx frame. The index used to access the array
                  FrIf_TxPduWasSentFlags[] is obtained from a Tx PDU handle given as input.
  \COUNTERMEASURE \R [CM_FRIF_INVTXPDU]
                  \R [CM_FRIF_IMMEDIATETXPDU]
                  \M [CM_FRIF_IMMEDIATETX_IDX]

\ID SBSW_FRIF_REQUEST_COUNTERS_RST
  \DESCRIPTION    Array write access to all the Tx request counters (1 byte per Tx PDU configured with a Tx request
                  counter, all grouped in FrIf_TxPduTxRequestCounters[]). The index used in the loop ranges from 0 to
                  FrIf_CommonMaxNumberOfTxRequestCounters - 1 (if single controller optimization is enabled) or the
                  number of Tx request counters related to each controller - 1 (if single controller optimization is
                  disabled).
  \COUNTERMEASURE \M [CM_FRIF_TXREQCOUNTERS_SIZE]

\ID SBSW_FRIF_REQUEST_COUNTER_WRT1
  \DESCRIPTION    Array write access to the Tx request counter of a specific Tx PDU. The index used to access
                  FrIf_TxPduTxRequestCounters[] is obtained from a Tx PDU descriptor given as input.
  \COUNTERMEASURE \M [CM_FRIF_TXREQCOUNTERS_SIZE]

\ID SBSW_FRIF_REQUEST_COUNTER_WRT2
  \DESCRIPTION    Array write access to the Tx request counter of a specific Tx PDU. The index used to access
                  FrIf_TxPduTxRequestCounters[] is obtained from a Tx frame layout element.
  \COUNTERMEASURE \M [CM_FRIF_FLE_SIZE]
                  \M [CM_FRIF_TXPDUTRANS]
                  \M [CM_FRIF_TXPDUDESC_SIZE]
                  \M [CM_FRIF_TXREQCOUNTERS_SIZE]

\ID SBSW_FRIF_STATUS_WRT
  \DESCRIPTION    Array write access to the FrIf's cluster status. The index used to access FrIf_Status[] is obtained
                  from a Tx pdu translation table, given as input to the function where the writing takes places or
                  within a loop that ranges from 0 to the number of clusters - 1.
  \COUNTERMEASURE \R [CM_FRIF_INVCLST]
                  \M [CM_FRIF_TXPDUTRANS]
                  \M [CM_FRIF_MAX_NUM_CLST]

\ID SBSW_FRIF_REQUEST_COUNTER_WRT3
  \DESCRIPTION    Array write access to the Tx request counter of a specific Tx PDU. The index used to access
                  FrIf_TxPduTxRequestCounters[] is obtained from a Tx PDU handle given as input.
  \COUNTERMEASURE \R [CM_FRIF_INVTXPDU]
                  \M [CM_FRIF_TXPDUTRANS]
                  \M [CM_FRIF_TXPDUDESC_SIZE]
                  \M [CM_FRIF_TXREQCOUNTERS_SIZE]

\ID SBSW_FRIF_UPDATE_BITS_WRT
  \DESCRIPTION    Array write access to the byte containing the update-bit of a Tx PDU within a Tx frame.
  \COUNTERMEASURE \M [CM_FRIF_UPDATEBITBYTE_POS]

\ID SBSW_FRIF_FILL_REDUNDANT_INFO
  \DESCRIPTION    Array write access to fill the structs containing information of a redundant pair of Rx PDUs. The
                  structs are grouped in FrIf_RedundantRxPduInfo[] and accessed with an index given as input to the
                  internal function FrIf_FillRedundantRxPduInfo. The indexes given are always 0 and 1.
  \COUNTERMEASURE \M The size of FrIf_RedundantRxPduInfo[] must be 2.

\ID SBSW_FRIF_P2REDUNDANT_INFO_WRT
  \DESCRIPTION    Array write access to fill the array containing the pointers to the FrIf_RedundantRxPduInfo[] arrays
                  of each cluster. The index used to access the array ranges from 0 to the number of clusters - 1.
  \COUNTERMEASURE \M [CM_FRIF_MAX_NUM_CLST]

SBSW_JUSTIFICATION_END */

/*
\CM CM_FRIF_JOBDATA_SIZE    Size of FrIf_RxTxTaskScheduleData[] must be equal to FrIf_NumberOfJobs. This check must be
                            done per configuration variant.
*/

/*
\CM CM_FRIF_JOBDATA_COLUMNS    The MinColumnNumber and MaxColumnNumber of each valid Tx/Rx job (MinColumnNumber not
                               equal to 255 and MaxColumnNumber not equal to 254) must be within the bounds of
                               FrIf_TxHandles[]/FrIf_RxHandles[] and FrIf_TxCycleMasks[]/FrIf_RxCycleMasks[]. This
                               check must be done per configuration variant.
*/

/*
\CM CM_FRIF_JOBDATA_TXCONF    The MinTxConfJobNo and MaxTxConfJobNo of each valid Tx confirmation job (MinTxConfJobNo
                              not equal to 255 and MaxTxConfJobNo not equal to MaxTxConfJobNo not equal to 254) must be
                              within the bounds of FrIf_RxTxTaskScheduleData[]. This check must be done per
                              configuration variant.
*/

/*
\CM CM_FRIF_CYCLE_MASKS    FrIf_TxCycleMasks[n]/FrIf_RxCycleMasks[n] must be within the bounds of the array stored at
                           FrIf_TxHandles[n]/FrIf_RxHandles[n]. This check must be done per configuration variant.
*/

/*
\CM CM_FRIF_DIRTYBYTES_SIZE    1. If FRIF_CTRL_ENABLE_API_OPTIMIZATION is set to STD_ON , the size of
                                  FrIf_TxPduDirtyBytes[] must be equal to FrIf_CommonMaxTxPduId + 1.
                               2. If FRIF_CTRL_ENABLE_API_OPTIMIZATION is set to STD_OFF, the size of
                                  FrIf_TxPduDirtyBytes[] of each controller must be equal to the maximum Tx PDU Id
                                  related to the controller + 1.
                               3. The PduHandle of all the Tx FrIf_FrameLayoutElements must be within the bounds of
                                  FrIf_TxPduDirtyBytes[].
*/

/*
\CM CM_FRIF_DIRTYBITS_SIZE    1. If FRIF_CTRL_ENABLE_API_OPTIMIZATION is set to STD_ON, the size of
                                 FrIf_TxPduDirtyBits[] must be equal to (FrIf_CommonMaxTxPduId / 8) + 1.
                              2. If FRIF_CTRL_ENABLE_API_OPTIMIZATION is set to STD_OFF, the size of
                                 FrIf_TxPduDirtyBits[] of each controller must be equal to the maximum Tx PDU Id
                                 related to the controller divided by 8, plus 1.
                              3. (PduHandle / 8) of all the Tx FrIf_FrameLayoutElements must be within the bounds of
                                 FrIf_TxPduDirtyBits[].
*/

/*
\CM CM_FRIF_TXREQCOUNTERS_SIZE   1. The TxRequestCounterIndex of all the FrIf_TxPduDescriptors where
                                    PduConfig & FrIf_TxPduHasTxRequestCounter != 0 must be within the bounds of
                                    FrIf_TxPduTxRequestCounters[].
                                 2. If FrIf_TxPduDescriptors where PduConfig & FrIf_TxPduHasTxRequestCounter != 0
                                    exist, Size of FrIf_TxPduTxRequestCounters[] must be
                                    FrIf_CommonMaxNumberOfTxRequestCounters.
*/

/*
\CM CM_FRIF_SENTFLAGS_SIZE    1. Size of FrIf_TxPduWasSentFlags[] must be FrIf_CommonMaxTxFrameId + 1.
                              2. All valid Tx frame handles (not InvalidTxHandle) in the communication matrix must be
                                 within the bounds of FrIf_TxPduWasSentFlags[].
*/

/*
\CM CM_FRIF_MAX_NUM_CLST       1. FrIf_CommonMaxNumberOfClusters must be equal to 1.
*/

/*
\CM CM_FRIF_TXPDUTRANS    In post-build configurations:
                          1. Size of FrIf_TxPduTranslationTable[] must be equal to InvalidTxPduHandle.
                          2. The PduHandle of each Tx FrIf_FrameLayoutElement must be within the bounds of
                             FrIf_TxPduTranslationTable[].
                          3. The InternalTxPduIds obtained from TxPduTranslationTable[] when using the PduHandles of
                             each Tx FrIf_FrameLayoutElement as index must be valid (not InvalidTxPduHandle).
                          4. The controller index obtained from TxPduTranslationTable[] must be valid.

                          These checks must be done per configuration variant.
*/

/*
\CM CM_FRIF_TXPDUDESC_SIZE    In non-post-build configurations:
                              1. Size of FrIf_TxPduDescriptors[] must be equal to InvalidTxPduHandle.
                              2. The PduHandle of all the Tx FrIf_FrameLayoutElements must be within the bounds of
                                 FrIf_TxPduDescriptors[]. This check must be done per configuration variant.

                              In post-build configurations:
                              All valid InternalTxPduIds (not InvalidTxPduHandle) in TxPduTranslationTable[] must be
                              within the bounds of FrIf_TxPduDescriptors[]. This check must be done per configuration
                              variant
*/

/*
\CM CM_FRIF_FLE_SIZE    Size of FrIf_TxFrameLayoutElements[]/FrIf_RxFrameLayoutElements[] must be greater than or equal
                        to the sum (FirstFrameLayoutElementHandle + NumberOfPdus) for each Rx/Tx FrIf_FrameDescriptor.
*/

/*
\CM CM_FRIF_FRAMETRANS    In post-build configurations:
                          1. All valid Tx/Rx frame handles (not InvalidTxHandle/InvalidRxHandle) in the communication
                             matrix must be within the bounds of
                             FrIf_TxLPduTranslationTable[]/FrIf_RxLPduTranslationTable[].
                          2. The handles obtained from FrIf_TxLPduTranslationTable[]/FrIf_RxLPduTranslationTable[] when
                             using the valid handles (not InvalidTxHandle/InvalidRxHandle) from the Tx/Rx communication
                             matrix as index must be different from InvalidTxHandle/InvalidRxHandle.
*/

/*
\CM CM_FRIF_FRAMEDESC_SIZE    In non-post-build configurations:
                              All valid Tx/Rx frame handles (not InvalidTxHandle/InvalidRxHandle) in the communication
                              matrix must be within the bounds of FrIf_TxFrameDescriptors[]/FrIf_RxFrameDescriptors[].

                              In post-build configurations:
                              The valid frame handles (not InvalidTxHandle/InvalidRxHandle) in
                              FrIf_TxLPduTranslationTable[]/FrIf_RxLPduTranslationTable[] must be within the bounds of
                              FrIf_TxFrameDescriptors[]/FrIf_RxFrameDescriptors[].
*/

/*
\CM CM_FRIF_UPDATEBITBYTE_POS    1. If both FRIF_UNIFORMUPDATEBYTEPOS and FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS
                                    are set to STD_ON, the value of FrIf_UpdateBitBytePos must be less than the
                                    FrameLength in all the Tx/Rx FrIf_FrameDescriptors where
                                    FrameConfig & FrIf_FrameHasPduWithUpdateBit != 0.
                                 2. If only FRIF_UNIFORMUPDATEBYTEPOS is set to STD_ON, the UpdateBitBytePos must be
                                    less than the FrameLength in all the Tx/Rx FrIf_FrameDescriptors where
                                    FrameConfig & FrIf_FrameHasPduWithUpdateBit != 0.
                                 3. If neither FRIF_UNIFORMUPDATEBYTEPOS nor
                                    FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS are set to STD_ON, the FrameLength in
                                    the Tx/Rx FrIf_FrameDescriptors, where
                                    FrameConfig & FrIf_FrameHasPduWithUpdateBit != 0, must be greater than the
                                    UpdateBitBytePos in all the Tx/Rx FrIf_FrameLayoutElements related to the frame
                                    (frame layout elements with index ranging from FirstFrameLayoutElementHandle to
                                    (FirstFrameLayoutElementHandle + NumberOfPdus - 1)).
*/

/*
\CM CM_FRIF_IMMEDIATETX_IDX    In non-post-build configurations:
                               The index within FrIf_TxPduDescriptors[] of each FrIf_TxPduDescriptor where
                               PduConfig & FrIf_TxPduIsImmediateTx != 0 must be be within the bounds of
                               FrIf_TxPduWasSentFlags[].

                               In post-build configurations:
                               The TxFrameHandle in each FrIf_TxPduTranslationTuple related to a FrIf_TxPduDescriptor
                               where PduConfig & FrIf_TxPduIsImmediateTx != 0 must be within the bounds of
                               FrIf_TxPduWasSentFlags[]. This check must be done per configuration variant.
*/

/*
\CM CM_FRIF_PDU_FIT    The length of a Tx/Rx frame must be greater than or equal to (ByteOffsetInFrame + PduLength) for
                       all the Tx/Rx PDUs contained in the frame (PDUs associated to the Tx/Rx frame layout elements
                       with index ranging from FirstFrameLayoutElementHandle to
                       (FirstFrameLayoutElementHandle + NumberOfPdus - 1)).

                       Note: In post-build configurations the FrIf_TxPduTranslationTable[] indirection must be taken
                       into account for the Tx Frames/PDUs.
*/

/*
\CM CM_FRIF_PDU_INFO    The PDU is contained within the frame buffer, since the pointer references
                        &frameBuffer[pduOffsetInFrame] and frameBufferLength >= pduOffsetInFrame + pduLength.
*/

/*
\CM CM_FRIF_TRCVDESC_SIZE    Size of FrIf_TransceiverDescriptors[] must be 2.
*/

/*
\CM CM_FRIF_FBUFF_SIZE    Size of FrIf_FrameBuffer[] must be greater than or equal to (FrameLength + 3) / 4 (DWORDS)
                          for all the Tx and Rx FrIf_FrameDescriptors.
*/

/*
\CM CM_FRIF_INVCHIDX    Recognize invalid channel indexes and avoid their processing.
*/

/*
\CM CM_FRIF_INVFRTRCVMAPIDX    Recognize the invalid FrTrcv function map index and avoid its processing.
*/

/*
\CM CM_FRIF_INVTXFRAME    Recognize the invalid Tx frame handle and avoid its processing.
*/

/*
\CM CM_FRIF_INVRXFRAME    Recognize the invalid Rx frame handle and avoid its processing.
*/

/*
\CM CM_FRIF_INVTXPDU    Recognize invalid Tx PDU handles (not present in the configuration variant) and avoid their
                        processing.
*/

/*
\CM CM_FRIF_INVCLST    Recognize invalid cluster indexes and avoid their processing.
*/

/*
\CM CM_FRIF_IMMEDIATETXPDU    Recognize decoupled Tx PDUs and avoid their processing
*/

/*
\CM CM_FRIF_QMDEFINES    1. The FRIF_MEASURE_JLETASKTIMES macro must be defined as STD_OFF.
                         2. The FRIF_3RD_PARTY_DRIVER_SUPPORT macro must be defined as STD_OFF.
                         3. The FRIF_CUSTOM_JLE_SCHEDULING macro must be defined as STD_OFF.
                         4. The FRIF_ENABLE_JLE_TIMER macro must not be defined.
                         5. The FRIF_DISABLE_JLE_TIMER macro must not be defined.
                         6. The FRIF_SET_JLE_TIMER macro must not be defined.
                         7. The FRIF_API_AS_MACRO must not be defined as STD_ON if FRIF_DEV_ERROR_DETECT is defined as
                            STD_ON.
*/

/**********************************************************************************************************************
 *  END OF FILE: FrIf.c
 *********************************************************************************************************************/
