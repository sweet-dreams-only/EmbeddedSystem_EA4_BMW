/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Dlog
*
*  This file contains the postbuild configuration of Dlog.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [yes/no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.3.1
*
*  \remarks     The content of this file only serves as an example. If this
*               file is platform dependent, this shall be mentioned here.
*
*/
/*----------------------------------------------------------------------------*/

#ifndef DLOG_PBCFG_H_
#define DLOG_PBCFG_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "DlogClassic_Cfg.h"


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
   #error "Version of Dlog_PBCfg.h does not match the version of the module!"
#endif

#define DLOG_MULTIPLE_CONFIG_SETS_EXIST STD_OFF

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef struct {
  uint8 EcuId;
  uint8 HweTable;
} Dlog_PBConfigType;


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CONST_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern const Dlog_PBConfigType Dlog_Config;


#define Dlog_STOP_SEC_CONST_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern const Dlog_PBConfigType* Dlog_PBConfigSetPtr;

#define Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern void Dlog_SetConfiguration(const Dlog_PBConfigType* selectedConfig);

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOG_PBCFG_H_ */

/*--- End of file ------------------------------------------------------------*/

