/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: HwTqTrakgCtrl.c
 *  SW-C Type:HwTqTrakgCtrl
 *  C/C++ source code generated on : Mon May 14 10:12:30 2018
   Code generated for Simulink model 'HwTqTrakgCtrl'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : HwTqTrakgCtrl.c
 * Module Description: This component is used to calculate motor torque command from estimated torsion bar states, handwheel torque command and tracking control gains.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		2%
 * %derived_by:     dzvc93 %
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log

   Ver 2.0.0
   Author :Nimmy Mathews
   Date : 30 Apr2018
   CR : EA4#21437
   Description:
   Added new Input signal"MotTqCmdOvrl" .
   Added new Calibration "HwTqTrakgCtrlMotTqCmdOvrlGain" .
   Updated the datatype of the calibration gains.

   Ver 1.0.1
   Author :Nimmy Mathews
   Date : 2Mar2018
   CR : EA4#20883
   Description:  The model is updated for autocoding without changing the functionality of the design

   Ver 1.0.0
   Author :Dinesh Mankar (KPIT)
   Date : 24Jan2018
   CR : EA4#17583
   Description : Initial version of EA4 Design from Requirment baseline v1.0
 **********************************************************************************************************************/
/*********************File Level Rule Deviations**********************************************************************/

/* MISRA-AGC Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read, Rte_Write */
/* MISRA-AGC Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/* MISRA-AGC Rule 8.1   [NXTRDEV 8.1.1] :  Deviation for autocode only, due to tools limitation.
   �_Init� function does not have a declaration/prototype in autocode. This init function is generated by embedded coder and is not present in the Simulink model.
   This function is always empty and is not called */

/* MISRA-AGC Rule 8.10  [NXTRDEV 8.10.2]:  Deviation for autocode only, due to tools limitation.
   �_Init� function is not defined as �static� even though no external linkage is required. This init function is generated by embedded coder and is not present in the Simulink model.
   This function is always empty and is not called */

/*********************End of File Level Rule Deviations***************************************************************/
#include "HwTqTrakgCtrl.h"
#define HwTqTrakgCtrl_START_SEC_CODE
#include "HwTqTrakgCtrl_MemMap.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef NXTRFIXDPT_FLOATTOP7_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP7_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P12TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P12TOFLOAT_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P1TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P1TOFLOAT_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P7TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P7TOFLOAT_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P8TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P8TOFLOAT_ULS_F32" is not defined
#endif

#ifndef SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32
#error The variable for the parameter "SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32" is not defined
#endif

#ifndef SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32
#error The variable for the parameter "SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32" is not defined
#endif

/* Exported data define */

/* Definition for custom storage class: Const_Local */
#define SYSTQRATMAXVAL_HWNWTMTRPERMOTNWTMTR_F32 ((float32)(50.0F))
#define SYSTQRATMINVAL_HWNWTMTRPERMOTNWTMTR_F32 ((float32)(10.0F))

