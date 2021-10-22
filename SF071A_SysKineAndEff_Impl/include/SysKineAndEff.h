/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: SysKineAndEff.h
 *  SW-C Type:SysKineAndEff
 *  C/C++ source code generated on : Thu Apr 19 10:18:59 2018
   Code generated for Simulink model 'SysKineAndEff'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : SysKineAndEff.h
 * Module Description: In a variable ratio system the kinematic ratio and mechanical efficiency of  the input and motor torque can change as the rack moves.
   This component calculates the Efficiencies and Ratios based on the Rack movement.
 * Project           : CBD
 * Author            : Nimmy M
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		2%
 * %derived_by:     dzvc93 %
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log

   Ver 1.1.0
   Author :Nimmy Mathews
   Date : 17 April 2018
   Change Control #: EA4#22824
   Description : Design updated to add Limiter block to avoid overflow

   Ver 1.0.1
   Author :Vipin David (TataElxsi)
   Date : 24 Mar 2018
   Change Control #: EA4#21991
   Description : Design updated for autocoding without any functionality change.

   Ver 1.0.0
   Author :Dinesh Mankar (KPIT)/ Poonam Chavan (KPIT)
   Date : 20-Mar-2018
   Change Control #: EA4#19300, EA4#19825
   Description : Initial version of EA4 Design from Requirment baseline v2.1
 **********************************************************************************************************************/

#ifndef RTW_HEADER_SysKineAndEff_h_
#define RTW_HEADER_SysKineAndEff_h_
#ifndef SysKineAndEff_COMMON_INCLUDES_
# define SysKineAndEff_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SysKineAndEff.h"
#include "NxtrMath.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrIntrpn_MemMap.h"
#endif                                 /* SysKineAndEff_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "ArchGlbPrm.h"
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
 * '<Root>' : 'SysKineAndEff'
 * '<S1>'   : 'SysKineAndEff/Polyspace Comments'
 * '<S2>'   : 'SysKineAndEff/SysKineAndEff'
 * '<S3>'   : 'SysKineAndEff/Polyspace Comments/DocBlock'
 * '<S4>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffInit1'
 * '<S5>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1'
 * '<S6>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn'
 * '<S7>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1'
 * '<S8>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f16'
 * '<S9>'   : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f17'
 * '<S10>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f18'
 * '<S11>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f19'
 * '<S12>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f20'
 * '<S13>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f21'
 * '<S14>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f22'
 * '<S15>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f23'
 * '<S16>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f24'
 * '<S17>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f25'
 * '<S18>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f26'
 * '<S19>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f27'
 * '<S20>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f28'
 * '<S21>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f29'
 * '<S22>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/LimStat_f9'
 * '<S23>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/FixdToFloat_f32_s1'
 * '<S24>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/FixdToFloat_f32_s16'
 * '<S25>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/FixdToFloat_f32_s32'
 * '<S26>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/FixdToFloat_f32_u3'
 * '<S27>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/FloatToFixd_s16_f32'
 * '<S28>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/LimStat_f9'
 * '<S29>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/LnrIntrpn_s16_s16VariXs16VariY'
 * '<S30>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/LnrIntrpn_s16_s16VariXs16VariY1'
 * '<S31>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRackPosn/LnrIntrpn_u16_s16VariXu16VariY'
 * '<S32>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff'
 * '<S33>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv'
 * '<S34>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/MotToRackFInstsRatCalcn'
 * '<S35>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/PinionTqToRackFInstsRatCalcn'
 * '<S36>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/RackVelCalcn'
 * '<S37>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/SysAssiTqRatCalcn'
 * '<S38>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/SysKineRatCalcn'
 * '<S39>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/SysTqRatCalcn'
 * '<S40>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/FixdToFloat_f32_u1'
 * '<S41>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/FixdToFloat_f32_u2'
 * '<S42>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/FixdToFloat_f32_u3'
 * '<S43>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/FixdToFloat_f32_u4'
 * '<S44>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/FloatToFixd_s16_f32'
 * '<S45>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/LimStat_f4'
 * '<S46>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/LnrIntrpn_u16_s16VariXu16VariY'
 * '<S47>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/LnrIntrpn_u16_s16VariXu16VariY1'
 * '<S48>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/LnrIntrpn_u16_s16VariXu16VariY2'
 * '<S49>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CalcnRatAndEff/LnrIntrpn_u16_s16VariXu16VariY3'
 * '<S50>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv/DataStoreRead'
 * '<S51>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv/DataStoreRead1'
 * '<S52>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv/DataStoreWrite2'
 * '<S53>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv/DataStoreWrite3'
 * '<S54>'  : 'SysKineAndEff/SysKineAndEff/SysKineAndEffPer1/CalcnRatAndEff1/CmplncErrPinionToHwDerivtv/LimStat_f32'
 */
#endif                                 /* RTW_HEADER_SysKineAndEff_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
