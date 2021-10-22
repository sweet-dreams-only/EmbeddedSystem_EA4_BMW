
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
 *         File:  Dem_Dcm.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Static public API declarations of Dem.
 *                Dynamically available APIs are declared in the generated file Rte_Dem.h
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

#if !defined (DEM_DCM_H)
#define DEM_DCM_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
                                                               /* Dem itself */
/* ------------------------------------------------------------------------- */
#include "Dem.h"
/* ------------------------------------------------------------------------- */

                                /* Dcm, required because of Dcm_OpStatusType */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_OBDII == STD_ON) && ((DEM_CFG_SUPPORT_VID08 == STD_ON) || (DEM_CFG_SUPPORT_VID0B == STD_ON))                /* COV_MSR_UNSUPPORTED XF xf xf xf */
# include "Dcm.h"
#endif
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_DCM != STD_ON)
# error "Dcm API is not supported"
#endif

#include "Dem_DcmAPI_Interface.h"

#endif  /* DEM_DCM_H */
/*!
 *  \}
 */

/* ********************************************************************************************************************
 *  END OF FILE: Dem_DcmS.h
 *********************************************************************************************************************/