/**
*  \file
*
*  \brief       BMW SWC Stm
*
*  STM (State Monitor)
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
/*
 * MISRA-C:2004 Rule 8.7: Due the memory mapping mechanismus in AUTOSAR
 * and since is not allowed to include files (Stm_MemMap.h) inside the body of a
 * function static local variables are not allowed and shall be declared as global.
 * See [MEMMAP018] and [MEMMAP023]. See PRQA 3218.
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Stm_Version.h"      /* Own version header file     */
#include "Stm.h"              /* Own header file             */
#include "Stm_ErrMemAdapter.h"
#include "Stm_MgmtAdapter.h"

#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Stm_CHECK_VERSION(5,2,0))
   #error "Version of Stm.c does not match the version of the module!"
#endif

#define STM_NUMBER_CEL_STATES 5U

#define STM_NUMBER_CEL_EVENTS 7U

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/** \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5731 */
typedef enum {
   STM_S_CEL_INIT,
   STM_S_CEL_NOT_RECEIVABLE,
   STM_S_CEL_LEVEL1_TM,
   STM_S_CEL_UNLOCK,
   STM_S_CEL_LOCK
} Stm_CELStateType;

/** \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5731 */
typedef enum {
   STM_EV_CEL_RECEIVABLE,
   STM_EV_CEL_NOTRECEIVABLE,
   STM_EV_CEL_LEVEL1TM,
   STM_EV_CEL_LEVEL2TM,
   STM_EV_CEL_UNLOCKED,
   STM_EV_CEL_LOCKED,
   STM_EV_CEL_INVALID
} Stm_CELEventType;

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#define Stm_START_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

static Stm_CELStateType Stm_CELState = STM_S_CEL_INIT;

#define Stm_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#define Stm_START_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

/** \lhref  DMA_PA_5105, DMA_PA_8440 */
/* PRQA S 3218 Stm_NextStateTable */
/* x = currentstate, y = event, value = nextstate */
static const Stm_CELStateType Stm_NextStateTable[STM_NUMBER_CEL_EVENTS][STM_NUMBER_CEL_STATES] = {
 /*           STM_S_CEL_INIT, STM_S_CEL_NOT_RECEIVABLE,      STM_S_CEL_LEVEL1_TM,         STM_S_CEL_UNLOCK,           STM_S_CEL_LOCK */
   {     STM_S_CEL_LEVEL1_TM,      STM_S_CEL_LEVEL1_TM,      STM_S_CEL_LEVEL1_TM,         STM_S_CEL_UNLOCK,           STM_S_CEL_LOCK}, /* STM_EV_CEL_RECEIVABLE */
   {STM_S_CEL_NOT_RECEIVABLE, STM_S_CEL_NOT_RECEIVABLE, STM_S_CEL_NOT_RECEIVABLE, STM_S_CEL_NOT_RECEIVABLE, STM_S_CEL_NOT_RECEIVABLE}, /* STM_EV_CEL_NOTRECEIVABLE */
   {          STM_S_CEL_INIT, STM_S_CEL_NOT_RECEIVABLE,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK,           STM_S_CEL_LOCK}, /* STM_EV_CEL_LEVEL1TM */
   {          STM_S_CEL_INIT, STM_S_CEL_NOT_RECEIVABLE,      STM_S_CEL_LEVEL1_TM,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK}, /* STM_EV_CEL_LEVEL2TM */
   {          STM_S_CEL_INIT,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK}, /* STM_EV_CEL_UNLOCKED */
   {          STM_S_CEL_INIT,           STM_S_CEL_LOCK,           STM_S_CEL_LOCK,           STM_S_CEL_LOCK,           STM_S_CEL_LOCK}, /* STM_EV_CEL_LOCKED */
   {          STM_S_CEL_INIT,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK,         STM_S_CEL_UNLOCK}  /* STM_EV_CEL_INVALID */
};
/* PRQA L:Stm_NextStateTable */

#define Stm_STOP_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

static void Stm_EntryCELNotReceivable(void);
static void Stm_EntryCELLevel1TM(void);
static void Stm_EntryCELLock(void);
static void Stm_EntryCELUnlock(void);

static void Stm_TransitCELUnlocked(void);
static void Stm_TransitCELInvalid(void);

static void Stm_ProcessCentralErrorLock(Stm_CELEventType CELEvent);

