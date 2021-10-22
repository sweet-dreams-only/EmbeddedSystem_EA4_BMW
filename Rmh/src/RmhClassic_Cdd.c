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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Deviation List:

   MISRA-0) Deviated Rule: 19.1 (required)
   #include statements in a file should only be preceded by other preprocessor
   directives or comments.


   Reason:
   AUTOSAR compiler abstraction; see EB_MISRAC2004_Compliance_Autosar.pdf v1.0.1

*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

/*--------------------[Inclusion guard]---------------------------------------*/
/**
 * \brief Macro definition of a guard for information hiding.
 */
#define RMH_CDD_CODE_GUARD
#include "RmhClassic_Cfg.h"                 /* Module config header file */

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL)

/* Avoid empty translation unit according to ISO C90 */
typedef void Rmh_PreventEmptyTranslationUnitType;

#elif (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)

#include <ComStack_Types.h>          /* AUTOSAR comstack types */
#include "RmhClassic_Version.h"             /* Own version header file */
#include "RmhClassic_Cdd.h"                 /* Module CDD API */
#include "RmhClassic_Int.h"                 /* Module internals */
#include "Com.h"                     /* AUTOSAR Com */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of RmhClassic_Cdd.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
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
/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_BEGIN_SEC_CODE */
#define Rmh_Cdd_START_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
/* PRQA L:MISRA_MEMMAP_BEGIN_SEC_CODE */

/*----------------------------------------------------------------------------*/
/**
 * \brief Description of function Rmh_TriggerComIPDUSend
 *
 * This function is part of the RMH_CDD and only needed in case the usage of
 * Com_TriggerIPDUSend API is configured.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]  messageId  This is the requested message Id (see RMH_034)
 *
 * \pre --
 *
 * \post --
 *
 * \remarks This API is only available in TIS mode.
 *
 */
/*----------------------------------------------------------------------------*/

FUNC(void, Rmh_Cdd_CODE) Rmh_TriggerComIPDUSend(uint16 messageId)
{
   P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_Cdd_CONST) mappingResult;

   mappingResult = Rmh_FindMapping(messageId);

   if ( mappingResult != NULL_PTR )
   {
      /* <req refid="RMH_019">
       * <version>1</version><coverage>SRC</coverage></req> */
      Com_TriggerIPDUSend((*mappingResult).comPduId);
   }
   /* <req refid="RMH_045">
    * <version>1</version><coverage>SRC</coverage></req> */

} /* end of function Rmh_TriggerComIPDUSend */

/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_END_SEC_CODE */
#define Rmh_Cdd_STOP_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
/* PRQA L:MISRA_MEMMAP_END_SEC_CODE */

#else
#error "Rmh_Cdd.c: RMH_PDU_TRIGGER_MODE is not defined."
#endif /* if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND) */

/*--- End of file ------------------------------------------------------------*/
