/**
 * \file
 *
 * \brief       Dlog User adapter.
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

#include "Dlog_UserAdapter.h"

#include "DlogClassic_Cfg.h"
#include "Dlog_User.h"

#if (DLOG_ENABLE_RTE == STD_ON)
#include <Rte_Dlog.h>
#else
#include "Dlog_Rte2C.h"
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5, 3, 1))
#error "Version of Dlog_NvMAdapter.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

UDS_ReturnType Dlog_User_ReadSvkCurrent(uint8* data, uint16* numberOfSvk) {
#if (DLOG_ENABLE_MULTI_CPU == STD_ON) && (DLOG_ENABLE_SVK_CURRENT == STD_ON)
  if (E_OK != Rte_Call_DlogUser_SvkCurrent_ReadSvk(DCM_INITIAL, data, numberOfSvk)) {
    return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }
#else
  (void)data;
  *numberOfSvk = 0;
#endif
  return UDS_DIAG_JOB_FINISHED_OK;
}

UDS_ReturnType Dlog_User_ReadSvkHistory(uint8 historyIndex, uint8* data, uint16* numberOfSvk) {
#if (DLOG_ENABLE_MULTI_CPU == STD_ON) && (DLOG_ENABLE_SVK_HISTORY == STD_ON)
  if (E_OK != Rte_Call_DlogUser_SvkHistory_ReadSvkHistory(historyIndex, DCM_INITIAL, data, numberOfSvk)) {
    return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }
#else
  (void)historyIndex;
  (void)data;
  *numberOfSvk = 0;
#endif
  return UDS_DIAG_JOB_FINISHED_OK;
}

UDS_ReturnType Dlog_User_ReadDevelopmentInfoField(
    const uint8* sgbmId,
    uint8* developmentInfoField,
    size_t* developmentInfoFieldLength) {
#if (DLOG_ENABLE_MULTI_CPU == STD_ON) && (DLOG_ENABLE_SVK_CURRENT == STD_ON)
  uint16 l;
  Dcm_NegativeResponseCodeType e;
  if (E_OK != Rte_Call_DlogUser_DevelopmentInfo_ReadDevelopmentInfoField(sgbmId, DCM_INITIAL, developmentInfoField, &l, &e)) {
    return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }
  *developmentInfoFieldLength = l;
  return UDS_DIAG_JOB_FINISHED_OK;
#else
  (void)sgbmId;
  (void)developmentInfoField;
  (void)developmentInfoFieldLength;
  return UDS_DIAG_JOB_FINISHED_E_NOT_OK;
#endif
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */
