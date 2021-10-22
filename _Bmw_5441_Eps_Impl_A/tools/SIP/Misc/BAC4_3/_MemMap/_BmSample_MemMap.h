/**
*  \file
*
*  \brief       BMW Module Bm
*
*  MemMap file for module BmSample.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2016 - 2017
*
*  \version     5.0.1
*
*  \remarks     ---
*
*/

/*@@@Vector: Commented out
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/

#if 0

#elif defined (BmSample_START_SEC_CODE)
  #undef BmSample_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_BmSample_SEC_CODE
    #error "BmSample_SEC_CODE already open"
  #endif
  #define CHK_BmSample_SEC_CODE

#elif defined (BmSample_STOP_SEC_CODE)
  #undef BmSample_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_BmSample_SEC_CODE
    #error "BmSample_SEC_CODE not open"
  #endif
  #undef CHK_BmSample_SEC_CODE

#else
  #error "error section does not exist in BmSample_MemMap.h"
#endif
#include "MemMap.h"
