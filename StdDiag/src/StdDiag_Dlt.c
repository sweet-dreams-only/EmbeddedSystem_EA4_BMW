/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the DLT support of the module StdDiag
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

#include "StdDiagClassic_Cfg.h"

#if (STDDIAG_DLT_SUPPORT == STD_ON)

#include "StdDiag_AssertAdapter.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_Dlt.c does not match the version of the module!"
#endif

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/**
 * \brief diagnostic request for setting DLT log level.
 *
 * This function implements the diagnostic request to set the DLT log level
 * (Request 0x31 0x01 0x10 0x90)
 *
 * \param[in] applicationId contains the Dlt application identifier
 * \param[in] contextId contains the Dlt context identifier
 * \param[in] newLogLevel contains the Dlt log level
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1582, DK_T3_1583, DK_T3_1585, DK_T3_1586, DK_T3_1903
 *
 */
Std_ReturnType StdDiag_DltSetLoglevel(
    uint32 applicationId,
    uint32 contextId,
    uint8 newLogLevel,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;
  Dlt_ApplicationIDType appId;
  Dlt_ContextIDType ctxId;

  /* convert IN-parameters to byte-array */
  appId[0] = (uint8) (applicationId >> 24);
  appId[1] = (uint8) (applicationId >> 16);
  appId[2] = (uint8) (applicationId >> 8);
  appId[3] = (uint8) (applicationId);

  ctxId[0] = (uint8) (contextId >> 24);
  ctxId[1] = (uint8) (contextId >> 16);
  ctxId[2] = (uint8) (contextId >> 8);
  ctxId[3] = (uint8) (contextId);

  switch (OpStatus)
  {
    case DCM_INITIAL:
      if( E_OK != Rte_Call_DLTServices_SetLogLevel(appId, ctxId, (Dlt_MessageLogLevelType) newLogLevel) )
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
}

/**
 * \brief diagnostic request for resetting all DLT settings.
 *
 * This function implements the diagnostic request to reset all DLT settings
 * (Request 0x31 0x01 0x10 0x91)
 *
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1589, DK_T3_1590, DK_T3_1591, DK_T3_1592
 *
 */
Std_ReturnType StdDiag_DltResetToDefault(
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;

  switch (OpStatus)
  {
    case DCM_INITIAL:
      if( E_OK != Rte_Call_DLTServices_ResetToFactoryDefault() )
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
}

/**
 * \brief diagnostic request for setting DLT message filter.
 *
 * This function implements the diagnostic request to set the DLT message filter
 * (Request 0x31 0x01 0x10 0x92)
 *
 * \param[in] newFilterStatus contains the Dlt filter status
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1595, DK_T3_1596, DK_T3_1597, DK_T3_1598, DK_T3_1599, DK_T3_1904
 *
 */
Std_ReturnType StdDiag_DltSetMessageFilteringState(
    uint8 newFilterStatus,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;

  switch (OpStatus)
  {
    case DCM_INITIAL:
      /* check if parameter is in boolean range */
      if( (STD_OFF == newFilterStatus) || (STD_ON == newFilterStatus) )
      {
        retVal = Rte_Call_DLTServices_SetMessageFilteringStatus((boolean) newFilterStatus);
      }
      else
      {
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      retVal = E_NOT_OK;
      break;
  }

  if( retVal != E_OK )
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**
 * \brief diagnostic request for setting DLT log level threshold.
 *
 * This function implements the diagnostic request to set the DLT log level threshold
 * (Request 0x31 0x01 0x10 0x93)
 *
 * \param[in] logChannelName contains the name of the Dlt log channel
 * \param[in] newLogLevelThreshold contains the Dlt log level threshold
 * \param[in] newTraceStatus contains the Dlt trace status
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1602, DK_T3_1603, DK_T3_1909, DK_T3_1605, DK_T3_1606, DK_T3_1902, DK_T3_1911
 *
 */
Std_ReturnType StdDiag_DltSetLogChannelThreshold(
    uint32 logChannelName,
    uint8 newLogLevelThreshold,
    uint8 newTraceStatus,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;
  Dlt_LogChannelNameType channelName;

  /* convert IN-parameter to byte-array */
  channelName[0] = (uint8) (logChannelName >> 24);
  channelName[1] = (uint8) (logChannelName >> 16);
  channelName[2] = (uint8) (logChannelName >> 8);
  channelName[3] = (uint8) (logChannelName);

  switch (OpStatus)
  {
    case DCM_INITIAL:
      /* check if parameter is in boolean range */
      if( (STD_OFF == newTraceStatus) || (STD_ON == newTraceStatus) )
      {
        retVal = Rte_Call_DLTServices_SetLogChannelThreshold(channelName, (Dlt_MessageLogLevelType) newLogLevelThreshold, (boolean) newTraceStatus);
      }
      else
      {
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      retVal = E_NOT_OK;
      break;
  }

  if( retVal != E_OK )
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**
 * \brief diagnostic request for storing DLT settings.
 *
 * This function implements the diagnostic request to store the DLT settings
 * (Request 0x31 0x01 0x10 0x94)
 *
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1609, DK_T3_1610, DK_T3_1611, DK_T3_1612
 *
 */
Std_ReturnType StdDiag_DltStoreConfiguration(
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;

  switch (OpStatus)
  {
    case DCM_INITIAL:
      if( E_OK != Rte_Call_DLTServices_StoreConfiguration() )
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
}

/**
 * \brief diagnostic request for setting DLT trace status.
 *
 * This function implements the diagnostic request to set the DLT trace status
 * (Request 0x31 0x01 0x10 0x95)
 *
 * \param[in] applicationId contains the Dlt application identifier
 * \param[in] contextId contains the Dlt context identifier
 * \param[in] newTraceStatus contains the Dlt trace status
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1615, DK_T3_1616, DK_T3_1617, DK_T3_1618, DK_T3_1619, DK_T3_1905
 *
 */
Std_ReturnType StdDiag_DltSetTraceState(
    uint32 applicationId,
    uint32 contextId,
    uint8 newTraceStatus,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;
  Dlt_ApplicationIDType appId;
  Dlt_ContextIDType ctxId;

  /* convert IN-parameters to byte-array */
  appId[0] = (uint8) (applicationId >> 24);
  appId[1] = (uint8) (applicationId >> 16);
  appId[2] = (uint8) (applicationId >> 8);
  appId[3] = (uint8) (applicationId);

  ctxId[0] = (uint8) (contextId >> 24);
  ctxId[1] = (uint8) (contextId >> 16);
  ctxId[2] = (uint8) (contextId >> 8);
  ctxId[3] = (uint8) (contextId);

  switch (OpStatus)
  {
    case DCM_INITIAL:
      /* check if parameter is in boolean range */
      if( (STD_OFF == newTraceStatus) || (STD_ON == newTraceStatus) )
      {
        retVal = Rte_Call_DLTServices_SetTraceStatus(appId, ctxId, (boolean) newTraceStatus);
      }
      else
      {
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      retVal = E_NOT_OK;
      break;
  }

  if( retVal != E_OK )
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**
 * \brief diagnostic request for setting DLT default log level.
 *
 * This function implements the diagnostic request to set the DLT default log level
 * (Request 0x31 0x01 0x10 0x96)
 *
 * \param[in] newDefaultLogLevel contains the Dlt default log level
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1622, DK_T3_1623, DK_T3_1624, DK_T3_1625, DK_T3_1626, DK_T3_1906
 *
 */
Std_ReturnType StdDiag_DltSetDefaultLoglevel(
    uint8 newDefaultLogLevel,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;

  switch (OpStatus)
  {
    case DCM_INITIAL:
      if( E_OK != Rte_Call_DLTServices_SetDefaultLogLevel((Dlt_MessageLogLevelType) newDefaultLogLevel) )
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
}

/**
 * \brief diagnostic request for setting DLT default trace status.
 *
 * This function implements the diagnostic request to set the DLT default trace status
 * (Request 0x31 0x01 0x10 0x97)
 *
 * \param[in] newDefaultTraceStatus contains the Dlt default trace status
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1629, DK_T3_1630, DK_T3_1631, DK_T3_1632, DK_T3_1633, DK_T3_1907
 *
 */
Std_ReturnType StdDiag_DltSetDefaultTraceState(
    uint8 newDefaultTraceStatus,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;

  switch (OpStatus)
  {
    /* in case that this function is called for the first time. */
    case DCM_INITIAL:
      /* check if parameter is in boolean range */
      if( (STD_OFF == newDefaultTraceStatus) || (STD_ON == newDefaultTraceStatus) )
      {
        retVal = Rte_Call_DLTServices_SetDefaultTraceStatus((boolean) newDefaultTraceStatus);
      }
      else
      {
        retVal = E_NOT_OK;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      retVal = E_NOT_OK;
      break;
  }

  if( retVal != E_OK )
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**
 * \brief diagnostic request for reading DLT log channel names.
 *
 * This function reads the DLT log channel names.
 *
 * \param[out] Data pointer to the buffer, where the log channel names
 *                  are stored.
 *
 * \retval E_OK The log channel names are successfully read.
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks this function is only available if the configuration container
 *          StdDiagProvideDLTSupport is available.
 *
 * \lhref DK_T3_1636, DK_T3_1637, DK_T3_1638, DK_T3_1639, DK_T3_1908
 *
 */
Std_ReturnType StdDiag_DltReadLogChannelNames(
    uint8 *Data)
{
  Std_ReturnType retVal;

  retVal = Rte_Call_DLTServices_GetLogChannelNames(Data);

  StdDiag_Assert_DevAssert((E_OK == retVal), STDDIAG_DEVERROR_DLT_READLOGCHANNELNAMES);

  /* This function returns always E_OK */
  return E_OK;
}


/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

#endif /* (STDDIAG_DLT_SUPPORT == STD_ON) */

/*--- End of file ------------------------------------------------------------*/
