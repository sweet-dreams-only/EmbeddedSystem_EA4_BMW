/**
*  \file
*
*  \brief       Stm Management Adapter
*
*  This file contains the Stm management functionality.
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
   MISRA-C:2004 Rule 19.1: including Stm_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Stm_MgmtAdapter.h"
#include "Stm_Mgmt.h"
#include "Stm.h"
#include "Stm_Timer.h"
#include "Rte_Stm.h"
#include "StmClassic_Version.h"
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
#include "StmClassic_PBCfg.h"        /* Post build configuration    */
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_MgmtAdapter.c does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

static void Stm_Mgmt_ProvideCentralErrorLockMode(Rte_ModeType_Stm_CentralErrorLockMode Stm_NextCentralErrorLockMode);

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideCentralErrorLockMode
 *
 * Function to provide/set the central error lock mode
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     Stm_NextCentralErrorLockMode
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
static void Stm_Mgmt_ProvideCentralErrorLockMode(Rte_ModeType_Stm_CentralErrorLockMode Stm_NextCentralErrorLockMode)
{
   Rte_ModeType_Stm_CentralErrorLockMode previousMode;
   Rte_ModeType_Stm_CentralErrorLockMode nextMode;
   /* return value is ignored only next mode is needed */
   (void)Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(&previousMode,&nextMode);
   if(    nextMode
      != Stm_NextCentralErrorLockMode)
   {
      /* set new CentralErrorLockMode*/
      /* Requirement STM_070: The return value is ignored because a return value != RTE_OK
         is considered an RTE configuration issue */
      (void)Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_NextCentralErrorLockMode);
   }
}

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_MULTIPLE_CONFIG_SETS_EXIST == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * \brief       set selected Stm Configuration
 *
 *
 * \global_r    None
 * \global_w    None
 * \global_rw   None
 *
 * \param       Stm_PBConfigType: Pointer to configuration
 *
 * \retval      None
 *
 * \pre         PostBuild Option must be used
 *
 * \post        None
 *
 * \remarks     None
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_SetConfiguration(const Stm_PBConfigType * selectedConfig)
{
   Stm_PBConfigSetPtr = selectedConfig;
}/* end of function Stm_SetConfiguration */
#endif /* #if STM_MULTIPLE_CONFIG_SETS_EXIST == STD_ON */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_StopCentralErrorLockSupervision
 *
 * Initialize the state monitor module
 *
 * \global_r  none
 * \global_w  Stm_TimeoutMonitoringActive
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval none
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5731
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_StopCentralErrorLockSupervision(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->CentralErrorLockEnabled == TRUE)
#endif
   {
      Stm_CELNotReceivable();
      Stm_Timer_Cancel();
   }
} /* end of function Stm_StopCentralErrorLockSupervision */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_InitialCentralErrorLockSupervision
 *
 * Function to start the central error lock level1 timer
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval none
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5731
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_InitialCentralErrorLockSupervision(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->CentralErrorLockEnabled == TRUE)
#endif
   {
      Stm_Timer_StartLevel1TM();
      Stm_CELReceivable();
   }
} /* end of function Stm_InitialCentralErrorLockSupervision */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideCentralErrorLockModeUnlocked
 *
 * Function to provide/set the central error lock mode Unlocked
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Mgmt_ProvideCentralErrorLockModeUnlocked(void)
{
   Stm_Mgmt_ProvideCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED);
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideCentralErrorLockModeLocked
 *
 * Function to provide/set the central error lock mode Locked
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Mgmt_ProvideCentralErrorLockModeLocked(void)
{
   Stm_Mgmt_ProvideCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED);
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideCentralErrorLockModeInvalid
 *
 * Function to provide/set the central error lock mode Invalid
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Mgmt_ProvideCentralErrorLockModeInvalid(void)
{
   Stm_Mgmt_ProvideCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID);
}

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#if STM_ENERGY_STATE_ENABLED == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideEnergyMode
 *
 * Function to provide/set the energy mode
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     Stm_NextEnergyStateMode
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Mgmt_ProvideEnergyMode(Rte_ModeType_Stm_EnergyStateMode Stm_NextEnergyStateMode)
{
   Rte_ModeType_Stm_EnergyStateMode previousMode;
   Rte_ModeType_Stm_EnergyStateMode nextMode;

   /* return value is ignored only next mode is needed */
   (void)Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(&previousMode,&nextMode);
   if(    nextMode
      != Stm_NextEnergyStateMode)
   {
      /* set new EnergyMode*/
      /* Requirement STM_070: The return value is ignored because a return value != RTE_OK
         is considered an RTE configuration issue */
      (void)Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(Stm_NextEnergyStateMode);
   }
}
#endif /* #if STM_ENERGY_STATE_ENABLED == STD_ON */

#if STM_VEHICLE_STATE_ENABLED == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_Mgmt_ProvideVehicleStateMode
 *
 * Function to provide/set the vehicle state mode
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     Stm_NextVehicleStateMode
 *
 * \retval none
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  PNW_2023
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_Mgmt_ProvideVehicleStateMode(Rte_ModeType_Stm_VehicleStateMode Stm_NextVehicleStateMode)
{
   Rte_ModeType_Stm_VehicleStateMode previousMode;
   Rte_ModeType_Stm_VehicleStateMode nextMode;

   /* return value is ignored only next mode is relevant */
   (void)Rte_Mode_VehicleStateModeSwitchPort_currentVehicleStateMode(&previousMode,&nextMode);

   /** \lhref  PNW_2080 */
   if(nextMode != Stm_NextVehicleStateMode)
   {
       /* set new VehicleStateMode*/
       /* Requirement STM_070: The return value is ignored because a return value != RTE_OK
          is considered an RTE configuration issue */
       (void)Rte_Switch_VehicleStateModeSwitchPort_currentVehicleStateMode(Stm_NextVehicleStateMode);
   }
}
#endif /* #if STM_VEHICLE_STATE_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */
