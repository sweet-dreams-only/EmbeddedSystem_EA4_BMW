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

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_SvkGen.h"
#include "Dlog_Cfg.h"

#include "Dlog_CodingAdapter.h"
#include "Dlog_NvMAdapter.h"
#include "Dlog_UDSAdapter.h"
#include "Dlog_UserAdapter.h"

#include "Dlog_Data.h"
#include "BUtil_Algorithm.h"
#include "BUtil_BitArray.h"
#include "BUtil_ByteMask.h"

#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_SvkGen.c does not match the version of the module!"
#endif


#if (DLOG_ENABLE_SVK_CURRENT == STD_ON)

#define DLOG_HISTORY_SYSTEMSUPPLIER 0U
#define DLOG_HISTORY_PLANT          1U
#define DLOG_HISTORY_BACKUP_01      2U


/** The following enum type contains the 'testerKennungType' types            */
typedef enum
{
  DLOG_TESTERTYPFREEREPAIRSHOP    = 0x9u,
  DLOG_TESTERTYPSERVICEBMWHO      = 0xAu,
  DLOG_TESTERTYPSYSTEMSUPPLIER    = 0xBu,
  DLOG_TESTERTYPCARFACTORY        = 0xDu,
  DLOG_TESTERTYPSPAREPARTFACTORY  = 0xEu,
  DLOG_TESTERTYPDEVELOPMENT       = 0xFu
} Dlog_TesterKennungType;

/** Types for SvkLockedStatus flag                                            */
typedef enum
{
  SVKSTATUS_SYSSUPPANDPLANTUNLOCKED,
  SVKSTATUS_SYSSUPLOCKEDPLANTUNLOCKED,
  SVKSTATUS_SYSSUPPANDPLANTLOCKED
} Dlog_SvkLockedStatusType;

typedef struct {
  uint16 currentBlockId;
  uint8  currentState;
  uint8  currentHistoryIndex;
} Dlog_WriteHistoryStateType;

/*------------------------------------------------------------------------------
                      Local Variables
-------------------------------------------------------------------------------*/

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

#define Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/** SVK History Memory */
Dlog_SvkHistoryMemoryType Dlog_SvkHistory;

Dlog_SvkEntryType Dlog_SvkTmpBuf;

#define Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#define Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/* Needed here for memory mapping */
/* PRQA S 3218 1 */
static Dlog_WriteHistoryStateType Dlog_WriteHistoryState;

#define Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#define Dlog_START_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

uint8 Dlog_SvkTmpHistoryIndex;

#define Dlog_STOP_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if DLOG_ENABLE_SVK_HISTORY == STD_ON */

/*------------------------------------------------------------------------------
                      Local Function Prototypes
-------------------------------------------------------------------------------*/

static void Dlog_SvkInitStage2(NvMService_ResultType result, void* context);
static void Dlog_SvkInitStage3(NvMService_ResultType result, void* context);
static uint16 Dlog_GetSvkTableSize(uint16 numberOfSvk);
static uint16 Dlog_GetSvkHistorySize(const uint8* Data);
static uint8 Dlog_GetPrevElementInFifo(uint8 num, uint8 prev, uint8 maxelem);
static uint8 Dlog_GetProgDepFlag(void);
static void Dlog_GetSvkCurrent(uint8* Data, size_t* DataLength);

/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/

/**
 * Returns the size of a SVK table with the given numbers of SVK entries
 */
static uint16 Dlog_GetSvkTableSize(uint16 numberOfSvk)
{
  return (4u + DLOG_FINGERPRINTLENGTH) + (DLOG_SGBM_ID_LENGTH * numberOfSvk);
}

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

/**
 * Returns the size of the given SVK History table in bytes
 */
static uint16 Dlog_GetSvkHistorySize(const uint8* Data)
{
  return BUtil_MIN( /* PRQA S 0492 */
      Dlog_GetSvkTableSize(BUtil_Make16Bit(Data[2], Data[3])),
      DLOG_SVK_BACKUP_SIZE);
}
#endif


/**
 * Calculate the index of the previous element in a fifo buffer
 */
