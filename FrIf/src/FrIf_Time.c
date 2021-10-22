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
/**        \file  FrIf_Time.c
 *        \brief  FrIf Time source file
 *
 *      \details  Implementation of the global time access according to:
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

#define FRIF_TIME_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of FrIf.h */
#if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
    || (FRIF_SW_MINOR_VERSION != (1u)) \
    || (FRIF_SW_PATCH_VERSION != (2u)) )
# error "Version numbers of FrIf_Time.c and FrIf.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_API_AS_MACRO == STD_OFF)
/**********************************************************************************************************************
 *  FrIf_GetGlobalTime()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetGlobalTime(FRIF_VCTRL_ONLY,
                                                  P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_CyclePtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_MacroTickPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRIF_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRIF_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check that the FrIf is initialized. \trace SPEC-29878 */
  if (!FRIF_IS_INITIALIZED())
  {
    errorId = FRIF_E_NOT_INITIALIZED;
  }
  /* #20 If required, check the validity of the FlexRay CC index given as input. \trace SPEC-29837 */
  else if (FRIF_VCTRL_IDX >= FrIf_GetNumberOfControllers()) /* PRQA S 3201, 3325 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */ /* COV_FRIF_CTRL_OPTIMIZATION */
  {
    errorId = FRIF_E_INV_CTRL_IDX;
  }
  else
#endif
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If the initial checks are passed or not required: */
  {
    /* #40 Call Fr_GetGlobalTime with the cycle/offset pointers and untranslated CC index as arguments. \trace SPEC-29842 */
    /* SPEC-29842 Dev: Multiple FlexRay CCs are currently not supported, so no index translation is required */
    retVal = Fr_GetGlobalTime(FRIF_VCTRL_IDX, FrIf_CyclePtr, FrIf_MacroTickPtr);        /* SBSW_FRIF_FCT_CALL_PTRFWD */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRIF_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRIF_E_NO_ERROR)
  {
    (void)Det_ReportError(FRIF_MODULE_ID, 0, FRIF_SID_GETGLOBALTIME, errorId);
  }
#else
  FRIF_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal; 
} /* FrIf_GetGlobalTime() */
#endif /* if (FRIF_API_AS_MACRO == STD_OFF) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Time.c
 *********************************************************************************************************************/
