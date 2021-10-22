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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 5.6: Normal variable names. There should be no confusion at all.
 * See PRQA:0781 */

/*
 * MISRA-C:2004 Rule 14.7: early return on error makes code more readable,
 * see PRQA 2006, 5207
 */

/* MISRA-C:2004 Rule 17.4. Reason: arrays are passed as pointers due to compiler abstraction,
   see PRQA: 0492 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Vin_Ssv.h"
#include "Vin_PBCfg.h"

#include "Vin.h"
#include "Rte_Vin.h"

#include "Vin_Dlog.h"

#include "BUtil_ByteMask.h"
#include "BUtil_Assert.h"

#include <string.h>

#if (Vin_ENABLE_SECURE_VIN == STD_ON)
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Ssv.c does not match the version of the module!"
#endif


#define VIN_SSV_CHALLENGE_LENGTH  5u

#define VIN_SSV_RESP_SIZE         16u
#define VIN_SSV_RESP_OFFSET_SSVID      VIN_SSV_CHALLENGE_LENGTH
#define VIN_SSV_RESP_OFFSET_COUTERBASE (VIN_SSV_RESP_OFFSET_SSVID + 1u)
#define VIN_SSV_RESP_OFFSET_PADDING    (VIN_SSV_RESP_OFFSET_COUTERBASE + 3u)
#define VIN_SSV_RESP_SIZEOF_PADDING    (VIN_SSV_RESP_SIZE - VIN_SSV_RESP_OFFSET_PADDING)

   /* PRQA S 4104 1 *//* MISRA-C:2004 Rule 12.6: tested Macro of BUtil */
BUTIL_STATIC_ASSERT(VIN_SSV_RESP_SIZEOF_PADDING > 0, "Invalid Response Message Format!");

#define VIN_SSV_ERC_FSCSM_SSV_ERROR_STATE     0x06u
#define VIN_SSV_ERC_FSCSM_MESSAGE_TIMEOUT_REQ 0x08u


/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

typedef struct {
   enum {
      VIN_SSV_WAITFORF50 = 0,
      VIN_SSV_WAITFORSSS,
      VIN_SSV_IDLE,
      VIN_SSV_ERROR
   } runState;
   uint8 challengeSendCounter;
   boolean counterBaseReceived;
   uint8 macRequestCounter;
   boolean macReceived;
   uint8 counterBaseTimeout;
   uint8 macTimeout;
} Vin_SsvStateType;


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_8
#include "Vin_MemMap.h"

/**
 * \brief Array which stores the generated challenge of each Ssv
 */
static VAR(uint8, Vin_VAR_NOINIT)            Vin_SsvChallenge[VIN_SSV_CHALLENGE_LENGTH];

static VAR(uint8, Vin_VAR_NOINIT)            Vin_CurrentMac[8];

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_8
#include "Vin_MemMap.h"

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_32
#include "Vin_MemMap.h"

static VAR(uint32, Vin_VAR_NOINIT)           Vin_Counterbase;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_32
#include "Vin_MemMap.h"

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"

static VAR(Vin_SsvStateType, Vin_VAR_NOINIT) Vin_SsvState;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

#if (Vin_ENABLE_SI_ADAPTER != STD_ON)
static FUNC(void, Vin_CODE) Vin_ReverseCopy(
      P2VAR(uint8, AUTOMATIC, Vin_APPL_DATA) dest,
      P2CONST(uint8, AUTOMATIC, Vin_APPL_DATA) src,
      uint32 length);
static FUNC(void, Vin_CODE) Vin_SsvRequestMac(void);
static FUNC(void, Vin_CODE) Vin_SsvHandleMacError(void);
#endif
static FUNC(void, Vin_CODE) Vin_SsvSendChallengeToSSS(void);
static FUNC(void, Vin_CODE) Vin_SsvHandleCounterbaseError(void);


