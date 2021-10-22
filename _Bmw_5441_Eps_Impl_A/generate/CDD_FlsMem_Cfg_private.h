/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_FlsMem_Cfg_private.h
* Module Description: Private configuration header file for Flah Configuration for CRC calculation component.
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          23 %
* %derived_by:       tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev     Author  Change Description                                                              SCR #
* --------  ------- ------- ---------------------------------------------------------------------------     ----------
* 1/14/16  1       AJM     Initial version of the private header template                                  EA4#3245 
* 3/07/17  2       AJM     Updated to include memory map section                                           EA4#7197
* 4/24/17  3       AJM     Added constant for Application Region CRC Index and Quality Updates             EA4#10797
**********************************************************************************************************************/
/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_FLSMEM_CFG_PRIVATE_H
#define CDD_FLSMEM_CFG_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"
   

/******************************************** File Level Rule Deviations *********************************************/
 /* MISRA-C:2004 Rule 8.12 [NXTRDEV 8.12.1] The ghs compiler requires the [] notation in extern declarations of linker symbols and the size of the
                           sections is unknown when generating the extern declarations.  Code using the symbols is not performing array access
                           so the unknown size is not a functional issue. */
 /* MISRA-C:2004 Rule 8.9  [NXTRDEV 8.9.1] Deviation allowed for use of linker symbols, because the linker symbols are not defined 
                           in any source code file. */
/**************************************************** Type defs ******************************************************/
#define HWCRCRESARYSIZE_CNT_U08		(8U)
#define NROFFLSCRCREGNS_CNT_U08		(3U)

#define APPLCRCREGNNR_CNT_U08		(0U)

#if (APPLCRCREGNNR_CNT_U08 >=  NROFFLSCRCREGNS_CNT_U08)
#error "Undefined CRC Region"
#endif


extern uint8 CCT_Range_01_Start[];
extern uint8 CCT_Range_01_Address[];
extern uint8 CCT_Range_01_Length[];

extern uint8 CCT_Range_02_Start[];
extern uint8 CCT_Range_02_Address[];
extern uint8 CCT_Range_02_Length[];

extern uint8 CCT_Range_03_Start[];
extern uint8 CCT_Range_03_Address[];
extern uint8 CCT_Range_03_Length[];


typedef struct 
{

	/*! \n
	* -# Description: Start Address of the Flash Block for CRC Calculation.
	* -# Units of measure:               N/A
	* -# Limit/range of values:          0-0xFFFFFFFF
	* -# Required Accuracy/Precision:    N/A
	* -# Source/Destination:             
	* -# Type:                           uint32
	* -# Calculation Frequency:          At link time
	*/
	uint32 CrcFlsBlkStrtAdr;
	
	/*! \n
	* -# Description: Length of the Flash Block for CRC Calculation.
	* -# Units of measure:               N/A
	* -# Limit/range of values:          0-0xFFFFFFFF
	* -# Required Accuracy/Precision:    N/A
	* -# Source/Destination:             
	* -# Type:                           uint32
	* -# Calculation Frequency:          At link time
	*/
	uint32 CrcFlsBlkLen;
	
	/*! \n
	* -# Description: Pointer to the Pre calculated CRC saved in flash.
	* -# Units of measure:               N/A
	* -# Limit/range of values:          0-0xFFFFFFFF
	* -# Required Accuracy/Precision:    N/A
	* -# Source/Destination:             
	* -# Type:                           uint32*
	* -# Calculation Frequency:          At link time
	*/
	uint32* PreCalcnCrcFlsAdr;
}FlsCrcCfgBlkRec;


#define CDD_FlsMemNonRte_START_SEC_VAR_INIT_128
#include "CDD_FlsMemNonRte_MemMap.h"

extern VAR(uint32, AUTOMATIC) HwCrcCalcdRes_C[HWCRCRESARYSIZE_CNT_U08];
    
#define CDD_FlsMemNonRte_STOP_SEC_VAR_INIT_128
#include "CDD_FlsMemNonRte_MemMap.h"

extern const FlsCrcCfgBlkRec FlsCfgTbl[NROFFLSCRCREGNS_CNT_U08];

/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/

/**************************************** End Of Multiple Include Protection *****************************************/
#endif/*CDD_FLSMEM_CFG_PRIVATE_H*/
