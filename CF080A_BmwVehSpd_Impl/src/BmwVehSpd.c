/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwVehSpd.c
 *        Config:  C:/_S/work/ses_dev_ea4/CF080A_BmwVehSpd_Impl-z172399/CF080A_BmwVehSpd_Impl/tools/Component.dpa
 *     SW-C Type:  BmwVehSpd
 *  Generated at:  Mon Jun 25 12:43:27 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwVehSpd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : BmwVehSpd.c
* Module Description: Implementation of BMW Vehicle Speed - CF080A FDD
* Project           : CBD 
* Author            : Matthew Leser
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       z172399 %
*----------------------------------------------------------------------------------------------------------------------
* Date       Rev     Author    Change Description                                                   	         SCR #
* -------   -------  --------  ---------------------------------------------------------------------------    ---------
* 02/27/18   1       ML        Initial Version                                                                EA4#17295
* 06/25/18   2       BrykczyM  Based on the design 3.0.0                                                      EA4#24330
*----------------------------------------------------------------------------------------------------------------------
**********************************************************************************************************************/

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
 * BmwCogVehSpdQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwNearStillVehSpdSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwPinionAgQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwSecurVehSpdSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u16p0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_BmwVehSpd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"
#include "ArchGlbPrm.h"

/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read and Rte_Write */ 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16 ((uint32)10U)
#define ONECNT_CNT_U16                      ((uint32)20U)
#define SPDDIFF_KPH_F32                     (1.0F)
#define VEHSPDMAX_KPH_F32                   (511.0F)
#define VEHSPDMIN_KPH_F32                   (0.0F)

/********************************************* Local Function Prototypes *********************************************/
static FUNC(void, BmwVehSpd_CODE) Cntr(
        CONST(boolean, AUTOMATIC) CntrTrigInp_Cnt_T_logl,
        CONSTP2VAR(boolean, AUTOMATIC, BmwVehSpd_VAR) SigValVld_Cnt_T_logl,
        CONSTP2VAR(boolean, AUTOMATIC, BmwVehSpd_VAR) CdnDurnSigValVld_Cnt_T_logl);

static FUNC(boolean, BmwVehSpd_CODE) VehSpdVldCalcn(
        CONST(BmwSecurVehSpdSts1, AUTOMATIC) BmwSecurVehSpdSts_Cnt_T_enum);

static FUNC(float32, BmwVehSpd_CODE) VehSpdRateLim(
        CONST(BmwSecurVehSpdSts1, AUTOMATIC) BmwSecurVehSpdSts_Cnt_T_enum,
        CONST(float32, AUTOMATIC) IntEpsVehSpd_Kph_T_f32);

static FUNC(boolean, BmwVehSpd_CODE) ProcessSecondAndGateState(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum);

static FUNC(boolean, BmwVehSpd_CODE) ProcessThirdAndGateState(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum);

static FUNC(boolean, BmwVehSpd_CODE) ProcessSixthAndGateState(
        CONST(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum);

static FUNC(boolean, BmwVehSpd_CODE) ProcessFourthAndGateState(
        CONST(boolean, AUTOMATIC) ThirdAndGateEval_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) SixthAndGateEval_Cnt_T_logl);

