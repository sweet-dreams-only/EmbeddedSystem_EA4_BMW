/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FrIf_Priv.h
 *        \brief  FrIf private header file
 *
 *      \details  Private header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *********************************************************************************************************************/

#if (!defined FRIF_PRIV_H_)
# define FRIF_PRIV_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf.h"
# include "FrIf_Lcfg.h"
# include "FrIf_PBCfg.h"

# include "Fr.h"

# include "SchM_FrIf.h"

# if (FRIF_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif

# if (FRIF_PROD_ERROR_DETECT == STD_ON)
#  include "Dem.h"
# endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrIf.h */
# if (  (FRIF_SW_MAJOR_VERSION != (5u)) \
     || (FRIF_SW_MINOR_VERSION != (1u)) \
     || (FRIF_SW_PATCH_VERSION != (2u)) )
#  error "Version numbers of FrIf_Priv.h and FrIf.h are inconsistent"
# endif

/* Check the version of FrIf_Lcfg.h */
# if (  (FRIF_CFG_MAJOR_VERSION != (4u)) \
     || (FRIF_CFG_MINOR_VERSION != (1u)) )
#  error "Version numbers of FrIf_Priv.h and FrIf_Cfg.h are inconsistent"
# endif

/** 
* \defgroup IF Embedded Interfaces
* \brief Module Fr offers hardware independent interfaces to a FlexRay Communication Controller.
* \{
*/
/** \defgroup Generic Generic */
/** 
* \defgroup AbsT Absolute Timer Handling
* \brief The Absolute Timer Handling Interface wraps all services offered by the FlexRay Driver that influence the 
*        behaviour of the absolute timer.
* \trace CREQ-105566
*/
/** 
* \defgroup ComC Communication Control
* \brief The Communication Control Interface wraps the services offered by the FlexRay Driver that influence the POC state.
* \trace CREQ-105567
*/
/** 
* \defgroup CCS Controller Status
* \brief The Controller Status Interface wraps services related to the controller status offered by the FlexRay Driver.
* \trace CREQ-105570
*/
/** 
* \defgroup FrR Frame Reconfiguration
* \brief The Frame Reconfiguration Interface wraps the services offered by the FlexRay Driver that influence frame parameters
*        (e.g., base cycle, slot, repetition) at runtime.
* \trace CREQ-105568
*/
/** 
* \defgroup StateH State Handling
* \brief The State Handing Interface provides the state handling-related services of the FrIf.
*/
/** 
* \defgroup Trcv Transceiver Abstraction
* \brief The Transceiver Abstraction Interface wraps the following services offered by the FlexRay Transceiver Driver:
- services that enable/disable branches.
- wakeup-related services.
- status-related services.
* \trace CREQ-105571, CREQ-105573, CREQ-105572
*/
/** 
* \defgroup Wakeup Wakeup
* \brief The Wakeup Handling Interface wraps the wakeup-related services offered by the FlexRay Driver.
* \trace CREQ-105569
*/
/** 
* \defgroup PDU PDU Handling
* \brief The PDU Handing Interface provides all PDU handling-related services of the FrIf.
* \{
*/
/** \defgroup RX RX */
/** \defgroup TX TX */
/** \} */ 
/** \} */ 

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* File version information */
# define FRIF_PRIV_MAJOR_VERSION              (5u)
# define FRIF_PRIV_MINOR_VERSION              (1u)
# define FRIF_PRIV_PATCH_VERSION              (2u)

# define FRIF_IS_INITIALIZED_MAGIC_NUMBER  (uint16)0xCAFEu
# define FRIF_MAX_NUMBER_OF_REDUNDANT_PDUS (uint8)0x02u
# define NO_FLEXRAY_CYCLES                 (uint8)64u

# if (!defined FRIF_CUSTOM_JLE_SCHEDULING) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FRIF_CUSTOM_JLE_SCHEDULING        STD_OFF
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

# if !defined (FRIF_DUMMY_STATEMENT) /* COV_FRIF_MSR_COMPATIBILITY */
#  define FRIF_DUMMY_STATEMENT(arg)
# endif

