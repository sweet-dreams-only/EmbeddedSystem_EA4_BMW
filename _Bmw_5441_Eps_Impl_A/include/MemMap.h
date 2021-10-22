/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2016 by Vctr Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vctr Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vctr Informatik GmbH
 *  Heike Honert                  Ht            Vctr Informatik GmbH
 *  Eugen Stripling               Seu           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */

# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (1u)
# define MEMMAP_SW_MINOR_VERSION     (9u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION 
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION 
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION 

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */


#include "Rte_MemMap.h"
#include "WdgM_OsMemMap.h" /*visbim*/



/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COMM_START_SEC_CODE
  #undef COMM_START_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_CODE
  #undef COMM_STOP_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COMM_START_SEC_CONST_8BIT
# undef COMM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef COMM_STOP_SEC_CONST_8BIT
# undef COMM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef COMM_START_SEC_CONST_16BIT
# undef COMM_START_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef COMM_STOP_SEC_CONST_16BIT
# undef COMM_STOP_SEC_CONST_16BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_UNSPECIFIED
# undef COMM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_CONST_UNSPECIFIED
# undef COMM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* CONST PBCFG sections */

#ifdef COMM_START_SEC_PBCFG
# undef COMM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef COMM_STOP_SEC_PBCFG
# undef COMM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef COMM_START_SEC_VAR_NOINIT_8BIT
# undef COMM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_8BIT
# undef COMM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_16BIT
# undef COMM_START_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_16BIT
# undef COMM_STOP_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR PBCFG sections */

#ifdef COMM_START_SEC_VAR_PBCFG
# undef COMM_START_SEC_VAR_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                         /* mapped to default var pbcfg section */
#endif
#ifdef COMM_STOP_SEC_VAR_PBCFG
# undef COMM_STOP_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR ZERO INIT sections */

#ifdef COMM_START_SEC_VAR_ZERO_INIT_8BIT
# undef COMM_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef COMM_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NVRAM sections */

#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FrSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRSM_START_SEC_CODE
  #undef FRSM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRSM_STOP_SEC_CODE
  #undef FRSM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */



#ifdef FRSM_START_SEC_CONST_32BIT
# undef FRSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FRSM_STOP_SEC_CONST_32BIT
# undef FRSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef FRSM_START_SEC_CONST_UNSPECIFIED
# undef FRSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_CONST_UNSPECIFIED
# undef FRSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#ifdef FRSM_START_SEC_PBCFG_ROOT
# undef FRSM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG_ROOT
# undef FRSM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/* Tables for postbuild data */
#ifdef FRSM_START_SEC_PBCFG
# undef FRSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG
# undef FRSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef FRSM_START_SEC_VAR_NOINIT_8BIT
# undef FRSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FRSM_START_SEC_VAR_NOINIT_16BIT
# undef FRSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif


#ifdef FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/
/* Copy the memory mapping defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

/*******  CODE sections **********************************************************************************************/

#ifdef _CDD_START_SEC_CODE
# undef _CDD_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef _CDD_STOP_SEC_CODE
# undef _CDD_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/* Add additional memory mapping defines for each of you configured CDDs here. */

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(XCP_START_SEC_CODE)
# undef XCP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(XCP_STOP_SEC_CODE)
# undef XCP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(XCP_START_SEC_CONST_8BIT)
# undef XCP_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(XCP_STOP_SEC_CONST_8BIT)
# undef XCP_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(XCP_START_SEC_CONST_16BIT)
# undef XCP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(XCP_STOP_SEC_CONST_16BIT)
# undef XCP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_32BIT)
# undef XCP_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(XCP_STOP_SEC_CONST_32BIT)
# undef XCP_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_UNSPECIFIED)
# undef XCP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_CONST_UNSPECIFIED)
# undef XCP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(XCP_START_SEC_PBCFG)
# undef XCP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(XCP_STOP_SEC_PBCFG)
# undef XCP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(XCP_START_SEC_VAR_INIT_8BIT)
# undef XCP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(XCP_START_SEC_VAR_INIT_16BIT)
# undef XCP_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_32BIT)
# undef XCP_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(XCP_START_SEC_VAR_PBCFG)
# undef XCP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(XCP_STOP_SEC_VAR_PBCFG)
# undef XCP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOCACHE INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR Safe sections */
#if defined (XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined (XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRXCP_START_SEC_CODE 
    #undef FRXCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRXCP_STOP_SEC_CODE 
    #undef FRXCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_16BIT 
    #undef FRXCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_16BIT 
    #undef FRXCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_8BIT 
    #undef FRXCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_8BIT 
    #undef FRXCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_PBCFG
    #undef FRXCP_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef FRXCP_STOP_SEC_PBCFG
    #undef FRXCP_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_PBCFG
    #undef FRXCP_START_SEC_VAR_PBCFG
    #define START_SEC_VAR_PBCFG
#endif

#ifdef FRXCP_STOP_SEC_VAR_PBCFG
    #undef FRXCP_STOP_SEC_VAR_PBCFG
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_INIT_8BIT 
    #undef FRXCP_START_SEC_VAR_INIT_8BIT 
    #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef FRXCP_STOP_SEC_VAR_INIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_INIT_8BIT 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/

/* ==== Start sections mapping ==== */
#ifdef DCM_START_SEC_CONST_8
# undef DCM_START_SEC_CONST_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                        /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_16
# undef DCM_START_SEC_CONST_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_32
# undef DCM_START_SEC_CONST_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_UNSPECIFIED
# undef DCM_START_SEC_CONST_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_8
# undef DCM_START_SEC_CALIB_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                        /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_16
# undef DCM_START_SEC_CALIB_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_32
# undef DCM_START_SEC_CALIB_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_UNSPECIFIED
# undef DCM_START_SEC_CALIB_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_PBCFG
# undef DCM_START_SEC_PBCFG                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_VAR_PBCFG
# undef DCM_START_SEC_VAR_PBCFG                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                                         /*mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_INIT_8
# undef DCM_START_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                     /*mapped to default initialized var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_8
# undef DCM_START_SEC_VAR_NO_INIT_8                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT                                   /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_16
# undef DCM_START_SEC_VAR_NO_INIT_16                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_32
# undef DCM_START_SEC_VAR_NO_INIT_32
# define START_SEC_VAR_NOINIT_32BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_INIT_32
# undef DCM_START_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT                                    /*mapped to default initialized var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED                            /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_CODE
# undef DCM_START_SEC_CODE                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

#ifdef DCM_START_SEC_APPL_CODE
# undef DCM_START_SEC_APPL_CODE                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

#ifdef DCM_START_SEC_CALLOUT_CODE
# undef DCM_START_SEC_CALLOUT_CODE                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

