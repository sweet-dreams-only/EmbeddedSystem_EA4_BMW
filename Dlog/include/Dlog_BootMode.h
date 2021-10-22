/**
 * \file
 *
 * \brief       Services for get and set the bootmode.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOG_BOOTMODE_H
#define DLOG_BOOTMODE_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "DlogClassic_Cfg.h"                /* Dlog config header file                 */


#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include <Dcm_Types.h>                      /* Dcm_ProgConditionsType */
/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_BootMode.h does not match the version of the module!"
#endif

#define   DLOG_MAGIC_WORD_INVALID               0x00u

/**\{*/
/**
 * \name The following symbols are used for BootMode
 */
#define DLOG_BM_LENGTH           0x08u
#define DLOG_BM_MAGIC_WORD       (uint8)0x00u, (uint8)0xFFu,                \
                                 (uint8)0xA5u, (uint8)0x5Au,                \
                                 (uint8)0x23u, (uint8)0x42u,                \
                                 (uint8)0xEBu, (uint8)0x6Cu
/**\}*/


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
  DLOG_BMUSER_PROG = 0x11,
  DLOG_BMUSER_PFM  = 0x22
} Dlog_BootModeUserType;


/** Type for boot status */
typedef struct {
  uint8 MagicWord[DLOG_BM_LENGTH];    /**< Valid flag for BootStatus */
  uint8 BootFlags;                    /**< a set bit indicates a request for Bootloader */
  uint8 BootFlagsInv;                 /**< inverse of BootFlags */
} Dlog_BootStatusType;

typedef struct
{
   /** pattern of BootMode Bootloader                                          */
   uint8                                   MagicWord[DLOG_BM_LENGTH];
} Dlog_CommonBmType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/** contains boot status information */
extern Dlog_BootStatusType Dlog_BootStatus;

#define Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Dlog_START_SEC_CONST_SHARED_BM_DATA
#include "Dlog_MemMap.h" /* PRQA S 5087 */

extern const Dlog_CommonBmType Dlog_CommonBm;

/* Define end of the shared ROM section                                       */
#define Dlog_STOP_SEC_CONST_SHARED_BM_DATA
#include "Dlog_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

extern void    Dlog_BootModeInit (void);

extern boolean Dlog_BootModeIsBootloader(void);
extern void    Dlog_BootModeRequestBootloader(Dlog_BootModeUserType user, boolean bootloader);


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

#endif /* DLOG_BOOTMODE_H */

/*--- End of file ------------------------------------------------------------*/
