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
 *          File:  Rte_PullCmpActv_Type.h
 *        Config:  C:/Component/SF013A_PullCmpActv_Impl/tools/Component.dpa
 *     SW-C Type:  PullCmpActv
 *  Generated at:  Wed Jan 24 10:44:46 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <PullCmpActv> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PULLCMPACTV_TYPE_H
# define _RTE_PULLCMPACTV_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

# ifndef NVM_REQ_OK
#  define NVM_REQ_OK (0U)
# endif

# ifndef NVM_REQ_NOT_OK
#  define NVM_REQ_NOT_OK (1U)
# endif

# ifndef NVM_REQ_PENDING
#  define NVM_REQ_PENDING (2U)
# endif

# ifndef NVM_REQ_INTEGRITY_FAILED
#  define NVM_REQ_INTEGRITY_FAILED (3U)
# endif

# ifndef NVM_REQ_BLOCK_SKIPPED
#  define NVM_REQ_BLOCK_SKIPPED (4U)
# endif

# ifndef NVM_REQ_NV_INVALIDATED
#  define NVM_REQ_NV_INVALIDATED (5U)
# endif

# ifndef NVM_REQ_CANCELED
#  define NVM_REQ_CANCELED (6U)
# endif

# ifndef NVM_REQ_REDUNDANCY_FAILED
#  define NVM_REQ_REDUNDANCY_FAILED (7U)
# endif

# ifndef NVM_REQ_RESTORED_FROM_ROM
#  define NVM_REQ_RESTORED_FROM_ROM (8U)
# endif


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PULLCMPACTV_TYPE_H */