static uint8 Dlog_GetPrevElementInFifo(uint8 num, uint8 prev, uint8 maxelem)
{
  return (num >= prev) ? (num - prev) : (maxelem - (prev - num));
}

static uint8 Dlog_GetProgDepFlag(void) {
  if (DLOG_PROG_DEP_UNCHECKED_APPL == Dlog_Data.sweProgDepState) {
    return DLOG_PROG_DEP_INVALID;
  }
  return (uint8)Dlog_Data.sweProgDepState;
}

/*----------------------------------------------------------------------------*/
/**
 * Copies the current SVK to the buffer.
 *
 * \param[out] Data       SVK buffer
 * \param[out] DataLength Length of the SVK data written to the buffer
 */
/*----------------------------------------------------------------------------*/
static void Dlog_GetSvkCurrent(uint8* Data, size_t* DataLength) {
  uint8* dataPtr = Data;
  uint16 numberOfSvk = Dlog_Data.numberOfHwe + Dlog_Data.numberOfSwe;
  uint8 i;
  uint8 lastGroupId = 0;
  boolean validInThisGroup = FALSE;

  *dataPtr++ = 1; /* SVK Version */
  *dataPtr++ = Dlog_GetProgDepFlag();

  *dataPtr++ = BUtil_GetHiByte(numberOfSvk);
  *dataPtr++ = BUtil_GetLoByte(numberOfSvk);

  /** \lhref FL149 */
  (void)memcpy(dataPtr, Dlog_Data.fingerprint, sizeof(Dlog_Data.fingerprint));
  dataPtr += sizeof(Dlog_Data.fingerprint);

  /* HWEs */
  for (i = 0; i < Dlog_Data.numberOfHwe; ++i) {
    memcpy(dataPtr, Dlog_Data.hweInfo[i].sgmbId, sizeof(Dlog_Data.hweInfo[i].sgmbId));
    dataPtr += sizeof(Dlog_Data.hweInfo[i].sgmbId);
  }

  /* SWEs */
  for (i = 0; i < Dlog_Data.numberOfSwe; ++i) {
    uint8 groupId = Dlog_Data.sweInfo[i].group;

    if (groupId != lastGroupId) {
      /* new group -> reset flag */
      validInThisGroup = FALSE;
    }

    if ((DLOG_SWE_STATE_VALID_SWFL == Dlog_Data.sweInfo[i].validState) ||
        (DLOG_SWE_STATE_VALID_BTLD == Dlog_Data.sweInfo[i].validState)) {
      memcpy(dataPtr, Dlog_Data.sweInfo[i].sgmbId, sizeof(Dlog_Data.sweInfo[i].sgmbId));
      validInThisGroup = TRUE;
    } else {
      if (((DLOG_SWEGROUP_ONEOBLIGATORY == Dlog_Data.sweGroupInfo[groupId])
          &&  (((i+1 < Dlog_Data.numberOfSwe) && (Dlog_Data.sweInfo[i+1].group == groupId))
                || (FALSE != validInThisGroup)
              )
          )
          || (DLOG_SWEGROUP_OPTIONAL == Dlog_Data.sweGroupInfo[groupId])) {
        /** \lhref FL142 */
        --numberOfSvk;
        continue;
      }
      /** \lhref FL143 */
      memset(dataPtr, 0x00, sizeof(Dlog_Data.sweInfo[i].sgmbId));
    }
    lastGroupId = groupId;
    dataPtr += sizeof(Dlog_Data.sweInfo[i].sgmbId);
  }

  /* set number of SVK entries                                            */
  Data[2] = BUtil_GetHiByte(numberOfSvk);                        /* MSB */
  Data[3] = BUtil_GetLoByte(numberOfSvk);                        /* LSB */

  *DataLength = dataPtr - Data;
}

