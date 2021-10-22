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
 *          File:  Rte_CtrldVelRtn.h
 *        Config:  C:/Component/SF065A_CtrldVelRtn_Impl/tools/Component.dpa
 *     SW-C Type:  CtrldVelRtn
 *  Generated at:  Wed Nov  8 14:19:12 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CtrldVelRtn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRLDVELRTN_H
# define _RTE_CTRLDVELRTN_H

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

# include "Rte_CtrldVelRtn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CtrldVelRtn
{
  /* PIM Handles section */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrlScaLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DesVelLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DesVelScaLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DrvrTqLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionTqLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDesVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildB; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildD; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqFildF; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary1D_f32_5, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvrTqMtrx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevHwAuthySca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevHwTqSeln; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIntglTermA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIntglTermB; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIntglTermC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevRtnOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnCtrlSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnCtrlScaPreFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDampgCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDesVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDesVelSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDesVelScaPreFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDrvrTqEstimd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnDrvrTqFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnHwAgCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnHwAuthySca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnHwPosnSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnHwTqSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnHwTqScaSeln; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnIntglTermCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnIntgrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnPinionTqSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnPropTermCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnRtnCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnRtnCmdPreLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnTqGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnTqGrdtSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCtrldVelRtnVelErrSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CtrldVelRtn, RTE_CONST, RTE_CONST) Rte_Inst_CtrldVelRtn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CtrldVelRtn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssiMechPolarity_Val (1)
# define Rte_InitValue_CtrldVelRtnCmd_Val (0.0F)
# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_HwAgAuthy_Val (0.0F)
# define Rte_InitValue_HwAgRtnOffs_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_HwVel_Val (0.0F)
# define Rte_InitValue_MotTqCmdPwrLimd_Val (0.0F)
# define Rte_InitValue_RtnCmdDi_Logl (FALSE)
# define Rte_InitValue_RtnCmdDiagcDi_Logl (FALSE)
# define Rte_InitValue_RtnCmdSca_Val (1.0F)
# define Rte_InitValue_RtnCmdScaServo_Val (1.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_AssiMechPolarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_HwAg_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_HwAgAuthy_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_HwAgRtnOffs_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_HwVel_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_MotTqCmdPwrLimd_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_RtnCmdDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_RtnCmdDiagcDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_RtnCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_RtnCmdScaServo_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtrldVelRtn_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_CTRLDVELRTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtrldVelRtn_CtrldVelRtnCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnAntiWdup_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthySlewThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnTqThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnVelThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnOffsSlewThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnOffsThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnScaLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CtrldVelRtn_SysGlbPrmSysTqRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgScaEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u10p6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u10p6_8_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_8_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u8p8_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u12p4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u12p4_8_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u10p6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u10p6_8_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxA_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxA_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxB_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_f32_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxB_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxC_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxC_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxD_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxD_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u12p4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u12p4_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1X_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u8p8_5_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1X_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1Y_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_5_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1Y_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2X_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u8p8_5_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2X_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2Y_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_5_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2Y_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnIntglGain_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u8p8_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnIntglGain_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnIntgrLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_5_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnIntgrLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u8p8_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPropGain_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnPropGain_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnRtnCmdLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnRtnCmdLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u8p8_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u12p4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u12p4_7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s10p5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s10p5_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_7_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelSpdTbl_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_CtrldVelRtn_CtrldVelRtnVelSpdTbl_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AssiMechPolarity_Val Rte_Read_CtrldVelRtn_AssiMechPolarity_Val
# define Rte_Read_HwAg_Val Rte_Read_CtrldVelRtn_HwAg_Val
# define Rte_Read_HwAgAuthy_Val Rte_Read_CtrldVelRtn_HwAgAuthy_Val
# define Rte_Read_HwAgRtnOffs_Val Rte_Read_CtrldVelRtn_HwAgRtnOffs_Val
# define Rte_Read_HwTq_Val Rte_Read_CtrldVelRtn_HwTq_Val
# define Rte_Read_HwVel_Val Rte_Read_CtrldVelRtn_HwVel_Val
# define Rte_Read_MotTqCmdPwrLimd_Val Rte_Read_CtrldVelRtn_MotTqCmdPwrLimd_Val
# define Rte_Read_RtnCmdDi_Logl Rte_Read_CtrldVelRtn_RtnCmdDi_Logl
# define Rte_Read_RtnCmdDiagcDi_Logl Rte_Read_CtrldVelRtn_RtnCmdDiagcDi_Logl
# define Rte_Read_RtnCmdSca_Val Rte_Read_CtrldVelRtn_RtnCmdSca_Val
# define Rte_Read_RtnCmdScaServo_Val Rte_Read_CtrldVelRtn_RtnCmdScaServo_Val
# define Rte_Read_VehSpd_Val Rte_Read_CtrldVelRtn_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_CtrldVelRtnCmd_Val Rte_Write_CtrldVelRtn_CtrldVelRtnCmd_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_CtrldVelRtnAntiWdup_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnAntiWdup_Val

