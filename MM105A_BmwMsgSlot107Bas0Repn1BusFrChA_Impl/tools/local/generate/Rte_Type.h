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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM105A_BmwMsgSlot107Bas0Repn1BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot107Bas0Repn1BusFrChA
 *  Generated at:  Fri Jun  8 11:01:56 2018
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

# define Rte_TypeDef_AVL_PO_IDX_ICM1
typedef unsigned short AVL_PO_IDX_ICM1;

# define Rte_TypeDef_CRC_OFFS_QUAD_EPS1
typedef unsigned char CRC_OFFS_QUAD_EPS1;

# define Rte_TypeDef_OFFS_QUAD_RTR_EPS1
typedef unsigned char OFFS_QUAD_RTR_EPS1;

# define Rte_TypeDef_ALIV_OFFS_QUAD_EPS1
typedef unsigned char ALIV_OFFS_QUAD_EPS1;

# define Rte_TypeDef_ST_OFFS_QUAD_EPS1
typedef unsigned char ST_OFFS_QUAD_EPS1;

# define Rte_TypeDef_sigGroup_OFFS_QUAD_EPS1
typedef struct
{
  AVL_PO_IDX_ICM1 AVL_PO_IDX_ICM;
  ST_OFFS_QUAD_EPS1 ST_OFFS_QUAD_EPS;
  CRC_OFFS_QUAD_EPS1 CRC_OFFS_QUAD_EPS;
  OFFS_QUAD_RTR_EPS1 OFFS_QUAD_RTR_EPS;
  ALIV_OFFS_QUAD_EPS1 ALIV_OFFS_QUAD_EPS;
} sigGroup_OFFS_QUAD_EPS1;

# define Rte_TypeDef_BmwQuadOffsSts1
typedef uint8 BmwQuadOffsSts1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
