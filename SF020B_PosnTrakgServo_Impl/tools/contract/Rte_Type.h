/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Type.h
 *     SW-C Type:  PosnTrakgServo
 *  Generated at:  Wed Jan 25 15:10:41 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_s4p11
typedef sint16 s4p11;

# define Rte_TypeDef_s8p7
typedef sint16 s8p7;

# define Rte_TypeDef_u11p5
typedef uint16 u11p5;

# define Rte_TypeDef_u12p4
typedef uint16 u12p4;

# define Rte_TypeDef_u15p1
typedef uint16 u15p1;

# define Rte_TypeDef_u2p14
typedef uint16 u2p14;

# define Rte_TypeDef_u8p8
typedef uint16 u8p8;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_s4p11_12
typedef s4p11 Ary1D_s4p11_12[12];

# define Rte_TypeDef_Ary1D_s8p7_12
typedef s8p7 Ary1D_s8p7_12[12];

# define Rte_TypeDef_Ary1D_u11p5_12
typedef u11p5 Ary1D_u11p5_12[12];

# define Rte_TypeDef_Ary1D_u12p4_12
typedef u12p4 Ary1D_u12p4_12[12];

# define Rte_TypeDef_Ary1D_u15p1_12
typedef u15p1 Ary1D_u15p1_12[12];

# define Rte_TypeDef_Ary1D_u2p14_10
typedef u2p14 Ary1D_u2p14_10[10];

# define Rte_TypeDef_Ary1D_u2p14_12
typedef u2p14 Ary1D_u2p14_12[12];

# define Rte_TypeDef_Ary1D_u8p8_10
typedef u8p8 Ary1D_u8p8_10[10];

# define Rte_TypeDef_Ary1D_u8p8_12
typedef u8p8 Ary1D_u8p8_12[12];

# define Rte_TypeDef_Ary1D_u9p7_12
typedef u9p7 Ary1D_u9p7_12[12];


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1485379696
#    error "The magic number of the generated file <C:/component/SF020B_PosnTrakgServo_Impl/tools/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1485379696
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