# define Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelLpFilFrq_Val

# define Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthySlewThd_Val

# define Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqLpFilFrq_Val

# define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnSlewHiLim_Val

# define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnSlewLoLim_Val

# define Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnTqThd_Val

# define Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqScaSelnVelThd_Val

# define Rte_Prm_CtrldVelRtnOffsSlewThd_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnOffsSlewThd_Val

# define Rte_Prm_CtrldVelRtnOffsThd_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnOffsThd_Val

# define Rte_Prm_CtrldVelRtnScaLpFilFrq_Val Rte_Prm_CtrldVelRtn_CtrldVelRtnScaLpFilFrq_Val

# define Rte_Prm_SysGlbPrmSysTqRat_Val Rte_Prm_CtrldVelRtn_SysGlbPrmSysTqRat_Val

# define Rte_Prm_CtrldVelRtnDampgEna_Logl Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgEna_Logl

# define Rte_Prm_CtrldVelRtnDampgScaEna_Logl Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgScaEna_Logl

# define Rte_Prm_CtrldVelRtnDrvrTqEna_Logl Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqEna_Logl

# define Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaEna_Logl

# define Rte_Prm_CtrldVelRtnVelErrScaEna_Logl Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaEna_Logl

# define Rte_Prm_CtrldVelRtnDampgX_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgX_Ary2D

# define Rte_Prm_CtrldVelRtnDampgY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDampgY_Ary2D

# define Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaX_Ary2D

# define Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelScaY_Ary2D

# define Rte_Prm_CtrldVelRtnDesVelX_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelX_Ary2D

# define Rte_Prm_CtrldVelRtnDesVelY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDesVelY_Ary2D

# define Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxA_Ary2D

# define Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxB_Ary2D

# define Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxC_Ary1D

# define Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnDrvrTqMtrxD_Ary1D

# define Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaX_Ary1D

# define Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwAuthyScaY_Ary1D

# define Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaX_Ary1D

# define Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwPosnScaY_Ary1D

# define Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1X_Ary2D

# define Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca1Y_Ary2D

# define Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2X_Ary2D

# define Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnHwTqSca2Y_Ary2D

# define Rte_Prm_CtrldVelRtnIntglGain_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnIntglGain_Ary1D

# define Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnIntgrLimY_Ary2D

# define Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaX_Ary2D

# define Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnPinionTqScaY_Ary2D

# define Rte_Prm_CtrldVelRtnPropGain_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnPropGain_Ary1D

# define Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnRtnCmdLimY_Ary1D

# define Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaX_Ary2D

# define Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnTqGrdtScaY_Ary2D

# define Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D

# define Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaBilnrSeln_Ary1D

# define Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaX_Ary1D

# define Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrScaY_Ary2D

# define Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnVelErrVehSpdScaY_Ary1D

