/**
 * \file
 *
 * \brief       Coding Mgmt Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_MgmtAdapter.h"
#include "Rte_Coding.h"
#include "Coding.h"                    /* Coding_NCDStateType */
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_MgmtAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Service for managing the startup life cycle switch.
 */
/*----------------------------------------------------------------------------*/
void Coding_Mgmt_StartupFinished(void) {
  (void)Rte_Switch_LifeCycle_Mode(RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED);
}

/*----------------------------------------------------------------------------*/
/**
 * Service for managing the pre run life cycle switch.
 */
/*----------------------------------------------------------------------------*/
void Coding_Mgmt_PreRunFinished(void) {
  (void)Rte_Switch_LifeCycle_Mode(RTE_MODE_Coding_LifeCycle_CODING_RUNNING);
}

/*----------------------------------------------------------------------------*/
/**
 * Service for managing the shutdown life cycle switch.
 */
/*----------------------------------------------------------------------------*/
void Coding_Mgmt_ShutdownFinished(void) {
  (void)Rte_Switch_LifeCycle_Mode(RTE_MODE_Coding_LifeCycle_CODING_STOPPED);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that evaluates the requested mode and switches accordingly.
 */
/*----------------------------------------------------------------------------*/
void Coding_LifeCycleHandler(void) {
  Coding_LifeCycleRequestType nextMode, prevMode;  /* PRQA S 0781 */
  Coding_LifeCycleRequestType reqMode = Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  /* ignore return value, only nextMode is used */
  (void)Rte_Mode_LifeCycle_Mode(&prevMode, &nextMode);

  switch (reqMode) {
    case RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED:
      if (RTE_MODE_Coding_LifeCycle_CODING_STOPPED == nextMode) {
        Coding_Init();
      }
      break;
    case RTE_MODE_Coding_LifeCycle_CODING_RUNNING:
      if (RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED == nextMode) {
        Coding_Run();
      }
      break;
    case RTE_MODE_Coding_LifeCycle_CODING_STOPPED:
      if (RTE_MODE_Coding_LifeCycle_CODING_STOPPED != nextMode) {
        Coding_Shutdown();
      }
      break;
    default:
      /* Should never be reached because the allowed states,
       * are managed by the case statements above and this function
       * should never be called in any other case.
       */
      break;
  }
}

/*----------------------------------------------------------------------------*/
/**
 * Service for managing a data mode switch.
 */
/*----------------------------------------------------------------------------*/
void Coding_Notify_NCDState(const Coding_NCDStateType NCDState) {
  uint8 currentDataMode;

  switch (NCDState) {
    case DATA_ST_UNDEFINED:
      currentDataMode = RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED;
      break;
    case DATA_ST_DEFAULT:
      currentDataMode = RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT;
      break;
    case DATA_ST_UNQUALIFIED:
      currentDataMode = RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED;
      break;
    case DATA_ST_QUALIFIED:
      currentDataMode = RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED;
      break;
    case DATA_ST_INPROGRESS:
      currentDataMode = RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS;
      break;
    default:
      /* Shall not be possible to end up here                              */
      break;
  }

  (void)Rte_Switch_DataMode_currentDataMode(currentDataMode);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that evaluates the bus communication state.
 */
/*----------------------------------------------------------------------------*/
boolean Coding_BusComState(void) {
  uint8 busComState;
  boolean retVal = TRUE;

  busComState = Rte_Mode_BusCom_Mode();

  /* convert return value */
  if (RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF == busComState) {
    retVal = FALSE;
  }

  return (retVal);
}

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
/*----------------------------------------------------------------------------*/
/**
 * Service that evaluates the condition state.
 */
/*----------------------------------------------------------------------------*/
boolean Coding_ConditionState(void) {
  uint8 conditionState;
  boolean retVal = TRUE;

  /** \lhref COD_059 */
  conditionState = Rte_Mode_ConditionMode_currentConditionMode();

  /* convert return value */
  if (RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED == conditionState) {
    retVal = FALSE;
  }

  return (retVal);
}

#endif /* CODING_CONDITIONCHECK_SUPPORT */

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
