/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_FlsMem.h
* Module Description: Flash Memory Complex Driver Header
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/05/15  1        LWW       Initial Version                                                                 EA4#1830
* 01/11/16  2        AJM       Changes for Flash CRC Region check					       					   EA4#3245 
* 03/31/16  3	     AJM       Removed Code Flash Single Bit ECC error handler 								   EA4#4960
* 04/18/16  4	     AJM       Added Trusted function to clean up the DTS registers 						   EA4#5403
* 08/20/16  5	     AJM       Added ISR handler for single bit ECC error			 						   EA4#6660
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_FLSMEM_H
#define CDD_FLSMEM_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/******************************************** File Level Rule Deviations *********************************************/

/*********************************************** Exported Declarations ***********************************************/
extern FUNC(void, CDD_FlsMem_CODE) DtsInin(uint32 CrcHwIdxInReg, uint32 CrcHwIdxOutReg) ;
extern FUNC(void, CDD_FlsMem_CODE) DtsClnUp(void);

extern FUNC(void, CDD_FlsMem_CODE) FlsMemInit2(void) ;
extern FUNC(void, CDD_FlsMem_CODE) CodFlsSngBitEcc(void) ;

/**************************************** End Of Multiple Include Protection *****************************************/
#endif
