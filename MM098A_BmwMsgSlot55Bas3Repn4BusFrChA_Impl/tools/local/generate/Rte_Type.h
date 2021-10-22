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
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM098A_BmwMsgSlot55Bas3Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot55Bas3Repn4BusFrChA
 *  Generated at:  Fri Jun 22 07:51:47 2018
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

# define Rte_TypeDef_ALIV_V_VEH1
typedef unsigned char ALIV_V_VEH1;

# define Rte_TypeDef_CRC_V_VEH1
typedef unsigned char CRC_V_VEH1;

# define Rte_TypeDef_DVCO_VEH1
typedef unsigned char DVCO_VEH1;

# define Rte_TypeDef_QU_V_VEH_COG1
typedef unsigned char QU_V_VEH_COG1;

# define Rte_TypeDef_ST_V_VEH_NSS1
typedef unsigned char ST_V_VEH_NSS1;

# define Rte_TypeDef_V_VEH_COG1
typedef unsigned short V_VEH_COG1;

# define Rte_TypeDef_V_VEH_dummy_39_391
typedef unsigned char V_VEH_dummy_39_391;

# define Rte_TypeDef_sigGroup_V_VEH1
typedef struct
{
  V_VEH_COG1 V_VEH_COG;
  ST_V_VEH_NSS1 ST_V_VEH_NSS;
  QU_V_VEH_COG1 QU_V_VEH_COG;
  ALIV_V_VEH1 ALIV_V_VEH;
  V_VEH_dummy_39_391 V_VEH_dummy_39_39;
  DVCO_VEH1 DVCO_VEH;
  CRC_V_VEH1 CRC_V_VEH;
} sigGroup_V_VEH1;

# define Rte_TypeDef_BmwCogVehSpdQlfr1
typedef uint8 BmwCogVehSpdQlfr1;

# define Rte_TypeDef_BmwNearStillVehSpdSts1
typedef uint8 BmwNearStillVehSpdSts1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
