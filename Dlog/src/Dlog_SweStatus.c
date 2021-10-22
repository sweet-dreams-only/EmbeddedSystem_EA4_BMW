/**
 * \file
 *
 * \brief       The SWE status contains the error flags for each SWE.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_SweStatus.h"
#include "Dlog_Swe.h"

#include <stddef.h>
#include <string.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SweStatus.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

Dlog_SweStatusType Dlog_SweStatus;

Dlog_SweInfoType Dlog_SweInfos[DLOG_MAX_NUMBER_OF_SWES];

Dlog_DataType Dlog_Data;

#define Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/**
 * Copies the SWE description from flash into Dlog_SweInfos
 *
 * \param sweId the SWE description to copy
 *
 */
void Dlog_CopySweDescription(uint8 sweId) {
  (void)memcpy(Dlog_SweInfos[sweId].sgmbId, Dlog_CommonLogisticBtld.PointerToSweTable[sweId]->SgbmId, sizeof(Dlog_SweInfos[sweId].sgmbId));
  Dlog_SweInfos[sweId].developmentInfo = Dlog_CommonLogisticBtld.PointerToSweTable[sweId]->SweDevInfo;
}

/**
 * Sets the valid state of the given SWE
 *
 * \param[in] sweId      ID of the SWE to set the valid state
 * \param[in] validState the valid state
 *
 */
void Dlog_SetSweValidState(uint8 sweId, Dlog_SweValidStateType validState) {
  if (DLOG_SWE_STATE_VALID_SWFL == validState || DLOG_SWE_STATE_VALID_BTLD == validState) {
    /* valid swe -> copy swe info from flash */
    Dlog_CopySweDescription(sweId);
  }
  Dlog_SweInfos[sweId].validState = validState;
}


/**
 * Gets the valid state of the given SWE
 *
 * \param sweId ID of the SWE to get the valid state from
 * \return the valid state
 *
 */
Dlog_SweValidStateType Dlog_GetSweValidState(uint8 sweId) {
  return Dlog_Data.sweInfo[sweId].validState;
}

/**
 * Sets the programming dependency state.
 *
 * \param[in] progDepState the programming dependency state
 *
 */
void Dlog_SetSweProgDepState(Dlog_SweProgDepStateType progDepState) {
  Dlog_Data.sweProgDepState = progDepState;
}

/**
 * Gets the programming dependency state.
 *
 * \return the programming dependency state
 *
 */
Dlog_SweProgDepStateType Dlog_GetSweProgDepState(void) {
  return Dlog_Data.sweProgDepState;
}