static FUNC(boolean, BmwVehSpd_CODE) ProcessThridConditionOfOrGate(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC)  CdnDurnSigValVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum);

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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u16p0: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwCogVehSpdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWCOGVEHSPDQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWCOGVEHSPDQLFR_INIT (8U)
 *   BMWCOGVEHSPDQLFR_SIGVALTMPVLD (10U)
 *   BMWCOGVEHSPDQLFR_SIGQLYMONTMPRSTRCTD (11U)
 *   BMWCOGVEHSPDQLFR_SIGVALTMPINVLD (14U)
 *   BMWCOGVEHSPDQLFR_INVLD (15U)
 * BmwNearStillVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWNEARSTILLVEHSPDSTS_VEHREST (12U)
 *   BMWNEARSTILLVEHSPDSTS_VEHNOTREST (13U)
 *   BMWNEARSTILLVEHSPDSTS_INVLD (15U)
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWPINIONAGQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWPINIONAGQLFR_SIGVALVLD (2U)
 *   BMWPINIONAGQLFR_SUBVALSETINUSRSIG (4U)
 *   BMWPINIONAGQLFR_INIT (8U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY (9U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY (10U)
 *   BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG (12U)
 *   BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP (14U)
 *   BMWPINIONAGQLFR_INVLDSIG (15U)
 * BmwSecurVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWSECURVEHSPDSTS_SIGVALVLD (1U)
 *   BMWSECURVEHSPDSTS_VEHSTANDG (4U)
 *   BMWSECURVEHSPDSTS_VEHRUNNG (12U)
 *   BMWSECURVEHSPDSTS_NOINFO (14U)
 *   BMWSECURVEHSPDSTS_INVLD (15U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_VehSpdLimPrev(void)
 *   uint32 *Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(void)
 *   boolean *Rte_Pim_SpdDifChkFlg(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdRunngSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val(void)
 *   u16p0 Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void)
 *
 *********************************************************************************************************************/


#define BmwVehSpd_START_SEC_CODE
#include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwVehSpd_CODE) BmwVehSpdInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdInit1
 *********************************************************************************************************************/

    *Rte_Pim_SpdDifChkFlg() = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwCogVehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdStsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data)
 *   Std_ReturnType Rte_Write_VehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehSpdVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwVehSpd_CODE) BmwVehSpdPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdPer1
 *********************************************************************************************************************/
    
    /* Inputs */
    VAR(float32, AUTOMATIC) BmwCogVehSpd_Kph_T_f32;
    VAR(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) BmwCogVehSpdVld_Cnt_T_logl;
    VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwNearStillVehSpdSts_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwNearStillVehSpdStsVld_Cnt_T_logl;
    VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum;

    /* Internals */
    VAR(boolean, AUTOMATIC) SigValVld_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) CdnDurnSigValVld_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) OrConBmwSecurVehSpdStsSigValNotEquToVld_Cnt_T_logl;
    VAR(float32, AUTOMATIC) IntEpsVehSpd_Kph_T_f32;
    VAR(boolean, AUTOMATIC) SecondAndGateEval_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) ThirdAndGateEval_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) FourthAndGateEval_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) SixthAndGateEval_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) TheThirdConditionOfOrGate_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) VehStandg_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) VehRunng_Cnt_T_logl;

    /* Outputs */
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(BmwSecurVehSpdSts1, AUTOMATIC) BmwSecurVehSpdSts_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl;
    
    /* Read Inputs */
    (void) Rte_Read_BmwCogVehSpd_Val(&BmwCogVehSpd_Kph_T_f32);
    (void) Rte_Read_BmwCogVehSpdQlfr_Val(&BmwCogVehSpdQlfr_Cnt_T_enum);
    (void) Rte_Read_BmwCogVehSpdQlfrVld_Logl(&BmwCogVehSpdQlfrVld_Cnt_T_logl);
    (void) Rte_Read_BmwCogVehSpdVld_Logl(&BmwCogVehSpdVld_Cnt_T_logl);
    (void) Rte_Read_BmwNearStillVehSpdSts_Val(&BmwNearStillVehSpdSts_Cnt_T_enum);
    (void) Rte_Read_BmwNearStillVehSpdStsVld_Logl(&BmwNearStillVehSpdStsVld_Cnt_T_logl);
    (void) Rte_Read_BmwPinionAgQlfr_Val(&BmwPinionAgQlfr_Cnt_T_enum);
    
    /* BmwSecurVehSpdStsSigValVldCalcn */
    /* the 1st AND and the 2nd AND evaluation */
    SecondAndGateEval_Cnt_T_logl = ProcessSecondAndGateState(
            BmwCogVehSpdVld_Cnt_T_logl,
            BmwCogVehSpdQlfrVld_Cnt_T_logl,
            BmwCogVehSpdQlfr_Cnt_T_enum);

    /* the 1st AND and the 3rd AND evaluation */
    ThirdAndGateEval_Cnt_T_logl = ProcessThirdAndGateState(
            BmwCogVehSpdVld_Cnt_T_logl,
            BmwCogVehSpdQlfrVld_Cnt_T_logl,
            BmwCogVehSpdQlfr_Cnt_T_enum);

    /* the 6th AND evaluation */
    SixthAndGateEval_Cnt_T_logl = ProcessSixthAndGateState(BmwPinionAgQlfr_Cnt_T_enum);

    /* the 4th AND evaluation */
    FourthAndGateEval_Cnt_T_logl = ProcessFourthAndGateState(ThirdAndGateEval_Cnt_T_logl,SixthAndGateEval_Cnt_T_logl);

    /* Cntr */
    Cntr((((ThirdAndGateEval_Cnt_T_logl != FALSE) && (SixthAndGateEval_Cnt_T_logl == FALSE)) ? TRUE : FALSE),
            &SigValVld_Cnt_T_logl,
            &CdnDurnSigValVld_Cnt_T_logl);

    /* OR gate evaluation */
    if ((SigValVld_Cnt_T_logl != FALSE)
       || (SecondAndGateEval_Cnt_T_logl != FALSE)
       || (FourthAndGateEval_Cnt_T_logl != FALSE))
    {
        SigValVld_Cnt_T_logl = TRUE;
    }
    else
    {
        SigValVld_Cnt_T_logl = FALSE;
    }

    /* BmwSecurVehSpdStsSigValNotEquToVld */
    /* process conditions in OR */
    TheThirdConditionOfOrGate_Cnt_T_logl = ProcessThridConditionOfOrGate(
            BmwCogVehSpdQlfrVld_Cnt_T_logl,
            CdnDurnSigValVld_Cnt_T_logl,
            BmwCogVehSpdQlfr_Cnt_T_enum);

    if ((BmwCogVehSpdVld_Cnt_T_logl == FALSE)
       || (BmwCogVehSpdQlfrVld_Cnt_T_logl == FALSE)
       || (TheThirdConditionOfOrGate_Cnt_T_logl != FALSE))
    {
        OrConBmwSecurVehSpdStsSigValNotEquToVld_Cnt_T_logl = TRUE;
    }
    else
    {
        OrConBmwSecurVehSpdStsSigValNotEquToVld_Cnt_T_logl = FALSE;
    }

    VehStandg_Cnt_T_logl =
            ((BmwNearStillVehSpdStsVld_Cnt_T_logl != FALSE) && (BmwNearStillVehSpdSts_Cnt_T_enum == BMWNEARSTILLVEHSPDSTS_VEHREST)
                    && (OrConBmwSecurVehSpdStsSigValNotEquToVld_Cnt_T_logl != FALSE)) ? TRUE : FALSE;

    VehRunng_Cnt_T_logl =
            ((BmwNearStillVehSpdStsVld_Cnt_T_logl != FALSE) && (BmwNearStillVehSpdSts_Cnt_T_enum == BMWNEARSTILLVEHSPDSTS_VEHNOTREST)
                    && (OrConBmwSecurVehSpdStsSigValNotEquToVld_Cnt_T_logl != FALSE)) ? TRUE : FALSE;

    if (SigValVld_Cnt_T_logl != FALSE)
    {
        /* BMWSECURVEHSPDSTS_SIGVALVLD */
        BmwSecurVehSpdSts_Cnt_T_enum = BMWSECURVEHSPDSTS_SIGVALVLD;
        IntEpsVehSpd_Kph_T_f32       = BmwCogVehSpd_Kph_T_f32;
    }
    else if (VehStandg_Cnt_T_logl != FALSE)
    {
        /* VehStandg */
        BmwSecurVehSpdSts_Cnt_T_enum = BMWSECURVEHSPDSTS_VEHSTANDG;
        IntEpsVehSpd_Kph_T_f32 = Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val();
    }
    else if (VehRunng_Cnt_T_logl != FALSE)
    {
        /* VehRunng */
        BmwSecurVehSpdSts_Cnt_T_enum = BMWSECURVEHSPDSTS_VEHRUNNG;
        IntEpsVehSpd_Kph_T_f32 = Rte_Prm_BmwVehSpdRunngSubVehSpd_Val();
    }
    else
    {
        /* NoInfo */
        BmwSecurVehSpdSts_Cnt_T_enum = BMWSECURVEHSPDSTS_NOINFO;
        IntEpsVehSpd_Kph_T_f32 = Rte_Prm_BmwVehSpdRunngSubVehSpd_Val();
    }


    VehSpdVld_Cnt_T_logl = VehSpdVldCalcn(BmwSecurVehSpdSts_Cnt_T_enum);

    VehSpd_Kph_T_f32 = VehSpdRateLim(
            BmwSecurVehSpdSts_Cnt_T_enum,
            IntEpsVehSpd_Kph_T_f32);

    VehSpd_Kph_T_f32      = Lim_f32(VehSpd_Kph_T_f32, VEHSPDMIN_KPH_F32, VEHSPDMAX_KPH_F32);
    *Rte_Pim_VehSpdLimPrev() = VehSpd_Kph_T_f32;

    /* Write Outputs */
    (void) Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts_Cnt_T_enum);
    (void) Rte_Write_VehSpdVld_Logl(VehSpdVld_Cnt_T_logl);
    (void) Rte_Write_VehSpd_Val(VehSpd_Kph_T_f32);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwVehSpd_STOP_SEC_CODE
