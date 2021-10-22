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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_BootMode.h"            /* Own header file                        */
#include "DlogClassic_Cfg.h"          /* Dlog config header file                 */

#include <Std_Types.h>               /* AUTOSAR Standard Types                 */
#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_BootMode.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* Boot mode and ECC/CRC error flags */
Dlog_BootStatusType Dlog_BootStatus;

#define Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Dlog_START_SEC_CONST_SHARED_BM_DATA
#include "Dlog_MemMap.h" /* PRQA S 5087 */

const Dlog_CommonBmType Dlog_CommonBm =
{
   /* pattern of BootMode Bootloader                                          */
   {
       DLOG_BM_MAGIC_WORD
   }

}; /* sharedBootROMData                                                       */

/* Define end of the shared ROM section                                       */
#define Dlog_STOP_SEC_CONST_SHARED_BM_DATA
#include "Dlog_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */


/**
 * This function inits the structure Dlog_BootStatus.
 *
 * \remark If the magic word is valid, the boot status is not overwritten.
 */
void Dlog_BootModeInit(void) {
  /* Compare MagicWord with the valid value */
  if ((memcmp(Dlog_BootStatus.MagicWord, Dlog_CommonBm.MagicWord, sizeof(Dlog_BootStatus.MagicWord)) != 0x00) ||
      (Dlog_BootStatus.BootFlags != (uint8)(~Dlog_BootStatus.BootFlagsInv))){
    /* Set magic word to valid */
    (void)memcpy(&Dlog_BootStatus.MagicWord[0], &Dlog_CommonBm.MagicWord[0], sizeof(Dlog_BootStatus.MagicWord));

    /* Set bootmode to normal */
    Dlog_BootStatus.BootFlags = 0;
    Dlog_BootStatus.BootFlagsInv = ~Dlog_BootStatus.BootFlags;
  }
} /* end of function Dlog_BootModeInit */

/**
 * Returns true, if Bootloader is requested
 *
 * \retval TRUE  Bootloader is requested
 * \retval FALSE otherwise
 *
 * \pre Dlog_BootModeInit() has been called since startup
 */
boolean Dlog_BootModeIsBootloader(void) {
  return Dlog_BootStatus.BootFlags != 0;
}

/**
 * This function sets the request for bootloader for a specific user
 *
 * \param[in] user        The user that wants to request for bootloader
 * \param[in] bootloader  TRUE to request bootloader startup, FALSE to reset the request
 *
 * \post Dlog_BootModeIsBootloader() returns TRUE if bootloader == TRUE
 */
void Dlog_BootModeRequestBootloader(Dlog_BootModeUserType user, boolean bootloader) {
  if (FALSE != bootloader) {
    Dlog_BootStatus.BootFlags |= user;
  } else {
    Dlog_BootStatus.BootFlags &= ~user;
  }
  Dlog_BootStatus.BootFlagsInv = ~Dlog_BootStatus.BootFlags;
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
