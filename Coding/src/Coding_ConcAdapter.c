/**
 * \file
 *
 * \brief       Coding Conc Adapter
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

#include "Coding_ConcAdapter.h"
#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */
#include "Rte_Coding.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_ConcAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * Enters the critical section CodingData.
 */
void Coding_CritSect_Data_Enter(void) {
  Rte_Enter_CodingData();
}

/**
 * Leaves the critical section CodingData.
 */
void Coding_CritSect_Data_Exit(void) {
  Rte_Exit_CodingData();
}

/**
 * Enters the critical section CodingState.
 */
void Coding_CritSect_State_Enter(void) {
  Rte_Enter_CodingState();
}

/**
 * Leaves the critical section CodingState.
 */
void Coding_CritSect_State_Exit(void) {
  Rte_Exit_CodingState();
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
