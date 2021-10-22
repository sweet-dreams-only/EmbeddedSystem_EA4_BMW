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
 *            Module: WdgIf
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgIf_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:07
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

#define WDGIF_LCFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Wdg_59_DriverA.h" 
#include "WdgIf_Lcfg.h" 
#include "WdgIf.h" 


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGIF_LCFG_C_MAJOR_VERSION (2u) 
#define WDGIF_LCFG_C_MINOR_VERSION (1u) 
#define WDGIF_LCFG_C_PATCH_VERSION (0u) 

/* Check the version of WdgIf header file */
#if ( (WDGIF_SW_MAJOR_VERSION != (5u)) \
   || (WDGIF_SW_MINOR_VERSION != (2u)) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf.h are inconsistent!"
#endif

/* Check the version of WdgIf_Lcfg header file */
#if ( (WDGIF_LCFG_MAJOR_VERSION != WDGIF_LCFG_C_MAJOR_VERSION) \
   || (WDGIF_LCFG_MINOR_VERSION != WDGIF_LCFG_C_MINOR_VERSION) \
   || (WDGIF_LCFG_PATCH_VERSION != WDGIF_LCFG_C_PATCH_VERSION) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf_Lcfg.h are inconsistent!"
#endif

#if !defined (WDGIF_LOCAL) /* COV_WDGIF_COMPATIBILITY */
# define WDGIF_LOCAL static
#endif

#define WDGIF_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDGIF_LOCAL const WdgIf_InterfaceFunctionsType wdgifdevice_functions = 
{
  Wdg_59_DriverA_SetMode /*  Wdg_SetMode  */ , 
  Wdg_59_DriverA_SetTriggerCondition /*  Wdg_SetTriggerCondition  */ 
}; /* WdgGeneral */ 


WDGIF_LOCAL const WdgIf_InterfaceFunctionsPerWdgDeviceType WdgIf_FunctionsPerWdg [WDGIF_NUMBER_OF_WDGIFDEVICES] =
{
  {
    &wdgifdevice_functions /*  WdgFunctions  */ 
  } /*  [0]  */ 
};

const WdgIf_InterfaceType WdgIf_Interface =
{
  WDGIF_NUMBER_OF_WDGIFDEVICES /*  NumOfWdgs  */ , 
  WdgIf_FunctionsPerWdg /*  WdgFunctionsPerDevice  */ 
};

#define WDGIF_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Lcfg.c
 *********************************************************************************************************************/

