/**********************************************************************************************************************
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
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file     FrTp.c
 *      \brief    Source file of the FrTp main-module.
 *      \details  Source file containing the API functions of the main-module of the FrTp.
 *                Implements a FrTp according to ISO10681-2
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
 
#define FRTP_SOURCE
#define TP_ISO10681_SOURCE

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Common.h"
#include "FrTp_Cbk.h"
#include "FrTp.h"
#include "FrIf.h"
#if(FRTP_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if (FrTp_IsPostbuild()) 
# include "EcuM_Error.h"
#endif
#if (FRTP_RUNTIME_MEASUREMENT_SUPPORT == STD_ON) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
# include "Rtm.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_SW_MINOR_VERSION != (4u)) \
    || (FRTP_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp.c and FrTp_Cfg.h are inconsistent!"
#endif

/* Check the version of FrTp_Cbk header file */
#if (  (FRTP_CBK_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_CBK_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_CBK_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of FrTp.c and FrTp_Cbk.h are inconsistent"
#endif

/* Check the version of FrTp_XCfg header file */
#if (  (FRTP_XCFG_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_XCFG_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_XCFG_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of FrTp.c and FrTp_XCfg.h are inconsistent"
#endif

/* Check the version of the FrTp's submodules: */
#if (  (FRTP_RSRC_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_RSRC_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_RSRC_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_Rsrc are inconsistent"
#endif
#if (  (FRTP_FRIF_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_FRIF_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_FRIF_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_FrIf are inconsistent"
#endif
#if (  (FRTP_RXSM_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_RXSM_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_RXSM_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_RxSm are inconsistent"
#endif
#if (  (FRTP_TXSM_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_TXSM_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_TXSM_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_TxSm are inconsistent"
#endif
#if (  (FRTP_UTIL_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_UTIL_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_UTIL_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_Util are inconsistent"
#endif
#if (  (FRTP_COMMON_SW_MAJOR_VERSION != FRTP_SW_MAJOR_VERSION) \
    || (FRTP_COMMON_SW_MINOR_VERSION != FRTP_SW_MINOR_VERSION) \
    || (FRTP_COMMON_SW_PATCH_VERSION != FRTP_SW_PATCH_VERSION) )
# error "Vendor specific version numbers of module FrTp and submodule FrTp_Common are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/*!< Vendor and module ID */
#define FrTp_InternalModuleId    ((uint8)(36u))
#define FrTp_InternalVendorId    ((uint16)(30u))

/*!< Limits of different pdu-types */
#define FrTp_PayloadMaxLenOfSTForLF  ((uint8)(246u))
#define FrTp_PayloadMaxLenOfCF       ((uint8)(248u))
#define FrTp_FrFrameMaxLength        ((uint8)(254u))

/*!< FrTp-initialization */
#define FrTp_InitSm_Uninitialized ((uint8)0u) /*!< \trace FrTp_InitSm_Uninitialized */
#define FrTp_InitSm_Initialized   ((uint8)1u) /*!< \trace FrTp_InitSm_Initialized */
#define FrTp_InitSm_Shutdown      ((uint8)2u) /*!< \trace FrTp_InitSm_Shutdown */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/*!< The macros [FrTp_Rtm_Start|FrTp_Rtm_Stop] indicate the [start|end] of the "FrTp_"-API-functions to the optional RTM module: */
#if (FRTP_RUNTIME_MEASUREMENT_SUPPORT == STD_ON) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
/* In case FRTP_RUNTIME_MEASUREMENT_SUPPORT is STD_ON then the RTM module is "active" from the view of the FrTp and thus the Rtm-functions are actually called: */
# define FrTp_Rtm_Start(measurement) Rtm_Start(RtmConf_RtmMeasurementPoint_##measurement) /* PRQA S 0342 */ /* MD_FrTp_0342 */
# define FrTp_Rtm_Stop(measurement)  Rtm_Stop(RtmConf_RtmMeasurementPoint_##measurement)  /* PRQA S 0342 */ /* MD_FrTp_0342 */
#else
/*!< In case FRTP_RUNTIME_MEASUREMENT_SUPPORT is STD_OFF then the from the view of the FrTp the RTM module is "not active" and thus the Rtm-functions are not called: */
# define FrTp_Rtm_Start(measurement)
# define FrTp_Rtm_Stop(measurement)
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define FRTP_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/*!< Legacy: Requirement Specification Template version */
CONST(uint8, FRTP_CONST) FrTp_MainVersion    = TP_ISO10681_SW_MAJOR_VERSION;
CONST(uint8, FRTP_CONST) FrTp_SubVersion     = TP_ISO10681_SW_MINOR_VERSION;
CONST(uint8, FRTP_CONST) FrTp_ReleaseVersion = TP_ISO10681_SW_PATCH_VERSION;

