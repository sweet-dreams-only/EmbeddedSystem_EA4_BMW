/**
*  \file
*
*  \brief       Darh Queue Handler
*
*  Darh Queue Handler header file
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
#ifndef DARH_QUEUEHANDLER_H
#define DARH_QUEUEHANDLER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_Version.h"

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
#error "Version of Darh_QueueHandler.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_QueueHandler
 *
 * Function shall be cyclically called. It shall check the queue for entered
 * errors and send it via TriggerOnEvent operation of Dcm.
 *
 * \global Darh_CurrentRoeState, Darh_ErrorQueue
 *
 */
extern void Darh_QueueHandler(void);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_QUEUEHANDLER_H */
