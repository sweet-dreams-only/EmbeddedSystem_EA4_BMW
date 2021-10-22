/**********************************************************************************************************************
 * Copyright 2016-2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotCtrlMgr_Data.h
 * Module Description: Header file for local folder of CM200B
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          3 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 05/27/16  1        AJM       Initial version                                                               EA4#4954
 * 06/06/16  2        AJM       Updated comment                                                               EA4#6016
 * 08/04/17  3        KByrski   Updated label                                                                 EA4#13614
 *********************************************************************************************************************/

#ifndef CDD_MOTCTRLMGR_DATA_H
#define CDD_MOTCTRLMGR_DATA_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

typedef struct
{
	uint32 DummyVar1;
	uint32 DummyVar2;
	uint32 DummyVar3;
	uint32 DummyVar4;
} MotCtrlFromTwoMilliSecRec1;

typedef struct
{
	uint32 DummyVar1;
	uint32 DummyVar2;
	uint32 DummyVar3;
	uint32 DummyVar4;
} TwoMilliSecToMotCtrlRec1;

typedef struct
{
	uint32 DummyVar1;
	uint32 DummyVar2;
	uint32 DummyVar3;
	uint32 DummyVar4;
} MotCtrlToTwoMilliSecRec1;

typedef struct
{
	uint32 DummyVar1;
	uint32 DummyVar2;
	uint32 DummyVar3;
	uint32 DummyVar4;
} TwoMilliSecFromMotCtrlRec1;

/*********************************************** Exported Declarations ***********************************************/
extern uint32 MOTCTRLMGR_MotCtrlMotAg0RawRes[];
extern uint32 MOTCTRLMGR_MotCtrlMotAg1RawRes[]; 
extern uint32 MOTCTRLMGR_MotCtrlAdc0RawRes[];
extern uint32 MOTCTRLMGR_MotCtrlTSG31DCMP0E;
extern uint32 MOTCTRLMGR_MotCtrlTSG31CMPWE;
extern TwoMilliSecToMotCtrlRec1 MotCtrlMgr_TwoMilliSecToMotCtrl_Rec;
extern MotCtrlFromTwoMilliSecRec1 MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec;
extern uint32 MOTCTRLMGR_MotCtrlAdc1RawRes[];
extern MotCtrlToTwoMilliSecRec1 MotCtrlMgr_MotCtrlToTwoMilliSec_Rec;
extern TwoMilliSecFromMotCtrlRec1 MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec;

#endif /* CDD_MOTCTRLMGR_DATA_H */
