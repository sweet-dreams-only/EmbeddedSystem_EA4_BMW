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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Srv_BootMode.h"            /* Own header file                        */
#include "Srv_Cfg.h"                 /* Srv config header file                 */

#include <Std_Types.h>               /* AUTOSAR Standard Types                 */
#include <string.h>

#if (SRV_FEATURE_BOOTMODE >= SRV_BM_ENABLED)

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Srv_CHECK_VERSION(3,1,0))
   #error "Version of Srv_BootMode.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Srv_START_SEC_VAR_NOINIT_BOOT_STATUS
#include "Srv_MemMap.h" /* PRQA S 5087 */

/* SWS_ID: BM_0018 */
/* Boot mode and ECC/CRC error flags */
VAR(Srv_BootStatusType, Srv_VAR) Srv_BootStatus;

#define Srv_STOP_SEC_VAR_NOINIT_BOOT_STATUS
#include "Srv_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Srv_START_SEC_CONST_SHARED_BM_DATA
#include "Srv_MemMap.h" /* PRQA S 5087 */

CONST(Srv_CommonBmType, Srv_SHARED_CONST) Srv_CommonBm =
{
   /* pattern of BootMode Bootloader                                          */
   {
      SRV_BM_BOOTLOADER
   }

}; /* sharedBootROMData                                                       */

/* Define end of the shared ROM section                                       */
#define Srv_STOP_SEC_CONST_SHARED_BM_DATA
#include "Srv_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Local Data Types
-------------------------------------------------------------------------------*/

/* empty */


/*------------------------------------------------------------------------------
                      Local Variables
-------------------------------------------------------------------------------*/

/* empty */


/*------------------------------------------------------------------------------
                      Local Constants
-------------------------------------------------------------------------------*/

/* empty */


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

/* empty */


/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/

/* empty */


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Srv_START_SEC_CODE
#include "Srv_MemMap.h" /* PRQA S 5087 */


/*----------------------------------------------------------------------------*/
/**
 * This function inits the structure Srv_BootStatus.
 *
 * \remark If the magic word is valid, the boot status and the dcm status
 *         are not overwritten.
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Srv_CODE) Srv_BootModeInit ( void )
{
   /* Compare MagicWord with the valid value */
   if ( memcmp( Srv_BootStatus.MagicWord,
                Srv_CommonBm.BootModeBootloader,
                sizeof(Srv_BootStatus.MagicWord)
              ) != 0x00 )
   {
      /* Set magic word to invalid */
      (void)memset( &Srv_BootStatus.MagicWord[0],
                    (uint8)SRV_MAGIC_WORD_INVALID,
                    sizeof(Srv_BootStatus.MagicWord)
                  );

      /* Set bootmode to normal witout Dcm response */
      Srv_BootStatus.NextBootMode = SRV_BOOT_MODE_NORMAL_NO_RESP;

      /* Set Dcm status to invalid */
      (void)memset( &Srv_BootStatus.DcmStatus,
                    (uint8)SRV_DCM_STATUS_INVALID,
                    sizeof(Srv_BootStatus.DcmStatus)
                  );
   }
} /* end of function Srv_BootModeInit */

#if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM)
/*----------------------------------------------------------------------------*/
/**
 * This function copy the Dcm status from global structure
 * to the parameter DcmStatus
 *
 * \param[out] pDcmStatus Pointer to where the result shall be copied
 *
 * \pre Srv_BootModeInit() has been called since startup
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Srv_CODE) Srv_BootDcmStatusGet
             (
                P2VAR ( Dcm_ProgConditionsType, AUTOMATIC, Srv_VAR )  pDcmStatus
             )
{
   /* Get Dcm status */
   *pDcmStatus = Srv_BootStatus.DcmStatus;
} /* end of function Srv_BootDcmStatusGet */
#endif /* #if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM) */

/*----------------------------------------------------------------------------*/
/**
 * This function returns the current boot mode.
 *
 * \return current boot mode
 *
 * \pre Srv_BootModeInit() has been called since startup
 */
/*----------------------------------------------------------------------------*/
FUNC(Srv_BootModeType, Srv_CODE) Srv_BootModeGet ( void )
{
   return ( Srv_BootStatus.NextBootMode );
} /* end of function Srv_BootModeGet */

