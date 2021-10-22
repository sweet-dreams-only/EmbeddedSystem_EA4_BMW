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
 *          File:  Rte_BmwFltHndlg_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwFltHndlg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWFLTHNDLG_TYPE_H
# define _RTE_BMWFLTHNDLG_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BMWFLTLAMPREQSTS_FLTLAMPRSTREQD
#   define BMWFLTLAMPREQSTS_FLTLAMPRSTREQD (0U)
#  endif

#  ifndef BMWFLTLAMPREQSTS_FLTLAMPSETREQD
#   define BMWFLTLAMPREQSTS_FLTLAMPSETREQD (1U)
#  endif

#  ifndef BMWFLTLAMPREQSTS_INVLD
#   define BMWFLTLAMPREQSTS_INVLD (3U)
#  endif

#  ifndef BMWFLTLAMPREQTYP_NOLAMP
#   define BMWFLTLAMPREQTYP_NOLAMP (0U)
#  endif

#  ifndef BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP
#   define BMWFLTLAMPREQTYP_EPTI_INSPNRLVLAMP (1U)
#  endif

#  ifndef BMWFLTLAMPREQTYP_NORMWARNLAMP
#   define BMWFLTLAMPREQTYP_NORMWARNLAMP (2U)
#  endif

#  ifndef BMWFLTLAMPREQTYP_THERMWARNLAMP
#   define BMWFLTLAMPREQTYP_THERMWARNLAMP (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWFLTHNDLG_TYPE_H */
