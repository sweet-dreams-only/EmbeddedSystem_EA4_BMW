/**
 * \file
 *
 * \brief       Coding Assert Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_ASSERT_H_
#define CODING_ASSERT_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */
#include "Rte_Coding.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_Assert.h does not match the Classic adapter version!"
#endif

#define CODING_DEVERROR_GENERAL         0x0000 /* General Error             */
#define CODING_DEVERROR_BUSAPI          0x0001 /* BUS API Error             */

#define CODING_DEVERROR_NVMADPT         0x0101 /* NvM Adapter Error         */
#define CODING_DEVERROR_APPLADPT        0x0101 /* Application Adapter Error */
#define CODING_DEVERROR_TIMERDPT        0x0101 /* Timer Adapter Error       */

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

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#if (STD_ON == CODING_DEV_ERROR_DETECT)

#define Coding_DevAssert(condition, errorCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETService_ReportError(0u, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
       } \
   } while(0)

#define Coding_DevAssertReturn(condition, errorCode, returnCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETService_ReportError(0u, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
          return (returnCode); \
       } \
   } while(0)

#define Coding_DevAssertReturnVoid(condition, errorCode) \
   do {                                                        \
       if (!(condition)) { \
          (void)Rte_Call_DETService_ReportError(0u, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff));\
          return; \
       } \
   } while(0)

#else

#define Coding_DevAssert(condition, errorCode) do {} while(0)
#define Coding_DevAssertReturn(condition, errorCode, returnCode) do {} while(0)
#define Coding_DevAssertReturnVoid(condition, errorCode) do {} while(0)

#endif /* CODING_DEV_ERROR_DETECT */

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#endif /* CODING_ASSERT_H_ */
