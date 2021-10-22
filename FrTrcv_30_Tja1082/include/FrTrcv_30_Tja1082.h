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
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file  FrTrcv_30_Tja1082.h
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver header file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Andreas Herkommer             hr            Vctr Informatik GmbH
 *  Oliver Reineke                ore           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2014-05-12  hr      ESCAN00075721 Creation of component
 *  1.00.01   2015-05-27  hr      ESCAN00079836 Compiler error: Wrong mapping of critical sections
 *                                              FrTrcv_30_Tja1082_EnterCritical/FrTrcv_30_Tja1082_LeaveCritical
 *  1.00.02   2015-07-15  ore     ESCAN00084021 Compiler error: Undefined symbol 'FRTRCV_APPL_DATA'
 *  1.01.00   2016-10-24  hr      ESCAN00092491 Support AR3
 *                        hr      ESCAN00092492 Variable for DET init check not located in INIT section
 *  2.00.00   2017-07-19  hr      STORY-1874    Create Safe BSW Transceiver Driver for Tja1082
 *  2.00.01   2017-10-06  hr      ESCAN00096759 Wrong wake up reason reported due to false priority of wake up reason FRTRCV_WU_INTERNALLY
 *********************************************************************************************************************/
#ifndef FRTRCV_30_TJA1082_H
# define FRTRCV_30_TJA1082_H

/**************************************************************************************************
* Include files
**************************************************************************************************/
# include "ComStack_Types.h"
# include "Fr_GeneralTypes.h"
# include "EcuM_Cbk.h"
# include "Dio.h"
# include "FrTrcv_30_Tja1082_Cfg.h"

# if ( FRTRCV_30_TJA1082_PROD_ERROR_DETECT == STD_ON )
#  include "Dem.h"
# endif

# include "SchM_FrTrcv_30_Tja1082.h"

/*!
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
 */

/**************************************************************************************************
* Version
**************************************************************************************************/
/* BCD coded version number */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans_Tja1082FrAsr CQComponent : Implementation */
# define DRVTRANS_TJA1082FRASR_VERSION         0x0200u /* BCD coded version number */
# define DRVTRANS_TJA1082FRASR_RELEASE_VERSION 0x01u   /* BCD coded version number */

/* supported Autosar version */
# define FRTRCV_30_TJA1082_AR_MAJOR_VERSION     (4u)
# define FRTRCV_30_TJA1082_AR_MINOR_VERSION     (0u)
# define FRTRCV_30_TJA1082_AR_PATCH_VERSION     (3u)
# define FRTRCV_30_TJA1082_SW_MAJOR_VERSION     (2u)
# define FRTRCV_30_TJA1082_SW_MINOR_VERSION     (0u)
# define FRTRCV_30_TJA1082_SW_PATCH_VERSION     (1u)

# define FRTRCV_30_TJA1082_VENDOR_ID (30u) /* Vector = 30 */
# define FRTRCV_30_TJA1082_MODULE_ID (71u) /* FlexRay Trcv = 71 */

# define FRTRCV_30_TJA1082_INSTANCE_ID (0u)

/**************************************************************************************************
* Global defines
**************************************************************************************************/

/* Development errors */
/* ----- API service IDs ----- */
# define FRTRCV_30_TJA1082_SID_TRCVINIT                            0u
# define FRTRCV_30_TJA1082_SID_SETTRANSCEIVERMODE                  1u
# define FRTRCV_30_TJA1082_SID_GETTRANSCEIVERMODE                  5u
# define FRTRCV_30_TJA1082_SID_GETTRANSCEIVERWUREASON              6u
# define FRTRCV_30_TJA1082_SID_GETVERSIONINFO                      7u
# define FRTRCV_30_TJA1082_SID_GETTRANSCEIVERERROR                 8u
# define FRTRCV_30_TJA1082_SID_CLEARTRANSCEIVERWAKEUP             12u
# define FRTRCV_30_TJA1082_SID_MAINFUNCTION                       13u
# define FRTRCV_30_TJA1082_SID_CHECKWAKEUPBYTRANSCEIVER           14u
# define FRTRCV_30_TJA1082_SID_DISABLETRANSCEIVERBRANCH           15u
# define FRTRCV_30_TJA1082_SID_ENABLETRANSCEIVERBRANCH            16u

