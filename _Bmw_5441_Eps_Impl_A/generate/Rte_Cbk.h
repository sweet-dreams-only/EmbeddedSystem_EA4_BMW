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
 *          File:  Rte_Cbk.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBK_H
# define _RTE_CBK_H

# include "Com.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_ANFRAGE_ID2_fbd80461_In(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_AVL_STEA_PNI_OFFS_9678c0e9(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_DIR_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_ILVL_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_PTRN_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_FACT_MO_STE_SO_DXP_59dc6376(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_MILE_KM_a6dd5496(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_ST_ENERG_FZM_e7ce1a0c(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_ST_ILK_ERRM_FZM_e7ce1a0c(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_SU_CLU_STMOM_SFE_DXP_59dc6376(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_T_SEC_COU_REL_0b27fbfe(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_ACLNY_MASSCNTR_461c64b1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_CON_VEH_675e7344(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_ENERG_DGR_DRDY_3f76efd3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_OFFS_QUAD_EPS_cc150a52(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_TAR_QTA_STRMOM_DV_231dfb08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_VYAW_VEH_fc66be94(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_V_VEH_2fe00c20(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AVL_STEA_PNI_OFFS_9678c0e9(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_DIR_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_ILVL_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_PTRN_VIB_EPS_66c73f8f(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_FACT_MO_STE_SO_DXP_59dc6376(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_MILE_KM_a6dd5496(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ST_ENERG_FZM_e7ce1a0c(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ST_ILK_ERRM_FZM_e7ce1a0c(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SU_CLU_STMOM_SFE_DXP_59dc6376(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_ACLNY_MASSCNTR_461c64b1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_CON_VEH_675e7344(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_ENERG_DGR_DRDY_3f76efd3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_OFFS_QUAD_EPS_cc150a52(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_TAR_QTA_STRMOM_DV_231dfb08(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_VYAW_VEH_fc66be94(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_V_VEH_2fe00c20(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_CBK_H */
