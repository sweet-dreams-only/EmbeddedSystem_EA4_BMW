
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  FrSM_Types.h
 *    Component:  FlexRay State Manager
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Types header of FlexRay State Manager AUTOSAR Release 4
 *
 *********************************************************************************************************************/

#if !defined (FRSM_TYPES_H)
# define FRSM_TYPES_H

/**********************************************************************************************************************
* INCLUDES
**********************************************************************************************************************/

# include "Std_Types.h"
# include "ComM_Types.h"        /* included because of the ComM_ModeType */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* FrSM Types header version */
# define CCL_ASR4SMFR_TYPES_HEADER_VERSION                             0x0202
# define CCL_ASR4SMFR_TYPES_HEADER_RELEASE_VERSION                     0x00





/* \trace SPEC-10946 */
#define FRSM_BSWM_READY                       (0x00u)
#define FRSM_BSWM_READY_ECU_PASSIVE           (0x01u)
#define FRSM_BSWM_STARTUP                     (0x02u)
#define FRSM_BSWM_STARTUP_ECU_PASSIVE         (0x03u)
#define FRSM_BSWM_WAKEUP                      (0x04u)
#define FRSM_BSWM_WAKEUP_ECU_PASSIVE          (0x05u)
#define FRSM_BSWM_HALT_REQ                    (0x06u)
#define FRSM_BSWM_HALT_REQ_ECU_PASSIVE        (0x07u)
#define FRSM_BSWM_KEYSLOT_ONLY                (0x08u)
#define FRSM_BSWM_KEYSLOT_ONLY_ECU_PASSIVE    (0x09u)
#define FRSM_BSWM_ONLINE                      (0x0Au)
#define FRSM_BSWM_ONLINE_ECU_PASSIVE          (0x0Bu)
#define FRSM_BSWM_ONLINE_PASSIVE              (0x0Cu)
#define FRSM_BSWM_ONLINE_PASSIVE_ECU_PASSIVE  (0x0Du)
/* #define FRSM_LOW_NUMBER_OF_COLDSTARTERS             0x0Eu */ /* not used */
/* #define FRSM_LOW_NUMBER_OF_COLDSTARTERS_ECU_PASSIVE 0x0Fu */ /* not used */
 /* \trace  SPEC-10987 */
 /* \trace  SPEC-11013 */
 /* \trace  SPEC-2181418 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Synchronization loss indication function pointer type definition */
typedef P2FUNC(void, FRSM_APPL_CODE, FrSMSyncLossErrorIndicationFctPtrType) (  CONST (NetworkHandleType, FRSM_CODE ) NetworkHandle ); /* PRQA S 0850 */  /* MD_MSR_19.8  */

/*! FrSM BswM state type definition */
typedef uint8 FrSM_BswM_StateType;
/* \trace SPEC-11034 */





#endif /* FRSM_TYPES_H */
/********************************************************************************************************************
 * END OF FILE: FrSM_Types.h
 *******************************************************************************************************************/

