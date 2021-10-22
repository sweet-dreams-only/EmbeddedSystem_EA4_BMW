/**********************************************************************************************************************
* Copyright 2015,2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_RamMem.h 
* Module Description: Declarations of global functions of CM103A RAM Memory
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 10/06/15   1       KMC       Initial Version                                                                EA4#1846
* 04/07/16   2       Selva     Updated to V2.1.0 of the FDD design                                            EA4#5097
* 08/20/16   3       AJM       Changed SPI double bit handling from Interrupt to Polling                      EA4#6658
**********************************************************************************************************************/
#ifndef CDD_RAMMEM_H
#define CDD_RAMMEM_H

/* Function prototypes */
extern FUNC(void, CDD_RamMem_CODE) RamMemLclRamSngBitEcc(void);

#endif
