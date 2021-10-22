/***********************************************************************************************************************
* Copyright 2015 Nxtr
* Nxtr Confidential
*
* Module File Name: SrvF212.c
* Module Description: Service processing
* Project           : Common Manufacturing Services
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         1 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 07/22/17  1        JWJ       Initial file creation                                                        EA4#14061
***********************************************************************************************************************/

/* ================================================================================================================== */
/* Includes */
/* ------------------------------------------------------------------------------------------------------------------ */
#include "Rte_CmnMfgSrv.h"
#include "CmnMfgSrv.h"
#include "CmnMfgSrvTyp.h"
#include "MfgSrvCfg.h"
#include "CmnMfgSrvFct.h"


/* ================================================================================================================== */
/* Service Function Definitions */
/* ------------------------------------------------------------------------------------------------------------------ */

/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  CmnMfgSrv_SrvF212Rd
 * Description:  0x12: Handwheel Torque Sensor 2 Send once
 *          ID:  0xF212
 *        Type:  0x22 (Read)
 *    Sub-Func:  N/A
 *    Req. Len:  0 bytes
 *   Resp. Len:  4 bytes
 * ------------------------------------------------------------------------------------------------------------------ */
#if (CMNMFGSRV_F212ENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF212Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RspCod_Cnt_T_enum = MFGSRVNRCPOSRSP;
	VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32 = 0.0f;

	(void)Rte_Read_HwTq2_Val(&HwTq_HwNwtMtr_T_f32);

	CmnMfgSrvFct_DecomposeFloat(HwTq_HwNwtMtr_T_f32, DataBuf_Uls_T_u08);

	return RspCod_Cnt_T_enum;
}
#endif



/* End of File: SrvF212.c */
