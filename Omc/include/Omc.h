/**
*  \file
*
*  \brief       Omc Header
*
*  Header file for Omc containing API
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

#ifndef OMC_H
#define OMC_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Omc_Version.h"
#include "Omc_Data.h"
#include "Omc_NvMAdapter.h"
#include "Omc_UDSAdapter.h"
#include "Omc_ErrMemAdapter.h"
#include "BUtil/PlatformTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5,1,0))
   #error "Version of Omc.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

extern void Omc_Init(void);

extern void Omc_NvMWriteBlockFinishedCallback(NvMService_ResultType Result);

extern UDS_ReturnType Omc_RoutineControlOperatingMode_Start(Omc_GenericOperatingModeType OperatingMode, UDS_ErrorCodeType* UDS_ErrorCode);

extern UDS_ReturnType Omc_RoutineControlExtendedOperatingMode_Start(Omc_GenericExtendedOperatingModeType ExtendedOperatingMode, UDS_ErrorCodeType* UDS_ErrorCode);

extern UDS_ReturnType Omc_ReadDataOperatingMode(Omc_GenericOperatingModeType* OperatingMode, UDS_ErrorCodeType* UDS_ErrorCode);

extern UDS_ReturnType Omc_ReadDataExtendedOperatingMode(Omc_GenericExtendedOperatingModeType* ExtendedOperatingMode, UDS_ErrorCodeType* UDS_ErrorCode);

extern void Omc_StdDiagCbk_OpModeSwitchAllowedResult(boolean Result);

extern void Omc_StdDiagCbk_OpModeSwitchCancelledAck(void);

extern void Omc_ApplicationCbk_OpModeSwitchAllowedResult(boolean Result);

extern void Omc_ApplicationCbk_OpModeSwitchCancelledAck(void);

extern void Omc_CycleTask(void);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_H */
