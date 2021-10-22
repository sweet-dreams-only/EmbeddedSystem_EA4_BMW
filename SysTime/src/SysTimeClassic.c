/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file contains the implementation of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*  \remarks     The System Time Client module receives the System Time,
*               which is sent by the System Time Master, and provides the
*               received System Time to other modules on the ECU.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including SysTime_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "SysTimeClassic_Version.h"
#include "SysTimeClassic_Cfg.h"
#include "SysTime.h"
#include "SysTime_AssertAdapter.h"
#include "Rte_SysTime.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTimeClassic_CHECK_VERSION(5,0,3))
#error "Version of SysTimeClassic.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define SysTime_START_SEC_CODE
#include "SysTime_MemMap.h"

/**
 * \brief lifecycle handler
 *
 * This function handles the lifecycle mode of the System Time Client
 *
 */
void SysTime_LifeCycleHandler(void)
{
  Std_ReturnType retval = E_NOT_OK;
  SysTime_LifeCycleRequestType requestedMode = Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();
  SysTime_LifeCycleRequestType nextMode;
  SysTime_LifeCycleRequestType previousMode;

  /* ignore return value, only nextMode is used */
  (void) Rte_Mode_LifeCycle_Mode(&previousMode, &nextMode);

  switch( requestedMode )
  {
    case RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED:
      if( nextMode == RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED )
      {
        retval = Rte_Switch_LifeCycle_Mode(requestedMode);
      }
      break;

    case RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING:
      if( nextMode == RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED )
      {
        if (TRUE == SysTime_Run())
        {
          retval = Rte_Switch_LifeCycle_Mode(requestedMode);
        }
      }
      break;

    case RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED:
      if( (nextMode == RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED) || (nextMode == RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING) )
      {
        SysTime_Stop();
        retval = Rte_Switch_LifeCycle_Mode(requestedMode);
      }
      break;

    default:
      break;
  }

  /* MISRA-C:2004 Rule 10.1: conversion to underlying type is intended */
  /* PRQA S 1290 1 */
  SysTime_Assert_DevAssert((E_OK == retval), SYSTIME_DEVERROR_LIFECYCLE_FAILED);
}

/**
 * \brief get current system time for diagnostics
 *
 * writes the current system time to a given buffer
 *
 * \param[out] Data pointer to the buffer, where the MSB of the current
 *                  system time will be stored. The other three bytes
 *                  of the current system time will be stored in
 *                  Data[1] to Data[3].
 *
 * \retval E_OK read operation was successful
 *
 */
Std_ReturnType SysTime_GetSystemTime(uint8* Data)
{
  uint32 tempSystime;
  UDS_ErrorCodeType errorCode;

  /* get system time from generic part */
  /* ignore return value, will always return UDS_DIAG_JOB_FINISHED_OK */
  (void) SysTime_ReadDataSystemTime(&tempSystime, &errorCode);

  /* copy data bytewise to Dcm buffer */
  /*
     MISRA-C:2004 Rule 17.4: pointer operation is necessary to fill the
     given buffer with more than one byte
  */
  /* PRQA S 0489 6 */
  *Data = (uint8) (tempSystime >> 24);
  Data++;
  *Data = (uint8) (tempSystime >> 16);
  Data++;
  *Data = (uint8) (tempSystime >> 8);
  Data++;
  *Data = (uint8) tempSystime;

  return E_OK;
}

/**
 * \brief receive signal from Com module
 *
 * This function is called, when a new system time signal
 * has been received by the Com module.
 *
 */
void SysTime_ReceiveSignal(void)
{
#if( SYSTIME_SERVICE_INTERFACE == STD_ON )
  RelativeTimeBN2020Type tempEvent;
#endif
  uint32 tempSignal;

  /* retrieve the received signal from the RTE */
#if( SYSTIME_SERVICE_INTERFACE == STD_ON )
  if( Rte_Read_SysTimeEventRx_RelativeTimeBN2020(&tempEvent) == RTE_E_OK )
#else
  if( Rte_Read_SysTimeRx_timeSignal(&tempSignal) == RTE_E_OK )
#endif
  {
#if( SYSTIME_SERVICE_INTERFACE == STD_ON )
    tempSignal = tempEvent.timeSecondCounterRelative;
#endif
    /* pass received system time to generic part */
    SysTime_ReceiveSystemTime(tempSignal);
  }
}

/**
 * \brief cyclic main function
 *
 * This function cyclically calls the generic main function
 * with a configured cycle rate of SYSTIME_MAINTASKCYCLE.
 *
 */
void SysTime_MainFunction(void)
{
  SysTime_CyclicTrigger(NULL_PTR);
}

/* PRQA S 5087 2 */
#define SysTime_STOP_SEC_CODE
#include "SysTime_MemMap.h"
