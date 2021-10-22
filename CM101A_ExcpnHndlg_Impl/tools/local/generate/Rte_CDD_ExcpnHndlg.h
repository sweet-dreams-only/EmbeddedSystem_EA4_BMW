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
 *        Config:  E:/EA4NewTemplate/CM101A_ExcpnHndlg_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_ExcpnHndlg
 *  Generated at:  Wed Sep 20 08:47:59 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_ExcpnHndlg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_EXCPNHNDLG_H
# define _RTE_CDD_EXCPNHNDLG_H

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

# include "Rte_CDD_ExcpnHndlg_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_ExcpnHndlg
{
  /* PIM Handles section */
  P2VAR(Ary1D_u32_4, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_McuDiagcData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_ExcpnHndlg, RTE_CONST, RTE_CONST) Rte_Inst_CDD_ExcpnHndlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_ExcpnHndlg, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ExcpnHndlg_McuDiagcData_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ExcpnHndlg_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_ExcpnHndlg_McuDiagcDataDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u32_4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_ExcpnHndlg_McuDiagcDataDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_McuDiagcData_SetRamBlockStatus Rte_Call_CDD_ExcpnHndlg_McuDiagcData_SetRamBlockStatus
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_ExcpnHndlg_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_McuDiagcDataDft Rte_CData_CDD_ExcpnHndlg_McuDiagcDataDft

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_McuDiagcData() (*Rte_Inst_CDD_ExcpnHndlg->Pim_McuDiagcData) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_McuDiagcData() (Rte_Inst_CDD_ExcpnHndlg->Pim_McuDiagcData) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_McuDiagcData(void)
 *     Returnvalue: uint32* is of type Ary1D_u32_4
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint32 *Rte_CData_McuDiagcDataDft(void)
 *     Returnvalue: uint32* is of type Ary1D_u32_4
 *
 *********************************************************************************************************************/


# define CDD_ExcpnHndlg_START_SEC_CODE
# include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkForStrtUpTest_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ChkForStrtUpTest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ChkForStrtUpTest_Oper(boolean *ExecStrtUpTest_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkForStrtUpTest_Oper ChkForStrtUpTest_Oper
FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ExcpnHndlgInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_McuDiagcData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ExcpnHndlgInit2 ExcpnHndlgInit2
FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgInit2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ExcpnHndlgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ExcpnHndlgPer1 ExcpnHndlgPer1
FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMcuDiagcSpplData_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMcuDiagcSpplData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMcuDiagcSpplData_Oper(uint32 *McuDiagcData1_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetMcuDiagcSpplData_Oper GetMcuDiagcSpplData_Oper
FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcSpplData_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) McuDiagcData1_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_ExcpnHndlg_STOP_SEC_CODE
# include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_EXCPNHNDLG_H */

#include "Rte_Stubs.h"
