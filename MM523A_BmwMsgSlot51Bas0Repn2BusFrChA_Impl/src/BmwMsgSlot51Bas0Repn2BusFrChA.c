/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot51Bas0Repn2BusFrChA.c
 *        Config:  C:/_Synergy_Projects/Working/MM523A_BmwMsgSlot51Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot51Bas0Repn2BusFrChA
 *  Generated at:  Tue Mar 27 17:52:25 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot51Bas0Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /*****************************************************************************
* Copyright 2017, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: BmwMsgSlot51Bas0Repn2BusFrChA.c
* Module Description: Implementation of BMW Message Slot 51 Base 0 Repetition 2 Bus FlexRay Channel A MM523A
* Project           : CBD  
* Author            : Brendon Binder
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz3734 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 10/27/17  1        BRB       Initial Implementation                                                          EA4#16221
* 01/29/18  2        BRB       Changed the flag for AVL_PO_EPS per anomaly EA4#19578                           EA4#19856
* 03/27/18  3        PHJ       Removed the validity flag for AVL_PO_EPS per anomaly EA4#21809                  EA4#22122
******************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * BmwPinionAgQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwSeldPosnUnit1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwTqSnsrIdx1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot51Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"

#include "E2EPW_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS_tx.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of:
                                              [Rte_Read, Rte_Read, E2EPW_Write]*/

#define PINIONAGSIGMAX_DEG_F32      (1439.9560546875F)
#define PINIONAGSIGMIN_DEG_F32      (-1439.9560546875F)
#define PINIONAGSIGOFFS_DEG_F32     (-1439.9560546875F)
#define PINIONAGSIGRESL_DEG_F32     (0.0439453125F)
#define RACKOFFSSIGMAX_DEG_F32      (89.9560546875F)
#define RACKOFFSSIGMIN_DEG_F32      (-89.9560546875F)
#define RACKOFFSSIGOFFS_DEG_F32     (-89.9560546875F)
#define RACKOFFSSIGRESL_DEG_F32     (0.0439453125F)
#define TARTQSIGMAX_HWNWTMTR_F32    (10.0F)
#define TARTQSIGMIN_HWNWTMTR_F32    (-10.0F)
#define TARTQSIGOFFS_HWNWTMTR_F32   (-10.0F)
#define TARTQSIGRESL_HWNWTMTR_F32   (0.01F)

