/**
 * \file
 *
 * \brief       Get SWE related data.
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
#include "Dlog_SweGet.h"          /* module own header file                   */

#if (DLOG_ENABLE_SWE_GET == STD_ON)

/* -------------------------------------------------------------------------- */
#include "Dlog_SweGen.h"
#include "Dlog_SweStatus.h"
/* -------------------------------------------------------------------------- */
#if (DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON)
#include "Dlog_SweInit.h"          /* contains sweErrorCheckDone              */
#include "Crc.h"                   /* contains function to calculate CRC      */

#endif
#include "BUtil_ByteMask.h"
#include "Dlog_Memory.h"

#if ((DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON) && (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON))
#include "Dlog_BluSweCheckSum.h" /* contains Dlog_BluSweCheckSumType */

#endif
#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) && (DLOG_HANDLE_ECC_ROM == STD_ON)
#include "Dlog_User.h"         /* contains Dlog_UserTriggerEccCheck */

#endif

#include <string.h>
/* -------------------------------------------------------------------------- */


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 14.7. Reason: early return in case of errors makes code more readable,
   see PRQA: 2006, 5207 */

/* Violation of MISRA rule 17.4. Reason: arrays are passed as pointers due to compiler abstraction,
   see PRQA: 0492 */

/* Violation of MISRA rule 19.1. Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5, 3, 1))
#error "Version of Dlog_SweGet.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

static const Dlog_SweFlashStatusType* Dlog_GetFlashStatus(uint8 sweId);

#if (DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK == STD_ON)
static boolean Dlog_BlankCheck(const uint8* data, uint8_least length);
#endif

#if ((DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON) && (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON))

static Std_ReturnType Dlog_CrcCheck(uint8 sweId);

#endif

#if (DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON)
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON) || (DLOG_HANDLE_ECC_ROM == STD_ON)

LOCAL_INLINE boolean Swe_GetErrorCheckDoneFlagOfSwe(uint8 sweId);

LOCAL_INLINE void Swe_SetErrorCheckDoneFlagOfSwe(uint8 sweId);

#endif
#endif

/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/
#if (DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON)
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON) || (DLOG_HANDLE_ECC_ROM == STD_ON)

/**
 * Returns the ErrorCheckDoneFlag of the given SWE.
 *
 * \param sweId Id of the SWE
 *
 * \retval TRUE The error flag of the SWE is set
 * \retval FALSE The error flag of the SWE is not set
 */
LOCAL_INLINE boolean Swe_GetErrorCheckDoneFlagOfSwe(uint8 sweId) {
  return BUtil_GetBitInMultiByteBitArray(Dlog_SweErrorCheckDone, sweId) != 0u;
}

/**
 * Sets the ErrorCheckDoneFlag of the given SWE.
 *
 * \param sweId Id of the SWE
 */
LOCAL_INLINE void Swe_SetErrorCheckDoneFlagOfSwe(uint8 sweId) {
  BUtil_SetBitInMultiByteBitArray(Dlog_SweErrorCheckDone, sweId);
}

#endif
#endif

/*----------------------------------------------------------------------------*/
/**
 * Returns a pointer to the Flash Status of the given Swe
 *
 * \param[in] sweId Id of the Swe
 *
 * \return a pointer to the Flash Status of the given Swe
 */
/*----------------------------------------------------------------------------*/
static const Dlog_SweFlashStatusType* Dlog_GetFlashStatus(uint8 sweId) {
  const Dlog_SweFlashStatusType* flashStatus;

#if (DLOG_ENABLE_DIRECT_BOOT_APPL1_SWE == STD_ON)

  if (SWE_ID_OF_BOOT_SWE == sweId) {
    flashStatus = &Dlog_BootFlashStatus;
  }                                 /* if SWE is not first application SWE      */
  else if (sweId != DLOG_SWE_ID_OF_BLU_SWE) {
#endif
    /* read valid flag of SWE from    */
    /* ROM by using address from      */
    /* bootloader (sharedBootROMData) */
    flashStatus = Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId];

#if (DLOG_ENABLE_DIRECT_BOOT_APPL1_SWE == STD_ON)
  } else {
    /* read valid flag of first appl  */
    /* SWE from ROM by using          */
    /* preconfigured address, because */
    /* bootloader may not be present  */
    /* in case of unfinished BLU      */
    flashStatus = &DLOG_DIRECT_BLU_SWE_FLASHSTATUS;
  }
