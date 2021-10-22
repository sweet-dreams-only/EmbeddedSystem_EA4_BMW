/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: HwTqTrakgCtrl.h
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
 * Module File Name  : HwTqTrakgCtrl.h
 * Module Description: This component is used to calculate motor torque command from estimated torsion bar states, handwheel torque command and tracking control gains.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		2%
 * %derived_by:      dzvc93%
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

#ifndef RTW_HEADER_HwTqTrakgCtrl_h_
#define RTW_HEADER_HwTqTrakgCtrl_h_
#include "Rte_Type.h"
#ifndef HwTqTrakgCtrl_COMMON_INCLUDES_
# define HwTqTrakgCtrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_HwTqTrakgCtrl.h"
#include "NxtrFixdPt.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "NxtrIntrpn.h"
#include "NxtrIntrpn_MemMap.h"
#include "NxtrMath.h"
#endif                                 /* HwTqTrakgCtrl_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "NxtrFixdPt.h"
#include "SysGlbPrm.h"

/* Macros for accessing real-time model data structure */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HwTqTrakgCtrl'
 * '<S1>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl'
 * '<S2>'   : 'HwTqTrakgCtrl/Polyspace Comments'
 * '<S3>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlInit1'
 * '<S4>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1'
 * '<S5>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TorsBarStEstimdStruct'
 * '<S6>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlCmdCalc'
 * '<S7>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain'
 * '<S8>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlCmdCalc/LimOffsRange'
 * '<S9>'   : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlCmdCalc/LimOffsRange1'
 * '<S10>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s1'
 * '<S11>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s16'
 * '<S12>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s2'
 * '<S13>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s3'
 * '<S14>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s4'
 * '<S15>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FixdToFloat_f32_s5'
 * '<S16>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/FloatToFixd_u16_f32'
 * '<S17>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY'
 * '<S18>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY1'
 * '<S19>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY2'
 * '<S20>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY3'
 * '<S21>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY4'
 * '<S22>'  : 'HwTqTrakgCtrl/HwTqTrakgCtrl/HwTqTrakgCtrlPer1/TrakgCtrlGain/LnrIntrpn_s16_u16VariXs16VariY5'
 * '<S23>'  : 'HwTqTrakgCtrl/Polyspace Comments/DocBlock'
 */
#endif                                 /* RTW_HEADER_HwTqTrakgCtrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
