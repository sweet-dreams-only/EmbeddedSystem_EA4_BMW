/*----------------------------------------------------------------------------*/
/**
*  \file
*  \ingroup API
*
*  \brief       Blu Swe Checkusm
*
*  This file contains the Srv_BluSweCheckSumType. This is needed here, since
*  the Srv module is the only BAC module that is shared between Bootmanager and Blu.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015
*
*  \version     3.1.0
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/

#ifndef SRV_BLUSWECHECKSUM_H_
#define SRV_BLUSWECHECKSUM_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Srv_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Srv_CHECK_VERSION(3,1,0))
   #error "Version of Srv_BluSweCheckSum.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef struct {
   uint32 crcValue;
   uint32 crcStartAddress;
   uint32 crcEndAddress;
   uint16 crcBlockStepSize;
   uint16 signatureSize;
} Srv_BluSweCheckSumType;

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* SRV_BLUSWECHECKSUM_H_ */

/*--- End of file ------------------------------------------------------------*/
