/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_BattRtnCurr_Cfg.h
 * Module Description: Configuration Header file for ES251A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 08/01/17  1        KByrski   Initial version                                                               EA4#13927
 * 10/11/17  2        KByrski   Updated as per Design version 1.1.0                                           EA4#16024
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_BATTRTNCURR_CFG_H
#define CDD_BATTRTNCURR_CFG_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/****************************************************** Macros *******************************************************/
/* Battery Return Current Estimated Current Difference Threshold */
#define BATTRTNCURR_CURRESTIMDIFTHD_AMPR_F32 (10.0F)
/* Battery Return Current Fail Step */
#define BATTRTNCURR_FAILSTEP_CNT_U16         (3276U)
/* Battery Return Current Pass Step */
#define BATTRTNCURR_PASSSTEP_CNT_U16         (1638U)
/* Battery Return Current Fast Loop Process */
#define BATTRTNCURR_FASTLOOPPROC_CNT_LOGL    (TRUE)
/* Battery Return Current Filter Cutoff Frequency */
#define BATTRTNCURR_FILCUTFREQ_HZ_F32        (10.0F)
/* Battery Return Current Gain */
#define BATTRTNCURR_GAIN_AMPRPERVOLT_F32     (100.0F)
/* Battery Return Current Lower Threshold */
#define BATTRTNCURR_LOWRTHD_AMPR_F32         (-200.0F)
/* Battery Return Current Offset */
#define BATTRTNCURR_OFFSET_VOLT_F32          (2.5F)
/* Battery Return Current Output Max */
#define BATTRTNCURR_OUTPMAX_AMPR_F32         (200.0F)
/* Battery Return Current Output Min */
#define BATTRTNCURR_OUTPMIN_AMPR_F32         (-200.0F)
/* Battery Return Current Upper Threshold */
#define BATTRTNCURR_UPPRTHD_AMPR_F32         (200.0F)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_BATTRTNCURR_CFG_H */
