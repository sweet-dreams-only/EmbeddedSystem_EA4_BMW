/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwFltHndlg.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF070A_BmwFltHndlg_Impl-nz2999/CF070A_BmwFltHndlg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwFltHndlg
 *  Generated at:  Tue Apr 10 16:07:23 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwFltHndlg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwFltHndlg.c
 * Module Description: Implementation of CF070A - BMW Fault Handling
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 11/06/17  1        KByrski   Initial version                                                               EA4#16251
 * 04/10/18  2        KByrski   Updated as per Design 2.0.0                                                   EA4#22087
 *********************************************************************************************************************/
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
 *
 * Component Types:
 * ================
 * BmwFltHndlg
 *   BMW Fault Handling function provides a functionality of requesting the lamp status whenever the proper indicator status is set to On.
 *
 *********************************************************************************************************************/

#include "Rte_BmwFltHndlg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Dem.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Dem_, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define EPTIINSPNRLVLAMP_CNT_U08   (2U)
#define NORMWARNLAMP_CNT_U08       (0U)
#define THERMWARNLAMP_CNT_U08      (1U)

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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwFltLampReqSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWFLTLAMPREQSTS_FLTLAMPRSTREQD (0U)
 *   BMWFLTLAMPREQSTS_FLTLAMPSETREQD (1U)
 *   BMWFLTLAMPREQSTS_INVLD (3U)
 * BmwFltLampReqTyp2: Enumeration of integer in interval [0...65535] with enumerators
 *   BMWFLTLAMPREQTYP_NOLAMP (0U)
 *   BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP (1U)
 *   BMWFLTLAMPREQTYP_NORMWARNLAMP (2U)
 *   BMWFLTLAMPREQTYP_THERMWARNLAMP (3U)
 *
 *********************************************************************************************************************/


#define BmwFltHndlg_START_SEC_CODE
#include "BmwFltHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwFltHndlgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwFltHndlg_CODE) BmwFltHndlgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgInit1
 *********************************************************************************************************************/

    /* Do nothing */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwFltHndlgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwFltLampReqSts_Val(BmwFltLampReqSts1 data)
 *   Std_ReturnType Rte_Write_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwFltHndlg_CODE) BmwFltHndlgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwFltHndlgPer1
 *********************************************************************************************************************/

    /* Outputs */
    VAR(BmwFltLampReqSts1, AUTOMATIC) BmwFltLampReqSts_Cnt_T_enum;
    VAR(BmwFltLampReqTyp2, AUTOMATIC) BmwFltLampReqTyp_Cnt_T_enum;

    /* Temporary */
    VAR(Dem_IndicatorStatusType, AUTOMATIC) EptiInspnRlvLamp_Cnt_T_enum = DEM_INDICATOR_OFF;
    VAR(Dem_IndicatorStatusType, AUTOMATIC) NormWarnLamp_Cnt_T_enum     = DEM_INDICATOR_OFF;
    VAR(Dem_IndicatorStatusType, AUTOMATIC) ThermWarnLamp_Cnt_T_enum    = DEM_INDICATOR_OFF;

    /* Read inputs */
    (void) Dem_GetIndicatorStatus(EPTIINSPNRLVLAMP_CNT_U08, &EptiInspnRlvLamp_Cnt_T_enum);
    (void) Dem_GetIndicatorStatus(NORMWARNLAMP_CNT_U08,     &NormWarnLamp_Cnt_T_enum);
    (void) Dem_GetIndicatorStatus(THERMWARNLAMP_CNT_U08,    &ThermWarnLamp_Cnt_T_enum);

    if (EptiInspnRlvLamp_Cnt_T_enum != DEM_INDICATOR_OFF)
    {
        /* SelfTest */
        BmwFltLampReqSts_Cnt_T_enum = BMWFLTLAMPREQSTS_FLTLAMPSETREQD;
        BmwFltLampReqTyp_Cnt_T_enum = BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP;
    }
    else if (NormWarnLamp_Cnt_T_enum != DEM_INDICATOR_OFF)
    {
        /* Normal */
        BmwFltLampReqSts_Cnt_T_enum = BMWFLTLAMPREQSTS_FLTLAMPSETREQD;
        BmwFltLampReqTyp_Cnt_T_enum = BMWFLTLAMPREQTYP_NORMWARNLAMP;
    }
    else if (ThermWarnLamp_Cnt_T_enum != DEM_INDICATOR_OFF)
    {
        /* Therm */
        BmwFltLampReqSts_Cnt_T_enum = BMWFLTLAMPREQSTS_FLTLAMPSETREQD;
        BmwFltLampReqTyp_Cnt_T_enum = BMWFLTLAMPREQTYP_THERMWARNLAMP;
    }
    else
    {
        /* NoLamp */
        BmwFltLampReqSts_Cnt_T_enum = BMWFLTLAMPREQSTS_FLTLAMPRSTREQD;
        BmwFltLampReqTyp_Cnt_T_enum = BMWFLTLAMPREQTYP_NOLAMP;
    }

    /* Write outputs */
    (void) Rte_Write_BmwFltLampReqSts_Val(BmwFltLampReqSts_Cnt_T_enum);
    (void) Rte_Write_BmwFltLampReqTyp_Val(BmwFltLampReqTyp_Cnt_T_enum);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwFltHndlg_STOP_SEC_CODE
#include "BmwFltHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
