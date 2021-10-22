/**
 * \file
 *
 * \brief       Exception Handler.
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

#include "Dlog_SweException.h"    /* module own header file                  */

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON )
#include "Dlog_SweGet.h"  /* needed for Dlog_GetAddressOfFlashSegmentContainingValidFlag */
                          /* Dlog_GetAddressOfFlashSegmentContainingValidFlag */
#include "Bmhw_Platform_Cfg.h"  /* for BM_CLEAR_HARDWARE_ECC_ERROR_FLAG       */
#endif

#include "Dlog_Swe.h"
#include "Dlog_SweStatus.h"

#include <stddef.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */

/* MISRA-C:2004 Rule 14.2: void cast for unused parameter */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
  #error "Version of Dlog_SweException.c does not match the version of the module!"
#endif


#if ( DLOG_HANDLE_ECC_ROM == STD_ON )

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * On some platforms this function is called if a flash ROM
 * access exception (ECC) occured. If the hardware does not
 * support this DLOG_HANDLE_ECC_ROM must not be enabled.
 * This function checks if an ECC error occured due to an
 * power failure during bootloader flash operation.
 * It calls Dlog_UserRomAccessExceptionHandler() which
 * can be used to handle ROM ECC errors in general.
 *
 * \param[in] codeAddress Code address where the ROM data was accessed
 * \param[in] dataAddress ROM data address which can not be accessed
 *
 * \return Anything except zero will trigger a reset
 *
 * \remark This function runs in interrupt context
 *
 * \swsid SWS_Dlog_0365
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * In Bootmanager, the function shall set the ECC error flags of the affected SWE.
 * \swsid SWS_Dlog_0367
 *
 */
/*----------------------------------------------------------------------------*/
size_t Dlog_RomAccessExceptionHandler(size_t codeAddress, size_t dataAddress) {
  uint32 resetEcu;

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON)
  boolean isSwe = FALSE;

  /* iterate all SWEs                         */
  uint8_least sweId = 0;
  do {
    size_t segmentStartAddress;
    size_t segmentEndAddress;

    /* get address of flash segment   */
    /* containing the SWE valid flag  */
    Dlog_GetAddressOfFlashSegmentContainingValidFlag((uint8)sweId,
                                                     &segmentStartAddress,
                                                     &segmentEndAddress);

    /* if ECC error occured in flash segment    */
    /* containing the valid flag of the SWE     */
    if ((dataAddress >= segmentStartAddress) &&
        (dataAddress <= segmentEndAddress)) {
      /* set ECC error flag of SWE      */
      Dlog_SetEccErrorFlagOfSwe(sweId);

      /* clear hardware ECC error flag  */
      BM_CLEAR_HARDWARE_ECC_ERROR_FLAG();

      /* PR: SWE ECC error indication to be returned to calling MCE */
      isSwe = TRUE;
      break;
    }

    ++sweId;

  } while (sweId < (uint8_least)Dlog_CommonLogisticBtld.NumberOfAllSWEs);
#else
   /* MISRA-C:2004 Rule 14.2: we need the dataAddress for the user handler only */
   /* PRQA S 3112 1 */
   (void)dataAddress;
#endif /* #if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON )                 */

  /* MISRA-C:2004 Rule 14.2: we need the codeAddress for the user handler only */
  /* PRQA S 3112 1 */
  (void)codeAddress;


#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON)
  if (FALSE != isSwe) {
    resetEcu = 0;
  } else
#endif
  {
    /* notify the application         */
    resetEcu = Dlog_UserRomAccessExceptionHandler(codeAddress, dataAddress);
  }

  return resetEcu;
} /* end of function 'Dlog_RomAccessExceptionHandler'                          */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOG_HANDLE_ECC_ROM == STD_ON                                                 */
