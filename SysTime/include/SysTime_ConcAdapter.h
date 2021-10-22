/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the concurrency adapter header file of the generic part of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

#ifndef SYSTIME_CONCADAPTER_H
#define SYSTIME_CONCADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "SysTime_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTime_CHECK_VERSION(5,0,3))
#error "Version of SysTime_ConcAdapter.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function shall enter the critical section for SystemTime
 *
 */
extern void SysTime_CritSect_SystemTime_Enter(void);

/**
 * \brief This function shall leave the critical section for SystemTime
 *
 */
extern void SysTime_CritSect_SystemTime_Exit(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTIME_CONCADAPTER_H */