# if !defined (FRIF_DUMMY_STATEMENT_CONST) /* COV_FRIF_MSR_COMPATIBILITY */
#  define FRIF_DUMMY_STATEMENT_CONST(arg)
# endif

# define NEXT_CYCLE(Cycle)     ((uint8)((uint8)((Cycle) + (uint8) 1u) & (uint8)0x3Fu))
# define PREVIOUS_CYCLE(Cycle) ((uint8)((uint8)((Cycle) + (uint8)63u) & (uint8)0x3Fu))

# define GET_TRANSCEIVER_INDEX(CtrlIdx, ChnlIdx)   ((2 * (CtrlIdx)) + (ChnlIdx))
# define FrIf_TimerIndex2FrTimerIndex(TimerIdx)    (TimerIdx)

# if (FrIf_CommonMaxNumberOfClusters > 1)
#  define FrIf_TimerIndex2FrCtrlIndex(TimerIdx)     (TimerIdx)
# else
#  define FrIf_TimerIndex2FrCtrlIndex(TimerIdx)     (0)
# endif

# if (!FrIf_IsPostbuild())
#  define FRIF_IS_INITIALIZED()        (FRIF_IS_INITIALIZED_MAGIC_NUMBER == FrIf_Status[0].IsInitialized)
# else
#  define FRIF_IS_INITIALIZED()        (0 != FrIf_Status[0].pConfigData)
# endif/* (!FrIf_IsPostbuild()) */

/* macros for accessing current state */
# define FrIf_IsOnline(ClstIdx)     (FRIF_STATE_ONLINE == FrIf_Status[(ClstIdx)].State)

/* PRQA S 0342 GLUEOPERATOR */ /* MD_FrIf_0342 */
# if (!FrIf_IsPostbuild())
#   define FrIf_GetCfgElem(Name)                        FrIf_##Name
#  if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#   define FrIf_GetCfgClstElemB(Name, ClstIdx)          FrIf_##Name
#   define FrIf_GetCfgClstElemC(Name, ClstIdx)          FrIf_##Name
#   define FrIf_GetCfgCtrlElemA(Name, CtrlIdx)          FrIf_##Name
#   define FrIf_GetCfgCtrlElemB(Name, CtrlIdx)          FrIf_##Name
#  else
#   define FrIf_GetCfgClstElemB(Name, ClstIdx)          FrIf_Clst2##Name[(ClstIdx)]
#   define FrIf_GetCfgClstElemC(Name, ClstIdx)          FrIf_Clst2##Name[(ClstIdx)]
#   define FrIf_GetCfgCtrlElemA(Name, CtrlIdx)          FrIf_Ctrl2##Name[(CtrlIdx)]
#   define FrIf_GetCfgCtrlElemB(Name, CtrlIdx)          FrIf_Ctrl2##Name[(CtrlIdx)]
#  endif
# else
#  define FrIf_GetCfgElem(Name)                         FrIf_Status[0].pConfigData->Name /* PRQA S 3410 */ /* MD_FrIf_3410 */
#  define FrIf_GetCfgCtrlElemA(Name, CtrlIdx)           FrIf_Status[(CtrlIdx)].p##Name
#  if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#   define FrIf_GetCfgClstElemB(Name, ClstIdx)          FrIf_Status[(ClstIdx)].pConfigData->p##Name
#   define FrIf_GetCfgClstElemC(Name, ClstIdx)          FrIf_Status[(ClstIdx)].pConfigData->Name /* PRQA S 3410 */ /* MD_FrIf_3410 */
#   define FrIf_GetCfgCtrlElemB(Name, CtrlIdx)          FrIf_Status[(CtrlIdx)].pConfigData->p##Name
#  else
#   define FrIf_GetCfgClstElemB(Name, ClstIdx)          FrIf_Status[(ClstIdx)].pConfigData->pClst2##Name[(ClstIdx)]
#   define FrIf_GetCfgClstElemC(Name, ClstIdx)          FrIf_Status[(ClstIdx)].pConfigData->pClst2##Name[(ClstIdx)]
#   define FrIf_GetCfgCtrlElemB(Name, CtrlIdx)          FrIf_Status[(CtrlIdx)].pConfigData->pCtrl2##Name[(CtrlIdx)]
#  endif
# endif
/* PRQA L:GLUEOPERATOR */ /* MD_FrIf_0342 */

