/**********************************************************************************************************************
* Copyright 2015,2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_GuardCfgAndDiagc.h 
* Module Description: Declarations of global functions of CM107A Guard Configuration and Diagnostics RH850
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz63rn %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 10/19/15   1       KMC       Initial Version                                                                EA4#2030
  02/15/16   2       AJM       Added PBG startup test							                              EA4#2754
**********************************************************************************************************************/
#ifndef CDD_GUARDCFGANDDIAGC_H
#define CDD_GUARDCFGANDDIAGC_H

/* Function prototypes */
extern FUNC(void, CDD_GuardCfgAndDiagc_CODE) GuardCfgAndDiagcInit1(void);
extern FUNC(void, CDD_GuardCfgAndDiagc_CODE) IpgInin(void);
extern FUNC(void, CDD_GuardCfgAndDiagc_CODE) GuardCfgAndDiagcInit3(void);
													
#endif
