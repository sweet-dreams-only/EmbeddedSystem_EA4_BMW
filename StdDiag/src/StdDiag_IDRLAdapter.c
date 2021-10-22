/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiag_IDRLAdapter.h"
#include "StdDiagClassic_Cfg.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_IDRLAdapter.c does not match the adapter or generic version!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

#if( STDDIAG_IDRL_SUPPORT == STD_ON )

#if (STDDIAG_INDIV_DID_NUMBER > 0)
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_IndivDataLength holds the length of an individual data
 */
static uint16 StdDiag_IndivDataLength;

/**
 * \brief StdDiag_IndivDIDIndex holds the index of an individual DID
 */
static uint16 StdDiag_IndivDIDIndex;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_IDRLClientReturnedPending holds the boolean value that states if the IDRLClient has returned a pending.
 */
static boolean StdDiag_IDRLClientReturnedPending;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief the data array StdDiag_IndivDataArray for holding an individual data
 */
static uint8 StdDiag_IndivDataArray[STDDIAG_BUFFER_SIZE_INDIV_DATA];

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"
/**
 * \brief StdDiag_InitialCalled holds the boolean value that states if a function has been invoked with the OpStatus DCM_INITIAL.
 */
static boolean StdDiag_InitialCalled;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_ResetIndivDataResult holds the result of resetting individual data
 *  persistently over pending cycles of asynchronous Dcm calls
 */
static uint8 StdDiag_ResetIndivDataResult;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief the array StdDiag_ResetIndivDataStatus to determine, which rte result invocations
 * of resetting individual data of IDRL clients data are finished.
 */
static Std_ReturnType StdDiag_ResetIndivDataStatus[STDDIAG_IDRL_CLIENT_NUMBER];

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */

#endif /*STDDIAG_IDRL_SUPPORT == STD_ON*/

/*------------------------------------------------------------------------------
                      Local Function Prototypes
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

#if (STDDIAG_IDRL_SUPPORT == STD_ON)
#if (STDDIAG_INDIV_DID_NUMBER > 0)
static Std_ReturnType StdDiag_ReadIndivData(uint16 DIDindex);
static Std_ReturnType StdDiag_GetRteResultReadIndivData(uint16 DIDindex);
static Std_ReturnType StdDiag_WriteIndivData(
   uint16 DIDindex,
   const uint8 *Data,
   uint16 DataLength);
static Std_ReturnType StdDiag_GetRteResultWriteIndivData(uint16 DIDindex);
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */
#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
static Std_ReturnType StdDiag_GetRteResultResetIndivData(void);
static void StdDiag_CancelResetIndivData(void);
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */
#endif /* STDDIAG_IDRL_SUPPORT == STD_ON */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#if( STDDIAG_IDRL_SUPPORT == STD_ON )
#if (STDDIAG_INDIV_DID_NUMBER > 0)
/**
 * \brief the function reading the IndivData
 *
 * This function reads the IndivData.
 *
 * \param[in] DIDindex an array index for a DID
 *
 * \retval E_OK the individual data is successfully read.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING reading individual data is pending.
 * \retval E_NOT_OK reading individual data is failed.
 *
 */
static Std_ReturnType StdDiag_ReadIndivData(uint16 DIDindex)
{
   Std_ReturnType retVal;

   retVal = StdDiag_ReadIndivDataAccess[DIDindex].rteCallFuncPtr(STDDIAG_IDRL_INITIAL, STDDIAG_BUFFER_SIZE_INDIV_DATA);
   if (retVal == RTE_E_LIMIT)
   {
      /*
       * This case means that the StdDiag has not retrieved the result of the last server call of reading individual data,
       * now try to finish the previous server call.
       */
      retVal = StdDiag_GetRteResultReadIndivData(DIDindex);
      if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
      {
         /* It means that the previous server call has been finished, now try to perform a new server call. */
         retVal = StdDiag_ReadIndivDataAccess[DIDindex].rteCallFuncPtr(STDDIAG_IDRL_INITIAL, STDDIAG_BUFFER_SIZE_INDIV_DATA);
      }
   }
   if (retVal == E_OK)
   {
      /* try to get the result of the function reading individual data */
      retVal = StdDiag_GetRteResultReadIndivData(DIDindex);
   }
   else if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
   {
      retVal = E_NOT_OK;
   }
   else
   {
      /* in case STDDIAG_E_OperateIndivData_E_PENDING, nothing is needed to do */
   }

   return retVal;
}

