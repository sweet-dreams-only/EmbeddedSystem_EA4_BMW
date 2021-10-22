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
 *  \addtogroup Dem_ClearTask
 *  \{
 *  \file       Dem_ClearTask_Types.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Public types of ClearTask subcomponent
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

#if !defined (DEM_CLEARTASK_TYPES_H)
#define DEM_CLEARTASK_TYPES_H

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
 * \defgroup  Dem_ClearTask_State  Macros encoding the state of the current clear operation
 * Macros encoding the state of the current clear operation
 * \{
 */
#define DEM_CLEARTASK_IDLE                (0x00U)  /*!< No clear operation in progress */
#define DEM_CLEARTASK_NEW                 (0x01U)  /*!< Clear operation started */
#define DEM_CLEARTASK_INPROGRESS          (0x02U)  /*!< Clear operation ongoing */
#define DEM_CLEARTASK_DONE                (0x03U)  /*!< Clear operation finished */
#define DEM_CLEARTASK_FAILED              (0x04U)  /*!< Clear operation failed */
#define DEM_CLEARTASK_NVERROR             (0x05U)  /*!< Write error during clear operation */
#define DEM_CLEARTASK_NV_INPROGRESS       (0x06U)  /*!< Wait for NV operation to finish */
/*!
 * \}
 */


/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Clear DTC request structure definition */
struct Dem_ClearTask_ClearRequestType_s
{
  Dem_EventIdType ClearEventId;  /*!< Specific EventId to clear */
  uint8  ClearMemoryId;  /*!< MemoryId to clear */
  uint8  ClearGroup;  /*!< DTC group to clear */
  uint8  ClearClient;  /*!< Client requesting the clear */
  uint8  ClearCode;  /*!< Event status code to clear */
  uint8  ClearMask;  /*!< Event status mask to clear */
  uint8  ClearNode;  /*!< J1939 Node to clear */
};

/*! Type to store a clear DTC request */
typedef struct Dem_ClearTask_ClearRequestType_s Dem_ClearTask_ClearRequestType;

typedef P2VAR(Dem_ClearTask_ClearRequestType, TYPEDEF, AUTOMATIC)  Dem_ClearTask_ClearRequestPtrType;
typedef P2CONST(Dem_ClearTask_ClearRequestType, TYPEDEF, AUTOMATIC)  Dem_ClearTask_ClearRequestConstPtrType;

#endif /* DEM_CLEARTASK_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ClearTask_Types.h
 *********************************************************************************************************************/