/* ----- Error codes ----- */
/* \trace SPEC-43654, SPEC-43636 */
# define FRTRCV_30_TJA1082_E_FR_NO_ERROR                        0x00u
# define FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX                 0x01u
# define FRTRCV_30_TJA1082_E_FR_INVALID_BRANCHIDX               0x02u
# define FRTRCV_30_TJA1082_E_FR_INVALID_MODE                    0x03u
# define FRTRCV_30_TJA1082_E_FR_UNINIT                          0x10u
# define FRTRCV_30_TJA1082_E_FR_TRCV_NOT_STANDBY                0x11u
# define FRTRCV_30_TJA1082_E_FR_TRCV_NOT_NORMAL                 0x12u
# define FRTRCV_30_TJA1082_E_FR_TRCV_NOT_SLEEP                  0x13u
# define FRTRCV_30_TJA1082_E_FR_TRCV_NOT_RECEIVEONLY            0x14u
# define FRTRCV_30_TJA1082_E_FR_TRCV_NULL_PTR                   0x15u
# define FRTRCV_30_TJA1082_E_FR_NO_CONTROL_TRCV                 0x16u

/* ----- FrTrcv420: Bit mask for transceiver errors ----- */
/* \trace SPEC-2690432 */
# define FRTRCV_30_TJA1082_ERROR_NONE                         0x0000u
# define FRTRCV_30_TJA1082_BDE_GLOBAL_ERROR                   0x0001u
# define FRTRCV_30_TJA1082_BDE_SHORT_CIRCUIT_BM_BP            0x0002u
# define FRTRCV_30_TJA1082_BDE_BP_SHORT_CIRCUIT_GND           0x0004u
# define FRTRCV_30_TJA1082_BDE_BP_SHORT_CIRCUIT_VCC           0x0008u
# define FRTRCV_30_TJA1082_BDE_BM_SHORT_CIRCUIT_GND           0x0010u
# define FRTRCV_30_TJA1082_BDE_BM_SHORT_CIRCUIT_VCC           0x0020u
# define FRTRCV_30_TJA1082_BDE_GENERAL_FAULT                  0x0040u
# define FRTRCV_30_TJA1082_BDE_UNDERVOLTAGE                   0x0080u
# define FRTRCV_30_TJA1082_BDE_TXEN_TIMEOUT                   0x0100u
# define FRTRCV_30_TJA1082_BDE_OVER_TEMPERATURE               0x0200u

/* Predefined timer indexes (0x01 - 0x0f) */
# define kFrTrcv_30_Tja1082_SetMode                            0x01u
# define kFrTrcv_30_Tja1082_ModeChange                         0x02u

# if !defined (FRTRCV_30_TJA1082_IMMEDIATE_WAKEUP_CHECK)      /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define FRTRCV_30_TJA1082_IMMEDIATE_WAKEUP_CHECK            STD_OFF
# endif

/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/
/*! Type defining the configuration structure used in FrTrcv_Cfg.c */
typedef struct
{
  FrTrcv_TrcvModeType    FrTrcv_InitState;          /*<! The initial operation mode */
  EcuM_WakeupSourceType  FrTrcv_WakeupSourceRef;    /*<! Wake Up Source Reference */
  uint8                  FrTrcv_WakeupSupported;    /*<! Is Wakeup detection supported */
  uint8                  FrTrcv_WakeupPolling;      /*<! Is polling active */
  uint8                  FrTrcv_ChannelUsed;        /*<! Is the channel used */
} FrTrcv_30_Tja1082_GenConfigType;

typedef struct
{
  Dio_ChannelType   TrcvPinSTBN;                    /*<! SNV for Pin STBN */
  Dio_ChannelType   TrcvPinERRN;                    /*<! SNV for Pin ERRN */
} FrTrcv_30_Tja1082_ChannelType;

/**************************************************************************************************
* Prototypes of export variables
**************************************************************************************************/

/****************************************************************************/
/* Constants for export with unspecified size                               */
/****************************************************************************/
# define FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

