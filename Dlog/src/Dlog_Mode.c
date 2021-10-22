/**
*  \file
*
*  \brief       Dlog mode routines
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "DlogClassic_Cfg.h"

#if (DLOG_ENABLE_RTE == STD_ON)

#include "Dlog_Ecu.h"
#include "Dlog_HweTable.h"
#include "Dlog_SvkGen.h"
#include "Rte_Dlog.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5, 3, 1))
#error "Version of Dlog_Mode.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Function Prototypes
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/**
 * Evaluates the requested life cycle mode and switches accordingly.
 */
void Dlog_ModeSwitchRequestLifeCycle(void) {
  Dlog_LifeCycleRequestType reqMode = Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode();
  Dlog_LifeCycleRequestType prevMode, nextMode;

  /* we don't care for the return value */
  (void)Rte_Mode_LifeCycle_Mode(&prevMode, &nextMode);

  switch (reqMode) {
    case RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED:
      if (RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED == nextMode) {
#if DLOG_HWETABLE_INIT_FROM_ROM == STD_ON
        Dlog_InitHweTable();
#endif
        Dlog_SvkInit();
        (void)Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;
    case RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING:
      if (RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED == nextMode) {
        (void)Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;
    case RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED:
      if (RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED != nextMode) {
        (void)Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;

    default:
      break;
  }

}

/**
 * The mode state machine.
 */
void Dlog_ModeSwitchAckLifeCycle(void) {
  Dlog_LifeCycleRequestType prevMode, nextMode;

  /* we don't care for the return value */
  (void)Rte_Mode_LifeCycle_Mode(&prevMode, &nextMode);

  switch (nextMode) {
    case RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED:
      Rte_Write_ProgId_progId(Dlog_Data.progId);
      break;
    case RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING:
      break;
    case RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED:
      break;

    default:
      break;
  }
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if ( DLOG_ENABLE_RTE == STD_ON ) */