/* ==== Stop sections mapping ==== */
#ifdef DCM_STOP_SEC_CONST_8
# undef DCM_STOP_SEC_CONST_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_16
# undef DCM_STOP_SEC_CONST_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_32
# undef DCM_STOP_SEC_CONST_32
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
# undef DCM_STOP_SEC_CONST_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_8
# undef DCM_STOP_SEC_CALIB_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_16
# undef DCM_STOP_SEC_CALIB_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_32
# undef DCM_STOP_SEC_CALIB_32
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_UNSPECIFIED
# undef DCM_STOP_SEC_CALIB_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_PBCFG
# undef DCM_STOP_SEC_PBCFG                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_8
# undef DCM_STOP_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default initialized var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_8
# undef DCM_STOP_SEC_VAR_NO_INIT_8                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_16
# undef DCM_STOP_SEC_VAR_NO_INIT_16                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_32
# undef DCM_STOP_SEC_VAR_NO_INIT_32                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_32
# undef DCM_STOP_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default initialized var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_PBCFG
# undef DCM_STOP_SEC_VAR_PBCFG                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section */
#endif

#ifdef DCM_STOP_SEC_CODE
# undef DCM_STOP_SEC_CODE                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

#ifdef DCM_STOP_SEC_APPL_CODE
# undef DCM_STOP_SEC_APPL_CODE                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

#ifdef DCM_STOP_SEC_CALLOUT_CODE
# undef DCM_STOP_SEC_CALLOUT_CODE                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

/* ==== Start sections mapping ==== */
#ifdef DCM_START_SEC_CONST_8
# undef DCM_START_SEC_CONST_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8                                           /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_16
# undef DCM_START_SEC_CONST_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16                                          /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_32
# undef DCM_START_SEC_CONST_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32                                          /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_UNSPECIFIED
# undef DCM_START_SEC_CONST_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_8
# undef DCM_START_SEC_CALIB_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8                                           /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_16
# undef DCM_START_SEC_CALIB_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16                                          /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_32
# undef DCM_START_SEC_CALIB_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32                                          /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_UNSPECIFIED
# undef DCM_START_SEC_CALIB_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_PBCFG
# undef DCM_START_SEC_PBCFG                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                                       /* mapped to default const section */
#endif

#ifdef DCM_START_SEC_VAR_PBCFG
# undef DCM_START_SEC_VAR_PBCFG                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                                         /* mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_INIT_8
# undef DCM_START_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8                                        /* mapped to default initialized var section */
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_8
# undef DCM_START_SEC_VAR_NO_INIT_8                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8                                     /* mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_16
# undef DCM_START_SEC_VAR_NO_INIT_16                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16                                    /* mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_32
# undef DCM_START_SEC_VAR_NO_INIT_32                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_32                                    /* mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_INIT_32
# undef DCM_START_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32                                       /* mapped to default initialized var section */
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED                           /* mapped to default var section */
#endif

#ifdef DCM_START_SEC_CODE
# undef DCM_START_SEC_CODE                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /* mapped to default code section */
#endif

#ifdef DCM_START_SEC_APPL_CODE
# undef DCM_START_SEC_APPL_CODE                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /* mapped to default code section */
#endif

#ifdef DCM_START_SEC_CALLOUT_CODE
# undef DCM_START_SEC_CALLOUT_CODE                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /* mapped to default code section */
#endif

/* ==== Stop sections mapping ==== */
#ifdef DCM_STOP_SEC_CONST_8
# undef DCM_STOP_SEC_CONST_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_16
# undef DCM_STOP_SEC_CONST_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_32
# undef DCM_STOP_SEC_CONST_32
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
# undef DCM_STOP_SEC_CONST_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_8
# undef DCM_STOP_SEC_CALIB_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_16
# undef DCM_STOP_SEC_CALIB_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_32
# undef DCM_STOP_SEC_CALIB_32
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_UNSPECIFIED
# undef DCM_STOP_SEC_CALIB_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_PBCFG
# undef DCM_STOP_SEC_PBCFG                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /* default const section */
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_8
# undef DCM_STOP_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default initialized var section */
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_8
# undef DCM_STOP_SEC_VAR_NO_INIT_8                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default var section */
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_16
# undef DCM_STOP_SEC_VAR_NO_INIT_16                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default var section */
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_32
# undef DCM_STOP_SEC_VAR_NO_INIT_32                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default var section */
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_32
# undef DCM_STOP_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default initialized var section */
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default var section */
#endif

#ifdef DCM_STOP_SEC_VAR_PBCFG
# undef DCM_STOP_SEC_VAR_PBCFG                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /* default var section */
#endif

#ifdef DCM_STOP_SEC_CODE
# undef DCM_STOP_SEC_CODE                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /* default code section */
#endif

#ifdef DCM_STOP_SEC_APPL_CODE
# undef DCM_STOP_SEC_APPL_CODE                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /* default code section */
#endif

#ifdef DCM_STOP_SEC_CALLOUT_CODE
# undef DCM_STOP_SEC_CALLOUT_CODE                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /* default code section */
#endif

/** DEM **********************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS------------------*/
                                                             
                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CODE)
# undef DEM_START_SEC_CODE                                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CALLOUT_CODE)
# undef DEM_START_SEC_CALLOUT_CODE                                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CODE_LIB)
# undef DEM_START_SEC_CODE_LIB                                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
# undef DEM_START_SEC_VAR_NOINIT_8BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
# undef DEM_START_SEC_VAR_NOINIT_16BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_32BIT)
# undef DEM_START_SEC_VAR_NOINIT_32BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
# undef DEM_START_SEC_VAR_NOINIT_8BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
# undef DEM_START_SEC_VAR_NOINIT_16BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_32BIT)
# undef DEM_START_SEC_VAR_NOINIT_32BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_UNCACHED_UNSPECIFIED)
# undef DEM_START_SEC_VAR_UNCACHED_UNSPECIFIED                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT0)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT0                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT1)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT1                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_INIT_8BIT)
# undef DEM_START_SEC_VAR_INIT_8BIT                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_INIT_32BIT)
# undef DEM_START_SEC_VAR_INIT_32BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_START_SEC_VAR_PBCFG)
# undef DEM_START_SEC_VAR_PBCFG                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif


                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_8BIT                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif


#if defined (DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_0_VAR_NOINIT_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_0_VAR_NOINIT_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CONST_8BIT)
# undef DEM_START_SEC_CONST_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_16BIT)
# undef DEM_START_SEC_CONST_16BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
# undef DEM_START_SEC_CONST_32BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif

#if defined (DEM_START_SEC_CONST_8BIT)
# undef DEM_START_SEC_CONST_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_16BIT)
# undef DEM_START_SEC_CONST_16BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
# undef DEM_START_SEC_CONST_32BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
# undef DEM_START_SEC_CONST_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONFIG_DATA_UNSPECIFIED)
# undef DEM_START_SEC_CONFIG_DATA_UNSPECIFIED                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_PBCFG_ROOT)
# undef DEM_START_SEC_PBCFG_ROOT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif

#if defined (DEM_START_SEC_CALIB_UNSPECIFIED)
# undef DEM_START_SEC_CALIB_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CALIB_8BIT)
# undef DEM_START_SEC_CALIB_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif

#if defined (DEM_START_SEC_PBCFG)
# undef DEM_START_SEC_PBCFG                                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif



/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS-------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS-------------------*/

                                                             
                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CODE)
