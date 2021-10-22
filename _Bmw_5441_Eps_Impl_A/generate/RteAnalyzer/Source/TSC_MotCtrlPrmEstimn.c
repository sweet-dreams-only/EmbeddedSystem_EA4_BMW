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
 *          File:  TSC_MotCtrlPrmEstimn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotCtrlPrmEstimn.h"
#include "TSC_MotCtrlPrmEstimn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotBackEmfConEstimd_Val(float32 data)
{
  return Rte_Write_MotBackEmfConEstimd_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimd_Val(float32 data)
{
  return Rte_Write_MotInduDaxEstimd_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimd_Val(float32 data)
{
  return Rte_Write_MotInduQaxEstimd_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotREstimd_Val(float32 data)
{
  return Rte_Write_MotREstimd_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_MotPrmNom_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_MotPrmNom_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuFltMtgtnEna_Logl(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrDaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrDaxCmd_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrQaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrQaxCmd_Val(data);
}




Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimdIvs_Val(float32 data)
{
  return Rte_Write_MotInduDaxEstimdIvs_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimdIvs_Val(float32 data)
{
  return Rte_Write_MotInduQaxEstimdIvs_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_MotCtrlPrmEstimn_Rte_IrvRead_MotCtrlPrmEstimnPer1_MotBackEmfConFf(void)
{
return Rte_IrvRead_MotCtrlPrmEstimnPer1_MotBackEmfConFf();
}






Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotFetT_Val(float32 *data)
{
  return Rte_Read_MotFetT_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotMagT_Val(float32 *data)
{
  return Rte_Read_MotMagT_Val(data);
}

Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotWidgT_Val(float32 *data)
{
  return Rte_Read_MotWidgT_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_MotCtrlPrmEstimn_Rte_IrvWrite_MotCtrlPrmEstimnPer2_MotBackEmfConFf(float32 data)
{
  Rte_IrvWrite_MotCtrlPrmEstimnPer2_MotBackEmfConFf( data);
}












     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
}
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val(void)
{
  return (float32 ) Rte_Prm_MotCtrlPrmEstimnTNom_Val();
}
Ary1D_u9p7_16 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(void)
{
  return (Ary1D_u9p7_16 *) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D();
}
Ary1D_u2p14_16 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(void)
{
  return (Ary1D_u2p14_16 *) Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D();
}
Ary1D_u9p7_6 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_6 *) Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D();
}
Ary1D_u9p7_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(void)
{
  return (Ary1D_u9p7_7 *) Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D();
}
Ary2D_u2p14_6_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(void)
{
  return (Ary2D_u2p14_6_7 *) Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D();
}
Ary2D_u2p14_6_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(void)
{
  return (Ary2D_u2p14_6_7 *) Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D();
}


     /* MotCtrlPrmEstimn */
      /* MotCtrlPrmEstimn */

/** Per Instance Memories */
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
}
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd(void)
{
  return Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
}
MotPrmNomEolRec3 *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom(void)
{
  return Rte_Pim_MotPrmNom();
}



