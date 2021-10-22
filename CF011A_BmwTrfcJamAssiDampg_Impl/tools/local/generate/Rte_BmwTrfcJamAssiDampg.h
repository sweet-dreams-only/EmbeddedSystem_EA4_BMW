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
 *          File:  Rte_BmwTrfcJamAssiDampg.h
 *        Config:  C:/_S/work/ses_dev_ea4/CF011A_BmwTrfcJamAssiDampg_Impl-z172399/CF011A_BmwTrfcJamAssiDampg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTrfcJamAssiDampg
 *  Generated at:  Tue Apr 17 15:01:17 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwTrfcJamAssiDampg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWTRFCJAMASSIDAMPG_H
# define _RTE_BMWTRFCJAMASSIDAMPG_H

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

# include "Rte_BmwTrfcJamAssiDampg_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwTrfcJamAssiDampg
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTrfcJamAssiDampgScaStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LimExcddFltRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLimExcddFlt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TmpBmwTrfcJamAssiDampgSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwTrfcJamAssiDampg, RTE_CONST, RTE_CONST) Rte_Inst_BmwTrfcJamAssiDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwTrfcJamAssiDampg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwTrfcJamAssiDampgScaReq_Val (0.0F)
# define Rte_InitValue_BmwTrfcJamAssiDampgScaReqVld_Logl (FALSE)
# define Rte_InitValue_BmwTrfcJamAssiDampgSt_Val (1U)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReq_Val (1U)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReqVld_Logl (FALSE)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_TrfcJamAssiCmd_Val (0.0F)
# define Rte_InitValue_TrfcJamAssiCmdEna_Logl (TRUE)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgScaReq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgScaReqVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgStReq_Val(P2VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgStReqVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_TrfcJamAssiCmdEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTrfcJamAssiDampg_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTrfcJamAssiDampg_TrfcJamAssiCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTrfcJamAssiDampg_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTrfcJamAssiDampg_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWTRFCJAMASSIDAMPG_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgRatThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateUp_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u11p5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u11p5_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u11p5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u11p5_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTrfcJamAssiDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwTrfcJamAssiDampgScaReq_Val Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgScaReq_Val
# define Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgScaReqVld_Logl
# define Rte_Read_BmwTrfcJamAssiDampgStReq_Val Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgStReq_Val
# define Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl Rte_Read_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgStReqVld_Logl
# define Rte_Read_MotVelCrf_Val Rte_Read_BmwTrfcJamAssiDampg_MotVelCrf_Val
# define Rte_Read_TrfcJamAssiCmdEna_Logl Rte_Read_BmwTrfcJamAssiDampg_TrfcJamAssiCmdEna_Logl
# define Rte_Read_VehSpd_Val Rte_Read_BmwTrfcJamAssiDampg_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwTrfcJamAssiDampgSt_Val Rte_Write_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSt_Val
# define Rte_Write_TrfcJamAssiCmd_Val Rte_Write_BmwTrfcJamAssiDampg_TrfcJamAssiCmd_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwTrfcJamAssiDampg_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwTrfcJamAssiDampg_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgRatThd_Val

# define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnActv_Val

# define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val

# define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val

# define Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSlewRateUp_Val

# define Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val

# define Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgX_Ary1D

# define Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgBasDampgY_Ary1D

# define Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgX_Ary1D

# define Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D Rte_Prm_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgLimdDampgY_Ary2D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_BmwTrfcJamAssiDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwTrfcJamAssiDampgScaStVari() (Rte_Inst_BmwTrfcJamAssiDampg->Pim_BmwTrfcJamAssiDampgScaStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LimExcddFltRefTi() (Rte_Inst_BmwTrfcJamAssiDampg->Pim_LimExcddFltRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TmpBmwTrfcJamAssiDampgSt() (Rte_Inst_BmwTrfcJamAssiDampg->Pim_TmpBmwTrfcJamAssiDampgSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLimExcddFlt() (Rte_Inst_BmwTrfcJamAssiDampg->Pim_PrevLimExcddFlt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwTrfcJamAssiDampgScaStVari(void)
 *   uint32 *Rte_Pim_LimExcddFltRefTi(void)
 *   uint8 *Rte_Pim_TmpBmwTrfcJamAssiDampgSt(void)
 *   boolean *Rte_Pim_PrevLimExcddFlt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val(void)
 *   uint16 Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void)
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


# define BmwTrfcJamAssiDampg_START_SEC_CODE
# include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTrfcJamAssiDampgInit1 BmwTrfcJamAssiDampgInit1
FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgPer1
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
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmd_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTrfcJamAssiDampgPer1 BmwTrfcJamAssiDampgPer1
FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwTrfcJamAssiDampg_STOP_SEC_CODE
# include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWTRFCJAMASSIDAMPG_H */

#include "Rte_Stubs.h"
