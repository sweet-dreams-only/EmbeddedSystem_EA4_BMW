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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg1Meas>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG1MEAS_H
# define _RTE_CDD_MOTAG1MEAS_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_MotAg1Meas_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1QepFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1ErrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl1Polarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1SpiMecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1WarnReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg4Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAg1ErrReg_Val (0U)
#  define Rte_InitValue_MotAg1MeclQlfr_Val (0U)
#  define Rte_InitValue_MotAg1ParFltCnt_Val (0U)
#  define Rte_InitValue_MotAg1Polarity_Val (1)
#  define Rte_InitValue_MotAg1QepFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg1SpiMecl_Val (0U)
#  define Rte_InitValue_MotAg1TurnCntr_Val (0.0F)
#  define Rte_InitValue_MotAg1TurnCntrQlfr_Val (0U)
#  define Rte_InitValue_MotAg1TurnCntrReg_Val (0U)
#  define Rte_InitValue_MotAg1TurnCntrRollgCntr_Val (0U)
#  define Rte_InitValue_MotAg1VltgFltCnt_Val (0U)
#  define Rte_InitValue_MotAg1WarnReg_Val (0U)
#  define Rte_InitValue_MotAg4Mecl_Val (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAg1ErrReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1ErrReg_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1ErrReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1ErrReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1ParFltCnt_Val Rte_Read_CDD_MotAg1Meas_MotAg1ParFltCnt_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1ParFltCnt_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1Polarity_Val Rte_Read_CDD_MotAg1Meas_MotAg1Polarity_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1Polarity_Val(data) (*(data) = Rte_PolarityCfg_MotAgMecl1Polarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1SpiMecl_Val Rte_Read_CDD_MotAg1Meas_MotAg1SpiMecl_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1SpiMecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1SpiMecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1TurnCntrReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1TurnCntrReg_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1TurnCntrReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1VltgFltCnt_Val Rte_Read_CDD_MotAg1Meas_MotAg1VltgFltCnt_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1VltgFltCnt_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1WarnReg_Val Rte_Read_CDD_MotAg1Meas_MotAg1WarnReg_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg1WarnReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1WarnReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg4Mecl_Val Rte_Read_CDD_MotAg1Meas_MotAg4Mecl_Val
#  define Rte_Read_CDD_MotAg1Meas_MotAg4Mecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg4Mecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotAg1MeclQlfr_Val Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val
#  define Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val(data) (Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1QepFaild_Logl Rte_Write_CDD_MotAg1Meas_MotAg1QepFaild_Logl
#  define Rte_Write_CDD_MotAg1Meas_MotAg1QepFaild_Logl(data) (Rte_CDD_MotAg1Meas_MotAg1QepFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1TurnCntr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntr_Val
#  define Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntr_Val(data) (Rte_CDD_MotAg1Meas_MotAg1TurnCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1TurnCntrQlfr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val
#  define Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val(data) (Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1TurnCntrRollgCntr_Val Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val
#  define Rte_Write_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val(data) (Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) CnvSnpshtData_s16_Oper(P2VAR(uint32, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CnvSnpshtData_s16_Oper(arg1, arg2) (CnvSnpshtData_s16_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) CnvSnpshtData_u16_Oper(P2VAR(uint32, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CnvSnpshtData_u16_Oper(arg1, arg2) (CnvSnpshtData_u16_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg1Clk_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper IoHwAb_SetFctGpioMotAg1Clk_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg1Cs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper IoHwAb_SetFctGpioMotAg1Cs_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg1Mosi_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper IoHwAb_SetFctGpioMotAg1Mosi_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg1Clk_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper IoHwAb_SetGpioMotAg1Clk_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg1Cs_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper IoHwAb_SetGpioMotAg1Cs_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg1Mosi_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper IoHwAb_SetGpioMotAg1Mosi_Oper
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg1CoeffTbl_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcStsAndSnpshtData10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsAndSnpshtData_Oper SetNtcStsAndSnpshtData10_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_MotAg1CoeffTblDft() (&(((P2CONST(Rte_Calprm_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg1CoeffTblDft[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_CData_MotAg1CoeffTblDft() (&((P2CONST(Rte_Calprm_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg1CoeffTblDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_MotAg1MeasOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->MotAg1MeasOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->MotAg1MeasSnsrIfErrNtcMask_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1QepFaildCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawStsReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawWarnReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1ParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1ParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1PrevSpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1RawMeclPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1TurnCntrParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1TurnCntrParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1VltgFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1VltgFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1PrevTCUpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1TurnCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1InitOffsCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1MeclRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAgMecl1Polarity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1QepFaildPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasPwrRstStsLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_f32_26, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_sm5p12_128, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MotAg1QepFaildCntr() \
  (&Rte_CDD_MotAg1Meas_MotAg1QepFaildCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RawAgReg() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RawErrReg() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RawStsReg() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawStsReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RawWarnReg() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawWarnReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1InitOffs() \
  (&Rte_CDD_MotAg1Meas_MotAg1InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1ParFltCntNtcPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1ParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1ParFltCntPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1ParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1PrevSpiMecl() \
  (&Rte_CDD_MotAg1Meas_MotAg1PrevSpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1RawMeclPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1RawMeclPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1TurnCntrParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1TurnCntrParFltCntPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1TurnCntrParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1VltgFltCntNtcPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1VltgFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1VltgFltCntPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1VltgFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1Delta() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasMotAg1RtOffs() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1PrevTCUpd() \
  (&Rte_CDD_MotAg1Meas_MotAg1PrevTCUpd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1TurnCntrPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1TurnCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1InitOffsCntr() \
  (&Rte_CDD_MotAg1Meas_MotAg1InitOffsCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1MeclRollgCntrPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1MeclRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1TurnCntrRollgCntrPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgMecl1Polarity() \
  (&Rte_CDD_MotAg1Meas_MotAgMecl1Polarity) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1QepFaildPrev() \
  (&Rte_CDD_MotAg1Meas_MotAg1QepFaildPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg1MeasPwrRstStsLtch() \
  (&Rte_CDD_MotAg1Meas_dMotAg1MeasPwrRstStsLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg1CoeffTbl() (&((*RtePim_MotAg1CoeffTbl())[0]))
#  else
#   define Rte_Pim_MotAg1CoeffTbl() RtePim_MotAg1CoeffTbl()
#  endif
#  define RtePim_MotAg1CoeffTbl() \
  (&Rte_CDD_MotAg1Meas_MotAg1CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg1CorrnTbl() (&((*RtePim_MotAg1CorrnTbl())[0]))
#  else
#   define Rte_Pim_MotAg1CorrnTbl() RtePim_MotAg1CorrnTbl()
#  endif
#  define RtePim_MotAg1CorrnTbl() \
  (&Rte_CDD_MotAg1Meas_MotAg1CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_MotAg1Meas_START_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotAg1CoeffTblRead_Oper MotAg1CoeffTblRead_Oper
#  define RTE_RUNNABLE_MotAg1CoeffTblWr_Oper MotAg1CoeffTblWr_Oper
#  define RTE_RUNNABLE_MotAg1MeasInit1 MotAg1MeasInit1
#  define RTE_RUNNABLE_MotAg1MeasPer2 MotAg1MeasPer2
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_MotAg1Meas_STOP_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG1MEAS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
