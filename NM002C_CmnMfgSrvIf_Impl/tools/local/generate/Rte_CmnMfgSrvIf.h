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
 *          File:  Rte_CmnMfgSrvIf.h
 *        Config:  C:/Workspace/_EA4/_Components/NM002C_CmnMfgSrvIf_Impl-kzdyfh/NM002C_CmnMfgSrvIf_Impl/tools/Component.dpa
 *     SW-C Type:  CmnMfgSrvIf
 *  Generated at:  Fri Feb  2 13:12:55 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CmnMfgSrvIf> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CMNMFGSRVIF_H
# define _RTE_CMNMFGSRVIF_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CmnMfgSrvIf_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CmnMfgSrvIf
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CmnMfgSrvIf, RTE_CONST, RTE_CONST) Rte_Inst_CmnMfgSrvIf; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CmnMfgSrvIf, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CmnMfgSrvIf_CmnMfgSrvCmnMfgSrvMaiFct_Oper(uint8 CmnMfgSrvCmnMfgSrvSrvId, uint8 CmnMfgSrvCmnMfgSrvSubFct, uint16 CmnMfgSrvCmnMfgSrvPrmId, P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) CmnMfgSrvCmnMfgSrvDataBufferPtr, uint16 CmnMfgSrvCmnMfgSrvReqLen, P2VAR(uint16, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) CmnMfgSrvCmnMfgSrvRespLen, P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) CmnMfgSrvCmnMfgSrvRespCod); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CmnMfgSrvCmnMfgSrvMaiFct_Oper Rte_Call_CmnMfgSrvIf_CmnMfgSrvCmnMfgSrvMaiFct_Oper




# define CmnMfgSrvIf_START_SEC_CODE
# include "CmnMfgSrvIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmnMfgSrvIfInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CmnMfgSrvCmnMfgSrvMaiFct_Oper(uint8 CmnMfgSrvCmnMfgSrvSrvId, uint8 CmnMfgSrvCmnMfgSrvSubFct, uint16 CmnMfgSrvCmnMfgSrvPrmId, uint8 *CmnMfgSrvCmnMfgSrvDataBufferPtr, uint16 CmnMfgSrvCmnMfgSrvReqLen, uint16 *CmnMfgSrvCmnMfgSrvRespLen, uint8 *CmnMfgSrvCmnMfgSrvRespCod)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CmnMfgSrvIfInit1 CmnMfgSrvIfInit1
FUNC(void, CmnMfgSrvIf_CODE) CmnMfgSrvIfInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CmnMfgSrvIf_STOP_SEC_CODE
# include "CmnMfgSrvIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CMNMFGSRVIF_H */

#include "Rte_Stubs.h"
