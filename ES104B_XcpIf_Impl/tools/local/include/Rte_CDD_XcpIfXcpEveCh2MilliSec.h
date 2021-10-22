/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_XcpIfXcpEveCh2MilliSec.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.15.0
 *                 RTE Core Version 1.15.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_XcpIfXcpEveCh2MilliSec>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_XCPIFXCPEVECH2MILLISEC_H
# define _RTE_CDD_XCPIFXCPEVECH2MILLISEC_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_XcpIfXcpEveCh2MilliSec_Type.h"
# include "Rte_DataHandleType.h"


# define CDD_XcpIfXcpEveCh2MilliSec_START_SEC_CODE
# include "CDD_XcpIfXcpEveCh2MilliSec_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDD_XcpIfXcpEveCh2MilliSecPer1 CDD_XcpIfXcpEveCh2MilliSecPer1
# endif

FUNC(void, CDD_XcpIfXcpEveCh2MilliSec_CODE) CDD_XcpIfXcpEveCh2MilliSecPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_XcpIfXcpEveCh2MilliSec_STOP_SEC_CODE
# include "CDD_XcpIfXcpEveCh2MilliSec_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_XCPIFXCPEVECH2MILLISEC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
