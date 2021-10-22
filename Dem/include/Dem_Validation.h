
/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dem_Validation.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Configuration sanity checks. Please note, the validation performed in this file is intentionally
 *                incomplete and restricted to basic verifications.  Not all combinations of options are supported
 *                even if the compilation of this file is successful. This is intended behavior.
 *                Exhaustive verifications are performed by the generation tool before configuration files are
 *                created.
 *
 *********************************************************************************************************************/
/*!
 *  \addtogroup   Dem_Ungrouped
 *  \{
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_VALIDATION_H)
#define DEM_VALIDATION_H

/* ********************************************************************************************************************
 *  VERIFY BASIC MACROS EXIST
 *********************************************************************************************************************/
#if !defined (STD_ON) || (STD_ON != 1)
# error "STD_ON is not correctly defined"
#endif

#if !defined (STD_OFF) || (STD_OFF != 0)
# error "STD_OFF is not correctly defined"
#endif

/**********************************************************************************************************************
 *  VERIFY SENSIBLE COMBINATION OF CONFIGURATION SWITCHES
 *********************************************************************************************************************/
#if !defined DEM_DUMMY_STATEMENT
# error "DEM_DUMMY_STATEMENT not defined"
#endif

#if ((DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON) && (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON))
# error "(DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON) && (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON) is not\
 a valid combination"
#endif

#if ((DEM_CFG_SUPPORT_SRECS_CALCULATED  == STD_ON) && (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON))
# error "(DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON) && (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON) is not\
 a valid combination"
#endif

#if ((DEM_CFG_SUPPORT_OPCYCLE_STORAGE != STD_ON) && (DEM_CFG_SUPPORT_OPCYCLE_AUTOMATIC_END == STD_ON))
# error "(DEM_CFG_SUPPORT_OPCYCLE_STORAGE != STD_ON) && (DEM_CFG_SUPPORT_OPCYCLE_AUTOMATIC_END == STD_ON) is not\
  a valid combination: without nonvolatile storage of cycle state there is no way NOT to end a cycle."
#endif

#if (DEM_CFG_PROCESS_PDTC_ALL_DTC == DEM_CFG_PROCESS_PDTC_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_PDTC_ALL_DTC, DEM_CFG_PROCESS_PDTC_STOREDONLY must be enabled"
#endif

#if (DEM_CFG_PROCESS_CDTC_ALL_DTC == DEM_CFG_PROCESS_CDTC_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_CDTC_ALL_DTC, DEM_CFG_PROCESS_CDTC_STOREDONLY must be enabled"
#endif

#if ((DEM_CFG_PROCESS_TFSLC_ALL_DTC + DEM_CFG_PROCESS_TFSLC_STOREDONLY + DEM_CFG_PROCESS_TFSLC_CLEARONLY) > STD_ON)
# error "Exactly one of the settings DEM_CFG_PROCESS_TFSLC_ALL_DTC, DEM_CFG_PROCESS_TFSLC_STOREDONLY must be enabled"
#endif

#if (DEM_CFG_PROCESS_WIR_ALL_DTC == DEM_CFG_PROCESS_WIR_STOREDONLY)
# error "Exactly one of the settings DEM_CFG_PROCESS_WIR_ALL_DTC, DEM_CFG_PROCESS_WIR_STOREDONLY must be enabled"
#endif

#if ((DEM_CFG_SUPPORT_EVENTAVAILABLE_NV == STD_ON) && (DEM_CFG_SUPPORT_EVENTAVAILABLE_DEFAULT == STD_ON))
# error "Event availability must use exactly one of initialization with default value, or initialization from NV"
#endif

#if !defined PRQA_SIZE_T && !defined _lint

#endif

#if (DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_OFF) && ((DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON))
# error "(DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_OFF) && ((DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON))\
  is not a valid combination"
#endif

#if (DEM_CFG_STORAGE_AT_CONFIRMED != STD_ON) && (DEM_CFG_STORAGE_AT_FAILED != STD_ON) && (DEM_CFG_STORAGE_AT_FDC != STD_ON)
# error "At least one DEM_CFG_STORAGE_AT_X must be defined to STD_ON"
#endif

