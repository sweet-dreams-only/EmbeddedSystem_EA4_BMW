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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Vin_Dlog.h"

#include "Rte_Vin.h"

#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Dlog.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * Checks the given VIN against the internal VIN and sets the qualifier accordingly.
 *
 * \param[in,out] vin The VIN and qualifier
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_CheckInternalVin(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) vin)
{
   Dlog_VinArrayType internalVin;
   Std_ReturnType ret;

   ret = Rte_Call_DlogEcuInfo_GetVin(internalVin);
   if (E_OK == ret)
   {
      if (0 == memcmp(&internalVin[sizeof(internalVin) - sizeof(vin->Vin)], vin->Vin, sizeof(vin->Vin)))
      {
         vin->Qualifier |= VIN_QUAL_EQ_INTERNAL;
      }
   }
}

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"
