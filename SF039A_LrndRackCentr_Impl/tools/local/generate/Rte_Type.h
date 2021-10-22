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
 *        Config:  C:/_Synergy_Projects/Working/SF039A_LrndRackCentr_Impl/tools/Component.dpa
 *     SW-C Type:  LrndRackCentr
 *  Generated at:  Tue Nov  7 18:31:38 2017
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

# define Rte_TypeDef_LrndRackCentrNvmRec1
typedef struct
{
  float32 TotRackTrvl;
  float32 RackCentrMotDeg;
  sint16 RackCentrMotRev;
  boolean LongTermRackCentrCmpl;
  boolean MotAgVld;
} LrndRackCentrNvmRec1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
