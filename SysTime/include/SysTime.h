/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the main header file of the generic part of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

#ifndef SYSTIME_H
#define SYSTIME_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericUDSTypes.h"
#include "SysTime_Version.h"
#include "SysTime_Cfg.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTime_CHECK_VERSION(5,0,3))
#error "Version of SysTime.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/
extern boolean SysTime_Run(void);

extern void SysTime_Stop( void );

extern UDS_ReturnType SysTime_ReadDataSystemTime(
    uint32* currentTime,
    UDS_ErrorCodeType* errorCode);

extern void SysTime_ReceiveSystemTime(uint32 newSystemTime);

extern void SysTime_CyclicTrigger(void* context);

#ifdef __cplusplus
}
#endif

#endif /* SYSTIME_H */