# if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
#  define FrIf_GetUpdateBitBytePos()                    FrIf_GetCfgElem(UpdateBitBytePos)
# endif

/* Cluster-related data */
# define FrIf_GetJobDescriptor(ClstIdx, Idx)            FrIf_GetCfgClstElemB(JobDescriptors, ClstIdx)[(Idx)]
# define FrIf_GetTxCycleMask(ClstIdx, Column)           FrIf_GetCfgClstElemB(TxCycleMasks, ClstIdx)[(Column)]
# define FrIf_GetRxCycleMask(ClstIdx, Column)           FrIf_GetCfgClstElemB(RxCycleMasks, ClstIdx)[(Column)]
# define FrIf_GetNumberOfJobs(ClstIdx)                  FrIf_GetCfgClstElemC(NumberOfJobs, ClstIdx)
# define FrIf_GetMacroTickLengthInNanoSeconds(ClstIdx)  FrIf_GetCfgClstElemC(MacroTickLengthInNanoSeconds, ClstIdx)
# define FrIf_GetNumberOfMacroTicksPerCycle(ClstIdx)    FrIf_GetCfgClstElemC(MacroTicksPerCycle, ClstIdx)

/* Controller-related data */
# define FrIf_GetTxPduDescriptor(CtrlIdx, Idx)          FrIf_GetCfgCtrlElemA(TxPduDescriptors, CtrlIdx)[(Idx)]
# define FrIf_GetTxFrameLayoutElement(CtrlIdx, Idx)     FrIf_GetCfgCtrlElemA(TxFrameLayoutElements, CtrlIdx)[(Idx)]
# define FrIf_GetTxFrameDescriptor(CtrlIdx, Idx)        FrIf_GetCfgCtrlElemA(TxFrameDescriptors, CtrlIdx)[(Idx)]
# define FrIf_GetRxPduDescriptor(CtrlIdx, Idx)          FrIf_GetCfgCtrlElemA(RxPduDescriptors, CtrlIdx)[(Idx)]
# define FrIf_GetRxFrameLayoutElement(CtrlIdx, Idx)     FrIf_GetCfgCtrlElemA(RxFrameLayoutElements, CtrlIdx)[(Idx)]
# define FrIf_GetRxFrameDescriptor(CtrlIdx, Idx)        FrIf_GetCfgCtrlElemA(RxFrameDescriptors, CtrlIdx)[(Idx)]
# define FrIf_GetTxPduTxRequestCounter(CtrlIdx, Idx)    FrIf_GetCfgCtrlElemB(TxPduTxRequestCounters, CtrlIdx)[(Idx)]
# define FrIf_GetTxPduWasSentFlags(CtrlIdx, Idx)        FrIf_GetCfgCtrlElemB(TxPduWasSentFlags, CtrlIdx)[(Idx)]
# define FrIf_GetRedundantRxPduInfo(CtrlIdx)            FrIf_GetCfgCtrlElemB(RedundantRxPduInfo, CtrlIdx)

# if (FRIF_PDUDIRTYBYTE_USAGE == STD_ON)
#  define FrIf_GetTxPduDirtyByte(CtrlIdx, FrTxPduId)    FrIf_GetCfgCtrlElemB(TxPduDirtyBytes, CtrlIdx)[(FrTxPduId)]
# else
#  define FrIf_GetTxPduDirtyBits(CtrlIdx)               FrIf_GetCfgCtrlElemB(TxPduDirtyBits, CtrlIdx)
# endif

