/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_NxtrTi_Init.c
* Module Description: Nxtr Time Library Initialization Function
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 02/04/15  1        LWW       Initial Version                                                                 EA4#101
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "tauj_regs.h"
#include "CDD_NxtrTi.h"

/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/
#define CDD_NxtrTi_START_SEC_CODE
#include "CDD_NxtrTi_MemMap.h"

/**********************************************************************************************************************
  * Name:        CDD_NxtrTiInit0
  * Description: Non-RTE version of Nxtr Time Initialization function.  Calling this function will initialize and
  *              start the hardware timers used by this module if not already done.
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called by the user during initialization.  If timers are not required prior to starting the 
  *              RTE, this function does not need to be called directly by a user.
  ********************************************************************************************************************/
FUNC(void, CDD_NxtrTi_CODE) NxtrTiInit0(void)
{
    if ((0U == TAUJ1TE03) && (0U == TAUJ2TE03))
    {
        /* 100uS Timer */
        TAUJ1PRS3 = 0x6U;   			/* TAUJnTPS Register: PCLK/64 */
		TAUJ1BRS = 124U;				/* TAUJnBRS Register: Clock/125 */
        TAUJ1CDR3 = 0xFFFFFFFFU;		/* TAUJnCDRm Register: Set Compare register to maximum register value */
        TAUJ1CMOR3 = 0xC004U;			/* TAUJnCMORm Register: CLK3 is source, Capture mode for up count from zero */

        
        /* 1uS Timer */
        TAUJ2PRS3 = 0x0U;				/* TAUJnTPS Register: PCLK/1 */
		TAUJ2BRS = 79U;					/* TAUJnBRS Register: Clock/80 */
        TAUJ2CDR3 = 0xFFFFFFFFU;		/* TAUJnCDRm Register: Set Compare register to maximum register value */
        TAUJ2CMOR3 = 0xC004U;			/* TAUJnCMORm Register: CLK3 is source, Capture mode for up count from zero */

		
		TAUJ1TS03 = 0x1U;				/* TAUJnTS Register: Start 100uS Timer */
        TAUJ2TS03 = 0x1U;				/* TAUJnTS Register: Start 1uS Timer */
    }
}

#define CDD_NxtrTi_STOP_SEC_CODE
#include "CDD_NxtrTi_MemMap.h"
