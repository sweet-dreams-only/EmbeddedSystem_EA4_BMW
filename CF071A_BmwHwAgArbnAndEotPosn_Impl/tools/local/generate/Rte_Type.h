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
 *        Config:  C:/_S/work/ses_dev_ea4/CF071A_BmwHwAgArbnAndEotPosn_Impl-z172399/CF071A_BmwHwAgArbnAndEotPosn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHwAgArbnAndEotPosn
 *  Generated at:  Thu Jul 19 09:07:16 2018
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

# define Rte_TypeDef_BmwVehCentrOffsRec1
typedef struct
{
  float32 BmwRackCentrToVehCentrOffs;
  float32 VehCentrOffs;
  float32 BmwPinionAgOffs;
  sint8 BmwQuadRotorOffs;
  uint8 TurnCntrCorrlnSts;
  uint8 Ntc8CSts;
  uint8 Ntc8ESts;
  uint8 BmwMotAgSelnSt;
  boolean LongTermVehCentrCmpl;
  boolean RackCentrToVehCentrOffsVld;
} BmwVehCentrOffsRec1;

# define Rte_TypeDef_BmwMotAgSelnSt1
typedef uint8 BmwMotAgSelnSt1;

# define Rte_TypeDef_BmwPinionAgOffsSts1
typedef uint8 BmwPinionAgOffsSts1;

# define Rte_TypeDef_BmwPinionAgQlfr1
typedef uint8 BmwPinionAgQlfr1;

# define Rte_TypeDef_BmwQuadOffsSts1
typedef uint8 BmwQuadOffsSts1;

# define Rte_TypeDef_BmwRackToVehCentrOffsSts1
typedef uint8 BmwRackToVehCentrOffsSts1;

# define Rte_TypeDef_BmwSetVehCentrOffsSts1
typedef uint8 BmwSetVehCentrOffsSts1;

# define Rte_TypeDef_BmwVehSpdSts1
typedef uint8 BmwVehSpdSts1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;

# define Rte_TypeDef_SigQlfr1
typedef uint8 SigQlfr1;

# define Rte_TypeDef_s18p13
typedef sint32 s18p13;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
