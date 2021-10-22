/**
*  \file
*
*  \brief       BMW SWC Darh Concurrency Adapter implementation
*
*  This file contains the implementation of the Darh Concurrency Adapter.
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
#include "DarhClassic_Version.h"
#include "Rte_Darh.h"
#include "Darh_ConcAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ConcAdapter.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
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
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
extern void Darh_CritSect_Area0_Enter()
{
   Rte_Enter_ExclusiveArea_0();

} /* end of function Darh_CritSect_Area0_Enter */


/**
 * \brief Description of function Darh_CritSect_Area0_Exit
 *
 * Exits to the Critical Section called Area0.
 *
 * \param --
 *
 * \return --
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
extern void Darh_CritSect_Area0_Exit()
{
   Rte_Exit_ExclusiveArea_0();

} /* end of function Darh_CritSect_Area0_Exit */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
