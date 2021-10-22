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
 *        Config:  C:/_Synergy_Projects/Working/MM523A_BmwMsgSlot51Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot51Bas0Repn2BusFrChA
 *  Generated at:  Tue Mar 27 17:52:25 2018
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

# define Rte_TypeDef_AVL_PO_EPS1
typedef unsigned short AVL_PO_EPS1;

# define Rte_TypeDef_AVL_PO_IDX_EPS1
typedef unsigned short AVL_PO_IDX_EPS1;

# define Rte_TypeDef_CRC_AVL_PO_EPS1
typedef unsigned char CRC_AVL_PO_EPS1;

# define Rte_TypeDef_OFFS_GRD_MID_EPS1
typedef unsigned short OFFS_GRD_MID_EPS1;

# define Rte_TypeDef_ALIV_AVL_PO_EPS1
typedef unsigned char ALIV_AVL_PO_EPS1;

# define Rte_TypeDef_IDX_TORQ_SEN1
typedef unsigned char IDX_TORQ_SEN1;

# define Rte_TypeDef_QU_AVL_PO_EPS1
typedef unsigned char QU_AVL_PO_EPS1;

# define Rte_TypeDef_UN_PO_EPS1
typedef unsigned char UN_PO_EPS1;

# define Rte_TypeDef_sigGroup_AVL_PO_EPS1
typedef struct
{
  AVL_PO_EPS1 AVL_PO_EPS;
  IDX_TORQ_SEN1 IDX_TORQ_SEN;
  OFFS_GRD_MID_EPS1 OFFS_GRD_MID_EPS;
  AVL_PO_IDX_EPS1 AVL_PO_IDX_EPS;
  CRC_AVL_PO_EPS1 CRC_AVL_PO_EPS;
  QU_AVL_PO_EPS1 QU_AVL_PO_EPS;
  ALIV_AVL_PO_EPS1 ALIV_AVL_PO_EPS;
  UN_PO_EPS1 UN_PO_EPS;
} sigGroup_AVL_PO_EPS1;

# define Rte_TypeDef_BmwPinionAgQlfr1
typedef uint8 BmwPinionAgQlfr1;

# define Rte_TypeDef_BmwSeldPosnUnit1
typedef uint8 BmwSeldPosnUnit1;

# define Rte_TypeDef_BmwTqSnsrIdx1
typedef uint8 BmwTqSnsrIdx1;

#endif /* _RTE_TYPE_H */
