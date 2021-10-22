/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : Dcm.h
 * Module Description: DCM Stub
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 03/27/18  1        KByrski   Initial version                                                               EA4#21983
 *********************************************************************************************************************/

#ifndef DCM_H
#define DCM_H

#include "Std_Types.h"

#define DCM_DEFAULT_SESSION (1U)
#define DCM_GarageMode (95U)

typedef uint8 Dcm_SesCtrlType;

FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType);

#endif /* DCM_H */
