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
 *          File:  TSC_CDD_AdcDiagc.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_AdcDiagc.h"
#include "TSC_CDD_AdcDiagc.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0ScanGroup2Ref0_Val(float32 *data)
{
  return Rte_Read_Adc0ScanGroup2Ref0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0ScanGroup2Ref1_Val(float32 *data)
{
  return Rte_Read_Adc0ScanGroup2Ref1_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0ScanGroup3Ref0_Val(float32 *data)
{
  return Rte_Read_Adc0ScanGroup3Ref0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0ScanGroup3Ref1_Val(float32 *data)
{
  return Rte_Read_Adc0ScanGroup3Ref1_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0SelfDiag0_Val(float32 *data)
{
  return Rte_Read_Adc0SelfDiag0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0SelfDiag2_Val(float32 *data)
{
  return Rte_Read_Adc0SelfDiag2_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc0SelfDiag4_Val(float32 *data)
{
  return Rte_Read_Adc0SelfDiag4_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1ScanGroup2Ref0_Val(float32 *data)
{
  return Rte_Read_Adc1ScanGroup2Ref0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1ScanGroup2Ref1_Val(float32 *data)
{
  return Rte_Read_Adc1ScanGroup2Ref1_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1ScanGroup3Ref0_Val(float32 *data)
{
  return Rte_Read_Adc1ScanGroup3Ref0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1ScanGroup3Ref1_Val(float32 *data)
{
  return Rte_Read_Adc1ScanGroup3Ref1_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1SelfDiag0_Val(float32 *data)
{
  return Rte_Read_Adc1SelfDiag0_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1SelfDiag2_Val(float32 *data)
{
  return Rte_Read_Adc1SelfDiag2_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Read_Adc1SelfDiag4_Val(float32 *data)
{
  return Rte_Read_Adc1SelfDiag4_Val(data);
}




Std_ReturnType TSC_CDD_AdcDiagc_Rte_Write_Adc0Faild_Logl(boolean data)
{
  return Rte_Write_Adc0Faild_Logl(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Write_Adc1Faild_Logl(boolean data)
{
  return Rte_Write_Adc1Faild_Logl(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Write_AdcDiagcEndPtrOutp_Val(uint8 data)
{
  return Rte_Write_AdcDiagcEndPtrOutp_Val(data);
}

Std_ReturnType TSC_CDD_AdcDiagc_Rte_Write_AdcDiagcStrtPtrOutp_Val(uint8 data)
{
  return Rte_Write_AdcDiagcStrtPtrOutp_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_AdcDiagc_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CDD_AdcDiagc_Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg)
{
  return Rte_Call_ReadErrInjReg_Oper(ErrId_Arg);
}
Std_ReturnType TSC_CDD_AdcDiagc_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}
Std_ReturnType TSC_CDD_AdcDiagc_Rte_Call_StrtErrInjCntr_Oper(void)
{
  return Rte_Call_StrtErrInjCntr_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint16  TSC_CDD_AdcDiagc_Rte_Prm_AdcDiagcNtc0x032FailStep_Val(void)
{
  return (uint16 ) Rte_Prm_AdcDiagcNtc0x032FailStep_Val();
}
uint16  TSC_CDD_AdcDiagc_Rte_Prm_AdcDiagcNtc0x032PassStep_Val(void)
{
  return (uint16 ) Rte_Prm_AdcDiagcNtc0x032PassStep_Val();
}
uint16  TSC_CDD_AdcDiagc_Rte_Prm_AdcDiagcNtc0x033FailStep_Val(void)
{
  return (uint16 ) Rte_Prm_AdcDiagcNtc0x033FailStep_Val();
}
uint16  TSC_CDD_AdcDiagc_Rte_Prm_AdcDiagcNtc0x033PassStep_Val(void)
{
  return (uint16 ) Rte_Prm_AdcDiagcNtc0x033PassStep_Val();
}


     /* CDD_AdcDiagc */
      /* CDD_AdcDiagc */

/** Per Instance Memories */
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0FltCntSt0(void)
{
  return Rte_Pim_Adc0FltCntSt0();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0FltCntSt2(void)
{
  return Rte_Pim_Adc0FltCntSt2();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0FltCntSt4(void)
{
  return Rte_Pim_Adc0FltCntSt4();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0FltCntSt6(void)
{
  return Rte_Pim_Adc0FltCntSt6();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0ScanGroup2RefFltCntSt(void)
{
  return Rte_Pim_Adc0ScanGroup2RefFltCntSt();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc0ScanGroup3RefFltCntSt(void)
{
  return Rte_Pim_Adc0ScanGroup3RefFltCntSt();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1FltCntSt0(void)
{
  return Rte_Pim_Adc1FltCntSt0();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1FltCntSt2(void)
{
  return Rte_Pim_Adc1FltCntSt2();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1FltCntSt4(void)
{
  return Rte_Pim_Adc1FltCntSt4();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1FltCntSt6(void)
{
  return Rte_Pim_Adc1FltCntSt6();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1ScanGroup2RefFltCntSt(void)
{
  return Rte_Pim_Adc1ScanGroup2RefFltCntSt();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_Adc1ScanGroup3RefFltCntSt(void)
{
  return Rte_Pim_Adc1ScanGroup3RefFltCntSt();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_AdcDiagcEndPtr(void)
{
  return Rte_Pim_AdcDiagcEndPtr();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_AdcDiagcSt(void)
{
  return Rte_Pim_AdcDiagcSt();
}
uint8 *TSC_CDD_AdcDiagc_Rte_Pim_AdcDiagcStrtPtr(void)
{
  return Rte_Pim_AdcDiagcStrtPtr();
}



