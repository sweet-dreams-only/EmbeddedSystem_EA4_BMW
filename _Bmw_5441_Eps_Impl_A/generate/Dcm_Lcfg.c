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
 *            Module: Dcm
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.c
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



#define DCM_LCFG_SOURCE
/* ----------------------------------------------
 ~&&&   Includes
---------------------------------------------- */
                                                                                                                                                     /* PRQA S 0857, 0828 EOF */ /* MD_MSR_1.1_857, MD_MSR_1.1_828 */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Det.h"
#include "Dcm_Int.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif
/* ----------------------------------------------
 ~&&&   Call-back function declarations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_RidMgr_0202_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0202_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0304_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0304_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_0F0C_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0F0C_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_1003_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_1003_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB56_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB56_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB6C_RequestResults()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB6C_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB71_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB71_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB72_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB72_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_FF00_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_FF00_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     status  The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        DCM_E_NOT_OK  Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(void);
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Uninitialized RAM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[8195];
#define DCM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[14]=
{
    8u
  , 3u
  , 2u
  , 1u
  , 0u
  , 7u
  , 6u
  , 5u
  , 4u
  ,13u
  ,12u
  ,11u
  ,10u
  , 9u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll[2]=
{
   1u
  , 0u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[17]=
{
   16u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x27u
  ,0x28u
  ,0x2Eu
  ,0x2Fu
  ,0x31u
  ,0x34u
  ,0x36u
  ,0x37u
  ,0x3Eu
  ,0x85u
  ,0x86u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[10]=
{
   9u
  ,0x01u
  ,0x02u
  ,0x03u
  ,0x41u
  ,0x44u
  ,0x4Fu
  ,0x5Fu
  ,0x61u
  ,0x7Eu
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[2]=
{
   1u
  ,0x01u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[8]=
{
   7u
  ,0x02u
  ,0x04u
  ,0x06u
  ,0x0Au
  ,0x17u
  ,0x18u
  ,0x19u
};
/*! Service 0x27 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[5]=
{
   4u
  ,0x00u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[2]=
{
   1u
  ,0x00u
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
/*! Service 0x86 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc86SubFuncLookUpTable[4]=
{
   3u
  ,0x04u
  ,0x40u
  ,0x45u
};
#define DCM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 16-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[93]=
{
   92u
  ,0x1000u
  ,0x100Au
  ,0x100Eu
  ,0x1701u
  ,0x1704u
  ,0x1723u
  ,0x2502u
  ,0x2503u
  ,0x2504u
  ,0x2507u
  ,0x250Bu
  ,0x2540u
  ,0x2541u
  ,0x37FEu
  ,0x37FFu
  ,0xDB3Cu
  ,0xDB57u
  ,0xDB5Au
  ,0xDB99u
  ,0xDC77u
  ,0xDFDDu
  ,0xF100u
  ,0xF101u
  ,0xF102u
  ,0xF103u
  ,0xF104u
  ,0xF105u
  ,0xF106u
  ,0xF150u
  ,0xF152u
  ,0xF15Au
  ,0xF186u
  ,0xF18Au
  ,0xF18Bu
  ,0xF18Cu
  ,0xF190u
  ,0xF194u
  ,0xF195u
  ,0xF1F2u
  ,0xF1F3u
  ,0xF1F4u
  ,0xF1F7u
  ,0xF1F8u
  ,0xF1F9u
  ,0xF1FDu
  ,0xF1FEu
  ,0xF1FFu
  ,0xF201u
  ,0xFD00u
  ,0xFD01u
  ,0xFD02u
  ,0xFD03u
  ,0xFD05u
  ,0xFD06u
  ,0xFD30u
  ,0xFD31u
  ,0xFD32u
  ,0xFD38u
  ,0xFD39u
  ,0xFD3Au
  ,0xFD3Bu
  ,0xFD3Cu
  ,0xFD40u
  ,0xFD41u
  ,0xFD42u
  ,0xFD60u
  ,0xFD62u
  ,0xFD63u
  ,0xFDB4u
  ,0xFDB5u
  ,0xFDB6u
  ,0xFDB7u
  ,0xFDBCu
  ,0xFDBDu
  ,0xFDBEu
  ,0xFDBFu
  ,0xFDC0u
  ,0xFDD7u
  ,0xFDDFu
  ,0xFDF6u
  ,0xFDF7u
  ,0xFDF8u
  ,0xFE21u
  ,0xFE81u
  ,0xFE82u
  ,0xFE83u
  ,0xFE8Au
  ,0xFE8Bu
  ,0xFE8Cu
  ,0xFE90u
  ,0xFED0u
  ,0xFED1u
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[61]=
{
   60u
  ,0x0202u
  ,0x0203u
  ,0x0205u
  ,0x0220u
  ,0x0303u
  ,0x0304u
  ,0x0F06u
  ,0x0F0Cu
  ,0x1003u
  ,0x37FCu
  ,0x37FDu
  ,0x37FEu
  ,0x400Au
  ,0xA2BBu
  ,0xAB56u
  ,0xAB69u
  ,0xAB6Cu
  ,0xAB71u
  ,0xAB72u
  ,0xAB7Cu
  ,0xAB7Du
  ,0xF000u
  ,0xF001u
  ,0xF002u
  ,0xF100u
  ,0xF101u
  ,0xF110u
  ,0xF111u
  ,0xF112u
  ,0xF113u
  ,0xF114u
  ,0xF115u
  ,0xF116u
  ,0xF117u
  ,0xF118u
  ,0xF119u
  ,0xF11Au
  ,0xF140u
  ,0xF141u
  ,0xF150u
  ,0xF151u
  ,0xF200u
  ,0xFD68u
  ,0xFD70u
  ,0xFD71u
  ,0xFDA4u
  ,0xFDA5u
  ,0xFDACu
  ,0xFDADu
  ,0xFDAEu
  ,0xFDAFu
  ,0xFDF0u
  ,0xFDF1u
  ,0xFE20u
  ,0xFE80u
  ,0xFE88u
  ,0xFE89u
  ,0xFEA1u
  ,0xFF00u
  ,0xFF01u
};
#define DCM_STOP_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM of unspecified size
---------------------------------------------- */
#define DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,8195u}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[28]=
{
   { TRUE, 8u}
  ,{ FALSE, 8u}
  ,{ TRUE, 3u}
  ,{ FALSE, 3u}
  ,{ TRUE, 2u}
  ,{ FALSE, 2u}
  ,{ TRUE, 1u}
  ,{ FALSE, 1u}
  ,{ TRUE, 0u}
  ,{ FALSE, 0u}
  ,{ TRUE, 7u}
  ,{ FALSE, 7u}
  ,{ TRUE, 6u}
  ,{ FALSE, 6u}
  ,{ TRUE, 5u}
  ,{ FALSE, 5u}
  ,{ TRUE, 4u}
  ,{ FALSE, 4u}
  ,{ TRUE,13u}
  ,{ FALSE,13u}
  ,{ TRUE,12u}
  ,{ FALSE,12u}
  ,{ TRUE,11u}
  ,{ FALSE,11u}
  ,{ TRUE,10u}
  ,{ FALSE,10u}
  ,{ TRUE, 9u}
  ,{ FALSE, 9u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[14]=
{
   { 0x00F4u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF4, 0u,0u}
  ,{ 0x00F3u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF3, 0u,0u}
  ,{ 0x00F2u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF2, 0u,0u}
  ,{ 0x00F1u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF1, 0u,0u}
  ,{ 0x00F8u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF8, 0u,0u}
  ,{ 0x00F7u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF7, 0u,0u}
  ,{ 0x00F6u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF6, 0u,0u}
  ,{ 0x00F5u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF5, 0u,0u}
  ,{ 0x00F0u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF0, 0u,0u}
  ,{ 0x00FDu,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFD, 0u,0u}
  ,{ 0x00FCu,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFC, 0u,0u}
  ,{ 0x00FBu,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFB, 0u,0u}
  ,{ 0x00FAu,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFA, 0u,0u}
  ,{ 0x00F9u,PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF9, 0u,0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1]=
{
   { {    6u,   6u},4095u, 4u,TRUE,0u,DemConf_DemClient_DemClient_DCM}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[1]=
{
   ComMConf_ComMChannel_A_FlexRay_372befd6
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[2]=
{
   1u
  ,ComMConf_ComMChannel_A_FlexRay_372befd6
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[27]=
{
   { { 0x017Fu,0x0003u}}
  ,{ { 0x012Fu,0x0003u}}
  ,{ { 0x000Eu,0x0003u}}
  ,{ { 0x004Fu,0x0003u}}
  ,{ { 0x000Fu,0x0003u}}
  ,{ { 0x0014u,0x0003u}}
  ,{ { 0x0020u,0x0003u}}
  ,{ { 0x0045u,0x0003u}}
  ,{ { 0x0080u,0x0003u}}
  ,{ { 0x01FFu,0x0003u}}
  ,{ { 0x000Du,0x0003u}}
  ,{ { 0x0005u,0x0003u}}
  ,{ { 0x014Fu,0x0003u}}
  ,{ { 0x0008u,0x0003u}}
  ,{ { 0x0004u,0x0003u}}
  ,{ { 0x0147u,0x0003u}}
  ,{ { 0x0101u,0x0003u}}
  ,{ { 0x01CFu,0x0003u}}
  ,{ { 0x0002u,0x0003u}}
  ,{ { 0x0145u,0x0003u}}
  ,{ { 0x0007u,0x0003u}}
  ,{ { 0x01DFu,0x0003u}}
  ,{ { 0x0107u,0x0003u}}
  ,{ { 0x0100u,0x0003u}}
  ,{ { 0x0047u,0x0003u}}
  ,{ { 0x0040u,0x0003u}}
  ,{ { 0x00C0u,0x0003u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[9]=
{
   { {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION,0x02u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION,0x41u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_RSU_SESSION,0x44u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_DEVELOPMENT_SESSION,0x4Fu}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_GarageMode,0x5Fu}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_SYSTEM_SUPPLIER_SPECIFIC_61,0x61u}
  ,{ {   10u,1000u},RTE_MODE_DcmDiagnosticSessionControl_DcmDspSessionRow_NXTRMFG,0x7Eu}
};
/*! Security Access state properties */
CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[1]=
{
   {    0u, 3u,0x01u} /* SecLvl: DcmDspSecurityRow_Coding */
};
/*! DID ranges look up */
CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[2]=
{
   {    1u,   1u}
  ,{ 0xF201u,0xF23Fu}
};
/*! DID ranges to DID info map */
CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[1]=
{
     47u
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[92]=
{
   {    3u,   3u,   0u,   0u,0x03u} /* DID: 0x1000 */
  ,{    1u,   1u,   2u,   0u,0x01u} /* DID: 0x100A */
  ,{    1u,   1u,   3u,   0u,0x01u} /* DID: 0x100E */
  ,{    4u,   4u,   4u,   0u,0x01u} /* DID: 0x1701 */
  ,{    4u,   4u,   5u,   0u,0x01u} /* DID: 0x1704 */
  ,{    0u,  40u,   6u,   0u,0x01u} /* DID: 0x1723 */
  ,{    4u,   4u,   7u,   0u,0x01u} /* DID: 0x2502 */
  ,{    2u,   2u,   8u,   0u,0x03u} /* DID: 0x2503 */
  ,{   12u,  12u,  10u,   0u,0x01u} /* DID: 0x2504 */
  ,{    1u,   1u,  11u,   0u,0x01u} /* DID: 0x2507 */
  ,{  140u, 140u,  12u,   0u,0x01u} /* DID: 0x250B */
  ,{    3u,   3u,  13u,   0u,0x01u} /* DID: 0x2540 */
  ,{   20u,  20u,  14u,   0u,0x01u} /* DID: 0x2541 */
  ,{   18u,  18u,  15u,   0u,0x01u} /* DID: 0x37FE */
  ,{    9u,   9u,  16u,   0u,0x01u} /* DID: 0x37FF */
  ,{   15u,  15u,  17u,   0u,0x01u} /* DID: 0xDB3C */
  ,{    7u,   7u,  18u,   0u,0x01u} /* DID: 0xDB57 */
  ,{    2u,   2u,  19u,   0u,0x03u} /* DID: 0xDB5A */
  ,{    3u,   3u,  21u,   0u,0x01u} /* DID: 0xDB99 */
  ,{    1u,   1u,  22u,   0u,0x01u} /* DID: 0xDC77 */
  ,{    8u,   8u,  23u,   0u,0x01u} /* DID: 0xDFDD */
  ,{    4u,   4u,  24u,   0u,0x01u} /* DID: 0xF100 */
  ,{  100u, 100u,  25u,   0u,0x01u} /* DID: 0xF101 */
  ,{   48u,  48u,  26u,   0u,0x01u} /* DID: 0xF102 */
  ,{   48u,  48u,  27u,   0u,0x01u} /* DID: 0xF103 */
  ,{   57u,  57u,  28u,   0u,0x01u} /* DID: 0xF104 */
  ,{   57u,  57u,  29u,   0u,0x01u} /* DID: 0xF105 */
  ,{   57u,  57u,  30u,   0u,0x01u} /* DID: 0xF106 */
  ,{    3u,   3u,  31u,   0u,0x01u} /* DID: 0xF150 */
  ,{    2u,   2u,  32u,   0u,0x01u} /* DID: 0xF152 */
  ,{    1u,   1u,  33u,   0u,0x02u} /* DID: 0xF15A */
  ,{    1u,   1u,  34u,   0u,0x01u} /* DID: 0xF186 */
  ,{    3u,   3u,  35u,   0u,0x01u} /* DID: 0xF18A */
  ,{    3u,   3u,  36u,   0u,0x01u} /* DID: 0xF18B */
  ,{   10u,  10u,  37u,   0u,0x01u} /* DID: 0xF18C */
  ,{   17u,  17u,  38u,   0u,0x01u} /* DID: 0xF190 */
  ,{   16u,  16u,  39u,   0u,0x01u} /* DID: 0xF194 */
  ,{   16u,  16u,  40u,   0u,0x01u} /* DID: 0xF195 */
  ,{    5u,   5u,  41u,   0u,0x01u} /* DID: 0xF1F2 */
  ,{    5u,   5u,  42u,   0u,0x01u} /* DID: 0xF1F3 */
  ,{    5u,   5u,  43u,   0u,0x01u} /* DID: 0xF1F4 */
  ,{   59u,  59u,  44u,   0u,0x01u} /* DID: 0xF1F7 */
  ,{   59u,  59u,  45u,   0u,0x01u} /* DID: 0xF1F8 */
  ,{   59u,  59u,  46u,   0u,0x01u} /* DID: 0xF1F9 */
  ,{    9u,   9u,  47u,   0u,0x01u} /* DID: 0xF1FD */
  ,{    5u,   5u,  48u,   0u,0x01u} /* DID: 0xF1FE */
  ,{   20u,  20u,  49u,   0u,0x01u} /* DID: 0xF1FF */
  ,{    0u, 300u,  50u,   0u,0x01u} /* DID: 0xF201 */
  ,{    1u,   1u,  51u,   0u,0x01u} /* DID: 0xFD00 */
  ,{    4u,   4u,  52u,   0u,0x01u} /* DID: 0xFD01 */
  ,{    1u,   1u,  53u,   0u,0x03u} /* DID: 0xFD02 */
  ,{    4u,   4u,  55u,   0u,0x03u} /* DID: 0xFD03 */
  ,{    8u,   8u,  57u,   0u,0x03u} /* DID: 0xFD05 */
  ,{    1u,   1u,  59u,   0u,0x01u} /* DID: 0xFD06 */
  ,{   20u,  20u,  60u,   0u,0x03u} /* DID: 0xFD30 */
  ,{   20u,  20u,  62u,   0u,0x03u} /* DID: 0xFD31 */
  ,{   20u,  20u,  64u,   0u,0x03u} /* DID: 0xFD32 */
  ,{   16u,  16u,  66u,   0u,0x03u} /* DID: 0xFD38 */
  ,{   16u,  16u,  68u,   0u,0x03u} /* DID: 0xFD39 */
  ,{   16u,  16u,  70u,   0u,0x03u} /* DID: 0xFD3A */
  ,{   16u,  16u,  72u,   0u,0x03u} /* DID: 0xFD3B */
  ,{   16u,  16u,  74u,   0u,0x03u} /* DID: 0xFD3C */
  ,{    4u,   4u,  76u,   0u,0x05u} /* DID: 0xFD40 */
  ,{    4u,   4u,  78u,   1u,0x05u} /* DID: 0xFD41 */
  ,{    4u,   4u,  80u,   2u,0x05u} /* DID: 0xFD42 */
  ,{  100u, 100u,  82u,   0u,0x01u} /* DID: 0xFD60 */
  ,{  256u, 256u,  83u,   0u,0x01u} /* DID: 0xFD62 */
  ,{   20u,  20u,  84u,   0u,0x01u} /* DID: 0xFD63 */
  ,{    4u,   4u,  85u,   0u,0x03u} /* DID: 0xFDB4 */
  ,{    4u,   4u,  87u,   0u,0x03u} /* DID: 0xFDB5 */
  ,{    4u,   4u,  89u,   0u,0x03u} /* DID: 0xFDB6 */
  ,{    4u,   4u,  91u,   0u,0x03u} /* DID: 0xFDB7 */
  ,{    1u,   1u,  93u,   0u,0x01u} /* DID: 0xFDBC */
  ,{    1u,   1u,  94u,   0u,0x01u} /* DID: 0xFDBD */
  ,{    1u,   1u,  95u,   0u,0x01u} /* DID: 0xFDBE */
  ,{    1u,   1u,  96u,   0u,0x01u} /* DID: 0xFDBF */
  ,{    2u,   2u,  97u,   0u,0x03u} /* DID: 0xFDC0 */
  ,{  106u, 106u,  99u,   0u,0x03u} /* DID: 0xFDD7 */
  ,{  106u, 106u, 101u,   0u,0x03u} /* DID: 0xFDDF */
  ,{   12u,  12u, 103u,   0u,0x03u} /* DID: 0xFDF6 */
  ,{   28u,  28u, 105u,   0u,0x03u} /* DID: 0xFDF7 */
  ,{    8u,   8u, 107u,   0u,0x03u} /* DID: 0xFDF8 */
  ,{   28u,  28u, 109u,   0u,0x03u} /* DID: 0xFE21 */
  ,{   13u,  13u, 111u,   0u,0x01u} /* DID: 0xFE81 */
  ,{    4u,   4u, 112u,   0u,0x02u} /* DID: 0xFE82 */
  ,{    4u,   4u, 113u,   0u,0x02u} /* DID: 0xFE83 */
  ,{    7u,   7u, 114u,   0u,0x03u} /* DID: 0xFE8A */
  ,{    1u,   1u, 116u,   0u,0x03u} /* DID: 0xFE8B */
  ,{  212u, 212u, 118u,   0u,0x03u} /* DID: 0xFE8C */
  ,{    4u,   4u, 120u,   0u,0x03u} /* DID: 0xFE90 */
  ,{    1u,   1u, 122u,   0u,0x03u} /* DID: 0xFED0 */
  ,{    1u,   1u, 124u,   0u,0x03u} /* DID: 0xFED1 */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoType, DCM_CONST) Dcm_CfgDidMgrOpInfo[126]=
{
   {   11u,   0u,0x05u} /* DID: 0x1000 */
  ,{   11u,   2u,0x01u} /* DID: 0x1000 */
  ,{   20u,   3u,0x01u} /* DID: 0x100A */
  ,{   20u,   4u,0x01u} /* DID: 0x100E */
  ,{   11u,   5u,0x01u} /* DID: 0x1701 */
  ,{   11u,   6u,0x05u} /* DID: 0x1704 */
  ,{   21u,   8u,0x03u} /* DID: 0x1723 */
  ,{   20u,  10u,0x01u} /* DID: 0x2502 */
  ,{   22u,  11u,0x05u} /* DID: 0x2503 */
  ,{   23u,  13u,0x01u} /* DID: 0x2503 */
  ,{    4u,  14u,0x01u} /* DID: 0x2504 */
  ,{   20u,  15u,0x05u} /* DID: 0x2507 */
  ,{   20u,  17u,0x05u} /* DID: 0x250B */
  ,{   11u,  19u,0x05u} /* DID: 0x2540 */
  ,{   11u,  21u,0x01u} /* DID: 0x2541 */
  ,{   10u,  22u,0x05u} /* DID: 0x37FE */
  ,{   10u,  24u,0x05u} /* DID: 0x37FF */
  ,{   11u,  26u,0x05u} /* DID: 0xDB3C */
  ,{    7u,  28u,0x05u} /* DID: 0xDB57 */
  ,{    7u,  30u,0x05u} /* DID: 0xDB5A */
  ,{    7u,  32u,0x01u} /* DID: 0xDB5A */
  ,{    7u,  33u,0x05u} /* DID: 0xDB99 */
  ,{    4u,  35u,0x05u} /* DID: 0xDC77 */
  ,{   11u,  37u,0x05u} /* DID: 0xDFDD */
  ,{    4u,  39u,0x05u} /* DID: 0xF100 */
  ,{   24u,  41u,0x05u} /* DID: 0xF101 */
  ,{   20u,  43u,0x05u} /* DID: 0xF102 */
  ,{   20u,  45u,0x05u} /* DID: 0xF103 */
  ,{   11u,  47u,0x05u} /* DID: 0xF104 */
  ,{   11u,  49u,0x05u} /* DID: 0xF105 */
  ,{   11u,  51u,0x05u} /* DID: 0xF106 */
  ,{    9u,  53u,0x01u} /* DID: 0xF150 */
  ,{   20u,  54u,0x01u} /* DID: 0xF152 */
  ,{   18u,  55u,0x01u} /* DID: 0xF15A */
  ,{   12u,  56u,0x01u} /* DID: 0xF186 */
  ,{   11u,  57u,0x05u} /* DID: 0xF18A */
  ,{   20u,  59u,0x01u} /* DID: 0xF18B */
  ,{   20u,  60u,0x01u} /* DID: 0xF18C */
  ,{    9u,  61u,0x01u} /* DID: 0xF190 */
  ,{   23u,  62u,0x01u} /* DID: 0xF194 */
  ,{   23u,  63u,0x01u} /* DID: 0xF195 */
  ,{   23u,  64u,0x01u} /* DID: 0xF1F2 */
  ,{   23u,  65u,0x01u} /* DID: 0xF1F3 */
  ,{   23u,  66u,0x01u} /* DID: 0xF1F4 */
  ,{   23u,  67u,0x01u} /* DID: 0xF1F7 */
  ,{   23u,  68u,0x01u} /* DID: 0xF1F8 */
  ,{   23u,  69u,0x01u} /* DID: 0xF1F9 */
  ,{   23u,  70u,0x01u} /* DID: 0xF1FD */
  ,{   23u,  71u,0x01u} /* DID: 0xF1FE */
  ,{   23u,  72u,0x01u} /* DID: 0xF1FF */
  ,{   23u,  73u,0x01u} /* DID: 0xF201 */
  ,{   23u,  74u,0x01u} /* DID: 0xFD00 */
  ,{   23u,  75u,0x01u} /* DID: 0xFD01 */
  ,{   23u,  76u,0x01u} /* DID: 0xFD02 */
  ,{   23u,  77u,0x01u} /* DID: 0xFD02 */
  ,{   23u,  78u,0x01u} /* DID: 0xFD03 */
  ,{   23u,  79u,0x01u} /* DID: 0xFD03 */
  ,{   23u,  80u,0x01u} /* DID: 0xFD05 */
  ,{   23u,  81u,0x01u} /* DID: 0xFD05 */
  ,{   23u,  82u,0x01u} /* DID: 0xFD06 */
  ,{   23u,  83u,0x01u} /* DID: 0xFD30 */
  ,{   23u,  84u,0x01u} /* DID: 0xFD30 */
  ,{   23u,  85u,0x01u} /* DID: 0xFD31 */
  ,{   23u,  86u,0x01u} /* DID: 0xFD31 */
  ,{   23u,  87u,0x01u} /* DID: 0xFD32 */
  ,{   23u,  88u,0x01u} /* DID: 0xFD32 */
  ,{   23u,  89u,0x01u} /* DID: 0xFD38 */
  ,{   23u,  90u,0x01u} /* DID: 0xFD38 */
  ,{   23u,  91u,0x01u} /* DID: 0xFD39 */
  ,{   23u,  92u,0x01u} /* DID: 0xFD39 */
  ,{   23u,  93u,0x01u} /* DID: 0xFD3A */
  ,{   23u,  94u,0x01u} /* DID: 0xFD3A */
  ,{   23u,  95u,0x01u} /* DID: 0xFD3B */
  ,{   23u,  96u,0x01u} /* DID: 0xFD3B */
  ,{   23u,  97u,0x01u} /* DID: 0xFD3C */
  ,{   23u,  98u,0x01u} /* DID: 0xFD3C */
  ,{   23u,  99u,0x01u} /* DID: 0xFD40 */
  ,{   23u, 100u,0x09u} /* DID: 0xFD40 */
  ,{   23u, 102u,0x01u} /* DID: 0xFD41 */
  ,{   23u, 103u,0x09u} /* DID: 0xFD41 */
  ,{   23u, 105u,0x01u} /* DID: 0xFD42 */
  ,{   23u, 106u,0x09u} /* DID: 0xFD42 */
  ,{   23u, 108u,0x01u} /* DID: 0xFD60 */
  ,{   23u, 109u,0x01u} /* DID: 0xFD62 */
  ,{   23u, 110u,0x01u} /* DID: 0xFD63 */
  ,{   23u, 111u,0x01u} /* DID: 0xFDB4 */
  ,{   23u, 112u,0x01u} /* DID: 0xFDB4 */
  ,{   23u, 113u,0x01u} /* DID: 0xFDB5 */
  ,{   23u, 114u,0x01u} /* DID: 0xFDB5 */
  ,{   23u, 115u,0x01u} /* DID: 0xFDB6 */
  ,{   23u, 116u,0x01u} /* DID: 0xFDB6 */
  ,{   23u, 117u,0x01u} /* DID: 0xFDB7 */
  ,{   23u, 118u,0x01u} /* DID: 0xFDB7 */
  ,{   23u, 119u,0x01u} /* DID: 0xFDBC */
  ,{   23u, 120u,0x01u} /* DID: 0xFDBD */
  ,{   23u, 121u,0x01u} /* DID: 0xFDBE */
  ,{   23u, 122u,0x01u} /* DID: 0xFDBF */
  ,{   23u, 123u,0x01u} /* DID: 0xFDC0 */
  ,{   23u, 124u,0x01u} /* DID: 0xFDC0 */
  ,{   23u, 125u,0x01u} /* DID: 0xFDD7 */
  ,{   23u, 126u,0x01u} /* DID: 0xFDD7 */
  ,{   23u, 127u,0x01u} /* DID: 0xFDDF */
  ,{   23u, 128u,0x01u} /* DID: 0xFDDF */
  ,{   23u, 129u,0x01u} /* DID: 0xFDF6 */
  ,{   23u, 130u,0x01u} /* DID: 0xFDF6 */
  ,{   23u, 131u,0x01u} /* DID: 0xFDF7 */
  ,{   23u, 132u,0x01u} /* DID: 0xFDF7 */
  ,{   23u, 133u,0x01u} /* DID: 0xFDF8 */
  ,{   23u, 134u,0x01u} /* DID: 0xFDF8 */
  ,{   23u, 135u,0x01u} /* DID: 0xFE21 */
  ,{   23u, 136u,0x01u} /* DID: 0xFE21 */
  ,{   23u, 137u,0x01u} /* DID: 0xFE81 */
  ,{   23u, 138u,0x01u} /* DID: 0xFE82 */
  ,{   23u, 139u,0x01u} /* DID: 0xFE83 */
  ,{   23u, 140u,0x01u} /* DID: 0xFE8A */
  ,{   23u, 141u,0x01u} /* DID: 0xFE8A */
  ,{   23u, 142u,0x01u} /* DID: 0xFE8B */
  ,{   23u, 143u,0x01u} /* DID: 0xFE8B */
  ,{   23u, 144u,0x01u} /* DID: 0xFE8C */
  ,{   23u, 145u,0x01u} /* DID: 0xFE8C */
  ,{   23u, 146u,0x01u} /* DID: 0xFE90 */
  ,{   23u, 147u,0x01u} /* DID: 0xFE90 */
  ,{   23u, 148u,0x01u} /* DID: 0xFED0 */
  ,{   23u, 149u,0x01u} /* DID: 0xFED0 */
  ,{   23u, 150u,0x01u} /* DID: 0xFED1 */
  ,{   23u, 151u,0x01u} /* DID: 0xFED1 */
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[152]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1000_Pruefstempel_ReadData)), 2u} /* DID: 0x1000 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1000_Pruefstempel_ConditionCheckRead)), 1u} /* DID: 0x1000 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1000_Pruefstempel_WriteData)), 2u} /* DID: 0x1000 */                                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_100A_EnergySavingState_ReadData)), 1u} /* DID: 0x100A */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_100E_ExtendedEnergySavingState_ReadData)), 1u} /* DID: 0x100E */                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1701_Systemzeit_ReadData)), 1u} /* DID: 0x1701 */                                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData)), 2u} /* DID: 0x1704 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead)), 1u} /* DID: 0x1704 */                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadData)), 1u} /* DID: 0x1723 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadDataLength)), 1u} /* DID: 0x1723 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2502_ProgrammingCounter_ReadData)), 1u} /* DID: 0x2502 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ReadData)), 1u} /* DID: 0x2503 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ConditionCheckRead)), 0u} /* DID: 0x2503 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_WriteData)), 1u} /* DID: 0x2503 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2504_FlashTimingParameter_ReadData)), 1u} /* DID: 0x2504 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ReadData)), 1u} /* DID: 0x2507 */                                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead)), 0u} /* DID: 0x2507 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_250B_ReadSwRevision_ReadData)), 2u} /* DID: 0x250B */                                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_250B_ReadSwRevision_ConditionCheckRead)), 1u} /* DID: 0x250B */                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2540_MileKmEeprom_ReadData)), 2u} /* DID: 0x2540 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2540_MileKmEeprom_ConditionCheckRead)), 1u} /* DID: 0x2540 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_2541_StatusCalcvn_ReadData)), 1u} /* DID: 0x2541 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_37FE_Cps_ReadData)), 1u} /* DID: 0x37FE */                                                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_37FE_Cps_ConditionCheckRead)), 0u} /* DID: 0x37FE */                                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_37FF_ReadProtocolData_ReadData)), 1u} /* DID: 0x37FF */                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_37FF_ReadProtocolData_ConditionCheckRead)), 0u} /* DID: 0x37FF */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ReadData)), 2u} /* DID: 0xDB3C */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ConditionCheckRead)), 1u} /* DID: 0xDB3C */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ReadData)), 2u} /* DID: 0xDB57 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ConditionCheckRead)), 1u} /* DID: 0xDB57 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ReadData)), 2u} /* DID: 0xDB5A */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ConditionCheckRead)), 1u} /* DID: 0xDB5A */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_WriteData)), 2u} /* DID: 0xDB5A */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ReadData)), 2u} /* DID: 0xDB99 */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ConditionCheckRead)), 1u} /* DID: 0xDB99 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ReadData)), 2u} /* DID: 0xDC77 */                                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ConditionCheckRead)), 1u} /* DID: 0xDC77 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ReadData)), 2u} /* DID: 0xDFDD */                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ConditionCheckRead)), 1u} /* DID: 0xDFDD */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ReadData)), 1u} /* DID: 0xF100 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ConditionCheckRead)), 0u} /* DID: 0xF100 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F101_SvkAktuell_ReadData)), 2u} /* DID: 0xF101 */                                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F101_SvkAktuell_ConditionCheckRead)), 1u} /* DID: 0xF101 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F102_SvkSysSupplier_ReadData)), 2u} /* DID: 0xF102 */                                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F102_SvkSysSupplier_ConditionCheckRead)), 1u} /* DID: 0xF102 */                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F103_SvkWerk_ReadData)), 2u} /* DID: 0xF103 */                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F103_SvkWerk_ConditionCheckRead)), 1u} /* DID: 0xF103 */                                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup0_ReadData)), 2u} /* DID: 0xF104 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead)), 1u} /* DID: 0xF104 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup1_ReadData)), 2u} /* DID: 0xF105 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead)), 1u} /* DID: 0xF105 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup2_ReadData)), 2u} /* DID: 0xF106 */                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead)), 1u} /* DID: 0xF106 */                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F150_SgbdIdx_ReadData)), 1u} /* DID: 0xF150 */                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F152_Readhwmodificationindex_ReadData)), 1u} /* DID: 0xF152 */                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F15A_WdbiFp_WriteData)), 2u} /* DID: 0xF15A */                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_F186_ReadData)), 1u} /* DID: 0xF186 */                                                                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ReadData)), 2u} /* DID: 0xF18A */                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ConditionCheckRead)), 1u} /* DID: 0xF18A */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F18B_Herstelldatum_ReadData)), 1u} /* DID: 0xF18B */                                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_F18C_EcuSerialNumber_ReadData)), 1u} /* DID: 0xF18C */                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DcmDspData_Vin_ReadData)), 2u} /* DID: 0xF190 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF194Rd)), 2u} /* DID: 0xF194 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF195Rd)), 2u} /* DID: 0xF195 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F2Rd)), 2u} /* DID: 0xF1F2 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F3Rd)), 2u} /* DID: 0xF1F3 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F4Rd)), 2u} /* DID: 0xF1F4 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F7Rd)), 2u} /* DID: 0xF1F7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F8Rd)), 2u} /* DID: 0xF1F8 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1F9Rd)), 2u} /* DID: 0xF1F9 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1FDRd)), 2u} /* DID: 0xF1FD */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1FERd)), 2u} /* DID: 0xF1FE */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF1FFRd)), 2u} /* DID: 0xF1FF */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmReadDataIdWrpr_Oper)), 0u} /* DID: 0xF201 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD00Rd)), 2u} /* DID: 0xFD00 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD01Rd)), 2u} /* DID: 0xFD01 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD02Rd)), 2u} /* DID: 0xFD02 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD02Wr)), 2u} /* DID: 0xFD02 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD03Rd)), 2u} /* DID: 0xFD03 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD03Wr)), 2u} /* DID: 0xFD03 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD05Rd)), 2u} /* DID: 0xFD05 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD05Wr)), 2u} /* DID: 0xFD05 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD06Rd)), 2u} /* DID: 0xFD06 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD30Rd)), 2u} /* DID: 0xFD30 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD30Wr)), 2u} /* DID: 0xFD30 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD31Rd)), 2u} /* DID: 0xFD31 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD31Wr)), 2u} /* DID: 0xFD31 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD32Rd)), 2u} /* DID: 0xFD32 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD32Wr)), 2u} /* DID: 0xFD32 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD38Rd)), 2u} /* DID: 0xFD38 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD38Wr)), 2u} /* DID: 0xFD38 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD39Rd)), 2u} /* DID: 0xFD39 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD39Wr)), 2u} /* DID: 0xFD39 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3ARd)), 2u} /* DID: 0xFD3A */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3AWr)), 2u} /* DID: 0xFD3A */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3BRd)), 2u} /* DID: 0xFD3B */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3BWr)), 2u} /* DID: 0xFD3B */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3CRd)), 2u} /* DID: 0xFD3C */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD3CWr)), 2u} /* DID: 0xFD3C */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD40Rd)), 2u} /* DID: 0xFD40 */                                                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD40CtrlRtn)), 3u} /* DID: 0xFD40 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD40CtrlAdj)), 4u} /* DID: 0xFD40 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD41Rd)), 2u} /* DID: 0xFD41 */                                                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD41CtrlRtn)), 3u} /* DID: 0xFD41 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD41CtrlAdj)), 4u} /* DID: 0xFD41 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD42Rd)), 2u} /* DID: 0xFD42 */                                                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD42CtrlRtn)), 3u} /* DID: 0xFD42 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIfDcmWrpSrvFD42CtrlAdj)), 4u} /* DID: 0xFD42 */                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD60Rd)), 2u} /* DID: 0xFD60 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD62Rd)), 2u} /* DID: 0xFD62 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD63Rd)), 2u} /* DID: 0xFD63 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB4Rd)), 2u} /* DID: 0xFDB4 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB4Wr)), 2u} /* DID: 0xFDB4 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB5Rd)), 2u} /* DID: 0xFDB5 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB5Wr)), 2u} /* DID: 0xFDB5 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB6Rd)), 2u} /* DID: 0xFDB6 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB6Wr)), 2u} /* DID: 0xFDB6 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB7Rd)), 2u} /* DID: 0xFDB7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDB7Wr)), 2u} /* DID: 0xFDB7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDBCRd)), 2u} /* DID: 0xFDBC */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDBDRd)), 2u} /* DID: 0xFDBD */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDBERd)), 2u} /* DID: 0xFDBE */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDBFRd)), 2u} /* DID: 0xFDBF */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDC0Rd)), 2u} /* DID: 0xFDC0 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDC0Wr)), 2u} /* DID: 0xFDC0 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDD7Rd)), 2u} /* DID: 0xFDD7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDD7Wr)), 2u} /* DID: 0xFDD7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDDFRd)), 2u} /* DID: 0xFDDF */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDDFWr)), 2u} /* DID: 0xFDDF */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF6Rd)), 2u} /* DID: 0xFDF6 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF6Wr)), 2u} /* DID: 0xFDF6 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF7Rd)), 2u} /* DID: 0xFDF7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF7Wr)), 2u} /* DID: 0xFDF7 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF8Rd)), 2u} /* DID: 0xFDF8 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF8Wr)), 2u} /* DID: 0xFDF8 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE21Rd)), 2u} /* DID: 0xFE21 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE21Wr)), 2u} /* DID: 0xFE21 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE81Rd)), 2u} /* DID: 0xFE81 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE82Wr)), 2u} /* DID: 0xFE82 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE83Wr)), 2u} /* DID: 0xFE83 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8ARd)), 2u} /* DID: 0xFE8A */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8AWr)), 2u} /* DID: 0xFE8A */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8BRd)), 2u} /* DID: 0xFE8B */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8BWr)), 2u} /* DID: 0xFE8B */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8CRd)), 2u} /* DID: 0xFE8C */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE8CWr)), 2u} /* DID: 0xFE8C */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE90Rd)), 2u} /* DID: 0xFE90 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE90Wr)), 2u} /* DID: 0xFE90 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFED0Rd)), 2u} /* DID: 0xFED0 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFED0Wr)), 2u} /* DID: 0xFED0 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFED1Rd)), 2u} /* DID: 0xFED1 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFED1Wr)), 2u} /* DID: 0xFED1 */                                                                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! IO control DID operation properties */
CONST(Dcm_CfgDidMgrOpInfoIoControlType, DCM_CONST) Dcm_CfgDidMgrOpInfoIoControl[3]=
{
   {  100u,  23u} /* DID: 0xFD40 */
  ,{  103u,  23u} /* DID: 0xFD41 */
  ,{  106u,  23u} /* DID: 0xFD42 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[60]=
{
   {    0u,  18u,0x01u} /* RID: 0x0202 */
  ,{    1u,   9u,0x01u} /* RID: 0x0203 */
  ,{    2u,  11u,0x01u} /* RID: 0x0205 */
  ,{    3u,  18u,0x01u} /* RID: 0x0220 */
  ,{    4u,  11u,0x01u} /* RID: 0x0303 */
  ,{    5u,  11u,0x01u} /* RID: 0x0304 */
  ,{    6u,   7u,0x01u} /* RID: 0x0F06 */
  ,{    7u,  11u,0x01u} /* RID: 0x0F0C */
  ,{    8u,  20u,0x01u} /* RID: 0x1003 */
  ,{    9u,  10u,0x01u} /* RID: 0x37FC */
  ,{   10u,  13u,0x01u} /* RID: 0x37FD */
  ,{   11u,  13u,0x01u} /* RID: 0x37FE */
  ,{   12u,  11u,0x03u} /* RID: 0x400A */
  ,{   14u,  25u,0x01u} /* RID: 0xA2BB */
  ,{   15u,  25u,0x05u} /* RID: 0xAB56 */
  ,{   17u,  25u,0x01u} /* RID: 0xAB69 */
  ,{   18u,   7u,0x07u} /* RID: 0xAB6C */
  ,{   21u,  25u,0x05u} /* RID: 0xAB71 */
  ,{   23u,  25u,0x07u} /* RID: 0xAB72 */
  ,{   26u,  26u,0x01u} /* RID: 0xAB7C */
  ,{   27u,   7u,0x01u} /* RID: 0xAB7D */
  ,{   28u,  16u,0x01u} /* RID: 0xF000 */
  ,{   29u,  16u,0x01u} /* RID: 0xF001 */
  ,{   30u,  16u,0x01u} /* RID: 0xF002 */
  ,{   31u,  16u,0x07u} /* RID: 0xF100 */
  ,{   34u,  16u,0x07u} /* RID: 0xF101 */
  ,{   37u,  16u,0x07u} /* RID: 0xF110 */
  ,{   40u,  16u,0x07u} /* RID: 0xF111 */
  ,{   43u,  16u,0x07u} /* RID: 0xF112 */
  ,{   46u,  16u,0x07u} /* RID: 0xF113 */
  ,{   49u,  16u,0x07u} /* RID: 0xF114 */
  ,{   52u,  16u,0x07u} /* RID: 0xF115 */
  ,{   55u,  16u,0x07u} /* RID: 0xF116 */
  ,{   58u,  16u,0x07u} /* RID: 0xF117 */
  ,{   61u,  16u,0x07u} /* RID: 0xF118 */
  ,{   64u,  16u,0x07u} /* RID: 0xF119 */
  ,{   67u,  16u,0x07u} /* RID: 0xF11A */
  ,{   70u,  16u,0x07u} /* RID: 0xF140 */
  ,{   73u,  16u,0x07u} /* RID: 0xF141 */
  ,{   76u,  16u,0x07u} /* RID: 0xF150 */
  ,{   79u,  16u,0x07u} /* RID: 0xF151 */
  ,{   82u,  16u,0x01u} /* RID: 0xF200 */
  ,{   83u,  16u,0x01u} /* RID: 0xFD68 */
  ,{   84u,  16u,0x01u} /* RID: 0xFD70 */
  ,{   85u,  16u,0x01u} /* RID: 0xFD71 */
  ,{   86u,  16u,0x01u} /* RID: 0xFDA4 */
  ,{   87u,  16u,0x01u} /* RID: 0xFDA5 */
  ,{   88u,  16u,0x01u} /* RID: 0xFDAC */
  ,{   89u,  16u,0x01u} /* RID: 0xFDAD */
  ,{   90u,  16u,0x01u} /* RID: 0xFDAE */
  ,{   91u,  16u,0x01u} /* RID: 0xFDAF */
  ,{   92u,  16u,0x05u} /* RID: 0xFDF0 */
  ,{   94u,  16u,0x05u} /* RID: 0xFDF1 */
  ,{   96u,  16u,0x03u} /* RID: 0xFE20 */
  ,{   98u,  23u,0x01u} /* RID: 0xFE80 */
  ,{   99u,  16u,0x01u} /* RID: 0xFE88 */
  ,{  100u,  16u,0x01u} /* RID: 0xFE89 */
  ,{  101u,  16u,0x01u} /* RID: 0xFEA1 */
  ,{  102u,  18u,0x01u} /* RID: 0xFF00 */
  ,{  103u,  18u,0x01u} /* RID: 0xFF01 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[104]=
{
   { ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0202_Start)),   1u,   1u,   1u,   1u, 9u} /* RID: 0x0202 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_RcCppc_Routine_Start)),   0u,   0u,   0u, 256u, 6u} /* RID: 0x0203 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_RcRswedi_Routine_Start)),   8u,   8u,   0u, 256u, 8u} /* RID: 0x0205 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_DeleteSwPackage_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0x0220 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_DiagCommLoopback_Routine_Start)),   0u,1024u,   0u,1024u, 7u} /* RID: 0x0303 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0304_Start)),   1u,   1u,   4u,   4u, 9u} /* RID: 0x0304 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_IsLoeschen_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0x0F06 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0F0C_Start)),   1u,   1u,   0u,   0u, 9u} /* RID: 0x0F0C */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_1003_Start)),   1u,   1u,   0u,   0u, 9u} /* RID: 0x1003 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ReadNcd_Routine_Start)),   6u,   6u,   0u,1024u, 8u} /* RID: 0x37FC */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_WriteNcd_Routine_Start)),   0u,1024u,   0u,   0u, 4u} /* RID: 0x37FD */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_CheckNcd_Routine_Start)),   0u,  18u,   1u,   1u, 5u} /* RID: 0x37FE */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_DarhStrtStop_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0x400A */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_DarhStrtStop_Routine_Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0x400A */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xA2BB */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_AB56_Start)),   3u,   3u,   0u,   0u, 9u} /* RID: 0xAB56 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsPendeln_Routine_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xAB56 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB69 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB6C */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB6C */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_AB6C_RequestResults)),   0u,   0u,   4u,   4u, 9u} /* RID: 0xAB6C */                                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_AB71_Start)),   5u,   5u,   0u,   0u, 9u} /* RID: 0xAB71 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsVerfahren_Routine_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xAB71 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_AB72_Start)),   3u,   3u,   0u,   0u, 9u} /* RID: 0xAB72 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB72 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xAB72 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_EpsZahnstangenmitteReset_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB7C */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_SteuernEpsMultiturnwertReset_Routine_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xAB7D */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF000Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF000 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF001Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF001 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF002Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF002 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF100Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF100 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF100Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF100 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF100Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF100 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF101Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF101 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF101Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF101 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF101Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF101 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF110Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF110 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF110Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF110 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF110Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF110 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF111Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF111 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF111Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF111 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF111Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF111 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF112Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF112 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF112Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF112 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF112Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF112 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF113Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF113 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF113Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF113 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF113Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF113 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF114Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF114 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF114Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF114 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF114Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF114 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF115Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF115 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF115Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF115 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF115Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF115 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF116Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF116 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF116Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF116 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF116Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF116 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF117Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF117 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF117Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF117 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF117Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF117 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF118Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF118 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF118Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF118 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF118Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF118 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF119Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF119 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF119Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF119 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF119Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF119 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF11AStrt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF11A */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF11AStop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF11A */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF11ASts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF11A */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF140Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF140 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF140Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF140 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF140Sts)),   0u,   0u,   8u,   8u, 3u} /* RID: 0xF140 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF141Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF141 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF141Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF141 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF141Sts)),   0u,   0u,   8u,   8u, 3u} /* RID: 0xF141 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF150Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF150 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF150Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF150 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF150Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF150 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF151Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF151 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF151Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF151 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF151Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF151 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xF200Strt)),   4u,   4u,   0u,   0u, 1u} /* RID: 0xF200 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD68Strt)),   2u,   2u,   5u,   5u, 2u} /* RID: 0xFD68 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD70Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFD70 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFD71Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFD71 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDA4Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDA4 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDA5Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDA5 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDACStrt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDAC */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDADStrt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDAD */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDAEStrt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDAE */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDAFStrt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDAF */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF0Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDF0 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF0Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xFDF0 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF1Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFDF1 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFDF1Sts)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xFDF1 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE20Strt)),   8u,   8u,   0u,   0u, 1u} /* RID: 0xFE20 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE20Stop)),   4u,   4u,   0u,   0u, 1u} /* RID: 0xFE20 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE80Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFE80 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE88Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFE88 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFE89Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFE89 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(CmnMfgSrvIf_Srv0xFEA1Strt)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFEA1 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_FF00_Start)),   1u,   1u,   1u,   1u, 9u} /* RID: 0xFF00 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_RcCpd_Routine_Start)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xFF01 */                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[4]=
{
   Dcm_Service27Init
  ,Dcm_Service2FInit
  ,Dcm_Service86Init
  ,NULL_PTR /* end marker */
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[17]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 0u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   0u,   0u, 0u, 0u} /* SID: 0x22 */
  ,{ Dcm_Service27Processor,0x03u, 1u,   6u,   0u, 0u, 0u} /* SID: 0x27 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   7u,   0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x2E */
  ,{ Dcm_Service2FProcessor,0x00u, 3u,   8u,   0u, 0u, 0u} /* SID: 0x2F */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x31 */
  ,{ DcmDsdSidTabFnc_RequestDownload,0x00u, 0u,   0u,   0u, 0u, 0u} /* SID: 0x34 */
  ,{ DcmDsdSidTabFnc_TransferData,0x00u, 0u,   0u,   0u, 0u, 0u} /* SID: 0x36 */
  ,{ DcmDsdSidTabFnc_RequestTransferExit,0x00u, 0u,   0u,   0u, 0u, 0u} /* SID: 0x37 */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,   9u,   0u, 0u, 0u} /* SID: 0x85 */
  ,{ Dcm_Service86Processor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x86 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[16]=
{
      0u /* SID: 0x10 */
  ,  10u /* SID: 0x11 */
  ,   7u /* SID: 0x14 */
  ,  10u /* SID: 0x19 */
  ,  12u /* SID: 0x22 */
  ,  13u /* SID: 0x27 */
  ,  14u /* SID: 0x28 */
  ,  15u /* SID: 0x2E */
  ,  16u /* SID: 0x2F */
  ,  17u /* SID: 0x31 */
  ,  18u /* SID: 0x34 */
  ,  18u /* SID: 0x36 */
  ,  18u /* SID: 0x37 */
  ,  19u /* SID: 0x3E */
  ,  14u /* SID: 0x85 */
  ,  11u /* SID: 0x86 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[10]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service27PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service2FPostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[1]=
{
   Dcm_ServiceNoCancel
};
/*! OEM notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagOemNotificationInfo[3]=
{
   { Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Indication,Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Confirmation}
  ,{ Rte_Call_ServiceRequestManufacturerNotification_Coding_Indication,Rte_Call_ServiceRequestManufacturerNotification_Coding_Confirmation}
  ,{ NULL_PTR,NULL_PTR}
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[9]=
{
   { { 50u, 500u}, 0u} /* Session ID: 0x01 */
  ,{ { 50u, 500u}, 1u} /* Session ID: 0x02 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x03 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x41 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x44 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x4F */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x5F */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x61 */
  ,{ { 50u, 500u}, 0u} /* Session ID: 0x7E */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[9]=
{
      1u /* Session ID: 0x01 */
  ,   2u /* Session ID: 0x02 */
  ,   3u /* Session ID: 0x03 */
  ,   4u /* Session ID: 0x41 */
  ,   5u /* Session ID: 0x44 */
  ,   6u /* Session ID: 0x4F */
  ,   7u /* Session ID: 0x5F */
  ,   8u /* Session ID: 0x61 */
  ,   9u /* Session ID: 0x7E */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[1]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[1]=
{
     10u /* SF: 0x01 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[7]=
{
   { Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
  ,{ Dcm_Service19_0AProcessor, 1u} /* SF: 0x0A */
  ,{ Dcm_Service19_17Processor, 3u} /* SF: 0x17 */
  ,{ Dcm_Service19_18Processor, 6u} /* SF: 0x18 */
  ,{ Dcm_Service19_19Processor, 6u} /* SF: 0x19 */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[7]=
{
     11u /* SF: 0x02 */
  ,  11u /* SF: 0x04 */
  ,  11u /* SF: 0x06 */
  ,  10u /* SF: 0x0A */
  ,  11u /* SF: 0x17 */
  ,  11u /* SF: 0x18 */
  ,  11u /* SF: 0x19 */
};
/*! Service 0x27 sub-service properties table  */
CONST(Dcm_CfgSvc27SubFuncInfoType, DCM_CONST) Dcm_CfgSvc27SubFuncInfo[2]=
{
   { Dcm_Service27SeedProcessor,   5u} /* SF: 0x01 */                                                                                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ Dcm_Service27KeyProcessor, 133u} /* SF: 0x02 */                                                                                                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Service 0x27 security level properties table  */
CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[1]=
{
   { ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed)),Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey,   8u, 1u} /* SecLvl: DcmDspSecurityRow_Coding */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Indirection from service 0x27 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[2]=
{
     13u /* SF: 0x01 */
  ,  13u /* SF: 0x02 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[4]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x03 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[4]=
{
     14u /* SF: 0x00 */
  ,  14u /* SF: 0x01 */
  ,  14u /* SF: 0x02 */
  ,  14u /* SF: 0x03 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[1]=
{
   DCM_SVC_28_NETWORK_ALL
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      9u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
     14u /* SF: 0x01 */
  ,  14u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
/*! Service 0x86 sub-service properties table  */
CONST(Dcm_CfgSvc86SubFuncInfoType, DCM_CONST) Dcm_CfgSvc86SubFuncInfo[3]=
{
   { Dcm_ExtService86_04Processor, 2u} /* SF: 0x04 */
  ,{ Dcm_ExtService86_40Processor, 2u} /* SF: 0x40 */
  ,{ Dcm_ExtService86_45Processor, 2u} /* SF: 0x45 */
};
/*! Indirection from service 0x86 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc86SubFuncExecPrecondTable[3]=
{
     11u /* SF: 0x04 */
  ,  11u /* SF: 0x40 */
  ,  11u /* SF: 0x45 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module call-out implementations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_RidMgr_0202_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0202_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInRcCmIcvRcoStruct_In;

  dataInRcCmIcvRcoStruct_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                 /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_RcCm_Routine_Start(dataInRcCmIcvRcoStruct_In
                                                    , OpStatus
                                                    , Dcm_DiagGetResDataRel(pMsgContext, 0u)                                                         /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                    , ErrorCode
                                                    );                                                                                               /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0304_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0304_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInDTCType_In;

  dataInDTCType_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                          /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_DmClientTriggerDtcEntry_Routine_Start(dataInDTCType_In
                                                                       , OpStatus
                                                                       , Dcm_DiagGetResDataRel(pMsgContext, 0u)                                      /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                       , Dcm_DiagGetResDataRel(pMsgContext, 1u)                                      /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                       , Dcm_DiagGetResDataRel(pMsgContext, 2u)                                      /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                       , Dcm_DiagGetResDataRel(pMsgContext, 3u)                                      /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                       , ErrorCode
                                                                       );                                                                            /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0F0C_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0F0C_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataIndataIn_In;

  dataIndataIn_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_Energiesparmode_Routine_Start(dataIndataIn_In
                                                               , OpStatus
                                                               , ErrorCode
                                                               );                                                                                    /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_1003_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_1003_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataIndataIn_In;

  dataIndataIn_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_ControlExtendedEnergySavingState_Routine_Start(dataIndataIn_In
                                                                                , OpStatus
                                                                                , ErrorCode
                                                                                );                                                                   /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB56_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB56_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInFrequenz_In;
  uint8 dataInMaxAmplitude_In;
  uint8 dataInNumberOfCycles_In;

  dataInFrequenz_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                         /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInMaxAmplitude_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 1u)));                                                                     /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInNumberOfCycles_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 2u)));                                                                   /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_EpsPendeln_Routine_Start(dataInFrequenz_In
                                                          , dataInMaxAmplitude_In
                                                          , dataInNumberOfCycles_In
                                                          , OpStatus
                                                          , ErrorCode
                                                          );                                                                                         /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB6C_RequestResults()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB6C_RequestResults(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_EpsInitialisierungService_Routine_RequestResults(OpStatus
                                                                                  , Dcm_DiagGetResDataRel(pMsgContext, 0u)                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                                  , Dcm_DiagGetResDataRel(pMsgContext, 1u)                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                                  , Dcm_DiagGetResDataRel(pMsgContext, 3u)                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                                                  , ErrorCode
                                                                                  );                                                                 /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB71_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB71_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInWinkelgeschwindigkeit_In;
  uint8 dataInWinkelbeschleunigung_In;
  uint8 dataInAbsolutEin_In;

  dataInWinkelgeschwindigkeit_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 2u)));                                                            /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInWinkelbeschleunigung_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 3u)));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInAbsolutEin_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 4u)));                                                                       /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_EpsVerfahren_Routine_Start(Dcm_DiagGetReqDataRel(pMsgContext, 0u)                                                  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                            , dataInWinkelgeschwindigkeit_In
                                                            , dataInWinkelbeschleunigung_In
                                                            , dataInAbsolutEin_In
                                                            , OpStatus
                                                            , ErrorCode
                                                            );                                                                                       /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_AB72_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_AB72_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInWinkel_In;
  uint8 dataInWinkelgeschwindigkeit_In;
  uint8 dataInWinkelbeschleunigung_In;

  dataInWinkel_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                           /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInWinkelgeschwindigkeit_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 1u)));                                                            /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
  dataInWinkelbeschleunigung_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 2u)));                                                             /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Start(dataInWinkel_In
                                                                      , dataInWinkelgeschwindigkeit_In
                                                                      , dataInWinkelbeschleunigung_In
                                                                      , OpStatus
                                                                      , ErrorCode
                                                                      );                                                                             /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_FF00_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_FF00_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInRcEmIeRco_In;

  dataInRcEmIeRco_In = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)));                                                                        /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_RcEm_Routine_Start(dataInRcEmIeRco_In
                                                    , OpStatus
                                                    , Dcm_DiagGetResDataRel(pMsgContext, 0u)                                                         /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                                                    , ErrorCode
                                                    );                                                                                               /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ConfirmationStatusType status)
{
  DCM_IGNORE_UNREF_PARAM(status);                                                                                                                    /* PRQA S 3112 */ /* MD_Dcm_3112 */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  DCM_IGNORE_UNREF_PARAM(pDataContext);                                                                                                              /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);                                                                                                                 /* PRQA S 3112 */ /* MD_Dcm_3112 */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(void)
{
  /* nothing to do */
}
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Lcfg.c
 * ******************************************************************************************************************** */

