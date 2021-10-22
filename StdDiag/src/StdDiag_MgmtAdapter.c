/**
*  \file
*
*  \brief       BMW SWC StdDiag Adapter
*
*  This file contains the implementation of the StdDiag Management adapter
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
#include "StdDiag_MgmtAdapter.h"
#include "StdDiagClassic_Version.h"
#include "Rte_StdDiag.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_MgmtAdapter.cpp does not match the adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

void StdDiag_Mgmt_EnableNonDiagnosticCommunication(void) {
  (void) Rte_Write_ComControlModeRequestPort_requestedMode(RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL);
}

void StdDiag_Mgmt_DisableNonDiagnosticCommunication(void) {
  (void) Rte_Write_ComControlModeRequestPort_requestedMode(RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL);
}


