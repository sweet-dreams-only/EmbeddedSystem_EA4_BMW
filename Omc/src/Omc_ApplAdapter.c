/**
*  \file
*
*  \brief       Omc Application Adapter
*
*  This file contains the Omc application interface functionality.
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
#include "Omc_ApplAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_ApplAdapter.c does not match the version of the module!"
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
#if (OMC_OPMODECALLOUT == STD_ON)

Omc_Appl_ResultType Omc_Appl_AllowOpModeChange(
    Omc_GenericOperatingModeType ActiveOperatingMode, Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType OperatingMode, Omc_GenericExtendedOperatingModeType ExtendedOperatingMode) {

  Omc_Appl_ResultType retVal;
  Std_ReturnType applRetVal;

  /* check if the user application allows this mode change */

  applRetVal = Rte_Call_User_AllowOpModeSwitch(
      ActiveOperatingMode, ActiveExtendedOperatingMode, OperatingMode, ExtendedOperatingMode);

  switch (applRetVal) {
    case RTE_E_OmcModesCallouts_E_OK:
      retVal = OMC_APPL_OK;
      break;

    case RTE_E_OmcModesCallouts_E_RUNNING:
      retVal = OMC_APPL_RUNNING;
      break;

    case RTE_E_OmcModesCallouts_E_NOT_OK:
    default:
      retVal = OMC_APPL_NOT_OK;
      break;

  }

  return retVal;
}

extern Omc_Appl_ResultType Omc_Appl_OpModeSwitchCancelled(
    Omc_GenericOperatingModeType ActiveOperatingMode,
    Omc_GenericExtendedOperatingModeType ActiveExtendedOperatingMode,
    Omc_GenericOperatingModeType NewOperatingMode, Omc_GenericExtendedOperatingModeType NewExtendedOperatingMode) {

  Omc_Appl_ResultType retVal;
  Std_ReturnType applRetVal;

  /* inform about a cancel the application */

  applRetVal = Rte_Call_User_OpModeSwitchCancelled(
      ActiveOperatingMode, ActiveExtendedOperatingMode, NewOperatingMode, NewExtendedOperatingMode);

  switch (applRetVal) {
    case RTE_E_OmcModesCallouts_E_OK:
      retVal = OMC_APPL_OK;
      break;

    case RTE_E_OmcModesCallouts_E_RUNNING:
      retVal = OMC_APPL_RUNNING;
      break;

    case RTE_E_OmcModesCallouts_E_NOT_OK:
    default:
      retVal = OMC_APPL_NOT_OK;
      break;
  }

  return retVal;
}

Std_ReturnType Omc_Appl_OpModeSwitchAllowedResult(boolean Result)
{
  Omc_ApplicationCbk_OpModeSwitchAllowedResult(Result);

  return E_OK;
}

Std_ReturnType Omc_Appl_OpModeSwitchCancelledAck(void)
{
  Omc_ApplicationCbk_OpModeSwitchCancelledAck();

  return E_OK;
}
#endif /* #if ( OMC_OPMODECALLOUT == STD_ON ) */

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
