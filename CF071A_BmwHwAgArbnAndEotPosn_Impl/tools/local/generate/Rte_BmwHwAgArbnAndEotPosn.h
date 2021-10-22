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
 *          File:  Rte_BmwHwAgArbnAndEotPosn.h
 *        Config:  C:/_S/work/ses_dev_ea4/CF071A_BmwHwAgArbnAndEotPosn_Impl-z172399/CF071A_BmwHwAgArbnAndEotPosn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHwAgArbnAndEotPosn
 *  Generated at:  Thu Jul 19 09:07:16 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHwAgArbnAndEotPosn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHWAGARBNANDEOTPOSN_H
# define _RTE_BMWHWAGARBNANDEOTPOSN_H

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

# include "Rte_BmwHwAgArbnAndEotPosn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwHwAgArbnAndEotPosn
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AllwExitFromInitTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwPinionAgOffsRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwRackToVehCentrOffsSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwRackCentrToVehCentrOffsSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwVehCentrOffsRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehCentrOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ClrNotCmplPinionAgFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CurrAlgndPinionAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CurrDftPinionAgFltPrsnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DynStabyCtrlCdn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FirstLoopIndcr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_IniTurnCntrCorrlnSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_KineIntegrityFlt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LpFilActvd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotPosnDegArbdBlndFac; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotPosnDegArbdBlndTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_OffsCorrnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionAgConfRampStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionAgFilStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionAgFltRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevAllwCorrn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwMotAgSelnSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevBmwOffsAuthy; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevBmwOffsAuthyFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIgnCycBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIgnCycNtc8CSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIgnCycNtc8ESts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevIgnCycTurnCntrCorrlnSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwMotAgSelnSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLoopBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwQuadOffsSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLoopBmwQuadOffsSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLoopPinionAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevPinionAgConf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SetBmwRackCentrToVehCentrOffsTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SigInvldTranTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TurnCntrCorrlnStsTmrTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TurnCntrValTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehCentrCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwHwAgArbnAndEotPosn, RTE_CONST, RTE_CONST) Rte_Inst_BmwHwAgArbnAndEotPosn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwHwAgArbnAndEotPosn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlgndPinionAg_Val (0.0F)
# define Rte_InitValue_BmwHwAgOffs_Val (0.0F)
# define Rte_InitValue_BmwPinionAg_Val (0.0F)
# define Rte_InitValue_BmwPinionAgOffs_Val (0.0F)
# define Rte_InitValue_BmwPinionAgOffsSts_Val (4U)
# define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
# define Rte_InitValue_BmwQuadOffsSts_Val (15U)
# define Rte_InitValue_BmwQuadOffsStsVld_Logl (FALSE)
# define Rte_InitValue_BmwQuadRotorOffs_Val (0)
# define Rte_InitValue_BmwQuadRotorOffsVld_Logl (FALSE)
# define Rte_InitValue_BmwRackCentrToVehCentrOffs_Val (0.0F)
# define Rte_InitValue_BmwRackCentrToVehCentrOffsVld_Logl (FALSE)
# define Rte_InitValue_BmwVehSpdSts_Val (15U)
# define Rte_InitValue_CmplncErrMotToPinion_Val (0.0F)
# define Rte_InitValue_DiKineIntegrityTest_Logl (FALSE)
# define Rte_InitValue_HwAgCcwDetd_Logl (FALSE)
# define Rte_InitValue_HwAgCwDetd_Logl (FALSE)
# define Rte_InitValue_HwAgEotCcw_Val (-360.0F)
# define Rte_InitValue_HwAgEotCw_Val (360.0F)
# define Rte_InitValue_LongTermRackCentrCmpl_Logl (FALSE)
# define Rte_InitValue_LongTermVehCentrCmpl_Logl (FALSE)
# define Rte_InitValue_MotAgCumvAlgndMrf_Val (0)
# define Rte_InitValue_MotAgMeclCorrlnSt_Val (3U)
# define Rte_InitValue_MotAgTurnCntr_Val (0.0F)
# define Rte_InitValue_OffsCmpdPinionAg_Val (0.0F)
# define Rte_InitValue_PinionAg_Val (0.0F)
# define Rte_InitValue_PinionAgConf_Val (0.0F)
# define Rte_InitValue_RackCentrPinionAg_Val (0.0F)
# define Rte_InitValue_TotRackTrvl_Val (0.0F)
# define Rte_InitValue_TurnCntrCorrlnSts_Val (3U)
# define Rte_InitValue_VehSpd_Val (0.0F)
# define Rte_InitValue_VehSpdVld_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwHwAgOffs_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffs_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsSts_Val(P2VAR(BmwPinionAgOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsSts_Val(P2VAR(BmwQuadOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsStsVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffs_Val(P2VAR(sint8, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffsVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_BmwVehSpdSts_Val(P2VAR(BmwVehSpdSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_CmplncErrMotToPinion_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_LongTermRackCentrCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_MotAgCumvAlgndMrf_Val(P2VAR(s18p13, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_MotAgMeclCorrlnSt_Val(P2VAR(uint8, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_MotAgTurnCntr_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_RackCentrPinionAg_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_TotRackTrvl_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnSts_Val(P2VAR(uint8, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwAgArbnAndEotPosn_VehSpdVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_PinionAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwAgArbnAndEotPosn_PinionAgConf_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_RstRackCentrMotRev_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCcwMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCcwMin_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCwMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCwMin_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMotToHwResl_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsAuthy_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_SysGlbPrmSysKineRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwHwAgOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwHwAgOffs_Val
# define Rte_Read_BmwPinionAgOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffs_Val
# define Rte_Read_BmwPinionAgOffsSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsSts_Val
# define Rte_Read_BmwQuadOffsSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsSts_Val
# define Rte_Read_BmwQuadOffsStsVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsStsVld_Logl
# define Rte_Read_BmwQuadRotorOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffs_Val
# define Rte_Read_BmwQuadRotorOffsVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffsVld_Logl
# define Rte_Read_BmwVehSpdSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwVehSpdSts_Val
# define Rte_Read_CmplncErrMotToPinion_Val Rte_Read_BmwHwAgArbnAndEotPosn_CmplncErrMotToPinion_Val
# define Rte_Read_DiKineIntegrityTest_Logl Rte_Read_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl
# define Rte_Read_LongTermRackCentrCmpl_Logl Rte_Read_BmwHwAgArbnAndEotPosn_LongTermRackCentrCmpl_Logl
# define Rte_Read_MotAgCumvAlgndMrf_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgCumvAlgndMrf_Val
# define Rte_Read_MotAgMeclCorrlnSt_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgMeclCorrlnSt_Val
# define Rte_Read_MotAgTurnCntr_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgTurnCntr_Val
# define Rte_Read_RackCentrPinionAg_Val Rte_Read_BmwHwAgArbnAndEotPosn_RackCentrPinionAg_Val
# define Rte_Read_TotRackTrvl_Val Rte_Read_BmwHwAgArbnAndEotPosn_TotRackTrvl_Val
# define Rte_Read_TurnCntrCorrlnSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnSts_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwHwAgArbnAndEotPosn_VehSpd_Val
# define Rte_Read_VehSpdVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_VehSpdVld_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AlgndPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val
# define Rte_Write_BmwPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val
# define Rte_Write_BmwPinionAgQlfr_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val
# define Rte_Write_BmwRackCentrToVehCentrOffs_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val
# define Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl
# define Rte_Write_HwAgCcwDetd_Logl Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl
# define Rte_Write_HwAgCwDetd_Logl Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl
# define Rte_Write_HwAgEotCcw_Val Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val
# define Rte_Write_HwAgEotCw_Val Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val
# define Rte_Write_LongTermVehCentrCmpl_Logl Rte_Write_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl
# define Rte_Write_OffsCmpdPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val
# define Rte_Write_PinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_PinionAg_Val
# define Rte_Write_PinionAgConf_Val Rte_Write_BmwHwAgArbnAndEotPosn_PinionAgConf_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_BmwVehCentrOffs_GetErrorStatus Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_GetErrorStatus
# define Rte_Call_BmwVehCentrOffs_SetRamBlockStatus Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_SetRamBlockStatus
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_BmwHwAgArbnAndEotPosn_GetNtcQlfrSts_Oper
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwHwAgArbnAndEotPosn_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwHwAgArbnAndEotPosn_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_RstRackCentrMotRev_Oper Rte_Call_BmwHwAgArbnAndEotPosn_RstRackCentrMotRev_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwHwAgArbnAndEotPosn_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCcwMax_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCcwMin_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCwMax_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnEotCwMin_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMotToHwResl_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsAuthy_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val

