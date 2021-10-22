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
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr_Ext.h
 *        \brief  FlexRay Driver external header file
 *
 *      \details  External header for FlexRay Driver according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined FR_EXT_H)
# define FR_EXT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Fr_GeneralTypes.h"
# include "Fr_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define Fr_IsPostbuild() ((FR_POSTBUILD_VARIANT_SUPPORT == STD_ON) || (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE))
# define Fr_IsPreCompile() ((FR_POSTBUILD_VARIANT_SUPPORT == STD_OFF) && (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_PRECOMPILE))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Application Callbacks */
# define FR_APPL_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */


# if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON) /* COV_FR_TESTSUITE_INSTRUMENTATION */
/**********************************************************************************************************************
 *  ApplFr_ISR_CycleStart()
 *********************************************************************************************************************/
/*! \brief        Cycle start interrupt callback function.
 *  \details      This callback is called when a new communication cycle starts. This callback is only called if the the 
 *                physical layer is synchronous with the network.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_APPL_CALLBACK_CYCLE_START
 *********************************************************************************************************************/
     extern FUNC(void, FR_APPL_CODE) ApplFr_ISR_CycleStart(void);

#  if (FR_NUM_CTRL_USED > 1)
/**********************************************************************************************************************
 *  ApplFr_ISR_CycleStart_1()
 *********************************************************************************************************************/
/*! \brief        Cycle start interrupt callback function.
 *  \details      This callback is called when a new communication cycle starts. This callback is only called if the the 
 *                physical layer is synchronous with the network.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_APPL_CALLBACK_CYCLE_START and FR_NUM_CTRL_USED
 *********************************************************************************************************************/
     extern FUNC(void, FR_APPL_CODE) ApplFr_ISR_CycleStart_1(void);
#  endif

# endif

# if (FR_CFG_APPL_CALLBACK_TIMER0 == STD_ON)
/**********************************************************************************************************************
 *  ApplFr_ISR_Timer0()
 *********************************************************************************************************************/
/*! \brief        Absolute timer interrupt callback function.
 *  \details      This callback is called when the absolute timer elapsed. This callback is only called if the the 
 *                physical layer is synchronous with the network.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_APPL_CALLBACK_TIMER0
 *********************************************************************************************************************/
     extern FUNC(void, FR_APPL_CODE) ApplFr_ISR_Timer0(void);

#  if (FR_NUM_CTRL_USED > 1)
/**********************************************************************************************************************
 *  ApplFr_ISR_Timer0_1()
 *********************************************************************************************************************/
/*! \brief        Absolute timer interrupt callback function.
 *  \details      This callback is called when the absolute timer elapsed. This callback is only called if the the 
 *                physical layer is synchronous with the network.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_APPL_CALLBACK_TIMER0 and FR_NUM_CTRL_USED
 *********************************************************************************************************************/
     extern FUNC(void, FR_APPL_CODE) ApplFr_ISR_Timer0_1(void);
#  endif
# endif


# define FR_APPL_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/***** end of header file ********************************************************************************************/
#endif/* ifndef FR_EXT_H */