/* Model step function for TID1 */
FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlInit1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID2 */
FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlPer1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* local block i/o variables */
  float32 rtb_Sum2;
  uint16 rtb_FloatToFixd_u16_f32;
  float32 tmpRead;
  float32 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpWrite;
  TorsBarStEstimdRec1 rtb_TmpSignalConversionAtTorsBa;

  /* Inport: '<Root>/MotTqCmdOvrl' */
  Rte_Read_MotTqCmdOvrl_Val(&tmpRead_2);

  /* Inport: '<Root>/VehSpd' */
  Rte_Read_VehSpd_Val(&tmpRead_1);

  /* Inport: '<Root>/SysTqRat' */
  Rte_Read_SysTqRat_Val(&tmpRead_0);

  /* Inport: '<Root>/HwTqCmd' */
  Rte_Read_HwTqCmd_Val(&tmpRead);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_call_HwTqTrakgCtrlPer1_at_outport_1' incorporates:
   *  SubSystem: '<S1>/HwTqTrakgCtrlPer1'
   */
  /* SignalConversion: '<S4>/TmpSignal ConversionAtTorsBarStEstimdOutport1' incorporates:
   *  Inport: '<Root>/TorsBarStEstimd'
   */
  Rte_Read_TorsBarStEstimd_Rec(&rtb_TmpSignalConversionAtTorsBa);

  /* S-Function (FloatToFixd_u16_f32): '<S16>/FloatToFixd_u16_f32' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_FloatToFixd_u16_f32 = FloatToFixd_u16_f32( (float32)tmpRead_1, (float32)
    ((float32)NXTRFIXDPT_FLOATTOP7_ULS_F32));

  /* Sum: '<S6>/Sum2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S6>/HwTqTrakgCtrlMotTqCmdOvrlGain'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/SysTqRat'
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Product: '<S6>/Product4'
   *  Product: '<S6>/Product5'
   *  Product: '<S6>/Product6'
   *  S-Function (FixdToFloat_f32_s16): '<S10>/FixdToFloat_f32_s16'
   *  S-Function (FixdToFloat_f32_s16): '<S11>/FixdToFloat_f32_s16'
   *  S-Function (FixdToFloat_f32_s16): '<S12>/FixdToFloat_f32_s16'
   *  S-Function (FixdToFloat_f32_s16): '<S13>/FixdToFloat_f32_s16'
   *  S-Function (FixdToFloat_f32_s16): '<S14>/FixdToFloat_f32_s16'
   *  S-Function (FixdToFloat_f32_s16): '<S15>/FixdToFloat_f32_s16'
   *  S-Function (Lim_f32): '<S9>/Lim_f32'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S17>/LnrIntrpn_s16_u16VariXs16VariY'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S18>/LnrIntrpn_s16_u16VariXs16VariY'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S19>/LnrIntrpn_s16_u16VariXs16VariY'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S20>/LnrIntrpn_s16_u16VariXs16VariY'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S21>/LnrIntrpn_s16_u16VariXs16VariY'
   *  S-Function (LnrIntrpn_s16_u16VariXs16VariY): '<S22>/LnrIntrpn_s16_u16VariXs16VariY'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  rtb_Sum2 = (((tmpRead * FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P8TOFLOAT_ULS_F32))) +
               (((((rtb_TmpSignalConversionAtTorsBa.MotVelEstimd *
                    FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P12TOFLOAT_ULS_F32))) +
                   (rtb_TmpSignalConversionAtTorsBa.TorsBarTqEstimd *
                    FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P1TOFLOAT_ULS_F32)))) +
                  (rtb_TmpSignalConversionAtTorsBa.TorsBarRotatmEstimd *
                   FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P7TOFLOAT_ULS_F32)))) +
                 (rtb_TmpSignalConversionAtTorsBa.DrvrTqEstimd *
                  FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P12TOFLOAT_ULS_F32)))) +
                (rtb_TmpSignalConversionAtTorsBa.RackTqEstimd *
                 FixdToFloat_f32_s16( (sint16)((sint16)
    LnrIntrpn_s16_u16VariXs16VariY((const uint16*)
    Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(), (const sint16*)
    Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(),(uint16)4U, rtb_FloatToFixd_u16_f32)),
    (float32)((float32)NXTRFIXDPT_P12TOFLOAT_ULS_F32))))) / Lim_f32( (float32)
    tmpRead_0, (float32)SYSTQRATMINVAL_HWNWTMTRPERMOTNWTMTR_F32, (float32)
    SYSTQRATMAXVAL_HWNWTMTRPERMOTNWTMTR_F32)) + (tmpRead_2 *
    Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val());

  /* S-Function (Lim_f32): '<S8>/Lim_f32' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Outport: '<Root>/MotTqCmdTrakgCtrl'
   */
  tmpWrite = Lim_f32( (float32)rtb_Sum2, (float32)((float32)
    SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32), (float32)((float32)
    SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32));

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_call_HwTqTrakgCtrlPer1_at_outport_1' */

  /* Outport: '<Root>/MotTqCmdTrakgCtrl' */
  (void) Rte_Write_MotTqCmdTrakgCtrl_Val(tmpWrite);
}

/* Model initialize function */
FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrl_Init(void)
{
  /* (no initialization code required) */
}

#define HwTqTrakgCtrl_STOP_SEC_CODE
#include "HwTqTrakgCtrl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */