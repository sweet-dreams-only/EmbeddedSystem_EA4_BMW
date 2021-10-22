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
/*! \addtogroup Dem_Ungrouped
 *  \{
 *  \file       Dem_MemCopy.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of MemCopy subcomponent
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

#if !defined (DEM_MEMCOPY_H)
#define DEM_MEMCOPY_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Cfg_Macros.h"
#if (DEM_CFG_USE_MEMCOPY_MACROS == STD_OFF)
#include "vstdlib.h"
#endif
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
*  SUBCOMPONENT FUNCTION MACROS
*********************************************************************************************************************/

#if (DEM_CFG_USE_MEMCOPY_MACROS == STD_ON)                                                                                       /* COV_MSR_UNSUPPORTED XF */
# if !defined(Dem_MemCpy_Macro)
/*! Default Macro implementation of memcopy. Can be used instead of external function call. BEWARE: 'dst' and 'src' MUST have the type 'uint8 *'. */
#  define Dem_MemCpy_Macro(dst, src, len)        { uint16_least lMemCopyIndex; \
                                                   for ( lMemCopyIndex = 0x00u; lMemCopyIndex < (len); ++lMemCopyIndex) \
                                                   { (dst)[lMemCopyIndex] = (src)[lMemCopyIndex]; \
                                                 } }                                                                             /* PRQA S 3453, 3458 */ /* MD_MSR_19.7, MD_MSR_19.7 */
# endif

# if !defined(Dem_MemSet_Macro)
/*! Macro implementation of memset. Can be used instead of external function call. BEWARE: 'dst' MUST have the type 'uint8 *'. */
#  define Dem_MemSet_Macro(dst, val, len)        { uint16_least lMemCopyIndex; \
                                                   for ( lMemCopyIndex = 0x00u; lMemCopyIndex < (len); ++lMemCopyIndex) \
                                                   { (dst)[lMemCopyIndex] = (val); \
                                                 } }                                                                             /* PRQA S 3453, 3458 */ /* MD_MSR_19.7, MD_MSR_19.7 */
# endif

/*! Wrapper macro for memcopy */
# define Dem_MemCpy(dst, src, len)               Dem_MemCpy_Macro((dst), (src), (len))                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Wrapper macro for memset */
# define Dem_MemSet(dst, val, len)               Dem_MemSet_Macro((dst), (val), (len))                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
/*! Wrapper macro for memcopy */
# define Dem_MemCpy(dst, src, len)               VStdMemCpy((Dem_DataPtrType)(dst), (Dem_DataPtrType)(src), (len))               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Wrapper macro for memset */
# define Dem_MemSet(dst, val, len)               VStdMemSet((Dem_DataPtrType)(dst), (val), (len))                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#endif /* DEM_MEMCOPY_H */
/*!
 *  \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemCopy.h
 *********************************************************************************************************************/
