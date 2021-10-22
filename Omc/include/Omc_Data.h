/**
*  \file
*
*  \brief       Omc modes data
*
*  This file contains the declarations of the RAM mirror and of the ROM mirror
*  of the current Omc modes.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
*
*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/
#ifndef OMC_DATA_H
#define OMC_DATA_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "Omc_Version.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc_Data.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/** \brief Omc Modes
 * \lhref FZM_SC_SYS_PA_168
 */
typedef enum {
  OMC_GENMODE_NORMAL = 0,
  OMC_GENMODE_ASSEMBLY = 1,
  OMC_GENMODE_TRANSPORT = 2,
  OMC_GENMODE_BMW_FLASH = 3
} Omc_GenericOperatingModeType;

/** \brief Omc Extended Mode
 * \lhref FZM_SC_SYS_PA_328
 */
typedef enum {
  OMC_GENMODE_EXTENSION_NORMAL = 0,
  OMC_GENMODE_EXTENSION_1 = 1,
  OMC_GENMODE_EXTENSION_2 = 2,
  OMC_GENMODE_EXTENSION_3 = 3,
  OMC_GENMODE_EXTENSION_4 = 4,
  OMC_GENMODE_EXTENSION_5 = 5,
  OMC_GENMODE_EXTENSION_6 = 6,
  OMC_GENMODE_EXTENSION_7 = 7,
  OMC_GENMODE_EXTENSION_8 = 8,
  OMC_GENMODE_EXTENSION_9 = 9,
  OMC_GENMODE_EXTENSION_10 = 10,
  OMC_GENMODE_EXTENSION_11 = 11,
  OMC_GENMODE_EXTENSION_12 = 12,
  OMC_GENMODE_EXTENSION_13 = 13,
  OMC_GENMODE_EXTENSION_14 = 14,
  OMC_GENMODE_EXTENSION_SAVE_ENERGY = 15,
  OMC_GENMODE_EXTENSION_INVALID = 255
} Omc_GenericExtendedOperatingModeType;

/* Struct type containing the data to be stored in Non-volatile memory */
typedef struct {
  /* Operating mode */
  Omc_GenericOperatingModeType operatingMode;
  /* Extended operating mode */
  Omc_GenericExtendedOperatingModeType extendedOperatingMode;
} Omc_NvDataType;

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/* RAM mirror of Omc Non-volatile data */
extern Omc_NvDataType Omc_NvData;

#define Omc_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

#define Omc_START_SEC_CONST_SAVED_RECOVERY_ZONE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/* Default data of Omc Non-volatile data */
extern const Omc_NvDataType Omc_DefaultNvData;

#define Omc_STOP_SEC_CONST_SAVED_RECOVERY_ZONE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* OMC_DATA_H */
