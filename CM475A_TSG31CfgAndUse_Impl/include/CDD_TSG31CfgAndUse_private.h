/*****************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_TSG31CfgAndUse_private.h
* Module Description: Private header file for the CDD_TSG31CfgAndUse component
* Project           : CBD   
* Author            : Kathleen Creager
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz63rn %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/20/15	1   	 KMC			initial version							                                    EA4#337
* 06/20/15  2        KMC            remove CnvNanoSecToHalfTmrCnt() function and add masking constant	    	EA4#865 
*                                   for changes per FDD 1.3.0				
******************************************************************************/
/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_TSG31CFGANDUSE_PRIVATE_H
#define CDD_TSG31CFGANDUSE_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"
#include "ElecGlbPrm.h"

#define ROUNDGTERM_CNT_U13P19 		((uint32)262144u) /* 2 raised to power 18 in counts = 0.5 U13P19 */
#define PWMTMRPERDIVSSCAG_CNT_U16	((uint16)19u)  /* PWMTMRPERDIVS Scaling Factor for timer count scaling */
#define CLRBIT0MASK_CNT_U32			((uint32)0xFFFFFFFEU) 
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 1.1  [NXTRDEV 1.1.2]: Inline functions are used for functions called from Motor Control ISR to allow for throughput optimization */
/* MISRA-C:2004 Rule 8.5 [NXTRDEV 8.5.1]: Function definitions are required to be in a header for inline function usage */


/*********************************************** Exported Declarations ***********************************************/

INLINE FUNC (uint32, TSG31CfgAndUse_APPL_CODE) CnvNanoSecToTmrCnt (uint32 Ti_NanoSec_T_u32);

/******************************************************************************
  * Name:        CnvNanoSecToTmrCnt
  * Description: Converts a time in nanoseconds to timer counts
  * Inputs:      Ti_NanoSec_T_u32 :- time to be converted, in nanoseconds 
  * Outputs:     Returns timer counts as a uint32 (p0) 
  * Usage Notes: Per FDD assumptions in model comments, input range is 0 to 100000
  ****************************************************************************/
INLINE FUNC (uint32, TSG31CfgAndUse_APPL_CODE) CnvNanoSecToTmrCnt (uint32 Ti_NanoSec_T_u32)
{
	VAR (uint32, AUTOMATIC) Tmr_Cnt_T_u32;
	VAR (uint32, AUTOMATIC) Ti_Cnt_T_u13p19;

	Ti_Cnt_T_u13p19 = Ti_NanoSec_T_u32 * ELECGLBPRM_PWMTMRPERDIVS_CNTPERNANOSEC_U13P19;
	Ti_Cnt_T_u13p19 += ROUNDGTERM_CNT_U13P19;
	Tmr_Cnt_T_u32 = (Ti_Cnt_T_u13p19 >> PWMTMRPERDIVSSCAG_CNT_U16);
	return Tmr_Cnt_T_u32;
}

/**************************************** End Of Multiple Include Protection *****************************************/
#endif

