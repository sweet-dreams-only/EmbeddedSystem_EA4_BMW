
/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*!  Project    MICROSAR Diagnostic Event Manager (Dem)
 *
 *  \addtogroup Dem_Main
 *  \{
 *  \file       Dem.c
 *  \brief      Implementation header file for the MICROSAR Dem
 *  \details    Implementation of DEM module
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/
#define DEM_SOURCE

/* ********************************************************************************************************************
 *  GLOBAL MISRA VIOLATIONS
 *********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */
/* PRQA S 0810 EOF */ /* MD_MSR_1.1_810 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 3406 EOF */ /* MD_DEM_8.5 */

/* ********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

                                                       /* Dem module headers */
/* ------------------------------------------------------------------------- */
#include "Dem.h"
#include "Dem_Cbk.h"

#include "Dem_Int.h"

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
# include "Dem_Dcm.h"
#endif

                            /* Development error tracer, for Det_ReportError */
/* ------------------------------------------------------------------------- */
#if (DEM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
/* ------------------------------------------------------------------------- */

                   /* Diagnostic Logger and Tracer, for callback declaration */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_NOTIFY_DLT == STD_ON)
# include "Dlt.h"
#endif
/* ------------------------------------------------------------------------- */

      /* Fault inhibition manager, for callbacks and IUMPR inhibition matrix */
/* ------------------------------------------------------------------------- */
#if (((DEM_CFG_SUPPORT_OBDII == STD_ON) || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)) \
   && (DEM_CFG_SUPPORT_IUMPR == STD_ON)) || (DEM_CFG_NOTIFY_FIM == STD_ON)                                                       /* COV_MSR_UNSUPPORTED TF xf xf xf tf */
# include "FiM.h"
#endif
/* ------------------------------------------------------------------------- */

                                  /* Schedule Manager, for critical sections */
/* ------------------------------------------------------------------------- */
#include "SchM_Dem.h"
/* ------------------------------------------------------------------------- */

                               /* Rte for forward global callback prototypes */
/* ------------------------------------------------------------------------- */
#include "Dem_Swc.h"
/* ------------------------------------------------------------------------- */

                                            /* Dcm for notification callback */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_NOTIFY_DCM == STD_ON)
# include "Dcm.h"
#endif
/* ------------------------------------------------------------------------- */

                                       /* J1939Dcm for notification callback */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_NOTIFY_J1939DCM == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
# include "J1939Dcm.h"
#endif
/* ------------------------------------------------------------------------- */

                                                          /* NvM for its API */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"
#endif
/* ------------------------------------------------------------------------- */

                                                       /* EcuM for ErrorHook */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_VARIANT_POSTBUILD_LOADABLE == STD_ON)
# include "EcuM_Error.h"
#endif

                                           /* OS for GetCurrentApplicationID */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
# include "Os.h"
#endif
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON)                                                                            /* COV_MSR_UNSUPPORTED XF */
# include "DidMuSa.h"
#endif

#if (DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON) && (DEM_CFG_USE_OHDS == STD_ON)
# include "OHDS_Dem.h"
#endif

/* ********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is decimal coded */
#if ( (DEM_SW_MAJOR_VERSION != 13) \
   || (DEM_SW_MINOR_VERSION !=  6) \
   || (DEM_SW_PATCH_VERSION !=  2) )
# error "Vendor specific version numbers of Dem.c and Dem.h are inconsistent"
#endif

/* versions of all included configuration header files shall be checked */
#if ( (DEM_CFG_SW_MAJOR_VERSION != 13) \
   || (DEM_CFG_SW_MINOR_VERSION !=  6) )
# error "Version numbers of Dem.c and Dem_Cfg.h are inconsistent!"
#endif

#if (DEM_CFG_GEN_MAJOR_VERSION != 11)
# error "Incompatible configuration file version used!"
#endif

                                                            /* subcomponents */
/* ------------------------------------------------------------------------- */
#include "Dem_AdditionalIncludeCfg.h"

#include "Dem_Cfg_Declarations.h"
#include "Dem_Cfg_Definitions.h"

#include "Dem_Error_Implementation.h"
#include "Dem_API_Implementation.h"
#include "Dem_DcmAPI_Implementation.h"
#include "Dem_Memory_Implementation.h"
#include "Dem_DataReportIF_Implementation.h"
#include "Dem_DataStorageIF_Implementation.h"
#include "Dem_Data_Implementation.h"
#include "Dem_Queue_Implementation.h"
#include "Dem_Esm_Implementation.h"

/*!
 * \}
 */

