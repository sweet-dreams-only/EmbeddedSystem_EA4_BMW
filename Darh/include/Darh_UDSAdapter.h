/**
*  \file
*
*  \brief       Darh UDS Adapter
*
*  Declaration of UDS Adapter needed functions.
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
#ifndef DARH_UDSADAPTER_H
#define DARH_UDSADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_Version.h"
#include "BUtil/GenericUDSTypes.h"

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
#error "Version of Darh_UDSAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Start routine completed successfully
 *
 * This function is called to indicate that a start routine has been
 * completed successfully.
 */
extern void Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultOk(void);

/**
 * \brief Stop routine completed successfully
 *
 * This function is called to indicate that a stop routine has been
 * completed successfully.
 */
extern void Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultOk(void);

/**
 * \brief Start routine completed with error
 *
 * This function is called to indicate that a start routine has been
 * completed with an error.
 *
 * \param[in] errorCode UDS Error to report to the tester
 */
extern void Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultError(UDS_ErrorCodeType errorCode);

/**
 * \brief Stop routine completed with error
 *
 * This function is called to indicate that a stop routine has been
 * completed with an error.
 *
 * \param[in] errorCode UDS Error to report to the tester
 */
extern void Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultError(UDS_ErrorCodeType errorCode);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_UDSADAPTER_H */
