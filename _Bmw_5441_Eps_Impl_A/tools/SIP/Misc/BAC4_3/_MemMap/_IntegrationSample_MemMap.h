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
#if 0

#elif defined (IntegrationSample_START_SEC_CODE)
  #undef IntegrationSample_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_IntegrationSample_SEC_CODE
    #error "IntegrationSample_SEC_CODE already open"
  #endif
  #define CHK_IntegrationSample_SEC_CODE
//  #pragma ghs section text="text_default"

#elif defined (IntegrationSample_START_SEC_CONST_UNSPECIFIED)
  #undef IntegrationSample_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_IntegrationSample_SEC_CONST_UNSPECIFIED
    #error "IntegrationSample_SEC_CONST_UNSPECIFIED already open"
  #endif
  #define CHK_IntegrationSample_SEC_CONST_UNSPECIFIED

#elif defined (IntegrationSample_STOP_SEC_CODE)
  #undef IntegrationSample_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_IntegrationSample_SEC_CODE
    #error "IntegrationSample_SEC_CODE not open"
  #endif
  #undef CHK_IntegrationSample_SEC_CODE
//  #pragma ghs section text=default

#elif defined (IntegrationSample_STOP_SEC_CONST_UNSPECIFIED)
  #undef IntegrationSample_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_IntegrationSample_SEC_CONST_UNSPECIFIED
    #error "IntegrationSample_SEC_CONST_UNSPECIFIED not open"
  #endif
  #undef CHK_IntegrationSample_SEC_CONST_UNSPECIFIED

#else
  #error "error section does not exist in this IntegrationSample memmap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of IntegrationSample sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

