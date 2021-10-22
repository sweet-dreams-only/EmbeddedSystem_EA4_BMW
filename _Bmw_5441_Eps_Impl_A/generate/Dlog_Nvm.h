/*----------------------------------------------------------------------------*/
/**
 * \file
 *
 * \brief       Read NV-Memory into Mirror.
 *
 * \project     BMW AUTOSAR Core
 *
 * \par         To be changed by user:
 *              [no]
 *
 * \copyright   BMW AG 2015 - 2016
 *
 *  \version     5.3.1
 *
 */
/*----------------------------------------------------------------------------*/

#ifndef DLOG_NVM_H_
#define DLOG_NVM_H_


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include "DlogClassic_Cfg.h"

/* The following includes are needed by NvM_Include.h which includes this file */
#include "Dlog_Ecu.h"
#include "Dlog_SvkGen.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Nvm.c does not match the version of the module!"
#endif

   #define DLOG_NVM_BLOCK_PROG_DATA                    0x1U
   #define DLOG_NVM_BLOCK_SVK_HISTORY                  0x2U
   #define DLOG_NVM_BLOCK_SVK_SYS_SUPP                 0x3U
   #define DLOG_NVM_BLOCK_SVK_PLANT                    0x4U

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef void* Dlog_NvmMirrorPtr;

typedef enum {
   DLOG_NVM_OK,
   DLOG_NVM_NOT_OK,
   DLOG_NVM_PENDING
} Dlog_NvmBlockState;

typedef enum {
   DLOG_INITIAL,
   DLOG_PENDING
} Dlog_OpStatusType;


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


extern Dlog_NvmBlockState Dlog_WriteNvmBlockAsync
   (
      uint16 blockId,
      Dlog_NvmMirrorPtr mirror, /* PRQA S 3673 *//* configuration dependent */
      Dlog_OpStatusType OpStatus
   );

extern Std_ReturnType Dlog_WriteNvmBlock
   (
      uint16 blockId,
      Dlog_NvmMirrorPtr mirror,
      boolean wait
   );

extern Dlog_NvmBlockState Dlog_GetNvmBlockState
      (
         uint16 blockId
      );

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOG_NVM_H_ */

