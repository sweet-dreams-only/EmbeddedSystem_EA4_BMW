/**
*  \file
*
*  \brief       Stm Com Adapter
*
*  This file contains the Stm Com functionality.
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
/*
 * MISRA-C:2004 Rule 8.7: Due the memory mapping mechanismus in AUTOSAR
 * and since is not allowed to include files (Stm_MemMap.h) inside the body of a
 * function static local variables are not allowed and shall be declared as global.
 * See [MEMMAP018] and [MEMMAP023]. See PRQA 3218.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Stm_Com.h"
#include "Stm.h"
#include "Stm_Mgmt.h"
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
   #error "Version of Stm_ComAdapter.c does not match the Classic adapter version!"
#endif

/**
 * \brief Number of vehicle states
 */
#define STM_NUMBER_OF_VEHICLE_STATES 16

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

#if STM_VEHICLE_STATE_ENABLED == STD_ON

#define Stm_START_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Mapping of the vehicle state to the VehicleStateMode
 *
 * \lhref PNW_2076, PNW_2077
 *
 */
/* PRQA S 3218 Stm_VehicleStateModeMap */
static const Rte_ModeType_Stm_VehicleStateMode Stm_VehicleStateModeMap[STM_NUMBER_OF_VEHICLE_STATES] =
{
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_NOK,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_OK,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CUSTOMER_ABSENT,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_LIVING,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_DRIVE,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE,
   RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID
};
/* PRQA L:Stm_VehicleStateModeMap */

#define Stm_STOP_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /*STM_VEHICLE_STATE_ENABLED == STD_ON*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

static void Stm_ComHandleReceivedCELData(Stm_CentralErrorLockType data);

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
 * \brief Stm_ComHandleReceivedCELData
 *
 * Handling DataReceptionEvent of signal CENTRAL_ERROR_LOCK
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] Stm_CentralErrorLockType: signal value
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
static void Stm_ComHandleReceivedCELData(Stm_CentralErrorLockType data)
{
   switch (data)
   {
      case STM_CEL_UNLOCKED:
         Stm_Timer_Cancel();
         Stm_ReceivedCELUnlocked();
         break;
      case STM_CEL_LOCKED:
         Stm_Timer_StartLevel2TM();
         Stm_ReceivedCELLocked();
         break;
      default:
         Stm_Timer_Cancel();
         Stm_ReceivedCELInvalid();
         break;
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

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ReceiveCentralErrorLock
 *
 * Handling DataReceptionEvent of signal CENTRAL_ERROR_LOCK
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceiveCentralErrorLock(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->CentralErrorLockEnabled == TRUE)
#endif
   {
      /* Local variable to store the signal */
      Stm_CentralErrorLockType data = STM_CEL_INVALID;

      /* read the signal from the rte */
      /* Requirement STM_071: Return value is ignored because a value != RTE_OK
         can only be caused by wrong integration of the STM here */
      (void)Rte_Read_CentralErrorLockRx_centralErrorLock(&data);
      Stm_ComHandleReceivedCELData(data);
   }
} /* end of function Stm_ReceiveCentralErrorLock */

#if STM_COM_VARIANT_FIELDS == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ComTriggerGetVehicleStatus
 *
 * Triggers receiption of vehice status PDU for central error lock mode
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval COM_OK on success
 *         COM_NOT_OK on error
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
ComService_ResultType Stm_ComTriggerGetVehicleStatus(void)
{
   ComService_ResultType result = COM_NOT_OK;
   Std_ReturnType ret;

   ret = Rte_Call_CELQueryPort_GetVehicleStatus();
   if (ret == RTE_E_OK)
   {
      result = COM_OK;
   }
   return result;
}

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ComGetVehicleStatus
 *
 * Reads vehice status PDU for central error lock mode and provides value to Stm
 * generic on success
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in,out] none
 *
 * \retval COM_OK on success
 *         COM_NO_DATA if no data has been received
 *         COM_NOT_OK on error
 *
 * \pre Stm_ComTriggerGetVehicleStatus has been called before
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
ComService_ResultType Stm_ComGetVehicleStatus(void)
{
   ComService_ResultType result = COM_NOT_OK;
   Stm_VehicleStateFieldType data;
   Std_ReturnType ret;

   ret = Rte_Result_CELQueryPort_GetVehicleStatus(&data);
   if (ret == RTE_E_OK)
   {
      Stm_ComHandleReceivedCELData(data.StatusInterlockErrorMemoryFzm);
      result = COM_OK;
   }
   else if (ret == RTE_E_NO_DATA)
   {
      result = COM_NO_DATA;
   }
   return result;
}

/* #if STM_COM_VARIANT_FIELDS == STD_ON */

