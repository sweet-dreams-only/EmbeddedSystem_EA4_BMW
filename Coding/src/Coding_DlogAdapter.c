/**
 * \file
 *
 * \brief       Coding Dlog Adapter
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

#include "Coding_DlogAdapter.h"
#include "Coding.h"
#include "Rte_Coding.h"
#include "Coding_Assert.h"
#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_DlogAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Called by Coding on startup ecu and on storing Coding data to get the 'progId'.
 */
/*----------------------------------------------------------------------------*/
void Coding_DlogGetProgId(uint8* progId) {
  Std_ReturnType ret = E_NOT_OK;

  ret = Rte_Read_Coding_ProgId_progId(progId);
  Coding_DevAssert(ret == RTE_E_OK, CODING_DEVERROR_GENERAL);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the Dlog request to get the caf Id values for 'SVK'.
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_DlogGetCafIds(uint8* cafIds, uint16* numberOfCafIds) {
  Coding_GetCafIds(cafIds, numberOfCafIds);

  return (E_OK);
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
