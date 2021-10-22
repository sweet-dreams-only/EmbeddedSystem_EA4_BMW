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
/*!
 *  \addtogroup Dem_Dcm
 *  \{
 *  \file       Dem_Dcm_Types.h
 *  \brief      Diagnostic Event Manager (Dem) Type and Macro definition file
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

#if !defined (DEM_DCM_TYPES_H)
#define DEM_DCM_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*!
 * \defgroup  Dem_Dcm_FilterStates Macros encoding state for DTC data access
 * Macros encoding state for DTC data access
 * \{
 */
#define DEM_DCM_FILTERDATA_IDLE                  (0xFFU)  /*!< No data filter in progress */
#define DEM_DCM_FILTERDATA_PENDING               (0x03U)  /*!< Data filter in progress */
#define DEM_DCM_FILTERDATA_READY                 (0x00U)  /*!< Data filter completed, ready for access */
/*!
 * \}
 */
 
/*!
 * \defgroup  Dem_Dcm_ExtendedDataRecord_Value Extended Data Records
 * List of special extended data record values
 * \{
 */
#define DEM_DCM_EXTENDEDDATARECORD_INVALID         (0x00u)     /*! Invalid extended record */
#define DEM_DCM_EXTENDEDDATARECORD_FIRST           (0x01u)     /*! The first valid extended record */
#define DEM_DCM_EXTENDEDDATARECORD_FIRST_OBD       (0x90u)     /*! The first valid OBD extended record */
#define DEM_DCM_EXTENDEDDATARECORD_LAST            (0xEFu)     /*! The last valid extended record */
#define DEM_DCM_EXTENDEDDATARECORD_FIRST_RESERVED  (0xF0u)     /*! The first reserved extended record */
#define DEM_DCM_EXTENDEDDATARECORD_OBD             (0xFEu)     /*! Select all OBD records */
#define DEM_DCM_EXTENDEDDATARECORD_ALL             (0xFFu)     /*! Select all extended records */
/*!
 * \}
 */
 
/*!
 * \defgroup  Dem_Dcm_SnapshotDataRecord_Value Snapshot data Records
 * List of special snapshot data record values
 * \{
 */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_FIRST        (0x10u)     /*! The first valid TMC time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_LAST         (0x4Fu)     /*! The last valid TMC time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST   (0x10u)     /*! The first valid TMC fast time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_LAST    (0x2Fu)     /*! The last valid TMC fast time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST (0x30u)     /*! The first valid TMC normal time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_LAST  (0x4Fu)     /*! The last valid TMC normal time series record */
