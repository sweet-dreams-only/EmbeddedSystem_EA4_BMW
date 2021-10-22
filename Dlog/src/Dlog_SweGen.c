/**
 * \file
 *
 * \brief       Dlog SWE.
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

#include "Dlog_SweGen.h"
#include "Dlog_Data.h"

#include "Dlog_UDSAdapter.h"
#include "Dlog_UserAdapter.h"

#include "BUtil_BitArray.h"

#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_SweGen.c does not match the version of the module!"
#endif


#define DLOG_SWE_ID_OF_BLU_SWE 1u
#define SWE_ID_OF_APPL_SWE1 1u


#if DLOG_ENABLE_ECU == STD_ON
/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * RoutineControl (0x31) - DIAG_RID_0205_READ_DEVELOPMENT_INFO.
 * Reads the SWE development info for the sgbm-id.
 *
 * \param[in]  requestData        SGBM-ID of the Development Info Field
 * \param[in]  requestDataLength  8
 * \param[out] responseData       Development Info Field
 * \param[out] responseDataLength In:8, Out:Length of the Development Info Field
 * \param[out] errorCode          Negative Response Code in case of an error, else untouched
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK        success
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK  An error occurred and the Negative Response Code is written to ErrorCode
 *
 * \lhref FL1201
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset | Value | Description
 * ------ | ----- | -----------------
 *    0   |  0x.. | Number of bytes: n
 *    1   |  0x.. | Development Info byte\#1
 *    2   |  0x.. | Development Info byte\#2
 *   ...  |   ... | ...
 *    n   |  0x.. | Development Info byte\#n
 * \lhref FL1202,FL1203
 *
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Dlog_RoutineControlReadDevelopmentInfoFieldStart(
    const uint8* requestData,
    size_t requestDataLength,
    uint8* responseData,
    size_t* responseDataLength,
    UDS_ErrorCodeType* errorCode) {
  boolean found = FALSE;
  uint8 i;
  UDS_ReturnType ret = UDS_DIAG_JOB_FINISHED_OK;

  if (requestDataLength != (size_t)DLOG_SGBM_ID_LENGTH) {
    *errorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
    return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }

  /* check process class */
  switch (requestData[0]) {
    case DLOG_PROCESSCLASS_HWEL:
    case DLOG_PROCESSCLASS_HWAP:
    case DLOG_PROCESSCLASS_HWFR:
      /* search in HWEDevelopmentInfo list                              */
      for (i = 0; i < Dlog_Data.numberOfHwe; ++i) {
        const Dlog_HweInfoType* hweInfo = &Dlog_Data.hweInfo[i];
        if (0 == memcmp(hweInfo->sgmbId, requestData, DLOG_SGBM_ID_LENGTH)) {
          *responseDataLength = (size_t)(*hweInfo->developmentInfo + 1);
          (void)memcpy(responseData, hweInfo->developmentInfo, *responseDataLength);
          found = TRUE;
          break;
        }
      }
      break;
    default:
      /* search in SWEDevelopmentInfo list                              */
      for (i = 0; i < Dlog_Data.numberOfSwe; ++i) {
        const Dlog_SweInfoType* sweInfo = &Dlog_Data.sweInfo[i];
        if (((DLOG_SWE_STATE_VALID_SWFL == sweInfo->validState) || (DLOG_SWE_STATE_VALID_BTLD == sweInfo->validState))
            && (0 == memcmp(sweInfo->sgmbId, requestData, DLOG_SGBM_ID_LENGTH))) {
          *responseDataLength = (size_t)(*sweInfo->developmentInfo + 1);
          (void)memcpy(responseData, sweInfo->developmentInfo, *responseDataLength);
          found = TRUE;
          break;
        }
      }
      break;

  }

  if (FALSE == found) {
    ret = Dlog_User_ReadDevelopmentInfoField(requestData, responseData, responseDataLength);
    if (UDS_DIAG_JOB_FINISHED_E_NOT_OK == ret) {
      /*
       * No according SWE found or no DevelopmentInfo is available:
       * Response with 0x00
       */
      responseData[0] = (uint8)0x00;
      *responseDataLength = (size_t)1;
      ret = UDS_DIAG_JOB_FINISHED_OK;
    }
  }

  return ret;
}

void Dlog_UserReadDevelopmentInfoField_ResultOk(const uint8* developmentInfoField, size_t developmentInfoFieldLength) {
  Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultOk(developmentInfoField, developmentInfoFieldLength);
}

