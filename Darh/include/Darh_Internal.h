/**
*  \file
*
*  \brief       BMW SWC Darh
*
*  This file contains the internal declarations of the BMW SWC Darh.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015
*
*  \version     5.1.0
*
*  \remarks     --
*
*/
#ifndef DARHINTERNAL_H
#define DARHINTERNAL_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "Darh_Version.h"               /* Own version header file */
#include "Darh_NvMAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/* check version of the module */
#if (!Darh_CHECK_VERSION(5,1,0))
#error "Version of Darh_Internal.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Checks if an event shall be reported or not
 *
 * Returns true if an event id shall be reported and false in other case.
 *
 * \global Darh_ActiveReportedEvents
 *
 * \param[in] EventId index of the event
 *
 * \return TRUE the event shall be reported,
 *         FALSE the event shall not be reported
 *
 */
extern boolean Darh_CheckEventToBeReported(ErrMemService_EventIdType EventId);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#endif /* DARHINTERNAL_H */
