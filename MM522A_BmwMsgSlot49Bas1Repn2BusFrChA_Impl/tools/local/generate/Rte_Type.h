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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM522A_BmwMsgSlot49Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas1Repn2BusFrChA
 *  Generated at:  Mon May  7 10:19:48 2018
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

# define Rte_TypeDef_ALIV_DT_EST1
typedef unsigned char ALIV_DT_EST1;

# define Rte_TypeDef_CRC_DT_EST1
typedef unsigned char CRC_DT_EST1;

# define Rte_TypeDef_DT_EST_dummy_12_151
typedef unsigned char DT_EST_dummy_12_151;

# define Rte_TypeDef_DT_EST_dummy_16_471
typedef unsigned long DT_EST_dummy_16_471;

# define Rte_TypeDef_DT_EST_dummy_64_951
typedef unsigned long DT_EST_dummy_64_951;

# define Rte_TypeDef_DT_EST_dummy_96_1271
typedef unsigned long DT_EST_dummy_96_1271;

# define Rte_TypeDef_AVL_I_ACT_EST1
typedef unsigned char AVL_I_ACT_EST1;

# define Rte_TypeDef_QU_AVL_I_ACT_EST1
typedef unsigned char QU_AVL_I_ACT_EST1;

# define Rte_TypeDef_ST_CULI_EST1
typedef unsigned char ST_CULI_EST1;

# define Rte_TypeDef_sigGroup_DT_EST1
typedef struct
{
  ST_CULI_EST1 ST_CULI_EST;
  DT_EST_dummy_64_951 DT_EST_dummy_64_95;
  QU_AVL_I_ACT_EST1 QU_AVL_I_ACT_EST;
  DT_EST_dummy_12_151 DT_EST_dummy_12_15;
  AVL_I_ACT_EST1 AVL_I_ACT_EST;
  ALIV_DT_EST1 ALIV_DT_EST;
  CRC_DT_EST1 CRC_DT_EST;
  DT_EST_dummy_96_1271 DT_EST_dummy_96_127;
  DT_EST_dummy_16_471 DT_EST_dummy_16_47;
} sigGroup_DT_EST1;

# define Rte_TypeDef_BattRtnCurrAmprQlfr1
typedef uint8 BattRtnCurrAmprQlfr1;

# define Rte_TypeDef_EpsCurrLimSts1
typedef uint8 EpsCurrLimSts1;

#endif /* _RTE_TYPE_H */
