/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file conatins the interface to the Com BSWC.
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

#include "Vin_Cfg.h"
#include "Vin.h"
#include "Vin_Helper.h"
#include "Rte_Vin.h"

#if (Vin_ENABLE_SECURE_VIN == STD_ON)
#include "Vin_Ssv.h"
#endif

#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Com.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

LOCAL_INLINE FUNC(boolean, Vin_CODE) Vin_ComIsValid(P2CONST(Vin_ComVinType, AUTOMATIC, AUTOMATIC) vin);


/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

LOCAL_INLINE FUNC(boolean, Vin_CODE) Vin_ComIsValid(P2CONST(Vin_ComVinType, AUTOMATIC, AUTOMATIC) vin)
{
   return (boolean)
          ((vin->Vin1 != 0xff) &&
           (vin->Vin2 != 0xff) &&
           (vin->Vin3 != 0xff) &&
           (vin->Vin4 != 0xff) &&
           (vin->Vin5 != 0xff) &&
           (vin->Vin6 != 0xff) &&
           (vin->Vin7 != 0xff));
}


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Called on a data received event
 *
 * \global_rw Vin_CurrentVin
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_ReceiveFromCom (void)
{
   P2CONST(Vin_ComVinType, AUTOMATIC, AUTOMATIC) vinFromCom = Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin();

   if ((FALSE != Vin_ComIsValid(vinFromCom)) && /* PRQA S 3415 2 *//* Vin_ComIsValid has no side effects */
       ((0    != memcmp(Vin_CurrentVin.Vin, vinFromCom, sizeof(Vin_CurrentVin.Vin))) || /* so does memcmp */
             (!VIN_CHECKQUALIFIER(Vin_CurrentVin.Qualifier, VIN_CQ_VIN_RECEIVED))))
   {
      Vin_CurrentVin.Qualifier = VIN_QUAL_RECEIVED;

      Vin_CurrentVin.Vin[0] = vinFromCom->Vin1;
      Vin_CurrentVin.Vin[1] = vinFromCom->Vin2;
      Vin_CurrentVin.Vin[2] = vinFromCom->Vin3;
      Vin_CurrentVin.Vin[3] = vinFromCom->Vin4;
      Vin_CurrentVin.Vin[4] = vinFromCom->Vin5;
      Vin_CurrentVin.Vin[5] = vinFromCom->Vin6;
      Vin_CurrentVin.Vin[6] = vinFromCom->Vin7;

      Vin_NotifyVinReceived();
   }
}

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"