/*----------------------------------------------------------------------------*/
/**
 * This function sets the new BootMode in the Srv_BootStatus
 * that will be stored permanently later.
 *
 * \param[in] NewBootMode new BootMode that should be set
 * \param[in] pDcmStatus  pointer to new dcm status
 *
 * \remark In case of NewBootMode==SRV_BOOT_MODE_NORMAL_NO_RESP,
 *         the dcm status will not be overwritten. Therefore,
 *         pDcmStatus can be NULL in this case.
 *
 * \remark The Boot Mode will be set only, if Parallel Flash Mode is not set
 *
 * \pre    NewBootMode==SRV_BOOT_MODE_NORMAL_NO_RESP or
 *         pDcmStatus != NULL
 *
 * \post   Srv_BootModeGet() returns NewBootMode
 *
 * \post   If NewBootMode is one of {SRV_BOOT_MODE_BOOTLOADER, SRV_BOOT_MODE_NORMAL_WITH_RESP},
 *         then Srv_BootDcmStatusGet() returns the content of pDcmStatus
 */
/*----------------------------------------------------------------------------*/
FUNC(void, Srv_CODE) Srv_BootModeSet
             (
                CONST   ( Srv_BootModeType, Srv_VAR )  NewBootMode,
                P2CONST ( Dcm_ProgConditionsType, AUTOMATIC, Srv_VAR )  pDcmStatus
             )
{
   if (SRV_BOOT_MODE_BOOTLOADER_PFM != Srv_BootStatus.NextBootMode)
   {
      switch ( NewBootMode )
      {
         case SRV_BOOT_MODE_BOOTLOADER:
         case SRV_BOOT_MODE_NORMAL_WITH_RESP:
            /* Set magic word to valid */
            (void)memcpy( &Srv_BootStatus.MagicWord[0],
                          &Srv_CommonBm.BootModeBootloader[0],
                          sizeof(Srv_BootStatus.MagicWord)
                        );
            /* Set Dcm status */
            Srv_BootStatus.DcmStatus = *pDcmStatus;
            break;

         case SRV_BOOT_MODE_NORMAL_NO_RESP:
         default:
            /* Set magic word to invalid */
            (void)memset( &Srv_BootStatus.MagicWord[0],
                          (uint8)SRV_MAGIC_WORD_INVALID,
                          sizeof(Srv_BootStatus.MagicWord)
                        );
            /* Dcm status is not touched here */
            break;
      }

      /* Set NextBoootMode to parameter variable */
      Srv_BootStatus.NextBootMode = NewBootMode;
   }
} /* end of function Srv_BootModeSet */

#if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM)

/*----------------------------------------------------------------------------*/
/**
 * Getter for parallel flash mode flag (also known as C3 flag)
 *
 * \retval TRUE  parallel flash mode is set
 * \retval FALSE parallel flash mode is not set
 */
/*----------------------------------------------------------------------------*/
FUNC ( boolean, Srv_CODE) Srv_ParallelFlashModeGet  ( void )
{
   return (SRV_BOOT_MODE_BOOTLOADER_PFM == Srv_BootModeGet()) ? TRUE : FALSE;
}

/*----------------------------------------------------------------------------*/
/**
 * Setter for parallel flash mode flag (also known as C3 flag)
 *
 * \param parallelFlashMode The parallel flash mode flag to be set
 *
 * \remark The Dcm Status is invalidated
 */
/*----------------------------------------------------------------------------*/
FUNC ( void, Srv_CODE) Srv_ParallelFlashModeSet (boolean parallelFlashMode)
{
   if (TRUE == parallelFlashMode)
   {
      /* Set Dcm status to invalid */
      (void)memset( &Srv_BootStatus.DcmStatus,
                    (uint8)SRV_DCM_STATUS_INVALID,
                    sizeof(Srv_BootStatus.DcmStatus)
                  );

      /* Set NextBoootMode to parameter variable */
      Srv_BootStatus.NextBootMode = SRV_BOOT_MODE_BOOTLOADER_PFM;

      /* Set magic word to valid */
      (void)memcpy( &Srv_BootStatus.MagicWord[0],
                    &Srv_CommonBm.BootModeBootloader[0],
                    sizeof(Srv_BootStatus.MagicWord)
                  );
   }
   else
   {
      /* Set magic word to invalid */
      (void)memset( &Srv_BootStatus.MagicWord[0],
                    (uint8)SRV_MAGIC_WORD_INVALID,
                    sizeof(Srv_BootStatus.MagicWord)
                  );
      /* Set NextBoootMode to normal */
      Srv_BootStatus.NextBootMode = SRV_BOOT_MODE_NORMAL_NO_RESP;
   }
}

#endif /* #if (SRV_FEATURE_BOOTMODE == SRV_BM_ENABLED_DCM) */

#define Srv_STOP_SEC_CODE
#include "Srv_MemMap.h" /* PRQA S 5087 */

#endif /* #if (SRV_FEATURE_BOOTMODE >= SRV_BM_ENABLED) */

/*--- End of file ------------------------------------------------------------*/
