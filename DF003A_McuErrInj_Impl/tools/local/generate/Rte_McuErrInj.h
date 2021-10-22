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
 *          File:  Rte_McuErrInj.h
 *     SW-C Type:  McuErrInj
 *  Generated at:  Thu Mar 16 15:35:54 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <McuErrInj> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MCUERRINJ_H
# define _RTE_MCUERRINJ_H

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

# include "Rte_McuErrInj_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_McuErrInj
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ErrInjActvCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StrtErrInj; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_McuErrInj, RTE_CONST, RTE_CONST) Rte_Inst_McuErrInj; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_McuErrInj, TYPEDEF, RTE_CONST) Rte_Instance;



/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_ErrInjActvCntr() (Rte_Inst_McuErrInj->Pim_ErrInjActvCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StrtErrInj() (Rte_Inst_McuErrInj->Pim_StrtErrInj) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_ErrInjActvCntr(void)
 *   boolean *Rte_Pim_StrtErrInj(void)
 *
 *********************************************************************************************************************/


# define McuErrInj_START_SEC_CODE
# include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrErrInjReg_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClrErrInjReg_Oper ClrErrInjReg_Oper
FUNC(void, McuErrInj_CODE) ClrErrInjReg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_McuErrInjInit1 McuErrInjInit1
FUNC(void, McuErrInj_CODE) McuErrInjInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_McuErrInjPer1 McuErrInjPer1
FUNC(void, McuErrInj_CODE) McuErrInjPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ReadErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ReadErrInjReg_Oper ReadErrInjReg_Oper
FUNC(void, McuErrInj_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtErrInjCntr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <StrtErrInjCntr>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void StrtErrInjCntr_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_StrtErrInjCntr_Oper StrtErrInjCntr_Oper
FUNC(void, McuErrInj_CODE) StrtErrInjCntr_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: UpdErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <UpdErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_UpdErrInjReg_Oper UpdErrInjReg_Oper
FUNC(void, McuErrInj_CODE) UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define McuErrInj_STOP_SEC_CODE
# include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1489686140
#    error "The magic number of the generated file <C:/Component/DF003A_McuErrInj_Impl/tools/contract/Rte_McuErrInj.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1489686140
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_MCUERRINJ_H */
