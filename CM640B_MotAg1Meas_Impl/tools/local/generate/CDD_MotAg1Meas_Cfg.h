/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg1Meas_Cfg.h
 * Module Description: Configuration Header file for CM640A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 * Generator         : artt 2.1.2.0
 * Generation Time   : 15.05.2018 13:00:07
 **********************************************************************************************************************
 * Version Control:
 * %version:          5 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/25/18  1        KByrski   Initial version                                                               EA4#17185,EA4#18362,EA4#22024
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG1MEAS_CFG_H
#define CDD_MOTAG1MEAS_CFG_H

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg1Meas.h"

/****************************************************** Macros *******************************************************/
/* Disables usage of QEP readings. Motor position readings switch to SPI interface */
#define MOTAG1MEAS_DIQEPIF_CNT_LOGL             (FALSE)
/* Motor Angle 1 Protocol Fault NTC Number */
#define MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM (NTCNR_0X085)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_MOTAG1MEAS_CFG_H */
