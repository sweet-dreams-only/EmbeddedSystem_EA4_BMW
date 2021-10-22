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
 *          File:  Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM101A_BmwMsgSlot68Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot68Bas0Repn2BusFrChA
 *  Generated at:  Fri Jun  8 11:32:27 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot68Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot68Bas0Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynDampgFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynDampgFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynEffortFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynEffortFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynEnaReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynErrIfActvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwOvrlCmdQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynFacQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynFacQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynRtnFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDrvgDynRtnFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwEpsDeactvnCtrl1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwEpsDeactvnCtrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwEpsDeactvnCtrlVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarHwTqOvrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwOvrlCmdQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarHwTqOvrlQlfPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarHwTqOvrlQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarHwTqOvrlVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarSteerTqDrvrActrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwOvrlCmdQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarSteerTqDrvrActrQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarSteerTqDrvrActrQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTarSteerTqDrvrActrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTrfcJamAssiDampgScaReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTrfcJamAssiDampgScaReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwTrfcJamAssiDampgStReq1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTrfcJamAssiDampgStReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwTrfcJamAssiDampgStReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrDeacEpsFnsFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrDeacEpsFnsPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactAssStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactAssStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactCtrrStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactCtrrStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactDmpngAddonStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactDmpngAddonStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactDmpngStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactDmpngStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarDmpngAddonStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarDmpngAddonStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarFactStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarFactStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarQtaStmomDvFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarQtaStmomDvPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarStmomDvActFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuTarStmomDvActPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStmomDvFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStmomDvPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvAliveCntFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvAliveCntPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvArcVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvCRCFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvCRCPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvMissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvMissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvMsgProcd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarQtaStrmomDvMsgVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActAliveCntFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActAliveCntPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActArcVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActCrcFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActCrcPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActMissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActMissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActMsgProcd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActMsgVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarStmomDvActPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot68Bas0Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot68Bas0Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwDrvgDynDampgFacReq_Val (1.0F)
