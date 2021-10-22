/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotCtrlMgr_Data.h
 * Module Description: Header file for contract folder of CM640B
 * Project           : CBD
 * Author            : Brendon Binder
 **********************************************************************************************************************
 * Version Control:
 * %version:          3 %
 * %derived_by:       rzk04c %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 05/15/17  1        BRB       Initial Version                                                               EA4#8338
 * 04/25/18  2        KByrski   Updated as per Design 5.0.0                                                   EA4#17185,EA4#18362,EA4#22024
 * 05/04/18  3        AJM       Removed motor control signals MotCtrlMotAg1Offs & MotCtrlMotAgMecl1Polarity   EA4#23197
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTCTRLMGR_DATA_H
#define CDD_MOTCTRLMGR_DATA_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

extern VAR(boolean, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1QepFaild;
extern VAR(uint32,  AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1RawRes[5U];

extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1ErrReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1Mecl;                     /* Actual type is u0p16 */
extern VAR(uint8,  AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1MeclRollgCntr;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1ParFltCnt;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1SpiMecl;                  /* Actual type is u0p16 */
extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1TurnCntrReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1VltgFltCnt;
extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg1WarnReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg4Mecl;                     /* Actual type is u0p16 */

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
