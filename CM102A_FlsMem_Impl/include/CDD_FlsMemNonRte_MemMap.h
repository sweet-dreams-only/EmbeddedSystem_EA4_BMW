/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_FlsMemNonRte_MemMap.h
* Module Description: FlsMem component DmaWrite MemMap
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/12/16  1        AJM       Initial version                                                                 EA4#8359
* 05/17/17  2        LWW       Added mapping of sdata for compiler setting compatibility                       EA4#11988
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define MEMMAP_ERROR

#if defined CDD_FlsMemNonRte_START_SEC_VAR_INIT_128
	/* Use GreenHills pragma for ensuring proper memory section allocation for DMA structures that need DMA write access  */
	#pragma ghs section data=".data_dma_128"
	#pragma ghs section sdata=".sdata_dma_128"
	#undef CDD_FlsMemNonRte_START_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#elif defined CDD_FlsMemNonRte_STOP_SEC_VAR_INIT_128
	/* Use GreenHills pragma to restore default memory section allocation  */
	#pragma ghs section sdata=default
	#pragma ghs section data=default
	#undef CDD_FlsMemNonRte_STOP_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#endif

#ifdef MEMMAP_ERROR
	#error "CDD_FlsMemNonRte_MemMap.h, wrong pragma command"
#endif

