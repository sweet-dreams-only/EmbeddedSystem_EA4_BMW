/**
 * \file
 *
 * \brief       Coding Vin Adapter
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

#include "Coding.h"                    /* Coding_VinReceivedCallback() */
#include "Rte_Coding.h"
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_VinAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the vin reception.
 *
 * \lhref COD_063
 */
/*----------------------------------------------------------------------------*/
void Coding_VinReceivedExternalVin(void) {
  const Vin_VinType* externalVin = Rte_IRead_VinReceiveHandler_Vin_Vin();
  Coding_VinReceivedCallback(externalVin->Vin);
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
