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
 *              File: Os_MemMap.h
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


#include "Os_MemMap_OsCodeInt.h"
#include "Os_MemMap_OsSectionsInt.h"
#include "Os_MemMap_StacksInt.h"

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ERRORHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_ERRORHOOK_CODE"
# undef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_ERRORHOOK_CODE_OPEN
#  error Section OS_ERRORHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ERRORHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OS_COREINITHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_OS_COREINITHOOK_CODE"
# undef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_OS_COREINITHOOK_CODE_OPEN
#  error Section OS_OS_COREINITHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OS_COREINITHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SHUTDOWNHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SHUTDOWNHOOK_CODE"
# undef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SHUTDOWNHOOK_CODE_OPEN
#  error Section OS_SHUTDOWNHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SHUTDOWNHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Fr_IrqLine0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Fr_IrqLine0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Fr_IrqLine0_CODE"
# undef OS_START_SEC_Fr_IrqLine0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Fr_IrqLine0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Fr_IrqLine0_CODE_OPEN
#  error Section OS_Fr_IrqLine0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Fr_IrqLine0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Fr_IrqLine0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Fr_IrqTimer0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Fr_IrqTimer0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Fr_IrqTimer0_CODE"
# undef OS_START_SEC_Fr_IrqTimer0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Fr_IrqTimer0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Fr_IrqTimer0_CODE_OPEN
#  error Section OS_Fr_IrqTimer0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Fr_IrqTimer0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Fr_IrqTimer0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_MCU_ECM_EIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_MCU_ECM_EIC_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_MCU_ECM_EIC_CAT2_ISR_CODE"
# undef OS_START_SEC_MCU_ECM_EIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_MCU_ECM_EIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_MCU_ECM_EIC_CAT2_ISR_CODE_OPEN
#  error Section OS_MCU_ECM_EIC_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_MCU_ECM_EIC_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_MCU_ECM_EIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_CmnMfgSrv_CallSvc10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_CmnMfgSrv_CallSvc10_CODE"
# undef OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_CmnMfgSrv_CallSvc10_CODE_OPEN
#  error Section OS_NtWrapS_CmnMfgSrv_CallSvc10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_CmnMfgSrv_CallSvc10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_CmnMfgSrv_CallSvc7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_CmnMfgSrv_CallSvc7_CODE"
# undef OS_START_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_CmnMfgSrv_CallSvc7_CODE_OPEN
#  error Section OS_NtWrapS_CmnMfgSrv_CallSvc7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_CmnMfgSrv_CallSvc7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_CmnMfgSrv_CallSvc7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_EraseNvBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_EraseNvBlock_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_EraseNvBlock_CODE"
# undef OS_START_SEC_NtWrapS_NvM_EraseNvBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_EraseNvBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_EraseNvBlock_CODE_OPEN
#  error Section OS_NtWrapS_NvM_EraseNvBlock_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_EraseNvBlock_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_EraseNvBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_GetDataIndex_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_GetDataIndex_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_GetDataIndex_CODE"
# undef OS_START_SEC_NtWrapS_NvM_GetDataIndex_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_GetDataIndex_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_GetDataIndex_CODE_OPEN
#  error Section OS_NtWrapS_NvM_GetDataIndex_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_GetDataIndex_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_GetDataIndex_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_GetErrorStatus_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_GetErrorStatus_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_GetErrorStatus_CODE"
# undef OS_START_SEC_NtWrapS_NvM_GetErrorStatus_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_GetErrorStatus_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_GetErrorStatus_CODE_OPEN
#  error Section OS_NtWrapS_NvM_GetErrorStatus_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_GetErrorStatus_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_GetErrorStatus_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_InvalidateNvBlock_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_InvalidateNvBlock_CODE"
# undef OS_START_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_InvalidateNvBlock_CODE_OPEN
#  error Section OS_NtWrapS_NvM_InvalidateNvBlock_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_InvalidateNvBlock_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_InvalidateNvBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_ReadBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_ReadBlock_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_ReadBlock_CODE"
# undef OS_START_SEC_NtWrapS_NvM_ReadBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_ReadBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_ReadBlock_CODE_OPEN
#  error Section OS_NtWrapS_NvM_ReadBlock_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_ReadBlock_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_ReadBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_SetBlockProtection_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_SetBlockProtection_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_SetBlockProtection_CODE"
# undef OS_START_SEC_NtWrapS_NvM_SetBlockProtection_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_SetBlockProtection_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_SetBlockProtection_CODE_OPEN
#  error Section OS_NtWrapS_NvM_SetBlockProtection_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_SetBlockProtection_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_SetBlockProtection_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_SetDataIndex_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_SetDataIndex_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_SetDataIndex_CODE"
# undef OS_START_SEC_NtWrapS_NvM_SetDataIndex_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_SetDataIndex_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_SetDataIndex_CODE_OPEN
#  error Section OS_NtWrapS_NvM_SetDataIndex_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_SetDataIndex_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_SetDataIndex_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_SetRamBlockStatus_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_SetRamBlockStatus_CODE"
# undef OS_START_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_SetRamBlockStatus_CODE_OPEN
#  error Section OS_NtWrapS_NvM_SetRamBlockStatus_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_SetRamBlockStatus_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_SetRamBlockStatus_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_NvM_WriteBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_NvM_WriteBlock_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_NvM_WriteBlock_CODE"
# undef OS_START_SEC_NtWrapS_NvM_WriteBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_NvM_WriteBlock_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_NvM_WriteBlock_CODE_OPEN
#  error Section OS_NtWrapS_NvM_WriteBlock_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_NvM_WriteBlock_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_NvM_WriteBlock_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE"
# undef OS_START_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE_OPEN
#  error Section OS_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_Rte_Call_CopyCalPageReq_Oper_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE"
# undef OS_START_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE_OPEN
#  error Section OS_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_Rte_Call_SetCalPageReq_Oper_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE"
# undef OS_START_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE_OPEN
#  error Section OS_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_SyncCrc_GetAvlCrcHwUnit_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE"
# undef OS_START_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE_OPEN
#  error Section OS_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_SyncCrc_RelsCrcHwUnit_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_NtWrapS_Xcp_Event_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_NtWrapS_Xcp_Event_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_NtWrapS_Xcp_Event_CODE"
# undef OS_START_SEC_NtWrapS_Xcp_Event_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_NtWrapS_Xcp_Event_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_NtWrapS_Xcp_Event_CODE_OPEN
#  error Section OS_NtWrapS_Xcp_Event_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_NtWrapS_Xcp_Event_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_NtWrapS_Xcp_Event_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIG0_TIC_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIG0_TIC_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIG0_TIC_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIG0_TIC_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIG0_TIC_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIG0_TIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIG0_TIRE_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIG0_TIR_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIG0_TIR_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIG0_TIR_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIG0_TIR_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIG0_TIR_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIG0_TIR_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIH2_TIC_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIH2_TIC_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIH2_TIC_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIH2_TIC_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIH2_TIC_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIH2_TIC_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIH2_TIRE_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_SPI_CSIH2_TIR_CAT2_ISR_CODE"
# undef OS_START_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_OPEN
#  error Section OS_SPI_CSIH2_TIR_CAT2_ISR_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_100ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_100ms_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_100ms_Appl10_CODE"
# undef OS_START_SEC_Task_100ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_100ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_100ms_Appl10_CODE_OPEN
#  error Section OS_Task_100ms_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_100ms_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_100ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_100ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_100ms_Appl7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_100ms_Appl7_CODE"
# undef OS_START_SEC_Task_100ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_100ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_100ms_Appl7_CODE_OPEN
#  error Section OS_Task_100ms_Appl7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_100ms_Appl7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_100ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_100ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_100ms_Appl9_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_100ms_Appl9_CODE"
# undef OS_START_SEC_Task_100ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_100ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_100ms_Appl9_CODE_OPEN
#  error Section OS_Task_100ms_Appl9_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_100ms_Appl9_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_100ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_10msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_10msBsw_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_10msBsw_Appl10_CODE"
# undef OS_START_SEC_Task_10msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_10msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_10msBsw_Appl10_CODE_OPEN
#  error Section OS_Task_10msBsw_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_10msBsw_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_10msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_10ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_10ms_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_10ms_Appl10_CODE"
# undef OS_START_SEC_Task_10ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_10ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_10ms_Appl10_CODE_OPEN
#  error Section OS_Task_10ms_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_10ms_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_10ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_10ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_10ms_Appl7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_10ms_Appl7_CODE"
# undef OS_START_SEC_Task_10ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_10ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_10ms_Appl7_CODE_OPEN
#  error Section OS_Task_10ms_Appl7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_10ms_Appl7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_10ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_10ms_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_10ms_Appl8_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_10ms_Appl8_CODE"
# undef OS_START_SEC_Task_10ms_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_10ms_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_10ms_Appl8_CODE_OPEN
#  error Section OS_Task_10ms_Appl8_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_10ms_Appl8_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_10ms_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_10ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_10ms_Appl9_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_10ms_Appl9_CODE"
# undef OS_START_SEC_Task_10ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_10ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_10ms_Appl9_CODE_OPEN
#  error Section OS_Task_10ms_Appl9_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_10ms_Appl9_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_10ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2msA_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2msA_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2msA_Appl10_CODE"
# undef OS_START_SEC_Task_2msA_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2msA_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2msA_Appl10_CODE_OPEN
#  error Section OS_Task_2msA_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2msA_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2msA_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2msB_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2msB_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2msB_Appl10_CODE"
# undef OS_START_SEC_Task_2msB_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2msB_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2msB_Appl10_CODE_OPEN
#  error Section OS_Task_2msB_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2msB_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2msB_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2msTmplMonr_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2msTmplMonr_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2msTmplMonr_Appl10_CODE"
# undef OS_START_SEC_Task_2msTmplMonr_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2msTmplMonr_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2msTmplMonr_Appl10_CODE_OPEN
#  error Section OS_Task_2msTmplMonr_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2msTmplMonr_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2msTmplMonr_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2ms_Appl7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2ms_Appl7_CODE"
# undef OS_START_SEC_Task_2ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2ms_Appl7_CODE_OPEN
#  error Section OS_Task_2ms_Appl7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2ms_Appl7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2ms_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2ms_Appl8_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2ms_Appl8_CODE"
# undef OS_START_SEC_Task_2ms_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2ms_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2ms_Appl8_CODE_OPEN
#  error Section OS_Task_2ms_Appl8_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2ms_Appl8_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2ms_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_2ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_2ms_Appl9_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_2ms_Appl9_CODE"
# undef OS_START_SEC_Task_2ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_2ms_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_2ms_Appl9_CODE_OPEN
#  error Section OS_Task_2ms_Appl9_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_2ms_Appl9_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_2ms_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_4msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_4msBsw_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_4msBsw_Appl10_CODE"
# undef OS_START_SEC_Task_4msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_4msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_4msBsw_Appl10_CODE_OPEN
#  error Section OS_Task_4msBsw_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_4msBsw_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_4msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_4ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_4ms_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_4ms_Appl10_CODE"
# undef OS_START_SEC_Task_4ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_4ms_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_4ms_Appl10_CODE_OPEN
#  error Section OS_Task_4ms_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_4ms_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_4ms_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_4ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_4ms_Appl7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_4ms_Appl7_CODE"
# undef OS_START_SEC_Task_4ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_4ms_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_4ms_Appl7_CODE_OPEN
#  error Section OS_Task_4ms_Appl7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_4ms_Appl7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_4ms_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_5msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_5msBsw_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_5msBsw_Appl10_CODE"
# undef OS_START_SEC_Task_5msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_5msBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_5msBsw_Appl10_CODE_OPEN
#  error Section OS_Task_5msBsw_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_5msBsw_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_5msBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_Coding_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_Coding_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_Coding_Appl10_CODE"
# undef OS_START_SEC_Task_Coding_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_Coding_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_Coding_Appl10_CODE_OPEN
#  error Section OS_Task_Coding_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_Coding_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_Coding_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_ComBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_ComBsw_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_ComBsw_Appl10_CODE"
# undef OS_START_SEC_Task_ComBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_ComBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_ComBsw_Appl10_CODE_OPEN
#  error Section OS_Task_ComBsw_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_ComBsw_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_ComBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_InitBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_InitBsw_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_InitBsw_Appl10_CODE"
# undef OS_START_SEC_Task_InitBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_InitBsw_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_InitBsw_Appl10_CODE_OPEN
#  error Section OS_Task_InitBsw_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_InitBsw_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_InitBsw_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_Init_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_Init_Appl10_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_Init_Appl10_CODE"
# undef OS_START_SEC_Task_Init_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_Init_Appl10_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_Init_Appl10_CODE_OPEN
#  error Section OS_Task_Init_Appl10_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_Init_Appl10_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_Init_Appl10_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_Init_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_Init_Appl7_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_Init_Appl7_CODE"
# undef OS_START_SEC_Task_Init_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_Init_Appl7_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_Init_Appl7_CODE_OPEN
#  error Section OS_Task_Init_Appl7_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_Init_Appl7_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_Init_Appl7_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_Init_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_Init_Appl8_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_Init_Appl8_CODE"
# undef OS_START_SEC_Task_Init_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_Init_Appl8_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_Init_Appl8_CODE_OPEN
#  error Section OS_Task_Init_Appl8_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_Init_Appl8_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_Init_Appl8_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Task_Init_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Task_Init_Appl9_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = ".OS_Task_Init_Appl9_CODE"
# undef OS_START_SEC_Task_Init_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Task_Init_Appl9_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Task_Init_Appl9_CODE_OPEN
#  error Section OS_Task_Init_Appl9_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Task_Init_Appl9_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section text = default
# undef OS_STOP_SEC_Task_Init_Appl9_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_Appl0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_BOOLEAN_OPEN
#  error Section OS_Appl0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_8BIT_OPEN
#  error Section OS_Appl0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_16BIT_OPEN
#  error Section OS_Appl0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_32BIT_OPEN
#  error Section OS_Appl0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_UNSPECIFIED_OPEN
#  error Section OS_Appl0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Appl0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_FAST_8BIT_OPEN
#  error Section OS_Appl0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_FAST_16BIT_OPEN
#  error Section OS_Appl0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_FAST_32BIT_OPEN
#  error Section OS_Appl0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl0_CONST"
# pragma ghs section rosdata = ".OS_Appl0_CONST_FAST"
# undef OS_START_SEC_Appl0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_BOOLEAN_OPEN
#  error Section OS_Appl10_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_8BIT_OPEN
#  error Section OS_Appl10_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_16BIT_OPEN
#  error Section OS_Appl10_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_32BIT_OPEN
#  error Section OS_Appl10_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_UNSPECIFIED_OPEN
#  error Section OS_Appl10_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Appl10_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_FAST_8BIT_OPEN
#  error Section OS_Appl10_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_FAST_16BIT_OPEN
#  error Section OS_Appl10_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_FAST_32BIT_OPEN
#  error Section OS_Appl10_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl10_CONST"
# pragma ghs section rosdata = ".OS_Appl10_CONST_FAST"
# undef OS_START_SEC_Appl10_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl10_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl10_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_BOOLEAN_OPEN
#  error Section OS_Appl7_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_8BIT_OPEN
#  error Section OS_Appl7_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_16BIT_OPEN
#  error Section OS_Appl7_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_32BIT_OPEN
#  error Section OS_Appl7_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_UNSPECIFIED_OPEN
#  error Section OS_Appl7_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Appl7_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_FAST_8BIT_OPEN
#  error Section OS_Appl7_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_FAST_16BIT_OPEN
#  error Section OS_Appl7_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_FAST_32BIT_OPEN
#  error Section OS_Appl7_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl7_CONST"
# pragma ghs section rosdata = ".OS_Appl7_CONST_FAST"
# undef OS_START_SEC_Appl7_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl7_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl7_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_BOOLEAN_OPEN
#  error Section OS_Appl8_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_8BIT_OPEN
#  error Section OS_Appl8_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_16BIT_OPEN
#  error Section OS_Appl8_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_32BIT_OPEN
#  error Section OS_Appl8_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_UNSPECIFIED_OPEN
#  error Section OS_Appl8_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Appl8_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_FAST_8BIT_OPEN
#  error Section OS_Appl8_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_FAST_16BIT_OPEN
#  error Section OS_Appl8_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_FAST_32BIT_OPEN
#  error Section OS_Appl8_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl8_CONST"
# pragma ghs section rosdata = ".OS_Appl8_CONST_FAST"
# undef OS_START_SEC_Appl8_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl8_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl8_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_BOOLEAN_OPEN
#  error Section OS_Appl9_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_8BIT_OPEN
#  error Section OS_Appl9_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_16BIT_OPEN
#  error Section OS_Appl9_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_32BIT_OPEN
#  error Section OS_Appl9_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_UNSPECIFIED_OPEN
#  error Section OS_Appl9_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Appl9_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_FAST_8BIT_OPEN
#  error Section OS_Appl9_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_FAST_16BIT_OPEN
#  error Section OS_Appl9_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_FAST_32BIT_OPEN
#  error Section OS_Appl9_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_Appl9_CONST"
# pragma ghs section rosdata = ".OS_Appl9_CONST_FAST"
# undef OS_START_SEC_Appl9_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl9_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_Appl9_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_GLOBALSHARED_CONST"
# pragma ghs section rosdata = ".OS_GLOBALSHARED_CONST_FAST"
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = ".OS_SystemApplication_CONST"
# pragma ghs section rosdata = ".OS_SystemApplication_CONST_FAST"
# undef OS_START_SEC_SystemApplication_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section rodata = default
# pragma ghs section rosdata = default
# undef OS_STOP_SEC_SystemApplication_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_Appl0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_8BIT_OPEN
#  error Section OS_Appl0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_16BIT_OPEN
#  error Section OS_Appl0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_32BIT_OPEN
#  error Section OS_Appl0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_8BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_16BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_32BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST"
# undef OS_START_SEC_Appl0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl0_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl0_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl0_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl0_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_8BIT_OPEN
#  error Section OS_Appl10_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_16BIT_OPEN
#  error Section OS_Appl10_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_32BIT_OPEN
#  error Section OS_Appl10_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_8BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_16BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_32BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST"
# undef OS_START_SEC_Appl10_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl10_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl10_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl10_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl10_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl10_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_8BIT_OPEN
#  error Section OS_Appl7_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_16BIT_OPEN
#  error Section OS_Appl7_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_32BIT_OPEN
#  error Section OS_Appl7_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_8BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_16BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_32BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST"
# undef OS_START_SEC_Appl7_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl7_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl7_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl7_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl7_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl7_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_8BIT_OPEN
#  error Section OS_Appl8_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_16BIT_OPEN
#  error Section OS_Appl8_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_32BIT_OPEN
#  error Section OS_Appl8_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_8BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_16BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_32BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST"
# undef OS_START_SEC_Appl8_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl8_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl8_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl8_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl8_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl8_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_8BIT_OPEN
#  error Section OS_Appl9_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_16BIT_OPEN
#  error Section OS_Appl9_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_32BIT_OPEN
#  error Section OS_Appl9_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_8BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_16BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_32BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST"
# undef OS_START_SEC_Appl9_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_Appl9_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_Appl9_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_Appl9_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_Appl9_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_Appl9_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_GLOBALSHARED_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST"
# undef OS_START_SEC_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_NOCACHE_NOINIT"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_NOCACHE_NOINIT"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = ".OS_SystemApplication_VAR_ZERO_INIT_bss"
# pragma ghs section data = ".OS_SystemApplication_VAR_NOCACHE_ZERO_INIT"
# pragma ghs section sbss = ".OS_SystemApplication_VAR_FAST_ZERO_INIT_bss"
# pragma ghs section sdata = ".OS_SystemApplication_VAR_FAST_NOCACHE_ZERO_INIT"
# undef OS_START_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma ghs section bss = default
# pragma ghs section data = default
# pragma ghs section sbss = default
# pragma ghs section sdata = default
# undef OS_STOP_SEC_SystemApplication_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif



