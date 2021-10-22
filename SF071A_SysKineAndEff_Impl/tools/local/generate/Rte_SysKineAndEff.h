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
 *          File:  Rte_SysKineAndEff.h
 *        Config:  C:/Component/SF071A_SysKineAndEff_Impl/tools/Component.dpa
 *     SW-C Type:  SysKineAndEff
 *  Generated at:  Fri Mar 23 13:15:56 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <SysKineAndEff> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SYSKINEANDEFF_H
# define _RTE_SYSKINEANDEFF_H

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

# include "Rte_SysKineAndEff_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_SysKineAndEff
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmplncErrDerivtvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmplncErrPinionToHwPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_SysKineAndEff, RTE_CONST, RTE_CONST) Rte_Inst_SysKineAndEff; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_SysKineAndEff, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CmplncErrPinionToHw_Val (0.0F)
# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_HwVel_Val (0.0F)
# define Rte_InitValue_MotAgCumvAlgndMrf_Val (0)
# define Rte_InitValue_MotAgToRackPosnInstsRat_Val (0.01F)
# define Rte_InitValue_MotToRackFInstsRat_Val (3000.0F)
# define Rte_InitValue_MotToRackInstsEff_Val (0.86F)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_PinionAg_Val (0.0F)
# define Rte_InitValue_PinionAgToRackInstsEff_Val (0.92F)
# define Rte_InitValue_PinionAgToRackPosnInstsRat_Val (10.0F)
# define Rte_InitValue_PinionTqToRackFInstsRat_Val (200.0F)
# define Rte_InitValue_PinionVel_Val (0.0F)
# define Rte_InitValue_RackPosn_Val (0.0F)
# define Rte_InitValue_RackVel_Val (0.0F)
# define Rte_InitValue_RoadWhlAg_Val (0.0F)
# define Rte_InitValue_SteerArmLen_Val (200.0F)
# define Rte_InitValue_SysAssiTqRat_Val (26.0F)
# define Rte_InitValue_SysKineRat_Val (28.0F)
# define Rte_InitValue_SysTqRat_Val (26.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SysKineAndEff_CmplncErrPinionToHw_Val(P2VAR(float32, AUTOMATIC, RTE_SYSKINEANDEFF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SysKineAndEff_MotAgCumvAlgndMrf_Val(P2VAR(s18p13, AUTOMATIC, RTE_SYSKINEANDEFF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SysKineAndEff_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_SYSKINEANDEFF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SysKineAndEff_PinionAg_Val(P2VAR(float32, AUTOMATIC, RTE_SYSKINEANDEFF_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_HwAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_HwVel_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_MotAgToRackPosnInstsRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_MotToRackFInstsRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_MotToRackInstsEff_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_PinionAgToRackInstsEff_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_PinionAgToRackPosnInstsRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_PinionTqToRackFInstsRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_PinionVel_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_RackPosn_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_RackVel_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_RoadWhlAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_SteerArmLen_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_SysAssiTqRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_SysKineRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SysKineAndEff_SysTqRat_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s15p0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotAgScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s15p0_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotAgScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotToRackEffScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffMotToRackEffScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u5p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u5p11_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffPinionToRackEffScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffPinionToRackEffScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s8p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s8p7_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s2p13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s2p13_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_21, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_SysKineAndEff_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CmplncErrPinionToHw_Val Rte_Read_SysKineAndEff_CmplncErrPinionToHw_Val
# define Rte_Read_MotAgCumvAlgndMrf_Val Rte_Read_SysKineAndEff_MotAgCumvAlgndMrf_Val
# define Rte_Read_MotVelCrf_Val Rte_Read_SysKineAndEff_MotVelCrf_Val
# define Rte_Read_PinionAg_Val Rte_Read_SysKineAndEff_PinionAg_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwAg_Val Rte_Write_SysKineAndEff_HwAg_Val
# define Rte_Write_HwVel_Val Rte_Write_SysKineAndEff_HwVel_Val
# define Rte_Write_MotAgToRackPosnInstsRat_Val Rte_Write_SysKineAndEff_MotAgToRackPosnInstsRat_Val
# define Rte_Write_MotToRackFInstsRat_Val Rte_Write_SysKineAndEff_MotToRackFInstsRat_Val
# define Rte_Write_MotToRackInstsEff_Val Rte_Write_SysKineAndEff_MotToRackInstsEff_Val
# define Rte_Write_PinionAgToRackInstsEff_Val Rte_Write_SysKineAndEff_PinionAgToRackInstsEff_Val
# define Rte_Write_PinionAgToRackPosnInstsRat_Val Rte_Write_SysKineAndEff_PinionAgToRackPosnInstsRat_Val
# define Rte_Write_PinionTqToRackFInstsRat_Val Rte_Write_SysKineAndEff_PinionTqToRackFInstsRat_Val
# define Rte_Write_PinionVel_Val Rte_Write_SysKineAndEff_PinionVel_Val
# define Rte_Write_RackPosn_Val Rte_Write_SysKineAndEff_RackPosn_Val
# define Rte_Write_RackVel_Val Rte_Write_SysKineAndEff_RackVel_Val
# define Rte_Write_RoadWhlAg_Val Rte_Write_SysKineAndEff_RoadWhlAg_Val
# define Rte_Write_SteerArmLen_Val Rte_Write_SysKineAndEff_SteerArmLen_Val
# define Rte_Write_SysAssiTqRat_Val Rte_Write_SysKineAndEff_SysAssiTqRat_Val
# define Rte_Write_SysKineRat_Val Rte_Write_SysKineAndEff_SysKineRat_Val
# define Rte_Write_SysTqRat_Val Rte_Write_SysKineAndEff_SysTqRat_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val Rte_Prm_SysKineAndEff_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val

