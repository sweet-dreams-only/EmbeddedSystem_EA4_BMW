/**
*  \file
*
*  \brief       Omc Management Adapter
*
*  This file contains the Omc management functionality.
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
#include "Omc_Assert.h"
#include "Omc_MgmtAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_MgmtAdapter.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Data Types
 -----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
 -----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

MgmtService_ResultType Omc_Mgmt_ProvideOperatingMode(Omc_GenericOperatingModeType Mode) {
  Std_ReturnType retVal;
  MgmtService_ResultType result;

  /* Make a rte swith to the mode. */
  retVal = Rte_Switch_operatingModeSwitchPort_currentOperatingMode((Rte_ModeType_OmcOperatingMode) Mode);
  if (retVal == E_OK) {
    result = MGMTSERVICE_OK;
  } else {
    result = MGMTSERVICE_NOT_OK;
  }
  return result;
}

MgmtService_ResultType Omc_Mgmt_ProvideExtendedOperatingMode(Omc_GenericExtendedOperatingModeType extendedMode) {
  Std_ReturnType retVal;
  MgmtService_ResultType result;

  /* Make a rte swith to the mode. */
  retVal = Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(
      (Rte_ModeType_OmcExtendedOperatingMode) extendedMode);
  if (retVal == E_OK) {
    result = MGMTSERVICE_OK;
  } else {
    result = MGMTSERVICE_NOT_OK;
  }
  return result;
}

/*----------------------------------------------------------------------------*/
/**
 * \brief   Omc_LifeCycleHandler
 *          Initializes Omc
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
void Omc_LifeCycleHandler(void) {
  Std_ReturnType retVal = E_OK;
  Omc_LifeCycleRequestType prevMode, nextMode;  /* PRQA S 0781 */
  Omc_LifeCycleRequestType reqMode = Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  (void) Rte_Mode_LifeCycle_Mode(&prevMode, &nextMode);

  switch (reqMode) {
    case RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED:
      if (RTE_MODE_Omc_LifeCycle_OMC_STOPPED == nextMode) {
        /* perform Omc initialization */
        Omc_Init();
        retVal = Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;
    case RTE_MODE_Omc_LifeCycle_OMC_RUNNING:
      if (RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED == nextMode) {
        /* switch to OMC_RUNNING */
        retVal = Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;
    case RTE_MODE_Omc_LifeCycle_OMC_STOPPED:
      if ((RTE_MODE_Omc_LifeCycle_OMC_RUNNING == nextMode) || (RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED == nextMode)) {
        /* switch to OMC_STOPPED */
        retVal = Rte_Switch_LifeCycle_Mode(reqMode);
      }
      break;

    default:
      break;
  }

  Omc_Assert_DevAssert(E_OK == retVal, OMC_DEVERROR_LIFECYCLEHANDLER_ERETURN);
#if (OMC_DEV_ERROR_DETECT == STD_OFF)
  (void)retVal;
#endif
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
