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
 *          File:  Rte_HwRefTqSum.h
 *        Config:  C:/Users/NZ5334/Documents/Synergy/Working/ses_dev_ea4/SF069A_HwRefTqSum_Impl/tools/Component.dpa
 *     SW-C Type:  HwRefTqSum
 *  Generated at:  Tue Feb 20 13:39:09 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <HwRefTqSum> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HWREFTQSUM_H
# define _RTE_HWREFTQSUM_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_HwRefTqSum_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_HwRefTqSum
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_HwRefTqSum, RTE_CONST, RTE_CONST) Rte_Inst_HwRefTqSum; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_HwRefTqSum, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTqCmdDampg_Val (0.0F)
# define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
# define Rte_InitValue_HwTqCmdHys_Val (0.0F)
# define Rte_InitValue_HwTqCmdOvrl_Val (0.0F)
# define Rte_InitValue_HwTqCmdSum_Val (0.0F)
# define Rte_InitValue_RtnCmd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwRefTqSum_HwTqCmdDampg_Val(P2VAR(float32, AUTOMATIC, RTE_HWREFTQSUM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwRefTqSum_HwTqCmdEffort_Val(P2VAR(float32, AUTOMATIC, RTE_HWREFTQSUM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwRefTqSum_HwTqCmdHys_Val(P2VAR(float32, AUTOMATIC, RTE_HWREFTQSUM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwRefTqSum_HwTqCmdOvrl_Val(P2VAR(float32, AUTOMATIC, RTE_HWREFTQSUM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwRefTqSum_RtnCmd_Val(P2VAR(float32, AUTOMATIC, RTE_HWREFTQSUM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwRefTqSum_HwTqCmdSum_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_HwRefTqSum_SysGlbPrmSysTqRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTqCmdDampg_Val Rte_Read_HwRefTqSum_HwTqCmdDampg_Val
# define Rte_Read_HwTqCmdEffort_Val Rte_Read_HwRefTqSum_HwTqCmdEffort_Val
# define Rte_Read_HwTqCmdHys_Val Rte_Read_HwRefTqSum_HwTqCmdHys_Val
# define Rte_Read_HwTqCmdOvrl_Val Rte_Read_HwRefTqSum_HwTqCmdOvrl_Val
# define Rte_Read_RtnCmd_Val Rte_Read_HwRefTqSum_RtnCmd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTqCmdSum_Val Rte_Write_HwRefTqSum_HwTqCmdSum_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SysGlbPrmSysTqRat_Val Rte_Prm_HwRefTqSum_SysGlbPrmSysTqRat_Val



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *
 *********************************************************************************************************************/


# define HwRefTqSum_START_SEC_CODE
# include "HwRefTqSum_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwRefTqSumInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwRefTqSumInit1 HwRefTqSumInit1
FUNC(void, HwRefTqSum_CODE) HwRefTqSumInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwRefTqSumPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTqCmdDampg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdEffort_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdHys_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdSum_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwRefTqSumPer1 HwRefTqSumPer1
FUNC(void, HwRefTqSum_CODE) HwRefTqSumPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define HwRefTqSum_STOP_SEC_CODE
# include "HwRefTqSum_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_HWREFTQSUM_H */

#include "Rte_Stubs.h"
