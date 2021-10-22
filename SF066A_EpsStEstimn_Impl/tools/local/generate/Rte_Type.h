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
 *        Config:  C:/_Synergy_Projects/New_Working/SF066A_EpsStEstimn_Impl/tools/Component.dpa
 *     SW-C Type:  EpsStEstimn
 *  Generated at:  Sat Apr 21 09:56:04 2018
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

# define Rte_TypeDef_Ary1D_f32_3
typedef float32 Ary1D_f32_3[3];

# define Rte_TypeDef_Ary1D_f32_5
typedef float32 Ary1D_f32_5[5];

# define Rte_TypeDef_TorsBarStEstimdRec1
typedef struct
{
  float32 MotVelEstimd;
  float32 TorsBarTqEstimd;
  float32 TorsBarRotatmEstimd;
  float32 DrvrTqEstimd;
  float32 RackTqEstimd;
} TorsBarStEstimdRec1;

# define Rte_TypeDef_Ary2D_f32_5_3
typedef Ary1D_f32_3 Ary2D_f32_5_3[5];

# define Rte_TypeDef_Ary2D_f32_5_5
typedef Ary1D_f32_5 Ary2D_f32_5_5[5];


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
