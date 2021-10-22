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
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr.c
 *        \brief  FlexRay Driver source file
 *
 *      \details  Source file implementation of the AUTOSAR FlexRay Driver according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FR_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0303 EOF */ /* MD_Fr_0306 */

/**********************************************************************************************************************
* Filtered for DrvFr_V85xErayAsr 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fr_Priv.h"
#include "Std_Types.h"

#if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
# include "EcuM_Error.h"
#endif

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

#if ((FR_SW_MAJOR_VERSION != 0x5u) || (FR_SW_MINOR_VERSION != 0x00u) || (FR_SW_PATCH_VERSION != 0x01u))
# error "Fr.c: Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define FR_VNMV1_BYTECOUNT                                            4u
#define FR_VNMV2_BYTECOUNT                                            8u
#define FR_VMAX_ARRAY_FOR_NMVECTOR                                    3u
#define FR_FIFO_MARK                                                  0x80u
#define FR_LAST_FIFO_FRAME                                            1u

#define FR_TXVIRTBUF_INFO_DYNPAYLOAD                                  ((uint8)0x1)
#if (FR_BUFFER_RECONFIG == STD_ON)
# define FR_TXVIRTBUF_INFO_RECONFIG                                   ((uint8)0x2)
#else
# define FR_TXVIRTBUF_INFO_RECONFIG                                   ((uint8)0x0)
#endif
#define FR_TXVIRTBUF_INFO_RECONFIG_LPDU                               ((uint8)0x4)

#define FR_RXVIRTBUF_CYCLEBASE_RECONFIG_LPDU                          ((uint8)0x80)
#define FR_RECONFIG_LPDU_WRHS1_MASK                                   (0x3C000000UL)

#define FR_SYNC_FRAME_LIST_MAX                                        ((uint8)15)
#define FR_HEADER_CRC_MAX                                             ((uint16)0x7FF) /* Must be 2^x-1 bitvalue to allow bitfiltering */
#define FR_CRC_RUNS                                                   ((uint8)7u)
#define FR_CRC_POLYNOM                                                0x385

#if (FR_CC_READ_BACK_SUPPORT == STD_ON)
# define FR_VER_FIRST_ELEMENT                                         13u
# define FR_VER_SUCC1_POSITION                                        12u
# define FR_VER_LENGTH                                                16u
# define FR_VER_KEYSLOT_NOT_USED                                      0u
# define FR_VER_KEYSLOT_BUFFER_IDX                                    0u
# define FR_VER_FILTER_CFG_BITS                                       0xFFFFFF00u
#endif

#define FR_SIGNEDBIT_RCV                                              0x0800u
#define FR_SIGNEDBIT_OCV                                              0x00040000UL

#define FR_FILLSIGNED_RCV                                             0xF000u
#define FR_FILLSIGNED_OCV                                             0xFFF80000UL

#define FR_GETCHANNELSTATUS_ACS_MASK                                  0x1F
#define FR_GETCHANNELSTATUS_MTS_SHIFT                                 8
#define FR_GETCHANNELSTATUS_SWS_SHIFT                                 9
#define FR_GETCHANNELSTATUS_NIT_SHIFT                                 12

#define FR_SIZE_CLEAR_IBF                                             70

#define FR_MASK_NMBYTEPOS                                             0x03

#if (FR_PROD_ERROR_DETECT == STD_ON)
# define FR_DEM_E_ACCESS                                              FR_DEM_GEN_E_ACCESS
# define FR_DEM_E_CTRLTESTRESULT                                      FR_DEM_GEN_E_CtrlTestResult
#endif

#if (FR_VHARDWARE_CANCELLATION == STD_ON)
# define FR_NOHWTIMEOUT                                               (Fr_VLoopTimeout <= FR_VGETTIMEOUT_DURATION)
# define FR_INCREASETIMEOUTCOUNTER                                    (Fr_VLoopTimeout++)
#else
# define FR_NOHWTIMEOUT                                               (1)
# define FR_INCREASETIMEOUTCOUNTER
#endif

/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */
#if (Fr_IsPostbuild())
# if (FR_VENABLE_MID_FILTERING == STD_ON)
#  if (FR_NUM_CTRL_USED > 1)  /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             ((uint16)Fr_VPostBuildConfigPtr->LastStaticFrameID[(Ctrl)])
#  else
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             ((uint16)Fr_VPostBuildConfigPtr->LastStaticFrameID)
#  endif
#  define FR_GETSIZE_MID_ARRAY                                        ((uint16)Fr_VPostBuildConfigPtr->NumMIDs)
#  define FR_GETMIDFILTER(Idx)                                        (Fr_VPostBuildConfigPtr->MsgIdFilterMap[(Idx)])
# endif

# if (FR_CC_READ_BACK_SUPPORT == STD_ON)
#  define Fr_GetCtrlTestCount                                         (Fr_VPostBuildConfigPtr->Fr_CtrlTestCount)
# endif

# if (FR_VHARDWARE_CANCELLATION == STD_ON)
#  define FR_VGETTIMEOUT_DURATION                                     (Fr_VPostBuildConfigPtr->Fr_VTimeoutDuration)
# endif
#endif

#if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME)
# if (FR_VENABLE_MID_FILTERING == STD_ON)
#  if (FR_NUM_CTRL_USED > 1)  /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             ((uint16)Fr_VLastStaticFrameID[(Ctrl)])
#  else
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             ((uint16)Fr_VLastStaticFrameID)
#  endif
#  define FR_GETSIZE_MID_ARRAY                                        ((uint16)Fr_VNumMIDs)
#  define FR_GETMIDFILTER(Idx)                                        (Fr_VMsgIdFilterMap[(Idx)])
# endif

# if (FR_CC_READ_BACK_SUPPORT == STD_ON)
#  define Fr_GetCtrlTestCount                                         (Fr_CtrlTestCount)
# endif

# if (FR_VHARDWARE_CANCELLATION == STD_ON)
#  define FR_VGETTIMEOUT_DURATION                                     (Fr_VTimeoutDuration)
# endif
#endif

#if (Fr_IsPreCompile())
# if (FR_VENABLE_MID_FILTERING == STD_ON)
#  if (FR_NUM_CTRL_USED > 1)  /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             ((uint16)Fr_VLastStaticFrameID[(Ctrl)])
#  else
#  define FR_GETLAST_STATIC_FRAMEID(Ctrl)                             (FR_LAST_STATIC_FRAMEID)
#  endif
#  define FR_GETSIZE_MID_ARRAY                                        (FR_SIZE_MID_ARRAY)
#  define FR_GETMIDFILTER(Idx)                                        (Fr_VMsgIdFilterMap[(Idx)])
# endif

# if (FR_CC_READ_BACK_SUPPORT == STD_ON)
#  define Fr_GetCtrlTestCount                                         FR_CTRL_TEST_COUNT
# endif

# if (FR_VHARDWARE_CANCELLATION == STD_ON)
#  define FR_VGETTIMEOUT_DURATION                                     FR_VTIMEOUT_DURATION
# endif
#endif

#if !defined (FR_LOCAL_INLINE)                                        /* COV_MSR_COMPATIBILITY */
# define FR_LOCAL_INLINE                                              LOCAL_INLINE
#endif

#if !defined (LOCAL_INLINE)                                           /* COV_MSR_COMPATIBILITY */
# define LOCAL_INLINE                                                 inline
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if (FR_NUM_CTRL_USED > 1)
# if (Fr_IsPostbuild())
#  define FR_P2CONST_CFG(Type)                                         P2CONST(Type, AUTOMATIC, FR_PBCFG)
# else
#  define FR_P2CONST_CFG(Type)                                         P2CONST(Type, AUTOMATIC, FR_CONST)
# endif
#else
# if (Fr_IsPostbuild())
#  define FR_P2CONST_CFG(Type)                                         P2CONST(Type, AUTOMATIC, FR_PBCFG)
# else
#  define FR_P2CONST_CFG(Type)                                         P2CONST(Type, AUTOMATIC, FR_CONST)
# endif
#endif

#define FR_P2VAR_APPLDATA(Type)                                       P2VAR(Type, AUTOMATIC, FR_APPL_DATA)
#define FR_P2CONST_APPLDATA(Type)                                     P2CONST(Type, AUTOMATIC, FR_APPL_DATA)
#define FR_P2CONST_REGSPACE(Type)                                     P2CONST(Type, AUTOMATIC, MSR_REGSPACE)

#if (FR_NUM_CTRL_USED > 1)
# if (Fr_IsPostbuild()) 
#  define Fr_VGetCcBufCfgAt(Ctrl, Idx)                                 (&Fr_VPostBuildConfigPtr->CcBufs[(Ctrl)][(Idx)])
#  define Fr_VGetCcCfgAddrAt(Ctrl, Idx)                                (Fr_VPostBuildConfigPtr->CcRegAddrs[(Idx)])
#  define Fr_VGetCcCfgValAt(Ctrl, Idx)                                 (Fr_VPostBuildConfigPtr->CcRegVals[(Ctrl)][(Idx)])
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (Fr_VPostBuildConfigPtr->NumRxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (Fr_VPostBuildConfigPtr->NumTxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumCcBufs(Ctrl)                                       (Fr_VPostBuildConfigPtr->NumCcBufs[(Ctrl)])
#  define Fr_VGetNumCcRegs(Ctrl)                                       (Fr_VPostBuildConfigPtr->NumCcRegs[(Ctrl)])
#  define Fr_GetRxVirtBuf2Phys(Ctrl,Idx)                               (Fr_VRxVirtBuf2PhysBufMapPtr[(Ctrl)][(Idx)])
#  define Fr_GetTxVirtBuf2Phys(Ctrl,Idx)                               (Fr_VTxVirtBuf2PhysBufMapPtr[(Ctrl)][(Idx)])

#  if (FR_NMVECTOR_ENABLE == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetNMVectorLength(Ctrl)                                  (Fr_VPostBuildConfigPtr->NmVectorLength[(Ctrl)])
#  endif

#  if (FR_READ_CC_CONFIGURATION == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetVCCConfigParam8Bit(Ctrl, Idx)                         (Fr_VPostBuildConfigPtr->CCConfigParam8Bit[(Ctrl)][(Idx)])
#   define Fr_GetVCCConfigParam16Bit(Ctrl, Idx)                        (Fr_VPostBuildConfigPtr->CCConfigParam16Bit[(Ctrl)][(Idx)])
#   define Fr_GetVCCConfigParam32Bit(Ctrl, Idx)                        (Fr_VPostBuildConfigPtr->CCConfigParam32Bit[(Ctrl)][(Idx)])

#  endif
# endif

# if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumRxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumTxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumCcBufs(Ctrl)                                       (Fr_VNumCcBufs[(Ctrl)])
#  define Fr_VGetNumCcRegs(Ctrl)                                       (Fr_VNumCcRegs[(Ctrl)])

#  if (FR_NMVECTOR_ENABLE == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetNMVectorLength(Ctrl)                                  (Fr_NmVectorLength[(Ctrl)])
#  endif

# endif

# if ((FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) || (Fr_IsPreCompile()))
#  define Fr_VGetCcBufCfgAt(Ctrl, Idx)                                 (&Fr_CcBufs[(Ctrl)][(Idx)])
#  define Fr_VGetCcCfgAddrAt(Ctrl, Idx)                                (Fr_VCcRegAddrs[(Idx)])
#  define Fr_VGetCcCfgValAt(Ctrl, Idx)                                 (Fr_CtrlRegs[(Ctrl)][(Idx)])

#  define Fr_GetRxVirtBuf2Phys(Ctrl, Idx)                              (Fr_RxVirt2PhysBuf[(Ctrl)][(Idx)])
#  define Fr_GetTxVirtBuf2Phys(Ctrl, Idx)                              (Fr_TxVirt2PhysBuf[(Ctrl)][(Idx)])

#  if (FR_READ_CC_CONFIGURATION == STD_ON)
#   define Fr_GetVCCConfigParam8Bit(Ctrl, Idx)                         (Fr_Params8Bit[(Ctrl)][(Idx)])
#   define Fr_GetVCCConfigParam16Bit(Ctrl, Idx)                        (Fr_Params16Bit[(Ctrl)][(Idx)])
#   define Fr_GetVCCConfigParam32Bit(Ctrl, Idx)                        (Fr_Params32Bit[(Ctrl)][(Idx)])
#  endif
# endif

# if (Fr_IsPreCompile())
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumRxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumTxVirtBuf2PhysBufs[(Ctrl)])
#  define Fr_VGetNumCcBufs(Ctrl)                                       (Fr_VNumCcBufs[(Ctrl)])
#  define Fr_VGetNumCcRegs(Ctrl)                                       (Fr_VNumCcRegs[(Ctrl)])

#  if (FR_NMVECTOR_ENABLE == STD_ON)
#   define Fr_GetNMVectorLength(Ctrl)                                  (Fr_NmVectorLength[(Ctrl)])
#  endif

# endif
#else /* single controller */
# if (Fr_IsPostbuild())
#  define Fr_VGetCcBufCfgAt(Ctrl, Idx)                                 (&Fr_VPostBuildConfigPtr->CcBufs[(Idx)])
#  define Fr_VGetCcCfgAddrAt(Ctrl, Idx)                                (Fr_VPostBuildConfigPtr->CcRegAddrs[(Idx)])
#  define Fr_VGetCcCfgValAt(Ctrl, Idx)                                 (Fr_VPostBuildConfigPtr->CcRegVals[(Idx)])
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (Fr_VPostBuildConfigPtr->NumRxVirtBuf2PhysBufs)
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (Fr_VPostBuildConfigPtr->NumTxVirtBuf2PhysBufs)
#  define Fr_VGetNumCcBufs(Ctrl)                                       (Fr_VPostBuildConfigPtr->NumCcBufs)
#  define Fr_VGetNumCcRegs(Ctrl)                                       (Fr_VPostBuildConfigPtr->NumCcRegs)
#  define Fr_GetRxVirtBuf2Phys(Ctrl,Idx)                               (Fr_VRxVirtBuf2PhysBufMapPtr[(Idx)])
#  define Fr_GetTxVirtBuf2Phys(Ctrl,Idx)                               (Fr_VTxVirtBuf2PhysBufMapPtr[(Idx)])

#  if (FR_NMVECTOR_ENABLE == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetNMVectorLength(Ctrl)                                  (Fr_VPostBuildConfigPtr->NmVectorLength)
#  endif

#  if (FR_READ_CC_CONFIGURATION == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetVCCConfigParam8Bit(Ctrl, Idx)                         (Fr_VPostBuildConfigPtr->CCConfigParam8Bit[(Idx)])
#   define Fr_GetVCCConfigParam16Bit(Ctrl, Idx)                        (Fr_VPostBuildConfigPtr->CCConfigParam16Bit[(Idx)])
#   define Fr_GetVCCConfigParam32Bit(Ctrl, Idx)                        (Fr_VPostBuildConfigPtr->CCConfigParam32Bit[(Idx)])

#  endif
# endif

# if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME)
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumRxVirtBuf2PhysBufs)
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (Fr_VNumTxVirtBuf2PhysBufs)
#  define Fr_VGetNumCcBufs(Ctrl)                                       (Fr_VNumCcBufs)
#  define Fr_VGetNumCcRegs(Ctrl)                                       (Fr_VNumCcRegs)

#  if (FR_NMVECTOR_ENABLE == STD_ON)
#   define Fr_GetNMVectorLength(Ctrl)                                  (Fr_NmVectorLength)
#  endif

# endif

# if ((FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) || (Fr_IsPreCompile()))
#  define Fr_VGetCcBufCfgAt(Ctrl, Idx)                                 (&Fr_VCcBufs[(Idx)])
#  define Fr_VGetCcCfgAddrAt(Ctrl, Idx)                                (Fr_VCcRegAddrs[(Idx)])
#  define Fr_VGetCcCfgValAt(Ctrl, Idx)                                 (Fr_VCcRegVals[(Idx)])

#  define Fr_GetRxVirtBuf2Phys(Ctrl, Idx)                              (Fr_VRxVirtBuf2PhysBufMap[(Idx)])
#  define Fr_GetTxVirtBuf2Phys(Ctrl, Idx)                              (Fr_VTxVirtBuf2PhysBufMap[(Idx)])

#  if (FR_READ_CC_CONFIGURATION == STD_ON)
#   define Fr_GetVCCConfigParam8Bit(Ctrl, Idx)                         (Fr_VCCConfigParam8Bit[Idx])
#   define Fr_GetVCCConfigParam16Bit(Ctrl, Idx)                        (Fr_VCCConfigParam16Bit[Idx])
#   define Fr_GetVCCConfigParam32Bit(Ctrl, Idx)                        (Fr_VCCConfigParam32Bit[Idx])
#  endif
# endif

# if (Fr_IsPreCompile()) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#  define Fr_VGetNumRxVirtBuf2PhysBufs(Ctrl)                           (FR_SIZE_RXVIRTBUF2PHAYBUFMAP)
#  define Fr_VGetNumTxVirtBuf2PhysBufs(Ctrl)                           (FR_SIZE_TXVIRTBUF2PHAYBUFMAP)
#  define Fr_VGetNumCcBufs(Ctrl)                                       (FR_SIZE_MB_ARRAY)
#  define Fr_VGetNumCcRegs(Ctrl)                                       (FR_SIZE_CONTROLREGCONFARRAY)

