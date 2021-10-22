/**
*  \file
*
*  \brief       Stm Timer Adapter
*
*  This file contains the Stm Timer functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Stm_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Stm_Timer.h"
#include "Stm.h"
#include "Stm_Com.h"
#include "StmClassic_Version.h"
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
#include "StmClassic_PBCfg.h"        /* Post build configuration    */
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_MgmtAdapter.c does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

 #if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#define Stm_START_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

static Stm_Timer_LevelType Stm_Timer_Level = STM_TIMER_NONE;

#define Stm_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_COM_VARIANT_FIELDS == STD_ON

#define Stm_START_SEC_VAR_CLEARED_BOOLEAN
#include "Stm_MemMap.h" /* PRQA S 5087 */

static boolean Stm_EventPollingCallRunning = FALSE;

#define Stm_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Stm_MemMap.h" /* PRQA S 5087 */

#define Stm_START_SEC_VAR_CLEARED_16
#include "Stm_MemMap.h" /* PRQA S 5087 */

static uint16 Stm_CelTimeoutCounter = 0U;
static uint16 Stm_WaitCSResponseCnt = 0U;

#define Stm_STOP_SEC_VAR_CLEARED_16
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /* STM_COM_VARIANT_FIELDS == STD_ON */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#if STM_COM_VARIANT_FIELDS == STD_ON
static void Stm_HandleCelTimeout(void);
#endif /* STM_COM_VARIANT_FIELDS == STD_ON */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#if STM_COM_VARIANT_FIELDS == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_HandleCelTimeout
 *
 * Local function to handle Central Error Lock Timeout
 *
 *
 * \global_r  none
 * \global_w  Stm_Timer_Level
 * \global_rw Stm_EventPollingCallRunning Stm_WaitCSResponseCnt
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_HandleCelTimeout(void)
{
   ComService_ResultType ret;

   if (Stm_EventPollingCallRunning == FALSE)
   {
      /* we have not yet called the getter to retrieve the data */
      ret = Stm_ComTriggerGetVehicleStatus();
      Stm_WaitCSResponseCnt = 0; /* we have a configuarble counter, how many supervision_runnable cycles we wait until
                                a response of our C/S-Call returns. */
      if (ret == COM_OK)
      {
         Stm_EventPollingCallRunning = TRUE;
      }
      else
      {
         /* call to getter failed - this is interpreted as TIMEOUT */
         Stm_Timer_FireTimeout();
      }
   }
   else
   {
      /* The C/S-call to get the data has already been done in a previous
         supervision cycle. We check for a result: */
      ret = Stm_ComGetVehicleStatus();
      if (ret == COM_OK)
      {
         /* polling successful, ComAdapter triggerd Stm according new data, nothing to do */
      }
      else if (ret == COM_NO_DATA)
      {
         Stm_WaitCSResponseCnt += STM_CYCLE_TIME;
         if (Stm_WaitCSResponseCnt >= STM_MAX_WAIT_FOR_C_S_RESPONSE_TIME)
         {
            /* Answer for Poll-Request took too long - we handle this like timeout */
            Stm_Timer_FireTimeout();
         }
      }
      else
      {
         Stm_Timer_Level = STM_TIMER_NONE;
         /* Result error will be handled like INVALID */
         Stm_ReceivedCELInvalid();
      }
   }
} /* end of function Stm_HandleCelTimeout */
#endif /* STM_COM_VARIANT_FIELDS == STD_ON */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Timer_Cancel
 *
 * Starts timeout level 1 and set timeout counter for TimeoutSupervision.
 *
 * \global_r  none
 * \global_w  Stm_Timer_Level Stm_CelTimeoutCounter
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Timer_StartLevel1TM(void)
{
   Stm_Timer_Level = STM_TIMER_LEVEL1TM;

#if STM_COM_VARIANT_FIELDS == STD_ON
   Stm_CelTimeoutCounter = STM_CEL_LVL_1_TIMEOUT_TIME;
#endif /*#if STM_COM_VARIANT_FIELDS == STD_ON*/
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Timer_Cancel
 *
 * Starts timeout level 2 and set timeout counter for TimeoutSupervision.
 *
 * \global_r  none
 * \global_w  Stm_Timer_Level Stm_CelTimeoutCounter
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Timer_StartLevel2TM(void)
{
   Stm_Timer_Level = STM_TIMER_LEVEL2TM;

#if STM_COM_VARIANT_FIELDS == STD_ON
   Stm_CelTimeoutCounter = STM_CEL_LVL_2_TIMEOUT_TIME;
#endif /*#if STM_COM_VARIANT_FIELDS == STD_ON*/
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Timer_Cancel
 *
 * Fires and stops started timeout to Stm generic.
 *
 * \global_r  none
 * \global_w  none
 * \global_rw Stm_Timer_Level
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Timer_FireTimeout(void)
{
   if (Stm_Timer_Level == STM_TIMER_LEVEL2TM)
   {
      Stm_Timer_Level = STM_TIMER_NONE;
      Stm_Level2TM_Fired();
   }
   else if (Stm_Timer_Level == STM_TIMER_LEVEL1TM)
   {
      Stm_Timer_Level = STM_TIMER_NONE;
      Stm_Level1TM_Fired();
   }
   else /* timer not started yet */
   {
   }
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Timer_Cancel
 *
 * Stops any started timeout.
 *
 * \global_r  none
 * \global_w  Stm_Timer_Level
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Timer_Cancel(void)
{
   Stm_Timer_Level = STM_TIMER_NONE;
}

#if STM_COM_VARIANT_FIELDS == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_TimeoutSupervision
 *
 * Timeout Supervision is a cyclically triggered runnable (TIMING_EVENT)
 * the frequency/cycle shall be configurable in paramdef.
 * based on the cycle, STM will compute FIRST_CEL_TIMEOUT_CNT and CEL_TIMEOUT_CNT
 *
 * \global_r  Stm_Timer_Level
 * \global_w  none
 * \global_rw Stm_CelTimeoutCounter Stm_EventPollingCallRunning
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_TimeoutSupervision(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->CentralErrorLockEnabled == TRUE)
#endif
   {
      if(  (Stm_EventPollingCallRunning == TRUE)
         &&(Stm_CelTimeoutCounter != 0))
      {
         /* when a new signal is received befor we can retreive the result
            Ignore the result of the last RteCall_CELQueryPort_GetVehicleStatus() call */
         Stm_EventPollingCallRunning = FALSE;
      }

      if (Stm_Timer_Level != STM_TIMER_NONE )
      {
         if (Stm_CelTimeoutCounter > STM_CYCLE_TIME)
         {
            Stm_CelTimeoutCounter -= STM_CYCLE_TIME;
         }
         else
         {
            /*timeout detected */
            Stm_CelTimeoutCounter = 0;
            Stm_HandleCelTimeout();
         }
      }
   }
}
#endif /*#if STM_COM_VARIANT_FIELDS == STD_ON*/

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */
