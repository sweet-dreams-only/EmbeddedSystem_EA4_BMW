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
 *  \defgroup   Dem_ExtDataElementIF ExtDataElementIF
 *  \{
 *  \file       Dem_ExtDataElementIF_Interface.h
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

#if !defined (DEM_EXTDATAELEMENTIF_INTERFACE_H)
#define DEM_EXTDATAELEMENTIF_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ExtDataElementIF_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ExtDataElementIF_Properties Properties
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ExtDataElementIF_Private Private Methods
 * \{
 */
#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectUserData
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves C/S user data or S/R user data with data type
 *                uint8 Array from the application and stores it into the
 *                passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectUserData(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectCSDataWithEventId
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves C/S user data from the application and stores it into
 *                the passed buffer. The callback also passes the EventId to
 *                the application.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectCSDataWithEventId(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Boolean
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type boolean from the
 *                application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Boolean(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint8
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint8 from the
 *                application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint8(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif


#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Uint8
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type uint8 from the
 *                application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Uint8(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint16
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint16 (Motorola)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex 
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint16(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint16_Intel
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint16 (Intel)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint16_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Uint16
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type uint16 (Motorola)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Uint16(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Uint16_Intel
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type uint16 (Intel)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Uint16_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint32
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint32 (Motorola)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint32(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint32_Intel
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint32 (Intel)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint32_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Uint32
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type uint32 (Motorola)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Uint32(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_Dem_ExtDataElementIF_CollectSRData_Uint32_Intel
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type uint32 (Intel)
 *                from the application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dem_ExtDataElementIF_CollectSRData_Uint32_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectSRData_Sint8_N
 *****************************************************************************/
/*!
 * \brief         Requests user data from application
 *
 * \details       Retrieves S/R user data with data type sint8 Array from the
 *                application and stores it into the passed buffer.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \pre           -
 * \config        ( (DEM_CFG_SUPPORT_ERECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *               || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *               || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *               || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) 
 *               || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) 
 *               || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint8_N(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if ( ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
     || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
     || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
     || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) ) \
   && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectRootCauseEventId
 *****************************************************************************/
/*!
 * \brief         Store the event that caused event memory storage
 *
 * \details       Stores the EventId of the event which caused event memory
 *                storage. For combined events this stores the exact sub-event.
 *
 * \param[in]     CollectDidInfoPtr
 *                CollectDid context
 *
 * \pre           -
 * \config        ( ( (DEM_CFG_SUPPORT_ERECS == STD_ON)
 *                 || (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *                 || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *                 || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *                 || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)
 *                 || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
 *               && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectRootCauseEventId(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr
  );
#endif
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ExtDataElementIF_Public Public Methods
 * \{
 */
#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_InitCollectDidInfo
 *****************************************************************************/
/*!
 * \brief         Initializes CollectDidInfo context
 *
 * \details       Initializes CollectDidInfo context
 *
 * \param[in,out] CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DestinationBuffer
 *                Destination buffer receiving the DID data
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     BufferSize
 *                Buffer size of the destination buffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_SRECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON  ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_InitCollectDidInfo(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestinationBuffer,
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(uint16, AUTOMATIC) BufferSize);
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectDataElement
 *****************************************************************************/
/*!
 * \brief         Copies data element collected from application into a buffer.
 *
 * \details       Collects a data element from a application and copies it
 *                into the destination buffer.
 *
 * \param[in,out] CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DataIndex
 *                Unique handle of the data element
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_SRECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON  ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_ExtDataElementIF_CollectDataElement(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_ExtDataElementIF_CollectStoredDid
 *****************************************************************************/
/*!
 * \brief         Collects the environment data to store for a data identifier
 *
 * \details       Stores all data elements attached to a data identifier object
 *                into the destination buffer.
 *                Note that a data identifier in this context is not only a
 *                UDS DID, but can also be an extended data record or PID.
 *
 * \param[in,out] CollectDidInfoPtr
 *                CollectDid context
 * \param[in]     DidIndex
 *                Unique handle of the DID
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_SRECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON  ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectStoredDid(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  );
#endif
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EXTDATAELEMENTIF_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ExtDataElementIF_Interface.h
 *********************************************************************************************************************/
