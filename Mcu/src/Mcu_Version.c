/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains version check of modules included by MCU Driver         */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version
 *
 * V1.0.1:  08-Oct-2014 : As per CR008 and mantis #19850, Following changes
 *                        is made,
 *                        1. Trace marking is added in the file
 *
 * V1.0.2:  26-Nov-2014 : As per CR076 and mantis #25069, file is updated
 *                        to remove trim Trailing spaces.
 * V1.0.3:  02-Jan-2016 : As per V4.0.5 activity, SchM version check is added.
 *                        1. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        2. Copyright year updated.
 * V1.0.4:  21-Apr-2016 : Following changes are done as part of P1M 4.01.01
 *                        release
 *                        1. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        2. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0001*/
/* Implements EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0069*/
/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0018 */
/* Header file inclusion */
#include "Mcu_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*Implements EAAR_PN0034_FR_0055*/
/* AUTOSAR release version information */
#define MCU_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                           MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                           MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_VERSION_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_VERSION_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                   MCU_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Version.c : Mismatch in Release Major Version"
#endif /* (MCU_VERSION_AR_RELEASE_MAJOR_VERSION != \
        *                           MCU_VERSION_C_AR_RELEASE_MAJOR_VERSION)
        */

#if (MCU_VERSION_AR_RELEASE_MINOR_VERSION != \
                                   MCU_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Version.c : Mismatch in Release Minor Version"
#endif /* (MCU_VERSION_AR_RELEASE_MINOR_VERSION != \
        *                           MCU_VERSION_C_AR_RELEASE_MINOR_VERSION)
        */

#if (MCU_VERSION_AR_RELEASE_REVISION_VERSION != \
                                   MCU_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Version.c : Mismatch in Release Revision Version"
#endif /* (MCU_VERSION_AR_RELEASE_REVISION_VERSION != \
        *                        MCU_VERSION_C_AR_RELEASE_REVISION_VERSION)
        */

#if (MCU_VERSION_SW_MAJOR_VERSION != MCU_VERSION_C_SW_MAJOR_VERSION)
  #error "Mcu_Version.c : Mismatch in Software Major Version"
#endif /* (MCU_VERSION_SW_MAJOR_VERSION != MCU_VERSION_C_SW_MAJOR_VERSION) */

#if (MCU_VERSION_SW_MINOR_VERSION != MCU_VERSION_C_SW_MINOR_VERSION)
  #error "Mcu_Version.c : Mismatch in Software Minor Version"
#endif /* (MCU_VERSION_SW_MINOR_VERSION != MCU_VERSION_C_SW_MINOR_VERSION) */

/* Implements MCU_ESDD_UD_057 */
#if (MCU_VERSION_CHECK_EXT_MODULES == STD_ON)

/* Implements MCU110 */
/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||  \
    (DEM_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Implements MCU_ESDD_UD_052 */
/* Implements MCU110 */
/* Det Module Version Check */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||  \
    (DET_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* #if (MCU_DEV_ERROR_DETECT == STD_ON) */

/* Os Module Version Check */
/* Implements MCU110 */
#if ((OS_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
    (OS_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif

/* Rte Module Version Check */
/* Implements MCU110 */
/* Implements MCU_ESDD_UD_058 */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||  \
    (RTE_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Implements MCU_ESDD_UD_058 */
/* Implements MCU110 */
/* SchM Module Version Check */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((SCHM_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) ||  \
    (SCHM_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of SchM.h does not match the expected version"
#endif
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */



#endif /* (MCU_VERSION_CHECK_EXT_MODULES == STD_ON) */


/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
