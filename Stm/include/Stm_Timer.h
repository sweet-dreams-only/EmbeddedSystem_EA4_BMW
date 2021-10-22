/**
*  \file
*
*  \brief       Stm Timer Interface
*
*  This file contains the interface definition for the Stm Timer.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef STM_TIMER_H
#define STM_TIMER_H

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

#include "StmClassic_Version.h"
#include "StmClassic_Cfg.h"
#include "Stm_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_Timer.h does not match the Classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef enum {
   STM_TIMER_NONE,
   STM_TIMER_LEVEL1TM,
   STM_TIMER_LEVEL2TM
} Stm_Timer_LevelType;

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

extern void Stm_Timer_StartLevel1TM(void);
extern void Stm_Timer_StartLevel2TM(void);

extern void Stm_Timer_FireTimeout(void);

extern void Stm_Timer_Cancel(void);

#if STM_COM_VARIANT_FIELDS == STD_ON
extern void Stm_TimeoutSupervision(void);
#endif /*#if STM_COM_VARIANT_FIELDS == STD_ON*/

#endif /* #if STM_CENTRAL_ERROR_LOCK_ENABLED == STD_ON */

#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */

#endif /* STM_TIMER_H */

/*--- End of file ------------------------------------------------------------*/