# undef DEM_STOP_SEC_CODE                                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CALLOUT_CODE)
# undef DEM_STOP_SEC_CALLOUT_CODE                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CODE_LIB)
# undef DEM_STOP_SEC_CODE_LIB                                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_32BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_32BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_32BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_32BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_UNCACHED_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_UNCACHED_UNSPECIFIED                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT0)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT0                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT1)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT1                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_INIT_8BIT)
# undef DEM_STOP_SEC_VAR_INIT_8BIT                                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_INIT_32BIT)
# undef DEM_STOP_SEC_VAR_INIT_32BIT                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_STOP_SEC_VAR_PBCFG)
# undef DEM_STOP_SEC_VAR_PBCFG                                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CONST_8BIT)
# undef DEM_STOP_SEC_CONST_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_16BIT)
# undef DEM_STOP_SEC_CONST_16BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
# undef DEM_STOP_SEC_CONST_32BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CONST_8BIT)
# undef DEM_STOP_SEC_CONST_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_16BIT)
# undef DEM_STOP_SEC_CONST_16BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
# undef DEM_STOP_SEC_CONST_32BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
# undef DEM_STOP_SEC_CONST_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG_ROOT)
# undef DEM_STOP_SEC_PBCFG_ROOT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CALIB_UNSPECIFIED)
# undef DEM_STOP_SEC_CALIB_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CALIB_8BIT)
# undef DEM_STOP_SEC_CALIB_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG)
# undef DEM_STOP_SEC_PBCFG                                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS--------------------*/
/** End of DEM ***************************************************************/


/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FR_START_SEC_CODE
# undef FR_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef FR_STOP_SEC_CODE
# undef FR_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


#ifdef FR_START_SEC_CODE_ISR
# undef FR_START_SEC_CODE_ISR
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#ifdef FR_STOP_SEC_CODE_ISR
# undef FR_STOP_SEC_CODE_ISR
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef FR_APPL_START_SEC_CODE
# undef FR_APPL_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef FR_APPL_STOP_SEC_CODE
# undef FR_APPL_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FR_START_SEC_CONST_32BIT
# undef FR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FR_STOP_SEC_CONST_32BIT
# undef FR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_16BIT
# undef FR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FR_STOP_SEC_CONST_16BIT
# undef FR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_8BIT
# undef FR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FR_STOP_SEC_CONST_8BIT
# undef FR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


#ifdef FR_START_SEC_CONST_UNSPECIFIED
# undef FR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_CONST_UNSPECIFIED
# undef FR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef FR_START_SEC_PBCFG_ROOT
# undef FR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG_ROOT
# undef FR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_PBCFG
# undef FR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG
# undef FR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_30_TJA1082_START_SEC_CODE
    #undef FRTRCV_30_TJA1082_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1082_STOP_SEC_CODE 
    #undef FRTRCV_30_TJA1082_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


 #ifdef WD_FBL_TRIGGER_START_SEC_CODE
  #pragma ghs section text=".RAMCODE"
  #undef WD_FBL_TRIGGER_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
  #undef MEMMAP_ERROR
#endif

#ifdef WD_FBL_TRIGGER_STOP_SEC_CODE
  #undef WD_FBL_TRIGGER_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
  #pragma ghs section text=default
  #undef MEMMAP_ERROR
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_INIT_UNSPECIFIED 
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_INIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32
    #undef IOHWAB_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32
    #undef IOHWAB_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_16BIT
# undef PDUR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_16BIT
# undef PDUR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */


/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_16BIT
# undef PDUR_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_32BIT
# undef PDUR_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif


#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

/* Postbuild CFG VAR sections */

#ifdef PDUR_START_SEC_VAR_PBCFG
# undef PDUR_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef PDUR_STOP_SEC_VAR_PBCFG
# undef PDUR_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGIF START
 *********************************************************************************************************************/

#include "WdgIf_MemMap.h"

/*******  CODE sections **********************************************************************************************/

#if defined WDGIF_START_SEC_CODE
# undef WDGIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGIF_STOP_SEC_CODE
# undef WDGIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGIF_START_SEC_CONST_8BIT
# undef WDGIF_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_8BIT
# undef WDGIF_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_16BIT
# undef WDGIF_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_16BIT
# undef WDGIF_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_32BIT
# undef WDGIF_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_32BIT
# undef WDGIF_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_UNSPECIFIED
# undef WDGIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
# undef WDGIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined WDGIF_START_SEC_VAR_INIT_8BIT
# undef WDGIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_8BIT
# undef WDGIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_16BIT
# undef WDGIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_16BIT
# undef WDGIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_32BIT
# undef WDGIF_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_32BIT
# undef WDGIF_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined WDGIF_START_SEC_VAR_NOINIT_8BIT
# undef WDGIF_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_8BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_16BIT
# undef WDGIF_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_16BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_32BIT
# undef WDGIF_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_32BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO_INIT sections */

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  WDGIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# undef CRYIF_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRYIF_STOP_SEC_CODE
# undef CRYIF_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef CRYIF_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */


/* VAR ZERO INIT sections */

#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_30_SMALLSECTOR_START_SEC_CODE
    #undef FEE_30_SMALLSECTOR_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */
#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_UNSPECIFIED
    #define STOP_SEC_VAR
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRIF_START_SEC_CODE
  #undef FRIF_START_SEC_CODE                        /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRIF_STOP_SEC_CODE
  #undef FRIF_STOP_SEC_CODE                         /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FRIF_START_SEC_APPL_CODE
  #undef FRIF_START_SEC_APPL_CODE                   /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default appl code section */
#endif
#ifdef FRIF_STOP_SEC_APPL_CODE
  #undef FRIF_STOP_SEC_APPL_CODE                    /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRIF_START_SEC_CONST_32BIT
# undef FRIF_START_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#ifdef FRIF_STOP_SEC_CONST_32BIT
# undef FRIF_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_CONST_UNSPECIFIED
# undef FRIF_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_CONST_UNSPECIFIED  
# undef FRIF_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef FRIF_START_SEC_PBCFG
# undef FRIF_START_SEC_PBCFG                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG
# undef FRIF_STOP_SEC_PBCFG                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_PBCFG_ROOT
# undef FRIF_START_SEC_PBCFG_ROOT                   /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG_ROOT
# undef FRIF_STOP_SEC_PBCFG_ROOT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#ifdef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

/* PBCFG section for flexible RAM management */

#ifdef FRIF_START_SEC_VAR_PBCFG
# undef FRIF_START_SEC_VAR_PBCFG       /* PRQA S 0841 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef FRIF_STOP_SEC_VAR_PBCFG
# undef FRIF_STOP_SEC_VAR_PBCFG        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/

#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
    #undef MEMIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_8BIT
# undef COM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef COM_STOP_SEC_CONST_8BIT
# undef COM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_16BIT
# undef COM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef COM_STOP_SEC_CONST_16BIT
# undef COM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_32BIT
# undef COM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COM_STOP_SEC_CONST_32BIT
# undef COM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_64BIT
# undef COM_START_SEC_CONST_64BIT
# define START_SEC_CONST_64BIT
#endif
#ifdef COM_STOP_SEC_CONST_64BIT
# undef COM_STOP_SEC_CONST_64BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_VAR_PBCFG
# undef COM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef COM_STOP_SEC_VAR_PBCFG
# undef COM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_ZERO_INIT_8BIT
# undef COM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef COM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef COM_START_SEC_VAR_NOINIT_BOOLEAN
# undef COM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_8BIT
# undef COM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_8BIT
# undef COM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_16BIT
# undef COM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_16BIT
# undef COM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_32BIT
# undef COM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_32BIT
# undef COM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_64BIT
# undef COM_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_64BIT
# undef COM_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IPDUM_START_SEC_CODE
# undef IPDUM_START_SEC_CODE
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef IPDUM_STOP_SEC_CODE
# undef IPDUM_STOP_SEC_CODE
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* Postbuild CFG CONST sections */

