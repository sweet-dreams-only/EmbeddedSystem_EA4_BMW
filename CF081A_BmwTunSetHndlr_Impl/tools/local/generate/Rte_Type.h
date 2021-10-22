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
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF081A_BmwTunSetHndlr_Impl-nz2999/CF081A_BmwTunSetHndlr_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTunSetHndlr
 *  Generated at:  Thu May 17 16:39:22 2018
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

# define Rte_TypeDef_BmwDesIninIdxRec1
typedef struct
{
  uint8 BmwDesIninIdx;
  boolean BmwDesIninIdxWrSts;
} BmwDesIninIdxRec1;

# define Rte_TypeDef_BmwDesIninOptSetAIdxRec1
typedef struct
{
  uint8 BmwDesIninOptSetAIdx;
  boolean BmwDesIninOptSetAIdxWrSts;
} BmwDesIninOptSetAIdxRec1;

# define Rte_TypeDef_BmwRtIdx1
typedef uint8 BmwRtIdx1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
