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
 *          File:  Rte_CDD_ExcpnHndlg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_ExcpnHndlg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_EXCPNHNDLG_H
# define _RTE_CDD_EXCPNHNDLG_H

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

# include "Rte_CDD_ExcpnHndlg_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_McuDiagcData_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_McuDiagcDataDft() (&(((P2CONST(Rte_Calprm_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP])->McuDiagcDataDft[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_CData_McuDiagcDataDft() (&((P2CONST(Rte_Calprm_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP])->McuDiagcDataDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Ary1D_u32_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_ExcpnHndlg_McuDiagcData; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_McuDiagcData() (&((*RtePim_McuDiagcData())[0]))
#  else
#   define Rte_Pim_McuDiagcData() RtePim_McuDiagcData()
#  endif
#  define RtePim_McuDiagcData() \
  (&Rte_CDD_ExcpnHndlg_McuDiagcData) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_ExcpnHndlg_START_SEC_CODE
# include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ChkForStrtUpTest_Oper ChkForStrtUpTest_Oper
#  define RTE_RUNNABLE_ExcpnHndlgInit2 ExcpnHndlgInit2
#  define RTE_RUNNABLE_ExcpnHndlgPer1 ExcpnHndlgPer1
#  define RTE_RUNNABLE_GetMcuDiagcSpplData_Oper GetMcuDiagcSpplData_Oper
# endif

FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgInit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcSpplData_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) McuDiagcData1_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_ExcpnHndlg_STOP_SEC_CODE
# include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_EXCPNHNDLG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