# define Rte_InitValue_BmwDrvgDynEffortFacReq_Val (1.0F)
# define Rte_InitValue_BmwDrvgDynEnaRqst_Logl (FALSE)
# define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
# define Rte_InitValue_BmwDrvgDynFacQlfr_Val (15U)
# define Rte_InitValue_BmwDrvgDynFacQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwDrvgDynRtnFacReq_Val (1.0F)
# define Rte_InitValue_BmwEpsDeactvnCtrl_Val (15U)
# define Rte_InitValue_BmwTarHwTqOvrl_Val (0.0F)
# define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (15U)
# define Rte_InitValue_BmwTarHwTqOvrlQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwTarSteerTqDrvrActr_Val (0.0F)
# define Rte_InitValue_BmwTarSteerTqDrvrActrQlfr_Val (15U)
# define Rte_InitValue_BmwTarSteerTqDrvrActrQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwTrfcJamAssiDampgScaReq_Val (0.0F)
# define Rte_InitValue_BmwTrfcJamAssiDampgScaReqVld_Logl (FALSE)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReq_Val (1U)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReqVld_Logl (FALSE)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(P2VAR(sigGroup_TAR_QTA_STRMOM_DV1, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(P2VAR(sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot68Bas0Repn2BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(sint8, RTE_CODE) Rte_Prm_BmwMsgSlot68Bas0Repn2BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl
# define Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV
# define Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwDrvgDynDampgFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val
# define Rte_Write_BmwDrvgDynEffortFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val
# define Rte_Write_BmwDrvgDynEnaRqst_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl
# define Rte_Write_BmwDrvgDynErrIfActv_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl
# define Rte_Write_BmwDrvgDynFacQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val
# define Rte_Write_BmwDrvgDynFacQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl
# define Rte_Write_BmwDrvgDynRtnFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val
# define Rte_Write_BmwEpsDeactvnCtrl_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrl_Val
# define Rte_Write_BmwTarHwTqOvrl_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val
# define Rte_Write_BmwTarHwTqOvrlQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val
# define Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl
# define Rte_Write_BmwTarSteerTqDrvrActr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val
# define Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val
# define Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl
# define Rte_Write_BmwTrfcJamAssiDampgScaReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val
# define Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl
# define Rte_Write_BmwTrfcJamAssiDampgStReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val
# define Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot68Bas0Repn2BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val Rte_Prm_BmwMsgSlot68Bas0Repn2BusFrChA_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwDrvgDynDampgFacReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynDampgFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynEffortFacReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynEffortFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynRtnFacReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynRtnFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarHwTqOvrlPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarHwTqOvrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarSteerTqDrvrActrPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarSteerTqDrvrActrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTrfcJamAssiDampgScaReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynFacQlfrPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynFacQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwEpsDeactvnCtrlPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwEpsDeactvnCtrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarHwTqOvrlQlfPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarHwTqOvrlQlfPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarSteerTqDrvrActrQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTrfcJamAssiDampgStReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTrfcJamAssiDampgStReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrDeacEpsFnsFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_CtrDeacEpsFnsFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrDeacEpsFnsPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_CtrDeacEpsFnsPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactAssStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactAssStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactAssStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactAssStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactCtrrStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactCtrrStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactCtrrStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactCtrrStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactDmpngAddonStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactDmpngAddonStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactDmpngAddonStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactDmpngAddonStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactDmpngStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactDmpngStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactDmpngStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_FactDmpngStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarDmpngAddonStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarDmpngAddonStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarFactStmomFtaxFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarFactStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarFactStmomFtaxPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarFactStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarQtaStmomDvFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarQtaStmomDvFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarQtaStmomDvPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarQtaStmomDvPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarStmomDvActFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarStmomDvActFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuTarStmomDvActPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_QuTarStmomDvActPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStmomDvFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStmomDvFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStmomDvPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStmomDvPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvAliveCntFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvAliveCntFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvAliveCntPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvAliveCntPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvCRCFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvCRCFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvCRCPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvCRCPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvMissFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvMissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvMissPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvMissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActAliveCntFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActAliveCntFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActAliveCntPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActAliveCntPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActCrcFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActCrcFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActCrcPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActCrcPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActMissFaild() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActMissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActMissPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActMissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActPassd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynDampgFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynEffortFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynEnaReqPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynEnaReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynErrIfActvPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynErrIfActvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynFacQlfrVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynFacQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwDrvgDynRtnFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwEpsDeactvnCtrlVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwEpsDeactvnCtrlVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarHwTqOvrlQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarHwTqOvrlVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarHwTqOvrlVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarSteerTqDrvrActrQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTarSteerTqDrvrActrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTrfcJamAssiDampgScaReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_BmwTrfcJamAssiDampgStReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvArcVld() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvArcVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvMsgProcd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvMsgProcd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarQtaStrmomDvMsgVld() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarQtaStrmomDvMsgVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActArcVld() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActArcVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActMsgProcd() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActMsgProcd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarStmomDvActMsgVld() (Rte_Inst_BmwMsgSlot68Bas0Repn2BusFrChA->Pim_TarStmomDvActMsgVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwDrvgDynDampgFacReqPrev(void)
 *   float32 *Rte_Pim_BmwDrvgDynEffortFacReqPrev(void)
 *   float32 *Rte_Pim_BmwDrvgDynRtnFacReqPrev(void)
 *   float32 *Rte_Pim_BmwTarHwTqOvrlPrev(void)
 *   float32 *Rte_Pim_BmwTarSteerTqDrvrActrPrev(void)
 *   float32 *Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwDrvgDynFacQlfrPrev(void)
 *   BmwEpsDeactvnCtrl1 *Rte_Pim_BmwEpsDeactvnCtrlPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwTarHwTqOvrlQlfPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev(void)
 *   BmwTrfcJamAssiDampgStReq1 *Rte_Pim_BmwTrfcJamAssiDampgStReqPrev(void)
 *   uint8 *Rte_Pim_CtrDeacEpsFnsFaild(void)
 *   uint8 *Rte_Pim_CtrDeacEpsFnsPassd(void)
 *   uint8 *Rte_Pim_FactAssStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactAssStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactCtrrStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactCtrrStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactDmpngAddonStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactDmpngAddonStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactDmpngStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactDmpngStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarFactStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_QuTarFactStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarQtaStmomDvFaild(void)
 *   uint8 *Rte_Pim_QuTarQtaStmomDvPassd(void)
 *   uint8 *Rte_Pim_QuTarStmomDvActFaild(void)
 *   uint8 *Rte_Pim_QuTarStmomDvActPassd(void)
 *   uint8 *Rte_Pim_TarQtaStmomDvFaild(void)
 *   uint8 *Rte_Pim_TarQtaStmomDvPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvAliveCntFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvAliveCntPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvCRCFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvCRCPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvMissFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvMissPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActAliveCntFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActAliveCntPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActCrcFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActCrcPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActMissFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActMissPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActPassd(void)
 *   boolean *Rte_Pim_BmwDrvgDynDampgFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynEffortFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynEnaReqPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynErrIfActvPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynFacQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynRtnFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwEpsDeactvnCtrlVldPrev(void)
 *   boolean *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwTarHwTqOvrlVldPrev(void)
 *   boolean *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwTarSteerTqDrvrActrVldPrev(void)
 *   boolean *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev(void)
 *   boolean *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvArcVld(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvMsgProcd(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvMsgVld(void)
 *   boolean *Rte_Pim_TarStmomDvActArcVld(void)
 *   boolean *Rte_Pim_TarStmomDvActMsgProcd(void)
 *   boolean *Rte_Pim_TarStmomDvActMsgVld(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot68Bas0Repn2BusFrChAInit1
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

# define RTE_RUNNABLE_BmwMsgSlot68Bas0Repn2BusFrChAInit1 BmwMsgSlot68Bas0Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) BmwMsgSlot68Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_QTA_STRMOM_DV_Miss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_TAR_QTA_STRMOM_DV> of PortPrototype <sigGroup_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(sigGroup_TAR_QTA_STRMOM_DV1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynDampgFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEffortFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynRtnFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrl_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(boolean data)
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

# define RTE_RUNNABLE_TAR_QTA_STRMOM_DV_Miss TAR_QTA_STRMOM_DV_Miss
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Miss(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_QTA_STRMOM_DV_Rxd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_TAR_QTA_STRMOM_DV> of PortPrototype <sigGroup_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(sigGroup_TAR_QTA_STRMOM_DV1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynDampgFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEffortFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynRtnFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrl_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(boolean data)
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

# define RTE_RUNNABLE_TAR_QTA_STRMOM_DV_Rxd TAR_QTA_STRMOM_DV_Rxd
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Rxd(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_STMOM_DV_ACT_Miss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_TAR_STMOM_DV_ACT> of PortPrototype <sigGroup_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(sigGroup_TAR_STMOM_DV_ACT1 *data)
 *   boolean Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActr_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data)
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

# define RTE_RUNNABLE_TAR_STMOM_DV_ACT_Miss TAR_STMOM_DV_ACT_Miss
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Miss(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_STMOM_DV_ACT_Rxd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_TAR_STMOM_DV_ACT> of PortPrototype <sigGroup_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(sigGroup_TAR_STMOM_DV_ACT1 *data)
 *   boolean Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActr_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data)
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

# define RTE_RUNNABLE_TAR_STMOM_DV_ACT_Rxd TAR_STMOM_DV_ACT_Rxd
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Rxd(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H */
