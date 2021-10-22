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
 *          File:  TSC_CmplncErr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CmplncErr.h"
#include "TSC_CmplncErr.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CmplncErr_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_CmplncErr_Rte_Read_MotTqCmdCrf_Val(float32 *data)
{
  return Rte_Read_MotTqCmdCrf_Val(data);
}




Std_ReturnType TSC_CmplncErr_Rte_Write_CmplncErrMotToPinion_Val(float32 data)
{
  return Rte_Write_CmplncErrMotToPinion_Val(data);
}

Std_ReturnType TSC_CmplncErr_Rte_Write_CmplncErrPinionToHw_Val(float32 data)
{
  return Rte_Write_CmplncErrPinionToHw_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





Ary1D_u1p15_6 * TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncDepTblY_Ary1D(void)
{
  return (Ary1D_u1p15_6 *) Rte_Prm_CmplncErrHwAgNonLinCmplncDepTblY_Ary1D();
}
Ary1D_u5p11_6 * TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncIndTblX_Ary1D(void)
{
  return (Ary1D_u5p11_6 *) Rte_Prm_CmplncErrHwAgNonLinCmplncIndTblX_Ary1D();
}
Ary1D_u8p8_6 * TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncDepTblY_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_CmplncErrMotAgNonLinCmplncDepTblY_Ary1D();
}
Ary1D_u5p11_6 * TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncIndTblX_Ary1D(void)
{
  return (Ary1D_u5p11_6 *) Rte_Prm_CmplncErrMotAgNonLinCmplncIndTblX_Ary1D();
}


     /* CmplncErr */
      /* CmplncErr */



