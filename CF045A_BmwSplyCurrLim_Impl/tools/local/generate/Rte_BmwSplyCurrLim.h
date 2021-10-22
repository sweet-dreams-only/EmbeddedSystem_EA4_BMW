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
 *          File:  Rte_BmwSplyCurrLim.h
 *        Config:  C:/_S/work/ses_dev_ea4/CF045A_BmwSplyCurrLim_Impl-z172399/CF045A_BmwSplyCurrLim_Impl/tools/Component.dpa
 *     SW-C Type:  BmwSplyCurrLim
 *  Generated at:  Wed Jun  6 12:35:23 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwSplyCurrLim> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSPLYCURRLIM_H
# define _RTE_BMWSPLYCURRLIM_H

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

# include "Rte_BmwSplyCurrLim_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwSplyCurrLim
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwMaxCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SplyCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VltgDptCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimBmwMaxCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimCurrLimPrel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimGlbLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimSplyCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimVehSpdDptCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwSplyCurrLimVltgDptCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwSplyCurrLim, RTE_CONST, RTE_CONST) Rte_Inst_BmwSplyCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwSplyCurrLim, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwMaxCurrLimr_Val (120.0F)
# define Rte_InitValue_BmwMaxCurrLimrSts_Val (4U)
# define Rte_InitValue_BmwStrtStopLim_Val (120.0F)
# define Rte_InitValue_BmwStrtStopMsgActv_Logl (FALSE)
# define Rte_InitValue_BrdgVltg_Val (6.0F)
# define Rte_InitValue_MaxCurrAtHiSpd_Val (120.0F)
# define Rte_InitValue_MaxCurrAtLoSpd_Val (120.0F)
# define Rte_InitValue_RemCtrlPrkgEna_Logl (FALSE)
# define Rte_InitValue_SplyCurrLim_Val (120.0F)
# define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimr_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimrSts_Val(P2VAR(BmwMaxCurrLimrSts1, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_BmwStrtStopLim_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_BrdgVltg_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_MaxCurrAtHiSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_MaxCurrAtLoSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_RemCtrlPrkgEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_SysMotTqCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSplyCurrLim_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSPLYCURRLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSplyCurrLim_SplyCurrLim_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSplyCurrLim_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimMin_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsCpbyOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsMaxGrdt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsMinGrdt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimMaxCurrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimRemCtrlPrkgLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrLimFltThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVrntMaxCurr_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u8p8_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u8p8_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u16p0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u16p0_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u16p0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u16p0_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwMaxCurrLimr_Val Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimr_Val
# define Rte_Read_BmwMaxCurrLimrSts_Val Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimrSts_Val
# define Rte_Read_BmwStrtStopLim_Val Rte_Read_BmwSplyCurrLim_BmwStrtStopLim_Val
# define Rte_Read_BmwStrtStopMsgActv_Logl Rte_Read_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl
# define Rte_Read_BrdgVltg_Val Rte_Read_BmwSplyCurrLim_BrdgVltg_Val
# define Rte_Read_MaxCurrAtHiSpd_Val Rte_Read_BmwSplyCurrLim_MaxCurrAtHiSpd_Val
# define Rte_Read_MaxCurrAtLoSpd_Val Rte_Read_BmwSplyCurrLim_MaxCurrAtLoSpd_Val
# define Rte_Read_RemCtrlPrkgEna_Logl Rte_Read_BmwSplyCurrLim_RemCtrlPrkgEna_Logl
# define Rte_Read_SysMotTqCmdSca_Val Rte_Read_BmwSplyCurrLim_SysMotTqCmdSca_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwSplyCurrLim_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_SplyCurrLim_Val Rte_Write_BmwSplyCurrLim_SplyCurrLim_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwSplyCurrLim_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimMax_Val

# define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimMin_Val

# define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val

# define Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsCpbyOffs_Val

# define Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsMaxGrdt_Val

# define Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimEpsMinGrdt_Val

# define Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimMaxCurrLim_Val

# define Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimRemCtrlPrkgLim_Val

# define Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrLimFltThd_Val

# define Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVrntMaxCurr_Val

# define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D

# define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D

# define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D

# define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D

# define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D

# define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D

# define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D

# define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D

# define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D

# define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D Rte_Prm_BmwSplyCurrLim_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwMaxCurrLimGrdt() (Rte_Inst_BmwSplyCurrLim->Pim_BmwMaxCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SplyCurrLimGrdt() (Rte_Inst_BmwSplyCurrLim->Pim_SplyCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VltgDptCurrLimGrdt() (Rte_Inst_BmwSplyCurrLim->Pim_VltgDptCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimBmwMaxCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimCurrLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimCurrLimPrel() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimCurrLimPrel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimGlbLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimGlbLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimSplyCurrLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimSplyCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimVehSpdDptCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim() (Rte_Inst_BmwSplyCurrLim->Pim_dBmwSplyCurrLimVltgDptCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwMaxCurrLimGrdt(void)
 *   float32 *Rte_Pim_SplyCurrLimGrdt(void)
 *   float32 *Rte_Pim_VltgDptCurrLimGrdt(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimCurrLim(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimCurrLimPrel(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimGlbLim(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimSplyCurrLim(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim(void)
 *   float32 *Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val(void)
 *   float32 Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val(void)
 *   u6p10 *Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_8
 *   u8p8 *Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u6p10 *Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_8
 *   u8p8 *Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u9p7 *Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *   u8p8 *Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u6p10 *Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_8
 *   u16p0 *Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D(void)
 *     Returnvalue: u16p0* is of type Ary1D_u16p0_8
 *   u6p10 *Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_8
 *   u16p0 *Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D(void)
 *     Returnvalue: u16p0* is of type Ary1D_u16p0_8
 *
 *********************************************************************************************************************/


# define BmwSplyCurrLim_START_SEC_CODE
# include "BmwSplyCurrLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSplyCurrLimInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwSplyCurrLimInit1 BmwSplyCurrLimInit1
FUNC(void, BmwSplyCurrLim_CODE) BmwSplyCurrLimInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSplyCurrLimPer1
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
 *   Std_ReturnType Rte_Read_BmwMaxCurrLimr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 *data)
 *   Std_ReturnType Rte_Read_BmwStrtStopLim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwStrtStopMsgActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BrdgVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MaxCurrAtHiSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MaxCurrAtLoSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RemCtrlPrkgEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysMotTqCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SplyCurrLim_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwSplyCurrLimPer1 BmwSplyCurrLimPer1
FUNC(void, BmwSplyCurrLim_CODE) BmwSplyCurrLimPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwSplyCurrLim_STOP_SEC_CODE
# include "BmwSplyCurrLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSPLYCURRLIM_H */

#include "Rte_Stubs.h"
