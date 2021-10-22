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
 *          File:  Rte_SerlComTrcvIf.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/ES340A_SerlComTrcvIf_Impl-nz2999/ES340A_SerlComTrcvIf_Impl/tools/Component.dpa
 *     SW-C Type:  SerlComTrcvIf
 *  Generated at:  Fri Apr  6 08:21:52 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <SerlComTrcvIf> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SERLCOMTRCVIF_H
# define _RTE_SERLCOMTRCVIF_H

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

# include "Rte_SerlComTrcvIf_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_SerlComTrcvIf
{
  /* PIM Handles section */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SerlComTrcvIfFltErrPin; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SerlComTrcvIfSpiErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SerlComTrcvIfSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dSerlComTrcvIfStsReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_SerlComTrcvIf, RTE_CONST, RTE_CONST) Rte_Inst_SerlComTrcvIf; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_SerlComTrcvIf, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_SerlComTrcvIfNoErr_Logl (FALSE)
# define Rte_InitValue_SerlComTrcvIfQlfr_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SerlComTrcvIf_SerlComTrcvIfNoErr_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SerlComTrcvIf_SerlComTrcvIfQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_CnvSnpshtData_u16_Oper(P2VAR(uint32, AUTOMATIC, RTE_SERLCOMTRCVIF_APPL_VAR) SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_SERLCOMTRCVIF_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_IoHwAb_GetGpioERRN_Oper(P2VAR(boolean, AUTOMATIC, RTE_SERLCOMTRCVIF_APPL_VAR) PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_SerlComTrcvIfNoErr_Logl Rte_Write_SerlComTrcvIf_SerlComTrcvIfNoErr_Logl
# define Rte_Write_SerlComTrcvIfQlfr_Val Rte_Write_SerlComTrcvIf_SerlComTrcvIfQlfr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CnvSnpshtData_u16_Oper Rte_Call_SerlComTrcvIf_CnvSnpshtData_u16_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_SerlComTrcvIf_GetNtcQlfrSts_Oper
# define Rte_Call_IoHwAb_GetGpioERRN_Oper Rte_Call_SerlComTrcvIf_IoHwAb_GetGpioERRN_Oper
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_SerlComTrcvIf_SetNtcStsAndSnpshtData_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_dSerlComTrcvIfStsReg() (Rte_Inst_SerlComTrcvIf->Pim_dSerlComTrcvIfStsReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SerlComTrcvIfSpiErrCntr() (Rte_Inst_SerlComTrcvIf->Pim_SerlComTrcvIfSpiErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SerlComTrcvIfSt() (Rte_Inst_SerlComTrcvIf->Pim_SerlComTrcvIfSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SerlComTrcvIfFltErrPin() (Rte_Inst_SerlComTrcvIf->Pim_SerlComTrcvIfFltErrPin) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_dSerlComTrcvIfStsReg(void)
 *   uint8 *Rte_Pim_SerlComTrcvIfSpiErrCntr(void)
 *   uint8 *Rte_Pim_SerlComTrcvIfSt(void)
 *   boolean *Rte_Pim_SerlComTrcvIfFltErrPin(void)
 *
 *********************************************************************************************************************/


# define SerlComTrcvIf_START_SEC_CODE
# include "SerlComTrcvIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SerlComTrcvIfInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SerlComTrcvIfInit1 SerlComTrcvIfInit1
FUNC(void, SerlComTrcvIf_CODE) SerlComTrcvIfInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SerlComTrcvIfPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SerlComTrcvIfNoErr_Logl(boolean data)
 *   Std_ReturnType Rte_Write_SerlComTrcvIfQlfr_Val(SigQlfr1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioERRN_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SerlComTrcvIfPer1 SerlComTrcvIfPer1
FUNC(void, SerlComTrcvIf_CODE) SerlComTrcvIfPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define SerlComTrcvIf_STOP_SEC_CODE
# include "SerlComTrcvIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SERLCOMTRCVIF_H */

#include "Rte_Stubs.h"
