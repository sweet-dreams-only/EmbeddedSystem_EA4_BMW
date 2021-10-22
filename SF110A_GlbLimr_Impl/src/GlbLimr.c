/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  GlbLimr.c
 *        Config:  C:/_S/work/ses_dev_ea4/SF110A_GlbLimr_Impl-z172399/SF110A_GlbLimr_Impl/tools/Component.dpa
 *     SW-C Type:  GlbLimr
 *  Generated at:  Fri Apr 20 09:39:24 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <GlbLimr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : GlbLimr.c
 * Module Description: Implementation of SF110A - Global Limiter
 * Project           : CBD
 * Author            : Marek Brykczynski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/20/18  1        BrykczyM  Updated in compliance to the Design 1.0.0                                     EA4#22473
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
 * s4p11
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_GlbLimr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/************************************************ Include Statements *************************************************/
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"
#include "SysGlbPrm.h"

/********************************************* Embedded Local Constants **********************************************/
#define D_NUMLOOPS_CNT      2U

/*************************************************** Local Macros ****************************************************/
#define PrmGlbLimrVehSpdBilnrSelnTbl (*(const Ary1D_u9p7_10 *) Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D())
#define PrmGlbLimrBndXTbl            (*(const Ary2D_s4p11_10_13 *) Rte_Prm_GlbLimrBndX_Ary2D())

