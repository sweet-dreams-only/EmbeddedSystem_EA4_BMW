/***********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name  : McalErrHndlg.h
* Module Description: MCAL Error Handling
* Project           : CBD
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       kzdyfh %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ---------
* 05/30/17  1        JWJ       Created with sine table from NxtrMath.c and function to catch errno            EA4#12340
***********************************************************************************************************************/

/******************************************* Multiple Include Protection **********************************************/
#ifndef MCALERRHNDLG_H
#define MCALERRHNDLG_H


/******************************************** File Level Rule Deviations **********************************************/
/* MISRA-C:2004 Rule 1.1 [NXTRDEV 1.1.1]: Inline functions are used for Nxtr Math library macros to allow for throughput optimization */
/* MISRA-C:2004 Rule 8.5 [NXTRDEV 8.5.1]: Function definitions are required to be in a header for inline function usage */


/*********************************************** Exported Declarations ************************************************/
extern FUNC(void, McalErrHndlg_CODE) HndlMcalDemErr(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
extern FUNC(void, McalErrHndlg_CODE) HndlMcalWrVrfyErr(Dem_EventIdType WrVrfyErrId, uint8 ApplProgmIfId);
extern FUNC(void, McalErrHndlg_RAMCODE) Fls_CallSwitchBFlashErrorNotification(void);


#endif /* MCALERRHNDLG_H */
