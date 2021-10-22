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
 *          File:  Rte_BmwMotTqOvrlArbn_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwMotTqOvrlArbn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMOTTQOVRLARBN_TYPE_H
# define _RTE_BMWMOTTQOVRLARBN_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BMWNEARSTILLVEHSPDSTS_VEHREST
#   define BMWNEARSTILLVEHSPDSTS_VEHREST (12U)
#  endif

#  ifndef BMWNEARSTILLVEHSPDSTS_VEHNOTREST
#   define BMWNEARSTILLVEHSPDSTS_VEHNOTREST (13U)
#  endif

#  ifndef BMWNEARSTILLVEHSPDSTS_INVLD
#   define BMWNEARSTILLVEHSPDSTS_INVLD (15U)
#  endif

#  ifndef BMWTRFCJAMASSIST_INACTV
#   define BMWTRFCJAMASSIST_INACTV (1U)
#  endif

#  ifndef BMWTRFCJAMASSIST_ACTV
#   define BMWTRFCJAMASSIST_ACTV (2U)
#  endif

#  ifndef BMWTRFCJAMASSIST_INVLD
#   define BMWTRFCJAMASSIST_INVLD (15U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMOTTQOVRLARBN_TYPE_H */
