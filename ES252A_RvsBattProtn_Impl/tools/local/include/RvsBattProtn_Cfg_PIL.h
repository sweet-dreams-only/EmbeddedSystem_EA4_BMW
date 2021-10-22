/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : RvsBattProtn_Cfg.h
 * Module Description: Configuration Header file for ES252A (PIL version)
 * Project           : CBD
 * Author            : Krzysztof Byrski
 * Generator         : artt 2.1.2.0
 * Generation Time   : 16.10.2017 13:21:34
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 10/17/17  1        KByrski   Initial version                                                               EA4#14474
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef RVSBATTPROTN_CFG_H
#define RVSBATTPROTN_CFG_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/****************************************************** Macros *******************************************************/
/* Debounce NTC set strategy step towards FAIL status */
extern VAR(uint16,  RvsBattProtn_CODE) RVSBATTPROTN_FAILSTEP_CNT_U16;
/* Maximum allowed signal level for ground related measures */
extern VAR(float32, RvsBattProtn_CODE) RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32;
/* Minimum allowed signal level for ground related measures */
extern VAR(float32, RvsBattProtn_CODE) RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32;
/* Debounce NTC set strategy step towards PASS status */
extern VAR(uint16,  RvsBattProtn_CODE) RVSBATTPROTN_PASSSTEP_CNT_U16;
/* Maximum allowed signal level for battery return related measures */
extern VAR(float32, RvsBattProtn_CODE) RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32;
/* Minimum allowed signal level for battery return related measures */
extern VAR(float32, RvsBattProtn_CODE) RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32;
/* Threshold level for detection of MOSFET malfunction */
extern VAR(float32, RvsBattProtn_CODE) RVSBATTPROTN_RVSFLTTHD_VOLT_F32;

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* RVSBATTPROTN_CFG_H */
