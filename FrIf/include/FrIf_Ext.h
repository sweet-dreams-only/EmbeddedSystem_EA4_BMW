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
/**        \file  FrIf_Ext.h
 *        \brief  FrIf Extension header file
 *
 *      \details  Extension header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *********************************************************************************************************************/

#if (!defined  FRIF_EXT_H_)
# define FRIF_EXT_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "FrIf_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 *********************************************************************************************************************/
# if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */

#  define FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

     extern VAR(sint16_least, FRIF_VAR_ZERO_INIT) FrIf_MaxTaskDelay;
     extern VAR(sint16_least, FRIF_VAR_ZERO_INIT) FrIf_MaxTaskOverlap;

#  define FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* File version information */
# define FRIF_EXT_MAJOR_VERSION              (5u)
# define FRIF_EXT_MINOR_VERSION              (1u)
# define FRIF_EXT_PATCH_VERSION              (2u)

# if (FRIF_MEASURE_JLETASKTIMES == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FrIf_GetMaxTaskDelay()             (FrIf_MaxTaskDelay)
#  define FrIf_ResetMaxTaskDelay()           (FrIf_MaxTaskDelay = 0)
#  define FrIf_GetMaxTaskOverlap()           (-FrIf_MaxTaskOverlap)
#  define FrIf_ResetMaxTaskOverlap()         (FrIf_MaxTaskOverlap = 0)
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# if (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
/**********************************************************************************************************************
  FrIf_Enable_JLE_Timer
**********************************************************************************************************************/
/*!
 *
 * \brief        Enables the job list execution timer for a given cluster.
 * \details      Enables the job list execution timer for a given cluster when custom scheduling is enabled.
 * \param[in]    ClusterIdx    Index of the FlexRay cluster associated to the timer.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \config       Available only if FRIF_CUSTOM_JLE_SCHEDULING == STD_ON.
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_Enable_JLE_Timer(uint8 ClusterIdx);

/**********************************************************************************************************************
  FrIf_Disable_JLE_Timer
**********************************************************************************************************************/
/*!
 *
 * \brief        Disables the job list execution timer for a given cluster.
 * \details      Disables the job list execution timer for a given cluster when custom scheduling is enabled.
 * \param[in]    ClusterIdx    Index of the FlexRay cluster associated to the timer.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \config       Available only if FRIF_CUSTOM_JLE_SCHEDULING == STD_ON.
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_Disable_JLE_Timer(uint8 ClusterIdx);

/**********************************************************************************************************************
  FrIf_Set_JLE_Timer
**********************************************************************************************************************/
/*!
 *
 * \brief        Sets the job list execution timer for the given cluster.
 * \details      Sets the job list execution timer when custom scheduling is enabled.
 * \param[in]    ClusterIdx         Index of the FlexRay cluster associated to the timer.
 * \param[in]    Cycle              FlexRay cycle of the next activation of the job list execution.
 * \param[in]    MacrotickOffset    Macrotick offset of the next activation of the job list execution.
 * \param[in]    RepeatJLE          Flag indicating if the job list execution should be triggered twice.
 * \return       E_OK               The service FrIf_Set_JLE_Timer was called successfully.
 * \return       E_NOT_OK           The service FrIf_Set_JLE_Timer was called unsuccessfully.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \config       Available only if FRIF_CUSTOM_JLE_SCHEDULING == STD_ON.
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_Set_JLE_Timer(uint8 ClusterIdx,  
                                                         uint8 Cycle,  
                                                         uint16 MacrotickOffset,  
                                                         uint8 RepeatJLE);

# endif /* (FRIF_CUSTOM_JLE_SCHEDULING == STD_ON) */

# define FRIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#endif /* FRIF_EXT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Ext.h
 *********************************************************************************************************************/
