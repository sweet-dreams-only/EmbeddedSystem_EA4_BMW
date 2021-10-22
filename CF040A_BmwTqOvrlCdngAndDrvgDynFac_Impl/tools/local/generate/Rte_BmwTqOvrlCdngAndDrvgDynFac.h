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
 *          File:  Rte_BmwTqOvrlCdngAndDrvgDynFac.h
 *        Config:  C:/S/W/ses_dev_ea4/CF040A_BmwTqOvrlCdngAndDrvgDynFac_Impl-z172399/CF040A_BmwTqOvrlCdngAndDrvgDynFac_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTqOvrlCdngAndDrvgDynFac
 *  Generated at:  Tue Apr 24 15:38:28 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwTqOvrlCdngAndDrvgDynFac> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H
# define _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H

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

# include "Rte_BmwTqOvrlCdngAndDrvgDynFac_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwTqOvrlCdngAndDrvgDynFac
{
  /* PIM Handles section */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwOutpTqOvrlCmdRampCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwOutpTqOvrlCmdStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarSteerTqDrvrActrLpFilStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DampgCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_EffortCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FrznBmwTarSteerTqDrvrActr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FrznSigActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LimdCdndTqOvrl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MsgCycTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDampgSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvgDynActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(DrvgDynIfSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDrvgDynIfSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevEffortSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevRtnSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RampToZeroEnad; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RtnCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwTqOvrlCdngAndDrvgDynFac, RTE_CONST, RTE_CONST) Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwTqOvrlCdngAndDrvgDynFac, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwDrvgDynDampgFacReq_Val (1.0F)
# define Rte_InitValue_BmwDrvgDynEffortFacReq_Val (1.0F)
# define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
# define Rte_InitValue_BmwDrvgDynRtnFacReq_Val (1.0F)
# define Rte_InitValue_BmwOutpTqOvrlCmd_Val (0.0F)
# define Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl (TRUE)
# define Rte_InitValue_BmwTarSteerTqDrvrActr_Val (0.0F)
# define Rte_InitValue_DampgCmdSca_Val (1.0F)
# define Rte_InitValue_DrvgDynActv_Logl (FALSE)
# define Rte_InitValue_DrvgDynFacEna_Logl (TRUE)
# define Rte_InitValue_DrvgDynIfSt_Val (128U)
# define Rte_InitValue_EffortCmdSca_Val (1.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_OutpTqOvrlRampInEna_Logl (FALSE)
# define Rte_InitValue_RtnCmdSca_Val (1.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynDampgFacReq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynEffortFacReq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynErrIfActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynRtnFacReq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActr_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynFacEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynIfSt_Val(P2VAR(DrvgDynIfSt1, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_OutpTqOvrlRampInEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u11p5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u11p5_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u1p15_12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u2p14_12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwDrvgDynDampgFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynDampgFacReq_Val
# define Rte_Read_BmwDrvgDynEffortFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynEffortFacReq_Val
# define Rte_Read_BmwDrvgDynErrIfActv_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynErrIfActv_Logl
# define Rte_Read_BmwDrvgDynRtnFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynRtnFacReq_Val
# define Rte_Read_BmwOutpTqOvrlCmdEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdEna_Logl
# define Rte_Read_BmwTarSteerTqDrvrActr_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActr_Val
# define Rte_Read_DrvgDynActv_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynActv_Logl
# define Rte_Read_DrvgDynFacEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynFacEna_Logl
# define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynIfSt_Val
# define Rte_Read_HwTq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_HwTq_Val
# define Rte_Read_MotVelCrf_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_MotVelCrf_Val
# define Rte_Read_OutpTqOvrlRampInEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_OutpTqOvrlRampInEna_Logl
# define Rte_Read_VehSpd_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwOutpTqOvrlCmd_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val
# define Rte_Write_DampgCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val
# define Rte_Write_EffortCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val
# define Rte_Write_RtnCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInj_f32_Oper Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_FltInj_f32_Oper
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwTqOvrlCdngAndDrvgDynFac_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D

# define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_BmwTqOvrlCdngAndDrvgDynFac_SysGlbPrmVehSpdBilnrSeln_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwOutpTqOvrlCmdStVari() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_BmwOutpTqOvrlCmdStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DampgCmdScaRateLimrStVari() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_DampgCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_EffortCmdScaRateLimrStVari() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_EffortCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FrznBmwTarSteerTqDrvrActr() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_FrznBmwTarSteerTqDrvrActr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LimdCdndTqOvrl() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_LimdCdndTqOvrl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RtnCmdScaRateLimrStVari() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_RtnCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MsgCycTmr() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_MsgCycTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvgDynIfSt() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_PrevDrvgDynIfSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_BmwOutpTqOvrlCmdRampCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FrznSigActv() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_FrznSigActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDampgSlewInProgs() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_PrevDampgSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDrvgDynActv() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_PrevDrvgDynActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevEffortSlewInProgs() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_PrevEffortSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevRtnSlewInProgs() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_PrevRtnSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RampToZeroEnad() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_RampToZeroEnad) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari() (Rte_Inst_BmwTqOvrlCdngAndDrvgDynFac->Pim_BmwTarSteerTqDrvrActrLpFilStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwOutpTqOvrlCmdStVari(void)
 *   float32 *Rte_Pim_DampgCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_EffortCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_FrznBmwTarSteerTqDrvrActr(void)
 *   float32 *Rte_Pim_LimdCdndTqOvrl(void)
 *   float32 *Rte_Pim_RtnCmdScaRateLimrStVari(void)
 *   uint32 *Rte_Pim_MsgCycTmr(void)
 *   DrvgDynIfSt1 *Rte_Pim_PrevDrvgDynIfSt(void)
 *   boolean *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl(void)
 *   boolean *Rte_Pim_FrznSigActv(void)
 *   boolean *Rte_Pim_PrevDampgSlewInProgs(void)
 *   boolean *Rte_Pim_PrevDrvgDynActv(void)
 *   boolean *Rte_Pim_PrevEffortSlewInProgs(void)
 *   boolean *Rte_Pim_PrevRtnSlewInProgs(void)
 *   boolean *Rte_Pim_RampToZeroEnad(void)
 *   FilLpRec1 *Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void)
 *   u11p5 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u1p15 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u2p14 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u9p7 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


# define BmwTqOvrlCdngAndDrvgDynFac_START_SEC_CODE
# include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTqOvrlCdngAndDrvgDynFacInit1 BmwTqOvrlCdngAndDrvgDynFacInit1
FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynDampgFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynEffortFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynRtnFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynFacEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_OutpTqOvrlRampInEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_EffortCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_RtnCmdSca_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTqOvrlCdngAndDrvgDynFacPer1 BmwTqOvrlCdngAndDrvgDynFacPer1
FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwTqOvrlCdngAndDrvgDynFac_STOP_SEC_CODE
# include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H */

#include "Rte_Stubs.h"
