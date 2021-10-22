/**
 * \file
 *
 * \brief       Access memory segmentation table.
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
------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
#include "Dlog_Memory.h"       /* module own header file                      */
/* -------------------------------------------------------------------------- */
#include "Dlog_Swe.h"          /* contains CommonLogisticBtld                 */
/* -------------------------------------------------------------------------- */
#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )
#if (DLOG_ENABLE_MULTI_CPU == STD_ON)
#include "Dlog_User.h"
#endif
#include "BUtil_ByteMask.h"
#endif

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 12.13 and 17.4. Reason: Standard way of writing to a buffer,
   see PRQA: 0489, 3440 */

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
   #error "Version of Dlog_Memory.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/**
 * Type definition for the memory segmentation table
 */
typedef struct {
  uint32 StartAddress[DLOG_MEMSEGTABLE_NUM_ENTRIES];
  uint32 SegmentSize[DLOG_MEMSEGTABLE_NUM_ENTRIES];
  uint16 NumberOfSegments[DLOG_MEMSEGTABLE_NUM_ENTRIES];
} Dlog_MemSegTableType;


/*------------------------------------------------------------------------------
                      Local Variables
-------------------------------------------------------------------------------*/

#if (DLOG_ENABLE_MULTI_CPU == STD_ON && DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON)

#define Dlog_START_SEC_VAR_CLEARED_16
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

static uint16 Dlog_NumberOfUserMemSegTableEntries = 0;

#define Dlog_STOP_SEC_VAR_CLEARED_16
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /*#if (DLOG_ENABLE_MULTI_CPU == STD_ON && DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON)*/


/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/* Define beginning of the shared ROM section                                 */
#define Dlog_START_SEC_CONST_SHARED_MEMSEGTBL_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/**
 * The memory segmentation table
 */
static const Dlog_MemSegTableType Dlog_MemSegTable = /* PRQA S 3218 *//* needed here for memory mapping */
      {
            DLOG_MEMSEGTABLE_START_ADDRESSES,
            DLOG_MEMSEGTABLE_SIZES,
            DLOG_MEMSEGTABLE_NUMBERS_OF_SEGMENTS
      };

/* Define end of the shared ROM section                                       */
#define Dlog_STOP_SEC_CONST_SHARED_MEMSEGTBL_DATA
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Calculate the number of elements, that will occur in the
 * MemorySegmentationTable after run length encoding.
 *
 * \return The number of elements in the MemorySegmentationTable
 *
 * \remark The result is stored static, for further use
 *
 */
/*----------------------------------------------------------------------------*/
uint8 Dlog_GetNumberOfElementsInReadMemorySegmentationTable(void) {
  return DLOG_MEMSEGTABLE_NUM_ENTRIES;
} /* end of function 'GetNumberOfElementsInReadMemorySegmentationTable'       */


#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )

/*----------------------------------------------------------------------------*/
/**
 * Contains the condition check functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE
 * Read memory segmentation table.
 *
 * \param[in]  OpStatus    See Dcm specification \cite SWS-DiagnosticCommunicationManager.
 * \param[out] ErrorCode   Contains the error code in case E_NOT_OK is returned
 *
 * \retval E_OK      Conditions satisfied
 * \retval E_NOT_OK  Conditions not satisfied
 * \retval E_PENDING Not yet finished
 *
 * \swsid SWS_Dlog_0502
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ConditionCheckMemorySegmentationTable(
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode /* PRQA S 3673 */
    /* defined by AUTOSAR */
) {
   Std_ReturnType ret = E_OK;
#if (DLOG_ENABLE_MULTI_CPU == STD_ON)
   ret = Dlog_UserNumberOfMemorySegmentationTableEntries(OpStatus, &Dlog_NumberOfUserMemSegTableEntries);
   if (E_NOT_OK == ret)
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
#else
   /* MISRA-C:2004 Rule 14.2: parameter needed by Autosar */
   /* PRQA S 3112 2 */
   (void)OpStatus;
   (void)ErrorCode;
#endif
   return ret;
}

/*----------------------------------------------------------------------------*/
/**
 * Contains the read data length functionality for job 'Read memory segmentation table'
 *
 * \param[in]  OpStatus   See Dcm specification \cite SWS-DiagnosticCommunicationManager.
 * \param[out] DataLength data length
 *
 * \return Always E_OK
 *
 * \swsid SWS_Dlog_0535
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataLengthMemorySegmentationTable(Dcm_OpStatusType OpStatus, uint16* DataLength) {
   /* MISRA-C:2004 Rule 14.2: parameter needed by Autosar */
   /* PRQA S 3112 1 */
   (void)OpStatus;
   *DataLength = (Dlog_GetNumberOfElementsInReadMemorySegmentationTable() * 10u) + (uint16)3u;
