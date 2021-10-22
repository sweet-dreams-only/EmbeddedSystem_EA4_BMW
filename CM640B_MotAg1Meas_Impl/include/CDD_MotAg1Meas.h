/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg1Meas.h
 * Module Description: CSIH3 peripheral configuration and motor Angle 1 measurement Complex Driver Header
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          3 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial version                                                               EA4#5033
 * 11/22/17  2        ML        Updated to change value for MOTAG1MEAS_MOTAG1TRSMSTRTININ_CNT_U32             EA4#17728
 * 04/25/18  3        KByrski   Updated as per Design 5.0.0                                                   EA4#17185,EA4#18362,EA4#22024
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG1MEAS_H
#define CDD_MOTAG1MEAS_H


/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/********************************************* Embedded Global Constants **********************************************/
#define  MOTAG1MEAS_MOTAG1TRSMSTRTININ_CNT_U32      ((uint32)2147811328U)  /* Used in DMA */
#define  MOTAG1MEAS_MOTAG1READPTRRST_CNT_U32        (0U)


/*********************************************** Exported Declarations ***********************************************/
extern FUNC (void, CDD_MotAg1Meas_CODE) MotAg1MeasPer1(void);
extern FUNC (void, CDD_MotAg1Meas_CODE) MotAg1CfgLoPwrMod(void);


/**************************************** End Of Multiple Include Protection *****************************************/
#endif
