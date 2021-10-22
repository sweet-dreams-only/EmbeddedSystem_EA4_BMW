/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : FltInj.h
 * Module Description: A stub version of FltInj.h
 * Project           : CBD
 * Author            : Marek Brykczynski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/24/18  1        BrykczyM  Initial version                                                               EA4#20426
 *********************************************************************************************************************/

#ifndef FLTINJ_H
#define FLTINJ_H

#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 8.8 [NXTRDEV 8.8.1]: Deviation allowed for functions required to be declared in two headers to be accessible via the RTE as well as outside of the RTE 
						  Function Names: FltInj_f32_Oper, FltInj_logl_Oper, FltInj_u08_Oper, FltInj_u0p16_Oper */
						  
/* Fault Injection Enable */
/* This is false for production builds.  It is set to true at compile time
   only for s/w special builds with fault injection active. */
#define FLTINJENA								            (STD_OFF)
#define FLTINJ_BMWTQOVRLCDNGANDDRVGDYNFAC_BMWOUTPTQOVRLCMD  (60U)

#endif
