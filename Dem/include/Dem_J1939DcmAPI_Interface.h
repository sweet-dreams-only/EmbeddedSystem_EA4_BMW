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
 */
/*! \ingroup    Dem_Master
 *  \defgroup   Dem_J1939DcmAPI J1939Dcm interface
 *  \{
 *  \file       Dem_J1939DcmAPI_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
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

#if !defined (DEM_J1939DCMAPI_INTERFACE_H)
#define DEM_J1939DCMAPI_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_J1939DcmAPI_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_J1939DcmAPI_Public Public Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmClearDTC
 *****************************************************************************/
/*!
 * \brief         Clear the J1939 DTCs.
 *
 * \details       Clears the J1939 DTCs.
 *
 * \param[in]     DTCTypeFilter
 *                DEM_J1939DTC_CLEAR_ALL - all active DTCs shall be cleared
 *                DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE- all previously active DTCs
 *                shall be cleared
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     NodeAddress - The node that is cleared
 *
 * \return        E_OK
 *                DTC successfully cleared
 * \return        DEM_WRONG_DTC
 *                DTC value not existing (in this format)
 * \return        DEM_WRONG_DTCORIGIN
 *                Wrong DTC origin
 * \return        DEM_CLEAR_FAILED
 *                DTC clearing failed
 * \return        DEM_CLEAR_MEMORY_ERROR
 *                The clear operation has completed, but the NV synchronization
 *                has failed
 * \return        DEM_PENDING
 *                The clear operation was started and is currently processed
 * \return        DEM_CLEAR_BUSY
 *                Another clear operation is currently processing
 *
 * \config        DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmClearDTC(
  Dem_J1939DcmSetClearFilterType DTCTypeFilter,
  Dem_DTCOriginType DTCOrigin,
  uint8 NodeAddress
);
#endif

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmFirstDTCwithLampStatus
 *****************************************************************************/
/*!
 * \brief         Initialize the filter mechanism to the first event in the
 *                primary memory.
 *
 * \details       Initializes the filter mechanism to the first event in the
 *                primary memory.
 *
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \config           DEM_CFG_SUPPORT_J1939_DM31 == STD_ON
 *                && DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(void, DEM_CODE)
Dem_J1939DcmFirstDTCwithLampStatus(
  uint8 NodeAddress
);
#endif

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNextDTCwithLampStatus
 *****************************************************************************/
/*!
 * \brief         Get the next filtered J1939 DTC for DM31 including current
 *                LampStatus.
 *
 * \details       Return the next filtered J1939 DTC for DM31 including current
 *                LampStatus.
 *
 * \param[out]    LampStatus
 *                Pointer to the LampStatus buffer
 * \param[out]    J1939DTC
 *                Pointer to the J1939DTC buffer
 * \param[out]    OccurenceCounter
 *                Pointer to the OccurenceCounter buffer
 *
 * \return        DEM_FILTERED_OK
 *                A matching DTC was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config           DEM_CFG_SUPPORT_J1939_DM31 == STD_ON
 *                && DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 * \pre           A filter has been initialized using
 *                Dem_J1939DcmFirstDTCwithLampStatus
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextDTCwithLampStatus(
  P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus,
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter
);
#endif

#if (DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON) || (DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmSetFreezeFrameFilter
 *****************************************************************************/
/*!
 * \brief         Initialize the filter criteria for freeze frame access.
 *
 * \details       Initializes the filter criteria for freeze frame access.
 *
 * \param[in]     FreezeFrameKind
 *                DEM_J1939DCM_FREEZEFRAME: Set the filter for J1939 Freeze
 *                Frame data
 *                DEM_J1939DCM_EXPANDED_FREEZEFRAME: Set the filter for J1939
 *                Expanded Freeze Frame data
 *                DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME: Not supported,
 *                DM24 message is handled by J1939Dcm
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \return        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \return        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \config           DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON
 *                || DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetFreezeFrameFilter(
  Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
  uint8 NodeAddress
);
#endif

#if (DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON) || (DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNextFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Get the next J1939DTC and Freeze Frame matching the
 *                filter criteria.
 *
 * \details       Returns the next J1939DTC and Freeze Frame matching the
 *                filter criteria.
 *
 * \param[out]    J1939DTC
 *                Pointer to the J1939DTC buffer
 * \param[out]    OccurenceCounter
 *                Pointer to the OccurenceCounter buffer
 * \param[out]    DestBuffer
 *                Pointer to the output buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 * \return        DEM_FILTERED_PENDING
 *                The operation was started and is currently processed
 * \return        DEM_FILTERED_BUFFER_TOO_SMALL
 *                The provided buffer is not large enough
 *
 * \config           DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON
 *                || DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON
 * \pre           A filter has been initialized using Dem_J1939DcmSetFreezeFrameFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFreezeFrame(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  DestBuffer,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  BufSize
);
#endif

#if (DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON) || (DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNextSPNInFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Get the SPNs that are stored in the J1939 FreezeFrame(s)
 *
 * \details       This function is not implemented
 *
 * \param[out]    SPNSupported
 *                Pointer to receive the SPN number
 * \param[out]    SPNDataLength
 *                Pointer to receive the data length
 *
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *
 * \config           DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON
 *                || DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON
 * \pre           A filter has been initialized using
 *                Dem_J1939DcmSetFreezeFrameFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextSPNInFreezeFrame(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  SPNSupported,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  SPNDataLength
);
#endif

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmSetDTCFilter
 *****************************************************************************/
