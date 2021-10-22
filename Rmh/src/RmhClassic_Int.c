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

#include <Std_Types.h>               /* AUTOSAR standard types */
#include "RmhClassic_Version.h"      /* Own version header file */
#include "RmhClassic_Int.h"          /* Module internal header file */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of Rmh_Int.c does not match the version of the module!"
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

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_BEGIN_SEC_CODE1 */
#define Rmh_Cdd_START_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
/* PRQA L:MISRA_MEMMAP_BEGIN_SEC_CODE1 */
#else
/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_BEGIN_SEC_CODE2 */
#define Rmh_START_SEC_CODE
#include "RmhClassic_MemMap.h"
/* PRQA L:MISRA_MEMMAP_BEGIN_SEC_CODE2 */
#endif

/*----------------------------------------------------------------------------*/
/**
 * \brief Description of function Rmh_FindMapping
 *
 * This function find a existant mapping element related to the messageId,
 * which coresponds to the Rmh configuration.
 *
 * \global_r  Rmh_RMComIPduMapping
 * \global_w  --
 * \global_rw --
 *
 * \param[in]  messageId  This is the requested message Id (see RMH_034)
 *
 * \return Rmh_RMComIPduMappingType
 * \retval Pointer2MappingElement Pointer to the requested element.
 * \retval NULL_PTR If there is no mapping.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
/*----------------------------------------------------------------------------*/

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
FUNC(P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_Cdd_CONST), Rmh_Cdd_CODE)
   Rmh_FindMapping(uint16 messageId)
#else
FUNC(P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_CONST), Rmh_CODE)
   Rmh_FindMapping(uint16 messageId)
#endif
{
   uint16_least loopVal;

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
   P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_Cdd_CONST) mappingResult = NULL_PTR;
#else
   P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_CONST) mappingResult = NULL_PTR;
#endif

   for (loopVal=0U ; loopVal<RMH_MAPPED_ELEM_COUNT ; ++loopVal)
   {
      if ( messageId == Rmh_RMComIPduMapping[loopVal].requestedMsgId )
      {
         mappingResult = &Rmh_RMComIPduMapping[loopVal];
         break;
      }
   }
   return mappingResult;

} /* end of function Rmh_FindMapping */

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_END_SEC_CODE1 */
#define Rmh_Cdd_STOP_SEC_CODE
#include "RmhClassic_Cdd_MemMap.h"
/* PRQA L:MISRA_MEMMAP_END_SEC_CODE1 */
#else
/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_END_SEC_CODE2 */
#define Rmh_STOP_SEC_CODE
#include "RmhClassic_MemMap.h"
/* PRQA L:MISRA_MEMMAP_END_SEC_CODE2 */
#endif

/*--- End of file ------------------------------------------------------------*/
