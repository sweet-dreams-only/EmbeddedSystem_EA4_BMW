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
#if 0

#elif defined (Bs_START_SEC_CODE)
#undef Bs_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #define CHK_Bs_SEC_CODE

#elif defined (Bs_START_SEC_VAR_NO_INIT_8)
#undef Bs_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT                                     /* mapped to default var section */
  #define CHK_Bs_SEC_VAR_NO_INIT_8

#elif defined (Bs_START_SEC_VAR_NO_INIT_UNSPECIFIED)
#undef Bs_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED                           /* mapped to default var section */
  #define CHK_Bs_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined (Bs_START_SEC_VAR_INIT_UNSPECIFIED)
#undef Bs_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED                              /* mapped to default init var section */
  #define CHK_Bs_SEC_VAR_INIT_UNSPECIFIED

#elif defined (Bs_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
#undef Bs_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED
  #define CHK_Bs_SEC_VAR_SAVED_ZONE_UNSPECIFIED

#elif defined (Bs_START_SEC_CONST_8)
#undef Bs_START_SEC_CONST_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #define CHK_Bs_SEC_CONST_8

#elif defined (Bs_START_SEC_CONST_UNSPECIFIED)
#undef Bs_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #define CHK_Bs_SEC_CONST_UNSPECIFIED

#elif defined (Bs_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED)
#undef Bs_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #define CHK_Bs_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED

#elif defined (Bs_STOP_SEC_CODE)
#undef Bs_STOP_SEC_CODE
  #ifndef CHK_Bs_SEC_CODE
    #error "Bs_SEC_CODE not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #undef CHK_Bs_SEC_CODE

#elif defined (Bs_STOP_SEC_VAR_NO_INIT_8)
#undef Bs_STOP_SEC_VAR_NO_INIT_8
  #ifndef CHK_Bs_SEC_VAR_NO_INIT_8
    #error "Bs_SEC_VAR_NO_INIT_8 not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #undef CHK_Bs_SEC_VAR_NO_INIT_8

#elif defined (Bs_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
#undef Bs_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #ifndef CHK_Bs_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "Bs_SEC_VAR_NO_INIT_UNSPECIFIED not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #undef CHK_Bs_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined (Bs_STOP_SEC_VAR_INIT_UNSPECIFIED)
#undef Bs_STOP_SEC_VAR_INIT_UNSPECIFIED
  #ifndef CHK_Bs_SEC_VAR_INIT_UNSPECIFIED
    #error "Bs_SEC_VAR_INIT_UNSPECIFIED not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #undef CHK_Bs_SEC_VAR_INIT_UNSPECIFIED

#elif defined (Bs_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
#undef Bs_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #ifndef CHK_Bs_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #error "Bs_SEC_VAR_SAVED_ZONE_UNSPECIFIED not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #undef CHK_Bs_SEC_VAR_SAVED_ZONE_UNSPECIFIED

#elif defined (Bs_STOP_SEC_CONST_8)
#undef Bs_STOP_SEC_CONST_8
  #ifndef CHK_Bs_SEC_CONST_8
    #error "Bs_SEC_CONST_8 not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #undef CHK_Bs_SEC_CONST_8

#elif defined (Bs_STOP_SEC_CONST_UNSPECIFIED)
#undef Bs_STOP_SEC_CONST_UNSPECIFIED
  #ifndef CHK_Bs_SEC_CONST_UNSPECIFIED
    #error "Bs_SEC_CONST_UNSPECIFIED not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #undef CHK_Bs_SEC_CONST_UNSPECIFIED

#elif defined (Bs_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED)
#undef Bs_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
  #ifndef CHK_Bs_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
    #error "Bs_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED not open"
  #endif
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #undef CHK_Bs_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED

#else
#error "Error: section does not exist in Bs_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Bs sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