#define FRTP_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FRTP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FrTp_Transmit()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_Transmit(
  PduIdType FrTpTxSduId,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxSduInfoPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTP_E_NO_ERROR;
  uint8 txSmIdx;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if(FrTpTxSduInfoPtr == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else if(FrTpTxSduId >= FrTp_CCfg_MaxTxSduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else
#endif
  {  
    /* ----- Local Variables ---------------------------------------------- */
    PduLengthType requestedTxLen = FrTpTxSduInfoPtr->SduLength;

    /* ----- Implementation ----------------------------------------------- */ 
    /* #10 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrTpTxSduId = *(FrTp_CCfg_TxSduSnv2ConnIdx(FrTpTxSduId));
    /* #11 Given the FrTpConnection has NOT configured a FrTpTxSdu
     *            Then reject the request
     *            And issue the DET-error FRTP_E_INVALID_PDU_SDU_ID
     *            Else process the transmit-request */
    if(FrTpTxSduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
    else if(requestedTxLen == 0u)
    {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_UMSG_LENGTH_ERROR;
#endif
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */ 
      /* #20 FrTp_Transmit requires the determination of free tx-state-machine-resources to make a proper decision whether a
       *              transmission may be accepted or not. The TP-channels are also occupied in the context of e.g.
       *              FrTp_RxIndication which may be called in interrupt context, also.
       *              Hence the search for a free channel is protected by FRTP_EXCLUSIVE_AREA_0
       *              Enter FRTP_EXCLUSIVE_AREA_0
       *              Retrieve the index of the tx-state-machine the connection is currently active in */
      FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      txSmIdx = FrTp_VCfg_ConnState(FrTpTxSduId)->CurrTxSmIdx;
      /* #30 In case the connection is not active prepare activating it by finding a free state-machine
       *              Otherwise the connection is active, already: Prepare exiting with E_NOT_OK */
      if(txSmIdx == FrTp_NoSm)
      {
        txSmIdx = FrTp_Rsrc_FindTxSm();
      }
      else
      {
        if(FrTp_TxSm_Idle != FrTp_VCfg_TxState(txSmIdx)->State)
        {
          txSmIdx = FrTp_NoSm;
        }
      }

      /* #40 In case the requestedTxLen is non-zero
       *              and a free state-machine has been found and the connection is also not active transmitting at the moment
       *              and the requestedTxLen is in the allowed range */
      if(    (txSmIdx != FrTp_NoSm)
          && (FrTp_MaxTransferLenSegm >= requestedTxLen) /* PRQA S 3355 */ /* MD_FrTp_3355 */
        )
      {
        P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_CCfg_ConnCfg(FrTpTxSduId);
        uint8 poolOffset = FrTp_ConnGetTxPoolOffset(pConnCfg);
        P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByCheckedOffset(poolOffset);
        P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pPoolDataUsed = FrTp_FrIf_GetTxPduPoolDataPtrByCheckedOffset(poolOffset);

        /* #50 In case a pPoolCfg is available for the given connection
         *                and pPoolDataUsed is available
         *                and a valid tx-sdu is configured for the given connection */
        if(    (pPoolCfg != NULL_PTR) 
            && (pPoolDataUsed != NULL_PTR)
            && (pConnCfg->FrTpSduTxId != FRTP_INVALID_SNV) /* PRQA S 3355 */ /* MD_FrTp_3355 */
          )
        {
          /* #60 In case the transfer shall be done on a 'functional' connection:
           *                  Check whether the given ML fits into the min. length of the pdus of the tx-pdu-pool.
           *                  If yes: Indicate that the transfer will be started */
          if(pConnCfg->MultRec == TRUE)
          {
            if(FrTp_CalcPduPayloadLen(pPoolCfg->MinPduLen, FrTp_PCISTFunseg) >= requestedTxLen)
            {
              FrTp_Rsrc_AllocateTxSm(pConnCfg, requestedTxLen, FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeCs), txSmIdx); /* SBSW_FRTP_ALLOCATE_RXTX_SM */
              retVal = E_OK;
            }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
            /* #69 In case the transfer was rejected and it is a 1:n connection and DET is active: Issue a DET-error */
            else
            {
              errorId = FRTP_E_SEG_ERROR;
            }
#endif
          }
          else
          {
            /* #70 Otherwise it is 'physical' connection and the relation of ML and pdu-length is not relevant:
             *                    Indicate that the transfer will be started */
            FrTp_Rsrc_AllocateTxSm(pConnCfg, requestedTxLen, FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeCs), txSmIdx); /* SBSW_FRTP_ALLOCATE_RXTX_SM */
            retVal = E_OK;
          }
        }
      }
      /* #90 Leave FRTP_EXCLUSIVE_AREA_0 */
      FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_Transmit_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  /* #100 Indicate acceptance status of the request to the caller */
  return retVal;
} /* FrTp_Transmit */ /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  FrTp_MainFunction()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 3408 3 */ /* MD_FrTp_3408 */
FUNC(void, FRTP_CODE) FrTp_MainFunction(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Development Error Checks ------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */  
  /* #10 Indicate the start of the FrTp_MainFunction() to the optional RTM module: */
  FrTp_Rtm_Start(FrTp_MainFunction); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(*FrTp_LCfg_InitState() == FrTp_InitSm_Initialized)
  {
    /* #20 Inform the tx-pdu-pools about the tx-confirmations that have come in since the last call to FrTp_MainFunction() */
    FrTp_FrIf_ProcessTxConfirmations();

    /* #30 Rx-operation is done prior to Tx-operation in order to reserve "the one" Tx-Pdu that is required to send
     *     one(1!) FC-pdu and then leave "the rest" of the Tx-Pdu-Pool to the Tx-connections */
    FrTp_RxSm_OperateAllSms();
    /* #40 Now use the remaining Tx-Pdus for Tx-operation (In case Tx-operation gets "no Tx-Pdu" in a particular cycle
     *     then this is not a problem because TimeoutCr is usually >1 FR-cycle! */
    FrTp_TxSm_OperateAllSms();
  }
  /* #50 In case the FrTp is not initialized NO DET-ERRORS are issued because for Multi-Identity-Ecus it is required
   *          to call FrTp_MainFunction() in case in the current Identity FrTp-services are not used */

  /* #60 Indicate the end of the FrTp_MainFunction() to the optional RTM module: */
  FrTp_Rtm_Stop(FrTp_MainFunction); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_MainFunction */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 * FrTp_Init()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_Init(
  P2CONST(FrTp_ConfigType, AUTOMATIC, FRTP_INIT_DATA) CfgPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
#if (FRTP_CONFIGURATION_VARIANT == 3)
  uint8 ecumErrorId = ECUM_NO_BSWERROR;
#endif
  uint8 errorId = FRTP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if (CfgPtr == NULL_PTR)
  {
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    errorId = FRTP_E_NULL_PTR;
#endif
#if (FRTP_CONFIGURATION_VARIANT == 3)
    ecumErrorId = ECUM_BSWERROR_NULLPTR;
  }
  else if (CfgPtr->GeneratorCompatibilityVersion != (uint16) FRTP_GENERATOR_COMPATIBILITY_VERSION)
  {
    ecumErrorId = ECUM_BSWERROR_COMPATIBILITYVERSION;
  }
  else if (CfgPtr->FinalMagicNumber != FRTP_FINAL_MAGICNUMBER)
  {
    ecumErrorId = ECUM_BSWERROR_MAGICNUMBER;
#endif
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set the initialization state to 'un-initialized'
     *            For all postbuild-variants: Store the given pointer
     *            For variants linktime or precompile: Do not store the given pointer */
    *FrTp_LCfg_InitState() = FrTp_InitSm_Uninitialized; /* SBSW_FRTP_LCFG_ACCESS */
#if (FrTp_IsPostbuild())
    *FrTp_LCfg_CfgPtr() = CfgPtr; /* SBSW_FRTP_LCFG_ACCESS */
#endif
    /* #20 Enter FRTP_EXCLUSIVE_AREA_0
     *            Initialize all state-machines without giving a notification to the PduR */
    FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    FrTp_Rsrc_InitAllSms();

    /* #30 Initialize the admin data of the FrIf-tx-pdus and tx-pdu-pools used by FrTp
     *            Initialize connection-specific runtime-values for all connections */
    FrTp_FrIf_Init();
    FrTp_Rsrc_InitAllConns();

    /* #40 Initialize the current round robin state-machine and the max. number of iterations in the main loop */
    *FrTp_LCfg_RxCurrRoundRobChan() = 0u; /* SBSW_FRTP_LCFG_ACCESS */
    *FrTp_LCfg_TxCurrRoundRobChan() = 0u; /* SBSW_FRTP_LCFG_ACCESS */
    *FrTp_LCfg_RxSm_MaxIterations() = FrTp_CCfg_NumRxChan() * (FrTp_IterationsPerPdu + 1u); /* SBSW_FRTP_LCFG_ACCESS */
    *FrTp_LCfg_TxSm_MaxIterations() = FrTp_CCfg_NumTxChan() * (FrTp_IterationsPerPdu + 1u) * FrTp_CCfg_NumFrIfTxPdus(); /* SBSW_FRTP_LCFG_ACCESS */

    /* #50 Set the initialization state to 'initialized' */
    *FrTp_LCfg_InitState() = FrTp_InitSm_Initialized; /* SBSW_FRTP_LCFG_ACCESS */

    /* #60 Leave FRTP_EXCLUSIVE_AREA_0 */
    FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_CONFIGURATION_VARIANT == 3)
  if (ecumErrorId != ECUM_NO_BSWERROR)
  {
    EcuM_BswErrorHook((uint16) FRTP_MODULE_ID, ecumErrorId);
  }
#else
  FRTP_DUMMY_STATEMENT(CfgPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, 0, FrTp_Init_ServiceId, errorId);
  }
#else
    FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* FrTp_Init */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

 /***********************************************************************************************************************
 * FrTp_Shutdown()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_Shutdown(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set status to shutdown */
    *FrTp_LCfg_InitState() = FrTp_InitSm_Shutdown; /* SBSW_FRTP_LCFG_ACCESS */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_Shutdown_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* FrTp_Shutdown */

#if (FRTP_HAVE_TC == STD_ON)
/***********************************************************************************************************************
 * FrTp_CancelTransmit()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_CancelTransmit(
  PduIdType FrTpTxSduId
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if(FrTpTxSduId >= FrTp_CCfg_MaxTxSduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrTpTxSduId = *(FrTp_CCfg_TxSduSnv2ConnIdx(FrTpTxSduId));
    if(FrTpTxSduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      uint8 txSmIdx;
      /* #30 Enter FRTP_EXCLUSIVE_AREA_0 */
      FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #40 Lookup the index of the current state-machine of the SduId */
      txSmIdx = FrTp_VCfg_ConnState(FrTpTxSduId)->CurrTxSmIdx;

      /* #50 In case the index of the tx-state-machine is valid
       *              Retrieve pointer to tx-state-machine */
      if(txSmIdx != FrTp_NoSm)
      {
        pTxSm = FrTp_VCfg_TxState(txSmIdx);

        /* #60 In case cancellation is allowed:
         *                Terminate transmission with error.
         *                Indicate acceptance of the request to the caller */
        if(    (FrTp_TxSm_Item(pTxSm, CurrPCI) > FrTp_PCISTFunseg)
            && (FrTp_TxSm_Item(pTxSm, DataIndex) < FrTp_TxSm_Item(pTxSm, DataLength))
          )
        {
          FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
          retVal = E_OK;
        }
      }
      /* #70 Leave FRTP_EXCLUSIVE_AREA_0 */
      FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_CancelTransmit_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* FrTp_CancelTransmit */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif
/* (FRTP_HAVE_TC == STD_ON) */

#if (FRTP_HAVE_RC == STD_ON)
/***********************************************************************************************************************
 * FrTp_CancelReceive()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_CancelReceive(
  PduIdType FrTpRxSduId
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if (FrTpRxSduId >= FrTp_CCfg_MaxRxSduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrTpRxSduId = *(FrTp_CCfg_RxSduSnv2ConnIdx(FrTpRxSduId));
    if(FrTpRxSduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      uint8 rxSmIdx;
      /* #30 Enter FRTP_EXCLUSIVE_AREA_0 */
      FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #40 Lookup the index of the current state-machine of the SduId */
      rxSmIdx = FrTp_VCfg_ConnState(FrTpRxSduId)->CurrRxSmIdx;

      /* #50 In case the index of the rx-state-machine is valid
       *            Retrieve pointer to rx-state-machine */
      if(rxSmIdx != FrTp_NoSm)
      {
        pRxSm = FrTp_VCfg_RxState(rxSmIdx);

        /* #60 In case the CurrPCI is not unsegmented:
         *              And the DataIndex has not yet reached DataLength.
         *              And the upper layer has already been informed about the start of reception.
         *              Terminate the reception with error.
         *              Indicate acceptance of the request to the caller */
        if(    (FrTp_RxSm_Item(pRxSm, CurrPCI) > FrTp_PCISTFunseg)
            && (FrTp_RxSm_Item(pRxSm, DataIndex) < FrTp_RxSm_Item(pRxSm, DataLength))
            && (((uint8_least)FrTp_RxSm_Item(pRxSm, RxStartedAtUpperLayer)) == TRUE)
          )
        {
          FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
          retVal = E_OK;
        }
      }
      /* #70 Leave FRTP_EXCLUSIVE_AREA_0 */
      FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
# if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_CancelReceive_ServiceId, errorId);
  }
# else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
} /* FrTp_CancelReceive */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif
/* (FRTP_HAVE_RC == STD_ON) */

/***********************************************************************************************************************
 * FrTp_ChangeParameter()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_ChangeParameter(
  PduIdType FrTpRxSduId,
  TPParameterType FrTpParameterType,
  uint16 FrTpParameterValue
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if (FrTpRxSduId > FrTp_CCfg_MaxRxSduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else if (FrTpParameterType != TP_BC)
  {
    errorId = FRTP_WRONG_PARAM_VAL;
  }
  else
#else
  FRTP_DUMMY_STATEMENT(FrTpParameterType); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrTpRxSduId = *(FrTp_CCfg_RxSduSnv2ConnIdx(FrTpRxSduId));
    if(FrTpRxSduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
    else
    {
      /*! It is assumed that the generated data in the map used above contains either:
          a) a valid internal FrTp-item index or
          b) FRTP_INVALID_SNV which is checked, above, too.
          Thus there is no additional DET check on the generated data required, here:
      FrTp_CheckDetErrorReturnValue(FrTpRxSduId < FrTp_CCfg_NumConn(),
                                    FrTp_ChangeParameter_ServiceId, 
                                    FRTP_E_INVALID_PDU_SDU_ID, retVal) */
      /* #20 Enter FRTP_EXCLUSIVE_AREA_0 */
      FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #30 In case there is no reception active on the given FrTpRxSduId.
       *              And the given parameter value is roughly valid:
       *              Accept the new value in case it does will not lead to a violation of FrTpTimeoutCr */
      if(    (FrTp_VCfg_ConnState(FrTpRxSduId)->CurrRxSmIdx == FrTp_NoSm)
          && (FrTpParameterValue <= 0xff)
        )
      {
        if(    FrTp_TxSm_GetSepCyclesFor[(((uint8)(FrTpParameterValue)) & FrTp_SCexpMask)]
            <= FrTp_GetConnCtrlItem((FrTp_CCfg_ConnCfg(FrTpRxSduId)->ConnCtrlPtr), TimeoutCr)
          )
        {
          FrTp_VCfg_ConnState(FrTpRxSduId)->CurrBC = (uint8)(FrTpParameterValue); /* SBSW_FRTP_CONN_STATE_WRT */
          retVal = E_OK;
        }
      }
      /* #40 Leave FRTP_EXCLUSIVE_AREA_0 */
      FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_ChangeParameter_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif  
  return retVal;
} /* FrTp_ChangeParameter */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 * FrTp_RxIndication()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_FrTp_3673 */
FUNC(void, FRTP_CODE) FrTp_RxIndication(
  PduIdType FrIfRxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTP_E_NO_ERROR;

  /* #10 Indicate the start of the FrTp_RxIndication() to the optional RTM module: */
  FrTp_Rtm_Start(FrTp_RxIndication); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if (FrIf_PduInfoPtr == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else if (FrIf_PduInfoPtr->SduDataPtr == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else if (FrIfRxPduId >= FrTp_CCfg_MaxFrIfRxPduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else if (FrIf_PduInfoPtr->SduLength == 0u)
  {
    errorId = FRTP_WRONG_PARAM_VAL;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrIfRxPduId = FrTp_CCfg_RxPduSnv2RxPduIdx(FrIfRxPduId);
    if(FrIfRxPduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
    else if(    (FrIf_PduInfoPtr->SduLength > FrTp_CCfg_FrIfRxPdus(FrIfRxPduId)->Length)
             || (FrIf_PduInfoPtr->SduLength <= FrTp_Util_OffsetTPCI) /* SBWS_FRTP_MINIMUM_TP_PDU_LENGTH */
           )
    {
      errorId = FRTP_WRONG_PARAM_VAL;
    }
#endif
    else
    {
      PduIdType connIdx;
      /* #30 Extract TA and SA from the Pdu */
      uint16 TA = FrTp_Util_ReadTA(FrIf_PduInfoPtr->SduDataPtr);
      uint16 SA = FrTp_Util_ReadSA(FrIf_PduInfoPtr->SduDataPtr);
      /* #40 Loop all connections that reference the rx-pdu that has come in.
       *              For each of the connections of the rx-pdu-specific (reduced) set of connections:
       *              retrieve its index in the global connection configuration array,
       *              access the connections global configuration struct and
       *              compare TA and SA to the TA and SA of the pdu received and if equal:
       *              Call internal handler for the Rx-indication
       *              Exit the for-loop */
      for(connIdx = 0u; connIdx < FrTp_CCfg_FrIfRxPdus(FrIfRxPduId)->NumConns; connIdx++)
      {
        PduIdType tpConn = FrTp_CCfg_FrIfRxPdus(FrIfRxPduId)->ConnOffsetsPtr[connIdx];
        if(    (FrTp_CCfg_ConnCfg(tpConn)->LocalAddress == TA)
            && (FrTp_CCfg_ConnCfg(tpConn)->RemoteAddress == SA)
          )
        {
          FrTp_FrIf_RxIndication(
            FrIf_PduInfoPtr,
            FrIfRxPduId,
            tpConn
          ); /* SBSW_FRTP_FRIF_RX_INDICATION */
          break;
        }
      }
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_RxIndication_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  /* #50 Indicate the end of the FrTp_RxIndication() to the optional RTM module: */
  FrTp_Rtm_Stop(FrTp_RxIndication); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_RxIndication */ /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  FrTp_TxConfirmation()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_TxConfirmation(
  PduIdType FrIfTxPduId
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTP_E_NO_ERROR;

  /* #10 Indicate the start of the FrTp_TxConfirmation() to the optional RTM module: */
  FrTp_Rtm_Start(FrTp_TxConfirmation); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if (FrIfTxPduId >= FrTp_CCfg_MaxFrIfTxPduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #11 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrIfTxPduId = FrTp_CCfg_TxPduSnv2TxPduIdx(FrIfTxPduId);
    if(FrIfTxPduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
#endif
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      uint8 smIdx = FrTp_FrIf_GetSmIdxOfExpectedTxConfOfTxPdu(FrIfTxPduId);

      /* #20 In case a Tx-Confirmation is pending for this channel */
      if(FrTp_NoSm != smIdx)
      {
        /* #30 Enter FRTP_EXCLUSIVE_AREA_0 */
        FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* #40 In case a tx-confirmation is pending for a Tx-operation:
         *                Retrieve pointer to tx-state-machine
         *                Reset the pending flag of the FrIfTxPdu that has been tx-confirmed
         *                Decrease PendingTxConfs */
        if(FrTp_FrIf_IsTxConfExpectedForTxSmUsingTxPdu(FrIfTxPduId))
        {
          smIdx = FrTp_FrIf_GetTxSmIdxOfExpectedTxConfOfTxPdu(FrIfTxPduId);
          /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
          if(smIdx >= FrTp_CCfg_NumTxChan())
          {
            errorId = FRTP_WRONG_PARAM_VAL;
          }
          else
#endif
          /* #50 In case a valid txSmIdx can be found for the tx-pdu that was tx-confirmed:
           *                  Actually process the tx-confirmation for the tx-state-machine */
          {
            FrTp_FrIf_TxConfirmationForTxSmUsingTxPdu(FrIfTxPduId); /* SBSW_FRTP_RXTX_FRIF_PENDING_WRT */
            FrTp_TxSm_FrIfTxConfirmation(smIdx);
            FrTp_FrIf_IncreaseNumTxConfOverlapped((uint8_least)FrIfTxPduId);
          }
        }
        else
        /* #51 Otherwise it is the tx-confirmation of a tx-pdu used by a rx-state-machine (FC)
         *                 Reset the pending flag of the FrIfTxPdu that has been tx-confirmed
         *                 Inform all affected channels of the TxConfirmation
         *                 Inform all affected pools of the TxConfirmation */
        {
          smIdx = FrTp_FrIf_GetRxSmIdxOfExpectedTxConfOfTxPdu(FrIfTxPduId);
          /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
          if(smIdx >= FrTp_CCfg_NumRxChan())
          {
            errorId = FRTP_WRONG_PARAM_VAL;
          }
          else
#endif
          /* #61 In case a valid rxSmIdx can be found for the tx-pdu that was tx-confirmed:
           *                  Actually process the tx-confirmation for the rx-state-machine */
          {
            FrTp_FrIf_TxConfirmationForRxSmUsingTxPdu(FrIfTxPduId); /* SBSW_FRTP_RXTX_FRIF_PENDING_WRT */
            FrTp_RxSm_FrIfTxConfirmation(smIdx);
            FrTp_FrIf_IncreaseNumTxConfOverlapped((uint8_least)FrIfTxPduId);
          }
        }
        /* #60 Leave FRTP_EXCLUSIVE_AREA_0 */
        FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_TxConfirmation_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  /* #70 Indicate the end of the FrTp_TxConfirmation() to the optional RTM module: */
  FrTp_Rtm_Stop(FrTp_TxConfirmation); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_TxConfirmation */ /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  FrTp_TriggerTransmit()
 *********************************************************************************************************************/
 /*!
  *
  * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
  */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_TriggerTransmit(
  PduIdType FrIfTxPduId, 
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTP_E_NO_ERROR;
  
  /* #10 Indicate the start of the FrTp_TriggerTransmit() to the optional RTM module: */
  FrTp_Rtm_Start(FrTp_TriggerTransmit); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(*FrTp_LCfg_InitState() != FrTp_InitSm_Initialized)
  {
    errorId = FRTP_E_NOT_INIT;
  }
  else if (FrTpTxPduInfoPtr == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else if (FrIfTxPduId >= FrTp_CCfg_MaxFrIfTxPduId())
  {
    errorId = FRTP_E_INVALID_PDU_SDU_ID;
  }
  else if (FrTpTxPduInfoPtr->SduDataPtr == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else
#endif
  {
    /* ----- Development Error Checks ------------------------------------- */
    /* #20 Map the FrTp[Rx|Tx][Pdu|Sdu]Id provided by the caller to the internal FrTp-item-index */
    FrIfTxPduId = FrTp_CCfg_TxPduSnv2TxPduIdx(FrIfTxPduId);
    if(FrIfTxPduId == FRTP_INVALID_SNV) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      errorId = FRTP_E_INVALID_PDU_SDU_ID;
    }
    else if (FrTpTxPduInfoPtr->SduLength > FrTp_CCfg_FrIfTxPdus(FrIfTxPduId)->Length)
    {
      errorId = FRTP_WRONG_PARAM_VAL;
    }
    else
    {
      /* ----- Development Error Checks ------------------------------------- */
      /* #30 In case the tx-pdu triggered is 'decoupled' */
      if(!FrTp_FrIf_IsDecoupPdu(*FrTp_CCfg_FrIfTxPdus(FrIfTxPduId))) /* PRQA S 3355, 3356, 3358 */ /* MD_FrTp_3355, MD_FrTp_3356, MD_FrTp_3358 */ /* SBSW_FRTP_TRIGGER_ONLY_DECOUPLED_PDUS */
      {
        errorId = FRTP_WRONG_PARAM_VAL;
      }
      else
      { /* PRQA S 3201 */ /* MD_FrTp_3201 */
        /* ----- Implementation ----------------------------------------------- */
        /* #40 Enter FRTP_EXCLUSIVE_AREA_0
         *                Prepare the pdu-info of the PCI in order to call the pdu-assembly function, later on */
        FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        if(FrTp_FrIf_IsTxConfExpectedForTxSmUsingTxPdu(FrIfTxPduId) != FALSE) /* SBSW_FRTP_TRIGGER_ONLY_TRANSMITTED_PDUS */
        {
          retVal = FrTp_TxSm_TriggerTransmit(FrTpTxPduInfoPtr, FrIfTxPduId, &errorId); /* SBSW_FRTP_TRIGGER_TRANSMIT */
        }
        if(FrTp_FrIf_IsTxConfExpectedForRxSmUsingTxPdu(FrIfTxPduId) != FALSE) /* SBSW_FRTP_TRIGGER_ONLY_TRANSMITTED_PDUS */
        {
          retVal = FrTp_RxSm_TriggerTransmit(FrTpTxPduInfoPtr, FrIfTxPduId); /* SBSW_FRTP_TRIGGER_TRANSMIT */
        }
        /* #50 Leave FRTP_EXCLUSIVE_AREA_0 */
        FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR) /* PRQA S 3355, 3358 */ /* MD_FrTp_3355, MD_FrTp_3358 */
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_TriggerTransmit_ServiceId, errorId);
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* #60 Indicate the end of the FrTp_TriggerTransmit() to the optional RTM module: */
  FrTp_Rtm_Stop(FrTp_TriggerTransmit); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;
} /* FrTp_TriggerTransmit */ /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STMIF, MD_MSR_STCYC */

#if(FRTP_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  FrTp_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FRTP_APPL_DATA) pVersionInfo
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTP_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (pVersionInfo == NULL_PTR)
  {
    errorId = FRTP_E_NULL_PTR;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Store the module and version information in the given VersionInfo-struct: */
    pVersionInfo->moduleID = FRTP_MODULE_ID; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
    pVersionInfo->sw_major_version = FRTP_SW_MAJOR_VERSION; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
    pVersionInfo->sw_minor_version = FRTP_SW_MINOR_VERSION; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
    pVersionInfo->sw_patch_version = FRTP_SW_PATCH_VERSION; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
    pVersionInfo->vendorID = FRTP_VENDOR_ID; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_GetVersionInfo_ServiceId, errorId);
  }
# else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* FrTp_GetVersionInfo */
#endif

/***********************************************************************************************************************
 FrTp_InitMemory()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_InitMemory(void)
{
  /* #10 Initialize the initialization status */
  *FrTp_LCfg_InitState() = FrTp_InitSm_Uninitialized; /* SBSW_FRTP_LCFG_ACCESS */
} /* FrTp_InitMemory */

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* Justification for module-specific MISRA deviations:

 MD_FrTp_0310:    Casting to different object pointer type / A cast should not be performed between a pointer to object
                  type and a different pointer to object type.
      Reason:     In file FrTp_FrIf.c for platform V850 all FrTp-internal buffers have to be 16-bit aligned. However
                  the AUTOSAR-type PduInfoType only offers a DataPtr of type uint8*. Thus this cast is required.
      Risk:       There is no risk because the start address of an array is the same, no matter if it is of type uint8 or uint16.
      Prevention: Covered by code review.

 MD_FrTp_0342:    Deliberate violation of rule: The glue operator ## will not be recognized by a K&R compiler.
      Reason:     The glue operator is required to implement the AUTOSAR configuration variant concept.
      Risk:       There is no risk because the ## operator is only used at 2 locations for Rtm-appliance.
                  The Rtm-appliance is based on a MICROSAR wide, unique and tested concept.
      Prevention: Covered by code review.

  MD_FrTp_0781:   '-identifier-' is being used as a structure/union member as well as being a label, tag or ordinary identifier.
      Reason:     The AUTOSAR-concept to support multiple configuration-variants implements configuration access via preprocessor macros.
                  Depending on the configuration variant and the configuration item's type an item might be a preprocessor or linktime
                  constant or a member of a postbuild-configuration struct.
                  To maintain a readable implementation these 3 scenarios are encapulated by config-access macros that take the item's unique identifier name,
                  independent of where the definition of the item is actually located (preprocessor- or linktime-constant or postbuild-struct).
      Risk:       There is no risk because there is only one config-variant active at a time. Thus two identifiers of the same name are never defined at the same time.
      Prevention: Covered by code review.

  MD_FrTp_3201:   Deliberate violation of rule: This statement is unreachable
      Reason:     This statement might occur at statements of the following type:
                  if(FRTP_INVALID_SNV == <Internal FrTp Rx or Tx-Sdu- or Pdu-Id>): This is an PRQA analysis error
                  This code-pattern is required to implement the SNV-concept of AUTOSAR and thus achieve full AUTOSAR compatibility.
      Risk:       There is no risk because the SNV-mapping mechanism is proven and tested.
      Prevention: Covered by code review.

 MD_FrTp_3218:    Deliberate violation of rule: File scope static, <variablename>, only accessed in one function.
      Reason:     Due to the AUTOSAR memory mapping concept this constant cannot be declared and defined locally in the function.
                  Also this definition of the variable provides a better code readability than declaring it in function scope.
      Risk:       There is no risk because the affected constant is only used file locally in one function and its usage 
                  is part of the resource-handling concept described in DSGN-FrTpStateMachineHandling which does not have side effects.
      Prevention: Covered by code review.

 MD_FrTp_3355:    Deliberate violation of rule: The result of this logical operation is always 'true'.
      Reason:     This statement might occur at this kind of statements:
                  2. For use cases where comparisons to FRTP_INVALID_SNV occur:
                  Refer to MD_FrTp_3358 below (Use cases: 'if(FRTP_INVALID_SNV != pConnCfg->FrTpSduRxId)' and 'if(((uint32)(FrTp_RxSm_Item(pRxSm, AvailableRxBuffer))) <= FrTp_MaxTransferLenSegm)')
                  3. For use cases where a comparison of uint8 bReq is done whose value was retrieved by cast (uint8) from BufReq_ReturnType-return-value of a PduR-function:
                  According to AUTOSAR the FrTp shall be able to cope with invalid return values and this is also tested!
                  Thus this if-statement is valid and not unreachable code.
      Risk:       There is no risk because this is a deliberate mechanism to fullfill AUTOSAR requirements.
      Prevention: Covered by code review.

 MD_FrTp_3356:    Deliberate violation of rule: The result of this logical operation is always 'false'.
      Reason:     This statement might occur at statements of the following type:
                  if(FRTP_INVALID_SNV == <Internal FrTp Rx or Tx-Sdu- or Pdu-Id>): This is an PRQA analysis error
                  This code-pattern is required to implement the SNV-concept of AUTOSAR and thus achieve full AUTOSAR compatibility.
      Risk:       There is no risk because the SNV-mapping mechanism is proven and tested.
      Prevention: Covered by code review.

 MD_FrTp_3358:    Deliberate violation of rule: The value of this 'if' control expression is always 'true'.
      Reason:     This statement might occur at statements of the following type:
                  if(FRTP_INVALID_SNV == <Internal FrTp Rx or Tx-Sdu- or Pdu-Id>): This is an PRQA analysis error
                  This code-pattern is required to implement the SNV-concept of AUTOSAR and thus achieve full AUTOSAR compatibility.
      Risk:       There is no risk because the SNV-mapping mechanism is proven and tested.
      Prevention: Covered by code review.

 MD_FrTp_3359:    Deliberate violation of rule: The value of this control expression is always 'false'.
      Reason:     This statement might occur at statements of the following type:
                  if(FRTP_INVALID_SNV == <Internal FrTp Rx or Tx-Sdu- or Pdu-Id>): This is an PRQA analysis error
                  This code-pattern is required to implement the SNV-concept of AUTOSAR and thus achieve full AUTOSAR compatibility.
      Risk:       There is no risk because the SNV-mapping mechanism is proven and tested.
      Prevention: Covered by code review.

 MD_FrTp_3408:    'FrTp_MainFunction' has external linkage but is being defined without any previous declaration.
      Reason:     The components EcuM and/or SchM are the only users of this functions.
                  They are informed about the prototype of FrTp_MainFunction during the calculation in the CFG5-GenTool
                  and generate the declaration themselves. However these components are not used in the FrTestSuite
                  and thus this violation is justfified.
      Risk:       There is no risk because the concept of letting EcuM and/or SchM generate the prototypes of the main functions
                  they call themselves is done all over the MICROSAR communication stack and thus proven and tested.
      Prevention: Covered by code review.

 MD_FrTp_3410:    Macro parameter not enclosed in ().
      Reason:     The combination of ISO10681-2, AUTOSAR configuration variants and Vector code size optimization
                  requires the macros that violate that rule exactly as they are.
      Risk:       There is no risk because the concept of affeced arrays are only used by Tp_Iso10681.
      Prevention: Covered by code review.

 MD_FrTp_3415:    Deliberate violation of rule 'The right hand operand of '&&' or '||' has side effects.'
      Reason:     The right hand operand is an configuration item of the FrTp which is accessed by inline functions
                  defined in module FrTp_XCfg (File FrTp_XCfg.h) which wraps all accesses to configuration items of the
                  FrTp. This is a unique pattern applied to all functions in that modul. The module is required to be
                  able to do stubbased testing of the CDD. Thus no changes are made to the configuration items and also
                  no changes to other FrTp-related items.
      Risk:       There is no risk because in the current case the function calls involved are used to retrieve the values to evaluate the whole expression.
                  Thus the side effects of both, operator || and operator &&, are not relevant in this case.
      Prevention: Covered by code review.

 MD_FrTp_3448:     Declaration of typedef '<Array-Variable>' is not in a header file although it is used in a definition or declaration with external linkage.
      Reason:     Have no casts with resulting compiler warnings. The type has not direct external linkage. An array with pointers to the arrays defined this 
                  way is linked externally and declared properly.
      Risk:       There is no risk because the sizes of the arrays without direct external linkage are known to the FrTp.c via other values
                  in the configuration and the consistency of these pairs is checked with by the MSSV plugin of the Tp_Iso10681.
      Prevention: Covered by code review.

 MD_FrTp_3673:    A pointer parameter in a function prototype should be declared as pointer to const if the pointer is
                  not used to modify the addressed object. 
      Reason:     In file FrTp_TxSm.c: The object addressed by the pointer FrIf_PduInfoPtr is not modified and so the
                  pointer could be of type 'pointer to const'.
                  In file FrTp_LCfg.c: PduR_FrTpStartOfReception(),
                  In file FrTp.c: FrTp_RxIndication():
                                       The prototypes of these functions with a non-const-pointer parameter are
                                       given by AUTOSAR and have to be used "as is".
                  In file FrTp_TxSm.c: FrTp_TxSm_FrIfRxIndication(): The MISRA tool does not properly detect that pTxSm
                                       is actually and indeed modified.
                  In file FrTp_RxSm.c: FrTp_RxSm_EvalBufReqRetVal(): Here the memcpy() function from the Vector
                                       Microsar StdLib has to be used which does not accept a constant-pointer as
                                       argument.
                                       FrTp_RxSm_ReceivedLF():
                                       FrTp_RxSm_CalcBfsValue():
                                       FrTp_RxSm_EvalBufReqRetVal():
                                       FrTp_RxSm_TolerateRxIndEarlierThanTxConf():
                                       The caller of these functions modifies the pRxSm parameter.
                                       At the callers level the parameter is volatile which leads to a compile warning
                                       in case the pRxSm parameter is made const as suggested by the MISRA tool.
      Risk:       There is the risk that for later changes of the component structures are modified by the FrTp that should not be modified.
                  However because the prototypes are required "as is" to meet AUTOSAR requirements that risk has to be accepted.
      Prevention: Covered by code review.

*/

/* COV_JUSTIFICATION_BEGIN

\ID COV_FRTP_MSR_COMPATIBILITY
\ACCEPT TX
\ACCEPT XF
\REASON [COV_MSR_COMPATIBILITY]

\ID COV_FRTP_TESTSUITE_INSTRUMENTATION
\ACCEPT TX 
\ACCEPT XF 
\REASON Not all branches covered because the following preprocessor macros and defines are necessary for proper test execution 
        with FrTestSuite: FRTP_UNIT_TEST

\ID COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE
\ACCEPT TX 
\ACCEPT XF 
\REASON [COV_MSR_UNSUPPORTED] The following features are not supported by FrTp in SafeBSW usecase and the corresponding 
        preprocessor switches must be configured according to CM_FRTP_QMDEFINES. This is guaranteed by the MSSV plugin.

COV_JUSTIFICATION_END */

/*
NOTE: For Tp_Iso10681 the following additional assumption is taken:
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
All FrTp-internal callers guarantee the validity of index parameters
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_FRTP_CONN_STATE_WRT
  \DESCRIPTION    Array write access to the connection state. The index used to access the array FrTp_ConnState[]
                  is FrTpRxSduId, which is given as input by the caller.
  \COUNTERMEASURE \R [CM_FRTP_INV_PDU]
                  \M FrTpRxSduId: [CM_FRTP_RX_SDU_SNV_TO_CONN_IDX_SIZE]
                  \M FrTpRxSduId: [CM_FRTP_RX_SDU_SNV_TO_CONN_IDX_VALUES]
                  \M [CM_FRTP_CONN_STATE_SIZE]

\ID SBSW_FRTP_RXTX_FRIF_PENDING_WRT
  \DESCRIPTION    Array write access to the Rx/Tx pending flag of a FrIf PDU. The index used to access the arrays
                  FrTp_RxFrIfPending[] and FrTp_TxFrIfPending[] is FrIfTxPduId, which is given as input by the caller.
  \COUNTERMEASURE \R [CM_FRTP_INV_PDU]
                  \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]

\ID              SBSW_FRTP_ALLOCATE_RXTX_SM
 \DESCRIPTION    The functions FrTp_Rsrc_Allocate[Rx|Tx]Sm work properly because they get valid parameters.
                 Critical parameters are these that are used as pointer or array indices, such as:
                 pConnCfg
                 pConnCfg->ConnCtrlPtr
                 [rx|tx]SmIdx]
                 [rx|tx]SmIdx] is always used as index to access generated arrays [FrTp_RxState|FrTp_TxState].
                 The initial values [rx|tx]SmIdx] are stored during runtime in members of a struct-member of generated array 
                 FrTp_ConnState. These initial values are always determined using functions [FrTp_Rsrc_FindRxSm|FrTp_Rsrc_FindTxSm].
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX_CHECK]                    
                 \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_TX_SDU_SNV_TO_CONN_IDX_SIZE]
                 \M [CM_FRTP_TX_SDU_SNV_TO_CONN_IDX_VALUES]
                 \M [CM_FRTP_CONN_CFG_SIZE]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_TX_STATE_SIZE]
                 \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_LCFG_ACCESS
 \DESCRIPTION    All Functions who are named using the prefix "FrTp_LCfg_" return pointer to generated FrTp configuration 
                 RAM items that are never indirectly referenced via pointer contained some initialization C-struct passed to 
                 FrTp_Init().
                 Instead these items are linked to the FrTp component by the embedded compilers' linker.
 \COUNTERMEASURE \N As the embedded compiler is a trusted tool pointers to items linked to the FrTp or to one of its submodules are always valid!

\ID              SBSW_FRTP_FRIF_RX_INDICATION
 \DESCRIPTION    The function FrTp_FrIf_RxIndication is called with valid parameters:
                 FrIf_PduInfoPtr is valid by caller due to SBSW_FRTP_STRUCT_WRT_UNCHANGED.
                 FrIfRxPduId is DET-checked by runtime CM 1 and CM_FRTP_RX_PDU_SNV_TO_PDU_IDX_SIZE.
                 tpConn is valid due to CM_FRTP_FRIF_RX_PDUS_VALUES.
 \COUNTERMEASURE \R 1. FrIfRxPduId is valid due to DET-check: if (FrIfRxPduId >= FrTp_CCfg_MaxFrIfRxPduId())
                 \M FrIfRxPduId: [CM_FRTP_RX_PDU_SNV_TO_PDU_IDX_SIZE]
                 \M FrIfRxPduId: [CM_FRTP_RX_PDU_SNV_TO_PDU_IDX_VALUES]
                 \R FrIfRxPduId: is valid due check: if(FrIfRxPduId == FRTP_INVALID_SNV)                 
                 \M [CM_FRTP_FRIF_RX_PDUS_SIZE]
                 \M [CM_FRTP_FRIF_RX_PDUS_VALUES]
                 \M [CM_FRTP_CONN_STATE_SIZE]
                 \M [CM_FRTP_CONN_CFG_SIZE]

\ID              SBSW_FRTP_TRIGGER_TRANSMIT
 \DESCRIPTION    The functions FrTp_[Rx|Tx]Sm_TriggerTransmit are called with valid parameters:
                 FrTpTxPduInfoPtr is valid by caller because of SBSW_FRTP_STRUCT_WRT_UNCHANGED
                 FrIfTxPduId is valid because of CM 1 and CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_SIZE.
                 &errorId is valid because it is the address of a local variable and the function called has the 
                 property: \synchronous TRUE i.e. it does not store pointers passed to it.
 \COUNTERMEASURE \R FrIfTxPduId: is valid due to DET-check: if (FrIfRxPduId >= FrTp_CCfg_MaxFrIfRxPduId())
                 \M FrIfTxPduId: [CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_SIZE]
                 \M FrIfTxPduId: [CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_VALUES]
                 \R FrIfTxPduId: is valid due check: if(FrIfTxPduId == FRTP_INVALID_SNV)                 

\ID              SBSW_FRTP_FRIF_RXINDICATION_RXTXSM
 \DESCRIPTION    The functions FrTp_FrIf_RxIndicationRxSm, FrTp_FrIf_RxIndicationTxSm are called with valid parameters:
                 1. Parameter FrIf_PduInfoPtr comes valid from the caller of FrTp_FrIf_RxIndication,
                 2. Parameter FrIfRxPduId comes valid from the caller of FrTp_FrIf_RxIndication,
                 3. Parameter tpConn comes valid from the caller of FrTp_FrIf_RxIndication.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_RXSM_RXINDICATION
 \DESCRIPTION    The function FrTp_RxSm_FrIfRxIndication is called with valid parameters.
                 
                 The following parameters are are given by the caller of FrTp_FrIf_RxIndication and are thus valid:
                 FrIf_PduInfoPtr: The parameter given by the caller with a valid value.
                 FrIfRxPduId: The parameter given by the caller with a valid value.
                 tpConn: The parameter given by the caller with a valid value.
                 For validity checks of the caller refer to justification SBSW_FRTP_FRIF_RXINDICATION_RXTXSM.

                 The following parameters are determined from the FrTp-configuration based on valid parameters given by 
                 the caller of FrTp_FrIf_RxIndication:
                 pConnCfg: Determined from configuration by looking up pConnCfg in generated array FrTp_ConnCfg[] using 
                 valid tpConn from caller as index. Refer to CM_FRTP_CONN_CFG_SIZE.
                 
                 The parameter rxSmIdx is valid because a free rx-state-machine is searched in method FrTp_Rsrc_FindRxSm().
                 In case not free rx-state-machine has been found then the affected function is not called: Refer to 
                 runtime CM and CM_FRTP_RX_STATE_SIZE.
 \COUNTERMEASURE \M pConnCfg: [CM_FRTP_CONN_CFG_SIZE]
                 \R rxSmIdx: The return value of function FrTp_Rsrc_FindRxSm is always valid, because it is taken from the
                    values processed in the loop for(rxSmIdx = 0u; rxSmIdx < FrTp_CCfg_NumRxChan(); rxSmIdx++) whose end 
                    index is always cross-checked to the generated array FrTp_RxState[] the return value is used to access:
                    Size of generated FrTp_RxState[] array has to be valid.
                 \M rxSmIdx: [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_TXSM_RXINDICATION
 \DESCRIPTION    The function FrTp_TxSm_FrIfTxIndication is called with valid parameters.

                 The following parameters are are given by the caller of FrTp_FrIf_TxIndication and are thus valid:
                 FrIf_PduInfoPtr: The parameter given by the caller with a valid value.
                 tpConn: The parameter given by the caller with a valid value.
                 For validity checks of the caller refer to justification SBSW_FRTP_FRIF_RXINDICATION_RXTXSM.

                 The following parameters are determined from the FrTp-configuration based on valid parameters given by 
                 the caller of FrTp_FrIf_TxIndication:
                 pConnCfg: Determined from configuration by looking up pConnCfg in generated array FrTp_ConnCfg[] using 
                 valid tpConn from caller as index.
                 Refer to CM_FRTP_CONN_CFG_SIZE.
                 
                 The parameter txSmIdx is valid because a free tx-state-machine is searched in method FrTp_Rsrc_FindTxSm().
                 In case not free tx-state-machine has been found then the affected function is not called: 
                 Refer to runtime CM 1., runtime CM 2. and CM_FRTP_TX_STATE_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_CONN_CFG_SIZE]
                 \R 1. The return value of function FrTp_Rsrc_FindTxSm is always valid, because it is taken from the values 
                       processed in the loop for(txSmIdx = 0u; txSmIdx < FrTp_CCfg_NumTxChan(); txSmIdx++) whose end index 
                       is always cross-checked to the generated array FrTp_TxState[] the return value is used to access:
                       Size of generated FrTp_TxState[] array has to be valid.
                 \R 2. Only in case runtime check CM 1. is ok pTxSm is assigned a non-NULL value.
                       Only in case pTxSm has a non-NULL value it is used as parameter to actually call the affected function: 
                       (pTxSm != NULL_PTR)
                 \M [CM_FRTP_TX_STATE_SIZE]

\ID              SBSW_FRTP_UPDATE_FREE_TX_PDUS
 \DESCRIPTION    In the macro FrTp_FrIf_GetTxPduPoolDataItem the member NumFreePdus of (FrTp_VarLData i.e. linktime-data) 
                 array FrTp_PoolData[] is written using variable index as array index. However in this function the index 
                 value used iterates from 0 to value FrTp_NumTxPools - 1.
                 Thus the value of the index is valid according to CM_FRTP_POOL_DATA_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_POOL_DATA_SIZE]
                 \R The loop ensures that index value does not exceed FrTp_NumTxPools - 1.

\ID              SBSW_FRTP_RESET_TX_CONFS
 \DESCRIPTION    In the macro FrTp_FrIf_GetTxPduPoolDataItem the member NumTxConfs of (FrTp_VarLData i.e. linktime-data) 
                 array FrTp_PoolData[] is written using variable index as array index. However in this function the index 
                 value used iterates from 0 to value FrTp_NumTxPools - 1.
                 Thus the value of the index is valid according to CM_FRTP_POOL_DATA_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_POOL_DATA_SIZE]
                 \R The loop ensures that index value does not exceed FrTp_NumTxPools - 1

\ID              SBSW_FRTP_RESET_RX_FRIF_PENDING
 \DESCRIPTION    In the macro FrTp_FrIf_TxConfirmationForRxSmUsingTxPdu the item at index pduIdx of generated array 
                 FrTp_RxFrIfPending is set to FrTp_NoSm.
                 The value of index variable pduIdx is determined by the following loop that limits the value to 
                 FrTp_NumFrIfTxPdus - 1:
                 for(FrIfTxPdu = 0u; FrIfTxPdu < FrTp_CCfg_NumFrIfTxPdus(); FrIfTxPdu++)
                 The value of FrTp_NumFrIfTxPdus and the length of FrTp_RxFrIfPending is assured by CM_FRTP_RXTX_FRIF_PENDING_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]
                 \R The loop ensures that FrIfTxPdu never exceeds FrTp_NumFrIfTxPdus - 1

\ID              SBSW_FRTP_RESET_TX_FRIF_PENDING
 \DESCRIPTION    In the macro FrTp_FrIf_TxConfirmationForTxSmUsingTxPdu the item at index pduIdx of generated array 
                 FrTp_TxFrIfPending is set to FrTp_NoSm.
                 The value of index variable pduIdx is determined by the following loop that limits the value to FrTp_NumFrIfTxPdus - 1:
                 for(FrIfTxPdu = 0u; FrIfTxPdu < FrTp_CCfg_NumFrIfTxPdus(); FrIfTxPdu++)
                 The value of FrTp_NumFrIfTxPdus and the length of FrTp_TxFrIfPending is assured by the following CM:
 \COUNTERMEASURE \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]
                 \R The loop ensures that FrIfTxPdu never exceeds FrTp_NumFrIfTxPdus - 1

\ID              SBSW_FRTP_INCREASE_TX_CONFS
 \DESCRIPTION    At this usage of the macro FrTp_FrIf_GetTxPduPoolDataItemByPtr the item NumTxConfs of the macros 
                 "pointer to struct"-parameter pPoolDataUsed is incremented by 1.
                 The pointer pPoolDataUsed is retrieved by accessing array FrTp_PoolData at index poolOffset using 
                 macro: FrTp_FrIf_GetTxPduPoolDataPtrByOffset.
                 The value of poolOffset is retrieved in 4 steps:
                 1. The item PoolOffsetsPtr is retrieved from the generated FrTp_FrIfTxPdus[] array at position 
                    FrIfTxPduId which comes as valid value from the caller.
                 2. The item PoolOffsetsPtr is an array containing the index-values of all tx-pdu-pools the tx-pdu 
                    belongs to. It is accessed at the index determined by the loop variable poolIdx.
                 3. The for-loop iterates all pools the tx-pdu belongs to. The max. value of the loop-variable 
                    poolIdx is determined by macro FrTp_GetTxPduItemByIdx.
                 4. Macro FrTp_GetTxPduItemByIdx accesses array generated array FrTp_TxPdus[] at position FrIfTxPduId 
                    and (there) reads the struct-member NumPools as end value of the loop.
                 The value of FrIfTxPduId is valid because the caller ensures validity: Refer to CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_SIZE.
                 CM_FRTP_POOLS_OF_TX_PDUS_SIZE assures that NumPools and FrTp_PoolsOfTxPdus fit to each other.
                 Runtime CM assures that the index passed to macro FrTp_FrIf_GetTxPduPoolDataItemByPtr 
                 is valid.
 \COUNTERMEASURE \M [CM_FRTP_POOLS_OF_TX_PDUS_SIZE]
                 \M [CM_FRTP_POOLS_OF_TX_PDUS_VALUES]
                 \M [CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_SIZE]
                 \M [CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_VALUES]
                 \R The loop ensures that poolIdx never exceeds NumPools - 1

\ID              SBSW_FRTP_DECREASE_FREE_PDUS
 \DESCRIPTION    At this usage of the macro FrTp_FrIf_GetTxPduPoolDataItem the item NumFreePdus of the macros 
                 "pointer to struct"-parameter pPoolDataUsed is decremented by 1.
                 The pointer pPoolDataUsed is retrieved by accessing array FrTp_PoolData at index poolOffset 
                 where poolOffset is determined using macro: FrTp_FrIf_GetTxPduPoolDataItem
                 The value of poolOffset is retrieved in 3 steps:
                 1. From the pFrIfTxPdu which is provided validly by the caller, the item PoolOffsetsPtr is retrieved.
                 2. The item PoolOffsetsPtr is an array containing the index-values of all tx-pdu-pools the tx-pdu 
                    belongs to. It is accessed at the index determined by the loop variable poolIdx.
                 3. The for-loop iterates all pools the tx-pdu belongs to. The loops' upper limit is determined by 
                    reading NumPools from the given pFrIfTxPdu (valid from caller).
                 The value of pFrIfTxPdu is valid because the caller ensures validity.
                 CM_FRTP_POOLS_OF_TX_PDUS_SIZE assures that NumPools and FrTp_PoolsOfTxPdus fit to each other.
                 Runtime CM assures that the index passed to macro FrTp_FrIf_GetTxPduPoolDataItem is valid.
 \COUNTERMEASURE \M [CM_FRTP_POOLS_OF_TX_PDUS_SIZE]
                 \M [CM_FRTP_POOLS_OF_TX_PDUS_VALUES]
                 \R The loop ensures that poolIdx never exceeds NumPools - 1
 
\ID              SBSW_FRTP_INIT_DECOUP_ADMIN_DATA
 \DESCRIPTION    At this usage of macro FrTp_FrIf_GetDecoupAdmin the generated array FrTp_DecoupPduAdminData 
                 is written at the position determined by member DecoupPduAdminDataOffset of a configured FrTp_FrIfTxPdu.
                 The configured FrTp_FrIfTxPdu is determined by accessing the generated array FrTp_FrIfTxPdus[] at 
                 position index.
                 The value of index is valid because the max. value of the surrounding loop is FrTp_NumFrIfTxPdus which 
                 is checked to fit to the size of generated array FrTp_FrIfTxPdus[]: Refer to CM_FRTP_POOLS_OF_TX_PDUS_SIZE.
                 Each struct-member of each member of generated array FrTp_FrIfTxPdus[] is initialized by a separate assignment.
                 The VStdLib_MemSet()-statement is used to zeroise the TPCI-part of the pdus payload contained in array TPCIData.
                 This works well, always, because the same constant FrTp_TPCIMaxLength that is used to define the length 
                 of that array in the type-declaration is used in the call to VStdLib_MemSet().
                 The length of FrTp_DecoupPduAdminData[] is also checked in CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE.
                 The member DecoupPduAdminDataOffset of each element of generated array FrTp_FrIfTxPdus[] is always used 
                 safely as described in CM_FRTP_FRIF_TX_PDUS_VALUES.
 \COUNTERMEASURE \M [CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE]
                 \R Usage of FrTp_FrIf_IsDecoupPdu() prior to accessing FrTp_DecoupPduAdminData[] with index FrTp_FrIfTxPdus[index].DecoupPduAdminDataOffset
                 \M [CM_FRTP_POOLS_OF_TX_PDUS_SIZE]
                 \M [CM_FRTP_POOLS_OF_TX_PDUS_VALUES]
                 \M [CM_FRTP_FRIF_TX_PDUS_VALUES]
                 \R The loop endures that index never exceeds FrTp_NumFrIfTxPdus - 1

\ID              SBSW_FRTP_INIT_RXTX_FRIF_PENDING
 \DESCRIPTION    The macro FrTp_VarLData here accesses the arrays [FrTp_RxFrIfPending|FrTp_TxFrIfPending] at position index.
                 The value of index is determined by the loop:
                 for(index = 0u; index < FrTp_CCfg_NumFrIfTxPdus(); index++)
                 This means that the size of the generated arrays [FrTp_RxFrIfPending|FrTp_TxFrIfPending] has to be equal 
                 to the generated constant FrTp_NumFrIfTxPdus. This is assured by CM_FRTP_RXTX_FRIF_PENDING_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]
                 \R The loop ensures that index never exceeds FrTp_NumFrIfTxPdus - 1

\ID              SBSW_FRTP_INIT_POOL_DATA
 \DESCRIPTION    The macro here writes the members NumTxConfs and NumFreePdus of generated array FrTp_PoolData[]
                 using variable index as index. The value of index is determined by the loop:
                 for(index = 0; index < FrTp_CCfg_NumTxPools(); index++)
                 This means that the size of the generated array FrTp_PoolData[] has to be equal to the generated 
                 constant FrTp_NumTxPools. This is assured by the CM_FRTP_POOL_DATA_SIZE listed, below.
 \COUNTERMEASURE \M [CM_FRTP_POOL_DATA_SIZE]
                 \R The loop ensures that index never exceeds FrTp_NumTxPools - 1.

\ID              SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN
 \DESCRIPTION    The values of struct of type FrTp_DecoupPduAdminType pointed to by pDecoupAdminData are updated.
                 The value of variable pDecoupAdminData is determined using macro FrTp_FrIf_GetDecoupAdmin: Refer 
                 to CM_FRTP_FRIF_TX_PDUS_VALUES, below.
                 The assignment is done only in case FrTp_FrIf_IsDecoupPdu has assured that the pFrIfTxPdu, belongs 
                 to a decoupled tx-pdu: 
                 The pointer pFrIfTxPdu itself comes valid from the caller.
                 In the call to VStdLib_MemCpy the array TPCIData is written. This array has a length of 
                 FrTp_TPCIMaxLength bytes (by definition).
                 The caller assures that the member SduLength of the given pTPCI is always < FrTp_TPCIMaxLength, i.e. 
                 this function conducts the copying, the caller conducts proper preparations for copying.
 \COUNTERMEASURE \R pTPCI and its members: [SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_RX_CONN] & [SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_TX_CONN]
                 \M [CM_FRTP_FRIF_TX_PDUS_VALUES]                 

\ID              SBSW_FRTP_TX_ASSEMBLE_IMMEDIATE_TX_PDU
 \DESCRIPTION    The function FrTp_Util_AssemblePdu is called with valid parameters:
                 Parameter pTPCI comes validly from the caller of the function FrTp_FrIf_TransmitPduForConn itself.
                 Parameter pConnCfg comes validly from the caller of the function FrTp_FrIf_TransmitPduForConn itself.
                 Parameter pPayload comes validly from the caller of the function FrTp_FrIf_TransmitPduForConn itself.
                 Parameter FrIfPduInfo.SduDataPtr is initialized with the address of generated array FrTp_FrIfTxBuf[] 
                 (used as buffer for TP-pdu-assembly)  by the function FrTp_FrIf_TransmitPduForConn itself.
                 The size of generated array FrTp_FrIfTxBuf[] and the values used by FrTp to access that array is checked 
                 by CM_FRTP_FRIF_TX_BUF_SIZE.
 \COUNTERMEASURE \M [CM_FRTP_FRIF_TX_BUF_SIZE]

\ID              SBSW_FRTP_TX_FRIF_TRANSMIT
 \DESCRIPTION    The function FrIf_Transmit is called with valid parameters: 
                 Parameter pFrIfTxPdu and its members: The parameter given by the caller with a valid value. 
                 (Member PduId is passed to FrIf_Transmit)
                 Parameter FrIfPduInfo is a local variable that is has 2 possibilities to be initialized:
                 1. Decoupled Pdu: FrIfPduInfo.SduLength is calculated as a sum of the items pTPCI->SduLength, 
                                   pPayload->SduLength, FrTp_Util_OffsetTPCI.
                                   pTPCI->SduLength and pPayload->SduLength are valid from caller.
                                   FrTp_Util_OffsetTPCI is a protocol constant that is also taken into account 
                                   by caller when determining values of pTPCI and pPayload.
                 2. Immediate Pdu: FrIfPduInfo.SduLength is retrieved as return value from function FrTp_Util_AssemblePdu. 
                                   FrIfPduInfo.SduDataPtr is valid as described in SBSW_FRTP_TX_ASSEMBLE_IMMEDIATE_TX_PDU, above.
                                   However the return value of FrTp_Util_AssemblePdu is determined in the same way as for case 
                                   '1. Decoupled Pdu', namely as sum of the parameters: pTPCI->SduLength, pPayload->SduLength, 
                                   FrTp_Util_OffsetTPCI.
 \COUNTERMEASURE \R The calculated length that is passed to FrIf_Transmit in parameter FrIfPduInfo.SduLength is checked 
                    to not be larger than the configured  length of the tx-pdu in pFrIfTxPdu. In case the calculated length 
                    is larger than configured then FrIf_Transmit will not be called.
                 \T The runtime measure, above, is tested by TCASE-393644

\ID              SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX_CONNSTATE
 \DESCRIPTION    Member CurrTxSmIdx of generated array FrTp_ConnState[] is written at position pConnCfg->ConnIdx whereas 
                 pConnCfg comes validly from the caller.
                 The index to access generated array FrTp_ConnState[] is member ConnIdx of pConnCfg which is MSSV-checked
                 to be valid: Refer to CM_FRTP_CONN_CFG_VALUES.
                 In addition the size of generated array FrTp_ConnState[] is also checked to fit all generated ConnIdx 
                 values: Refer to CM_FRTP_CONN_STATE_SIZE.
 \COUNTERMEASURE \R pConnCfg: [SBSW_FRTP_ALLOCATE_RXTX_SM]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_CONN_STATE_SIZE]

\ID              SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX_CONNSTATE
 \DESCRIPTION    Member CurrRxSmIdx of generated array FrTp_ConnState[] is written at position pConnCfg->ConnIdx whereas 
                 pConnCfg comes validly from the caller.
                 The index to access generated array FrTp_ConnState[] is member ConnIdx of pConnCfg which is MSSV-checked 
                 to be valid: Refer to CM_FRTP_CONN_CFG_VALUES.
                 In addition the size of generated array FrTp_ConnState[] is also checked to fit all generated ConnIdx 
                 values: Refer to CM_FRTP_CONN_STATE_SIZE.
 \COUNTERMEASURE \R pConnCfg: [SBSW_FRTP_ALLOCATE_RXTX_SM]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_CONN_STATE_SIZE]

\ID              SBSW_FRTP_RELEASE_TXSM_CONNSTATE
 \DESCRIPTION    Member CurrTxSmIdx of generated array FrTp_ConnState[] is written at position pConnCfg->ConnIdx whereas 
                 pConnCfg is retrieved from pTxSm.
                 pTxSm is retrieved from generated array FrTp_TxState[] at index txSmIdx which comes validly from the caller.
                 The member ConnCfgPtr of the pTxSm is only set in this module FrTp_Rsrc.c in functions:
                 FrTp_Rsrc_AllocateTxSm
                 FrTp_Rsrc_ReleaseTxSm
                 FrTp_Rsrc_InitAllSms
                 In these functions it is either set to NULL or to a pConnCfg coming valid from caller. Refer to runtime CM 2.
                 However runtime CM 1. prevents that pConnCfg is NULL.
                 The index to access generated array FrTp_ConnState[] is member ConnIdx of pConnCfg which is MSSV-checked to 
                 be valid: Refer to CM_FRTP_CONN_CFG_VALUES.
                 In addition the size of generated array FrTp_ConnState[] is also checked to fit all generated ConnIdx values:
                 Refer to CM_FRTP_CONN_STATE_SIZE.
 \COUNTERMEASURE \R 1. pConnCfg: Is checked to be non-NULL and if non-NULL it is valid due to runtime CM 2.
                 \R 2. pConnCfg: Is set only in this module in the complete FrTp source code and here pConnCfg used to set is 
                       given by the caller with a valid value.
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_CONN_STATE_SIZE]

\ID              SBSW_FRTP_RELEASE_RXSM_CONNSTATE
 \DESCRIPTION    Member CurrRxSmIdx of generated array FrTp_ConnState[] is written at position pConnCfg->ConnIdx whereas 
                 pConnCfg is retrieved from pRxSm.
                 pRxSm is retrieved from generated array FrTp_RxState[] at index rxSmIdx which comes validly from the caller.
                 The member ConnCfgPtr of the pRxSm is only set in this module FrTp_Rsrc.c in functions:
                 FrTp_Rsrc_AllocateRxSm
                 FrTp_Rsrc_ReleaseRxSm
                 FrTp_Rsrc_InitAllSms
                 In these functions it is either set to NULL or to a pConnCfg coming valid from caller. Refer to runtime CM 2.
                 However runtime CM 1. prevents that pConnCfg is NULL.
                 The index to access generated array FrTp_ConnState[] is member ConnIdx of pConnCfg which is MSSV-checked to be 
                 valid: Refer to CM_FRTP_CONN_CFG_VALUES.
                 In addition the size of generated array FrTp_ConnState[] is also checked to fit all generated ConnIdx values: 
                 Refer to CM_FRTP_CONN_STATE_SIZE.
 \COUNTERMEASURE \R 1. pConnCfg: Is checked to be non-NULL and if non-NULL it is valid due to runtime CM 2.
                 \R 2. pConnCfg: Is set only in this module in the complete FrTp source code and here pConnCfg used to set is 
                       given by the caller with a valid value.
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_CONN_STATE_SIZE]

\ID              SBSW_FRTP_INIT_RXSM
 \DESCRIPTION    The pointer pRxSm is retrieved from generated array FrTp_RxState[] by using index index.
                 The index is valid because it is limited to FrTp_NumRxChan - 1 by the for-loop that is used. Refer to CM_FRTP_RXTX_SM_IDX.
                 The size of the generated array FrTp_RxState[] and the upper limit of the loop are cross checked by CM_FRTP_RX_STATE_SIZE.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_INIT_TXSM
 \DESCRIPTION    The pointer pTxSm is retrieved from generated array FrTp_TxState[] by using index index.
                 The index is valid because it is limited to FrTp_NumTxChan - 1 by the for-loop that is used. Refer to CM_FRTP_RXTX_SM_IDX.
                 The size of the generated array FrTp_TxState[] and the upper limit of the loop are cross checked by CM_FRTP_TX_STATE_SIZE.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_TX_STATE_SIZE]

\ID              SBSW_FRTP_INIT_CONNSTATE
 \DESCRIPTION    The generated array FrTp_ConnState[] is written at index index.
                 The index is valid because it is limited to FrTp_NumConn -1 by the loop that is used. Refer to runtime CM, below:
 \COUNTERMEASURE \R The index is valid because it is limited to FrTp_NumConn - 1 by the for loop tfor(index = 0u; index < FrTp_CCfg_NumConn(); index++)
                 \M [CM_FRTP_CONN_STATE_SIZE]

\ID              SBSW_FRTP_VALID_SM_IDX_OF_ACTIVE_CONN
 \DESCRIPTION    Note: This justification is to be referenced by functions that are called after a rx- or tx-connection 
                 has been set active using the functions FrTp_Rsrc_AllocateRxSm, FrTp_Rsrc_AllocateTxSm.
                 The initialization of items Curr[Rx|Tx]SmIdx with valid values is exclusively done in functions 
                 FrTp_Rsrc_Allocate[Rx|Tx]Sm.
                 These values are reset only at 2 locations:
                 1. FrTp_Rsrc_InitAllConns which is a helper function called by FrTp_Init
                 2. FrTp_Rsrc_Release[Rx|Tx]Sm
                 During the runtime of those functions calling FrTp_Rsrc_Release[Rx|Tx]Sm (which are):
                 1. FrTp_MainFunction
                 2. FrTp_RxIndication
                 3. FrTp_TxConfirmation
                 4. FrTp_TriggerTransmit
                 5. FrTp_Init
                 the access to (resetting) the items Curr[Rx|Tx]SmIdx is locked by the exclusive area FrTp_EnterCritical
                 However prior to using the items Curr[Rx|Tx]SmIdx to look up a p[Rx|Tx]Sm from generated array 
                 FrTp_[Rx|Tx]State the following checks are done to assure that the affected [rx|tx]-state-machine is active:
                 Refer to runtime CMs 1. and 2.
                 At the point of time of that check the exclusive area is locked already, i.e. no call to 
                 FrTp_Rsrc_Release[Rx|Tx]Sm is able to interrupt and reset Curr[Rx|Tx]SmIdx to FrTp_NoSm.
                 As Curr[Rx|Tx]SmIdx and Timer are
                 a) set synchronously in functions FrTp_Rsrc_Allocate[Rx|Tx]Sm and
                 b) reset synchronously in functions FrTp_Rsrc_Allocate[Rx|Tx]Sm the fact that the check of Timer!=0 is TRUE 
                    means that Curr[Rx|Tx]SmIdx of the affected [rx|tx]-state-machine are currently valid.
                 This means that due to the critical sections applied and due to the synchronous setting and resetting the 
                 items Curr[Rx|Tx]SmIdx contain valid values as soon as they are used in an internal helper function.
 \COUNTERMEASURE \R 1. if(FrTp_RxSm_Item(pRxSm, Timer) != 0u) in FrTp_RxSm_PrepareAllSms in file FrTp_RxSm.c
                 \R 2. if(FrTp_TxSm_Item(pTxSm, Timer) != 0u) in FrTp_TxSm_PrepareAllSms in file FrTp_TxSm.c

\ID              SBSW_FRTP_PDUR_COPYTXDATA_ACTUALLY_COPY
 \DESCRIPTION    Function PduR_FrTpCopyTxData[s] is called with valid parameters.
                 1. Parameter id is valid for this decoupled tx-pdu as it is read from pConnCfg which is valid in the same way 
                    as described in justification SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable.
                    In addition this is a C-struct which is properly initialized using these values:
                    a) SduLength is initialized from local variable pduLen which is initialized from member PduInfoPayload.SduLength
                       of an item which is a struct of type FrTp_DecoupPduAdminType:
                       The value of this item is valid due to the description and countermeasures described in justification 
                       SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX.
                    b) SduDataPtr is looked up from generated array FrTp_TxBuf[] using the index NxtFreePduIdx read from the pTxSm.
                 3. Parameter retry of type PduInfoType* is used in case a <Bus>Tp wants to retry parts of a data-transfer. 
                    Any retry feature is not supported by the MICROSAR communication stack and thus 
                 4. Parameter &availableTxData is valid because it is the address of a local variable.
 \COUNTERMEASURE \M [CM_FRTP_FRIF_TX_PDUS_SIZE]
                 \M [CM_FRTP_FRIF_TX_PDUS_VALUES]                 

\ID              SBSW_FRTP_TXSM_PTR_FROM_VALID_CONN_DATA
 \DESCRIPTION    Write access to pointer pTxSm is valid. Pointer pTxSm is valid because it is read from generated array 
                 FrTp_TxState[] at position pConnState->CurrTxSmIdx.
                 Size of array FrTp_TxState[] is valid due to CM_FRTP_TX_STATE_SIZE.
                 pConnState is read at index connIdx from generated array FrTp_ConnState[] which is valid due to CM_FRTP_CONN_STATE_SIZE.
                 Local variable connIdx is read from member ConnIdx of struct ConnCfgPtr. ConnIdx is valid due to CM_FRTP_CONN_CFG_VALUES.
                 The struct ConnCfgPtr (used to initialize connIdx) is initialized from member ConnCfgPtr of an item which is a struct of 
                 type FrTp_DecoupPduAdminType.
                 The value of this item is valid due to the description and countermeasures described in justification 
                 SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX.
                 The value of pConnState member currTxState is valid due to runtime CM 1. and the description of justification 
                 SBSW_FRTP_VALID_SM_IDX_OF_ACTIVE_CONN.
                 Thus, reading pTxSm from valid generated array FrTp_TxState[] with valid index pConnState->CurrTxSmIdx, the write access 
                 on pTxSm is valid.
 \COUNTERMEASURE \M [CM_FRTP_TX_STATE_SIZE]
                 \M [CM_FRTP_CONN_STATE_SIZE]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \R 1. if(pConnState->CurrTxSmIdx != FrTp_NoSm)

\ID              SBSW_FRTP_ERRORID_PTR
 \DESCRIPTION    Write access to pointer pErrorId is valid. Pointer pErrorId is given by the caller with a valid value.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU
 \DESCRIPTION    The function FrTp_Util_AssemblePdu is called with valid parameters and the pointer write access storing the functions' 
                 return value is to a valid pointer.
                 The pointer accessed is FrTpTxPduInfoPtr which is a parameter of FrTp_TxSm_TriggerTransmit and thus is valid, including
                 its members SduDataPtr and SduLength.
                 I.e. FrTpTxPduInfoPtr->SduDataPtr may be passed to FrTp_Util_AssemblePdu and also its return value may be assigned to 
                 FrTpTxPduInfoPtr->SduLength. These parameters are valid from caller.
                 1. Parameter ConnCfgPtr is retrieved from local pointer variable pDecoupAdminData which points to an item which is a 
                    struct of type FrTp_DecoupPduAdminType:
                    The value of this item is valid due to the description and countermeasures described in justification 
                    SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX.
                 2. Parameter pDecoupAdminData->PduInfoPayload is valid as described in the chapter above.
                 3. Parameter FrTpTxPduInfoPtr->SduDataPtr is given by the caller with a valid value.
                 4. Parameter &TPCI is a pointer to local variable TPCI and thus valid. The members SduDataPtr and SduLength of TPCI are 
                    set from the members of local variable pDecoupAdminData.
                    Local variable pDecoupAdminData is initialized as pointer to an element of generated array FrTp_DecoupPduAdminData[] 
                    using FrTpTxPduId as index which is valid from caller.
                    The caller assures that the element pointed to be pDecoupAdminData is initialized validly as described in justification 
                    SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX
 \DESCRIPTION    The parameter pTxSm is looked up in generated array FrTp_TxState[] using index txSmIdx which is given by the caller with 
                 a valid value.
                 In addition the txSmIdx is cross-checked with generated array FrTp_TxState[] in CM_FRTP_TX_STATE_SIZE.
                 I.e. write accesses to pTxSm are valid and also the usage of pTxSm as function parameter leads to the function being 
                 called with valid parameters.
 \COUNTERMEASURE \M [CM_FRTP_TX_STATE_SIZE]

\ID              SBSW_FRTP_VALID_WRAPPED_TXSM_IDX
 \DESCRIPTION    FrTp_TxSm_OperateAllSms iterates txSmIdx as long as FrTp_TxSm_MaxIterations is reached and checks txSmIdx for wrap-around, 
                 i.e. txSmIdx is valid: if(txSmIdx >= FrTp_CCfg_NumTxChan())
                 The value of txSmIdx (and the value FrTp_NumTxChan that is used for wrap-around-check) is cross-checked with generated 
                 array FrTp_TxState[] in CM_FRTP_TX_STATE_SIZE and is thus valid.
                 In addition any pTxSm that is looked up in generated array FrTp_TxState[] is valid too (also taking into account 
                 CM_FRTP_TX_STATE_SIZE)
 \COUNTERMEASURE \R if(txSmIdx >= FrTp_CCfg_NumTxChan())
                 \M [CM_FRTP_TX_STATE_SIZE]

\ID              SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_TX_CONN
 \DESCRIPTION    The function FrTp_FrIf_TransmitPduForConn is called with valid parameters.
                 1. Parameter pConnCfg is read from pTxSm which is looked up in generated array FrTp_TxState[] using index txSmIdx which 
                    is given by the caller with a valid value.
                    The function FrTp_TxSm_FrIfTransmit is exclusively called by FrTp_TxSm_ActionOf which is called by FrTp_TxSm_OperateAllSms.
                    The value of txSmIdx is valid due to description and countermeasures in justification SBSW_FRTP_VALID_WRAPPED_TXSM_IDX

                    In function FrTp_TxSm_ActionOf function FrTp_TxSm_FrIfTransmit is only called in case the member State is not FrTp_TxSm_Idle
                    and has a value that is suitable for sending a tx-related tx-pdu.
                    Only then the tx-state-machine is active i.e. its values set properly. Such allocation is uniformly done by 
                    FrTp_Rsrc_AllocateTxSm all over the FrTp.
                    This method sets pTxSm-member ConnCfgPtr atomically with all other items that signal an active tx-state-machine. Thus the 
                    local variable pConnCfg read from pTxSm is valid.
                 2. Parameter pFrIfTxPdu is looked up from generated array FrTp_FrIfTxPdus[] using the index NxtFreePduIdx read from the pTxSm.
                    The pTxSm member index NxtFreePduIdx indicating that a free tx-pdu is available is checked by FrTp_TxSm_HandleAllSms as 
                    precondition to call FrTp_TxSm_ActionOf at all:
                    if(FrTp_TxSm_Item(pTxSm, NxtFreePduIdx) != FrTp_NoPdu)
                    Refer to TAG SBSW_FRTP_TIMEOUT_AND_ACTION_OF_TXSM
                    In addition the NxtFreePduIdx is always and exclusively set by function FrTp_FrIf_FindFreeTxPdu which only returns a valid 
                    index to generated array FrTp_FrIfTxPdus[] or FrTp_NoPdu.
                    Refer to TAG SBSW_FRTP_VALID_FREE_TXPDU in FrTp_TxSm.c.
                    if(FrTp_FrIf_TransmitPduForConn(pConnCfg, pFrIfTxPdu, pTPCI, pPayload) == E_OK)
                 3. Parameter pTPCI is given by the caller with a valid value.
                 4. Parameter pPayload is given by the caller with a valid value.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_TX_STATE_SIZE]                 

\ID              SBSW_FRTP_VALID_TXSM_IDX_FROM_CALLER
 \DESCRIPTION    The macro FrTp_FrIf_ExpectTxConfForTxPduOfTxSm writes the value pTxSmIdx into generated array FrTp_TxFrIfPending[] at index 
                 local variable intTxPduIdx.
                 Local variable intTxPduIdx is valid because it is read from member NxtFreeTxPdu from pTxSm which is looked up using valid txSmIdx from 
                 caller. 
 \COUNTERMEASURE \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]
                 \R [CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_TXSM]

\ID              SBSW_FRTP_VALID_FRIF_TXPDU_IN_TXSM
 \DESCRIPTION    The function FrTp_FrIf_DecreaseNumFreePdusOverlapped is called with valid parameters.
                 Parameter pFrIfTxPdu is valid as it is looked up using valid member NxtFreeTxPdu from pTxSm which is looked up using valid txSmIdx 
                 from caller. 
 \COUNTERMEASURE \R [CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_TXSM]

\ID              SBSW_FRTP_RXTX_PENDING_VALUES
 \DESCRIPTION    The pointer that is used for memory write points to an element of one of the generated arrays FrTp_[Rx|Tx]State[].
                 The index to access these arrays is read from one of the arrays FrTp_[Rx|Tx]FrIfPending.
                 Into these arrays always valid [rx|tx]SmIdx values are written into.
                 Nevertheless there is the possibility to configure the arrays FrTp_[Rx|Tx]State[] with different sizes.
                 Thus the [rx|tx]SmIdx is checked by these code-snippets prior in this function: SBSW_FRTP_RX_IND_EARLIER_THAN_TX_CONF
                 Access to FrTp_RxState is secured by a check that smIdx is smaller than FrTp_NumRxChan.
                 Access to FrTp_TxState is secured by a check that smIdx is smaller than FrTp_NumTxChan.
                 These checks can only work in case the generated values FrTp_Num[Rx|Tx]Chan fit to the generated arrays FrTp_[Rx|Tx]State[]
 \COUNTERMEASURE \M [CM_FRTP_RX_STATE_SIZE]
                 \M [CM_FRTP_TX_STATE_SIZE]
                 \R [CM_FRTP_RXTX_SM_IDX]

\ID              SBSW_FRTP_TXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP
 \DESCRIPTION    The parameter pTxSm is looked up in generated array FrTp_TxState[] using the loop variable txSmIdx which is valid
                 because it is limited by the loop the write access is executed in:
                 In addition the upper limit value of the loop FrTp_NumTxChan is cross-checked with generated array FrTp_TxState[] 
                 in CM_FRTP_TX_STATE_SIZE.
                 I.e. write accesses to pTxSm are valid and also the usage of pTxSm as function parameter leads to the function 
                 being called with valid parameters.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_TX_STATE_SIZE]

\ID              SBSW_FRTP_FIND_FREE_TX_PDU_FOR_TXSM
 \DESCRIPTION    Function FrTp_FrIf_FindFreeTxPdu is called with valid parameters.
                 1. Parameter pPoolCfg and
                 2. Parameter pPoolDataUsed
                    are both read from their associated, generated configuration and runtime-data arrays:
                    - FrTp_TxPduPools (valid according to CM_FRTP_RXTX_PDU_POOLS_SIZE.)
                    - FrTp_PoolData (valid according to CM_FRTP_POOL_DATA_SIZE.)
                    using index poolOffset which is read from the pointer pConnCfg which is valid due to SBSW_FRTP_PDUR_COPYTXDATA_AVAIL_BUF.
                    The value for poolOffset in the FrTp_ConnCfg[] array is checked to be valid in CM_FRTP_CONN_CFG_VALUES.

                    Concept for tx-pdu-pools in FrTp_Connections doing reception (in tx-state-machines):
                      It is possible to NOT configure a tx-pdu-pool for an FrTp_Connection doing reception of FrTp-data:
                      Whether a FrTp_Connection has configured a tx-pdu-pool or not is indicated by these values of FrTp_ConnCfg-initializer-
                      struct-list member 'poolOffset':
                        == FrTp_NumTxPduPools --> No pool is configured
                        < FrTp_NumTxPduPools --> Pool is configured
                      Any FrTp_Connection is only allowed to get active with ANY transmission (Segmented or not: Both types require tx-pdus) 
                      in a tx-state-machine in case a tx-pdu-pool is configured.
                      This is checked once at that point of time when the PduR calls FrTp_Transmit and the FrTp_Connection shall get active.
                      This concept can be seen according to the macros:
                      - FrTp_FrIf_GetTxPduPoolDataPtrByCheckedOffset being used only in FrTp_Transmit (i.e. the function where transmission 
                        processes start) and
                      - FrTp_FrIf_GetTxPduPoolDataPtrByOffset being used at all other locations in the FrTp (i.e. helpers called by 
                        FrTp_MainFunction).
                 ==> Thus pPoolCfg and pPoolDataUsed are valid.
                 3. BandwidthLimitation is not used as index in function FrTp_FrIf_FindFreeTxPdu.
 \COUNTERMEASURE \R [SBSW_FRTP_PDUR_COPYTXDATA_AVAIL_BUF]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_RXTX_PDU_POOLS_SIZE]
                 \M [CM_FRTP_POOL_DATA_SIZE]

\ID              SBSW_FRTP_TIMEOUT_AND_ACTION_OF_TXSM
 \DESCRIPTION    Functions FrTp_TxSm_TimeoutOf, FrTp_TxSm_ActionOf are called with valid parameters.
                 1. Parameter pTxSm is valid as described in justification SBSW_FRTP_VALID_WRAPPED_TXSM_IDX
                 2. Parameter txSmIdx is valid as described in justification SBSW_FRTP_VALID_WRAPPED_TXSM_IDX
 \COUNTERMEASURE \N refer to countermeasures of justification SBSW_FRTP_VALID_WRAPPED_TXSM_IDX

\ID              SBSW_FRTP_INITIALIZE_DECOUP_ADMIN_DATA
 \DESCRIPTION    Pointer write access to pDecoupAdminData is to a valid pointer.
                 Pointer pDecoupAdminData is initialized as described by justification SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX.
                 The precondition for that justification is that the affected tx-pdu (pointed to by pFrIfTxPdu which is initialized 
                 using member NxtFreePduIdx of valid caller-given pTxSm) is decoupled. This is assured by: if(FrTp_FrIf_IsDecoupPdu(*pFrIfTxPdu))
                 In addition the size of generated array FrTp_DecoupPduAdminData[] is checked to be valid by CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE.
 \COUNTERMEASURE \R if(FrTp_FrIf_IsDecoupPdu(*pFrIfTxPdu)) assures, that pDecoupAdminData is initialized with a valid element of generated 
                    array FrTp_DecoupPduAdminData[].
                 \M [CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE]
                 \M [CM_FRTP_FRIF_TX_PDUS_VALUES]

\ID              SBSW_FRTP_PDUR_COPYTXDATA_OPTIONALLY_COPY
 \DESCRIPTION    Function PduR_FrTpCopyTxData[s] is called with valid parameters.
                 1. Parameter pConnCfg->FrTpSduTxId is valid because of CM_FRTP_CONN_CFG_VALUES, assuming that pConnCfg is valid. pConnCfg is valid as it
                    read from pTxSm which is given by the caller with a valid value.
                 2. Parameter pApplPduInfo is valid, because is given by the caller with a valid value.
                 3. Parameter retry of type PduInfoType* is used in case a <Bus>Tp wants to retry parts of a data-transfer. Any retry feature 
                    is not supported by the MICROSAR communication stack and thus 
                 4. Parameter pAvailableTxData is valid because it is given by the caller with a valid value.
 \COUNTERMEASURE \M [CM_FRTP_CONN_CFG_VALUES]
                 \R pTxSm: [CM_FRTP_VALID_TXSM_PTR]
                 \R FrTp_TxSm_Item(pTxSm, ConnCfgPtr): [CM_FRTP_VALID_TXSM_PTR]
                 \R pApplPduInfo: [SBSW_FRTP_CALL_COPY_PAYLOAD_ONE_PDU]
                 \R pAvailableTxData: [SBSW_FRTP_CALL_COPY_PAYLOAD_ONE_PDU]

\ID              SBSW_FRTP_PDUR_COPYTXDATA_AVAIL_BUF
 \DESCRIPTION    Function PduR_FrTpCopyTxData[s] is called with valid parameters.
                 1. Parameter FrTpSduTxId is valid because it is given by the caller with a valid value.
                 2. Parameter pApplPduInfo is valid because it is given by the caller with a valid value. In addition the member SduLength of 
                    pApplPduInfo is set to 0. This leads to PduR_FrTpCopyTxData[s] ignoring the value member SduDataPtr, i.e. it does not have 
                    to be valid, at all.
                 3. Parameter retry of type PduInfoType* is used in case a <Bus>Tp wants to retry parts of a data-transfer. Any retry feature 
                    is not supported by the MICROSAR communication stack and thus 
                 4. Parameter &availableTxBuffer is valid because it is the address of a local variable.
 \COUNTERMEASURE \R FrTpSduTxId: Is given by the caller with a valid value.
                 \R pApplPduInfo: [SBSW_FRTP_RETRIEVE_AVAIL_TX_DATA]
                 \R pAvailableTxData: [SBSW_FRTP_RETRIEVE_AVAIL_TX_DATA]

\ID              SBSW_FRTP_CALL_COPY_PAYLOAD_ONE_PDU
 \DESCRIPTION    The function FrTp_TxSm_CopyPayloadOnePdu is called with valid parameters.
                 1. Parameter pTxSm is valid because of a valid txSmIdx given by the caller as described by justification 
                    SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable.
                 3. Parameter &availableTxData is valid because it is the address of a local variable.
 \COUNTERMEASURE \R pTxSm: Valid as described by justification SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX.

\ID              SBSW_FRTP_RETRIEVE_AVAIL_TX_DATA
 \DESCRIPTION    The function FrTp_TxSm_RequestAvailableTxData is called with valid parameters.
                 1. Parameter pConnCfg->FrTpSduTxId is valid because FrTpSduTxId is checked by CM_FRTP_CONN_CFG_VALUES. 
                    And pConnCfg is retrieved based on txSmIdx which is valid as demanded by PRE_FRTP_VALID_ACTIVE_TX_SM_IDX. 
                    Refer to runtime CM 1.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable. In addition its members are 
                    valid, because:
                              applPduInfo.SduDataPtr is initialized always prior the switch statement according to runtime CM 2.
                              applPduInfo.SduLength does not have to be initialized because the function called 
                              (FrTp_TxSm_RequestAvailableTxData) modifies this member in order to request the length of tx-data, 
                              available.
                 3. Parameter &availableTxData is valie because it is the address of a local variable. Refer to runtime CM 3.
 \COUNTERMEASURE \M [CM_FRTP_CONN_CFG_VALUES]
                 \R 1. pConnCfg is valid from pTxSm from txSmIdx from caller as demanded by [CM_FRTP_RXTX_SM_IDX]
                 \R [CM_FRTP_TX_BUF_SIZE]

\ID              SBSW_FRTP_STORE_VALID_TXSM_IDX_FROM_CALLER
 \DESCRIPTION    Macro FrTp_FrIf_ExpectTxConfForTxPduOfTxSm stores the given txSmIdx in generated array FrTp_TxFrIfPending[] at index intTxPduIdx.
                 Macro parameter intTxPduIdx is valid because it is read from pTxSm which is retrieved based on parameter txSmIdx which is valid 
                 as demanded by CM_FRTP_RXTX_SM_IDX.
 \COUNTERMEASURE \N CM_FRTP_RXTX_SM_IDX

\ID              SBSW_FRTP_WRITE_TX_SM_PTR_FROM_VALID_ACTIVE_TX_SM_IDX
 \DESCRIPTION    Write access to pointer pTxSm is valid because it is read from generated array FrTp_TxState[] using valid parameter txSmIdx which 
                 is valid as demanded by CM_FRTP_RXTX_SM_IDX.
 \COUNTERMEASURE \N CM_FRTP_RXTX_SM_IDX

\ID              SBSW_FRTP_ASSEMBLE_TPCI_TX
 \DESCRIPTION    The functions FrTp_Util_WriteML, FrTp_Util_WriteFPL, FrTp_Util_WriteFType, FrTp_Util_WriteBC are called with valid parameters.
                 - Parameters FrTp_TxSm_Item(pTxSm, [DataLength|CopiedDataLength]) are valid because of this functions precondition 
                   PRE_FRTP_VALID_ACTIVE_TX_SM_PTR.
                 - Parameter tpciBuffer is valid because it is local array of type uint8[], i.e. the address of a local array (which, thus, is valid)
                   is given as pointer to the affected functions.
                 In addition the size of local array tpciBuffer is determined by a #define which is cross-checked with the #defines used by 
                 FrTp_Util_WriteML, FrTp_Util_WriteFPL by CM_FRTP_TPCI_MAX_LENGTH.(This item formerly was called SBSW_FRTP_ASSEMBLE_TPCI_TX, 
                 also refer to SBSW_FRTP_ASSEMBLE_TPCI_RX)
 \COUNTERMEASURE \M [CM_FRTP_TPCI_MAX_LENGTH]

\ID              SBSW_FRTP_WRITE_TPCI_ARRAY
 \DESCRIPTION    Refer to SBSW_FRTP_WRITE_TPCI_ARRAY
 \COUNTERMEASURE \N Refer to the CMs of SBSW_FRTP_WRITE_TPCI_ARRAY

\ID              SBSW_FRTP_TXSM_FRIF_TRANSMIT
 \DESCRIPTION    Function FrTp_TxSm_FrIfTransmit is called with valid parameters.
                 1. Parameter &TPCI is valid because it is a pointer to a local variable.
                    In addition the variable is properly initialized to point to the local tpciBuffer. The length of the FrTp-pdu to be assembled 
                    in this function is determined by one of these ways:
                    a) FrTp_GetFmtOffsetFromPci(FrTp_PCISTF) ==> FrTp_PCISTF is a concrete value of a PCI-type of an FrTp-tx-pdu and thus that 
                       macro returns a valid PCI-length
                    b) FrTp_GetFmtOffsetFromPci(FrTp_TxSm_Item(pTxSm, CurrPCI)) ==> The value of CurrPCI is used as PCI-type. This value is valid 
                       because of PRE_FRTP_VALID_ACTIVE_SM which is part of PRE_FRTP_VALID_ACTIVE_TX_SM_PTR which is valid for the function 
                       FrTp_TxSm_ActionOf.
                 2. Parameter &payload is valid, because it is a pointer to a local variable. CM_FRTP_TX_BUF_CHANNEL_SIZE ensures that the local variabe 
                    points to a valid array. In addition the variable is properly initialized to indicate "no payload" because tx-state-machines never transmit 
                    FrTp-pdus containing payload.
                 3. Parameter txSmIdx is valid, because it is given by the caller with a valid value.
                 The function FrTp_TxSm_FrIfTransmit may only be called in case the tx-pdu-pool configured for the FrTp_Connection that is currently 
                 active in the tx-state-machine still has at least one tx-pdu 'free for use'. This is ensured by runtime CM 1.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \R 1. if(FrTp_TxSm_Item(pTxSm, NxtFreePduIdx) != FrTp_NoPdu), immediately PRIOR to the call to FrTp_TxSm_ActionOf 
                    (which is the only caller of FrTp_TxSm_FrIfTransmit) ensures that the semantics of the call to FrTp_TxSm_FrIfTransmit are correct.

\ID              SBSW_FRTP_EVAL_FRIF_TRANSMIT_RETVAL
 \DESCRIPTION    Function FrTp_TxSm_EvalFrIfTransmitRetVal is called with valid parameters.
                 1. Parameter pTxSm is valid because of PRE_FRTP_VALID_ACTIVE_SM which is part of PRE_FRTP_VALID_ACTIVE_TX_SM_PTR which is valid for 
                    the function FrTp_TxSm_ActionOf.
                 2. Parameter txResult is valid because it is a local variable.
                 3. & 4. Parameters are of the range of [FrTp_TxSm_WaitForTxConfNonBurstSTFseg, FrTp_TxSm_WaitForTxConfNonBurstSTFunseg] which complies 
                    to the precondition PRE_FRTP_VALID_TX_STATE_PARAM of function FrTp_TxSm_EvalFrIfTransmitRetVal.
 \COUNTERMEASURE \R Refer to PRE_FRTP_VALID_ACTIVE_TX_SM_PTR of function FrTp_TxSm_ActionOf

 \ID              SBSW_FRTP_VALID_DECOUP_ADMIN_DATA_IN_TRIG_TX
 \DESCRIPTION    Note: This justification was written to be referenced by all functions called by FrTp_TriggerTransmit.
                       1. Each of these functions is referenced as "the function" in the following section.
                       2. Each parameter that is contained in generated array FrTp_DecoupPduAdminData[] of type 
                          FrTp_DecoupPduAdminType is referenced as "this item" in the following section.

                 The value of this item is read from generated array FrTp_DecoupPduAdminData[] using macro 
                 FrTp_FrIf_GetDecoupAdminById using FrIfTxPduId as id.
                 This macro reads FrTp_DecoupPduAdminData[] at the position determined by element-member DecoupPduAdminDataOffset 
                 from generated array FrTp_FrIfTxPdus[] at position FrIfTxPduId. However FrIfTxPduId comes valid from caller.

                 The lookup using the member DecoupPduAdminDataOffet is valid only in case the uppermost caller 
                 FrTp_TriggerTransmit()  ensures that this function is called only for tx-pdus that:
                 a) are configured to be decoupled: Refer to runtime CM 2.
                 b) were requested to be sent using function FrIf_Transmit. Refer to runtime CM 1.
                 By a) it is ensured that the struct of type FrTp_DecoupPduAdminData does always belong to a valid decoupled
                       FrIf tx-pdu.
                 By b) it is ensured that the struct of type FrTp_DecoupPduAdminData is always correctly set with valid values 
                       of a running transmission. This affects these (all) members of pDecoupAdminData:
                       i)   ConnCfgPtr refers to a valid and active FrTp_Connection. Only for such connections FrIf_Transmit 
                            will be called and the flag checked at TAG SBSW_FRTP_TRIGGER_ONLY_TRANSMITTED_PDUS will be set.
                       ii)  PduInfoPayload refers to valid payload or, in case there is no payload to be sent (e.g. FC-pdus or 
                            LF-pdus without payload), its member SduDataPtr is plainly NULL.
                       iii) This plain setting is done in case the (decoupled) tx-pdu is prepared to be sent via FrIf_Transmit.
                       iv)  PduLengthTPCI is always set non-zero (there is no FrTp-pdu that contains no PCI)
                       v)   TPCIData: is always filled with PCI-data (there is no FrTp-pdu that contains no PCI)
                            ==> These values are centrally and uniformly set all over the FrTp by calling function 
                                FrTp_FrIf_TransmitPduForConn which is used by both rx- and tx-state-machines
                 The runtime CM 2. ensures that the function is only called in case this preparation has been done.

                 During the lookups described above the generated arrays FrTp_FrIfTxPdus[] and FrTp_DecoupPduAdminData[] are used:
                 The validity of generated array FrTp_FrIfTxPdus[] is checked by CM_FRTP_FRIF_TX_PDUS_SIZE.
                 The validity of generated array FrTp_DecoupPduAdminData[] and the constants DecoupPduAdminDataOffset to access 
                 it ist checked by CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE.
 \COUNTERMEASURE \R 1. The code at tag SBSW_FRTP_TRIGGER_ONLY_TRANSMITTED_PDUS ensures that helper functions of 
                       FrTp_TriggerTransmit are called only in case the tx-pdu identified by FrIfTxPduId was actually requested
                        to be sent using function FrIf_Transmit.
                 \R 2. The code at tag SBSW_FRTP_TRIGGER_ONLY_DECOUPLED_PDUS ensures that helper functions of 
                       FrTp_TriggerTransmit are called only in case the tx-pdu identified by FrIfTxPduId is configured to be 
                       decoupled.
                 \M [CM_FRTP_FRIF_TX_PDUS_SIZE]
                 \M [CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE]

\ID              SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU
 \DESCRIPTION    The function FrTp_Util_AssemblePdu is called with valid parameters and the pointer write access storing the 
                 functions' return value is to a valid pointer.
                 The pointer accessed is FrTpTxPduInfoPtr which is a parameter of FrTp_RxSm_TriggerTransmit and thus is valid, 
                 including its members SduDataPtr and SduLength.
                 I.e. FrTpTxPduInfoPtr->SduDataPtr may be passed to FrTp_Util_AssemblePdu and also its return value may be 
                 assigned to FrTpTxPduInfoPtr->SduLength. 
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_VALID_WRAPPED_RXSM_IDX
 \DESCRIPTION    FrTp_RxSm_OperateAllSms iterates rxSmIdx as long as FrTp_RxSm_MaxIterations is reached and checks rxSmIdx for 
                 wrap-around, i.e. rxSmIdx is valid: (rxSmIdx >= FrTp_CCfg_NumRxChan()).
                 The value of rxSmIdx (and the value FrTp_NumRxChan that is used for wrap-around-check) is cross-checked with 
                 generated array FrTp_RxState[] in CM_FRTP_RX_STATE_SIZE and is thus valid.
                 In addition any pRxSm that is looked up in generated array FrTp_RxState[] is valid too (also taking into account 
                 CM_FRTP_RX_STATE_SIZE)
 \COUNTERMEASURE \R pRxSm: [CM_FRTP_RXTX_SM_IDX]
                 \M pRxSm: [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_RX_CONN
 \DESCRIPTION    The function FrTp_FrIf_TransmitPduForConn is called with valid parameters.
                 1. Parameter pConnCfg is read from pRxSm which is looked up in generated array FrTp_RxState[] using index 
                    rxSmIdx which is given by the caller with a valid value.
                    The function FrTp_RxSm_FrIfTransmit is exclusively called by FrTp_RxSm_ActionOf which is called by 
                    FrTp_RxSm_OperateAllSms. The value of rxSmIdx is valid due to description and countermeasures in justification 
                    SBSW_FRTP_RXSM_FRIF_TRANSMIT.

                    In function FrTp_RxSm_ActionOf the function FrTp_RxSm_FrIfTransmit is only called in case the member State is 
                    not FrTp_RxSm_Idle and has a value that is suitable for sending an rx-related tx-pdu.
                    Only then the rx-state-machine is active i.e. its values set properly. Such allocation is uniformly done 
                    by FrTp_Rsrc_AllocateRxSm all over the FrTp.
                    This method sets pRxSm-member ConnCfgPtr atomically with all other items that signal an active 
                    rx-state-machine. Thus the local variable pConnCfg read from pRxSm is valid.
                 2. Parameter pFrIfTxPdu is looked up from generated array FrTp_FrIfTxPdus[] using the index NxtFreePduIdx 
                    read from the pRxSm.
                    The pRxSm member NxtFreePduIdx indicating that a free tx-pdu is available is checked by FrTp_RxSm_ActionOf 
                    as precondition to access that value, at all: if(FrTp_RxSm_Item(pRxSm, NxtFreePduIdx) != FrTp_NoPdu)
                    In addition the NxtFreePduIdx is always and exclusively set by function FrTp_FrIf_FindFreeTxPdu which
                    only returns a valid index to generated array FrTp_FrIfTxPdus[] or FrTp_NoPdu (refer to CM_FRTP_TX_PDU_POOL_OFFSETS_SIZE).
                    if(FrTp_FrIf_TransmitPduForConn(pConnCfg, pFrIfTxPdu, pTPCI, pPayload) == E_OK)
                 3. Parameter pTPCI is given by the caller with a valid value.
                 4. Parameter &payload is the address of a local variable initialized plainly to indicate: The 
                    rx-state-machines have no payload to transmit.
 \COUNTERMEASURE \M pFrIfTxPdu: [CM_FRTP_TX_PDU_POOL_OFFSETS_SIZE]
                 \M pRxSm: [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_STORE_VALID_RXSM_IDX_FROM_CALLER
 \DESCRIPTION    The macro FrTp_FrIf_ExpectTxConfForTxPduOfRxSm writes the value pRxSmIdx into generated array 
                 FrTp_RxFrIfPending[] at index local variable intTxPduIdx.
                 Local variable intTxPduIdx is valid because it is read from member NxtFreeTxPdu from pRxSm which is 
                 looked up using valid rxSmIdx from caller. Refer to CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_RXSM, below, for more details.
 \COUNTERMEASURE \M [CM_FRTP_RXTX_FRIF_PENDING_SIZE]
                 \R rxSmIdx: [CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_RXSM]

\ID              SBSW_FRTP_VALID_FRIF_TXPDU_IN_RXSM
 \DESCRIPTION    The function FrTp_FrIf_DecreaseNumFreePdusOverlapped is called with valid parameters.
                 Parameter pFrIfTxPdu is valid as it is looked up using valid member NxtFreeTxPdu from pRxSm which is looked
                 up using valid rxSmIdx from caller. Refer to CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_RXSM, below, for more details.
 \COUNTERMEASURE \R rxSmIdx: [CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_RXSM]

\ID              SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX
 \DESCRIPTION    The parameter pRxSm is looked up in generated array FrTp_RxState[] using index rxSmIdx which is given
                 by the caller with a valid value. In addition the rxSmIdx is cross-checked with generated array FrTp_RxState[] 
                 in CM_FRTP_RX_STATE_SIZE.
                 I.e. write accesses to pRxSm are valid and also the usage of pRxSm as function parameter leads to the function 
                 being called with valid parameters.
 \COUNTERMEASURE \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_RXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP
 \DESCRIPTION    The parameter pRxSm is looked up in generated array FrTp_RxState[] using the loop variable rxSmIdx which 
                 is valid because it is limited by the loop the write access is executed in: 
                            for(rxSmIdx = (uint8)0u; rxSmIdx < FrTp_CCfg_NumRxChan(); rxSmIdx++)
                 In addition the upper limit value of the loop FrTp_NumRxChan is cross-checked with generated array 
                 FrTp_RxState[] in CM_FRTP_RX_STATE_SIZE.
                 I.e. write accesses to pRxSm are valid and also the usage of pRxSm as function parameter leads to the function 
                 being called with valid parameters.
 \COUNTERMEASURE \R [CM_FRTP_RXTX_SM_IDX]
                 \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_EVAL_COPYRXDATA
 \DESCRIPTION    Function FrTp_RxSm_EvalBufReqRetVal is called with valid parameters.
                 Parameter dataPtr comes valid from caller.
                 Parameter rxSmidx comes valid from caller.
                 Parameter bReq is not used as index in the called function.
                 Parameters with value
                 [FrTp_RxSm_Idle|
                  FrTp_RxSm_WaitForSTFunsegmBuffer|
                  FrTp_RxSm_WaitForTxnNonBurstFC_CTS|
                  FrTp_RxSm_WaitForTxnNonBurstFC_WT|
                  FrTp_RxSm_WaitForTxnNonBurstFC_ABT|
                  FrTp_RxSm_WaitForTxnNonBurstFC_OVER|
                  FrTp_RxSm_WaitForSegmPdu|
                  FrTp_RxSm_WaitForCFbuffer|
                  FrTp_RxSm_Idle|
                  FrTp_RxSm_WaitForNxtFC_WT] are not used as index in the called function.
                 Parameter with value
                 [FrTp_PCISTFunseg|
                  FrTp_PCISTFseg|
                  FrTp_RxSm_Item(pRxSm, CurrPCI)] is not used as index in the called function.
                 The second parameter is always read or calculated based on pConnCfg->ConnCtrlPtr whereas ConnCtrlPtr is a struct with misc. values.
                 Possible values:
                 - FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeBr) * FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, MaxWft) - 1
                 - FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutAr)
                 - (lState == FrTp_RxSm_WaitForCFbuffer ? FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutCr) : FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutAr)),
                 - (lState == FrTp_RxSm_WaitForCFbuffer ? FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutCr) : FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutAr)),
                 ConnCtrlPtr is valid because pConnCfg is valid from caller and thus points to a struct of type FrTp_ConnCfgType which is retrieved from generated array FrTp_ConnCfg[].
                 Generated array FrTp_ConnCfg[] is checked to have valid members ConnCtrlPtr by CM_FRTP_CONN_CFG_VALUES, below.
 \COUNTERMEASURE \R dataPtr: is only written in after checking: (dataPtr != NULL_PTR) ([SBSW_FRTP_WAIT_BUF_UNSEGM], [SBSW_FRTP_WAIT_BUF_SEGM])
                 \M [CM_FRTP_CONN_CFG_VALUES]

\ID              SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER
 \DESCRIPTION    Function FrTp_RxSm_RequestAvailRxBufAndTryToCopy is called with valid parameters.
                 Parameter pRxSm is given by the caller with a valid value or is valid due to CM_FRTP_VALID_RXSM_PTR
                 Parameter rxSmIdx is given by the caller with a valid value.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_RECEIVED_LF
 \DESCRIPTION    Function FrTp_RxSm_ReceivedLF is called with valid parameters.
                 Parameter rxSmIdx is given by the caller with a valid value.
                 Parameter pRxSm is valid: Refer to CM_FRTP_VALID_RXSM_PTR
                 Parameters ML, FPL, desiredFPL are not used as index by function FrTp_RxSm_ReceivedLF.
 \COUNTERMEASURE \R pRxSm: [CM_FRTP_VALID_RXSM_PTR]
                 \M rxSmIdx: [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER_FROM_PDUR
 \DESCRIPTION    Function PduR_FrTpCopyRxData is called with valid parameters.
                 1. Parameter id is valid because it is read from FrTp_ConnCfgType-member FrTpSduRxId.
                    ConnCfgPtr, which is of type FrTp_ConnCfgType, is read from pRxSm which comes validly from caller.
                    The FrTp_ConnCfgType-member FrTpSduRxId is initialized with symbolic name values (SNV) generated by
                    the PduR itself, i.e. these values are implicitly valid.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable.
                    In addition this is a C-struct which is properly initialized using these values:
                    a) FrTp_RxSm_Item(pRxSm, ReceivedPduLen) is set to '0' which is a valid calling convention of the
                       PduR leading to dataPtr not being evaluated, because thus the length of the available rx-buffer
                       is retrieved.
                    b) dataPtr is not read by the PduR under the conditions described in a) and thus does not have to
                        be initialized explicitly.
                 3. Parameter &availableRxBuffer is valid because it is the address of a local variable.
  \COUNTERMEASURE \N No countermeasure required (refer to description above).

\ID              SBSW_FRTP_RECEIVED_STF
 \DESCRIPTION    Function FrTp_RxSm_ReceivedSTF is called with valid parameters.
                 Parameter is pConnCfg is given by the caller with a valid value.
                 Parameter dataPtr is calculated from parameter FrIf_PduInfoPtr->SduDataPtr to start at that arrays
                 offset FrTp_Util_OffsetTPCI.
                 The caller assures that the data array at least has a suitable length so that dataPtr points to a
                 memory location where a received FrTp-pdu can be found:
                 I.e. FrIf_PduInfoPtr->SduLength has to be > FrTp_Util_OffsetTPCI.
                 Also refer to TAG SBWS_FRTP_MINIMUM_TP_PDU_LENGTH
                 Parameters ML, FPL are not used as index by the called function.
                 Parameter is rxSmIdx is given by the caller with a valid value.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_RECEIVED_SEGM_PDU
 \DESCRIPTION    Function FrTp_RxSm_ReceivedSegmPdu is called with valid parameters.
                 Parameter dataPtr is calculated from parameter FrIf_PduInfoPtr->SduDataPtr to start at that arrays
                 offset FrTp_Util_OffsetTPCI.
                 The caller assures that the data array at least has a suitable length so that dataPtr points to a
                 memory location where a received FrTp-pdu can be found:
                 I.e. FrIf_PduInfoPtr->SduLength has to be > FrTp_Util_OffsetTPCI.
                 Also refer to TAG SBWS_FRTP_MINIMUM_TP_PDU_LENGTH.
                 Parameters ML, FPL, lCurrPCI, lengthOk are not used as index by the called function.
                 Parameter rxSmIdx is given by the caller with a valid value.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

\ID              SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF
 \DESCRIPTION    Function PduR_FrTpCopyRxData is called with valid parameters.
                 1. Parameter pRxSm->ConnCfgPtr->FrTpSduRxId is valid because:
                 a) pRxSm is valid from caller:
                    For all rx-state-machines (pointed to by pRxSm) ConnCfgPtr is centrally, uniformly and validly set
                    all over the FrTp-source-code by using function FrTp_Rsrc_AllocateTxSm (with valid parameters).
                 b) ConnCfgPtr is cleanly reset to NULL only in these functions:
                    - FrTp_Rsrc_InitAllSms
                    - FrTp_Rsrc_ReleaseRxSm
                    The function FrTp_RxSm_RequestAvailRxBufAndTryToCopy that contains the justification TAG
                    SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF is called by these functions:
                    - FrTp_RxSm_WaitForBufferSegmRxn
                    - FrTp_RxSm_WaitForBufferUnsegmRxn
                    These functions are only called by functions:
                    - FrTp_RxSm_TimeoutOf
                    - FrTp_RxSm_ActionOf
                    These functions are only called by function:
                    - FrTp_RxSm_OperateAllSms
                    which uses critical section FRTP_RE[QUEST|LEASE]_SM_ACCESS to prevent interruption by FlexRay
                    communication-events like:
                    - FrTp_RxIndication (+follow-up-calls:
                                          FrTp_RxSm_ReceivedSTF,
                                          FrTp_RxSm_ReceivedLF,
                                          FrTp_RxSm_FrIfTxConfirmation,
                                          FrTp_RxSm_ReceivedSegmPdu)
                    - FrTp_TxConfirmation (+follow-up-call: FrTp_RxSm_FrIfTxConfirmation)
                    which could possibly use FrTp_Rsrc_ReleaseRxSm to reset ConnCfgPtr to NULL or Ecu-management-related 
                    events like
                    - FrTp_Init where FrTp_Rsrc_ReleaseRxSm is used as helper function.
                    which uses critical section FRTP_RE[QUEST|LEASE]_SM_ACCESS to prevent interruption by FlexRay
                    communication-events like the events listed above in this chapter.
                 ==> No setting to NULL of ConnCtrlPtr possible by FlexRay-communication- or Ecu-management events
                     because the critical section FRTP_RE[QUEST|LEASE]_SM_ACCESS prevents calling FrTp_Rsrc_ReleaseRxSm
                     during the runtime of FrTp_RxSm_OperateAllSms.
                 c) FrTpSduRxId is valid because ConnCfgPtr is set valid in FrTp_Rsrc_AllocateRxSm() by a caller that uses
                    an element of generated array FrTp_ConnCfg[]: Refer to CM_FRTP_CONN_CFG_VALUES.
                 
 \COUNTERMEASURE \R Critical section FRTP_RE[QUEST|LEASE]_SM_ACCESS prevents the interruption of FrTp_MainFunction
                 \M [CM_FRTP_CONN_CFG_VALUES]

\ID              SBSW_FRTP_WAIT_BUF_UNSEGM
 \DESCRIPTION    Function FrTp_RxSm_WaitForBufferUnsegmRxn is called with valid parameters.
                 1. Parameter pRxSm is given by the caller with a valid value.
                    In addition the length of generated array FrTp_RxState[] is checked by CM_FRTP_RX_STATE_SIZE.
                 2. Parameter isTimeout (TRUE) is not used as an index by the called function.
                 3. Parameter rxSmIdx is given by the caller with a valid value.
 \COUNTERMEASURE \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_WAIT_BUF_SEGM
 \DESCRIPTION    Function FrTp_RxSm_WaitForBufferSegmRxn is called with valid parameters.
                 1. Parameter pRxSm is given by the caller with a valid value.
                    In addition the length of generated array FrTp_RxState[] is checked by CM_FRTP_RX_STATE_SIZE.
                 2. Parameter isTimeout (TRUE) is not used as an index by the called function.
                 3. Parameter rxSmIdx is given by the caller with a valid value.
 \COUNTERMEASURE \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_ASSEMBLE_TPCI_RX
 \DESCRIPTION    The functions FrTp_Util_WriteML, FrTp_Util_WriteFPL, FrTp_Util_WriteFType, FrTp_Util_WriteBC are called
                 with valid parameters.
                 - Parameters FrTp_TxSm_Item(pTxSm, [DataLength|CopiedDataLength]) are valid because of this functions 
                   precondition PRE_FRTP_VALID_ACTIVE_TX_SM_PTR.
                 - Parameter tpciBuffer is valid because it is local array of type uint8[], i.e. the address of a local 
                   array (which, thus, is valid) is given as pointer to the affected functions. 
                   In addition the size of local array tpciBuffer is determined by a #define which is cross-checked with 
                   the #defines used by FrTp_Util_WriteML, FrTp_Util_WriteFPL by CM_FRTP_TPCI_MAX_LENGTH. 
 \COUNTERMEASURE \M [CM_FRTP_TPCI_MAX_LENGTH]

\ID              SBSW_CALC_BFS_VALUE
 \DESCRIPTION    Function FrTp_RxSm_CalcBfsValue is called with valid parameters.
                 1. Parameter pRxSm is valid because it is looked up using rxSmIdx which is given by the caller with a 
                    valid value.
                 2. Parameter ConnCtrlPtr is read from pConnCfg which is valid because it is read from a valid pRxSm as 
                    described in SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF.
                 ConnCtrlPtr is checked for validity according to CM_FRTP_CONN_CFG_VALUES.
 \COUNTERMEASURE \R pRxSm: [CM_FRTP_VALID_RXSM_PTR]
                 \R [SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_FIND_FREE_TX_PDU_FOR_RXSM
 \DESCRIPTION    Function FrTp_FrIf_FindFreeTxPdu is called with valid parameters.
                 1. Parameter pPoolCfg and
                 2. Parameter pPoolDataUsed
                    are both read from their associated, generated configuration and runtime-data arrays:
                    - FrTp_TxPduPools (valid according to CM_FRTP_RXTX_PDU_POOLS_SIZE)
                    - FrTp_PoolData (valid according to CM_FRTP_POOL_DATA_SIZE)
                    using index poolOffset which is read from the pointer pConnCfg which is valid due to runtime CM 1.
                    The value for poolOffset in the FrTp_ConnCfg[] array is checked to be valid in CM_FRTP_CONN_CFG_VALUES.

                    Concept for tx-pdu-pools in FrTp_Connections doing reception (in rx-state-machines):
                      It is possible to NOT configure a tx-pdu-pool for an FrTp_Connection doing reception of FrTp-data:
                      Whether a FrTp_Connection has configured a tx-pdu-pool or not is indicated by these values of 
                      FrTp_ConnCfg-initializer-struct-list member 'poolOffset':
                        == FrTp_NumTxPduPools --> No pool is configured
                        < FrTp_NumTxPduPools --> Pool is configured
                      Any FrTp_Connection is only allowed to get active with segmented transmission (which requires tx-pdus)
                      in a rx-state-machine in case a tx-pdu-pool is configured.
                      This is checked once at that point of time when a FrTp_RxIndication is called by FrIf and the FrTp_Connection
                      shall get active.
                      This concept can be seen according to the macros:
                      - FrTp_FrIf_GetTxPduPoolDataPtrByCheckedOffset being used only in FrTp_RxIndication (i.e. the function where 
                        reception processes start) and
                      - FrTp_FrIf_GetTxPduPoolDataPtrByOffset being used at all other locations in the FrTp (i.e. helpers called by 
                        FrTp_MainFunction).
                 ==> Thus pPoolCfg and pPoolDataUsed are valid.
                 3. BandwidthLimitation is not used as index in function FrTp_FrIf_FindFreeTxPdu.
 \COUNTERMEASURE \R [SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF]
                 \M [CM_FRTP_CONN_CFG_VALUES]
                 \M [CM_FRTP_RXTX_PDU_POOLS_SIZE]
                 \M [CM_FRTP_POOL_DATA_SIZE]

\ID              SBSW_FRTP_RXSM_FRIF_TRANSMIT
 \DESCRIPTION    Function FrTp_RxSm_FrIfTransmit is called with valid parameters.
                 1. Parameter &TPCI is valid because it is a pointer to a local variable.
                    In addition the variable is properly initialized to point to the local tpciBuffer and its length according to 
                    the FrTp-pdu assembled in this function.
                    If this function has decided to not send a FrTp-pdu this is indicated by TPCI-member SduLength which is checked 
                    prior to FrTp_RxSm_FrIfTransmit. Refer to runtime CM 1.
                 2. Parameter &payload is valid, because it is a pointer to a local variable.
                    In addition the variable is properly initialized to indicate "no payload" because rx-state-machines never transmit 
                    FrTp-pdus containing payload.
                 3. Parameter rxSmIdx is valid, because it is given by the caller with a valid value.
                 The function FrTp_RxSm_FrIfTransmit may only be called in case the rx-pdu-pool configured for the FrTp_Connection that 
                 is currently active in the rx-state-machine still has at least one tx-pdu 'free for use'. This is ensured by runtime CM 2.
 \COUNTERMEASURE \R 1. if(TPCI.SduLength > 0u) ensures that FrTp_RxSm_FrIfTransmit is called only in case a valid TPCI has been prepared.
                 \R 2. if(FrTp_RxSm_Item(pRxSm, NxtFreePduIdx) != FrTp_NoPdu) ensures that the semantics of the call to FrTp_RxSm_FrIfTransmit
                       are correct.

\ID              SBSW_FRTP_EVAL_BUFREQ_RET_VAL
 \DESCRIPTION    Function VStdLib_MemCpy is called with valid parameters.
                 1. Parameter FrTp_VCfg_RxBuf(rxSmIdx) is valid because rxSmIdx is valid from caller and using this valid the 
                    generated FrTp_RxBuf[] array is accessed which is checked by CM_FRTP_RX_BUF_SIZE.
                 2. Parameter dataPtr is given by the caller with a valid value. The caller has called PduR_FrTpCopyRxData and 
                    has gotten a delay-indication from PduR and thus passes the received data the dataPtr for intermediate storing.
                 3. Parameter FrTp_RxSm_Item(pRxSm, ReceivedPduLen) is a member of pRxSm which is valid according to CM_FRTP_RX_STATE_SIZE. 
                    and CM_FRTP_VALID_RXSM_PTR.
                    The member ReceivedPduLen is the data-length used by the memcpy-function called to overwrite memory.
                    It is set in the FrTp either to
                    a) '0' after the payload has been copied successfully to the PduR in function FrTp_RxSm_CopyRxData.
                    b) FPL of the FrTp-pdu received.
                    For case b) FPL is valid because:
                    i) In case the caller of FrTp_RxSm_EvalBufReqRetVal is FrTp_RxSm_ReceivedSTF then the FPL value is checked 
                       by -again- the caller of FrTp_RxSm_ReceivedSTF, already.
                       Then this is FrTp_RxSm_FrIfRxIndication (called by FrTp_FrIf_RxIndication, called by FrTp_RxIndication)
                       In case FrTp_RxSm_FrIfRxIndication is called from there, CM_FRTP_VALID_RXSM_PTR has passed successfully, assuring 
                       the validity of the FPL assigned to FrTp_RxSm_Item(pRxSm, ReceivedPduLen).
                       The variable maxCfgedRxPayloadLen used in runtime CM 1. is a variable calculated from MSSV checked configuration 
                       items and is valid because:
                       - Refer to CM_FRTP_FRIF_RX_PDUS_SIZE.
                       - Calculation is done using DET-checked parameter FrIfRxPduId which is valid due to CM_FRTP_RX_BUF_CHANNEL_SIZE.
                       The buffer that is used to intermediately store the STFs payload in the call to VStdLib_MemCpy is a C-union pointed 
                       to by generated array FrTp_RxBuf[] which is valid due to CM_FRTP_RX_BUF_SIZE and CM_FRTP_RX_BUF_CHANNEL_SIZE.
                    ii) In case the caller of FrTp_RxSm_EvalBufReqRetVal is FrTp_RxSm_ReceivedSegmPdu the same as for point i) applies.
                        However then the parameter lengthOk (Refer to runtime CM 1.) is checked only there and combined with additional 
                        FrTp-protocol-specific checks.
                    iii) In case the caller is [FrTp_RxSm_WaitForBufferUnsegmRxn|FrTp_RxSm_WaitForBufferSegmRxn] then the parameter dataPtr 
                         is NULL_PTR which leads to VStdLib_MemCpy not being called at all.
 \COUNTERMEASURE \M [CM_FRTP_RX_BUF_SIZE]
                 \R pRxSm: [CM_FRTP_VALID_RXSM_PTR]
                 \M [CM_FRTP_RX_STATE_SIZE]
                 \R 1. Refer to function FrTp_RxSm_FrIfRxIndication, code:
                       switch(lCurrPCI)
                         [..]
                         case FrTp_PCISTF:
                           [..]
                           lengthOk = (uint8)(    (FPL > 0u)
                                               && (ML > 0u)
                                               && (FPL <= maxCfgedRxPayloadLen)
                                               && (rxedSduPayloadLen >= FPL)
                                               && (maxCfgedRxPayloadLen >= rxedSduPayloadLen)
                                             );
                           [..]
                           if(lengthOk == 1u)
                             FrTp_RxSm_ReceivedSTF();
                 \M [CM_FRTP_FRIF_RX_PDUS_SIZE]
                 \M [CM_FRTP_RX_BUF_CHANNEL_SIZE]
                 \M [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_RX_IND_EARLIER_THAN_TX_CONF
 \DESCRIPTION    The function FrTp_RxSm_TolerateRxIndEarlierThanTxConf is called with valid parameters.
                 1. Parameter pRxSm is valid due to CM_FRTP_RX_STATE_SIZE.
                 2. [CM_FRTP_RXTX_SM_IDX]
 \COUNTERMEASURE \R pRxSm: [CM_FRTP_VALID_RXSM_PTR]
                 \M pRxSm: [CM_FRTP_RX_STATE_SIZE]

\ID              SBSW_FRTP_START_OF_RECEPTION
 \DESCRIPTION    The function PduR_FrTpStartOfReception is called with valid parameters.
                 1. Parameter id is valid because it is read from FrTp_ConnCfgType-member FrTpSduRxId. pConnCfg is read from pRxSm.
                    pRxSm is valid due to CM_FRTP_RX_STATE_SIZE.
                    pConnCfg from pRxSm is valid due to CM_FRTP_VALID_RXSM_PTR.
                    The FrTp_ConnCfgType-member FrTpSduRxId is initialized with symbolic name values (SNV) generated by the PduR 
                    itself, i.e. these values are implicitly valid.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable.
                    In addition this is a C-struct which is properly initialized using these values:
                    a) SduLength = FrTp_RxSm_Item(pRxSm, ReceivedPduLen) is valid as described in section 3. Parameter 
                       FrTp_RxSm_Item(pRxSm, ReceivedPduLen) in justification SBSW_FRTP_EVAL_BUFREQ_RET_VAL.
                    b) SduDataPtr = dataPtr is given by the caller with a valid value.
                 3. Parameter FrTp_RxSm_Item(pRxSm, DataLength) is centrally and uniformly set in function FrTp_Rsrc_AllocateRxSm 
                    all over the FrTp.
                    In order to do so a value ML is used by the callers of FrTp_Rsrc_AllocateRxSm which is read using function 
                    FrTp_Util_ReadML which assembles a 16-bit value at max. by reading 2 byte values.
                    Thus at max. a value of 16_BIT_MAX (65535) can be in ML which is ISO10681-2 compliant and thus supported all 
                    over the FrTp.
                 4. Parameter &availableRxBuffer is valid because it is the address of a local variable. It is an out-variable - 
                    however it is nevertheless initialized.
 \COUNTERMEASURE \R pRxSm: [CM_FRTP_VALID_RXSM_PTR]
                 \M pRxSm: [CM_FRTP_RX_STATE_SIZE]
                 \R [CM_FRTP_FRIF_TRANSMIT_PDU_FOR_CONN]

\ID              SBSW_FRTP_PDUR_COPYRXDATA_ACTUALLY_COPY
 \DESCRIPTION    Function PduR_FrTpCopyRxData is called with valid parameters.
                 1. Parameter id is valid because it is read from FrTp_ConnCfgType-member FrTpSduRxId. pConnCfg is read from pRxSm.
                    pRxSm is valid due to CM_FRTP_RX_STATE_SIZE.
                    pConnCfg from pRxSm is valid due to runtime CM 1.
                    The FrTp_ConnCfgType-member FrTpSduRxId is initialized with symbolic name values (SNV) generated by the PduR 
                    itself, i.e. these values are implicitly valid.
                 2. Parameter &applPduInfo is valid because it is the address of a local variable.
                    In addition this is a C-struct which is properly initialized using these values:
                    a) FrTp_RxSm_Item(pRxSm, ReceivedPduLen) is valid as described in section 3. Parameter FrTp_RxSm_Item(pRxSm, ReceivedPduLen) 
                       in justification SBSW_FRTP_EVAL_BUFREQ_RET_VAL.
                    b) dataPtr is given by the caller with a valid value.
                 3. Parameter &availableRxBuffer is valid because it is the address of a local variable.
 \COUNTERMEASURE \M pRxSm: [CM_FRTP_RX_STATE_SIZE]
                 \R [CM_FRTP_FRIF_TRANSMIT_PDU_FOR_CONN]

\ID              SBSW_FRTP_WRITE_ML
 \DESCRIPTION    The caller of function FrTp_Util_WriteML expects to write the function to write to array dataPtr[] at these offsets:
                 1. FrTp_Iso_MlHighByteOffset
                 2. FrTp_Iso_MlLowByteOffset
 \COUNTERMEASURE \R dataPtr: [SBSW_FRTP_ASSEMBLE_TPCI_RX], [SBSW_FRTP_ASSEMBLE_TPCI_TX]

\ID              SBSW_FRTP_ASSEMBLE_PDU_ADDR
 \DESCRIPTION    The caller of function FrTp_Util_AssemblePdu expects the function to write to array pPduBuffer[] at these offsets:
                 FrTp_Util_AddrOffsetByte[1|2|3|4] in order to write the 4 address-bytes to the pdu.
                 The position of the address information in the pPduBuffer is at the very beginning of the pPduBuffer, i.e. the write 
                 access happens at bytes 0-3. This is known and intended by the caller.
 \COUNTERMEASURE \R pPduBuffer: [SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU], [BSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU]

\ID              SBSW_FRTP_ASSEMBLE_PDU_TPCI
 \DESCRIPTION    The caller of function FrTp_Util_AssemblePdu expects the function to copy the TPCI information from the SduDataPtr 
                 of the given pTPCI to the pPduBuffer.
                 The position of the TPCI information in the pPduBuffer is _after_ the address bytes, i.e. the write access happens 
                 at posInFrame which is 4 at that time. This is known and intended by the caller.
                 The copying is done using VStdLib_MemCpy. The parameters of VStdLib_MemCpy are valid, because they are calculated 
                 based on parameters given by the caller.
 \COUNTERMEASURE \R pTPCI: [SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU], [BSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU]
                 \R pPduBuffer: [SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU], [BSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU]

\ID              SBSW_FRTP_ASSEMBLE_PDU_PAYLOAD
 \DESCRIPTION    The caller of function FrTp_Util_AssemblePdu expects the function to copy the payload from the SduDataPtr of the 
                 given pPayload to the pPduBuffer.
                 The position of the payload information in the pPduBuffer is _after_ the TPCI information, i.e. the write access 
                 happens at posInFrame. This is known and intended by the caller.
                 The copying is done using VStdLib_MemCpy. The parameters of VStdLib_MemCpy are valid, because they are calculated 
                 based on parameters given by the caller.
 \COUNTERMEASURE \R pPayload: [SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU], [BSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU]
                 \R pPduBuffer: [SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU], [BSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU]

\ID              SBSW_FRTP_STRUCT_WRT_UNCHANGED
 \DESCRIPTION    Write access to the members of a struct using an unchanged pointer.
 \COUNTERMEASURE \N The original caller guarantees that the pointer references a valid struct.

SBSW_JUSTIFICATION_END */

/* MSSV Checks */

/* \CM CM_FRTP_QMDEFINES                             1. The FRTP_RUNTIME_MEASUREMENT_SUPPORT macro must be defined as STD_OFF.
                                                     2. The FRTP_FULL_AR421 macro must be defined as STD_OFF. */

/* \CM CM_FRTP_CONN_CFG_SIZE                         Ensure that the size of the array FrTp_ConnCfg[] matches the configuration value FrTp_NumConn. */

/* \CM CM_FRTP_CONN_CFG_VALUES                       Ensure that the initializers of array FrTp_ConnCfg[] have valid values:
                                                     * ConnIdx element is smaller than FrTp_NumConns
                                                     * ConnCtrlPtr is not NULL
                                                     * FrTpRxSduId and FrTpTxSduId are smaller than FRTP_INVALID_SNV 
                                                     * RxPduPoolOffset and TxPduPoolOffset are smaller than FrTp_NumRxPools and FrTp_NumTxPools.
                                                     * the value of the struct-member TxPduPoolOffset must be smaller than the array size of FrTp_TxPduPools[]
                                                     * the value of the struct-member RxPduPoolOffset must be smaller than the array size of FrTp_RxPduPools[] */

/* \CM CM_FRTP_CONN_STATE_SIZE                       Ensure that the size of the array FrTp_ConnState[] matches the configuration value FrTp_NumConn. */

/* \CM CM_FRTP_TX_STATE_SIZE                         Ensure that the size of the array FrTp_TxState[] matches the configuration value FrTp_NumTxChan. */

/* \CM CM_FRTP_RX_STATE_SIZE                         Ensure that the size of the array FrTp_RxState[] matches the configuration value FrTp_NumRxChan. */

/* \CM CM_FRTP_TX_BUF_SIZE                           Ensure that the size of the array FrTp_TxBuf[] matches the configuration value FrTp_NumTxChan. */

/* \CM CM_FRTP_FRIF_TX_BUF_SIZE                      Ensure that the size of the array FrTp_FrIfTxBuf[] is greater or equal to the maximum of all members Length of all
                                                     initializer structs of array FrTp_FrIfTxPdus[]. */

/* \CM CM_FRTP_TX_BUF_CHANNEL_SIZE                   Ensure that the size of the array FrTp_TxBuf_Channel<Idx>[] is greater or equal to the configuration value FrTp_MaxLengthTxPdus. */

/* \CM CM_FRTP_RX_BUF_SIZE                           Ensure that the size of the array FrTp_RxBuf[] matches the configuration value FrTp_NumRxChan. */

/* \CM CM_FRTP_RX_BUF_CHANNEL_SIZE                   Ensure that the size of the array FrTp_RxBuf_Channel<Idx>[] is greater or equal to the configuration value FrTp_MaxLengthRxPdus. */

/* \CM CM_FRTP_POOL_DATA_SIZE                        Ensure that the size of the array FrTp_PoolData[] matches the configuration value FrTp_NumTxPools. */

/* \CM CM_FRTP_POOLS_OF_TX_PDUS_SIZE                 Ensure that the size of the array FrTp_PoolsOfTxPdus[] matches the member NumPools of all initializer 
                                                     structs of type FrTp_TxPduInfoType that reference that array in their member PoolOffsetsPtr. */

/* \CM CM_FRTP_POOLS_OF_TX_PDUS_VALUES               Ensure that the value of struct-member PoolOffsetsPtr in the initializer list of generated struct-array FrTp_FrIfTxPdus[] is valid:
                                                     * the value of the array pointed to by struct-member PoolOffsetsPtr must be smaller than FrTp_NumTxPools
                                                     * the array size of the array pointed to by struct-member PoolOffsetsPtr must be smaller than the size of FrTp_TxPduPools[] */

/* \CM CM_FRTP_TX_PDU_POOL_OFFSETS_SIZE              Ensure that the size of the array FrTp_TxPduPoolOffsets[] matches the member NumPdus of all initializer
                                                     structs of type FrTp_TxPduPoolType that reference that array in their member PduOffsetsPtr. */

/* \CM CM_FRTP_RXTX_PDU_POOLS_SIZE                   Ensure that the size of the array FrTp_TxPduPools/FrTp_RxPduPools[] matches the configuration value 
                                                     FrTp_NumTxPools/FrTp_NumRxPools. */

/* \CM CM_FRTP_TX_PDU_POOLS_PDUOFFSETSPTR            Ensure that the value of struct-member PduOffsetsPtr in the initializer list of generated struct-array 
                                                     FrTp_TxPduPools[] is valid. 
                                                     PduOffsetsPtr points to an array of index values that are used to access generated array FrTp_FrIfTxPdus[] 
                                                     of size FrTp_NumFrIfTxPdus. Thus invalid means that at least one initializer value of the array pointed to 
                                                     by PduOffsetsPtr is larger or equal than the configuration value FrTp_NumFrIfTxPdus. */

/* \CM CM_FRTP_RXTX_PDU_POOLS_MINPDULEN              Ensure that the value of struct-member MinPduLen in the initializer list of generated struct-array 
                                                     FrTp_RxPduPools/FrTp_TxPduPools[] is smaller or equal than the configuration value 
                                                     FrTp_MaxLengthRxPdus/FrTp_MaxLengthTxPdus. */

/* \CM CM_FRTP_RXTX_FRIF_PENDING_SIZE                Ensure that the size of the arrays FrTp_RxFrIfPending[] and FrTp_TxFrIfPending[] match the configuration 
                                                     value FrTp_NumFrIfTxPdus. */

/* \CM CM_FRTP_FRIF_TX_PDUS_SIZE                     Ensure that the size of the array FrTp_FrIfTxPdus[] matches the configuration value FrTp_NumFrIfTxPdus. */

/* \CM CM_FRTP_FRIF_TX_PDUS_VALUES                   Ensure that the value of struct-member DecoupPduAdminDataOffset in the initializer list of generated struct-
                                                     array FrTp_FrIfTxPdus[] is valid. 
                                                     DecoupPduAdminDataOffset points to an array of index values that are used to access generated array 
                                                     FrTp_DecoupPduAdminData[]. Thus invalid means that at least one initializer value 
                                                     of the array pointed to by DecoupPduAdminDataOffset is larger or eqaul than the size of FrTp_DecoupPduAdminData[]. */

/* \CM CM_FRTP_DECOUP_PDU_ADMIN_DATA_SIZE            Ensure that the size of the array FrTp_DecoupPduAdminData[] is: 
                                                     * greater or equal to the configuration value FrTp_NumDecoupPdus.
                                                     * less or equal to the configuration value FrTp_NumFrIfTxPdus. */

/* \CM CM_FRTP_FRIF_RX_PDUS_SIZE                     Ensure that the size of the array FrTp_FrIfRxPdus[] matches the configuration value FrTp_NumFrIfRxPdus. */

/* \CM CM_FRTP_FRIF_RX_PDUS_VALUES                   Ensure that the values of struct-members Length, NumConns and ConnOffsetsPtr in the initializer list of generated 
                                                     struct-array FrTp_FrIfRxPdus[] are valid:
                                                     * Length must be less equal FrTp_MaxLengthRxPdus
                                                     * NumConns must be less equal FrTp_NumConn
                                                     * ConnOffsetsPtr references a FrTp_ConnsOfRxPdus[] which size must be eaual to FrTp_NumConn. */

/* \CM CM_FRTP_TX_SDU_SNV_TO_CONN_IDX_SIZE           Ensure that the size of the array FrTp_TxSduSnv2ConnIdx[] matches the configuration value FrTp_MaxTxSduId. */

/* \CM CM_FRTP_TX_SDU_SNV_TO_CONN_IDX_VALUES         Ensure that the the initializer values of FrTp_TxSduSnv2ConnIdx[] are smaller than FrTp_NumConn. */

/* \CM CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_SIZE            Ensure that the size of the array FrTp_TxPduSnv2TxPduIdx[] matches the configuration value FrTp_MaxFrIfTxPduId. */

/* \CM CM_FRTP_TX_PDU_SNV_TO_PDU_IDX_VALUES          Ensure that the the initializer values of FrTp_TxPduSnv2TxPduIdx[] are smaller than FrTp_NumFrIfTxPdus. */

/* \CM CM_FRTP_RX_SDU_SNV_TO_CONN_IDX_SIZE           Ensure that the size of the array FrTp_RxSduSnv2ConnIdx[] matches the configuration value FrTp_MaxRxSduId. */

/* \CM CM_FRTP_RX_SDU_SNV_TO_CONN_IDX_VALUES         Ensure that the the initializer values of FrTp_RxSduSnv2ConnIdx[] are smaller than FrTp_NumConn. */

/* \CM CM_FRTP_RX_PDU_SNV_TO_PDU_IDX_SIZE            Ensure that the size of the array FrTp_RxPduSnv2RxPduIdx[] matches the configuration value FrTp_MaxFrIfRxPduId. */

/* \CM CM_FRTP_RX_PDU_SNV_TO_PDU_IDX_VALUES          Ensure that the the initializer values of FrTp_RxPduSnv2RxPduIdx[] are smaller than FrTp_NumFrIfRxPdus. */

/* \CM CM_FRTP_CONFIG_VALUES                         Ensure that the the initializer values of generated struct FrTp_Config are valid:
                                                     1.) FrTp_NumRxChan <= 254 
                                                     2.) FrTp_NumTxChan <= 254
                                                     3.) FrTp_NumFrIfTxPdus <= 254
                                                     4.) FrTp_NumFrIfRxPdus <= 254
                                                     5.) FrTp_NumDecoupPdus <= 254
                                                     6.) FrTp_NumRxPools <= 254
                                                     7.) FrTp_NumTxPools <= 254
                                                     8.) FrTp_MaxRxSduId <= FRTP_INVALID_SNV
                                                     9.) FrTp_MaxTxSduId <= FRTP_INVALID_SNV
                                                     10.) FrTp_MaxFrIfRxPduId <= FRTP_INVALID_SNV
                                                     11.) FrTp_MaxFrIfTxPduId <= FRTP_INVALID_SNV. */

/* \CM CM_FRTP_TPCI_MAX_LENGTH                       Ensure that size of the byte arrays to store PCI data (FrTp_TPCIMaxLength) is larger than the constants 
                                                     (FrTp_FmtOffsetBc, FrTp_Iso_MlLowByteOffset, FrTp_Iso_MlHighByteOffset, FrTp_FmtOffsetFrameType, FrTp_FmtOffsetFPL) 
                                                     used to access these arrays. */

/* Runtime Checks */

/*\CM CM_FRTP_INV_PDU                                Recognize invalid Rx/Tx PDU and Rx/Tx SDU handles (not present in the configuration variant) 
                                                     and avoid their processing. */

/* \CM CM_FRTP_RXTX_SM_IDX                           The given index of a rx- or tx-state-machine has to valid.
                                                     Assure at runtime that [rx|Tx]SmIdx does never exceed the value [FrTp_NumRxChan|FrTp_NumTxChan]:
                                                     Refer to the following code snippets used in these methods [FrTp_Rsrc_FindRxSm|FrTp_Rsrc_FindTxSm] 
                                                     to determine a valid [rx|tx]SmIdx:
                                                     for(rxSmIdx = 0u; rxSmIdx < FrTp_CCfg_NumRxChan(); rxSmIdx++)
                                                     for(txSmIdx = 0u; txSmIdx < FrTp_CCfg_NumTxChan(); txSmIdx++) */

/* \CM CM_FRTP_RXTX_SM_IDX_CHECK                     Check at runtime whether [rx|tx]SmIdx is valid and if the value is invalid (because no free 
                                                     [rx|tx]-state-machine has been found or the FrTp_ConnState the value was read from is not active)
                                                     do not conduct the resulting action (e.g. call the function, do an array write access).
                                                     Refer to the following code snippets prior to the function call: 
                                                     (rxSmIdx != FrTp_NoSm) | (txSmIdx != FrTp_NoSm) */

/* \CM CM_FRTP_VALID_TXSM_PTR                        All parameters pTxSm that are looked up from generated array FrTp_TxState[] using the 
                                                     index txSmIdx are valid when txSmIdx is valid, e.g. from a function caller, because of 
                                                     CM_FRTP_TX_STATE_SIZE: Size of generated FrTp_TxState[] array has to be valid. */

/* \CM CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_TXSM         All parameters pFrIfTxPdu that are looked up from generated array FrTp_FrIfTxPdus[]
                                                     using the index NxtFreePduIdx read from the pTxSm are valid when the reading is done 
                                                     in function FrTp_TxSm_ActionOf because its caller conducts the checks as described 
                                                     in SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_TX_CONN */

/* \CM CM_FRTP_VALID_FRIF_TXPDU_PTR_IN_RXSM          All parameters pFrIfTxPdu that are looked up from generated array FrTp_FrIfTxPdus[]
                                                     using the index NxtFreePduIdx read from the pRxSm are valid when the reading is done 
                                                     in function FrTp_RxSm_ActionOf because its caller conducts the checks as described in 
                                                     SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_RX_CONN */

/* \CM CM_FRTP_VALID_RXSM_PTR                        All parameters pRxSm that are looked up from generated array FrTp_RxState[] using the 
                                                     index rxSmIdx are valid when rxSmIdx is valid, e.g. from a function caller, because of 
                                                     CM_FRTP_RX_STATE_SIZE: Size of generated FrTp_RxState[] array has to be valid. */

/* \CM CM_FRTP_FRIF_TRANSMIT_PDU_FOR_CONN            During a running reception the member ConnCfgPtr of a valid pRxSm [looked up in FrTp_RxState,
                                                     based on a valid rxSmIdx] is valid due to the \DESCRIPTION section of justification 
                                                     SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_RX_CONN */

/**********************************************************************************************************************
 *  END OF FILE: FrTp.c
 *********************************************************************************************************************/

