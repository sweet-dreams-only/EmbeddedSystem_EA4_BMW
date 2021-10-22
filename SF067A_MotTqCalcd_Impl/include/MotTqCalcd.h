/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: MotTqCalcd.h
 *  SW-C Type:MotTqCalcd
 *  C/C++ source code generated on : Tue Mar 20 14:25:55 2018
   Code generated for Simulink model 'MotTqCalcd'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : MotTqCalcd.h
 * Module Description: This component calculates motor torque estimate from measured Motor Currents or reference Motor Currents based on the Motor Control And Thermal Protection LOA Mode
 * Project           : CBD
 * Author            : vipin.d
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		1 %
 * %derived_by:    dzvc93 %
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log

   Ver 1.0.1
   Author :Vipin David (TataElxsi)
   Date : 14 Mar 2018
   Change Control:EA4#21805
   Description : Design updated for autocoding without any functionality change.


   Ver 1.0.0
   Author :Mansi Geet (KPIT)
   Date : 02 Feb 2018
   Change Control #:EA4#16544, EA4#17869
   Description : Initial version from Requirment baseline 1.1



 **********************************************************************************************************************/

#ifndef RTW_HEADER_MotTqCalcd_h_
#define RTW_HEADER_MotTqCalcd_h_
#ifndef MotTqCalcd_COMMON_INCLUDES_
# define MotTqCalcd_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_MotTqCalcd.h"
#include "NxtrMath.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#endif                                 /* MotTqCalcd_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "ArchGlbPrm.h"
#include "Platform_Types.h"

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
 * '<Root>' : 'MotTqCalcd'
 * '<S1>'   : 'MotTqCalcd/MotTqCalcd'
 * '<S2>'   : 'MotTqCalcd/Polyspace Comments'
 * '<S3>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdInit1'
 * '<S4>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdPer1'
 * '<S5>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdPer1/BitDecod'
 * '<S6>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdPer1/LimStat_f32'
 * '<S7>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdPer1/MotTqEstimdCalcnWithCmdInp'
 * '<S8>'   : 'MotTqCalcd/MotTqCalcd/MotTqCalcdPer1/MotTqEstimdCalcnWithMeasdInp'
 * '<S9>'   : 'MotTqCalcd/Polyspace Comments/DocBlock'
 */
#endif                                 /* RTW_HEADER_MotTqCalcd_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