#if (DLOG_ENABLE_MULTI_CPU == STD_ON)
   *DataLength += Dlog_NumberOfUserMemSegTableEntries * 10u;
#endif
   return E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service ReadDataByIdentifier (0x22) -
 * DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE Read memory segmentation table.
 *
 * \global     Dlog_MemSegTable
 *
 * \param[in]  OpStatus   See Dcm specification \cite SWS-DiagnosticCommunicationManager.
 * \param[out] Data       Contains the Memory Segmentation Table on return
 *
 * \return Always E_OK
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset | Value      | Description
 * ------ | ---------- | -----------------
 *    0   | 0x22..0xFF | addressAndLengthFormatIdentifier
 *    1   |       0x.. | Number of entries (MSB)
 *    2   |       0x.. | Number of entries (LSB)
 *    3   |       0x.. | Memory Address \#1 (Byte \#1, MSB)
 *   ...  |     ...    | ...
 *   2+n  |       0x.. | Memory Address \#1 (Byte \#n, LSB)
 *   3+n  |       0x.. | Memory Size \#1 (Byte \#1, MSB)
 *   ...  |     ...    | ...
 *   2+2n |       0x.. | Memory Size \#1 (Byte \#n, LSB)
 *   3+2n |       0x.. | Number of segments (MSB)
 *   4+2n |       0x.. | Number of segments (LSB)
 *   ...  |     ...    | \<Next entry\>
 * \lhref FL965,FL966
 *
 */
/*----------------------------------------------------------------------------*/
/* PRQA S 0492 PTAR */
/* PRQA S 0489,3440 BUF */
Std_ReturnType Dlog_ReadDataByIdentifierMemorySegmentationTable(Dcm_OpStatusType OpStatus, uint8* Data) {
   uint8_least          iLoop;               /* temporary loop variable       */
   uint16               totalNumberOfEntries;
   uint16               numberOfUserEntries = 0;
   P2VAR(uint8, AUTOMATIC, Dlog_APPL_DATA) dataBufPtr = Data;

   const uint8 numberOfEntries =
      Dlog_GetNumberOfElementsInReadMemorySegmentationTable();

#if (DLOG_ENABLE_MULTI_CPU == STD_ON)
   const uint32 userPos = 3ul + (numberOfEntries * 10ul);

   Std_ReturnType ret = Dlog_UserReadMemorySegmentationTable(OpStatus, &Data[userPos], &numberOfUserEntries);

   if (E_OK != ret) {
      return ret;
   }
   if (numberOfUserEntries != Dlog_NumberOfUserMemSegTableEntries) {
      return E_NOT_OK;
   }
#else
   /* MISRA-C:2004 Rule 14.2: parameter needed by Autosar */
   /* PRQA S 3112 1 */
   (void)OpStatus;
#endif

   totalNumberOfEntries = numberOfUserEntries + numberOfEntries;

   /* set addressAndLengthFormatIdentifier: 4 bytes address and 4 bytes size */
   *dataBufPtr++ = (uint8)0x44u;

   /* number of SWEs (boot and appl) MSB/LSB                               */
   *dataBufPtr++ = (uint8)BUtil_GetHiByte(totalNumberOfEntries);
   *dataBufPtr++ = (uint8)BUtil_GetLoByte(totalNumberOfEntries);

   for (iLoop = 0; iLoop < numberOfEntries; ++iLoop) {
      *dataBufPtr++ = BUtil_GetHiHiByte(Dlog_MemSegTable.StartAddress[iLoop]);
      *dataBufPtr++ = BUtil_GetHiLoByte(Dlog_MemSegTable.StartAddress[iLoop]);
      *dataBufPtr++ = BUtil_GetLoHiByte(Dlog_MemSegTable.StartAddress[iLoop]);
      *dataBufPtr++ = BUtil_GetLoLoByte(Dlog_MemSegTable.StartAddress[iLoop]);

      *dataBufPtr++ = BUtil_GetHiHiByte(Dlog_MemSegTable.SegmentSize[iLoop]);
      *dataBufPtr++ = BUtil_GetHiLoByte(Dlog_MemSegTable.SegmentSize[iLoop]);
      *dataBufPtr++ = BUtil_GetLoHiByte(Dlog_MemSegTable.SegmentSize[iLoop]);
      *dataBufPtr++ = BUtil_GetLoLoByte(Dlog_MemSegTable.SegmentSize[iLoop]);

      /* number of consecutive same sized flash segments                      */
      *dataBufPtr++ = BUtil_GetHiByte(Dlog_MemSegTable.NumberOfSegments[iLoop]);     /* MSB */
      *dataBufPtr++ = BUtil_GetLoByte(Dlog_MemSegTable.NumberOfSegments[iLoop]);     /* LSB */
   }

   return E_OK;
   /* PRQA S 2006,5207 1 */
}
/* PRQA L:BUF */
/* PRQA L:PTAR */

