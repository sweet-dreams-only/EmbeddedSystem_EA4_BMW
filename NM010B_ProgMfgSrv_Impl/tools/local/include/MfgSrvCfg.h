/***********************************************************************************************************************
* Copyright 2015 Nxtr
* Nxtr Confidential
*
* Module File Name: MfgSrvCfg.h
* Module Description: Manufacturing Services Configuration - Contract Header
* Project           : Common Manufacturing Services
* Author            : kzdyfh
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 02/28/18  1        kzdyfh    Initial file creation                                                        EA4#
***********************************************************************************************************************/
#ifndef MFGSRVCFG_H
#define MFGSRVCFG_H

#include "CmnMfgSrvTyp.h"

/* Service Enable/Disable */
#define PROGMFGSRV_FED0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define PROGMFGSRV_FED1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC


/* Prototypes for enabled services */
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED0Rd(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED0Wr(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED1Wr(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED1Rd(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CMNMfgSrv_CODE) CmnMfgSrv_SrvPerRdFast(VAR(uint8, CMNMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CMNMfgSrv_CODE) CmnMfgSrv_SrvPerRdMed(VAR(uint8, CMNMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CMNMfgSrv_CODE) CmnMfgSrv_SrvPerRdSlow(VAR(uint8, CMNMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CMNMfgSrv_CODE) CmnMfgSrv_SrvPerRdStop(VAR(uint8, CMNMfgSrv_VAR) DataBuf_Uls_T_u08[]);


#endif
/* End of File: MfgSrvCfg.h */
