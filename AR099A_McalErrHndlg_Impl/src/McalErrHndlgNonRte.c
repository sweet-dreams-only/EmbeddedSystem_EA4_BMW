/***********************************************************************************************************************
* Copyright 2015, 2016, 2017 Nxtr
* Nxtr Confidential
*
* Module File Name  : McalErrHndlgNonRte.c
* Module Description: Implements the non-RTE functionality of AR099A MCAL Error Handling
*                     Includes HndlMcalWrVrfyErr server runnable
* Project           : CBD
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       cz7lt6 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 05/30/17  1        JWJ       Initial Version                                                                EA4#12340
* 08/11/17  2        JWJ       Removed support for CVM startup test failure reporting                         EA4#14485
* 09/09/17  3        KJS       Added sys_regs.h to include list per anomaly EA4#15235                         EA4#15280
***********************************************************************************************************************/

/************************************************ Include Statements **************************************************/
#include "Std_Types.h"
#include "Mcu.h"
#include "Mcu_Reg.h"
#include "Mcu_Cfg.h"
#include "Mcu_PBTypes.h"
#include "Fls_Cfg.h"
#include "Spi_Cfg.h"
#include "Dem.h"
#include "ram_regs.h"
#include "CDD_ExcpnHndlg.h"
#include "Rte_McalErrHndlg.h"
#include "McalErrHndlg.h"
#include "sys_regs.h"


/******************************************** File Level Rule Deviations **********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/********************************************* Embedded Local Constants ***********************************************/
#define NOERR_CNT_U32  0U
#define FLSEINTINCONSISTENT_CNT_U32   ((uint32)(((uint32)(FLS_E_INT_INCONSISTENT)     << 8) | (DEM_EVENT_STATUS_FAILED)))
#define SPIEINTINCONSISTENT_CNT_U32   ((uint32)(((uint32)(SPI_E_INT_INCONSISTENT)     << 8) | (DEM_EVENT_STATUS_FAILED)))
#define FLSECOMPAREFAILED_CNT_U32     ((uint32)(((uint32)(FLS_E_COMPARE_FAILED)       << 8) | (DEM_EVENT_STATUS_FAILED)))
#define FLSEERASEFAILED_CNT_U32       ((uint32)(((uint32)(FLS_E_ERASE_FAILED)         << 8) | (DEM_EVENT_STATUS_FAILED)))
#define FLSEREADFAILED_CNT_U32        ((uint32)(((uint32)(FLS_E_READ_FAILED)          << 8) | (DEM_EVENT_STATUS_FAILED)))
#define FLSEREADFAILEDDED_CNT_U32     ((uint32)(((uint32)(FLS_E_READ_FAILED_DED)      << 8) | (DEM_EVENT_STATUS_FAILED)))
#define FLSEWRITEFAILED_CNT_U32       ((uint32)(((uint32)(FLS_E_WRITE_FAILED)         << 8) | (DEM_EVENT_STATUS_FAILED)))

#define NTCBITSPIINTRPTCONSISTNCFAILR_CNT_U08  1U
#define NTCBITFLASHCOMPFAILED_CNT_U08          1U
#define NTCBITFLASHERASEFAILED_CNT_U08         2U
#define NTCBITFLASHRDFAILED_CNT_U08            4U
#define NTCBITFLASHRDERRDETNFAILED_CNT_U08     8U
#define NTCBITFLASHWRFAILED_CNT_U08            16U



/************************************************ Global Functions ****************************************************/
#define McalErrHndlg_START_SEC_CODE
#include "McalErrHndlg_MemMap.h"

/***********************************************************************************************************************
 * Name        :   HndlMcalWrVrfyErr
 * Description :   Handle an MCAL write-verify error callback.  This callback is used whenever an MCAL component writes
 *                 to a guarded register and reads back a value that is different from that which was written.  This
 *                 is a global function trampoline that redirects the call to the RTE function owned by CM111A.
 * Inputs      :   EventId: DEM event ID indicating failure
 *                 EventStatus: MED failure flag indicating pass/fail.
 * Outputs     :   None
 * Usage Notes :   None
 **********************************************************************************************************************/