#if (DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && ((DEM_CFG_STORAGE_AT_FAILED == STD_ON) || (DEM_CFG_STORAGE_AT_FDC == STD_ON))
# error "At most one DEM_CFG_STORAGE_AT_X must be defined to STD_ON"
#endif

#if (DEM_CFG_STORAGE_AT_FAILED == STD_ON) && (DEM_CFG_STORAGE_AT_FDC == STD_ON)
# error "At most one DEM_CFG_STORAGE_AT_X must be defined to STD_ON"
#endif

#if (DEM_CFG_STORAGE_AT_FDC == STD_ON) && (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON)
# error "The combination of DemStorageTrigger=DEM_STORAGE_ON_FDC_THRESHOLD and DemRetryStorageSupport==True is not supported."
#endif

#if ((DEM_CFG_SUPPORT_ERECS != STD_ON) && (DEM_CFG_SUPPORT_USER_ERECS == STD_ON))
# error "((DEM_CFG_SUPPORT_ERECS != STD_ON) && (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)) is not a valid combination"
#endif

#if ((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON))
# error "((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

#if ((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON))
# error "((DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON) && (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
# if (DEM_CFG_GLOBAL_COMBINED_GROUP_COUNT == 0)
#  error "DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON without combined events is not supported"
# endif
#endif

#if ((DEM_CFG_AGING_NEXT_TESTS_TFTOC == STD_ON) && (DEM_CFG_AGING_NEXT_TESTS_TNCTOC == STD_OFF))
# error "(DEM_CFG_AGING_NEXT_TESTS_TFTOC == STD_ON) && (DEM_CFG_AGING_NEXT_TESTS_TNCTOC == STD_OFF) is not a valid combination"
#endif

#if ((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON))
# error "((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON) && (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

#if ((DEM_CFG_PROCESS_WIR_ALL_DTC == STD_ON) && (DEM_CFG_PROCESS_CDTC_STOREDONLY == STD_ON))
# error "((DEM_CFG_PROCESS_WIR_ALL_DTC == STD_ON) && (DEM_CFG_PROCESS_CDTC_STOREDONLY == STD_ON)) is not a valid combination"
#endif

/* ********************************************************************************************************************
 *  UNSUPPORTED ASR FEATURES
 *********************************************************************************************************************/
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
# error "DEM_CFG_SUPPORT_OBDII == STD_ON is not supported"
#endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
# error "DEM_CFG_SUPPORT_WWHOBD == STD_ON is not supported"
#endif /* (DEM_CFG_SUPPORT_WWHOBD == STD_ON) */

#if (DEM_CFG_SUPPORT_DLT == STD_ON)
# error "DEM_CFG_SUPPORT_DLT == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_VID08 == STD_ON)
# error "DEM_CFG_SUPPORT_VID08 == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_VID0B == STD_ON)
# error "DEM_CFG_SUPPORT_VID0B == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_MIRROR == STD_ON)
# error "DEM_CFG_SUPPORT_MIRROR == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
# error "DEM_CFG_SUPPORT_PERMANENT == STD_ON is not supported for non-OBD/WWH-OBD use cases"
#endif /* (DEM_CFG_SUPPORT_PERMANENT == STD_ON) */

#if (DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON)
# error "DEM_CFG_SUPPORT_AGINGCYCLE_STATE_API == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON)
# error "DEM_CFG_SUPPORT_AGINGCYCLE_COUNTER_API == STD_ON is not yet supported"
#endif

#if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
# error "DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CAPTURE_EXTDATA_TESTFAILED == STD_ON)
# error "DEM_CFG_CAPTURE_EXTDATA_TESTFAILED == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CAPTURE_FREEZEF_TESTFAILED == STD_ON)
# error "DEM_CFG_CAPTURE_FREEZEF_TESTFAILED == STD_ON is not yet supported"
#endif

#if (DEM_CFG_CLEAR_REINIT_BEFORE_RESPONSE != STD_ON)
# error "DEM_CFG_CLEAR_REINIT_BEFORE_RESPONSE == STD_OFF is not supported"
#endif

#endif  /* DEM_VALIDATION_H */
/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Validation.h
 *********************************************************************************************************************/
