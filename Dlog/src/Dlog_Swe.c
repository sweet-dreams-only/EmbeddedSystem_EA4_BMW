/**
 * \file
 *
 * \brief       Read SWE related data.
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

#include "Dlog_Swe.h"          /* module own header file                      */

#if ( DLOG_ENABLE_SWE_GET == STD_ON )
#include "Dlog_SweGet.h"      /* Contains SWE access functions               */
#endif

#include "Dlog_Memory.h"
#include "Dlog_SvkGen.h"         /* Contains DLOG_SVK_VERSION                   */
#include "Dlog_HweTable.h"

#if ( DLOG_ENABLE_ECU == STD_ON )
#include "Dlog_User.h"
#endif
#include "Dlog_SweGen.h"

#include "BUtil_ByteMask.h"

#if (DLOG_ENABLE_RTE == STD_ON)
#include <Rte_Dlog.h>
#else
#include "Dlog_Rte2C.h"
#endif

#include <string.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 14.7. Reason: early return in case of errors makes code more readable,
   see PRQA: 2006, 5207 */

/* Violation of MISRA rule 17.4. Reason: RTE uses pointers for arrays, see PRQA: 0492 */

/* Violation of MISRA rule 19.1. Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Swe.c does not match the version of the module!"
#endif

/* check SWE configuration                                                    */
#if ( (((DLOG_NUMBEROFBOOTSWESGBMIDS)+(DLOG_NUMBEROFAPPLSWESGBMIDS)) != (DLOG_NUMBEROFALLSWESGBMIDS)) ||  \
      ((DLOG_NUMBEROFALLSWESGBMIDS)  > 0xFEu)                                           \
    )
   #error "Dlog_Swe.c: 'SWENUMBEROFALLSWE' must not exceed 254"
#endif

#if (DLOG_FINGERPRINTLENGTH != 4u)
   #error "Dlog_Swe.c: adapt initialization of 'Fingerprint' data"
#endif


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Dlog_START_SEC_CONST_SHARED_SWE_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

const Dlog_CommonLogisticBtldType Dlog_CommonLogisticBtld = {
    /*
     * Sizeof this struct:
     * Used by the BLU to check, if the SWE configuration has changed
     */
    (uint16)sizeof(Dlog_CommonLogisticBtldType),

    (uint8)DLOG_SVK_VERSION,
    /*
     * Store number of Bootloaders and Applications for the BootManager:
     */
    (uint8)DLOG_NUMBEROFBOOTSWESGBMIDS,
    (uint8)DLOG_NUMBEROFALLSWESGBMIDS,
    /*
     * 'PointerToSweFlashStatus' must be the first member in the struct (after
     * the NumberOf's) because it is direct accessed by the BootManager. This
     * means, that it's possition in ROM can not be dependent to the numer of
     * SWEs
     */
    DLOG_PTR_TO_SWE_FLASH_STATUS,
    DLOG_PTR_TO_SWE_TABLE,
    DLOG_PTR_TO_SWE_SIGNATURE,
    DLOG_SWE_TO_GROUP_MAP,
    DLOG_SIG_ADR_TABLE,
    /* ^ MISRA violation: Rule 45 cast from integer to pointer is necessary */
    /* to initialize 'SignatureSweDataPtr' with correct addresses           */
    DLOG_SIG_LEN_TABLE,
    DLOG_SWE_SIGNATURE_TABLE,

    DLOG_SWE_BLOCK_INDEX_TABLE,
    DLOG_SWE_BLOCK_LEN_TABLE,
    DLOG_SWE_BLOCK_TABLE,

    DLOG_SWE_GROUP_TABLE,

    /* timing parameters */
    {
        /* Erase Memory Time                                                    */
        BUtil_GetHiByte(DLOG_ERASEMEMORYTIME),
        BUtil_GetLoByte(DLOG_ERASEMEMORYTIME),
        /* Check Memory Time                                                    */
        BUtil_GetHiByte(DLOG_CHECKMEMORYTIME),
        BUtil_GetLoByte(DLOG_CHECKMEMORYTIME),
        /* Bootloader Installation Time                                         */
        BUtil_GetHiByte(DLOG_BOOTLOADERINSTALLATIONTIME),
        BUtil_GetLoByte(DLOG_BOOTLOADERINSTALLATIONTIME),
        /* Authentification Time                                                */
        BUtil_GetHiByte(DLOG_AUTHENTIFICATIONTIME),
        BUtil_GetLoByte(DLOG_AUTHENTIFICATIONTIME),
        /* Reset Time                                                           */
        BUtil_GetHiByte(DLOG_RESETTIME),
        BUtil_GetLoByte(DLOG_RESETTIME),
        /* Transfer Data Time                                                   */
        BUtil_GetHiByte(DLOG_TRANSFERDATATIME),
        BUtil_GetLoByte(DLOG_TRANSFERDATATIME)
    },
    /* initial fingerprint                                                     */
    {
        DLOG_FINGERPRINT_INITIAL
    },

    (uint16)DLOG_CRC_CALC_BLOCK_SKIP_SIZE,
    (uint8)DLOG_SIGNATURE_LENGTH,
};

