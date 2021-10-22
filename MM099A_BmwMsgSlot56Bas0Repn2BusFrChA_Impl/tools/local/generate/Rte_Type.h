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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM099A_BmwMsgSlot56Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot56Bas0Repn2BusFrChA
 *  Generated at:  Wed Jun  6 15:31:36 2018
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

# define Rte_TypeDef_CRC_VYAW_VEH1
typedef unsigned char CRC_VYAW_VEH1;

# define Rte_TypeDef_VYAW_VEH1
typedef unsigned short VYAW_VEH1;

# define Rte_TypeDef_VYAW_VEH_ERR_AMP1
typedef unsigned short VYAW_VEH_ERR_AMP1;

# define Rte_TypeDef_VYAW_VEH_dummy_12_151
typedef unsigned char VYAW_VEH_dummy_12_151;

# define Rte_TypeDef_ALIV_VYAW_VEH1
typedef unsigned char ALIV_VYAW_VEH1;

# define Rte_TypeDef_BmwVehYawQlfr1
typedef unsigned char BmwVehYawQlfr1;

# define Rte_TypeDef_QU_VYAW_VEH1
typedef unsigned char QU_VYAW_VEH1;

# define Rte_TypeDef_sigGroup_VYAW_VEH1
typedef struct
{
  QU_VYAW_VEH1 QU_VYAW_VEH;
  VYAW_VEH_ERR_AMP1 VYAW_VEH_ERR_AMP;
  VYAW_VEH1 VYAW_VEH;
  VYAW_VEH_dummy_12_151 VYAW_VEH_dummy_12_15;
  CRC_VYAW_VEH1 CRC_VYAW_VEH;
  ALIV_VYAW_VEH1 ALIV_VYAW_VEH;
} sigGroup_VYAW_VEH1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
