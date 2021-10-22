/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file is a Adapter for the Service Interface.
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

#if (Vin_ENABLE_SI_ADAPTER == STD_ON)

#include "Rte_VinSIAdapter.h"

#include "BUtil_ByteMask.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_SIAdapter.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_8
#include "Vin_MemMap.h"

static VAR(uint8, Vin_VAR_NOINIT) Vin_SsvId;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_8
#include "Vin_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

#if (Vin_ENABLE_SECURE_VIN == STD_ON)

/**
 * Called upon reception of the Challenge from the Vin SWC.
 */
FUNC(void, Vin_CODE) Vin_SIAChallenge(void)
{
   Vin_ChallengeRecordType challenge;

   (void)Rte_Receive_Challenge_Challenge(&challenge);

   Vin_SsvId = challenge.SsvId;

   (void)Rte_Call_ChassisNumberAuthentication_generateAuthenticationCode(
         challenge.SsvId,
         challenge.Challenge);
}

FUNC(void, RTE_APPL_CODE) Vin_SIAGenAuthCodeReturn(void)
{
   Vin_CounterBaseArrayType counterBase;
   Vin_CounterBaseArrayType counterBaseMAC;
   Vin_SSVMACRecordType vinMAC;
   Vin_ResponseRecordType response;
   Std_ReturnType ret;

   ret = Rte_Result_ChassisNumberAuthentication_generateAuthenticationCode(
         counterBase,
         counterBaseMAC,
         vinMAC.Mac);

   if (E_OK == ret) {
      response.CounterBase = BUtil_Make32Bit(0, counterBase[0], counterBase[1], counterBase[2]);
      response.Signature = BUtil_Make32Bit(0, counterBaseMAC[0], counterBaseMAC[1], counterBaseMAC[2]);
      response.SsvId = Vin_SsvId;
      (void)Rte_Write_SSVResponseFromSSS_Response(&response);
      (void)Rte_Write_SSVVinMacFromSSS_Mac(&vinMAC);
   }
}

#endif /* #if (Vin_ENABLE_SECURE_VIN == STD_ON) */

/**
 * Called upon reception of the RequestMessageIdentifier from the Vin SWC.
 */
FUNC(void, Vin_CODE) Vin_SIARequest(void)
{
   Std_ReturnType ret;
   uint16 msgId;

   ret = Rte_Receive_VinRequest_RequestMessageIdentifier(&msgId);

   if ((E_OK == ret) && (VIN_VINREQUEST_MESSAGE_IDENTIFIER == msgId))
   {
      (void)Rte_Call_ChassisNumber_FieldGetterChassisNumber();
   }
}

/**
 * Called upon return of FieldGetterChassisNumber. Forwards the VIN to the Vin SWC.
 */
FUNC(void, Vin_CODE) Vin_SIAGetterChassisNumberReturn(void)
{
   Std_ReturnType ret;
   Vin_ComVinType vin;

   ret = Rte_Result_ChassisNumber_FieldGetterChassisNumber(&vin);

   if (E_OK == ret)
   {
      /* send VIN to Vin SWC */
      (void)Rte_Write_ComVin_ComVin(&vin);
   }
}

/**
 * Called upon reception of the VIN via the notifier signal. Forwards the VIN to the Vin SWC.
 */
FUNC(void, Vin_CODE) Vin_SIANotifyChassisNumber(void)
{
   P2CONST(Vin_ComVinType, AUTOMATIC, Vin_APPL_DATA) vin =
         Rte_IRead_Vin_SIANotifyChassisNumber_ChassisNumberNotifier_ComVin();

   Rte_IWrite_Vin_SIANotifyChassisNumber_ComVin_ComVin(vin);
}

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"

#else

typedef char Vin_DummyType;

#endif /* #if (Vin_ENABLE_SI_ADAPTER == STD_ON) */