/*!
 * \brief         Initialize the filter criteria for the J1939 DTC filter
 *                mechanism
 *
 * \details       This function sets up the filter parameters to iterate all
 *                matching DTCs. If the filter is valid, the node specific
 *                lampstatus is returned immediately, according to J1939
 *                format:
 *                HighByte
 *                 bits 7,6 - Malfunction Indicator Lamp Status
 *                 bits 5,4 - Red Stop Lamp Status
 *                 bits 3,2 - Amber Warning Lamp Status
 *                 bits 1,0 - Protect Lamp Status
 *                LowByte
 *                 bits 7,6 - Flash Malfunction Indicator Lamp
 *                 bits 5,4 - Flash Red Stop Lamp
 *                 bits 3,2 - Flash Amber Warning Lamp
 *                 bits 1,0 - Flash Protect Lamp
 *
 * \param[in]     DTCStatusFilter
 *                DTC status to filter
 * \param[in]     DTCKind
 *                DTC kind to filter
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 * \param[out]    LampStatus
 *                Pointer to receive the Lamp status for the requested node
 *
 * \return        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \return        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \config        DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetDTCFilter(
  Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
  Dem_DTCKindType DTCKind,
  Dem_DTCOriginType DTCOrigin,
  uint8 NodeAddress,
  P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus
);
#endif

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNumberOfFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Calculate the number of DTCs matching the filter criteria.
 *
 * \details       Calculates the number of DTCs matching the filter criteria.
 *
 * \param[out]    NumberOfFilteredDTC
 *                Pointer to receive the DTC count
 *
 * \return        DEM_NUMBER_OK
 *                The number of matching DTCs was returned
 * \return        DEM_NUMBER_FAILED
 *                The number of matching DTCs could not be calculated
 * \return        DEM_NUMBER_PENDING
 *                Counting is currently in progress
 *
 * \config        DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 * \pre           The filter has to be initialized by Dem_J1939DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  NumberOfFilteredDTC
);
#endif

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNextFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Get the next matching DTC.
 *
 * \details       Returns the next matching DTC.
 *
 * \param[out]    J1939DTC
 *                Pointer to receive the J1939 DTC number
 * \param[out]    OccurrenceCounter
 *                Pointer to receive the occurrence counter
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 * \pre           The filter has to be initialized by Dem_J1939DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFilteredDTC(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurrenceCounter
);
#endif

#if (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmSetRatioFilter
 *****************************************************************************/
/*!
 * \brief         Initializes the filter criteria for ratio filtering
 *
 * \details       Initializes the filter criteria for ratio filtering
 *
 * \param[out]    IgnitionCycleCounter
 *                Pointer to receive the ignition cycle counter
 * \param[out]    OBDMonitoringConditionsEncountered
 *                Pointer to receeive the general denominator value
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \return        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \return        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \config        DEM_CFG_SUPPORT_J1939_RATIO == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetRatioFilter(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  IgnitionCycleCounter,
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  OBDMonitoringConditionsEncountered,
  uint8 NodeAddress
);
#endif

#if (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmGetNextFilteredRatio
 *****************************************************************************/
/*!
 * \brief         Get the next filtered ratio.
 *
 * \details       Returns the next filtered ratio.
 *
 * \param[out]    SPN
 *                Pointer to receive the SPN
 * \param[out]    Numerator
 *                Pointer to receive the numerator value
 * \param[out]    Denominator
 *                Pointer to receive the denominator value
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_J1939_RATIO == STD_ON
 * \pre           The filter has been initialized by Dem_J1939DcmSetRatioFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFilteredRatio(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  SPN,
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  Numerator,
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  Denominator
);
#endif

#if (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmReadDiagnosticReadiness1
 *****************************************************************************/
/*!
 * \brief         Report the value of Diagnostic Readiness 1 (DM5)
 *
 * \details       Returns the value of Diagnostic Readiness 1 (DM5)
 *
 * \param[out]    DataValue
 *                Pointer to receive the DM5 data
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \return        E_OK
 *                Operation was successful
 * \return        E_NOT_OK
 *                Operation failed
 *
 * \config        DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness1(
  P2VAR(Dem_J1939DcmDiagnosticReadiness1Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,
  uint8 NodeAddress
);
#endif

#if (DEM_CFG_SUPPORT_J1939_READINESS2 == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmReadDiagnosticReadiness2
 *****************************************************************************/
/*!
 * \brief         Reports the value of Diagnostic Readiness 2 (DM21)
 *
 * \details       This API is not implemented and will always return E_NOT_OK
 *
 * \param[out]    DataValue
 *                Pointer to receive the DM21 data
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \return        E_NOT_OK
 *
 * \config        DEM_CFG_SUPPORT_J1939_READINESS2 == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness2(
  P2VAR(Dem_J1939DcmDiagnosticReadiness2Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,
  uint8 NodeAddress
);                                                                                                                               /* PRQA S 0777 */ /* MD_MSR_5.1_779_API */
#endif

