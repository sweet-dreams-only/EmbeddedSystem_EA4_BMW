/**
*  \file
*
*  \brief       BMW Module Bm
*
*  This file is a sample for the memory mapping header file of the BMW AUTOSAR Core
*  module "Bm".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2016 - 2017
*
*  \version     5.1.0
*
*  \remarks     This file contains all memory mapping macros of the module "Bm".
*
*/


/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 19.6, Reason: #undef is necessary according to memory abstraction
   PRQA S 0841 EOF

   MISRA-C:2004 Rule 19.15, Reason: File must be included repeatedly according to
   memory abstraction
   PRQA S 0883 EOF */

/*@@@Vector: Commented out
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/

#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (Bm_START_SEC_CODE)
  #undef Bm_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_Bm_SEC_STARTED
    #error "Bm section not closed"
  #endif
  #define CHK_Bm_SEC_STARTED
  #define CHK_Bm_SEC_CODE_STARTED

#elif defined (Bm_START_SEC_VAR_NO_INIT_8)
  #undef Bm_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT                                     /* mapped to default var section */
  #ifdef CHK_Bm_SEC_STARTED
    #error "Bm section not closed"
  #endif
  #define CHK_Bm_SEC_STARTED
  #define CHK_Bm_SEC_VAR_NO_INIT_8_STARTED

#elif defined (Bm_START_SEC_CODE_ENTRY_APPLICATION)
#undef Bm_START_SEC_CODE_ENTRY_APPLICATION
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #pragma section APPL_START_ADDR "APPL_START_ADDR"
  #if !defined( APPL_START_ADDR_USE_SECTION )
    #pragma use_section APPL_START_ADDR Bm_StartupApplication
	#define APPL_START_ADDR_USE_SECTION
  #endif
  #ifdef CHK_Bm_SEC_STARTED
    #error "Bm section not closed"
  #endif
  #define CHK_Bm_SEC_STARTED
    #pragma section APPL_START_ADDR "APPL_START_ADDR"
  #define CHK_Bm_SEC_CODE_ENTRY_APPLICATION_STARTED

#elif defined (Bm_START_SEC_CODE_ENTRY_BLU)
#undef Bm_START_SEC_CODE_ENTRY_BLU
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #pragma section BLU_START_ADDR "BLU_START_ADDR"
  #if !defined( BLU_START_ADDR_USE_SECTION )
    #pragma use_section BLU_START_ADDR Bm_StartupBlu
	#define BLU_START_ADDR_USE_SECTION
  #endif
  #ifdef CHK_Bm_SEC_STARTED
    #error "Bm section not closed"
  #endif
  #define CHK_Bm_SEC_STARTED
  #define CHK_Bm_SEC_CODE_ENTRY_BLU_STARTED

#elif defined (Bm_START_SEC_CODE_ENTRY_BOOTLOADER)
#undef Bm_START_SEC_CODE_ENTRY_BOOTLOADER
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #pragma section BL_START_ADDR "BL_START_ADDR"
  #if !defined( BL_START_ADDR_USE_SECTION )
    #pragma use_section BL_START_ADDR Bm_StartupBootloader
	#define BL_START_ADDR_USE_SECTION
  #endif
  #ifdef CHK_Bm_SEC_STARTED
    #error "Bm section not closed"
  #endif
  #define CHK_Bm_SEC_STARTED
  #define CHK_Bm_SEC_CODE_ENTRY_BOOTLOADER_STARTED
/*-------------------------------------------
   STOP Sections
--------------------------------------------*/

#elif defined (Bm_STOP_SEC_CODE)
  #undef Bm_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Bm_SEC_CODE_STARTED
    #error "Bm_SEC_CODE not opened"
  #endif
  #undef CHK_Bm_SEC_STARTED
  #undef CHK_Bm_SEC_CODE_STARTED

#elif defined (Bm_STOP_SEC_VAR_NO_INIT_8)
  #undef Bm_STOP_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Bm_SEC_VAR_NO_INIT_8_STARTED
    #error "Bm_SEC_VAR_NO_INIT_8 not opened"
  #endif
  #undef CHK_Bm_SEC_STARTED
  #undef CHK_Bm_SEC_VAR_NO_INIT_8_STARTED

#elif defined (Bm_STOP_SEC_CODE_ENTRY_APPLICATION)
#undef Bm_STOP_SEC_CODE_ENTRY_APPLICATION
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Bm_SEC_CODE_ENTRY_APPLICATION_STARTED
    #error "Bm_SEC_CODE_ENTRY_APPLICATION not opened"
  #endif
  #undef CHK_Bm_SEC_STARTED
  #undef CHK_Bm_SEC_CODE_ENTRY_APPLICATION_STARTED

#elif defined (Bm_STOP_SEC_CODE_ENTRY_BLU)
#undef Bm_STOP_SEC_CODE_ENTRY_BLU
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Bm_SEC_CODE_ENTRY_BLU_STARTED
    #error "Bm_SEC_CODE_ENTRY_BLU not opened"
  #endif
  #undef CHK_Bm_SEC_STARTED
  #undef CHK_Bm_SEC_CODE_ENTRY_BLU_STARTED

#elif defined (Bm_STOP_SEC_CODE_ENTRY_BOOTLOADER)
#undef Bm_STOP_SEC_CODE_ENTRY_BOOTLOADER
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Bm_SEC_CODE_ENTRY_BOOTLOADER_STARTED
    #error "Bm_SEC_CODE_ENTRY_BOOTLOADER not opened"
  #endif
  #undef CHK_Bm_SEC_STARTED
  #undef CHK_Bm_SEC_CODE_ENTRY_BOOTLOADER_STARTED

#else
  #error "Error: section does not exist in Bm_MemMap.h"
#endif
#include "MemMap.h"
