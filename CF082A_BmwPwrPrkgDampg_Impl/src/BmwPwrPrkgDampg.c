/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwPwrPrkgDampg.c
 *        Config:  C:/_S/work/ses_dev_ea4/CF082A_BmwPwrPrkgDampg_Impl-z172399/CF082A_BmwPwrPrkgDampg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwPwrPrkgDampg
 *  Generated at:  Wed May 16 13:53:21 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwPwrPrkgDampg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwPwrPrkgDampg.c
 * Module Description: Implementation of CF082A - BMW Power Parking Damping
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 01/08/18  1        KByrski   Initial version (based on Design 1.0.0)                                       EA4#17803
 * 04/18/18  2        BrykczyM  Updated in compliance to the Design 2.0.0                                     EA4#22459
 * 05/16/18  3        BrykczyM  Updated in compliance to the Design 3.0.0                                     EA4#23370
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
 * u12p4
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u1p15
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u5p11
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

#include "Rte_BmwPwrPrkgDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"
#include "ArchGlbPrm.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define ZERO_HWNWTMTR_F32                   (0.0F)
#define DAMPGCMDPWRPRKGHILIM_HWNWTMTR_F32   (10.0F)
#define DAMPGCMDPWRPRKGLOLIM_HWNWTMTR_F32   (-10.0F)

/*************************************************** Local Macros ****************************************************/
#define PrmBmwPwrPrkgDampgVehSpdLnrSelnX    (*(const Ary1D_u9p7_11 *) Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D())
#define PrmBmwPwrPrkgDampgPinionAgSelnTbl   (*(const Ary1D_u12p4_9 *) Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D())
#define PrmBmwPwrPrkgDampgHwVelTblX         (*(const Ary1D_u6p10_9 *) Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D())

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
 * u12p4: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u1p15_11: Array with 11 element(s) of type u1p15
 * Ary1D_u5p11_9: Array with 9 element(s) of type u5p11
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u9p7_11: Array with 11 element(s) of type u9p7
 * Ary2D_u5p11_9_9: Array with 9 element(s) of type Ary1D_u5p11_9
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DampgCmdPwrPrkgStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(void)
 *   float32 Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val(void)
 *   boolean Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(void)
 *   u5p11 *Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void)
 *     Returnvalue: u5p11* is of type Ary2D_u5p11_9_9
 *   u6p10 *Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_9
 *   u12p4 *Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u9p7 *Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_11
 *   u1p15 *Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_11
 *
 *********************************************************************************************************************/


#define BmwPwrPrkgDampg_START_SEC_CODE
#include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgInit1
 *********************************************************************************************************************/

    /* Empty Init function */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgPer1
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
 *   Std_ReturnType Rte_Read_DampgCmdBas_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DampgCmdPwrPrkgEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkg_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) DampgCmdBas_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) PinionAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) PinionAgConf_Uls_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(boolean, AUTOMATIC) DampgCmdPwrPrkgEna_Cnt_T_logl;

    /* Internals */
    VAR(u1p15,   AUTOMATIC) ScaFacY_Uls_T_u1p15;
    VAR(u5p11,   AUTOMATIC) ScadDampgY_HwNwtMtr_T_u5p11;
    VAR(float32, AUTOMATIC) ScadPwrPrkgDmpg_HwNwtMtr_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) DampgCmdPwrPrkg_HwNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_DampgCmdBas_Val(&DampgCmdBas_HwNwtMtr_T_f32);
    (void) Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);
    (void) Rte_Read_PinionAg_Val(&PinionAg_HwDeg_T_f32);
    (void) Rte_Read_PinionAgConf_Val(&PinionAgConf_Uls_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    (void) Rte_Read_DampgCmdPwrPrkgEna_Logl(&DampgCmdPwrPrkgEna_Cnt_T_logl);


    if (DampgCmdPwrPrkgEna_Cnt_T_logl != FALSE)
    {

        /* CodBitEnad */

        if ((Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl() == FALSE) && (PinionAgConf_Uls_T_f32 >= Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val()))
        {
            /* CalcScadDampg */
            ScaFacY_Uls_T_u1p15 = LnrIntrpn_u16_u16VariXu16VariY(
                    Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(),
                    Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(), (uint16) TblSize_m(PrmBmwPwrPrkgDampgVehSpdLnrSelnX),
                    FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32));

            ScadDampgY_HwNwtMtr_T_u5p11 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
                    FloatToFixd_u16_f32(Abslt_f32_f32(PinionAg_HwDeg_T_f32), NXTRFIXDPT_FLOATTOP4_ULS_F32),
                    FloatToFixd_u16_f32(Abslt_f32_f32(HwVel_HwRadPerSec_T_f32), NXTRFIXDPT_FLOATTOP10_ULS_F32),
                    Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(), (uint16) TblSize_m(PrmBmwPwrPrkgDampgPinionAgSelnTbl),
                    Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(),
                    Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(), (uint16) TblSize_m(PrmBmwPwrPrkgDampgHwVelTblX));

            ScadPwrPrkgDmpg_HwNwtMtr_T_f32 = FixdToFloat_f32_u16(ScaFacY_Uls_T_u1p15, NXTRFIXDPT_P15TOFLOAT_ULS_F32)
                    * ((float32) Sign_s08_f32(HwVel_HwRadPerSec_T_f32)) * FixdToFloat_f32_u16(ScadDampgY_HwNwtMtr_T_u5p11, NXTRFIXDPT_P11TOFLOAT_ULS_F32);
        }
        else
        {
            /* SetScadDampgToZero */
            ScadPwrPrkgDmpg_HwNwtMtr_T_f32 = ZERO_HWNWTMTR_F32;
        }

        /* RateLimDyn_f32 */
        *Rte_Pim_DampgCmdPwrPrkgStVari() = Lim_f32(
                ScadPwrPrkgDmpg_HwNwtMtr_T_f32,
                *Rte_Pim_DampgCmdPwrPrkgStVari() - (Rte_Prm_BmwPwrPrkgDampgMaxRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32),
                *Rte_Pim_DampgCmdPwrPrkgStVari() + (Rte_Prm_BmwPwrPrkgDampgMaxRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32));

        DampgCmdPwrPrkg_HwNwtMtr_T_f32 = *Rte_Pim_DampgCmdPwrPrkgStVari() + DampgCmdBas_HwNwtMtr_T_f32;


    }
    else
    {
        /* CodBitDisad */
        DampgCmdPwrPrkg_HwNwtMtr_T_f32   = ZERO_HWNWTMTR_F32;
        *Rte_Pim_DampgCmdPwrPrkgStVari() = ZERO_HWNWTMTR_F32;
    }


    /* LimStat_f32 */
    DampgCmdPwrPrkg_HwNwtMtr_T_f32 = Lim_f32(
            DampgCmdPwrPrkg_HwNwtMtr_T_f32,
            DAMPGCMDPWRPRKGLOLIM_HWNWTMTR_F32,
            DAMPGCMDPWRPRKGHILIM_HWNWTMTR_F32);

    /* Write outputs */
    (void) Rte_Write_DampgCmdPwrPrkg_Val(DampgCmdPwrPrkg_HwNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwPwrPrkgDampg_STOP_SEC_CODE
#include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
