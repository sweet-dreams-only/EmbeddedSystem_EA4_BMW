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
/**        \file  Dcm_Ext.c
 *        \brief  Implementation of DCM extensions
 *
 *      \details  MICROSAR DCM based on AR 4.0.3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define DCM_EXT_SOURCE
/* ----------------------------------------------
 ~&&&   Includes
---------------------------------------------- */
                                                                                                                                                     /* PRQA S 0857, 0828 EOF */ /* MD_MSR_1.1_857, MD_MSR_1.1_828 */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#if (DCM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif /* (DCM_DEV_ERROR_REPORT == STD_ON) */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# include "NvM.h"
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#include "Dcm_Int.h"
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */
#if ((DCM_SW_MAJOR_VERSION !=  8u) || \
    (DCM_SW_MINOR_VERSION !=  6u) || \
    (DCM_SW_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm.h are inconsistent"
#endif
#if ((DCM_CBK_MAJOR_VERSION !=  8u) || \
    (DCM_CBK_MINOR_VERSION !=  6u) || \
    (DCM_CBK_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Cbk.h are inconsistent"
#endif
#if ((DCM_TYPES_MAJOR_VERSION !=  8u) || \
    (DCM_TYPES_MINOR_VERSION !=  6u) || \
    (DCM_TYPES_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Types.h are inconsistent"
#endif
#if ((DCM_INT_MAJOR_VERSION !=  8u) || \
    (DCM_INT_MINOR_VERSION !=  6u) || \
    (DCM_INT_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Int.h are inconsistent"
#endif
#if ((DCM_CORE_MAJOR_VERSION !=  8u) || \
    (DCM_CORE_MINOR_VERSION !=  6u) || \
    (DCM_CORE_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Core.h are inconsistent"
#endif
#if ((DCM_CORECBK_MAJOR_VERSION !=  8u) || \
    (DCM_CORECBK_MINOR_VERSION !=  6u) || \
    (DCM_CORECBK_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_CoreCbk.h are inconsistent"
#endif
#if ((DCM_CORETYPES_MAJOR_VERSION !=  8u) || \
    (DCM_CORETYPES_MINOR_VERSION !=  6u) || \
    (DCM_CORETYPES_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_CoreTypes.h are inconsistent"
#endif
#if ((DCM_COREINT_MAJOR_VERSION !=  8u) || \
    (DCM_COREINT_MINOR_VERSION !=  6u) || \
    (DCM_COREINT_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_CoreInt.h are inconsistent"
#endif
#if ((DCM_EXT_MAJOR_VERSION !=  8u) || \
    (DCM_EXT_MINOR_VERSION !=  6u) || \
    (DCM_EXT_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Ext.h are inconsistent"
#endif
#if ((DCM_EXTCBK_MAJOR_VERSION !=  8u) || \
    (DCM_EXTCBK_MINOR_VERSION !=  6u) || \
    (DCM_EXTCBK_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_ExtCbk.h are inconsistent"
#endif
#if ((DCM_EXTTYPES_MAJOR_VERSION !=  8u) || \
    (DCM_EXTTYPES_MINOR_VERSION !=  6u) || \
    (DCM_EXTTYPES_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_ExtTypes.h are inconsistent"
#endif
#if ((DCM_EXTINT_MAJOR_VERSION !=  8u) || \
    (DCM_EXTINT_MINOR_VERSION !=  6u) || \
    (DCM_EXTINT_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_ExtInt.h are inconsistent"
#endif
#if ((DCM_CFG_MAJOR_VERSION !=  8u) || \
    (DCM_CFG_MINOR_VERSION !=  6u) || \
    (DCM_CFG_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Cfg.h are inconsistent"
#endif
#if ((DCM_LCFG_MAJOR_VERSION !=  8u) || \
    (DCM_LCFG_MINOR_VERSION !=  6u) || \
    (DCM_LCFG_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_Lcfg.h are inconsistent"
#endif
#if ((DCM_PBCFG_MAJOR_VERSION !=  8u) || \
    (DCM_PBCFG_MINOR_VERSION !=  6u) || \
    (DCM_PBCFG_PATCH_VERSION !=  1u))
# error "Vendor specific version numbers of Dcm_Ext.c and Dcm_PBcfg.h are inconsistent"
#endif
#if (DCM_EXTENSION_ID != 0x0001016CUL)
# error "Mismatching OEMs between static and generated code"
#endif
/* ----------------------------------------------
 ~&&&   Switches
---------------------------------------------- */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# define DCM_EXT_INSTANCE_CONTEXT_ENABLED                            STD_ON
#else
# define DCM_EXT_INSTANCE_CONTEXT_ENABLED                            STD_OFF
#endif
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# define DCM_EXT_SVC_86_ROE_DID                                      ((uint16)0x1704u)
# define DCM_EXT_SVC_86_READ_TIMEOUT                                 ((Dcm_ExtSvc86RoeTimeoutType)10)

/* states of the Roe service handler */
# define DCM_EXT_SVC_86_STATE_ACTIVE                                 ((Dcm_ExtSvc86RoeStateType)DCM_ROE_AR_STATE_ACTIVE)
# define DCM_EXT_SVC_86_STATE_INACTIVE                               ((Dcm_ExtSvc86RoeStateType)DCM_ROE_AR_STATE_INACTIVE)
# define DCM_EXT_SVC_86_STATE_INIT                                   ((Dcm_ExtSvc86RoeStateType)0x10u)
# define DCM_EXT_SVC_86_STATE_WRITE_NVM_DATA                         ((Dcm_ExtSvc86RoeStateType)0x11u)

/* access to Roe context data */
# define Dcm_ExtSvc86HandlerState                                    (Dcm_ExtInstanceContext.Svc86.HandlerState)
# define Dcm_ExtSvc86ReadTimeout                                     (Dcm_ExtInstanceContext.Svc86.NvmReadTimeout)
# define Dcm_ExtSvc86NvMData                                         (Dcm_ExtInstanceContext.Svc86.NvmData)
# define Dcm_ExtSvc86NvMReadOpStatus                                 (Dcm_ExtInstanceContext.Svc86.NvmReadOpStatus)
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Function-like macros
---------------------------------------------- */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# define Dcm_ExtGetRepeaterContextSvc86()                            ((Dcm_ExtSvc86RepeaterContextPtrType)Dcm_RepeaterGetExtSvcContext(DCM_REPEATER_EXT_CNTXT_SVC86))
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Typedefs
---------------------------------------------- */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
typedef uint8 Dcm_ExtSvc86RoeTimeoutType;

struct DCM_EXTSVC86CONTEXTTYPE_TAG
{
  Dcm_ExtSvc86NvMDataType    NvmData;
  Dcm_ExtSvc86RoeStateType   HandlerState;         /* state of the internal RoE state machine */
  Dcm_ExtSvc86RoeTimeoutType NvmReadTimeout;       /* timeout counter to handle failed calls to NvM_ReadBlock block */
  Dcm_OpStatusType           NvmReadOpStatus;      /* current operation status during initialization for NvM reading */
};
typedef struct DCM_EXTSVC86CONTEXTTYPE_TAG Dcm_ExtSvc86ContextType;

# if (DCM_EXT_INSTANCE_CONTEXT_ENABLED == STD_ON)
struct DCM_EXTINSTANCECONTEXTTYPE_TAG
{
#  if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
  Dcm_ExtSvc86ContextType   Svc86;         /* state of the internal RoE state machine */
#  endif
};
typedef struct DCM_EXTINSTANCECONTEXTTYPE_TAG Dcm_ExtInstanceContextType;
# endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Module internal function declarations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
/**********************************************************************************************************************
 *  Dcm_ExtSvc86UpdateNvM()
 *********************************************************************************************************************/
/*! \brief          Updates the NvM with the RoE information.
 *  \details        -
 *  \param[in]      opStatus              Operation status
 *  \param[in]      extSvc86ContextPtr    The RoE context
 *  \param[out]     ErrorCode             The NRC
 *  \return         DCM_E_OK              Update of NvM is successful
 *  \return         DCM_E_NOT_OK          Send negative response
 *  \return         DCM_E_PENDING         Retry later
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CODE) Dcm_ExtSvc86UpdateNvM(Dcm_OpStatusType opStatus
                                                        ,Dcm_ExtSvc86ReadOnlyRepeaterContextPtrType extSvc86ContextPtr
                                                        ,Dcm_NegativeResponseCodePtrType ErrorCode);
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Uninitialized RAM of unspecified size
---------------------------------------------- */
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# if (DCM_EXT_INSTANCE_CONTEXT_ENABLED == STD_ON)
DCM_LOCAL VAR(Dcm_ExtInstanceContextType, DCM_VAR_NOINIT)  Dcm_ExtInstanceContext;
# endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
CONST(Dcm_ExtSvc86NvMDataType, DCM_CONST) dcmExtSvc86DefaultNvMData =
{
  DCM_ROE_AR_STATE_INACTIVE /* per default - deactivate RoE */
 ,0
 ,0
};
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module internal function implementations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
/**********************************************************************************************************************
 *  Dcm_ExtSvc86UpdateNvM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CODE) Dcm_ExtSvc86UpdateNvM(Dcm_OpStatusType opStatus
                                                        ,Dcm_ExtSvc86ReadOnlyRepeaterContextPtrType extSvc86ContextPtr
                                                        ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType lStdResult;

  lStdResult = Dcm_UtiNvMWrite(opStatus, &(extSvc86ContextPtr->NewNvmData), DCM_EXT_SVC_86_NVRAM_BLOCKID);

  if (lStdResult == E_OK)
  {
    /* NvM storage complete; RoE is now inactive/active - update working mirror data */
    Dcm_ExtSvc86HandlerState = extSvc86ContextPtr->NewNvmData.Activation;

    Dcm_UtiAssignStruct(Dcm_ExtSvc86NvMData, extSvc86ContextPtr->NewNvmData);
    /* notify event handler */
    Dcm_RoEOnEventStateChange( DCM_EXT_SVC_86_DARH_EVENTID, Dcm_ExtSvc86HandlerState);
    lStdResult = DCM_E_OK;
  }
  else if (lStdResult == DCM_E_PENDING)
  {
    /* just try later */
  }
  else /* E_NOT_OK */
  {
    /* NvM storage failed; Roe remains active/inactive */
    Dcm_ExtSvc86HandlerState = Dcm_ExtSvc86NvMData.Activation;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;                                                                                                         /* SBSW_DCM_PARAM_PTR_WRITE */
    lStdResult = DCM_E_NOT_OK;
  }

  return lStdResult;
}
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module API function implementations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
/**********************************************************************************************************************
 *  Dcm_TriggerOnEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent(uint8 RoeEventId)                                                                                  /* PRQA S 1330 */ /* MD_Dcm_RteSpecific_1330 */
{
  Std_ReturnType result = DCM_E_NOT_OK;
  uint8 lErrorId = DCM_E_NO_ERROR;

# if (DCM_DEV_ERROR_DETECT == STD_ON)                                                                                                                /* COV_DCM_REQUIRED_BY_SAFEBSW TX */
  if(Dcm_DebugIsModuleInitialized() == FALSE)
  {
    lErrorId = DCM_E_UNINIT;
  }
  else
  if(RoeEventId != DCM_EXT_SVC_86_DARH_EVENTID)
  {
    lErrorId = DCM_E_PARAM;
  }
  else
# endif
  {
    DCM_IGNORE_UNREF_PARAM(RoeEventId);                                                                                                              /* PRQA S 3112 */ /* MD_Dcm_3112 */
    /* check if DCM is able to process the request */
    if(Dcm_ExtSvc86HandlerState == DCM_EXT_SVC_86_STATE_ACTIVE)
    {
      Dcm_MsgItemType vReq[3] =
      {
         0x22u
        ,Dcm_UtiGetHiByte(DCM_EXT_SVC_86_ROE_DID)
        ,Dcm_UtiGetLoByte(DCM_EXT_SVC_86_ROE_DID)
      };

      result = Dcm_NetRxIndInternal(Dcm_ExtSvc86NvMData.RxPduId, vReq, 3u);
    }/* else - event triggered under invalid conditions */
  }

# if (DCM_DEV_ERROR_REPORT == STD_ON)
  if (lErrorId != DCM_E_NO_ERROR)
  {
    Dcm_DebugReportError(DCM_SID_TRIGGERONEVENT, lErrorId);
  }
# else
  DCM_IGNORE_UNREF_PARAM(lErrorId);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
# endif
  return result;
}
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module internal API function implementations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
/**********************************************************************************************************************
 *  Dcm_ExtService86Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_ExtService86Init(void)
{
  /* set state to initial; reading NvM in first task cycle */
  Dcm_ExtSvc86HandlerState = DCM_EXT_SVC_86_STATE_INIT;
  Dcm_ExtSvc86ReadTimeout  = DCM_EXT_SVC_86_READ_TIMEOUT;
  Dcm_ExtSvc86NvMReadOpStatus = DCM_INITIAL;

  /* set default values for NvM data */
  Dcm_UtiAssignStruct(Dcm_ExtSvc86NvMData, dcmExtSvc86DefaultNvMData);

  Dcm_TskSetEvent(DCM_TSK_ID_ROE, DCM_EXT_TSK_EV_ROE_ACTIVATE);
}
# if (DCM_EXT_TSK_NUM_ROE > 0)
/**********************************************************************************************************************
 *  Dcm_ExtSvc86Task()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_ExtSvc86Task(Dcm_TskTaskEvOptType ev
                                     ,Dcm_TskTaskEvPtrType pPostEv)
{
  Std_ReturnType        lStdResult;

#  if (DCM_TSK_EV_ROE_MSB != 0x01u)
#   error "New events have been added for Dcm_ExtSvc86Task! Make set event check here!"
#  endif

  DCM_IGNORE_UNREF_PARAM(ev);                                                                                                                        /* PRQA S 3112 */ /* MD_Dcm_3112 */

  Dcm_DebugAssert((Dcm_ExtSvc86HandlerState == DCM_EXT_SVC_86_STATE_INIT), DCM_SID_INTERNAL, DCM_E_ILLEGAL_STATE)

  /* get persistent data from NvM */
  lStdResult = Dcm_UtiNvMRead(Dcm_ExtSvc86NvMReadOpStatus, &Dcm_ExtSvc86NvMData, DCM_EXT_SVC_86_NVRAM_BLOCKID);

  if(lStdResult == DCM_E_OK)
  {
#  if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
    if(Dcm_ExtSvc86NvMData.Activation == DCM_EXT_SVC_86_STATE_ACTIVE)
    {
      Dcm_CfgVarMgrComVariantType pComVariant = Dcm_VarMgrGetActiveComVariant();

      if( (Dcm_ExtSvc86NvMData.RxPduId >= Dcm_NetCfgGetNumRxPduIds(pComVariant))
        ||(Dcm_NetCfgGetRxPduInfo(pComVariant)[Dcm_ExtSvc86NvMData.RxPduId].ConnRef >= Dcm_NetCfgGetNumConnections(pComVariant)) /* keep evaluation order to guard the connRef indirection */
        ||(Dcm_ExtSvc86NvMData.ClientSrcAddr != Dcm_NetCfgGetTesterAddressOfRxPduId(pComVariant, Dcm_ExtSvc86NvMData.RxPduId)) )
      {
        /* Restore default values */
        Dcm_UtiAssignStruct(Dcm_ExtSvc86NvMData, dcmExtSvc86DefaultNvMData);
      }
    }
#  endif
    /* reading data from NvM finished; change state according to stored activation state */
    Dcm_ExtSvc86HandlerState = Dcm_ExtSvc86NvMData.Activation;
    Dcm_RoEOnEventStateChange( DCM_EXT_SVC_86_DARH_EVENTID, Dcm_ExtSvc86NvMData.Activation );
  }
  else if(lStdResult == DCM_E_PENDING)
  {
    /* retry later */
    Dcm_TskSetLocalEvent(*pPostEv, DCM_EXT_TSK_EV_ROE_ACTIVATE);                                                                                     /* SBSW_DCM_PARAM_PTR_WRITE */
    Dcm_ExtSvc86NvMReadOpStatus = DCM_PENDING;
  }
  else  /* DCM_E_NOT_OK */
  {
    /* If NvM request was not accepted -> retry later until timeout. Once accepted (OpStatus == DCM_PENDING) would mean that the read access has failed -> close the job */
    if( (Dcm_ExtSvc86NvMReadOpStatus == DCM_INITIAL)
      &&(Dcm_ExtSvc86ReadTimeout > 0) )
    {
      /* timeout not yet reached; try again in next cycle */
      Dcm_ExtSvc86ReadTimeout--;
      Dcm_TskSetLocalEvent(*pPostEv, DCM_EXT_TSK_EV_ROE_ACTIVATE);                                                                                   /* SBSW_DCM_PARAM_PTR_WRITE */
     /* Start new cycle - leave opStatus = DCM_INITIAL
      * Dcm_ExtSvc86NvMReadOpStatus = DCM_INITIAL;
      */
    }
    else
    {
      /* read data from NvM failed; set to default */
      Dcm_UtiAssignStruct(Dcm_ExtSvc86NvMData, dcmExtSvc86DefaultNvMData);

      /* giving up to try reading from NvM; continue with default values that have been set in initialize function */
      Dcm_ExtSvc86HandlerState = Dcm_ExtSvc86NvMData.Activation;
      Dcm_RoEOnEventStateChange( DCM_EXT_SVC_86_DARH_EVENTID, Dcm_ExtSvc86NvMData.Activation );
    }
  }
}
# endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CODE
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
#if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                           /* COV_DCM_UNSUPPORTED XF */
# if (DCM_SVC_86_40_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ExtService86_40Processor()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ExtService86_40Processor(Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgContextPtrType pMsgContext
                                                                   ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType lStdResult;
  Dcm_ExtSvc86RepeaterContextPtrType svc86Context;

  DCM_IGNORE_UNREF_PARAM(opStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */

  svc86Context = Dcm_ExtGetRepeaterContextSvc86();
  if (Dcm_DiagGetReqDataAsU8(pMsgContext) == 0x02u) /* eventWindowTime */
  {
    switch (Dcm_ExtSvc86HandlerState)
    {
      case DCM_EXT_SVC_86_STATE_ACTIVE:
        Dcm_ExtSvc86HandlerState = DCM_EXT_SVC_86_STATE_WRITE_NVM_DATA;
        svc86Context->NewNvmData.Activation = DCM_ROE_AR_STATE_INACTIVE;
        /* Not important: Dcm_ExtSvc86NewNvMData.RxPduId = pMsgContext->rxPduid; */
        /* Not important: Dcm_ExtSvc86NewNvMData.ClientSrcAddr = Dcm_NetCfgGetTesterAddressOfRxPduId(pComVariant, pMsgContext->rxPduId); */
        /* fall through */
      case DCM_EXT_SVC_86_STATE_WRITE_NVM_DATA:                                                                                                      /* PRQA S 2003 */ /* MD_Dcm_Optimize_2003 */
        lStdResult = Dcm_ExtSvc86UpdateNvM(opStatus, svc86Context, ErrorCode);
        break;

      case DCM_EXT_SVC_86_STATE_INACTIVE:
        /* Roe is already stopped */
        lStdResult = DCM_E_OK;
        break;
      default:
        /* Sub-service can not be processed in the current state */
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;                                                                                                     /* SBSW_DCM_PARAM_PTR_WRITE */
        lStdResult = DCM_E_NOT_OK;
        break;
    }

    if (lStdResult == DCM_E_OK)
    {
      /* report response data */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x00);                                                                                                 /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x02);                                                                                                 /* SBSW_DCM_PARAM_PTR_FORWARD */
    }
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;                                                                                                            /* SBSW_DCM_PARAM_PTR_WRITE */
    lStdResult = DCM_E_NOT_OK;
  }
  return lStdResult;
}
# endif

# if (DCM_SVC_86_45_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ExtService86_45Processor()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ExtService86_45Processor(Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgContextPtrType pMsgContext
                                                                   ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType lStdResult;

  Dcm_ExtSvc86RepeaterContextPtrType svc86Context;
#  if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
  Dcm_CfgVarMgrComVariantType pComVariant = Dcm_VarMgrGetActiveComVariant();
#  endif

  DCM_IGNORE_UNREF_PARAM(opStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */

  svc86Context = Dcm_ExtGetRepeaterContextSvc86();
  if (Dcm_DiagGetReqDataAsU8(pMsgContext) == 0x02u) /* eventWindowTime */
  {
    switch (Dcm_ExtSvc86HandlerState)
    {
      case DCM_EXT_SVC_86_STATE_INACTIVE:
        Dcm_ExtSvc86HandlerState               = DCM_EXT_SVC_86_STATE_WRITE_NVM_DATA;
        svc86Context->NewNvmData.Activation    = DCM_ROE_AR_STATE_ACTIVE;
        svc86Context->NewNvmData.RxPduId       = pMsgContext->rxPduId;
        svc86Context->NewNvmData.ClientSrcAddr = Dcm_NetCfgGetTesterAddressOfRxPduId(pComVariant, pMsgContext->rxPduId);
        /* fall through */
      case DCM_EXT_SVC_86_STATE_WRITE_NVM_DATA:                                                                                                      /* PRQA S 2003 */ /* MD_Dcm_Optimize_2003 */
        lStdResult = Dcm_ExtSvc86UpdateNvM(opStatus, svc86Context, ErrorCode);
        break;

      case DCM_EXT_SVC_86_STATE_ACTIVE:
        /* Roe is already started... */
        if (Dcm_NetCfgGetRxPduInfo(pComVariant)[Dcm_ExtSvc86NvMData.RxPduId].ConnRef != Dcm_NetCfgGetRxPduInfo(pComVariant)[pMsgContext->rxPduId].ConnRef)
        {
          /* ... but request comes from a different tester */
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;                                                                                                   /* SBSW_DCM_PARAM_PTR_WRITE */
          lStdResult = DCM_E_NOT_OK;
        }
        else
        {
          lStdResult = DCM_E_OK;
        }

        break;
      default:
        /* Sub-service can not be processed in the current state */
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;                                                                                                     /* SBSW_DCM_PARAM_PTR_WRITE */
        lStdResult = DCM_E_NOT_OK;
        break;
    }

    if (lStdResult == DCM_E_OK)
    {
      /* report response data */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x00);                                                                                                 /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x02);                                                                                                 /* SBSW_DCM_PARAM_PTR_FORWARD */
    }
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;                                                                                                            /* SBSW_DCM_PARAM_PTR_WRITE */
    lStdResult = DCM_E_NOT_OK;
  }
  return lStdResult;
}
# endif

# if (DCM_SVC_86_43_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ExtService86_43Processor()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ExtService86_43Processor(Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgContextPtrType pMsgContext
                                                                   ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType       lStdResult = DCM_E_OK;
  uint8 evtWindowTime;
  uint8 sid;
  uint16 roeDid1;
  uint16 roeDid2;

  DCM_IGNORE_UNREF_PARAM(opStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */

  Dcm_DiagConsumeReqDataAsU8(pMsgContext, &evtWindowTime);                                                                                           /* SBSW_DCM_COMB_PARAM_PTR_FORWARD */
  Dcm_DiagConsumeReqDataAsU16(pMsgContext, &roeDid1);                                                                                                /* SBSW_DCM_COMB_PARAM_PTR_FORWARD */
  Dcm_DiagConsumeReqDataAsU8(pMsgContext, &sid);                                                                                                     /* SBSW_DCM_COMB_PARAM_PTR_FORWARD */
  Dcm_DiagConsumeReqDataAsU16(pMsgContext, &roeDid2);                                                                                                /* SBSW_DCM_COMB_PARAM_PTR_FORWARD */

  if ( (evtWindowTime == 0x02u) /* eventWindowTime */
     &&(roeDid1 == DCM_EXT_SVC_86_ROE_DID)
     &&(sid == 0x22u) /* only SID 0x22 is allowed */
     &&(roeDid2 == DCM_EXT_SVC_86_ROE_DID) )
  { /* positive response */
    Dcm_DiagProvideResDataAsU8(pMsgContext, 0x00u); /* numberOfIdentifiedEvents */                                                                   /* SBSW_DCM_PARAM_PTR_FORWARD */
    Dcm_DiagProvideResDataAsU8(pMsgContext, 0x02u); /* eventWindowTime */                                                                            /* SBSW_DCM_PARAM_PTR_FORWARD */
    Dcm_DiagProvideResDataAsU16(pMsgContext, DCM_EXT_SVC_86_ROE_DID);                                                                                /* SBSW_DCM_PARAM_PTR_FORWARD */
    Dcm_DiagProvideResDataAsU8(pMsgContext, 0x22u); /* only SID 0x22 is allowed */                                                                   /* SBSW_DCM_PARAM_PTR_FORWARD */
    Dcm_DiagProvideResDataAsU16(pMsgContext, DCM_EXT_SVC_86_ROE_DID);                                                                                /* SBSW_DCM_PARAM_PTR_FORWARD */
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;                                                                                                            /* SBSW_DCM_PARAM_PTR_WRITE */
    lStdResult = DCM_E_NOT_OK;
  }
  return lStdResult;
}
# endif

# if (DCM_SVC_86_04_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ExtService86_04Processor()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ExtService86_04Processor(Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgContextPtrType pMsgContext
                                                                   ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType       lStdResult = DCM_E_OK;
  DCM_IGNORE_UNREF_PARAM(opStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */

  if (Dcm_DiagGetReqDataAsU8(pMsgContext) == 0x02u) /* eventWindowTime */
  {
    /* positive response */
    if (Dcm_ExtSvc86HandlerState == DCM_EXT_SVC_86_STATE_ACTIVE)
    {
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x01u); /* numberOfActivatedEvents */                                                                  /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x43u); /* eventTypeOfActiveEvent */                                                                   /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x02u); /* eventWindowTime */                                                                          /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU16(pMsgContext, DCM_EXT_SVC_86_ROE_DID); /* eventTypeRecord (BMWAG: 2 bytes only) */                                  /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x22u); /* only SID 0x22 is allowed */                                                                 /* SBSW_DCM_PARAM_PTR_FORWARD */
      Dcm_DiagProvideResDataAsU16(pMsgContext, DCM_EXT_SVC_86_ROE_DID);                                                                              /* SBSW_DCM_PARAM_PTR_FORWARD */
    }
    else
    {
      Dcm_DiagProvideResDataAsU8(pMsgContext, 0x00u); /* numberOfActivatedEvents */                                                                  /* SBSW_DCM_PARAM_PTR_FORWARD */
    }
    /* Shared buffer - copy not needed.
    pMsgContext->resData[0] = pMsgContext->reqData[0];
    */
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;                                                                                                            /* SBSW_DCM_PARAM_PTR_WRITE */
    lStdResult = DCM_E_NOT_OK;
  }
  return lStdResult;
}
# endif
#endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*lint -restore */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Ext.c
 * ******************************************************************************************************************** */
