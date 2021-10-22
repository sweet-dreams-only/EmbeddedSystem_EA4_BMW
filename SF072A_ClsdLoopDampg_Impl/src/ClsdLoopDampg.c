/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: ClsdLoopDampg.c
 *  SW-C Type:ClsdLoopDampg
 *  C/C++ source code generated on : Mon Apr 23 17:09:06 2018
   Code generated for Simulink model 'ClsdLoopDampg'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : ClsdLoopDampg.c
 * Module Description: This function produces a handwheel reference torque for the closed loop system.
   This function calculates damping torque based on motor velocity and scaled by
   factors such a rack force estimation. Closed Loop Damping shell be calibrated
   based on vehicle speed, and motor velocity.  End of Travel shall affect the output
   signal command based on the EoT State, EoT Delta Angle and EoT Assist Scale.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		2%
 * %derived_by:     dzvc93%
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log:

   Ver 2.0.0
   Author :Nimmy Mathews
   Date : 20 April 2018
   Change Control #: EA4#20916
   Description : Design updated for autocoding without any functionality change.
   The init value for DampgCmdSca is changed from 0 to 1.

   v1.0.0
   Date: 22 Feb 2018
   Change Control #: EA4#20451
   Author: Patryk Kolacki
   Description:
   - Design Initial Release
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
#include "ClsdLoopDampg.h"
#define ClsdLoopDampg_START_SEC_CODE
#include "ClsdLoopDampg_MemMap.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef NXTRFIXDPT_FLOATTOP10_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP10_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_FLOATTOP1_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP1_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_FLOATTOP6_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP6_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_FLOATTOP7_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_FLOATTOP7_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P12TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P12TOFLOAT_ULS_F32" is not defined
#endif

#ifndef NXTRFIXDPT_P15TOFLOAT_ULS_F32
#error The variable for the parameter "NXTRFIXDPT_P15TOFLOAT_ULS_F32" is not defined
#endif

/* Exported data define */

/* Definition for custom storage class: Const_Local */
#define MAXHWTQCMDDAMPG_HWNWTMTR_F32   ((float32)(10.0F))
#define MINHWTQCMDDAMPG_HWNWTMTR_F32   ((float32)(-10.0F))
#define ONE_ULS_F32                    ((float32)(1.0F))
#define ZERO_HWNWTMTRPERHWRADPERSEC_F32 ((float32)(0.0F))

