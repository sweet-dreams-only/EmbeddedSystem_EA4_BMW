/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  This file is a sample for the memory mapping header file of the
*  BMW AUTOSAR Core module "Dlog".
*
*  \project BMW AUTOSAR Core
*
*  \par To be changed by user:
*  yes
*
*  \copyright BMW AG 2012 - 2016
*
*  \remarks This file shall contain all memory mapping macros of the
*           module "Dlog".
*
*  \remarks The content of this file only serves as an example. If this file
*           is platform dependent, this shall be mentioned here.
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 19.6, Reason: #undef is necessary according to memory abstraction
   PRQA S 0841 EOF

   MISRA-C:2004 Rule 19.15, Reason: File must be included repeatedly according to
   memory abstraction
   PRQA S 0883 EOF */

/* Nxtr Commend: KJS - Template was changed to align closer to what our 
 * other MemMap header files are like. */

 /* Code Sections */
#ifdef Dlog_START_SEC_CODE
    #undef     Dlog_START_SEC_CODE
    #define    START_SEC_CODE
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CODE
    #undef     Dlog_STOP_SEC_CODE
    #define    STOP_SEC_CODE
    #include "MemMap.h"
#endif


/* Const Sections */

#ifdef Dlog_START_SEC_CONST_16
    #undef     Dlog_START_SEC_CONST_16
    #define    START_SEC_CONST_16BIT
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CONST_16
    #undef     Dlog_STOP_SEC_CONST_16
    #define    STOP_SEC_CONST
    #include "MemMap.h"
#endif 

#ifdef Dlog_START_SEC_CONST_32
    #undef     Dlog_START_SEC_CONST_32
    #define    START_SEC_CONST_32BIT
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CONST_32
    #undef     Dlog_STOP_SEC_CONST_32
    #define    STOP_SEC_CONST
    #include "MemMap.h"
#endif

#ifdef Dlog_START_SEC_CONST_UNSPECIFIED
    #undef      Dlog_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CONST_UNSPECIFIED
    #undef      Dlog_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
    #include "MemMap.h"
#endif

/* -------------------------------------------------------------------------- */
/*             APPL (Application)                                             */
/* -------------------------------------------------------------------------- */
/* special section for SWE1 description table */
#ifdef APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #undef      APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE1DESC"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #undef      APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE1 flash status */
#ifdef APPL_START_SEC_CONST_SWE1_FLASH_STATUS
    #undef      APPL_START_SEC_CONST_SWE1_FLASH_STATUS
    #pragma ghs startdata
    #pragma ghs section rodata="SWE1STAT"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
    #undef      APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE1 signature */
#ifdef APPL_START_SEC_CONST_SWE1_SIGNATURE
    #undef      APPL_START_SEC_CONST_SWE1_SIGNATURE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE1SIGNATURE"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE1_SIGNATURE
    #undef      APPL_STOP_SEC_CONST_SWE1_SIGNATURE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* -------------------------------------------------------------------------- */
/*             APPL (SWE2)                                                    */
/* -------------------------------------------------------------------------- */
/* special section for SWE2 description table */
#ifdef APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #undef      APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE2DESC"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #undef      APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE2 flash status */
#ifdef APPL_START_SEC_CONST_SWE2_FLASH_STATUS
    #undef      APPL_START_SEC_CONST_SWE2_FLASH_STATUS
    #pragma ghs startdata
    #pragma ghs section rodata="SWE2STAT"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
    #undef      APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE2 signature */
#ifdef APPL_START_SEC_CONST_SWE2_SIGNATURE
    #undef      APPL_START_SEC_CONST_SWE2_SIGNATURE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE2SIGNATURE"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE2_SIGNATURE
    #undef      APPL_STOP_SEC_CONST_SWE2_SIGNATURE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif
  
  
/* -------------------------------------------------------------------------- */
/*             APPL (SWE3)                                                    */
/* -------------------------------------------------------------------------- */
/* special section for SWE2 description table */
#ifdef APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #undef      APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE3DESC"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #undef      APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE3 flash status */
#ifdef APPL_START_SEC_CONST_SWE3_FLASH_STATUS
    #undef      APPL_START_SEC_CONST_SWE3_FLASH_STATUS
    #pragma ghs startdata
    #pragma ghs section rodata="SWE3STAT"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
    #undef      APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for SWE3 signature */
#ifdef APPL_START_SEC_CONST_SWE3_SIGNATURE
    #undef      APPL_START_SEC_CONST_SWE3_SIGNATURE
    #pragma ghs startdata
    #pragma ghs section rodata="SWE3SIGNATURE"
#endif

#ifdef APPL_STOP_SEC_CONST_SWE3_SIGNATURE
    #undef      APPL_STOP_SEC_CONST_SWE3_SIGNATURE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* -------------------------------------------------------------------------- */
/*             BL (Bootloader)                                                */
/* -------------------------------------------------------------------------- */
#ifdef Dlog_START_SEC_CONST_SHARED_SWE_DATA
    #undef      Dlog_START_SEC_CONST_SHARED_SWE_DATA
    #pragma ghs startdata
    #pragma ghs section rodata="SHAREDSWEDATA"
#endif

#ifdef Dlog_STOP_SEC_CONST_SHARED_SWE_DATA
    #undef      Dlog_STOP_SEC_CONST_SHARED_SWE_DATA
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

#ifdef Dlog_START_SEC_CONST_SHARED_MEMSEGTBL_DATA
   #undef      Dlog_START_SEC_CONST_SHARED_MEMSEGTBL_DATA
   #define START_SEC_CONST_UNSPECIFIED
   #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CONST_SHARED_MEMSEGTBL_DATA
   #undef      Dlog_STOP_SEC_CONST_SHARED_MEMSEGTBL_DATA
   #define STOP_SEC_CONST
   #include "MemMap.h"
#endif

/* special section for boot SWE description table */
#ifdef BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #undef      BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #pragma ghs startdata
    #pragma ghs section rodata="BOOTSWEDESC"
#endif

#ifdef BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #undef      BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif


/* special section for boot SWE data */
#ifdef Dlog_START_SEC_CONST_BOOT_SWE_DATA
    #undef      Dlog_START_SEC_CONST_BOOT_SWE_DATA
    #define START_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_CONST_BOOT_SWE_DATA
    #undef      Dlog_STOP_SEC_CONST_BOOT_SWE_DATA
    #define STOP_SEC_CONST
    #include "MemMap.h"
#endif

/* special section for boot SWE flash status */
#ifdef BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
    #undef      BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
    #pragma ghs startdata
    #pragma ghs section rodata="BOOTSWESTAT"
#endif

#ifdef BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
    #undef      BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for boot SWE signature */
#ifdef BL_START_SEC_CONST_BOOTSWE_SIGNATURE
    #undef      BL_START_SEC_CONST_BOOTSWE_SIGNATURE
    #pragma ghs startdata
    #pragma ghs section rodata="BOOTSWESIGNATURE"
#endif

#ifdef BL_STOP_SEC_CONST_BOOTSWE_SIGNATURE
    #undef      BL_STOP_SEC_CONST_BOOTSWE_SIGNATURE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif
  
/* -------------------------------------------------------------------------- */
/*             BM (BootManager)                                               */
/* -------------------------------------------------------------------------- */

/* special section for hardware description table */
#ifdef Dlog_START_SEC_CONST_BM_HW_DESCRIPTION_TABLE
    #undef      Dlog_START_SEC_CONST_BM_HW_DESCRIPTION_TABLE
    #pragma ghs startdata
    #pragma ghs section rodata="HWEDESC"
#endif