/**
 * \brief getting the RTE result of the function of reading the IndivData
 *
 * This function gets the RTE result of the function of reading the IndivData.
 *
 * \global_w StdDiag_IndivDataArray, StdDiag_IndivDataLength,
 *           StdDiag_IDRLClientReturnedPending
 *
 * \param[in] DIDindex an array index for a DID
 *
 * \retval E_OK the RTE result of reading individual data is available.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING
 *              the RTE result of reading individual data is not
 *              available. A Response Pending is needed.
 * \retval E_NOT_OK the RTE result of reading individual data is failed.
 *
 */
static Std_ReturnType StdDiag_GetRteResultReadIndivData(uint16 DIDindex)
{
   Std_ReturnType retVal;
   uint16 DataLength;

   /* try to get the result of the function reading individual data */
   retVal = StdDiag_ReadIndivDataAccess[DIDindex].rteResultFuncPtr(&DataLength, StdDiag_IndivDataArray);
   if ((retVal == E_OK)&&(DataLength <= STDDIAG_BUFFER_SIZE_INDIV_DATA))
   {
      StdDiag_IndivDataLength = DataLength;
   }
   else if (retVal == STDDIAG_E_OperateIndivData_E_PENDING)
   {
      StdDiag_IDRLClientReturnedPending = TRUE;
   }
   else if (retVal == RTE_E_NO_DATA)
   {
      retVal = STDDIAG_E_OperateIndivData_E_PENDING;
   }
   else
   {
      retVal = E_NOT_OK;
   }

   return retVal;
}

/**
 * \brief the function writing the IndivData
 *
 * This function writes the IndivData.
 *
 * \param[in] DIDindex an array index for a DID
 *
 * \param[in] Data pointer to the buffer, where the individual
 *                 data is stored.
 * \param[in] DataLength The length of the data to be written
 *
 * \retval E_OK the indiv data is successfully written.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING writing individual data is pending.
 * \retval E_NOT_OK writing individual data is failed.
 *
 */
static Std_ReturnType StdDiag_WriteIndivData(
   uint16 DIDindex,
   const uint8 *Data,
   uint16 DataLength)
{
   Std_ReturnType retVal;

   retVal = StdDiag_WriteIndivDataAccess[DIDindex].rteCallFuncPtr(STDDIAG_IDRL_INITIAL, DataLength, Data);
   if (retVal == RTE_E_LIMIT)
   {
      /*
       * This case means that the StdDiag has not retrieved the result of the last server call of writing individual data,
       * now try to finish the previous server call.
       */
      retVal = StdDiag_GetRteResultWriteIndivData(DIDindex);
      if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
      {
         /* It means that the previous server call has been finished, now try to perform a new server call. */
         retVal = StdDiag_WriteIndivDataAccess[DIDindex].rteCallFuncPtr(STDDIAG_IDRL_INITIAL, DataLength, Data);
      }
   }
   if (retVal == E_OK)
   {
      /* try to get the result of the function reading individual data */
      retVal = StdDiag_GetRteResultWriteIndivData(DIDindex);
   }
   else if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
   {
      retVal = E_NOT_OK;
   }
   else
   {
      /* in case STDDIAG_E_OperateIndivData_E_PENDING, nothing is needed to do */
   }
   return retVal;
}

/**
 * \brief getting the RTE result of the function of writing the IndivData
 *
 * This function gets the RTE result of the function of writing the IndivData.
 *
 * \global_w StdDiag_IDRLClientReturnedPending
 *
 * \param[in] DIDindex an array index for a DID
 *
 * \retval E_OK the RTE result of writing indiv data is available.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING
 *              the RTE result is not available. A Response Pending is needed.
 * \retval E_NOT_OK the RTE result of writing individual data is failed.
 *
 */
static Std_ReturnType StdDiag_GetRteResultWriteIndivData(uint16 DIDindex)
{
   Std_ReturnType retVal;

   /* try to get the RTE result of the function writing individual data */
   retVal = StdDiag_WriteIndivDataAccess[DIDindex].rteResultFuncPtr();

   if (retVal == STDDIAG_E_OperateIndivData_E_PENDING)
   {
      StdDiag_IDRLClientReturnedPending = TRUE;
   }
   else if (retVal == RTE_E_NO_DATA)
   {
      retVal = STDDIAG_E_OperateIndivData_E_PENDING;
   }
   else if (retVal != E_OK)
   {
      retVal = E_NOT_OK;
   }
   else
   {
      /* nothing is needed to do */
   }

   return retVal;
}

