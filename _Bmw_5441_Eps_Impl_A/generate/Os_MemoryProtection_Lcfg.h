/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_MemoryProtection_Lcfg.h
 *   Generation Time: 2018-07-30 19:49:08
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_MEMORYPROTECTION_LCFG_H)                                            /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Memory protection configuration data */
extern CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore_CORE0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl8;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Appl9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_OsCounter;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Fr_IrqLine0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Fr_IrqTimer0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_MCU_ECM_EIC_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIG0_TIC_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIG0_TIRE_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIG0_TIR_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIH2_TIC_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIH2_TIRE_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIH2_TIR_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore_CORE0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_100ms_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_100ms_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_100ms_Appl9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_10msBsw_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_10ms_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_10ms_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_10ms_Appl8;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_10ms_Appl9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2msA_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2msB_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2msTmplMonr_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2ms_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2ms_Appl8;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_2ms_Appl9;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_4msBsw_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_4ms_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_4ms_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_5msBsw_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_Coding_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_ComBsw_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_InitBsw_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_Init_Appl10;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_Init_Appl7;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_Init_Appl8;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Task_Init_Appl9;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Memory protection configuration data */
extern CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