# if (!FrIf_IsPostbuild())
#  define FrIf_GetInternalTxLPduIdx(ClstIdx, Index)         (Index)
#  define FrIf_GetInternalRxLPduIdx(ClstIdx, Index)         (Index)
#  define FrIf_IsFrTxPduIdInvalid(Index)                    (Index) >= FrIf_GetInvalidTxPduHandle()
#  if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#   define FrIf_GetInternalTxPduId(Index)                   (Index)
#   define FrIf_GetTxFrameHandle(ClstIdx, Index)            (Index)
#   define FrIf_GetClusterIndex(PduIdx)                      0U
#   define FrIf_GetTxColumn(ClstIdx, ColumnNumber)          (FrIf_TxHandles[(ColumnNumber)])
#   define FrIf_GetRxColumn(ClstIdx, ColumnNumber)          (FrIf_RxHandles[(ColumnNumber)])
#   define FrIf_GetInvalidRxHandle(ClstIdx)                 (FrIf_InvalidRxHandle)
#   define FrIf_GetInvalidTxHandle(ClstIdx)                 (FrIf_InvalidTxHandle)
#   define FrIf_GetInvalidTxPduHandle()                     (FrIf_InvalidTxPduHandle)
#   define FrIf_GetNumberOfChannels(ClstIdx)                (FrIf_NumberOfChannels)
#   define FrIf_GetMaxTxFrameId(ClstIdx)                    (FrIf_CommonMaxTxFrameId) 
#   define FrIf_GetMaxTxPduId(ClstIdx)                      (FrIf_CommonMaxTxPduId)
#   define FrIf_GetNumberOfTxRequestCounters(ClstIdx)       (FrIf_CommonMaxNumberOfTxRequestCounters)
#   define FrIf_GetNumberOfClusters()                        1U
#   define FrIf_GetNumberOfControllers()                     1U
#  else
#   define FrIf_GetInternalTxPduId(Index)                   (FrIf_TxPduTranslationTable[(Index)].InternalTxPduId)
#   define FrIf_GetTxFrameHandle(ClstIdx, Index)            (FrIf_TxPduTranslationTable[(Index)].InternalTxPduId)
#   define FrIf_GetClusterIndex(PduIdx)                     (FrIf_TxPduTranslationTable[(PduIdx)].ControllerIdx)
#   define FrIf_GetTxColumn(ClstIdx, ColumnNumber)          (FrIf_Clst2TxComHandleTable[(ClstIdx)][(ColumnNumber)])
#   define FrIf_GetRxColumn(ClstIdx, ColumnNumber)          (FrIf_Clst2RxComHandleTable[(ClstIdx)][(ColumnNumber)])
#   define FrIf_GetInvalidTxHandle(ClstIdx)                 (FrIf_Ctrl2InvalidTxHandle[ClstIdx])
#   define FrIf_GetInvalidRxHandle(ClstIdx)                 (FrIf_Ctrl2InvalidRxHandle[ClstIdx])
#   define FrIf_GetInvalidTxPduHandle()                     (FrIf_InvalidTxPduHandle)
#   define FrIf_GetNumberOfClusters()                       (FrIf_CommonMaxNumberOfClusters)
#   define FrIf_GetNumberOfControllers()                    (FrIf_CommonMaxNumberOfControllers)
#   define FrIf_GetNumberOfChannels(ClstIdx)                (FrIf_NumberOfChannels[(ClstIdx)])
#   define FrIf_GetMaxTxFrameId(ClstIdx)                    (FrIf_Ctrl2MaxTxFrameId[(ClstIdx)])
#   define FrIf_GetMaxTxPduId(ClstIdx)                      (FrIf_Ctrl2MaxTxPduId[(ClstIdx)])
#   define FrIf_GetNumberOfTxRequestCounters(ClstIdx)       (FrIf_Ctrl2NumberOfTxRequestCounters[(ClstIdx)])
#  endif /*FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON */

# else /* !FrIf_IsPostbuild() */

#  define FrIf_GetInternalTxPduId(Index)                     (FrIf_Status[0].pTxPduTranslationTable[(Index)].InternalTxPduId)
#  define FrIf_GetInternalTxLPduIdx(ClstIdx, Index)          (FrIf_Status[ClstIdx].pTxLPduTranslationTable[(Index)])
#  define FrIf_GetInternalRxLPduIdx(ClstIdx, Index)          (FrIf_Status[ClstIdx].pRxLPduTranslationTable[(Index)])
#  define FrIf_GetTxFrameHandle(ClstIdx, Index)              (FrIf_Status[ClstIdx].pTxPduTranslationTable[(Index)].TxFrameHandle)
#  define FrIf_IsFrTxPduIdInvalid(Index)                     (   ((Index) >= FrIf_GetInvalidTxPduHandle()) \
                                                              || (FrIf_GetInternalTxPduId(Index) >= FrIf_GetInvalidTxPduHandle()) \
                                                             )

