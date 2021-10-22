/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : RvsBattProtn_Cfg.h
 * Module Description: Configuration Header file for ES252A
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
 * 10/16/17  1        KByrski   Initial version                                                               EA4#14474
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef RVSBATTPROTN_CFG_H
#define RVSBATTPROTN_CFG_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/****************************************************** Macros *******************************************************/
/* Debounce NTC set strategy step towards FAIL status */
#define RVSBATTPROTN_FAILSTEP_CNT_U16             (6552U)
/* Maximum allowed signal level for ground related measures */
#define RVSBATTPROTN_GNDMEASDVLTGHILIMN_VOLT_F32  (1.5F)
/* Minimum allowed signal level for ground related measures */
#define RVSBATTPROTN_GNDMEASDVLTGLOLIMN_VOLT_F32  (1.1F)
/* Debounce NTC set strategy step towards PASS status */
#define RVSBATTPROTN_PASSSTEP_CNT_U16             (3276U)
/* Maximum allowed signal level for battery return related measures */
#define RVSBATTPROTN_RTNMEASDVLTGHILIMN_VOLT_F32  (1.5F)
/* Minimum allowed signal level for battery return related measures */
#define RVSBATTPROTN_RTNMEASDVLTGLOLIMN_VOLT_F32  (0.12F)
/* Threshold level for detection of MOSFET malfunction */
#define RVSBATTPROTN_RVSFLTTHD_VOLT_F32           (0.4F)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* RVSBATTPROTN_CFG_H */
