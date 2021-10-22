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
 *          File:  Rte_CDD_MotAg0Meas.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CM620B_MotAg0Meas_Impl-nz2999/CM620B_MotAg0Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAg0Meas
 *  Generated at:  Tue May 15 11:12:25 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg0Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG0MEAS_H
# define _RTE_CDD_MOTAG0MEAS_H

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

# include "Rte_CDD_MotAg0Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_MotAg0Meas
{
  /* PIM Handles section */
  P2VAR(Ary1D_f32_26, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary1D_sm5p12_128, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0InitOffsCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0MeclRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0ParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0ParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0PrevSpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0PrevTCUpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0QepFaildCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0QepFaildPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0RawMeclPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0SnsrCfg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0TurnCntrParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0TurnCntrParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0TurnCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0TurnCntrRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0VltgFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg0VltgFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCtrlRegCfg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgMecl0Polarity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(MotAgSnsrCfgSt1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgSnsrCfgSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RawStsReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RawWarnReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasMotAg0RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg0MeasPwrRstStsLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_MotAg0Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_MotAg0Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_MotAg0Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EgyModSt_Val (0U)
# define Rte_InitValue_MotAg0ErrReg_Val (0U)
# define Rte_InitValue_MotAg0MeclQlfr_Val (0U)
# define Rte_InitValue_MotAg0ParFltCnt_Val (0U)
# define Rte_InitValue_MotAg0Polarity_Val (1)
# define Rte_InitValue_MotAg0QepFaild_Logl (FALSE)
# define Rte_InitValue_MotAg0SnsrCfgAdr_Val (0U)
# define Rte_InitValue_MotAg0SpiMecl_Val (0U)
# define Rte_InitValue_MotAg0TurnCntr_Val (0.0F)
# define Rte_InitValue_MotAg0TurnCntrQlfr_Val (0U)
# define Rte_InitValue_MotAg0TurnCntrReg_Val (0U)
# define Rte_InitValue_MotAg0TurnCntrRollgCntr_Val (0U)
# define Rte_InitValue_MotAg0VltgFltCnt_Val (0U)
# define Rte_InitValue_MotAg0WarnReg_Val (0U)
# define Rte_InitValue_MotAg1MeclQlfr_Val (0U)
# define Rte_InitValue_MotAg1TurnCntrQlfr_Val (0U)
# define Rte_InitValue_MotAg3Mecl_Val (0U)
# define Rte_InitValue_TurnCntrIdptSig_Val (2U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_EgyModSt_Val(P2VAR(EgyModSt1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0ErrReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0ParFltCnt_Val(P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0SpiMecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0TurnCntrReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0VltgFltCnt_Val(P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg0WarnReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg1MeclQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg1TurnCntrQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_MotAg3Mecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg0Meas_TurnCntrIdptSig_Val(P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0QepFaild_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntr_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_CnvSnpshtData_s16_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_CnvSnpshtData_u16_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Clk_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Cs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Mosi_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Clk_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Cs_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Mosi_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_MotAg0CoeffTbl_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_MotAg0CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_MotAg0SnsrCfgDmaStrt_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg0Meas_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_MotAg0Meas_MotAg0MeasSnsrIfErrNtcMask_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_CDD_MotAg0Meas_MotAg0MeasPer2_MotAg0Qlfr(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_CDD_MotAg0Meas_MotAg0MeasPer2_TurnCntr0Qlfr(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(SigQlfr1, RTE_CODE) Rte_IrvRead_CDD_MotAg0Meas_MotAg0MeasPer3_MotAg0Qlfr(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(SigQlfr1, RTE_CODE) Rte_IrvRead_CDD_MotAg0Meas_MotAg0MeasPer3_TurnCntr0Qlfr(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg0Meas_MotAg0CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_26, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg0Meas_MotAg0CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_EgyModSt_Val Rte_Read_CDD_MotAg0Meas_EgyModSt_Val
# define Rte_Read_MotAg0ErrReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0ErrReg_Val
# define Rte_Read_MotAg0ParFltCnt_Val Rte_Read_CDD_MotAg0Meas_MotAg0ParFltCnt_Val
# define Rte_Read_MotAg0Polarity_Val Rte_Read_CDD_MotAg0Meas_MotAg0Polarity_Val
# define Rte_Read_MotAg0SpiMecl_Val Rte_Read_CDD_MotAg0Meas_MotAg0SpiMecl_Val
# define Rte_Read_MotAg0TurnCntrReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0TurnCntrReg_Val
# define Rte_Read_MotAg0VltgFltCnt_Val Rte_Read_CDD_MotAg0Meas_MotAg0VltgFltCnt_Val
# define Rte_Read_MotAg0WarnReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0WarnReg_Val
# define Rte_Read_MotAg1MeclQlfr_Val Rte_Read_CDD_MotAg0Meas_MotAg1MeclQlfr_Val
# define Rte_Read_MotAg1TurnCntrQlfr_Val Rte_Read_CDD_MotAg0Meas_MotAg1TurnCntrQlfr_Val
# define Rte_Read_MotAg3Mecl_Val Rte_Read_CDD_MotAg0Meas_MotAg3Mecl_Val
# define Rte_Read_TurnCntrIdptSig_Val Rte_Read_CDD_MotAg0Meas_TurnCntrIdptSig_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotAg0MeclQlfr_Val Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val
# define Rte_Write_MotAg0QepFaild_Logl Rte_Write_CDD_MotAg0Meas_MotAg0QepFaild_Logl
# define Rte_Write_MotAg0SnsrCfgAdr_Val Rte_Write_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val
# define Rte_Write_MotAg0TurnCntr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntr_Val
# define Rte_Write_MotAg0TurnCntrQlfr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val
# define Rte_Write_MotAg0TurnCntrRollgCntr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CnvSnpshtData_s16_Oper Rte_Call_CDD_MotAg0Meas_CnvSnpshtData_s16_Oper
# define Rte_Call_CnvSnpshtData_u16_Oper Rte_Call_CDD_MotAg0Meas_CnvSnpshtData_u16_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_MotAg0Meas_GetNtcQlfrSts_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Clk_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Cs_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetFctGpioMotAg0Mosi_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Clk_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Cs_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper Rte_Call_CDD_MotAg0Meas_IoHwAb_SetGpioMotAg0Mosi_Oper
# define Rte_Call_MotAg0CoeffTbl_GetErrorStatus Rte_Call_CDD_MotAg0Meas_MotAg0CoeffTbl_GetErrorStatus
# define Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus Rte_Call_CDD_MotAg0Meas_MotAg0CoeffTbl_SetRamBlockStatus
# define Rte_Call_MotAg0SnsrCfgDmaStrt_Oper Rte_Call_CDD_MotAg0Meas_MotAg0SnsrCfgDmaStrt_Oper
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_CDD_MotAg0Meas_SetNtcStsAndSnpshtData_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(data) \
  Rte_IrvWrite_CDD_MotAg0Meas_MotAg0MeasPer2_MotAg0Qlfr(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(data) \
  Rte_IrvWrite_CDD_MotAg0Meas_MotAg0MeasPer2_TurnCntr0Qlfr(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr() \
  Rte_IrvRead_CDD_MotAg0Meas_MotAg0MeasPer3_MotAg0Qlfr()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr() \
  Rte_IrvRead_CDD_MotAg0Meas_MotAg0MeasPer3_TurnCntr0Qlfr()
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_MotAg0CoeffTblDft Rte_CData_CDD_MotAg0Meas_MotAg0CoeffTblDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val Rte_Prm_CDD_MotAg0Meas_MotAg0MeasSnsrIfErrNtcMask_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MotAg0QepFaildCntr() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0QepFaildCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0SnsrCfg() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0SnsrCfg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RawAgReg() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RawErrReg() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RawStsReg() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RawStsReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RawWarnReg() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RawWarnReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0InitOffs() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0RtOffs() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0ParFltCntNtcPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0ParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0ParFltCntPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0ParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0PrevSpiMecl() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0PrevSpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0RawMeclPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0RawMeclPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0TurnCntrParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0TurnCntrParFltCntPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0TurnCntrParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0VltgFltCntNtcPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0VltgFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0VltgFltCntPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0VltgFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasMotAg0Delta() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasMotAg0Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0PrevTCUpd() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0PrevTCUpd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0TurnCntrPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0TurnCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0InitOffsCntr() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0InitOffsCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0MeclRollgCntrPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0MeclRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0TurnCntrRollgCntrPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0TurnCntrRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCtrlRegCfg() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAgCtrlRegCfg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgSnsrCfgSt() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAgSnsrCfgSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgMecl0Polarity() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAgMecl0Polarity) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg0QepFaildPrev() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0QepFaildPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg0MeasPwrRstStsLtch() (Rte_Inst_CDD_MotAg0Meas->Pim_dMotAg0MeasPwrRstStsLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg0CoeffTbl() (*Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg0CoeffTbl() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg0CorrnTbl() (*Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg0CorrnTbl() (Rte_Inst_CDD_MotAg0Meas->Pim_MotAg0CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_MotAg0QepFaildCntr(void)
 *   uint32 *Rte_Pim_MotAg0SnsrCfg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawAgReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawErrReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawStsReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawWarnReg(void)
 *   sint32 *Rte_Pim_MotAg0InitOffs(void)
 *   sint32 *Rte_Pim_dMotAg0MeasMotAg0RtOffs(void)
 *   uint16 *Rte_Pim_MotAg0ParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0ParFltCntPrev(void)
 *   u0p16 *Rte_Pim_MotAg0PrevSpiMecl(void)
 *   u0p16 *Rte_Pim_MotAg0RawMeclPrev(void)
 *   uint16 *Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0TurnCntrParFltCntPrev(void)
 *   uint16 *Rte_Pim_MotAg0VltgFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0VltgFltCntPrev(void)
 *   u0p16 *Rte_Pim_dMotAg0MeasMotAg0Delta(void)
 *   sint16 *Rte_Pim_MotAg0PrevTCUpd(void)
 *   sint16 *Rte_Pim_MotAg0TurnCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg0InitOffsCntr(void)
 *   uint8 *Rte_Pim_MotAg0MeclRollgCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg0TurnCntrRollgCntrPrev(void)
 *   uint8 *Rte_Pim_MotAgCtrlRegCfg(void)
 *   MotAgSnsrCfgSt1 *Rte_Pim_MotAgSnsrCfgSt(void)
 *   sint8 *Rte_Pim_MotAgMecl0Polarity(void)
 *   boolean *Rte_Pim_MotAg0QepFaildPrev(void)
 *   boolean *Rte_Pim_dMotAg0MeasPwrRstStsLtch(void)
 *   float32 *Rte_Pim_MotAg0CoeffTbl(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *   sm5p12 *Rte_Pim_MotAg0CorrnTbl(void)
 *     Returnvalue: sm5p12* is of type Ary1D_sm5p12_128
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 *Rte_CData_MotAg0CoeffTblDft(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_MotAg0Meas_START_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0CoeffTblRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg0CoeffTblRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg0CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg0CoeffTblRead_Oper MotAg0CoeffTblRead_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0CoeffTblWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg0CoeffTblWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg0CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg0CoeffTblWr_Oper MotAg0CoeffTblWr_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAg0Polarity_Val(sint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg0SnsrCfgAdr_Val(uint32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg0CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg0MeasInit1 MotAg0MeasInit1
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasPer2
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
 *   Std_ReturnType Rte_Read_MotAg0ErrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg0ParFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg0Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAg0SpiMecl_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotAg0TurnCntrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg0VltgFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg0WarnReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg3Mecl_Val(u0p16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg0MeclQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg0QepFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntr_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntrQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntrRollgCntr_Val(uint8 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(SigQlfr1 data)
 *   void Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(SigQlfr1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg0MeasPer2 MotAg0MeasPer2
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasPer3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EgyModSt_Val(EgyModSt1 *data)
 *   Std_ReturnType Rte_Read_MotAg1MeclQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAg1TurnCntrQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_TurnCntrIdptSig_Val(uint8 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SigQlfr1 Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr(void)
 *   SigQlfr1 Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_MotAg0SnsrCfgDmaStrt_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg0MeasPer3 MotAg0MeasPer3
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_MotAg0Meas_STOP_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG0MEAS_H */

#include "Rte_Stubs.h"
