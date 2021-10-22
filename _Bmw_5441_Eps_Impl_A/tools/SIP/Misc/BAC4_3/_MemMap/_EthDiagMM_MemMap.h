/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW CDD EthDiagMM
*
*  This file is a sample for the memory mapping header file of the
*  BMW AUTOSAR Core module "EthDiagMM".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*  \remarks     This file contains all memory mapping macros of the
*               module "EthDiagMM".
*
*/
/*----------------------------------------------------------------------------*/

/* PRQA S 0883,0841 EOF */ /* This file is designed for multiple inclusion and is allowed
   to use #undef */
/*@@@Vector: Commented out
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/
   
#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (ETHDIAGMM_START_SEC_CODE)
  #undef ETHDIAGMM_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CODE_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_INIT_16)
  #undef ETHDIAGMM_START_SEC_VAR_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_16BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_INIT_16_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_INIT_8)
  #undef ETHDIAGMM_START_SEC_VAR_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_8BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_INIT_8_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_NOINIT_8)
  #undef ETHDIAGMM_START_SEC_VAR_NOINIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_NOINIT_8_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_NOINIT_BOOTLDSHARED_8)
#undef ETHDIAGMM_START_SEC_VAR_NOINIT_BOOTLDSHARED_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
   #pragma section SDATA ".sdata" "ETHDIAGMM_BOOTLDSHARED" far-absolute
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_8_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_INIT_BOOLEAN)
  #undef ETHDIAGMM_START_SEC_VAR_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_8BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef ETHDIAGMM_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef ETHDIAGMM_START_SEC_VAR_NOINIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
#pragma section DATA
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_NOINIT_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_NOINIT_32)
  #undef ETHDIAGMM_START_SEC_VAR_NOINIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_32BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_NOINIT_32_STARTED

#elif defined (ETHDIAGMM_START_SEC_VAR_NOINIT_BOOTLDSHARED_32)
#undef ETHDIAGMM_START_SEC_VAR_NOINIT_BOOTLDSHARED_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_32BIT
   #pragma section SDATA ".sdata" "ETHDIAGMM_BOOTLDSHARED" far-absolute
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_32_STARTED

#elif defined (ETHDIAGMM_START_SEC_CONST_8)
  #undef ETHDIAGMM_START_SEC_CONST_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CONST_8_STARTED

#elif defined (ETHDIAGMM_START_SEC_CONST_16)
  #undef ETHDIAGMM_START_SEC_CONST_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_16BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CONST_16_STARTED

#elif defined (ETHDIAGMM_START_SEC_CONST_UNSPECIFIED)
  #undef ETHDIAGMM_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef ETHDIAGMM_START_SEC_CONFIG_DATA_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CONFIG_DATA_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_START_SEC_CONFIG_DATA_32)
  #undef ETHDIAGMM_START_SEC_CONFIG_DATA_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_32BIT
  #ifdef CHK_ETHDIAGMM_SEC_STARTED
    #error "EthDiagMM section not closed"
  #endif
  #define CHK_ETHDIAGMM_SEC_STARTED
  #define CHK_ETHDIAGMM_SEC_CONFIG_DATA_32_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (ETHDIAGMM_STOP_SEC_CODE)
  #undef ETHDIAGMM_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_ETHDIAGMM_SEC_CODE_STARTED
    #error "ETHDIAGMM_SEC_CODE not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CODE_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_INIT_8)
  #undef ETHDIAGMM_STOP_SEC_VAR_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_INIT_8_STARTED
    #error "ETHDIAGMM_SEC_VAR_INIT_8 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_INIT_8_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_NOINIT_8)
  #undef ETHDIAGMM_STOP_SEC_VAR_NOINIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_NOINIT_8_STARTED
    #error "ETHDIAGMM_SEC_VAR_NOINIT_8 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_NOINIT_8_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_NOINIT_BOOTLDSHARED_8)
#undef ETHDIAGMM_STOP_SEC_VAR_NOINIT_BOOTLDSHARED_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_8_STARTED
    #error "ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_8 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_8_STARTED
  #pragma section SDATA

#elif defined (ETHDIAGMM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef ETHDIAGMM_STOP_SEC_VAR_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_INIT_BOOLEAN_STARTED
    #error "ETHDIAGMM_SEC_VAR_INIT_BOOLEAN not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_INIT_16)
  #undef ETHDIAGMM_STOP_SEC_VAR_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_INIT_16_STARTED
    #error "ETHDIAGMM_SEC_VAR_INIT_16 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_INIT_16_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef ETHDIAGMM_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_INIT_UNSPECIFIED_STARTED
    #error "ETHDIAGMM_SEC_VAR_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef ETHDIAGMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
 #pragma section
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_NOINIT_UNSPECIFIED_STARTED
    #error "ETHDIAGMM_SEC_VAR_NOINIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_NOINIT_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_NOINIT_32)
  #undef ETHDIAGMM_STOP_SEC_VAR_NOINIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_NOINIT_32_STARTED
    #error "ETHDIAGMM_SEC_VAR_NOINIT_32 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_NOINIT_32_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_VAR_NOINIT_BOOTLDSHARED_32)
#undef ETHDIAGMM_STOP_SEC_VAR_NOINIT_BOOTLDSHARED_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_32_STARTED
    #error "ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_32 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_VAR_NOINIT_BOOTLDSHARED_32_STARTED
  #pragma section SDATA

#elif defined (ETHDIAGMM_STOP_SEC_CONST_8)
  #undef ETHDIAGMM_STOP_SEC_CONST_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_ETHDIAGMM_SEC_CONST_8_STARTED
    #error "ETHDIAGMM_SEC_CONST_8 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CONST_8_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_CONST_16)
  #undef ETHDIAGMM_STOP_SEC_CONST_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_ETHDIAGMM_SEC_CONST_16_STARTED
    #error "ETHDIAGMM_SEC_CONST_16 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CONST_16_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_CONST_UNSPECIFIED)
  #undef ETHDIAGMM_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_ETHDIAGMM_SEC_CONST_UNSPECIFIED_STARTED
    #error "ETHDIAGMM_SEC_CONST_UNSPECIFIED not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef ETHDIAGMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_ETHDIAGMM_SEC_CONFIG_DATA_UNSPECIFIED_STARTED
    #error "ETHDIAGMM_SEC_CONFIG_DATA_UNSPECIFIED not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CONFIG_DATA_UNSPECIFIED_STARTED

#elif defined (ETHDIAGMM_STOP_SEC_CONFIG_DATA_32)
  #undef ETHDIAGMM_STOP_SEC_CONFIG_DATA_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_ETHDIAGMM_SEC_CONFIG_DATA_32_STARTED
    #error "ETHDIAGMM_SEC_CONFIG_DATA_32 not opened"
  #endif
  #undef CHK_ETHDIAGMM_SEC_STARTED
  #undef CHK_ETHDIAGMM_SEC_CONFIG_DATA_32_STARTED

#else
  #error "Error: section does not exist in EthDiagMM_MemMap.h"
#endif

/*@@@viswmc: Mapping of EthDiagMM sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"