# define Rte_Prm_SysKineAndEffMotAgScaX_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffMotAgScaX_Ary1D

# define Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffMotAgToRackPosRatScaY_Ary1D

# define Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffMotToRackEffScaY_Ary1D

# define Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D

# define Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffPinionToRackEffScaY_Ary1D

# define Rte_Prm_SysKineAndEffRackPosScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffRackPosScaY_Ary1D

# define Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D

# define Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D Rte_Prm_SysKineAndEff_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_CmplncErrDerivtvPrev() (Rte_Inst_SysKineAndEff->Pim_CmplncErrDerivtvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CmplncErrPinionToHwPrev() (Rte_Inst_SysKineAndEff->Pim_CmplncErrPinionToHwPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_CmplncErrDerivtvPrev(void)
 *   float32 *Rte_Pim_CmplncErrPinionToHwPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val(void)
 *   s15p0 *Rte_Prm_SysKineAndEffMotAgScaX_Ary1D(void)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_21
 *   u4p12 *Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_21
 *   u1p15 *Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   u5p11 *Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(void)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_21
 *   u1p15 *Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   s8p7 *Rte_Prm_SysKineAndEffRackPosScaY_Ary1D(void)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_21
 *   s2p13 *Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(void)
 *     Returnvalue: s2p13* is of type Ary1D_s2p13_21
 *   u1p15 *Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *
 *********************************************************************************************************************/


# define SysKineAndEff_START_SEC_CODE
# include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SysKineAndEffInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SysKineAndEffInit1 SysKineAndEffInit1
FUNC(void, SysKineAndEff_CODE) SysKineAndEffInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SysKineAndEffPer1
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
 *   Std_ReturnType Rte_Read_CmplncErrPinionToHw_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotAgToRackPosnInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotToRackFInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotToRackInstsEff_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgToRackInstsEff_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgToRackPosnInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionTqToRackFInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_RackPosn_Val(float32 data)
 *   Std_ReturnType Rte_Write_RackVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_RoadWhlAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_SteerArmLen_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysAssiTqRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysKineRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysTqRat_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SysKineAndEffPer1 SysKineAndEffPer1
FUNC(void, SysKineAndEff_CODE) SysKineAndEffPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define SysKineAndEff_STOP_SEC_CODE
# include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SYSKINEANDEFF_H */

#include "Rte_Stubs.h"
