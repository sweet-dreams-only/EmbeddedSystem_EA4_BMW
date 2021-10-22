/**
 * \file
 *
 * \brief       Read NV-Memory into Mirror.
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
#include "Dlog_Nvm.h"
#include "Dlog_SvkGen.h"
#include "Dlog_HweTable.h"
#if ( DLOG_ENABLE_ECU == STD_ON )
#include "Dlog_Ecu.h"
#endif
/* -------------------------------------------------------------------------- */
#include <Rte_Dlog.h>
/* -------------------------------------------------------------------------- */


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA Rule 14.2. Reason: void cast for unused parameter, see PRQA: 3112 */

/* Violation of MISRA rule 14.7. Reason: early return in case of errors makes code more readable,
   see PRQA: 2006, 5207 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Nvm.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */



/**
 * Called by NvM when the read or write job has finished.
 */
Std_ReturnType Dlog_NotifyJobFinishedProgData(uint8 ServiceId, NvM_RequestResultType JobResult) {
  /* PRQA S 3112 2 *//* unused parameters, defined by Autosar */
  (void)ServiceId;
  (void)JobResult;

  /* Set write protection again */
  (void)Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(TRUE);

  return E_OK;
}



/**
 * Writes the given NV-Block to NV-Memory
 *
 * \param[in] blockId Id of the block to be written
 * \param[in] mirror  RAM mirror of the block to be written
 * \param[in] wait    If TRUE, the routine blocks until the NV-Block
 *                    is written or an error occurs. The blocking is done by calling
 *                    the blocking user-defined function WaitMemDriverReader().
 *                    If FALSE, the routine returns immediately after the
 *                    write job has been triggered.
 *
 * \remark If configured for NvM, the parameter wait is ignored, i.e. the routine
 *         always returns immediately after the write job has been triggered.
 */
Std_ReturnType Dlog_WriteNvmBlock(
    uint16 blockId,
    Dlog_NvmMirrorPtr mirror, /* PRQA S 3673 *//* configuration dependent */
    boolean wait) {
  Std_ReturnType ret;
  /* write to NV-Memory                                                */
  /* MISRA-C:2004 Rule 14.2: parameter needed for other configurations */
  /* PRQA S 3112 1 */
  (void)wait;
  switch(blockId) {
    case DLOG_NVM_BLOCK_PROG_DATA:
      /* Clear write protection */
      ret = Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(FALSE);
      if (E_OK != ret) {
        return ret;
      }
      ret = Rte_Call_NvMService_DlogProgData_WriteBlock(mirror);
      if (E_OK != ret) {
        /* Set write protection again */
        (void)Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(TRUE);
      }
      break;
    default:
      ret = E_NOT_OK;
      break;
  }
  return ret;
  /* PRQA S 2006,5207 1 */
}


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

