/**
 * \file
 *
 * \brief       Blu Swe Checkusm
 *
 * This file contains the Dlog_BluSweCheckSumType.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 * \remarks     --
 *
 */

#ifndef DLOG_BLUSWECHECKSUM_H_
#define DLOG_BLUSWECHECKSUM_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "DlogClassic_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_BluSweCheckSum.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef struct {
  uint32 crcValue;
  size_t crcStartAddress;
  size_t crcEndAddress;
  uint16 crcBlockStepSize;
  uint16 signatureSize;
} Dlog_BluSweCheckSumType;

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* DLOG_BLUSWECHECKSUM_H_ */

/*--- End of file ------------------------------------------------------------*/