/********************************************* Local Function Prototypes *********************************************/
static FUNC(float32, GlbLimr_CODE) GlbLimrCompensator(
        CONST(float32, AUTOMAITC)   Assist_MotNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, GlbLimrCompensator_VAR) GlbLimrNotchNumberFil1Ptr_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, GlbLimrCompensator_VAR) GlbLimrNotchNumberFil2Ptr_Uls_T_f32);


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s4p11: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_13: Array with 13 element(s) of type s4p11
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary2D_s4p11_10_13: Array with 10 element(s) of type Ary1D_s4p11_13
 *
 * Record Types:
 * =============
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_GlbLimrNotch1Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch1Fil2(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil1(void)
 *   float32 *Rte_Pim_GlbLimrNotch2Fil2(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   s4p11 *Rte_Prm_GlbLimrBndX_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   s4p11 *Rte_Prm_GlbLimrBndY_Ary2D(void)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   u9p7 *Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   FilNotchGainRec1 *Rte_Prm_GlbLimrNotchFilStruct_Rec(void)
 *
 *********************************************************************************************************************/


#define GlbLimr_START_SEC_CODE
#include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, GlbLimr_CODE) GlbLimrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GlbLimrPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LimdMotTqCmd_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, GlbLimr_CODE) GlbLimrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GlbLimrPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) MotTqCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Internals */
    VAR(uint8,  AUTOMATIC)  Iterator_Cnt_T_u08;
    VAR(s4p11,  AUTOMATIC)  InterHwTq_HwNwtMtr_T_s4p11;
    VAR(float32, AUTOMATIC) InvCompHwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) NotinvCompHwTq_HwNwtMtr_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) LimdMotTqCmd_MotNwtMtr_T_f32;


    /* Read Inputs */
    Rte_Read_MotTqCmd_Val(&MotTqCmd_MotNwtMtr_T_f32);
    Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);


    for(Iterator_Cnt_T_u08 = 0; Iterator_Cnt_T_u08 < D_NUMLOOPS_CNT; Iterator_Cnt_T_u08++)
    {

        InterHwTq_HwNwtMtr_T_s4p11 = BilnrIntrpnWithRound_s16_s16MplXs16MplY(
                FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32),
                FloatToFixd_s16_f32(((Iterator_Cnt_T_u08 == 0) ? (-HwTq_HwNwtMtr_T_f32):(HwTq_HwNwtMtr_T_f32)),NXTRFIXDPT_FLOATTOP11_ULS_F32),
                Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(),
                (uint16) TblSize_m(PrmGlbLimrVehSpdBilnrSelnTbl),
                Rte_Prm_GlbLimrBndX_Ary2D(),
                Rte_Prm_GlbLimrBndY_Ary2D(),
                (uint16) TblSize_m(PrmGlbLimrBndXTbl[0]));


        /* distinguish the iteration and call the compensator with different input parameters
         * iteration 0 - an inversed value is being processd
         * iteration 1 - a not inversed value is being  processed
         */
        if(Iterator_Cnt_T_u08 == 0)
        {
            /* Compensator 1 - Inversed sign */
            InvCompHwTq_HwNwtMtr_T_f32    = GlbLimrCompensator(
                    -(FixdToFloat_f32_s16(InterHwTq_HwNwtMtr_T_s4p11, NXTRFIXDPT_P11TOFLOAT_ULS_F32)),
                    Rte_Pim_GlbLimrNotch1Fil1(),
                    Rte_Pim_GlbLimrNotch1Fil2());
        }
        else
        {
            /* Compensator 2 - Not inversed sign  */
            NotinvCompHwTq_HwNwtMtr_T_f32 = GlbLimrCompensator(
                    FixdToFloat_f32_s16(InterHwTq_HwNwtMtr_T_s4p11, NXTRFIXDPT_P11TOFLOAT_ULS_F32),
                    Rte_Pim_GlbLimrNotch2Fil1(),
                    Rte_Pim_GlbLimrNotch2Fil2());

        }
    }

    LimdMotTqCmd_MotNwtMtr_T_f32 = Lim_f32(
            MotTqCmd_MotNwtMtr_T_f32,
            InvCompHwTq_HwNwtMtr_T_f32,
            NotinvCompHwTq_HwNwtMtr_T_f32);

    /* Write Outputs */
    Rte_Write_LimdMotTqCmd_Val(LimdMotTqCmd_MotNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define GlbLimr_STOP_SEC_CODE
#include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Name:        GlbLimrCompensator
 * Description: The unified implementation for compensator1 and compensator2 blocks from the design
 * Inputs:      Assist_MotNwtMtr_T_f32
 * In/Out:      GlbLimrNotchNumberFil1_Uls_T_f32
 *              GlbLimrNotchNumberFil2_Uls_T_f32
 * Outputs:     CompAssist_MotNwtMtr_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, GlbLimr_CODE) GlbLimrCompensator(
        CONST(float32, AUTOMAITC)   Assist_MotNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, GlbLimrCompensator_VAR) GlbLimrNotchNumberFil1Ptr_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, GlbLimrCompensator_VAR) GlbLimrNotchNumberFil2Ptr_Uls_T_f32)
{

    VAR(float32, AUTOMAITC)  CompAssist_MotNwtMtr_T_f32;


    /* CompFilter_FwdPath */
    CompAssist_MotNwtMtr_T_f32 = (Assist_MotNwtMtr_T_f32 * Rte_Prm_GlbLimrNotchFilStruct_Rec()->FilGainB0)
            + *GlbLimrNotchNumberFil1Ptr_Uls_T_f32;

    /* CompFilter_UpdateSV */

    /* Process CompFiltSV1 */
    *GlbLimrNotchNumberFil1Ptr_Uls_T_f32 = (*GlbLimrNotchNumberFil2Ptr_Uls_T_f32
            + (Assist_MotNwtMtr_T_f32 * Rte_Prm_GlbLimrNotchFilStruct_Rec()->FilGainB1))
            - (CompAssist_MotNwtMtr_T_f32 * Rte_Prm_GlbLimrNotchFilStruct_Rec()->FilGainA1);

    /* Process CompFiltSV2 */
    *GlbLimrNotchNumberFil2Ptr_Uls_T_f32 = (Assist_MotNwtMtr_T_f32 * Rte_Prm_GlbLimrNotchFilStruct_Rec()->FilGainB2)
            - (CompAssist_MotNwtMtr_T_f32 * Rte_Prm_GlbLimrNotchFilStruct_Rec()->FilGainA2);

    CompAssist_MotNwtMtr_T_f32 = Lim_f32(
            CompAssist_MotNwtMtr_T_f32,
            SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,
            SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

    return CompAssist_MotNwtMtr_T_f32;

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
