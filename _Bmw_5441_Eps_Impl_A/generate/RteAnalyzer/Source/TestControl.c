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
 *          File:  TestControl.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Project specific file that implements a Test Suite Component Instance
 *********************************************************************************************************************/

/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */

#include "string.h"
#include "Std_Types.h"
#include "Rte_Cbk.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_0883 */
#include "Rte_Main.h"


void TSC_BswCallbacks()
{
    /**********************************************************************************************************************
     * COM Callbacks for Rx Indication
     *********************************************************************************************************************/
    Rte_COMCbk_ANFRAGE_ID2_fbd80461_In();
    Rte_COMCbk_AVL_STEA_PNI_OFFS_9678c0e9();
    Rte_COMCbk_CTR_WARN_DIR_VIB_EPS_66c73f8f();
    Rte_COMCbk_CTR_WARN_ILVL_VIB_EPS_66c73f8f();
    Rte_COMCbk_CTR_WARN_PTRN_VIB_EPS_66c73f8f();
    Rte_COMCbk_FACT_MO_STE_SO_DXP_59dc6376();
    Rte_COMCbk_MILE_KM_a6dd5496();
    Rte_COMCbk_ST_ENERG_FZM_e7ce1a0c();
    Rte_COMCbk_ST_ILK_ERRM_FZM_e7ce1a0c();
    Rte_COMCbk_SU_CLU_STMOM_SFE_DXP_59dc6376();
    Rte_COMCbk_T_SEC_COU_REL_0b27fbfe();
    Rte_COMCbk_sigGroup_ACLNY_MASSCNTR_461c64b1();
    Rte_COMCbk_sigGroup_CON_VEH_675e7344();
    Rte_COMCbk_sigGroup_ENERG_DGR_DRDY_3f76efd3();
    Rte_COMCbk_sigGroup_OFFS_QUAD_EPS_cc150a52();
    Rte_COMCbk_sigGroup_TAR_QTA_STRMOM_DV_231dfb08();
    Rte_COMCbk_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3();
    Rte_COMCbk_sigGroup_VYAW_VEH_fc66be94();
    Rte_COMCbk_sigGroup_V_VEH_2fe00c20();

    /**********************************************************************************************************************
     * COM Callbacks for Rx Timeout Notification
     *********************************************************************************************************************/
    Rte_COMCbkRxTOut_AVL_STEA_PNI_OFFS_9678c0e9();
    Rte_COMCbkRxTOut_CTR_WARN_DIR_VIB_EPS_66c73f8f();
    Rte_COMCbkRxTOut_CTR_WARN_ILVL_VIB_EPS_66c73f8f();
    Rte_COMCbkRxTOut_CTR_WARN_PTRN_VIB_EPS_66c73f8f();
    Rte_COMCbkRxTOut_FACT_MO_STE_SO_DXP_59dc6376();
    Rte_COMCbkRxTOut_MILE_KM_a6dd5496();
    Rte_COMCbkRxTOut_ST_ENERG_FZM_e7ce1a0c();
    Rte_COMCbkRxTOut_ST_ILK_ERRM_FZM_e7ce1a0c();
    Rte_COMCbkRxTOut_SU_CLU_STMOM_SFE_DXP_59dc6376();
    Rte_COMCbkRxTOut_sigGroup_ACLNY_MASSCNTR_461c64b1();
    Rte_COMCbkRxTOut_sigGroup_CON_VEH_675e7344();
    Rte_COMCbkRxTOut_sigGroup_ENERG_DGR_DRDY_3f76efd3();
    Rte_COMCbkRxTOut_sigGroup_OFFS_QUAD_EPS_cc150a52();
    Rte_COMCbkRxTOut_sigGroup_TAR_QTA_STRMOM_DV_231dfb08();
    Rte_COMCbkRxTOut_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3();
    Rte_COMCbkRxTOut_sigGroup_VYAW_VEH_fc66be94();
    Rte_COMCbkRxTOut_sigGroup_V_VEH_2fe00c20();

} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0883:  MISRA rule: 19.15
     Reason:     AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                 select appropriate #pragma directives.
     Risk:       MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                 the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