#endif
  return flashStatus;
}

#if (DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK == STD_ON)
static boolean Dlog_BlankCheck(const uint8* data, uint8_least length)
{
   uint8_least numberOfBlankBytes = 0u;
   while ( ( numberOfBlankBytes < (uint8_least)length ) &&
           ( data[ numberOfBlankBytes ] == (uint8)FLASH_ERASED_BYTE ) /* PRQA S 0492 */
         )
   {
      ++numberOfBlankBytes;
   }

  return ( numberOfBlankBytes == (uint8_least)DLOG_SWE_VALID_FLAG_AREA_LENGTH );
}
#endif /* #if ( DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK == STD_ON ) */

#if ((DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON) && (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON))
/*----------------------------------------------------------------------------*/
/**
 * Performs a CRC check for the given SWE
 *
 * \param[in] sweId Id of the SWE to be checked
 *
 * \retval E_OK     CRC check is ok
 * \retval E_NOT_OK CRC check is not ok
 */
/*----------------------------------------------------------------------------*/
static Std_ReturnType Dlog_CrcCheck(uint8 sweId) {
  /* variables needed for CRC check */
  size_t       segmentStartAddress;
  size_t       segmentEndAddress;
  uint16       crcBlockSkipSize;
  const uint8* pCurrentPosition;
  const uint8* pCrcCheckAreaEnd;
  const uint8* pCrcExcludeBegin;
  const uint8* pCrcExcludeEnd;
  uint32       crcValueInRom;
  uint32       crcValueMisra;
  boolean      currentDataPointerOverflow;
  uint8        processClassOfSwe;

  if (sweId == DLOG_SWE_ID_OF_BLU_SWE) {
    processClassOfSwe = DLOG_DIRECT_BLU_SWE_TABLE.SgbmId[0];
  } else {
    processClassOfSwe =
        Dlog_CommonLogisticBtld.PointerToSweTable[sweId]->SgbmId[0];
  }

  /* if SWE is a BLU                         */
  if ((sweId == DLOG_SWE_ID_OF_BLU_SWE)
      && ((processClassOfSwe == DLOG_PROCESSCLASS_BTLD)
          || (processClassOfSwe == DLOG_PROCESSCLASS_BLUP))) {
    /* Get information for CRC check directly from BLU, because
     * bootloader may not be present in case of unfinished BLU.
     * The type cast is intended, since the structure is created in BLU.
     */
    /* PRQA S 0310 2 */
    const Dlog_BluSweCheckSumType* bluSweCheckSum =
    (const Dlog_BluSweCheckSumType*)&DLOG_DIRECT_BLU_SWE_FLASHSTATUS.SweCrcCheckSum;

    /* The CRC is calculated using uint8 */
    /* PRQA S 0310 1 */
    pCrcExcludeBegin =    (const uint8*)&DLOG_DIRECT_BLU_SWE_FLASHSTATUS;

    crcValueInRom =       bluSweCheckSum->crcValue;
    segmentStartAddress = bluSweCheckSum->crcStartAddress;
    segmentEndAddress =   bluSweCheckSum->crcEndAddress;
    crcBlockSkipSize =    bluSweCheckSum->crcBlockStepSize;
  }
    /* if SWE is not a BLU                      */
  else {
    /* get information for CRC check  */
    /* from bootloader ROM            */
    /* (sharedBootROMData)            */
    /* The CRC value is written by the SWE generator */
    /* PRQA S 0310 1 */
    crcValueInRom = *(const uint32*)(&Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->SweCrcCheckSum);

    /* The CRC is calculated using uint8 */
    /* PRQA S 0310 1 */
    pCrcExcludeBegin = (const uint8*)Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId];

    Dlog_GetAddressOfFlashSegmentContainingValidFlag(
        sweId,
        &segmentStartAddress,
        &segmentEndAddress);
    crcBlockSkipSize = Dlog_CommonLogisticBtld.CrcBlockSkipSize;
  }

  /* set pointer to start of segment*/
  /* containing the SWE valid flag  */
  /* We are using a platform specific macro here, so it should be save */
  /* PRQA S 0306 1*/
  pCurrentPosition = (const uint8*)Dlog_ConvertExtAddress2IntPointer(segmentStartAddress);

  /* get pointer to end of CRC      */
  /* check area (SgbmId)            */
  /* We are using a platform specific macro here, so it should be save */
  /* PRQA S 0306 1 */
  pCrcCheckAreaEnd = (const uint8*)Dlog_ConvertExtAddress2IntPointer(segmentEndAddress);

  /* The pointer arithmetic is intended here */
  /* PRQA S 0488 1*/
  pCrcExcludeEnd = pCrcExcludeBegin + DLOG_SWE_FLASH_STATUS_AREA_LENGTH;

  /* initialize calculated CRC      */
  crcValueMisra = Crc_CalculateCRC32(pCurrentPosition, 0u, 0u, TRUE);

  /* initialize overflow indication */
  currentDataPointerOverflow = FALSE;

  /* trigger watchdog before CRC    */
  /* check to avoid watchdog reset  */
  Dlog_WatchdogTrigger();

  /* iterate all bytes from start of flash    */
  /* segment to start of SgbmId. This area    */
  /* is part of the CRC check                 */
  while ((pCurrentPosition <= pCrcCheckAreaEnd) &&
         (currentDataPointerOverflow == FALSE)) {
    const uint8* pNextPosition;

    if ((pCurrentPosition >= pCrcExcludeBegin) && (pCurrentPosition < pCrcExcludeEnd)) {
#if (DLOG_HANDLE_ECC_ROM == STD_ON)
      /* read (touch) current byte      */
      const volatile uint8 devNull = *pCurrentPosition;
      if (devNull == 0) {} /* use devNull - this will be compiled away */
#endif /* DLOG_HANDLE_ECC_ROM == STD_ON                                        */
    } else {
      /* add current byte to checksum   */
      crcValueMisra = Crc_CalculateCRC32(pCurrentPosition, (uint32)DLOG_CRC_CALC_BLOCK_LENGTH, crcValueMisra, FALSE);
    }

    /* get next position from         */
    /* pCrcBlockStepArray             */
    /* The pointer arithmetic is intended here */
    /* PRQA S 0488 1*/
    pNextPosition = pCurrentPosition +
                    ((uint32)crcBlockSkipSize + DLOG_CRC_CALC_BLOCK_LENGTH);

    /* if overflow at end of address space      */
    if (pNextPosition < pCurrentPosition) {
      /* reached end                    */
      currentDataPointerOverflow = TRUE;
    }
      /* if no overflow accured                   */
    else {
      /* set next position              */
      pCurrentPosition = pNextPosition;
    }
  }

  /* trigger watchdog after CRC     */
  /* check to avoid watchdog reset  */
  Dlog_WatchdogTrigger();

  return (crcValueMisra == crcValueInRom) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK;
}

#endif /* #if (( DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON ) && ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON )) */


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/**
 * This function checks if it is safe to access
 * code/data of a SWE in ROM.
 *
 * \global Dlog_CommonLogisticBtld
 *
 * \param[in] sweId Number of SWE to check
 *
 * \retval DLOG_SWE_STATE_INVALID
 *            SWE is invalid and it's ROM area may not be accessed!
 *            This is because one of the checks failed (see REMARKS)
 * \retval DLOG_SWE_STATE_VALID_SWFL
 *            SWE is a valid application SWE
 * \retval DLOG_SWE_STATE_VALID_BTLD
 *            SWE1 is a valid BLU SWE
 * \retval DLOG_SWE_STATE_UNCHECKED
 *            SWE has not been signature checked yet
 *
 * \remark This function does the following in this order:
 *            - check ECC status (only if ECC check is enabled)
 *            - check CRC status (only if CRC check is enabled)
 *            - check valid flag of SWE in ROM
 *            - check process class of SWE in ROM
 *
 * \remark In Bootmanager additional error checks are performed:
 *            - check CRC of flash segment which contains the valid flag
 *              to ensure integrity after power failure during flashing
 *              (only if CRC check is enabled and has not been done yet)
 *            - check if an ECC error occured while accessing the SWE
 *              (only if ECC check is enabled and has not been done yet)
 * \remark In Bootloader additional checks are performed:
 *            - if valid flag is invalid check if it is blank
 */
Dlog_SweValidStateType Dlog_CheckValidStateOfSwe(uint8 sweId) {
  /* typedef needed since there is no compiler abstraction for ptr to array in autosar */
  typedef uint8 ValidFlagArrayType[DLOG_SWE_VALID_FLAG_AREA_LENGTH];

  Dlog_SweValidStateType validStateOfSwe = DLOG_SWE_STATE_INVALID;
  const ValidFlagArrayType* pSweValidFlag;
  uint16 sweValidFlag;

#if (DLOG_HANDLE_ECC_ROM == STD_ON)
  /* if no ECC error occured in this SWE      */
  if (FALSE != Dlog_GetEccErrorFlagOfSwe(sweId)) {
    return DLOG_SWE_STATE_ECC_ERROR;
  }
#endif

  pSweValidFlag = (const ValidFlagArrayType*)(&Dlog_GetFlashStatus(sweId)->SweValidFlag);

#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON)
  /* if no CRC error occured in this SWE      */
  if (Dlog_GetCrcErrorFlagOfSwe(sweId) == FALSE) {
#endif
    sweValidFlag = BUtil_Make16Bit((*pSweValidFlag)[0], (*pSweValidFlag)[1]);

    /* if valid flag of SWE is ok               */
    if (sweValidFlag == DLOG_SWE_VALID) {
      uint8 processClassOfSwe;

      /* if SWE is application SWE1               */
      if (sweId == DLOG_SWE_ID_OF_BLU_SWE) {
        /* get process class from         */
        /* preconfigured address          */
        processClassOfSwe = DLOG_DIRECT_BLU_SWE_TABLE.SgbmId[0];
      }
        /* if SWE is not application SWE1           */
      else {
        /* get process class from address */
        /* table (sharedBootROMData)      */
        processClassOfSwe = Dlog_CommonLogisticBtld.PointerToSweTable[sweId]->SgbmId[0];
      }

      /* if process class of application SWE1     */
      /* or boot SWE is 'BTLD' or BLUP            */
      if (((sweId < SWE_ID_OF_APPL_SWE1) || (sweId == DLOG_SWE_ID_OF_BLU_SWE))
          && ((processClassOfSwe == DLOG_PROCESSCLASS_BTLD)
              || (processClassOfSwe == DLOG_PROCESSCLASS_BLUP))) {
        /* found valid BL or BLU SWE      */
        validStateOfSwe = DLOG_SWE_STATE_VALID_BTLD;
      }
        /* if application SWE                       */
      else if ((sweId >= SWE_ID_OF_APPL_SWE1)) {
        /* found valid application SWE    */
        validStateOfSwe = DLOG_SWE_STATE_VALID_SWFL;
      } else {
        /* nothing to do, just to avoid MISRA violation */
      }

      /* perform additional CRC and ECC error     */
      /* checks in bootmanager only               */
#if (DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON)
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON) || (DLOG_HANDLE_ECC_ROM == STD_ON)
      /* if additional error check not done yet   */
      /* As the name "Get" suggest, this function does not have any side effects */
      if ((validStateOfSwe != DLOG_SWE_STATE_INVALID) &&
          (Swe_GetErrorCheckDoneFlagOfSwe(sweId) == FALSE)) /* PRQA S 3415 */
      {
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON)
        /* if calculated CRC value differs from CRC */
        /* value in ROM or if an ECC error occured  */
        if (E_OK != Dlog_CrcCheck(sweId)) {
          /* set CRC error flag             */
          Dlog_SetCrcErrorFlagOfSwe(sweId);

          /* return SWE is invalid          */
          validStateOfSwe = DLOG_SWE_STATE_INVALID;
        }
#endif /* DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON                                */

        /* error check done for this SWE  */
        Swe_SetErrorCheckDoneFlagOfSwe(sweId);
      }
#endif /* ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( DLOG_HANDLE_ECC_ROM == STD_ON )    */
#endif /* #if ( DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON )       */
    }
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON)
  }
#endif
#if (DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK == STD_ON)
  /* if SWE is invalid, check for blank bytes - side effect intended */
  if ((validStateOfSwe == DLOG_SWE_STATE_INVALID) &&
      (FALSE != Dlog_BlankCheck(&(*pSweValidFlag)[0], (uint8_least)DLOG_SWE_VALID_FLAG_AREA_LENGTH))) /* PRQA S 3415 */
  {
     validStateOfSwe = DLOG_SWE_STATE_UNCHECKED;
  }
#endif /* #if ( DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK == STD_ON )        */

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) && (DLOG_HANDLE_ECC_ROM == STD_ON)
#ifdef BOOTMANAGER_TEST_ENABLE
#if ( BOOTMANAGER_TEST_ENABLE == STD_ON )
  Bootmanager_Test_ECC_Input( sweId );
#endif
#endif
  Dlog_UserTriggerEccCheck(sweId);
  if (Dlog_GetEccErrorFlagOfSwe(sweId) != FALSE) {
    /* return SWE is invalid          */
    validStateOfSwe = DLOG_SWE_STATE_ECC_ERROR;
  }
#endif /* DLOG_HANDLE_ECC_ROM == STD_ON                                           */

  return validStateOfSwe;
  /* PRQA S 2006,5207 2 */
  /* PRQA S 5208 1 *//* STPTH: doesn't make sense to split up this function further */
} /* end of function 'Swe_CheckValidStateOfSwe'                                 */

/*----------------------------------------------------------------------------*/
/**
 * Returns the programming dependencies flag of the given SWE.
 *
 * \param[in] sweId Id of the SWE
 *
 * \return The programming dependencies flag
 */
/*----------------------------------------------------------------------------*/
Dlog_SweProgDepStateType Dlog_GetProgDepStateOfSwe(uint8 sweId) {
  return (Dlog_SweProgDepStateType)Dlog_GetFlashStatus(sweId)->ProgDepFlag[DLOG_PROG_DEP_OFS_FLAG];
}

/**
 * Returns the programming dependencies flag of the given SWE.
 *
 * \param[in]  sweId   Id of the SWE
 * \param[out] counter Counter of the Programming dependencies flag
 *
 * \return The programming dependencies flag
 */
Dlog_SweProgDepStateType Dlog_GetCheckedProgDepStateOfSwe(
    uint8 sweId,
    uint32* counter,
    uint8* fingerprint,
    uint8* progId) {
  /* typedef needed since there is no compiler abstraction for ptr to array in autosar */
  typedef uint8 ProgDepFlagArrayType[DLOG_PROG_DEP_AREA_LENGTH];

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) && (DLOG_HANDLE_ECC_ROM == STD_ON)
  Dlog_SweStatusType savedSweStatus;
#endif
  Dlog_SweProgDepStateType progDepState = DLOG_PROG_DEP_INVALID;

  /* get pointer to prog dep flag   */
  /* of this SWE                    */
  const ProgDepFlagArrayType* const pProgDepFlag = &Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->ProgDepFlag;

  /* calc number of blank bytes     */
  /* of prog dep flag of this SWE   */
  uint8_least numberOfBlankBytes = 0u;

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) && (DLOG_HANDLE_ECC_ROM == STD_ON)
  savedSweStatus = Dlog_SweStatus;
