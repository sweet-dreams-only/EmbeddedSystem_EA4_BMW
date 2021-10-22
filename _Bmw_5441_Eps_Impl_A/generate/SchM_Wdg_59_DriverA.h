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
 *          File:  SchM_Wdg_59_DriverA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Wdg_59_DriverA>
 *********************************************************************************************************************/
#ifndef SCHM_WDG_59_DRIVERA_H
# define SCHM_WDG_59_DRIVERA_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Wdg_59_DriverA_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_MODE_SWITCH_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_MODE_SWITCH_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_TRIGG_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_TRIGG_PROTECTION(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_WDG_59_DRIVERA_H */
