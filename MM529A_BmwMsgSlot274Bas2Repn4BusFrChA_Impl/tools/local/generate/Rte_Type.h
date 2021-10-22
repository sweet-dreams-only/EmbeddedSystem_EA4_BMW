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
 *          File:  Rte_Type.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM529A_BmwMsgSlot274Bas2Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas2Repn4BusFrChA
 *  Generated at:  Thu Apr 26 18:59:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_ALIV_DISP_CC_EPS1
typedef unsigned char ALIV_DISP_CC_EPS1;

# define Rte_TypeDef_CHL_DISP_CC_EPS1
typedef unsigned char CHL_DISP_CC_EPS1;

# define Rte_TypeDef_CRC_DISP_CC_EPS1
typedef unsigned char CRC_DISP_CC_EPS1;

# define Rte_TypeDef_NO_CC_EPS1
typedef unsigned short NO_CC_EPS1;

# define Rte_TypeDef_TRANF_CC_EPS1
typedef unsigned char TRANF_CC_EPS1;

# define Rte_TypeDef_ST_CC_EPS1
typedef unsigned char ST_CC_EPS1;

# define Rte_TypeDef_ST_IDC_CC_EPS1
typedef unsigned char ST_IDC_CC_EPS1;

# define Rte_TypeDef_sigGroup_DISP_CC_EPS1
typedef struct
{
  ST_CC_EPS1 ST_CC_EPS;
  ALIV_DISP_CC_EPS1 ALIV_DISP_CC_EPS;
  ST_IDC_CC_EPS1 ST_IDC_CC_EPS;
  CRC_DISP_CC_EPS1 CRC_DISP_CC_EPS;
  CHL_DISP_CC_EPS1 CHL_DISP_CC_EPS;
  NO_CC_EPS1 NO_CC_EPS;
  TRANF_CC_EPS1 TRANF_CC_EPS;
} sigGroup_DISP_CC_EPS1;

# define Rte_TypeDef_BmwFltLampFlsgFrq1
typedef uint8 BmwFltLampFlsgFrq1;

# define Rte_TypeDef_BmwFltLampReqSts1
typedef uint8 BmwFltLampReqSts1;

# define Rte_TypeDef_BmwFltLampReqTyp2
typedef uint16 BmwFltLampReqTyp2;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