# define Rte_Prm_SysGlbPrmSysKineRat_Val Rte_Prm_BmwHwAgArbnAndEotPosn_SysGlbPrmSysKineRat_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val

# define Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl Rte_Prm_BmwHwAgArbnAndEotPosn_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwPinionAgOffsRateLim() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_BmwPinionAgOffsRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CurrAlgndPinionAg() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_CurrAlgndPinionAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionAgConfRampStVari() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PinionAgConfRampStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevBmwOffsAuthy() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevBmwOffsAuthy) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLoopPinionAg() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevLoopPinionAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevPinionAgConf() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevPinionAgConf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AllwExitFromInitTi() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_AllwExitFromInitTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotPosnDegArbdBlndTi() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_MotPosnDegArbdBlndTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_OffsCorrnRefTi() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_OffsCorrnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionAgFltRefTi() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PinionAgFltRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TurnCntrValTi() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_TurnCntrValTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwRackCentrToVehCentrOffsSts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_BmwRackCentrToVehCentrOffsSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FirstLoopIndcr() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_FirstLoopIndcr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_IniTurnCntrCorrlnSts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_IniTurnCntrCorrlnSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevBmwMotAgSelnSt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIgnCycBmwMotAgSelnSt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevIgnCycBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIgnCycNtc8CSts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevIgnCycNtc8CSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIgnCycNtc8ESts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevIgnCycNtc8ESts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevIgnCycTurnCntrCorrlnSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLoopBmwMotAgSelnSt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevLoopBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLoopBmwQuadOffsSts() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevLoopBmwQuadOffsSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_ClrNotCmplPinionAgFlg() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_ClrNotCmplPinionAgFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CurrDftPinionAgFltPrsnt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_CurrDftPinionAgFltPrsnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DynStabyCtrlCdn() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_DynStabyCtrlCdn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_KineIntegrityFlt() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_KineIntegrityFlt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LpFilActvd() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_LpFilActvd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotPosnDegArbdBlndFac() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_MotPosnDegArbdBlndFac) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevAllwCorrn() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevAllwCorrn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevBmwOffsAuthyFlg() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PrevBmwOffsAuthyFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_SetBmwRackCentrToVehCentrOffsTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SigInvldTranTrig() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_SigInvldTranTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TurnCntrCorrlnStsTmrTrig() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_TurnCntrCorrlnStsTmrTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehCentrCmpl() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_VehCentrCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwVehCentrOffs() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_BmwVehCentrOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionAgFilStVari() (Rte_Inst_BmwHwAgArbnAndEotPosn->Pim_PinionAgFilStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwPinionAgOffsRateLim(void)
 *   float32 *Rte_Pim_CurrAlgndPinionAg(void)
 *   float32 *Rte_Pim_PinionAgConfRampStVari(void)
 *   float32 *Rte_Pim_PrevBmwOffsAuthy(void)
 *   float32 *Rte_Pim_PrevLoopPinionAg(void)
 *   float32 *Rte_Pim_PrevPinionAgConf(void)
 *   uint32 *Rte_Pim_AllwExitFromInitTi(void)
 *   uint32 *Rte_Pim_MotPosnDegArbdBlndTi(void)
 *   uint32 *Rte_Pim_OffsCorrnRefTi(void)
 *   uint32 *Rte_Pim_PinionAgFltRefTi(void)
 *   uint32 *Rte_Pim_TurnCntrValTi(void)
 *   BmwRackToVehCentrOffsSts1 *Rte_Pim_BmwRackCentrToVehCentrOffsSts(void)
 *   uint8 *Rte_Pim_FirstLoopIndcr(void)
 *   uint8 *Rte_Pim_IniTurnCntrCorrlnSts(void)
 *   BmwMotAgSelnSt1 *Rte_Pim_PrevBmwMotAgSelnSt(void)
 *   uint8 *Rte_Pim_PrevIgnCycBmwMotAgSelnSt(void)
 *   uint8 *Rte_Pim_PrevIgnCycNtc8CSts(void)
 *   uint8 *Rte_Pim_PrevIgnCycNtc8ESts(void)
 *   uint8 *Rte_Pim_PrevIgnCycTurnCntrCorrlnSts(void)
 *   BmwMotAgSelnSt1 *Rte_Pim_PrevLoopBmwMotAgSelnSt(void)
 *   BmwQuadOffsSts1 *Rte_Pim_PrevLoopBmwQuadOffsSts(void)
 *   uint8 *Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt(void)
 *   boolean *Rte_Pim_ClrNotCmplPinionAgFlg(void)
 *   boolean *Rte_Pim_CurrDftPinionAgFltPrsnt(void)
 *   boolean *Rte_Pim_DynStabyCtrlCdn(void)
 *   boolean *Rte_Pim_KineIntegrityFlt(void)
 *   boolean *Rte_Pim_LpFilActvd(void)
 *   boolean *Rte_Pim_MotPosnDegArbdBlndFac(void)
 *   boolean *Rte_Pim_PrevAllwCorrn(void)
 *   boolean *Rte_Pim_PrevBmwOffsAuthyFlg(void)
 *   boolean *Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig(void)
 *   boolean *Rte_Pim_SigInvldTranTrig(void)
 *   boolean *Rte_Pim_TurnCntrCorrlnStsTmrTrig(void)
 *   boolean *Rte_Pim_VehCentrCmpl(void)
 *   BmwVehCentrOffsRec1 *Rte_Pim_BmwVehCentrOffs(void)
 *   FilLpRec1 *Rte_Pim_PinionAgFilStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint32 Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val(void)
 *   uint32 Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val(void)
 *   boolean Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl(void)
 *
 *********************************************************************************************************************/


