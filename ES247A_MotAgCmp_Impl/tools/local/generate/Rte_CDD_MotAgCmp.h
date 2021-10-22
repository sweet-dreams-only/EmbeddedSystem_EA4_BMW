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
 *          File:  Rte_CDD_MotAgCmp.h
 *        Config:  C:/Users/nz3541/Documents/SynergyWorkingEA4/ES247A_MotAgCmp_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAgCmp
 *  Generated at:  Wed Sep  6 10:51:01 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAgCmp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAGCMP_H
# define _RTE_CDD_MOTAGCMP_H

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

# include "Rte_CDD_MotAgCmp_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_MotAgCmp
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmpEnaCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DigMotHwPosn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCmpMotAgBackEmf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(s15p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(s15p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCmpMotCtrlMotAgMeclPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_MotAgCmp, RTE_CONST, RTE_CONST) Rte_Inst_CDD_MotAgCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_MotAgCmp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssiMechPolarity_Val (1)
# define Rte_InitValue_MotAgCumvAlgndCrf_Val (0)
# define Rte_InitValue_MotAgCumvAlgndMrf_Val (0)
# define Rte_InitValue_MotAgCumvAlgndMrfRev_Val (0)
# define Rte_InitValue_MotAgCumvAlgndVld_Logl (FALSE)
# define Rte_InitValue_MotAgCumvInid_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAgCmp_AssiMechPolarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAgCmp_MotAgCumvAlgndMrfRev_Val(P2VAR(s15p16, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAgCmp_MotAgCumvInid_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndCrf_Val(s18p13 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val(s18p13 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAgCmp_MotAgCmpMotAgBackEmf_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CDD_MotAgCmp_SysGlbPrmSysKineRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_CDD_MotAgCmp_SysGlbPrmMotPoleCnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC(u0p16, RTE_CODE) Rte_CData_CDD_MotAgCmp_MotAgCmpMotAgBackEmfDft(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AssiMechPolarity_Val Rte_Read_CDD_MotAgCmp_AssiMechPolarity_Val
# define Rte_Read_MotAgCumvAlgndMrfRev_Val Rte_Read_CDD_MotAgCmp_MotAgCumvAlgndMrfRev_Val
# define Rte_Read_MotAgCumvInid_Logl Rte_Read_CDD_MotAgCmp_MotAgCumvInid_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotAgCumvAlgndCrf_Val Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndCrf_Val
# define Rte_Write_MotAgCumvAlgndMrf_Val Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val
# define Rte_Write_MotAgCumvAlgndVld_Logl Rte_Write_CDD_MotAgCmp_MotAgCumvAlgndVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus Rte_Call_CDD_MotAgCmp_MotAgCmpMotAgBackEmf_SetRamBlockStatus


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_MotAgCmpMotAgBackEmfDft Rte_CData_CDD_MotAgCmp_MotAgCmpMotAgBackEmfDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SysGlbPrmSysKineRat_Val Rte_Prm_CDD_MotAgCmp_SysGlbPrmSysKineRat_Val

# define Rte_Prm_SysGlbPrmMotPoleCnt_Val Rte_Prm_CDD_MotAgCmp_SysGlbPrmMotPoleCnt_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_DigMotHwPosn() (Rte_Inst_CDD_MotAgCmp->Pim_DigMotHwPosn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() (Rte_Inst_CDD_MotAgCmp->Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() (Rte_Inst_CDD_MotAgCmp->Pim_MotAgCmpMotCtrlMotAgMeclPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCmpMotAgBackEmf() (Rte_Inst_CDD_MotAgCmp->Pim_MotAgCmpMotAgBackEmf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CmpEnaCntr() (Rte_Inst_CDD_MotAgCmp->Pim_CmpEnaCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DigMotHwPosn(void)
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev(void)
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev(void)
 *   u0p16 *Rte_Pim_MotAgCmpMotAgBackEmf(void)
 *   uint8 *Rte_Pim_CmpEnaCntr(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   u0p16 Rte_CData_MotAgCmpMotAgBackEmfDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_MotAgCmp_START_SEC_CODE
# include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAgCmpBackEmfRead_Oper(u0p16 *MotAgBackEmfRead_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCmpBackEmfRead_Oper MotAgCmpBackEmfRead_Oper
FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpBackEmfRead_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) MotAgBackEmfRead_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCmpBackEmfWr_Oper MotAgCmpBackEmfWr_Oper
FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCmpInit1 MotAgCmpInit1
FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpPer2
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
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrfRev_Val(s15p16 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvInid_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndCrf_Val(s18p13 data)
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndMrf_Val(s18p13 data)
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndVld_Logl(boolean data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCmpPer2 MotAgCmpPer2
FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_MotAgCmp_STOP_SEC_CODE
# include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAGCMP_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/

#include "Rte_Stubs.h"
