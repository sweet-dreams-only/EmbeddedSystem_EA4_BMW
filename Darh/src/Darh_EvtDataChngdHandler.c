/**
*  \file
*
*  \brief       BMW SWC Darh Event Data Changed Handler implementation
*
*  Implements the Callback Event Data Changed handler
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "DarhClassic_Version.h"
#include "Rte_Darh.h"
#include "Darh.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_EvtDataChngdHandler.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/**
 * \brief Darh_EventDataChangedHandler
 *
 * Triggered by Error Manager in case event data has changed.
 *
 * \param[in] EventId ID of the event whose data changed
 *
 * \retval none
 *
 * \pre Darh module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Darh_EventDataChangedHandler(Dem_EventIdType eventIdx)
{
   Darh_EventDataChanged(eventIdx);

} /* end of function Darh_EventDataChangedHandler */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

/*--- End of file ------------------------------------------------------------*/
