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
 *              File: Os_ServiceFunction_Lcfg.h
 *   Generation Time: 2018-07-30 19:49:09
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

#if !defined (OS_SERVICEFUNCTION_LCFG_H)                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SERVICEFUNCTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ServiceFunction_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/*! Service function configuration data: Adc0OutpInin */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Adc0OutpInin;

/*! Service function configuration data: CritRegInitChk */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CritRegInitChk;

/*! Service function configuration data: CritRegPerChk */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_CritRegPerChk;

/*! Service function configuration data: DmaRegInin */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DmaRegInin;

/*! Service function configuration data: DtsClnUp */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DtsClnUp;

/*! Service function configuration data: DtsInin */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_DtsInin;

/*! Service function configuration data: EcuM_GoDown */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_EcuM_GoDown;

/*! Service function configuration data: Fls_MainFunction */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Fls_MainFunction;

/*! Service function configuration data: IpgInin */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_IpgInin;

/*! Service function configuration data: NvM_MainFunction */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_NvM_MainFunction;

/*! Service function configuration data: NxtrWdgM_Init */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_NxtrWdgM_Init;

/*! Service function configuration data: RstRackCentrMotAg_Oper */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RstRackCentrMotAg_Oper;

/*! Service function configuration data: RstRackCentrMotRev_Oper */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_RstRackCentrMotRev_Oper;

/*! Service function configuration data: SetInpPrm_Oper */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_SetInpPrm_Oper;

/*! Service function configuration data: Spi_AsyncTransmit */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Spi_AsyncTransmit;

/*! Service function configuration data: XcpAppl_CalibrationWriteTrustd */
extern CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_XcpAppl_CalibrationWriteTrustd;

/*! Service function configuration data: NtWrapS_CmnMfgSrv_CallSvc10 */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_CmnMfgSrv_CallSvc10;

/*! Service function configuration data: NtWrapS_NvM_EraseNvBlock */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_EraseNvBlock;

/*! Service function configuration data: NtWrapS_NvM_GetDataIndex */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_GetDataIndex;

/*! Service function configuration data: NtWrapS_NvM_GetErrorStatus */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_GetErrorStatus;

/*! Service function configuration data: NtWrapS_NvM_InvalidateNvBlock */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_InvalidateNvBlock;

/*! Service function configuration data: NtWrapS_NvM_ReadBlock */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_ReadBlock;

/*! Service function configuration data: NtWrapS_NvM_SetBlockProtection */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_SetBlockProtection;

/*! Service function configuration data: NtWrapS_NvM_SetDataIndex */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_SetDataIndex;

/*! Service function configuration data: NtWrapS_NvM_SetRamBlockStatus */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_SetRamBlockStatus;

/*! Service function configuration data: NtWrapS_NvM_WriteBlock */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_NvM_WriteBlock;

/*! Service function configuration data: NtWrapS_Rte_Call_CopyCalPageReq_Oper */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_Rte_Call_CopyCalPageReq_Oper;

/*! Service function configuration data: NtWrapS_Rte_Call_SetCalPageReq_Oper */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_Rte_Call_SetCalPageReq_Oper;

/*! Service function configuration data: NtWrapS_SyncCrc_GetAvlCrcHwUnit */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_SyncCrc_GetAvlCrcHwUnit;

/*! Service function configuration data: NtWrapS_SyncCrc_RelsCrcHwUnit */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_SyncCrc_RelsCrcHwUnit;

/*! Service function configuration data: NtWrapS_Xcp_Event */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_Xcp_Event;

/*! Service function configuration data: NtWrapS_CmnMfgSrv_CallSvc7 */
extern CONST(Os_ServiceNtfConfigType, OS_CONST) OsCfg_Service_NtWrapS_CmnMfgSrv_CallSvc7;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for trusted functions. */
extern CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1];

/*! Object reference table for non-trusted functions. */
extern CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1];

/*! Object reference table for fast trusted functions. */
extern CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_SERVICEFUNCTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.h
 *********************************************************************************************************************/
