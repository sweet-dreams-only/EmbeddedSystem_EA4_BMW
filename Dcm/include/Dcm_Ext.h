/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dcm_Ext.h
 *        \brief  Public interface of DCM extensions for other components
 *
 *      \details  MICROSAR DCM based on AR 4.0.3
 *
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Mishel Shishmanyan            vissa         Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-08-20                        No relevant changes
 *  01.01.00  2012-09-20                        No relevant changes
 *  01.01.01  2012-10-12  vissa   ESCAN00062132 Wrong service processing for diagnostic services 0x86 0x03/0x04
 *  01.02.00  2013-01-31  vissa   ESCAN00063273 Service 0x86 0x43 is not supported
 *                        vissa   ESCAN00063482 Dcm does not store the tester connection during the RoE activation command execution
 *  01.03.00  2013-04-17                        No relevant changes
 *  01.03.01  2013-05-28                        No relevant changes
 *  01.04.00  2013-06-17                        No relevant changes
 *  01.05.00  2013-07-26  vissa   ESCAN00069875 For OBD ECUs service 0x19 handler shall patch the requested DTC status mask and also all reported DTC status masks
 *  02.00.00  2013-07-18  vissa   ESCAN00070647 Dcm accepts any EWT value in requests 0x86 0x04, 0x40 and 0x45
 *  02.00.01  2013-12-05  vissa   ESCAN00072441 Service 0x19 0x04/0x06 report wrong DTC status mask in case of not stored SnapShot/ExtendedData Records
 *                        vissa   ESCAN00072524 SID 0x86: No RoE responses on multi protocol configurations with enabled declined second request feature
 *  02.01.00  2013-12-03                        No relevant changes
 *  02.02.00  2014-04-11  vissa   ESCAN00075446 SId 0x86 improved NvM API usage reliability
 *  02.02.01  2014-07-31                        No relevant changes
 *  02.02.02  2014-08-11                        No relevant changes
 *  03.00.00  2014-10-30  vissa   ESCAN00078136 Diagnostic client cannot communicate with the ECU
 *  03.01.00  2014-11-11                        No relevant changes
 *  04.00.00  2015-01-30  vissa   ESCAN00081890 Make DTC Status Byte Patch optional
 *  04.01.00  2015-04-07                        No relevant changes
 *  04.01.01  2015-09-10                        No relevant changes
 *  05.00.00  2015-11-27                        No relevant changes
 *  05.01.00  2016-02-28  vissa   ESCAN00088636 Service 0x86: small runtime and code usage reduction for NvM update
 *  05.02.00  2016-04-07                        No relevant changes
 *  07.00.00  2016-05-02                        No relevant changes
 *  07.01.00  2016-09-22                        No relevant changes
 *  07.02.00  2017-01-03                        No relevant changes
 *  08.00.00  2017-04-04                        No relevant changes
 *  08.01.00  2017-04-19                        No relevant changes
 *  08.02.00  2017-05-19                        No relevant changes
 *  08.03.00  2017-06-19                        No relevant changes
 *  08.04.00  2017-07-13                        No relevant changes
 *  08.05.00  2017-08-07                        No relevant changes
 *  08.06.00  2017-09-20                        No relevant changes
 *  08.06.01  2017-11-06                        No relevant changes
 *********************************************************************************************************************/
#if !defined(DCM_EXT_H)
# define DCM_EXT_H
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */

/*! Implementation version */
# define DCM_EXT_MAJOR_VERSION                                       8u
# define DCM_EXT_MINOR_VERSION                                       6u
# define DCM_EXT_PATCH_VERSION                                       1u
# if (DCM_EXTENSION_ID != 0x0001016CUL)
#  error "Mismatching OEMs between static and generated code"
# endif
/* ----------------------------------------------
 ~&&&   Module API function declarations
---------------------------------------------- */
# define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
# if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                          /* COV_DCM_UNSUPPORTED XF */
/**********************************************************************************************************************
 *  Dcm_TriggerOnEvent()
 *********************************************************************************************************************/
/*! \brief          Triggers service to respond to.
 *  \details        Triggers service to respond to which was previously defined via service 0x86 request.
 *  \param[in]      RoeEventId      The RxPDUID of the request
 *  \return         DCM_E_OK        RoeEventId value is valid
 *  \return         DCM_E_NOT_OK    RoeEventId value is not valid or the DCM is currently processing another request
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         This function is only available if DCM_SVC_86_SUPPORT_ENABLED = STD_ON.
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent(uint8 RoeEventId);
# endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
# define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM of unspecified size
---------------------------------------------- */
# define DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
# if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                          /* COV_DCM_UNSUPPORTED XF */
extern CONST(Dcm_ExtSvc86NvMDataType, DCM_CONST) dcmExtSvc86DefaultNvMData;
# endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
# define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#endif /* !defined(DCM_EXT_H) */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Ext.h
 * ******************************************************************************************************************** */