#endif

  while ((numberOfBlankBytes < (uint8_least)DLOG_PROG_DEP_AREA_LENGTH) &&
         ((*pProgDepFlag)[numberOfBlankBytes] == (uint8)FLASH_ERASED_BYTE)
      ) {
    ++numberOfBlankBytes;
  }

  /* if all bytes of prog dep flag are blank  */
  if (numberOfBlankBytes == (uint8_least)DLOG_PROG_DEP_AREA_LENGTH) {
    /* return prog dep not checked yet*/
    progDepState = DLOG_PROG_DEP_UNCHECKED_APPL;
    *counter = 0xffffffffuL;
  }
    /* if prog dep flag has been written before */
  else {
    /* get value of prog dep flag     */
    /* PRQA S 1482 1 */ /* Reason: we have written a Dlog_SweProgDepStateType into this uint8 before */
    progDepState = (Dlog_SweProgDepStateType)((*pProgDepFlag)[DLOG_PROG_DEP_OFS_FLAG]);

    /* get counter of prog dep flag   */
    *counter = BUtil_Make32Bit((*pProgDepFlag)[DLOG_PROG_DEP_OFS_COUNTER + 0],
                               (*pProgDepFlag)[DLOG_PROG_DEP_OFS_COUNTER + 1],
                               (*pProgDepFlag)[DLOG_PROG_DEP_OFS_COUNTER + 2],
                               (*pProgDepFlag)[DLOG_PROG_DEP_OFS_COUNTER + 3]);

    (void)memcpy(fingerprint, &((*pProgDepFlag)[DLOG_PROG_DEP_OFS_FINGERPRINT]), DLOG_FINGERPRINTLENGTH);
    (void)memcpy(progId, &((*pProgDepFlag)[DLOG_PROG_DEP_OFS_PROGID]), DLOG_PROG_ID_LENGTH);
  }

#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) && (DLOG_HANDLE_ECC_ROM == STD_ON)
  Dlog_UserTriggerEccCheck(sweId);
  /* if an ECC error occured while reading    */
  /* the prog dep flag from ROM               */
  if (Dlog_GetEccErrorFlagOfSwe(sweId) != FALSE) {
    /* return invalid SWE found       */
    progDepState = DLOG_PROG_DEP_ECC_ERROR;
    *counter = 0xffffffffuL;
  }
  /* restore saved swe status */
  Dlog_SweStatus = savedSweStatus;
#endif

  return progDepState;
}

/**
 * This function checks if the programming dependencies of
 * all application SWEs are correct.
 *
 * \global Dlog_CommonLogisticBtld
 *
 * \param[out] fingerprint the fingerprint of the prog dep flag
 * \param[out] progId      the progId of the prog dep flag
 *
 * \retval DLOG_PROG_DEP_UNCHECKED_APPL
 *            Programming dependencies of application SWEs
 *            have not been checked after reprogramming
 * \retval DLOG_PROG_DEP_CONSISTENT_APPL
 *            All application SWEs belong to each other
 * \retval DLOG_PROG_DEP_INCONSISTENT_APPL
 *            One or more application SWEs do not belong to each other
 * \retval DLOG_PROG_DEP_WRONG_APPL
 *            The application SWEs do not belong to the HWE
 * \retval DLOG_PROG_DEP_VALID_BLU
 *            A valid BLU was found
 * \retval DLOG_PROG_DEP_INVALID
 *            One or more SWEs are invalid and may not be accessed!
 *
 * \remark fingerprint and progId have valid values only in case DLOG_PROG_DEP_CONSISTENT_APPL is returned
 *
 */