extern CONST( FrTrcv_30_Tja1082_GenConfigType, FRTRCV_30_TJA1082_CONST ) FrTrcv_30_Tja1082_Config[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES];
extern CONST( FrTrcv_30_Tja1082_ChannelType, FRTRCV_30_TJA1082_CONST ) FrTrcv_30_Tja1082_Channel[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES];
# if ( FRTRCV_30_TJA1082_PROD_ERROR_DETECT == STD_ON )
  extern CONST( Dem_EventIdType, FRTRCV_30_TJA1082_CONST ) FrTrcv_30_Tja1082_DEM_E_Fr_Error_Channel[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES];
# endif

# define FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

# define FRTRCV_30_TJA1082_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Initialize static variables.
 *  \details     This function must be used if the startup code does not initialize the memory.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_InitMemory( void );

/**********************************************************************************************************************
 * FrTrcv_30_Tja1082_Init()
 **********************************************************************************************************************/
/*! \brief       Component initialization function.
 *  \details     This function initializes the module FrTrcv. It initializes all variables and sets the module state to
 *               initialized. Furthermore pending wake up events are checked and the transceiver device is set to a
 *               default mode.
 *  \pre         FrTrcv_InitMemory has been called unless FrTrcv_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43639, SPEC-43524 DIO can not fail, SPEC-43532, SPEC-43648, SPEC-43506, SPEC-43677
 *  \trace SPEC-43566 Always performed if diagnosis is enabled. Parameter FrTrcvErrorCheckInInit not evaluated
 *  \trace SPEC-43673, SPEC-43620, SPEC-43688, SPEC-43670, SPEC-43578, SPEC-43577, SPEC-43666, SPEC-43534, SPEC-43668 
 *  \trace CREQ-705
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_Init( void );

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_MainFunction()
 **********************************************************************************************************************/
/*! \fn          FrTrcv_30_Tja1082_MainFunction
 *  \brief       Cyclic task function of the comnponent
 *  \details     The MainFunction must be called cyclically to perform tasks used in polling use case like wake up and
 *               error detection.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-22506, SPEC-22509 The SchM always expects a MainFunction. Therefore this optimnization was omitted.
 *  \trace SPEC-43557 Internal function is used to detect the error information. GetTransceiverError is only used for reporting.
 *  \trace SPEC-43683, SPEC-43511, SPEC-43547, SPEC-43665, SPEC-43580, SPEC-22464, SPEC-22393
 *  \trace SPEC-22401, SPEC-43653, SPEC-43509
 **********************************************************************************************************************/
/* In ASR4 MainFunction prototype is declared in SchM */

# if ( FRTRCV_30_TJA1082_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     FrTrcv_30_Tja1082_GetVersionInfo() returns version information,
 *               vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to where to store the version information. Parameter must be valid.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      FRTRCV_30_TJA1082_VERSION_INFO_API
 *  \trace SPEC-22475, SPEC-43644, SPEC-43608, SPEC-43552, SPEC-43538, SPEC-43607, SPEC-22455, SPEC-22481, SPEC-43619
 *  \trace SPEC-22519 not realized to keep complexity low, SPEC-2690429, SPEC-43629, SPEC-22455
 *  \trace CREQ-756
 **********************************************************************************************************************/
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) versioninfo);
# endif

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_SetTransceiverMode()
 **********************************************************************************************************************/
/*! \brief       Changes the operation mode of the selected transceiver.
 *  \details     If the requested mode is not supported an equivalent mode is selected. If the mode change was not
 *               successful, E_NOT_OK is returned. If an active mode is set, the wake up reason is set to FRTRCV_WU_INTERNALLY
 *  \param[in]   FrTrcv_TrcvIdx   The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_TrcvMode  The Transceiver mode that shall be set
 *  \return      E_NOT_OK - Transceiver state change failed or function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43674, SPEC-43635, SPEC-43513, SPEC-43563, SPEC-43640 Name of call-out is fixed, SPEC-43526
 *  \trace SPEC-43681, SPEC-43562, SPEC-43551, SPEC-43539, SPEC-43572, SPEC-22377, SPEC-22484
 *  \trace SPEC-43710 State transisitions can not fail on DIO transceivers.
 *  \trace SPEC-43630, SPEC-22397, SPEC-43525
 *  \trace SPEC-43708, SPEC-22499
 *  \trace CREQ-758
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_SetTransceiverMode(uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvModeType FrTrcv_TrcvMode);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverMode()
 **********************************************************************************************************************/