#if DLOG_ENABLE_SVK_HISTORY == STD_ON
static void Dlog_SvkInitStage2(NvMService_ResultType result, void* context) {
  (void)context;

  if ((NVMSERVICE_OK != result)
      #if (DLOG_NUMBEROFSVKBACKUPS > 0u)
        || (Dlog_SvkHistory.SvkBackupFIFOCounter >= DLOG_NUMBEROFSVKBACKUPS)
      #endif
      )
  {

    Dlog_SvkHistory.SvkLockedStatus = 0;
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
    Dlog_SvkHistory.SvkBackupFIFOCounter = 0;
#endif
    /* take over current ProgId so no history entry will be written */
    (void)memcpy(Dlog_SvkHistory.LastProgId, Dlog_Data.progId, sizeof(Dlog_SvkHistory.LastProgId));

    /* all SVK memories are unlocked                                           */
    Dlog_SvkHistory.SvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED;
    Dlog_NvM_WriteSvkHistoryMemory(&Dlog_SvkHistory, Dlog_SvkInitStage3, NULL);
  }

  /* if progId changed, write history */
  if (0 != memcmp(Dlog_SvkHistory.LastProgId, Dlog_Data.progId, sizeof(Dlog_SvkHistory.LastProgId))) {
    (void)memcpy(Dlog_SvkHistory.LastProgId, Dlog_Data.progId, sizeof(Dlog_SvkHistory.LastProgId));
    Dlog_WriteSvkHistory();
  }
}

static void Dlog_SvkInitStage3(NvMService_ResultType result, void* context) {
  (void)result;
  (void)context;
}
#endif

/**
 * Initializes the Svk
 */
void Dlog_SvkInit(void) {
#if DLOG_ENABLE_SVK_HISTORY == STD_ON
  Dlog_NvM_ReadInitialSvkHistoryMemory(&Dlog_SvkHistory, Dlog_SvkInitStage2, NULL);
#endif
}

/**
 *
 * Description of response out parameter data:
 * Offset       |  Value |  Description
 * ------------ | ------ | -----------------
 *    0         |   0x01 | SVK Version
 *    1         |   0x.. | ProgrammingDependenciesChecked
 *    2         |   0x.. | Number of XWEs: (MSB)
 *    3         |   0x.. | Number of XWEs: (LSB)
 *    4         |   0x.. | Fingerprint \#1 (MSB)
 *   ...        |   ...  | ...
 *    7         |   0x.. | Fingerprint \#m (LSB)
 *    8         |   0x.. | XWE\#1, SGBM-ID, Byte\#1
 *   ...        |   ...  | ...
 *   15         |   0x.. | XWE\#1, SGBM-ID, Byte\#8
 *   ...        |   ...  | ...
 *  8+(n-1)*8   |   0x.. | XWE\#n, SGBM-ID, Byte\#1
 *   ...        |   ...  | ...
 * \lhref FL848,FL849
 *
 */
UDS_ReturnType Dlog_ReadDataSvkCurrent(uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode) {
  uint16      numberOfSvk;                       /* number of svks */
  uint16  numberOfUserSvk;
  UDS_ReturnType ret;
  uint8* dataPtr;

  Dlog_GetSvkCurrent(responseData, dataLength);
  numberOfSvk = BUtil_Make16Bit(responseData[2], responseData[3]);

  dataPtr = responseData + *dataLength;

  ret = Dlog_User_ReadSvkCurrent(dataPtr, &numberOfUserSvk);
  if (UDS_DIAG_JOB_FINISHED_E_NOT_OK == ret) {
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }
  if (UDS_DIAG_JOB_RUNNING == ret) {
    return ret;
  }
  dataPtr += numberOfUserSvk * DLOG_SGBM_ID_LENGTH;
  *dataLength += numberOfUserSvk * DLOG_SGBM_ID_LENGTH;
  numberOfSvk += numberOfUserSvk;

  Dlog_Coding_GetCafIds(dataPtr, &numberOfUserSvk);
  *dataLength += numberOfUserSvk * DLOG_SGBM_ID_LENGTH;
  numberOfSvk += numberOfUserSvk;

  /* set number of SVK entries                                            */
  responseData[2] = BUtil_GetHiByte(numberOfSvk);                        /* MSB */
  responseData[3] = BUtil_GetLoByte(numberOfSvk);                        /* LSB */

  return UDS_DIAG_JOB_FINISHED_OK;
}

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

