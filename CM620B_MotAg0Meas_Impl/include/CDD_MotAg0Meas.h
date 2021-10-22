/**********************************************************************************************************************
 * Copyright 2016-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg0Meas.h
 * Module Description: CSIH1 peripheral configuration and motor Angle 0 measurement Complex Driver Header
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          3 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial version                                                               EA4#5027
 * 11/22/17  2        AJM       Corrected SPI register configuration for anomaly fix EA4#17707                EA4#17725
 * 04/25/17  3        KByrski   Updated as per Design 5.0.0                                                   EA4#15121,EA4#18232,EA4#22026
 *********************************************************************************************************************/
/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG0MEAS_H
#define CDD_MOTAG0MEAS_H


/************************************************ Include Statements *************************************************/
#include "Std_Types.h"


/********************************************* Embedded Global Constants **********************************************/
#define MOTAG0MEAS_MOTAG0TRSMSTRTININ_CNT_U32      ((uint32)2147811328u)  /* Used in DMA */
#define MOTAG0MEAS_MOTAG0READPTRRST_CNT_U32        (0U)


/*********************************************** Exported Declarations ***********************************************/
extern FUNC (void, CDD_MotAg0Meas_CODE) MotAg0MeasPer1(void);
extern FUNC (void, CDD_MotAg0Meas_CODE) MotAg0CfgLoPwrMod(void);


/**************************************** End Of Multiple Include Protection *****************************************/
#endif