#else /* #if STM_COM_VARIANT_FIELDS == STD_OFF */
/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ErrorCentralErrorLock
 *
 * Handling the DataReceiveErrorEvent signal for the Central Error Lock state.
 * This function will be used only in case the StmComVariant is STM_COM_CYCLIC_DATAELEMENTS,
 * In this case this function will be called if the level 1 timeout or
 * the the level 2 timeout is reached.
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]  none
 * \param[in]   none
 *
 * \retval none
 *
 * \pre Stm module is initialized
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ErrorCentralErrorLock(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->CentralErrorLockEnabled == TRUE)
#endif
   {
      /* Set mode to invalid */
      Stm_ComHandleReceivedCELData(STM_CEL_INVALID);
   }
} /* end of function Stm_ErrorCentralErrorLock */

#endif /* #if STM_COM_VARIANT_FIELDS == STD_OFF */
#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/


#if STM_ENERGY_STATE_ENABLED == STD_ON
#if STM_COM_VARIANT_FIELDS == STD_OFF

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ErrorEnergyMode
 *
 * Handling DataReceptionErrorEvent of signal ENERGY_STATE
 *
 * \global_r  none
 * \global_w  none
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
 */
/*----------------------------------------------------------------------------*/
void Stm_ErrorEnergyMode(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->EnergyStateEnabled == TRUE)
#endif
   {
      /* The new mode is set at once */
      Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID);
   }
} /* end of function Stm_ErrorEnergyMode */

#endif /* #if STM_COM_VARIANT_FIELDS == STD_OFF */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ReceiveEnergyMode
 *
 * Handling DataReceptionEvent of signal ENERGY_STATE
 *
 * \global_r  none
 * \global_w  none
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
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceiveEnergyMode(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->EnergyStateEnabled == TRUE)
#endif
   {
       /* Local variable to store the signal */
       Stm_EnergyStateType data = STM_ENERGY_INVALID;

       /* read the signal from the rte */
       /* Requirement STM_071: Return value is ignored because a value != RTE_OK
          can only be caused by wrong integration of the STM here */
       (void)Rte_Read_EnergyModeRx_energyState(&data);
       switch(data)
       {
          case STM_ENERGY_GOOD:
             /* STM_ENERGY_GOOD received */
             /* The new mode is set at once */
             Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD);
             break;
          case STM_ENERGY_OK:
             /* STM_ENERGY_OK received */
             /* The new mode is set at once */
             Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK);
             break;
          case STM_ENERGY_SHORTAGE:
             /* STM_ENERGY_SHORTAGE received */
             /* The new mode is set at once */
             Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE);
             break;
          case STM_ENERGY_SEVERE_SHORTAGE:
             /* STM_ENERGY_SEVERE_SHORTAGE received */
             /* The new mode is set at once */
             Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE);
             break;
          default :
             /* invalid data */
             Stm_Mgmt_ProvideEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID);
             break;
       }
   }
}

#endif /* #if STM_ENERGY_STATE_ENABLED == STD_ON */


#if STM_VEHICLE_STATE_ENABLED == STD_ON
#if STM_COM_VARIANT_FIELDS == STD_OFF

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ErrorVehicleState
 *
 * Handling DataReceptionErrorEvent of signal VEHICLE_STATE
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  PNW_2023
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ErrorVehicleState(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->VehicleStateEnabled == TRUE)
#endif
   {
      /* The new mode is set at once */
      /** \lhref  PNW_2081 */
      Stm_Mgmt_ProvideVehicleStateMode(RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID);
   }
} /* end of function Stm_ErrorVehicleState */

#endif /* #if STM_COM_VARIANT_FIELDS == STD_OFF */

/*----------------------------------------------------------------------------*/
/**
 * \brief Stm_ReceiveVehicleState
 *
 * Handling DataReceptionEvent of signal VEHICLE_STATE
 *
 * \global_r  none
 * \global_w  none
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
 * \lhref  PNW_2023
 *
 */
/*----------------------------------------------------------------------------*/
void Stm_ReceiveVehicleState(void)
{
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
   if(Stm_PBConfigSetPtr->VehicleStateEnabled == TRUE)
#endif
   {
      /* Local variable to store the signal */
      Stm_VehicleStateType data = STM_VEHICLE_STATE_INVALID;

      /* read the signal from the rte */
      /* Requirement STM_071: Return value is ignored because a value != RTE_OK
         can only be caused by wrong integration of the STM here */
      (void)Rte_Read_VehicleStateRx_VehicleState(&data);

      /** \lhref  PNW_2079 */
      if(STM_NUMBER_OF_VEHICLE_STATES > data)
      {
         /* valid signal received */
         Stm_Mgmt_ProvideVehicleStateMode(Stm_VehicleStateModeMap[data]);
      }
      else
      {
         /* invalid data */
         Stm_Mgmt_ProvideVehicleStateMode(RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID);
      }
   }
} /* end of function Stm_ReceiveVehicleState */

#endif /* #if STM_VEHICLE_STATE_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */
