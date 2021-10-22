/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_BattRtnCurr_MotCtrl.c
 * Module Description: Implementation of Battery or Switched Battery Voltage Arbitration FDD ES251A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 07/21/17  1        KByrski   Initial version                                                               EA4#13927
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_BattRtnCurr.h"
#include "CDD_BattRtnCurr.h"
#include "CDD_BattRtnCurr_Cfg.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#define CDD_BattRtnCurr_MotCtrl_START_SEC_CODE
#include "CDD_BattRtnCurr_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        BattRtnCurrPer1
 * Description: Battery Return Current measurement periodic execution carried out inside motor control loop
 * Inputs:      MotCtrlBattRtnCurrAdc
 * Outputs:     MotCtrlBattRtnCurrAmprFastLoop
 * Usage Notes: Called by Motor control ISR (Call rate 2 * MtrCtrlISR)
 *********************************************************************************************************************/
FUNC(void, CDD_BattRtnCurr_APPL_CODE) BattRtnCurrPer1(void)
{
#if (BATTRTNCURR_FASTLOOPPROC_CNT_LOGL == TRUE)

    VAR(float32, AUTOMATIC) BattCurrVolts_Volt_T_f32;
    VAR(float32, AUTOMATIC) BattCurrAmpr_Ampr_T_f32;

    /* Read inputs */
    BattCurrVolts_Volt_T_f32 = MOTCTRLMGR_MotCtrlBattRtnCurrAdc;

    /* SampleCnv */
    BattCurrAmpr_Ampr_T_f32 = (BattCurrVolts_Volt_T_f32 - BATTRTNCURR_OFFSET_VOLT_F32) * BATTRTNCURR_GAIN_AMPRPERVOLT_F32;
    BattCurrAmpr_Ampr_T_f32 = Lim_f32(BattCurrAmpr_Ampr_T_f32, BATTRTNCURR_OUTPMIN_AMPR_F32, BATTRTNCURR_OUTPMAX_AMPR_F32);

    /* Write outputs */
    MOTCTRLMGR_MotCtrlBattRtnCurrAmprFastLoop = BattCurrAmpr_Ampr_T_f32;

#endif
}

#define CDD_BattRtnCurr_MotCtrl_STOP_SEC_CODE
#include "CDD_BattRtnCurr_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
