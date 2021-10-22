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
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FrIf_Cbk.h
 *        \brief  FrIf Callback header file
 *
 *      \details  Callback header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#if (!defined FRIF_CBK_H_)
# define FRIF_CBK_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Cfg.h"          /* for FRIF_USE_FRTRCV_API */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* File version information */
# define FRIF_CBK_MAJOR_VERSION              (5u)
# define FRIF_CBK_MINOR_VERSION              (1u)
# define FRIF_CBK_PATCH_VERSION              (2u)

# if (FRIF_USE_FRTRCV_API == STD_ON)
#  include "Fr_GeneralTypes.h" /* They include standard types in turn */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#  define FRIF_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_CheckWakeupByTransceiver
**********************************************************************************************************************/
/*!
 *
 * \brief        Triggers the notification of bus wake-up events for a given FlexRay Transceiver Driver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_CheckWakeupByTransceiver().
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 * \param[in]    FrIf_ChnlIdx    Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                               FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105572
 * \trace        SPEC-29957
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_CheckWakeupByTransceiver(uint8 FrIf_CtrlIdx,
                                                    Fr_ChannelType FrIf_ChnlIdx );

#  define FRIF_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# endif /* if (FRIF_USE_FRTRCV_API == STD_ON) */


#endif
/* FRIF_CBK_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Cbk.h
 *********************************************************************************************************************/
