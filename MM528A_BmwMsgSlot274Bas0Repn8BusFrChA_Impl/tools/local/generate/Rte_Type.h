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
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM528A_BmwMsgSlot274Bas0Repn8BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas0Repn8BusFrChA
 *  Generated at:  Thu May 31 11:34:48 2018
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

# define Rte_TypeDef_ALIV_SU_EPS1
typedef unsigned char ALIV_SU_EPS1;

# define Rte_TypeDef_CRC_SU_EPS1
typedef unsigned char CRC_SU_EPS1;

# define Rte_TypeDef_SU_EPS_dummy_14_191
typedef unsigned char SU_EPS_dummy_14_191;

# define Rte_TypeDef_SU_EPS_dummy_20_511
typedef unsigned long SU_EPS_dummy_20_511;

# define Rte_TypeDef_TOT_STR_EPS1
typedef unsigned short TOT_STR_EPS1;

# define Rte_TypeDef_UN_TOT_STR_EPS1
typedef unsigned char UN_TOT_STR_EPS1;

# define Rte_TypeDef_sigGroup_SU_EPS1
typedef struct
{
  CRC_SU_EPS1 CRC_SU_EPS;
  UN_TOT_STR_EPS1 UN_TOT_STR_EPS;
  ALIV_SU_EPS1 ALIV_SU_EPS;
  TOT_STR_EPS1 TOT_STR_EPS;
  SU_EPS_dummy_20_511 SU_EPS_dummy_20_51;
  SU_EPS_dummy_14_191 SU_EPS_dummy_14_19;
} sigGroup_SU_EPS1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
