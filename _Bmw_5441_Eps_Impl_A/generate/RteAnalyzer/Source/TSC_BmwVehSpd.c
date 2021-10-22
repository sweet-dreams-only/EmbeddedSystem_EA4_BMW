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
 *          File:  TSC_BmwVehSpd.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwVehSpd.h"
#include "TSC_BmwVehSpd.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpd_Val(float32 *data)
{
  return Rte_Read_BmwCogVehSpd_Val(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 *data)
{
  return Rte_Read_BmwCogVehSpdQlfr_Val(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfrVld_Logl(boolean *data)
{
  return Rte_Read_BmwCogVehSpdQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdVld_Logl(boolean *data)
{
  return Rte_Read_BmwCogVehSpdVld_Logl(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
{
  return Rte_Read_BmwNearStillVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdStsVld_Logl(boolean *data)
{
  return Rte_Read_BmwNearStillVehSpdStsVld_Logl(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
{
  return Rte_Read_BmwPinionAgQlfr_Val(data);
}




Std_ReturnType TSC_BmwVehSpd_Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data)
{
  return Rte_Write_BmwSecurVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Write_VehSpd_Val(float32 data)
{
  return Rte_Write_VehSpd_Val(data);
}

Std_ReturnType TSC_BmwVehSpd_Rte_Write_VehSpdVld_Logl(boolean data)
{
  return Rte_Write_VehSpdVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwVehSpd_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwVehSpd_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val(void)
{
  return (float32 ) Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val();
}
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdRunngSubVehSpd_Val(void)
{
  return (float32 ) Rte_Prm_BmwVehSpdRunngSubVehSpd_Val();
}
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val();
}
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val();
}
u16p0  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void)
{
  return (u16p0 ) Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val();
}


     /* BmwVehSpd */
      /* BmwVehSpd */

/** Per Instance Memories */
float32 *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev(void)
{
  return Rte_Pim_VehSpdLimPrev();
}
uint32 *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(void)
{
  return Rte_Pim_BmwSecurVehSpdStsSigValVldDurn();
}
boolean *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg(void)
{
  return Rte_Pim_SpdDifChkFlg();
}



