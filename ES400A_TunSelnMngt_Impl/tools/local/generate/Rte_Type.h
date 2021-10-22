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
 *        Config:  C:/Component/ES400A_TunSelnMngt_Impl-cz7lt6/ES400A_TunSelnMngt_Impl/tools/Component.dpa
 *     SW-C Type:  TunSelnMngt
 *  Generated at:  Wed May 16 10:51:33 2018
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

# define Rte_TypeDef_AdrMpgReqTyp1
typedef uint8 AdrMpgReqTyp1;

# define Rte_TypeDef_CalCopySts1
typedef uint8 CalCopySts1;

# define Rte_TypeDef_GetSegMod1
typedef uint8 GetSegMod1;

# define Rte_TypeDef_NtcNr1
typedef uint16 NtcNr1;

# define Rte_TypeDef_NtcSts1
typedef uint8 NtcSts1;

# define Rte_TypeDef_OnlineCalStsRec2
typedef struct
{
  Ary1D_OnlineCalSegInfoRec1_TunSelnMngt1 Seg;
  CalCopySts1 CopySts;
  uint8 ActvGroup;
  uint8 ActvInin;
  uint8 ActvIninOptSetA;
  uint8 ActvRt;
} OnlineCalStsRec2;

# define Rte_TypeDef_RtIdxChgSts1
typedef uint8 RtIdxChgSts1;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# endif

/* Add to Rte_Types.h at the bottom */

/* The following were added manually since the component project does not generate teh Rte tables or the data types */
typedef P2CONST(void, TYPEDEF, RTE_CONST) Rte_ParameterRefType;
typedef Rte_ParameterRefType Rte_ParameterRefTabType[36];
typedef P2CONST(Rte_ParameterRefType, TYPEDEF, RTE_CONST) Rte_ParameterBaseType;
extern CONST(Rte_ParameterRefTabType, RTE_CONST) RteParameterRefTab;
extern VAR(Rte_ParameterBaseType, RTE_VAR_NOINIT) RteParameterBase;

/* The following are based on the configuration that you have created for the component. */
typedef struct
{
	uint32 CalA;
	uint32 CalB;
} Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type;
typedef struct
{
	uint32 CalA;
	uint32 CalB;
} Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type;  
typedef struct
{
	uint32 CalA;
	uint32 CalB;
} Rte_Calprm_CalRegn01Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type;
typedef struct
{
	uint32 CalA;
	uint32 CalB;
} Rte_Calprm_CalRegn02Inin00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type;
typedef struct
{
	uint32 CalA;
	uint32 CalB;
} Rte_Calprm_CalRegn03IninOptSetA00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type;

#define Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP 0U
#define Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP 1U
#define Rte_CalprmElementGroup_CalRegn02Inin00GroupB_DEFAULT_RTE_CALPRM_GROUP 2U
#define Rte_CalprmElementGroup_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP 3U
#define Rte_CalprmElementGroup_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP 4U
#define Rte_CalprmElementGroup_CalRegn02Inin01GroupB_DEFAULT_RTE_CALPRM_GROUP 5U
#define Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP 6U
#define Rte_CalprmElementGroup_CalRegn03IninOptSetA00GroupC_DEFAULT_RTE_CALPRM_GROUP 7U
#define Rte_CalprmElementGroup_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP 8U
#define Rte_CalprmElementGroup_CalRegn03IninOptSetA01GroupC_DEFAULT_RTE_CALPRM_GROUP 9U
#define Rte_CalprmElementGroup_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP 10U
#define Rte_CalprmElementGroup_CalRegn03IninOptSetA02GroupC_DEFAULT_RTE_CALPRM_GROUP 11U
#define Rte_CalprmElementGroup_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP 12U
#define Rte_CalprmElementGroup_CalRegn01Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP 13U
#define Rte_CalprmElementGroup_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP 14U
#define Rte_CalprmElementGroup_CalRegn01Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP 15U
#define Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP 16U



/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

#endif /* _RTE_TYPE_H */
