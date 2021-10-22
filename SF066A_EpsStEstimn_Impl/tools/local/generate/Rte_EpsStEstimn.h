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
 *          File:  Rte_EpsStEstimn.h
 *        Config:  C:/_Synergy_Projects/New_Working/SF066A_EpsStEstimn_Impl/tools/Component.dpa
 *     SW-C Type:  EpsStEstimn
 *  Generated at:  Sat Apr 21 09:56:04 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <EpsStEstimn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_EPSSTESTIMN_H
# define _RTE_EPSSTESTIMN_H

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

# include "Rte_EpsStEstimn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_EpsStEstimn
{
  /* PIM Handles section */
  P2VAR(Ary1D_f32_5, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StEstimrStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_EpsStEstimn, RTE_CONST, RTE_CONST) Rte_Inst_EpsStEstimn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_EpsStEstimn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_MotTqEstimd_Val (0.0F)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_PinionTqToRackFInstsRat_Val (60.0F)
# define Rte_InitValue_RackFEstimd_Val (0.0F)
# define Rte_InitValue_SysKineRat_Val (10.0F)
# define Rte_InitValue_SysTqRat_Val (10.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_MotTqEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_PinionTqToRackFInstsRat_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_SysKineRat_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EpsStEstimn_SysTqRat_Val(P2VAR(float32, AUTOMATIC, RTE_EPSSTESTIMN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EpsStEstimn_RackFEstimd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EpsStEstimn_TorsBarStEstimd_Rec(P2CONST(TorsBarStEstimdRec1, AUTOMATIC, RTE_EPSSTESTIMN_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxA_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxA_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxB_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_3, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxB_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxC_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxC_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxD_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_3, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_EpsStEstimn_EpsStEstimnMtrxD_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq_Val Rte_Read_EpsStEstimn_HwTq_Val
# define Rte_Read_MotTqEstimd_Val Rte_Read_EpsStEstimn_MotTqEstimd_Val
# define Rte_Read_MotVelCrf_Val Rte_Read_EpsStEstimn_MotVelCrf_Val
# define Rte_Read_PinionTqToRackFInstsRat_Val Rte_Read_EpsStEstimn_PinionTqToRackFInstsRat_Val
# define Rte_Read_SysKineRat_Val Rte_Read_EpsStEstimn_SysKineRat_Val
# define Rte_Read_SysTqRat_Val Rte_Read_EpsStEstimn_SysTqRat_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_RackFEstimd_Val Rte_Write_EpsStEstimn_RackFEstimd_Val
# define Rte_Write_TorsBarStEstimd_Rec Rte_Write_EpsStEstimn_TorsBarStEstimd_Rec


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_EpsStEstimnMtrxA_Ary2D Rte_Prm_EpsStEstimn_EpsStEstimnMtrxA_Ary2D

# define Rte_Prm_EpsStEstimnMtrxB_Ary2D Rte_Prm_EpsStEstimn_EpsStEstimnMtrxB_Ary2D

# define Rte_Prm_EpsStEstimnMtrxC_Ary2D Rte_Prm_EpsStEstimn_EpsStEstimnMtrxC_Ary2D

# define Rte_Prm_EpsStEstimnMtrxD_Ary2D Rte_Prm_EpsStEstimn_EpsStEstimnMtrxD_Ary2D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_StEstimrStPrev() (*Rte_Inst_EpsStEstimn->Pim_StEstimrStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_StEstimrStPrev() (Rte_Inst_EpsStEstimn->Pim_StEstimrStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_StEstimrStPrev(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 *Rte_Prm_EpsStEstimnMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *   float32 *Rte_Prm_EpsStEstimnMtrxC_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxD_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *
 *********************************************************************************************************************/


# define EpsStEstimn_START_SEC_CODE
# include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_EpsStEstimnInit1 EpsStEstimnInit1
FUNC(void, EpsStEstimn_CODE) EpsStEstimnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionTqToRackFInstsRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysKineRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysTqRat_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RackFEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_TorsBarStEstimd_Rec(const TorsBarStEstimdRec1 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_EpsStEstimnPer1 EpsStEstimnPer1
FUNC(void, EpsStEstimn_CODE) EpsStEstimnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define EpsStEstimn_STOP_SEC_CODE
# include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_EPSSTESTIMN_H */

#include "Rte_Stubs.h"