void Dlog_UserReadDevelopmentInfoField_ResultError(UDS_ErrorCodeType errorCode) {
  const uint8 developmentInfoField = 0x00;
  const size_t developmentInfoFieldLength = 1;
  Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultOk(&developmentInfoField, developmentInfoFieldLength);
}

#endif /* #if DLOG_ENABLE_ECU == STD_ON */

Dlog_SweValidStateType Dlog_GetValidState(void) {
  Dlog_SweValidStateType validStateOfApplSwes = Dlog_Data.sweInfo[DLOG_SWE_ID_OF_BLU_SWE].validState;
  uint8 groupStates[BUtil_CalcRequiredBytesForMultiByteBitArray(DLOG_MAX_NUMBER_OF_SWE_GROUPS)] = {0};
  uint8 groupId;
  uint8 maxGroupId = 0;

  /* if first SWE has not been sig checked    */
  if (validStateOfApplSwes == DLOG_SWE_STATE_UNCHECKED) {
    /* return invalid SWE found       */
    validStateOfApplSwes = DLOG_SWE_STATE_INVALID;
  }
    /* if BLU SWE is valid and no BLU         */
  else if (validStateOfApplSwes == DLOG_SWE_STATE_VALID_SWFL) {
    /* iterate other SWEs of application too    */
    uint8_least sweId = (uint8_least)(SWE_ID_OF_APPL_SWE1);
    while (sweId < (uint8_least)Dlog_Data.numberOfSwe) {
      groupId = Dlog_Data.sweInfo[sweId].group;

      if (groupId > maxGroupId) {
        maxGroupId = groupId;
      }

      /* if any other SWE is not valid            */
      if ((DLOG_SWE_ID_OF_BLU_SWE != sweId) &&
          (Dlog_Data.sweInfo[sweId].validState != DLOG_SWE_STATE_VALID_SWFL)) {
        if (DLOG_SWEGROUP_ALLOBLIGATORY == Dlog_Data.sweGroupInfo[groupId]) {
          /* return invalid SWE found       */
          validStateOfApplSwes = DLOG_SWE_STATE_INVALID;
        }
      } else {
        if (DLOG_SWEGROUP_ONEOBLIGATORY == Dlog_Data.sweGroupInfo[groupId]) {
          BUtil_SetBitInMultiByteBitArray(groupStates, groupId);
        }
      }
      ++sweId;
    }
    for (groupId = 0; groupId <= maxGroupId; ++groupId) {
      if ((DLOG_SWEGROUP_ONEOBLIGATORY == Dlog_Data.sweGroupInfo[groupId])
          && (0 == BUtil_GetBitInMultiByteBitArray(groupStates, groupId))) {
        /* one swe is obligatory, but none is valid -> return invalid SWE found       */
        validStateOfApplSwes = DLOG_SWE_STATE_INVALID;
        break;
      }
    }
  } else {
    /* nothing to do, just to avoid MISRA violation */
  }

  return validStateOfApplSwes;
}

/**
 * Returns the SweId of an Swe identified by an SgbmId
 *
 * \param[in]  SgbmId  The SdbmId of the Swe
 * \param[out] SweId   The SweId of the Swe
 *
 * \retval TRUE   The Swe was found and SweId contains the Id
 * \retval FALSE  The Swe was not found
 *
 */
boolean Dlog_GetSweIdBySgbmId(const uint8* SgbmId, uint8* SweId) {
  uint8 tmpSweId;

  for (tmpSweId = 0; tmpSweId < (uint8)Dlog_Data.numberOfSwe; ++tmpSweId) {
    /* If in bootloader check if SWE is valid. In application SWEs */
    /* are always valid, otherwise it would not have been started  */
    const Dlog_SweValidStateType validStateOfSwe = Dlog_Data.sweInfo[tmpSweId].validState;

    if ((validStateOfSwe == DLOG_SWE_STATE_VALID_SWFL) ||
        (validStateOfSwe == DLOG_SWE_STATE_VALID_BTLD)) {

      /* check SgbmId                                  */
      if (memcmp(Dlog_Data.sweInfo[tmpSweId].sgmbId, SgbmId, DLOG_SGBM_ID_LENGTH) == 0x00) {
        /* an according SWE was found                            */

        *SweId = tmpSweId;
        return TRUE;
      }
    }
  }

  return FALSE;
  /* PRQA S 2006,5207 1 */
}
