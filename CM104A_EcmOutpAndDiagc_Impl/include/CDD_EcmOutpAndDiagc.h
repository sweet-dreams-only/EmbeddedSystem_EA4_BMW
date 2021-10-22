/**********************************************************************************************************************
* Copyright 2015,2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_EcmOutpAndDiagc.h
* Module Description: Error Control Module Output and Diagnostics Complex Driver Header
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/06/15  1        LWW       Initial Version                                                                 EA4#1847
* 02/05/16	2		 AJM	   Updates for the EI and Pseudo Error Injection start up tests					   EA4#3683
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_ECMOUTPANDDIAGC_H
#define CDD_ECMOUTPANDDIAGC_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 8.8 [NXTRDEV 8.8.1]: Deviation allowed for functions required to be declared in two headers to be accessible via the RTE as well as outside of the RTE 
						  Function Names: CtrlErrOut_Oper */

/************************************************* Type Definitions* *************************************************/
typedef uint8 TrigReg1;

#ifndef TRIGREG_MST
#define         TRIGREG_MST             (85U)	/* 0x55 */
#endif
#ifndef TRIGREG_CHKR
#define         TRIGREG_CHKR            (170U)	/* 0xAA */
#endif
#ifndef TRIGREG_MSTANDCHKR
#define         TRIGREG_MSTANDCHKR      (255U)	/* 0xFF */
#endif

/*********************************************** Exported Declarations ***********************************************/
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE) CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg);
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit1(void);
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit3(void);
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit4(void);

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
