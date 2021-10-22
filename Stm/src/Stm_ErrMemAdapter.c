/**
*  \file
*
*  \brief       Stm Error Memory Adapter
*
*  This file contains the Stm Error Memory functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Stm_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Stm_ErrMemAdapter.h"
#include "Rte_Stm.h"
#include "StmClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_ErrMemAdapter.c does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

/*----------------------------------------------------------------------------*/
/**
 * \brief ErrMem_EnableMemoryLockCentralErrorLock
 *
 * Function to disable Dem Enable condition (=false)
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval ERRMEMSERVICE_OK on success
 *         ERRMEMSERVICE_NOT_OK on error
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
ErrMemService_ResultType ErrMem_EnableMemoryLockCentralErrorLock(void)
{
   ErrMemService_ResultType result;
   if ( E_OK == Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition( FALSE ) )
   {
      result = ERRMEMSERVICE_OK;
   }
   else
   {
      result = ERRMEMSERVICE_NOT_OK;
   }
   return result;
}

/*----------------------------------------------------------------------------*/
/**
 * \brief ErrMem_DisableMemoryLockCentralErrorLock
 *
 * Function to enable Dem Enable condition (=true)
 *
 * \global_r  none
 * \global_w  none
 * \global_rw none
 *
 * \param[out]    none
 * \param[in]     none
 *
 * \retval ERRMEMSERVICE_OK on success
 *         ERRMEMSERVICE_NOT_OK on error
 *
 * \pre none
 *
 * \post none
 *
 * \remarks none
 *
 * \lhref  DMA_PA_5105, DMA_PA_8440, DMA_PA_5111
 *
 */
/*----------------------------------------------------------------------------*/
ErrMemService_ResultType ErrMem_DisableMemoryLockCentralErrorLock(void)
{
   ErrMemService_ResultType result;
   if ( E_OK == Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition( TRUE ) )
   {
      result = ERRMEMSERVICE_OK;
   }
   else
   {
      result = ERRMEMSERVICE_NOT_OK;
   }
   return result;
}

#endif /* #if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */
