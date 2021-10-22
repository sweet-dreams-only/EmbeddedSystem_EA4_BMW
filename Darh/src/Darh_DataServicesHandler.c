/**
*  \file
*
*  \brief       BMW SWC Darh Data Services Handler implementation
*
*  Handling of the  Data Services Indications for the Darh
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh.h"
#include "BUtil/PlatformTypes.h"
#include "DarhClassic_Version.h"
#include "Rte_Darh.h"
#include "Darh_ReadActivelyReportedDTCs.h"
#include "Darh_QueueHandler.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_DataServicesHandler.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_ConditionCheckReadActivelyReportedDtcHandler
 *
 * Function is called by Dcm in the context of an RDBI request.
 *
 * \global --
 *
 * \param[out] ErrorCode
 *
 * \return Std_ReturnType
 * \retval E_OK
 * \retval E_NOT_OK in case DARH not initialized
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
Std_ReturnType Darh_ConditionCheckReadActivelyReportedDtcHandler(Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType retVal = E_NOT_OK;
  Darh_LifeCycleRequestType unusedParam, presentMode;

  /* This API also returns the current Mode on the second param - nextMode */
  (void) Rte_Mode_LifeCycle_Mode(&unusedParam, &presentMode);

  if (NULL_PTR == ErrorCode) {
#if(DARH_DEV_ERROR_DETECT == STD_ON)
    (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_CONDITIONCHECKREADACTIVELYREPORTEDDTC, DARH_E_PARAM );
#endif
  } else if (RTE_MODE_Darh_LifeCycle_DARH_RUNNING == presentMode) {
    retVal = E_OK;
  } else {
#if(DARH_DEV_ERROR_DETECT == STD_ON)
    (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_CONDITIONCHECKREADACTIVELYREPORTEDDTC, DARH_E_PARAM );
#endif

    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }
  return retVal;
} /* end of function Darh_ConditionCheckReadActivelyReportedDtcHandler */

/**
 * \brief Darh_ReadActivelyReportedDtcLengthHandler
 *
 * Function is called by Diagnostic Communication Manager in the context
 * of an RDBI request to know the length of the data to be returned by the
 * RDBI job.
 *
 * \param[out] DataLength Number of bytes in data. I.e. number of actively
 *             reported DTC/event * size of DTC (3)
 *
 * \return E_OK if success, E_NOT_OK if not.
 *
 * \pre Darh module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 */
Std_ReturnType Darh_ReadActivelyReportedDtcLengthHandler(uint16* DataLength) {
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR == DataLength) {
#if(DARH_DEV_ERROR_DETECT == STD_ON)
    (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_READACTIVELYREPORTEDDTCLENGTH, DARH_E_PARAM );
#endif
  } else if (Darh_ReadActivelyReportedDtc_Length(DataLength)) {
    retVal = E_OK;
  }

  return retVal;

} /* end of function Darh_ReadActivelyReportedDtcLengthHandler */

/**
 * \brief Darh_ReadActivelyReportedDtcDataHandler
 *
 * Function is called by Diagnostic Communication Manager in the context of an RDBI request
 * and returns the lists of DTCs which are reported to the diagnostic master. Data
 * shall be an array with at least the length returned by Darh_ReadActivelyReportedDtc_Length.
 *
 * \param[out] Data List of actively reported DTC
 *
 * \return E_OK if success, E_NOT_OK if not.
 *
 * \pre Darh module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 */
Std_ReturnType Darh_ReadActivelyReportedDtcDataHandler(uint8* data) {
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR == data) {
#if(DARH_DEV_ERROR_DETECT == STD_ON)
    (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_READACTIVELYREPORTEDDTC, DARH_E_PARAM );
#endif
  } else if (Darh_ReadActivelyReportedDtc_Data(data)) {
    retVal = E_OK;
  }

  return retVal;

} /* end of function Darh_ReadActivelyReportedDtcDataHandler */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
