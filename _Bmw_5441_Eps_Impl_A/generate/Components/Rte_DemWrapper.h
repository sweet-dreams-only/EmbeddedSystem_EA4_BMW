/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_DemWrapper.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <DemWrapper>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DEMWRAPPER_H
# define _RTE_DEMWRAPPER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DemWrapper_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SelectDTC(uint8 parg0, uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DemWrapper_ClearDTC_SelectDTC(arg1, arg2, arg3) (Dem_SelectDTC((uint8)1, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)7, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)9, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent Dem_GetDTCOfEvent
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx Dem_GetEventFreezeFrameDataEx


# endif /* !defined(RTE_CORE) */


# define DemWrapper_START_SEC_CODE
# include "DemWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent
#  define RTE_RUNNABLE_DemWrapper_CddIf_ClearDTC DemWrapper_CddIf_ClearDTC
#  define RTE_RUNNABLE_DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent
#  define RTE_RUNNABLE_DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData
#  define RTE_RUNNABLE_DemWrapper_Init DemWrapper_Init
#  define RTE_RUNNABLE_DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent
# endif

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_CddIf_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DestBuffer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DestBuffer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, DemWrapper_CODE) DemWrapper_Init(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DemWrapper_STOP_SEC_CODE
# include "DemWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CddIf_DEM_CLEAR_BUSY (5U)

#  define RTE_E_CddIf_DEM_CLEAR_FAILED (3U)

#  define RTE_E_CddIf_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_CddIf_DEM_CLEAR_PENDING (4U)

#  define RTE_E_CddIf_DEM_CLEAR_WRONG_DTC (1U)

#  define RTE_E_CddIf_DEM_CLEAR_WRONG_DTCORIGIN (2U)

#  define RTE_E_CddIf_E_OK (0U)

#  define RTE_E_ClearDTC_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_E_OK (0U)

#  define RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (2U)

#  define RTE_E_Darh_DiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NODATAAVAILABLE (48U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (2U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_DIDNUMBER (50U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_RECORDNUMBER (49U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DEMWRAPPER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
