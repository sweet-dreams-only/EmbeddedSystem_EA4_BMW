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
 *            Module: FrSM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrSM_Lcfg.c
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




/* PRQA S 0857 NumberOfMacroDefinitions */ /* MD_MSR_1.1 */

#define FRSM_LCFG_C

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "FrSM.h"



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  FrSM_ClusterConfig
**********************************************************************************************************************/
/** 
  \var    FrSM_ClusterConfig
  \brief  root config struct
  \details
  Element                         Description
  DurationT4                  
  Trcv_Handling               
  ControllerIndex             
  DurationT1                  
  DurationT2                  
  DurationT3                  
  FrIfClusterIndex            
  NetworkHandle               
  NumWakeupPatterns           
  StartupRepetitions          
  StartupRepetitionsWithWakeup
  TrcvStbyDelay               
  FrChannel                   
*/ 
#define FRSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(FrSM_ClusterConfigType, FRSM_CONST) FrSM_ClusterConfig[1] = {
    /* Index    DurationT4  Trcv_Handling  ControllerIndex  DurationT1  DurationT2  DurationT3  FrIfClusterIndex  NetworkHandle  NumWakeupPatterns  StartupRepetitions  StartupRepetitionsWithWakeup  TrcvStbyDelay  FrChannel    */
  { /*     0 */         0U,          TRUE,              0U,         1U,        10U,       100U,               0U,           0UL,                1U,                 0U,                           0U,            0U, FR_CHANNEL_A }
};
#define FRSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  FrSM_VarStruct
**********************************************************************************************************************/
/** 
  \var    FrSM_VarStruct
  \details
  Element                    Description
  Timer_ColdstartDelay   
  InternalState          
  Startup_Counter        
  Timer_RetryStartUp     
  Timer_StartUpMonitoring
  WakeUpPatternCounter   
  WakeUpType             
  RequestedComMode       
*/ 
#define FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(FrSM_VarStructType, FRSM_VAR_NOINIT) FrSM_VarStruct[1];
#define FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




/* START of Checksum include for - Ccl_AsrSmFrLinktimeCRC */

#define FRSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(FrSMSyncLossErrorIndicationFctPtrType, FRSM_CONST) FrSMSyncLossErrorIndicationFctPtr = NULL_PTR;





#define FRSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* -----------------------------------------------------------------------------
    FrSM Functions
 ----------------------------------------------------------------------------- */






#define FRSM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \internal
 * - #10 Call the internal main function with the internal cluster ID which belonges to the FrIf cluster ID of the indexed main function
 * \endinternal
 */
FUNC(void, FRSM_CODE) FrSM_MainFunction_0(void)
{
  FrSM_MainFunction( 0 );
}



#define FRSM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* END of Checksum include for - Ccl_AsrSmFrLinktimeCRC */


/* PRQA L:NumberOfMacroDefinitions */ /* MD_MSR_1.1 */

