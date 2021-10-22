/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : McuErrInjNonRte_MemMap.h
* Module Description: McuErrInj component DmaWrite and Global MemMap
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 03/09/17	1   	 AJM			Initial version							                                   EA4#6934
* 07/21/17	2   	 AJM			Compiler settings driven #pragma update                                    EA4#13348
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#if defined McuErrInj_START_SEC_VAR_INIT_128
	/* Use GreenHills pragma for ensuring proper memory section allocation for DMA structures that need DMA write access  */
	#pragma ghs section data=".data_dma_128"
    #pragma ghs section sdata=".sdata_dma_128"
	#undef McuErrInj_START_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#elif defined McuErrInj_STOP_SEC_VAR_INIT_128
	/* Use GreenHills pragma to restore default memory section allocation  */
    #pragma ghs section sdata=default
	#pragma ghs section data=default
	#undef McuErrInj_STOP_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#endif


#ifdef McuErrInjGlobalShared_START_SEC_VAR_CLEARED_32
	#pragma ghs section bss=".osGlobalShared_bss"
	#pragma ghs section sbss=".osGlobalShared_sbss"
	#undef McuErrInjGlobalShared_START_SEC_VAR_CLEARED_32
	#undef MEMMAP_ERROR
#endif
#ifdef McuErrInjGlobalShared_STOP_SEC_VAR_CLEARED_32
	#pragma ghs section bss=default
	#pragma ghs section sbss=default
	#undef McuErrInjGlobalShared_STOP_SEC_VAR_CLEARED_32
	#undef MEMMAP_ERROR
#endif


