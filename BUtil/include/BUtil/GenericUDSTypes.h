/**
 *  \file
 *
 *  \brief       BUtil Generic UDS Types
 *
 *  This file contains the generic UDS types to be used by
 *  generic modules and their UDS adapters.
 *
 *  \project     BMW Platform Software
 *
 *  \copyright   BMW AG 2016 - 2017
 *
 *  \version     5.0.3
 *
*/

#ifndef BUTIL_GENERICUDSTYPES_H_
#define BUTIL_GENERICUDSTYPES_H_

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of GenericUDSTypes.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum
{  /** diagnostic job has been successfully finished -> means positive (UDS) response */
   UDS_DIAG_JOB_FINISHED_OK = 0U,
   /** diagnostic job has been finished with Error -> means negative (UDS) response */
   UDS_DIAG_JOB_FINISHED_E_NOT_OK = 1U,
   /** diagnostic job has not been finished - still running */
   UDS_DIAG_JOB_RUNNING = 2U
} UDS_ReturnType;

/**
 * This is an Enum Type reflecting the different UDS error codes an application level service processor might typically
 * set in the course of service processing. Cast to uint8 may be necessary (e.g. AUTOSAR Dcm uses type
 * Dcm_NegativeResponseCodeType, which is an uint8).
 */
typedef enum
{
  UDS_DIAG_E_GENERALREJECT = 0x10,
  UDS_DIAG_E_SUBFUNCTIONNOTSUPPORTED = 0x12U,
  UDS_DIAG_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT = 0x13U,
  UDS_DIAG_E_BUSYREPEATREQUEST = 0x21,
  UDS_DIAG_E_CONDITIONSNOTCORRECT = 0x22U,
  UDS_DIAG_E_REQUESTSEQUENCEERROR = 0x24,
  UDS_DIAG_E_REQUESTOUTOFRANGE = 0x31U,
  UDS_DIAG_E_INVALIDKEY = 0x35,
  UDS_DIAG_E_UPLOADDOWNLOADNOTACCEPTED = 0x70,
  UDS_DIAG_E_TRANSFERDATASUSPENDED = 0x71,
  UDS_DIAG_E_GENERALPROGRAMMINGFAILURE = 0x72U,
  UDS_DIAG_E_WRONGBLOCKSEQUENCECOUNTER = 0x73U
} UDS_ErrorCodeType;

/**
 * This is an Enum Type reflecting the different UDS error codes an application level service processor might typically
 * set in the course of service processing. */
typedef enum
{
   /** positive UDS response successfully sent out/given to the network layer */
   UDS_DIAG_Confirm_PosResp_OK = 0U,
   /** positive UDS response NOT successfully sent out/given to the network layer */
   UDS_DIAG_Confirm_PosResp_E_NOT_OK = 1U,
   /** positive UDS response not sent out/given to the network layer, since the bit suppress pos. response was set in the request.
      Note: In classic AUTOSAR this type is NOT given to the application - most likely it gets replaced by PosResp_OK. */
   UDS_DIAG_Confirm_PosResp_Suppressed = 2U,
   /** negative UDS response successfully sent out/given to the network layer */
   UDS_DIAG_Confirm_NegResp_OK = 3U,
   /** negative UDS response NOT successfully sent out/given to the network layer */
   UDS_DIAG_Confirm_NegResp_E_NOT_OK = 4U
} UDS_ConfirmationType;

/** This is an Enum Type reflecting the different UDS diagnostic sessions. */
typedef enum
{
   UDS_DIAG_DEFAULT_SESSION = 0x01U,
   UDS_DIAG_PROGRAMMING_SESSION = 0x02U,
   UDS_DIAG_EXTENDED_SESSION = 0x03U,
   UDS_DIAG_CODING_SESSION = 0x41U,
   UDS_DIAG_SWT_SESSION = 0x42U,
   UDS_DIAG_HDD_UPDATE_SESSION = 0x43U,
   UDS_DIAG_RSU_SESSION = 0x44U,
   UDS_DIAG_INVALID_SESSION = 0xFFU
} UDS_SessionType;

/** This is an Enum Type reflecting the different UDS security level. */
typedef enum
{
   UDS_DIAG_SEC_LEVEL_LOCKED = 0x00U,
   UDS_DIAG_SEC_LEVEL_PROGRAMMING = 0x09U,
   UDS_DIAG_SEC_LEVEL_SWT = 0x0AU,
   UDS_DIAG_SEC_LEVEL_INVALID = 0xFFU
} UDS_SecLevelType;




#endif /* #ifndef BUTIL_GENERICUDSTYPES_H_ */