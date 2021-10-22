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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg0Meas>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG0MEAS_H
# define _RTE_CDD_MOTAG0MEAS_H

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

# include "Rte_CDD_MotAg0Meas_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrIdptSig_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0QepFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EgyModSt1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_EgyModSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0ErrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl0Polarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0SpiMecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0WarnReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg3Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EgyModSt_Val (0U)
#  define Rte_InitValue_MotAg0ErrReg_Val (0U)
#  define Rte_InitValue_MotAg0MeclQlfr_Val (0U)
#  define Rte_InitValue_MotAg0ParFltCnt_Val (0U)
#  define Rte_InitValue_MotAg0Polarity_Val (1)
#  define Rte_InitValue_MotAg0QepFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg0SnsrCfgAdr_Val (0U)
#  define Rte_InitValue_MotAg0SpiMecl_Val (0U)
#  define Rte_InitValue_MotAg0TurnCntr_Val (0.0F)
#  define Rte_InitValue_MotAg0TurnCntrQlfr_Val (0U)
#  define Rte_InitValue_MotAg0TurnCntrReg_Val (0U)
#  define Rte_InitValue_MotAg0TurnCntrRollgCntr_Val (0U)
#  define Rte_InitValue_MotAg0VltgFltCnt_Val (0U)
#  define Rte_InitValue_MotAg0WarnReg_Val (0U)
#  define Rte_InitValue_MotAg1MeclQlfr_Val (0U)
#  define Rte_InitValue_MotAg1TurnCntrQlfr_Val (0U)
#  define Rte_InitValue_MotAg3Mecl_Val (0U)
#  define Rte_InitValue_TurnCntrIdptSig_Val (2U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg0Qlfr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_TurnCntr0Qlfr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EgyModSt_Val Rte_Read_CDD_MotAg0Meas_EgyModSt_Val
#  define Rte_Read_CDD_MotAg0Meas_EgyModSt_Val(data) (*(data) = Rte_CDD_MotAg0Meas_EgyModSt_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0ErrReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0ErrReg_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0ErrReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0ErrReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0ParFltCnt_Val Rte_Read_CDD_MotAg0Meas_MotAg0ParFltCnt_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0ParFltCnt_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0Polarity_Val Rte_Read_CDD_MotAg0Meas_MotAg0Polarity_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0Polarity_Val(data) (*(data) = Rte_PolarityCfg_MotAgMecl0Polarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0SpiMecl_Val Rte_Read_CDD_MotAg0Meas_MotAg0SpiMecl_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0SpiMecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0SpiMecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0TurnCntrReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0TurnCntrReg_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0TurnCntrReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0VltgFltCnt_Val Rte_Read_CDD_MotAg0Meas_MotAg0VltgFltCnt_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0VltgFltCnt_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0WarnReg_Val Rte_Read_CDD_MotAg0Meas_MotAg0WarnReg_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg0WarnReg_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0WarnReg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1MeclQlfr_Val Rte_Read_CDD_MotAg0Meas_MotAg1MeclQlfr_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg1MeclQlfr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1TurnCntrQlfr_Val Rte_Read_CDD_MotAg0Meas_MotAg1TurnCntrQlfr_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg1TurnCntrQlfr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg3Mecl_Val Rte_Read_CDD_MotAg0Meas_MotAg3Mecl_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAg3Mecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg3Mecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TurnCntrIdptSig_Val Rte_Read_CDD_MotAg0Meas_TurnCntrIdptSig_Val
#  define Rte_Read_CDD_MotAg0Meas_TurnCntrIdptSig_Val(data) (*(data) = Rte_TurnCntrCorrln_TurnCntrIdptSig_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotAg0MeclQlfr_Val Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0QepFaild_Logl Rte_Write_CDD_MotAg0Meas_MotAg0QepFaild_Logl
#  define Rte_Write_CDD_MotAg0Meas_MotAg0QepFaild_Logl(data) (Rte_CDD_MotAg0Meas_MotAg0QepFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0SnsrCfgAdr_Val Rte_Write_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0TurnCntr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0TurnCntrQlfr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0TurnCntrRollgCntr_Val Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg0Clk_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper IoHwAb_SetFctGpioMotAg0Clk_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg0Cs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper IoHwAb_SetFctGpioMotAg0Cs_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg0Mosi_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper IoHwAb_SetFctGpioMotAg0Mosi_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg0Clk_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper IoHwAb_SetGpioMotAg0Clk_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg0Cs_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper IoHwAb_SetGpioMotAg0Cs_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg0Mosi_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper IoHwAb_SetGpioMotAg0Mosi_Oper
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg0CoeffTbl_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CDD_DMACFGANDUSE_APPL_CODE) MotAg0SnsrCfgDmaStrt_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg0SnsrCfgDmaStrt_Oper MotAg0SnsrCfgDmaStrt_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcStsAndSnpshtData10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsAndSnpshtData_Oper SetNtcStsAndSnpshtData10_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(data) \
  (Rte_Irv_CDD_MotAg0Meas_MotAg0Qlfr = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(data) \
  (Rte_Irv_CDD_MotAg0Meas_TurnCntr0Qlfr = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr() \
  Rte_Irv_CDD_MotAg0Meas_MotAg0Qlfr
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr() \
  Rte_Irv_CDD_MotAg0Meas_TurnCntr0Qlfr
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_MotAg0CoeffTblDft() (&(((P2CONST(Rte_Calprm_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg0CoeffTblDft[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_CData_MotAg0CoeffTblDft() (&((P2CONST(Rte_Calprm_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg0CoeffTblDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->MotAg0MeasSnsrIfErrNtcMask_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0QepFaildCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0SnsrCfg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawStsReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawWarnReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0ParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0ParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevSpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0RawMeclPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0TurnCntrParFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0TurnCntrParFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0VltgFltCntNtcPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0VltgFltCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevTCUpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0TurnCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0InitOffsCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAgCtrlRegCfg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(MotAgSnsrCfgSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAgSnsrCfgSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAgMecl0Polarity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0QepFaildPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasPwrRstStsLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_f32_26, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_sm5p12_128, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MotAg0QepFaildCntr() \
  (&Rte_CDD_MotAg0Meas_MotAg0QepFaildCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0SnsrCfg() \
  (&Rte_CDD_MotAg0Meas_MotAg0SnsrCfg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawAgReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawErrReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawStsReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawStsReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawWarnReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawWarnReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0InitOffs() \
  (&Rte_CDD_MotAg0Meas_MotAg0InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RtOffs() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0ParFltCntNtcPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0ParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0ParFltCntPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0ParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0PrevSpiMecl() \
  (&Rte_CDD_MotAg0Meas_MotAg0PrevSpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0RawMeclPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0RawMeclPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0TurnCntrParFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0TurnCntrParFltCntPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0TurnCntrParFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0VltgFltCntNtcPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0VltgFltCntNtcPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0VltgFltCntPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0VltgFltCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0Delta() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0PrevTCUpd() \
  (&Rte_CDD_MotAg0Meas_MotAg0PrevTCUpd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0TurnCntrPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0TurnCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0InitOffsCntr() \
  (&Rte_CDD_MotAg0Meas_MotAg0InitOffsCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0MeclRollgCntrPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0TurnCntrRollgCntrPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgCtrlRegCfg() \
  (&Rte_CDD_MotAg0Meas_MotAgCtrlRegCfg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgSnsrCfgSt() \
  (&Rte_CDD_MotAg0Meas_MotAgSnsrCfgSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgMecl0Polarity() \
  (&Rte_CDD_MotAg0Meas_MotAgMecl0Polarity) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0QepFaildPrev() \
  (&Rte_CDD_MotAg0Meas_MotAg0QepFaildPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasPwrRstStsLtch() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasPwrRstStsLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg0CoeffTbl() (&((*RtePim_MotAg0CoeffTbl())[0]))
#  else
#   define Rte_Pim_MotAg0CoeffTbl() RtePim_MotAg0CoeffTbl()
#  endif
#  define RtePim_MotAg0CoeffTbl() \
  (&Rte_CDD_MotAg0Meas_MotAg0CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg0CorrnTbl() (&((*RtePim_MotAg0CorrnTbl())[0]))
#  else
#   define Rte_Pim_MotAg0CorrnTbl() RtePim_MotAg0CorrnTbl()
#  endif
#  define RtePim_MotAg0CorrnTbl() \
  (&Rte_CDD_MotAg0Meas_MotAg0CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_MotAg0Meas_START_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotAg0CoeffTblRead_Oper MotAg0CoeffTblRead_Oper
#  define RTE_RUNNABLE_MotAg0CoeffTblWr_Oper MotAg0CoeffTblWr_Oper
#  define RTE_RUNNABLE_MotAg0MeasInit1 MotAg0MeasInit1
#  define RTE_RUNNABLE_MotAg0MeasPer2 MotAg0MeasPer2
#  define RTE_RUNNABLE_MotAg0MeasPer3 MotAg0MeasPer3
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_MotAg0Meas_STOP_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG0MEAS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
