/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotCtrlMgr_Data.h
 * Module Description: Header file for contract folder of CM620B
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          3 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial Version                                                               EA4#5027
 * 10/18/17  2        KByrski   Updated as per Design 2.0.0                                                   EA4#13291
 * 04/25/18  3        KByrski   Updated as per Design 5.0.0                                                   EA4#15121,EA4#18232,EA4#22026
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTCTRLMGR_DATA_H
#define CDD_MOTCTRLMGR_DATA_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

extern VAR(sint32,  AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0Offs;
extern VAR(boolean, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0QepFaild;
extern VAR(uint32,  AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0RawRes[5U];
extern VAR(sint8,   AUTOMATIC) MOTCTRLMGR_MotCtrlMotAgMecl0Polarity;

extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0ErrReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0Mecl;                     /* Actual type is u0p16 */
extern VAR(uint8,  AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0MeclRollgCntr;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0ParFltCnt;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0SpiMecl;                  /* Actual type is u0p16 */
extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0TurnCntrReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0VltgFltCnt;
extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg0WarnReg;
extern VAR(uint16, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAg3Mecl;                     /* Actual type is u0p16 */
extern VAR(uint32, AUTOMATIC) MOTCTRLMGR_MotCtrlMotAgMeasTi;

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