#  if (FR_NMVECTOR_ENABLE == STD_ON) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   define Fr_GetNMVectorLength(Ctrl)                                  (FR_NM_VECTOR_LENGTH)
#  endif

# endif

#endif

#define Fr_VNewData(Ctrl, physBufIdx)                                 (Fr_VCCNewData((Ctrl), (physBufIdx)))
/* Hint: Null Frame is indicated as NFI == 0 (see ERay-Spec) */
#define Fr_ReceiveCycleCount(Ctrl)                                    (Fr_VCCReadBitsShift((Ctrl), FR_RDHS3, FR_RDHS3_RCC_MASK, FR_RDHS3_RCC_SHIFT))
#define Fr_CheckPPI(Ctrl)                                             (FR_RDHS3_PPI == Fr_VCCReadBits((Ctrl), FR_RDHS3, FR_RDHS3_PPI))
#define Fr_IsDynamicFrame(Ctrl)                                       (((uint16) Fr_VCCReadBits((Ctrl), FR_RDHS1, FR_RDHS1_FID_MASK)) > FR_GETLAST_STATIC_FRAMEID(Ctrl))

# define Fr_GetMessageID(Ctrl)                                        ((uint16) Fr_VCCReadBits((Ctrl), FR_RDDSn, 0xFFFFUL))
#define Fr_GetReceiveByteLength(Ctrl)                                 (Fr_VCCGetReceiveLength((Ctrl)) << 1)
#define Fr_GetRDHS1(Ctrl)                                             (Fr_VCCReadValue((Ctrl), FR_RDHS1))
#define Fr_WriteWRHS1(Ctrl, value)                                    Fr_VCCWriteValueWRHS((Ctrl), FR_WRHS1, (value))
#define Fr_WriteWRHS2(Ctrl, value)                                    Fr_VCCWriteValueWRHS((Ctrl), FR_WRHS2, (value))
#define Fr_WriteWRHS3(Ctrl, value)                                    Fr_VCCWriteValueWRHS((Ctrl), FR_WRHS3, (value))

# if defined FR_CPU_RH850 /* COV_FR_EQUIVALENT_HARDWARE */
#  ifndef FR_WAIT_STATES  /* COV_FR_EQUIVALENT_HARDWARE */
#   define FR_WAIT_STATES   5
#  endif
# endif

/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
# if defined(FR_USE_STUB_HW_FAILURE)  /* COV_FR_TESTSUITE_INSTRUMENTATION */
#  include "FrStubHwFailure.h"
# endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (Fr_IsPostbuild())
FR_LOCAL P2CONST(Fr_VConfigType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VPostBuildConfigPtr;  /*!< Used to access postbuild config struct */
# if (FR_NUM_CTRL_USED > 1)
FR_LOCAL P2CONST(Fr_VRxVirtBuf2PhysBufMapType*, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VRxVirtBuf2PhysBufMapPtr; /*!< Used to access Rx triggerings in postbuild use case */
FR_LOCAL P2CONST(Fr_VTxVirtBuf2PhysBufMapType*, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VTxVirtBuf2PhysBufMapPtr; /*!< Used to access Tx triggerings in postbuild use case */
# else
FR_LOCAL P2CONST(Fr_VRxVirtBuf2PhysBufMapType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VRxVirtBuf2PhysBufMapPtr; /*!< Used to access Rx triggerings in postbuild use case */
FR_LOCAL P2CONST(Fr_VTxVirtBuf2PhysBufMapType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VTxVirtBuf2PhysBufMapPtr; /*!< Used to access Tx triggerings in postbuild use case */
# endif
#endif

#define FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#define FR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/*! Holds the states of the communication controller. */
FR_LOCAL CONST(Fr_POCStateType, FR_CONST) Fr_VPocStateMapTable[3][16] =  /* PRQA S 3218 */ /* MD_Fr_3218 */
{
  /* Run states */
  {
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:DEFAULT_CONFIG state */
    FR_POCSTATE_READY,          /* CC:READY state */
    FR_POCSTATE_NORMAL_ACTIVE,  /* NORMAL_ACTIVE state */
    FR_POCSTATE_NORMAL_PASSIVE, /* NORMAL_PASSIVE state */
    FR_POCSTATE_HALT,           /* HALT state */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:MONITOR_MODE state */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_CONFIG
  },
  /* Wakeup */
  {
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_STANDBY state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_LISTEN state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_SEND state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_DETECT state */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP  /* CC:reserved */
  },
  /* Startup */
  {
    FR_POCSTATE_STARTUP,  /* CC:STARTUP_PREPARE state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_LISTEN state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_COLLISION_RESOLUTION state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_CONSISTENCY_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_GAP state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_JOIN State */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_COLDSTART_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_LISTEN state */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_CONSISTENCY_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:INITIALIZE_SCHEDULE state */
    FR_POCSTATE_STARTUP,  /* CC:ABORT_STARTUP state */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP   /* CC:reserved */
   }
};

/*! Holds the different slotmode states */
FR_LOCAL CONST(Fr_SlotModeType, FR_CONST) Fr_VSlotModeMapTable[] =   /* PRQA S 3218 */ /* MD_Fr_3218 */
{
  FR_SLOTMODE_SINGLE,
  FR_SLOTMODE_SINGLE,
  FR_SLOTMODE_ALL_PENDING,
  FR_SLOTMODE_ALL
};

/*! Holds the detailed startup states */
FR_LOCAL CONST(Fr_StartupStateType, FR_CONST) Fr_VStartupStateMapTable[] =  /* PRQA S 3218 */ /* MD_Fr_3218 */
{
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_COLDSTART_LISTEN,
  FR_STARTUP_COLDSTART_COLLISION_RESOLUTION,
  FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,
  FR_STARTUP_COLDSTART_GAP,
  FR_STARTUP_COLDSTART_JOIN,
  FR_STARTUP_INTEGRATION_COLDSTART_CHECK,
  FR_STARTUP_INTEGRATION_LISTEN,
  FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,
  FR_STARTUP_INITIALIZE_SCHEDULE,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED
};

#define FR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FR_DEV_ERROR_DETECT == STD_ON)
VAR(Fr_VFrDrvStateType, FR_VAR_ZERO_INIT) Fr_VFrDrvState = FR_VUNINITPTR; /*!< Used to save the internal driver state during development */
#endif

#define FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/** \ingroup LHAL
* \{
*/

#define FR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#if (FR_VENABLE_MID_FILTERING == STD_ON)
/**********************************************************************************************************************
 *  Fr_VIsMsgId()
 *********************************************************************************************************************/
/*! \brief        Discovers if received message ID is in list
 *  \details      Discovers if received message ID of a dynamic frame matches one of the entries of the statically configured message ID list. 
 *  \return       TRUE  message ID is in list or no dynamic frame
 *  \return       FALSE message ID is not in list
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \config       FR_VENABLE_MID_FILTERING
 *  \note         Local function called by Fr_ReceiveRxLPdu()
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(boolean, FR_CODE) Fr_VIsMsgId(FR_VCTRL_SYSTEMTYPE_ONLY);
#endif /* (FR_VENABLE_MID_FILTERING == STD_ON) */

#if (FR_CC_READ_BACK_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Fr_VReadBackSupport()
 *********************************************************************************************************************/
/*! \brief        Verifies register values
 *  \details      Verifies that the FlexRay protocol parameters and some other configuration values have been successfully written to the controller registers.
 *  \return       E_NOT_OK  Comparing ROM with register values failed.
 *  \return       E_OK      No error
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \config       FR_CC_READ_BACK_SUPPORT
 *  \note         Local function called by Fr_ControllerInit()
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VReadBackSupport(FR_VCTRL_SYSTEMTYPE_ONLY);
#endif /* (FR_CC_READ_BACK_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  Fr_VEnterConfigMode()
 *********************************************************************************************************************/
/*! \brief        Sets the communication controller into POCstate CONFIG 
 *  \details      Sets the communication controller into POCstate CONFIG and initializes all module-internal RAMS to 0.
 *  \return       E_NOT_OK  CLEAR_RAMS failed
 *  \return       E_OK      CLEAR_RAMS succeeded
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \note         Local function called by Fr_ControllerInit()
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VEnterConfigMode(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_VLeaveConfigMode()
 *********************************************************************************************************************/
/*! \brief        Sets the communication controller into POCstate READY
 *  \details      Sets the communication controller into POCstate READY after writing a special key sequence to leave the POCstate CONFIG.
 *  \return       E_OK      Transition to READY passed
 *  \return       E_NOT_OK  Transition to READY failed
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \note         Local function Called by Fr_ControllerInit()
                  E-Ray requires a sequence of unlock keys to leave CONFIG state
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VLeaveConfigMode(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_VExecutePOCCommand()
 *********************************************************************************************************************/
/*! \brief        Requests the CC to go in appropriate POCstate
 *  \details      Internal helper function that requests the CC to go into POCstate Fr_PocCommand.
 *  \param[in]    Fr_PocCommand    Requested POCstate. range: 1..12
 *  \return       E_OK     Transition to requested POCstate passed
 *  \return       E_NOT_OK PocCommand was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VExecutePOCCommand
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  uint32 Fr_PocCommand
);

#if (FR_RECONFIGLPDUSUPPORT == STD_ON) && (FR_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  Fr_VBitCnt()
 *********************************************************************************************************************/
/*! \brief        Counts the amount of bits set.
 *  \details      Counts the amount of bits set of the given value and returns it.
 *  \param[in]    value     Holds a value
 *  \return       uint8     Returns the amount of bits counted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \config       FR_RECONFIGLPDUSUPPORT && FR_DEV_ERROR_DETECT
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(uint8, FR_CODE) Fr_VBitCnt
(
  uint8 value 
);
#endif

/**********************************************************************************************************************
 *  Fr_VSetReg()
 *********************************************************************************************************************/
/*! \brief        Waits until a register accepted the expected value.
 *  \details      Internal function that waits until the register regAddr accepted the expected value mask. The parameter operator regulates which kind of condition is executed.
 *  \param[in]    regAddr   Holds address of register
 *  \param[in]    mask      Holds the expected value of the register
 *  \param[in]    operator  Decides which condition is used [range: EQUAL, NEQUAL]
 *  \return       E_OK      Value was accepted
 *  \return       E_NOT_OK  Value was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VSetReg
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint32 regAddr, 
  uint32 mask, 
  boolean operator
);

/**********************************************************************************************************************
 *  Fr_VCalHeaderCRC()
 *********************************************************************************************************************/
/*! \brief        Calculates header CRC 
 *  \details      Calculates header CRC for frames within dynamic segment.
 *  \param[in]    Fr_PayloadLength  Payload length of a frame
 *  \param[in]    Fr_CRC            Initial CRC value
 *  \return       CRC value
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(uint16, FR_CODE) Fr_VCalHeaderCRC
(
  uint8 Fr_PayloadLength, 
  uint16 Fr_CRC
);

/**********************************************************************************************************************
 *  Fr_VWriteDataToCC()
 *********************************************************************************************************************/
/*! \brief        Copy function
 *  \details      Copies CpyLength bytes from register address pSrc to RAM address pDest
 *  \param[in]    *pDst       RAM destination pointer 
 *  \param[in]    *pSrc       RAM source pointer (CC)  
 *  \param[in]    CpyLength   Number of bytes to be copied 
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \note         Internal function called by Fr_TransmitTxLPdu
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(void, FR_CODE) Fr_VWriteDataToCC
(
  Fr_RegisterPtrType pDst,
  FR_P2CONST_APPLDATA(uint8) pSrc,
  uint8 CpyLength
);

/**********************************************************************************************************************
 *  Fr_VReadDataFromCC()
 *********************************************************************************************************************/
/*! \brief        Copy function
 *  \details      Copies CpyLength bytes from RAM address pSrc to register address pDest
 *  \param[in]    *pDst       RAM destination pointer 
 *  \param[in]    *pSrc       RAM source pointer (CC)  
 *  \param[in]    CpyLength   Number of bytes to be copied 
 *  \pre          -
 *  \context      TASK|ISR
 *  \note         Internal function called by Fr_ReceiveRxLPdu
 *********************************************************************************************************************/
FR_LOCAL_INLINE FUNC(void, FR_CODE) Fr_VReadDataFromCC
(
  P2VAR  (uint8, AUTOMATIC, FR_APPL_DATA) pDst,
  volatile FR_P2CONST_REGSPACE(uint32) pSrc,
  uint8 CpyLength
);

# if defined FR_CPU_RH850 /* COV_FR_EQUIVALENT_HARDWARE */
/***********************************************************************************************************************
 *  Fr_VWaitMs()
 **********************************************************************************************************************/
/*! \brief        Waits the desired amount of milliseconds.
 *  \details      Waits the desired amount of milliseconds.
 *  \param[in]    Fr_Time     time in ms
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \note         Internal function called by Fr_Init
 **********************************************************************************************************************/
FR_LOCAL_INLINE void Fr_VWaitMs
(
  uint16 Fr_Time
);
# endif
/** \} */ 

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (FR_RECONFIGLPDUSUPPORT == STD_ON) && (FR_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  Fr_VBitCnt()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FR_LOCAL_INLINE FUNC(uint8, FR_CODE) Fr_VBitCnt
(
  uint8 value
)
{  
  /* ----- Local Variables ---------------------------------------------- */
  uint8 cnt = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Count the amount of bits to determine whether values other than 1, 2, 4, 8, 16, 32 or 64 are used. */
  cnt = value & 0x1;
  value>>=1;
  cnt += value & 0x1;
  value>>=1;
  cnt += value & 0x1;
  value>>=1;
  cnt += value & 0x1;
  value>>=1;
  cnt += value & 0x1;
  value>>=1;
  cnt += value & 0x1;
  value>>=1;
  cnt += value & 0x1;

  return cnt;
}
#endif

/**********************************************************************************************************************
 *  Fr_VSetReg()
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
 */
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VSetReg
(
  FR_VCTRL_SYSTEMTYPE_ONLY,  
  uint32 regAddr, 
  uint32 mask, 
  boolean operator
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
#if (FR_VHARDWARE_CANCELLATION == STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Depending on the given condition (equal or not equal) read from the register address and compare with the given
   *     mask until either and increment a loop counter:
   *      The condition is fulfilled.
   *      Or if FR_VHARDWARE_CANCELLATION is enabled and The loop counter has reached the configured threshold:
   *        In this case DemEvent FR_DEM_E_ACCESS with DEM_EVENT_STATUS_FAILED is reported. */
  if (operator == EQUAL)
  {
    while ((Fr_VCCReadBits(FR_VCTRL_IDX, regAddr, mask) == mask) && (FR_NOHWTIMEOUT)) /* COV_FR_HARDWARE_FAILURE */
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
  }
  else
  {
    while ((Fr_VCCReadBits(FR_VCTRL_IDX, regAddr, FR_CCSV_POCS_MASK) != mask) && (FR_NOHWTIMEOUT))  /* COV_FR_HARDWARE_FAILURE */
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
  }
#if (FR_VHARDWARE_CANCELLATION == STD_ON)
  if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)  /* COV_FR_HARDWARE_FAILURE */
  {
    Fr_DemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
  }
  else
#endif
  {
    retVal = E_OK;
  }

  return retVal;
} /* Fr_VSetReg() */

/**********************************************************************************************************************
 *  Fr_VExecutePOCCommand()
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
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VExecutePOCCommand
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint32 Fr_PocCommand
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Wait until POC Busy flag (PBSY) is cleared in the SUC Configuration Register 1 (SUCC1) and next protocol control
   *     command can be set. */
  (void)Fr_VSetReg(FR_VCTRL_IDX, FR_SUCC1, FR_SUCC1_PBSY, EQUAL);

  /* #20 Write POC command to CHI Command Vector flags (CMDn) of SUC Configuration Register 1 (SUCC1). */
  Fr_VCCSetBitsMask(FR_VCTRL_IDX, FR_SUCC1, Fr_PocCommand, FR_SUCC1_CMD_MASK);  /* SBSW_FR_WriteHwReg */

  /* #30 Wait until POC Busy flag (PBSY) is cleared in the SUC Configuration Register 1 (SUCC1) and POC is not busy any more. */
  (void)Fr_VSetReg(FR_VCTRL_IDX, FR_SUCC1, FR_SUCC1_PBSY, EQUAL);

  /* #40 If the CHI Command Vector flags (CMDn) SUC Configuration Register 1 (SUCC1) indicate that the command was not
   *     accepted afterwards:
   *       Report DemEvent FR_DEM_E_ACCESS with DEM_EVENT_STATUS_FAILED. */
  if (Fr_VCCReadBits(FR_VCTRL_IDX, FR_SUCC1, FR_SUCC1_CMD_MASK) != CCCMD_CNA)
  {
    retVal = E_OK;
  }
  else
  {
    Fr_DemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
  }

  return retVal;
} /* Fr_VExecutePOCCommand() */

/**********************************************************************************************************************
 *  Fr_VReadDataFromCC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FR_LOCAL_INLINE FUNC(void, FR_CODE) Fr_VReadDataFromCC
(
  FR_P2VAR_APPLDATA(uint8) pDst,
  volatile FR_P2CONST_REGSPACE(uint32) pSrc,
  uint8 CpyLength
)
{
/** 
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
 */
  /* ----- Local Variables ---------------------------------------------- */
  FR_P2VAR_APPLDATA(uint16) p16Dst;
  volatile FR_P2CONST_REGSPACE(uint32) p32Src;
  uint32 payloadValue;
  uint16 DWordCnt;
  p32Src = pSrc;
  /* ESCAN00064374 */
  /* PRQA S 0306 3 */ /* MD_Fr_0306 */ 
  /* PRQA S 0310 2 */ /* MD_Fr_0310 */ 
  /* PRQA S 0311 1 */ /* MD_Fr_0311 */
  p16Dst = (FR_P2VAR_APPLDATA(uint16))((uint32)pDst);  

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy word-wise from source pointer destination register address without changing the byte-order. */
  CpyLength = (CpyLength + 1) >> 1;
  DWordCnt = CpyLength >> 1;

  while (DWordCnt != 0)
  {
    payloadValue = (uint32)(*p32Src);
    *p16Dst = (uint16)payloadValue; /* SBSW_FR_WritePtr */
    p16Dst  = &p16Dst[1];
    *p16Dst = (uint16)(payloadValue >> 16); /* SBSW_FR_WritePtr */
    p32Src  = &p32Src[1];
    p16Dst  = &p16Dst[1];
    DWordCnt--;
  }
  if ((CpyLength % 2) != 0)  /* copy last 16bit for odd CpyLength */
  {
    *p16Dst = (uint16)(*p32Src); /* SBSW_FR_WritePtr */
  }
} /* Fr_VReadDataFromCC() */

/**********************************************************************************************************************
 *  Fr_VWriteDataToCC()
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
 */
FR_LOCAL_INLINE FUNC(void, FR_CODE) Fr_VWriteDataToCC
(
  Fr_RegisterPtrType pDst,
  FR_P2CONST_APPLDATA(uint8) pSrc,
  uint8 CpyLength
)
{
  /* ----- Implementation ----------------------------------------------- */
#  if defined(FR_NONALIGNED_SRCMEMORY) /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#   if (FR_NONALIGNED_SRCMEMORY == STD_ON) 
  /* #10 If FR_NONALIGNED_SRCMEMORY is enabled:
   *       Copy byte-wise from register source address to destination pointer without changing the byte-order and do
   *       proper alignment. */
  if ((0x01 & pSrc) != 0x0) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    uint32 src32;
    uint8 count8 = (CpyLength) >> 2;

    while (count8 != 0)
    {
      src32 = pSrc[3] << 24 |
              pSrc[2] << 16 |
              pSrc[1] <<  8 |
              pSrc[0] <<  0;

      pSrc  = &pSrc[4];
      *pDst = src32; /* SBSW_FR_WritePtr */

      --count8;
    }

    if ((CpyLength % 4) == 3)
    {
      src32 = pSrc[2] << 16 |
              pSrc[1] <<  8 |
              pSrc[0] <<  0;
      *pDst = src32; /* SBSW_FR_WritePtr */
    }
    else if ((CpyLength % 4) == 2)
    {
      src32 = pSrc[1] <<  8 |
              pSrc[0] <<  0;
      *pDst = src32; /* SBSW_FR_WritePtr */
    }
    else if ((CpyLength % 4) == 1)
    {
      src32 = pSrc[0] <<  0;
      *pDst = src32; /* SBSW_FR_WritePtr */
    }
  }
  else
#   endif /* (FR_NONALIGNED_SRCMEMORY == STD_ON) */
#  endif /* defined(FR_NONALIGNED_SRCMEMORY) */
  /* #20 Otherwise:
   *       Copy word-wise from register source address to destination pointer without changing the byte-order. */
  {
    /* ----- Local Variables ---------------------------------------------- */
    FR_P2CONST_APPLDATA(uint16) p16SrcL;
    FR_P2CONST_APPLDATA(uint16) p16SrcH;
    Fr_RegisterPtrType p32Dst;
    uint16 DWordCnt;

    /* PRQA S 0310 2 */ /* MD_Fr_0310 */ 
    /* PRQA S 0311 1 */ /* MD_Fr_0311 */
    p16SrcL    = (FR_P2CONST_APPLDATA(uint16))((FR_P2VAR_APPLDATA(uint32))pSrc);   
    p32Dst     = pDst;

    CpyLength = (CpyLength + 1) >> 1;
    DWordCnt  =  CpyLength  >> 1;

    p16SrcH = &(p16SrcL[1]);

    while (DWordCnt != 0)
    {
      *p32Dst = (((uint32)(*p16SrcH)) << 16u) | (*p16SrcL); /* SBSW_FR_WritePtr */
      p32Dst  = &(p32Dst[1]);
      p16SrcH = &(p16SrcH[2]);
      p16SrcL = &(p16SrcL[2]);
      DWordCnt--;
    }

    if ((CpyLength % 2) != 0) /* copy last 16bit for odd CpyLength */
    {
      *p32Dst = *p16SrcL; /* SBSW_FR_WritePtr */
    }
  }
} /* Fr_VWriteDataToCC */

# if defined FR_CPU_RH850 /* COV_FR_EQUIVALENT_HARDWARE */
/***********************************************************************************************************************
 *  Fr_VWaitMs()
 **********************************************************************************************************************/
/*! 
 *
 * Internal comment removed.
 *
 *
 */ 
/* PRQA S 1006, 3006 15 */ /* MD_MSR_1.1 */
FR_LOCAL_INLINE void Fr_VWaitMs(uint16 Fr_Time)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 cnt;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Execute NOPs over Fr_Time ms. */
  for (cnt = 0; cnt < ( Fr_Time * 6154 ); cnt++)
  {
    __asm("NOP"); /* SBSW_FR_AsmNop */ 
  }
}
# endif

#if (FR_VENABLE_MID_FILTERING == STD_ON)
/**************************************************************************************************
*  Fr_VIsMsgId()
**************************************************************************************************/
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
 */
FR_LOCAL_INLINE FUNC(boolean, FR_CODE) Fr_VIsMsgId(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  uint16 msgIDreceived;
  uint16_least i;
  /* #10 Per default mark the current handled message buffer to be received normally. */
  boolean msgIDfound = TRUE;

/** 
 *
 * Internal comment removed.
 *
 *
 *
 */

  /* ----- Implementation ----------------------------------------------- */
# if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) || (Fr_IsPostbuild())
  /* #20 If there is at least one entry in the configured message ID array list: */
  if (FR_GETSIZE_MID_ARRAY > 0u)
# endif
  {
    /* #30 If Payload Preamble Indicator flag (PPI) is set in the Read Header Section 3 register
     *     (RDHS3) of the current handled message buffer: */
    if (Fr_CheckPPI(FR_VCTRL_IDX))
    {
      /* #40 If the Frame ID flag (FID) of the Read Header Section 1 register (RDHS1) of the requested
       *     message buffer is in the dynamic segment: */
      if (Fr_IsDynamicFrame(FR_VCTRL_IDX))
      {
        /* #50 If the first 2 bytes of the payload are not found in the configured message ID array:
         *       Re-Mark the current handled message buffer not to be received. */
        msgIDfound = FALSE;
        msgIDreceived = Fr_GetMessageID(FR_VCTRL_IDX);

        for (i = 0; i < FR_GETSIZE_MID_ARRAY; i++)
        {
          if (msgIDreceived == FR_GETMIDFILTER(i))
          {
            msgIDfound = TRUE;
            break;
          }
        }
      }
    }
  }

  return msgIDfound;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_VIsMsgId() */
#endif /* FR_VENABLE_MID_FILTERING */

#if (FR_CC_READ_BACK_SUPPORT == STD_ON)
/**************************************************************************************************
*  Fr_VReadBackSupport()
**************************************************************************************************/
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
 */
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VReadBackSupport(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  /* value assignment necessary if FR_CTRL_TEST_COUNT == 0 */
  Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;   
  boolean nextLoopCnt = FALSE;
  boolean earlyBreak = FALSE;
  uint8_least counter;
  uint8_least index;
  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Loop Fr_GetCtrlTestCount times: */
  for (counter = 0; counter < Fr_GetCtrlTestCount; counter++) /* COV_FR_HARDWARE_FAILURE */
  {
    /* #20 If ROM value in configuration struct and SUC Configuration Register 1 (SUCC1) are equal beside
     *     the CHI Command Vector flags (CMDn): */
    if ((Fr_VCCReadValue(FR_VCTRL_IDX, Fr_VGetCcCfgAddrAt(FR_VCTRL_IDX, FR_VER_SUCC1_POSITION)) & FR_VER_FILTER_CFG_BITS) ==
         Fr_VGetCcCfgValAt(FR_VCTRL_IDX, FR_VER_SUCC1_POSITION)) /* COV_FR_HARDWARE_FAILURE */
    {
      /* #30 Check ROM values with register values of all low level parameters. */
      for (index = FR_VER_FIRST_ELEMENT; index < (FR_VER_FIRST_ELEMENT + FR_VER_LENGTH); index++)
      {
        if (Fr_VCCReadValue(FR_VCTRL_IDX, Fr_VGetCcCfgAddrAt(FR_VCTRL_IDX, index)) != Fr_VGetCcCfgValAt(FR_VCTRL_IDX, index)) /* COV_FR_HARDWARE_FAILURE */
        {
          nextLoopCnt = TRUE;
          break;
        }
      }

      /* #40 If at least one ROM value was not equal to its register value:
       *       Skip keyslot configuration check. */
      if (nextLoopCnt == FALSE) /* COV_FR_HARDWARE_FAILURE */
      {

        /* #45 Otherwise:
         *    If there is no Key Slot used, all checks are passed, thus break the Fr_GetCtrlTestCount loop
         *    and mark the register configuration as valid.
         */
        /* ESCAN00087171 */
        if ((Fr_VGetCcCfgValAt(FR_VCTRL_IDX, FR_VER_SUCC1_POSITION) & (FR_SUCC1_TXST | FR_SUCC1_TXSY))
          == (uint32)FR_VER_KEYSLOT_NOT_USED) 
        {
          retVal = E_OK;
          earlyBreak = TRUE;
        }
        else
        {
          /* #50 Otherwise:
           *      If Transmit Startup Frame in Key Slot (TXST) or Transmit Sync Frame in Key Slot (TXSY)
           *      flags are set in ROM configuration struct for SUC Configuration Register 1 (SUCC1): 
           */

          pBufCfg   = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, FR_VER_KEYSLOT_BUFFER_IDX);

          Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCM, FR_OBCM_RHSS); /* SBSW_FR_WriteHwReg */
          Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCR, (FR_OBCR_REQ | (((uint32)FR_VER_KEYSLOT_BUFFER_IDX) & FR_OBCR_OBRS_MASK))); /* SBSW_FR_WriteHwReg */
          (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
          Fr_VCCSetBits(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_VIEW); /* SBSW_FR_WriteHwReg */

          /* #60 If the ROM and register configuration values of the key slot message buffer are equal:
           *       Break the Fr_GetCtrlTestCount loop and mark the register configuration as valid because
           *       all conditions have been met. */
          if (pBufCfg->WRHS1 == Fr_GetRDHS1(FR_VCTRL_IDX)) /* COV_FR_HARDWARE_FAILURE */
          {
            retVal = E_OK;
            earlyBreak = TRUE;
          }
        }

        if (earlyBreak == TRUE) /* COV_FR_HARDWARE_FAILURE */
        {
          break;
        }
      }
    }
  }

  /* #70 If the register configuration has been marked as valid in previous loop:
   *       Report DemEvent FR_DEM_E_CTRLTESTRESULT with DEM_EVENT_STATUS_PASSED.
   *     Otherwise:
   *       Report DemEvent FR_DEM_E_CTRLTESTRESULT with DEM_EVENT_STATUS_FAILED. */
  if (retVal == E_OK) /* COV_FR_HARDWARE_FAILURE */
  {
    Fr_DemReportErrorStatus(FR_DEM_E_CTRLTESTRESULT, DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    Fr_DemReportErrorStatus(FR_DEM_E_CTRLTESTRESULT, DEM_EVENT_STATUS_FAILED);
  }

  return retVal;

  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_VReadBackSupport() */
#endif

/**********************************************************************************************************************
 *  Fr_VEnterConfigMode()
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
 */
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VEnterConfigMode(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  uint32 pocState;
  Fr_RegisterPtrType IbfAdr;
  uint16_least IbfCount;

  /* ----- Implementation ----------------------------------------------- */
  pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);

  /* #10 If communication controller is not in POCState CONFIG: */
  if (pocState != CCPOCS_CONFIG)
  {
    /* #20 If communication controller is in POCState HALT, READY or DEFAULT_CONFIG: */
    if (((pocState == CCPOCS_HALT) | (pocState == CCPOCS_READY) | (pocState == CCPOCS_DEFAULT_CONFIG)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
    {
      /* #30 If communication controller is in POCState HALT:
       *       Execute POCcommand CMD_CONFIG to put the CC into POCState DEFAULT_CONFIG.
       *     Otherwise:
       *       Do nothing because CC can change to POCstate CONFIG without further state changes. */
      if (pocState == CCPOCS_HALT)
      {
        (void)Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_CONFIG);
      }
    }
    /* #40 Otherwise: execute POC commands CMD_FREEZE and CMD_CONFIG to put CC in POCState DEFAULT_CONFIG. */
    else
    {      

      (void)Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_FREEZE);
      (void)Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_CONFIG);
    }

    /* #50 Execute POC command CMD_CONFIG to trigger state transition to POCState CONFIG. */
    (void)Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_CONFIG);
  }

  /* #60 Clear the RAM buffers, IBF and OBF due to ERAY Errata Sheet (REL20100723) No. 35. */
  IbfAdr = (Fr_RegisterPtrType)(CCBUF_WRDS1 + Fr_VCCGetRegStartAddr(FR_VCTRL_IDX));

  for (IbfCount = FR_SIZE_CLEAR_IBF; IbfCount != 0; --IbfCount)
  {
    *IbfAdr = 0; /* SBSW_FR_WriteHwReg */
    IbfAdr = &IbfAdr[1];
  }

  /* #70 Executing the POC command CMD_CLEAR_RAMS to initialize all module-internal RAMS with 0. */
  return Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_CLEAR_RAMS);
} /* Fr_VEnterConfigMode() */