#define DEM_DCM_SNAPSHOTDATARECORD_OBD              (0x00u)     /*! OBD record */
#define DEM_DCM_SNAPSHOTDATARECORD_VCC              (0x30u)     /*! VCC record */
#define DEM_DCM_SNAPSHOTDATARECORD_STANDARD_FIRST   (0x01u)     /*! The first vaild standard snapshot data record */
#define DEM_DCM_SNAPSHOTDATARECORD_STANDARD_LAST    (0xFEu)     /*! The last valid standard snapshot data record */
#define DEM_DCM_SNAPSHOTDATARECORD_ALL              (0xFFu)     /*! All snapshot data records */
/*!
* \}
*/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/*! Get filter criteria of Dcm filter info */
#define Dem_Dcm_FilterGetCriteria()              (Dem_Dcm_FilterInfo.FilterFlags)                                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criteria of Dcm filter info */
#define Dem_Dcm_FilterSetCriteria(Criteria)      (Dem_Dcm_FilterInfo.FilterFlags = (Criteria))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter status mask of Dcm filter info */
#define Dem_Dcm_FilterDtcGetStatusMask()         (Dem_Dcm_FilterInfo.Filter.Dtc.StatusMask)                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter status mask of Dcm filter info */
#define Dem_Dcm_FilterDtcSetStatusMask(Mask)     (Dem_Dcm_FilterInfo.Filter.Dtc.StatusMask = (Mask))                             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter memory id of Dcm filter info */
#define Dem_Dcm_FilterDtcGetMemoryId()           (Dem_Dcm_FilterInfo.Filter.Dtc.MemoryId)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter memory id of Dcm filter info */
#define Dem_Dcm_FilterDtcSetMemoryId(Id)         (Dem_Dcm_FilterInfo.Filter.Dtc.MemoryId = (Id))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter severity mask of Dcm filter info */
# define Dem_Dcm_FilterDtcGetSeverityMask()      (Dem_Dcm_FilterInfo.Filter.Dtc.SeverityMask)                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter severity mask of Dcm filter info */
# define Dem_Dcm_FilterDtcSetSeverityMask(Mask)  (Dem_Dcm_FilterInfo.Filter.Dtc.SeverityMask = (Dem_DTCSeverityType)(Mask))      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get event iterator position of Dcm filter info */
#define Dem_Dcm_FilterDtcGetEventIndex()         (Dem_Dcm_FilterInfo.Filter.Dtc.Iterator.EventIndex)                             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set event iterator position of Dcm filter info */
#define Dem_Dcm_FilterDtcSetEventIndex(Index)    (Dem_Dcm_FilterInfo.Filter.Dtc.Iterator.EventIndex = (Index))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get chronological iterator position of Dcm filter info */
#define Dem_Dcm_FilterDtcGetChronoIndex()        (Dem_Dcm_FilterInfo.Filter.Dtc.Iterator.ChronoIndex)                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set chronological iterator position of Dcm filter info */
#define Dem_Dcm_FilterDtcSetChronoIndex(Index)   (Dem_Dcm_FilterInfo.Filter.Dtc.Iterator.ChronoIndex = (Index))                  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter function pointer of Dcm filter info */
#define Dem_Dcm_FilterDtcGetFunctionPtr()        (Dem_Dcm_FilterInfo.pFilterDtcFunction)                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter function pointer of Dcm filter info */
#define Dem_Dcm_FilterDtcSetFunctionPtr(FuncPtr) (Dem_Dcm_FilterInfo.pFilterDtcFunction = (FuncPtr))                             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter fault detection counter of Dcm filter info */
#define Dem_Dcm_FilterDtcGetFdc()                (Dem_Dcm_FilterInfo.Filter.Dtc.FaultDetectionCounter)                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter fault detection counter of Dcm filter info */
#define Dem_Dcm_FilterDtcSetFdc(Fdc)             (Dem_Dcm_FilterInfo.Filter.Dtc.FaultDetectionCounter = (Fdc))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter snapshot records memory iterator position of Dcm filter info */
#define Dem_Dcm_FilterRecordGetMemIndex()        (Dem_Dcm_FilterInfo.Filter.Record.MemoryIndex)                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter snapshot records memory iterator position of Dcm filter info */
#define Dem_Dcm_FilterRecordSetMemIndex(Index)   (Dem_Dcm_FilterInfo.Filter.Record.MemoryIndex = (Index))                        /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter snapshot records snapshot iterator position of Dcm filter info */
#define Dem_Dcm_FilterRecordGetSRecIndex()       (Dem_Dcm_FilterInfo.Filter.Record.SnapshotIndex)                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter snapshot records snapshot iterator position of Dcm filter info */
#define Dem_Dcm_FilterRecordSetSRecIndex(Index)  (Dem_Dcm_FilterInfo.Filter.Record.SnapshotIndex = (Index))                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get filter time series snapshot iterator position of Dcm filter info */
# define Dem_Dcm_FilterRecordGetTimeSeriesRecordNr()    (Dem_Dcm_FilterInfo.Filter.Record.TimeSeriesRecordNumber)                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter time series snapshot iterator position of Dcm filter info */
# define Dem_Dcm_FilterRecordSetTimeSeriesRecordNr(Nr)  (Dem_Dcm_FilterInfo.Filter.Record.TimeSeriesRecordNumber = (Nr))         /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/*! Get filter snapshot records iterator variable of Dcm filter info */
#define Dem_Dcm_FilterRecordGetIterator()        (&Dem_Dcm_FilterInfo.Filter.Record.Iterator)                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter data state of Dcm filter info */
#define Dem_Dcm_FilterDataGetState()             (Dem_Dcm_FilterInfo.FilterDataState)                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter data state of Dcm filter info */
#define Dem_Dcm_FilterDataSetState(State)        (Dem_Dcm_FilterInfo.FilterDataState = (State))                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get filter data memory Id of Dcm filter info */
#define Dem_Dcm_FilterDataGetMemoryId()          (Dem_Dcm_FilterInfo.Filter.Data.MemoryId)                                       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter data memory Id of Dcm filter info */
#define Dem_Dcm_FilterDataSetMemoryId(Id)        (Dem_Dcm_FilterInfo.Filter.Data.MemoryId = (Id))                                /* PRQA S 3453 */ /* MD_MSR_19.7 */


