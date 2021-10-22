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

#ifndef DLOG_SWE_H
#define DLOG_SWE_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <Std_Types.h>                      /* AUTOSAR Standard Types         */

#include "DlogClassic_Cfg.h"                  /* module configuration         */

#if ( DLOG_ENABLE_ECU == STD_ON )
#if ( DLOG_ENABLE_RTE == STD_ON )
#include <Rte_Dlog_Type.h>
#else
#include "Dcm_Types.h"                    /* DCM Api                                */
#endif
#endif

#include "Dlog_SweTable.h"


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */

/* Violation of MISRA rule 19.7, Reason: C90 does not support inline
 * functions, see PRQA 3453
 */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Swe.h does not match the version of the module!"
#endif

#define SWE_ID_OF_BOOT_SWE    0u
#define SWE_ID_OF_APPL_SWE1   DLOG_NUMBEROFBOOTSWESGBMIDS

#define DLOG_TIMINGPARAMETERLENGTH 12u /**< length of the 'TimingParameters' array */

/*----------------------------------------------------------------------------*/
/**
 * Returns a pointer to the valid flag of the SWE
 *
 * \param[in] sweId Id of the SWE to look for
 *
 * \return Pointer to the valid flag of the SWE
 */
/*----------------------------------------------------------------------------*/
#define Dlog_SweGetValidFlagAddress(sweId) ((const uint8*)Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->SweValidFlag) /* PRQA S 3453 */

/*----------------------------------------------------------------------------*/
/**
 * Returns a pointer to the programming dependency flag of the SWE
 *
 * \param[in] sweId Id of the SWE to look for
 *
 * \return Pointer to the programming dependency flag of the SWE
 */
/*----------------------------------------------------------------------------*/
#define Dlog_SweGetProgDepFlagAddress(sweId) ((const uint8*)Dlog_CommonLogisticBtld.PointerToSweFlashStatus[sweId]->ProgDepFlag) /* PRQA S 3453 */


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/** This structure is used for data that is common for BootManager, Bootloader and Application. */
typedef struct
{
  /**
   * Sizeof this struct:
   * Used by the BLU to check, if the SWE configuration has changed
   */
  uint16                                  SizeOfStruct;

  uint8                                   SvkVersion;
  /**
   * Store number of Bootloaders and Applications for the BootManager:
   */
  uint8                                   NumberOfBootSWEs;
  uint8                                   NumberOfAllSWEs;
  /**
   * 'PointerToSweFlashStatus' must be the first member in the struct (after
   * the NumberOf's) because it is direct accessed by the BootManager. This
   * means, that it's position in ROM can not be dependent to the number of
   * SWEs
   */
  const Dlog_SweFlashStatusType* const    PointerToSweFlashStatus[DLOG_NUMBEROFALLSWESGBMIDS];
  const Dlog_SweHeaderType* const         PointerToSweTable[DLOG_NUMBEROFALLSWESGBMIDS];
  const uint8* const                      PointerToSweSignature[DLOG_NUMBEROFALLSWESGBMIDS];
  uint8                                   SweToGroupMap[DLOG_NUMBEROFALLSWESGBMIDS];

  uint32                                  SignatureSweDataPtr[DLOG_SIG_TABLE_SIZE];
  uint32                                  SignatureSweDataLength[DLOG_SIG_TABLE_SIZE];
  uint8                                   SignatureTable[DLOG_NUMBEROFALLSWESGBMIDS+1];

  /**
   * Start indices of the SWE memory segments
   */
  uint16                                  SweBlockSegmentIndex[DLOG_SWE_BLOCK_TABLE_SIZE];
  /**
   * Numbers of consecutive memory segments
   */
  uint16                                  SweBlockNumberOfSegments[DLOG_SWE_BLOCK_TABLE_SIZE];
  /**
   * Indices into SweBlockSegmentIndex and SweBlockNumberOfSegments
   */
  uint8                                   SweBlockTable[DLOG_NUMBEROFAPPLSWESGBMIDS+1];

  /**
   * Describes the SWE groups
   */
  uint8                                   SweGroupTable[DLOG_NUMBEROFSWEGROUPS];

  uint8                                   TimingParameters[DLOG_TIMINGPARAMETERLENGTH];

  /** initial fingerprint                                                     */
  uint8                                   FINGERPRINT_INIT_VAL[DLOG_FINGERPRINTLENGTH];

  /**
   * CRC check configuration used by BootManager
   */
  uint16                                  CrcBlockSkipSize;
  uint8                                   SignatureSize;   /*used by Dlog_SweGet */
} Dlog_CommonLogisticBtldType;


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Dlog_START_SEC_CONST_SHARED_SWE_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern const Dlog_CommonLogisticBtldType Dlog_CommonLogisticBtld;