#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
/**
 * \brief getting the RTE result of the function of resetting the IndivData
 *
 * This function gets the RTE result of the function of resetting the IndivData.
 *
 * \global_w  StdDiag_ResetIndivDataResult
 * \global_rw StdDiag_ResetIndivDataStatus
 *
 * \retval E_OK all RTE results of resetting individual data are available.
 * \retval RTE_E_RoutineServices_ResetIndivData_DCM_E_PENDING
 *              at least one RTE result of resetting individual data is not
 *              available. A Response Pending is needed.
 *
 */
static Std_ReturnType StdDiag_GetRteResultResetIndivData(void)
{
   Std_ReturnType retVal = E_OK;
   Std_ReturnType rteResult;
   uint16 i;

   for (i = 0; i < STDDIAG_IDRL_CLIENT_NUMBER; i++)
   {
      if (StdDiag_ResetIndivDataStatus[i] == RTE_E_ResetIndivData_E_PENDING)
      {
         /*
          * This case means that the IDRL client has returned RTE_E_ResetIndivData_E_PENDING to the RTE, when the rte result was called.
          * In this case, the rte call has to be called with the status parameter STDDIAG_IDRL_PENDING again.
          */
         if (StdDiag_ResetIndivDataAccess[i].rteCallFuncPtr(STDDIAG_IDRL_PENDING) != E_OK)
         {
            /* It means that the rte call is failed, and the rte result is not needed to be invoked. */
            StdDiag_ResetIndivDataStatus[i] = E_OK;
            StdDiag_ResetIndivDataResult = 0x01u;
         }
      }

      if (StdDiag_ResetIndivDataStatus[i] != E_OK)
      {
         /*getting the result*/
         rteResult = StdDiag_ResetIndivDataAccess[i].rteResultFuncPtr();
         switch (rteResult)
         {
            case E_OK:
               StdDiag_ResetIndivDataStatus[i] = E_OK;
               break;

            case RTE_E_ResetIndivData_E_PENDING:
               StdDiag_ResetIndivDataStatus[i] = RTE_E_ResetIndivData_E_PENDING;
               /* This case means that the IDRL-Client has returned RTE_E_ResetIndivData_E_PENDING and needs to be called again. */
               retVal = RTE_E_RoutineServices_ResetIndivData_DCM_E_PENDING;
               break;

            case RTE_E_NO_DATA:
               StdDiag_ResetIndivDataStatus[i] = RTE_E_NO_DATA;
               /* This case means that the RTE result is not available. */
               retVal = RTE_E_RoutineServices_ResetIndivData_DCM_E_PENDING;
               break;

            default:
               /* This case means that the rte result invocation is failed, and not needed to be performed again. */
               StdDiag_ResetIndivDataStatus[i] = E_OK;
               StdDiag_ResetIndivDataResult = 0x01u;
               break;
         }
      }
   }

   return retVal;
}

/**
 * \brief canceling the function of resetting the IndivData
 *
 * This function cancels the function of resetting the IndivData.
 *
 * \global_rw StdDiag_ResetIndivDataStatus
 *
 */
static void StdDiag_CancelResetIndivData(void)
{
   uint16 i;

   for (i = 0; i < STDDIAG_IDRL_CLIENT_NUMBER; i++)
   {
      if (StdDiag_ResetIndivDataStatus[i] == RTE_E_ResetIndivData_E_PENDING)
      {
         /*
          * This case means that the IDRL client has returned RTE_E_ResetIndivData_E_PENDING to the RTE, when the rte result was called.
          * In this case, cancel the reset invocation.
          */
         if (StdDiag_ResetIndivDataAccess[i].rteCallFuncPtr(STDDIAG_IDRL_CANCEL) == E_OK)
         {
            /* handling of return value is not necessary, because it is a cancel operation. */
            (void)StdDiag_ResetIndivDataAccess[i].rteResultFuncPtr();
         }
         StdDiag_ResetIndivDataStatus[i] = E_OK;
      }
   }
}