#include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Name:        Cntr
 * Description: The implementation of the simulink block Cntr
 * Inputs:      CntrTrigInp_Cnt_T_logl
 *              *Rte_Pim_BmwSecurVehSpdStsSigValVldDurn()
 * Outputs:     SigValVld_Cnt_T_logl
 *              CdnDurnSigValVld_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwVehSpd_CODE) Cntr(
        CONST(boolean, AUTOMATIC) CntrTrigInp_Cnt_T_logl,
        CONSTP2VAR(boolean, AUTOMATIC, BmwVehSpd_VAR) SigValVld_Cnt_T_logl,
        CONSTP2VAR(boolean, AUTOMATIC, BmwVehSpd_VAR) CdnDurnSigValVld_Cnt_T_logl)
{

    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (CntrTrigInp_Cnt_T_logl != FALSE)
    {
        /* SigValVldElpdTi */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32)Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val() * CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* SigValVldDurnFalse */
            *SigValVld_Cnt_T_logl        = FALSE;
            *CdnDurnSigValVld_Cnt_T_logl = TRUE;
        }
        else
        {
            /* SigValVldDurnTrue */
            *SigValVld_Cnt_T_logl        = TRUE;
            *CdnDurnSigValVld_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* GetTi */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_BmwSecurVehSpdStsSigValVldDurn());
        *Rte_Pim_BmwSecurVehSpdStsSigValVldDurn()  += ONECNT_CNT_U16;
        *SigValVld_Cnt_T_logl                      =  FALSE;
        *CdnDurnSigValVld_Cnt_T_logl               =  FALSE;
    }
}

