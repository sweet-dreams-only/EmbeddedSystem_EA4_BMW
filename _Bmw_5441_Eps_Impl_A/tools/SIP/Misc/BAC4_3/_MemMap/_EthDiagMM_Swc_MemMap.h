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
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*BMW - Start*/

/* PRQA S 0883,0841 EOF */ /* This file is designed for multiple inclusion and is allowed
   to use #undef */

#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (EthDiagMM_START_SEC_CODE)
  #undef EthDiagMM_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_EthDiagMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_EthDiagMM_SEC_STARTED
  #define CHK_EthDiagMM_SEC_CODE_STARTED

#elif defined (EthDiagMM_Swc_START_SEC_CODE)
  #undef EthDiagMM_Swc_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_EthDiagMM_Swc_SEC_STARTED
    #error "EthDiagMM_Swc section not closed"
  #endif
  #define CHK_EthDiagMM_Swc_SEC_STARTED
  #define CHK_EthDiagMM_Swc_SEC_CODE_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (EthDiagMM_STOP_SEC_CODE)
  #undef EthDiagMM_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_EthDiagMM_SEC_CODE_STARTED
    #error "EthDiagMM_SEC_CODE not opened"
  #endif
  #undef CHK_EthDiagMM_SEC_STARTED
  #undef CHK_EthDiagMM_SEC_CODE_STARTED

#elif defined (EthDiagMM_Swc_STOP_SEC_CODE)
  #undef EthDiagMM_Swc_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_EthDiagMM_Swc_SEC_CODE_STARTED
    #error "EthDiagMM_Swc_SEC_CODE not opened"
  #endif
  #undef CHK_EthDiagMM_Swc_SEC_STARTED
  #undef CHK_EthDiagMM_Swc_SEC_CODE_STARTED

#else
  #error "Error: section does not exist in EthDiagMM_Swc_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of EthDiagMM_Swc sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

