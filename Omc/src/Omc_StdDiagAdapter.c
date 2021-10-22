/**
*  \file
*
*  \brief       Omc StdDiag Adapter
*
*  This file contains the Omc StdDiag interface functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "OmcClassic_Version.h"
#include "Rte_Omc.h"
#include "Omc.h"
#include "Omc_StdDiagAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_StdDiagAdapter.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

Omc_StdDiag_ResultType Omc_StdDiag_AllowOpModeChange(
    Omc_GenericOperatingModeType ActiveOperatingMode, Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType OperatingMode, Omc_GenericExtendedOperatingModeType ExtendedOperatingMode) {

  Std_ReturnType stdDiagRetVal;
  Omc_StdDiag_ResultType retVal;

  /* check if the user application allows this mode change */
  stdDiagRetVal = Rte_Call_StdDiag_AllowOpModeSwitch(
      ActiveOperatingMode, ActiveExtendedOperatingMode, OperatingMode, ExtendedOperatingMode);

  switch (stdDiagRetVal) {
    case RTE_E_OmcModesCallouts_E_OK:
      retVal = OMC_STDDIAG_OK;
      break;

    case RTE_E_OmcModesCallouts_E_RUNNING:
      retVal = OMC_STDDIAG_RUNNING;
      break;

    case RTE_E_OmcModesCallouts_E_NOT_OK:
    default:
      retVal = OMC_STDDIAG_NOT_OK;
      break;
  }

  return retVal;
}

Omc_StdDiag_ResultType Omc_StdDiag_OpModeSwitchCancelled(
    Omc_GenericOperatingModeType ActiveOperatingMode,
    Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType NewOperatingMode, Omc_GenericExtendedOperatingModeType NewExtendedOperatingMode) {

  Omc_StdDiag_ResultType retVal;
  Std_ReturnType applRetVal;

  /* inform about a cancel the application */

  applRetVal = Rte_Call_StdDiag_OpModeSwitchCancelled(
      ActiveOperatingMode, ActiveExtendedOperatingMode, NewOperatingMode, NewExtendedOperatingMode);

  switch (applRetVal) {
    case RTE_E_OmcModesCallouts_E_OK:
      retVal = OMC_STDDIAG_OK;
      break;

    case RTE_E_OmcModesCallouts_E_RUNNING:
      retVal = OMC_STDDIAG_RUNNING;
      break;

    case RTE_E_OmcModesCallouts_E_NOT_OK:
    default:
      retVal = OMC_STDDIAG_NOT_OK;
      break;
  }

  return retVal;
}

Std_ReturnType Omc_StdDiag_OpModeSwitchAllowedResult(boolean Result)
{
  Omc_StdDiagCbk_OpModeSwitchAllowedResult(Result);

  return E_OK;
}

Std_ReturnType Omc_StdDiag_OpModeSwitchCancelledAck(void)
{
  Omc_StdDiagCbk_OpModeSwitchCancelledAck();

  return E_OK;
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