/**********************************************************************************************************************
 * Name:        VehSpdVldCalcn
 * Description: The implementation of a Simulink block VehSpdVldCalcn
 * Inputs:      BmwSecurVehSpdSts_Cnt_T_enum
 * Outputs:     VehSpdVld_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) VehSpdVldCalcn(
        CONST(BmwSecurVehSpdSts1, AUTOMATIC) BmwSecurVehSpdSts_Cnt_T_enum)
{
    VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl;

    if (  (BmwSecurVehSpdSts_Cnt_T_enum == BMWSECURVEHSPDSTS_SIGVALVLD)
       || (BmwSecurVehSpdSts_Cnt_T_enum == BMWSECURVEHSPDSTS_VEHSTANDG)
       || (BmwSecurVehSpdSts_Cnt_T_enum == BMWSECURVEHSPDSTS_VEHRUNNG))
    {
        VehSpdVld_Cnt_T_logl = TRUE;
    }
    else
    {
        VehSpdVld_Cnt_T_logl = FALSE;
    }

    return VehSpdVld_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        VehSpdRateLim
 * Description: The implementation of a Simulink block VehSpdRateLim
 * Inputs:      BmwSecurVehSpdSts_Cnt_T_enum
 *              IntEpsVehSpd_Kph_T_f32
 *              *Rte_Pim_VehSpdLimPrev()
 *              *Rte_Pim_SpdDifChkFlg()
 * Outputs:     *Rte_Pim_VehSpdLimPrev()
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, BmwVehSpd_CODE) VehSpdRateLim(
        CONST(BmwSecurVehSpdSts1, AUTOMATIC) BmwSecurVehSpdSts_Cnt_T_enum,
        CONST(float32, AUTOMATIC) IntEpsVehSpd_Kph_T_f32)
{
    VAR(float32, AUTOMATIC) SecurVehSpdInvldRateLim_KphPerSec_T_f32;
    VAR(boolean, AUTOMATIC) SpdDiff_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) SecondOrGateInput_Cnt_T_logl;

    if (Abslt_f32_f32(*Rte_Pim_VehSpdLimPrev() - IntEpsVehSpd_Kph_T_f32) >= SPDDIFF_KPH_F32)
    {
        SpdDiff_Cnt_T_logl = TRUE;
    }
    else
    {
        SpdDiff_Cnt_T_logl = FALSE;
    }

    SecondOrGateInput_Cnt_T_logl =
            ((BmwSecurVehSpdSts_Cnt_T_enum == BMWSECURVEHSPDSTS_SIGVALVLD)
            && (SpdDiff_Cnt_T_logl != FALSE)
            && (*Rte_Pim_SpdDifChkFlg() != FALSE)) ? TRUE : FALSE;

    if ((BmwSecurVehSpdSts_Cnt_T_enum != BMWSECURVEHSPDSTS_SIGVALVLD) || (SecondOrGateInput_Cnt_T_logl != FALSE))
    {
        SecurVehSpdInvldRateLim_KphPerSec_T_f32 = Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val();
        *Rte_Pim_SpdDifChkFlg()                 = TRUE;
    }
    else
    {
        SecurVehSpdInvldRateLim_KphPerSec_T_f32 = Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val();
        *Rte_Pim_SpdDifChkFlg()                 = FALSE;
    }

    *Rte_Pim_VehSpdLimPrev() = Lim_f32(
            IntEpsVehSpd_Kph_T_f32,
            *Rte_Pim_VehSpdLimPrev() - (SecurVehSpdInvldRateLim_KphPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32),
            *Rte_Pim_VehSpdLimPrev() + (SecurVehSpdInvldRateLim_KphPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32));

    return *Rte_Pim_VehSpdLimPrev();
}


/**********************************************************************************************************************
 * Name:        ProcessSecondAndGateState
 * Description: The implementation of the second AND gate logic in simulink block BmwSecurVehSpdStsSigValVldCalcn
 * Inputs:      BmwCogVehSpdVld_Cnt_T_logl
 *              BmwCogVehSpdQlfrVld_Cnt_T_logl
 *              BmwCogVehSpdQlfr_Cnt_T_enum
 * Outputs:     SecondAndGateEval_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) ProcessSecondAndGateState(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum)
{

    VAR(boolean, AUTOMATIC) SecondAndGateEval_Cnt_T_logl;

    if ((BmwCogVehSpdVld_Cnt_T_logl       != FALSE)
       && (BmwCogVehSpdQlfrVld_Cnt_T_logl != FALSE)
       && (BmwCogVehSpdQlfr_Cnt_T_enum    == BMWCOGVEHSPDQLFR_SIGVALVLDANDPLAUS))
    {
        SecondAndGateEval_Cnt_T_logl = TRUE;
    }
    else
    {
        SecondAndGateEval_Cnt_T_logl = FALSE;
    }

    return SecondAndGateEval_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        ProcessThirdAndGateState
 * Description: The implementation of the third AND gate logic in simulink block BmwSecurVehSpdStsSigValVldCalcn
 * Inputs:      BmwCogVehSpdVld_Cnt_T_logl
 *              BmwCogVehSpdQlfrVld_Cnt_T_logl
 *              BmwCogVehSpdQlfr_Cnt_T_enum
 * Outputs:     ThirdAndGateEval_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) ProcessThirdAndGateState(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum)
{

    VAR(boolean, AUTOMATIC) ThirdAndGateEval_Cnt_T_logl;

    if ((BmwCogVehSpdVld_Cnt_T_logl       != FALSE)
       && (BmwCogVehSpdQlfrVld_Cnt_T_logl != FALSE)
       && (BmwCogVehSpdQlfr_Cnt_T_enum    == BMWCOGVEHSPDQLFR_SIGVALTMPVLD))
    {
        ThirdAndGateEval_Cnt_T_logl = TRUE;
    }
    else
    {
        ThirdAndGateEval_Cnt_T_logl = FALSE;
    }

    return ThirdAndGateEval_Cnt_T_logl;
}



/**********************************************************************************************************************
 * Name:        ProcessSixthAndGateState
 * Description: The implementation of the sixth AND gate logic in simulink block BmwSecurVehSpdStsSigValVldCalcn
 * Inputs:      BmwCogVehSpdQlfr_Cnt_T_enum
 * Outputs:     SixthAndGateEval_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) ProcessSixthAndGateState(
        CONST(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum)
{

    VAR(boolean, AUTOMATIC) SixthAndGateEval_Cnt_T_logl;

    if ((BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALVLDANDPLAUS)
       && (BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALVLD)
       && (BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY)
       && (BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY))

    {
        SixthAndGateEval_Cnt_T_logl = TRUE;
    }
    else
    {
        SixthAndGateEval_Cnt_T_logl = FALSE;
    }

    return SixthAndGateEval_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        ProcessFourthAndGateState
 * Description: The implementation of the fourth AND gate logic in simulink block BmwSecurVehSpdStsSigValVldCalcn
 * Inputs:      ThirdAndGateEval_Cnt_T_logl
 *              SixthAndGateEval_Cnt_T_logl
 * Outputs:     return value of logic operation
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) ProcessFourthAndGateState(
        CONST(boolean, AUTOMATIC) ThirdAndGateEval_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) SixthAndGateEval_Cnt_T_logl)
{
    return (((ThirdAndGateEval_Cnt_T_logl != FALSE) && (SixthAndGateEval_Cnt_T_logl != FALSE)) ? TRUE : FALSE);
}

/**********************************************************************************************************************
 * Name:        ProcessThridConditionOfOrGate
 * Description: The implementation of the logic of the three input OR gate from
 *              the simulink block BmwSecurVehSpdStsSigValNotEquToVld
 * Inputs:      BmwCogVehSpdQlfrVld_Cnt_T_logl
 *              CdnDurnSigValVld_Cnt_T_logl
 *              BmwCogVehSpdQlfr_Cnt_T_enum
 * Outputs:     LogicResult_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwVehSpd_CODE) ProcessThridConditionOfOrGate(
        CONST(boolean, AUTOMATIC) BmwCogVehSpdQlfrVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC)  CdnDurnSigValVld_Cnt_T_logl,
        CONST(BmwCogVehSpdQlfr1, AUTOMATIC) BmwCogVehSpdQlfr_Cnt_T_enum)
{
    VAR(boolean, AUTOMATIC) LogicResult_Cnt_T_logl;

    if ((BmwCogVehSpdQlfrVld_Cnt_T_logl != FALSE)
       && ((CdnDurnSigValVld_Cnt_T_logl != FALSE)
          || ((BmwCogVehSpdQlfr_Cnt_T_enum != BMWCOGVEHSPDQLFR_SIGVALTMPVLD)
          && (BmwCogVehSpdQlfr_Cnt_T_enum != BMWCOGVEHSPDQLFR_SIGVALVLDANDPLAUS))))
    {
        LogicResult_Cnt_T_logl = TRUE;
    }
    else
    {
        LogicResult_Cnt_T_logl = FALSE;
    }

    return LogicResult_Cnt_T_logl;

}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
