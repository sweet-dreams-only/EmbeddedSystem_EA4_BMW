/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  E2E.c
 *        \brief  E2E source file
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "E2E.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if(   (E2E_SW_MAJOR_VERSION != (1u) ) \
    || (E2E_SW_MINOR_VERSION != (2u) ))
# error "Version numbers of E2E.c and E2E.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (E2E_LOCAL) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL static
#endif

#if !defined (E2E_LOCAL_INLINE) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define E2E_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  E2E_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, E2E_CODE) E2E_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, E2E_APPL_DATA) VersionInfo)
{
  if (VersionInfo != NULL_PTR)
  {
    VersionInfo->vendorID = E2E_VENDOR_ID; /* SBSW_E2E_01 */
    VersionInfo->moduleID = E2E_MODULE_ID; /* SBSW_E2E_01 */
    VersionInfo->sw_major_version = E2E_SW_MAJOR_VERSION; /* SBSW_E2E_01 */
    VersionInfo->sw_minor_version = E2E_SW_MINOR_VERSION; /* SBSW_E2E_01 */
    VersionInfo->sw_patch_version = E2E_SW_PATCH_VERSION; /* SBSW_E2E_01 */
  }
}

# define E2E_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

 MD_EtoE_14.1: rule 14.1
      Reason:     This switch default label is unreachable. MISRA-C:2004 Rule 14.1
      Risk:       No risk. Switch default must be available due to coding guidelines,
                  but is not used. It is ensured that an error code is returned if switch default is in fact executed.
      Prevention: Program flow has been verified by component tests and review.

*/

/* START_COVERAGE_JUSTIFICATION
  \ID COV_E2E_MISRA
    \ACCEPT XX
    \REASON [MSR_COV_MISRA]

  \ID COV_E2E_COMPATIBILITY
    \ACCEPT TX
    \ACCEPT XF
    \REASON [COV_MSR_COMPATIBILITY]
END_COVERAGE_JUSTIFICATION */

/* SBSW_JUSTIFICATION_BEGIN

    \ID SBSW_E2E_01
      \DESCRIPTION The function E2E_GetVersionInfo writes to the object referenced by parameter VersionInfo.
      \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter VersionInfo is valid.

    \ID SBSW_E2E_02
      \DESCRIPTION Function is called with reference to local parameter.
      \COUNTERMEASURE \N Reference to local parameter is valid because it is initialized in every case.

    \ID SBSW_E2E_03
      \DESCRIPTION Function is called with pointer parameter. Parameter is either DataPtr, StatePtr or ConfigPtr.
      \COUNTERMEASURE \N The caller of the function ensures that the pointer passed to the parameter is valid.

    \ID SBSW_E2E_04
      \DESCRIPTION Value is assigned to parameter which is referenced by pointer NewDataAvailablePtr.
      \COUNTERMEASURE \N The caller of the function ensures that the pointer passed to the parameter NewDataAvailablePtr is valid.

    \ID SBSW_E2E_05
      \DESCRIPTION Write access to local array with static index.
      \COUNTERMEASURE \N Index of array access does not exceed array length because indexes and array length are defined statically.
SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: E2E.c
 *********************************************************************************************************************/
