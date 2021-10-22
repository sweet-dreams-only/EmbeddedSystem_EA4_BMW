/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_BmwTunSetHndlr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwTunSetHndlr.h"
#include "TSC_BmwTunSetHndlr.h"











Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesIninIdx_Val(uint8 data)
{
  return Rte_Write_DesIninIdx_Val(data);
}

Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesIninOptSetAIdx_Val(uint8 data)
{
  return Rte_Write_DesIninOptSetAIdx_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_BmwDesIninIdx_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_BmwDesIninIdx_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_BmwRtIdx_Val(BmwRtIdx1 *data)
{
  return Rte_Read_BmwRtIdx_Val(data);
}

Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_BmwRtIdxVld_Logl(boolean *data)
{
  return Rte_Read_BmwRtIdxVld_Logl(data);
}

Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_TunSetHndlrEna_Logl(boolean *data)
{
  return Rte_Read_TunSetHndlrEna_Logl(data);
}




Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesRtIdx_Val(uint8 data)
{
  return Rte_Write_DesRtIdx_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint16  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val();
}
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val(void)
{
  return (uint8 ) Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val();
}
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val(void)
{
  return (uint8 ) Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val();
}
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val(void)
{
  return (uint8 ) Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val();
}
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val(void)
{
  return (uint8 ) Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val();
}

BmwDesIninIdxRec1 * TSC_BmwTunSetHndlr_Rte_CData_BmwDesIninIdxDft(void)
{
  return (BmwDesIninIdxRec1 *) Rte_CData_BmwDesIninIdxDft();
}
BmwDesIninOptSetAIdxRec1 * TSC_BmwTunSetHndlr_Rte_CData_BmwDesIninOptSetAIdxDft(void)
{
  return (BmwDesIninOptSetAIdxRec1 *) Rte_CData_BmwDesIninOptSetAIdxDft();
}

     /* BmwTunSetHndlr */
      /* BmwTunSetHndlr */

/** Per Instance Memories */
uint32 *TSC_BmwTunSetHndlr_Rte_Pim_BmwRtIdxTi(void)
{
  return Rte_Pim_BmwRtIdxTi();
}
BmwRtIdx1 *TSC_BmwTunSetHndlr_Rte_Pim_DebBmwRtIdx(void)
{
  return Rte_Pim_DebBmwRtIdx();
}
uint8 *TSC_BmwTunSetHndlr_Rte_Pim_LstVldIdx(void)
{
  return Rte_Pim_LstVldIdx();
}
BmwRtIdx1 *TSC_BmwTunSetHndlr_Rte_Pim_PrevBmwRtIdx(void)
{
  return Rte_Pim_PrevBmwRtIdx();
}
BmwDesIninIdxRec1 *TSC_BmwTunSetHndlr_Rte_Pim_BmwDesIninIdx(void)
{
  return Rte_Pim_BmwDesIninIdx();
}
BmwDesIninOptSetAIdxRec1 *TSC_BmwTunSetHndlr_Rte_Pim_BmwDesIninOptSetAIdx(void)
{
  return Rte_Pim_BmwDesIninOptSetAIdx();
}



