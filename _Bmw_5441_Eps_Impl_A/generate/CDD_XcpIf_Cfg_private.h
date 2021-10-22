/**********************************************************************************************************************
* Copyright 2017, 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_XcpIf_Cfg_private.h
* Module Description: Private configuration header file for ES104B XCP Interface.
* Project           : CBD
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          15 %
* %derived_by:       tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev     Author  Change Description                                                              SCR #
* --------  ------- ------- ---------------------------------------------------------------------------     ----------
* 10/30/17  1       KJS     Initial version of the private header template                                  EA4#17610
* 05/05/18  2       KJS     Moved non-private values to CDD_XcpIf_Cfg.h                                     EA4#23861
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_XCPIF_CFG_PRIVATE_H
#define CDD_XCPIF_CFG_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

/* Include required headers */
#include "CDD_XcpIf_Cfg.h"

/******************************************** File Level Rule Deviations *********************************************/

/**************************************************** Type defs ******************************************************/

/************************************************ Embedded Constants *************************************************/

/* XCP Control */
#define XCPIF_XCPCTRLDI_CNT_U08     kXcp_Control_Disable
#define XCPIF_XCPCTRLENA_CNT_U08    kXcp_Control_Enable

/* XCP User Functions */
#define XCPIF_RESPBUF_CNT_U08(x)    Xcp_ChannelInfo[0].ResponseFrame.b[x]
#define XCPIF_RESPBUFLEN_CNT_U08    Xcp_ChannelInfo[0].ResponseFrameLength

/* Read and Write Trap Protection */
#if !defined ( XCP_PREVENT_SRC_READ_TRAP )
    #define XCPIF_PREVENT_SRC_READ_TRAP STD_ON
#endif
#if !defined ( XCP_PREVENT_DST_WRITE_TRAP )
    #define XCPIF_PREVENT_DST_WRITE_TRAP STD_ON
#endif

/* Nxtr Definied XCP Services */
#define GETSEGINFO_CNT_U08          0xE8U
#define GETPAGEPROCRINFO_CNT_U08    0xE9U
#define APPLXCPUSRSRV_CNT_U08       0xF1U
#define ACTVTUNSTSREQ_CNT_U16       0xEF00U

/* Xcp Driver Os Application */
#define XCPIF_XCPOSAPPL_CNT_U08     Appl10

/****************************************************** Macros *******************************************************/
/* Data Acquistion */
#define XCPIF_XCPEVE(x)    Xcp_Event(x)

/* XCP Control */
#define XCPIF_XCPCNTRLDI()  XCP_DEACTIVATE()
#define XCPIF_XCPCNTRLENA() XCP_ACTIVATE()

/*********************************************** Exported Declarations ***********************************************/

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_XCPIF_CFG_PRIVATE_H */