static void Dlog_ReadDataSvkHistoryNvMCallBack(NvMService_ResultType result, void* context) {
  (void)context;

  if (NVMSERVICE_OK == result && DLOG_SVK_VERSION == Dlog_SvkTmpBuf[0]) {
    uint16 userNumberOfSvk;
    uint16 numberOfSvk;
    uint16 historySize = Dlog_GetSvkHistorySize(Dlog_SvkTmpBuf);
    Dlog_User_ReadSvkHistory(Dlog_SvkTmpHistoryIndex, &Dlog_SvkTmpBuf[historySize], &userNumberOfSvk);

    numberOfSvk = BUtil_Make16Bit(Dlog_SvkTmpBuf[2], Dlog_SvkTmpBuf[3]);
    numberOfSvk += userNumberOfSvk;

    Dlog_SvkTmpBuf[2] = BUtil_GetHiByte(numberOfSvk);                        /* MSB */
    Dlog_SvkTmpBuf[3] = BUtil_GetLoByte(numberOfSvk);                        /* LSB */

    historySize = Dlog_GetSvkHistorySize(Dlog_SvkTmpBuf);
    Dlog_UDS_ReadDataSvkHistory_ResultOk(Dlog_SvkTmpBuf, (size_t)historySize);
  }
  else
  {
    Dlog_UDS_ReadDataSvkHistory_ResultError(UDS_DIAG_E_CONDITIONSNOTCORRECT);
  }
}

/**
 * Implements the Diagnostic Service Read SVK History.
 *
 * \param[in]  historyIndex  The index of the history entry (0=SysSup,1=Plant,n=Backup#n-1)
 * \param[out] responseData  response data
 * \param[out] dataLength    length of responseData
 * \param[out] errorCode     UDS error code
 *
 * \return see UDS_ReturnType
 *
 * \lhref FL873, FL879, FL885
 */
UDS_ReturnType Dlog_ReadDataSvkHistory(uint8 historyIndex, uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode) {
  (void)responseData;
  (void)dataLength;

  Dlog_SvkTmpHistoryIndex = historyIndex;

  if (historyIndex < DLOG_HISTORY_BACKUP_01) {
    Dlog_NvM_ReadSvkEntry(historyIndex, &Dlog_SvkTmpBuf, &Dlog_ReadDataSvkHistoryNvMCallBack, NULL);
  } else {
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
    uint8 svkBackupNumber = historyIndex - DLOG_HISTORY_BACKUP_01;

    if (svkBackupNumber < DLOG_NUMBEROFSVKBACKUPS) {
      uint8 tmpSvkBackupNumber;
      /*
       * Calculate position that have to read from svk history memmory.
       * Remark: svkBackupNumber = 0 means the last backup stored in
       *         history memory during flash download.
       * Remark: The SVK backup memory is a ring buffer
       */
      tmpSvkBackupNumber = Dlog_SvkHistory.SvkBackupFIFOCounter;

      tmpSvkBackupNumber = Dlog_GetPrevElementInFifo
          ( tmpSvkBackupNumber,
            svkBackupNumber + (uint8)1,
            DLOG_NUMBEROFSVKBACKUPS
          );

      Dlog_NvM_ReadSvkEntry(tmpSvkBackupNumber + DLOG_HISTORY_BACKUP_01, &Dlog_SvkTmpBuf, &Dlog_ReadDataSvkHistoryNvMCallBack, NULL);
    } else {
#endif
      *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
      return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
    }
#endif
  }
  return UDS_DIAG_JOB_RUNNING;
}

static void Dlog_WriteSvkHistoryNvMCallBackStage2(NvMService_ResultType result, void* context) {
  /* finish writing svk history */
  /* TODO: user callout? */
}

static void Dlog_WriteSvkHistoryNvMCallBackStage1(NvMService_ResultType result, void* context) {
  (void)context;

  if (NVMSERVICE_OK == result) {
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
    if (DLOG_HISTORY_BACKUP_01 <= Dlog_WriteHistoryState.currentHistoryIndex)
    {
      /*
       * Calculate the position of the next SVK backup.
       * Remark: The SVK backup memory is a ring buffer
       */
      Dlog_SvkHistory.SvkBackupFIFOCounter =
          (uint8)((Dlog_SvkHistory.SvkBackupFIFOCounter + (uint8)1) %
                  (uint8)DLOG_NUMBEROFSVKBACKUPS);
    }
#endif
    Dlog_NvM_WriteSvkHistoryMemory(&Dlog_SvkHistory, Dlog_WriteSvkHistoryNvMCallBackStage2, 0);
  } else {
    Dlog_WriteSvkHistoryNvMCallBackStage2(result, context);
  }
}

