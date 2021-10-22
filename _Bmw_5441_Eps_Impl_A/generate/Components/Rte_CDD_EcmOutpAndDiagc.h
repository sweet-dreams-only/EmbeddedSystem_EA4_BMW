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
 *          File:  Rte_CDD_EcmOutpAndDiagc.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_EcmOutpAndDiagc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_ECMOUTPANDDIAGC_H
# define _RTE_CDD_ECMOUTPANDDIAGC_H

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

# include "Rte_CDD_EcmOutpAndDiagc_Type.h"
# include "Rte_DataHandleType.h"


# define CDD_EcmOutpAndDiagc_START_SEC_CODE
# include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CtrlErrOut_Oper CtrlErrOut_Oper
#  define RTE_RUNNABLE_EcmOutpAndDiagcInit2 EcmOutpAndDiagcInit2
# endif

FUNC(void, CDD_EcmOutpAndDiagc_CODE) CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_EcmOutpAndDiagc_STOP_SEC_CODE
# include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_ECMOUTPANDDIAGC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
