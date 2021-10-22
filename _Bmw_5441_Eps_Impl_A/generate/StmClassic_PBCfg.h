/**
*  \file
*
*  \brief       BMW SWC StmClassic_PBCfg
*
*  Configuration file for Stm Post Build Functionality
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.2.0
*
*  \remarks     File is generated with PAGe
*
*/
/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.979486
*
------------------------------------------------------------------------------*/

#ifndef STMCLASSIC_PBCFG_H
#define STMCLASSIC_PBCFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"          /* BMW standard types                         */
#include "StmClassic_Version.h"        /* Stm Version                                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of StmClassic_PBCfg.h does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/* Struct containing configuration                                            */
typedef struct
{
    boolean CentralErrorLockEnabled;
    boolean EnergyStateEnabled;
    boolean VehicleStateEnabled;
}Stm_PBConfigType;

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

extern const Stm_PBConfigType Stm_PBConfig_StmFeatureActivation;

#define Stm_STOP_SEC_CONST_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

#define Stm_START_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

extern const Stm_PBConfigType * Stm_PBConfigSetPtr;

#define Stm_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Stm_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#endif /* STMCLASSIC_PBCFG_H */
/*** End of file **************************************************************/
