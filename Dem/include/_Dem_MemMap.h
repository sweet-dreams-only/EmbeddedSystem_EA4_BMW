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
 *  Template file for Dem memory map
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
 *  1.0.0     2017-07-05  visavi  -             Initial version
 *********************************************************************************************************************/

 /* PRQA S 0883 */  /* MD_DEM_1915 */
#if defined (DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED                                                                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED                                                                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* Sample Preprocessor directive for a newly configured OS-Application instance <OS_APPLICATION_NAME>

  #if defined (DEM_START_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED)
  # undef DEM_START_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED                                                             
  # define START_SEC_VAR_NOINIT_UNSPECIFIED
  #endif
  
  #if defined (DEM_STOP_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED)
  # undef DEM_STOP_SEC_<OS_APPLICATION_NAME>_VAR_NOINIT_UNSPECIFIED                                                              
  # define STOP_SEC_VAR
  #endif 
 
 */

