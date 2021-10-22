/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot274Bas2Repn4BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM529A_BmwMsgSlot274Bas2Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas2Repn4BusFrChA
 *  Generated at:  Thu Apr 26 18:59:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot274Bas2Repn4BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /*****************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name: BmwMsgSlot274Bas2Repn4BusFrChA.c
* Module Description: Implementation of BMW Message Slot 274 Base 2 Repetition 4 Bus FlexRay Channel A MM523A
* Project           : CBD  
* Author            : Brendon Binder
*****************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       nzlf92 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 11/02/17  1        BRB       Initial Implementation                                                          EA4#16222
* 11/21/17  2        BRB       Updated PIM name to comply with naming conventions; removed unnecessary         EA4#16222
*                              typecasts                    
* 11/22/17  3        BRB       Updated enum entry names to match CF070A                                        EA4#16222
* 11/22/17  4        PHJ       Updated in[ut port and enum values to match CF070A                              EA4#23055
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
 * BmwFltLampFlsgFrq1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwFltLampReqSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwFltLampReqTyp2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot274Bas2Repn4BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "E2EPW_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS_tx.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */

#define LSTTXTHD_ULS_U08        		((uint8)5U)
#define PERDTHD_ULS_U08         		((uint8)31U)
#define CHLDISPCCEPS_ULS_U08    		((uint8)12U)
#define NOCCEPSNOLAMP_ULS_U16			((uint16)65534U)
#define NOCCEPSINSPNRLVLAMP_ULS_U16		((uint16)627U)
#define NOCCEPSNORMWARNLAMP_ULS_U16		((uint16)627U)
#define NOCCEPSTHERMWARNLAMP_ULS_U16	((uint16)997U)

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
 * ALIV_DISP_CC_EPS1: Integer in interval [0...255]
 * CHL_DISP_CC_EPS1: Integer in interval [0...255]
 * CRC_DISP_CC_EPS1: Integer in interval [0...255]
 * NO_CC_EPS1: Integer in interval [0...65535]
 * TRANF_CC_EPS1: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwFltLampFlsgFrq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPFLSGFRQ_NOFLSG (0U)
 *   BMWFLTLAMPFLSGFRQ_SLOWFLSG (1U)
 *   BMWFLTLAMPFLSGFRQ_FASTFLSG (2U)
 *   BMWFLTLAMPFLSGFRQ_INVLD (3U)
 * BmwFltLampReqSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPREQSTS_FLTLAMPRSTREQD (0U)
 *   BMWFLTLAMPREQSTS_FLTLAMPSETREQD (1U)
 *   BMWFLTLAMPREQSTS_INVLD (3U)
 * BmwFltLampReqTyp2: Enumeration of integer in interval [0...65535] with enumerators
 *   BMWFLTLAMPREQTYP_NOLAMP (0U)
 *   BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP (1U)
 *   BMWFLTLAMPREQTYP_NORMWARNLAMP (2U)
 *   BMWFLTLAMPREQTYP_THERMWARNLAMP (3U)
 * ST_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ST_CC_EPS_Ruecksetzen (0U)
 *   ST_CC_EPS_Setzen (1U)
 *   ST_CC_EPS_SignalUngueltig (3U)
 * ST_IDC_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ST_IDC_CC_EPS_KeinBlinken (0U)
 *   ST_IDC_CC_EPS_LangsamesBlinken (1U)
 *   ST_IDC_CC_EPS_SchnellesBlinken (2U)
 *   ST_IDC_CC_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_DISP_CC_EPS1: Record with elements
 *   ST_CC_EPS of type ST_CC_EPS1
 *   ALIV_DISP_CC_EPS of type ALIV_DISP_CC_EPS1
 *   ST_IDC_CC_EPS of type ST_IDC_CC_EPS1
 *   CRC_DISP_CC_EPS of type CRC_DISP_CC_EPS1
 *   CHL_DISP_CC_EPS of type CHL_DISP_CC_EPS1
 *   NO_CC_EPS of type NO_CC_EPS1
 *   TRANF_CC_EPS of type TRANF_CC_EPS1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwFltLampReqTyp2 *Rte_Pim_BmwFltLampReqTypPrev(void)
 *   BmwFltLampFlsgFrq1 *Rte_Pim_BmwFltLampFlsgFrqPrev(void)
 *   BmwFltLampReqSts1 *Rte_Pim_BmwFltLampReqStsPrev(void)
 *   uint8 *Rte_Pim_BmwFltLampReqTxTypPrev(void)
 *   uint8 *Rte_Pim_LstTxCntr(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot274Bas2Repn4BusFrChA_START_SEC_CODE
#include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAInit1
 *********************************************************************************************************************/

    /* Do Nothing */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BmwFltLampFlsgFrq_Val(BmwFltLampFlsgFrq1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqSts_Val(BmwFltLampReqSts1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTxTyp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(const sigGroup_DISP_CC_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas2Repn4BusFrChAPer1
 *********************************************************************************************************************/
    
    /* Inputs */
    VAR(BmwFltLampFlsgFrq1, AUTOMATIC) BmwFltLampFlsgFrq_Cnt_T_enum;
    VAR(BmwFltLampReqSts1, AUTOMATIC) BmwFltLampReqSts_Cnt_T_enum;
    VAR(uint8, AUTOMATIC) BmwFltLampReqTxTyp_Sec_T_u08;
    VAR(BmwFltLampReqTyp2, AUTOMATIC) BmwFltLampReqTyp_Cnt_T_enum;
    
    /* Output */
    VAR(sigGroup_DISP_CC_EPS1, AUTOMATIC) SigGroupDispCCEps_Cnt_T_rec;
        
    /* Read Inputs */
    (void)Rte_Read_BmwFltLampFlsgFrq_Val(&BmwFltLampFlsgFrq_Cnt_T_enum);
    (void)Rte_Read_BmwFltLampReqSts_Val(&BmwFltLampReqSts_Cnt_T_enum);
    (void)Rte_Read_BmwFltLampReqTxTyp_Val(&BmwFltLampReqTxTyp_Sec_T_u08);
    (void)Rte_Read_BmwFltLampReqTyp_Val(&BmwFltLampReqTyp_Cnt_T_enum);
        
    /*** Start of SigGroup Processing ***/
    
    if (((*Rte_Pim_LstTxCntr() >= LSTTXTHD_ULS_U08) &&
        ((*Rte_Pim_BmwFltLampFlsgFrqPrev() != BmwFltLampFlsgFrq_Cnt_T_enum) ||
         (*Rte_Pim_BmwFltLampReqStsPrev() != BmwFltLampReqSts_Cnt_T_enum) ||
         (*Rte_Pim_BmwFltLampReqTxTypPrev() != BmwFltLampReqTxTyp_Sec_T_u08) ||
         (*Rte_Pim_BmwFltLampReqTypPrev() != BmwFltLampReqTyp_Cnt_T_enum) ||
         (*Rte_Pim_PerdCntr() == PERDTHD_ULS_U08))))
    {
        /* If there is a new input and the previous transmission was more than a debounce step,
           or if the periodic counter has reached its threshold, process the message */
                
        /* CHL_DISP_CC_EPS */
        SigGroupDispCCEps_Cnt_T_rec.CHL_DISP_CC_EPS = CHLDISPCCEPS_ULS_U08;
        
        /* NO_CC_EPS */
		if (BmwFltLampReqTyp_Cnt_T_enum == BMWFLTLAMPREQTYP_NOLAMP)
		{
			SigGroupDispCCEps_Cnt_T_rec.NO_CC_EPS = NOCCEPSNOLAMP_ULS_U16;
		}
        else if (BmwFltLampReqTyp_Cnt_T_enum == BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP)
		{
			SigGroupDispCCEps_Cnt_T_rec.NO_CC_EPS = NOCCEPSINSPNRLVLAMP_ULS_U16;
		}
		else if (BmwFltLampReqTyp_Cnt_T_enum == BMWFLTLAMPREQTYP_NORMWARNLAMP)
		{
			SigGroupDispCCEps_Cnt_T_rec.NO_CC_EPS = NOCCEPSNORMWARNLAMP_ULS_U16;
		}
		else if (BmwFltLampReqTyp_Cnt_T_enum == BMWFLTLAMPREQTYP_THERMWARNLAMP)
		{
			SigGroupDispCCEps_Cnt_T_rec.NO_CC_EPS = NOCCEPSTHERMWARNLAMP_ULS_U16;
		}
		else
		{
			/* Do Nothing */
		}
        /* ST_CC_EPS */
        SigGroupDispCCEps_Cnt_T_rec.ST_CC_EPS = (ST_CC_EPS1)BmwFltLampReqSts_Cnt_T_enum;
        
        /* TRANF_CC_EPS */
        SigGroupDispCCEps_Cnt_T_rec.TRANF_CC_EPS = BmwFltLampReqTxTyp_Sec_T_u08;
        
        /* ST_IDC_CC_EPS */
        SigGroupDispCCEps_Cnt_T_rec.ST_IDC_CC_EPS = (ST_IDC_CC_EPS1)BmwFltLampFlsgFrq_Cnt_T_enum;
        
        /* Reset transmission counter */
        *Rte_Pim_LstTxCntr() = 0U;
        
        /* Reset the periodic counter if not event based, or if the next periodic tick is less than a debounce step away.
           Otherwise, increment the counter. */
        if (*Rte_Pim_PerdCntr() >= PERDTHD_ULS_U08)
        {
            *Rte_Pim_PerdCntr() = 0U;
        }
        else
        {
            *Rte_Pim_PerdCntr() = *Rte_Pim_PerdCntr() + 1U;
        }
        
        *Rte_Pim_BmwFltLampFlsgFrqPrev() = BmwFltLampFlsgFrq_Cnt_T_enum;
        *Rte_Pim_BmwFltLampReqStsPrev() = BmwFltLampReqSts_Cnt_T_enum;
        *Rte_Pim_BmwFltLampReqTxTypPrev() = BmwFltLampReqTxTyp_Sec_T_u08;
        *Rte_Pim_BmwFltLampReqTypPrev() = BmwFltLampReqTyp_Cnt_T_enum;         
        
        /* Write Output */
        (void)E2EPW_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(&SigGroupDispCCEps_Cnt_T_rec);
    }
    else
    {
        /* There is a possibility data will be written within 60ms of the main periodic counter. If this happens,
           the periodic counter will not trigger a data write but will still increment. This check will reset the
           periodic counter in that event */
        if (*Rte_Pim_PerdCntr() >= PERDTHD_ULS_U08)
        {
            *Rte_Pim_PerdCntr() = 0U;
        }
        else
        {
            *Rte_Pim_PerdCntr() = *Rte_Pim_PerdCntr() + 1U;
        }
        
        /* Otherwise, increment the counter */
        *Rte_Pim_LstTxCntr() = *Rte_Pim_LstTxCntr() + 1U;
    }
    
    /*** End of SigGroup Processing ***/
    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot274Bas2Repn4BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
