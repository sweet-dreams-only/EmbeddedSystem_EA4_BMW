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
 *          File:  Rte_ClsdLoopHys.h
 *        Config:  C:/_S/work/ses_dev_ea4/SF073A_ClsdLoopHys_Impl-z172399/SF073A_ClsdLoopHys_Impl/tools/Component.dpa
 *     SW-C Type:  ClsdLoopHys
 *  Generated at:  Wed Jul 18 10:05:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ClsdLoopHys> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CLSDLOOPHYS_H
# define _RTE_CLSDLOOPHYS_H

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

# include "Rte_ClsdLoopHys_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_ClsdLoopHys
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_IntgtrSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_ClsdLoopHys, RTE_CONST, RTE_CONST) Rte_Inst_ClsdLoopHys; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_ClsdLoopHys, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
# define Rte_InitValue_HwTqCmdHys_Val (0.0F)
# define Rte_InitValue_HwVel_Val (0.0F)
# define Rte_InitValue_RackFEstimd_Val (0.0F)
# define Rte_InitValue_SysFricOffs_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_HwAg_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_HwTqCmdEffort_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_HwVel_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_RackFEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_SysFricOffs_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopHys_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPHYS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ClsdLoopHys_HwTqCmdHys_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgBlndFac_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgNegLowrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgNegUpprLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgPosLowrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgPosUpprLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysDeltaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysDeltaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysGainY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysGainY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u15p1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u15p1_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_12_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRhoY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysRhoY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s4p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s4p11_7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopHys_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwAg_Val Rte_Read_ClsdLoopHys_HwAg_Val
# define Rte_Read_HwTq_Val Rte_Read_ClsdLoopHys_HwTq_Val
# define Rte_Read_HwTqCmdEffort_Val Rte_Read_ClsdLoopHys_HwTqCmdEffort_Val
# define Rte_Read_HwVel_Val Rte_Read_ClsdLoopHys_HwVel_Val
# define Rte_Read_RackFEstimd_Val Rte_Read_ClsdLoopHys_RackFEstimd_Val
# define Rte_Read_SysFricOffs_Val Rte_Read_ClsdLoopHys_SysFricOffs_Val
# define Rte_Read_VehSpd_Val Rte_Read_ClsdLoopHys_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTqCmdHys_Val Rte_Write_ClsdLoopHys_HwTqCmdHys_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_ClsdLoopHysHwAgBlndFac_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgBlndFac_Val

# define Rte_Prm_ClsdLoopHysPolarity_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysPolarity_Val

# define Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgNegLowrLim_Val

# define Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgNegUpprLim_Val

# define Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgPosLowrLim_Val

# define Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerInHwAgPosUpprLim_Val

# define Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgNegLowrLim_Val

# define Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgNegUpprLim_Val

# define Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgPosLowrLim_Val

# define Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val Rte_Prm_ClsdLoopHys_ClsdLoopHysSteerOutHwAgPosUpprLim_Val

# define Rte_Prm_ClsdLoopHysDeltaY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysDeltaY_Ary1D

# define Rte_Prm_ClsdLoopHysGainY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysGainY_Ary1D

# define Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndX_Ary1D

# define Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadBlndY_Ary1D

# define Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrX_Ary1D

# define Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwAgQuadQlfrY_Ary1D

# define Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndX_Ary1D

# define Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysHwVelQuadBlndY_Ary1D

# define Rte_Prm_ClsdLoopHysRackFFacX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacX_Ary1D

# define Rte_Prm_ClsdLoopHysRackFFacY_Ary2D Rte_Prm_ClsdLoopHys_ClsdLoopHysRackFFacY_Ary2D

# define Rte_Prm_ClsdLoopHysRhoY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysRhoY_Ary1D

# define Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimX_Ary1D

# define Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricOffsLimY_Ary1D

# define Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaX_Ary1D

# define Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D Rte_Prm_ClsdLoopHys_ClsdLoopHysSysFricScaY_Ary1D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_ClsdLoopHys_SysGlbPrmVehSpdBilnrSeln_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_IntgtrSt() (Rte_Inst_ClsdLoopHys->Pim_IntgtrSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_IntgtrSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysPolarity_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(void)
 *   u6p10 *Rte_Prm_ClsdLoopHysDeltaY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysGainY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u6p10 *Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u15p1 *Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_4
 *   u2p14 *Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_4
 *   u6p10 *Rte_Prm_ClsdLoopHysRhoY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u9p7 *Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u4p12 *Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   s4p11 *Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(void)
 *     Returnvalue: s4p11* is of type Ary1D_s4p11_7
 *   u2p14 *Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_7
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


# define ClsdLoopHys_START_SEC_CODE
# include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClsdLoopHysInit1 ClsdLoopHysInit1
FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdEffort_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysFricOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdHys_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClsdLoopHysPer1 ClsdLoopHysPer1
FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define ClsdLoopHys_STOP_SEC_CODE
# include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CLSDLOOPHYS_H */

#include "Rte_Stubs.h"
