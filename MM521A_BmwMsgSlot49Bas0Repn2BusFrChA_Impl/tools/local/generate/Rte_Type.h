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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM521A_BmwMsgSlot49Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas0Repn2BusFrChA
 *  Generated at:  Mon May  7 09:17:37 2018
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

# define Rte_TypeDef_AVL_FORC_GRD1
typedef unsigned short AVL_FORC_GRD1;

# define Rte_TypeDef_AVL_FORC_GRD_dummy_12_151
typedef unsigned char AVL_FORC_GRD_dummy_12_151;

# define Rte_TypeDef_AVL_PWR_EL_EPS_COOD1
typedef unsigned char AVL_PWR_EL_EPS_COOD1;

# define Rte_TypeDef_AVL_STMOM_DV_ACT1
typedef unsigned short AVL_STMOM_DV_ACT1;

# define Rte_TypeDef_AVL_STMOM_DV_ACT_dummy_12_151
typedef unsigned char AVL_STMOM_DV_ACT_dummy_12_151;

# define Rte_TypeDef_CRC_AVL_FORC_GRD1
typedef unsigned char CRC_AVL_FORC_GRD1;

# define Rte_TypeDef_CRC_AVL_STMOM_DV_ACT1
typedef unsigned char CRC_AVL_STMOM_DV_ACT1;

# define Rte_TypeDef_ALIV_AVL_FORC_GRD1
typedef unsigned char ALIV_AVL_FORC_GRD1;

# define Rte_TypeDef_ALIV_AVL_STMOM_DV_ACT1
typedef unsigned char ALIV_AVL_STMOM_DV_ACT1;

# define Rte_TypeDef_QU_AVL_FORC_GRD1
typedef unsigned char QU_AVL_FORC_GRD1;

# define Rte_TypeDef_QU_AVL_STMOM_DV_ACT1
typedef unsigned char QU_AVL_STMOM_DV_ACT1;

# define Rte_TypeDef_sigGroup_AVL_FORC_GRD1
typedef struct
{
  AVL_FORC_GRD1 AVL_FORC_GRD;
  AVL_PWR_EL_EPS_COOD1 AVL_PWR_EL_EPS_COOD;
  ALIV_AVL_FORC_GRD1 ALIV_AVL_FORC_GRD;
  CRC_AVL_FORC_GRD1 CRC_AVL_FORC_GRD;
  QU_AVL_FORC_GRD1 QU_AVL_FORC_GRD;
  AVL_FORC_GRD_dummy_12_151 AVL_FORC_GRD_dummy_12_15;
} sigGroup_AVL_FORC_GRD1;

# define Rte_TypeDef_sigGroup_AVL_STMOM_DV_ACT1
typedef struct
{
  AVL_STMOM_DV_ACT1 AVL_STMOM_DV_ACT;
  ALIV_AVL_STMOM_DV_ACT1 ALIV_AVL_STMOM_DV_ACT;
  QU_AVL_STMOM_DV_ACT1 QU_AVL_STMOM_DV_ACT;
  CRC_AVL_STMOM_DV_ACT1 CRC_AVL_STMOM_DV_ACT;
  AVL_STMOM_DV_ACT_dummy_12_151 AVL_STMOM_DV_ACT_dummy_12_15;
} sigGroup_AVL_STMOM_DV_ACT1;

# define Rte_TypeDef_SigQlfr1
typedef uint8 SigQlfr1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