#ifdef IPDUM_START_SEC_PBCFG_8BIT
# undef IPDUM_START_SEC_PBCFG_8BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_8BIT
# undef IPDUM_STOP_SEC_PBCFG_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_16BIT
# undef IPDUM_START_SEC_PBCFG_16BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_16BIT
# undef IPDUM_STOP_SEC_PBCFG_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_32BIT
# undef IPDUM_START_SEC_PBCFG_32BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_32BIT
# undef IPDUM_STOP_SEC_PBCFG_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_UNSPECIFIED
# undef IPDUM_START_SEC_PBCFG_UNSPECIFIED
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_UNSPECIFIED
# undef IPDUM_STOP_SEC_PBCFG_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG
# undef IPDUM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG
# undef IPDUM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_VAR_PBCFG
# undef IPDUM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_VAR_PBCFG
# undef IPDUM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_CONST_8BIT
# undef IPDUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_8BIT
# undef IPDUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_16BIT
# undef IPDUM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_16BIT
# undef IPDUM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_32BIT
# undef IPDUM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_32BIT
# undef IPDUM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_UNSPECIFIED
# undef IPDUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# undef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR ZERO INIT sections */

#ifdef IPDUM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
# undef IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_INIT_8BIT
# undef IPDUM_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_INIT_8BIT
# undef IPDUM_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef IPDUM_START_SEC_VAR_NOINIT_8BIT
# undef IPDUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_16BIT
# undef IPDUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_16BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_32BIT
# undef IPDUM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SECOC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(SECOC_START_SEC_CODE)
# undef SECOC_START_SEC_CODE      /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif

#if defined(SECOC_STOP_SEC_CODE)
# undef SECOC_STOP_SEC_CODE       /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(SECOC_START_SEC_APPL_CODE)
# undef SECOC_START_SEC_APPL_CODE      /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif

#if defined(SECOC_STOP_SEC_APPL_CODE)
# undef SECOC_STOP_SEC_APPL_CODE       /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(SECOC_START_SEC_CONST_8BIT)
# undef SECOC_START_SEC_CONST_8BIT  /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#if defined(SECOC_STOP_SEC_CONST_8BIT)
# undef SECOC_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_CONST /* default const stop section */
#endif

#if defined(SECOC_START_SEC_CONST_16BIT)
# undef SECOC_START_SEC_CONST_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(SECOC_STOP_SEC_CONST_16BIT)
# undef SECOC_STOP_SEC_CONST_16BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(SECOC_START_SEC_CONST_32BIT)
# undef SECOC_START_SEC_CONST_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(SECOC_STOP_SEC_CONST_32BIT)
# undef SECOC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(SECOC_START_SEC_CONST_UNSPECIFIED)
# undef SECOC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_CONST_UNSPECIFIED)
# undef SECOC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(SECOC_START_SEC_PBCFG)
# undef SECOC_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(SECOC_STOP_SEC_PBCFG)
# undef SECOC_STOP_SEC_PBCFG /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(SECOC_START_SEC_VAR_INIT_8BIT)
# undef SECOC_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_8BIT)
# undef SECOC_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_VAR   /* default var stop section */
#endif

#if defined(SECOC_START_SEC_VAR_INIT_16BIT)
# undef SECOC_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_16BIT)
# undef SECOC_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_INIT_32BIT)
# undef SECOC_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_32BIT)
# undef SECOC_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_INIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined SECOC_START_SEC_VAR_NOINIT_BOOLEAN
# undef SECOC_START_SEC_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined SECOC_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef SECOC_STOP_SEC_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_8BIT)
# undef SECOC_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_8BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_16BIT)
# undef SECOC_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_16BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_32BIT)
# undef SECOC_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_32BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_PBCFG)
# undef SECOC_START_SEC_VAR_PBCFG /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(SECOC_STOP_SEC_VAR_PBCFG)
# undef SECOC_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_16BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_32BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  SECOC END
 *********************************************************************************************************************/

#ifdef ADC_START_SEC_APPL_CODE
  #undef ADC_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_APPL_CODE
  #undef ADC_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CODE_FAST
  #undef ADC_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ADC_STOP_SEC_CODE_FAST
  #undef ADC_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_CONST_UNSPECIFIED
  #undef ADC_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONST_UNSPECIFIED
  #undef ADC_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_PRIVATE_CODE
  #undef ADC_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PRIVATE_CODE
  #undef ADC_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_PUBLIC_CODE
  #undef ADC_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PUBLIC_CODE
  #undef ADC_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_VAR_8BIT
  #undef ADC_START_SEC_VAR_8BIT
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_8BIT
  #undef ADC_STOP_SEC_VAR_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_INIT_8
  #undef ADC_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_8
  #undef ADC_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_8
  #undef ADC_START_SEC_VAR_NOINIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_8
  #undef ADC_STOP_SEC_VAR_NOINIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_8BIT
  #undef ADC_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_8BIT
  #undef ADC_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_PUBLIC_CODE
  #undef DIO_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_PUBLIC_CODE
  #undef DIO_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_VAR_1BIT
  #undef DIO_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_1BIT
  #undef DIO_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_INIT_BOOLEAN
  #undef DIO_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_INIT_BOOLEAN
  #undef DIO_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NOINIT_16
  #undef DIO_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NOINIT_16
  #undef DIO_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NOINIT_16BIT
  #undef DIO_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NOINIT_16BIT
  #undef DIO_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NO_INIT_16
  #undef DIO_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NO_INIT_16
  #undef DIO_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NO_INIT_16BIT
  #undef DIO_START_SEC_VAR_NO_INIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NO_INIT_16BIT
  #undef DIO_STOP_SEC_VAR_NO_INIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_APPL_CODE
  #undef DIO_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_APPL_CODE
  #undef DIO_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_APPL_CODE
  #undef FLS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_APPL_CODE
  #undef FLS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CODE
  #undef FLS_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
  #undef FLS_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_PRIVATERAM_CODE
  #undef FLS_START_SEC_PRIVATERAM_CODE
  #pragma ghs section text=".FLS_PRIVATE_CODE_RAM"
  #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef FLS_STOP_SEC_PRIVATERAM_CODE
  #undef  FLS_STOP_SEC_PRIVATERAM_CODE
  #pragma ghs section text=default
  #undef MEMMAP_ERROR
#endif

#ifdef FLS_START_SEC_CODE_FAST
  #undef FLS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef FLS_STOP_SEC_CODE_FAST
  #undef FLS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_PRIVATE_CODE
  #undef FLS_START_SEC_PRIVATE_CODE
  #define PRIVATE_CODE_SEC_STARTED
  #include "McalErrHndlg.h"
  #define Dem_ReportErrorStatus HndlMcalDemErr
#undef MEMMAP_ERROR
#endif

