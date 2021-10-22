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
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/SF111A_FalbckAssi_Impl-nz2999/SF111A_FalbckAssi_Impl/tools/Component.dpa
 *     SW-C Type:  FalbckAssi
 *  Generated at:  Fri Apr 20 08:33:34 2018
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

# define Rte_TypeDef_FilNotchGainRec1
typedef struct
{
  float32 FilGainB0;
  float32 FilGainB1;
  float32 FilGainB2;
  float32 FilGainA1;
  float32 FilGainA2;
} FilNotchGainRec1;

# define Rte_TypeDef_u4p12
typedef uint16 u4p12;

# define Rte_TypeDef_u6p10
typedef uint16 u6p10;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_u4p12_20
typedef u4p12 Ary1D_u4p12_20[20];

# define Rte_TypeDef_Ary1D_u6p10_20
typedef u6p10 Ary1D_u6p10_20[20];

# define Rte_TypeDef_Ary1D_u9p7_12
typedef u9p7 Ary1D_u9p7_12[12];

# define Rte_TypeDef_Ary2D_u4p12_12_20
typedef Ary1D_u4p12_20 Ary2D_u4p12_12_20[12];

# define Rte_TypeDef_Ary2D_u6p10_12_20
typedef Ary1D_u6p10_20 Ary2D_u6p10_12_20[12];


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