/* Define end of the shared ROM section                                       */
#define Dlog_STOP_SEC_CONST_SHARED_SWE_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if ( DLOG_ENABLE_ECU == STD_ON )

/**
 * Check which application SWE corresponds to a given LogicalBlockNumber.
 *
 * \global \link #Dlog_CommonLogisticBtld Dlog_CommonLogisticBtld.PointerToSweTable \endlink
 *
 * \param[in]  LogicalBlockNumber The logical block number
 * \param[out] pApplSWENumber     The corresponding application SWE
 *
 * \retval E_OK     A corresponding application SWE was found
 * \retval E_NOT_OK The given LogicalBlockNumber doesn't correspond to an
 *                  application SWE
 */
Std_ReturnType Dlog_GetApplSWENumberByLogicalBlockNumber(
    uint32 const LogicalBlockNumber,
    uint8* const pApplSWENumber) {
  Std_ReturnType addressOk = E_NOT_OK;
  uint8_least iLoop = (uint8_least)SWE_ID_OF_APPL_SWE1;

  do {
    /* We are using a platform specific macro here, so it should be save */
    /* PRQA S 0306 1*/
    const uint32 tmpLogicalBlockNumber = Dlog_ConvertIntPointer2ExtAddress(
        Dlog_CommonLogisticBtld.PointerToSweTable[iLoop]);

    if (LogicalBlockNumber == tmpLogicalBlockNumber) {
      /*
       * valid application SWE found
       */
      *pApplSWENumber = (uint8)iLoop;
      addressOk = E_OK;
    } else {
      ++iLoop;
    }
  } while ((addressOk != E_OK) &&
           (iLoop < (uint8_least)DLOG_NUMBEROFALLSWESGBMIDS)
      );

  return addressOk;
}

/**
 * Check which application SWE corresponds to a given flash segment.
 *
 * \global #Dlog_CommonLogisticBtld
 *
 * \param[in]  FlashSegmentNumber Number of flash segment
 * \param[out] pApplSWENumber     The corresponding application SWE
 *
 * \retval E_OK     A corresponding application SWE was found
 * \retval E_NOT_OK The given flash segment number doesn't correspond to an
 *                  application SWE
 */
Std_ReturnType Dlog_GetApplSWENumberByFlashSegmentNumber(
    uint16 FlashSegmentNumber,
    uint8* const pApplSWENumber) {
  uint8_least applSweIndex;
  Std_ReturnType RetVal = E_NOT_OK;

  for (applSweIndex = 0; applSweIndex < (uint8_least)DLOG_NUMBEROFAPPLSWESGBMIDS; ++applSweIndex) {
    const uint8 firstBlock = Dlog_CommonLogisticBtld.SweBlockTable[applSweIndex];
    const uint8 lastBlock  = Dlog_CommonLogisticBtld.SweBlockTable[applSweIndex + 1];
    uint8 block;

    for (block = firstBlock; block < lastBlock; ++block) {
      /*
       * Keeps the number of the first flash segment of the current SWE
       */
      const uint16 firstFlashSegmentOfSWEBlock =
          (Dlog_CommonLogisticBtld.SweBlockSegmentIndex[block]
          );
      /*
       * Keeps the number of the last flash segment of the current SWE
       */
      const uint16 lastFlashSegmentOfSWEBlock =
          ((firstFlashSegmentOfSWEBlock +
            Dlog_CommonLogisticBtld.SweBlockNumberOfSegments[block]) -
           (uint8)1u
          );
      /*
       * check if the given flash segment is inbetween this SWE
       */
      if ((FlashSegmentNumber >= firstFlashSegmentOfSWEBlock) &&
          (FlashSegmentNumber <= lastFlashSegmentOfSWEBlock)
          ) {
        *pApplSWENumber = (uint8)applSweIndex + Dlog_CommonLogisticBtld.NumberOfBootSWEs;
        return E_OK;
      }
    }
  }

  return RetVal;
  /* PRQA S 2006,5207 1 */
} /* end of function Dlog_GetApplSWENumberByFlashSegmentNumber */

