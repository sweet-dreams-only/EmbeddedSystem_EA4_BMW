/*****************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : NxtrDmaRegs.h
* Module Description: Nxtr Direct Memory Access Peripheral Registers
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 05/27/16  1        AJM       Initial version -- defines for bit fields not included in the Renesas headers   EA4#4954
**********************************************************************************************************************/

#ifndef NXTRDMAREGS_H
#define NXTRDMAREGS_H

/**********************************************************************************************************************
* Include files
 *********************************************************************************************************************/
#include "dma_regs.h"

#define DMASSDRQC9 (DMASS.DTFRRQC9.BIT.DRQC)
#define DMASSTCC9 (DMASS.DCSTC9.BIT.TCC)
#define DMASSDTE9 (DMASS.DCEN9.BIT.DTE)
#define DMASSDRQC14 (DMASS.DTFRRQC14.BIT.DRQC)
#define DMASSTCC14 (DMASS.DCSTC14.BIT.TCC)
#define DMASSDTE14 (DMASS.DCEN14.BIT.DTE)
#define DMASSTC15 (DMASS.DCST15.BIT.TC)
#define DMASSTCC15 (DMASS.DCSTC15.BIT.TCC)

#define DMASSDRQC6 (DMASS.DTFRRQC6.BIT.DRQC)
#define DMASSTCC6 (DMASS.DCSTC6.BIT.TCC)
#define DMASSDTE6 (DMASS.DCEN6.BIT.DTE)

#define DMASSDRQC7 (DMASS.DTFRRQC7.BIT.DRQC)
#define DMASSTCC7 (DMASS.DCSTC7.BIT.TCC)
#define DMASSDTE7 (DMASS.DCEN7.BIT.DTE)

#endif
