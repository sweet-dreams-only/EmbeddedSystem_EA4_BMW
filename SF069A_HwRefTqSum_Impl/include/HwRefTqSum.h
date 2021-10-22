/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: HwRefTqSum.h
 *  SW-C Type:HwRefTqSum
 *  C/C++ source code generated on : Wed Mar  7 17:59:46 2018
   Code generated for Simulink model 'HwRefTqSum'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : HwRefTqSum.h
 * Module Description: Handwheel Reference Torque Summation is used to do the sum of reference
   torque generated through effort, return, damping and command overlay.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		1 %
 * %derived_by:      dzvc93 %
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log

   Ver 1.0.1
   Author :Nimmy Mathews
   Date : 21Feb2018
   CR : EA4#20879
   Description : Updated model for Autocoding without any functionality change.

   Ver 1.0.0
   Author :Avani Shah (KPIT)
   Date : 8Dec2017
   CR : EA4#17860
   Description : Initial version from Requirment baseline 1.0
 **********************************************************************************************************************/

#ifndef RTW_HEADER_HwRefTqSum_h_
#define RTW_HEADER_HwRefTqSum_h_
#ifndef HwRefTqSum_COMMON_INCLUDES_
# define HwRefTqSum_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_HwRefTqSum.h"
#include "NxtrMath.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#endif                                 /* HwRefTqSum_COMMON_INCLUDES_ */

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
 * '<Root>' : 'HwRefTqSum'
 * '<S1>'   : 'HwRefTqSum/HwRefTqSum'
 * '<S2>'   : 'HwRefTqSum/Polyspace Comments'
 * '<S3>'   : 'HwRefTqSum/HwRefTqSum/HwRefTqSumInit1'
 * '<S4>'   : 'HwRefTqSum/HwRefTqSum/HwRefTqSumPer1'
 * '<S5>'   : 'HwRefTqSum/HwRefTqSum/HwRefTqSumPer1/LimStat_f32'
 * '<S6>'   : 'HwRefTqSum/Polyspace Comments/DocBlock'
 */
#endif                                 /* RTW_HEADER_HwRefTqSum_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