/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#if (Vin_ENABLE_SI_ADAPTER != STD_ON)
/*----------------------------------------------------------------------------*/
/**
 * Copies src to dest in reverse orde, i.e. the first byte of dest will be
 * the last byte of src and so on.
 *
 * \param[out] dest   destination
 * \param[in]  src    source
 * \param[in]  length number of bytes to copy
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_ReverseCopy(
      P2VAR(uint8, AUTOMATIC, Vin_APPL_DATA) dest,
      P2CONST(uint8, AUTOMATIC, Vin_APPL_DATA) src,
      uint32 length)
{
   uint32 i;
   for(i = 0; i < length; ++i)
   {
      dest[i] = src[length - i - 1]; /* PRQA S 0492 */
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Sends a message to request the MAC.
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_SsvRequestMac(void)
{
   if (Vin_ERROR_LIMIT_MAC <= Vin_SsvState.macRequestCounter)
   {
      Vin_SsvHandleMacError();
      return;
   }
   (void)Rte_Send_VinRequest_RequestMessageIdentifier(VIN_MACREQUEST_MESSAGE_IDENTIFIER);

   ++Vin_SsvState.macRequestCounter;
}
#endif /* #if (Vin_ENABLE_SI_ADAPTER != STD_ON) */

/*----------------------------------------------------------------------------*/
/**
 * Generates a challenge and sends it to the SSS.
 *
 * \global_rw Vin_SsvState
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_SsvSendChallengeToSSS(void)
{
   Vin_ChallengeRecordType challenge;
   Std_ReturnType ret;

   /* PRQA S 4104 1 *//* MISRA-C:2004 Rule 12.6: tested Macro of BUtil */
   BUTIL_STATIC_ASSERT(sizeof(challenge.Challenge) == sizeof(Vin_SsvChallenge), "Challenge sizes do not match!");

   if (Vin_ERROR_LIMIT_COUNTERBASE <= Vin_SsvState.challengeSendCounter)
   {
      Vin_SsvHandleCounterbaseError();
      return;
   }

   ret = Rte_Call_RandomNumberGenerator_GenerateRandomNumber(Vin_SsvChallenge, sizeof(Vin_SsvChallenge));
   Vin_Assert(E_OK == ret, VIN_RANDOM_NUMBER_GENERATOR_API_ID, ret);
#if (Vin_ENABLE_SI_ADAPTER != STD_ON)
   /* Don't know why we have to reverse the challenge on CAN/FR, but we have to */
   Vin_ReverseCopy(challenge.Challenge, Vin_SsvChallenge, sizeof(challenge.Challenge));
#else
   (void)memcpy(challenge.Challenge, Vin_SsvChallenge, sizeof(challenge.Challenge));
#endif
   challenge.SsvId = Vin_PBConfigSetPtr->SsvId;
   challenge.SssId = Vin_REMOTE_SSS_ID;

   (void)Rte_Send_SSVChallengeToSSS_Challenge(&challenge);

   ++Vin_SsvState.challengeSendCounter;
} /* PRQA S 2006 */

/*----------------------------------------------------------------------------*/
/**
 * Handles a counterbase error
 *
 * \global_w Vin_SsvState
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_SsvHandleCounterbaseError(void)
{
   Std_ReturnType ret;

   ret = Rte_Write_SSVErrorCode_ErrorCode(VIN_SSV_ERC_FSCSM_SSV_ERROR_STATE);
   Vin_Assert(E_OK == ret, VIN_RTE_API_ID, ret);
   (void)Rte_Call_DiagnosticMonitor_FscsmErrorEvent_SetEventStatus(DEM_EVENT_STATUS_FAILED);
   Vin_SsvState.runState = VIN_SSV_ERROR;

   /* update qualifier */
   Vin_NotifyVinSecurityUpdate();
}

#if (Vin_ENABLE_SI_ADAPTER != STD_ON)
/*----------------------------------------------------------------------------*/
/**
 * Handles a MAC timeout error
 *
 * \global_w Vin_SsvState
 */