#ifdef FLS_STOP_SEC_PRIVATE_CODE
  #undef FLS_STOP_SEC_PRIVATE_CODE
  #undef Dem_ReportErrorStatus
  #undef PRIVATE_CODE_SEC_STARTED
  #undef MEMMAP_ERROR
#endif

#ifdef FLS_START_SEC_PUBLIC_CODE
  #undef FLS_START_SEC_PUBLIC_CODE
#define PUBLIC_CODE_SEC_STARTED
#undef MEMMAP_ERROR
#endif

#ifdef FLS_STOP_SEC_PUBLIC_CODE
  #undef FLS_STOP_SEC_PUBLIC_CODE
#undef PUBLIC_CODE_SEC_STARTED
#undef MEMMAP_ERROR
#endif

#ifdef FLS_START_SEC_VAR_1BIT
  #undef FLS_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_1BIT
  #undef FLS_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_BOOLEAN
  #undef FLS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_1BIT
  #undef FLS_START_SEC_VAR_NOINIT_1BIT
  #define START_SEC_VAR_NOINIT_UNSPECIFIED

#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_1BIT
  #undef FLS_STOP_SEC_VAR_NOINIT_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_32
  #undef FLS_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_32
  #undef FLS_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_32BIT
  #undef FLS_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_32BIT
  #undef FLS_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_BOOLEAN
  #undef FLS_START_SEC_VAR_NOINIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_32
  #undef FLS_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_32
  #undef FLS_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef FLS_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif



#ifdef FLSTST_START_SEC_CODE
  #undef FLSTST_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_CODE
  #undef FLSTST_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_APPL_CODE
  #undef FLSTST_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_APPL_CODE
  #undef FLSTST_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLSTST_START_SEC_PRIVATE_CODE
  #undef FLSTST_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_PRIVATE_CODE
  #undef FLSTST_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_PUBLIC_CODE
  #undef FLSTST_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_PUBLIC_CODE
  #undef FLSTST_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_NOINIT_32
  #undef FLSTST_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLSTST_STOP_SEC_VAR_NOINIT_32
  #undef FLSTST_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLSTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLSTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_APPL_CODE
  #undef GPT_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_APPL_CODE
  #undef GPT_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_FAST
  #undef GPT_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef GPT_STOP_SEC_CODE_FAST
  #undef GPT_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PRIVATE_CODE
  #undef GPT_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_PRIVATE_CODE
  #undef GPT_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PUBLIC_CODE
  #undef GPT_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_PUBLIC_CODE
  #undef GPT_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_VAR_1BIT
  #undef GPT_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_1BIT
  #undef GPT_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
  #undef GPT_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
  #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
  #undef GPT_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
  #undef GPT_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NOINIT_8BIT
  #undef GPT_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef GPT_STOP_SEC_VAR_NOINIT_8BIT
  #undef GPT_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_APPL_CODE
  #undef ICU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_APPL_CODE
  #undef ICU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CODE_FAST
  #undef ICU_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ICU_STOP_SEC_CODE_FAST
  #undef ICU_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ICU_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef ICU_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_PRIVATE_CODE
  #undef ICU_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_PRIVATE_CODE
  #undef ICU_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_PUBLIC_CODE
  #undef ICU_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_PUBLIC_CODE
  #undef ICU_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_VAR_1BIT
  #undef ICU_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_1BIT
  #undef ICU_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_INIT_BOOLEAN
  #undef ICU_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_INIT_BOOLEAN
  #undef ICU_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_32
  #undef ICU_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ICU_STOP_SEC_VAR_NOINIT_32
  #undef ICU_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_32BIT
  #undef ICU_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ICU_STOP_SEC_VAR_NOINIT_32BIT
  #undef ICU_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_APPL_CODE
  #undef MCU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_APPL_CODE
  #undef MCU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CODE_FAST
  #undef MCU_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef MCU_STOP_SEC_CODE_FAST
  #undef MCU_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PRIVATE_CODE
  #undef MCU_START_SEC_PRIVATE_CODE
  #include "McalErrHndlg.h"
  #define Dem_ReportErrorStatus HndlMcalDemErr
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PRIVATE_CODE
  #undef MCU_STOP_SEC_PRIVATE_CODE
  #undef Dem_ReportErrorStatus
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_PUBLIC_CODE
  #undef MCU_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PUBLIC_CODE
  #undef MCU_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_VAR_INIT_32
  #undef MCU_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_32
  #undef MCU_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_BOOLEAN
  #undef MCU_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_APPL_CODE
  #undef PORT_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_APPL_CODE
  #undef PORT_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PRIVATE_CODE
  #undef PORT_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PRIVATE_CODE
  #undef PORT_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PUBLIC_CODE
  #undef PORT_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PUBLIC_CODE
  #undef PORT_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_VAR_1BIT
  #undef PORT_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_1BIT
  #undef PORT_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_INIT_BOOLEAN
  #undef PORT_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_INIT_BOOLEAN
  #undef PORT_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_APPL_CODE
  #undef PWM_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_APPL_CODE
  #undef PWM_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CODE_FAST
  #undef PWM_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef PWM_STOP_SEC_CODE_FAST
  #undef PWM_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #undef PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_PRIVATE_CODE
  #undef PWM_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_PRIVATE_CODE
  #undef PWM_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_PUBLIC_CODE
  #undef PWM_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_PUBLIC_CODE
  #undef PWM_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_VAR_1BIT
  #undef PWM_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_1BIT
  #undef PWM_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_BOOLEAN
  #undef PWM_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_BOOLEAN
  #undef PWM_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_16
  #undef PWM_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_16
  #undef PWM_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_16BIT
  #undef PWM_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_16BIT
  #undef PWM_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_8
  #undef PWM_START_SEC_VAR_NOINIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_8
  #undef PWM_STOP_SEC_VAR_NOINIT_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_8BIT
  #undef PWM_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_8BIT
  #undef PWM_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_CODE
  #undef RAMTST_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef RAMTST_STOP_SEC_CODE
  #undef RAMTST_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_16
  #undef RAMTST_START_SEC_CONST_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef RAMTST_STOP_SEC_CONST_16
  #undef RAMTST_STOP_SEC_CONST_16
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_VAR_NOINIT_16
  #undef RAMTST_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_NOINIT_16
  #undef RAMTST_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NOINIT_32
  #undef RAMTST_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_NOINIT_32
  #undef RAMTST_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NOINIT_8
  #undef RAMTST_START_SEC_VAR_NOINIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_NOINIT_8
  #undef RAMTST_STOP_SEC_VAR_NOINIT_8
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_POWER_ON_INIT_8
  #undef RAMTST_START_SEC_VAR_POWER_ON_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
  #undef RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_CODE
#undef SPI_START_SEC_CODE
#define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
#undef SPI_STOP_SEC_CODE
#define STOP_SEC_CODE
#endif


#ifdef SPI_START_SEC_APPL_CODE
  #undef SPI_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_APPL_CODE
  #undef SPI_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE_FAST
  #undef SPI_START_SEC_CODE_FAST
  #include "McalErrHndlg.h"
  #define Dem_ReportErrorStatus HndlMcalDemErr
  #define START_SEC_CODE_FAST
#endif

