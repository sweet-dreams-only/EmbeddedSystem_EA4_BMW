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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ProgMfgSrv>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PROGMFGSRV_H
# define _RTE_PROGMFGSRV_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_ProgMfgSrv_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWTUNSETHNDLR_APPL_CODE) MotVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotVrntRead_Oper MotVrntRead_Oper
#  define RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWTUNSETHNDLR_APPL_CODE) MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotVrntWr_Oper MotVrntWr_Oper
#  define RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWTUNSETHNDLR_APPL_CODE) TunVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_TunVrntRead_Oper TunVrntRead_Oper
#  define RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWTUNSETHNDLR_APPL_CODE) TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_TunVrntWr_Oper TunVrntWr_Oper


# endif /* !defined(RTE_CORE) */


# define ProgMfgSrv_START_SEC_CODE
# include "ProgMfgSrv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ProgMfgSrvInit1 ProgMfgSrvInit1
# endif

FUNC(void, ProgMfgSrv_CODE) ProgMfgSrvInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define ProgMfgSrv_STOP_SEC_CODE
# include "ProgMfgSrv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_MotVrntRead_PortIf1_E_NOT_OK (1U)

#  define RTE_E_MotVrntWr_PortIf1_E_NOT_OK (1U)

#  define RTE_E_TunVrntRead_PortIf1_E_NOT_OK (1U)

#  define RTE_E_TunVrntWr_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PROGMFGSRV_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
