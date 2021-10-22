/**
 * \file
 *
 * \brief       Read and write SVK entries.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef DLOG_SVKGEN_H
#define DLOG_SVKGEN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Data.h"
#include "BUtil/GenericUDSTypes.h"
#include "BUtil/PlatformTypes.h"

#include <stddef.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_SvkGen.h does not match the version of the module!"
#endif


#define DLOG_SVK_VERSION              (uint8)0x01
#if DLOG_ENABLE_SVK_HISTORY == STD_ON
#define DLOG_SVK_BACKUP_SIZE ( 4u + DLOG_FINGERPRINTLENGTH + (DLOG_SGBM_ID_LENGTH *           \
                          (DLOG_MAXNUMBEROFSVKSGBMIDS))            \
                        )
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

typedef struct
{
  /**
   * SysSupplier and Plant entries can be locked by this flag
   */
  uint8 SvkLockedStatus;
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
  uint8 SvkBackupFIFOCounter;                  /**< Svk Backup as FIFO    */
#endif
  uint8 LastProgId[DLOG_PROG_ID_LENGTH];
} Dlog_SvkHistoryMemoryType;

typedef uint8 Dlog_SvkEntryType[DLOG_SVK_BACKUP_SIZE];

#endif /* #if DLOG_ENABLE_SVK_HISTORY == STD_ON */

#define Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if DLOG_ENABLE_SVK_HISTORY == STD_ON
/** SVK History Memory */
extern Dlog_SvkHistoryMemoryType Dlog_SvkHistory;

extern Dlog_SvkEntryType Dlog_SvkTmpBuf;

#endif

#define Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#ifdef __cplusplus
extern "C" {
#endif

void Dlog_SvkInit(void);

UDS_ReturnType Dlog_ReadDataSvkCurrent(uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode);

void Dlog_UserReadSvkCurrentResultOk(const uint8* data, size_t dataLength);
void Dlog_UserReadSvkCurrentResultError(UDS_ErrorCodeType errorCode);

#if DLOG_ENABLE_SVK_HISTORY == STD_ON
UDS_ReturnType Dlog_ReadDataSvkHistory(uint8 historyIndex, uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode);

void Dlog_WriteSvkHistory(void);
#endif

#ifdef __cplusplus
}
#endif

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #ifndef DLOG_SVKGEN_H */
