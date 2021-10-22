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
 *            Module: IoHwAb
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IoHwAb_Cfg.h
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


#if (!defined IOHWAB_CFG_H)
#define IOHWAB_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/

/* ===== MODULE INCLUDES ================================================== */
#include "Dio.h"
#include "Port.h"

/* ===== SCHM INCLUDE ===================================================== */ 
#include "SchM_IoHwAb.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/* ===== VERSION IDENTIFICATION =========================================== */
#define IOHWAB_CFG_MAJOR_VERSION  (6u) 
#define IOHWAB_CFG_MINOR_VERSION  (00u) 
#define IOHWAB_CFG_PATCH_VERSION  (00u) 



/* ====== API CONFIGURATION =============================================== */

#define IOHWAB_VERSION_INFO_API                 (STD_OFF)
#define IOHWAB_USE_INIT_FUNCTION                (STD_OFF)

/* ====== CONFIGURATION FOR DEVELOPMENT MODE ============================== */

#define IOHWAB_DEV_ERROR_DETECT                 (STD_ON)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


#define IoHwAb_GlobalSuspend() SchM_Enter_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()
#define IoHwAb_GlobalRestore() SchM_Exit_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Prototypes of Sender/Receiver functions can be found in Rte_IoHwAb.h */

/* Prototypes of Client/Server functions can be found in Rte_IoHwAb.h */

/* Prototypes of Handler functions can be found in Rte_IoHwAb.h */



#endif /* (!defined IOHWAB_CFG_H) */
/**********************************************************************************************************************
 *  END OF FILE: IoHwAb_Cfg.h
 **********************************************************************************************************************/