#define PINIONINVLD_ULS_U16         ((uint16)65535U)
#define RACKCENTERINVLD_ULS_U16     ((uint16)4095U)
#define TRGGINVLD_ULS_U16           ((uint16)4095U)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * AVL_PO_EPS1: Integer in interval [0...65535]
 * AVL_PO_IDX_EPS1: Integer in interval [0...65535]
 * CRC_AVL_PO_EPS1: Integer in interval [0...255]
 * OFFS_GRD_MID_EPS1: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   PinionAgQlfrSigValVldAndPlaus (1U)
 *   PinionAgQlfrSigValVld (2U)
 *   PinionAgQlfrSubValSetInUsrSig (4U)
 *   PinionAgQlfrInit (8U)
 *   PinionAgQlfrSigValVldAndTmpOfAvrgQly (9U)
 *   PinionAgQlfrSigValVldAndTmpOfLoQly (10U)
 *   PinionAgQlfrAdjmtValSetInUsrSig (12U)
 *   PinionAgQlfrSigValInvldButStTmp (14U)
 *   PinionAgQlfrInvldSig (15U)
 * BmwSeldPosnUnit1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWSELDPOSNUNIT_PINIONIF (0U)
 *   BMWSELDPOSNUNIT_TOOTHEDRACKSTROKEIF (1U)
 *   BMWSELDPOSNUNIT_INVLDSIG (3U)
 * BmwTqSnsrIdx1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTQSNSRIDX_INIT (0U)
 *   BMWTQSNSRIDX_NOIDXEDGE (1U)
 *   BMWTQSNSRIDX_IDXEDGE (2U)
 *   BMWTQSNSRIDX_INVLDSIG (3U)
 * IDX_TORQ_SEN1: Enumeration of integer in interval [0...255] with enumerators
 *   IDX_TORQ_SEN_Initialisierung (0U)
 *   IDX_TORQ_SEN_KeineIndexFlanke (1U)
 *   IDX_TORQ_SEN_IndexFlanke (2U)
 *   IDX_TORQ_SEN_SignalUngueltig (3U)
 * QU_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_AVL_PINA_EPS_Initialisierung (8U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert (1U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltig (2U)
 *   QU_AVL_PINA_EPS_ErsatzwertIstImNutzsignalGesetzt (4U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_mittlereSignalqualitaet_ (9U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_geringeSignalqualitaet_ (10U)
 *   QU_AVL_PINA_EPS_AbgleichwertIstImNutzsignalGesetztZustandSlashStatusTemporaer (12U)
 *   QU_AVL_PINA_EPS_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
 *   QU_AVL_PINA_EPS_SignalUngueltig (15U)
 * UN_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   UN_PO_EPS_Ritzelschnittstelle (0U)
 *   UN_PO_EPS_Zahnstangenhubschnittstelle (1U)
 *   UN_PO_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_AVL_PO_EPS1: Record with elements
 *   AVL_PO_EPS of type AVL_PO_EPS1
 *   IDX_TORQ_SEN of type IDX_TORQ_SEN1
 *   OFFS_GRD_MID_EPS of type OFFS_GRD_MID_EPS1
 *   AVL_PO_IDX_EPS of type AVL_PO_IDX_EPS1
 *   CRC_AVL_PO_EPS of type CRC_AVL_PO_EPS1
 *   QU_AVL_PO_EPS of type QU_AVL_PO_EPS1
 *   ALIV_AVL_PO_EPS of type ALIV_AVL_PO_EPS1
 *   UN_PO_EPS of type UN_PO_EPS1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot51Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwPinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdx_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdxVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwSeldPosnUnit_Val(BmwSeldPosnUnit1 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTqSnsrIdx_Val(BmwTqSnsrIdx1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TRGG_ENGTORQ_EPS_Val(uint16 data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(const sigGroup_AVL_PO_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum;
    VAR(float32, AUTOMATIC) BmwPinionAg_Deg_T_f32;
    VAR(float32, AUTOMATIC) BmwPinionAgIdx_Deg_T_f32;
    VAR(boolean, AUTOMATIC) BmwPinionAgIdxVld_Cnt_T_logl;
    VAR(float32, AUTOMATIC) BmwRackCntrToVehCntrOffs_Deg_T_f32;
    VAR(boolean, AUTOMATIC) BmwRackCntrToVehCntrOffsVld_Cnt_T_logl;
    VAR(BmwTqSnsrIdx1, AUTOMATIC) BmwTqSnsrIdx_Cnt_T_enum;
    VAR(BmwSeldPosnUnit1, AUTOMATIC) BmwSeldPosnUnit_Cnt_T_enum;
    VAR(float32, AUTOMATIC) BmwTarMotTq_NwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) BmwTarMotTqVld_Cnt_T_logl;

    /* Outputs */
    VAR(uint16, AUTOMATIC) TrggEngtorqEps_Uls_T_u16;
    VAR(sigGroup_AVL_PO_EPS1, AUTOMATIC) sigGroupAVLPOEPS_T_rec;
    
    /* Temporary Variables */
    VAR(float32, AUTOMATIC) AvlPoePst_Deg_T_f32;
    VAR(float32, AUTOMATIC) AvlPoIdxEps_Deg_T_f32;
    VAR(float32, AUTOMATIC) OffsGrdMidEps_Deg_T_f32;
    VAR(float32, AUTOMATIC) TrggEngtorqEps_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) AvlPoePstTmp_Deg_T_f32;
    VAR(float32, AUTOMATIC) AvlPoIdxEpsTmp_Deg_T_f32;
    VAR(float32, AUTOMATIC) OffsGrdMidEpsTmp_Deg_T_f32;
    VAR(float32, AUTOMATIC) TrggEngtorqEpsTmp_HwNwtMtr_T_f32;
    
    /* Read Inputs */
    (void)Rte_Read_BmwPinionAg_Val(&BmwPinionAg_Deg_T_f32);
    (void)Rte_Read_BmwPinionAgIdx_Val(&BmwPinionAgIdx_Deg_T_f32);
    (void)Rte_Read_BmwPinionAgIdxVld_Logl(&BmwPinionAgIdxVld_Cnt_T_logl);
    (void)Rte_Read_BmwPinionAgQlfr_Val(&BmwPinionAgQlfr_Cnt_T_enum);
    (void)Rte_Read_BmwRackCntrToVehCntrOffs_Val(&BmwRackCntrToVehCntrOffs_Deg_T_f32);
    (void)Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(&BmwRackCntrToVehCntrOffsVld_Cnt_T_logl);
    (void)Rte_Read_BmwSeldPosnUnit_Val(&BmwSeldPosnUnit_Cnt_T_enum);
    (void)Rte_Read_BmwTarMotTq_Val(&BmwTarMotTq_NwtMtr_T_f32);
    (void)Rte_Read_BmwTarMotTqVld_Logl(&BmwTarMotTqVld_Cnt_T_logl);
    (void)Rte_Read_BmwTqSnsrIdx_Val(&BmwTqSnsrIdx_Cnt_T_enum);
    
    /*** Start of SigGroup Processing ***/
    
    /* QU_AVL_PO_EPS */
    sigGroupAVLPOEPS_T_rec.QU_AVL_PO_EPS = (QU_AVL_PO_EPS1)BmwPinionAgQlfr_Cnt_T_enum;
    
    /* AVL_PO_EPS */
    AvlPoePst_Deg_T_f32 = Lim_f32((BmwPinionAg_Deg_T_f32 * (float32)Rte_Prm_BmwSteerPolarity_Val()), PINIONAGSIGMIN_DEG_F32, PINIONAGSIGMAX_DEG_F32);
    AvlPoePstTmp_Deg_T_f32 = (AvlPoePst_Deg_T_f32 - PINIONAGSIGOFFS_DEG_F32) / PINIONAGSIGRESL_DEG_F32;
    sigGroupAVLPOEPS_T_rec.AVL_PO_EPS = (uint16)AvlPoePstTmp_Deg_T_f32;
    
    /* AVL_PO_IDX_EPS */
    if (BmwPinionAgIdxVld_Cnt_T_logl == FALSE)
    {
        sigGroupAVLPOEPS_T_rec.AVL_PO_IDX_EPS = PINIONINVLD_ULS_U16;
    }
    else
    {
        AvlPoIdxEps_Deg_T_f32 = Lim_f32((BmwPinionAgIdx_Deg_T_f32 * (float32)Rte_Prm_BmwSteerPolarity_Val()), PINIONAGSIGMIN_DEG_F32, PINIONAGSIGMAX_DEG_F32);
        AvlPoIdxEpsTmp_Deg_T_f32 = (AvlPoIdxEps_Deg_T_f32 - PINIONAGSIGOFFS_DEG_F32) / PINIONAGSIGRESL_DEG_F32;
        sigGroupAVLPOEPS_T_rec.AVL_PO_IDX_EPS = (uint16)AvlPoIdxEpsTmp_Deg_T_f32;
    }
    
    /* OFFS_GRD_MID_EPS */
    if (BmwRackCntrToVehCntrOffsVld_Cnt_T_logl == FALSE)
    {
        sigGroupAVLPOEPS_T_rec.OFFS_GRD_MID_EPS = RACKCENTERINVLD_ULS_U16;
    }
    else
    {
        OffsGrdMidEps_Deg_T_f32 = Lim_f32((BmwRackCntrToVehCntrOffs_Deg_T_f32 * (float32)Rte_Prm_BmwSteerPolarity_Val()),
                                           RACKOFFSSIGMIN_DEG_F32, 
                                           RACKOFFSSIGMAX_DEG_F32);
        OffsGrdMidEpsTmp_Deg_T_f32 = (OffsGrdMidEps_Deg_T_f32 - RACKOFFSSIGOFFS_DEG_F32) / RACKOFFSSIGRESL_DEG_F32;
        sigGroupAVLPOEPS_T_rec.OFFS_GRD_MID_EPS = (uint16)OffsGrdMidEpsTmp_Deg_T_f32;
    }
    
    /* IDX_TORQ_SEN */
    sigGroupAVLPOEPS_T_rec.IDX_TORQ_SEN = (IDX_TORQ_SEN1)BmwTqSnsrIdx_Cnt_T_enum;
    
    /* UN_PO_EPS */
    sigGroupAVLPOEPS_T_rec.UN_PO_EPS = (UN_PO_EPS1)BmwSeldPosnUnit_Cnt_T_enum;
        
    /*** End of SigGroup Processing ***/
    
    /*** Start of TRGG_ENGTORQ_EPS Processing ***/
    
    if (BmwTarMotTqVld_Cnt_T_logl == FALSE)
    {
        TrggEngtorqEps_Uls_T_u16 = TRGGINVLD_ULS_U16;
    }
    else
    {
        TrggEngtorqEps_HwNwtMtr_T_f32 = Lim_f32((BmwTarMotTq_NwtMtr_T_f32 * (float32)Rte_Prm_BmwSteerPolarity_Val()), 
                                            TARTQSIGMIN_HWNWTMTR_F32, 
                                            TARTQSIGMAX_HWNWTMTR_F32);
        TrggEngtorqEpsTmp_HwNwtMtr_T_f32 = (TrggEngtorqEps_HwNwtMtr_T_f32 - TARTQSIGOFFS_HWNWTMTR_F32) / TARTQSIGRESL_HWNWTMTR_F32;
        TrggEngtorqEps_Uls_T_u16 = (uint16)TrggEngtorqEpsTmp_HwNwtMtr_T_f32;
    }
    
    /*** End of TRGG_ENGTORQ_EPS Processing ***/
    
    /* Write Outputs */
    (void)Rte_Write_TRGG_ENGTORQ_EPS_Val(TrggEngtorqEps_Uls_T_u16);
    (void)E2EPW_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(&sigGroupAVLPOEPS_T_rec);
    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot51Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