#ifdef Dlog_STOP_SEC_CONST_BM_HW_DESCRIPTION_TABLE
    #undef      Dlog_STOP_SEC_CONST_BM_HW_DESCRIPTION_TABLE
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for const data that is shared between bootmanager, application and bootloader */
#ifdef Dlog_START_SEC_CONST_SHARED_BM_DATA
    #undef      Dlog_START_SEC_CONST_SHARED_BM_DATA
    #pragma ghs startdata
    #pragma ghs section rodata="COMMONBM"
#endif

#ifdef Dlog_STOP_SEC_CONST_SHARED_BM_DATA
    #undef      Dlog_STOP_SEC_CONST_SHARED_BM_DATA
    #pragma ghs section rodata=default
    #pragma ghs enddata
#endif

/* special section for swe status that is shared between bootmanager and bootloader */
#ifdef Dlog_START_SEC_VAR_SHARED_SWESTATUS
    #undef      Dlog_START_SEC_VAR_SHARED_SWESTATUS
    #pragma ghs startdata
    #pragma ghs section bss="DLOG_SWESTATUS"
#endif

#ifdef Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
    #undef      Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
    #pragma ghs section bss=default
    #pragma ghs enddata
#endif

/* special section for swe status that is shared between bootmanager and bootloader */
#ifdef Dlog_START_SEC_VAR_SHARED_SWEINFOS
    #undef      Dlog_START_SEC_VAR_SHARED_SWEINFOS
    #pragma ghs startdata
    #pragma ghs section bss="DLOG_SWEINFOS"
#endif

#ifdef Dlog_STOP_SEC_VAR_SHARED_SWEINFOS
    #undef      Dlog_STOP_SEC_VAR_SHARED_SWEINFOS
    #pragma ghs section bss=default
    #pragma ghs enddata
#endif

/* special section for swe status that is shared between bootmanager and bootloader */
#ifdef Dlog_START_SEC_VAR_SHARED_DATA
    #undef      Dlog_START_SEC_VAR_SHARED_DATA
    #pragma ghs startdata
    #pragma ghs section bss="DLOG_SWEDATA"
#endif

#ifdef Dlog_STOP_SEC_VAR_SHARED_DATA
    #undef      Dlog_STOP_SEC_VAR_SHARED_DATA
    #pragma ghs section bss=default
    #pragma ghs enddata
#endif

/* special section for boot status that is shared between bootmanager, application and bootloader */
#ifdef Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
    #undef      Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
    #pragma ghs startdata
    #pragma ghs section bss="BOOTSTATUS"
#endif

#ifdef Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
    #undef      Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
    #pragma ghs section data=default
    #pragma ghs enddata
#endif

/* -------------------------------------------------------------------------- */
/*             Data Logistic (Application and Bootloader)                     */
/* -------------------------------------------------------------------------- */
/* special section for SVK history memory, progstatus */
#ifdef Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef      Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
    #include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef      Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #define STOP_SEC_VAR
    #include "MemMap.h"
#endif

 
#ifdef Dlog_START_SEC_VAR_CLEARED_16
#undef Dlog_START_SEC_VAR_CLEARED_16
#define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_CLEARED_16
#undef Dlog_STOP_SEC_VAR_CLEARED_16
#define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#include "MemMap.h"
#endif
// Dlog_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef Dlog_START_SEC_VAR_INIT_UNSPECIFIED
#undef Dlog_START_SEC_VAR_INIT_UNSPECIFIED
#define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED
#define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#include "MemMap.h"
#endif
// Dlog_START_SEC_VAR_NO_INIT_8
#ifdef Dlog_START_SEC_VAR_NO_INIT_8
#undef Dlog_START_SEC_VAR_NO_INIT_8
#define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_NO_INIT_8
#undef Dlog_STOP_SEC_VAR_NO_INIT_8
#define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif
// Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif
// Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#ifdef Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#undef Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#undef Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif
// Dlog_START_SEC_VAR_SHARED_SWESTATUS
#ifdef Dlog_START_SEC_VAR_SHARED_SWESTATUS
#undef Dlog_START_SEC_VAR_SHARED_SWESTATUS
#define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#ifdef Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
#undef Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
#define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

