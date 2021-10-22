/**
*  \file
*
*  \brief       Stm Com Interface
*
*  This file contains the interface definition for the Stm Com Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef STM_COM_H
#define STM_COM_H

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

#include "Stm_Cfg.h"
#include "StmClassic_Cfg.h"
#include "StmClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_Com.h does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef enum {
   COM_OK,
   COM_NOT_OK,
   COM_NO_DATA
} ComService_ResultType;

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

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

#if STM_COM_VARIANT_FIELDS == STD_ON
extern ComService_ResultType Stm_ComTriggerGetVehicleStatus(void);
extern ComService_ResultType Stm_ComGetVehicleStatus(void);
#endif /* STM_COM_VARIANT_FIELDS == STD_ON */

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /* STM_COM_H */

/*--- End of file ------------------------------------------------------------*/
