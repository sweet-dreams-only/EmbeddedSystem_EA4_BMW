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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM102A_BmwMsgSlot68Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot68Bas1Repn2BusFrChA
 *  Generated at:  Wed Jun  6 09:22:12 2018
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

# define Rte_TypeDef_ALIV_ENERG_DGR_DRDY1
typedef unsigned char ALIV_ENERG_DGR_DRDY1;

# define Rte_TypeDef_CRC_ENERG_DGR_DRDY1
typedef unsigned char CRC_ENERG_DGR_DRDY1;

# define Rte_TypeDef_ENERG_DGR_DRDY_dummy_12_151
typedef unsigned char ENERG_DGR_DRDY_dummy_12_151;

# define Rte_TypeDef_BmwMaxCurrLimrSts1
typedef unsigned char BmwMaxCurrLimrSts1;

# define Rte_TypeDef_BmwRqrdCurrLimEpsSfty1
typedef unsigned char BmwRqrdCurrLimEpsSfty1;

# define Rte_TypeDef_ENERG_AVAI_ARS1
typedef unsigned char ENERG_AVAI_ARS1;

# define Rte_TypeDef_MAX_I_LD_SPEC_ARS1
typedef unsigned char MAX_I_LD_SPEC_ARS1;

# define Rte_TypeDef_MAX_I_RECUP_SPEC_ARS1
typedef unsigned char MAX_I_RECUP_SPEC_ARS1;

# define Rte_TypeDef_MAX_I_SPEC_BAX_STE1
typedef unsigned char MAX_I_SPEC_BAX_STE1;

# define Rte_TypeDef_MAX_I_SPEC_EPS1
typedef unsigned char MAX_I_SPEC_EPS1;

# define Rte_TypeDef_QU_DGR_AISP_ENERG1
typedef unsigned char QU_DGR_AISP_ENERG1;

# define Rte_TypeDef_RQ_CULI_EST_SFY1
typedef unsigned char RQ_CULI_EST_SFY1;

# define Rte_TypeDef_sigGroup_ENERG_DGR_DRDY1
typedef struct
{
  MAX_I_LD_SPEC_ARS1 MAX_I_LD_SPEC_ARS;
  MAX_I_RECUP_SPEC_ARS1 MAX_I_RECUP_SPEC_ARS;
  RQ_CULI_EST_SFY1 RQ_CULI_EST_SFY;
  ALIV_ENERG_DGR_DRDY1 ALIV_ENERG_DGR_DRDY;
  ENERG_AVAI_ARS1 ENERG_AVAI_ARS;
  QU_DGR_AISP_ENERG1 QU_DGR_AISP_ENERG;
  CRC_ENERG_DGR_DRDY1 CRC_ENERG_DGR_DRDY;
  MAX_I_SPEC_BAX_STE1 MAX_I_SPEC_BAX_STE;
  ENERG_DGR_DRDY_dummy_12_151 ENERG_DGR_DRDY_dummy_12_15;
  MAX_I_SPEC_EPS1 MAX_I_SPEC_EPS;
} sigGroup_ENERG_DGR_DRDY1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
