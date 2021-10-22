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
 *          File:  TSC_MotQuadDetn.h
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
Std_ReturnType TSC_MotQuadDetn_Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data);
Std_ReturnType TSC_MotQuadDetn_Rte_Read_MotTqCmd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotQuadDetn_Rte_Write_MotDirInsts_Val(sint8 data);
Std_ReturnType TSC_MotQuadDetn_Rte_Write_MotQuad_Val(MotQuad1 data);

/** Calibration Component Calibration Parameters */
s18p13  TSC_MotQuadDetn_Rte_Prm_MotQuadDetnMotDirHysInsts_Val(void);

/** Per Instance Memories */
s18p13 *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev(void);
s18p13 *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta(void);
sint8 *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev(void);
sint8 *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev(void);
sint8 *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign(void);



