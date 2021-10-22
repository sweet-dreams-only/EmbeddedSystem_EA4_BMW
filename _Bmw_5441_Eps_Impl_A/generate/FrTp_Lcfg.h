/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: FrTp
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTp_Lcfg.h
 *   Generation Time: 2018-07-30 19:49:07
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/



#if !defined (FRTP_LCFG_H)
#define FRTP_LCFG_H

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "FrTp_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern VAR(FrTp_RxStateType, FRTP_VAR_NOINIT) FrTp_RxState[28];
extern VAR(FrTp_TxStateType, FRTP_VAR_NOINIT) FrTp_TxState[14];

extern VAR(uint32, FRTP_VAR_NOINIT) FrTp_FrIfTxBuf[8U];

extern VAR(FrTp_ConnStateType, FRTP_VAR_NOINIT) FrTp_ConnState[28];
extern VAR(FrTp_DecoupPduAdminType, FRTP_VAR_NOINIT) FrTp_DecoupPduAdminData[1];
extern VAR(FrTp_TxPduPoolDataType, FRTP_VAR_NOINIT) FrTp_PoolData[1];


#define FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRTP_START_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Flag to check initialization */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
extern VAR(uint8, FRTP_VAR_NOINIT) FrTp_InitState;


#define FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRTP_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern VAR(uint8, FRTP_VAR_NOINIT) FrTp_RxFrIfPending[1];
extern VAR(uint8, FRTP_VAR_NOINIT) FrTp_TxFrIfPending[1];
extern VAR(uint8, FRTP_VAR_NOINIT) FrTp_RxCurrRoundRobChan;
extern VAR(uint8, FRTP_VAR_NOINIT) FrTp_TxCurrRoundRobChan;
extern VAR(uint16_least, FRTP_VAR_NOINIT) FrTp_RxSm_MaxIterations;
extern VAR(uint16_least, FRTP_VAR_NOINIT) FrTp_TxSm_MaxIterations;


#define FRTP_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define FRTP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONSTP2VAR(uint8, FRTP_CONST, FRTP_VAR_NOINIT) FrTp_RxBuf[28];
extern CONSTP2VAR(uint8, FRTP_CONST, FRTP_VAR_NOINIT) FrTp_TxBuf[14];

#define FRTP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRTP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



extern CONST(FrTp_RxPduPoolType, FRTP_CONST) FrTp_RxPduPools[2];
extern CONST(FrTp_TxPduPoolType, FRTP_CONST) FrTp_TxPduPools[1];
extern CONST(FrTp_RxPduInfoType, FRTP_CONST) FrTp_FrIfRxPdus[2];
extern CONST(FrTp_TxPduInfoType, FRTP_CONST) FrTp_FrIfTxPdus[1];
extern CONST(FrTp_ConnCfgType, FRTP_CONST) FrTp_ConnCfg[28];
extern CONST(PduIdType, FRTP_CONST) FrTp_TxPduSnv2TxPduIdx[1];
extern CONST(PduIdType, FRTP_CONST) FrTp_RxPduSnv2RxPduIdx[2];
extern CONST(PduIdType, FRTP_CONST) FrTp_TxSduSnv2ConnIdx[14];
extern CONST(PduIdType, FRTP_CONST) FrTp_RxSduSnv2ConnIdx[28];


#define FRTP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* FRTP_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Lcfg.h
 *********************************************************************************************************************/



