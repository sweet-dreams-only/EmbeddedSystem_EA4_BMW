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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM526A_BmwMsgSlot234Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot234Bas1Repn2BusFrChA
 *  Generated at:  Fri Apr 27 09:35:10 2018
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

# define Rte_TypeDef_CRC_ST_EST_FTAX1
typedef unsigned char CRC_ST_EST_FTAX1;

# define Rte_TypeDef_ST_EST_dummy_16_231
typedef unsigned char ST_EST_dummy_16_231;

# define Rte_TypeDef_ALIV_ST_EST_FTAX1
typedef unsigned char ALIV_ST_EST_FTAX1;

# define Rte_TypeDef_DrvgDynIfSt1
typedef unsigned char DrvgDynIfSt1;

# define Rte_TypeDef_HaptcFbSt1
typedef unsigned char HaptcFbSt1;

# define Rte_TypeDef_QU_FN_EST1
typedef unsigned char QU_FN_EST1;

# define Rte_TypeDef_QU_FN_VIB_EPS1
typedef unsigned char QU_FN_VIB_EPS1;

# define Rte_TypeDef_QU_SER_STMOM_DV_ACT1
typedef unsigned char QU_SER_STMOM_DV_ACT1;

# define Rte_TypeDef_sigGroup_ST_EST1
typedef struct
{
  QU_SER_STMOM_DV_ACT1 QU_SER_STMOM_DV_ACT;
  QU_FN_VIB_EPS1 QU_FN_VIB_EPS;
  ST_EST_dummy_16_231 ST_EST_dummy_16_23;
  ALIV_ST_EST_FTAX1 ALIV_ST_EST_FTAX;
  CRC_ST_EST_FTAX1 CRC_ST_EST_FTAX;
  QU_FN_EST1 QU_FN_EST;
} sigGroup_ST_EST1;

# define Rte_TypeDef_BmwEpsFctSts1
typedef uint8 BmwEpsFctSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