#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */
#endif /*STDDIAG_IDRL_SUPPORT == STD_ON*/

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#if( STDDIAG_IDRL_SUPPORT == STD_ON )
/**
 * \brief Reading the individual data identifier table
 *
 * This function reads the individual data identifier table (Request 0x22 0x17 0x34).
 *
 *
 * \param[out] Data pointer to the buffer, where the individual
 *                  data ID table is stored.
 *
 * \retval E_OK The data of the DID table is successfully read.
 *
 */
Std_ReturnType StdDiag_ReadDataDIDTable(
   uint8 *Data)
{
   size_t dataLength;
   UDS_ErrorCodeType errorCode;

   /* handling of return value is not necessary, because API always returns OK. */
   (void) StdDiag_ReadDataRawDIDTable( Data, &dataLength, &errorCode);

   /* always return E_OK */
   return E_OK;
} /* end of function StdDiag_ReadDataDIDTable */

#if (STDDIAG_INDIV_DID_NUMBER > 0)
/**
 * \brief Condition check for reading the individual data identified by a DID.
 *
 * This function checks the conditions for reading the individual data.
 *
 * \global_rw StdDiag_IndivDIDIndex,
 *            StdDiag_IDRLClientReturnedPending,
 *            StdDiag_InitialCalled
 *
 * \param[in] DID The data ID of an individual data
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification. Only set in
 *                       case of return value E_NOT_OK.
 *
 * \retval E_OK Conditions are fulfilled.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING ConditionCheck is pending.
 * \retval E_NOT_OK Conditions are not fulfilled.
 *
 */
