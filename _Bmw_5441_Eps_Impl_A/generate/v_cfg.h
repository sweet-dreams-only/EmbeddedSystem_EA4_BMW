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
 *            Module: EcuC
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: v_cfg.h
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

#if !defined(__V_CFG_H__)
#define __V_CFG_H__


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef V_USE_DUMMY_FUNCTIONS
#define V_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef V_USE_DUMMY_STATEMENT
#define V_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef V_DUMMY_STATEMENT
#define V_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_DUMMY_STATEMENT_CONST
#define V_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define V_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef V_ATOMIC_VARIABLE_ACCESS
#define V_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef V_PROCESSOR_RH850_1363
#define V_PROCESSOR_RH850_1363
#endif
#ifndef V_COMP_GREENHILLS
#define V_COMP_GREENHILLS
#endif
#ifndef V_GEN_GENERATOR_MSR
#define V_GEN_GENERATOR_MSR
#endif
#ifndef V_CPUTYPE_BITORDER_LSB2MSB
#define V_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef V_CONFIGURATION_VARIANT_PRECOMPILE
#define V_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef V_CONFIGURATION_VARIANT_LINKTIME
#define V_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef V_CONFIGURATION_VARIANT
#define V_CONFIGURATION_VARIANT V_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef V_POSTBUILD_VARIANT_SUPPORT
#define V_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef C_USE_DUMMY_FUNCTIONS
#define C_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef C_USE_DUMMY_STATEMENT
#define C_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef C_DUMMY_STATEMENT
#define C_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_DUMMY_STATEMENT_CONST
#define C_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define C_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef C_ATOMIC_VARIABLE_ACCESS
#define C_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef C_PROCESSOR_RH850_1363
#define C_PROCESSOR_RH850_1363
#endif
#ifndef C_COMP_GREENHILLS
#define C_COMP_GREENHILLS
#endif
#ifndef C_GEN_GENERATOR_MSR
#define C_GEN_GENERATOR_MSR
#endif
#ifndef C_CPUTYPE_BITORDER_LSB2MSB
#define C_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef C_CONFIGURATION_VARIANT_PRECOMPILE
#define C_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef C_CONFIGURATION_VARIANT_LINKTIME
#define C_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef C_CONFIGURATION_VARIANT
#define C_CONFIGURATION_VARIANT C_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef C_POSTBUILD_VARIANT_SUPPORT
#define C_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define V_DISABLE_USE_DUMMY_FUNCTIONS
#define V_DISABLE_USE_DUMMY_STATEMENT
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* __V_CFG_H__ */
/**********************************************************************************************************************
 *  END OF FILE: v_cfg.h
 *********************************************************************************************************************/    

