/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  Contains the SSV functionality of the Vin module
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

#ifndef VIN_SSV_H_
#define VIN_SSV_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Vin_Cfg.h"
#include "Rte_Vin_Type.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Ssv.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

extern FUNC(void, Vin_CODE) Vin_SsvInit(void);
extern FUNC(void, Vin_CODE) Vin_SsvOnComOn(void);
extern FUNC(void, Vin_CODE) Vin_SsvMain(void);

extern FUNC(void, Vin_CODE) Vin_SsvCheckMac(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) vin);

#endif /* VIN_SSV_H_ */

/*--- End of file ------------------------------------------------------------*/
