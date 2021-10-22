/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  FalbckAssi.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/SF111A_FalbckAssi_Impl-nz2999/SF111A_FalbckAssi_Impl/tools/Component.dpa
 *     SW-C Type:  FalbckAssi
 *  Generated at:  Fri Apr 20 08:33:35 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <FalbckAssi>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : FalbckAssi.c
 * Module Description: SF111A Implementation - Fallback Assist
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/19/18  1        KByrski   Initial version(based in Design 1.0.0)                                        EA4#22536
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
 * u4p12
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u6p10
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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

#include "Rte_FalbckAssi.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"
#include "SysGlbPrm.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Local Function Prototypes *********************************************/

/*************************************************** Local Macros ****************************************************/
#define PrmFalbckAssiAssiX              (*(const Ary2D_u6p10_12_20 *) Rte_Prm_FalbckAssiAssiX_Ary2D())
#define PrmSysGlbPrmVehSpdBilnrSeln     (*(const Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D())

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
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u4p12_20: Array with 20 element(s) of type u4p12
 * Ary1D_u6p10_20: Array with 20 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u4p12_12_20: Array with 12 element(s) of type Ary1D_u4p12_20
 * Ary2D_u6p10_12_20: Array with 12 element(s) of type Ary1D_u6p10_20
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
 *   float32 *Rte_Pim_FalbckAssiNotchFil1(void)
 *   float32 *Rte_Pim_FalbckAssiNotchFil2(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   u6p10 *Rte_Prm_FalbckAssiAssiX_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_20
 *   u4p12 *Rte_Prm_FalbckAssiAssiY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_20
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *   FilNotchGainRec1 *Rte_Prm_FalbckAssiNotchFil_Rec(void)
 *
 *********************************************************************************************************************/


#define FalbckAssi_START_SEC_CODE
#include "FalbckAssi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FalbckAssiInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FalbckAssiInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, FalbckAssi_CODE) FalbckAssiInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FalbckAssiInit1
 *********************************************************************************************************************/

    /* Empty Init function */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FalbckAssiPer1
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
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FalbckAssiMotTqCmd_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FalbckAssiPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, FalbckAssi_CODE) FalbckAssiPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FalbckAssiPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) FalbckAssiMotTqCmd_MotNwtMtr_T_f32;

    /* Temporary */
    VAR(u4p12, AUTOMATIC) MotTqCmd_MotNwtMtr_T_u4p12;
    VAR(float32, AUTOMATIC) FalbckAssiMotTqCmdPreFilt_MotNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

    /* Assi */
    MotTqCmd_MotNwtMtr_T_u4p12 = BilnrIntrpnWithRound_u16_u16MplXu16MplY(
            FloatToFixd_u16_f32(Abslt_f32_f32(VehSpd_Kph_T_f32), NXTRFIXDPT_FLOATTOP7_ULS_F32),
            FloatToFixd_u16_f32(Abslt_f32_f32(HwTq_HwNwtMtr_T_f32), NXTRFIXDPT_FLOATTOP10_ULS_F32),
            Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln),
            Rte_Prm_FalbckAssiAssiX_Ary2D(),
            Rte_Prm_FalbckAssiAssiY_Ary2D(),
            (uint16) TblSize_m(PrmFalbckAssiAssiX[0]));

    FalbckAssiMotTqCmdPreFilt_MotNwtMtr_T_f32 =
            FixdToFloat_f32_u16(MotTqCmd_MotNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32) *
            (float32) Sign_s08_f32(HwTq_HwNwtMtr_T_f32);

    /* StabyCmp */
    /* CompFilter_FwdPath */
    FalbckAssiMotTqCmd_MotNwtMtr_T_f32 =
            (FalbckAssiMotTqCmdPreFilt_MotNwtMtr_T_f32 * Rte_Prm_FalbckAssiNotchFil_Rec()->FilGainB0) +
            *Rte_Pim_FalbckAssiNotchFil1();

    /* CompFilter_UpdateSV */
    *Rte_Pim_FalbckAssiNotchFil1()  =
            (*Rte_Pim_FalbckAssiNotchFil2() +
             (FalbckAssiMotTqCmdPreFilt_MotNwtMtr_T_f32 * Rte_Prm_FalbckAssiNotchFil_Rec()->FilGainB1)) -
            (FalbckAssiMotTqCmd_MotNwtMtr_T_f32 * Rte_Prm_FalbckAssiNotchFil_Rec()->FilGainA1);

    *Rte_Pim_FalbckAssiNotchFil2() =
            (FalbckAssiMotTqCmdPreFilt_MotNwtMtr_T_f32 * Rte_Prm_FalbckAssiNotchFil_Rec()->FilGainB2) -
            (FalbckAssiMotTqCmd_MotNwtMtr_T_f32 * Rte_Prm_FalbckAssiNotchFil_Rec()->FilGainA2);

    FalbckAssiMotTqCmd_MotNwtMtr_T_f32 = Lim_f32(
            FalbckAssiMotTqCmd_MotNwtMtr_T_f32,
            SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,
            SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

    /* Write outputs */
    (void) Rte_Write_FalbckAssiMotTqCmd_Val(FalbckAssiMotTqCmd_MotNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define FalbckAssi_STOP_SEC_CODE
#include "FalbckAssi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
