/**
*  \file
*
*  \brief       Stm Mgmt Interface
*
*  This file contains the interface definition for the Stm Management.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef STM_MGMT_H
#define STM_MGMT_H

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

#include "StmClassic_Cfg.h"
#include "Rte_Stm.h"
#include "StmClassic_Version.h"
#if ( STD_ON == STM_MULTIPLE_CONFIG_SETS_EXIST )
#include <StmClassic_PBCfg.h>        /* Post build configuration    */
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_Mgmt.h does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_MULTIPLE_CONFIG_SETS_EXIST == STD_ON
/**
 * \brief Function to select Post Build configuration
 */
void Stm_SetConfiguration(const Stm_PBConfigType * selectedConfig);
#endif /* #if STM_MULTIPLE_CONFIG_SETS_EXIST == STD_ON */

#if STM_ENERGY_STATE_ENABLED == STD_ON
extern void Stm_Mgmt_ProvideEnergyMode(Rte_ModeType_Stm_EnergyStateMode EnergyState);
#endif /* #if STM_ENERGY_STATE_ENABLED == STD_ON */

#if STM_VEHICLE_STATE_ENABLED == STD_ON
extern void Stm_Mgmt_ProvideVehicleStateMode(Rte_ModeType_Stm_VehicleStateMode VehicleState);
#endif /* #if STM_VEHICLE_STATE_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /* STM_MGMT_H */

/*--- End of file ------------------------------------------------------------*/
