/**
 * \file
 *
 * \brief       Initialize Error Flags of all SWEs.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
#include "Dlog_SweInit.h"          /* module own header file                 */
/* -------------------------------------------------------------------------- */

#include "BUtil_BitArray.h"
#include "Dlog_Data.h"
#include "Dlog_Swe.h"
#include "Dlog_SweGet.h"
#include "Dlog_SweStatus.h"        /* Dlog_SweStatus */
#include "Dlog_SweTable.h"

#include <string.h>

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SweInit.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/
#if (DLOG_ENABLE_SWE_INIT == STD_ON) && (( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( DLOG_HANDLE_ECC_ROM == STD_ON ))

#define Dlog_START_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
      uint8 Dlog_SweErrorCheckDone[
               BUtil_CalcRequiredBytesForMultiByteBitArray( DLOG_MAX_NUMBER_OF_SWES )
            ];
                                            /* 0 = CRC of SWE not checked yet */
                                            /* 1 = CRC of SWE already checked */
                                            /* Bit 0: Bootloader SWE          */
                                            /* Bit 1: Application SWE 1       */
                                            /* ...                            */
                                            /* Bit n: Application SWE n       */
#define Dlog_STOP_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/**
 * This function clears the CRC and/or ECC error flags of all SWEs
 *
 * \global Dlog_SweStatus
 */
void Dlog_InitErrorFlagsOfAllSwes(void) {
  /* iterate all bytes of error flags         */
  uint8_least byte;

  for (byte = 0; byte < BUtil_CalcRequiredBytesForMultiByteBitArray(DLOG_MAX_NUMBER_OF_SWES); byte++) {
#if (DLOG_HANDLE_ECC_ROM == STD_ON)
    /* init ECC error flags           */
    Dlog_SweStatus.EccError[byte] = 0x00u;
#endif
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON)
    /* init CRC error flags           */
    Dlog_SweStatus.CrcError[byte] = 0x00u;
    /* init error check done flags    */
    Dlog_SweErrorCheckDone[byte] = 0x00u;
#endif
  }
}

/**
 * Scans all SWEs and fills the SweTable accordingly
 *
 * Should be called by Bootmanager before anything else.
 */
void Dlog_InitSweTable(void) {
  uint8 i;
  Dlog_SweValidStateType validState;

  (void)memset(Dlog_SweInfos, 0, sizeof(Dlog_SweInfos));

  Dlog_Data.sweInfo = Dlog_SweInfos;
  Dlog_Data.numberOfSwe = DLOG_NUMBEROFALLSWESGBMIDS;

  /* Check for BLU */
  validState = Dlog_CheckValidStateOfSwe(DLOG_SWE_ID_OF_BLU_SWE);
  Dlog_SweInfos[DLOG_SWE_ID_OF_BLU_SWE].validState = validState;
  if (DLOG_SWE_STATE_VALID_BTLD == validState) {
    /* valid BLU -> check for consistency */
    Dlog_SweProgDepStateType progDepState = Dlog_GetProgDepStateOfSwe(DLOG_SWE_ID_OF_BLU_SWE);

    if (DLOG_PROG_DEP_CONSISTENT_APPL == progDepState) {
      /* We have a valid and consistent BLU -> skip the rest */
      Dlog_Data.sweProgDepState = progDepState;
      return;
    }
  }
  if (DLOG_SWE_STATE_VALID_SWFL == validState) {
    Dlog_CopySweDescription(DLOG_SWE_ID_OF_BLU_SWE);
  }

  /* Check for BTLD */
  validState = Dlog_CheckValidStateOfSwe(SWE_ID_OF_BOOT_SWE);
  Dlog_SweInfos[SWE_ID_OF_BOOT_SWE].validState = validState;
  if (DLOG_SWE_STATE_VALID_BTLD != validState) {
    /* No valid BLU and no valid BTLD -> panic!!! */
    return;
  }

  Dlog_CopySweDescription(SWE_ID_OF_BOOT_SWE);

  /* Check all remaining SWEs */
  for (i = SWE_ID_OF_APPL_SWE1; i < DLOG_NUMBEROFALLSWESGBMIDS; ++i) {
    Dlog_Data.sweInfo[i].group = Dlog_CommonLogisticBtld.SweToGroupMap[i];
    if (DLOG_SWE_ID_OF_BLU_SWE == i) {
      continue;
    }
    validState = Dlog_CheckValidStateOfSwe(i);
    Dlog_SweInfos[i].validState = validState;
    if (DLOG_SWE_STATE_VALID_SWFL == validState) {
      Dlog_CopySweDescription(i);
    }
  }

  Dlog_Data.sweGroupInfo = Dlog_CommonLogisticBtld.SweGroupTable;

  /* set prog dep state, fingerprint and progId */
  Dlog_Data.sweProgDepState = Dlog_GetProgDepStateOfApplSwes(Dlog_Data.fingerprint, Dlog_Data.progId);

  Dlog_Data.numberOfHwe = 0;
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* (DLOG_ENABLE_SWE_INIT == STD_ON) && (( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( DLOG_HANDLE_ECC_ROM == STD_ON )) */
