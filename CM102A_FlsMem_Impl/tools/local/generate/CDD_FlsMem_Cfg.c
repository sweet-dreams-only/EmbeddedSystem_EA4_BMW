/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_FlsMem_Cfg.c
* Module Description: Variable definition for Flash CRC Sections from Configurator .
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev     Author  Change Description                                                              SCR #
* --------  ------- ------- ---------------------------------------------------------------------------     ----------
* 1/14/16  	1       AJM     Initial version of the Config.c template		                                EA4#3245 
* 1/15/16  	2       AJM     Corrected placement of the structure members                                    EA4#3245 
* 3/07/17   3       AJM     Updated to include address symbols                                              EA4#7197
* 4/24/17   4       AJM     Quality Updates                                                                 EA4#10797
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "CDD_FlsMem_Cfg_private.h"

/******************************************** File Level Rule Deviations *********************************************/
 /* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.2]	Cast of a variable address to an integer type required for writing a variable address to a register. */
 /* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Memory pointers to array base types are cast back to their array 
                           type for code readability and to allow use of "sizeof" */
/**************************************************** Type defs ******************************************************/


#define CDD_FlsMem_START_SEC_CODE
#include "CDD_FlsMem_MemMap.h"


const FlsCrcCfgBlkRec FlsCfgTbl[NROFFLSCRCREGNS_CNT_U08] = 
{
	{
		((uint32)CCT_Range_01_Start),
		((uint32)CCT_Range_01_Length),
		((uint32 *)CCT_Range_01_Address),
	}
	,
	{
		((uint32)CCT_Range_02_Start),
		((uint32)CCT_Range_02_Length),
		((uint32 *)CCT_Range_02_Address),
	}
	,
	{
		((uint32)CCT_Range_03_Start),
		((uint32)CCT_Range_03_Length),
		((uint32 *)CCT_Range_03_Address),
	}
	,
	{
		((uint32)CCT_Range_04_Start),
		((uint32)CCT_Range_04_Length),
		((uint32 *)CCT_Range_04_Address),
	}
	,
	{
		(uint32)0x00000000UL,
		(uint32)0x00000064UL,
		(uint32 *)0x000004D2UL,
	}

};

#define CDD_FlsMem_STOP_SEC_CODE
#include "CDD_FlsMem_MemMap.h"


/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/

/**************************************** End Of Multiple Include Protection *****************************************/
