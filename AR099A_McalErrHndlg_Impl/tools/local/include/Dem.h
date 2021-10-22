/***********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name   : Dem.h
* Module Description : Dem contract header for McalErrHndlg component
* Project            : CBD
* Author             : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         1 %
* %derived_by:      kzdyfh %
*-----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ----------
* 05/26/17  1        JWJ       Initial version                                                                EA4#
************************************************************************************************************************/

/******************************************* Multiple Include Protection **********************************************/
#ifndef DEM_H
#define DEM_H

#include "Std_Types.h"


/*********************************************** Exported Declarations ************************************************/
#define DEM_EVENT_STATUS_FAILED 1U

typedef uint16 Dem_EventIdType;
typedef uint8 Dem_EventStatusType;

FUNC(void, DEM_CODE) Dem_ReportErrorStatus(Dem_EventIdType, Dem_EventStatusType);



#endif /* DEM_H */