/**
 * Returns the SgbmId of an Swe
 *
 * \param[in]  SweId   The SweId of the Swe
 * \param[out] SgbmId  The SdbmId of the Swe
 *
 * \return Always E_OK
 *
 * \pre SweId < DLOG_NUMBEROFALLSWESGBMIDS
 *
 */
Std_ReturnType Dlog_GetSgbmId(uint8 SweId, uint8* SgbmId) {
  /* return value of memcpy ist not needed */
  (void)memcpy(SgbmId,
               Dlog_CommonLogisticBtld.PointerToSweTable[SweId]->SgbmId,
               sizeof(Dlog_CommonLogisticBtld.PointerToSweTable[SweId]->SgbmId));
  return E_OK;
}

#if (DLOG_SWFK_DELSUP_AVAILABLE == STD_ON)

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) -
 * DIAG_DID_2507_SWFK_DELETE_SUPPORTED
 * SWFK delete supported
 *
 * \param[out] Data SWFK delete supported:
 *                  - 0 = SWFK delete not supported
 *                  - 1 = SWFK delete supported
 *
 * \return Always E_OK
 *
 * \swsid SWS_Dlog_0536
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierSwfkDeleteSupported(
   uint8* Data)
{
   *Data = DLOG_SWFK_DELETE_SUPPORTED;
   return E_OK;
}

#endif

/**
 * Returns the number of SWEs
 *
 * \param[out] numSwe Number of SWEs
 *
 * \return Always E_OK
 */
Std_ReturnType Dlog_SweGetNumSwe(uint8* numSwe) {
  *numSwe = Dlog_CommonLogisticBtld.NumberOfAllSWEs;
  return E_OK;
}

/**
 * Returns the number of signature blocks for the SWE
 *
 * \param[in]  sweId  Id of the SWE to look for
 * \param[out] numSig Number of signature blocks
 *
 * \return Always E_OK
 *
 * \pre sweId < Dlog_CommonLogisticBtld.NumberOfAllSWEs
 */
Std_ReturnType Dlog_SweGetNumSig(uint8 sweId, uint8* numSig) {
  *numSig = Dlog_CommonLogisticBtld.SignatureTable[sweId + 1] - Dlog_CommonLogisticBtld.SignatureTable[sweId];
  return E_OK;
}

/**
 * Returns the start address of the given SWE signature block
 */
Std_ReturnType Dlog_SweGetSigStart(uint8 sweId, uint8 blkNum, uint32* address) {
  *address = Dlog_CommonLogisticBtld.SignatureSweDataPtr[Dlog_CommonLogisticBtld.SignatureTable[sweId] + blkNum];
  return E_OK;
}

/**
 * Returns the length of the given SWE signature block
 */
Std_ReturnType Dlog_SweGetSigLength(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, Dlog_APPL_DATA) length) {
  *length = Dlog_CommonLogisticBtld.SignatureSweDataLength[Dlog_CommonLogisticBtld.SignatureTable[sweId] + blkNum];
  return E_OK;
}

#if (DLOG_ENABLE_RTE == STD_ON)

/**
 * Returns the signature of the SWE
 *
 * \param[in]  sweId     Id of the SWE to look for
 * \param[out] signature signature of the SWE
 *
 * \return Always E_OK
 */
Std_ReturnType Dlog_SweGetSignatureRte(uint8 sweId, uint8* signature) {
  (void)memcpy(signature, Dlog_CommonLogisticBtld.PointerToSweSignature[sweId], DLOG_SIGNATURE_LENGTH);
  return E_OK;
}

#else /* #if (DLOG_ENABLE_RTE == STD_ON) */

/**
 * Returns a pointer to the signature of the SWE
 *
 * \param[in]  sweId     Id of the SWE to look for
 * \param[out] signature Pointer to the signature of the SWE
 *
 * \return Always E_OK
 */
