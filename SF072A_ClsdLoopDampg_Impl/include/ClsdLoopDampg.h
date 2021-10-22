/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: ClsdLoopDampg.h
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
 * Module File Name  : ClsdLoopDampg.h
 * Module Description: This function produces a handwheel reference torque for the closed loop system.
   This function calculates damping torque based on motor velocity and scaled by
   factors such a rack force estimation. Closed Loop Damping shell be calibrated
   based on vehicle speed, and motor velocity.  End of Travel shall affect the output
   signal command based on the EoT State, EoT Delta Angle and EoT Assist Scale.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		1%
 * %derived_by:    dzvc93%
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

#ifndef RTW_HEADER_ClsdLoopDampg_h_
#define RTW_HEADER_ClsdLoopDampg_h_
#include "Rte_Type.h"
#ifndef ClsdLoopDampg_COMMON_INCLUDES_
# define ClsdLoopDampg_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_ClsdLoopDampg.h"
#include "NxtrFixdPt.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "NxtrIntrpn.h"
#include "NxtrIntrpn_MemMap.h"
#include "NxtrMath.h"
#endif                                 /* ClsdLoopDampg_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "NxtrFixdPt.h"

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
 * '<Root>' : 'ClsdLoopDampg'
 * '<S1>'   : 'ClsdLoopDampg/ClsdLoopDampg'
 * '<S2>'   : 'ClsdLoopDampg/Polyspace Comments'
 * '<S3>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgInit1'
 * '<S4>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1'
 * '<S5>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot'
 * '<S6>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgMotVelRef'
 * '<S7>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgRackFSca'
 * '<S8>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/FloatToFixd_u16_f1'
 * '<S9>'   : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/LimStat_f32'
 * '<S10>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_DISAD'
 * '<S11>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_EXIT'
 * '<S12>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_OTHER'
 * '<S13>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_EXIT/FixdToFloat_f32_u16'
 * '<S14>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_EXIT/FloatToFixd_u16_f32'
 * '<S15>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_EXIT/LnrIntrpn_u16_u16VariXu16VariY'
 * '<S16>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_OTHER/FixdToFloat_f32_u16'
 * '<S17>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_OTHER/FloatToFixd_u16_f32'
 * '<S18>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgEot/EOTST_OTHER/LnrIntrpn_u16_u16VariXu16VariY'
 * '<S19>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgMotVelRef/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
 * '<S20>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgMotVelRef/FixdToFloat_f32_u16'
 * '<S21>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgMotVelRef/FloatToFixd_u16_f32'
 * '<S22>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgRackFSca/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
 * '<S23>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgRackFSca/FixdToFloat_f32_u16'
 * '<S24>'  : 'ClsdLoopDampg/ClsdLoopDampg/ClsdLoopDampgPer1/ClsdLoopDampgRackFSca/FloatToFixd_u16_f32'
 * '<S25>'  : 'ClsdLoopDampg/Polyspace Comments/DocBlock'
 */
#endif                                 /* RTW_HEADER_ClsdLoopDampg_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
