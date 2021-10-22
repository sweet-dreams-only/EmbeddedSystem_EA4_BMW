/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file contains the main VIN functionality.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user: no
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 5.6: Normal variable names. There should be no confusion at all.
 * See PRQA:0781 */

/*
 * MISRA-C:2004 Rule 14.7: early return on error makes code more readable,
 * see PRQA 2006, 5207
 */

/*
   MISRA-C:2004 Rule 19.1: including Vin_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Vin.h"                   /* Own header file         */
#include "Vin_Cfg.h"               /* Own configuration file  */
#include "Vin_Helper.h"
#include "Vin_Dlog.h"
#if (Vin_ENABLE_SECURE_VIN == STD_ON)
#include "Vin_Ssv.h"               /* Secure Vin functionality */
#endif
#include "Std_Types.h"             /* AUTOSAR Standard Types  */
#include "Rte_Vin.h"               /* Own RTE header file     */

#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"

VAR(Vin_VinType, Vin_VAR) Vin_CurrentVin;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"


#define Vin_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */

VAR(Vin_NVStateType, Vin_VAR) Vin_NVState;

#define Vin_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Vin_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */

CONST(Vin_NVStateType, Vin_CONST) Vin_NVStateDefault = {
      {0,0,0,0,0,0,0},
      VIN_UNSAFE_ENVIRONMENT
};

#define Vin_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

typedef struct {
   enum {
      VIN_REC_INIT,
      VIN_REC_VINREQUESTED,
      VIN_REC_VINRECEIVED,
      VIN_REC_ERROR
   } recState;
   enum {
      VIN_PREP_INIT,
      VIN_PREP_WAITFORNVM,
      VIN_PREP_FINISH,
      VIN_PREP_ERROR
   } prepState;
   boolean switchToStopPending;
   boolean switchToSavePending;
   uint8 vinTimeout;
   uint8 macTimeout;
   uint8 vinRequestCounter;
} Vin_StateType;


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"

static VAR(Vin_StateType, Vin_VAR_NOINIT) Vin_State;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"


/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

static FUNC(void, Vin_CODE) Vin_RequestVin(void);
static FUNC(void, Vin_CODE) Vin_Init(void);
static FUNC(void, Vin_CODE) Vin_Run(void);
static FUNC(void, Vin_CODE) Vin_CheckForVinChange(void);

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"


/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * Requests the external VIN over the bus.
 *
 * \global_w    Vin_State
 *
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_RequestVin(void)
{
   (void)Rte_Send_VinRequest_RequestMessageIdentifier(VIN_VINREQUEST_MESSAGE_IDENTIFIER);
   ++Vin_State.vinRequestCounter;
}

/*----------------------------------------------------------------------------*/
/**
 * \brief       Performs the Vin initialization
 *
 * \global_w    Vin_State
 *
 * \pre EA VinState shall be entered
 *
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_Init(void)
{
   Vin_State.recState = VIN_REC_INIT;
   Vin_State.prepState = VIN_PREP_INIT;
   Vin_State.switchToStopPending = FALSE;
   Vin_State.vinTimeout = 0u;
   Vin_State.vinRequestCounter = 0u;
   Vin_CurrentVin.Qualifier = VIN_QUAL_INIT;
}/* end of function Vin_Init */

/*----------------------------------------------------------------------------*/
/**
 * \brief       Performs everything needed when RTE_MODE_Vin_LifeCycle_VIN_RUNNING
 *              is requested.
 *
 * \global_w    Vin_NVState
 * \global_w    Vin_State
 *
 * \pre EA VinState shall be entered
 *
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_Run(void)
{
   Std_ReturnType ret;

   Vin_State.prepState = VIN_PREP_WAITFORNVM;

   ret = Rte_Call_NvMService_Vin_ReadBlock((P2VAR(void, AUTOMATIC, Vin_APPL_DATA))&Vin_NVState);
   Vin_Assert(E_OK == ret, VIN_NVM_API_ID, ret);
}/* end of function Vin_Run */

/*----------------------------------------------------------------------------*/
/**
 * Checks for change in external VIN and switches the ChangeIndicator mode accordingly.
 *
 * \global_r  Vin_State
 * \global_rw Vin_NVState
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_CheckForVinChange(void)
{
   Rte_ModeType_Vin_ChangeIndicator ci = Rte_Mode_VinChangeIndicator_ChangeIndicator();

   if ((RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED != ci) &&
       (VIN_PREP_FINISH == Vin_State.prepState) &&
       (VIN_CHECKQUALIFIER(Vin_CurrentVin.Qualifier, VIN_CQ_VIN_RECEIVED)))
   {
      /* The last VIN has been read out of NVM and the current VIN has been received -> compare */
      if (0 == memcmp(Vin_CurrentVin.Vin, Vin_NVState.lastReceivedVin, sizeof(Vin_CurrentVin.Vin)))
      {
         (void)Rte_Switch_VinChangeIndicator_ChangeIndicator(RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE);
      }
      else
      {
         (void)memcpy(Vin_NVState.lastReceivedVin, Vin_CurrentVin.Vin, sizeof(Vin_NVState.lastReceivedVin));
         (void)Rte_Switch_VinChangeIndicator_ChangeIndicator(RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED);
      }
   }
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Main function.
 *
 * Handles the main state machine.
 *
 * \global_rw   Vin_State
 *
 * \remark This function is cyclically triggered every 0.1s, when life cycle mode is running and
 *         VIN communication mode is on.
 *
 * \swsid SWS_Vin_0004
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_Main(void)
{
   switch(Vin_State.recState)
   {
      case VIN_REC_INIT:
         ++Vin_State.vinTimeout;
         if (Vin_State.vinTimeout >= VIN_TIMEOUT_INIT)
         {
            Vin_RequestVin();
            Vin_State.recState = VIN_REC_VINREQUESTED;
            Vin_State.vinTimeout = 0u;
         }
         break;
      case VIN_REC_VINREQUESTED:
         ++Vin_State.vinTimeout;
         if (Vin_State.vinTimeout >= VIN_TIMEOUT_REQUEST)
         {
            if (Vin_State.vinRequestCounter < VIN_MAX_NUMBER_REQUESTS)
            {
               Vin_RequestVin();
               Vin_State.vinTimeout = 0u;
            }
            else
            {
               Vin_State.recState = VIN_REC_ERROR;
            }
         }
         break;
      case VIN_REC_VINRECEIVED:
      case VIN_REC_ERROR:
         /* We are done - nothing to do :-) */
         break;
      default:
         /* We should not reach this line of code */
         break; /* LCOV_EXCL_LINE */
   }
#if (Vin_ENABLE_SECURE_VIN == STD_ON)
   if ((VIN_PREP_FINISH == Vin_State.prepState) &&
       (VIN_REC_VINRECEIVED == Vin_State.recState))
   {
      Vin_SsvMain();
   }
#endif

} /* end of function Vin_Main */

/*----------------------------------------------------------------------------*/
/**
 * Called, when VIN communication is going off
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_OnComOff(void)
{

}

/*----------------------------------------------------------------------------*/
/**
 * Called, when VIN communication is going on
 *
 * \remark This is a RTE runnable which runs inside the exclusive area VinState.
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_OnComOn(void)
{
   if (VIN_REC_VINRECEIVED != Vin_State.recState)
   {
      /* Communication is switched on and we have not yet received a VIN -> Restart */
      Vin_State.recState = VIN_REC_INIT;
      Vin_State.vinTimeout = 0u;
      Vin_State.vinRequestCounter = 0u;
   }
#if (Vin_ENABLE_SECURE_VIN == STD_ON)
   Vin_SsvOnComOn();
#endif
}

/*----------------------------------------------------------------------------*/
/**
 * Called on ModeSwitchedAck event for the ChangeIndicator. Writes the external VIN
 * to NV memory, if it has changed.
 *
 * \remark This is a RTE runnable which runs inside the exclusive area VinState.
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_OnVinChangeIndicatorAck(void)
{
   Rte_ModeType_Vin_ChangeIndicator ci = Rte_Mode_VinChangeIndicator_ChangeIndicator();

   if ((RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED == ci) &&
       (VIN_PREP_FINISH == Vin_State.prepState))
   {
      /* If VIN_PREP_FINISH != Vin_State.prepState, we have
       * a) an error -> nothing to do here, or
       * b) the NV block is currently being written (switch to save env)
       *    -> again nothing to do, since the VIN will be written, too (same block).
       */
      Std_ReturnType ret;

      Vin_State.prepState = VIN_PREP_WAITFORNVM;

      ret = Rte_Call_NvMService_Vin_WriteBlock(&Vin_NVState);
      Vin_Assert(E_OK == ret, VIN_NVM_API_ID, ret);
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Evaluates the requested mode and switches accordingly.
 *
 * \swsid SWS_Vin_0005
 *
 * \remark This is a RTE runnable which runs inside the exclusive area VinState.
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_LifeCycleModeRequest(void)
{
   Vin_LifeCycleRequestType prevMode, nextMode;  /* PRQA S 0781 */
   Vin_LifeCycleRequestType reqMode = Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode();

   (void)Rte_Mode_LifeCycle_Mode(&prevMode, &nextMode);

   switch(reqMode)
   {
      case RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED:
         if (RTE_MODE_Vin_LifeCycle_VIN_STOPPED == nextMode)
         {
            Vin_Init();
#if (Vin_ENABLE_SECURE_VIN == STD_ON)
            Vin_SsvInit();
#endif
            (void)Rte_Switch_LifeCycle_Mode(reqMode);
         }
         break;
      case RTE_MODE_Vin_LifeCycle_VIN_RUNNING:
         if (RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED == nextMode)
         {
            Vin_Run();
            (void)Rte_Switch_LifeCycle_Mode(reqMode);
         }
         break;
      case RTE_MODE_Vin_LifeCycle_VIN_STOPPED:
         if (RTE_MODE_Vin_LifeCycle_VIN_STOPPED != nextMode)
         {
            if (VIN_PREP_WAITFORNVM == Vin_State.prepState)
            {
               Vin_State.switchToStopPending = TRUE;
            }
            else
            {
               (void)Rte_Switch_LifeCycle_Mode(reqMode);
            }
         }
         break;
      default:
         break;
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Sets the VIN state to VIN_REC_VINRECEIVED.
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_NotifyVinReceived(void)
{
   Vin_State.recState = VIN_REC_VINRECEIVED;

   Vin_CheckInternalVin(&Vin_CurrentVin);
   Vin_CheckForVinChange();

#if (Vin_ENABLE_SECURE_VIN == STD_ON)
   (void)Rte_Write_InternalCheckVinTrigger_Trigger(0);
#else
   (void)Rte_Write_Vin_Vin(&Vin_CurrentVin);
#endif
}

#if (Vin_ENABLE_SECURE_VIN == STD_ON)
/*----------------------------------------------------------------------------*/
/**
 * Called, when security information has been updated.
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_NotifyVinSecurityUpdate(void)
{
   (void)Rte_Write_InternalCheckVinTrigger_Trigger(0);
}
#endif

/*----------------------------------------------------------------------------*/
/**
 * Called by NvM when the read job has finished.
 */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, Vin_CODE) Vin_NvmJobFinished(uint8 ServiceId, NvM_RequestResultType JobResult)
{
   /*PRQA S 3112 1*//* unused parameter */
   (void)ServiceId;

   /* The notification is called by NvM on readall even though the block is not
    * configured for readall. JobResult should be NVM_REQ_BLOCK_SKIPPED in this case.
    */
   if ( (VIN_PREP_WAITFORNVM != Vin_State.prepState) &&
        (NVM_REQ_BLOCK_SKIPPED == JobResult)
      )
   {
      return E_OK;
   }

   Vin_Assert(VIN_PREP_WAITFORNVM == Vin_State.prepState, VIN_INTERNAL_API_ID, 0xff);

   if (NVM_REQ_NV_INVALIDATED == JobResult)
   {
      /* Since this is not consistently specified by AUTOSAR, we
       * restore the default values by ourselves. */
      Vin_NVState = Vin_NVStateDefault;
      JobResult = NVM_REQ_RESTORED_FROM_ROM;
   }

   if ((NVM_REQ_OK == JobResult) ||
       (NVM_REQ_RESTORED_FROM_ROM == JobResult))
   {
      Vin_State.prepState = VIN_PREP_FINISH;

      if (FALSE != Vin_State.switchToStopPending)
      {
         Vin_State.switchToStopPending = FALSE;
         (void)Rte_Switch_LifeCycle_Mode(RTE_MODE_Vin_LifeCycle_VIN_STOPPED);
      }
      else if ((FALSE != Vin_State.switchToSavePending) &&
               (VIN_SAFE_ENVIRONMENT != Vin_NVState.environment))
      {
         Vin_SwitchToSafeEnvironment();
      }
      else
      {
         Vin_CheckForVinChange();
      }
   }
   else
   {
      Vin_State.prepState = VIN_PREP_ERROR;
   }
   return E_OK;
} /* PRQA S 2006,5207 */

/*----------------------------------------------------------------------------*/
/**
 * Returns the current environment, or VIN_UNKOWN_ENVIRONMENT, if the NV block
 * has not been read yet.
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(Vin_EnvironmentType, Vin_CODE) Vin_GetEnvironment(void)
{
   Vin_EnvironmentType environment = VIN_UNKOWN_ENVIRONMENT; /* PRQA S 0781 */

   Rte_Enter_VinState();
   if (VIN_PREP_WAITFORNVM < Vin_State.prepState)
   {
      environment = (Vin_EnvironmentType)Vin_NVState.environment;
   }
   Rte_Exit_VinState();

   return environment;
}

/*----------------------------------------------------------------------------*/
/**
 * Switches to safe environment
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SwitchToSafeEnvironment(void)
{
   Std_ReturnType ret;

   Rte_Enter_VinState();
   if (VIN_PREP_WAITFORNVM == Vin_State.prepState)
   {
      Vin_State.switchToSavePending = TRUE;
   }
   else
   {
      Vin_State.switchToSavePending = FALSE;
      Vin_State.prepState = VIN_PREP_WAITFORNVM;
      Vin_NVState.environment = VIN_SAFE_ENVIRONMENT;

      ret = Rte_Call_NvMService_Vin_WriteBlock(&Vin_NVState);
      Vin_Assert(E_OK == ret, VIN_NVM_API_ID, ret);
   }
   Rte_Exit_VinState();
}

/*----------------------------------------------------------------------------*/
/**
 * Returns a copy of the current VIN.
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_GetCurrentVin(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) currentVin)
{
   Rte_Enter_VinState();
   *currentVin = Vin_CurrentVin;
   if (VIN_REC_VINRECEIVED != Vin_State.recState)
   {
      currentVin->Qualifier = VIN_QUAL_INIT;
   }
   Rte_Exit_VinState();
}


/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"

/*--- End of file ------------------------------------------------------------*/
