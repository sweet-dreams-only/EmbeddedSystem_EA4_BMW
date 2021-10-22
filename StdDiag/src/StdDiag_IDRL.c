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
*  \version     5.3.0
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

#include "BUtil/PlatformTypes.h"
#include "StdDiag_UDSAdapter.h"
#include "StdDiag.h"
#include "StdDiag_Version.h"
#include "StdDiag_Cfg.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
   #error "Version of StdDiag_IDRL.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

#if( STDDIAG_IDRL_SUPPORT == STD_ON )
/**
 * \brief ReadDataByIdentifier DID Table
 *
 * This function collects data for diagnostic request
 * ReadDataByIdentifier DIDTable
 *
 * \param[out] responseData pointer to buffer to store data
 * \param[in,out] dataLength pointer to length of data
 * \param[out] errorCode negative response code in case of an error
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK job finished successful
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK job did not finish successful
 *
 * \lhref ADUE_3929
 *
 */
UDS_ReturnType StdDiag_ReadDataRawDIDTable( uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode)
{
#if (STDDIAG_INDIV_DID_NUMBER > 0)
    uint16 i;
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

    uint16 formatIdentifier = STDDIAG_DID_TABLE_FORMAT_IDENTIFIER;

    /* check available buffer size: 2 Byte per DID plus 2 Byte for format identifier */
    if ( (((STDDIAG_INDIV_DID_NUMBER) * 2u) + 2u) > *dataLength )
    {
        *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
        return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    }

    /* The first 2 bytes of the Indiv DID table are the format identifier (16 bits).*/
    /*
       MISRA-C:2004 Rule 17.4 (2x): array subscription is necessary to write more
       than one byte to the given buffer
    */
    /* PRQA S 0492 2 */
    responseData[0] = (uint8) (formatIdentifier >> 8);
    responseData[1] = (uint8) formatIdentifier;

#if (STDDIAG_INDIV_DID_NUMBER > 0)
    /* the following are the DIDs. converting the uint16 DID into the uint8 table array.*/
   for (i = 1; i <= STDDIAG_INDIV_DID_NUMBER; i++)
   {
      /* The index for StdDiag_DIDArray begins with 0. Therefore this index is (i-1) */
      /*
         MISRA-C:2004 Rule 17.4 (2x): array subscription is necessary to write more
         than one byte to the given buffer
      */
      /* PRQA S 0492 2 */
      responseData[i*2] = (uint8) (StdDiag_DIDArray[i-1] >> 8);
      responseData[(i*2)+1] = (uint8) StdDiag_DIDArray[i-1];
   }
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

  *dataLength = ((STDDIAG_INDIV_DID_NUMBER) * 2u) + 2u;

  return UDS_DIAG_JOB_FINISHED_OK;
}
#endif /* (STDDIAG_IDRL_SUPPORT == STD_ON) */

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"
