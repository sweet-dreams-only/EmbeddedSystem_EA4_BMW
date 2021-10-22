/**
*  \file
*
*  \brief       Darh Read Actively Reported DTCs Job
*
*  Declarations for the diagnose job to read the actively reported DTCs.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
#ifndef DARH_READACTIVELYREPORTEDDTCS_H
#define DARH_READACTIVELYREPORTEDDTCS_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_Version.h"
#include "BUtil/PlatformTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/*
 * \brief  check version of the module
 */
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ReadActivelyReportedDTCs.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_ReadActivelyReportedDtc_Length
 *
 * Function is called by Diagnostic Communication Manager in the context
 * of an RDBI request to know the lenght of the data to be returned by the
 * RDBI job.
 *
 * \global --
 *
 * \param[out] DataLength Number of bytes in data. I.e. number of actively
 *             reported DTC/event * size of DTC (3)
 *
 * \return boolean TRUE if success, FALSE if not. If FALSE is returned the
 *         content of *DataLenght is undefined.
 *
 */
extern boolean Darh_ReadActivelyReportedDtc_Length(uint16 *DataLength);

/**
 * \brief Description of function Darh_ReadActivelyReportedDtc_Data
 *
 * Function is called by Diagnostic Communication Manager in the context of an RDBI request
 * and returns the lists of DTCs which are reported to the diagnostic master. Data
 * shall be an array with at least the length returned by Darh_ReadActivelyReportedDtc_Length.
 *
 * \global --
 *
 * \param[out] Data List of actively reported DTC (see DARH_067)
 *
 * \return TRUE if success, FALSE if not. If FALSE is returned the content of Data
 *         is  undefined.
 *
 */
extern boolean Darh_ReadActivelyReportedDtc_Data(uint8 *Data);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_READACTIVELYREPORTEDDTCS_H */