# define Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D Rte_Prm_CtrldVelRtn_CtrldVelRtnVelSpdTbl_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PrevDesVel() (Rte_Inst_CtrldVelRtn->Pim_PrevDesVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildA() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildA) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildB() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildB) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildC() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildC) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildD() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildD) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildE() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildE) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvrTqFildF() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqFildF) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevHwAuthySca() (Rte_Inst_CtrldVelRtn->Pim_PrevHwAuthySca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevHwTqSeln() (Rte_Inst_CtrldVelRtn->Pim_PrevHwTqSeln) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIntglTermA() (Rte_Inst_CtrldVelRtn->Pim_PrevIntglTermA) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIntglTermB() (Rte_Inst_CtrldVelRtn->Pim_PrevIntglTermB) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIntglTermC() (Rte_Inst_CtrldVelRtn->Pim_PrevIntglTermC) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevRtnOffs() (Rte_Inst_CtrldVelRtn->Pim_PrevRtnOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnCtrlSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnCtrlSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnCtrlScaPreFild() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnCtrlScaPreFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDampgCmd() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDampgCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDesVel() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDesVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDesVelSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDesVelSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDesVelScaPreFild() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDesVelScaPreFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDrvrTqEstimd() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDrvrTqEstimd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnDrvrTqFild() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnDrvrTqFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnHwAgCmp() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnHwAgCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnHwAuthySca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnHwAuthySca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnHwPosnSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnHwPosnSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnHwTqSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnHwTqSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnHwTqScaSeln() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnHwTqScaSeln) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnIntglTermCmd() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnIntglTermCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnIntgrLim() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnIntgrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnPinionTqSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnPinionTqSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnPropTermCmd() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnPropTermCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnRtnCmd() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnRtnCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnRtnCmdPreLim() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnRtnCmdPreLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnTqGrdt() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnTqGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnTqGrdtSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnTqGrdtSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCtrldVelRtnVelErrSca() (Rte_Inst_CtrldVelRtn->Pim_dCtrldVelRtnVelErrSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_PrevDrvrTqMtrx() (*Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqMtrx) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_PrevDrvrTqMtrx() (Rte_Inst_CtrldVelRtn->Pim_PrevDrvrTqMtrx) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# define Rte_Pim_CtrlScaLpFil() (Rte_Inst_CtrldVelRtn->Pim_CtrlScaLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DesVelLpFil() (Rte_Inst_CtrldVelRtn->Pim_DesVelLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DesVelScaLpFil() (Rte_Inst_CtrldVelRtn->Pim_DesVelScaLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DrvrTqLpFil() (Rte_Inst_CtrldVelRtn->Pim_DrvrTqLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionTqLpFil() (Rte_Inst_CtrldVelRtn->Pim_PinionTqLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevDesVel(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildA(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildB(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildC(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildD(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildE(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildF(void)
 *   float32 *Rte_Pim_PrevHwAuthySca(void)
 *   float32 *Rte_Pim_PrevHwTqSeln(void)
 *   float32 *Rte_Pim_PrevIntglTermA(void)
 *   float32 *Rte_Pim_PrevIntglTermB(void)
 *   float32 *Rte_Pim_PrevIntglTermC(void)
 *   float32 *Rte_Pim_PrevRtnOffs(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDampgCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVel(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqEstimd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAgCmp(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAuthySca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwPosnSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqScaSeln(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntglTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntgrLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPinionTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPropTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmdPreLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdt(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdtSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnVelErrSca(void)
 *   float32 *Rte_Pim_PrevDrvrTqMtrx(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   FilLpRec1 *Rte_Pim_CtrlScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DrvrTqLpFil(void)
 *   FilLpRec1 *Rte_Pim_PinionTqLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_CtrldVelRtnAntiWdup_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsSlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDrvrTqEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(void)
 *   u10p6 *Rte_Prm_CtrldVelRtnDampgX_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_9
 *   u6p10 *Rte_Prm_CtrldVelRtnDampgY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_8_9
 *   u8p8 *Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u12p4 *Rte_Prm_CtrldVelRtnDesVelX_Ary2D(void)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_8_12
 *   u10p6 *Rte_Prm_CtrldVelRtnDesVelY_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_12
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_4
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u12p4 *Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u2p14 *Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_9
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnIntglGain_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u6p10 *Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_5_9
 *   u8p8 *Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u4p12 *Rte_Prm_CtrldVelRtnPropGain_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u4p12 *Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u8p8 *Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u9p7 *Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_7
 *   s10p5 *Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(void)
 *     Returnvalue: s10p5* is of type Ary1D_s10p5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_7_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_5
 *   u9p7 *Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_8
 *
 *********************************************************************************************************************/


# define CtrldVelRtn_START_SEC_CODE
# include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CtrldVelRtnInit1 CtrldVelRtnInit1
FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnPer1
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
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgAuthy_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgRtnOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdDiagcDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdScaServo_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmd_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CtrldVelRtnPer1 CtrldVelRtnPer1
FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtrldVelRtn_STOP_SEC_CODE
# include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRLDVELRTN_H */

#include "Rte_Stubs.h"
