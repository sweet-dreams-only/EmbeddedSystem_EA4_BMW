/**
*  \file
*
*  \brief       BMW SWC Omc
*
*  This file contains the assert macros.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/

#ifndef OMC_ASSERT_H
#define OMC_ASSERT_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "OmcClassic_Version.h"
#include "Omc_Cfg.h"

#include "Rte_Omc.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5,2,0))
   #error "Version of Omc_Assert.h does not match the version of the module!"
#endif


#define OMC_DEVERROR_GENERAL                          0x0000 /*"General Error"*/

#define OMC_DEVERROR_LIFECYCLEHANDLER_ERETURN         0x0002

#define OMC_DEVERROR_CONDCHECKOPERATINGMODE_EPARAM    0x0701
#define OMC_DEVERROR_READDIDOPERATINGMODE_EPARAM      0x0301

#define OMC_DEVERROR_OPERATINGMODE_EPARAM             0x0501

#define OMC_DEVERROR_CONDCHECKEXTOPERATINGMODE_EPARAM 0x0801
#define OMC_DEVERROR_READDIDEXTOPERATINGMODE_EPARAM   0x0401

#define OMC_DEVERROR_EXTOPERATINGMODE_EPARAM          0x0601

#define OMC_DEVERROR_CLEAREVENTALLOWED_EPARAM         0x0901

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/


#if (OMC_DEV_ERROR_DETECT == STD_ON)

#define Omc_Assert_DevAssert(condition, errorCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETServicePort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
       } \
   } while(0)

#define Omc_Assert_DevAssertReturn(condition, errorCode, returnCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETServicePort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
          return (returnCode); \
       } \
   } while(0)

#define Omc_Assert_DevAssertReturnVoid(condition, errorCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETServicePort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
          return; \
       } \
   } while(0)


#else
#define Omc_Assert_DevAssert(condition, errorCode) do {} while(0)
#define Omc_Assert_DevAssertReturn(condition, errorCode, returnCode) do {} while(0)
#define Omc_Assert_DevAssertReturnVoid(condition, errorCode) do {} while(0)
#endif

#endif /* OMC_ASSERT_H */