#endif /*#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )*/


/*----------------------------------------------------------------------------*/
/**
 * Get the address, size and segment index of the memory segment containing
 * the given address.
 *
 * \global     Dlog_MemSegTable
 *
 * \param[in]  Address         Address to find the segment for
 * \param[out] SegmentAddress  Contains the segment address on return
 * \param[out] SegmentSize     Contains the segment size on return
 * \param[out] SegmentIndex    Contains the segment index on return
 *
 * \retval     E_OK            Segment found
 * \retval     E_NOT_OK        No segment containing the given address
 *                             was found
 *
 * \pre  SegmentAddress, SegmentSize and SegmentIndex are valid non-null pointers
 *
 * \post E_NOT_OK is returned or the output parameters are filled with the
 *       segment information
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_GetMemorySegmentForAddress(
    size_t const Address,
    size_t* const SegmentAddress,
    size_t* const SegmentSize,
    uint16* const SegmentIndex
) {
  uint8_least       iLoop;               /* temporary loop variable       */
  uint16            segIndexBase    = 0;
  Std_ReturnType    ret             = E_NOT_OK;
  const uint8_least numberOfEntries = Dlog_GetNumberOfElementsInReadMemorySegmentationTable();

  for (iLoop = 0; iLoop < numberOfEntries; ++iLoop) {
    const uint32 start = Dlog_MemSegTable.StartAddress[iLoop];
    const uint32 endBlock = start + (Dlog_MemSegTable.SegmentSize[iLoop]
                                       * Dlog_MemSegTable.NumberOfSegments[iLoop]);

    if ((Address >= start) && (Address < endBlock)) {
      const uint32 segSize = Dlog_MemSegTable.SegmentSize[iLoop];
      const uint16 segIndexOffset = (uint16)((Address - start) / segSize);
      *SegmentAddress = start + (segSize * (uint32)segIndexOffset);
      *SegmentSize = segSize;
      *SegmentIndex = segIndexBase + segIndexOffset;
      ret = E_OK;
      break;
    }
    segIndexBase += Dlog_MemSegTable.NumberOfSegments[iLoop];
  }
  return ret;
}


#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )
/*----------------------------------------------------------------------------*/
/**
 * Get the address and size of the memory segment containing with the
 * given index.
 *
 * \global     Dlog_MemSegTable
 *
 * \param[in]  SegmentIndex    Index for the segment
 * \param[out] SegmentAddress  Contains the segment address on return
 * \param[out] SegmentSize     Contains the segment size on return
 *
 * \retval     E_OK            Segment found
 * \retval     E_NOT_OK        SegmentIndex out of range
 *
 * \pre  SegmentAddress and SegmentSize are valid non-null pointers
 *
 * \post E_NOT_OK is returned or the output parameters are filled with the
 *       segment information
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_GetMemorySegmentForIndex(
    const uint16 SegmentIndex,
    uint32* const SegmentAddress,
    uint32* const SegmentSize
) {
   uint8_least       iLoop;
   uint16            index           = 0;
   Std_ReturnType    ret             = E_NOT_OK;
   const uint8_least numberOfEntries = Dlog_GetNumberOfElementsInReadMemorySegmentationTable();

   for (iLoop = 0; iLoop < numberOfEntries; ++iLoop) {
      const uint16 numSeg = Dlog_MemSegTable.NumberOfSegments[iLoop];
      if (SegmentIndex < (index + numSeg)) {
         const uint32 segSize = Dlog_MemSegTable.SegmentSize[iLoop];
         const uint16 segIndexOffset = SegmentIndex - index;
         *SegmentAddress = Dlog_MemSegTable.StartAddress[iLoop] + (segSize * (uint32)segIndexOffset);
         *SegmentSize = segSize;
         ret = E_OK;
         break;
      }
      index += numSeg;
   }
   return ret;
}
#endif /* #if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
