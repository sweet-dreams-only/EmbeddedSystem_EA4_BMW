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
 *          File:  Rte_CDD_BattRtnCurr.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/ES251A_BattRtnCurr_Impl-nz2999/ES251A_BattRtnCurr_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_BattRtnCurr
 *  Generated at:  Wed Oct 11 14:48:46 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_BattRtnCurr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_BATTRTNCURR_H
# define _RTE_CDD_BATTRTNCURR_H

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

# include "Rte_CDD_BattRtnCurr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_BattRtnCurr
{
  /* PIM Handles section */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BattCurrEstimDifLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dBattRtnCurrBfrSatn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_BattRtnCurr, RTE_CONST, RTE_CONST) Rte_Inst_CDD_BattRtnCurr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_BattRtnCurr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BattRtnCurrAdc_Val (0.0F)
# define Rte_InitValue_BattRtnCurrAdcFaild_Logl (FALSE)
# define Rte_InitValue_BattRtnCurrAmpr_Val (0.0F)
# define Rte_InitValue_BattRtnCurrStsQlfr_Val (0U)
# define Rte_InitValue_SplyCurrEstim_Val (0.0F)
# define Rte_InitValue_SysSt_Val (3U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdc_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_BattRtnCurr_SplyCurrEstim_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_BattRtnCurr_SysSt_Val(P2VAR(SysSt1, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_BattRtnCurr_BattRtnCurrAmpr_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_BattRtnCurr_CnvSnpshtData_f32_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) SnpshtDataCnvd_Arg, float32 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_BattRtnCurr_CnvSnpshtData_u08_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) SnpshtDataCnvd_Arg, uint8 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_BattRtnCurr_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_BATTRTNCURR_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_BattRtnCurr_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BattRtnCurrAdc_Val Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdc_Val
# define Rte_Read_BattRtnCurrAdcFaild_Logl Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdcFaild_Logl
# define Rte_Read_SplyCurrEstim_Val Rte_Read_CDD_BattRtnCurr_SplyCurrEstim_Val
# define Rte_Read_SysSt_Val Rte_Read_CDD_BattRtnCurr_SysSt_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BattRtnCurrAmpr_Val Rte_Write_CDD_BattRtnCurr_BattRtnCurrAmpr_Val
# define Rte_Write_BattRtnCurrStsQlfr_Val Rte_Write_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CnvSnpshtData_f32_Oper Rte_Call_CDD_BattRtnCurr_CnvSnpshtData_f32_Oper
# define Rte_Call_CnvSnpshtData_u08_Oper Rte_Call_CDD_BattRtnCurr_CnvSnpshtData_u08_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_BattRtnCurr_GetNtcQlfrSts_Oper
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_CDD_BattRtnCurr_SetNtcStsAndSnpshtData_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_dBattRtnCurrBfrSatn() (Rte_Inst_CDD_BattRtnCurr->Pim_dBattRtnCurrBfrSatn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BattCurrEstimDifLpFil() (Rte_Inst_CDD_BattRtnCurr->Pim_BattCurrEstimDifLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dBattRtnCurrBfrSatn(void)
 *   FilLpRec1 *Rte_Pim_BattCurrEstimDifLpFil(void)
 *
 *********************************************************************************************************************/


# define CDD_BattRtnCurr_START_SEC_CODE
# include "CDD_BattRtnCurr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattRtnCurrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BattRtnCurrInit1 BattRtnCurrInit1
FUNC(void, CDD_BattRtnCurr_CODE) BattRtnCurrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattRtnCurrPer2
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
 *   Std_ReturnType Rte_Read_BattRtnCurrAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattRtnCurrAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SplyCurrEstim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BattRtnCurrAmpr_Val(float32 data)
 *   Std_ReturnType Rte_Write_BattRtnCurrStsQlfr_Val(SigQlfr1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CnvSnpshtData_f32_Oper(uint32 *SnpshtDataCnvd_Arg, float32 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CnvSnpshtData_u08_Oper(uint32 *SnpshtDataCnvd_Arg, uint8 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BattRtnCurrPer2 BattRtnCurrPer2
FUNC(void, CDD_BattRtnCurr_CODE) BattRtnCurrPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_BattRtnCurr_STOP_SEC_CODE
# include "CDD_BattRtnCurr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_BATTRTNCURR_H */

#include "Rte_Stubs.h"
