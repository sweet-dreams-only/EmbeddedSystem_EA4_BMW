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
 *          File:  Rte_BmwMsgSlot274Bas2Repn4BusFrChA_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwMsgSlot274Bas2Repn4BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_TYPE_H
# define _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BMWFLTLAMPFLSGFRQ_NOFLSG
#   define BMWFLTLAMPFLSGFRQ_NOFLSG (0U)
#  endif

#  ifndef BMWFLTLAMPFLSGFRQ_SLOWFLSG
#   define BMWFLTLAMPFLSGFRQ_SLOWFLSG (1U)
#  endif

#  ifndef BMWFLTLAMPFLSGFRQ_FASTFLSG
#   define BMWFLTLAMPFLSGFRQ_FASTFLSG (2U)
#  endif

#  ifndef BMWFLTLAMPFLSGFRQ_INVLD
#   define BMWFLTLAMPFLSGFRQ_INVLD (3U)
#  endif

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

#  ifndef ST_CC_EPS_Ruecksetzen
#   define ST_CC_EPS_Ruecksetzen (0U)
#  endif

#  ifndef ST_CC_EPS_Setzen
#   define ST_CC_EPS_Setzen (1U)
#  endif

#  ifndef ST_CC_EPS_SignalUngueltig
#   define ST_CC_EPS_SignalUngueltig (3U)
#  endif

#  ifndef ST_IDC_CC_EPS_KeinBlinken
#   define ST_IDC_CC_EPS_KeinBlinken (0U)
#  endif

#  ifndef ST_IDC_CC_EPS_LangsamesBlinken
#   define ST_IDC_CC_EPS_LangsamesBlinken (1U)
#  endif

#  ifndef ST_IDC_CC_EPS_SchnellesBlinken
#   define ST_IDC_CC_EPS_SchnellesBlinken (2U)
#  endif

#  ifndef ST_IDC_CC_EPS_SignalUngueltig
#   define ST_IDC_CC_EPS_SignalUngueltig (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_TYPE_H */