Std_ReturnType Dlog_SweGetSignature(uint8 sweId, const uint8** signature) {
  *signature = Dlog_CommonLogisticBtld.PointerToSweSignature[sweId];
  return E_OK;
}

#endif /* #if (DLOG_ENABLE_RTE == STD_ON) */

#if (DLOG_ENABLE_SWE_GET == STD_ON)

/**
 * Returns the group info of an SWE.
 *
 * \param[in]  sweId     Id of the SWE to look for
 * \param[out] groupId   Id of the group
 * \param[out] groupType Type of the group, will be one of
 *                       DLOG_SWEGROUP_ALLOBLIGATORY,
 *                       DLOG_SWEGROUP_ONEOBLIGATORY,
 *                       DLOG_SWEGROUP_OPTIONAL.
 *
 * \return Always E_OK
 *
 * \pre sweId < Dlog_CommonLogisticBtld.NumberOfAllSWEs
 *
 */
Std_ReturnType Dlog_SweGetGroupInfo
    (
        uint8 sweId,
        uint8* groupId,
        uint8* groupType
    ) {
  *groupId = Dlog_CommonLogisticBtld.SweToGroupMap[sweId];
  *groupType = Dlog_CommonLogisticBtld.SweGroupTable[*groupId];
  return E_OK;
}

/**
 * Returns the number of memory blocks for the SWE
 *
 * \param[in]  sweId  Id of the SWE to look for
 * \param[out] numMem Number of memory blocks
 *
 * \return Always E_OK
 *
 * \pre Dlog_CommonLogisticBtld.NumberOfBootSWEs <= sweId < Dlog_CommonLogisticBtld.NumberOfAllSWEs
 */
Std_ReturnType Dlog_SweGetNumMem(uint8 sweId, uint8* numMem) {
  const uint8 applSweId = sweId - Dlog_CommonLogisticBtld.NumberOfBootSWEs;
  *numMem = Dlog_CommonLogisticBtld.SweBlockTable[applSweId + 1] - Dlog_CommonLogisticBtld.SweBlockTable[applSweId];
  return E_OK;
}

/**
 * Get the memory segments for an SWE memory block
 *
 * \param[in]  sweId            Id of the SWE to look for
 * \param[in]  blkNum           Block number to look for
 * \param[out] memSegIndexStart Index of the first memory segment of this block
 * \param[out] numMemSegs       Number of consecutive memory segments in this block
 *
 * \return Always E_OK
 *
 * \pre Dlog_CommonLogisticBtld.NumberOfBootSWEs <= sweId < Dlog_CommonLogisticBtld.NumberOfAllSWEs
 */
Std_ReturnType Dlog_SweGetBlkMemSegs
    (
        uint8 sweId,
        uint8 blkNum,
        uint16* const memSegIndexStart,
        uint16* const numMemSegs
    ) {
  const uint8 applSweId = sweId - Dlog_CommonLogisticBtld.NumberOfBootSWEs;

  *memSegIndexStart = Dlog_CommonLogisticBtld.SweBlockSegmentIndex[
      Dlog_CommonLogisticBtld.SweBlockTable[applSweId] + blkNum
  ];
  *numMemSegs = Dlog_CommonLogisticBtld.SweBlockNumberOfSegments[
      Dlog_CommonLogisticBtld.SweBlockTable[applSweId] + blkNum
  ];
  return E_OK;
}

/**
 * Get the memory segment of the Valid Flags of an SWE
 *
 * \param[in]  sweId                 Id of the SWE
 * \param[out] memSegIndexValidFlags The index of the memory segment containing the valid flags
 *
 * \retval E_OK     Everything is ok
 * \retval E_NOT_OK Invalid SWE Id or other error
 */
Std_ReturnType Dlog_SweGetMemSegValidFlags
    (
        uint8 sweId,
        uint16* const memSegIndexValidFlags
    ) {
  size_t address;
  size_t size;

  return Dlog_GetMemorySegmentForAddress(
      /* We are using a platform specific macro here, so it should be save */
      /* PRQA S 0306 1*/
      Dlog_ConvertIntPointer2ExtAddress(
          &Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->SweValidFlag
      ),
      &address,
      &size,
      memSegIndexValidFlags
  );
}

#endif /* #if (DLOG_ENABLE_SWE_GET == STD_ON) */

#endif /*#if ( DLOG_ENABLE_ECU == STD_ON )*/

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
