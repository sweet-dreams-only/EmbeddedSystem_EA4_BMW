/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot234Bas1Repn2BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM526A_BmwMsgSlot234Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot234Bas1Repn2BusFrChA
 *  Generated at:  Fri Apr 27 09:35:10 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot234Bas1Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: BmwMsgSlot234Bas1Repn2BusFrChA.c
* Module Description: Implementation of BMW Message Slot 234 Base 1 Repetition 2 Bus FlexRay Channel A MM526A
* Project           : CBD  
* Author            : Brendon Binder
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz3734 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/11/18  1        BRB       Initial Implementation                                                          EA4#22531
* 04/26/18  2        PHJ       Updated Initial Values in Developer                                             EA4#22531
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
 * BmwEpsFctSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "E2EPW_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST_tx.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */

#define CYCCNTRTHD_CNT_T_U08      ((uint8)5U)
#define PERDTHD_CNT_T_U08       ((uint8)50U)
#define BURSTMODTHD_CNT_T_U08   ((uint8)3U)

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
 * CRC_ST_EST_FTAX1: Integer in interval [0...255]
 * ST_EST_dummy_16_231: Integer in interval [0...255]
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_ST_EST_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwEpsFctSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWEPSFCTSTS_FCTINFALLBACK (49U)
 *   BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV (51U)
 *   BMWEPSFCTSTS_NOTAVIERR (96U)
 *   BMWEPSFCTSTS_ININ (128U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEPS (160U)
 *   BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV (162U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEAS (164U)
 *   BMWEPSFCTSTS_FCTAVIACTV24VEAS (168U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACK (176U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT (178U)
 *   BMWEPSFCTSTS_NOTAVISWDOFF (224U)
 *   BMWEPSFCTSTS_INVLD (255U)
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 *   HAPTCFBST_FCTAVLNOTACTV (1U)
 *   HAPTCFBST_ERR (6U)
 *   HAPTCFBST_FCTAVLACTV (9U)
 *   HAPTCFBST_FCTNOTAVL (14U)
 *   HAPTCFBST_INVLDSIG (15U)
 * QU_FN_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_FN_EST_Initialisierung (128U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv12VEPS (160U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv12VEAS (164U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv24VEAS (168U)
 *   QU_FN_EST_FunktionVerfuegbar_AktivNotfallfunktionUmwelteinfluesse_Aktiv (162U)
 *   QU_FN_EST_FunktionInRueckfallebene (49U)
 *   QU_FN_EST_FunktionInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (51U)
 *   QU_FN_EST_FunktionTemporaerInRueckfallebene (176U)
 *   QU_FN_EST_FunktionTemporaerInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (178U)
 *   QU_FN_EST_FunktionNichtVerfuegbar_Fehler (96U)
 *   QU_FN_EST_FunktionNichtVerfuegbar_Ausgeschaltet (224U)
 *   QU_FN_EST_SignalUngueltig (255U)
 * QU_FN_VIB_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_FN_VIB_EPS_Funktion_verfuegbar_nicht_aktiv (1U)
 *   QU_FN_VIB_EPS_Funktion_verfuegbar_aktiv (9U)
 *   QU_FN_VIB_EPS_Funktion_nicht_verfuegbar (14U)
 *   QU_FN_VIB_EPS_Fehler (6U)
 *   QU_FN_VIB_EPS_Signal_unbefuellt (15U)
 * QU_SER_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleWirdInitialisiert (128U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitOhneZusatzdaempfung (32U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitMitZusatzdaempfung (34U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungNichtVerfuegbar (33U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungVerfuegbar (35U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Fehler (96U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_PMA (224U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_EPSStatus (225U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SignalUngueltig (255U)
 *
 * Record Types:
 * =============
 * sigGroup_ST_EST1: Record with elements
 *   QU_SER_STMOM_DV_ACT of type QU_SER_STMOM_DV_ACT1
 *   QU_FN_VIB_EPS of type QU_FN_VIB_EPS1
 *   ST_EST_dummy_16_23 of type ST_EST_dummy_16_231
 *   ALIV_ST_EST_FTAX of type ALIV_ST_EST_FTAX1
 *   CRC_ST_EST_FTAX of type CRC_ST_EST_FTAX1
 *   QU_FN_EST of type QU_FN_EST1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwEpsFctSts1 *Rte_Pim_BmwEpsFctStsPrev(void)
 *   uint8 *Rte_Pim_BurstModCntr(void)
 *   uint8 *Rte_Pim_CycCntr(void)
 *   DrvgDynIfSt1 *Rte_Pim_DrvgDynIfStPrev(void)
 *   HaptcFbSt1 *Rte_Pim_HaptcFbStPrev(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot234Bas1Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAInit1
 *********************************************************************************************************************/

	/* Initialize previous values to nominal */
    *Rte_Pim_BmwEpsFctStsPrev() = BMWEPSFCTSTS_ININ;
    *Rte_Pim_DrvgDynIfStPrev() = DRVGDYNIFST_IFINID;
    *Rte_Pim_HaptcFbStPrev() = HAPTCFBST_FCTNOTAVL;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BmwEpsFctSts_Val(BmwEpsFctSts1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HaptcFbSt_Val(HaptcFbSt1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(const sigGroup_ST_EST1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAPer1
 *********************************************************************************************************************/
 
	/* Inputs */
    VAR(BmwEpsFctSts1, AUTOMATIC) BmwEpsFctSts_Cnt_T_enum;
    VAR(DrvgDynIfSt1, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum;
    VAR(HaptcFbSt1, AUTOMATIC) HaptcFbSt_Cnt_T_enum;
    
    /* Output */
    VAR(sigGroup_ST_EST1, AUTOMATIC) SigGroupStEst_Cnt_T_rec;
    
    /* Read Inputs */
    (void)Rte_Read_BmwEpsFctSts_Val(&BmwEpsFctSts_Cnt_T_enum);
    (void)Rte_Read_DrvgDynIfSt_Val(&DrvgDynIfSt_Cnt_T_enum);
    (void)Rte_Read_HaptcFbSt_Val(&HaptcFbSt_Cnt_T_enum);
    
    /* Check for updated inputs, update PIMs if applicable */
    if ((*Rte_Pim_BmwEpsFctStsPrev() != BmwEpsFctSts_Cnt_T_enum) ||
        (*Rte_Pim_DrvgDynIfStPrev() != DrvgDynIfSt_Cnt_T_enum) ||
        (*Rte_Pim_HaptcFbStPrev() != HaptcFbSt_Cnt_T_enum))
    {
        *Rte_Pim_BmwEpsFctStsPrev() = BmwEpsFctSts_Cnt_T_enum;
        *Rte_Pim_DrvgDynIfStPrev() = DrvgDynIfSt_Cnt_T_enum; 
        *Rte_Pim_HaptcFbStPrev() = HaptcFbSt_Cnt_T_enum;
        
        *Rte_Pim_BurstModCntr() = 0U;
        *Rte_Pim_CycCntr() = CYCCNTRTHD_CNT_T_U08;
    }
    
    /* Initialize variables */
    SigGroupStEst_Cnt_T_rec.QU_FN_VIB_EPS = *Rte_Pim_HaptcFbStPrev();
    SigGroupStEst_Cnt_T_rec.QU_SER_STMOM_DV_ACT = *Rte_Pim_DrvgDynIfStPrev();
    SigGroupStEst_Cnt_T_rec.QU_FN_EST = *Rte_Pim_BmwEpsFctStsPrev();
            
    /* Burst mode processing */
    if ((*Rte_Pim_CycCntr() >= CYCCNTRTHD_CNT_T_U08) && (*Rte_Pim_BurstModCntr() < BURSTMODTHD_CNT_T_U08))
    {        
        /* Write outputs */
        (void)E2EPW_Write_sigGroup_ST_EST_sigGroup_ST_EST(&SigGroupStEst_Cnt_T_rec);
    
        /* Increment burst mode counter */
        *Rte_Pim_BurstModCntr() = *Rte_Pim_BurstModCntr() + 1U;
                      
        /* Reset CycCntr */
        *Rte_Pim_CycCntr() = 1U;
        
        /* There is a possibility data will be written at the same time the main periodic counter reaches 500ms. If this happens,
        the periodic counter will not trigger a data write but will still increment. This check will reset the
        periodic counter in that event */
        if (*Rte_Pim_PerdCntr() >= PERDTHD_CNT_T_U08)
        {
            *Rte_Pim_PerdCntr() = 1U;
        }
        else
        {
            *Rte_Pim_PerdCntr() = *Rte_Pim_PerdCntr() + 1U;
        }
    }
    else if ((*Rte_Pim_PerdCntr() >= PERDTHD_CNT_T_U08) && (*Rte_Pim_CycCntr() >= CYCCNTRTHD_CNT_T_U08))
    {                    
        (void)E2EPW_Write_sigGroup_ST_EST_sigGroup_ST_EST(&SigGroupStEst_Cnt_T_rec);
        
        /* Reset PerdCntr */
        *Rte_Pim_CycCntr() = 1U;
        *Rte_Pim_PerdCntr() = 1U;
    }    
    else
    {
        /* Increment CycCntr and PerdCntr */
        *Rte_Pim_CycCntr() = *Rte_Pim_CycCntr() + 1U;
        *Rte_Pim_PerdCntr() = *Rte_Pim_PerdCntr() + 1U;
    }
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot234Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