Dlog_SweProgDepStateType Dlog_GetProgDepStateOfApplSwes(uint8* fingerprint, uint8* progId) {
  Dlog_SweProgDepStateType progDepStateOfApplSwes = DLOG_PROG_DEP_INVALID;

  /* get valid state of appl SWEs   */
  Dlog_SweValidStateType validStateOfApplSwes = Dlog_GetValidState();

  /* if valid BLU was found                   */
  if (validStateOfApplSwes == DLOG_SWE_STATE_VALID_BTLD) {
    /* return valid BLU found -> consistent         */
    return DLOG_PROG_DEP_CONSISTENT_APPL;
  }
  /* if valid application was found           */
  if (validStateOfApplSwes == DLOG_SWE_STATE_VALID_SWFL) {
    uint8_least sweId = (uint8_least)SWE_ID_OF_APPL_SWE1;

    /* used to save prog dep value of */
    /* SWE with max prog dep counter  */
    uint32 progDepCounterMax = 0uL;
    Dlog_SweProgDepStateType progDepValueMax = DLOG_PROG_DEP_UNCHECKED_APPL;
    uint8 tmpFingerprint[DLOG_FINGERPRINTLENGTH];
    uint8 tmpProgId[DLOG_PROG_ID_LENGTH];

    /* initiate search for prog deps  */
    progDepStateOfApplSwes = DLOG_PROG_DEP_CONSISTENT_APPL;

    /* iterate all application SWEs             */
    do {
      uint32 progDepCounter;
      const Dlog_SweProgDepStateType progDepValue = Dlog_GetCheckedProgDepStateOfSwe((uint8)sweId, &progDepCounter,
                                                                                     tmpFingerprint, tmpProgId);

      /* if SWE has the highest prog dep counter  */
      if (progDepCounter > progDepCounterMax) {
        /* remember prog dep value        */
        progDepValueMax = progDepValue;

        (void)memcpy(fingerprint, tmpFingerprint, sizeof(tmpFingerprint));
        (void)memcpy(progId, tmpProgId, sizeof(tmpProgId));

        /* remember prog dep counter      */
        progDepCounterMax = progDepCounter;
      }

      if (0xffffffffuL == progDepCounter) {
        progDepStateOfApplSwes = progDepValue;
      }
      ++sweId;
    } while ((progDepStateOfApplSwes == DLOG_PROG_DEP_CONSISTENT_APPL) &&
             (sweId <= (uint8_least)DLOG_NUMBEROFAPPLSWESGBMIDS));

    /* if all prog dep flags could be read      */
    if (progDepStateOfApplSwes == DLOG_PROG_DEP_CONSISTENT_APPL) {
      /* return prog dep value of SWE   */
      /* with highest prog dep counter  */
      progDepStateOfApplSwes = (Dlog_SweProgDepStateType)progDepValueMax;
    }
  } else {
    /* nothing to do, just to avoid MISRA violation */
  }

  return progDepStateOfApplSwes;
  /* PRQA S 2006,5207 1 */
} /* end of function 'Dlog_GetProgDepStateOfApplSwes'                          */


/*----------------------------------------------------------------------------*/
/**
 * This function returns the flash segment that contains
 * the valid flag
 *
 * \global Dlog_CommonLogisticBtld
 *
 * \param[in]  sweId               Number of SWE to search
 * \param[out] segmentStartAddress Start address of the flash segment
 * \param[out] segmentEndAddress   End address of the flash segment
 *
 * \pre A bootloader is present.
 */
/*----------------------------------------------------------------------------*/
#if (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON) || (DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON)
#if (DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON) || (DLOG_HANDLE_ECC_ROM == STD_ON)

void Dlog_GetAddressOfFlashSegmentContainingValidFlag
    (
        uint8 sweId,
        size_t* segmentStartAddress,
        size_t* segmentEndAddress
    ) {
  /* get valid flag address of SWE  */
  /* We are using a platform specific macro here, so it should be save */
  /* PRQA S 0306 1*/
  const size_t sweValidFlagAddress = Dlog_ConvertIntPointer2ExtAddress
  (Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->SweValidFlag);

  /* iterate all flash segments of SWE        */
  uint16 flashSegmentId;
  size_t segmentLength;

  boolean flashSegmentFound = (E_OK == Dlog_GetMemorySegmentForAddress(
      sweValidFlagAddress,
      segmentStartAddress,
      &segmentLength,
      &flashSegmentId));

  if (TRUE == flashSegmentFound) {
    *segmentEndAddress = (*segmentStartAddress + segmentLength) - 1u;
  }

}

#endif /* ( DLOG_VERIFY_SWE_CRC_CHKSUM == STD_ON ) || ( DLOG_HANDLE_ECC_ROM == STD_ON )    */
#endif /* (DLOG_HANDLE_ECC_SWE_ERRORS == STD_ON ) || ( DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK == STD_ON ) */


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if (DLOG_ENABLE_SWE_GET == STD_ON) */