/* Define end of the shared ROM section                                       */
#define Dlog_STOP_SEC_CONST_SHARED_SWE_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if ( DLOG_ENABLE_ECU == STD_ON )

extern Std_ReturnType Dlog_GetApplSWENumberByLogicalBlockNumber
       (
          uint32 const LogicalBlockNumber,
          uint8* const pApplSWENumber
       );

extern Std_ReturnType Dlog_GetApplSWENumberByFlashSegmentNumber
       (
          uint16       FlashSegmentNumber,
          uint8* const pApplSWENumber
       );

extern Std_ReturnType Dlog_GetSgbmId(uint8 SweId, uint8* SgbmId);

#if ( DLOG_ENABLE_RTE != STD_ON )

#if (DLOG_SWFK_DELSUP_AVAILABLE == STD_ON)
extern Std_ReturnType Dlog_ReadDataByIdentifierSwfkDeleteSupported
       (
          uint8* Data
       );
#endif

#endif /* #if ( DLOG_ENABLE_RTE != STD_ON ) */

#ifdef BOOTLOADER

extern Std_ReturnType Dlog_SetProgDepFlag
      (
         uint8 SweIndex,
         Dlog_SweProgDepStateType DependencyFlag
      );

extern FUNC(uint16, Dlog_CODE) Dlog_GetProgDepCounter
      (
         uint8 SweIndex
      );

extern Std_ReturnType Dlog_SetProgDepCounter
      (
         uint8 SweIndex,
         uint16 DependencyCounter
      );

#endif /* #ifdef BOOTLOADER */

#if ( DLOG_ENABLE_RTE != STD_ON )

extern Std_ReturnType Dlog_SweGetNumSwe(uint8* numSwe);
extern Std_ReturnType Dlog_SweGetNumSig(uint8 sweId, uint8* numSig);
extern Std_ReturnType Dlog_SweGetSigStart(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, Dlog_APPL_DATA) address);
extern Std_ReturnType Dlog_SweGetSigLength(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, Dlog_APPL_DATA) length);

extern Std_ReturnType Dlog_SweGetSignature(uint8 sweId, const uint8** signature);

#endif /* #if ( DLOG_ENABLE_RTE != STD_ON ) */

#if (DLOG_ENABLE_SWE_GET == STD_ON)
extern Std_ReturnType Dlog_SweGetGroupInfo
   (
      uint8 sweId,
      uint8* groupId,
      uint8* groupType
   );

extern Std_ReturnType Dlog_SweGetNumMem(uint8 sweId, uint8* numMem);

extern Std_ReturnType Dlog_SweGetBlkMemSegs
   (
      uint8 sweId,
      uint8 blkNum,
      uint16* const memSegIndexStart,
      uint16* const numMemSegs
   );

extern Std_ReturnType Dlog_SweGetMemSegValidFlags
       (
           uint8 sweId,
           uint16* const memSegIndexValidFlags
       );
#endif /* #if (DLOG_ENABLE_SWE_GET == STD_ON) */

#endif /* #if ( DLOG_ENABLE_ECU == STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif  /* DLOG_SWE_H                                                       */
