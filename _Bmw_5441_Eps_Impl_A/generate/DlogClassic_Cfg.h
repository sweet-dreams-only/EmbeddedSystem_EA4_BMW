/**
*  \file
*
*  \brief       Configuration header file of module Dlog.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.421030
*
------------------------------------------------------------------------------*/

#ifndef DLOGCLASSIC_CFG_H
#define DLOGCLASSIC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Dlog_Cfg.h"
#include "Dlog_CfgCommon.h"
#include "DlogClassic_Version.h"
#include "Std_Types.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of DlogClassic_Cfg.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                        Configuration Section
------------------------------------------------------------------------------*/

/**
 * The parameter disables or enables support for multi CPUs.
 * STD_ON  : Enable the functionality for MultiCpu
 * STD_OFF : Disable the functionality for MultiCpu
 */
#define DLOG_ENABLE_MULTI_CPU           STD_OFF

#define DLOG_USE_CODING                 STD_ON




/* -------------------------------------------------------------------------- */
/*                          Data Logistic                                     */
/* -------------------------------------------------------------------------- */


/**
 * Maximum length of the SWE development info field by LH FP
 */
#define DLOG_MAX_XWE_DEV_INFO_LENGTH  256u

/* check user configurations                                                  */
#if (DLOG_SWE_DEV_INFO_LENGTH >= DLOG_MAX_XWE_DEV_INFO_LENGTH)
   #error "DlogClassic_Cfg.h: 'DLOG_SWE_DEV_INFO_LENGTH' too long. The maximum is 255 Byte"
#endif

#if (DLOG_HWEDEVELOPMENTINFOLENGTH >= DLOG_MAX_XWE_DEV_INFO_LENGTH)
   #error "DlogClassic_Cfg.h: 'DLOG_HWEDEVELOPMENTINFOLENGTH' too long. The maximum is 255 Byte"
#endif


/* *******************  SWE configuration  ******************************* */

#define Dlog_WatchdogTrigger()                          WdgIf_SetTriggerCondition(0,100)

#define Dlog_UserRomAccessExceptionHandler(codeAddress, dataAddress) 0


   /*
    *  Features
    */
#define DLOG_ENABLE_MEMSEGTABLE_READ STD_ON

#define DLOG_ENABLE_ECU_WRITE_VIN    STD_OFF

#define DLOG_NVM_INTERFACE_MEMIF     1
#define DLOG_NVM_INTERFACE_NVM       2
#define DLOG_NVM_INTERFACE           DLOG_NVM_INTERFACE_NVM


#define DLOG_ENABLE_SWE_GET                    STD_ON
#define DLOG_ENABLE_DIRECT_BOOT_APPL1_SWE      STD_OFF
#define DLOG_ENABLE_SWE_PERFORM_ERROR_CHECK    STD_OFF
#define DLOG_ENABLE_SWE_VALID_FLAG_BLANK_CHECK STD_OFF
#define DLOG_VERIFY_SWE_CRC_CHKSUM             STD_ON

#define DLOG_ENABLE_SWE_INIT                   STD_OFF

#define DLOG_HANDLE_ECC_ROM                    STD_ON
#define DLOG_HANDLE_ECC_SWE_ERRORS             STD_OFF

#define DLOG_ENABLE_TIMINGPARAMETERS           STD_ON

#define DLOG_ENABLE_RTE                        STD_ON

#endif /* DLOGCLASSIC_CFG_H */


/*** End of file **************************************************************/

