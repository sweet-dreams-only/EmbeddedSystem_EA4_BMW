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
 *          File:  Rte_BmwMsgSlot107Bas0Repn1BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM105A_BmwMsgSlot107Bas0Repn1BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot107Bas0Repn1BusFrChA
 *  Generated at:  Fri Jun  8 11:01:56 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot107Bas0Repn1BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H
# define _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H

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

# include "Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot107Bas0Repn1BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AvlPoIdxIcmFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AvlPoIdxIcmPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwActIntgtdCtrlModlPosnIdxValPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwQuadOffsSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwQuadOffsStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwQuadRtrOffsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(AVL_PO_IDX_ICM1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(ST_OFFS_QUAD_EPS1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(OFFS_QUAD_RTR_EPS1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_OffsQuadRtrEpsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_OffsQuadRtrEpsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StOffsQuadEpsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StOffsQuadEpsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot107Bas0Repn1BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot107Bas0Repn1BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwActIntgtdCtrlModlPosnIdxValVld_Logl (FALSE)
# define Rte_InitValue_BmwQuadOffsSts_Val (15U)
# define Rte_InitValue_BmwQuadOffsStsVld_Logl (FALSE)
# define Rte_InitValue_BmwQuadRtrOffs_Val (0)
# define Rte_InitValue_BmwQuadRtrOffsVld_Logl (FALSE)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(P2VAR(sigGroup_OFFS_QUAD_EPS1, AUTOMATIC, RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val(sint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot107Bas0Repn1BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(sint8, RTE_CODE) Rte_Prm_BmwMsgSlot107Bas0Repn1BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl
# define Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS Rte_IsUpdated_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val
# define Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl
# define Rte_Write_BmwQuadOffsSts_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val
# define Rte_Write_BmwQuadOffsStsVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl
# define Rte_Write_BmwQuadRtrOffs_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val
# define Rte_Write_BmwQuadRtrOffsVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot107Bas0Repn1BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val Rte_Prm_BmwMsgSlot107Bas0Repn1BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_BmwActIntgtdCtrlModlPosnIdxValPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM1() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvFaildCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvPassdCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AvlPoIdxIcmFaildCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_AvlPoIdxIcmFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AvlPoIdxIcmPassdCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_AvlPoIdxIcmPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwQuadOffsStsPrev() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_BmwQuadOffsStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcFaildCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcPassdCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM2() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM3() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_Dummy_PIM3) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissMsgCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_OffsQuadRtrEpsFaildCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_OffsQuadRtrEpsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_OffsQuadRtrEpsPassdCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_OffsQuadRtrEpsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RxdMsgCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StOffsQuadEpsFaildCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_StOffsQuadEpsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StOffsQuadEpsPassdCnt() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_StOffsQuadEpsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwQuadRtrOffsPrev() (Rte_Inst_BmwMsgSlot107Bas0Repn1BusFrChA->Pim_BmwQuadRtrOffsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev(void)
 *   AVL_PO_IDX_ICM1 *Rte_Pim_Dummy_PIM1(void)
 *   uint8 *Rte_Pim_AlvFaildCnt(void)
 *   uint8 *Rte_Pim_AlvPassdCnt(void)
 *   uint8 *Rte_Pim_AvlPoIdxIcmFaildCnt(void)
 *   uint8 *Rte_Pim_AvlPoIdxIcmPassdCnt(void)
 *   BmwQuadOffsSts1 *Rte_Pim_BmwQuadOffsStsPrev(void)
 *   uint8 *Rte_Pim_CrcFaildCnt(void)
 *   uint8 *Rte_Pim_CrcPassdCnt(void)
 *   ST_OFFS_QUAD_EPS1 *Rte_Pim_Dummy_PIM2(void)
 *   OFFS_QUAD_RTR_EPS1 *Rte_Pim_Dummy_PIM3(void)
 *   uint8 *Rte_Pim_MissMsgCnt(void)
 *   uint8 *Rte_Pim_OffsQuadRtrEpsFaildCnt(void)
 *   uint8 *Rte_Pim_OffsQuadRtrEpsPassdCnt(void)
 *   uint8 *Rte_Pim_RxdMsgCnt(void)
 *   uint8 *Rte_Pim_StOffsQuadEpsFaildCnt(void)
 *   uint8 *Rte_Pim_StOffsQuadEpsPassdCnt(void)
 *   sint8 *Rte_Pim_BmwQuadRtrOffsPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_CODE
# include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot107Bas0Repn1BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data)
 *   boolean Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsStsVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data)
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

# define RTE_RUNNABLE_BmwMsgSlot107Bas0Repn1BusFrChAInit1 BmwMsgSlot107Bas0Repn1BusFrChAInit1
FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) BmwMsgSlot107Bas0Repn1BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OFFS_QUAD_EPS_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_OFFS_QUAD_EPS> of PortPrototype <sigGroup_OFFS_QUAD_EPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data)
 *   boolean Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsStsVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadRtrOffs_Val(sint8 data)
 *   Std_ReturnType Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data)
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

# define RTE_RUNNABLE_OFFS_QUAD_EPS_Missing_Oper OFFS_QUAD_EPS_Missing_Oper
FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) OFFS_QUAD_EPS_Missing_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OFFS_QUAD_EPS_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_OFFS_QUAD_EPS> of PortPrototype <sigGroup_OFFS_QUAD_EPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data)
 *   boolean Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data)
 *   Std_ReturnType Rte_Write_BmwQuadOffsStsVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwQuadRtrOffs_Val(sint8 data)
 *   Std_ReturnType Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data)
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

# define RTE_RUNNABLE_OFFS_QUAD_EPS_Received_Oper OFFS_QUAD_EPS_Received_Oper
FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) OFFS_QUAD_EPS_Received_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H */
