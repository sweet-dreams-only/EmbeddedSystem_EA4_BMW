/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file contains the main VIN functionality.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user: no
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Vin_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

#ifndef VIN_H
#define VIN_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Rte_Vin_Type.h"              /* AUTOSAR Standard Types */
#include "Vin_Cfg.h"                   /* Own config header file */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/**
 * \brief Type to describe the environment the ssv is in
 */
typedef enum
{
   /** In an unsafe environment the Ssv does not expect to receive signed messages */
   VIN_UNSAFE_ENVIRONMENT       = 0x0,
   /** In a safe environment the Ssv expects to receive signed messages */
   VIN_SAFE_ENVIRONMENT         = 0x11,
   /** State of environment until NV is read */
   VIN_UNKOWN_ENVIRONMENT       = 0x55
} Vin_EnvironmentType;

typedef struct
{
   VinArrayType lastReceivedVin;
   uint8 environment;
} Vin_NVStateType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"

extern VAR(Vin_VinType, Vin_VAR) Vin_CurrentVin;

/* PRQA S 5087 2 */
#define Vin_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Vin_MemMap.h"

#define Vin_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */

extern VAR(Vin_NVStateType, Vin_VAR) Vin_NVState;

#define Vin_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Vin_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */

extern CONST(Vin_NVStateType, Vin_CONST) Vin_NVStateDefault;

#define Vin_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Vin_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Vin_START_SEC_CODE
#include "Vin_MemMap.h"

extern FUNC(void, Vin_CODE) Vin_NotifyVinReceived(void);
#if (Vin_ENABLE_SECURE_VIN == STD_ON)
extern FUNC(void, Vin_CODE) Vin_NotifyVinSecurityUpdate(void);
#endif

extern FUNC(Vin_EnvironmentType, Vin_CODE) Vin_GetEnvironment(void);
extern FUNC(void,                Vin_CODE) Vin_SwitchToSafeEnvironment(void);

extern FUNC(void, Vin_CODE) Vin_GetCurrentVin(P2VAR(Vin_VinType, AUTOMATIC, Vin_APPL_DATA) currentVin);


/* PRQA S 5087 2 */
#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h"

#endif /* VIN_H */
/*--- End of file ------------------------------------------------------------*/
