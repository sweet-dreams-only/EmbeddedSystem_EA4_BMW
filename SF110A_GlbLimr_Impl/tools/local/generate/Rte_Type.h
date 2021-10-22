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
 *        Config:  C:/_S/work/ses_dev_ea4/SF110A_GlbLimr_Impl-z172399/SF110A_GlbLimr_Impl/tools/Component.dpa
 *     SW-C Type:  GlbLimr
 *  Generated at:  Fri Apr 20 09:39:24 2018
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

# define Rte_TypeDef_s4p11
typedef sint16 s4p11;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_s4p11_13
typedef s4p11 Ary1D_s4p11_13[13];

# define Rte_TypeDef_Ary1D_u9p7_10
typedef u9p7 Ary1D_u9p7_10[10];

# define Rte_TypeDef_Ary2D_s4p11_10_13
typedef Ary1D_s4p11_13 Ary2D_s4p11_10_13[10];


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
