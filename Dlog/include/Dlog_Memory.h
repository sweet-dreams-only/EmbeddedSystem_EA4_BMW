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

#ifndef DLOG_MEMORY_H
#define DLOG_MEMORY_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include "DlogClassic_Cfg.h"
#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )
#if ( DLOG_ENABLE_RTE == STD_ON )
#include <Rte_Dlog_Type.h>
#else
#include "Dcm.h"                      /* AUTOSAR DCM Types              */
#endif
#endif /* ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON ) */
#include <stddef.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Memory.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern uint8 Dlog_GetNumberOfElementsInReadMemorySegmentationTable(void);

#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )
extern Std_ReturnType Dlog_ConditionCheckMemorySegmentationTable
               (
                  Dcm_OpStatusType OpStatus,
                  Dcm_NegativeResponseCodeType* ErrorCode
               );

extern Std_ReturnType Dlog_ReadDataLengthMemorySegmentationTable(Dcm_OpStatusType OpStatus, uint16* DataLength);

extern Std_ReturnType Dlog_ReadDataByIdentifierMemorySegmentationTable
            (
               Dcm_OpStatusType OpStatus,
               uint8* Data
            );
#endif /* #if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON ) */

extern Std_ReturnType Dlog_GetMemorySegmentForAddress(
    size_t const Address,
    size_t* const SegmentAddress,
    size_t* const SegmentSize,
    uint16* const SegmentIndex
);

#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )

extern Std_ReturnType Dlog_GetMemorySegmentForIndex(
    const uint16 SegmentIndex,
    uint32* const SegmentAddress,
    uint32* const SegmentSize
);

#endif /* #if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOG_MEMORY_H                                                       */
