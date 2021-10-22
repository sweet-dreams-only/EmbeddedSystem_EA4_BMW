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
#include "RmhClassic.h"              /* Module header file */
#include "RmhClassic_Int.h"          /* Module internals */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of RmhClassic.c does not match the version of the module!"
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
#define Rmh_START_SEC_CODE
#include "RmhClassic_MemMap.h"
/* PRQA L:MISRA_MEMMAP_BEGIN_SEC_CODE */

/*----------------------------------------------------------------------------*/
/**
 * \brief Description of function Rmh_RxRequestMsg
 *
 * Function is called by RTE in case new data is received by Com.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
/*----------------------------------------------------------------------------*/

FUNC(void, Rmh_CODE) Rmh_RxRequestMsg(void)
{
   uint16 messageId;

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL)
P2CONST(Rmh_RMComIPduMappingType, AUTOMATIC, Rmh_CONST) mappingResult;
#endif

   (void)Rte_Read_RxRequestedMsgID_requestedMsgID(&messageId);

   if ( messageId == RMH_RMID_INVALID_VALUE )
   {
#if (RMH_DEV_ERROR_DETECT == STD_ON)
      (void)Rte_Call_Det_ReportError((uint8)RMH_INSTANCE_ID,
                                     (uint8)RMH_RXREQUESTMSG_ID,
                                     (uint8)RMH_E_PARAM
                                    );
#endif
   }
   else
   {

#if (RMH_PDU_TRIGGER_MODE == RMH_MODE_TRIGGER_IPDU_SEND)
      (void)Rte_Call_TriggerIPDUSend_Rmh_TriggerComIPDUSend(messageId);
#else
      mappingResult = Rmh_FindMapping(messageId);

      if ( mappingResult != NULL_PTR )
      {
/* <req refid="RMH_006">
 * <version>2</version><coverage>SRC</coverage></req> */
#if (RMH_DEV_ERROR_DETECT == STD_ON)
         if ( (*mappingResult).dummyTriggerFuncPtr(RMH_TRIGGER_VALUE)
                    != RTE_E_OK
            )
         {
            /* <req refid="RMH_008">
             * <version>1</version><coverage>SRC</coverage></req> */
            /* <req refid="RMH_015">
             * <version>1</version><coverage>SRC</coverage></req> */
            (void)Rte_Call_Det_ReportError((uint8)RMH_INSTANCE_ID,
                                           (uint8)RMH_RXREQUESTMSG_ID,
                                           (uint8)RMH_E_RETURN
                                          );
         }
#else
         (void)(*mappingResult).dummyTriggerFuncPtr(RMH_TRIGGER_VALUE);
#endif
      }
/* <req refid="RMH_012">
 * <version>1</version><coverage>SRC</coverage></req> */
#endif
   }

} /* end of function Rmh_RxRequestMsg */

/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_END_SEC_CODE */
#define Rmh_STOP_SEC_CODE
#include "RmhClassic_MemMap.h"
/* PRQA L:MISRA_MEMMAP_END_SEC_CODE */

/*--- End of file ------------------------------------------------------------*/
