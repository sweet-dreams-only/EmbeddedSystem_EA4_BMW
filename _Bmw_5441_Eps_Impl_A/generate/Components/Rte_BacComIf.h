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
 *          File:  Rte_BacComIf.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BacComIf>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BACCOMIF_H
# define _RTE_BACCOMIF_H

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

# include "Rte_BacComIf_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_1_NO_VECH_1(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_1_NO_VECH_1(P2VAR(NO_VECH_1, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_2_NO_VECH_2(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_2_NO_VECH_2(P2VAR(NO_VECH_2, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_3_NO_VECH_3(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_3_NO_VECH_3(P2VAR(NO_VECH_3, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_4_NO_VECH_4(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_4_NO_VECH_4(P2VAR(NO_VECH_4, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_5_NO_VECH_5(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_5_NO_VECH_5(P2VAR(NO_VECH_5, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_6_NO_VECH_6(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_6_NO_VECH_6(P2VAR(NO_VECH_6, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_7_NO_VECH_7(P2VAR(uint8, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BacComIf_NO_VECH_7_NO_VECH_7(P2VAR(NO_VECH_7, AUTOMATIC, RTE_BACCOMIF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BacComIf_ComVin_ComVin(P2CONST(Vin_ComVinType, AUTOMATIC, RTE_BACCOMIF_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_NO_VECH_1_NO_VECH_1 Rte_Read_BacComIf_NO_VECH_1_NO_VECH_1
#  define Rte_Read_NO_VECH_2_NO_VECH_2 Rte_Read_BacComIf_NO_VECH_2_NO_VECH_2
#  define Rte_Read_NO_VECH_3_NO_VECH_3 Rte_Read_BacComIf_NO_VECH_3_NO_VECH_3
#  define Rte_Read_NO_VECH_4_NO_VECH_4 Rte_Read_BacComIf_NO_VECH_4_NO_VECH_4
#  define Rte_Read_NO_VECH_5_NO_VECH_5 Rte_Read_BacComIf_NO_VECH_5_NO_VECH_5
#  define Rte_Read_NO_VECH_6_NO_VECH_6 Rte_Read_BacComIf_NO_VECH_6_NO_VECH_6
#  define Rte_Read_NO_VECH_7_NO_VECH_7 Rte_Read_BacComIf_NO_VECH_7_NO_VECH_7


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ComVin_ComVin Rte_Write_BacComIf_ComVin_ComVin


# endif /* !defined(RTE_CORE) */


# define BacComIf_START_SEC_CODE
# include "BacComIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_VehicleState VehicleState
#  define RTE_RUNNABLE_VinUpdate VinUpdate
# endif

FUNC(void, BacComIf_CODE) VehicleState(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BacComIf_CODE) VinUpdate(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BacComIf_STOP_SEC_CODE
# include "BacComIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BACCOMIF_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
