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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM101A_BmwMsgSlot68Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot68Bas0Repn2BusFrChA
 *  Generated at:  Fri Jun  8 11:32:28 2018
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

# define Rte_TypeDef_CRC_TAR_QTA_STMOM_DV1
typedef unsigned char CRC_TAR_QTA_STMOM_DV1;

# define Rte_TypeDef_CRC_TAR_STMOM_DV_ACT1
typedef unsigned char CRC_TAR_STMOM_DV_ACT1;

# define Rte_TypeDef_FACT_ASS_STMOM_FTAX1
typedef unsigned char FACT_ASS_STMOM_FTAX1;

# define Rte_TypeDef_FACT_CTRR_STMOM_FTAX1
typedef unsigned char FACT_CTRR_STMOM_FTAX1;

# define Rte_TypeDef_FACT_DMPNG_STMOM_FTAX1
typedef unsigned char FACT_DMPNG_STMOM_FTAX1;

# define Rte_TypeDef_TAR_QTA_STMOM_DV1
typedef unsigned short TAR_QTA_STMOM_DV1;

# define Rte_TypeDef_TAR_QTA_STRMOM_DV_dummy_12_151
typedef unsigned char TAR_QTA_STRMOM_DV_dummy_12_151;

# define Rte_TypeDef_TAR_STMOM_DV_ACT1
typedef unsigned short TAR_STMOM_DV_ACT1;

# define Rte_TypeDef_TAR_STMOM_DV_ACT_dummy_12_151
typedef unsigned char TAR_STMOM_DV_ACT_dummy_12_151;

# define Rte_TypeDef_TAR_STMOM_DV_ACT_dummy_32_511
typedef unsigned long TAR_STMOM_DV_ACT_dummy_32_511;

# define Rte_TypeDef_ALIV_TAR_QTA_STMOM_DV1
typedef unsigned char ALIV_TAR_QTA_STMOM_DV1;

# define Rte_TypeDef_ALIV_TAR_STMOM_DV_ACT1
typedef unsigned char ALIV_TAR_STMOM_DV_ACT1;

# define Rte_TypeDef_BmwEpsDeactvnCtrl1
typedef unsigned char BmwEpsDeactvnCtrl1;

# define Rte_TypeDef_BmwOvrlCmdQlfr1
typedef unsigned char BmwOvrlCmdQlfr1;

# define Rte_TypeDef_BmwTrfcJamAssiDampgStReq1
typedef unsigned char BmwTrfcJamAssiDampgStReq1;

# define Rte_TypeDef_CTR_DEAC_EPS_FNS1
typedef unsigned char CTR_DEAC_EPS_FNS1;

# define Rte_TypeDef_FACT_DMPNG_ADDON_STMOM_FTAX1
typedef unsigned char FACT_DMPNG_ADDON_STMOM_FTAX1;

# define Rte_TypeDef_QU_TAR_DMPNG_ADDON_STMOM_FTAX1
typedef unsigned char QU_TAR_DMPNG_ADDON_STMOM_FTAX1;

# define Rte_TypeDef_QU_TAR_FACT_STMOM_FTAX1
typedef unsigned char QU_TAR_FACT_STMOM_FTAX1;

# define Rte_TypeDef_QU_TAR_QTA_STMOM_DV1
typedef unsigned char QU_TAR_QTA_STMOM_DV1;

# define Rte_TypeDef_QU_TAR_STMOM_DV_ACT1
typedef unsigned char QU_TAR_STMOM_DV_ACT1;

# define Rte_TypeDef_sigGroup_TAR_QTA_STRMOM_DV1
typedef struct
{
  FACT_DMPNG_STMOM_FTAX1 FACT_DMPNG_STMOM_FTAX;
  QU_TAR_QTA_STMOM_DV1 QU_TAR_QTA_STMOM_DV;
  ALIV_TAR_QTA_STMOM_DV1 ALIV_TAR_QTA_STMOM_DV;
  QU_TAR_FACT_STMOM_FTAX1 QU_TAR_FACT_STMOM_FTAX;
  CTR_DEAC_EPS_FNS1 CTR_DEAC_EPS_FNS;
  FACT_CTRR_STMOM_FTAX1 FACT_CTRR_STMOM_FTAX;
  TAR_QTA_STRMOM_DV_dummy_12_151 TAR_QTA_STRMOM_DV_dummy_12_15;
  FACT_ASS_STMOM_FTAX1 FACT_ASS_STMOM_FTAX;
  TAR_QTA_STMOM_DV1 TAR_QTA_STMOM_DV;
  CRC_TAR_QTA_STMOM_DV1 CRC_TAR_QTA_STMOM_DV;
} sigGroup_TAR_QTA_STRMOM_DV1;

# define Rte_TypeDef_sigGroup_TAR_STMOM_DV_ACT1
typedef struct
{
  TAR_STMOM_DV_ACT_dummy_12_151 TAR_STMOM_DV_ACT_dummy_12_15;
  TAR_STMOM_DV_ACT_dummy_32_511 TAR_STMOM_DV_ACT_dummy_32_51;
  QU_TAR_DMPNG_ADDON_STMOM_FTAX1 QU_TAR_DMPNG_ADDON_STMOM_FTAX;
  FACT_DMPNG_ADDON_STMOM_FTAX1 FACT_DMPNG_ADDON_STMOM_FTAX;
  TAR_STMOM_DV_ACT1 TAR_STMOM_DV_ACT;
  CRC_TAR_STMOM_DV_ACT1 CRC_TAR_STMOM_DV_ACT;
  QU_TAR_STMOM_DV_ACT1 QU_TAR_STMOM_DV_ACT;
  ALIV_TAR_STMOM_DV_ACT1 ALIV_TAR_STMOM_DV_ACT;
} sigGroup_TAR_STMOM_DV_ACT1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
