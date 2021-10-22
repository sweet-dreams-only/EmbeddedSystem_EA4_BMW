/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : Dem.h
 * Module Description: Dem local header for BmwFltHndlg component
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 11/06/17  1        KByrski   Initial version                                                               EA4#16251
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection **********************************************/
#ifndef DEM_H
#define DEM_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

typedef uint8                                    Dem_IndicatorStatusType;      /*!< Type for warning indicator status */

# define DEM_INDICATOR_OFF                       (0x00U)                       /*!< Warning Indicator: Not requested */

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetIndicatorStatus(
  uint8  IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA)  IndicatorStatus
  );

#endif /* DEM_H */
