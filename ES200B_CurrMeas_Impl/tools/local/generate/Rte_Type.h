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
 *        Config:  C:/Users/nz4826/Documents/Mrudula/Synergy_working/comp_dev_ea4/ES200B_CurrMeas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_CurrMeas
 *  Generated at:  Thu Mar 15 14:18:15 2018
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

# define Rte_TypeDef_CurrMeasEolGainCal3PhaRec1
typedef struct
{
  float32 CurrMeasMotCurrEolGainA;
  float32 CurrMeasMotCurrEolGainB;
  float32 CurrMeasMotCurrEolGainC;
} CurrMeasEolGainCal3PhaRec1;

# define Rte_TypeDef_CurrMeasEolOffsCal3PhaRec1
typedef struct
{
  float32 CurrMeasEolOffsHiBrdgVltg;
  float32 CurrMeasMotCurrEolOffsDifA;
  float32 CurrMeasMotCurrEolOffsDifB;
  float32 CurrMeasMotCurrEolOffsDifC;
  float32 CurrMeasMotCurrOffsLoAvrgA;
  float32 CurrMeasMotCurrOffsLoAvrgB;
  float32 CurrMeasMotCurrOffsLoAvrgC;
} CurrMeasEolOffsCal3PhaRec1;

# define Rte_TypeDef_MotCurrEolCalSt2
typedef uint8 MotCurrEolCalSt2;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;

# define Rte_TypeDef_SigQlfr1
typedef uint8 SigQlfr1;

# define Rte_TypeDef_SysSt1
typedef uint8 SysSt1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
