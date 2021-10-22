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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM097A_BmwMsgSlot55Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot55Bas0Repn2BusFrChA
 *  Generated at:  Wed May 30 13:10:02 2018
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

# define Rte_TypeDef_ACLNY_COG1
typedef unsigned short ACLNY_COG1;

# define Rte_TypeDef_ACLNY_COG_ERR_AMP1
typedef unsigned short ACLNY_COG_ERR_AMP1;

# define Rte_TypeDef_ACLNY_MASSCNTR_dummy_12_151
typedef unsigned char ACLNY_MASSCNTR_dummy_12_151;

# define Rte_TypeDef_CRC_ACLNY_COG1
typedef unsigned char CRC_ACLNY_COG1;

# define Rte_TypeDef_ALIV_ACLNY_COG1
typedef unsigned char ALIV_ACLNY_COG1;

# define Rte_TypeDef_BmwVehLatAQlfr1
typedef unsigned char BmwVehLatAQlfr1;

# define Rte_TypeDef_QU_ACLNY_COG1
typedef unsigned char QU_ACLNY_COG1;

# define Rte_TypeDef_sigGroup_ACLNY_MASSCNTR1
typedef struct
{
  ACLNY_MASSCNTR_dummy_12_151 ACLNY_MASSCNTR_dummy_12_15;
  ACLNY_COG1 ACLNY_COG;
  QU_ACLNY_COG1 QU_ACLNY_COG;
  ACLNY_COG_ERR_AMP1 ACLNY_COG_ERR_AMP;
  ALIV_ACLNY_COG1 ALIV_ACLNY_COG;
  CRC_ACLNY_COG1 CRC_ACLNY_COG;
} sigGroup_ACLNY_MASSCNTR1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
