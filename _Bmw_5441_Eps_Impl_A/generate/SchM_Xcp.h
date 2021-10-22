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
 *          File:  SchM_Xcp.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Xcp>
 *********************************************************************************************************************/
#ifndef SCHM_XCP_H
# define SCHM_XCP_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Xcp_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# define XCP_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, XCP_CODE) FrXcp_MainFunctionRx(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, XCP_CODE) FrXcp_MainFunctionTx(void); /* PRQA S 3451 */ /* MD_Rte_3451 */
FUNC(void, XCP_CODE) Xcp_MainFunction(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define XCP_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define SchM_Enter_Xcp_CANXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_CANXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_1()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_1()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_2()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_2()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_TCPIPXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_TCPIPXCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_2()  /* RteAnalyzer(ExclusiveArea, NONE) */

# define SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_2()  /* RteAnalyzer(ExclusiveArea, NONE) */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_XCP_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