/**********************************************************************************************************************
 *  Fr_VLeaveConfigMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FR_LOCAL_INLINE FUNC(Std_ReturnType, FR_CODE) Fr_VLeaveConfigMode(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write special key sequence to Configuration Lock Key flags (CLK) of Lock Register (LCK) in order to leave
   *     the POCState CONFIG. */
  Fr_VCCWriteValue(FR_VCTRL_IDX, FR_LCK, FR_LCK_CLK_KEY1); /* SBSW_FR_WriteHwReg */
  Fr_VCCWriteValue(FR_VCTRL_IDX, FR_LCK, FR_LCK_CLK_KEY2); /* SBSW_FR_WriteHwReg */

  /* #20 Trigger transition to POCstate READY. */
  return (Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_READY));
} /* Fr_VLeaveConfigMode() */

/**********************************************************************************************************************
 *  Fr_VCalHeaderCRC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FR_LOCAL_INLINE FUNC(uint16, FR_CODE) Fr_VCalHeaderCRC
(
  uint8 Fr_PayloadLength, 
  uint16 Fr_CRC
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Initialize the CRC value. */
  uint16 vCrcReg = Fr_CRC;

  /* #20 No startup and sync flag because recalculation of CRC is only done for frames in dynamic segment. */
  uint16 vHeader = (uint8)Fr_PayloadLength << 4;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 Calculate the header CRC according to FlexRay specification 2.1 A. Only the payload length changed. */
  for (i = 0; i < FR_CRC_RUNS; ++i)
  {
    uint16 vCrcNext = (vHeader ^ vCrcReg) & (1 << 10);
    vCrcReg = vCrcReg << 1;

    if (vCrcNext > 0u)
    {
      vCrcReg ^= FR_CRC_POLYNOM;
    }

    vHeader = (uint16)vHeader << 1;
  }

  vCrcReg &= FR_HEADER_CRC_MAX;

  return vCrcReg;
} /* Fr_VCalHeaderCRC() */

/* PRQA S 3453 MISRA_SINGLE_API */ /* MD_MSR_19.7 */

# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  define Fr_VEnterConfigMode(Fr_CtrlIdx)                             Fr_VEnterConfigMode()
#  define Fr_VLeaveConfigMode(Fr_CtrlIdx)                             Fr_VLeaveConfigMode()
#  define Fr_VIsMsgId(Fr_CtrlIdx)                                     Fr_VIsMsgId()
#  define Fr_VReadBackSupport(Fr_CtrlIdx)                             Fr_VReadBackSupport()
# endif

/* PRQA L:MISRA_SINGLE_API */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**************************************************************************************************
                                      A  U  T  O  S  A  R
