/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File: Effort.h
 *  SW-C Type:Effort
 *  C/C++ source code generated on : Tue May 22 11:55:58 2018
   Code generated for Simulink model 'Effort'.
 ***********************************************************************************************************************
   Tool Information
 *-----------------------------------------------------------------------------------------------------------------------
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 **********************************************************************************************************************
 * Copyright '2018' Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : Effort.h
 * Module Description: This function produces a handwheel reference torque for the closed loop system.
 * Project           : CBD
 * Author            : Nimmy Mathews
 ***********************************************************************************************************************
 * Version Control:
 * %version:  		3 %
 * %derived_by:      dzvc93 %
 **********************************************************************************************************************
 * CHANGE LOG COPIED FROM SIMULINK MODEL
 *---------------------------------------
 * Change Log:

   v2.1.0
   Date: 21 May 2018
   Change Control #: EA4#24062
   Author: Nimmy Mathews
   Description:
   -Added Polarity Correction to change the polarity of
   the output HwTqCmdEffort


   v2.0.0
   Date: 30 Apr 2018
   Change Control #: EA4#22637
   Author: Nimmy Mathews
   Description:
   - Added new input EffortCmdSca
   - Added blending between EffortCmdSca and a constant value

   v1.0.1
   Date: 19 Feb 2018
   Change Control #: EA4#20871
   Author: Nimmy Mathews
   Description:
   - Design updated for autocoding without any functionality change.

   v1.0.0
   Date: 29 Nov 2017
 **********************************************************************************************************************/

#ifndef RTW_HEADER_Effort_h_
#define RTW_HEADER_Effort_h_
#ifndef Effort_COMMON_INCLUDES_
# define Effort_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_Effort.h"
#include "NxtrMath.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrIntrpn_MemMap.h"
#endif                                 /* Effort_COMMON_INCLUDES_ */

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
 * '<Root>' : 'Effort'
 * '<S1>'   : 'Effort/Effort'
 * '<S2>'   : 'Effort/Polyspace Comments'
 * '<S3>'   : 'Effort/Effort/EffortInit1'
 * '<S4>'   : 'Effort/Effort/EffortPer1'
 * '<S5>'   : 'Effort/Effort/EffortPer1/EffortSca'
 * '<S6>'   : 'Effort/Effort/EffortPer1/LimStat_f32'
 * '<S7>'   : 'Effort/Effort/EffortPer1/RackFEffort'
 * '<S8>'   : 'Effort/Effort/EffortPer1/EffortSca/FixdToFloat_f32_u16'
 * '<S9>'   : 'Effort/Effort/EffortPer1/EffortSca/FloatToFixd_s16_f32'
 * '<S10>'  : 'Effort/Effort/EffortPer1/EffortSca/LnrIntrpn_u16_s16VariXu16VariY'
 * '<S11>'  : 'Effort/Effort/EffortPer1/RackFEffort/BilnrIntrpnWithRound_u16_u16MplXu16MplY'
 * '<S12>'  : 'Effort/Effort/EffortPer1/RackFEffort/FixdToFloat_f32_u16'
 * '<S13>'  : 'Effort/Effort/EffortPer1/RackFEffort/FloatToFixd_u16_f1'
 * '<S14>'  : 'Effort/Effort/EffortPer1/RackFEffort/FloatToFixd_u16_f32'
 * '<S15>'  : 'Effort/Polyspace Comments/DocBlock'
 */
#endif                                 /* RTW_HEADER_Effort_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
