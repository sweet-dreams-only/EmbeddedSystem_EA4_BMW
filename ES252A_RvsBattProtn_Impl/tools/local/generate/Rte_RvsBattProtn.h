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
 *          File:  Rte_RvsBattProtn.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/ES252A_RvsBattProtn_Impl-nz2999/ES252A_RvsBattProtn_Impl/tools/Component.dpa
 *     SW-C Type:  RvsBattProtn
 *  Generated at:  Mon Oct 16 13:21:33 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <RvsBattProtn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_RVSBATTPROTN_H
# define _RTE_RVSBATTPROTN_H

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

# include "Rte_RvsBattProtn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_RvsBattProtn
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_RvsBattProtn, RTE_CONST, RTE_CONST) Rte_Inst_RvsBattProtn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_RvsBattProtn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_RvsBattDiagcGndAdc_Val (0.0F)
# define Rte_InitValue_RvsBattDiagcGndAdcFaild_Logl (FALSE)
# define Rte_InitValue_RvsBattDiagcRtnAdc_Val (0.0F)
# define Rte_InitValue_RvsBattDiagcRtnAdcFaild_Logl (FALSE)
# define Rte_InitValue_RvsBattProtnStsQlfr_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RvsBattProtn_RvsBattDiagcGndAdc_Val(P2VAR(float32, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RvsBattProtn_RvsBattDiagcGndAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdc_Val(P2VAR(float32, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_RvsBattProtn_RvsBattProtnStsQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RvsBattProtn_CnvSnpshtData_f32_Oper(P2VAR(uint32, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) SnpshtDataCnvd_Arg, float32 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RvsBattProtn_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_RVSBATTPROTN_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RvsBattProtn_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_RvsBattDiagcGndAdc_Val Rte_Read_RvsBattProtn_RvsBattDiagcGndAdc_Val
# define Rte_Read_RvsBattDiagcGndAdcFaild_Logl Rte_Read_RvsBattProtn_RvsBattDiagcGndAdcFaild_Logl
# define Rte_Read_RvsBattDiagcRtnAdc_Val Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdc_Val
# define Rte_Read_RvsBattDiagcRtnAdcFaild_Logl Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdcFaild_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_RvsBattProtnStsQlfr_Val Rte_Write_RvsBattProtn_RvsBattProtnStsQlfr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CnvSnpshtData_f32_Oper Rte_Call_RvsBattProtn_CnvSnpshtData_f32_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_RvsBattProtn_GetNtcQlfrSts_Oper
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_RvsBattProtn_SetNtcStsAndSnpshtData_Oper




# define RvsBattProtn_START_SEC_CODE
# include "RvsBattProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: RvsBattProtnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RvsBattProtnInit1 RvsBattProtnInit1
FUNC(void, RvsBattProtn_CODE) RvsBattProtnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RvsBattProtnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RvsBattDiagcGndAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RvsBattDiagcGndAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RvsBattDiagcRtnAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RvsBattDiagcRtnAdcFaild_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RvsBattProtnStsQlfr_Val(SigQlfr1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CnvSnpshtData_f32_Oper(uint32 *SnpshtDataCnvd_Arg, float32 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RvsBattProtnPer1 RvsBattProtnPer1
FUNC(void, RvsBattProtn_CODE) RvsBattProtnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RvsBattProtn_STOP_SEC_CODE
# include "RvsBattProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_RVSBATTPROTN_H */

#include "Rte_Stubs.h"
