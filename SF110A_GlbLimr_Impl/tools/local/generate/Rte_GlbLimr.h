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
 *          File:  Rte_GlbLimr.h
 *        Config:  C:/_S/work/ses_dev_ea4/SF110A_GlbLimr_Impl-z172399/SF110A_GlbLimr_Impl/tools/Component.dpa
 *     SW-C Type:  GlbLimr
 *  Generated at:  Fri Apr 20 09:39:24 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <GlbLimr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GLBLIMR_H
# define _RTE_GLBLIMR_H

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

# include "Rte_GlbLimr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_GlbLimr
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_GlbLimrNotch1Fil1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_GlbLimrNotch1Fil2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_GlbLimrNotch2Fil1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_GlbLimrNotch2Fil2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_GlbLimr, RTE_CONST, RTE_CONST) Rte_Inst_GlbLimr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_GlbLimr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_LimdMotTqCmd_Val (0.0F)
# define Rte_InitValue_MotTqCmd_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GlbLimr_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_GLBLIMR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GlbLimr_MotTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_GLBLIMR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GlbLimr_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_GLBLIMR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_GlbLimr_LimdMotTqCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s4p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrBndX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_s4p11_10_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrBndX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s4p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrBndY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_s4p11_10_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrBndY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC_P2CONST(FilNotchGainRec1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_GlbLimr_GlbLimrNotchFilStruct_Rec(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq_Val Rte_Read_GlbLimr_HwTq_Val
# define Rte_Read_MotTqCmd_Val Rte_Read_GlbLimr_MotTqCmd_Val
# define Rte_Read_VehSpd_Val Rte_Read_GlbLimr_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_LimdMotTqCmd_Val Rte_Write_GlbLimr_LimdMotTqCmd_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_GlbLimrBndX_Ary2D Rte_Prm_GlbLimr_GlbLimrBndX_Ary2D

# define Rte_Prm_GlbLimrBndY_Ary2D Rte_Prm_GlbLimr_GlbLimrBndY_Ary2D

# define Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D Rte_Prm_GlbLimr_GlbLimrVehSpdBilnrSeln_Ary1D

# define Rte_Prm_GlbLimrNotchFilStruct_Rec Rte_Prm_GlbLimr_GlbLimrNotchFilStruct_Rec

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_GlbLimrNotch1Fil1() (Rte_Inst_GlbLimr->Pim_GlbLimrNotch1Fil1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_GlbLimrNotch1Fil2() (Rte_Inst_GlbLimr->Pim_GlbLimrNotch1Fil2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_GlbLimrNotch2Fil1() (Rte_Inst_GlbLimr->Pim_GlbLimrNotch2Fil1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_GlbLimrNotch2Fil2() (Rte_Inst_GlbLimr->Pim_GlbLimrNotch2Fil2) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_GlbLimrNotch1Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch1Fil2(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil2(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   s4p11 *Rte_Prm_GlbLimrBndX_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   s4p11 *Rte_Prm_GlbLimrBndY_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   u9p7 *Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   FilNotchGainRec1 *Rte_Prm_GlbLimrNotchFilStruct_Rec(void)
 *
 *********************************************************************************************************************/


# define GlbLimr_START_SEC_CODE
# include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GlbLimrInit1 GlbLimrInit1
FUNC(void, GlbLimr_CODE) GlbLimrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrPer1
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
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LimdMotTqCmd_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GlbLimrPer1 GlbLimrPer1
FUNC(void, GlbLimr_CODE) GlbLimrPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define GlbLimr_STOP_SEC_CODE
# include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GLBLIMR_H */

#include "Rte_Stubs.h"
