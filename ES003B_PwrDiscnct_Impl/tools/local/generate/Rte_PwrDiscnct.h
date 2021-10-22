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
 *          File:  Rte_PwrDiscnct.h
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/ES003B_PwrDiscnct_Impl/tools/Component.dpa
 *     SW-C Type:  PwrDiscnct
 *  Generated at:  Wed Jun  7 08:08:43 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PwrDiscnct> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PWRDISCNCT_H
# define _RTE_PWRDISCNCT_H

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

# include "Rte_PwrDiscnct_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_PwrDiscnct
{
  /* PIM Handles section */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PwrDiscnctATestCmplPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_PwrDiscnct, RTE_CONST, RTE_CONST) Rte_Inst_PwrDiscnct; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_PwrDiscnct, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BattVltg_Val (0.0F)
# define Rte_InitValue_BattVltgSwd1_Val (0.0F)
# define Rte_InitValue_PwrDiscnctATestCmpl_Logl (FALSE)
# define Rte_InitValue_PwrDiscnctBTestCmpl_Logl (FALSE)
# define Rte_InitValue_StrtUpSt_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrDiscnct_BattVltg_Val(P2VAR(float32, AUTOMATIC, RTE_PWRDISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrDiscnct_BattVltgSwd1_Val(P2VAR(float32, AUTOMATIC, RTE_PWRDISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrDiscnct_StrtUpSt_Val(P2VAR(uint8, AUTOMATIC, RTE_PWRDISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PwrDiscnct_PwrDiscnctATestCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PwrDiscnct_PwrDiscnctBTestCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrDiscnct_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_PWRDISCNCT_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrDiscnct_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PwrDiscnct_BattVltgSwdMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BattVltg_Val Rte_Read_PwrDiscnct_BattVltg_Val
# define Rte_Read_BattVltgSwd1_Val Rte_Read_PwrDiscnct_BattVltgSwd1_Val
# define Rte_Read_StrtUpSt_Val Rte_Read_PwrDiscnct_StrtUpSt_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PwrDiscnctATestCmpl_Logl Rte_Write_PwrDiscnct_PwrDiscnctATestCmpl_Logl
# define Rte_Write_PwrDiscnctBTestCmpl_Logl Rte_Write_PwrDiscnct_PwrDiscnctBTestCmpl_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_PwrDiscnct_GetNtcQlfrSts_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_PwrDiscnct_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BattVltgSwdMax_Val Rte_Prm_PwrDiscnct_BattVltgSwdMax_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PwrDiscnctATestCmplPrev() (Rte_Inst_PwrDiscnct->Pim_PwrDiscnctATestCmplPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   boolean *Rte_Pim_PwrDiscnctATestCmplPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BattVltgSwdMax_Val(void)
 *
 *********************************************************************************************************************/


# define PwrDiscnct_START_SEC_CODE
# include "PwrDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrDiscnctInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PwrDiscnctInit1 PwrDiscnctInit1
FUNC(void, PwrDiscnct_CODE) PwrDiscnctInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrDiscnctPer1
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
 *   Std_ReturnType Rte_Read_BattVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattVltgSwd1_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StrtUpSt_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PwrDiscnctATestCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_PwrDiscnctBTestCmpl_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PwrDiscnctPer1 PwrDiscnctPer1
FUNC(void, PwrDiscnct_CODE) PwrDiscnctPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PwrDiscnct_STOP_SEC_CODE
# include "PwrDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PWRDISCNCT_H */

#include "Rte_Stubs.h"
