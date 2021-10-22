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
 *            Module: FrTrcv
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTrcv_30_Tja1082_Cfg.h
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


#if !defined(FRTRCV_30_TJA1082_CFG_H)
#define FRTRCV_30_TJA1082_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ General Define Block
 ----------------------------------------------------------------------------- */

#ifndef FRTRCV_30_TJA1082_USE_DUMMY_FUNCTIONS
#define FRTRCV_30_TJA1082_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FRTRCV_30_TJA1082_USE_DUMMY_STATEMENT
#define FRTRCV_30_TJA1082_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FRTRCV_30_TJA1082_DUMMY_STATEMENT
#define FRTRCV_30_TJA1082_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTRCV_30_TJA1082_DUMMY_STATEMENT_CONST
#define FRTRCV_30_TJA1082_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRTRCV_30_TJA1082_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRTRCV_30_TJA1082_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FRTRCV_30_TJA1082_ATOMIC_VARIABLE_ACCESS
#define FRTRCV_30_TJA1082_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FRTRCV_30_TJA1082_PROCESSOR_RH850_1363
#define FRTRCV_30_TJA1082_PROCESSOR_RH850_1363
#endif
#ifndef FRTRCV_30_TJA1082_COMP_GREENHILLS
#define FRTRCV_30_TJA1082_COMP_GREENHILLS
#endif
#ifndef FRTRCV_30_TJA1082_GEN_GENERATOR_MSR
#define FRTRCV_30_TJA1082_GEN_GENERATOR_MSR
#endif
#ifndef FRTRCV_30_TJA1082_CPUTYPE_BITORDER_LSB2MSB
#define FRTRCV_30_TJA1082_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_PRECOMPILE
#define FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_LINKTIME
#define FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FRTRCV_30_TJA1082_CONFIGURATION_VARIANT
#define FRTRCV_30_TJA1082_CONFIGURATION_VARIANT FRTRCV_30_TJA1082_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FRTRCV_30_TJA1082_POSTBUILD_VARIANT_SUPPORT
#define FRTRCV_30_TJA1082_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/* -----------------------------------------------------------------------------
    &&&~ Constants
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - DrvTrans_Tja1082FrAsrPreCompileCRC */
#define FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES         1
/* AUTOSAR Version Info */
#define FRTRCV_30_TJA1082_AUTOSARVERSION                4
/* Main Function call cycle time in ms */
#define FRTRCV_30_TJA1082_MAIN_FUNCTION_CYCLE_TIME      5
/* Pre-processor switch to enable the Development Error Tracer. */
#define FRTRCV_30_TJA1082_DEV_ERROR_DETECT              STD_ON
#define FRTRCV_30_TJA1082_DEV_ERROR_REPORT              STD_OFF
/* Pre-processor switch to enable the Diagnostic Event Manager. */
#define FRTRCV_30_TJA1082_PROD_ERROR_DETECT             STD_OFF
#define FRTRCV_30_TJA1082_TRCV_DEM_CALLBACK             STD_OFF
/* Pre-processor switch to enable version info support. ON/OFF */
#define FRTRCV_30_TJA1082_VERSION_INFO_API              STD_ON
/* Pre-processor switch to enable Wakeup Support. ON/OFF */
#define FRTRCV_30_TJA1082_WAKEUP_SUPPORT                STD_OFF



/* -----------------------------------------------------------------------------
    &&&~ User Config File content
 ----------------------------------------------------------------------------- */
 
/* User Config File Start */

/* User Config File End */


#endif /* FRTRCV_30_TJA1082_CFG_H */
    
