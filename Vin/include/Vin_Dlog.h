/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file contains the interface to the Dlog module.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

#ifndef VIN_DLOG_H_
#define VIN_DLOG_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Rte_Vin_Type.h"
#include "Vin_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Dlog.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

extern FUNC(void, Vin_CODE) Vin_CheckInternalVin(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) vin);

#endif /* VIN_DLOG_H_ */

/*--- End of file ------------------------------------------------------------*/