#ifdef SPI_STOP_SEC_CODE_FAST
  #undef SPI_STOP_SEC_CODE_FAST
  #undef Dem_ReportErrorStatus
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
  #undef SPI_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
  #undef SPI_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_PRIVATE_CODE
  #undef SPI_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PRIVATE_CODE
  #undef SPI_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_PUBLIC_CODE
  #undef SPI_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PUBLIC_CODE
  #undef SPI_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_VAR_INIT_16
  #undef SPI_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_16
  #undef SPI_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_16
  #undef SPI_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_16
  #undef SPI_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_16BIT
  #undef SPI_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_16BIT
  #undef SPI_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_1BIT
  #undef SPI_START_SEC_VAR_NOINIT_1BIT
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_1BIT
  #undef SPI_STOP_SEC_VAR_NOINIT_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_8
  #undef SPI_START_SEC_VAR_NOINIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_8
  #undef SPI_STOP_SEC_VAR_NOINIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_8BIT
  #undef SPI_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_8BIT
  #undef SPI_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_BOOLEAN
  #undef SPI_START_SEC_VAR_NOINIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_BOOLEAN
  #undef SPI_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_8
  #undef SPI_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_8
  #undef SPI_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_16
  #undef SPI_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_16
  #undef SPI_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_APPL_CODE
  #undef WDG_59_DRIVERA_START_SEC_APPL_CODE
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_APPL_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
  #undef WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16
  #undef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_16
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_32
  #undef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_32
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
  #undef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #define START_SEC_CODE                /* mapped to default code section */
#endif
#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #define STOP_SEC_CODE                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef NVM_START_SEC_CONST_8
    #undef NVM_START_SEC_CONST_8
    #define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8
    #undef NVM_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16
    #undef NVM_START_SEC_CONST_16
    #define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16
    #undef NVM_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
    #undef NVM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
    #undef NVM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NVM_START_SEC_VAR_NOINIT_8
    #undef NVM_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8
    #undef NVM_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* If Development Error Detection is ON (as well as INIT check),    *
 *   it SHALL be mapped to an initialized section (zeor is ok)      *
 * if Development Error Detection (or at least INIT check) is OFF,  *
 *   it MAY also be mapped to a NOINIT section.                     */
#ifdef NVM_START_SEC_VAR_UNSPECIFIED
    #undef NVM_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */
#ifdef NVM_START_SEC_VAR_FAST_8
    #undef NVM_START_SEC_VAR_FAST_8
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8
    #undef NVM_STOP_SEC_VAR_FAST_8
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* SHALL be mapped to a section that is guaranteed to be ZEROed out after Power-On Reset       *
 * (therefore it MAY be a "normal" ZERO_INIT section, being ZEROed out after ANY reset         *
 * Make shure this helds true for all kinds of variable data (esp. "uninitialized).            *
 * If necessary, create a special section (don't map to a common one)                          */    
#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Cal START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CAL_START_SEC_CODE
# undef CAL_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */    
#undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */

#endif
#ifdef CAL_STOP_SEC_CODE
# undef CAL_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif
/*******  CONST sections  ********************************************************************************************/

#ifdef CAL_START_SEC_CONST_UNSPECIFIED
# undef CAL_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif
#ifdef CAL_STOP_SEC_CONST_UNSPECIFIED
# undef CAL_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif
/**********************************************************************************************************************
 *  Cal END
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/
 

/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef CSM_START_SEC_APPL_CODE
# undef CSM_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef CSM_STOP_SEC_APPL_CODE
# undef CSM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CSM_START_SEC_VAR_NOINIT_8BIT
# undef CSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_16BIT
# undef CSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef BSWM_START_SEC_CODE
# undef BSWM_START_SEC_CODE
# define START_SEC_CODE                                 /* mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_CODE
# undef BSWM_STOP_SEC_CODE
# define STOP_SEC_CODE                                  /* default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef BSWM_START_SEC_CONST_8BIT
# undef BSWM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                           /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_8BIT
# undef BSWM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_16BIT
# undef BSWM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_16BIT
# undef BSWM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_32BIT
# undef BSWM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_32BIT
# undef BSWM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
# undef BSWM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
# undef BSWM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_PBCFG
# undef BSWM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_PBCFG
# undef BSWM_STOP_SEC_PBCFG
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef BSWM_START_SEC_VAR_NOINIT_8BIT
# undef BSWM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT                      /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_16BIT
# undef  BSWM_START_SEC_VAR_NOINIT_16BIT                /* mapped to default var section */
# define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_32BIT
# undef  BSWM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT                     /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED               /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_PBCFG
# undef BSWM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG                            /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_PBCFG
# undef BSWM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
# undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED               /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR                /* default var stop section */
#endif


/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef ECUM_START_SEC_CODE
# undef ECUM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ECUM_STOP_SEC_CODE
# undef ECUM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef ECUM_START_SEC_PBCFG
# undef ECUM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_PBCFG
# undef ECUM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_PBCFG_GLOBALROOT
# undef ECUM_START_SEC_PBCFG_GLOBALROOT
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef ECUM_STOP_SEC_PBCFG_GLOBALROOT
# undef ECUM_STOP_SEC_PBCFG_GLOBALROOT
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/


/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_32BIT
# undef ECUM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_32BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ECUM_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ECUM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGM START
 *********************************************************************************************************************/

#include "WdgM_OsMemMap.h" 

/*******  CODE sections **********************************************************************************************/

#if defined WDGM_START_SEC_CODE
# undef WDGM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGM_STOP_SEC_CODE
# undef WDGM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#if defined WDGM_START_SEC_APPL_CODE
# undef WDGM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGM_STOP_SEC_APPL_CODE
# undef WDGM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif




/*******  CONST sections  ********************************************************************************************/

#if defined WDGM_START_SEC_CONST_8BIT
# undef WDGM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined WDGM_STOP_SEC_CONST_8BIT
# undef WDGM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_16BIT
# undef WDGM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined WDGM_STOP_SEC_CONST_16BIT
# undef WDGM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_32BIT
# undef WDGM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined WDGM_STOP_SEC_CONST_32BIT
# undef WDGM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_UNSPECIFIED
# undef WDGM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_CONST_UNSPECIFIED
# undef WDGM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_8BIT
# undef WDGM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_8BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_16BIT
# undef WDGM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_16BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_32BIT
# undef WDGM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_32BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR INIT sections */

#if defined WDGM_START_SEC_VAR_8BIT
# undef WDGM_START_SEC_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined WDGM_STOP_SEC_VAR_8BIT
# undef WDGM_STOP_SEC_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_16BIT
# undef WDGM_START_SEC_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT  
#endif
#if defined WDGM_STOP_SEC_VAR_16BIT
# undef WDGM_STOP_SEC_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_32BIT
# undef WDGM_START_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_32BIT
# undef WDGM_STOP_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_BOOLEAN
# undef WDGM_START_SEC_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_BOOLEAN
# undef WDGM_STOP_SEC_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* Global Shared Variables of the WdgM.
 * If a SafeContext OS is used this section will be defined by the OS.
 * If no SafeContext OS is used this section has to be mapped to a memory area where all SWCs has access
 */
/*#if defined GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define STOP_SEC_VAR
#endif*/
/* or the following section (depending on which OS version is used) */
/*#if defined OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define STOP_SEC_VAR
#endif*/
 
/**********************************************************************************************************************
 *  WDGM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef CRC_START_SEC_CONST_8
    #undef CRC_START_SEC_CONST_8
    #define START_SEC_CONST_8
#endif
#ifdef CRC_STOP_SEC_CONST_8
    #undef CRC_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_16
    #undef CRC_START_SEC_CONST_16
    #define START_SEC_CONST_16
#endif
#ifdef CRC_STOP_SEC_CONST_16
    #undef CRC_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_32
    #undef CRC_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef CRC_STOP_SEC_CONST_32
    #undef CRC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_64
    #undef CRC_START_SEC_CONST_64
    #define START_SEC_CONST_64
#endif
#ifdef CRC_STOP_SEC_CONST_64
    #undef CRC_STOP_SEC_CONST_64
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
 *********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SysService_E2eLib START
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#ifdef E2E_START_SEC_CODE
    #undef E2E_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef E2E_STOP_SEC_CODE
    #undef E2E_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  SysService_E2eLib END
 *********************************************************************************************************************/

/* E2EPW_MemMap.inc: End-To-End Protection Wrapper Memory Mapping: */


/* Code */
/* To be used for mapping code to application block, boot block, external flash etc. */
#if defined   E2EPW_START_SEC_CODE
#undef        E2EPW_START_SEC_CODE
#define           START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE
#undef        E2EPW_STOP_SEC_CODE
#define             STOP_SEC_CODE


/* Constants */
/* To be used for global or static constants.  */
#elif defined E2EPW_START_SEC_CONST_UNSPECIFIED
#undef        E2EPW_START_SEC_CONST_UNSPECIFIED
#define             START_SEC_CONST_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_CONST_UNSPECIFIED
#undef        E2EPW_STOP_SEC_CONST_UNSPECIFIED
#define             STOP_SEC_CONST


/* Var init unspecified */
#elif defined E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#define             START_SEC_VAR_INIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var uninitialized unspecified */
/* To be used for all global or static variables that are never initialized */
#elif defined E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#define             START_SEC_VAR_NOINIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var zero init unspecified */
#elif defined E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             START_SEC_VAR

#elif defined E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Library code     */
/* To be used for code that shall go into library segments for <MSN> module. */
#elif defined E2EPW_START_SEC_CODE_LIB
#undef        E2EPW_START_SEC_CODE_LIB
#define             START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE_LIB
#undef        E2EPW_STOP_SEC_CODE_LIB
#define             STOP_SEC_CODE

#endif

/* End of file E2EPW_MemMap.inc */

/**********************************************************************************************************************
 *  TP_ISO10681 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined (FRTP_START_SEC_CODE)
   #undef      FRTP_START_SEC_CODE                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CODE
#endif

#if defined (FRTP_STOP_SEC_CODE)
   #undef      FRTP_STOP_SEC_CODE                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CODE
#endif

#if defined (FRTP_START_SEC_CODE)
   #undef      FRTP_START_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CODE
#endif

#if defined (FRTP_STOP_SEC_CODE)
   #undef      FRTP_STOP_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined (FRTP_START_SEC_CONST_8BIT)
   #undef      FRTP_START_SEC_CONST_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_8BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_8BIT)
   #undef      FRTP_STOP_SEC_CONST_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_16BIT)
   #undef      FRTP_START_SEC_CONST_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_16BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_16BIT)
   #undef      FRTP_STOP_SEC_CONST_16BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_32BIT)
   #undef      FRTP_START_SEC_CONST_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_32BIT
#endif

#if defined (FRTP_STOP_SEC_CONST_32BIT)
   #undef      FRTP_STOP_SEC_CONST_32BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_CONST_UNSPECIFIED)
   #undef      FRTP_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (FRTP_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FRTP_STOP_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

/*******  Postbuild CFG CONST sections *******************************************************************************/

#if defined (FRTP_START_SEC_PBCFG)
   #undef      FRTP_START_SEC_PBCFG                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_PBCFG
#endif

#if defined (FRTP_STOP_SEC_PBCFG)
   #undef      FRTP_STOP_SEC_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

#if defined (FRTP_START_SEC_PBCFG_ROOT)
   #undef      FRTP_START_SEC_PBCFG_ROOT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_CONST_PBCFG
#endif

#if defined (FRTP_STOP_SEC_PBCFG_ROOT)
   #undef      FRTP_STOP_SEC_PBCFG_ROOT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_CONST
#endif

/*******  Postbuild CFG VAR sections *********************************************************************************/

#if defined (FRTP_START_SEC_VAR_PBCFG)
   #undef      FRTP_START_SEC_VAR_PBCFG              /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_PBCFG
#endif

#if defined (FRTP_STOP_SEC_VAR_PBCFG)
   #undef      FRTP_STOP_SEC_VAR_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined (FRTP_START_SEC_VAR_NOINIT_8BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_16BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_NOINIT_16BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_16BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_32BIT)
   #undef      FRTP_START_SEC_VAR_NOINIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_NOINIT_32BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_32BIT)         /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #undef      FRTP_STOP_SEC_VAR_NOINIT_32BIT
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

/*******  VAR ZERO INIT sections  *************************************************************************************/

/* VAR ZERO_INIT sections */

#if defined (FRTP_START_SEC_VAR_ZERO_INIT_8BIT)
   #undef      FRTP_START_SEC_VAR_ZERO_INIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT)
   #undef      FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_ZERO_INIT_16BIT)
   #undef      FRTP_START_SEC_VAR_ZERO_INIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_ZERO_INIT_16BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_ZERO_INIT_16BIT)
   #undef      FRTP_STOP_SEC_VAR_ZERO_INIT_16BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_ZERO_INIT_32BIT)
   #undef      FRTP_START_SEC_VAR_ZERO_INIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#if defined (FRTP_STOP_SEC_VAR_ZERO_INIT_32BIT)         /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #undef      FRTP_STOP_SEC_VAR_ZERO_INIT_32BIT
   #define STOP_SEC_VAR
#endif

#if defined (FRTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #undef      FRTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#if defined (FRTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
   #undef      FRTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
   #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TP_ISO10681 END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  MCALERRHNDLG START 
 *********************************************************************************************************************/

#ifdef McalErrHndlg_START_SEC_RAMCODE
     #undef  McalErrHndlg_START_SEC_RAMCODE
     #pragma ghs section text=".MCALERRHNDLG_PRIVATE_CODE_RAM"
     #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
 #endif

#ifdef McalErrHndlg_STOP_SEC_RAMCODE
     #undef  McalErrHndlg_STOP_SEC_RAMCODE
     #pragma ghs section text=default
     #undef MEMMAP_ERROR
#endif

/**********************************************************************************************************************
 *  MCALERRHNDLG END 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBALSHARED START 
 *********************************************************************************************************************/
#ifdef GlobalShared_START_SEC_VAR_NOINIT_8
#undef GlobalShared_START_SEC_VAR_NOINIT_8
    #define OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef GlobalShared_STOP_SEC_VAR_NOINIT_8
#undef GlobalShared_STOP_SEC_VAR_NOINIT_8
    #define OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GlobalShared_START_SEC_VAR_CLEARED_16
#undef GlobalShared_START_SEC_VAR_CLEARED_16
    #define OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT 
#endif
#ifdef GlobalShared_STOP_SEC_VAR_CLEARED_16
#undef GlobalShared_STOP_SEC_VAR_CLEARED_16
    #define OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT 
#endif

#ifdef GlobalShared_START_SEC_VAR_CLEARED_32
    #undef GlobalShared_START_SEC_VAR_CLEARED_32
    #define OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
#endif

#ifdef GlobalShared_STOP_SEC_VAR_CLEARED_32
    #undef GlobalShared_STOP_SEC_VAR_CLEARED_32
    #define OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
#endif

#ifdef GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
#endif
/**********************************************************************************************************************
 *  GLOBALSHARED END 
 *********************************************************************************************************************/

#ifdef NVMPROXY_START_SEC_CODE
#undef NVMPROXY_START_SEC_CODE
#define START_SEC_CODE
#endif
#ifdef NVMPROXY_STOP_SEC_CODE
#undef NVMPROXY_STOP_SEC_CODE
#define STOP_SEC_CODE
#endif

#ifdef CDD_NVMPROXY_START_SEC_CODE
#undef CDD_NVMPROXY_START_SEC_CODE
#define START_SEC_CODE
#endif
#ifdef CDD_NVMPROXY_STOP_SEC_CODE
#undef CDD_NVMPROXY_STOP_SEC_CODE
#define STOP_SEC_CODE
#endif

#ifdef MotCtrl_START_SEC_CODE
# undef MotCtrl_START_SEC_CODE
# define START_SEC_CODE
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
#endif

#ifdef MotCtrl_STOP_SEC_CODE
# undef MotCtrl_STOP_SEC_CODE
# define STOP_SEC_CODE
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
#endif

#ifdef CHKPT_START_SEC_CODE
# undef CHKPT_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef CHKPT_STOP_SEC_CODE
# undef CHKPT_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/

#include "Os_MemMap.h" /*visbim*/


/* Package Merger: Stop Section MemMapModuleList */


/* ------------------- provide compatibility to former specifications --------- */

#ifdef START_SEC_CONST_8
    #define START_SEC_CONST_8BIT
    #undef START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_16
    #define START_SEC_CONST_16BIT
    #undef START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
    #undef START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_64
    #define START_SEC_CONST_64BIT
    #undef START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_8
    #define START_SEC_CONST_FAST_8BIT
    #undef START_SEC_CONST_FAST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_16
    #define START_SEC_CONST_FAST_16BIT
    #undef START_SEC_CONST_FAST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_32
    #define START_SEC_CONST_FAST_32BIT
    #undef START_SEC_CONST_FAST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_64
    #define START_SEC_CONST_FAST_64BIT
    #undef START_SEC_CONST_FAST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_8
    #define START_SEC_VAR_INIT_8BIT
    #undef START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_16
    #define START_SEC_VAR_INIT_16BIT
    #undef START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32BIT
    #undef START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_64
    #define START_SEC_VAR_INIT_64BIT
    #undef START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_8
    #define START_SEC_VAR_NOINIT_8BIT
    #undef START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_16
    #define START_SEC_VAR_NOINIT_16BIT
    #undef START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_32
    #define START_SEC_VAR_NOINIT_32BIT
    #undef START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_64
    #define START_SEC_VAR_NOINIT_64BIT
    #undef START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_ZERO_INIT_8BIT
    #undef START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_ZERO_INIT_16BIT
    #undef START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_ZERO_INIT_32BIT
    #undef START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_64
    #define START_SEC_VAR_ZERO_INIT_64BIT
    #undef START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_8
    #define START_SEC_VAR_FAST_INIT_8BIT
    #undef START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_16
    #define START_SEC_VAR_FAST_INIT_16BIT
    #undef START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_32
    #define START_SEC_VAR_FAST_INIT_32BIT
    #undef START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_64
    #define START_SEC_VAR_FAST_INIT_64BIT
    #undef START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_8
    #define START_SEC_VAR_FAST_NOINIT_8BIT
    #undef START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_16
    #define START_SEC_VAR_FAST_NOINIT_16BIT
    #undef START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_32
    #define START_SEC_VAR_FAST_NOINIT_32BIT
    #undef START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_64
    #define START_SEC_VAR_FAST_NOINIT_64BIT
    #undef START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_8
    #define START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_16
    #define START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #undef START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_32
    #define START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #undef START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_64
    #define START_SEC_VAR_FAST_ZERO_INIT_64BIT
    #undef START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_8
    #define START_SEC_VAR_NOCACHE_INIT_8BIT
    #undef START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_16
    #define START_SEC_VAR_NOCACHE_INIT_16BIT
    #undef START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_32
    #define START_SEC_VAR_NOCACHE_INIT_32BIT
    #undef START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_64
    #define START_SEC_VAR_NOCACHE_INIT_64BIT
    #undef START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_8
    #define START_SEC_VAR_NOCACHE_NOINIT_8BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_16
    #define START_SEC_VAR_NOCACHE_NOINIT_16BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_32
    #define START_SEC_VAR_NOCACHE_NOINIT_32BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_64
    #define START_SEC_VAR_NOCACHE_NOINIT_64BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_8
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_16
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_32
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_64
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_64BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_64BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   ) || \
      (defined START_SEC_PBCFG_GLOBALROOT              )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8BIT                 ) || \
      (defined START_SEC_VAR_INIT_16BIT                ) || \
      (defined START_SEC_VAR_INIT_32BIT                ) || \
      (defined START_SEC_VAR_INIT_64BIT                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8BIT               ) || \
      (defined START_SEC_VAR_NOINIT_16BIT              ) || \
      (defined START_SEC_VAR_NOINIT_32BIT              ) || \
      (defined START_SEC_VAR_NOINIT_64BIT              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_PBCFG                     ) || \
      (defined START_SEC_VAR_ZERO_INIT_8BIT            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_64BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_64BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_64BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED) || \
      (defined START_SEC_VAR_NOCACHE_INIT_8BIT         ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_16BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_32BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_64BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED  ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT       ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)    \
      ))
    //#error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_64BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_64BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_64BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_64BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_PBCFG_GLOBALROOT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_PBCFG_GLOBALROOT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT                 
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_INIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_16BIT                
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_INIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_32BIT                
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_INIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_64BIT                
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_INIT_64BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED          
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_INIT_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT               
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_16BIT              
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_32BIT              
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_64BIT              
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOINIT_64BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_PBCFG                     
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT            
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_ZERO_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_ZERO_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_ZERO_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_64BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_ZERO_INIT_64BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_8BIT            
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_64BIT           
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_INIT_64BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT          
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_NOINIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT         
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_NOINIT_16BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT         
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_NOINIT_32BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_64BIT         
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_NOINIT_64BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_64BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_ZERO_INIT_64BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_8BIT         
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_16BIT        
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_INIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_32BIT        
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_INIT_32BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_64BIT        
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_INIT_64BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED  
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_8BIT       
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_NOINIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_16BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_NOINIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_32BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_NOINIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_64BIT      
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_NOINIT_64BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT   
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT   
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT   
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"/
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif



/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
    #undef STOP_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef MEMMAP_ERROR
   // #error "MemMap.h, wrong pragma command"
#endif

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
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

/* PRQA L:MEMMAP_0841_TAG */

