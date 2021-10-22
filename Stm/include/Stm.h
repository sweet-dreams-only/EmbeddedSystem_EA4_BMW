/**
*  \file
*
*  \brief       BMW SWC Stm
*
*  STM (State Monitor)
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
#ifndef STM_H
#define STM_H

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

#include "Stm_Version.h"      /* Own version header file     */
#include "Stm_Cfg.h"          /* Configuration of Stm module */
#include "BUtil/PlatformTypes.h"    /* BMW standard types */

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Stm_CHECK_VERSION(5,2,0))
   #error "Version of Stm.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON

extern void Stm_ReceivedCELUnlocked(void);
extern void Stm_ReceivedCELLocked(void);
extern void Stm_ReceivedCELInvalid(void);

extern void Stm_Level1TM_Fired(void);
extern void Stm_Level2TM_Fired(void);

extern void Stm_CELNotReceivable(void);
extern void Stm_CELReceivable(void);

#endif /*#if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON*/

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* STM_H */

/*--- End of file ------------------------------------------------------------*/
