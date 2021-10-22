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
 *        Config:  C:/Nimmy/Autocode/BMW/BMW_Production/SF070/SF070A_HwTqTrakgCtrl_Impl/tools/Component.dpa
 *     SW-C Type:  HwTqTrakgCtrl
 *  Generated at:  Mon May 14 09:57:36 2018
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

# define Rte_TypeDef_TorsBarStEstimdRec1
typedef struct
{
  float32 MotVelEstimd;
  float32 TorsBarTqEstimd;
  float32 TorsBarRotatmEstimd;
  float32 DrvrTqEstimd;
  float32 RackTqEstimd;
} TorsBarStEstimdRec1;

# define Rte_TypeDef_s14p1
typedef sint16 s14p1;

# define Rte_TypeDef_s3p12
typedef sint16 s3p12;

# define Rte_TypeDef_s7p8
typedef sint16 s7p8;

# define Rte_TypeDef_s8p7
typedef sint16 s8p7;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_s14p1_4
typedef s14p1 Ary1D_s14p1_4[4];

# define Rte_TypeDef_Ary1D_s3p12_4
typedef s3p12 Ary1D_s3p12_4[4];

# define Rte_TypeDef_Ary1D_s7p8_4
typedef s7p8 Ary1D_s7p8_4[4];

# define Rte_TypeDef_Ary1D_s8p7_4
typedef s8p7 Ary1D_s8p7_4[4];

# define Rte_TypeDef_Ary1D_u9p7_4
typedef u9p7 Ary1D_u9p7_4[4];

#endif /* _RTE_TYPE_H */
