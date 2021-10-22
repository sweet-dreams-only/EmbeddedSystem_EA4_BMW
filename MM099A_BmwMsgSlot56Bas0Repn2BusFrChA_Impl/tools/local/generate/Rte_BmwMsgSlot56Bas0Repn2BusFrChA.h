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
 *          File:  Rte_BmwMsgSlot56Bas0Repn2BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM099A_BmwMsgSlot56Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot56Bas0Repn2BusFrChA
 *  Generated at:  Wed Jun  6 15:31:36 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot56Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT56BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT56BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot56Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot56Bas0Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwVehYawQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehYawQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehYawRatePrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissingMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuVyawVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuVyawVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VyawVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VyawVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot56Bas0Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot56Bas0Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwVehYawQlfr_Val (15U)
# define Rte_InitValue_BmwVehYawQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwVehYawRate_Val (0.0F)
# define Rte_InitValue_BmwVehYawRateVld_Logl (FALSE)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot56Bas0Repn2BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot56Bas0Repn2BusFrChA_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(P2VAR(sigGroup_VYAW_VEH1, AUTOMATIC, RTE_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawRate_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawRateVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot56Bas0Repn2BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot56Bas0Repn2BusFrChA_FltCodEnad_Logl
# define Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH Rte_Read_BmwMsgSlot56Bas0Repn2BusFrChA_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwVehYawQlfr_Val Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawQlfr_Val
# define Rte_Write_BmwVehYawQlfrVld_Logl Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawQlfrVld_Logl
# define Rte_Write_BmwVehYawRate_Val Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawRate_Val
# define Rte_Write_BmwVehYawRateVld_Logl Rte_Write_BmwMsgSlot56Bas0Repn2BusFrChA_BmwVehYawRateVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot56Bas0Repn2BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwVehYawRatePrev() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_BmwVehYawRatePrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvFaildCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvPassdCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwVehYawQlfrPrev() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_BmwVehYawQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcFaildCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcPassdCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissingMsgCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_MissingMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuVyawVehFaildCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_QuVyawVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuVyawVehPassdCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_QuVyawVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RxdMsgCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VyawVehFaildCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_VyawVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VyawVehPassdCnt() (Rte_Inst_BmwMsgSlot56Bas0Repn2BusFrChA->Pim_VyawVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwVehYawRatePrev(void)
 *   uint8 *Rte_Pim_AlvFaildCnt(void)
 *   uint8 *Rte_Pim_AlvPassdCnt(void)
 *   BmwVehYawQlfr1 *Rte_Pim_BmwVehYawQlfrPrev(void)
 *   uint8 *Rte_Pim_CrcFaildCnt(void)
 *   uint8 *Rte_Pim_CrcPassdCnt(void)
 *   uint8 *Rte_Pim_MissingMsgCnt(void)
 *   uint8 *Rte_Pim_QuVyawVehFaildCnt(void)
 *   uint8 *Rte_Pim_QuVyawVehPassdCnt(void)
 *   uint8 *Rte_Pim_RxdMsgCnt(void)
 *   uint8 *Rte_Pim_VyawVehFaildCnt(void)
 *   uint8 *Rte_Pim_VyawVehPassdCnt(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot56Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot56Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot56Bas0Repn2BusFrChAInit1
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
 *   Std_ReturnType Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehYawQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehYawRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehYawRateVld_Logl(boolean data)
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

# define RTE_RUNNABLE_BmwMsgSlot56Bas0Repn2BusFrChAInit1 BmwMsgSlot56Bas0Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot56Bas0Repn2BusFrChA_CODE) BmwMsgSlot56Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VYAW_VEH_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_VYAW_VEH> of PortPrototype <sigGroup_VYAW_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehYawQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehYawRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehYawRateVld_Logl(boolean data)
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

# define RTE_RUNNABLE_VYAW_VEH_Missing_Oper VYAW_VEH_Missing_Oper
FUNC(void, BmwMsgSlot56Bas0Repn2BusFrChA_CODE) VYAW_VEH_Missing_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VYAW_VEH_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_VYAW_VEH> of PortPrototype <sigGroup_VYAW_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehYawQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehYawRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehYawRateVld_Logl(boolean data)
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

# define RTE_RUNNABLE_VYAW_VEH_Received_Oper VYAW_VEH_Received_Oper
FUNC(void, BmwMsgSlot56Bas0Repn2BusFrChA_CODE) VYAW_VEH_Received_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot56Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot56Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT56BAS0REPN2BUSFRCHA_H */
