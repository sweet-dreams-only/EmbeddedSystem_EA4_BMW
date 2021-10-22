/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_Tauj0CfgAndUse.h
 *     SW-C Type:  CDD_Tauj0CfgAndUse
 *  Generated at:  Tue Aug 11 12:24:34 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Tauj0CfgAndUse> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_TAUJ0CFGANDUSE_H
# define _RTE_CDD_TAUJ0CFGANDUSE_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_Tauj0CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_Tauj0CfgAndUse
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PhaOnTiCntrAPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PhaOnTiCntrBPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PhaOnTiCntrCPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_Tauj0CfgAndUse, RTE_CONST, RTE_CONST) Rte_Inst_CDD_Tauj0CfgAndUse; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_Tauj0CfgAndUse, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_PhaOnTiMeasdA_Val (0U)
# define Rte_InitValue_PhaOnTiMeasdB_Val (0U)
# define Rte_InitValue_PhaOnTiMeasdC_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PhaOnTiMeasdA_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val
# define Rte_Write_PhaOnTiMeasdB_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val
# define Rte_Write_PhaOnTiMeasdC_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PhaOnTiCntrAPrev() (Rte_Inst_CDD_Tauj0CfgAndUse->Pim_PhaOnTiCntrAPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PhaOnTiCntrBPrev() (Rte_Inst_CDD_Tauj0CfgAndUse->Pim_PhaOnTiCntrBPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PhaOnTiCntrCPrev() (Rte_Inst_CDD_Tauj0CfgAndUse->Pim_PhaOnTiCntrCPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_PhaOnTiCntrAPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrBPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrCPrev(void)
 *
 *********************************************************************************************************************/


# define CDD_Tauj0CfgAndUse_START_SEC_CODE
# include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Tauj0CfgAndUseInit1 Tauj0CfgAndUseInit1
FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUseInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdA_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdB_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdC_Val(uint32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Tauj0CfgAndUsePer1 Tauj0CfgAndUsePer1
FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUsePer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_Tauj0CfgAndUse_STOP_SEC_CODE
# include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1439312992
#    error "The magic number of the generated file <C:/component/CM455A_Tauj0CfgAndUse_Impl/tools/contract/Rte_CDD_Tauj0CfgAndUse.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1439312992
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CDD_TAUJ0CFGANDUSE_H */