#if (DEM_CFG_SUPPORT_J1939_READINESS3 == STD_ON)
/* ****************************************************************************
 * Dem_J1939DcmReadDiagnosticReadiness3
 *****************************************************************************/
/*!
 * \brief         Reports the value of Diagnostic Readiness 3 (DM26)
 *
 * \details       This API is not implemented and will always return E_NOT_OK
 *
 * \param[out]    DataValue
 *                Pointer to receive the DM26 data
 * \param[in]     NodeAddress
 *                Unique identifier of the node address
 *
 * \return        E_NOT_OK
 *
 * \config        DEM_CFG_SUPPORT_J1939_READINESS3 == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness3(
  P2VAR(Dem_J1939DcmDiagnosticReadiness3Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,
  uint8 NodeAddress
);                                                                                                                               /* PRQA S 0777 */ /* MD_MSR_5.1_779_API */
#endif

#if ( (DEM_CFG_SUPPORT_J1939 == STD_ON) \
   && ((DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON)) )
/* ****************************************************************************
 * Dem_J1939Dcm_FilterForEventMatch
 *****************************************************************************/
/*!
 * \brief         Checks if the passed EventId matches the filter criteria.
 *
 * \details       Checks if the passed EventId matches the filter criteria.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        E_OK
 *                The event matches the filter criteria
 * \return        E_NOT_OK
 *                The event does not match the filter criteria
 *
 * \pre           J1939 filter has been set
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON
 *             && (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 *                || DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_FilterForEventMatch(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 * Dem_J1939Dcm_GetNextDTCwithLampStatus
 *****************************************************************************/
/*!
 * \brief         Filters the next J1939 DTC with lamp status.
 *
 * \details       Filters the next J1939 DTC with lamp status.
 *
 * \param[out]    LampStatus
 *                Pointer to the LampStatus buffer
 * \param[out]    J1939DTC
 *                Pointer to the J1939DTC buffer
 * \param[out]    OccurenceCounter
 *                Pointer to the OccurenceCounter buffer
 *
 * \return        DEM_FILTERED_OK
 *                A DTC was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No DTC left to iterate
 *
 * \pre           J1939 iteration has been started by Dem_J1939DcmFirstDTCwithLampStatus
 * \config        DEM_CFG_SUPPORT_J1939_DM31 == STD_ON || DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_GetNextDTCwithLampStatus(
  CONSTP2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter
  );
#endif

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_J1939Dcm_GetNextFF_FindNextEvent
 *****************************************************************************/
/*!
 * \brief         Filters the next J1939 DTC
 *
 * \details       Filters the next J1939 DTC
 *
 * \param[in]     LastEventId
 *                Current iteration position
 * \param[in]     FreezeFrameKind
 *                DEM_J1939DCM_FREEZEFRAME find the next event with a freeze
 *                frame
 *                DEM_J1939DCM_EXPANDED_FREEZEFRAME find the next event with an
 *                expanded freeze frame
 *
 * \return        DEM_FILTERED_OK
 *                A DTC was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No DTC left to iterate
 *
 * \pre           J1939 freeze frame iteration has been started by
 *                Dem_J1939DcmSetFreezeFrameFilter
 * \config        DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_J1939Dcm_GetNextFF_FindNextEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  LastEventId,
  CONST(uint8, AUTOMATIC)  FreezeFrameKind
  );
#endif

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF xf xf xf */
/* ****************************************************************************
 * Dem_J1939Dcm_GetNextFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Filters the next J1939 DTC freeze frame
 *
 * \details       Filters the next J1939 DTC freeze frame
 *
 * \param[out]    J1939DTC
 *                Pointer to the J1939DTC buffer
 * \param[out]    OccurenceCounter
 *                Pointer to the OccurenceCounter buffer
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        DEM_FILTERED_OK
 *                A DTC was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No DTC left to iterate
 * \return        DEM_FILTERED_PENDING
 *                The data cannot be retrieved, try again
 * \return        DEM_FILTERED_BUFFER_TOO_SMALL
 *                BufSize too small for the freeze frame
 *
 * \pre           J1939 iteration has been started by
 *                Dem_J1939DcmSetFreezeFrameFilter
 * \config        DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_GetNextFreezeFrame(
  CONSTP2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  DestBuffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  BufSize
  );
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_J1939Dcm_FilterMemory
 *****************************************************************************/
/*!
 * \brief         Iterates events in requested memory matching the J1939Dcm
 *                DTC filter
 *
 * \details       This function iterates all events in order of their event ID.
 *
 * \return        EventId of the next event maching the filter criteria
 *
 * \pre           A J1939Dcm filter has been set
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(Dem_EventIdType, DEM_CODE)
Dem_J1939Dcm_FilterMemory(
  void
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_J1939DCMAPI_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_J1939DcmAPI_Interface.h
 *********************************************************************************************************************/
