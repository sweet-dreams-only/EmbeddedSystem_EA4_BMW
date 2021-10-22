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
 *          File:  Rte_BmwSwFctDi_Type.h
 *        Config:  C:/Component/CF108A_BmwSwFctDi_Impl/tools/Component.dpa
 *     SW-C Type:  BmwSwFctDi
 *  Generated at:  Sat Jul 28 12:27:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwSwFctDi> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSWFCTDI_TYPE_H
# define _RTE_BMWSWFCTDI_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"



/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_Coding_DataMode
#  define RTE_MODETYPE_Coding_DataMode
typedef uint8 Rte_ModeType_Coding_DataMode;
# endif

# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
#  define RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS (0U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
#  define RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT (1U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED (2U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED (3U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED (4U)
# endif
# ifndef RTE_TRANSITION_Coding_DataMode
#  define RTE_TRANSITION_Coding_DataMode (5U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSWFCTDI_TYPE_H */