Std_ReturnType StdDiag_ConditionCheckIndivData(
   uint16 DID,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode)
{
   Std_ReturnType retVal = E_OK;

   switch (OpStatus)
   {
      /* in case that this function is called for the first time. */
      case DCM_INITIAL:
         StdDiag_IDRLClientReturnedPending = FALSE;
         StdDiag_IndivDIDIndex = 0;
         StdDiag_InitialCalled = TRUE;
         /* find the index of the target DID */
         while ((StdDiag_IndivDIDIndex < STDDIAG_INDIV_DID_NUMBER) && (DID != StdDiag_ReadIndivDataAccess[StdDiag_IndivDIDIndex].dataIdentifier))
         {
            StdDiag_IndivDIDIndex++;
         }

         /* call the read operation identified by the target index through the RTE */
         if (StdDiag_IndivDIDIndex < STDDIAG_INDIV_DID_NUMBER)
         {
            retVal = StdDiag_ReadIndivData(StdDiag_IndivDIDIndex);
         }
         else
         {
            retVal = E_NOT_OK;
         }

         break;

      /* in case that the DCM sends a Response Pending. */
      case DCM_PENDING:

         if (StdDiag_InitialCalled == TRUE)
         {
            if (StdDiag_IDRLClientReturnedPending == TRUE)
            {
               /*
                * This case means that the IDRL client has returned STDDIAG_E_OperateIndivData_E_PENDING to the RTE, when the rte result was called.
                * In this case, the rte call has to be called with the status parameter STDDIAG_IDRL_PENDING again.
                */
               retVal = StdDiag_ReadIndivDataAccess[StdDiag_IndivDIDIndex].rteCallFuncPtr(STDDIAG_IDRL_PENDING, STDDIAG_BUFFER_SIZE_INDIV_DATA);
               StdDiag_IDRLClientReturnedPending = FALSE;
            }

            if (retVal == E_OK)
            {
               /* try to get the result of the function reading individual data */
               retVal = StdDiag_GetRteResultReadIndivData(StdDiag_IndivDIDIndex);
            }
            else
            {
               retVal = E_NOT_OK;
            }
         }
         else
         {
            retVal = E_NOT_OK;
         }
         break;

      /* in case that the DCM cancels the request. */
      case DCM_CANCEL:
         if (StdDiag_InitialCalled == TRUE)
         {
            if (StdDiag_IDRLClientReturnedPending == TRUE)
            {
               /* The last invocation of the rte result has returned STDDIAG_E_OperateIndivData_E_PENDING, now try to cancel the read operation */
               retVal = StdDiag_ReadIndivDataAccess[StdDiag_IndivDIDIndex].rteCallFuncPtr(STDDIAG_IDRL_CANCEL, STDDIAG_BUFFER_SIZE_INDIV_DATA);
               if (retVal == E_OK)
               {
                  /* handling of return value is not necessary, because it is a cancel operation. */
                  (void)StdDiag_GetRteResultReadIndivData(StdDiag_IndivDIDIndex);
               }
            }
            else
            {
               /*
                * The last invocation of the rte result has returned RTE_E_NO_DATA.
                * As the server call has not been finished, it does not make sense to call newly the server with the status parameter STDDIAG_IDRL_CANCEL.
                * But try to get the rte result for finishing the server call.
                */
               /* handling of return value is not necessary, because it is a cancel operation. */
               (void)StdDiag_GetRteResultReadIndivData(StdDiag_IndivDIDIndex);
            }
         }
         retVal = E_NOT_OK;
         break;

      /* for other cases. */
      default:
         retVal = E_NOT_OK;
         break;
   }

   if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
   {
      /* It means that the request is finished. Recover the variable StdDiag_InitialCalled */
      StdDiag_InitialCalled = FALSE;
   }

   if (retVal == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   return retVal;
} /* end of function StdDiag_ConditionCheckIndivData */


/**
 * \brief Get the response length of the individual data identified by the DID
 *
 * This function gives the length of the response on requesting the length of
 * the individual data identified by the DID.
 *
 * \global_r StdDiag_IndivDataLength
 *
 * \param[in] DID The data ID of an individual data
 * \param[in] OpStatus State of the Dcm
 * \param[out] DataLength pointer to a variable, where the length of the
 *                        result is stored.
 *
 * \retval E_OK The length of the individual data is successfully read.
 *
 */
Std_ReturnType StdDiag_ReadLengthIndivData(
   uint16 DID,
   Dcm_OpStatusType OpStatus,
   uint16 *DataLength )
{
   /* MISRA-C:2004 Rule 14.2: the parameters DID and OpStatus are not used */
   /* PRQA S 3112 2 */
   (void) (DID);
   (void) (OpStatus);

   *DataLength = StdDiag_IndivDataLength;

   return E_OK;
} /* end of function StdDiag_ReadLengthIndivData */


/**
 * \brief Reading the individual data
 *
 * This function reads the individual data.
 *
 * \global_r StdDiag_IndivDataArray, StdDiag_IndivDataLength
 *
 * \param[in] DID The data ID of an individual data
 * \param[in] OpStatus State of the Dcm
 * \param[out] Data pointer to the buffer, where the individual
 *                  data is stored.
 *
 * \retval E_OK The individual data is successfully read.
 *
 */
Std_ReturnType StdDiag_ReadDataIndivData(
   uint16 DID,
   Dcm_OpStatusType OpStatus,
   uint8 *Data)
{
   uint16 i;
   /* MISRA-C:2004 Rule 14.2: the parameters DID and OpStatus are not used */
   /* PRQA S 3112 2 */
   (void) (DID);
   (void) (OpStatus);

   for (i = 0; i < StdDiag_IndivDataLength; i++)
   {
      /*
         MISRA-C:2004 Rule 17.4: array subscription is necessary to write more
         than one byte to the given buffer
      */
      /* PRQA S 0492 1 */
      Data[i] = StdDiag_IndivDataArray[i];
   }
   /* This function returns always E_OK */
   return E_OK;
} /* end of function StdDiag_ReadDataIndivData */

/**
 * \brief writing the individual data
 *
 * This function writes the individual data.
 *
 * \global_rw StdDiag_IndivDIDIndex,
 *            StdDiag_IDRLClientReturnedPending,
 *            StdDiag_InitialCalled
 *
 * \param[in] DID The data ID of an individual data
 * \param[in] Data pointer to the buffer, where the individual
 *                 data is stored.
 * \param[in] DataLength The length of the data to be written
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification. Only set in
 *                       case of return value E_NOT_OK.
 *
 * \retval E_OK The individual data is successfully written.
 * \retval STDDIAG_E_OperateIndivData_E_PENDING WriteData is pending.
 * \retval E_NOT_OK The individual data is not successfully written.
 *
 */
Std_ReturnType StdDiag_WriteDataIndivData(
   uint16 DID,
   const uint8 *Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType *ErrorCode )
{
   Std_ReturnType retVal = E_OK;

   switch (OpStatus)
   {
      /* in case that this function is called for the first time. */
      case DCM_INITIAL:
         StdDiag_IDRLClientReturnedPending = FALSE;
         StdDiag_IndivDIDIndex = 0;
         StdDiag_InitialCalled = TRUE;
         /* find the index of the target DID*/
         while ((StdDiag_IndivDIDIndex < STDDIAG_INDIV_DID_NUMBER) && (DID != StdDiag_WriteIndivDataAccess[StdDiag_IndivDIDIndex].dataIdentifier))
         {
            StdDiag_IndivDIDIndex++;
         }

         /* call the write operation identified by the target index through the RTE*/
         if (StdDiag_IndivDIDIndex < STDDIAG_INDIV_DID_NUMBER)
         {
            retVal = StdDiag_WriteIndivData(StdDiag_IndivDIDIndex, Data, DataLength);
         }
         else
         {
            retVal = E_NOT_OK;
         }
         break;

      /* in case that the DCM sends a Response Pending. */
      case DCM_PENDING:

         if (StdDiag_InitialCalled == TRUE)
         {
            if (StdDiag_IDRLClientReturnedPending == TRUE)
            {
               /*
                * This case means that the IDRL client has returned STDDIAG_E_OperateIndivData_E_PENDING to the RTE, when the rte result was called.
                * In this case, the rte call has to be called with the status parameter STDDIAG_IDRL_PENDING again.
                */
               retVal = StdDiag_WriteIndivDataAccess[StdDiag_IndivDIDIndex].rteCallFuncPtr(STDDIAG_IDRL_PENDING, DataLength, Data);
               StdDiag_IDRLClientReturnedPending = FALSE;
            }

            if (retVal == E_OK)
            {
               /* try to get the result of the function writing individual data */
               retVal = StdDiag_GetRteResultWriteIndivData(StdDiag_IndivDIDIndex);
            }
            else
            {
               retVal = E_NOT_OK;
            }
         }
         else
         {
            retVal = E_NOT_OK;
         }

         break;

      /* in case that the DCM cancels the request. */
      case DCM_CANCEL:
         if (StdDiag_InitialCalled == TRUE)
         {
            if (StdDiag_IDRLClientReturnedPending == TRUE)
            {
               /* The last invocation of the rte result has returned STDDIAG_E_OperateIndivData_E_PENDING, now try to cancel the read operation */
               retVal = StdDiag_WriteIndivDataAccess[StdDiag_IndivDIDIndex].rteCallFuncPtr(STDDIAG_IDRL_CANCEL, DataLength, Data);
               if (retVal == E_OK)
               {
                  /* handling of return value is not necessary, because it is a cancel operation. */
                  (void)StdDiag_GetRteResultWriteIndivData(StdDiag_IndivDIDIndex);
               }
            }
            else
            {
               /*
                * The last invocation of the rte result has returned RTE_E_NO_DATA.
                * As the server call has not been finished, it does not make sense to call newly the server with the status parameter STDDIAG_IDRL_CANCEL.
                * But try to get the rte result for finishing the server call.
                */
               /* handling of return value is not necessary, because it is a cancel operation. */
               (void)StdDiag_GetRteResultWriteIndivData(StdDiag_IndivDIDIndex);
            }
         }
         retVal = E_NOT_OK;
         break;

      /* for other cases. */
      default:
         retVal = E_NOT_OK;
         break;
   }

   if (retVal != STDDIAG_E_OperateIndivData_E_PENDING)
   {
      /* It means that the request is finished. recover the variable StdDiag_InitialCalled */
      StdDiag_InitialCalled = FALSE;
   }

   if (retVal == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   return retVal;
} /* end of function StdDiag_WriteDataIndivData */
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

/**
 * \brief resetting the individual data.
 *
 * This function resets the individual data. (Request 0x31 0x01, 0x101A).
 *
 * \global_w StdDiag_ResetIndivDataStatus
 *
 * \global_rw StdDiag_InitialCalled, StdDiag_ResetIndivDataResult
 *
 * \param[in] OpStatus: the status of the DCM
 * \param[out] routineResult: pointer to the routine result.
 * \param[out] ErrorCode: Error code according to Dcm specification. Only set in
 *                        case of return value E_NOT_OK.
 * \retval E_OK Resetting individual data is completely performed.
 * \retval RTE_E_RoutineServices_ResetIndivData_DCM_E_PENDING IndivData reset is pending.
 * \retval E_NOT_OK when the DCM sends an unexpected OpStatus to the StdDiag.
 *
 * \lhref ADUE_3981, ADUE_3982, ADUE_3983
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType StdDiag_RoutineControlStartResetIndivData (
   Dcm_OpStatusType OpStatus,
   uint8 *routineResult,
   Dcm_NegativeResponseCodeType *ErrorCode)
{
   Std_ReturnType retVal = E_OK;

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
   uint16 i;
   Std_ReturnType rteResult;
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */

   switch (OpStatus)
   {
      /* in case that this function is called for the first time. */
      case DCM_INITIAL:
#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
         StdDiag_InitialCalled = TRUE;
         StdDiag_ResetIndivDataResult = 0x00u;
         for (i = 0; i < STDDIAG_IDRL_CLIENT_NUMBER; i++)
         {
            retVal = StdDiag_ResetIndivDataAccess[i].rteCallFuncPtr(STDDIAG_IDRL_INITIAL);
            if (retVal == RTE_E_LIMIT)
            {
               /*
                * The last invocation of the rte result has returned RTE_E_NO_DATA,
                * now try to get the result of the function setting individual data.
                */
               rteResult = StdDiag_ResetIndivDataAccess[i].rteResultFuncPtr();
               if (rteResult != RTE_E_NO_DATA)
               {
                  /* It means that the rte result is now available, now try to perform rte call newly. */
                  retVal = StdDiag_ResetIndivDataAccess[i].rteCallFuncPtr(STDDIAG_IDRL_INITIAL);
               }
            }

            if (retVal == E_OK)
            {
               /* if any StdDiag_ResetIndivDataStatus[i] is E_NOT_OK, that means the rte result invocation
                * of the appropriate IDRl client will be performed.
                */
               StdDiag_ResetIndivDataStatus[i] = E_NOT_OK;
            }
            else if (retVal == RTE_E_LIMIT)
            {
               /* This case means that the last server call has not been finished. */
               StdDiag_ResetIndivDataStatus[i] = RTE_E_NO_DATA;
            }
            else
            {
               /* This case means that the rte call is failed.
                * If any StdDiag_ResetIndivDataStatus[i] is E_OK, that means it is not needed
                * to perform the rte result invocation of the appropriate IDRL client.
                */
               StdDiag_ResetIndivDataStatus[i] = E_OK;
               /*0x01 means that the result of the routine control is incorrect. */
               StdDiag_ResetIndivDataResult = 0x01u;
            }
         }
         retVal = StdDiag_GetRteResultResetIndivData();

         break;

      /* in case that the DCM sends a Response Pending. */
      case DCM_PENDING:
         if (StdDiag_InitialCalled == TRUE)
         {
            retVal = StdDiag_GetRteResultResetIndivData();
         }
         else
         {
            /* This case means that the DCM does not work correctly. Therefore, E_NOT_OK is returned. */
            retVal = E_NOT_OK;
         }

         break;

      /* in case that the DCM cancels the request. */
      case DCM_CANCEL:
         if (StdDiag_InitialCalled == TRUE)
         {
            StdDiag_CancelResetIndivData();
            /* handling of return value is not necessary, because it is a cancel operation. */
            (void)StdDiag_GetRteResultResetIndivData();
            StdDiag_ResetIndivDataResult = 0x01u;
            retVal = E_OK;
         }
         else
         {
            /* This case means that the DCM does not work correctly. Therefore, E_NOT_OK is returned. */
            retVal = E_NOT_OK;
         }
#else
         /*0x00 means that the result of the routine control is correct.*/
         *routineResult = 0x00u;
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */
         break;

      /* for other cases. */
      default:
         retVal = E_NOT_OK;
         break;
   }

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
   if (retVal != RTE_E_RoutineServices_ResetIndivData_DCM_E_PENDING)
   {
      /* It means that the request is finished. Recover the variable StdDiag_InitialCalled */
      StdDiag_InitialCalled = FALSE;
   }

   /* set OUT-parameter before returning */
   *routineResult = StdDiag_ResetIndivDataResult;
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */

   if (retVal == E_NOT_OK)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      *routineResult = 0x01u;
   }

   return retVal;
} /*end of function StdDiag_RoutineControlStartResetIndivData */

#endif /* (STDDIAG_IDRL_SUPPORT == STD_ON) */

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"


