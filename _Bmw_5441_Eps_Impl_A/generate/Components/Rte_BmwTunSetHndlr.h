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
 *          File:  Rte_BmwTunSetHndlr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwTunSetHndlr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWTUNSETHNDLR_H
# define _RTE_BMWTUNSETHNDLR_H

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

# include "Rte_BmwTunSetHndlr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_BmwTunSetHndlr_DesIninIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_BmwTunSetHndlr_DesIninOptSetAIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_BmwTunSetHndlr_DesRtIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwRtIdx1, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_TunSetHndlrEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwRtIdx_Val (15U)
#  define Rte_InitValue_BmwRtIdxVld_Logl (FALSE)
#  define Rte_InitValue_DesIninIdx_Val (0U)
#  define Rte_InitValue_DesIninOptSetAIdx_Val (0U)
#  define Rte_InitValue_DesRtIdx_Val (0U)
#  define Rte_InitValue_TunSetHndlrEna_Logl (TRUE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwRtIdx_Val Rte_Read_BmwTunSetHndlr_BmwRtIdx_Val
#  define Rte_Read_BmwTunSetHndlr_BmwRtIdx_Val(data) (*(data) = Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwRtIdxVld_Logl Rte_Read_BmwTunSetHndlr_BmwRtIdxVld_Logl
#  define Rte_Read_BmwTunSetHndlr_BmwRtIdxVld_Logl(data) (*(data) = Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TunSetHndlrEna_Logl Rte_Read_BmwTunSetHndlr_TunSetHndlrEna_Logl
#  define Rte_Read_BmwTunSetHndlr_TunSetHndlrEna_Logl(data) (*(data) = Rte_BmwSwFctDi_TunSetHndlrEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_DesIninIdx_Val Rte_Write_BmwTunSetHndlr_DesIninIdx_Val
#  define Rte_Write_BmwTunSetHndlr_DesIninIdx_Val(data) (Rte_BmwTunSetHndlr_DesIninIdx_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DesIninOptSetAIdx_Val Rte_Write_BmwTunSetHndlr_DesIninOptSetAIdx_Val
#  define Rte_Write_BmwTunSetHndlr_DesIninOptSetAIdx_Val(data) (Rte_BmwTunSetHndlr_DesIninOptSetAIdx_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DesRtIdx_Val Rte_Write_BmwTunSetHndlr_DesRtIdx_Val
#  define Rte_Write_BmwTunSetHndlr_DesRtIdx_Val(data) (Rte_BmwTunSetHndlr_DesRtIdx_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_BmwDesIninIdx_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)9, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_BmwDesIninIdx_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)9, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)8, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)8, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  define Rte_CData_BmwDesIninIdxDft() (&((P2CONST(Rte_Calprm_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP])->BmwDesIninIdxDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_CData_BmwDesIninOptSetAIdxDft() (&((P2CONST(Rte_Calprm_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP])->BmwDesIninOptSetAIdxDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwTunSetHndlrBmwRtIdxDebThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwTunSetHndlrCptDisadOutp_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwTunSetHndlrNrOfMotVrnt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwTunSetHndlrNrOfTunSet_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwTunSetHndlrOvrdDesRtIdx_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_BmwRtIdxTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwRtIdx1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_DebBmwRtIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_LstVldIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwRtIdx1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_PrevBmwRtIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwDesIninIdxRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_BmwDesIninIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwDesIninOptSetAIdxRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTunSetHndlr_BmwDesIninOptSetAIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwRtIdxTi() \
  (&Rte_BmwTunSetHndlr_BmwRtIdxTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DebBmwRtIdx() \
  (&Rte_BmwTunSetHndlr_DebBmwRtIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LstVldIdx() \
  (&Rte_BmwTunSetHndlr_LstVldIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevBmwRtIdx() \
  (&Rte_BmwTunSetHndlr_PrevBmwRtIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDesIninIdx() \
  (&Rte_BmwTunSetHndlr_BmwDesIninIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDesIninOptSetAIdx() \
  (&Rte_BmwTunSetHndlr_BmwDesIninOptSetAIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwTunSetHndlr_START_SEC_CODE
# include "BmwTunSetHndlr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwTunSetHndlrInit1 BmwTunSetHndlrInit1
#  define RTE_RUNNABLE_BmwTunSetHndlrPer1 BmwTunSetHndlrPer1
#  define RTE_RUNNABLE_MotVrntRead_Oper MotVrntRead_Oper
#  define RTE_RUNNABLE_MotVrntWr_Oper MotVrntWr_Oper
#  define RTE_RUNNABLE_TunVrntRead_Oper TunVrntRead_Oper
#  define RTE_RUNNABLE_TunVrntWr_Oper TunVrntWr_Oper
# endif

FUNC(void, BmwTunSetHndlr_CODE) BmwTunSetHndlrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwTunSetHndlr_CODE) BmwTunSetHndlrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) MotVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) TunVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwTunSetHndlr_STOP_SEC_CODE
# include "BmwTunSetHndlr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_MotVrntRead_PortIf1_E_NOT_OK (1U)

#  define RTE_E_MotVrntWr_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_TunVrntRead_PortIf1_E_NOT_OK (1U)

#  define RTE_E_TunVrntWr_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWTUNSETHNDLR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
