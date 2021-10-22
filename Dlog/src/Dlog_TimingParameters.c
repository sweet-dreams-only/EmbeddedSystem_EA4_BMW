/**
 * \file
 *
 * \brief       Read timing parameters.
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

/* -------------------------------------------------------------------------- */
#include "Dlog_TimingParameters.h"    /* module own header file               */

#if (DLOG_ENABLE_TIMINGPARAMETERS == STD_ON)

/* -------------------------------------------------------------------------- */
#include "Dlog_Swe.h"       /* contains Dlog_CommonLogisticBtld               */
/* -------------------------------------------------------------------------- */
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
#if (!DlogClassic_CHECK_VERSION(5, 3, 1))
#error "Version of Dlog_TimingParameters.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) -
 * DIAG_DID_2504_FLASH_TIMING_PARAMS
 * Read program specific timing parameters
 *
 * \param[out] Data Timing Parameters
 *
 * \return Always E_OK
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset |  Value |  Description
 * ------ | ------ | -----------------
 *     0  |  0x..  | EraseMemoryTime: (MSB)
 *     1  |  0x..  | EraseMemoryTime: (LSB)
 *     2  |  0x..  | CheckMemoryTime: (MSB)
 *     3  |  0x..  | CheckMemoryTime: (LSB)
 *     4  |  0x..  | BootloaderInstallationTime: (MSB)
 *     5  |  0x..  | BootloaderInstallationTime: (LSB)
 *     6  |  0x..  | AuthenticationTime: (MSB)
 *     7  |  0x..  | AuthenticationTime: (LSB)
 *     8  |  0x..  | ResetTime: (MSB)
 *     9  |  0x..  | ResetTime: (LSB)
 *    10  |  0x..  | TransferDataTime: (MSB)
 *    11  |  0x..  | TransferDataTime: (LSB)
 * \lhref FL942,FL943
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierFlashTimingParameter(uint8* const Data) {
  (void)memcpy(
      Data,
      &Dlog_CommonLogisticBtld.TimingParameters[0],
      sizeof(Dlog_CommonLogisticBtld.TimingParameters)
  );
  return E_OK;
} /* end of function 'Dlog_ReadDataByIdentifierTimingParameters'            */


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if (DLOG_ENABLE_TIMINGPARAMETERS == STD_ON) */

