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
 *          File:  Rte_Type.h
 *        Config:  C:/Nimmy/Autocode/BMW/BMW_Production/SF068/SF068A_Effort_Impl/tools/Component.dpa
 *     SW-C Type:  Effort
 *  Generated at:  Tue May 22 12:00:33 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
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

# define Rte_TypeDef_s15p0
typedef sint16 s15p0;

# define Rte_TypeDef_u15p1
typedef uint16 u15p1;

# define Rte_TypeDef_u1p15
typedef uint16 u1p15;

# define Rte_TypeDef_u4p12
typedef uint16 u4p12;

# define Rte_TypeDef_u9p7
typedef uint16 u9p7;

# define Rte_TypeDef_Ary1D_s15p0_10
typedef s15p0 Ary1D_s15p0_10[10];

# define Rte_TypeDef_Ary1D_u15p1_24
typedef u15p1 Ary1D_u15p1_24[24];

# define Rte_TypeDef_Ary1D_u1p15_10
typedef u1p15 Ary1D_u1p15_10[10];

# define Rte_TypeDef_Ary1D_u4p12_24
typedef u4p12 Ary1D_u4p12_24[24];

# define Rte_TypeDef_Ary1D_u9p7_10
typedef u9p7 Ary1D_u9p7_10[10];

# define Rte_TypeDef_Ary2D_u15p1_10_24
typedef Ary1D_u15p1_24 Ary2D_u15p1_10_24[10];

# define Rte_TypeDef_Ary2D_u4p12_10_24
typedef Ary1D_u4p12_24 Ary2D_u4p12_10_24[10];

#endif /* _RTE_TYPE_H */
