
/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_MotCtrlMgr_Data.c
* Module Description: Motor Control Manager Data
* Project           : CBD
* Author            : Lucas Wendling
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:51
***********************************************************************************************************************
* Version Control:
* %version:          26 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/05/15  1        LWW       Initial Version                                                                 EA4#511
* 10/29/15  2        LWW       Template update for signal mapping changes and memory map change                EA4#3428
* 08/08/16  3        LWW       Template update for compatibility with MotCtrlMgr Configuration Tool            EA4#6787
**********************************************************************************************************************/
/************************************************ Include Statements *************************************************/
#include "CDD_MotCtrlMgr_Data.h"
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/************************************************** Global Signals ***************************************************/

#define CDD_MotCtrlMgr_DmaWrite_START_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

VAR(MotCtrlToTwoMilliSecRec1, CDD_MotCtrlMgr_VAR_INIT) MotCtrlMgr_MotCtrlToTwoMilliSec_Rec = 
{
	{0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}, 
	0U, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0, 
	{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 
	0.0F, 
	0.0F, 
	{0U, 62U, 125U, 187U, 250U, 312U, 375U, 437U}, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	{0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	FALSE, 
	0U, 
	0U, 
	0U, 
	{0U,0U,0U,0U,0U}
};

#define CDD_MotCtrlMgr_DmaWrite_STOP_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"


#define CDD_MotCtrlMgr_DmaWrite_START_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

VAR(TwoMilliSecFromMotCtrlRec1, CDD_MotCtrlMgr_VAR_INIT) MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec = 
{
	{0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}, 
	0U, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	0U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0, 
	{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 
	0.0F, 
	0.0F, 
	{0U, 62U, 125U, 187U, 250U, 312U, 375U, 437U}, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	{0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	0U, 
	FALSE, 
	0U, 
	0U, 
	0U, 
	{0U,0U,0U,0U,0U}
};

#define CDD_MotCtrlMgr_DmaWrite_STOP_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

#define CDD_MotCtrlMgr_START_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

VAR(TwoMilliSecToMotCtrlRec1, CDD_MotCtrlMgr_VAR_INIT) MotCtrlMgr_TwoMilliSecToMotCtrl_Rec = 
{
	0.0F, 
	0.0F, 
	25.0F, 
	6.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	8412.0F, 
	8412.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.005F, 
	0.0F, 
	0.0F, 
	0U, 
	IVTRFETFLTTYP_NOFETFLT, 
	FALSE, 
	SYSST_WRMININ, 
	MCECS_OFFSCMDSTRT, 
	FALSE, 
	FALSE, 
	FALSE, 
	21U, 
	FALSE, 
	23U, 
	1, 
	IVTRFETFLTPHA_NOPHASNGFETFLT, 
	63U, 
	SIGQLFR_NORES, 
	FALSE, 
	PHADISCNCTPWMVECT_NOCMD, 
	0U, 
	FALSE, 
	FALSE, 
	{0U,0U,0U}
};

#define CDD_MotCtrlMgr_STOP_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

#define CDD_MotCtrlMgr_DmaWrite_START_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

VAR(MotCtrlFromTwoMilliSecRec1, CDD_MotCtrlMgr_VAR_INIT) MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec = 
{
	0.0F, 
	0.0F, 
	25.0F, 
	6.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	8412.0F, 
	8412.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.005F, 
	0.0F, 
	0.0F, 
	0U, 
	IVTRFETFLTTYP_NOFETFLT, 
	FALSE, 
	SYSST_WRMININ, 
	MCECS_OFFSCMDSTRT, 
	FALSE, 
	FALSE, 
	FALSE, 
	21U, 
	FALSE, 
	23U, 
	1, 
	IVTRFETFLTPHA_NOPHASNGFETFLT, 
	63U, 
	SIGQLFR_NORES, 
	FALSE, 
	PHADISCNCTPWMVECT_NOCMD, 
	0U, 
	FALSE, 
	FALSE, 
	{0U,0U,0U}
};

#define CDD_MotCtrlMgr_DmaWrite_STOP_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

#define CDD_MotCtrlMgr_DmaWrite_START_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

VAR(MotCtrlIntRec1, CDD_MotCtrlMgr_VAR_INIT) MotCtrlMgr_MotCtrlInt_Rec = 
{
	{0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}, 
	3964U, 
	4444U, 
	4364U, 
	4444U, 
	4444U, 
	4444U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	62500U, 
	{0U, 0U, 0U, 0U, 0U}, 
	0U, 
	0.0F, 
	0.0F, 
	{0U, 0U, 0U, 0U, 0U}, 
	0U, 
	0U, 
	0U, 
	0U, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0.0F, 
	0U, 
	0U, 
	0U, 
	FALSE, 
	0U, 
	MFGENAST_PRDNMOD, 
	FALSE, 
	SIGQLFR_NORES, 
	0U, 
	{0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}
};

#define CDD_MotCtrlMgr_DmaWrite_STOP_SEC_VAR_INIT_128
#include "MotCtrlMgr_MemMap.h"

