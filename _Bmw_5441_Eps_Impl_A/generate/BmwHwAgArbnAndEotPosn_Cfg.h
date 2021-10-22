/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwHwAgArbnAndEotPosn_Cfg.h
 * Module Description: Configuration Header file for CF071A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 * Generator         : artt 2.0.2.0
 * Generation Time   : 30.07.2018 19:59:40
 **********************************************************************************************************************
 * Version Control:
 * %version:          17 %
 * %derived_by:       tzyksv %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 11/30/17  1        KByrski   Initial version                                                               EA4#17435
 * 01/12/18  2        ML        Deleted multiple Config Params                                                EA4#19235
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef BMWHWAGARBNANDEOTPOSN_CFG_H
#define BMWHWAGARBNANDEOTPOSN_CFG_H

/************************************************ Include Statements *************************************************/
#include "Rte_BmwHwAgArbnAndEotPosn.h"

/****************************************************** Macros *******************************************************/
/* Ntc Handwheel Angle Sensor Not Trim */
#define BMWHWAGARBNANDEOTPOSN_NTCHWAGSNSRNOTTRIM_CNT_ENUM         (NTCNR_0X1E4)
/* Ntc Loss of Pinion Angle Zero Speed */
#define BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIOINAGZEROSPD_CNT_ENUM  (NTCNR_0X0E0)
/* Ntc Loss of Pinion Angle */
#define BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIONAG_CNT_ENUM          (NTCNR_0X0E1)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* BMWHWAGARBNANDEOTPOSN_CFG_H */