# define BmwHwAgArbnAndEotPosn_START_SEC_CODE
# include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwAgArbnAndEotPosnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwHwAgArbnAndEotPosnInit1 BmwHwAgArbnAndEotPosnInit1
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwAgArbnAndEotPosnPer1
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
 *   Std_ReturnType Rte_Read_BmwHwAgOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 *data)
 *   Std_ReturnType Rte_Read_BmwQuadOffsSts_Val(BmwQuadOffsSts1 *data)
 *   Std_ReturnType Rte_Read_BmwQuadOffsStsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwQuadRotorOffs_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_BmwQuadRotorOffsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_CmplncErrMotToPinion_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DiKineIntegrityTest_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
 *   Std_ReturnType Rte_Read_MotAgMeclCorrlnSt_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgTurnCntr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackCentrPinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TotRackTrvl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AlgndPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwRackCentrToVehCentrOffs_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgCcwDetd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgCwDetd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgEotCcw_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwAgEotCw_Val(float32 data)
 *   Std_ReturnType Rte_Write_LongTermVehCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_OffsCmpdPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgConf_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotRev_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwHwAgArbnAndEotPosnPer1 BmwHwAgArbnAndEotPosnPer1
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrBmwRackCentrToVehCentrOffs_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrBmwRackCentrToVehCentrOffs>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrBmwRackCentrToVehCentrOffs_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClrBmwRackCentrToVehCentrOffs_Oper ClrBmwRackCentrToVehCentrOffs_Oper
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrBmwRackCentrToVehCentrOffs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrVehCentrPosn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrVehCentrPosn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrVehCentrPosn_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClrVehCentrPosn_Oper ClrVehCentrPosn_Oper
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrVehCentrPosn_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetVehCentrPosn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetVehCentrPosn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts1 *BmwSetVehCentrOffsSts_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SetVehCentrPosn_Oper SetVehCentrPosn_Oper
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) SetVehCentrPosn_Oper(P2VAR(BmwSetVehCentrOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) BmwSetVehCentrOffsSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwHwAgArbnAndEotPosn_STOP_SEC_CODE
# include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHWAGARBNANDEOTPOSN_H */

#include "Rte_Stubs.h"
