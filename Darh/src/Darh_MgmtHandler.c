/**
*  \file
*
*  \brief       Darh Management Handler
*
*  This file contains the Darh management functionality.
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
#include "Rte_Darh.h"
#include "DarhClassic_Version.h"
#include "Darh_AssertAdapter.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!DarhClassic_CHECK_VERSION(5,1,0))
   #error "Version of Darh_MgmtHandler.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * \brief   Darh_LifeCycleHandler
 *          Initializes Darh
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       none
 *
 * \param           none
 *
 * \retval          none
 *
 * \pre             none
 *
 * \post            none
 *
 */
/*----------------------------------------------------------------------------*/
void Darh_LifeCycleHandler(void)
{
   Darh_LifeCycleRequestType presentMode, unusedParam;
   Darh_LifeCycleRequestType requestedMode = Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

   presentMode = Rte_Mode_LifeCycle_Mode(&unusedParam, &presentMode);

   switch(requestedMode)
   {
      case RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED:

         if (presentMode == RTE_MODE_Darh_LifeCycle_DARH_STOPPED)
         {
            if (Rte_Switch_Darh_LifeCycle_Mode(requestedMode) != RTE_E_OK)
            {
#if( DARH_DEV_ERROR_DETECT == STD_ON )

               (void)Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_LIFECYCLEHANDLER, DARH_E_RETURN );
#endif
            }
         }
         break;

      case RTE_MODE_Darh_LifeCycle_DARH_RUNNING:

         if (presentMode == RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED)
         {
            Darh_Init();

            if (Rte_Switch_Darh_LifeCycle_Mode(requestedMode) != RTE_E_OK)
            {
#if( DARH_DEV_ERROR_DETECT == STD_ON )
               (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_LIFECYCLEHANDLER, DARH_E_RETURN );
#endif
            }
         }
         break;

      case RTE_MODE_Darh_LifeCycle_DARH_STOPPED:

         if ( (presentMode == RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED) ||
              (presentMode == RTE_MODE_Darh_LifeCycle_DARH_RUNNING) )
         {
            Darh_Shutdown();

            if (Rte_Switch_Darh_LifeCycle_Mode(requestedMode) != RTE_E_OK)
            {
#if( DARH_DEV_ERROR_DETECT == STD_ON )
               (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_LIFECYCLEHANDLER, DARH_E_RETURN );
#endif
            }
         }
         break;

      default:
         break;
   }

} /* end of function Darh_LifeCycleHandler */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
