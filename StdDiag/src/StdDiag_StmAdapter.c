/**
*  \file
*
*  \brief       BMW SWC StdDiag Adapter
*
*  This file contains the implementation of the StdDiag Stm adapter
*  for usage in the classic BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiag_StmAdapter.h"
#include "StdDiagClassic_Version.h"
#include "Rte_StdDiag.h"



/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_StmAdapter.c does not match the adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
extern StdDiag_Stm_VehicleStateType StdDiag_Stm_GetVehicleState( void ) {
  StdDiag_Stm_VehicleStateType retVal;

  /* check current vehicle state */
  Stm_VehicleStateType currentVehicleState = Rte_Mode_VehicleStatePort_currentVehicleStateMode();

  if(RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS == currentVehicleState)
  {
    retVal = STDDIAG_STM_MODE_PAD;
  }
  else if( (RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE == currentVehicleState) ||
           (RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID == currentVehicleState) )
  {
    retVal = STDDIAG_STM_MODE_UNAVAILABLE;
  }
  else
  {
    retVal = STDDIAG_STM_MODE_NON_PAD;
  }

  return retVal;
}
