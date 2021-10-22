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
 *          File:  Rte_BmwMsgSlot55Bas3Repn4BusFrChA.h
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM098A_BmwMsgSlot55Bas3Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot55Bas3Repn4BusFrChA
 *  Generated at:  Fri Jun 22 07:51:47 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot55Bas3Repn4BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H
# define _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H

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

# include "Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot55Bas3Repn4BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwCogVehSpdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwCogVehSpdQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwCogVehSpdQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwNearStillVehSpdSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwNearStillVehSpdStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(QU_V_VEH_COG1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(ST_V_VEH_NSS1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QlfrCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QlfrCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StVehNearStillFailCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StVehNearStillPassCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot55Bas3Repn4BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot55Bas3Repn4BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwCogVehSpd_Val (0.0F)
# define Rte_InitValue_BmwCogVehSpdQlfr_Val (15U)
# define Rte_InitValue_BmwCogVehSpdQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwCogVehSpdVld_Logl (FALSE)
# define Rte_InitValue_BmwNearStillVehSpdSts_Val (15U)
# define Rte_InitValue_BmwNearStillVehSpdStsVld_Logl (FALSE)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH(P2VAR(sigGroup_V_VEH1, AUTOMATIC, RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot55Bas3Repn4BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl
# define Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH Rte_IsUpdated_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwCogVehSpd_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val
# define Rte_Write_BmwCogVehSpdQlfr_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val
# define Rte_Write_BmwCogVehSpdQlfrVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl
# define Rte_Write_BmwCogVehSpdVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl
# define Rte_Write_BmwNearStillVehSpdSts_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val
# define Rte_Write_BmwNearStillVehSpdStsVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot55Bas3Repn4BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwCogVehSpdPrev() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_BmwCogVehSpdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvFaildCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvPassdCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwCogVehSpdQlfrPrev() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_BmwCogVehSpdQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwNearStillVehSpdStsPrev() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_BmwNearStillVehSpdStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcFaildCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcPassdCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM1() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM2() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissMsgCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QlfrCogFaildCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_QlfrCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QlfrCogPassdCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_QlfrCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RxdMsgCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StVehNearStillFailCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_StVehNearStillFailCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StVehNearStillPassCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_StVehNearStillPassCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehCogFaildCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_VehCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehCogPassdCnt() (Rte_Inst_BmwMsgSlot55Bas3Repn4BusFrChA->Pim_VehCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwCogVehSpdPrev(void)
 *   uint8 *Rte_Pim_AlvFaildCnt(void)
 *   uint8 *Rte_Pim_AlvPassdCnt(void)
 *   BmwCogVehSpdQlfr1 *Rte_Pim_BmwCogVehSpdQlfrPrev(void)
 *   BmwNearStillVehSpdSts1 *Rte_Pim_BmwNearStillVehSpdStsPrev(void)
 *   uint8 *Rte_Pim_CrcFaildCnt(void)
 *   uint8 *Rte_Pim_CrcPassdCnt(void)
 *   QU_V_VEH_COG1 *Rte_Pim_Dummy_PIM1(void)
 *   ST_V_VEH_NSS1 *Rte_Pim_Dummy_PIM2(void)
 *   uint8 *Rte_Pim_MissMsgCnt(void)
 *   uint8 *Rte_Pim_QlfrCogFaildCnt(void)
 *   uint8 *Rte_Pim_QlfrCogPassdCnt(void)
 *   uint8 *Rte_Pim_RxdMsgCnt(void)
 *   uint8 *Rte_Pim_StVehNearStillFailCnt(void)
 *   uint8 *Rte_Pim_StVehNearStillPassCnt(void)
 *   uint8 *Rte_Pim_VehCogFaildCnt(void)
 *   uint8 *Rte_Pim_VehCogPassdCnt(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot55Bas3Repn4BusFrChA_START_SEC_CODE
# include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot55Bas3Repn4BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot55Bas3Repn4BusFrChAInit1 BmwMsgSlot55Bas3Repn4BusFrChAInit1
FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) BmwMsgSlot55Bas3Repn4BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: V_VEH_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_V_VEH> of PortPrototype <sigGroup_V_VEH>
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
 *   Std_ReturnType Rte_Write_BmwCogVehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data)
 *   Std_ReturnType Rte_Write_BmwNearStillVehSpdStsVld_Logl(boolean data)
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

# define RTE_RUNNABLE_V_VEH_Missing_Oper V_VEH_Missing_Oper
FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) V_VEH_Missing_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: V_VEH_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_V_VEH> of PortPrototype <sigGroup_V_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH(sigGroup_V_VEH1 *data)
 *   boolean Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwCogVehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwCogVehSpdVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data)
 *   Std_ReturnType Rte_Write_BmwNearStillVehSpdStsVld_Logl(boolean data)
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

# define RTE_RUNNABLE_V_VEH_Received_Oper V_VEH_Received_Oper
FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) V_VEH_Received_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot55Bas3Repn4BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H */
