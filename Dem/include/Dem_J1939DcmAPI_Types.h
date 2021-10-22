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
/*! \addtogroup Dem_J1939DcmAPI
 *  \{
 *  \file       Dem_J1939DcmAPI_Types.h
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

#if !defined (DEM_J1939DCMAPI_TYPES_H)
#define DEM_J1939DCMAPI_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
#if ( (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) \
   || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) \
   || (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON) )
                                                        /* J1939 Dcm filters */
/* ------------------------------------------------------------------------- */
/*! Get filter criteria of J1939Dcm filter */
# define Dem_J1939Dcm_FilterGetCriteria()               (Dem_J1939Dcm_FilterInfo.FilterFlags)                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set filter criteria of J1939Dcm filter */
# define Dem_J1939Dcm_FilterSetCriteria(Criteria)       (Dem_J1939Dcm_FilterInfo.FilterFlags = (Criteria))                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get memory id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcGetMemoryId()            (Dem_J1939Dcm_FilterInfo.MemoryId)                                       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set memory id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcSetMemoryId(Index)       (Dem_J1939Dcm_FilterInfo.MemoryId = (Index))                             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get event iterator position id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcGetEventIndex()          (Dem_J1939Dcm_FilterInfo.EventIndex)                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set event iterator position id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcSetEventIndex(Index)     (Dem_J1939Dcm_FilterInfo.EventIndex = (Index))                           /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get node id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcGetNodeId()              (Dem_J1939Dcm_FilterInfo.Node)                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set node id of J1939Dcm filter */
# define Dem_J1939Dcm_FilterDtcSetNodeId(Index)         (Dem_J1939Dcm_FilterInfo.Node = (Index))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */

# if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
/*! Get freeze frame kind of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataGetKind()              (Dem_J1939Dcm_FilterInfo.FreezeFrameKind)                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set freeze frame kind of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataSetKind(kind)          (Dem_J1939Dcm_FilterInfo.FreezeFrameKind = (kind))                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get freeze frame event iterator position of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataGetEventId()           (Dem_J1939Dcm_FilterInfo.EventIndex)                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set freeze frame event iterator position of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataSetEventId(EventId)    (Dem_J1939Dcm_FilterInfo.EventIndex = (EventId))                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get freeze frame filter state of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataGetState()             (Dem_J1939Dcm_FilterInfo.FilterDataState)                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set freeze frame filter state of J1939Dcm filter */
#  define Dem_J1939Dcm_FilterDataSetState(State)        (Dem_J1939Dcm_FilterInfo.FilterDataState = (State))                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED TF */
/*! Get freeze frame filter node Id of J1939Dcm filter */
#   define Dem_J1939Dcm_FilterDataGetNodeId()           (Dem_J1939Dcm_FilterInfo.Node)                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set freeze frame filter node Id of J1939Dcm filter */
#   define Dem_J1939Dcm_FilterDataSetNodeId(Index)      (Dem_J1939Dcm_FilterInfo.Node = (Index))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif
# endif
#endif

#if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
/*! NodeId value for J1939 */
# define DEM_J1939_NODE_ID            lJ1939NodeId
#else
/*! NodeId value for J1939 */
# define DEM_J1939_NODE_ID            0x00U
#endif

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Filter data for J1939Dcm requests */
struct Dem_J1939Dcm_FilterInfoType_s
{
  Dem_EventIdType                      EventIndex;  /*!< Event iterator for linar order filtering */
  uint8                                MemoryId;  /*!< Filtered event memory */
# if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
  Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;  /*!< Filtered freeze frame kind */
  uint8                                FilterDataState;  /*!< Event data lock state */
# endif
  uint8                                FilterFlags;  /*!< Filter flags */
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  uint8                                Node;  /*!< Filtered J1939 node */
# endif
};

/*! Filter data type for J1939Dcm requests */
typedef struct Dem_J1939Dcm_FilterInfoType_s Dem_J1939_FilterInfoType;
#endif

#endif /* DEM_J1939DCMAPI_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_J1939DcmAPI_Types.h
 *********************************************************************************************************************/
