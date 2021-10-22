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
 *          File:  TSC_FalbckAssi.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_FalbckAssi_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_FalbckAssi_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_FalbckAssi_Rte_Write_FalbckAssiMotTqCmd_Val(float32 data);

/** Calibration Component Calibration Parameters */
Ary2D_u6p10_12_20 * TSC_FalbckAssi_Rte_Prm_FalbckAssiAssiX_Ary2D(void);
Ary2D_u4p12_12_20 * TSC_FalbckAssi_Rte_Prm_FalbckAssiAssiY_Ary2D(void);
Ary1D_u9p7_12 * TSC_FalbckAssi_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void);
FilNotchGainRec1 * TSC_FalbckAssi_Rte_Prm_FalbckAssiNotchFil_Rec(void);

/** Per Instance Memories */
float32 *TSC_FalbckAssi_Rte_Pim_FalbckAssiNotchFil1(void);
float32 *TSC_FalbckAssi_Rte_Pim_FalbckAssiNotchFil2(void);



