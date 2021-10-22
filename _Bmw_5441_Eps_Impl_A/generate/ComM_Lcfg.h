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
 *            Module: ComM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Lcfg.h
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


#if !defined(COMM_LCFG_H)
#define COMM_LCFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Cfg.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL DATA
 ----------------------------------------------------------------------------- */

#define COMM_START_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

extern CONST(ComM_InhibitionStatusType, COMM_CONST) ComM_ECUGroupClassInit;

#define COMM_STOP_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451 */ 

/* PRQA L:EXTERNDECLARATIONS */

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_0
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the 
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);

/* -----------------------------------------------------------------------------
    &&&~ INTERNAL GENERATED FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

/*********************************************************************************************************************
  FUNCTION: ComM_RequestBusSMMode
*********************************************************************************************************************/
/*! \brief       Requests a communication mode by BusSM
 *  \param[in]   Channel                 Handle of the ComM channel, can be found in ComM_Lcfg.h
 *  \param[out]  ComMode                 Mode to request by BusSM
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_RequestBusSMMode(NetworkHandleType Channel, ComM_ModeType ComMode);

/*********************************************************************************************************************
  FUNCTION: ComM_GetCurrentBusSMMode
*********************************************************************************************************************/
/*! \brief       Queries the current BusSM communication mode of the corresponding channel.
 *  \param[in]   Channel                 Handle of the ComM channel, can be found in ComM_Lcfg.h
 *  \param[out]  ComMode                 Pointer where the current BusSM mode shall be stored
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_GetCurrentBusSMMode(NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, AUTOMATIC) ComMode);



#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#endif /* COMM_LCFG_H */

