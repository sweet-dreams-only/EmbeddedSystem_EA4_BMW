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
 *          File:  Rte_CDD_Adc1CfgAndUse.h
 *        Config:  C:/Users/nz3541/Documents/SynergyWorkingEA4/CM320A_Adc1CfgAndUse_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_Adc1CfgAndUse
 *  Generated at:  Fri Nov 17 09:51:17 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Adc1CfgAndUse> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_ADC1CFGANDUSE_H
# define _RTE_CDD_ADC1CFGANDUSE_H

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

# include "Rte_CDD_Adc1CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_Adc1CfgAndUse
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1DiagcEndPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1DiagcStrtPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_Adc1CfgAndUse, RTE_CONST, RTE_CONST) Rte_Inst_CDD_Adc1CfgAndUse; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_Adc1CfgAndUse, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AdcDiagcEndPtrOutp_Val (23U)
# define Rte_InitValue_AdcDiagcStrtPtrOutp_Val (21U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_Adc1CfgAndUse_AdcDiagcEndPtrOutp_Val(P2VAR(uint8, AUTOMATIC, RTE_CDD_ADC1CFGANDUSE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_Adc1CfgAndUse_AdcDiagcStrtPtrOutp_Val(P2VAR(uint8, AUTOMATIC, RTE_CDD_ADC1CFGANDUSE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AdcDiagcEndPtrOutp_Val Rte_Read_CDD_Adc1CfgAndUse_AdcDiagcEndPtrOutp_Val
# define Rte_Read_AdcDiagcStrtPtrOutp_Val Rte_Read_CDD_Adc1CfgAndUse_AdcDiagcStrtPtrOutp_Val


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_Adc1DiagcEndPtr() (Rte_Inst_CDD_Adc1CfgAndUse->Pim_Adc1DiagcEndPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1DiagcStrtPtr() (Rte_Inst_CDD_Adc1CfgAndUse->Pim_Adc1DiagcStrtPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_Adc1DiagcEndPtr(void)
 *   uint8 *Rte_Pim_Adc1DiagcStrtPtr(void)
 *
 *********************************************************************************************************************/


# define CDD_Adc1CfgAndUse_START_SEC_CODE
# include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseAdc1EnaCnvn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Adc1CfgAndUseAdc1EnaCnvn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Adc1CfgAndUseAdc1EnaCnvn_Oper Adc1CfgAndUseAdc1EnaCnvn_Oper
FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseAdc1EnaCnvn_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Adc1CfgAndUseInit1 Adc1CfgAndUseInit1
FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Adc1CfgAndUsePer1 Adc1CfgAndUsePer1
FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer2
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
 *   Std_ReturnType Rte_Read_AdcDiagcEndPtrOutp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_AdcDiagcStrtPtrOutp_Val(uint8 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Adc1CfgAndUsePer2 Adc1CfgAndUsePer2
FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_Adc1CfgAndUse_STOP_SEC_CODE
# include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_ADC1CFGANDUSE_H */

#include "Rte_Stubs.h"
