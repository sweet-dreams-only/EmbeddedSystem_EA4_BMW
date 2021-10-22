/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       SWE Table.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.3.1
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.558144
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including StbMB_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Dlog_SweTable.h"
#include "Dlog_SweGen.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SweTable.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
/*                      Boot.-SWE                                             */
/* -------------------------------------------------------------------------- */
#define BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

const Dlog_SweHeaderType Dlog_SweBootTable = {
    {  /* logistic data                                                        */
        BOOTSWECLASSIFICATIONDATA,
        0x00u, 0x00u, 0x00u, 0x00u,  /* Logistik Id */
        0x00u, 0x00u, 0x00u          /* Version */
    }
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   , {BOOTSWEDEVINFO}
#else
   , {0}
#endif
};

#define BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* Boot flash status                                                          */
#define BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweFlashStatusType Dlog_BootFlashStatus = {
                                                     { DLOG_SWE_CRC_CHECKSUM_DATA },
                                                     { DLOG_SWE_VALID_FLAG_DATA },
                                                     { DLOG_PROG_DEP_DATA }
                                              };
#define BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

#define BL_START_SEC_CONST_BOOTSWE_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const uint8 Dlog_BootSignature[DLOG_SIGNATURE_LENGTH] = {0};
#define BL_STOP_SEC_CONST_BOOTSWE_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* -------------------------------------------------------------------------- */
/*                      Appl.-SWE 1                                           */
/* -------------------------------------------------------------------------- */

/* SWE1 table                                                                 */
#define APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweHeaderType Dlog_Swe1Table =
{
   {  /* logistic data                                                        */
      SWE1SWECLASSIFICATIONDATA,
     0x00u, 0x00u, 0x00u, 0x01u, /* Logistik Id */
     0x00u, 0x00u, 0x00u                        /* Version */
   }
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   , {SWE1SWEDEVINFO}
#else
   , {0}
#endif
};
#define APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE1 flash status                                                          */
#define APPL_START_SEC_CONST_SWE1_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweFlashStatusType Dlog_Swe1FlashStatus =
                                              {
                                                     { DLOG_SWE_CRC_CHECKSUM_DATA },
                                                     { DLOG_SWE_VALID_FLAG_DATA },
                                                     { DLOG_PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE1 signature                                                          */
#define APPL_START_SEC_CONST_SWE1_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const uint8 Dlog_Swe1Signature[DLOG_SIGNATURE_LENGTH] = {0};
#define APPL_STOP_SEC_CONST_SWE1_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* -------------------------------------------------------------------------- */
/*                      Appl.-SWE 2                                           */
/* -------------------------------------------------------------------------- */

/* SWE1 table                                                                 */
#define APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweHeaderType Dlog_Swe2Table =
{
   {  /* logistic data                                                        */
      SWE2SWECLASSIFICATIONDATA,
     0x00u, 0x00u, 0x00u, 0x02u, /* Logistik Id */
     0x00u, 0x00u, 0x00u                        /* Version */
   }
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   , {SWE2SWEDEVINFO}
#else
   , {0}
#endif
};
#define APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE2 flash status                                                          */
#define APPL_START_SEC_CONST_SWE2_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweFlashStatusType Dlog_Swe2FlashStatus =
                                              {
                                                     { DLOG_SWE_CRC_CHECKSUM_DATA },
                                                     { DLOG_SWE_VALID_FLAG_DATA },
                                                     { DLOG_PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE2 signature                                                          */
#define APPL_START_SEC_CONST_SWE2_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const uint8 Dlog_Swe2Signature[DLOG_SIGNATURE_LENGTH] = {0};
#define APPL_STOP_SEC_CONST_SWE2_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* -------------------------------------------------------------------------- */
/*                      Appl.-SWE 3                                           */
/* -------------------------------------------------------------------------- */

/* SWE1 table                                                                 */
#define APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweHeaderType Dlog_Swe3Table =
{
   {  /* logistic data                                                        */
      SWE3SWECLASSIFICATIONDATA,
     0x00u, 0x00u, 0x00u, 0x03u, /* Logistik Id */
     0x00u, 0x00u, 0x00u                        /* Version */
   }
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   , {SWE3SWEDEVINFO}
#else
   , {0}
#endif
};
#define APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE3 flash status                                                          */
#define APPL_START_SEC_CONST_SWE3_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const Dlog_SweFlashStatusType Dlog_Swe3FlashStatus =
                                              {
                                                     { DLOG_SWE_CRC_CHECKSUM_DATA },
                                                     { DLOG_SWE_VALID_FLAG_DATA },
                                                     { DLOG_PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
#include "Dlog_MemMap.h" /* PRQA S 5087 */

/* SWE3 signature                                                          */
#define APPL_START_SEC_CONST_SWE3_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */
const uint8 Dlog_Swe3Signature[DLOG_SIGNATURE_LENGTH] = {0};
#define APPL_STOP_SEC_CONST_SWE3_SIGNATURE
#include "Dlog_MemMap.h" /* PRQA S 5087 */

