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
 *        Config:  C:/Component/MM109A_BmwMsgSlot121Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot121Bas1Repn2BusFrChA
 *  Generated at:  Sat Nov  4 14:51:38 2017
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

# define Rte_TypeDef_ALIV_CON_VEH1
typedef unsigned char ALIV_CON_VEH1;

# define Rte_TypeDef_CON_VEH_dummy_56_631
typedef unsigned char CON_VEH_dummy_56_631;

# define Rte_TypeDef_CRC_CON_VEH1
typedef unsigned char CRC_CON_VEH1;

# define Rte_TypeDef_CTR_FKTN_PRTNT1
typedef unsigned long CTR_FKTN_PRTNT1;

# define Rte_TypeDef_CTR_BS_PRTNT1
typedef unsigned char CTR_BS_PRTNT1;

# define Rte_TypeDef_QU_ST_CON_VEH1
typedef unsigned char QU_ST_CON_VEH1;

# define Rte_TypeDef_QU_V_VEH_COG1
typedef unsigned char QU_V_VEH_COG1;

# define Rte_TypeDef_ST_CON_VEH1
typedef unsigned char ST_CON_VEH1;

# define Rte_TypeDef_sigGroup_CON_VEH1
typedef struct
{
  CTR_FKTN_PRTNT1 CTR_FKTN_PRTNT;
  QU_ST_CON_VEH1 QU_ST_CON_VEH;
  CRC_CON_VEH1 CRC_CON_VEH;
  ST_CON_VEH1 ST_CON_VEH;
  CTR_BS_PRTNT1 CTR_BS_PRTNT;
  ALIV_CON_VEH1 ALIV_CON_VEH;
  CON_VEH_dummy_56_631 CON_VEH_dummy_56_63;
} sigGroup_CON_VEH1;

# define Rte_TypeDef_BmwBasPtlNetCtrl1
typedef uint8 BmwBasPtlNetCtrl1;

# define Rte_TypeDef_BmwVehCdn1
typedef uint8 BmwVehCdn1;

# define Rte_TypeDef_BmwVehCdnQlfr1
typedef uint8 BmwVehCdnQlfr1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
