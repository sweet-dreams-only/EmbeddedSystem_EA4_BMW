/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_McuCoreCfgAndDiagc.h
* Module Description: Mcu Core Configuration and Diagnostics Complex Driver Header
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/11/15  1        LWW       Initial Version                                                                 EA4#1848
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MCUCORECFGANDDIAGC_H
#define CDD_MCUCORECFGANDDIAGC_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/

/*********************************************** Exported Declarations ***********************************************/
extern FUNC(void, CDD_McuCoreCfgAndDiagc_CODE) McuCoreCfgAndDiagcInit1(void);
extern FUNC(void, CDD_McuCoreCfgAndDiagc_CODE) McuCoreCfgAndDiagcInit2(void);

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
