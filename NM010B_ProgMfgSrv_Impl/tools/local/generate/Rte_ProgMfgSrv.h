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
 *          File:  Rte_ProgMfgSrv.h
 *        Config:  C:/Workspace/_EA4/_Components/NM010B_ProgMfgSrv_Impl-kzdyfh/NM010B_ProgMfgSrv_Impl/tools/Component.dpa
 *     SW-C Type:  ProgMfgSrv
 *  Generated at:  Fri May 18 08:11:18 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ProgMfgSrv> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PROGMFGSRV_H
# define _RTE_PROGMFGSRV_H

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

# include "Rte_ProgMfgSrv_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_ProgMfgSrv
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_ProgMfgSrv, RTE_CONST, RTE_CONST) Rte_Inst_ProgMfgSrv; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_ProgMfgSrv, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ProgMfgSrv_MotVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_PROGMFGSRV_APPL_VAR) BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ProgMfgSrv_MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ProgMfgSrv_TunVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_PROGMFGSRV_APPL_VAR) BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ProgMfgSrv_TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_MotVrntRead_Oper Rte_Call_ProgMfgSrv_MotVrntRead_Oper
# define Rte_Call_MotVrntWr_Oper Rte_Call_ProgMfgSrv_MotVrntWr_Oper
# define Rte_Call_TunVrntRead_Oper Rte_Call_ProgMfgSrv_TunVrntRead_Oper
# define Rte_Call_TunVrntWr_Oper Rte_Call_ProgMfgSrv_TunVrntWr_Oper




# define ProgMfgSrv_START_SEC_CODE
# include "ProgMfgSrv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ProgMfgSrvInit1
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
 *   Std_ReturnType Rte_Call_MotVrntRead_Oper(uint8 *BmwDesIninOptSetAIdx_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_MotVrntRead_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_MotVrntWr_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_TunVrntRead_Oper(uint8 *BmwDesIninIdx_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TunVrntRead_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TunVrntWr_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ProgMfgSrvInit1 ProgMfgSrvInit1
FUNC(void, ProgMfgSrv_CODE) ProgMfgSrvInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define ProgMfgSrv_STOP_SEC_CODE
# include "ProgMfgSrv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_MotVrntRead_PortIf1_E_NOT_OK (1U)

# define RTE_E_MotVrntWr_PortIf1_E_NOT_OK (1U)

# define RTE_E_TunVrntRead_PortIf1_E_NOT_OK (1U)

# define RTE_E_TunVrntWr_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PROGMFGSRV_H */