**************************************************************************************************/
/**********************************************************************************************************************
 *  Fr_Init()
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
FUNC(void, FR_CODE) Fr_Init
(
  FR_P2CONST_CFG(Fr_ConfigType) Fr_ConfigPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FR_E_NO_ERROR;
#if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  uint8 ecumErrorId = FR_E_NO_ERROR;
#endif
#if (FR_NUM_CTRL_USED > 1) || (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  uint8_least Fr_CtrlIdx = 0u;
#endif

  FR_DUMMY_STATEMENT(Fr_ConfigPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* #10 If if FR_DEV_ERROR_DETECT is enabled, set component initialization state to "FR_VUNINITPTR". */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  Fr_VFrDrvState = FR_VUNINITPTR;
#endif

  /* ----- Development Error Checks ------------------------------------- */

#if (Fr_IsPostbuild())
  Fr_VPostBuildConfigPtr      = (FR_P2CONST_CFG(Fr_VConfigType)) Fr_ConfigPtr;
#endif

  /* #20 Check the validity of the configuration pointer. */
  if (Fr_ConfigPtr == NULL_PTR)
  {
#if (FR_DEV_ERROR_DETECT == STD_ON)
    errorId = FR_E_INV_POINTER;
#endif
/* #30 If the configuration variant is post-build loadable: */
#if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
    ecumErrorId = ECUM_BSWERROR_NULLPTR;
  }
  /* #40 Check compatibility with the FR generator */
  else if (Fr_VPostBuildConfigPtr->GeneratorCompatibilityVersion != (uint16)FR_GENERATOR_COMPATIBILITY_VERSION)
  {
    ecumErrorId = ECUM_BSWERROR_COMPATIBILITYVERSION;
  }
  /* #50 Use the magic number to proof the validity of the configuration given as input. */
  else if (Fr_VPostBuildConfigPtr->FinalMagicNumber != FR_FINAL_MAGICNUMBER)
  {
    ecumErrorId = ECUM_BSWERROR_MAGICNUMBER;
#endif
  }
  /* #60 If the initial checks are passed or not required: */
  else
  {
    /* ----- Implementation ----------------------------------------------- */

    Fr_Rtm_Start(Fr_Init);

#if (Fr_IsPostbuild())
    Fr_VRxVirtBuf2PhysBufMapPtr = Fr_VPostBuildConfigPtr->RxVirtBuf2PhysBufMap;
    Fr_VTxVirtBuf2PhysBufMapPtr = Fr_VPostBuildConfigPtr->TxVirtBuf2PhysBufMap;
#endif

#if (FR_NUM_CTRL_USED > 1)
    for (Fr_CtrlIdx=0; Fr_CtrlIdx < FR_NUM_CTRL_USED; ++Fr_CtrlIdx)
    {
#endif

# if (defined FR_CPU_RH850) /* COV_FR_EQUIVALENT_HARDWARE */
      {
#  if (FR_VHARDWARE_CANCELLATION == STD_ON)
        uint32 Fr_VLoopTimeout = 0;
#  endif
        /* FROC register */
        /* To enable the FlexRay cell at RH850, OEP (Operation Enable bit Protection) need to be set to unprotected. */
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_FROC, 0x0UL);         /* OEP unprotected (is also reset value) */ /* SBSW_FR_WriteHwReg */
      
        /* Beside enabling the FlexRay cell, also the timer0 interrupt is enabled and then write access is re-protected again. */
        do {
          Fr_VCCWriteValue(FR_VCTRL_IDX, FR_FROC, (FR_FROC_T0IE | FR_FROC_OE)); /* enable OE and T0IE */ /* SBSW_FR_WriteHwReg */        
          FR_INCREASETIMEOUTCOUNTER;
        } while (((Fr_VCCReadValue(FR_VCTRL_IDX, FR_FROS) & FR_FROS_OS) != TRUE) && ((uint8)FR_NOHWTIMEOUT)); /* COV_FR_HARDWARE_FAILURE */

        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_FROC, (FR_FROC_T0IE | FR_FROC_OEP | FR_FROC_OE)); /* enable OE protection as soon as operation is enabled */ /* SBSW_FR_WriteHwReg */
        /* ESCAN00093807 */
        Fr_VWaitMs(FR_WAIT_STATES);
      }
# endif

      /* To enable the access to internal E-Ray registers this two consecutive      */
      /* write accesses to the Control Setting Lock Key has to be directly proceeded */
# if (defined FR_PROCESSOR_FX4) || (defined C_PROCESSOR_JCP2011) || (defined FR_PROCESSOR_GENERIC) || (defined FR_PROCESSOR_PX4) /* COV_FR_EQUIVALENT_HARDWARE */
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_CIF_2, FR_CIF_2_CSLK_FIRST_MASK); /* SBSW_FR_WriteHwReg */
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_CIF_2, FR_CIF_2_CSLK_SECOND_MASK); /* SBSW_FR_WriteHwReg */
# endif

      /* #70 If transition from ANY POCstate to HALT is executed correctly by executing POC command CMD_FREEZE: */
      if (Fr_VExecutePOCCommand((uint8)FR_VCTRL_IDX, CCCMD_FREEZE) == (Std_ReturnType)E_OK)
      {
        /* #80 Wait until communication controller is in POCstate HALT. */
        (void)Fr_VSetReg((uint8)FR_VCTRL_IDX, (uint32)FR_CCSV, CCPOCS_HALT, NEQUAL);

        /* #90 Disable all error and status interrupts. */
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_EIER, 0xFFFFFFFFUL); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_SIER, 0xFFFFFFFFUL); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_EIR, 0xFFFFFFFFUL); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_SIR, 0xFFFFFFFFUL); /* SBSW_FR_WriteHwReg */

        /**
         *
         *Internal comment removed.
 *
 *
 *
 *
         */

#if (FR_DEV_ERROR_DETECT == STD_ON)
        /* #100 if FR_DEV_ERROR_DETECT is enabled, set component initialization state to "FR_VUNINITCFG". */
        Fr_VFrDrvState = FR_VUNINITCFG;
#endif
      }
#if (FR_NUM_CTRL_USED > 1)
    }
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_INIT, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
#if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  if (ecumErrorId != FR_E_NO_ERROR)
  {
    EcuM_BswErrorHook((uint16) FR_MODULE_ID, ecumErrorId);
  }
#endif

  Fr_Rtm_Stop(Fr_Init); /* ESCAN00070620 */

  return;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_Init() */

/**********************************************************************************************************************
 *  Fr_ControllerInit()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
#if (FR_CC_READ_BACK_SUPPORT == STD_ON)
  Std_ReturnType verificationStep = E_NOT_OK;
#endif
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check whether component initialization state is either "FR_VUNINITCFG" or "FR_VINIT". */
  if (Fr_VFrDrvState == FR_VUNINITPTR)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    Fr_Rtm_Start(Fr_ControllerInit); /* ESCAN00070620 */

    /* #40 If state transition from POCstate DEFAULT_CONFIG to CONFIG is performed correctly by executing POC command CMD_CONFIG: */
    retVal = Fr_VEnterConfigMode(FR_VCTRL_IDX);
    if (retVal == E_OK)
    {
      uint16_least ccRegIdx;
      uint8_least  u8BufIdx;

      FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;

      /* #50 Write the configuration registers from the config structs to the CC. */
      for (ccRegIdx = 0; ccRegIdx < Fr_VGetNumCcRegs(FR_VCTRL_IDX); ++ccRegIdx)
      {
        Fr_VCCWriteValue(FR_VCTRL_IDX, (uint32)(Fr_VGetCcCfgAddrAt(FR_VCTRL_IDX, ccRegIdx)), Fr_VGetCcCfgValAt(FR_VCTRL_IDX, ccRegIdx)); /* SBSW_FR_WriteHwReg */
      }

      /* #60 Clear the Command Not Accepted flag (CNA) of the Error Interrupt Register (EIR) which has been set while
       *     writing SUCC1. */
      Fr_VCCSetBits(FR_VCTRL_IDX, FR_EIR, FR_EIR_CNA); /* SBSW_FR_WriteHwReg */

      /* #70 Clear the Transfer Input Buffer Completed flag (TIBC) of the Status Interrupt Register (SIR) which has been
       *     set while configuring the message buffers. */
      Fr_VCCSetBits(FR_VCTRL_IDX, FR_SIR, FR_SIR_TIBC); /* SBSW_FR_WriteHwReg */

      /* #80 Loop over all physical message buffer configurations: */
      for (u8BufIdx = 0; u8BufIdx < Fr_VGetNumCcBufs(FR_VCTRL_IDX); ++u8BufIdx)
      {
        /* Get configuration of current message buffer index from ROM (Fr_VCcBufs). */
        pBufCfg = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, u8BufIdx);

        /* #100 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
         *      to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
        (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

        /* #110 Write header information from ROM to Input Buffer. */
        Fr_VCCWriteValueWRHS(FR_VCTRL_IDX, FR_WRHS1, pBufCfg->WRHS1); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValueWRHS(FR_VCTRL_IDX, FR_WRHS2, pBufCfg->WRHS2); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValueWRHS(FR_VCTRL_IDX, FR_WRHS3, pBufCfg->WRHS3); /* SBSW_FR_WriteHwReg */

        /* #120 Trigger the transfer of the header data from Input Buffer to the Message RAM. */
        Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, FR_VFR_IBCM_INITVALUE); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValueIBCR(FR_VCTRL_IDX, (uint32)pBufCfg->IBCR); /* SBSW_FR_WriteHwReg */
      }

      /* #130 If FR_CC_READ_BACK_SUPPORT is enabled check certain register values if they correspond to their desired values. */
#if (FR_CC_READ_BACK_SUPPORT == STD_ON)
      verificationStep = Fr_VReadBackSupport(FR_VCTRL_IDX);
      
      if (verificationStep == E_OK) /* COV_FR_HARDWARE_FAILURE */
#endif
      {

        /* #140 If the readback values are fine, finalize configuration phase. */
        retVal = Fr_VLeaveConfigMode(FR_VCTRL_IDX);

#if (FR_DEV_ERROR_DETECT == STD_ON)
        if (retVal == E_OK) /* COV_FR_HARDWARE_FAILURE */
        {
            /* #150 If FR_DEV_ERROR_DETECT is enabled, set component initialization state of the component to "FR_VINIT" */
            Fr_VFrDrvState = FR_VINIT;
        }
        /* #160 Otherwise: Report the DemEvent FR_DEM_E_ACCESS with DEM_EVENT_STATUS_FAILED when transition to POCstate CONFIG or
         *      to READY failed. */
#endif
      }
    }

    /* #170 Otherwise: Report the FR_DEM_E_ACCESS error to DEM when transition to POCstate DEFAULT_CONFIG or to DEFAULT failed. */
    if (retVal == E_NOT_OK)
    {
      Fr_DemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_CONTROLLER_INIT, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  Fr_Rtm_Stop(Fr_ControllerInit);  /* ESCAN00070620 */

  return (retVal);

  /* PRQA S 6080 3 */ /* MD_MSR_STMIF */
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
}  /* Fr_ControllerInit() */

/**********************************************************************************************************************
*  Fr_StartCommunication()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that POCstate is READY. */
  else if (Fr_VCCGetPocState(FR_VCTRL_IDX) != CCPOCS_READY)
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Trigger transition from POCstate READY to STARTUP by executing POC command CMD_RUN. */
    retVal = Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_RUN);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_START_COMMUNICATION, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_StartCommunication() */

/**********************************************************************************************************************
 *  Fr_AllowColdstart()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
#if (FR_DEV_ERROR_DETECT == STD_ON)
  uint32 pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);
#endif

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that communication controller is not in POCstate DEFAULT_CONFIG or CONFIG or HALT. */
  else if (((pocState == CCPOCS_DEFAULT_CONFIG) | (pocState == CCPOCS_CONFIG) | (pocState == CCPOCS_HALT)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Trigger transition from POCstate READY to STARTUP using coldstart node path by executing POC command CMD_ALLOW_COLDSTART. */
    retVal = Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_ALLOW_COLDSTART);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_ALLOW_COLDSTART, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_AllowColdstart() */

/**********************************************************************************************************************
 *  Fr_HaltCommunication()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  uint32 pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);

  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that communication controller is either in POCstate NORMAL_ACTIVE or in NORMAL_PASSIVE. */
  else if (((pocState != CCPOCS_NORMAL_ACTIVE) & (pocState != CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Trigger transition from either POCstate NORMAL_ACTIVE or NORMAL_PASSIVE to HALT. */
    retVal = Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_HALT);
  }

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_HALT_COMMUNICATION, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_HaltCommunication() */

/**********************************************************************************************************************
 *  Fr_AbortCommunication()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #40 If transition from ANY POCstate to HALT is executed correctly by executing POC command CMD_FREEZE: */
    if (Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_FREEZE) == E_OK)
    {
      /* #50 Wait until communication controller is in POCstate HALT. */
      retVal = Fr_VSetReg(FR_VCTRL_IDX, FR_CCSV, CCPOCS_HALT, NEQUAL);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_ABORT_COMMUNICATION, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
} /* Fr_AbortCommunication() */

/**********************************************************************************************************************
 *  Fr_SendWUP()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that POCstate is READY. */
  else if (Fr_VCCGetPocState(FR_VCTRL_IDX) != CCPOCS_READY)
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Trigger transition from POCstate READY to WAKEUP by executing POC command CMD_WAKEUP. */
    retVal = Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_WAKEUP);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_SEND_WUP, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_SendWUP() */

/**********************************************************************************************************************
 *  Fr_SetWakeupChannel()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  Fr_ChannelType Fr_ChnlIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that input parameter Fr_ChnlIdx is either FR_CHANNEL_A or FR_CHANNEL_B. */
  else if (((Fr_ChnlIdx != FR_CHANNEL_A) & (Fr_ChnlIdx != FR_CHANNEL_B)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_CHNL_IDX;
  }
  /* #40 If required, check that POCstate is READY. */
  else if (Fr_VCCGetPocState(FR_VCTRL_IDX) != CCPOCS_READY)
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #50 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 If transition from POCstate READY to CONFIG is execute correctly by executing POC command CMD_CONFIG: */
    if (Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_CONFIG) == E_OK)
    {
      /* #70 If requested Fr_ChnlIdx is FR_CHANNEL_B:
       *     Set Wakeup Channel Select flag (WUCS) of SUC Configuration Register 1 (SUCC1) to 1 (Send wakeup pattern on channel B). */
      if (Fr_ChnlIdx == FR_CHANNEL_B)
      {
        Fr_VCCSetBits(FR_VCTRL_IDX, FR_SUCC1, FR_SUCC1_WUCS); /* SBSW_FR_WriteHwReg */
      }
      /* #80 Otherwise:
       *     Set Wakeup Channel Select flag (WUCS) of SUC Configuration Register 1 (SUCC1) to 0 (Send wakeup pattern on channel A). */
      else
      {
        Fr_VCCResetBits(FR_VCTRL_IDX, FR_SUCC1, FR_SUCC1_WUCS); /* SBSW_FR_WriteHwReg */
      }

      /* #90 Trigger transition from POCstate CONFIG back to READY. */
      retVal =  Fr_VLeaveConfigMode(FR_VCTRL_IDX);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_SET_WAKEUP_CHANNEL, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_SetWakeupChannel() */

/**********************************************************************************************************************
 *  Fr_GetPOCStatus()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  FR_P2VAR_APPLDATA(Fr_POCStatusType) Fr_POCStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 tempCCSVReg;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameter 'Fr_POCStatusPtr'. */
  else if (Fr_POCStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #50 Read the value of CC Status Vector register (CCSV). */
    tempCCSVReg = Fr_VCCReadValue(FR_VCTRL_IDX, FR_CCSV);

    /* #60 Save the values of CCSV flags to their corresponding struct members of Fr_POCStatusPtr. */
    Fr_POCStatusPtr->State = Fr_VPocStateMapTable[(tempCCSVReg & CCPOCS_GROUP_MASK) >> CCPOCS_GROUP_SHIFT][tempCCSVReg & FR_CCSV_POCS_VALUE_MASK]; /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->Freeze         = (boolean) ((tempCCSVReg & FR_CCSV_FSI) == FR_CCSV_FSI); /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->CHIHaltRequest = (boolean) ((tempCCSVReg & FR_CCSV_HRQ) == FR_CCSV_HRQ); /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->ColdstartNoise = (boolean) ((tempCCSVReg &  FR_CCSV_CSNI) == FR_CCSV_CSNI); /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->SlotMode =  Fr_VSlotModeMapTable[(tempCCSVReg & FR_CCSV_SLM_MASK) >> FR_CCSV_SLM_SHIFT ]; /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->ErrorMode    = (Fr_ErrorModeType) Fr_VCCReadBitsShift(FR_VCTRL_IDX, FR_CCEV, FR_CCEV_ERRM_MASK, FR_CCEV_ERRM_SHIFT); /* SBSW_FR_WriteStructMember */
    Fr_POCStatusPtr->WakeupStatus = (Fr_WakeupStatusType) ((tempCCSVReg & FR_CCSV_WSV_MASK) >> FR_CCSV_WSV_SHIFT); /* SBSW_FR_WriteStructMember */
    if ((tempCCSVReg & CCPOCS_GROUP_MASK) == CCPOCS_STARTUP_GROUP)
    {
      Fr_POCStatusPtr->StartupState = Fr_VStartupStateMapTable[tempCCSVReg & FR_CCSV_POCS_VALUE_MASK]; /* SBSW_FR_WriteStructMember */
    }
    else
    {
      Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED; /* SBSW_FR_WriteStructMember */
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_POC_STATUS, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_GetPOCStatus() */

/**********************************************************************************************************************
 *  Fr_TransmitTxLPdu()
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
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 uint16 Fr_LPduIdx,
 FR_P2CONST_APPLDATA(uint8) Fr_LPduPtr,
 uint8 Fr_LPduLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  /* #10 Get the index to the associated virtual message buffer. */
  uint8 cfgBufIdx = (Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;

  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #20 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #30 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #40 If required, check that input parameter 'Fr_LPduIdx' is less than or equal to the total number of Tx frame
   *     triggerings. */
  else if (Fr_LPduIdx >= Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /* #50 If required, check that input parameter 'Fr_LPduLength' is less than or equal to the length configured for
   *     this frame triggering. */
  else if (Fr_LPduLength > ((Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx)->WRHS2) >> FR_WRHS2_PLC_BYTE_SHIFT))
  {
    errorId = FR_E_INV_LENGTH;
  }
  /* #60 If required, check plausibility of input parameter 'Fr_LPduPtr'. */
  else if (Fr_LPduPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #70 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #80 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
     *     to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
    (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

    /**
     *
     *Internal comment removed.
 *
 *
 *
 *
     */
    /* #90 If message buffer is marked to be used with dynamic payload length OR with buffer reconfiguration:  */
    if (((Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).Info & (FR_TXVIRTBUF_INFO_DYNPAYLOAD + FR_TXVIRTBUF_INFO_RECONFIG)) != 0)
    {
      uint32  tmpWRHS2;

      /* #100 Get the physical message buffer index for the requested Fr_LPduIdx. */
      pBufCfg = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx);

#if (FR_BUFFER_RECONFIG == STD_ON)
      cfgBufIdx = pBufCfg->IBCR;
#endif

      /* #120 Get the header CRC for the requested physical message buffer by either:
       *       Calculating the header CRC at runtime depending on the requested Fr_LPduLength (If FR_BUFFER_RECONFIG
       *         is enabled AND message buffer is configured with dynamic payload Length OR if FR_BUFFER_RECONFIG is
       *         disabled).
       *       Using the static header CRC of the generated message buffer configuration (if FR_BUFFER_RECONFIG is
       *         enabled AND message buffer is NOT configured with dynamic payload Length). */
#if (FR_BUFFER_RECONFIG == STD_ON)
      if (((Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).Info & FR_TXVIRTBUF_INFO_DYNPAYLOAD) != 0)
#endif
      {
        uint8 dlcWord = (Fr_LPduLength + 1) >> 1;
        tmpWRHS2 = ((uint32)dlcWord << (FR_WRHS2_PLC_SHIFT)) | (uint32)Fr_VCalHeaderCRC(dlcWord, (Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).crc);
      }
#if (FR_BUFFER_RECONFIG == STD_ON)
      else
      {
        tmpWRHS2 = (pBufCfg->WRHS2);
      }
#endif

      /* #160 Enter Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #170 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
       *      to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);
#if (FR_RECONFIGLPDUSUPPORT == STD_ON)
      /* #180 Write the new header CRC to the Write Header Section registers (WRHSn). */
      if ((pBufCfg->WRHS1 & (FR_RDHS1_CHA | FR_RDHS1_CHB)) == 0)
      {
        uint32 rdhs1 = 0;
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCM, FR_OBCM_RHSS); /* SBSW_FR_WriteHwReg */
        (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCR, (FR_OBCR_REQ | (((uint32)cfgBufIdx) & FR_OBCR_OBRS_MASK))); /* SBSW_FR_WriteHwReg */
        (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
        Fr_VCCSetBits(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_VIEW); /* SBSW_FR_WriteHwReg */
      
        rdhs1 = Fr_VCCReadValue(FR_VCTRL_IDX, FR_RDHS1);
        Fr_WriteWRHS1(FR_VCTRL_IDX, rdhs1); /* SBSW_FR_WriteHwReg */
      }
      else
#endif
      {
        Fr_WriteWRHS1(FR_VCTRL_IDX, pBufCfg->WRHS1); /* SBSW_FR_WriteHwReg */
      }
      Fr_WriteWRHS2(FR_VCTRL_IDX, tmpWRHS2); /* SBSW_FR_WriteHwReg */
      Fr_WriteWRHS3(FR_VCTRL_IDX, pBufCfg->WRHS3); /* SBSW_FR_WriteHwReg */

      /* #190 Set Transmission Request Host (STXRH), Load Data Section Host (LDSH) and Load Header Section Host (SHSH)
       *      flags in the Input Buffer Command Mask Register (IBCM) to trigger the update of the data and of the header
       *      section. */
      Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, (FR_IBCM_STXRH | FR_IBCM_LDSH | FR_IBCM_LHSH)); /* SBSW_FR_WriteHwReg */
    }
    /* #200 Otherwise:  */
    else
    {
      /* #201 Enter Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VENTER_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #210 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
       *      to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

      /* #220 Set Transmission Request Host (STXRH) and Load Data Section Host (LDSH) flags in the Input Buffer Command
       *      Mask Register (IBCM) to trigger the update of the data section. */
      Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, (FR_IBCM_STXRH | FR_IBCM_LDSH)); /* SBSW_FR_WriteHwReg */
    }

    /* #230 Copy the given payload to Write Data Section registers (WRDSn). */
    (void)Fr_VWriteDataToCC((Fr_RegisterPtrType)(Fr_VCCRegAddr(FR_VCTRL_IDX, FR_WRDSn)), Fr_LPduPtr, Fr_LPduLength); /* PRQA S 0306 */ /* MD_Fr_0306 */ /* SBSW_FR_FctCallPtr2HwReg */

    /* #240 Select the target message buffer and trigger the transfer to the Message RAM and finalize the message buffer
     *      transmission. */
    Fr_VCCWriteValueIBCR(FR_VCTRL_IDX, cfgBufIdx); /* SBSW_FR_WriteHwReg */

    /* #250 Leave Fr_FR_EXCLUSIVE_AREA_0 */
    FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MD_MSR_14.3 */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_TRANSMIT_TX_LPDU, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 3 */ /* MD_MSR_STMIF */
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 1 */ /* MD_MSR_STPTH */
} /* Fr_TransmitTxLPdu() */

/**********************************************************************************************************************
 *  Fr_ReceiveRxLPdu()
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
FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 uint16 Fr_LPduIdx,
 FR_P2VAR_APPLDATA(uint8) Fr_LPduPtr,
 FR_P2VAR_APPLDATA(Fr_RxLPduStatusType) Fr_LPduStatusPtr,
 FR_P2VAR_APPLDATA(uint8) Fr_LPduLengthPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint8 lSduLength;
#if (FR_FIFO_SUPPORT == STD_ON)
  uint8_least fifoDepth = 1;
#endif

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check that input parameter 'Fr_LPduIdx' is less than or equal to the total number of Rx frame
   *     triggerings. */
  else if (Fr_LPduIdx >= Fr_VGetNumRxVirtBuf2PhysBufs(FR_VCTRL_IDX))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /* #40 If required, check the plausibility of output parameters 'Fr_LPduPtr', 'Fr_LPduStatusPtr' and 'Fr_LPduLengthPtr'. */
  else if (((Fr_LPduPtr == NULL_PTR) | (Fr_LPduStatusPtr == NULL_PTR) | (Fr_LPduLengthPtr == NULL_PTR)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Get the index to the associated physical message buffer. */
    uint8 physBufIdx = (Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;

    *Fr_LPduStatusPtr = FR_NOT_RECEIVED; /* SBSW_FR_WritePtr */
#if (FR_FIFO_SUPPORT == STD_ON)
    /* #70 If FR_FIFO_SUPPORT is enabled and the requested L-PDU lies within a FIFO range the following steps must be
     *    repeated until either:
     *      * a valid frame within the FIFO range was actually received (refer to #110).
     *      * no frame in the FIFO range was received (refer to #140).
     *     Otherwise the following steps are only processed for the requested L-PDU:*/
    if ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).cycleMask == FR_FIFO_MARK) /* fifo frame */
    {
      fifoDepth = ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).cycleBase);
    }

    for (;fifoDepth > 0; --fifoDepth)
    {
#endif
      /* #80 Check whether the following constraints hold true to determine whether the requested L-PDU was received
       *     or not: */

      /* #90 - The message buffer of the requested L-PDU contains new valid data. */
      if (Fr_VNewData(FR_VCTRL_IDX, physBufIdx) != (uint32)0u)
      {
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCM, (FR_OBCM_RHSS | FR_OBCM_RDSS)); /* SBSW_FR_WriteHwReg */
        (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
        Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCR, (FR_OBCR_REQ | (((uint32)physBufIdx) & FR_OBCR_OBRS_MASK))); /* SBSW_FR_WriteHwReg */
        (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
        Fr_VCCSetBits(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_VIEW); /* SBSW_FR_WriteHwReg */

        /* [FR604]  */ /* ESCAN00076357 */
        /* vSS!ValidFrame is implicitly tested by previous Fr_VNewData() check because NDAT flags are only set when */
        /* a valid received data frame matches the message buffer's filter configuration, independent of the pay-   */
        /* load length received or the payload length configured for that message buffer:                           */
#if (FR_RX_STRINGENT_CHECK == STD_ON)
        /* #100 - If FR_RX_STRINGENT_CHECK is enabled:
         *        There was no syntax error, content error or a boundary violation error reported in the Message Buffer
         *        Status register (MBS) for the requested Fr_LPduIdx. */
        /* ESCAN00085957 */
        if (((Fr_VCCReadValue(FR_VCTRL_IDX, FR_MBS) & (FR_MBS_SEOA | FR_MBS_CEOA | FR_MBS_SVOA)) != 0)
            || ((Fr_VCCReadValue(FR_VCTRL_IDX, FR_MBS) & (FR_MBS_SEOB | FR_MBS_CEOB | FR_MBS_SVOB)) != 0)
          ) /* COV_FR_HARDWARE_FAILURE */
        {
          /* Set Fr_LPduStatusPtr to FR_NOT_RECEIVED and Fr_LPduLengthPtr to 0 but the return value to E_OK if there was any error. */
          *Fr_LPduLengthPtr = 0; /* SBSW_FR_WritePtr */
          *Fr_LPduStatusPtr = FR_NOT_RECEIVED; /* SBSW_FR_WritePtr */
        }
        else
#endif
#if (FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
        /* #110 - If FR_RX_STRINGENT_LENGTH_CHECK is enabled:
         *        The configured payload length must be equal to the received one. */
        if (((Fr_VCCReadValue(FR_VCTRL_IDX, FR_RDHS2) & FR_RDHS2_PLC_MASK) >> FR_RDHS2_PLC_SHIFT) !=
          ((Fr_VCCReadValue(FR_VCTRL_IDX, FR_RDHS2) & FR_RDHS2_PLR_MASK) >> FR_RDHS2_PLR_SHIFT))
        {
          /* Do not accept this frame and set Fr_LPduStatusPtr to FR_NOT_RECEIVED whether their lengths are unequal. */
          *Fr_LPduStatusPtr = FR_NOT_RECEIVED; /* SBSW_FR_WritePtr */
        }
        else
#endif
        {
          /* #120 - The L-PDU lies either in a FIFO range or its cycle filtering matches. */
          if (
            (
#if (FR_FIFO_SUPPORT == STD_ON)
            ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).cycleMask == FR_FIFO_MARK) ||
#endif
            ((Fr_ReceiveCycleCount(FR_VCTRL_IDX) & (Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).cycleMask) ==
            ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).cycleBase
#if (FR_RECONFIGLPDUSUPPORT == STD_ON)
            & ((uint8)(~FR_RXVIRTBUF_CYCLEBASE_RECONFIG_LPDU))   /* PRQA S 0277 */ /* MD_Fr_0277 */
#endif
            ))))
          {
#if (FR_VENABLE_MID_FILTERING == STD_ON)
            /* #130 - If FR_VENABLE_MID_FILTERING is enabled:
             *        The message ID (first 2 bytes) of a received L-PDU in the dynamic segment with set payload preamble
             *        bit must be found in the message ID list of the driver. */
            if (Fr_VIsMsgId(FR_VCTRL_IDX) == TRUE)
#endif
            /* #140 If all these constraints hold true:
             *      Copy the received payload to the buffer Fr_LPduPtr points to and set Fr_LPduLengthPtr to the frame
             *      length of the received L-PDU (number of copied bytes).
             *      Note: reading the message buffer data clears the "new data flag". */
            {
              /* Get the received payload. */
              lSduLength = Fr_GetReceiveByteLength(FR_VCTRL_IDX);
              /**
               *
               *Internal comment removed. *
 *
 *
 *
               */
              /* PRQA S 0715 1 */ /* MD_MSR_1.1_715 */
              if (lSduLength > *Fr_LPduLengthPtr)
              {
                lSduLength = *Fr_LPduLengthPtr;
              }

              /* Copy the payload to the buffer Fr_LPduPtr points to. */
              (void)Fr_VReadDataFromCC(Fr_LPduPtr, (Fr_RegisterPtrType)(Fr_VCCRegAddr(FR_VCTRL_IDX, FR_RDDSn)), lSduLength);  /* PRQA S 0306 */ /* MD_Fr_0306 */ /* SBSW_FR_FctCallPtr2HwReg */
              /* Return the copied bytes of the frame in Fr_LPduLengthPtr. */
              *Fr_LPduLengthPtr = lSduLength; /* SBSW_FR_WritePtr */
#if (FR_FIFO_SUPPORT == STD_ON)
              /* #150 If FR_FIFO_SUPPORT is enabled and this was not the last FIFO entry set Fr_LPduStatusPtr to
               *      FR_RECEIVED_MORE_DATA_AVAILABLE (to tell the caller that more data is available and Fr_ReceiveRxLPdu
               *      should be called for this L-PDU again). */
              /* PRQA S 0715 1 */ /* MD_MSR_1.1_715 */
              if (fifoDepth > FR_LAST_FIFO_FRAME)
              {
                *Fr_LPduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE; /* SBSW_FR_WritePtr */
                break;
              }
              /* #160 Otherwise: Set Fr_LPduStatusPtr to FR_RECEIVED. */
              else
#endif
              {
                *Fr_LPduStatusPtr = FR_RECEIVED; /* SBSW_FR_WritePtr */
              }
            } 
          }
          /* #170 Otherwise: Set Fr_LPduLengthPtr to 0 and set Fr_LPduStatusPtr to FR_NOT_RECEIVED. */
        }
      } 
#if (FR_FIFO_SUPPORT == STD_ON)
      /* Point to the next physical message buffer. */
      physBufIdx++;
    } /* end of FIFO loop */
#endif
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_RECEIVE_RX_LPDU, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 3 */ /* MD_MSR_STMIF */
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 1 */ /* MD_MSR_STPTH */
} /* Fr_ReceiveRxLPdu() */

/**********************************************************************************************************************
 *  Fr_CheckTxLPduStatus()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 uint16 Fr_LPduIdx,
 FR_P2VAR_APPLDATA(Fr_TxLPduStatusType) Fr_TxLPduStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
#if (FR_BUFFER_RECONFIG == STD_ON)
  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;
#endif

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
# endif
  /* #30 If required, check that input parameter 'Fr_LPduIdx' is less than or equal to the total number of TX frame triggerings. */
  else if (Fr_LPduIdx >= Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /* #40 If required, check plausibility of output parameter 'Fr_TxLPduStatusPtr'. */
  else if (Fr_TxLPduStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Get the physical message buffer index for the requested Fr_LPduIdx. */
    uint8 cfgBufIdx = Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx).mbIdx;

#if (FR_BUFFER_RECONFIG == STD_ON)
    /* #70 If FR_BUFFER_RECONFIG is enabled and the requested message buffer is marked to be used for message buffer
     *     reconfiguration: */
    if (((Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx).Info) & FR_TXVIRTBUF_INFO_RECONFIG) == FR_TXVIRTBUF_INFO_RECONFIG)
    {
      /* #90 Request and get the Read Header Section 1 (RDHS1) of the current the message buffer configuration. */
      pBufCfg   = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx);
      cfgBufIdx = pBufCfg->IBCR;

      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCM, FR_OBCM_RHSS); /* SBSW_FR_WriteHwReg */
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCR, (FR_OBCR_REQ | (((uint32)cfgBufIdx) & FR_OBCR_OBRS_MASK))); /* SBSW_FR_WriteHwReg */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
      Fr_VCCSetBits(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_VIEW); /* SBSW_FR_WriteHwReg */

      /* #100 If the current the message buffer configuration is equal to the requested physical message buffer: */
      if (pBufCfg->WRHS1 == Fr_GetRDHS1(FR_VCTRL_IDX))
      {
        /* #110 Set Fr_TxLPduStatusPtr to FR_TRANSMITTED, if the Transmission Request flag (TXR) of corresponding message
         *      buffer is cleared and therewith the message buffer transmission not is pending anymore.
         *      If this is not the case set Fr_TxLPduStatusPtr to FR_NOT_TRANSMITTED. */
        *Fr_TxLPduStatusPtr = (Fr_TxLPduStatusType)((Fr_VCCNewReq(FR_VCTRL_IDX, cfgBufIdx) == 0UL) ? FR_TRANSMITTED : FR_NOT_TRANSMITTED); /* SBSW_FR_WritePtr */
        retVal = E_OK;
      }
      /* #120 Otherwise return E_NOT_OK because FrIf invalidly requested an Fr_LPduIdx which is not transmitted in this cycle.*/
      else
      {        
        /* The FrIf shall not try to repeat the FrIf_TxConfirmation. In case of buffer reconfiguration     */
        /* it could happen that FrIf retries the TxConf until the frame is transmitted again. But the      */
        /* frame might not be transmitted again.                                                           */
        *Fr_TxLPduStatusPtr = FR_NOT_TRANSMITTED; /* SBSW_FR_WritePtr */
        retVal = E_NOT_OK;
      }
    } /* Reconfig buffer */
    else
