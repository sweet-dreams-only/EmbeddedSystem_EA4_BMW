/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   TrustdFctDefn.h
* Module Description: Provides visibility to BswM for various function calls. 
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          6 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17   1       KJS       Initial Version                                                                EA4#14844
* 09/26/17   2       KJS       Added more header files from integrated components. TODOs were added as 
*                              place holders while the remaining components are being integrated.             EA4#14844
* 05/18/18   3       AR        XcpAppl.h removed. Xcp.h added                                                 EA4#23339
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef TRUSTDFCTDEFN_H
#define TRUSTDFCTDEFN_H

/************************************************ Include Statements *************************************************/
#include "Fls.h"
#include "CDD_DmaCfgAndUse.h"
#include "CDD_GuardCfgAndDiagc.h"
// <KJS> Remove comment after component is integrated #include "CDD_VrfyCritReg.h"
#include "CDD_FlsMem.h"
#include "CDD_Bmw5441McuCfg_Stub.h"
#include "Spi.h"
#include "Xcp.h"
#include "NxtrWdgM.h"


/******************************************** File Level Rule Deviations *********************************************/

/**************************************************** Type defs ******************************************************/

/************************************************ Embedded Constants *************************************************/

/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/
/* Provide visibility to NvM_MainFunction to OS for trusted function without visibility to all NvM APIs */
extern void NvM_MainFunction(void);

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* TRUSTDFCTDEFN_H */
