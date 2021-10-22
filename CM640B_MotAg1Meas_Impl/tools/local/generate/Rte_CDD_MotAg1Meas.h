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
 *          File:  Rte_CDD_MotAg1Meas.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CM640B_MotAg1Meas_Impl-nz2999/CM640B_MotAg1Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAg1Meas
 *  Generated at:  Tue May 15 13:00:06 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg1Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG1MEAS_H
# define _RTE_CDD_MOTAG1MEAS_H

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

# include "Rte_CDD_MotAg1Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_MotAg1Meas
{
  /* PIM Handles section */
  P2VAR(Ary1D_f32_26, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary1D_sm5p12_128, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1InitOffsCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1MeclRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1ParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1ParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1PrevSpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1PrevTCUpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1QepFaildCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1QepFaildPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1RawMeclPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1TurnCntrParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1TurnCntrParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1TurnCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1TurnCntrRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1VltgFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1VltgFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgMecl1Polarity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawStsReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawWarnReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasPwrRstStsLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_MotAg1Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_MotAg1Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_MotAg1Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAg1ErrReg_Val (0U)
# define Rte_InitValue_MotAg1MeclQlfr_Val (0U)
# define Rte_InitValue_MotAg1ParFltCnt_Val (0U)
# define Rte_InitValue_MotAg1Polarity_Val (1)
# define Rte_InitValue_MotAg1QepFaild_Logl (FALSE)
# define Rte_InitValue_MotAg1SpiMecl_Val (0U)
# define Rte_InitValue_MotAg1TurnCntr_Val (0.0F)
# define Rte_InitValue_MotAg1TurnCntrQlfr_Val (0U)
# define Rte_InitValue_MotAg1TurnCntrReg_Val (0U)
# define Rte_InitValue_MotAg1TurnCntrRollgCntr_Val (0U)
# define Rte_InitValue_MotAg1VltgFltCnt_Val (0U)
# define Rte_InitValue_MotAg1WarnReg_Val (0U)
# define Rte_InitValue_MotAg4Mecl_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1ErrReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1ParFltCnt_Val(P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1SpiMecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1TurnCntrReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1VltgFltCnt_Val(P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg1WarnReg_Val(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAg4Mecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1QepFaild_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntr_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_s16_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_u16_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Clk_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Cs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Mosi_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Clk_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Cs_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Mosi_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u0p16, RTE_CODE) Rte_Prm_CDD_MotAg1Meas_MotAg1MeasOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_MotAg1Meas_MotAg1MeasSnsrIfErrNtcMask_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_26, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAg1ErrReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1ErrReg_Val
# define Rte_Read_MotAg1ParFltCnt_Val Rte_Read_CDD_MotAg1Meas_MotAg1ParFltCnt_Val
# define Rte_Read_MotAg1Polarity_Val Rte_Read_CDD_MotAg1Meas_MotAg1Polarity_Val
# define Rte_Read_MotAg1SpiMecl_Val Rte_Read_CDD_MotAg1Meas_MotAg1SpiMecl_Val
# define Rte_Read_MotAg1TurnCntrReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1TurnCntrReg_Val
# define Rte_Read_MotAg1VltgFltCnt_Val Rte_Read_CDD_MotAg1Meas_MotAg1VltgFltCnt_Val
# define Rte_Read_MotAg1WarnReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1WarnReg_Val
# define Rte_Read_MotAg4Mecl_Val Rte_Read_CDD_MotAg1Meas_MotAg4Mecl_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotAg1MeclQlfr_Val Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val
# define Rte_Write_MotAg1QepFaild_Logl Rte_Write_CDD_MotAg1Meas_MotAg1QepFaild_Logl
# define Rte_Write_MotAg1TurnCntr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntr_Val
# define Rte_Write_MotAg1TurnCntrQlfr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val
# define Rte_Write_MotAg1TurnCntrRollgCntr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CnvSnpshtData_s16_Oper Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_s16_Oper
# define Rte_Call_CnvSnpshtData_u16_Oper Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_u16_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_MotAg1Meas_GetNtcQlfrSts_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Clk_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Cs_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Mosi_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Clk_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Cs_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Mosi_Oper
# define Rte_Call_MotAg1CoeffTbl_GetErrorStatus Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_GetErrorStatus
# define Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_SetRamBlockStatus
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_CDD_MotAg1Meas_SetNtcStsAndSnpshtData_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_MotAg1CoeffTblDft Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_MotAg1MeasOffs_Val Rte_Prm_CDD_MotAg1Meas_MotAg1MeasOffs_Val

# define Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val Rte_Prm_CDD_MotAg1Meas_MotAg1MeasSnsrIfErrNtcMask_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MotAg1QepFaildCntr() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1QepFaildCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawAgReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawErrReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawStsReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawStsReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawWarnReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawWarnReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1InitOffs() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1ParFltCntNtcPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1ParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1ParFltCntPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1ParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1PrevSpiMecl() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1PrevSpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1RawMeclPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1RawMeclPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1TurnCntrParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1TurnCntrParFltCntPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1TurnCntrParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1VltgFltCntNtcPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1VltgFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1VltgFltCntPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1VltgFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1Delta() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RtOffs() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1PrevTCUpd() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1PrevTCUpd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1TurnCntrPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1TurnCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1InitOffsCntr() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1InitOffsCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1MeclRollgCntrPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1MeclRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1TurnCntrRollgCntrPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1TurnCntrRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgMecl1Polarity() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAgMecl1Polarity) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1QepFaildPrev() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1QepFaildPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasPwrRstStsLtch() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasPwrRstStsLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg1CoeffTbl() (*Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg1CoeffTbl() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg1CorrnTbl() (*Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg1CorrnTbl() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_MotAg1QepFaildCntr(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawAgReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawErrReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawStsReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawWarnReg(void)
 *   sint32 *Rte_Pim_MotAg1InitOffs(void)
 *   uint16 *Rte_Pim_MotAg1ParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg1ParFltCntPrev(void)
 *   u0p16 *Rte_Pim_MotAg1PrevSpiMecl(void)
 *   u0p16 *Rte_Pim_MotAg1RawMeclPrev(void)
 *   uint16 *Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg1TurnCntrParFltCntPrev(void)
 *   uint16 *Rte_Pim_MotAg1VltgFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg1VltgFltCntPrev(void)
 *   u0p16 *Rte_Pim_dMotAg1MeasMotAg1Delta(void)
 *   uint16 *Rte_Pim_dMotAg1MeasMotAg1RtOffs(void)
 *   sint16 *Rte_Pim_MotAg1PrevTCUpd(void)
 *   sint16 *Rte_Pim_MotAg1TurnCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg1InitOffsCntr(void)
 *   uint8 *Rte_Pim_MotAg1MeclRollgCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg1TurnCntrRollgCntrPrev(void)
 *   sint8 *Rte_Pim_MotAgMecl1Polarity(void)
 *   boolean *Rte_Pim_MotAg1QepFaildPrev(void)
 *   boolean *Rte_Pim_dMotAg1MeasPwrRstStsLtch(void)
 *   float32 *Rte_Pim_MotAg1CoeffTbl(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *   sm5p12 *Rte_Pim_MotAg1CorrnTbl(void)
 *     Returnvalue: sm5p12* is of type Ary1D_sm5p12_128
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 *Rte_CData_MotAg1CoeffTblDft(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   u0p16 Rte_Prm_MotAg1MeasOffs_Val(void)
 *   uint16 Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_MotAg1Meas_START_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1CoeffTblRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg1CoeffTblRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg1CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1CoeffTblRead_Oper MotAg1CoeffTblRead_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1CoeffTblWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg1CoeffTblWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg1CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1CoeffTblWr_Oper MotAg1CoeffTblWr_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1MeasInit1
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
 *   Std_ReturnType Rte_Read_MotAg1Polarity_Val(sint8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg1CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1MeasInit1 MotAg1MeasInit1
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1MeasPer2
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
 *   Std_ReturnType Rte_Read_MotAg1ErrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg1ParFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg1Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAg1SpiMecl_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotAg1TurnCntrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg1VltgFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg1WarnReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg4Mecl_Val(u0p16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg1MeclQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg1QepFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotAg1TurnCntr_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotAg1TurnCntrQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg1TurnCntrRollgCntr_Val(uint8 data)
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

# define RTE_RUNNABLE_MotAg1MeasPer2 MotAg1MeasPer2
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_MotAg1Meas_STOP_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG1MEAS_H */

#include "Rte_Stubs.h"