/*! \brief       Reads the operation mode of the selected transceiver.
 *  \details     Returns the current transceiver mode on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx        The selected FlexRay bus transceiver.
 *  \param[out]  FrTrcv_TrcvModePtr    Output parameter reference for current Trcv mode. Pointer must be valid and is not
 *                                     used in an array write access.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-22382, SPEC-22434, SPEC-43527, SPEC-22487, SPEC-22413, SPEC-43536
 *  \trace CREQ-759
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverMode(uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_TrcvModePtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverWUReason()
 **********************************************************************************************************************/
/*! \brief       Returns the wakeup reason of the selected bus.
 *  \details     Returns the current transceiver wake up reason on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver.
 *  \param[out]  FrTrcv_TrcvWUReasonPtr  Output parameter reference for wake up reason. Pointer has to be valid.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43531, SPEC-43519, SPEC-43537, SPEC-43621, SPEC-22522, SPEC-22415, SPEC-43542
 *  \trace CREQ-761
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverWUReason(uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_TrcvWUReasonPtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_ClearTransceiverWakeup()
 **********************************************************************************************************************/
/*! \brief       Clears pending wakeup events.
 *  \details     Clears pending wake up events and resets the wake up reason on the selected channel.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43614, SPEC-22530, SPEC-43694, SPEC-43696, SPEC-43625, SPEC-43685, SPEC-2690430
 *  \trace CREQ-760, CREQ-761
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_ClearTransceiverWakeup(uint8 FrTrcv_TrcvIdx);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_DisableTransceiverBranch()
 **********************************************************************************************************************/
/*! \brief       Disables a specific transceiver branch.
 *  \details     The Tja1082 has no branches therefore this API does not perform any action.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \return      E_NOT_OK - branch was not disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43671, SPEC-43571, SPEC-43709, SPEC-43576
 *  \trace CREQ-763
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_DisableTransceiverBranch(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_EnableTransceiverBranch()
 **********************************************************************************************************************/
/*! \brief       Enables a specific transceiver branch.
 *  \details     The Tja1082 has no branches therefore this API does not perform any action.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43572, SPEC-43535, SPEC-43695, SPEC-43707
 *  \trace CREQ-762
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_EnableTransceiverBranch(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx);

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverError()
 **********************************************************************************************************************/
/*! \brief       Returns the error status of a specified branch.
 *  \details     This function returns the latest error reason, detected during FrTrcv_30_Tja1082_CheckWakeupByTransceiver.
 *  \param[in]   FrTrcv_TrcvIdx          The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_BranchIdx        The selected FlexRay bus transceiver branch
 *  \param[out]  FrTrcv_BusErrorState    The detailed bus error state. Pointer must be valid. See \trace FrTrcv420 in this header file
 *                                       for a detailed description of the individual bits of the result word.
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - success
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace SPEC-43688, SPEC-43533, SPEC-43657, SPEC-43555, SPEC-43618, SPEC-43705, SPEC-43594, SPEC-43582, SPEC-43586
 *  \trace SPEC-43646, SPEC-43661, SPEC-43568
 *  \trace CREQ-755
 **********************************************************************************************************************/
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverError(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_BusErrorStatePtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */

# define FRTRCV_30_TJA1082_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/*!
 * \exclusivearea FRTRCV_30_TJA1082_EXCLUSIVE_AREA_0
 * Ensures consistency of non-time critical sections. They may be interrupted by application functionality or time critical CAT1 interrupts.
 * \protects DIO access
 * \usedin FrTrcv_30_Tja1082_SetTransceiverMode, FrTrcv_30_Tja1082_ClearTransceiverWakeup, FrTrcv_30_Tja1082_GetTransceiverError, FrTrcv_30_Tja1082_CheckWakeupByTransceiver
 * \exclude all functions not mentioned above
 * \length SHORT Access to DIO/Variables is protected for atomic access.
 * \endexclusivearea
 */

/***** end of header file ************************************************************************/
#endif
  /* ifndef FRTRCV_30_TJA1082_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1082.h
 *********************************************************************************************************************/
