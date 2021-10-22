/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       SVK Backup access functions.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.3.1
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.791167
*
------------------------------------------------------------------------------*/

#ifndef DLOG_SVK_BACKUP_H
#define DLOG_SVK_BACKUP_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
/* -------------------------------------------------------------------------- */
#include "DlogClassic_Cfg.h"
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SvkBackup.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if ( DLOG_ENABLE_RTE != STD_ON )

extern Std_ReturnType Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType Dlog_ReadDataLengthSvkCurrent(Dcm_OpStatusType OpStatus, uint16* DataLength);

extern Std_ReturnType Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, uint8* DataOut);

extern Std_ReturnType Dlog_ConditionCheckSvkSysSupplier
                      (
                         Dcm_OpStatusType OpStatus,
                         Dcm_NegativeResponseCodeType* ErrorCode
                      );

#if (DLOG_ENABLE_MULTI_CPU == STD_ON) || (DLOG_CHECK_FOR_OPTIONAL_SWFK == STD_ON)
extern Std_ReturnType Dlog_ReadDataLengthSvkSysSupplier(Dcm_OpStatusType OpStatus, uint16* DataLength);
#endif
extern Std_ReturnType Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, uint8* Data);

extern Std_ReturnType Dlog_ConditionCheckSvkPlant(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode);

#if (DLOG_ENABLE_MULTI_CPU == STD_ON) || (DLOG_CHECK_FOR_OPTIONAL_SWFK == STD_ON)
extern Std_ReturnType Dlog_ReadDataLengthSvkPlant(Dcm_OpStatusType OpStatus, uint16* DataLength);
#endif

extern Std_ReturnType Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, uint8* Data);



extern Std_ReturnType Dlog_RoutineControlStartReadDevelopmentInfoField(
    const uint8* DataIn,
    Dcm_OpStatusType OpStatus,
    uint8* DataOut,
    uint16* CurrentDataLength,
    Dcm_NegativeResponseCodeType* ErrorCode
);

#endif /* #if ( DLOG_ENABLE_RTE == STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #ifndef DLOG_SVK_BACKUP_H */