/* Model step function for TID1 */
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgInit1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID2 */
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgPer1(void) /* Sample time: [0.002s, 0.0s] */
{
  /* local block i/o variables */
  float32 rtb_TmpSignalConversionAtPinion;
  float32 rtb_TmpSignalConversionAtEotDel;
  float32 rtb_Product1;
  float32 rtb_FixdToFloat_f32_u16_k;
  float32 rtb_FixdToFloat_f32_u16_a;
  uint16 rtb_FloatToFixd_u16_f32;
  sint8 rtb_Sign_s08_f32;
  float32 tmpRead;
  float32 tmpRead_0;
  EotSt1 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpWrite;
  float32 rtb_ClsdLoopDampgEot;

  /* Inport: '<Root>/VehSpd' */
  Rte_Read_VehSpd_Val(&rtb_ClsdLoopDampgEot);

  /* Inport: '<Root>/RackFEstimd' */
  Rte_Read_RackFEstimd_Val(&tmpRead_2);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' incorporates:
   *  SubSystem: '<S1>/ClsdLoopDampgPer1'
   */
  /* S-Function (FloatToFixd_u16_f32): '<S8>/FloatToFixd_u16_f32' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_FloatToFixd_u16_f32 = FloatToFixd_u16_f32( (float32)rtb_ClsdLoopDampgEot,
    (float32)((float32)NXTRFIXDPT_FLOATTOP7_ULS_F32));

  /* SignalConversion: '<S4>/TmpSignal ConversionAtPinionVelOutport1' incorporates:
   *  Inport: '<Root>/PinionVell'
   */
  Rte_Read_PinionVel_Val(&rtb_TmpSignalConversionAtPinion);

  /* S-Function (FixdToFloat_f32_u16): '<S20>/FixdToFloat_f32_u16' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  S-Function (Abslt_f32_f32): '<S6>/Abslt_f32_f32'
   *  S-Function (BilnrIntrpnWithRound_u16_u16MplXu16MplY): '<S19>/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
   *  S-Function (FloatToFixd_u16_f32): '<S21>/FloatToFixd_u16_f32'
   */
  rtb_FixdToFloat_f32_u16_k = FixdToFloat_f32_u16( (uint16)((uint16)
    BilnrIntrpnWithRound_u16_u16MplXu16MplY(rtb_FloatToFixd_u16_f32, ((uint16)
    FloatToFixd_u16_f32( (float32)Abslt_f32_f32( (float32)
    rtb_TmpSignalConversionAtPinion), (float32)((float32)
    NXTRFIXDPT_FLOATTOP10_ULS_F32))), (const uint16*)
    Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),(uint16)12U, (const uint16*)
    Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(), (const uint16*)
    Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(),(uint16)9U)), (float32)((float32)
    NXTRFIXDPT_P12TOFLOAT_ULS_F32));

  /* S-Function (Sign_s08_f32): '<S6>/Sign_s08_f32' */
  rtb_Sign_s08_f32 = Sign_s08_f32( (float32)rtb_TmpSignalConversionAtPinion);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtEotDeltaAgOutport1' incorporates:
   *  Inport: '<Root>/EotDeltaAg'
   */
  Rte_Read_EotDeltaAg_Val(&rtb_TmpSignalConversionAtEotDel);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' */

  /* Inport: '<Root>/EotSt' */
  Rte_Read_EotSt_Val(&tmpRead_1);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' incorporates:
   *  SubSystem: '<S1>/ClsdLoopDampgPer1'
   */
  /* SwitchCase: '<S5>/Switch Case' incorporates:
   *  Inport: '<Root>/EotCtrlSca'
   */
  switch (tmpRead_1)
  {
   case EOTST_DISAD:
    /* Outputs for IfAction SubSystem: '<S5>/EOTST_DISAD' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion: '<S10>/OutportBufferForClsdLoopDampgEot' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_ClsdLoopDampgEot = ZERO_HWNWTMTRPERHWRADPERSEC_F32;

    /* End of Outputs for SubSystem: '<S5>/EOTST_DISAD' */
    break;

   case EOTST_EXIT:
    Rte_Read_EotCtrlSca_Val(&tmpRead_0);

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S13>/Constant'
     *  Constant: '<S14>/Constant'
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  S-Function (FixdToFloat_f32_u16): '<S13>/FixdToFloat_f32_u16'
     *  S-Function (FloatToFixd_u16_f32): '<S14>/FloatToFixd_u16_f32'
     *  S-Function (LnrIntrpn_u16_u16VariXu16VariY): '<S15>/LnrIntrpn_u16_u16VariXu16VariY'
     *  Sum: '<S11>/Sum'
     */
    rtb_ClsdLoopDampgEot = FixdToFloat_f32_u16( (uint16)((uint16)
      LnrIntrpn_u16_u16VariXu16VariY((const uint16*)
      Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(), (const uint16*)
      Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(),(uint16)4U, ((uint16)
      FloatToFixd_u16_f32( (float32)rtb_TmpSignalConversionAtEotDel, (float32)
                          ((float32)NXTRFIXDPT_FLOATTOP6_ULS_F32))))), (float32)
      ((float32)NXTRFIXDPT_P15TOFLOAT_ULS_F32)) * (ONE_ULS_F32 - tmpRead_0);

    /* End of Outputs for SubSystem: '<S5>/EOTST_EXIT' */
    break;

   default:
    /* S-Function (FixdToFloat_f32_u16): '<S16>/FixdToFloat_f32_u16' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant1'
     *  S-Function (FloatToFixd_u16_f32): '<S17>/FloatToFixd_u16_f32'
     *  S-Function (LnrIntrpn_u16_u16VariXu16VariY): '<S18>/LnrIntrpn_u16_u16VariXu16VariY'
     */
    rtb_FixdToFloat_f32_u16_a = FixdToFloat_f32_u16( (uint16)((uint16)
      LnrIntrpn_u16_u16VariXu16VariY((const uint16*)
      Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(), (const uint16*)
      Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(),(uint16)4U, ((uint16)
      FloatToFixd_u16_f32( (float32)rtb_TmpSignalConversionAtEotDel, (float32)
                          ((float32)NXTRFIXDPT_FLOATTOP6_ULS_F32))))), (float32)
      ((float32)NXTRFIXDPT_P15TOFLOAT_ULS_F32));

    /* SignalConversion: '<S12>/OutportBufferForClsdLoopDampgEot' */
    rtb_ClsdLoopDampgEot = rtb_FixdToFloat_f32_u16_a;

    /* End of Outputs for SubSystem: '<S5>/EOTST_OTHER' */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' */

  /* Inport: '<Root>/DampgCmdSca' */
  Rte_Read_DampgCmdSca_Val(&tmpRead);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' incorporates:
   *  SubSystem: '<S1>/ClsdLoopDampgPer1'
   */
  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/RackFEstimd'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product2'
   *  Product: '<S6>/Product'
   *  S-Function (Abslt_f32_f32): '<S7>/Abslt_f32_f32'
   *  S-Function (BilnrIntrpnWithRound_u16_u16MplXu16MplY): '<S22>/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
   *  S-Function (FixdToFloat_f32_u16): '<S23>/FixdToFloat_f32_u16'
   *  S-Function (FloatToFixd_u16_f32): '<S24>/FloatToFixd_u16_f32'
   *  Sum: '<S4>/Add'
   */
  rtb_Product1 = (((rtb_FixdToFloat_f32_u16_k * ((float32)rtb_Sign_s08_f32)) *
                   FixdToFloat_f32_u16( (uint16)((uint16)
    BilnrIntrpnWithRound_u16_u16MplXu16MplY(rtb_FloatToFixd_u16_f32, ((uint16)
    FloatToFixd_u16_f32( (float32)Abslt_f32_f32( (float32)tmpRead_2), (float32)
                        ((float32)NXTRFIXDPT_FLOATTOP1_ULS_F32))), (const uint16*)
    Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),(uint16)12U, (const uint16*)
    Rte_Prm_ClsdLoopDampgRackFX_Ary2D(), (const uint16*)
    Rte_Prm_ClsdLoopDampgRackFY_Ary2D(),(uint16)9U)), (float32)((float32)
    NXTRFIXDPT_P15TOFLOAT_ULS_F32))) + (rtb_TmpSignalConversionAtPinion *
    rtb_ClsdLoopDampgEot)) * tmpRead;

  /* S-Function (Lim_f32): '<S9>/Lim_f32' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Outport: '<Root>/HwTqCmdDampg'
   */
  tmpWrite = Lim_f32( (float32)rtb_Product1, (float32)
                     MINHWTQCMDDAMPG_HWNWTMTR_F32, (float32)
                     MAXHWTQCMDDAMPG_HWNWTMTR_F32);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_ClsdLoopDampgPer1_at_outport_1' */

  /* Outport: '<Root>/HwTqCmdDampg' */
  (void) Rte_Write_HwTqCmdDampg_Val(tmpWrite);
}

/* Model initialize function */
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampg_Init(void)
{
  /* (no initialization code required) */
}

#define ClsdLoopDampg_STOP_SEC_CODE
#include "ClsdLoopDampg_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