#endif /* (FR_BUFFER_RECONFIG == STD_ON) */
    /* #130 Otherwise set Fr_TxLPduStatusPtr to FR_TRANSMITTED, if the Transmission Request flag (TXR) of corresponding message
         *      buffer is cleared and therewith the message buffer transmission is not pending anymore.
         *      If this is not the case set Fr_TxLPduStatusPtr to FR_NOT_TRANSMITTED. */
    {
      *Fr_TxLPduStatusPtr = (Fr_TxLPduStatusType)((Fr_VCCNewReq(FR_VCTRL_IDX, cfgBufIdx) == 0UL) ? FR_TRANSMITTED : FR_NOT_TRANSMITTED); /* SBSW_FR_WritePtr */
      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_CHECK_TX_LPDU_STATUS, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_CheckTxLPduStatus() */ 

/**********************************************************************************************************************
 *  Fr_GetGlobalTime()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  FR_P2VAR_APPLDATA(uint8) Fr_CyclePtr,
  FR_P2VAR_APPLDATA(uint16) Fr_MacroTickPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 RegVal;
  uint32 pocState;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameters 'Fr_CyclePtr' and 'Fr_MacroTickPtr'. */
  else if (((Fr_CyclePtr == NULL_PTR) | (Fr_MacroTickPtr == NULL_PTR)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #50 Read value of Macrotick and Cycle Counter Value register (MTCCV). */
    RegVal =  Fr_VCCReadValue(FR_VCTRL_IDX, FR_MTCCV);

    /* #60 If the communication controller is either in POCstate NORMAL_ACTIVE or in NORMAL_PASSIVE: */
    pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);
    if (((pocState == CCPOCS_NORMAL_ACTIVE) | (pocState == CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
    {
      /* #80 Set Fr_MacroTickPtr according the read Macrotick Value flags (MTV) from the Macrotick and Cycle Counter
       *      Value register (MTCCV). */
      *Fr_MacroTickPtr = (uint16)((RegVal & FR_MTCCV_MTV_MASK) >> FR_MTCCV_MTV_SHIFT); /* SBSW_FR_WritePtr */

      /* #90 If the read Macrotick Value flag (MTV) was zero, re-read Macrotick and Cycle Counter Value register
       *      (MTCCV) due to ERAY Errata Sheet (REL20100723) No. 8. */
      if (*Fr_MacroTickPtr == 0)
      {
        RegVal =  Fr_VCCReadValue(FR_VCTRL_IDX, FR_MTCCV);
      }

      /* #100 Set Fr_CyclePtr according the read Cycle Counter Value flags (CCV) from the Macrotick and Cycle Counter
       *      Value register (MTCCV). */
      *Fr_CyclePtr = (uint8)((RegVal & FR_MTCCV_CCV_MASK) >> FR_MTCCV_CCV_SHIFT); /* SBSW_FR_WritePtr */

      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_GLOBAL_TIME, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_GetGlobalTime() */

/**********************************************************************************************************************
 *  Fr_GetNmVector()
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
#if (FR_NMVECTOR_ENABLE == STD_ON)  /* FR266 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  FR_P2VAR_APPLDATA(uint8) Fr_NmVectorPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 frCycle;
  uint32 pocState;
  uint32 tempNMVnValue[FR_VMAX_ARRAY_FOR_NMVECTOR];
  uint8_least  nmBytePos;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#  endif
  /* #30 If required, check plausibility of output parameter 'Fr_NmVectorPtr'. */
  else if (Fr_NmVectorPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Deviation of Autosar requirement [FR261]: Fr_GetNmVector do not check CC access */
    /* #50 Get the current POCstate of the communication controller because */
    pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);

    /* #60 If the communication controller is either in POCstate NORMAL_ACTIVE or in NORMAL_PASSIVE: [FR263] */
    if (((pocState == CCPOCS_NORMAL_ACTIVE) | (pocState == CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
    {
      /* #70 Get the current cycle counter value from the Macrotick and Cycle Counter Value register (MTCCV) before
       *      reading the NM Vector [FR265]. */
      frCycle = Fr_VCCReadBits(FR_VCTRL_IDX, FR_MTCCV, FR_MTCCV_CCV_MASK);

      /* #80 Get the first 4 bytes of the NM Vector from the Network Management Vector 1 register (NMV1). */
      tempNMVnValue[0] = Fr_VCCReadValue(FR_VCTRL_IDX, FR_NMV1); /* SBSW_FR_WriteArrayLocal */

      /* #90 If NM vector is longer than 4 bytes, read the next 4 bytes of the NM Vector from Network Management
       *      Vector 2 register (NMV2). */
      if (Fr_GetNMVectorLength(FR_VCTRL_IDX) > (uint32)FR_VNMV1_BYTECOUNT) /* PRQA S 3201, 3792, 3325 1 */ /* MD_MSR_14.1 */
      {
        tempNMVnValue[1] = Fr_VCCReadValue(FR_VCTRL_IDX, FR_NMV2); /* SBSW_FR_WriteArrayLocal */
      }

      /* #100 If NM vector is longer than 8 bytes, read the last 4 bytes of the NM Vector from Network Management
       *      Vector 3 register (NMV3). */
      if (Fr_GetNMVectorLength(FR_VCTRL_IDX) > (uint32)FR_VNMV2_BYTECOUNT) /* PRQA S 3201, 3792, 3325 1 */ /* MD_MSR_14.1 */
      {
        tempNMVnValue[2] = Fr_VCCReadValue(FR_VCTRL_IDX, FR_NMV3); /* SBSW_FR_WriteArrayLocal */
      }

      /* #130 Iterate over received all NM Vector bytes and copy them to Fr_NmVectorPtr in the same byte order as it
       *      was received on the bus. [FR264] */
      for (nmBytePos = 0; nmBytePos < Fr_GetNMVectorLength(FR_VCTRL_IDX); nmBytePos++)  /* PRQA S 3356, 3359 3 */ /* MD_Fr_13.7 */
      {
        /* Little Endian */
        Fr_NmVectorPtr[nmBytePos] = (uint8)(tempNMVnValue[nmBytePos >> 2] >> ((nmBytePos & FR_MASK_NMBYTEPOS) << 3)); /* SBSW_FR_WriteArrayNmVector */
      }

      /* #140 Get the current cycle counter value again from the Macrotick and Cycle Counter Value register (MTCCV)
       *      and compare it with the previous MTCCV value to ensure that it is still the same cycle [FR265].
       *      If this is the case return E_OK, othewise return E_NOT_OK. */
      if (frCycle == Fr_VCCReadBits(FR_VCTRL_IDX, FR_MTCCV, FR_MTCCV_CCV_MASK))
      {
        retVal = E_OK;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_NM_VECTOR, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_GetNmVector() */
#endif /* FR_NMVECTOR_ENABLE */

#if (FR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Fr_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FR_CODE) Fr_GetVersionInfo
(
  FR_P2VAR_APPLDATA(Std_VersionInfoType) Fr_VersionInfoPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FR_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check plausibility of all input parameters. */
  if (Fr_VersionInfoPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #20 If the initial checks are passed or not required: */
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #30 Fill the version information struct using the macros from the component header. */
    Fr_VersionInfoPtr->vendorID = FR_VENDOR_ID; /* SBSW_FR_WriteStructMember */
    Fr_VersionInfoPtr->moduleID = FR_MODULE_ID; /* SBSW_FR_WriteStructMember */
    
    Fr_VersionInfoPtr->sw_major_version = (uint8)FR_SW_MAJOR_VERSION; /* SBSW_FR_WriteStructMember */
    Fr_VersionInfoPtr->sw_minor_version = (uint8)FR_SW_MINOR_VERSION; /* SBSW_FR_WriteStructMember */
    Fr_VersionInfoPtr->sw_patch_version = (uint8)FR_SW_PATCH_VERSION; /* SBSW_FR_WriteStructMember */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_VERSION_INFO, errorId);
  }
#  else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
} /* Fr_GetVersionInfo() */
#endif /* FR_VERSION_INFO_API */

/**********************************************************************************************************************
 *  Fr_InitMemory()
 **********************************************************************************************************************/
/*! 
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FR_CODE) Fr_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If FR_DEV_ERROR_DETECT is enabled, flag the FR as uninitialized.*/
  Fr_VFrDrvState = FR_VUNINITPTR;
#endif
} /* Fr_InitMemory() */

#if (FR_GET_CLOCK_CORRECTION_EXT == STD_ON)
/**********************************************************************************************************************
 *  Fr_GetClockCorrection()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 FR_P2VAR_APPLDATA(sint16) Fr_RateCorrectionPtr,
 FR_P2VAR_APPLDATA(sint32) Fr_OffsetCorrectionPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameter 'Fr_RateCorrectionPtr'. */
  else if (Fr_RateCorrectionPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If required, check plausibility of output parameter 'Fr_OffsetCorrectionPtr'. */
  else if (Fr_OffsetCorrectionPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Get Rate and Offset Correction values from the Rate Correction Value register (RCV) and Offset Correction Value register (OCV). */
    *Fr_RateCorrectionPtr = (sint16)Fr_VCCReadBits(FR_VCTRL_IDX, FR_RCV, FR_RCV_MASK); /* SBSW_FR_WritePtr */
    *Fr_OffsetCorrectionPtr = (sint32)Fr_VCCReadValue(FR_VCTRL_IDX, FR_OCV); /* SBSW_FR_WritePtr */

    /* #70 Convert Rate Correction to a sint16 value because both this is stored in two's complement and write to Fr_RateCorrectionPtr. */
    if (((uint16)*Fr_RateCorrectionPtr & FR_SIGNEDBIT_RCV) == FR_SIGNEDBIT_RCV)
    {
      *Fr_RateCorrectionPtr =  (sint16)((uint16)*Fr_RateCorrectionPtr | FR_FILLSIGNED_RCV); /* SBSW_FR_WritePtr */
    }

# if defined (FR_TRICORE_AURIX) /* COV_FR_EQUIVALENT_HARDWARE */
    {/* ESCAN00073879 */
      sint8 pClusterDriftDamping = Fr_VCCReadBits(FR_VCTRL_IDX, FR_GTUC5, FR_GTUC5_CDD_MASK) >> FR_GTUC5_CDD_SHIFT; 

      if ((*Fr_RateCorrectionPtr >= (-pClusterDriftDamping)) && (*Fr_RateCorrectionPtr <= pClusterDriftDamping))
      {
        *Fr_RateCorrectionPtr = (sint16)0; /* SBSW_FR_WritePtr */
      }
    }
# endif

    /* #80 Convert Offset Correction to a sint32 value because this value is also stored in two's complemented and write to Fr_OffsetCorrectionPtr. */
    if (((uint32)*Fr_OffsetCorrectionPtr & FR_SIGNEDBIT_OCV) == FR_SIGNEDBIT_OCV)
    {
      *Fr_OffsetCorrectionPtr = (sint32)((uint32)*Fr_OffsetCorrectionPtr | FR_FILLSIGNED_OCV); /* SBSW_FR_WritePtr */
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_CLOCK_CORRECTION, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_GetClockCorrection() */
#endif /* FR_GET_CLOCK_CORRECTION_EXT */

#if (FR_VCHANNEL_STATUS_EXT == STD_ON)
/**********************************************************************************************************************
 *  Fr_GetChannelStatus()
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
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelAStatusPtr,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelBStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32         pocState;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameter 'Fr_ChannelAStatusPtr'. */
  else if (Fr_ChannelAStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If required, check plausibility of output parameter 'Fr_ChannelBStatusPtr'. */
  else if (Fr_ChannelBStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 If the communication controller is either in POCstate NORMAL_ACTIVE or in NORMAL_PASSIVE: */
    pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);
    if (((pocState == CCPOCS_NORMAL_ACTIVE) | (pocState == CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
    {
      /* #70 Read Aggregated Channel Status register (ACS) and reset it. */
      uint16 RegVal = (uint16)Fr_VCCReadValue(FR_VCTRL_IDX, FR_ACS);
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_ACS, (uint32)RegVal); /* SBSW_FR_WriteHwReg */

      *Fr_ChannelAStatusPtr  = (RegVal >> FR_FR_ACS_VFRA_SHIFT) & FR_GETCHANNELSTATUS_ACS_MASK; /* SBSW_FR_WritePtr */
      *Fr_ChannelBStatusPtr  = (RegVal >> FR_FR_ACS_VFRB_SHIFT) & FR_GETCHANNELSTATUS_ACS_MASK; /* SBSW_FR_WritePtr */

      /* #80 Read Symbol Window and NIT Status register (SWNIT) without resetting it. */
      RegVal = (uint16)Fr_VCCReadValue(FR_VCTRL_IDX, FR_SWNIT);

      /* #90 Set the value of Fr_ChannelAStatusPtr/Fr_ChannelBStatusPtr according the read register values, whereas the
       *     channel status is bit-coded with the following meaning (Bit 0 = LSB, Bit 15 = MSB):
       *       Bit 0: Channel A/B aggregated channel status vSS!ValidFrame
       *       Bit 1: Channel A/B aggregated channel status vSS!SyntaxError
       *       Bit 2: Channel A/B aggregated channel status vSS!ContentError
       *       Bit 3: Channel A/B aggregated channel status additional
       *       Bit 4: Channel A/B aggregated channel status vSS!Bviolation
       *       Bit 5: Channel A/B aggregated channel status vSS!TxConflict is not supported by FlexRay 2.1 Hardware.
       *       Bit 8: Channel A/B symbol window status data vSS!ValidMTS
       *       Bit 9: Channel A/B symbol window status data vSS!SyntaxError
       *       Bit 10: Channel A/B symbol window status data vSS!Bviolation
       *       Bit 11: Channel A/B symbol window status data vSS!TxConflict
       *       Bit 12: Channel A/B NIT status data vSS!SyntaxError
       *       Bit 13: Channel A/B NIT status data vSS!Bviolation */
      *Fr_ChannelAStatusPtr |= (uint16)((RegVal & FR_SWNIT_MTSA_SFS) << (FR_GETCHANNELSTATUS_MTS_SHIFT - FR_SWNIT_MTSA_SFS_SHIFT)); /* SBSW_FR_WritePtr */
      *Fr_ChannelBStatusPtr |= (uint16)((RegVal & FR_SWNIT_MTSB_SFS) << (FR_GETCHANNELSTATUS_MTS_SHIFT - FR_SWNIT_MTSB_SFS_SHIFT)); /* SBSW_FR_WritePtr */

      *Fr_ChannelAStatusPtr |= (uint16)((RegVal & (FR_SWNIT_SESA + FR_SWNIT_SBSA + FR_SWNIT_TCSA)) << (FR_GETCHANNELSTATUS_SWS_SHIFT - FR_SWNIT_WIN_A_SHIFT)); /* SBSW_FR_WritePtr */
      *Fr_ChannelBStatusPtr |= (uint16)((RegVal & (FR_SWNIT_SESB + FR_SWNIT_SBSB + FR_SWNIT_TCSB)) << (FR_GETCHANNELSTATUS_SWS_SHIFT - FR_SWNIT_WIN_B_SHIFT)); /* SBSW_FR_WritePtr */

      *Fr_ChannelAStatusPtr |= (uint16)((RegVal & (FR_SWNIT_SENA + FR_SWNIT_SBNA)) << (FR_GETCHANNELSTATUS_NIT_SHIFT - FR_SWNIT_SENA_SHIFT)); /* SBSW_FR_WritePtr */
      *Fr_ChannelBStatusPtr |= (uint16)((RegVal & (FR_SWNIT_SENB + FR_SWNIT_SBNB)) << (FR_GETCHANNELSTATUS_NIT_SHIFT - FR_SWNIT_SENB_SHIFT)); /* SBSW_FR_WritePtr */

      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_CHANNEL_STATUS, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_GetChannelStatus() */
#endif /* (FR_VCHANNEL_STATUS_EXT == STD_ON) */

#if (FR_GETSYNCFRAMELIST_API == STD_ON)
/**********************************************************************************************************************
 *  Fr_GetSyncFrameList()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  uint8 Fr_ListSize,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelAEvenListPtr,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelBEvenListPtr,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelAOddListPtr,
  FR_P2VAR_APPLDATA(uint16) Fr_ChannelBOddListPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint8_least  n;
  uint32 RegVal;
  uint8_least ChannelAEvenListCount = 0;
  uint8_least ChannelBEvenListCount = 0;
  uint8_least ChannelAOddListCount  = 0;
  uint8_least ChannelBOddListCount  = 0;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState == FR_VUNINITPTR)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameters 'Fr_ChannelAEvenListPtr' and 'Fr_ChannelBEvenListPtr'. */
  else if (((Fr_ChannelAEvenListPtr == NULL_PTR) | (Fr_ChannelBEvenListPtr == NULL_PTR)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If required, check plausibility of output parameters 'Fr_ChannelAOddListPtr' and 'Fr_ChannelBOddListPtr'. */
  else if (((Fr_ChannelAOddListPtr == NULL_PTR) | (Fr_ChannelBOddListPtr == NULL_PTR)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Limit Fr_ListSize to 15 (FR_SYNC_FRAME_LIST_MAX). */
    if (Fr_ListSize > FR_SYNC_FRAME_LIST_MAX)
    {
      errorId = FR_E_INV_LISTSIZE;
      Fr_ListSize = FR_SYNC_FRAME_LIST_MAX;
    }

    /* #70 Initialize all entries of the even and odd arrays with 0. */
    for (n = 0; n < Fr_ListSize; n++)
    {
      Fr_ChannelAEvenListPtr[n] = 0; /* SBSW_FR_WriteArray */
      Fr_ChannelBEvenListPtr[n] = 0; /* SBSW_FR_WriteArray */
      Fr_ChannelAOddListPtr[n] = 0;  /* SBSW_FR_WriteArray */
      Fr_ChannelBOddListPtr[n] = 0;  /* SBSW_FR_WriteArray */
    }

    /* #80 Iterate over the 15 Even and Odd Sync ID registers that hold the sync frame IDs of the even and odd cycles. */
    for (n = 0; n < FR_ESIDn_NUMBER; n++)
    {
      RegVal = Fr_VCCReadValue(FR_VCTRL_IDX, (FR_ESIDn + (n << 2)));

      /* #90 Only save the current frame ID to the Fr_ChannelAEvenListPtr list if indeed a sync frame of an even cycle
       *      on channel A has been received and increment ChannelAEvenListCount. */
      if (((RegVal & FR_ESIDn_RXEA) != 0) && (ChannelAEvenListCount < Fr_ListSize))
      {
        Fr_ChannelAEvenListPtr[ChannelAEvenListCount] = (uint16)(RegVal & FR_ESIDn_EID_MASK); /* SBSW_FR_WriteArray */
        ++ChannelAEvenListCount;
      }

      /* #100 Only save the current frame ID to the Fr_ChannelBEvenListPtr list if indeed a sync frame of an even cycle
       *      on channel B has been received and increment ChannelBEvenListCount. */
      if (((RegVal & FR_ESIDn_RXEB) != 0) && (ChannelBEvenListCount < Fr_ListSize))
      {
        Fr_ChannelBEvenListPtr[ChannelBEvenListCount] = (uint16)(RegVal & FR_ESIDn_EID_MASK); /* SBSW_FR_WriteArray */
        ++ChannelBEvenListCount;
      }

      RegVal = Fr_VCCReadValue(FR_VCTRL_IDX, (FR_OSIDn + (n << 2)));

      /* #110 Only save the current frame ID to the Fr_ChannelAOddListPtr list if indeed a sync frame of an odd cycle
       *      on channel A has been received and increment ChannelAOddListCount. */
      if (((RegVal & FR_OSIDn_RXOA) != 0) && (ChannelAOddListCount < Fr_ListSize))
      {
        Fr_ChannelAOddListPtr[ChannelAOddListCount] = (uint16)(RegVal & FR_OSIDn_OID_MASK); /* SBSW_FR_WriteArray */
        ++ChannelAOddListCount;
      }

      /* #120 Only save the current frame ID to the Fr_ChannelBOddListPtr list if indeed a sync frame of an odd cycle
       *      on channel B has been received and increment ChannelBOddListCount. */
      if (((RegVal & FR_OSIDn_RXOB) != 0) && (ChannelBOddListCount < Fr_ListSize))
      {
        Fr_ChannelBOddListPtr[ChannelBOddListCount] = (uint16)(RegVal & FR_OSIDn_OID_MASK); /* SBSW_FR_WriteArray */
        ++ChannelBOddListCount;
      }

      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GET_SYNC_FRAME_LIST, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */
  /* PRQA S 6060 3 */ /* MD_MSR_STPAR */ 
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */ 
  /* PRQA S 6030 1 */ /* MD_MSR_STCYC */ 
} /* Fr_GetSyncFrameList() */ 
#endif /* ( FR_GETSYNCFRAMELIST_API == STD_ON ) */

#if (FR_DISABLELPDUSUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Fr_DisableLPdu()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint8 cfgBufIdx;
  boolean reconfigurable = TRUE;
  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;
  
  /**
   *
   * Internal comment removed.
 *
 * 
   */

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#  endif
  /* #30 If required, check that input parameter 'Fr_LPduIdx' is less than or equal to the total number of TX and RX
   *     frame triggerings. */
  else if (Fr_LPduIdx >= (Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX) + Fr_VGetNumRxVirtBuf2PhysBufs(FR_VCTRL_IDX)))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #50 Determine the physical buffer index depending on whether the Fr_LPduIdx is a virtual buffer index for a TX
     *     or a RX frame triggering.
     *     In case the Fr_LPduIdx was less than the number of TX frame triggerings it is a TX frame triggering.
     *     Otherwise it is a RX frame triggering. */
    if (Fr_LPduIdx < Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX))
    {   /* TX */
      cfgBufIdx = (Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;

      if ((Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx).Info & FR_TXVIRTBUF_INFO_RECONFIG_LPDU) == 0)
      {
        reconfigurable = FALSE;
      }
    }
    else
    { /* RX */
      /* Subtract the number of TX frame triggerings because the indexes of Rx frame triggerings are zero based. */
      Fr_LPduIdx -= (uint16)Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX);
      cfgBufIdx = (Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;

      if ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx).cycleBase & FR_RXVIRTBUF_CYCLEBASE_RECONFIG_LPDU) == 0)
      {
        reconfigurable = FALSE;
      }
    }

    /* #60 If the requested physical message buffer is marked as reconfigurable: */
    if (reconfigurable == TRUE)
    {
      /* #70 Enter Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #80 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
       *      to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

      /**
       *
       * Internal comment removed.
 *
 *
 *
 *
 *
 *
       */
      /* #90 Disable the physical message buffer which is associated by the given Fr_LPduIdx by clearing the Channel
       *      Filter Control flags (CHA, CHB) in the Write Header Section 1 register (WRHS1). */
      pBufCfg = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx);
      Fr_WriteWRHS1(FR_VCTRL_IDX, (pBufCfg->WRHS1)& 0x3C7F07FFu); /* SBSW_FR_WriteHwReg */
      Fr_WriteWRHS2(FR_VCTRL_IDX, pBufCfg->WRHS2); /* SBSW_FR_WriteHwReg */
      Fr_WriteWRHS3(FR_VCTRL_IDX, pBufCfg->WRHS3); /* SBSW_FR_WriteHwReg */

      /* #100 Select the target message buffer and trigger the transfer to the Message RAM. */
      Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, FR_IBCM_LHSH); /* SBSW_FR_WriteHwReg */
      Fr_VCCWriteValueIBCR(FR_VCTRL_IDX, cfgBufIdx); /* SBSW_FR_WriteHwReg */

      /* #110 Leave Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MD_MSR_14.3 */

      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_DISABLE_LPDU, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_DisableLPdu() */
#endif

#if (FR_RECONFIGLPDUSUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Fr_ReconfigLPdu()
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
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu
(
   FR_VCTRL_SYSTEMTYPE_ONLY,
   uint16 Fr_LPduIdx,
   uint16 Fr_FrameId,
   Fr_ChannelType Fr_ChnlIdx,
   uint8 Fr_CycleRepetition,
   uint8 Fr_CycleOffset,
   uint8 Fr_PayloadLength,
   uint16 Fr_HeaderCRC
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 dlcWord;
  uint8 cfgBufIdx;
  boolean reconfigurable = TRUE;

  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* #10 Determine the physical buffer index depending on whether the Fr_LPduIdx is a virtual buffer index for a TX or
   *     a RX frame triggering. In case the Fr_LPduIdx was less than the number of TX frame triggerings it is a TX
   *     frame triggering. Otherwise it is a RX frame triggering. */
  if (Fr_LPduIdx < Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX))
  {   /* TX */
    cfgBufIdx = (Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;

    if ((Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx).Info & FR_TXVIRTBUF_INFO_RECONFIG_LPDU) == 0)
    {
      reconfigurable = FALSE;
    }
  }
  else
  { /* RX */
    uint16 tmpLPduIdx;

    tmpLPduIdx = Fr_LPduIdx - (uint16)Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX);
    cfgBufIdx = (Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, tmpLPduIdx)).mbIdx;

    if ((Fr_GetRxVirtBuf2Phys(FR_VCTRL_IDX, tmpLPduIdx).cycleBase & FR_RXVIRTBUF_CYCLEBASE_RECONFIG_LPDU) == 0)
    {
      reconfigurable = FALSE;
    }
  }

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #20 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #30 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#  endif
  /* #40 If required, check that input parameter 'Fr_ChnlIdx' is either FR_CHANNEL_A, FR_CHANNEL_B or FR_CHANNEL_AB. */
  else if ((Fr_ChnlIdx > FR_CHANNEL_AB))
  {
    errorId = FR_E_INV_CHNL_IDX;
  }
  /* #50 If required, check that input parameter 'Fr_LPduIdx' is less than or equal to the total number of TX and RX
   *     frame triggerings. */
  else if (Fr_LPduIdx >= (Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX) + Fr_VGetNumRxVirtBuf2PhysBufs(FR_VCTRL_IDX)))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /**
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
   */
  /* #60 If required, check that input parameter 'Fr_PayloadLength' is less than or equal to the length configured
   *     for the physical message buffer. */
  else if (Fr_PayloadLength > ((Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx)->WRHS2) >> FR_WRHS2_PLC_BYTE_SHIFT))
  {
    errorId = FR_E_INV_LENGTH;
  }
  /* #70 If required, check that input parameter 'Fr_CycleRepetition' has a valid value. */
  /* According to AR 4.0.3 there are more valid values for Fr_CycleRepetition, but they are only relevant for FlexRay
   * 3.0 Hardware.
   */
  else if (Fr_VBitCnt(Fr_CycleRepetition) != 1)
  {
    errorId = FR_E_INV_CYCLE;
  }
  /* #80 If required, check that input parameter 'Fr_CycleOffset' (BaseCycle) is always less than Fr_CycleRepetition. */
  else if (Fr_CycleOffset >= Fr_CycleRepetition)
  {
    errorId = FR_E_INV_CYCLE;
  }
  /* #90 If required, check that input parameter 'Fr_HeaderCRC' value is between 0 and 2047 (0x7FF). */
  else if (Fr_HeaderCRC > FR_HEADER_CRC_MAX)
  {
    errorId = FR_E_INV_HEADERCRC;
  }
  /* #100 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #110 If the requested physical message buffer is marked as reconfigurable: */
    if (reconfigurable == TRUE)
    {
      pBufCfg = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx);
# if (FR_BUFFER_RECONFIG == STD_ON)
      cfgBufIdx = pBufCfg->IBCR;
# endif

      /* #120 Enter Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #130 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared
       *      to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

      /* #140 Fill the Write Header Section 1/2/3 registers (WRHS1,WRHS2,WRHS3) with the given parameter values. */
      Fr_WriteWRHS1(FR_VCTRL_IDX, (pBufCfg->WRHS1 & FR_RECONFIG_LPDU_WRHS1_MASK) /* SBSW_FR_WriteHwReg */
        + Fr_FrameId
        + ((uint32)(Fr_ChnlIdx + 1) << FR_WRHS1_CHA_SHIFT)
        + ((uint32)(Fr_CycleRepetition | Fr_CycleOffset) << FR_WRHS1_CYC_SHIFT)
        );
      dlcWord = (uint32)(((uint32)Fr_PayloadLength + 1) >> 1);
      Fr_WriteWRHS2(FR_VCTRL_IDX, (dlcWord << FR_WRHS2_PLC_SHIFT) + Fr_HeaderCRC); /* SBSW_FR_WriteHwReg */
      Fr_WriteWRHS3(FR_VCTRL_IDX, pBufCfg->WRHS3); /* SBSW_FR_WriteHwReg */

      /* #150 Select the target message buffer and trigger the transfer to the Message RAM to finalize the message buffer
       *      reconfiguration. */
      Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, FR_IBCM_LHSH); /* SBSW_FR_WriteHwReg */
      Fr_VCCWriteValueIBCR(FR_VCTRL_IDX, cfgBufIdx); /* SBSW_FR_WriteHwReg */

      /* #160 Leave Fr_FR_EXCLUSIVE_AREA_0 */
      FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MD_MSR_14.3 */

      retVal = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_RECONFIG_LPDU, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 3 */ /* MD_MSR_STMIF */
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6060 1 */ /* MD_MSR_STPAR */
} /* Fr_ReconfigLPdu() */ 
#endif /* (FR_RECONFIGLPDUSUPPORT == STD_ON) */

#if (FR_READ_CC_CONFIGURATION == STD_ON)
/**********************************************************************************************************************
 *  Fr_ReadCCConfig()
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
FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  uint8 Fr_ConfigParamIdx,
  FR_P2VAR_APPLDATA(uint32) Fr_ConfigParamValuePtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
# if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameter 'Fr_ConfigParamValuePtr'. */
  else if (Fr_ConfigParamValuePtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If required, check that input parameter 'Fr_ConfigParamIdx' is less than or equal to the total number of all
   *     config parameters. */
  else if (Fr_ConfigParamIdx >= (uint8)(FR_CC_CONFIG_PARAM_MAX8BIT + FR_CC_CONFIG_PARAM_MAX16BIT + FR_CC_CONFIG_PARAM_MAX32BIT))
  {
    errorId = FR_E_INV_CONFIG_IDX;
  }
  /* #50 If the initial checks are passed or not required: */
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #60 Return the corresponding parameter via Fr_ConfigParamValuePtr for the given Fr_ConfigParamIdx. */
    if (Fr_ConfigParamIdx < FR_CC_CONFIG_PARAM_MAX32BIT)
    {
      *Fr_ConfigParamValuePtr = Fr_GetVCCConfigParam32Bit(FR_VCTRL_IDX, Fr_ConfigParamIdx); /* SBSW_FR_WritePtr */
    }
    else
    {
      if (Fr_ConfigParamIdx < (FR_CC_CONFIG_PARAM_MAX32BIT + FR_CC_CONFIG_PARAM_MAX16BIT))
      {
        *Fr_ConfigParamValuePtr = Fr_GetVCCConfigParam16Bit(FR_VCTRL_IDX, Fr_ConfigParamIdx - FR_CC_CONFIG_PARAM_MAX32BIT); /* SBSW_FR_WritePtr */
      }
      else
      {
        *Fr_ConfigParamValuePtr = Fr_GetVCCConfigParam8Bit(FR_VCTRL_IDX, Fr_ConfigParamIdx - (FR_CC_CONFIG_PARAM_MAX16BIT + FR_CC_CONFIG_PARAM_MAX32BIT)); /* SBSW_FR_WritePtr */
      }
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_READCCCONFIG, errorId);
  }
# else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_ReadCCConfig() */
#endif /* FR_READ_CC_CONFIGURATION == STD_ON */

/**********************************************************************************************************************
 *  Fr_GetNumOfStartupFrames()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 FR_P2VAR_APPLDATA(uint8) Fr_NumOfStartupFramesPtr
)
{ 
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 pocState;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 Get the current POCstate of the communication controller.*/
  pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);

  /* #20 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #30 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #40 If required, check plausibility of output parameter 'Fr_NumOfStartupFramesPtr'. */
  else if (Fr_NumOfStartupFramesPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #50 If the current POCstate is NORMAL_ACTIVE or NORMAL_PASSIVE: */
  else if (((pocState != CCPOCS_NORMAL_ACTIVE) & (pocState != CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #60 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #70 Set Fr_NumOfStartupFramesPtr to 2 startup frames (always the same for FlexRay 2.1 Rev A hardware). */
    *Fr_NumOfStartupFramesPtr = 0x02; /* SBSW_FR_WritePtr */
    retVal = E_OK;
    /* #80 Otherwise: return E_NOT_OK and leave Fr_NumOfStartupFramesPtr unchanged. */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GETNUMOFSTARTUPFRAMES, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_GetNumOfStartupFrames() */

/**********************************************************************************************************************
 *  Fr_GetWakeupRxStatus()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  FR_P2VAR_APPLDATA(uint8) Fr_WakeupRxStatusPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
  uint32 tmpVal32;

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check plausibility of output parameter 'Fr_WakeupRxStatusPtr'. */
  else if (Fr_WakeupRxStatusPtr == NULL_PTR)
  {
    errorId = FR_E_INV_POINTER;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    
    /* #50 Reset the status value. */
    *Fr_WakeupRxStatusPtr = 0; /* SBSW_FR_WritePtr */

    /* #60 Get the value of the Status Interrupt Register (SIR). */
    tmpVal32 = Fr_VCCReadValue(FR_VCTRL_IDX, FR_SIR);

    /* #70 Set Fr_WakeupRxStatusPtr value depending on whether Wakeup Pattern Channel A (WUPA) or Wakeup Pattern Channel B
     *     (WUPB) flags were set in the Status Interrupt Register (SIR):
     *     The value of *Fr_WakeupRxStatusPtr is bit-coded with the following meaning (Bit 0 = LSB, Bit 7 = MSB):
     *        Bit 0:   Wakeup pattern received on channel A (1), otherwise (0)
     *        Bit 1:   Wakeup pattern received on channel B (1), otherwise (0)
     *        Bit 2-7: Unused */
    if ((tmpVal32 & FR_SIR_WUPA) == FR_SIR_WUPA)
    {
      *Fr_WakeupRxStatusPtr |= FR_WAKEUPRX_ON_CHANNEL_A; /* SBSW_FR_WritePtr */
    }
    if ((tmpVal32 & FR_SIR_WUPB) == FR_SIR_WUPB)
    {
      *Fr_WakeupRxStatusPtr |= FR_WAKEUPRX_ON_CHANNEL_B; /* SBSW_FR_WritePtr */
    }

    /* #80 Clear both Wakeup Pattern Channel A (WUPA) and Wakeup Pattern Channel B (WUPB) flags in the Status Interrupt
     *     Register (SIR). */
    Fr_VCCWriteValue(FR_VCTRL_IDX, FR_SIR,  FR_SIR_WUPA | FR_SIR_WUPB); /* SBSW_FR_WriteHwReg */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_GETWAKEUPRXSTATUS, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_GetWakeupRxStatus() */ 

/**********************************************************************************************************************
 *  Fr_CancelTxLPdu()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  uint16 Fr_LPduIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
#if (FR_BUFFER_RECONFIG == STD_ON)
  FR_P2CONST_CFG(Fr_VCcBufType) pBufCfg;
#endif

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
/* #30 If required, check that input parameter Fr_LPduIdx is less than or equal to the total number of TX and RX frame
 *     triggerings. */
  else if (Fr_LPduIdx >= Fr_VGetNumTxVirtBuf2PhysBufs(FR_VCTRL_IDX))
  {
    errorId = FR_E_INV_LPDU_IDX;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #50 Get the physical message buffer index for the requested Fr_LpduIdx. */
    uint8 cfgBufIdx = (Fr_GetTxVirtBuf2Phys(FR_VCTRL_IDX, Fr_LPduIdx)).mbIdx;
#if (FR_BUFFER_RECONFIG == STD_ON)
    pBufCfg   = Fr_VGetCcBufCfgAt(FR_VCTRL_IDX, cfgBufIdx);
    cfgBufIdx = pBufCfg->IBCR;
#endif
    /* #60 Wait until Input Buffer Busy Host flag (IBSYH) of Input Buffer Command Request register (IBCR) is cleared,
     *     to ensure that no transfer between IBF shadow buffer and message RAM is pending. */
    (void)Fr_VSetReg(FR_VCTRL_IDX, FR_IBCR, FR_IBCR_IBSYH, EQUAL);

    /* #70 Enter Fr_FR_EXCLUSIVE_AREA_0 */
    FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #71 If the Transmission Request flag (TXR) of corresponding message buffer is set and therewith a transmission
     *     request is pending: */
    if (Fr_VCCNewReq(FR_VCTRL_IDX, cfgBufIdx) != 0UL) /* FR611 */
    {
#if (FR_BUFFER_RECONFIG == STD_ON)
      /* #80 If FR_BUFFER_RECONFIG is enabled:
       *     Read the header section (RDHS1) of the current physical message buffer configuration. */
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCM, FR_OBCM_RHSS); /* SBSW_FR_WriteHwReg */
      Fr_VCCWriteValue(FR_VCTRL_IDX, FR_OBCR, (FR_OBCR_REQ | (((uint32)cfgBufIdx) & FR_OBCR_OBRS_MASK))); /* SBSW_FR_WriteHwReg */
      (void)Fr_VSetReg(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_OBSYS, EQUAL);
      Fr_VCCSetBits(FR_VCTRL_IDX, FR_OBCR, FR_OBCR_VIEW); /* SBSW_FR_WriteHwReg */

      /* #90 If FR_BUFFER_RECONFIG is enabled AND the read header section (RDHS1) of the physical message buffer configuration
       *     is equal to the requested one OR FR_BUFFER_RECONFIG is disabled: */
      if (pBufCfg->WRHS1 == Fr_VCCReadValue(FR_VCTRL_IDX, FR_RDHS1))
#endif
      {
        /* #100 Clear Input Buffer Command Mask Register (IBCM) to clear the TXR flag for the corresponding message buffer. */
        Fr_VCCWriteValueIBCM(FR_VCTRL_IDX, 0); /* SBSW_FR_WriteHwReg */
        Fr_VCCWriteValueIBCR(FR_VCTRL_IDX, cfgBufIdx); /* SBSW_FR_WriteHwReg */
        retVal = E_OK;
      }
    }

    /* #110 Leave Fr_FR_EXCLUSIVE_AREA_0 */
    FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_CANCELTXLPDU, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Fr_CancelTxLPdu() */

/**********************************************************************************************************************
 *  Fr_AllSlots()
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
 */
FUNC(Std_ReturnType, FR_CODE) Fr_AllSlots
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FR_E_NO_ERROR;
#if (FR_DEV_ERROR_DETECT == STD_ON)
  uint32 pocState = Fr_VCCGetPocState(FR_VCTRL_IDX);
#endif

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Development Error Checks ------------------------------------- */
#if (FR_DEV_ERROR_DETECT == STD_ON)
  /* #10 If required, check initialization state of the component. */
  if (Fr_VFrDrvState != FR_VINIT)
  {
    errorId = FR_E_NOT_INITIALIZED;
  }
#if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF)
  /* #20 If required, check plausibility of input parameter 'Fr_CtrlIdx'. */
  else if (FR_VCTRL_IDX >= FR_NUM_CTRL_SUPPORTED)
  {
    errorId = FR_E_INV_CTRL_IDX;
  }
#endif
  /* #30 If required, check if controller is not in POCstates NORMAL_ACTIVE or NORMAL_PASSIVE. */
  else if (((pocState != CCPOCS_NORMAL_ACTIVE) & (pocState != CCPOCS_NORMAL_PASSIVE)) != FALSE) /* PRQA S 4101, 4102, 4105 */ /* MD_Fr_4102 */
  {
    errorId = FR_E_INV_POCSTATE;
  }
  /* #40 If the initial checks are passed or not required: */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #50 Trigger transition to POCstate ALL_SLOTS by executing POC command CMD_ALL_SLOTS. */
    retVal = Fr_VExecutePOCCommand(FR_VCTRL_IDX, CCCMD_ALL_SLOTS); /* SWS_Fr_00518 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FR_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FR_E_NO_ERROR)
  {
    (void)Det_ReportError(FR_MODULE_ID, FR_INSTANCE_ID_DET, FR_SID_ALLSLOTS, errorId);
  }
#else
  FR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* Fr_AllSlots() */

# if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON) /* COV_FR_TESTSUITE_INSTRUMENTATION */
/**********************************************************************************************************************
 *  Fr_ISR_Status()
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
 */
FUNC(void, FR_CODE) Fr_ISR_Status
(
  FR_VCTRL_SYSTEMTYPE_ONLY
)
{ /* PRQA S 3007 */ /* MD_Fr_3007 */
  /* ----- Local Variables ---------------------------------------------- */
#  if ( FR_VHARDWARE_CANCELLATION == STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#  endif
  /* #10 Get value of Status Interrupt Register (SIR). */
  uint32 ui32SIR  = Fr_VCCReadValue(FR_VCTRL_IDX, FR_SIR);

  FR_DUMMY_STATEMENT_CONST(FR_VCTRL_IDX); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  /* ----- Implementation ----------------------------------------------- */
  /* ESCAN00070620 */
  Fr_Rtm_Start(Fr_ISR_Status);

  /**
   *
   * Internal comment removed. *
 *
 *
 *
   */
  /* #20 Iterate as long as the Cycle Start Interrupt Enable flag (CYCSE) in SIR register is set. */
  while (((ui32SIR & FR_SIR_CYCS) != 0UL) && ((uint8)FR_NOHWTIMEOUT)) /* COV_FR_HARDWARE_FAILURE */
  {
    FR_INCREASETIMEOUTCOUNTER;
    /************************************************/
    /*           CycleStart Interrupt               */
    /************************************************/
#  if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON) /* COV_FR_TESTSUITE_INSTRUMENTATION */
    /* #40 If FR_CFG_APPL_CALLBACK_CYCLE_START is enabled, call application callback ApplFr_ISR_CycleStart(). */
#   if (FR_NUM_CTRL_USED > 1)
    if (FR_VCTRL_IDX == 1)
    {
      ApplFr_ISR_CycleStart_1();
    }
    else
#   endif
    {
      ApplFr_ISR_CycleStart();
    }
#  endif
    /* #50 Clear the Cycle Start Interrupt flag (CYCS) in SIR register. */
    Fr_VCCClearIrqStatusFlag(FR_VCTRL_IDX, FR_SIR_CYCS); /* SBSW_FR_WriteHwReg */

    /* #60 Process further pending Interrupts. */
    ui32SIR = Fr_VCCReadValue(FR_VCTRL_IDX, FR_SIR);
  }

#  if (FR_VHARDWARE_CANCELLATION == STD_ON)
  if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION) /* COV_FR_HARDWARE_FAILURE */
  {
    Fr_DemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
  }
#  endif

  /* ESCAN00070620 */
  Fr_Rtm_Stop(Fr_ISR_Status);
} /* Fr_ISR_Status() */
# endif /* FR_CFG_APPL_CALLBACK_CYCLE_START */

#define FR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* module specific MISRA deviations: 
 MD_Fr_0277:      Rule 3.1
      Reason:     Negative bit value is signed, but unsigned bitmask is needed.
      Risk:       No risk
      Prevention: Covered by code review.
 MD_Fr_3218:      Rule 8.7
      Reason:     Avoid stop and restart of FR_CONST-section within the one and only function the constant is used in.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_Fr_3408:      Rule 8.8
      Reason:     The function or symbol must be declared as extern by the application.
      Risk:       No risk
      Prevention: Covered by code review.
 MD_Fr_8.12:      Rule 8.12
      Reason:     The arrays in file Fr.h, Fr_PBcfg.h and Fr_Lcfg.h are declared as extern without size specification since their size depend on the configuration in GENy.
      Risk:       There is no risk because these arrays are only used by Fr.
      Prevention: Covered by code review.
 MD_Fr_0306:      Rule 11.3
      Reason:     This cast between a pointer type and an integral type is needed because of addressing a memory mapped variable.
      Risk:       No risk (see ESCAN00064374)
      Prevention: Covered by code review.
 MD_Fr_0310:      Rule 11.4
      Reason:     The downcast between pointer and integral type is required for efficient implementation.
      Risk:       There is no risk as the cast is a downcast.
      Prevention: Covered by code review.
 MD_Fr_0311:      Rule 11.5
      Reason:     The loss of const qualification is uncritical because only the pSrc pointer is changed by Fr_VReadDataFromCC() and not the (const) data.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_Fr_13.7:      Rule 13.7
      Reason:     If NM is enabled but NMVectorlength is set to 0 the condition is always false.
      Risk:       There is no risk because the for-loop will be skipped completely.
      Prevention: Covered by code review.
 MD_Fr_3007:      Rule 16.5
      Reason:     Due to the Single Channel API optimization void has been omitted when defining a function with no parameters.
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review. 
 MD_Fr_4102:      Rule 12.6
      Reason:     Deliberate violation of rule: confusing logical operators with bitwise operators is prevented by code review.
      Risk:       There is no risk.
      Prevention: Covered by code review.
 MD_Fr_0342:      Rule: 19.13: K&R compilers do not support the ISO glue operator ##.
     Reason:      Identifier has to be a combination of both IDs
     Risk:        Compile error.
     Prevention:  Not required.
*/

/* COV_JUSTIFICATION_BEGIN

\ID COV_FR_MSR_COMPATIBILITY
\ACCEPT TX 
\ACCEPT XF 
\REASON [COV_MSR_COMPATIBILITY]

\ID COV_FR_UNSUPPORTED_SAFEBSW_FEATURE
\ACCEPT TX 
\ACCEPT TF tx tf 
\ACCEPT XF xf xx
\ACCEPT XF 
\ACCEPT TF xf tf
\REASON [COV_MSR_UNSUPPORTED] The following features are not supported by FR in SafeBSW usecase and the correpsonding preprocessor switches must be configured to STD_OFF or need to be undefined (which is ensured by MSSV plugin): FR_VTT, FR_DIRECT_BUFFER_ACCESS_ENABLE, FR_NONALIGNED_SRCMEMORY, FR_TRICORE_AURIX_IR_CONF, (FR_NUM_CTRL_USED == 1)

\ID COV_FR_TESTSUITE_INSTRUMENTATION
\ACCEPT XF 
\ACCEPT TX 
\ACCEPT XX 
\REASON Not all branches covered because the following preprocessor macros and defines are necessary for proper test execution with FrTestSuite: FR_CFG_APPL_CALLBACK_CYCLE_START

\ID COV_FR_EQUIVALENT_HARDWARE
\ACCEPT XF 
\ACCEPT TX 
\ACCEPT XF xf xf xf xf
\REASON Not all branches covered because the FR driver was tested on a equivalent hardware platform.

\ID COV_FR_SOURCE
\ACCEPT XF 
\REASON Only False branch is covered because FR_SOURCE is only defined in Fr.c and the macros shall not be defined in the C-file. Otherwise the single channel API optimization does not work properly and a compiler warning is thrown.

\ID COV_FR_UNSUPPORTED_ISR_TYPE
\ACCEPT XF xf xf
\ACCEPT XX
\ACCEPT TX
\REASON SafeBSW only allows ISR type CAT2.

\ID COV_FR_HARDWARE_FAILURE
\ACCEPT TX
\ACCEPT XF
\ACCEPT XX
\ACCEPT TF tf tx
\ACCEPT XF xf xf
\ACCEPT XF xf xx
\REASON The condition checks for hardware failures that cannot be stimulated. The code is verified by code inspection.

COV_JUSTIFICATION_END */ 

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_FR_WritePtr
  \DESCRIPTION        Pointer write access by dereferencing a pointer given as input.  
  \COUNTERMEASURE \N  The original caller guarantees the validity of the pointer.

\ID SBSW_FR_WriteHwReg
  \DESCRIPTION        The function accesses a hardware register of E-Ray using a pointer access.
  \COUNTERMEASURE \M  [CM_FR_RegisterAccess]
                  \M  A plugin makes sure that the base address of the E-Ray FlexRay cell is correct.

\ID SBSW_FR_WriteStructMember 
  \DESCRIPTION        Write access to the members of a struct using an unchanged pointer.
  \COUNTERMEASURE \N  The original caller guarantees the validity of the pointer.

\ID SBSW_FR_FctCallPtr2HwReg
  \DESCRIPTION        Function call with a pointer to a hardware register.
  \COUNTERMEASURE \M  [CM_FR_RegisterAccess]

\ID SBSW_FR_WriteArray
  \DESCRIPTION        Write access to initialize and fill array. Both pointer to array and the length of the array are given by the caller and can thus be considered to be valid.
  \COUNTERMEASURE \R  [CM_FR_ArrayAccess]

\ID SBSW_FR_WriteArrayNmVector
  \DESCRIPTION        Write access to array to return the NM vector. 
  \COUNTERMEASURE \S  The caller of the function Fr_GetNMVector must ensure that the pointer passed to the parameter Fr_NmVectorPtr 
                      references a valid memory location and that the size of the array referenced by it is greater or equal to the value of the BSWMD parameter 
                      /MICROSAR/FrIf/FrIfConfig/FrIfCluster/FrIfGNetworkManagementVectorLength.
                      SMI-345

\ID SBSW_FR_WriteArrayLocal
  \DESCRIPTION        Write access to fill local array.
  \COUNTERMEASURE \N  Write access to locally defined arrays can be safely considered to be valid.

\ID SBSW_FR_AsmNop
  \DESCRIPTION        Assembler instruction NOP.
  \COUNTERMEASURE \N  Only a NOP is executed that has no side effects.

SBSW_JUSTIFICATION_END */                  

/*
\CM CM_FR_RegisterAccess    A plugin makes sure that the used register offset addresses (Fr_VCcRegAddrs) are in the register address range of the E-Ray communication controller.
*/

/*
\CM CM_FR_ArrayAccess       The for loop and the following conditions ensure that it never exceeds the size of the array.
*/