/* DTC Filter Criteria ------------ */
/*! Test filter criterion status mask */
#define DEM_DCM_TEST_FILTER_USESTATUSMASK(Criteria)     ((uint8)((Criteria) & 0x01U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criterion status mask */
#define DEM_DCM_SET_FILTER_USESTATUSMASK(Criteria)      ((uint8)((Criteria) | 0x01U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset filter criterion status mask */
#define DEM_DCM_RESET_FILTER_USESTATUSMASK(Criteria)    ((uint8)((Criteria) & 0xfeU))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test filter criterion fault detection counter */
#define DEM_DCM_TEST_FILTER_USEFDC(Criteria)            ((uint8)((Criteria) & 0x02U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criterion fault detection counter */
#define DEM_DCM_SET_FILTER_USEFDC(Criteria)             ((uint8)((Criteria) | 0x02U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset filter criterion fault detection counter */
#define DEM_DCM_RESET_FILTER_USEFDC(Criteria)           ((uint8)((Criteria) & 0xfdU))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test filter criterion severity mask */
#define DEM_DCM_TEST_FILTER_USESEVERITY(Criteria)       ((uint8)((Criteria) & 0x04U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criterion severity mask */
#define DEM_DCM_SET_FILTER_USESEVERITY(Criteria)        ((uint8)((Criteria) | 0x04U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Get filter criterion severity mask */
#define DEM_DCM_RESET_FILTER_USESEVERITY(Criteria)      ((uint8)((Criteria) & 0xfbU))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test filter criterion OBD format */
#define DEM_DCM_TEST_FILTER_DTCFORMAT_OBD(Criteria)     ((uint8)((Criteria) & 0x08U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criterion OBD format */
#define DEM_DCM_SET_FILTER_DTCFORMAT_OBD(Criteria)      ((uint8)((Criteria) | 0x08U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset filter criterion OBD format */
#define DEM_DCM_RESET_FILTER_DTCFORMAT_OBD(Criteria)    ((uint8)((Criteria) & 0xf7U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test filter criterion emission related */
#define DEM_DCM_TEST_FILTER_DTCKIND_EMISSION(Criteria)  ((uint8)((Criteria) & 0x10U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criterion emission related */
#define DEM_DCM_SET_FILTER_DTCKIND_EMISSION(Criteria)   ((uint8)((Criteria) | 0x10U))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset filter criterion emission related */
#define DEM_DCM_RESET_FILTER_DTCKIND_EMISSION(Criteria) ((uint8)((Criteria) & 0xefU))                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* DTC Filter Event Reported Marker ------------ */
/*! Size of filtered event marker bitfield */
#define DEM_DCM_FILTER_CALC_MARKER_SIZE(NumEvents)      (uint16)(((NumEvents)+7)/8)                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Index of filtered event marker bitfield */
#define DEM_DCM_FILTER_CALC_MARKER_INDEX(EventId)       (uint16)((EventId)/8)                                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Bitmask of filtered event marker bitfield */
#define DEM_DCM_FILTER_CALC_MARKER_MASK(EventId)        (uint8)(0x01u << ((uint8)((EventId) % 8)))                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get event filtered bit in filtered event bitfield */
#define DEM_DCM_GET_FILTER_EVENT_MARKER(Value, Mask)    (uint8)((Value) & (Mask))                                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set event filtered bit in filtered event bitfield */
#define DEM_DCM_SET_FILTER_EVENT_MARKER(Value, Mask)    (uint8)((Value) | (Mask))                                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset event filtered bit in filtered event bitfield */
#define DEM_DCM_RESET_FILTER_EVENT_MARKER(Value, Mask)  (uint8)((Value) & ~(Mask))                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* DTR */
/*! Test if a MID is a 'supported MID' (0x00, 0x20, 0x40...) */
#define Dem_Dcm_TestMidSupportedMid(Mid)                (((Mid) % 32U) == 0)                                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */



/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Function pointer type for event filter functions */
typedef P2FUNC(Dem_EventIdType, DEM_CODE, Dem_Dcm_FilterFuncPtrType) (
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)
  );

/*! Filter data for Dcm 'filter DTC' requests */
struct Dem_Dcm_FilterDtcInfoType_s
{
  /*! Iterator data */
  union
  {                                                                                                                              /* PRQA S 0750 */ /* MD_MSR_18.4 */
    Dem_EventIdType          EventIndex;  /*!< Event iterator for linar order filtering */
    uint8                    ChronoIndex;  /*!< chronology iterator for chronological order filtering */
  }                          Iterator;
  uint8                      StatusMask;  /*!< Status mask filter */
  sint8                      FaultDetectionCounter;  /*!< FaultDetectionCounter for FDC filter */
  uint8                      MemoryId;  /*!< Filtered event memory */
  Dem_DTCSeverityType        SeverityMask;  /*!< Severity mask filter */
};

/*! Filter data for Dcm 'filter Record' requests */
struct Dem_Dcm_FilterRecordInfoType_s
{
  uint8                      MemoryIndex;  /*!< memory entry iterator position */
  uint8                      SnapshotIndex;  /*!< snapshot record iterator position */
#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
  uint8                      TimeSeriesRecordNumber;  /*!< time series iterator position */
#endif
  Dem_Cfg_EventSRecIterType  Iterator;  /*!< snapshot record configuration iterator position */
};

/*! Filter data for Dcm 'filter event data' requests */
struct Dem_Dcm_FilterDataInfoType_s
{
  Dem_EventIdType            EventId;  /*!< Filtered event Id */
  uint8                      MemoryId;  /*!< Filtered event memory */
};

/*! Filter data for Dcm requests */
struct Dem_Dcm_FilterInfoType_s
{
  union
  {                                                                                                                              /* PRQA S 0750 */ /* MD_MSR_18.4 */
    struct Dem_Dcm_FilterDtcInfoType_s    Dtc;  /*!< Filter data for Dcm 'filter DTC' requests */
    struct Dem_Dcm_FilterRecordInfoType_s Record;  /*!< Filter data for Dcm 'filter Record' requests */
    struct Dem_Dcm_FilterDataInfoType_s   Data;  /*!< Filter data for Dcm 'filter event data' requests */
  }                          Filter;
  uint8                      FilterFlags;  /*!< Filter flags */
  uint8                      FilterDataState;  /*!< Event data lock state */
  Dem_Dcm_FilterFuncPtrType  pFilterDtcFunction;  /*!< Active filter function */
};

/*! Filter data type for Dcm requests */
typedef struct Dem_Dcm_FilterInfoType_s Dem_Dcm_FilterInfoType;

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
/*! Filter data for IUMPR requests */
struct Dem_Dcm_IumprFilterInfoType_s
{
  uint16      FirstEvent;  /*!< First event matching the request */
  uint16      CurrentEvent;  /*!< Current iterator position */
  uint16      LastEvent;  /*!< Last event matching the request */
  uint8       ReadinessGroup;  /*!< Filtered readiness group */
};

/*! Filter data type for IUMPR requests */
typedef struct Dem_Dcm_IumprFilterInfoType_s Dem_Dcm_IumprFilterInfoType;
#endif

#endif /* DEM_DCM_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Dcm_Types.h
 *********************************************************************************************************************/