/*----------------------------------------------------------------------------*/
static FUNC(void, Vin_CODE) Vin_SsvHandleMacError(void)
{
   Std_ReturnType ret;
   Vin_EnvironmentType environment = Vin_GetEnvironment(); /* PRQA S 0781 */

   if (VIN_SAFE_ENVIRONMENT == environment)
   {
      ret = Rte_Write_SSVErrorCode_ErrorCode(VIN_SSV_ERC_FSCSM_MESSAGE_TIMEOUT_REQ);
      Vin_Assert(E_OK == ret, VIN_RTE_API_ID, ret);
      (void)Rte_Call_DiagnosticMonitor_FscsmErrorEvent_SetEventStatus(DEM_EVENT_STATUS_FAILED);
   }
   Rte_Enter_VinState();
   /* not receiving the MAC is not considered an error for the SSV -> normal idle state instead of error */
   Vin_SsvState.runState = VIN_SSV_IDLE;
   Rte_Exit_VinState();

   /* update qualifier */
   Vin_NotifyVinSecurityUpdate();
}
#endif /* #if (Vin_ENABLE_SI_ADAPTER != STD_ON) */

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Initializes the Vin_Ssv
 *
 * \global_w Vin_SsvState
 *
 * \pre EA VinState shall be entered
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvInit(void)
{
   boolean vkEstablished = Rte_DRead_FscsmVK_Established_Flag();

   Vin_SsvState.challengeSendCounter = 0;
   Vin_SsvState.counterBaseReceived = FALSE;
   Vin_SsvState.macRequestCounter = 0;
   Vin_SsvState.macReceived = FALSE;
   Vin_SsvState.counterBaseTimeout = Vin_TIMEOUT_COUNTERBASE;
   Vin_SsvState.macTimeout = Vin_TIMEOUT_MAC;
   if (FALSE == vkEstablished)
   {
      Vin_SsvState.runState = VIN_SSV_WAITFORF50;
   }
   else
   {
      Vin_SsvState.runState = VIN_SSV_WAITFORSSS;
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Called, when VIN communication is going on
 *
 * \global_rw Vin_SsvState
 *
 * \pre EA VinState shall be entered
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvOnComOn(void)
{
   if (FALSE == Vin_SsvState.macReceived)
   {
      Vin_SsvState.macRequestCounter = 0;
      Vin_SsvState.macTimeout = Vin_TIMEOUT_MAC;
   }
   if (FALSE == Vin_SsvState.counterBaseReceived)
   {
      Vin_SsvState.challengeSendCounter = 0;
      Vin_SsvState.counterBaseTimeout = Vin_TIMEOUT_COUNTERBASE;
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Called, when a new VKEstablished flag is available
 *
 * \global_rw Vin_SsvState
 *
 * \swsid SWS_Vin_0081
 *
 * \remark This is a RTE runnable which runs inside the exclusive area VinState.
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, RTE_APPL_CODE) Vin_SsvOnVkEstablished(void)
{
   boolean vkEstablished = Rte_IRead_Vin_SsvOnVkEstablished_FscsmVK_Established_Flag();

   if ((TRUE == vkEstablished) && (VIN_SSV_WAITFORF50 == Vin_SsvState.runState))
   {
      Vin_SsvState.runState = VIN_SSV_WAITFORSSS;
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Main function, called every 100ms
 *
 * \global_rw Vin_SsvState
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvMain(void)
{
   if (VIN_SSV_WAITFORSSS != Vin_SsvState.runState)
   {
      return;
   }
#if (Vin_ENABLE_SI_ADAPTER != STD_ON)
   if (FALSE == Vin_SsvState.macReceived)
   {
      ++Vin_SsvState.macTimeout;
      if (Vin_TIMEOUT_MAC <= Vin_SsvState.macTimeout)
      {
         Vin_SsvRequestMac();
         Vin_SsvState.macTimeout = 0;
      }
   }
   else
#endif
        if (FALSE == Vin_SsvState.counterBaseReceived)
   {
      ++Vin_SsvState.counterBaseTimeout;
      if (Vin_TIMEOUT_COUNTERBASE <= Vin_SsvState.counterBaseTimeout)
      {
         Vin_SsvSendChallengeToSSS();
         Vin_SsvState.counterBaseTimeout = 0;
      }
   }
   else
   {
      /* nothing to do - just satisfy MISRA */
   }
} /* PRQA S 2006,5207 */

/*----------------------------------------------------------------------------*/
/**
 * Checks the MAC of the VIN
 *
 * \global_r Vin_SsvState
 *
 * \lhref FsCSM_796
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvCheckMac(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) vin)
{
   Fscsm_MessageArrayType message;
   Std_ReturnType ret;
   Vin_SsvStateType locSsvState;

   boolean vkEstablished = Rte_DRead_FscsmVK_Established_Flag();
   Vin_EnvironmentType environment = Vin_GetEnvironment();  /* PRQA S 0781 */

   Rte_Enter_VinState();
   locSsvState = Vin_SsvState;
   Rte_Exit_VinState();

   if ((FALSE == vkEstablished) || (FALSE == locSsvState.counterBaseReceived) || (FALSE == locSsvState.macReceived))
   {
      /* No security information received yet -> Check Environment */
      if (VIN_UNSAFE_ENVIRONMENT != environment)
      {
         if (VIN_SSV_ERROR == locSsvState.runState)
         {
            /* Preconditions not fulfilled, and already in error state -> finished */
            vin->Qualifier |= VIN_QUAL_SECURE_FINISHED;
         }
         else
         {
            /* Preconditions not fulfilled yet -> Pending */
            vin->Qualifier |= VIN_QUAL_SECURE_PENDING;
         }
      }  /* else we are unsafe and therefore no check needed */
      return;
   }

   (void)memcpy(message, vin->Vin, sizeof(vin->Vin));
   message[7] = 0; /* Padding up to 64 Bit */
   message[8] = BUtil_GetHiLoByte(Vin_Counterbase);
   message[9] = BUtil_GetLoHiByte(Vin_Counterbase);
   message[10] = BUtil_GetLoLoByte(Vin_Counterbase);
   (void)memset(&message[11], 0, 5); /* Padding 40 Bit 0's */

   ret = Rte_Call_FscsmCryptographicFunctions_VerifyMessage(message, 16, Vin_CurrentMac, sizeof(Vin_CurrentMac));

   switch(ret)
   {
      case E_OK:
         vin->Qualifier |= VIN_QUAL_SECURE_FINISHED | VIN_QUAL_SECURE_OK;
         if (VIN_SAFE_ENVIRONMENT != environment)
         {
            Vin_SwitchToSafeEnvironment();
         }
        break;
      case RTE_E_FscsmApplSwcInterface_FSCSM_E_MISSING_KEYS:
         vin->Qualifier |= VIN_QUAL_SECURE_PENDING;
         break;
      default:
         vin->Qualifier |= VIN_QUAL_SECURE_FINISHED;
         break;
   }
  /* PRQA S 5203 1 *//* a critical section does not make the code more complex */
} /* PRQA S 2006 */

/*----------------------------------------------------------------------------*/
/**
 * Gets and checks the current VIN.
 *
 * This is called via data received event CheckVinTrigger
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvCheckVin(void)
{
   VAR(Vin_VinType, Vin_VAR) vin;
   Std_ReturnType ret;

   Vin_GetCurrentVin(&vin);

   if (VIN_QUAL_INIT != vin.Qualifier)
   {
      Vin_SsvCheckMac(&vin);
      ret = Rte_Write_Vin_Vin(&vin);
      Vin_Assert(E_OK == ret, VIN_RTE_API_ID, ret);
   }
}

/*----------------------------------------------------------------------------*/
/**
 * Called on a data received event when the response has been received from the SSS.
 *
 * \global_r  Vin_SsvChallenge
 * \global_w  Vin_Counterbase
 * \global_rw Vin_SsvState
 *
 * \swsid SWS_Vin_0082
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvReceiveResponseFromSss(void)
{
   Std_ReturnType ret;
   uint8 message[VIN_SSV_RESP_SIZE];
   uint8 mac[3];
   P2CONST(Vin_ResponseRecordType, AUTOMATIC, Vin_APPL_CONST) response = Rte_IRead_Vin_SsvReceiveResponseFromSss_SSVResponseFromSSS_Response();

   if (Vin_PBConfigSetPtr->SsvId != response->SsvId)
   {
      return;
   }

   Rte_Enter_VinState();
   (void)memcpy(message, Vin_SsvChallenge, sizeof(Vin_SsvChallenge));
   Rte_Exit_VinState();

   message[VIN_SSV_RESP_OFFSET_SSVID] = Vin_PBConfigSetPtr->SsvId;
   message[VIN_SSV_RESP_OFFSET_COUTERBASE+0] = BUtil_GetHiLoByte(response->CounterBase);
   message[VIN_SSV_RESP_OFFSET_COUTERBASE+1] = BUtil_GetLoHiByte(response->CounterBase);
   message[VIN_SSV_RESP_OFFSET_COUTERBASE+2] = BUtil_GetLoLoByte(response->CounterBase);
   (void)memset(&message[VIN_SSV_RESP_OFFSET_PADDING], 0, VIN_SSV_RESP_SIZEOF_PADDING);

   mac[0] = BUtil_GetHiLoByte(response->Signature);
   mac[1] = BUtil_GetLoHiByte(response->Signature);
   mac[2] = BUtil_GetLoLoByte(response->Signature);

   ret = Rte_Call_FscsmCryptographicFunctions_VerifyMessage(message, sizeof(message), mac, sizeof(mac));

   if (E_OK == ret)
   {
      boolean locMacReceived;
      Rte_Enter_VinState();
      /* counterbase successfully received */
      Vin_Counterbase = response->CounterBase;
      Vin_SsvState.counterBaseReceived = TRUE;
      locMacReceived = Vin_SsvState.macReceived;
      Rte_Exit_VinState();

      if (FALSE != locMacReceived)
      {
         Vin_NotifyVinSecurityUpdate();
      }
   }
   else
   {
      Vin_SsvSendChallengeToSSS();
   }
} /* PRQA S 2006 */

/*----------------------------------------------------------------------------*/
/**
 * Called on a data received event when the MAC has been received.
 *
 * \global_w Vin_CurrentMac
 * \global_w Vin_SsvState
 *
 * \swsid SWS_Vin_0083
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Vin_CODE) Vin_SsvReceiveMac(void)
{
   P2CONST(Vin_SSVMACRecordType, AUTOMATIC, RTE_APPL_CONST) mac = Rte_IRead_Vin_SsvReceiveMac_SSVVinMacFromSSS_Mac();
   /* PRQA S 4104 1 *//* MISRA-C:2004 Rule 12.6: tested Macro of BUtil */
   BUTIL_STATIC_ASSERT(sizeof(Vin_CurrentMac) == sizeof(mac->Mac), "size mismatch");

   Rte_Enter_VinState();
   (void)memcpy(Vin_CurrentMac, mac->Mac, sizeof(Vin_CurrentMac));
   Vin_SsvState.macReceived = TRUE;
   Rte_Exit_VinState();

   Vin_NotifyVinSecurityUpdate();
}

/*----------------------------------------------------------------------------*/
/**
 * Returns the current SSV state
 *
 * \param[out] mac          current MAC
 * \param[out] errorCounter current error counter
 * \param[out] counterbase  current counterbase
 *
 * \swsid SWS_Vin_0084
 *
 * \remark This function is needed by the Fscsm module for the FAT test
 *
 */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, Vin_CODE) Vin_SsvStateGet(
      P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) mac,
      P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) errorCounter,
      P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) counterbase)
{
   Rte_Enter_VinState();
   (void)memcpy(mac,Vin_CurrentMac,sizeof(Vin_CurrentMac));
   *errorCounter = (Vin_SsvState.challengeSendCounter > 1) ? (Vin_SsvState.challengeSendCounter - 1) : 0;
   if (VIN_SSV_ERROR == Vin_SsvState.runState)
   {
      *errorCounter = Vin_ERROR_LIMIT_COUNTERBASE;
   }
   *counterbase = Vin_Counterbase;
   Rte_Exit_VinState();
   return E_OK;
}


/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"

#endif /* #if (Vin_ENABLE_SECURE_VIN == STD_ON) */