#endif /* #if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_EntryCELNotReceivable
 *
 * Processing actions on entering state CEL_NOT_RECEIVABLE
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_EntryCELNotReceivable(void)
{
   (void)ErrMem_DisableMemoryLockCentralErrorLock();
   Stm_Mgmt_ProvideCentralErrorLockModeInvalid();
} /* end of function Stm_EntryCELNotReceivable */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_EntryCELLevel1TM
 *
 * Processing actions on entering state CEL_Level1_TM
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_EntryCELLevel1TM(void)
{
   (void)ErrMem_EnableMemoryLockCentralErrorLock();
   Stm_Mgmt_ProvideCentralErrorLockModeLocked();
} /* end of function Stm_EntryCELLevel1TM */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_EntryCELLock
 *
 * Processing actions on entering state CEL_LOCK
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_EntryCELLock(void)
{
   (void)ErrMem_EnableMemoryLockCentralErrorLock();
   Stm_Mgmt_ProvideCentralErrorLockModeLocked();
} /* end of function Stm_EntryCELLock */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_EntryCELUnlock
 *
 * Processing actions on entering state CEL_UNLOCK
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_EntryCELUnlock(void)
{
   (void)ErrMem_DisableMemoryLockCentralErrorLock();
} /* end of function Stm_EntryCELUnlock */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_TransitCELUnlocked
 *
 * Providing STM_CEL_UNLOCKED state to system during transition to next state
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_TransitCELUnlocked(void)
{
   Stm_Mgmt_ProvideCentralErrorLockModeUnlocked();
} /* end of function Stm_TransitCELUnlocked */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_TransitCELInvalid
 *
 * Providing STM_CEL_INVALID state to system during transition to next state
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_TransitCELInvalid(void)
{
   Stm_Mgmt_ProvideCentralErrorLockModeInvalid();
} /* end of function Stm_TransitCELInvalid */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ProcessCentralErrorLock
 *
 * Processing events of Stm statemachine
 *
 * \global_r  none
 * \global_w  none
 * \global_rw Stm_CELState
 *
 * \param[out]    none
 * \param[in]     Stm_CELEventType: event to be processed
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_ProcessCentralErrorLock(Stm_CELEventType CELEvent)
{
   Stm_CELStateType nextState;

   /* get next state */
   nextState = Stm_NextStateTable[CELEvent][Stm_CELState];

   /* no actions if state doesn't change */
   if (Stm_CELState != nextState)
   {
      void (*transitFunction)(void) = NULL;
      void (*entryFunction)(void) = NULL;

      /* set transitFunction and entryFunction */
      switch (nextState)
      {
         case STM_S_CEL_UNLOCK:
            /* only on transition to this state actions are possible*/
            if (CELEvent == STM_EV_CEL_UNLOCKED)
            {
               transitFunction = &Stm_TransitCELUnlocked;
            }
            else if ((CELEvent == STM_EV_CEL_INVALID) ||
                     (CELEvent == STM_EV_CEL_LEVEL2TM) ||
                     (CELEvent == STM_EV_CEL_LEVEL1TM))
            {
               transitFunction = &Stm_TransitCELInvalid;
            }
            else
            {
            }
            entryFunction = &Stm_EntryCELUnlock;
            break;
         case STM_S_CEL_LEVEL1_TM:
            entryFunction = &Stm_EntryCELLevel1TM;
            break;
         case STM_S_CEL_LOCK:
            entryFunction = &Stm_EntryCELLock;
            break;
         case STM_S_CEL_NOT_RECEIVABLE:
            entryFunction = &Stm_EntryCELNotReceivable;
            break;
         default:
            break;
      }

      /* do transit actions */
      if (transitFunction != NULL)
      {
         transitFunction();
      }

      /* set the new state */
      Stm_CELState = nextState;

      /* do state entry actions */
      if (entryFunction != NULL)
      {
         entryFunction();
      }
   }
} /* end of function Stm_ProcessCentralErrorLock */

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
 * \brief Stm_ReceivedCELUnlocked
 *
 * Signal CENTRAL_ERROR_LOCK has been recevied with value STM_CEL_UNLOCKED.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from ComAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceivedCELUnlocked(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_UNLOCKED);
} /* end of function Stm_ReceivedCELUnlocked */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ReceivedCELLocked
 *
 * Signal CENTRAL_ERROR_LOCK has been recevied with value STM_CEL_LOCKED.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from ComAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceivedCELLocked(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_LOCKED);
} /* end of function Stm_ReceivedCELLocked */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ReceivedCELInvalid
 *
 * Signal CENTRAL_ERROR_LOCK has been recevied with value STM_CEL_INVALID.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from ComAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceivedCELInvalid(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_INVALID);
} /* end of function Stm_ReceivedCELInvalid */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Level1TM_Fired
 *
 * Timeout level 1 occured.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from TimerAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Level1TM_Fired(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_LEVEL1TM);
} /* end of function Stm_Level1TM_Fired */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Level2TM_Fired
 *
 * Timeout level 2 occured.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from TimerAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Level2TM_Fired(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_LEVEL2TM);
} /* end of function Stm_Level2TM_Fired */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_CELNotReceivable
 *
 * Signal CENTRAL_ERROR_LOCK is not receivable.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from MgmtAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_CELNotReceivable(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_NOTRECEIVABLE);
} /* end of function Stm_CELNotReceivable */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_CELReceivable
 *
 * Signal CENTRAL_ERROR_LOCK is receivable.
 *
 * \global_r  none
 * \global_w  none
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
 * \remarks typically called from MgmtAdapter
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_CELReceivable(void)
{
   Stm_ProcessCentralErrorLock(STM_EV_CEL_RECEIVABLE);
} /* end of function Stm_CELReceivable */

#endif /* #if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*--- End of file ------------------------------------------------------------*/
