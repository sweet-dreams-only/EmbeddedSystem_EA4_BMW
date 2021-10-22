/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Services for get and set the bootmode.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015
*
*  \version     3.1.0
*
*/
/*----------------------------------------------------------------------------*/


#ifndef SRV_BOOTMODE_H
#define SRV_BOOTMODE_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Srv_Cfg.h"                /* Srv config header file                 */

#if (SRV_FEATURE_BOOTMODE >= SRV_BM_ENABLED)

#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include <Dcm_Types.h>                      /* Dcm_ProgConditionsType */
/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Srv_CHECK_VERSION(3,1,0))
   #error "Version of Srv_BootMode.h does not match the version of the module!"
#endif

#define   SRV_MAGIC_WORD_INVALID               0x00u
#define   SRV_DCM_STATUS_INVALID               0xFF

/**\{*/
/**
 * \name The following symbols are used for BootMode
 */
#define SRV_BM_LENGTH            0x08u
#define SRV_BM_BOOTLOADER        (uint8)0x00u, (uint8)0xFFu,                \
                                 (uint8)0xA5u, (uint8)0x5Au,                \
                                 (uint8)0x23u, (uint8)0x42u,                \
                                 (uint8)0xEBu, (uint8)0x6Cu
/**\}*/


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum
{
   SRV_BOOT_MODE_BOOTLOADER            = 0x5Au,
   SRV_BOOT_MODE_BOOTLOADER_PFM        = 0x3Cu,
   SRV_BOOT_MODE_NORMAL_WITH_RESP      = 0xA3u,
   SRV_BOOT_MODE_NORMAL_NO_RESP        = 0xC5u
} Srv_BootModeType;


/** Type for boot status */
typedef struct
{
   uint8                     MagicWord[8];      /**< Valid flag for BootStatus */

   Srv_BootModeType          NextBootMode;      /**< Next start mode */

   Dcm_ProgConditionsType    DcmStatus;         /**< Status for Dcm startup */

} Srv_BootStatusType;

typedef struct
{
   /** pattern of BootMode Bootloader                                          */
   uint8                                   BootModeBootloader[SRV_BM_LENGTH];
} Srv_CommonBmType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

/* Note: This area shall only contain one variable, because the linking
 *       processes for BM, BL and Appl may link this on different addresses
 *       otherwise.
 */

#define Srv_START_SEC_VAR_NOINIT_BOOT_STATUS
#include "Srv_MemMap.h" /* PRQA S 5087 */

/** contains boot status information */
extern VAR(Srv_BootStatusType, Srv_VAR) Srv_BootStatus;

#define Srv_STOP_SEC_VAR_NOINIT_BOOT_STATUS
#include "Srv_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Srv_START_SEC_CONST_SHARED_BM_DATA
#include "Srv_MemMap.h" /* PRQA S 5087 */

extern CONST(Srv_CommonBmType, Srv_SHARED_CONST) Srv_CommonBm;

/* Define end of the shared ROM section                                       */
#define Srv_STOP_SEC_CONST_SHARED_BM_DATA
#include "Srv_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Srv_START_SEC_CODE
#include "Srv_MemMap.h" /* PRQA S 5087 */

extern FUNC ( void, Srv_CODE)             Srv_BootModeInit ( void );

#if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM)
extern FUNC ( void, Srv_CODE)             Srv_BootDcmStatusGet
                 (
                    P2VAR ( Dcm_ProgConditionsType, AUTOMATIC, Srv_VAR )  pDcmStatus
                 );
#endif

extern FUNC ( Srv_BootModeType, Srv_CODE) Srv_BootModeGet  ( void );

extern FUNC ( void, Srv_CODE)             Srv_BootModeSet
                 (
                    CONST   ( Srv_BootModeType, Srv_VAR )  NewBootMode,
                    P2CONST ( Dcm_ProgConditionsType, AUTOMATIC, Srv_VAR )  pDcmStatus
                 );

#if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM)

extern FUNC ( boolean, Srv_CODE) Srv_ParallelFlashModeGet  ( void );
extern FUNC ( void, Srv_CODE) Srv_ParallelFlashModeSet (boolean parallelFlashMode);

#endif /* #if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM) */

#define Srv_STOP_SEC_CODE
#include "Srv_MemMap.h" /* PRQA S 5087 */

#endif /* #if (SRV_FEATURE_BOOTMODE >= SRV_BM_ENABLED) */

#endif /* SRV_BOOTMODE_H */

/*--- End of file ------------------------------------------------------------*/
