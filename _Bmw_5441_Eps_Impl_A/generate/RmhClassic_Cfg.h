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
*  GENERATION TIME : 2018-07-30 19:57:39.476035
*
------------------------------------------------------------------------------*/

#ifndef RMH_CLASSIC_CFG_H
#define RMH_CLASSIC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <RmhClassic_Version.h>             /* Own version header file */
#include <ComStack_Types.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
#error "Version of RmhClassic_Cfg.h does not match the version of the module!"
#endif

#if (defined RMH_MODE_TRIGGER_IPDU_SEND) /* to prevent double declaration */
#error "RmhClassic_Cfg.h: RMH_MODE_TRIGGER_IPDU_SEND already defined"
#endif


/**
 * \brief Macro definition of mode RMH_MODE_TRIGGER_IPDU_SEND
 */
#define RMH_MODE_TRIGGER_IPDU_SEND               0U

#if (defined RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL)
#error "RmhClassic_Cfg.h: RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL already defined"
#endif

/**
 * \brief Macro definition of mode RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL
 */
#define RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL      1U

#if (defined RMH_DEV_ERROR_DETECT)
#error "RmhClassic_Cfg.h: RMH_DEV_ERROR_DETECT already defined"
#endif


/**
 * \brief Det reporting switch
 *
 * Switch, indicating if development error detection is activated for Rmh
 *
 * \remarks This macro depends on configuration parameter RmhDevErrorDetect
 *
 */
#define RMH_DEV_ERROR_DETECT          STD_OFF


#if (defined RMH_PDU_TRIGGER_MODE)
#error "RmhClassic_Cfg.h: RMH_PDU_TRIGGER_MODE already defined"
#endif

/**
 *  \brief RMH_PDU_TRIGGER_MODE
 *
 * Switch, indicating the configured trigger mode. (TIS or ZLTS)
 *
 * \remarks This macro depends on configuration parameter RmhPduTriggerMode
 *
 */
#define RMH_PDU_TRIGGER_MODE  RMH_MODE_TRIGGER_IPDU_SEND

#if (defined RMH_MAPPED_ELEM_COUNT)
#error "RmhClassic_Cfg.h: RMH_MAPPED_ELEM_COUNT already defined"
#endif

/**
 * \brief RMH_MAPPED_ELEM_COUNT
 *
 * Macro definition with count of all mapped elements in Rmh configuration.
 *
 * \remarks This macro depends on configuration parameter RmhRequestPduMapping
 *
 */
#define RMH_MAPPED_ELEM_COUNT     1U

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
/**
 * \brief struct Rmh_RMComIPduMappingType
 *
 *  Note: The member comPduId is only available in TIS mode. If ZLTS mode is
 *        used the member dummyTriggerFuncPtr is used.
 *
 * This structure contains the mapping between a request message id and his
 * corresponding Com I-PDU(RMH_MODE_TRIGGER_IPDU_SEND) respectively S/R provide
 * port (RMH_MODE_ZERO_LENGTH_TRIGGER_SIGNAL)
 *
 */
typedef struct
{
  /** member stores the corresponding Com I-PDU */
  PduIdType comPduId;
  /** member stores the requestable message Id */
  uint16 requestedMsgId;
} Rmh_RMComIPduMappingType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/
#define Rmh_Cdd_START_SEC_CONST_UNSPECIFIED
#include "RmhClassic_Cdd_MemMap.h"

extern CONST(Rmh_RMComIPduMappingType, Rmh_Cdd_CONST) Rmh_RMComIPduMapping[RMH_MAPPED_ELEM_COUNT];

#define Rmh_Cdd_STOP_SEC_CONST_UNSPECIFIED
#include "RmhClassic_Cdd_MemMap.h"

#endif /* RMH_CLASSIC_CFG_H */

/*--- End of file ------------------------------------------------------------*/
