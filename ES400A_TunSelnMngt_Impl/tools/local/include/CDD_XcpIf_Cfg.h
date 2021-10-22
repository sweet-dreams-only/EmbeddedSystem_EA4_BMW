/**********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_XcpIf_Cfg.h
* Module Description: Configuration header file for ES104B XCP Interface.
* Project           : CBD
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       cz7lt6 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev     Author  Change Description                                                              SCR #
* --------  ------- ------- ---------------------------------------------------------------------------     ----------
* 05/05/18  1       KJS     Initial version of the configuration header template                             EA4#<TBD>
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_XCPIF_CFG_H
#define CDD_XCPIF_CFG_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/* Include required headers */
#include "Xcp.h"
#include "XcpAppl.h"
#include "Os.h"

/* Headers defined in Configurator */
/* --- None Defined --- */

/******************************************** File Level Rule Deviations *********************************************/

/**************************************************** Type defs ******************************************************/

/************************************************ Embedded Constants *************************************************/
/* XCP Command Error Codes */
#define XCPIF_ERRCMDSYNC_CNT_U08        XCP_ERR_CMD_SYNCH
#define XCPIF_ERRCMDBUSY_CNT_U08        XCP_ERR_CMD_BUSY
#define XCPIF_ERRDAQACTV_CNT_U08        XCP_ERR_DAQ_ACTIVE
#define XCPIF_ERRPRMACTV_CNT_U08        XCP_ERR_PRM_ACTIVE
#define XCPIF_ERRCMDUKWN_CNT_U08        XCP_ERR_CMD_UNKNOWN
#define XCPIF_ERRCMDSYNTAX_CNT_U08      XCP_ERR_CMD_SYNTAX
#define XCPIF_ERROUTOFRNG_CNT_U08       XCP_ERR_OUT_OF_RANGE
#define XCPIF_ERRWRPROTD_CNT_U08        XCP_ERR_WRITE_PROTECTED
#define XCPIF_ERRACSDENIED_CNT_U08      XCP_ERR_ACCESS_DENIED
#define XCPIF_ERRACSLOCKD_CNT_U08       XCP_ERR_ACCESS_LOCKED
#define XCPIF_ERRPAGENOTVLD_CNT_U08     XCP_ERR_PAGE_NOT_VALID
#define XCPIF_ERRPAGEMODNOTVLD_CNT_U08  XCP_ERR_PAGE_MODE_NOT_VALID
#define XCPIF_ERRSEGNOTVLD_CNT_U08      XCP_ERR_SEGMENT_NOT_VALID
#define XCPIF_ERRSEQ_CNT_U08            XCP_ERR_SEQUENCE
#define XCPIF_ERRDATAACQNCFG_CNT_U08    XCP_ERR_DAQ_CONFIG
#define XCPIF_ERRMEMOVF_CNT_U08         XCP_ERR_MEMORY_OVERFLOW
#define XCPIF_ERRGEN_CNT_U08            XCP_ERR_GENERIC
#define XCPIF_ERRVRFY_CNT_U08           XCP_ERR_VERIFY
#define XCPIF_ERRRSRCTMPNOTAVL_CNT_U08  XCP_ERR_RESOURCE_TEMP_NOT_ACCESSIBLE

/* XCP Command Return Codes */
#define XCPIF_RTNCMDSYNC_CNT_U08        XCP_CRC_CMD_SYNCH
#define XCPIF_RTNCMDBUSY_CNT_U08        XCP_CRC_CMD_BUSY
#define XCPIF_RTNDAQACTV_CNT_U08        XCP_CRC_DAQ_ACTIVE
#define XCPIF_RTNPRMACTV_CNT_U08        XCP_CRC_PRM_ACTIVE
#define XCPIF_RTNCMDUKWN_CNT_U08        XCP_CRC_CMD_UNKNOWN
#define XCPIF_RTNCMDSYNTAX_CNT_U08      XCP_CRC_CMD_SYNTAX
#define XCPIF_RTNOUTOFRNG_CNT_U08       XCP_CRC_OUT_OF_RANGE
#define XCPIF_RTNWRPROTD_CNT_U08        XCP_CRC_WRITE_PROTECTED
#define XCPIF_RTNACSDENIED_CNT_U08      XCP_CRC_ACCESS_DENIED
#define XCPIF_RTNACSLOCKD_CNT_U08       XCP_CRC_ACCESS_LOCKED
#define XCPIF_RTNPAGENOTVLD_CNT_U08     XCP_CRC_PAGE_NOT_VALID
#define XCPIF_RTNPAGEMODNOTVLD_CNT_U08  XCP_CRC_PAGE_MODE_NOT_VALID
#define XCPIF_RTNSEGNOTVLD_CNT_U08      XCP_CRC_SEGMENT_NOT_VALID
#define XCPIF_RTNSEQ_CNT_U08            XCP_CRC_SEQUENCE
#define XCPIF_RTNDATAACQNCFG_CNT_U08    XCP_CRC_DAQ_CONFIG
#define XCPIF_RTNMEMOVF_CNT_U08         XCP_CRC_MEMORY_OVERFLOW
#define XCPIF_RTNGEN_CNT_U08            XCP_CRC_GENERIC
#define XCPIF_RTNVRFY_CNT_U08           XCP_CRC_VERIFY
#define XCPIF_RTNRSRCTMPNOTAVL_CNT_U08  XCP_CRC_RESOURCE_TEMP_NOT_ACCESSIBLE

/* XCP Command Return Values */
#define XCPIF_CMDOK_CNT_U08         XCP_CMD_OK
#define XCPIF_CMDPND_CNT_U08        XCP_CMD_PENDING
#define XCPIF_CMDBUSY_CNT_U08       XCP_CMD_BUSY
#define XCPIF_CMDUKWN_CNT_U08       XCP_CMD_UNKNOWN
#define XCPIF_CMDSYNTAX_CNT_U08     XCP_CMD_SYNTAX
#define XCPIF_CMDOUTOFRNG_CNT_U08   XCP_CMD_OUT_OF_RANGE
#define XCPIF_CMDPROTD_CNT_U08      XCP_CMD_PROTECTED
#define XCPIF_CMDDENIED_CNT_U08     XCP_CMD_DENIED
#define XCPIF_CMDERR_CNT_U08        XCP_CMD_ERROR

/* Online Calibrations */
#define XCPIF_FLSPAGE_CNT_U08   0U
#define XCPIF_RAMPAGE_CNT_U08   1U
#define XCPIF_MAXCALSEG_CNT_U08    XCP_MAX_SEGMENT
#define XCPIF_MAXCALPAGE_CNT_U08   XCP_MAX_PAGES

/* XCP Access Modes */
#define XCPIF_ONLINECALNOACS_CNT_U08            0U
#define XCPIF_ONLINECALECUACS_CNT_U08           1U
#define XCPIF_ONLINECALXCPACS_CNT_U08           2U
#define XCPIF_ONLINECALXCPANDECUACS_CNT_U08     3U
#define XCPIF_ONLINECALALLACS_CNT_U08           0x80U /* Not used by the XCP driver, but included to match the XCP protocol spec. */

/* XCP Flash Access */
#define XCPIF_MAXFLSADR_CNT_U32     0x1FFFF

/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_XCPIF_CFG_H */
