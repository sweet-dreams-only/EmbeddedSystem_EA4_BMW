/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_MotAg1Meas.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_s16_Oper(uint32 * SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg)
{
    MotAg1Meas_Srv_CnvSnpshtData_s16_SnpshtData = SnpshtData_Arg;
    *SnpshtDataCnvd_Arg = MotAg1Meas_Srv_CnvSnpshtData_s16_SnpshtDataCnvd;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_CnvSnpshtData_u16_Oper(uint32 * SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
{
    MotAg1Meas_Srv_CnvSnpshtData_u16_SnpshtData = SnpshtData_Arg;
    *SnpshtDataCnvd_Arg = MotAg1Meas_Srv_CnvSnpshtData_u16_SnpshtDataCnvd;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    MotAg1Meas_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = MotAg1Meas_Srv_GetNtcQlfrSts_NtcQlfr;
    return MotAg1Meas_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Clk_Oper()
{
    return MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Clk_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Cs_Oper()
{
    return MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Cs_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1Mosi_Oper()
{
    return MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Mosi_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Clk_Oper(boolean PinSt_Arg)
{
    MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Clk_PinSt = PinSt_Arg;
    return MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Clk_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Cs_Oper(boolean PinSt_Arg)
{
    MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Cs_PinSt = PinSt_Arg;
    return MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Cs_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1Mosi_Oper(boolean PinSt_Arg)
{
    MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Mosi_PinSt = PinSt_Arg;
    return MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Mosi_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_GetErrorStatus(uint8 * RequestResultPtr_Arg)
{
    *RequestResultPtr_Arg = MotAg1Meas_Srv_MotAg1CoeffTbl_GetErrorStatus_RequestResultPtr;
    return MotAg1Meas_Srv_MotAg1CoeffTbl_GetErrorStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    MotAg1Meas_Srv_MotAg1CoeffTbl_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return MotAg1Meas_Srv_MotAg1CoeffTbl_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcNr = NtcNr_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcStInfo = NtcStInfo_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcSts = NtcSts_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_DebStep = DebStep_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0 = SpclSnpshtData0_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1 = SpclSnpshtData1_Arg;
    MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2 = SpclSnpshtData2_Arg;
    return MotAg1Meas_Srv_SetNtcStsAndSnpshtData_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    MotAg1MeasInit1();
    MotAg1MeasPer1();
    MotAg1MeasPer2();
    MotAg1CoeffTblRead_Oper(&MotAg1Meas_Cli_MotAg1CoeffTblRead_MotAgCoeffTbl[0]);
    MotAg1CoeffTblWr_Oper(&MotAg1Meas_Cli_MotAg1CoeffTblWr_MotAgCoeffTbl[0]);
}

