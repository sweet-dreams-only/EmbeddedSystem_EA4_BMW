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
 *          File:  Rte_BmwMsgSlot108Bas0Repn2BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM106A_BmwMsgSlot108Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot108Bas0Repn2BusFrChA
 *  Generated at:  Tue May 29 22:59:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot108Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot108Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot108Bas0Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AvlSteaPniOffsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AvlSteaPniOffsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwPinionAgOffsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissingMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RxMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot108Bas0Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot108Bas0Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS (2046U)
# define Rte_InitValue_BmwPinionAgOffs_Val (0.0F)
# define Rte_InitValue_BmwPinionAgOffsSts_Val (4U)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(P2VAR(AVL_STEA_PNI_OFFS1, AUTOMATIC, RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot108Bas0Repn2BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(sint8, RTE_CODE) Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwPinionAgOffs_Val Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val
# define Rte_Write_BmwPinionAgOffsSts_Val Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot108Bas0Repn2BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwPinionAgOffsPrev() (Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA->Pim_BmwPinionAgOffsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AvlSteaPniOffsFaildCnt() (Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA->Pim_AvlSteaPniOffsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AvlSteaPniOffsPassdCnt() (Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA->Pim_AvlSteaPniOffsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissingMsgCnt() (Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA->Pim_MissingMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RxMsgCnt() (Rte_Inst_BmwMsgSlot108Bas0Repn2BusFrChA->Pim_RxMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwPinionAgOffsPrev(void)
 *   uint8 *Rte_Pim_AvlSteaPniOffsFaildCnt(void)
 *   uint8 *Rte_Pim_AvlSteaPniOffsPassdCnt(void)
 *   uint8 *Rte_Pim_MissingMsgCnt(void)
 *   uint8 *Rte_Pim_RxMsgCnt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot108Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot108Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot108Bas0Repn2BusFrChAInit1
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
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot108Bas0Repn2BusFrChAInit1 BmwMsgSlot108Bas0Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) BmwMsgSlot108Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: STEA_OFFS_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwPinionAgOffs_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data)
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

# define RTE_RUNNABLE_STEA_OFFS_Missing_Oper STEA_OFFS_Missing_Oper
FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) STEA_OFFS_Missing_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: STEA_OFFS_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <AVL_STEA_PNI_OFFS> of PortPrototype <AVL_STEA_PNI_OFFS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(AVL_STEA_PNI_OFFS1 *data)
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwPinionAgOffs_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data)
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

# define RTE_RUNNABLE_STEA_OFFS_Received_Oper STEA_OFFS_Received_Oper
FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) STEA_OFFS_Received_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot108Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot108Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H */
