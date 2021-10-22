/***********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name  : SrvFED0.c
* Module Description: Service processing for BMW Tuning Variant Selection
* Project           : Program Specific Manufacturing Services
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         1 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 03/28/18  1        JWJ       Initial file creation                                                        EA4#22133
***********************************************************************************************************************/

/* ================================================================================================================== */
/* Includes */
/* ------------------------------------------------------------------------------------------------------------------ */
#include "Rte_ProgMfgSrv.h"
#include "CmnMfgSrv.h"
#include "CmnMfgSrvTyp.h"
#include "MfgSrvCfg.h"


/* ================================================================================================================== */
/* Service Function Definitions */
/* ------------------------------------------------------------------------------------------------------------------ */

/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  ProgMfgSrv_SrvFED0Rd
 * Description:  0xFED0: Tuning Variant Read
 *          ID:  0xFED0
 *        Type:  0x22 (Read)
 *    Sub-Func:  N/A
 *    Req. Len:  0 bytes
 *   Resp. Len:  1 byte
 * ------------------------------------------------------------------------------------------------------------------ */
#if (PROGMFGSRV_FED0ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED0Rd(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RespCod_Cnt_T_enum = MFGSRVNRCPOSRSP;
	VAR(uint8, AUTOMATIC) BmwDesIninIdx_Cnt_T_u08 = 0U;

	if (Rte_Call_TunVrntRead_Oper(&BmwDesIninIdx_Cnt_T_u08) == E_OK)
	{
		DataBuf_Uls_T_u08[0] = BmwDesIninIdx_Cnt_T_u08;
	}
	else
	{
		RespCod_Cnt_T_enum = MFGSRVNRCCONDITIONSNOTCORRECT;
	}

	return RespCod_Cnt_T_enum;
}
#endif

/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  ProgMfgSrv_SrvFED0Wr
 * Description:  0xFED0: Tuning Variant Write
 *          ID:  0xFED0
 *        Type:  0x2E (Write)
 *    Sub-Func:  N/A
 *    Req. Len:  1 byte
 *   Resp. Len:  0 bytes
 * ------------------------------------------------------------------------------------------------------------------ */
#if (PROGMFGSRV_FED0ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, ProgMfgSrv_CODE) ProgMfgSrv_SrvFED0Wr(VAR(uint8, ProgMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RespCod_Cnt_T_enum = MFGSRVNRCPOSRSP;
	VAR(uint8, AUTOMATIC) BmwDesIninIdx_Cnt_T_u08;

	BmwDesIninIdx_Cnt_T_u08 = DataBuf_Uls_T_u08[0];

	if (Rte_Call_TunVrntWr_Oper(BmwDesIninIdx_Cnt_T_u08) != E_OK)
	{
		RespCod_Cnt_T_enum = MFGSRVNRCCONDITIONSNOTCORRECT;
	}

	return RespCod_Cnt_T_enum;
}
#endif



/* End of File: SrvFED0.c */
