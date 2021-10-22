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
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/SF102A_MotCtrlPrmEstimn_Impl/tools/Component.dpa
 *     SW-C Type:  MotCtrlPrmEstimn
 *  Generated at:  Fri Dec  8 14:08:26 2017
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_MotPrmNomEolRec3
typedef struct
{
  float32 MotBackEmfConNom;
  float32 MotRNom;
} MotPrmNomEolRec3;

# define Rte_TypeDef_u2p14
typedef uint16 u2p14;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_u2p14_16
typedef u2p14 Ary1D_u2p14_16[16];

# define Rte_TypeDef_Ary1D_u2p14_7
typedef u2p14 Ary1D_u2p14_7[7];

# define Rte_TypeDef_Ary1D_u9p7_16
typedef u9p7 Ary1D_u9p7_16[16];

# define Rte_TypeDef_Ary1D_u9p7_6
typedef u9p7 Ary1D_u9p7_6[6];

# define Rte_TypeDef_Ary1D_u9p7_7
typedef u9p7 Ary1D_u9p7_7[7];

# define Rte_TypeDef_Ary2D_u2p14_6_7
typedef Ary1D_u2p14_7 Ary2D_u2p14_6_7[6];


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