#  define FrIf_GetConfig(ClstIdx)                            FrIf_Status[ClstIdx].pConfigData
#  define FrIf_GetInvalidRxHandle(ClstIdx)                  (FrIf_Status[ClstIdx].InvalidRxHandle)
#  define FrIf_GetInvalidTxHandle(ClstIdx)                  (FrIf_Status[ClstIdx].InvalidTxHandle)
#  define FrIf_GetInvalidTxPduHandle()                      (FrIf_Status[0].InvalidTxPduHandle)

#  define FrIf_GetNumberOfChannels(ClstIdx)                 (FrIf_GetConfig(ClstIdx)->NumberOfChannels)
#  define FrIf_GetNumberOfClusters()                        (FrIf_GetConfig(0)->NumberOfClusters)
#  define FrIf_GetNumberOfControllers()                     (FrIf_GetConfig(0)->NumberOfControllers)
#  if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#   define FrIf_GetClusterIndex(PduIdx)                      0U
#   define FrIf_GetTxColumn(ClstIdx, ColumnNumber)          (FrIf_GetConfig(ClstIdx)->pTxHandles[(ColumnNumber)])
#   define FrIf_GetRxColumn(ClstIdx, ColumnNumber)          (FrIf_GetConfig(ClstIdx)->pRxHandles[(ColumnNumber)])
#   define FrIf_GetNumberOfTxRequestCounters(ClstIdx)       (FrIf_CommonMaxNumberOfTxRequestCounters)
#   define FrIf_GetMaxTxFrameId(ClstIdx)                    (FrIf_CommonMaxTxFrameId)
#   define FrIf_GetMaxTxPduId(ClstIdx)                      (FrIf_CommonMaxTxPduId)
#  else
#   define FrIf_GetClusterIndex(PduIdx)                     (FrIf_Status[0].pTxPduTranslationTable[(PduIdx)].ControllerIdx) /* Pdu2Clst translation is the same for all */
#   define FrIf_GetTxColumn(ClstIdx, ColumnNumber)          (FrIf_GetConfig(ClstIdx)->pClst2TxComHandleTable[(ClstIdx)][(ColumnNumber)])
#   define FrIf_GetRxColumn(ClstIdx, ColumnNumber)          (FrIf_GetConfig(ClstIdx)->pClst2RxComHandleTable[(ClstIdx)][(ColumnNumber)])
#   define FrIf_GetNumberOfTxRequestCounters(ClstIdx)       (FrIf_GetConfig(ClstIdx)->pCtrl2NumberOfTxRequestCounters[(ClstIdx)])
#   define FrIf_GetMaxTxFrameId(ClstIdx)                    (FrIf_GetConfig(ClstIdx)->pCtrl2MaxTxFrameId[(ClstIdx)])
#   define FrIf_GetMaxTxPduId(ClstIdx)                      (FrIf_GetConfig(ClstIdx)->pCtrl2MaxTxPduId[(ClstIdx)])
#  endif

# endif /* (!FrIf_IsPostbuild()) */

# if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE)
 /* PRQA S 3412 10 */ /* MD_MSR_19.4 */
#  define FrIf_SetBit(  /* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   |= FrIf_SetBitMask[(bitNumber)  &(uint8)0x07u])
#  define FrIf_ClearBit(/* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   &= FrIf_ClearBitMask[(bitNumber)&(uint8)0x07u])
#  define FrIf_GetBit(  /* uint8* */ pData, bitNumber)  \
     ((pData)[(bitNumber) >> 3]   &  FrIf_SetBitMask[(bitNumber)  &(uint8)0x07u])
# endif /* (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE) */

/* Calculate the index of the byte containing the dirty bit corresponding to the Tx PDU with ID = TxPduId */
# define FrIf_GetDirtyBitByteIdx(TxPduId) ((TxPduId) / 8)

# define FrIf_IsLastFrIfRxTaskForNm(ClstIdx) (boolean)(0 != (FrIf_GetJobDescriptor(ClstIdx, FrIf_Status[ClstIdx].CurrentJobNumber).JobConfig & FrIf_JobDataIsLastFrIfRxTaskForNm))
# define FrIf_IsLastFrIfRxTaskForTp(ClstIdx) (boolean)(0 != (FrIf_GetJobDescriptor(ClstIdx, FrIf_Status[ClstIdx].CurrentJobNumber).JobConfig & FrIf_JobDataIsLastFrIfRxTaskForTp))

/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 **********************************************************************************************************************/
typedef struct
{
# if (!FrIf_IsPostbuild())
  uint16 IsInitialized;
# else
  FRIF_P2CONSTCFGROOT(FrIf_PostBuildConfigType) pConfigData;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pTxFrameDescriptors;
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pTxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) pTxPduDescriptors;
  FRIF_P2CONSTCFG(FrIf_TxPduTranslationTupleType) pTxPduTranslationTable;
  FRIF_P2CONSTCFG(FrIf_TxHandleType) pTxLPduTranslationTable;
  FRIF_P2CONSTCFG(FrIf_RxHandleType) pRxLPduTranslationTable;
  FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) pRxFrameDescriptors;  
  FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) pRxFrameLayoutElements;
  FRIF_P2CONSTCFG(FrIf_RxPduDescriptorType) pRxPduDescriptors;
# endif
  FrIf_TxHandleType InvalidTxHandle;
  FrIf_RxHandleType InvalidRxHandle;
  PduIdType InvalidTxPduHandle;
  FrIf_StateType State;
  uint8_least CurrentJobNumber;
  uint8 CurrentCycle;
  uint8 JobListExecutionEnabled;
} FrIf_StateDataType;

# define FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FrIf_CommonMaxNumberOfClusters == 1)
extern VAR(FrIf_StateDataType, FRIF_VAR_ZERO_INIT) FrIf_Status[1];
#else
extern VAR(FrIf_StateDataType, FRIF_VAR_ZERO_INIT) FrIf_Status[2];
#endif

# define FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON)
# if (FrIf_CommonMaxNumberOfClusters == 1) /* COV_FRIF_UNSUPPORTED_SAFEBSW_FEATURE */
extern P2VAR(PduInfoType, AUTOMATIC, FRIF_VAR_NOINIT) FrIf_P2RedundantRxPduInfo[1];
# else
extern P2VAR(PduInfoType, AUTOMATIC, FRIF_VAR_NOINIT) FrIf_P2RedundantRxPduInfo[2];
# endif
#endif

#define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#define FRIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FRIF_PDUDIRTYBYTE_USAGE == STD_OFF)
extern CONST(uint8, FRIF_CONST) FrIf_SetBitMask[8];
extern CONST(uint8, FRIF_CONST) FrIf_ClearBitMask[8];
#endif

#define FRIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_RxTask_0
**********************************************************************************************************************/
/*!
 *
 * \brief        Performs the Rx communication operations of the current job.
 * \details      Determines which of the Rx frames associated to the current Rx job shall be processed during the current
 *               cycle and performs their reception.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK        All the Rx communication operations where successfully executed.
 * \return       E_NOT_OK    A Problem occurred during the reception of a frame.
 * \pre          -
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      RX
 * \trace        SPEC-30062
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_RxTask(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_TxTask_0
**********************************************************************************************************************/
/*!
 *
 * \brief        Performs the Tx communication operations of the current job.
 * \details      Determines which of the Tx frames associated to the current Tx job shall be processed during the current
 *               cycle, assembles them and requests their transmission to the Fr.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      TX
 * \trace        SPEC-29905
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_TxTask(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_TxConfTask_0
**********************************************************************************************************************/
/*!
 *
 * \brief        Performs the Tx confirmation communication operations of the current job.
 * \details      Determines which of the Tx frames associated to a previous Tx job contain PDUs that shall be confirmed
 *               during the current cycle, and confirms their transmission to the corresponding upper layer if necessary.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \synchronous  TRUE
 * \reentrant    FALSE
 * \ingroup      TX
 * \trace        SPEC-29870
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_TxConfTask(FRIF_VCLST_ONLY);

# define FRIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#endif
/* FRIF_PRIV_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Priv.h
 *********************************************************************************************************************/
