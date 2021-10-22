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
 *          File:  Rte_MotTqCalcd.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <MotTqCalcd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTTQCALCD_H
# define _RTE_MOTTQCALCD_H

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

# include "Rte_MotTqCalcd_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_MotTqCalcd_MotTqEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LoaMgr_MotAndThermProtnLoaMod_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotBackEmfConEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrQaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduDaxEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduQaxEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAndThermProtnLoaMod_Val (0U)
#  define Rte_InitValue_MotBackEmfConEstimd_Val (0.025F)
#  define Rte_InitValue_MotCurrDax_Val (0.0F)
#  define Rte_InitValue_MotCurrDaxCmd_Val (0.0F)
#  define Rte_InitValue_MotCurrQax_Val (0.0F)
#  define Rte_InitValue_MotCurrQaxCmd_Val (0.0F)
#  define Rte_InitValue_MotInduDaxEstimd_Val (0.00011889F)
#  define Rte_InitValue_MotInduQaxEstimd_Val (0.00011889F)
#  define Rte_InitValue_MotTqEstimd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAndThermProtnLoaMod_Val Rte_Read_MotTqCalcd_MotAndThermProtnLoaMod_Val
#  define Rte_Read_MotTqCalcd_MotAndThermProtnLoaMod_Val(data) (*(data) = Rte_LoaMgr_MotAndThermProtnLoaMod_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotBackEmfConEstimd_Val Rte_Read_MotTqCalcd_MotBackEmfConEstimd_Val
#  define Rte_Read_MotTqCalcd_MotBackEmfConEstimd_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotBackEmfConEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrDax_Val Rte_Read_MotTqCalcd_MotCurrDax_Val
#  define Rte_Read_MotTqCalcd_MotCurrDax_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrDaxCmd_Val Rte_Read_MotTqCalcd_MotCurrDaxCmd_Val
#  define Rte_Read_MotTqCalcd_MotCurrDaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrDaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQax_Val Rte_Read_MotTqCalcd_MotCurrQax_Val
#  define Rte_Read_MotTqCalcd_MotCurrQax_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQaxCmd_Val Rte_Read_MotTqCalcd_MotCurrQaxCmd_Val
#  define Rte_Read_MotTqCalcd_MotCurrQaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrQaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotInduDaxEstimd_Val Rte_Read_MotTqCalcd_MotInduDaxEstimd_Val
#  define Rte_Read_MotTqCalcd_MotInduDaxEstimd_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotInduDaxEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotInduQaxEstimd_Val Rte_Read_MotTqCalcd_MotInduQaxEstimd_Val
#  define Rte_Read_MotTqCalcd_MotInduQaxEstimd_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotInduQaxEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotTqEstimd_Val Rte_Write_MotTqCalcd_MotTqEstimd_Val
#  define Rte_Write_MotTqCalcd_MotTqEstimd_Val(data) (Rte_MotTqCalcd_MotTqEstimd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmMotPoleCnt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define MotTqCalcd_START_SEC_CODE
# include "MotTqCalcd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotTqCalcdInit1 MotTqCalcdInit1
#  define RTE_RUNNABLE_MotTqCalcdPer1 MotTqCalcdPer1
# endif

FUNC(void, MotTqCalcd_CODE) MotTqCalcdInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, MotTqCalcd_CODE) MotTqCalcdPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define MotTqCalcd_STOP_SEC_CODE
# include "MotTqCalcd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MOTTQCALCD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
