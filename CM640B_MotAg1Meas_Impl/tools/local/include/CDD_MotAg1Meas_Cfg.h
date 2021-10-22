/**********************************************************************************************************************
stub file for unit testing
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG1MEAS_CFG_H
#define CDD_MOTAG1MEAS_CFG_H

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg1Meas.h"

/****************************************************** Macros *******************************************************/
/* Disables usage of QEP readings. Motor position readings switch to SPI interface */
extern boolean MOTAG1MEAS_DIQEPIF_CNT_LOGL;
/* Motor Angle 1 Protocol Fault NTC Number */
#define MOTAG1MEAS_MOTAG1PRTCLFLTNTCNR_CNT_ENUM (NTCNR_0X085)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_MOTAG1MEAS_CFG_H */