FUNC(void, McalErrHndlg_CODE) HndlMcalDemErr(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
	VAR(uint32, AUTOMATIC) ErrCod_Cnt_T_u32;

	/* Pass events through to DEM as expected by MCAL. */
	Dem_ReportErrorStatus(EventId, EventStatus);

	/* Combine the two arguments into a singular error source to assist in determining the correct path for the switch. */
	ErrCod_Cnt_T_u32 = ((uint32)EventId << 8U) | (uint32)EventStatus;

	switch (ErrCod_Cnt_T_u32)
	{
		/* -----[ Critical Responses ]----- */
		case SPIEINTINCONSISTENT_CNT_U32:
			*Rte_Pim_CritErrCod() |= NTCBITSPIINTRPTCONSISTNCFAILR_CNT_U08;
			break;

		/* -----[ Non-critical Responses ]----- */
		case FLSECOMPAREFAILED_CNT_U32:
			*Rte_Pim_NonCritErrCod() |= NTCBITFLASHCOMPFAILED_CNT_U08;
			break;

		case FLSEERASEFAILED_CNT_U32:
			*Rte_Pim_NonCritErrCod() |= NTCBITFLASHERASEFAILED_CNT_U08;
			break;

		case FLSEREADFAILED_CNT_U32:
			*Rte_Pim_NonCritErrCod() |= NTCBITFLASHRDFAILED_CNT_U08;
			break;

		case FLSEREADFAILEDDED_CNT_U32:
			*Rte_Pim_NonCritErrCod() |= NTCBITFLASHRDERRDETNFAILED_CNT_U08;
			break;

		case FLSEWRITEFAILED_CNT_U32:
			*Rte_Pim_NonCritErrCod() |= NTCBITFLASHWRFAILED_CNT_U08;
			break;

		/* -----[ Unexpected Error ]----- */
		default:
			/* Do Nothing */
			break;
	}
}

/***********************************************************************************************************************
 * Name        :   HndlMcalWrVrfyErr
 * Description :   Handle an MCAL write-verify error callback.  This callback is used whenever an MCAL component writes
 *                 to a guarded register and reads back a value that is different from that which was written.  This
 *                 is a global function trampoline that redirects the call to the RTE function owned by CM111A.
 * Inputs      :   WrVrfyErrId: Error ID indicating specific failure.
 *                 ApplProgmIfId: API ID indicating failed module.
 * Outputs     :   None
 * Usage Notes :   None
 **********************************************************************************************************************/
FUNC(void, McalErrHndlg_CODE) HndlMcalWrVrfyErr(Dem_EventIdType WrVrfyErrId, uint8 ApplProgmIfId)
{
	/* Redirect this error to the handler provided by CM111A */
	(void)Rte_Call_MCalReadVrfyFailFltInfo_Oper(ApplProgmIfId, (uint16)WrVrfyErrId);
}

#define McalErrHndlg_STOP_SEC_CODE
#include "McalErrHndlg_MemMap.h"



#define McalErrHndlg_START_SEC_RAMCODE
#include "MemMap.h"

/***********************************************************************************************************************
 * Name        :   Fls_CallSwitchBFlashErrorNotification
 * Description :   Handle a Flash write-verify error callback.  This callback is used whenever the flash component
 *                 writes to a guarded register and reads back a value that is different from that which was written.
 * Inputs      :   None
 * Outputs     :   None - Function does not return.
 * Usage Notes :   This function **MUST** execute out of RAM.  It is called when an error is detected in FLASH and it's
 *                 sole responsibility is to perform a microcontroller reset in an attempt to recover from the problem.
 **********************************************************************************************************************/
FUNC(void, McalErrHndlg_RAMCODE) Fls_CallSwitchBFlashErrorNotification(void)
{
	VAR(uint8, AUTOMATIC) LoopCnt_Cnt_T_u08 = MCU_LOOPCOUNT;

	BRAMDAT0 = MCUDIAGC_CODFLASHEXECENAREGFAILR;

	/* Reset RESF per SAN-808 prior to each SW reset */
	SYSRESFC = 0x00000007U;

	/* Perform the reset by writing to the SWRESA register using the special method provided by the MCU macro. */
	MCU_PROTECTEDWRITERETNONE(MCU_SWRESA, MCU_RES_CORRECT_VAL, MCU_PROT1PHCMD, MCU_PROT1PS, LoopCnt_Cnt_T_u08)

	/* Wait for the reset to occur. */
	while(1)
	{
		/* Do nothing */
	}
}

#define McalErrHndlg_STOP_SEC_RAMCODE
#include "MemMap.h"