/* module specific MISRA deviations:

   MD_DEM_1.1_612
     Description: Rule 1.1
                  All code shall conform to ISO 9899:1990 C programming language, ISO 9899, amended and corrected by
                  ISO/IEC 9899/COR1:1995, ISO/IEC 9899/AMD1:1995, and ISO/IEC 9899/COR2: 1996
     Reason:      Depending on the configuration size the generated tables can
                  exceed the C90 limit of 32767 bytes
     Risk:        Compilation error.
     Prevention:  Compiler compatibility must be tested during integration.

   MD_DEM_5.1
     Description: Rule 5.1
                  Identifiers (internal and external) shall not rely on the significance of more than 31 characters.
     Reason:      The API is standardized and a change would break compliance.
     Risk:        Compilation errors are possible.
     Prevention:  Compiler compatibility is tested during integration.

   MD_DEM_8.5:
     Description: Rule 8.5
                  There shall be no definitions of objects or functions in a header file.
     Reason:      Subcomponent structure is implemented in header files. The implementation files can be identified by
                  their name ending in _Implementation.h
     Risk:        None.
     Prevention:  None.

   MD_DEM_8.7:
     Description: Rule 8.7
                  Objects shall be defined at block scope if they are only accessed from within a single function.
     Reason:      Vector style guide prevents usage of static variables in function scope
     Risk:        None.
     Prevention:  None.

   MD_DEM_8.8_dcm:
     Description: Rule 8.8
                  An external object or function shall be declared in one and only one file.
     Reason:      MICROSAR Dcm generates all prototypes of functions used. This leads to duplicate definitions.
     Risk:        None.
     Prevention:  None.

   MD_DEM_11.1:
     Decription:  Rule 11.1
                  Conversions shall not be performed between a pointer to a function and any type other than an integral type.
     Reason:      Different types of callback functions need to be supported through a generic mechanism
     Risk:        Functions are cast to the wrong type before calling.
     Prevention:  The correct function type is indicated by type tagging. The correct cast is verified during code review.

   MD_DEM_11.4_cpy:
     Description: Rule 11.4
                  A cast should not be performed between a pointer to object type and a different pointer to object
                  type.
     Reason:      Use of memcopy/memset requires common pointer type.
     Risk:        Data corruption due to miscast.
     Prevention:  Covered by descriptive pointer types and code review for correct usage.

   MD_DEM_11.4_inh:
     Description: Rule 11.4
                  A cast should not be performed between a pointer to object type and a different pointer to object
                  type.
     Reason:      Use of inheritance pattern requires cast to specific class type.
     Risk:        Data corruption due to miscast.
     Prevention:  Covered by descriptive pointer types and code review for correct usage.

   MD_DEM_11.4_nvm:
     Description: Rule 11.4
                  A cast should not be performed between a pointer to object type and a different pointer to object
                  type.
     Reason:      Mechanism for Nv handling requires common pointer type
     Risk:        None. Pointers are initially aligned and only cast due to common API later on.
     Prevention:  Covered by descriptive pointer types and code review for correct usage.

   MD_DEM_11.4_sr:
     Description: Rule 11.4
                  A cast should not be performed between a pointer to object type and a different pointer to object
                  type.
     Reason:      Serialization of typed data.
     Risk:        Data corruption due to miscast.
     Prevention:  Covered by descriptive pointer types and code review for correct usage.

   MD_DEM_11.5:
     Description: Rule 11.5
                  A cast shall not be performed that removes any const or volatile qualification from the type
                  addressed by a pointer.
     Reason:      MemSet and MemCpy are defined as taking an unqualified pointer.
     Risk:        None.
     Prevention:  Safe access of shared data is verified during code review.

   MD_DEM_12.4_cs:
     Description: Rule 12.4
                  The right hand operand of a logical && or || operator shall not contain side effects
     Reason:      The function must be called in a critical section, so the access to volatile variables does not
                  apply as side effect.
     Risk:        Additional calls might be introduces later outside the critical section.
     Prevention:  Requirement for critical section is documented and compliance is assured during code review.

   MD_DEM_12.4_cf:
     Description: Rule 12.4
                  The right hand operand of a logical && or || operator shall not contain side effects
     Reason:      The function called on the right hand side has no side effects.
     Risk:        The function may introduce side effects at a later time.
     Prevention:  Code analysis (e.g. MISRA).

   MD_DEM_12.4_m:
     Description: Rule 12.4
                  The right hand operand of a logical && or || operator shall not contain side effects
     Reason:      The right hand operand may only be evaluated if the left hand operator is valid. This is more
                  maintainable than introducing additional levels of nesting, since nesting does reduce readibility
                  and does not reduce the risk of missing the order dependency of the two terms.
     Risk:        Later rework might miss the dependency and turn the order of checks around.
     Prevention:  Code analysis (e.g. MISRA) and review.

   MD_DEM_13.3:
     Description: Rule 13.3
                  Floating-point expressions shall not be tested for equality or inequality.
     Reason:      Test for generatad special value.
     Risk:        None
     Prevention:  Correctness is ensured in test suite.

   MD_DEM_13.6:
     Description: Rule 13.6
                  Numeric variables being used within a for loop for iteration counting shall not be modified in the
                  body of the loop.
     Reason:      Restore loop invariant in an error case.
     Risk:        Difficult to maintain.
     Prevention:  Correctness is ensured in test suite.

   MD_DEM_13.7:
     Description: Rule 13.7
                  Boolean operations whose results are invariant shall not be permitted.
     Reason:      The expression is not invariant. Depending on supported features invariant value is possible but
                  the resulting code modification will adversely affect maintainability of already complicated code
                  paths.
     Risk:        Compiler warnings or compiler errors depending on configuration.
     Prevention:  None.

   MD_DEM_14.1_ACCESSOR
     Description: Rule 14.1
                  Static function '%s()' is not used within this translation unit.
     Reason:      Accessor function ('getter', 'setter') is present although no code is actively using it.
                  Accessor functions do not provide functionality, and are not conditionally compiled to increase
                  maintainability.
     Risk:        Compiler warnings depending on configuration.
                  No reduced code size with a special configuration, not realized optimization.
     Prevention:  None.

   MD_DEM_14.1:
     Description: Rule 14.1
                  This switch default label is unreachable.
     Reason:      Switch default labels are mandatory due to mandatory MISRA rule 15.3 'The final clause of a switch
                  statement shall be the default clause.'.
     Risk:        Compiler warnings or compiler errors depending on configuration.
                  Default branch cannot be tested.
     Prevention:  None.

   MD_DEM_14.2:
     Description: Rule 14.2
                  All non-null statements shall either (i) have at least one side-effect however executed, or
                  (ii) cause control flow to change
     Reason:      This statement is used to avoid warnings caused by unused parameters. Parameters are defined by
                  standardized API requirements, and not needed in case a feature is disabled by configuration.
                  It is either impossible due to API standardization or necessary code duplication (severe maintenance
                  increase) to provide feature dependent APIs with different signatures.
     Risk:        Unavoidable compiler warning or error because of either unused statements or unused parameter.
     Prevention:  None.

   MD_DEM_14.5:
     Description: Rule 14.5
                  The continue statement shall not be used
     Reason:      The continue statement is used in a circumstance where a different approach would reduce efficiency
                  or maintainability due to increased complexity.
     Risk:        None.
     Prevention:  None.

   MD_DEM_14.6_err:
     Description: Rule 14.6
                  For any iteration statement there shall be at most one break statement used for loop termination.
     Reason:      The loop needs multiple exit points since error conditions cannot be verified prior to the loop.
     Risk:        None.
     Prevention:  None.

   MD_DEM_14.6_opt:
     Description: Rule 14.6
                  For any iteration statement there shall be at most one break statement used for loop termination.
     Reason:      Increased efficiency on the time critical path
     Risk:        Maintainability is adversely affected.
     Prevention:  The break statement is documented.

   MD_DEM_14.7:
     Description: Rule 14.7
                  A function shall have a single point of exit at the end of the function.
     Reason:      Due to maintainability problems the control flow through the function shall not be complicated even
                  further.
     Risk:        Maintainability is adversely affected.
     Prevention:  None.

   MD_DEM_15.2:
     Description: Rule 15.2
                  An unconditional break statement shall terminate every non-empty switch clause.
     Reason:      The fall-through is preferred to an if-else cascade to avoid code duplication in this particular
                  circumstance.
     Risk:        Adverse effect on maintainability.
     Prevention:  The fall-through is documented.

   MD_DEM_16.4_dcm:
     Description: Rule 16.4
                  The identifiers used in the declaration and definition of a function shall be identical
     Reason:      Dcm generates its own prototypes based on a generic algorithm.
     Risk:        Dcm prototypes can deviate from the implementation.
     Prevention:  Verify compatibility during integraton tests.

   MD_DEM_16.4_rte:
     Description: Rule 16.4
                  The identifiers used in the declaration and definition of a function shall be identical
     Reason:      Port-Defined arguments are not generated with the correct name. This can currently not be influenced
                  due to the RTE being a third party module.
     Risk:        None. The generated prototypes are never used directly but only from generated RTE code.
     Prevention:  None.

   MD_DEM_16.7:
     Description: Rule 16.7
                  A pointer parameter in a function prototype should be declared as pointer to const if the pointer is
                  not used to modify the addressed object.
     Reason:      The API is standardized and a change would break compliance.
     Risk:        None.
     Prevention:  None.

   MD_DEM_16.7_False:
     Description: Rule 16.7
                  A pointer parameter in a function prototype should be declared as pointer to const if the pointer is
                  not used to modify the addressed object.
     Reason:      The data behind the pointer is modified, or modified in some configurations. This is a false positive.
     Risk:        None.
     Prevention:  None.

   MD_DEM_16.7_Internal:
     Description: Rule 16.7
                  A pointer parameter in a function prototype should be declared as pointer to const if the pointer is
                  not used to modify the addressed object.
     Reason:      The API has to be compatible to a common prototype
     Risk:        None.
     Prevention:  None.

   MD_DEM_16.7_Design:
     Description: Rule 16.7
                  A pointer parameter in a function prototype should be declared as pointer to const if the pointer is
                  not used to modify the addressed object.
     Reason:      The function has write access to shared state. The caller may not rely on constancy. Even if the
                  current implementation does not need write access, this is allowed to change. A stable interface is
                  preferred to adhering to this rule.
     Risk:        None.
     Prevention:  None.

   MD_DEM_16.9_fp:
     Description: Rule 16.9
                  A function identifier shall only be used with either a preceding &, or with a parenthesised parameter
                  list, which may be empty.
     Reason:      There is a preceeding &, and the use as a function pointer is intended
     Risk:        None.
     Prevention:  None.

   MD_DEM_19_7:
     Description: Rule 19.7
                  A function should be used in preference to a function-like macro. 
     Reason:      The calculation result is used on preprocessor level
     Risk:        Resulting code is difficult to understand or may not work as expected.
     Prevention:  Code inspection and test of the different variants in the component test. 

   MD_DEM_19.13:
     Description: Rule 19.13
                  K&R compilers do not support the ISO glue operator '##'.
     Reason:      This kind of implementation creates the least MISRA warnings.
     Risk:        K&R compilers will not work.
     Prevention:  Integration test using target compiler, error directives to detect evaluation errors.

   MD_DEM_19.15:
     Description: Rule 19.15
                  Precautions shall be taken in order to prevent the contents of a header file being included twice.
     Reason:      Precautions HAVE been taken, this violation is a false positive.
     Risk:        None.
     Prevention:  None.

   MD_DEM_20.2:
     Description: Rule 20.2
                  The names of standard library macros, objects and functions shall not be reused.
     Reason:      Included from vector standard library.
     Risk:        Name collision with different standard library.
     Prevention:  None.

   MD_DEM_21.1_negative:
     Description: Rule 21.1
                  Minimisation of run-time failures shall be ensured by the use of at least one of (a) static analysis
                  tools/techniques; (b) dynamic analysis tools/techniques; (c) explicit coding of checks to handle
                  run-time faults.
     Reason:      The value of the lMid - 1 could become negative.
     Risk:        Undefined behavior.
     Prevention:  0 is not a valid value in the generated configuration and will therefore not occur at runtime.

   MD_DEM_21.1_Always_Negative:
     Description: Rule 21.1
                  Minimisation of run-time failures shall be ensured by the use of at least one of (a) static analysis
                  tools/techniques; (b) dynamic analysis tools/techniques; (c) explicit coding of checks to handle
                  run-time faults.
     Reason:      Signed value is never evaluated. Value is used only for bitwise operations.
     Risk:        None.
     Prevention:  None.

   MD_DEM_0832:
     Description: Rule N/A
                  Macro substitution in #include preprocessor directive.
     Reason:      The include file name is not known because it depends on configuration.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3197_na:
     Description: Rule N/A
                  The initialiser for '%s' is always modified before being used.
     Reason:      Assignment is necessary for an inactive code branch. Reworking the code would have negative effects
                  on maintainability, which is deemed more important.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3198_fp:
     Description: Rule N/A
                  The value assigned to '%s' is always modified before being used.
     Reason:      False positive.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3382:
     Description: Rule 21.1
                  Unsigned arithmetic apparently results in wraparound past zero.
     Reason:      The operands of this arithmetic operation are verified in previous steps and this operation can never 
                  result in a wraparound past zero.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3198_na:
     Description: Rule N/A
                  The value assigned to '%s' is always modified before being used.
     Reason:      Assignment is necessary for an inactive code branch. Reworking the code would have negative effects
                  on maintainability, which is deemed more important.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3199:
     Description: Rule N/A
                  The value of '%s' is never used following this assignment.
     Reason:      The function argument cannot be removed, bacause it is either used in a different configuration,
                  or required by design.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3203:
     Description: Rule N/A
                  The variable '%s' is set but never used.
     Reason:      The variable cannot be removed, because it is used in a different configuration.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3206:
     Description: Rule N/A
                  The parameter '%s' is not used in this function.
     Reason:      API / Standardized API is not adapted based on configuration
     Risk:        None.
     Prevention:  None.

   MD_DEM_3305:
     Description: Rule N/A
                  Pointer cast to stricter alignment
     Reason:      Already aligned pointers are handled in a generic way.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3356:
     Description: Rule 13.7
                  The result of this logical operation is always 'false'
     Reason:      With only a specific configuration, the is logical operation always false
     Risk:        None.
     Prevention:  None.

   MD_DEM_3359:
     Description: Rule 13.7
                  The result of this logical operation is always 'false'
     Reason:      With only a specific configuration, the is logical operation always false
     Risk:        None.
     Prevention:  None.

   MD_DEM_3325:
     Description: Rule 14.1
                  This control expression has a constant 'false' value
     Reason:      With only a specific configuration, the is control expression is always false
     Risk:        None.
     Prevention:  None.

   MD_DEM_3201:
     Description: Rule 14.1
                  This statement is unreachable
     Reason:      The line of code is unreachable due to configuration specific reasons
     Risk:        None.
     Prevention:  None.

   MD_DEM_COMSTACKLIB:
     Description: Rule 14.1
                  This statement is unreachable
                  Control expression has a constant TRUE/FALSE value
     Reason:      Comstacklib optimization causes a control statement to compare two constant values depending on configuration
     Risk:        Compiler warnings issued during compilation.
     Prevention:  None.

   MD_DEM_TEST:
     Description: Multiple rules
     Reason:      Test code does not respect MISRA coding standard
     Risk:        None.
     Prevention:  None.

   MD_DEM_1915:
     Description: Rule 19.15 Precautions shall be taken in order to prevent the contents of a header file being included twice
     Reason:      Memmap.h must be included multiple times, so header file guards must not be present.
     Risk:        None.
     Prevention:  None.

   MD_DEM_3.1:
     Description: Rule 3.1
                  An integer constant expression with negative value is being converted to an unsigned type.
     Reason:      The result of a not operation is converted to a uint8.
     Risk:        There is no risk due to the defines and there on/off setting is static for a concrete delivery
                  and so is the include structure.
     Prevention:  Runtime test during delivery tests on target platform verify that all includes can be found
                  and are applied.

*/
/**********************************************************************************************************************
 COV_JUSTIFICATION_BEGIN

 \ID COV_DEM_ORGANI_COMMENT
   \REASON This section only contains commentaries that are removed from the source before delivery.

 \ID COV_DEM_TESTCODE
   \REASON This section only contains code to help test the software. It has no influence on the actual code. All such
           code is removed from the source before delivery.

 \COV_DEM_BITCALCULATION
   \REASON The coverage tool cannot evaluate the preprocessor coverage. The line coverage is sufficient to tell that
           all decisions have been covered.

 COV_JUSTIFICATION_END
 *********************************************************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_DEM_POINTER_WRITE_API
  \DESCRIPTION    In an API function, data is written through a pointer passed as function argument.
  \COUNTERMEASURE \N The caller ensures the pointers passed to this function are valid.

\ID SBSW_DEM_POINTER_WRITE_ARGUMENT
  \DESCRIPTION    In an internal function, data is written through a pointer passed as function argument.
  \COUNTERMEASURE \N The caller ensures the pointers passed to this function are valid.

\ID SBSW_DEM_POINTER_FORWARD_ARGUMENT
  \DESCRIPTION    A pointer parameter is received as argument and forwarded to another function expecting a valid
                  pointer. The called function does not store its pointer parameters.
  \COUNTERMEASURE \N The pointer is used unmodified, as such it is still valid.

\ID SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER
  \DESCRIPTION    A pointer parameter and buffer size are received as argument. The function writes to the buffer,
                  or forwards the buffer and buffer size to another function which will write data to the buffer.
                  The called function will only write up to the number of bytes received as argument.
  \COUNTERMEASURE \R [CM_DEM_R_CHECK_REMAINING_BUFFER]

\ID SBSW_DEM_POINTER_FORWARD_STACK
  \DESCRIPTION    A pointer is passed to a function expecting a valid pointer. The called function does not store its
                  pointer parameter.
  \COUNTERMEASURE \N The pointer is taken from a local variable, as such it is always valid.

\ID SBSW_DEM_POINTER_FORWARD_GLOBAL
  \DESCRIPTION    A pointer is passed to a function expecting a valid pointer.
  \COUNTERMEASURE \N The pointer is taken from a global variable, as such it is always valid.

\ID SBSW_DEM_POINTER_FORWARD_API
  \DESCRIPTION    One or multiple pointer(s) received in the API function are passed to a function expecting one or
                  more valid pointers.
  \COUNTERMEASURE \N The caller ensures that pointers passed to this function are valid.

\ID SBSW_DEM_NVM_WRITEBLOCK
  \DESCRIPTION    A NvMBlockId and a source pointer is passed to NvM_WriteBlock.
  \COUNTERMEASURE \R [CM_DEM_R_CHECK_NVBLOCKID]
                  \S [CM_DEM_S_CHECK_NVBLOCKID]
                  \S [CM_DEM_S_CHECK_NVBLOCK_LENGTH]

\ID SBSW_DEM_POINTER_MEMCPY_TIMESERIESENTRY
  \DESCRIPTION    In an internal function, a memory area is copied through a pointer to a memory entry. The entry
                  pointer is initialized by Dem_Mem_TimeSeriesGetEntry which will always return a pointer to a valid memory
                  entry. The number of bytes copied is the size of the target buffer.
  \COUNTERMEASURE \R [CM_DEM_R_TIMESERIES_GET_ENTRY]
                  \M [CM_DEM_M_TIMESERIESINDEX_LIMITS]
                  \M [CM_DEM_M_SIZEOF_MEMORYDATAPTR]
                  \S [CM_DEM_M_TIMESERIESINDEX_TYPE]

\ID SBSW_DEM_POINTER_MEMCPY_READOUTBUFFER
  \DESCRIPTION    In an internal function, data is copied into the ReadoutBuffer using memcpy. Dem_Cfg_ReadoutBuffer
                  is a global variable, as such the pointer is always valid. The buffer size to copy is derived by sizeof.
  \COUNTERMEASURE \N The memory area is always valid.

\ID SBSW_DEM_POINTER_MEMCPY_TIMESERIESREADOUTBUFFER
  \DESCRIPTION    In an internal function, data is copied into the TimeSeriesReadoutBuffer using memcpy. Dem_Cfg_TimeSeriesReadoutBuffer
                  is a global variable, as such the pointer is always valid. The buffer size to copy is derived by sizeof.
  \COUNTERMEASURE \N The memory area is always valid.

\ID SBSW_DEM_CALL_FOREACH_FUNCPTR
  \DESCRIPTION    In an internal function, a pointer passed as function argument is called, with a pointer argument as argument.
  \COUNTERMEASURE \N The caller ensures that both pointers passed to this function are valid, and the argument pointer is a valid
                     argument for the function pointer.

\ID SBSW_DEM_CALL_ITERATOR_POINTER
  \DESCRIPTION    The iterator pattern works like this:
                  The functions Dem_Cfg_<X>IterInit, Dem_Cfg_<X>IterExists, Dem_Cfg_<X>IterNext, Dem_Cfg_<X>IterGet
                  receive a pointer to an iterator variable Dem_Cfg_<X>IterType.
                  The Dem_Cfg_<X>IterInit initializes the iterator variable, so it is valid to be used by the other three functions. Those
                  functions expect a reference to a valid iterator variable. The iterator variable is still valid when those
                  functions return.
  \COUNTERMEASURE \N The iterator variable is initialized using the appropriate Init function before passing its reference
                     to Dem_Cfg_<X>IterExists/Dem_Cfg_<X>IterNext/Dem_Cfg_<X>IterGet.

\ID SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER
  \DESCRIPTION    The iterator pattern works like this:
                  The functions Dem_Cfg_<X>IterInit, Dem_Cfg_<X>IterExists, Dem_Cfg_<X>IterNext, Dem_Cfg_<X>IterGet
                  receive a pointer to an iterator variable Dem_Cfg_<X>IterType.
                  The Dem_Cfg_<X>IterInit initializes the iterator variable, so it is valid to be used by the other three
                  functions. Those functions expect a reference to a valid iterator variable. The iterator variable is still
                  valid when those functions return.
                  Dem_Cfg_<X>IterGet will verify the iterator is still in range of the target table to prevent
                  returning a table row with invalid pointer contents.
  \COUNTERMEASURE \R [CM_DEM_R_INIT_MONITOR_FOR_FUNCTION_INDEX]
                  \R [CM_DEM_R_EVENT_CBK_STATUS_INDEX]
                  \R [CM_DEM_R_DTC_CBK_STATUS_INDEX]

\ID SBSW_DEM_CLEARDTCTEST_ITERATOR
  \DESCRIPTION    The iterator pattern works like this:
                  The functions <X>IterInit, <X>IterExists, <X>IterNext, <X>IterGet receive a pointer to
                  a local stack variable of type <X>IterType.
                  The Dem_Cfg_<X>IterInit initializes the iterator variable, so it is valid to be used by the other three functions.
                  The iterator variable remains valid when these functions return.
                  This iterator guarantees that <X>IterGet will always return a valid function pointer, as long as the
                  iterator was initialized with <X>IterInit.
  \COUNTERMEASURE \R [CM_DEM_R_CLEARDTCTEST_ITERATOR]

\ID SBSW_DEM_CALL_MEMORYINFO_POINTER
  \DESCRIPTION    The memory info pointer is locally allocated and initialized using Dem_MemStorageManager_MemoryInfoInit.
  \COUNTERMEASURE \N The pointer is always valid.

\ID SBSW_DEM_CALL_DEBOUNCEINFO_INIT
  \DESCRIPTION    The debounce info pointer is locally allocated and passed to Dem_Debounce_DebounceInfoInit for initialization.
  \COUNTERMEASURE \N The pointer is always valid.

\ID SBSW_DEM_CALL_DEBOUNCEINFO_POINTER
  \DESCRIPTION    A debounce info pointer is locally allocated and passed as argument to other functions.
                  As a reference to a local stack variable the pointer itself is always valid.
                  The pointer is initialized using Dem_Debounce_DebounceInfoInit, which will always initialize it to point
                  to an existing debounce info struct.
  \COUNTERMEASURE \R [CM_DEM_R_DEBOUNCEINFO_INIT]

\ID SBSW_DEM_CALL_FUNCPTR_DEBOUNCEINFO_POINTER
  \DESCRIPTION    A debounce info pointer is locally allocated and passed as argument to a function pointer stored in
                  the debounce info.
                  As a reference to a local stack variable the pointer itself is always valid.
                  The pointer is initialized using Dem_Debounce_DebounceInfoInit, which will always initialize it to point
                  to an existing debounce info struct. This also initializes the function pointer table, so the dereferenced
                  function pointer is always valid.
  \COUNTERMEASURE \R [CM_DEM_R_DEBOUNCEINFO_INIT]

\ID SBSW_DEM_POINTER_LOCAL_COPYDIDINFO
  \DESCRIPTION    A pointer to a CopyDidInfo structure is passed to a function expecting a valid CopyDidInfo. The struct
                  fields are initialized with values that are expected to be valid:
                  The destination buffer pointer can be received via a *Dcm API. It is the responsibility of the Dcm
                  to pass a destination buffer and matching size.
                  The destination buffer pointer can alternatively be a pointer received from an application API without
                  size information. The application must ensure that the buffer is large enough to receive
                  MaxDataValueSize bytes of data.
                  The buffer size is initialized to the corresponding buffer size.
                  The remaining fields do not influence the write location by design.
                  The struct pointer passed to the called function points to a stack variable and is always valid.
  \COUNTERMEASURE \S [CM_DEM_S_SIZE_OF_RECORD_DATA_BUFFER]

\ID SBSW_DEM_POINTER_LOCAL_COLLECTDIDINFO
  \DESCRIPTION    A pointer to a CollectDidInfo structure is passed to a function expecting a valid CollectDidInfo.
                  The struct fields are initialized with values that are expected to be valid.
  \COUNTERMEASURE \N The caller ensures that the pointer and size information are valid. The struct pointer itself
                     points to a stack variable and is always valid.

\ID SBSW_DEM_POINTER_NORMAL_TIME_SERIES_COLLECTDIDINFO
  \DESCRIPTION    A pointer to a locally defined CollectDidInfo structure is passed to a function expecting a valid
                  CollectDidInfo.
                  The destination buffer pointer is initialized from Dem_Mem_RingBufferNormalRatePtr() which will always
                  return a valid pointer.
                  The buffer size is initialized to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_RINGBUFFER_NORMALRATEPTR]
                  \M [CM_DEM_M_SIZEOF_NORMAL_RATE_RINGBUFFER]

\ID SBSW_DEM_POINTER_FAST_TIME_SERIES_COLLECTDIDINFO
  \DESCRIPTION    A pointer to a locally defined CollectDidInfo structure is passed to a function expecting a valid
                  CollectDidInfo.
                  The destination buffer pointer is initialized from Dem_Mem_RingBufferFastRatePtr() which will always
                  return a valid pointer.
                  The buffer size is initialized to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_RINGBUFFER_FASTRATEPTR]
                  \M [CM_DEM_M_SIZEOF_FAST_RATE_RINGBUFFER]

\ID SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER
  \DESCRIPTION    An amount of data is written into the destination buffer pointer of a CollectDidInfo or CopyDidInfo.
                  The caller is responsible that buffer pointer and buffer length are correct (see also
                  SBSW_DEM_POINTER_LOCAL_COPYDIDINFO, SBSW_DEM_POINTER_LOCAL_COLLECTDIDINFO)
  \COUNTERMEASURE \R [CM_DEM_R_CHECK_REMAINING_BUFFER]

\ID SBSW_DEM_CALL_DIDINFO_DESTINATIONBUFFER
  \DESCRIPTION    An application callback is invoked to write data into the destination buffer pointer of a CollectDidInfo
                  or CopyDidInfo.
                  The caller is responsible that buffer pointer and buffer length are correct (see also
                  SBSW_DEM_POINTER_LOCAL_COPYDIDINFO, SBSW_DEM_POINTER_LOCAL_COLLECTDIDINFO).
  \COUNTERMEASURE \R [CM_DEM_R_CHECK_REMAINING_BUFFER]
                  \R [CM_DEM_R_SIZEOF_DATAELEMENT_TABLE]
                  \R [CM_DEM_R_CHECK_DATAELEMENT_TYPE]
                  \S [CM_DEM_S_DATA_CALLBACK_FPTR]
                  \S [CM_DEM_S_CALL_DESTINATIONBUFFER]

\ID SBSW_DEM_POINTER_EXTENDEDDATA_BUFFER
  \DESCRIPTION    A pointer to a locally defined CollectDidInfo structure is passed to a function expecting a valid
                  CollectDidInfo.
                  The destination buffer pointer is initialized from Dem_Mem_EntryGetERecDataPtr() which will always
                  return a valid pointer.
                  The buffer size is initialized to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_MEMORY_GET_ERECDATAPTR]
                  \M [CM_DEM_M_SIZEOF_MEMORYENTRY_EXTENDEDDATA]

\ID SBSW_DEM_POINTER_SNAPSHOT_BUFFER
  \DESCRIPTION    A destination buffer pointer and buffer size is passed into a function that will write to the passed
                  memory area.
                  The pointer argument is returned from Dem_Mem_EntryGetSRecDataPtr() which will always return a valid
                  pointer.
                  The buffer size argument is set to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_MEMORY_GET_SRECDATAPTR]
                  \M [CM_DEM_M_SIZEOF_MEMORYENTRY_SNAPSHOTDATA]

\ID SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY
  \DESCRIPTION    In an internal function, data is written through a pointer to a time series entry, or the pointer is
                  passed to a function expecting a valid reference to a time series entry.
                  The memory entry pointer is initialized by Dem_Mem_TimeSeriesGetEntry which will always return a pointer
                  to a valid time series entry.
  \COUNTERMEASURE \R [CM_DEM_R_TIMESERIES_GET_ENTRY]
                  \M [CM_DEM_M_TIMESERIESINDEX_LIMITS]
                  \M [CM_DEM_M_SIZEOF_MEMORYDATAPTR]
                  \S [CM_DEM_M_TIMESERIESINDEX_TYPE]

\ID SBSW_DEM_POINTER_TIMESERIESENTRY_NORMALBUFFER
  \DESCRIPTION    A destination buffer pointer and buffer size is passed into a function that will write to the passed
                  memory area.
                  The pointer argument is returned from Dem_Mem_TimeSeriesEntryGetNormalDataPtr() which will always
                  return a valid pointer.
                  The buffer size is set to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_TIMESERIES_GET_NORMALDATAPTR]
                  \M [CM_DEM_M_SIZEOF_SERIESENTRY_NORMAL_SNAPSHOTDATA]

\ID SBSW_DEM_POINTER_TIMESERIESENTRY_FASTBUFFER
  \DESCRIPTION    A destination buffer pointer and buffer size is passed into a function that will write to the passed
                  memory area.
                  The pointer argument is returned from Dem_Mem_TimeSeriesEntryGetFastDataPtr() which will always
                  return a valid pointer.
                  The buffer size is set to the corresponding buffer size.
  \COUNTERMEASURE \R [CM_DEM_R_TIMESERIES_GET_FASTDATAPTR]
                  \M [CM_DEM_M_SIZEOF_SERIESENTRY_FAST_SNAPSHOTDATA]

\ID SBSW_DEM_CALL_FOREACH_COMBINED_EVENT
  \DESCRIPTION    A function passes a function pointer and argument struct to Dem_DTC_ForEachCombinedEvent. The function
                  is a function label, as such it is always valid. The argument struct is a reference to a local stack
                  variable.
  \COUNTERMEASURE \N The pointers are always valid.

\ID SBSW_DEM_CALL_DTCFILTER_FPTR
  \DESCRIPTION    A function dereferences the function pointer Dem_FilterData_GetFilterFunction(). The dereferenced function
                  expects a valid pointer argument and does not store the passed pointer. The passed pointer is initialized
                  using Dem_MemStorageManager_MemoryInfoInit.
  \COUNTERMEASURE \R [CM_DEM_R_DTCFILTER_FPTR]

\ID SBSW_DEM_MEMCOPY_MEMORY_DATA
  \DESCRIPTION    A function copies data into Dem_Cfg_CommitBuffer using memcopy.
  \COUNTERMEASURE \R [CM_DEM_R_MEMORYDATA_INDEX]
                  \M [CM_DEM_M_SIZEOF_MEMORYDATAPTR]
                  \S [CM_DEM_M_SIZEOF_COMMIT_BUFFER]
                  \S [CM_DEM_S_CHECK_NVBLOCK_LENGTH]

\ID SBSW_DEM_ARRAY_WRITE_ADMINDATA_CYCLECOUNTER
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_AdminData.CycleCounter[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_DEM_CFG_ADMINDATA_CYCLECOUNTER_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_ADMINDATA_CYCLECOUNTER]

\ID SBSW_DEM_ARRAY_WRITE_STATUSDATA_EVENTSTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_StatusData.EventStatus[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_DEM_CFG_STATUSDATA_EVENTSTATUS_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_STATUSDATA_EVENTSTATUS]

\ID SBSW_DEM_ARRAY_WRITE_STATUSDATA_TRIPCOUNT
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_StatusData.TripCount[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_DEM_CFG_STATUSDATA_TRIPCOUNT_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_STATUSDATA_TRIPCOUNT]

\ID SBSW_DEM_ARRAY_WRITE_EVENTINTERNALSTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventInternalStatus[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID SBSW_DEM_MEMSET_EVENTINTERNALSTATUS
  \DESCRIPTION    Dem_Cfg_EventInternalStatus[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \N Similar to CSL02: The ComStackLib guarantees that the array size is correctly returned by the GetSize access macro.

\ID SBSW_DEM_ARRAY_WRITE_EVENTDEBOUNCEVALUE
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventDebounceValue[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_EVENTMAXDEBOUNCEVALUES
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventMaxDebounceValue[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_COMBINEDGROUPSTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_CombinedGroupStatus[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_COMBINEDGROUPINTERNALSTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_CombinedGroupInternalStatus[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_DEBOUNCEDATA
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_DebounceData[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_DEBOUNCEDATA_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_DEBOUNCEDATA]

\ID SBSW_DEM_MEMSET_DEBOUNCEDATA
  \DESCRIPTION    Dem_Cfg_DebounceData[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_DEBOUNCEDATA]

\ID SBSW_DEM_ARRAY_WRITE_EVENTAVAILABLEDATA
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventAvailableData[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_AVAILABLEDATA_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_EVENTAVAILABLEDATA]

\ID SBSW_DEM_MEMSET_EVENTAVAILABLEDATA
  \DESCRIPTION    Dem_Cfg_EventAvailableData[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_EVENTAVAILABLEDATA]

\ID SBSW_DEM_ARRAY_WRITE_PRESTORAGEINDEX
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_PrestorageIndex[] using a configured index.
  \COUNTERMEASURE \R [CM_DEM_R_PRESTORAGE_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_PRESTORAGEINDEX]

\ID SBSW_DEM_MEMSET_PRESTORAGEINDEX
  \DESCRIPTION    Dem_Cfg_PrestorageIndex[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_PRESTORAGEINDEX]

\ID SBSW_DEM_POINTER_WRITE_PRESTORAGEENTRY
  \DESCRIPTION    In an internal function, data is written through a handle (position) of a prestorage entry, or the position is
                  passed to a function expecting a valid position of a prestorage entry.
                  The memory entry position is initialized by Dem_Prestore_FindPrestorageEntry() or
                  Dem_Prestore_AllocatePrestorageEntry() which will always return a position of an existing memory entry.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_PRESTORAGE]

\ID SBSW_DEM_ARRAY_WRITE_MEMORYCOMMITNUMBER
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_MemoryCommitNumber[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_DEM_MEMSET_MEMORYCOMMITNUMBER
  \DESCRIPTION    Dem_Cfg_MemoryCommitNumber[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_MEMORYCOMMITNUMBER]

\ID SBSW_DEM_ARRAY_WRITE_MEMORYCHRONOLOGY
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_PrimaryChronology[], Dem_Cfg_SecondaryChronology[] or
                  Dem_Cfg_TimeSeriesChronology[] using a function argument as index. A valid MemoryInfo structure must
                  be provided by the caller.
  \COUNTERMEASURE \R [CM_DEM_R_MEMORYCHRONOLOGY_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_PRIMARYCHRONOLOGY]
                  \M [CM_DEM_M_SIZEOF_SECONDARYCHRONOLOGY]
                  \M [CM_DEM_M_SIZEOF_TIMESERIES_CHRONOLOGY]

\ID SBSW_DEM_ARRAY_WRITE_INDICATORCONTINUOUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_IndicatorContinuous[][] using function arguments as indices.
  \COUNTERMEASURE \R [CM_DEM_R_INDICATORCONTINUOUS_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_INDICATORCONTINUOUS]

\ID SBSW_DEM_ARRAY_WRITE_INDICATORBLINKING
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_IndicatorBlinking[][] using function arguments as indices.
  \COUNTERMEASURE \R [CM_DEM_R_INDICATORBLINKING_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_INDICATORBLINKING]

\ID SBSW_DEM_ARRAY_WRITE_MEMORYSTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_MemoryStatus[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_MEMORYSTATUS_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_MEMORYSTATUS]

\ID SBSW_DEM_MEMSET_MEMORYSTATUS
  \DESCRIPTION    Dem_Cfg_MemoryStatus[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_MEMORYSTATUS]

\ID SBSW_DEM_ARRAY_WRITE_EVENTQUEUE
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventQueue[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_EVENTQUEUE_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_EVENTQUEUE]

\ID SBSW_DEM_ARRAY_WRITE_EVENTQUEUESTATUS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_EventQueueStatus[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_FILTERREPORTEDEVENTS
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_FilterReportedEvents[] using a function argument as index.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_DEM_ARRAY_WRITE_MISSINGTIMESERIESNORMALRATE
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_MissingTimeSeriesNormalRate[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_MISSINGTIMESERIESNORMALRATE_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_MISSINGTIMESERIESNORMALRATE]

\ID SBSW_DEM_MEMSET_MISSINGTIMESERIESNORMALRATE
  \DESCRIPTION    Dem_Cfg_MissingTimeSeriesNormalRate[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_MISSINGTIMESERIESNORMALRATE]

\ID SBSW_DEM_ARRAY_WRITE_MISSINGTIMESERIESFASTRATE
  \DESCRIPTION    In a function, data is written to array Dem_Cfg_MissingTimeSeriesFastRate[] using a function argument as index.
  \COUNTERMEASURE \R [CM_DEM_R_MISSINGTIMESERIESFASTRATE_INDEX_CHECK]
                  \M [CM_DEM_M_SIZEOF_MISSINGTIMESERIESFASTRATE]

\ID SBSW_DEM_MEMSET_MISSINGTIMESERIESFASTRATE
  \DESCRIPTION    Dem_Cfg_MissingTimeSeriesFastRate[] is initialized using memset. The array size is multiplied with the array base
                  size type to make sure the initialized memory area is correct.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_MISSINGTIMESERIESFASTRATE]

\ID SBSW_DEM_CLEARALLOWED_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced. The dereferenced function expects a valid
                  pointer argument and does not store the passed pointer. A pointer to a local stack variable is passed
                  to the dereferenced function, so the pointer argument is always valid.
  \COUNTERMEASURE \R [CM_DEM_R_CLEAR_EVENT_ALLOWED_INDEX]
                  \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_CLEAR_EVENT_ALLOWED_FPTR]

\ID SBSW_DEM_INITMONITORFOREVENT_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_INIT_MONITOR_FOR_EVENT_INDEX]
                  \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_INIT_MONITOR_FOR_EVENT_FPTR]

\ID SBSW_DEM_INITMONITORFORFUNCTION_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_INIT_MONITOR_FOR_FUNCTION_FPTR]

\ID SBSW_DEM_GLOBALCBKDTCSTATUS_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_GLOBAL_CBK_DTC_STATUS_FPTR]

\ID SBSW_DEM_EVENTCBKSTATUS_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_EVENT_CBK_STATUS_FPTR]

\ID SBSW_DEM_EVENTCBKDATA_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_EVENT_CBK_DATA_FPTR]

\ID SBSW_DEM_EVENTCBKGETFDC_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced. The dereferenced function expects a valid
                  pointer argument and does not store the passed pointer. A pointer to a local stack variable is passed
                  to the dereferenced function, so the pointer argument is always valid.
  \COUNTERMEASURE \R [CM_DEM_R_EVENT_CALLBACK_GET_FDC_INDEX]
                  \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_EVENT_CALLBACK_GET_FDC_FPTR]

\ID SBSW_DEM_GLOBALCBKEVENTSTATUS_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_GLOBAL_CBK_EVENT_STATUS_FPTR]

\ID SBSW_DEM_GLOBALCBKEVENTDATA_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_GLOBAL_CBK_EVENT_DATA_FPTR]

\ID SBSW_DEM_GLOBALCBKCONTROLDTCSETTING_FPTR
  \DESCRIPTION    In a function, a configured function pointer is dereferenced.
  \COUNTERMEASURE \R [CM_DEM_R_OPTIONAL_CALLBACK]
                  \S [CM_DEM_S_GLOBAL_CBK_CONTROL_DTC_SETTING_FPTR]

\ID SBSW_DEM_PRESTORED_SNAPSHOT
  \DESCRIPTION    In a function, the snapshot buffer of a prestored entry is passed into a function writing to the buffer.
                  The call includes the buffer size.
  \COUNTERMEASURE \M [CM_DEM_M_SIZEOF_PRESTORED_SNAPSHOT]

\ID SBSW_DEM_DCM_FILTERRECORD_ITERATOR_POINTER
  \DESCRIPTION    The iterator pattern works like this:
                  The functions Dem_Cfg_<X>IterInit, Dem_Cfg_<X>IterExists, Dem_Cfg_<X>IterNext, Dem_Cfg_<X>IterGet
                  receive a pointer to an iterator variable Dem_Cfg_<X>IterType.
                  The Dem_Cfg_<X>IterInit initializes the iterator variable, so it is valid to be used by the other three functions.
                  Those functions expect a reference to a valid iterator variable. The iterator variable is still valid
                  when those functions return.
                  Not all call paths initialize the iterator.
  \COUNTERMEASURE \N The iterator in this case is a global variable, as such the iterator pointer is always valid.
                  No other function accesses the same global variable (it could be function scope static but this is
                  not allowed due to coding guidelines).
                  As such it is not modified outside the function and it can be assumed that the iterator state remains valid in
                  between function calls.
                  Missing initialization cannot cause memory corruption.

SBSW_JUSTIFICATION_END */
/* ********************************************************************************************************************
 Silent BSW Countermeasures
 ----------------------------------------------------------------------------------------------------------------------
\CM CM_DEM_M_SIZEOF_ADMINDATA_CYCLECOUNTER
  Verify Dem_Cfg_AdminData.CycleCounter[] is defined for each index in range [0..DEM_CFG_GLOBAL_CYCLE_COUNT[ .

\CM CM_DEM_M_SIZEOF_STATUSDATA_EVENTSTATUS
  Verify Dem_Cfg_StatusData.EventStatus[] is defined for each index in the event table.

\CM CM_DEM_M_SIZEOF_STATUSDATA_TRIPCOUNT
  Verify Dem_Cfg_StatusData.TripCount[] is defined for each index in the event table.

\CM CM_DEM_M_SIZEOF_EVENTAVAILABLEDATA
  Verify Dem_Cfg_EventAvailableData[] is defined for each index in range [0..ceil(size of event table / 8)[ .

\CM CM_DEM_M_SIZEOF_DEBOUNCEDATA
  Verify Dem_Cfg_DebounceData[] is defined for each index in range [0..DEM_CFG_GLOBAL_DEBOUNCE_STORAGE_EVENT_COUNT[ .

\CM CM_DEM_M_SIZEOF_PRESTORAGE
  Verify Dem_Cfg_Prestorage[] is defined for each index in range [0..DEM_CFG_GLOBAL_PRESTORED_FF_SIZE] .

\CM CM_DEM_M_SIZEOF_PRESTORAGEINDEX
  Verify Dem_Cfg_PrestorageIndex[] is defined for each index in range [0..DEM_G_GLOBAL_PRESTORED_EVENT_COUNT[ .

\CM CM_DEM_M_SIZEOF_PRIMARYCHRONOLOGY
  Verify Dem_Cfg_PrimaryChronology[] is defined for each index in range [0..DEM_CFG_GLOBAL_PRIMARY_SIZE[ .

\CM CM_DEM_M_SIZEOF_SECONDARYCHRONOLOGY
  Verify Dem_Cfg_SecondaryChronology[] is defined for each index in range [0..DEM_CFG_GLOBAL_SECONDARY_SIZE[ .

\CM CM_DEM_M_SIZEOF_TIMESERIES_CHRONOLOGY
  Verify Dem_Cfg_TimeSeriesChronology[] is defined for each index in range [0..DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE[ .

\CM CM_DEM_M_SIZEOF_INDICATORCONTINUOUS
  Verify Dem_Cfg_IndicatorContinuous[] is defined for each index in range [0..DEM_CFG_GLOBAL_INDICATOR_COUNT[ .
  Verify Dem_Cfg_IndicatorContinuous[][] is defined for each index in range [0..max(1, DEM_G_MAX_NUMBER_J1939_NODES)[ .

\CM CM_DEM_M_SIZEOF_INDICATORBLINKING
  Verify Dem_Cfg_IndicatorBlinking[] is defined for each index in range [0..DEM_CFG_GLOBAL_INDICATOR_COUNT[ .
  Verify Dem_Cfg_IndicatorBlinking[][] is defined for each index in range [0..max(1, DEM_G_MAX_NUMBER_J1939_NODES)[ .

\CM CM_DEM_M_SIZEOF_MEMORYSTATUS
  Verify Dem_Cfg_MemoryStatus[] is defined for each index in range [0..DEM_CFG_GLOBAL_NV_BLOCK_COUNT[ .

\CM CM_DEM_M_SIZEOF_MEMORYCOMMITNUMBER
  Verify Dem_Cfg_MemoryCommitNumber[] is defined for each index in range [0..DEM_CFG_GLOBAL_NV_BLOCK_COUNT[ .

\CM CM_DEM_M_SIZEOF_MEMORYDATAPTR
  Verify Dem_Cfg_MemoryDataPtr[] is defined for each index in range [0..DEM_CFG_GLOBAL_NV_BLOCK_COUNT[ .

\CM CM_DEM_M_MEMORYINDEX_LIMITS
  Verify DEM_CFG_MEMORY_PRIMARY_INDEX + DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE <= DEM_CFG_GLOBAL_NV_BLOCK_COUNT,
  with DEM_CFG_GLOBAL_PRIMARY_SIZE > 0.

\CM CM_DEM_M_MEMORYINDEX_TYPE
  [SMI-2199] Verify that for each index in [DEM_CFG_MEMORY_PRIMARY_INDEX .. DEM_CFG_MEMORY_PRIMARY_INDEX + DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE[
  there is a memory entry pointer (Dem_Cfg_PrimaryEntry_XX / Dem_Cfg_SecondaryEntry_XX) configured in Dem_Cfg_MemoryDataPtr[index] .
  Reason for SMI: MSSV cannot evaluate function like macros - needed to get the type of the initializer

\CM CM_DEM_M_SIZEOF_MISSINGTIMESERIESNORMALRATE
  Verify Dem_Cfg_MissingTimeSeriesNormalRate[] is defined for each index in range [0..DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE[ .

\CM CM_DEM_M_SIZEOF_MISSINGTIMESERIESFASTRATE
  Verify Dem_Cfg_MissingTimeSeriesFastRate[] is defined for each index in range [0..DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE[ .

\CM CM_DEM_M_TIMESERIESINDEX_LIMITS
  Verify DEM_CFG_MEMORY_TIME_SERIES_INDEX + DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE <= DEM_CFG_GLOBAL_NV_BLOCK_COUNT, with
  DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE > 0.

\CM CM_DEM_M_TIMESERIESINDEX_TYPE
  [SMI-2200] Verify that for each index in [DEM_CFG_MEMORY_TIME_SERIES_INDEX .. DEM_CFG_MEMORY_TIME_SERIES_INDEX + DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE[
  there is a timeseries entry pointer (Dem_Cfg_TimeSeriesEntry_XX) configured in Dem_Cfg_MemoryDataPtr[index] .
  Reason for SMI: MSSV cannot evaluate function like macros - needed to get the type of the initializer

\CM CM_DEM_M_SIZEOF_EVENTQUEUE
  Verify Dem_Cfg_EventQueue[] is defined for each index in range [0..DEM_CFG_BSW_ERROR_BUFFER_SIZE[ .

\CM CM_DEM_M_SIZEOF_COMMIT_BUFFER
  [SMI-2201] Verify that Dem_Cfg_CommitBuffer is as large or larger than all entries in Dem_Cfg_MemoryDataSize.
  Reason for SMI: MSSV cannot evaluate sizeof(struct/union)

\CM CM_DEM_M_SIZEOF_PRESTORED_SNAPSHOT
  Verify that Dem_Cfg_PrestorageEntryType.SnapshotData[] has at least DEM_CFG_MAX_SIZE_SNAPSHOT elements.

\CM CM_DEM_M_SIZEOF_MEMORYENTRY_EXTENDEDDATA
  Verify that Dem_Cfg_PrimaryEntryType.ExtendedData[] is valid for values in range [0..DEM_CFG_MAX_NUM_EXT_RECORDS[ .
  Verify that Dem_Cfg_PrimaryEntryType.ExtendedData[][] has at least DEM_CFG_MAX_SIZE_EXT_RECORD elements .

\CM CM_DEM_M_SIZEOF_MEMORYENTRY_SNAPSHOTDATA
  Verify that Dem_Cfg_PrimaryEntryType.SnapshotData[] is valid for values in range [0..DEM_CFG_MAX_NUM_SNAPSHOTS[ .
  Verify that Dem_Cfg_PrimaryEntryType.SnapshotData[][] has at least DEM_CFG_MAX_SIZE_SNAPSHOT elements.

\CM CM_DEM_M_SIZEOF_NORMAL_RATE_RINGBUFFER
  Verify that Dem_Cfg_RingBufferNormalRateType.Buffer[] is valid for indices in range [0..max(1, DEM_CFG_TIMESERIES_NORMAL_PAST_SAMPLES)[ .
  Verify that Dem_Cfg_RingBufferNormalRateType.Buffer[][] is valid for indices in range [0..DEM_CFG_TIMESERIES_NORMAL_BUFFER_SIZE[ .

\CM CM_DEM_M_SIZEOF_FAST_RATE_RINGBUFFER
  Verify that Dem_Cfg_RingBufferFastRateType.Buffer[] is valid for indices in range [0..max(1, DEM_CFG_TIMESERIES_FAST_PAST_SAMPLES)[ .
  Verify that Dem_Cfg_RingBufferFastRateType.Buffer[][] is valid for indices in range [0..DEM_CFG_TIMESERIES_FAST_BUFFER_SIZE[ .

\CM CM_DEM_M_SIZEOF_SERIESENTRY_NORMAL_SNAPSHOTDATA
  Verify that Dem_Cfg_TimeSeriesEntryType.SnapshotData_NormalRate[] is valid for values in range [0..(DEM_CFG_TIMESERIES_NORMAL_FUTURE_SAMPLES + DEM_CFG_TIMESERIES_NORMAL_PAST_SAMPLES)[ .
  Verify that Dem_Cfg_TimeSeriesEntryType.SnapshotData_NormalRate[][] has at least DEM_CFG_MAX_SIZE_SNAPSHOT elements.

\CM CM_DEM_M_SIZEOF_SERIESENTRY_FAST_SNAPSHOTDATA
  Verify that Dem_Cfg_TimeSeriesEntryType.SnapshotData_FastRate[] is valid for values in range [0..(DEM_CFG_TIMESERIES_FAST_FUTURE_SAMPLES + DEM_CFG_TIMESERIES_FAST_PAST_SAMPLES)[ .
  Verify that Dem_Cfg_TimeSeriesEntryType.SnapshotData_FastRate[][] has at least DEM_CFG_MAX_SIZE_SNAPSHOT elements.

\CM CM_DEM_R_DEBOUNCEINFO_INIT
  Dem_Debounce_DebounceInfoInit will always initialize the function pointer table with valid function pointers even when
  the passed event index is not a handle to an event, or the passed event does not have a valid debounce algorithm
  configured.

\CM CM_DEM_R_TIMESERIES_GET_ENTRY
  Dem_Mem_TimeSeriesGetEntry will always return a valid time series entry even when the passed memory index is not a handle to a time series entry.

\CM CM_DEM_R_OPTIONAL_CALLBACK
  Optional Callbacks can be NULL_PTR, so the code must explicitly verify that the function called is not NULL_PTR.

\CM CM_DEM_R_CLEARDTCTEST_ITERATOR
  As long as the iterator is initialized Dem_Dcm_ClearDtcTestIterGet will always return a function pointer of the correct type.

\CM CM_DEM_R_CHECK_NVBLOCKID
  Before passing an NV block ID to the NvM, verify that the Dem memory index is valid. This is necessary for SMI-22 and SMI-23.

\CM CM_DEM_R_SIZEOF_DATAELEMENT_TABLE
  Verify that the data element index used to access Dem_Cfg_DataElementTable is valid.

\CM CM_DEM_R_CHECK_DATAELEMENT_TYPE
  Verify that the function pointer called is configured to have the expected data element type.

\CM CM_DEM_R_MEMORY_GET_ERECDATAPTR
  Dem_Mem_EntryGetERecDataPtr will always return a valid pointer even when the passed record index is not valid.

\CM CM_DEM_R_MEMORY_GET_SRECDATAPTR
  Dem_Mem_EntryGetSRecDataPtr will always return a valid pointer even when the passed record index is not valid.

\CM CM_DEM_R_RINGBUFFER_NORMALRATEPTR
  Dem_Mem_RingBufferNormalRatePtr will always return a valid pointer even when the passed buffer index is not valid.

\CM CM_DEM_R_RINGBUFFER_FASTRATEPTR
  Dem_Mem_RingBufferFastRatePtr will always return a valid pointer even when the passed record index is not valid.

\CM CM_DEM_R_TIMESERIES_GET_NORMALDATAPTR
  Dem_Mem_TimeSeriesEntryGetNormalDataPtr will always return a valid pointer even when the passed series index is not valid.

\CM CM_DEM_R_TIMESERIES_GET_FASTDATAPTR
  Dem_Mem_TimeSeriesEntryGetFastDataPtr will always return a valid pointer even when the passed series index is not valid.

\CM CM_DEM_R_CHECK_REMAINING_BUFFER
  Before writing data to a buffer, check that the buffer is large enough for the data written to it.

\CM CM_DEM_R_DTCFILTER_FPTR
  Before calling the function pointer returned by Dem_FilterData_GetFilterFunction() verify that it is one of the expected function pointers.

\CM CM_DEM_R_CLEAR_EVENT_ALLOWED_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_CallbackClearEventAllowed.

\CM CM_DEM_R_INIT_MONITOR_FOR_EVENT_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_InitMonitorForEvent.

\CM CM_DEM_R_INIT_MONITOR_FOR_FUNCTION_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_InitMonitorsForFunc.

\CM CM_DEM_R_EVENT_CBK_STATUS_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_EventStatusChanged.

\CM CM_DEM_R_DTC_CBK_STATUS_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_CallbackDtcStatusChanged.

\CM CM_DEM_R_EVENT_CALLBACK_GET_FDC_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_CallbackGetFdc.

\CM CM_DEM_R_MEMORYDATA_INDEX
  Verify that the table index is in range before accessing Dem_Cfg_MemoryDataPtr and Dem_Cfg_MemoryDataSize.

\CM CM_DEM_R_DEM_CFG_ADMINDATA_CYCLECOUNTER_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_AdminData.CycleCounter.

\CM CM_DEM_R_DEM_CFG_STATUSDATA_EVENTSTATUS_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_StatusData.EventStatus.

\CM CM_DEM_R_DEM_CFG_STATUSDATA_TRIPCOUNT_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_StatusData.TripCount.

\CM CM_DEM_R_DEBOUNCEDATA_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_DebounceData.

\CM CM_DEM_R_AVAILABLEDATA_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_EventAvailableData.

\CM CM_DEM_R_PRESTORAGE_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_PrestorageIndex.

\CM CM_DEM_R_MEMORYCHRONOLOGY_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_PrimaryChronology.
  Verify that the array index is in range before writing to Dem_Cfg_SecondaryChronology.
  Verify that the array index is in range before writing to Dem_Cfg_TimeSeriesChronology.

\CM CM_DEM_R_INDICATORCONTINUOUS_INDEX_CHECK
  Verify that all array indices are in range before writing to Dem_Cfg_IndicatorContinuous[][] .

\CM CM_DEM_R_INDICATORBLINKING_INDEX_CHECK
  Verify that all array indices are in range before writing to Dem_Cfg_IndicatorBlinking[][] .

\CM CM_DEM_R_MEMORYSTATUS_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_MemoryStatus.

\CM CM_DEM_R_EVENTQUEUE_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_EventQueue.

\CM CM_DEM_R_MISSINGTIMESERIESNORMALRATE_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_MissingTimeSeriesNormalRate.

\CM CM_DEM_R_MISSINGTIMESERIESFASTRATE_INDEX_CHECK
  Verify that the array index is in range before writing to Dem_Cfg_MissingTimeSeriesFastRate.

\CM CM_DEM_S_CLEAR_EVENT_ALLOWED_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_CallbackClearEventAllowed are compatible to
  Dem_ClearEventAllowedFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_INIT_MONITOR_FOR_EVENT_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_InitMonitorForEvent are compatible to
  Dem_InitMonitorForEventFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_INIT_MONITOR_FOR_FUNCTION_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_InitMonitorsForFunc are compatible to
  Dem_InitMonitorForFuncFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_GLOBAL_CBK_DTC_STATUS_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_CallbackDtcStatusChanged are compatible to
  Dem_DtcStatusChangedFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_EVENT_CBK_STATUS_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_EventStatusChanged are compatible to
  Dem_EventStatusChangedFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_EVENT_CBK_DATA_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_EventDataChanged are compatible to
  Dem_EventDataChangedFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_EVENT_CALLBACK_GET_FDC_FPTR
  [SMI-2055] Verify that all function pointers stored in table Dem_Cfg_CallbackGetFdc are compatible to
  Dem_GetFDCFPtrType. The value NULL_PTR is valid for this callback type.

\CM CM_DEM_S_GLOBAL_CBK_EVENT_STATUS_FPTR
  [SMI-2207] Verify that the function pointer defined as macro DEM_CFG_GLOBALCBKSTATUS_FUNC is compatible to
  Dem_GlobalStatusChangedFPtrType. The value NULL_PTR is valid for this callback.

\CM CM_DEM_S_GLOBAL_CBK_EVENT_DATA_FPTR
  [SMI-2207] Verify that the function pointer defined as macro DEM_CFG_GLOBALCBKDATA_FUNC is compatible to
  Dem_GlobalDataChangedFPtrType. The value NULL_PTR is valid for this callback.

\CM CM_DEM_S_GLOBAL_CBK_CONTROL_DTC_SETTING_FPTR
  [SMI-2207] Verify that the function pointer defined as macro DEM_CFG_GLOBALCBKCONTROLDTCSETTING_FUNC is compatible to
  Dem_ControlDtcSettingChangedFPtrType. The value NULL_PTR is valid for this callback.

\CM CM_DEM_S_DATA_CALLBACK_FPTR
  [SMI-2194] The user of MICROSAR Safe shall verify for all function pointers stored in table Dem_Cfg_DataElementTable:
  - If ElementKind is DEM_CFG_DATA_FROM_CBK_STORED, verify that the callback function ReadDataFunc is compatible to
    Dem_ReadDataStandardFPtrType.
  - If ElementKind is DEM_CFG_DATA_FROM_CBK_CURRENT, verify that the callback function ReadDataFunc is compatible to
    Dem_ReadDataStandardFPtrType.
  - If ElementKind is DEM_CFG_DATA_FROM_CBK_STORED_WITH_EVENTID, verify that the callback function ReadDataFunc is
    compatible to Dem_ReadDataExtendedFPtrType.
  - If ElementKind is DEM_CFG_DATA_FROM_CBK_CURRENT_WITH_EVENTID, verify that the callback function ReadDataFunc is
    compatible to Dem_ReadDataExtendedFPtrType.
  - Verify that all other callback functions ReadDataFunc in the table are set to NULL_PTR.
  The function pointer types are defined in Dem_Types.h. The table is generated into Dem_Lcfg.c.

\CM CM_DEM_S_CALL_DESTINATIONBUFFER
  [SMI-2195] The user of MICROSAR Safe shall verify that all function callbacks configured in table
  Dem_Cfg_DataElementTable write at most ElementSize bytes.
  E.g. for a line {  DEM_CFG_DATA_FROM_CBK_STORED, 4U, (Dem_ReadDataFPtrType)Rte_Call_CBReadData_DemDataElementClass_ReadData }
  verify that the application runnable triggered by the Rte when the Dem invokes operation 'ReadData' on PortPrototype
  'DemDataElementClass' will at most write 4 bytes.
  The table is generated into Dem_Lcfg.c.

\CM CM_DEM_S_CHECK_NVBLOCKID
  [SMI-2196] The user of MICROSAR Safe shall verify that the NV Block IDs listed in table Dem_Cfg_MemoryBlockId are
  intended to be used exclusively by Dem. This is required for SMI-22.
  The table is generated into Dem_Lcfg.c.

\CM CM_DEM_S_CHECK_NVBLOCK_LENGTH
  [SMI-2197] The user of MICROSAR Safe shall verify that the configured NvM block size of the NV blocks referenced
  in table Dem_Cfg_MemoryBlockId is equal to the data size in table Dem_Cfg_MemoryDataSize for the same index.
  The user of MICROSAR Safe shall verify that the NV block is also configured to use the RAM buffer referenced in
  Dem_Cfg_MemoryDataPtr for the same index. This is required for SMI-23.
  E.g. Verify that the NvM block descriptor referenced in Dem_Cfg_MemoryBlockId[1] is configured with data length
  Dem_Cfg_MemoryDataSize[1] and RAM buffer Dem_Cfg_MemoryDataPtr[1].
  The tables Dem_Cfg_MemoryBlockId, Dem_Cfg_MemoryDataSize and Dem_Cfg_MemoryDataPtr are generated into Dem_Lcfg.c.
  Refer to the NvM for the location of the tables generated by the NvM to verify the correct configuration.

\CM CM_DEM_S_SIZE_OF_RECORD_DATA_BUFFER
  [SMI-2198] The user of MICROSAR Safe shall verify that when calling Dem_GetEventExtendedDataRecord or
  Dem_GetEventFreezeFrameData, either directly or by RTE operation GetExtendedDataRecord or GetFreezeFrameData of port
  interfaces DiagnosticInfo, GeneralDiagnosticInfo or DiagnosticMonitor:
  - The DestBuffer parameter shall point to a memory area which can receive at least sizeof(Dem_MaxDataValueSize) bytes.
  If an RTE is used, the type Dem_MaxDataValueSize is defined in Rte_Type.h.
  If no RTE is used, the value of DEM_CFG_SIZEOF_MAX_DATA_VALUE_TYPE corresponds to the expected buffer size.
  This macro is defined in Dem_Lcfg.h.

*/

/*!
 * \}
 */

/* ********************************************************************************************************************
 *  END OF FILE: DEM.C
 *********************************************************************************************************************/
