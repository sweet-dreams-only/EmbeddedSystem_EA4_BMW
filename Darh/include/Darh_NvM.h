/**
*  \file
*
*  \brief       Darh NvM
*
*  NvM for Darh Module
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
#ifndef DARH_NVM_H
#define DARH_NVM_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "Darh_ErrMemAdapter.h"
#include "Darh_Cfg.h"

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
#error "Version of Darh_NvM.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
/**
 * \brief Information related to an event which is stored in the event queue
 */
typedef struct {
  uint32 timestamp; /**< member stores timestamp of the corresponding freeze frame */
  ErrMemService_EventIdType EventId; /**< member stores value of the Dem Event ID */
} Darh_QueueElementType;

/**
 * \brief Information related to a error queue structure
 */
typedef struct {
  Darh_QueueElementType queue[DARH_QUEUE_SIZE]; /**< member stores array of queued elements */
  uint16 first; /**< member stores index of the first element on the queue */
  uint16 size; /**< member stores count of elements on the queue */
} Darh_ErrorQueueType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
#define Darh_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Darh_MemMap.h"

/**
 * \brief Queue of elements (DTCs and Timestamp) to be reported to the diagnose master.
 */
extern Darh_ErrorQueueType Darh_ErrorQueue;

#define Darh_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Darh_MemMap.h"

#define Darh_START_SEC_VAR_SAVED_ZONE_BOOLEAN
#include "Darh_MemMap.h"

/**
 * \brief Indicates if the Diagnose Master transmission is enable or not.
 */
extern boolean Darh_DiagnoseMasterEnable;

#define Darh_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_NVM_H */
