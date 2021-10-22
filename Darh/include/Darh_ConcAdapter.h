/**
*  \file
*
*  \brief       Darh Critical Section adapter
*
*  Adapter for the Critical Sections of Darh
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
#ifndef DARH_CRITSECADAPTER_H
#define DARH_CRITSECADAPTER_H

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
#error "Version of Darh_ConcAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_CritSect_Area0_Enter
 *
 * Enters to the Critical Section called Area0.
 *
 * \param --
 *
 * \return --
 *
 */
extern void Darh_CritSect_Area0_Enter(void);

/**
 * \brief Description of function Darh_CritSect_Area0_Exit
 *
 * Exits to the Critical Section called Area0.
 *
 * \param --
 *
 * \return --
 *
 */
extern void Darh_CritSect_Area0_Exit(void);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_CRITSECADAPTER_H */
