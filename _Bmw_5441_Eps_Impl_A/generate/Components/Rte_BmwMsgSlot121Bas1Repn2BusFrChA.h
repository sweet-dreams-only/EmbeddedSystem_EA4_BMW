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
 *          File:  Rte_BmwMsgSlot121Bas1Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot121Bas1Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwBasPtlNetCtrl1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdn1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwBasPtlNetCtrl_Val (15U)
#  define Rte_InitValue_BmwBasPtlNetCtrlVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehCdn_Val (15U)
#  define Rte_InitValue_BmwVehCdnQlfr_Val (15U)
#  define Rte_InitValue_BmwVehCdnQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehCdnVld_Logl (FALSE)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH(P2VAR(sigGroup_CON_VEH1, AUTOMATIC, RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH Rte_IsUpdated_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH
#  define Rte_IsUpdated_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwBasPtlNetCtrl_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val(data) (Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwBasPtlNetCtrlVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl(data) (Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehCdn_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val(data) (Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehCdnQlfr_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfr_Val
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfr_Val(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehCdnQlfrVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl(data) (Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehCdnVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl
#  define Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl(data) (Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwBasPtlNetCtrl1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdn1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdnQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrBsPrtntFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrBsPrtntPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrFktnPrtntFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrFktnPrtntPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(QU_ST_CON_VEH1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(QU_V_VEH_COG1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ST_CON_VEH1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(CTR_BS_PRTNT1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QlfrCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QlfrCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QuStConVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QuStConVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_StConVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_StConVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_AlvFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwBasPtlNetCtrlPrev() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwVehCdnPrev() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwVehCdnQlfrPrev() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrBsPrtntFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrBsPrtntFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrBsPrtntPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrBsPrtntPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrFktnPrtntFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrFktnPrtntFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrFktnPrtntPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_CtrFktnPrtntPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM1() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM2() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM3() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM3) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM4() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Dummy_PIM4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QlfrCogFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QlfrCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QlfrCogPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QlfrCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuStConVehFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QuStConVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuStConVehPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_QuStConVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RxdMsgCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StConVehFaildCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_StConVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StConVehPassdCnt() \
  (&Rte_BmwMsgSlot121Bas1Repn2BusFrChA_StConVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot121Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot121Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot121Bas1Repn2BusFrChAInit1 BmwMsgSlot121Bas1Repn2BusFrChAInit1
#  define RTE_RUNNABLE_CON_VEH_Missing_Oper CON_VEH_Missing_Oper
#  define RTE_RUNNABLE_CON_VEH_Received_Oper CON_VEH_Received_Oper
# endif

FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) BmwMsgSlot121Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) CON_VEH_Missing_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) CON_VEH_Received_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot121Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot121Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
