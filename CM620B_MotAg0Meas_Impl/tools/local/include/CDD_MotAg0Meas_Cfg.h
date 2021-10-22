/**********************************************************************************************************************
Stub file for unit testing
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG0MEAS_CFG_H
#define CDD_MOTAG0MEAS_CFG_H

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg0Meas.h"

/****************************************************** Macros *******************************************************/
/* Disables usage of QEP readings. Motor position readings switch to SPI interface */
extern boolean MOTAG0MEAS_DIQEPIF_CNT_LOGL;
/* Motor Angle 0 Protocol Fault NTC Number */
#define MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM (NTCNR_0X083)

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_MOTAG0MEAS_CFG_H */
