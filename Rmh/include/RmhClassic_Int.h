/**
*  \file
*
*  \brief       BMW SWC Rmh
*
*  This file contains the implementation of the BMW SWC RmhClassic
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.0
*
*/

#ifndef RMH_CLASSIC_INT_H
#define RMH_CLASSIC_INT_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <Std_Types.h>               /* AUTOSAR Standard Types */
#include "RmhClassic_Version.h"      /* Own version header file */
#include "RmhClassic_Cfg.h"          /* Module config header file */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of RmhClassic_Int.h does not match the version of the module!"
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

#if ((!defined RMH_PDU_TRIGGER_MODE) || \
     ( (RMH_PDU_TRIGGER_MODE != RMH_MODE_TRIGGER_IPDU_SEND) && \
       (RMH_PDU_TRIGGER_MODE != RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL) \
     ) \
    )
#error "RmhClassic_Int.h: RMH_PDU_TRIGGER_MODE is not defined."
#endif

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
#define Rmh_Cdd_START_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
#else
#define Rmh_START_SEC_CODE
#include "RmhClassic_MemMap.h"
#endif


#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
extern FUNC(P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_Cdd_CONST), Rmh_Cdd__CODE)
   Rmh_FindMapping(uint16 messageId);
#else
extern FUNC(P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_CONST), RmhClassic_CODE)
   Rmh_FindMapping(uint16 messageId);
#endif

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
#define Rmh_Cdd_STOP_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
#else
#define Rmh_STOP_SEC_CODE
#include "RmhClassic_MemMap.h"
#endif


#endif /* RMH_CLASSIC_INT_H */

/*--- End of file ------------------------------------------------------------*/
