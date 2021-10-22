/**
*  \file
*
*  \brief
*
*  Configuration for RmhClassic Module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.0.0
*
*  \remarks     File is generated with PAGe
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.441032
*
------------------------------------------------------------------------------*/

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
#include "RmhClassic_Cfg.h"                 /* Rmh configuration header file */
#include <Com.h>                            /* Com header file for symbolic name values of ComPduIds */
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of RmhClassic_Cfg.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/* Deviation MISRA-0 */ /* PRQA S 5087 MISRA_MEMMAP_BEGIN_SEC_CONST_UNSPECIFIED */
#define Rmh_Cdd_START_SEC_CONST_UNSPECIFIED
#include "RmhClassic_Cdd_MemMap.h"
/* PRQA L:MISRA_MEMMAP_BEGIN_SEC_CONST_UNSPECIFIED */

/**
* \brief constant Rmh_RMComIPduMapping
*
* Constant contains the configured requestMsgId <--> Com I-PDU mapping
* (RMH_MODE_TRIGGER_IPDU_SEND) or requestMsgId <--> S/R provide port
* (RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL) mapping
*
*/
CONST(Rmh_RMComIPduMappingType, Rmh_Cdd_CONST) Rmh_RMComIPduMapping[RMH_MAPPED_ELEM_COUNT] =
{
  { (PduIdType)ComConf_ComIPdu_SU_EPS_19255f18, 13316U }
};
#define Rmh_Cdd_STOP_SEC_CONST_UNSPECIFIED
#include "RmhClassic_Cdd_MemMap.h"



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

/*--- End of file ------------------------------------------------------------*/
