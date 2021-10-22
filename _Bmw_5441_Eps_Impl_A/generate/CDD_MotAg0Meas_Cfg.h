/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg0Meas_Cfg.h
 * Module Description: Configuration Header file for CM620A
 * Project           : CBD
 * Author            : Krzysztof Byrski
 * Generator         : artt 2.0.2.0
 * Generation Time   : 30.07.2018 19:59:42
 **********************************************************************************************************************
 * Version Control:
 * %version:          18 %
 * %derived_by:       tzyksv %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 10/18/17  1        KByrski   Initial version                                                               EA4#13291
 * 04/25/18  2        KByrski   Added MOTAG0MEAS_DIQEPIF_CNT_LOGL ConfigParam                                 EA4#15121,EA4#18232,EA4#22026
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG0MEAS_CFG_H
#define CDD_MOTAG0MEAS_CFG_H

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg0Meas.h"

/****************************************************** Macros *******************************************************/
/* Disables usage of QEP readings. Motor position readings switch to SPI interface */
#define MOTAG0MEAS_DIQEPIF_CNT_LOGL             (FALSE)
/* Motor Angle 0 Protocol Fault NTC Number */
#define MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM (NTCNR_0X083)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_MOTAG0MEAS_CFG_H */