/**
 * Writes the current SVK into history memory.
 *
 * \param currentTesterType the current tester type (determines the history location)
 *
 */
void Dlog_WriteSvkHistory(void) {
  uint8 currentTesterType = (Dlog_Data.fingerprint[3] & 0x0fu);
  uint8 newSvkLockedStatus = Dlog_SvkHistory.SvkLockedStatus;
  uint8 historyIndex;
  size_t dataLength;

  if ( (currentTesterType  == (uint8)DLOG_TESTERTYPSYSTEMSUPPLIER) &&
       (newSvkLockedStatus == (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED)
      )
  {
    /* system supplier SVK entry                                            */
    historyIndex       = DLOG_HISTORY_SYSTEMSUPPLIER;
    newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED;
  }
  else if ( ( (currentTesterType == (uint8)DLOG_TESTERTYPCARFACTORY) ||
              (currentTesterType == (uint8)DLOG_TESTERTYPSPAREPARTFACTORY)
            ) &&
            ( newSvkLockedStatus != (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED)
      )
  {
    /* plant SVK entry                                                      */
    historyIndex       = DLOG_HISTORY_PLANT;
    newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPLOCKEDPLANTUNLOCKED;
  }
  else
  {
    newSvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED;
#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
    /* backup SVK entry                                                     */
      historyIndex       = DLOG_HISTORY_BACKUP_01 + Dlog_SvkHistory.SvkBackupFIFOCounter;
#else /* (DLOG_NUMBEROFSVKBACKUPS > 0u)                                            */
    if ( newSvkLockedStatus == Dlog_SvkHistory.SvkLockedStatus )
    {
      /* Nothing to do                                                     */
      return;
    }
    /* store new locked status only                                             */
    Dlog_SvkHistory.SvkLockedStatus = newSvkLockedStatus;

    Dlog_WriteHistoryState.currentState = 1;
    Dlog_WriteHistoryState.currentHistoryIndex = DLOG_NUMBEROFSVKBACKUPS+DLOG_HISTORY_BACKUP_01;

    Dlog_NvM_WriteSvkHistoryMemory(&Dlog_SvkHistory, Dlog_WriteSvkHistoryNvMCallBackStage2, NULL);
    return;
#endif  /* (DLOG_NUMBEROFSVKBACKUPS > 0u)                                          */
  }

#if (DLOG_NUMBEROFSVKBACKUPS > 0u)
  /*
    * programming dependencies must be valid if SVK backup memory is used
    */
   if ( newSvkLockedStatus == (uint8)SVKSTATUS_SYSSUPPANDPLANTLOCKED )
   {
      /* get programming dependency state of all application SWEs */
      Dlog_SweProgDepStateType progDepStateOfApplSwes = Dlog_Data.sweProgDepState;

      if (progDepStateOfApplSwes != DLOG_PROG_DEP_CONSISTENT_APPL )
      {
         return;
      }
   }
#endif /* #if (DLOG_NUMBEROFSVKBACKUPS > 0u) */

  /* store new locked status                                                 */
  Dlog_SvkHistory.SvkLockedStatus = newSvkLockedStatus;

  Dlog_WriteHistoryState.currentState = 0;
  Dlog_WriteHistoryState.currentHistoryIndex = historyIndex;

  Dlog_GetSvkCurrent( Dlog_SvkTmpBuf, &dataLength );
  Dlog_NvM_WriteSvkEntry(historyIndex,
                         (const Dlog_SvkEntryType*)&Dlog_SvkTmpBuf,
                         Dlog_WriteSvkHistoryNvMCallBackStage1,
                         NULL);
}

#endif /* #if DLOG_ENABLE_SVK_HISTORY == STD_ON */

#endif /* #if (DLOG_ENABLE_SVK_CURRENT == STD_ON) */