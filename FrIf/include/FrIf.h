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
/**        \file  FrIf.h
 *        \brief  FlexRay Interface header file
 *
 *      \details  Header file implementation of the AUTOSAR FlexRay Interface according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 -  Klaus Bergdolt                ber           Vctr Informatik GmbH
 -  Oliver Reineke                ore           Vctr Informatik GmbH
 -  Anthony Thomas                ath           Vctr Informatik GmbH
 -  -------------------------------------------------------------------------------------------------------------------
 *  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  03.00.00  2007-12-12  ber     -             release of version 3.00.0 
 -  03.00.01  2008-02-01  ber     -             added compiler abstraction and memory mapping
 -  03.00.02  2008-03-20  ber     -             Configuration of FrIf Update Bit for TX PDUs
 -            2008-04-02  ber     ESCAN00023644 FrIf detects JobListOutOfSynch in case of large difference of job times
 -  03.00.03  2008-04-17  ber     -             Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     -             Tx call back functions called with wrong PDU-ID in case some PDUs are configured for immediate transmission
 -  03.00.04  2008-04-25  ore     ESCAN00026130 Use <BSW>_InitMemory
 -            2008-04-25  ore     ESCAN00026216 Extension for MSR3.0 LinkTime checks
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 FrIf_Cbk.h is missing
 -            2008-04-28  ore     ESCAN00026447 FrIf_ConfigType is missing in implementation
 -            2008-04-28  ore     ESCAN00026449 FrIf_GetMacroticksDuration is missing
 -            2008-05-15  ore     ESCAN00026651 Extension for MSR3.0 generator version checks
 -            2008-05-19  ore     ESCAN00026973 Inconsistent Memory Mapping
 -  03.00.05  2008-06-09  ore     -             Inconsistent Memory Mapping for FrIf_Lcfg.c
 -            2008-06-09  ore     -             Add missing Postbuild Features
 -            2008-07-08  ore     -             Integrate Post-Build Feature
 -            2008-07-09  ore     ESCAN00028155 FrIf does not clear transmit request when changing to state OFFLINE.
 -  03.00.06  2008-07-17  ore     -             Improve Interaction with FrNm- and FrTp-MainFunction
 -  03.00.07  2008-07-18  ore     ESCAN00027867 Receive with Direct Buffer Access
 -            2008-07-24  ore     ESCAN00027210 FrIf shall call Fr_PrepareLPdu to enable the driver to use a more efficient message buffer assignment for RX
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-01  ore     ESCAN00027451 FrIf Job List Execution in Polling Mode
 -            2008-08-07  ore     ESCAN00029068 FrIf does not detect that a received frame is shorter than configured.
 -            2008-08-07  ore     ESCAN00029042 FrIf Job List Execution sometimes skips complete round (64 cycles)
 -            2008-08-13  ore     ESCAN00029218 Decrease jitter in case of FrIf task overlapping
 -            2008-08-13  ore     ESCAN00029219 Provide API to monitor the quality of the FrIf job list execution
 -            2008-08-13  ore     ESCAN00029184 Call TxConf-callbacks in case of stopping or resynchronizing the FrIf-JobList
 -  03.00.08  2008-08-22  ore     -             No constant generated which can be used as parameter for FrIf_Init()
 -  03.00.09  2008-09-17  ore     -             release of version 3.00.09
 -  03.00.10  2008-10-01  ore     ESCAN00030038 FrIf file name conventions
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 AUTOSAR Dummy Statements
 -            2008-10-01  ore     ESCAN00029736 instanceID by <MSN>_GetVersionInfo
 -            2008-11-03  ore     ESCAN00031030 Unused frame parts are not always initialized
 -            2008-11-03  ore     ESCAN00031026 FrIf header file structure differs from AUTOSAR specification 
 -  03.01.00  2008-11-10  ore     ESCAN00030776 FrIf_SetState does not return E_NOT_OK in case it could not start the job list execution
 -            2008-11-10  ore     ESCAN00030577 Clear PduConfCounter in case Fr_CheckTxLPduStatus returns E_NOT_OK
 -            2008-11-10  ore     ESCAN00030264 PreCompile and Linktime Crc Check
 -            2008-11-10  ore     ESCAN00030764 Concurrent Write Access to FrIf State
 -            2008-11-17  ore     ESCAN00031345 FrIf indicates PDUs in non received frame areas
 -            2008-11-17  ore     ESCAN00030264 PreCompile and Linktime Crc Check
 -            2008-11-24  ore     ESCAN00031026 FrIf header file structure differs from AUTOSAR specification 
 -            2008-11-24  ore     ESCAN00031360 Implement FrIf_GetChannelStatus() and FrIf_GetClockCorrection()
 -            2008-12-01  ore     ESCAN00031710 Rollback TxRequestCounter in case of FrDrv-API errors
 -            2008-12-08  ore     ESCAN00031843 Compile Error when Single Controller API optimization is enabled
 -  03.02.00  2009-02-02  ore     ESCAN00032463 Compiler warning on TMS570
 -            2009-02-10  ore     ESCAN00032944 Call of Fr_ControllerInit
 -            2009-02-17  ore     ESCAN00033102 FrIf_Transmit does not return E_NOT_OK in case the FrIf_Status is OFFLINE
 -            2009-02-18  ore     ESCAN00027867 Receive with Direct Buffer Access
 -            2009-02-18  ore     ESCAN00033318 FrIf_Cbk.h should include Fr_GeneralTypes.h and the CrtlApiOptimization
 *                                              of FrIf_Cbk_WakeupByTransceiver should be removed
 -            2009-02-18  ore     ESCAN00033145 Transmit with Direct Buffer Access
 -            2009-02-18  ore     ESCAN00033220 The functions FrIf_RxTask_0 and FrIf_TxTask_0 shall have standard return values.
 -            2009-02-18  ore     ESCAN00032895 FrIf Job Concatenation Optimization
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra violations.
 -            2009-02-18  ore     ESCAN00031278 Missing extern declaration of FrIf_Config in FrIf.h
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 The FrIf source and header files don't use the Compiler-Abstraction keyword STATIC
 -            2009-02-26  ore     ESCAN00032715 Check at runtime whether the FrIf job execution is performed during its own slot range
 -            2009-03-05  ore     ESCAN00033650 Add missing DetChecks FrIf_Abs/RelTimer APIs, FrIf_GetTransceiverMode and FrIf_GetTransceiverWUReason
 -            2009-03-06  ore     ESCAN00033651 Unify DET implementation
 -            2009-03-06  ore     ESCAN00033665 Add missing Link-time configuration variant
 -            2009-03-18  ore     ESCAN00033669 The FrIf main-, sub- and release-version shall be BCD coded
 -            2009-03-10  ore     -             Generate FrIf wrapper functions instead of function tables to call the upperlayer functions
 -            2009-03-23  ore     ESCAN00034040 Extended version check causes compiler warnings
 -  03.03.00  2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     -             The FrIf supports only a maximum of 8 Pdus per frame. Extend the maximum to 32 pdus per frame.
 -            2009-05-28  ore     ESCAN00035048 MacroTicksLengthInNanoSeconds returns invalid value for systems with selectable postbuild
 -            2009-06-29  ore     ESCAN00035991 Compiler error when V_USE_DUMMY_STATEMENT == STD_ON
 -            2009-07-06  ore     -             Add FRIF_USE_FRTRCV_API precompileswitch to remove dependecy to v_cfg.h
 -            2009-07-20  ore     ESCAN00036397 FlexRay Interface shall support FIFOs (Asr 4.0)
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration 
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file
 -            2009-07-15  ore     ESCAN00036426 Remove obsolete FrIf status changes and FrIf_DisableJobListExecution calls
 -            2009-07-15  ore     ESCAN00036427 Implement FrIf_DiffTime as static function
 -            2009-07-15  ore     ESCAN00036429 Reduce codesize by implementing the FrIf wrapper APIs as macros
 -            2009-07-15  ore     ESCAN00036451 Unused FrIf APIs cannot be disabled via precompile switch
 -            2009-07-16  ore     ESCAN00036471 Add precompile switch to enable/disable the usage of the request counter handling
 -            2009-07-17  ore     -             Add compiler abstraction modifier <MSN>_PBCFG_ROOT
 -            2009-07-28  ore     ESCAN00036120 pre-processor checks for building the library
 -            2009-07-31  ore     ESCAN00036776 FrIf_StopJobListExec can take some seconds if the FrIf is re-initialized with a new PB-config at runtime
 -  03.04.00  2009-09-23  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-08-24  ore     -             FrIf does not support TX frames with more than 8 PDUs
 -            2009-08-24  ore     ESCAN00037257 FrIf Api without FrTrans are not switched off - Compiler Error
 -            2009-09-08  ore     -             The FrIf bitarrays in postbuild structures are not supported by the GenTool_GenyFrameworkPostbuildconfig component
 -            2009-09-08  ore     ESCAN00037643 FrIf_ext.h is not included if FRIF_CUSTOM_JLE_SCHEDULING is set to STD_ON
 -            2009-09-08  ore     -             Implement wrapper functions for FrTpIso with AUTOSAR 4.0 Buffer API
 -            2009-09-21  ore     ESCAN00036013 Similar DET Usage
 -            2009-10-27  ore     ESCAN00038513 Use E_PENDING in FrIf_Transmit if data is copied in PduR_FrIfTriggerTransmit, FrNm_TriggerTransmit and FrTp_TriggerTransmit
 -            2009-11-02  ore     ESCAN00038914 FrIf_EnableJobListExecution routine shall call Fr_PrepareLPdu for all Rx and Tx handles to flush the complete hardware FIFO
 -            2009-11-02  ore     ESCAN00038855 Support FrTrcv Vendor Id and vendor api infix in file and API names
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 Add FrIf_CancelTransmit API according to AUTOSAR 4.0 to reset the request counter.
 -            2009-11-30  ore     -             FrIf does not set update bit if last PDU of frame has no update bit
 -            2009-12-07  ore     -             Add code-size optimization for configurations with uniform update byte usage
 -            2009-12-07  ore     -             Add code-size optimization for configurations with less than 256 rx or tx mapped PDUs
 -  03.05.00  2010-02-01  ore     ESCAN00040508 Add feature to support FreeOp-Callbacks
 -            2010-02-16  ore     ESCAN00040867 The TxRequestCounter shall only decremented if a frame in the dynamic segment has not been suppressed
 -            2010-02-18  ore     ESCAN00040951 FrIf without SchM cannot be compiled
 -            2010-02-18  ore     ESCAN00040960 DEM errors are reported by the FlexRay Interface if the main function is called before the FrIf state is set by the FrSM
 -            2010-02-22  ore     -             Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 Compile error for missing C_COMP_zzz_yyy definition if v_cfg.h is not included by Compiler_Cfg.h
 -            2010-03-24  ore     ESCAN00041766 Support return value E_PENDING when calling Fr_RequestBuffer_DBA routine
 -            2010-03-24  ore     ESCAN00041788 Compile error because integer conversion resulted in a change of sign
 -            2010-03-30  ore     ESCAN00041966 Metrowerks Compile warning: Possible loss of data
 -            2010-04-22  ore     -             Add support for other FlexRay transceivers than Tja1080
 -            2010-05-05  ore     ESCAN00041396 Reduce the duration of critical sections of the FrIf when the FrIfJobList execution goes out of sync
 -  03.06.00  2010-05-19  ore     ESCAN00042989 The FlexRay Interface shall support ReconfigLPdu and DisableLPdu (Asr 4.0)
 -            2010-05-28  ore     -             Convert VectorSpecific BSWMD parameter to the corresponding ASR 4.0 parameter
 -            2010-06-24  ore     ESCAN00043567 The FlexRay Interface shall support ReadCCConfig (Bugzilla 30176)
 -            2010-06-24  ore     ESCAN00043569 The FlexRay Interface shall support GetSyncFrameList (Asr 4.0)
 -            2010-07-22  ore     -             Add feature to support a delayed TxConfirmation for a FrIf Tx Job
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 Add check for enabled features that are filtered by Organi
 -  03.06.01  2010-09-22  ore     ESCAN00044465 Missing DetChecks for FRIF_E_NOT_INITIALIZED
 -            2010-09-22  ore     ESCAN00045547 Compile error occurs if FrIf_GetChannelStatus API is enabled
 -  03.07.00  2010-11-02  ore     ESCAN00045650 Compiler warning:  condition is always false
 -            2010-11-02  ore     ESCAN00046417 Pointer cast without using memory abstraction
 -            2010-11-02  ore     ESCAN00046257 Adapt AUTOSAR version check
 -            2010-11-05  ore     ESCAN00046607 Add DualChannelRedundancy support according to Bugzillla 42025.
 -            2010-11-16  ore     ESCAN00046950 Configurable TxConfirmation CommunicationOperation assignment (AR3-1229)
 -            2010-11-25  ore     ESCAN00046093 AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 -            2010-11-26  ore     -             PreCompileCrc changes if parameter FrIfSchedulingAlgorithm is set to 'HandleDynamicAsStatic'
 -            2010-12-01  ore     ESCAN00047302 Adapt MainFunction for usage with IdentityManagerConfig
 -            2010-12-01  ore     ESCAN00047327 No decoupled Tx in TxConfirmation context or missing confirmation in case of immediate Tx in TxConfirmation context 
 -            2011-01-27  ore     ESCAN00048244 'FrIf_Cbk_WakeupByTransceiver' is undefined if EcuM_Callout_Stubs.c includes FrIf_Cbk.h
 -  03.07.01  2011-02-23  ore     ESCAN00048836 The actual PduLength of Rx Pdus is not given to the upper layer if DualChannelRedundancySupport and UsePduInfoType is enabled
 -  03.08.00  2011-04-21  ore     ESCAN00049388 Start the JobListExecution in the same cylce in which the FrIfState was set to 'FRIF_STATE_ONLINE'
 -            2011-04-21  ore     ESCAN00050328 Support of 3rd party FrTrcv drivers
 -            2011-04-21  ore     ESCAN00050174 Support MultiConfig
 -            2011-05-04  ore     ESCAN00050585 [ASR3.2.1] Trcv APIs shall use 'Fr_ChannelType FrIf_ChnlIdx' in their 
 *                                              signature instead of 'uint8 FrIf_ChnlIDx'
 -            2011-05-04  ore     ESCAN00050587 [ASR3.2.1] Remove obsolete AbsoluteTimer and Releative Timer DET-Checks 
 -            2011-05-04  ore     ESCAN00050584 [ASR3.2.1] FRIF_E_INV_FRIF_CC_STATE shall be reported to the DET if FrIf_StateTransition of FrIf_SetState() was invalid
 -            2011-05-04  ore     ESCAN00050586 [ASR3.2.1] Add FrIf_GetCycleLength API and remove obsolete time conversion APIs
 -            2011-05-18  ore     ESCAN00050742 AR3-1330: Remove E_PENDING for ASR3
 -            2011-05-18  ore     ESCAN00050988 [ASR3.2.1] Implement the DET service ids according to the ASR 3.2.1 specification
 -            2011-05-26  ore     ESCAN00051149 AR3-1684: Implement RxIndication and TriggerTransmit Prototypes as specified in ASR 3.2.1
 -            2011-05-26  ore     ESCAN00051191 Compile error occurs because extern declaration of FrIf_RxHandles uses FrIf_TxHandleType instead of FrIf_RxHandleType
 -            2011-06-01  ore     -             Add support for ASR4.0 FrTrcv drivers
 -            2011-06-08  ore     ESCAN00051459 Add source defines according to MICROSAR template source file
 -            2011-06-21  ore     ESCAN00051519 Remove the AUTOSAR Release Version Check
 -            2011-08-03  ore     ESCAN00051840 TxConfirmation is not called if the FrIf goes out of sync before the Tx FrIfJob is executed
 -  03.08.01  2011-09-23  ore     -             PduR sends wrong FrIfPdus in MultiConfig usecase
 -            2011-09-23  ore     ESCAN00053800 FrIf wraps the FrTrcv APIs incorrectly in case 'FRTRCV_API_OPTIMIZATION' is enabled
 -  03.08.02  2011-09-29  ore     ESCAN00053923 Compiler error is thrown because FrTrcv_SetTransceiverMode symbol is 
 *                                              undefined when using "Wrapper APIs as Macro"
 -  03.09.00  2011-10-18  ore     ESCAN00053411 AR3-2069: Remove non-SchM code for critical section handling
 -            2011-11-23  ore     -             Add POLYSPACE support
 -            2012-01-20  ore     ESCAN00056172 FrIf wraps the FrTrcv APIs incorrectly in case 'FRTRCV_API_OPTIMIZATION' is enabled for AS8223 or E981.56 transceiver
 -  03.09.01  2012-01-25  ore     ESCAN00056269 Unsent Tx PDUs are confirmed when the FrIf looses synchronization
 -            2012-02-07  ore     ESCAN00056612 Out of bounds array access in FrIf_InitializeTransmission when job list execution is started
 -            2012-02-07  ore     ESCAN00056659 ASR4.0 API FrIf_CancelTransmit does not cancel Tx Pdus correctly in Multi Config use case
 -            2012-02-22  ore     ESCAN00056898 Call of FrIf_InitMemory is mandatory for normal operation
 -  03.09.02  2012-02-28  ore     -             AR3-2139: Provide Cfg5 Generator
 -  03.09.03  2012-03-12  ore     ESCAN00056160 AR4-125: Remove the inclusion of v_cfg.h and v_def.h because it is not needed anymore for VStdLib.h usage
 -            2012-03-12  ore     ESCAN00057355 AR3-2383: Implement handling of call to Dem_ReportErrorStatus
 -            2012-03-16  ore     ESCAN00057677 ZERO_INIT variables have no values assigned during variable definition
 -  03.10.00  2012-06-01  ore     ESCAN00059245 Job list execution does not work if two single FrIfJobs are concatenated with each other (no other FrIfJobs)
 -            2012-06-19  ore     ESCAN00058230 AR4-156: Support ASR4.00.3 APIs and filenames
 -            2012-07-30  ore     ESCAN00060444 Compiler warning: Implicit cast in assignment (destination type FrIf_PostBuildConfigType const *)
 -            2012-07-30  ore     ESCAN00060445 Compiler warning: Possible loss of data
 -            2012-08-14  ore     ESCAN00060783 PDU is transmitted although <UL>_TriggerTransmit returned E_NOT_OK
 -  03.11.00  2012-09-10  ore     ESCAN00060548 AR3-2443: Implement Silent Checks in BSW module code
 -            2012-09-10  ore     ESCAN00061294 Compiler error: due to missing inclusion of v_cfg.h and v_def.h 
 -            2012-09-18  ore     ESCAN00061399 The FrIf_GetMacroticksPerCycle() and FrIf_GetMacroticksDuration() API 
 *                                              services are missing in AUTOSAR4 use case
 -            2012-09-18  ore     ESCAN00061401 Resolve suggested improvements of 3.10.00 review
 -            2012-09-19  ore     ESCAN00061525 AR4-228: Return value of the FrIf_Transmit not clear when FrIfCounterLimit reached
 -            2012-10-08  ore     ESCAN00060725 AR3-2378: Implement instrumentation for time measurement
 -            2012-11-16  ore     ESCAN00063089 AR4-91: Support Fr_CancelTxLPdu() API
 -            2012-11-19  ore     ESCAN00063130 Compiler error: Unknown symbol Fr_GetSyncState() when using 3rd party driver
 -  03.11.01  2012-11-22  ore     ESCAN00063247 Compiler error: illegal else without matching in function FrIf_SetState  and unresolved symbol SynchState
 -            2012-11-23  ore     ESCAN00063257 Compiler warning: variable "ChannelAStatus" was declared but never referenced
 -            2012-11-29  ore     ESCAN00063414 Compiler error: function has return type void but a value is returned
 -            2012-12-10  ore     ESCAN00063625 Support of 3rd party FlexRay drivers
 -  03.12.00  2012-11-22  ore     -             AR4-325: Implement Post-Build Loadable
 -            2013-02-19  ore     ESCAN00065217 Incorrect signature for Fr_ControllerInit (has only one parameter in AR4)
 -            2013-03-21  ore     ESCAN00066146 Compiler error: void function "FrIf_GetNumOfStartupFrames" may not return a value
 -            2013-03-28  ore     ESCAN00066295 Compiler error: symbol Fr_AllSlots multiply defined 
 -            2013-04-23  ore     ESCAN00066846 DEM_EVENT_STATUS_PASSED was not reported in FrIf_MainFunction if Fr_GetChannelStatus() returned vSS!ValidFrame
 -            2013-04-23  ore     ESCAN00066853 AR4-220: Remove STATIC 
 -            2013-04-24  ore     ESCAN00066875 Compiler warning: warning C4244: '-=' : conversion from 'int' to 'uint16', possible loss of data
 -            2013-05-06  ore     ESCAN00067162 Compiler warning:  'FrIf_ConfigPtr' : unreferenced formal parameter
 -            2013-05-15  ore     ESCAN00067366 Compiler error: Unknown symbol FrIf_TransceiverDescriptors in post-build variant
 -  03.13.00  2013-07-19  ore     ESCAN00068268 AR4-447: Implement (post-build loadable) flexible RAM management
 -            2013-08-01  ore     ESCAN00069548 Improve AR compatibility by adding <vendor>_<device> infix
 -            2013-09-02  ore     ESCAN00069845 Compiler warning: FrIf_ClstIdx and FrIf_CtrlIdx unreferenced formal parameter
 -            2013-09-16  ore     ESCAN00067721 AR4-328: Predefined Runtime Measurement Points
 -            2013-10-10  ore     ESCAN00071035 Compiler warning: warning C4255: 'FrIf_GetMacroticksPerCycle' : no function 
 *                                              prototype given: converting '()' to '(void)'
 -            2013-10-18  ore     ESCAN00071232 Compiler warning: FrIf_Rx.c; FrIf_Tx.c: narrowing or signed-to-unsigned type conversion found: unsigned int to unsigned char
 -  03.13.01  2014-05-16  ore     ESCAN00075310 Unsent Tx PDUs are not confirmed when the FrIf looses synchronization
 -            2014-05-16  ore     ESCAN00075484 The protected range check in FrIf_JobListExec_0() shall be optional
 -  03.14.00  2014-06-25  ore     ESCAN00076433 Use CPU type optimized data definition types (uintX_least)
 -            2014-07-11  ore     ESCAN00074013 Implement FrIf_Receive and FrIf_TxConfirmation as inline functions
 -            2014-07-14  ore     ESCAN00073229 AR3-2645: Remove second check of joblist out of sync in FrIf_JobListExec_0
 -            2014-10-27  ath     ESCAN00079139 Unnecessary DET error is reported when calling the FrIf_MainFunction of an non-initialized FrIf
 -            2014-11-01  ath     -             AR4-698: Post-Build Selectable (Identity Manager)
 -  03.14.01  2014-11-14  ath     ESCAN00079425 Revision history is not up to date
 -            2014-11-25  ath     ESCAN00079811 Wrong return value when calling FrIf_CancelTransmit before initializing the FrIf
 -  04.00.00  2015-02-09  ath     ESCAN00080653 Wrong preprocessor defines used to create "FrIf_Dem_ReportError_*" APIs
 -            2015-03-04  ath     ESCAN00081608 Increase only the necessary PDU request counters during a Tx rollback
 -            2015-05-13  ath     ESCAN00082019 Fixed invalid memory access when redundant frames where not received
 -            2015-05-13  ath     ESCAN00082367 Fixed Rx of dynamic-length frames with more than 1 PDU
 -            2015-05-13  ath     ESCAN00082393 Use the actual length of the received redundant frames
 -            2015-05-13  ath     ESCAN00082957 Fixed the Tx rollback of redundant frames
 -            2015-06-12  ath     ESCAN00083360 Enable the job list execution and flag the FrIf as online atomically
 -  05.00.00  2015-09-11  ath     ESCAN00079561 Removed unnecessary structs with a single member
 -            2015-10-12  ath     ESCAN00085795 FrIf_GetMacrotickDuration reports DET error with wrong ServiceID
 -            2015-10-16  ath     ESCAN00085934 A NULL_PTR exception occurs in case FrIf_GetCycleLength() is called before initialization
 -            2015-11-13  ath     ESCAN00086041 Clear the WasSentFlags before calling the TxConfirmation functions
 -  05.00.01  2016-02-23  ath     ESCAN00088502 Generate the FrIf_Types.h file
 -            2016-02-29  ath     ESCAN00087836 Trigger Transmit API with SduLength In/Out according to ASR4.2.2
 -  05.00.02  2016-04-21  ath     ESCAN00087809 FEAT-1688: SafeBSW Step 4
 -            2016-05-04  ath     ESCAN00089885 Recognize elapsed points in time between cycles 63 and 0
 -  05.00.03  2016-07-26  ath     ESCAN00090810 Compiler warning: 'JobStartTime' : variable is initialized but not referenced
 -  05.01.00  2016-11-21  ath     ESCAN00081059 Cancel the Tx of PDUs which are not the first PDU-in-frame
 -            2017-02-23  ath     FEATC-1077    Support 2 FlexRay controllers
 -  05.01.01  2017-04-27  ath     ESCAN00094906 Fixed macros causing memory corruption in FrIf_InitializeTransmission
 -            2017-06-22  ore     ESCAN00095593 DEM events of a second FrIfCluster are reported with the wrong event ID.
 -  05.01.02  2017-10-04  ath     ESCAN00095968 C4189: 'JobDataPtr' : local variable is initialized but not referenced
 *********************************************************************************************************************/

#if (!defined  FRIF_H_)
# define FRIF_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Lcfg.h"    /* Includes FrIfTypes and therewith: ComStack_Types.h and FrIf_Cfg.h */
# include "FrIf_PBCfg.h"   

# if (FRIF_API_AS_MACRO == STD_ON)
#  include "Fr.h"
# endif

/*lint -{652} */ /* Suppress ID652 because function symbols are re-defined due to single controller optimization */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define FRIF_VENDOR_ID                           (30u)
# define FRIF_MODULE_ID                           (0x3Du)

/* Component version information (decimal version of ALM implementation package) */
# define FRIF_SW_MAJOR_VERSION                    (5u)
# define FRIF_SW_MINOR_VERSION                    (1u)
# define FRIF_SW_PATCH_VERSION                    (2u)

/* AUTOSAR software specification version information */
# define FRIF_AR_RELEASE_MAJOR_VERSION            (4u)
# define FRIF_AR_RELEASE_MINOR_VERSION            (0u)
# define FRIF_AR_RELEASE_REVISION_VERSION         (3u)

/* Generator compatibility */
#define FRIF_GENERATOR_COMPATIBILITY_VERSION      ((uint16)0x0001u) /* UREQ00035482 */

/* Magic number the configuration structure */
#define FRIF_FINAL_MAGICNUMBER                    ((uint16)0x6142u) /* UREQ00035483 */

/* API service IDs */
# define FRIF_SID_RECONFIG_LPDU                     (uint8)0x00u /**< ASR4.0 FrIf_ReconfigLPdu() service ID */
# define FRIF_SID_GETVERSIONINFO                    (uint8)0x01u /**< ASR3.2+ASR4.0 FrIf_GetVersionInfo() service ID */
# define FRIF_SID_INIT                              (uint8)0x02u /**< ASR3.2+ASR4.0 FrIf_Init() service ID */
# define FRIF_SID_CONTROLLERINIT                    (uint8)0x03u /**< ASR3.2+ASR4.0 FrIf_ControllerInit() service ID */
# define FRIF_SID_STARTCOMMUNICATION                (uint8)0x04u /**< ASR4.0 FrIf_StartCommunication() service ID */
# define FRIF_SID_HALTCOMMUNICATION                 (uint8)0x05u /**< ASR4.0 FrIf_HaltCommunication() service ID */
# define FRIF_SID_ABORTCOMMUNICATION                (uint8)0x06u /**< ASR4.0 FrIf_AbortCommunication() service ID */
# define FRIF_SID_GETSTATE                          (uint8)0x07u /**< ASR4.0 FrIf_GetState() service ID */
# define FRIF_SID_SETSTATE                          (uint8)0x08u /**< ASR4.0 FrIf_SetState() service ID because ASR3.2.1 ID overlaps with FrIf_GetState() */
# define FRIF_SID_SETWAKEUPCHANNEL                  (uint8)0x09u /**< ASR4.0 FrIf_SetWakeupChannel() service ID */
# define FRIF_SID_SENDWUP                           (uint8)0x0Au /**< ASR4.0 FrIf_SendWUP() service ID */
# define FRIF_SID_GETPOCSTATUS                      (uint8)0x0Du /**< ASR4.0 FrIf_GetPOCStatus() service ID */
# define FRIF_SID_GETGLOBALTIME                     (uint8)0x0Eu /**< ASR4.0 FrIf_GetGlobalTime() service ID */
# define FRIF_SID_GETNMVECTOR                       (uint8)0x0Fu /**< ASR4.0 FrIf_GetNmVector() service ID */
# define FRIF_SID_ALLOWCOLDSTART                    (uint8)0x10u /**< ASR4.0 FrIf_AllowColdstart() service ID */
# define FRIF_SID_GETMACROTICKSPERCYCLE             (uint8)0x11u /**< ASR4.0 FrIf_GetMacroticksPerCycle() service ID */
# define FRIF_SID_TRANSMIT                          (uint8)0x12u /**< ASR4.0 FrIf_Transmit() service ID */
# define FRIF_SID_SETTRANSCEIVERMODE                (uint8)0x13u /**< ASR4.0 FrIf_SetTransceiverMode() service ID */
# define FRIF_SID_GETTRANSCEIVERMODE                (uint8)0x14u /**< ASR4.0 FrIf_GetTransceiverMode() service ID */
# define FRIF_SID_GETTRANSCEIVERWUREASON            (uint8)0x15u /**< ASR4.0 FrIf_GetTransceiverWUReason() service ID */
# define FRIF_SID_CLEARTRANSCEIVERWAKEUP            (uint8)0x18u /**< ASR4.0 FrIf_ClearTransceiverWakeup() service ID */
# define FRIF_SID_SETABSOLUTETIMER                  (uint8)0x19u /**< ASR4.0 FrIf_SetAbsoluteTimer() service ID */
# define FRIF_SID_CANCELABSOLUTETIMER               (uint8)0x1Bu /**< ASR4.0 FrIf_CancelAbsoluteTimer() service ID */
# define FRIF_SID_ENABLEABSOLUTETIMERIRQ            (uint8)0x1Du /**< ASR4.0 FrIf_EnableAbsoluteTimerIRQ() service ID */
# define FRIF_SID_GETABSOLUTETIMERIRQSTATUS         (uint8)0x1Fu /**< ASR4.0 FrIf_GetAbsoluteTimerIRQStatus() service ID */
# define FRIF_SID_ACKABSOLUTETIMERIRQ               (uint8)0x21u /**< ASR4.0 FrIf_AckAbsoluteTimerIRQ() service ID */
# define FRIF_SID_DISABLEABSOLUTETIMERIRQ           (uint8)0x23u /**< ASR4.0 FrIf_DisableAbsoluteTimerIRQ() service ID */
# define FRIF_SID_GET_CHANNEL_STATUS                (uint8)0x26u /**< ASR4.0 FrIf_GetChannelStatus() service ID */
# define FRIF_SID_MAINFUNCTION                      (uint8)0x27u /**< ASR4.0 FrIf_MainFunction() service ID */
# define FRIF_SID_DISABLE_LPDU                      (uint8)0x28u /**< ASR4.0 FrIf_DisableLPdu() service ID */
# define FRIF_SID_GET_CLOCK_CORRECTION              (uint8)0x29u /**< ASR3.2+ASR4.0 FrIf_GetClockCorrection() service ID */
# define FRIF_SID_GETSYNCFRAMELISTSUPPORT           (uint8)0x2Au /**< ASR4.0 FrIf_GetSyncFrameList() service ID */
# define FRIF_SID_GETWAKEUPRXSTATUS                 (uint8)0x2Bu /**< ASR4.0 FrIf_GetWakeupRxStatus() service ID */
# define FRIF_SID_CANCEL_TRANSMIT                   (uint8)0x30u /**< ASR4.0 FrIf_CancelTransmit() service ID */
# define FRIF_SID_GETMACROTICKDURATION              (uint8)0x31u /**< ASR4.0 FrIf_GetMacrotickDuration() service ID */
# define FRIF_SID_JOBLISTEXEC                       (uint8)0x32u /**< ASR3.2+ASR4.0 FrIf_JobListExec() service ID */
# define FRIF_SID_ALLSLOTS                          (uint8)0x33u /**< ASR4.0 FrIf_AllSlots() service ID */
# define FRIF_SID_GETNUMOFSTARTUPFRAMES             (uint8)0x34u /**< ASR4.0 FrIf_GetNumOfStartupFrames() service ID */
# define FRIF_SID_GET_TRANSCEIVER_ERROR             (uint8)0x35u /**< ASR4.0 FrIf_GetTransceiverError() service ID */
# define FRIF_SID_ENABLETRANSCEIVERWAKEUP           (uint8)0x36u /**< ASR4.0 FrIf_EnableTransceiverBranch() service ID */
# define FRIF_SID_DISABLETRANSCEIVERWAKEUP          (uint8)0x37u /**< ASR4.0 FrIf_DisableTransceiverBranch() service ID */
# define FRIF_SID_CBK_WAKEUPBYTRANSCEIVER           (uint8)0x39u /**< ASR4.0 FrIf_CheckWakeupByTransceiver() service ID */
# define FRIF_SID_GET_CYCLE_LENGTH                  (uint8)0x3Au /**< ASR3.2+ASR4.0 FrIf_GetCycleLength() service ID */
# define FRIF_SID_READCCCONFIG                      (uint8)0x3Bu /**< ASR4.0 FrIf_ReadCCConfig() service ID */

/* service ids for internal FrIf functions */
# define FRIF_SID_EXEC_CURRENT_JOB                  (uint8)0x40u /**< internal FrIf_ExecCurrentJob() service ID */
# define FRIF_SID_TRIGGER_TRANSMIT_FCTS             (uint8)0x41u /**< internal FrIf_TriggerTransmitFunctions() service ID */
# define FRIF_SID_TX_CONFIRMATION_FCTS              (uint8)0x42u /**< internal FrIf_TxConfirmationFunctions() service ID */
# define FRIF_SID_RX_INDICATION_FCTS                (uint8)0x43u /**< internal FrIf_RxIndicationFunctions() service ID */

# define FRIF_CTRL_IDX_MAX_SUPPORTED 0 /**< Maximum number-1 of FlexRay CCs that the FlexRay Interface supports */
# define FRIF_CLST_IDX_MAX_SUPPORTED 0 /**< Maximum number-1 of FlexRay Clusters that the FlexRay Interface supports */

/* FrIf_GetChannelStatus bit masks */
# define FRIF_ACS_VALID_FRAME     (uint16)0x0001u
# define FRIF_ACS_SYNTAX_ERROR    (uint16)0x0002u
# define FRIF_ACS_CONTENT_ERROR   (uint16)0x0004u
# define FRIF_ACS_ADDITIONAL_COMM (uint16)0x0008u
# define FRIF_ACS_B_VIOLATION     (uint16)0x0010u
# define FRIF_ACS_TX_CONFLICT     (uint16)0x0020u
# define FRIF_SW_VALID_MTS        (uint16)0x0100u
# define FRIF_SW_SYNTAX_ERROR     (uint16)0x0200u
# define FRIF_SW_B_VIOLATION      (uint16)0x0400u
# define FRIF_SW_TX_CONFLICT      (uint16)0x0800u
# define FRIF_NIT_SYNTAX_ERROR    (uint16)0x1000u
# define FRIF_NIT_B_VIOLATION     (uint16)0x2000u

/* Single Controller API optimization */
# if ( STD_ON == FRIF_CTRL_ENABLE_API_OPTIMIZATION)
#  define FRIF_VCTRL_ENABLE_API_OPTIMIZATION   STD_ON

/* PRQA S 3460 1 */ /*  MD_MSR_19.4 */
#  define FRIF_VCTRL_ONLY     void
#  define FRIF_VCTRL_FIRST
#  define FRIF_VCTRL_IDX      0u

/* PRQA S 3460 1 */ /*  MD_MSR_19.4 */
#  define FRIF_VCLST_ONLY     void
#  define FRIF_VCLST_FIRST
#  define FRIF_VCLST_IDX      0u
#  define FRIF_VCLST_OPT
# else
#  define FRIF_VCTRL_ENABLE_API_OPTIMIZATION   STD_OFF

#  define FRIF_VCTRL_ONLY     uint8 FrIf_CtrlIdx
#  define FRIF_VCTRL_FIRST    uint8 FrIf_CtrlIdx,
#  define FRIF_VCTRL_IDX      FrIf_CtrlIdx

#  define FRIF_VCLST_ONLY     uint8 FrIf_ClstIdx
#  define FRIF_VCLST_FIRST    uint8 FrIf_ClstIdx,
#  define FRIF_VCLST_IDX      FrIf_ClstIdx
#  define FRIF_VCLST_OPT      FrIf_ClstIdx
# endif
  /* ( STD_ON == FRIF_CTRL_ENABLE_API_OPTIMIZATION) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrIf_InitMemory
**********************************************************************************************************************/
/*!
 *
 * \brief        Initializes variables at power up.
 * \details      Initializes module global variables in *_INIT_* sections at power up. Used if they are not initialized
 *               by the startup code.
 * \pre          The FrIf hasn't been initialized.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-1222
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_InitMemory(void);

/**********************************************************************************************************************
  FrIf_Init
**********************************************************************************************************************/
/*!
 *
 * \brief        Initializes the FlexRay Interface.
 * \details      Flags the FrIf as initialized and offline, resets transmission-related flags/counters and flags the
 *               job list execution as disabled.
 * \param[in]    FrIf_ConfigPtr    Pointer to the configuration structure of the FrIf.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-1222
 * \trace        SPEC-29877
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_Init(FRIF_P2CONSTCFGROOT(FrIf_ConfigType) FrIf_ConfigPtr);

/**********************************************************************************************************************
  FrIf_MainFunction
**********************************************************************************************************************/
/*!
 *
 * \brief        Monitors and controls the continuous execution of the FlexRay Job List Execution Function.
 * \details      Monitors the proper (in time) execution of the FrIf_JobListExec() of the same cluster and resynchronize 
 *               the Joblist if necessary. 
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_MainFunction(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_MainFunction_0
**********************************************************************************************************************/
/*!
 *
 * \fn           void FrIf_MainFunction_0(void)
 * \brief        Cyclically executed API service of the FlexRay Interface for FrIf cluster 0.
 * \details      This function will be called cyclically by a task body provided by the BSW Scheduler for the FlexRay 
 *               Cluster with index 0. 
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-30018, SPEC-30044, SPEC-29825
 * \ingroup      Generic
 *********************************************************************************************************************/
/*  extern FUNC(void, FRIF_CODE) FrIf_MainFunction_0(void); - declared by SchM.h */

/**********************************************************************************************************************
  FrIf_MainFunction_1
**********************************************************************************************************************/
/*!
 *
 * \fn           void FrIf_MainFunction_1(void)
 * \brief        Cyclically executed API service of the FlexRay Interface for FrIf cluster 1.
 * \details      This function will be called cyclically by a task body provided by the BSW Scheduler for the FlexRay 
 *               Cluster with index 1. 
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-30018, SPEC-30044, SPEC-29825
 * \config       Available only if FrIf_CommonMaxNumberOfClusters > 1.
 * \ingroup      Generic
 *********************************************************************************************************************/
/*  extern FUNC(void, FRIF_CODE) FrIf_MainFunction_1(void); - declared by SchM.h */

/**********************************************************************************************************************
  FrIf_SetState
**********************************************************************************************************************/
/*!
 *
 * \brief        Requests a transition of the FrIf state machine for a given FlexRay cluster.
 * \details      Enables the job list execution and flags the FrIf as online, or disables the job list execution and
 *               flags the FrIf as offline, depending on the requested transition.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_State      Requested FrIf state transition.
 * \return       E_OK            Transition request succeeded.
 * \return       E_NOT_OK        Transition request failed or an error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-1228
 * \trace        SPEC-29923
 * \ingroup      StateH
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetState(FRIF_VCLST_FIRST
                                                    FrIf_StateTransitionType  FrIf_State);

/**********************************************************************************************************************
  FrIf_GetState
**********************************************************************************************************************/
/*!
 *
 * \brief        Retrieves the current state of the FrIf state machine for a given FlexRay cluster.
 * \details      -
 * \param[in]    FrIf_CtrlIdx     Index of the cluster to be addressed. 
 *                                This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_StatePtr    Pointer to a memory location were the current state shall be stored.
 * \return       E_OK             The current state was successfully retrieved.
 * \return       E_NOT_OK         An error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    TRUE
 * \synchronous  TRUE
 * \trace        CREQ-1227
 * \trace        SPEC-29976
 * \ingroup      StateH
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetState(FRIF_VCLST_FIRST
                                                    P2VAR(FrIf_StateType, AUTOMATIC, FRIF_APPL_DATA) FrIf_StatePtr);
     
/**********************************************************************************************************************
  FrIf_GetMacroticksPerCycle
**********************************************************************************************************************/
/*!
 *
 * \brief        Retrieves the amount of macrotricks per FlexRay cycle for a given FlexRay CC.
 * \details      Retrieves the configured amount of macroticks per FlexRay cycle for a given FlexRay CC.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       The number of macroticks per cycle.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    TRUE
 * \synchronous  TRUE
 * \trace        CREQ-105565
 * \trace        SPEC-29882
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksPerCycle(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_GetMacrotickDuration
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns the duration of a macrotick in nanoseconds.
 * \details      Returns the configured duration of a macrotick in nanoseconds.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       The duration of a macrotick in nanoseconds.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    TRUE
 * \synchronous  TRUE
 * \trace        CREQ-105565
 * \trace        SPEC-30036
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(uint16, FRIF_CODE) FrIf_GetMacrotickDuration(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_JobListExec
**********************************************************************************************************************/
/*!
 *
 * \brief        Executes the current FlexRay job and sets the timer for its next call.
 * \details      Executes the current FlexRay job and sets the timer based on the start of the next job. If
 *               FRIF_JOB_CONCATENATION_ENABLE == STD_ON, concatenates jobs before setting the timer. If
 *               FRIF_MEASURE_JLETASKTIMES == STD_ON, tracks the delays of the job list execution. If
 *               FRIF_SUPPRESS_PROTECTED_RANGE_CHECK == STD_OFF, verifies that jobs occur outside their protected range.
 * \param[in]    FrIf_ClstIdx    Index of the cluster to be addressed. 
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-30175
 * \ingroup      PDU
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_JobListExec(FRIF_VCLST_ONLY);

/**********************************************************************************************************************
  FrIf_JobListExec_0
**********************************************************************************************************************/
/*!
 *
 * \brief        Executes the job list for FrIf cluster 0.
 * \details      Processes the FlexRay Job List of the FlexRay Cluster with index 0. 
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-8444, SPEC-29859, SPEC-30003, SPEC-30182
 * \ingroup      PDU
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_JobListExec_0(void);

# if (FrIf_CommonMaxNumberOfClusters > 1)
/**********************************************************************************************************************
  FrIf_JobListExec_1
**********************************************************************************************************************/
/*!
 *
 * \brief        Executes the job list for FrIf cluster 1.
 * \details      Processes the FlexRay Job List of the FlexRay Cluster with index 1. 
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-8444, SPEC-29859, SPEC-30003, SPEC-30182
 * \config       Available only if FrIf_CommonMaxNumberOfClusters > 1.
 * \ingroup      PDU
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_JobListExec_1(void);
# endif

# if (FRIF_CANCELTRANSMITSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_CancelTransmit
**********************************************************************************************************************/
/*!
 *
 * \brief        Cancels the transmission of a PDU.
 * \details      Cancels the transmission of any frames containing the PDU. It also flags the PDU as non-dirty and sets
 *               its request counter to 0 (only if FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF).
 * \param[in]    FrTxPduId    ID of the FlexRay PDU to be cancelled. It shall be used as array index without any
 *                            modifications.
 * \return       E_OK         The transmission of the PDU was successfully cancelled or the PDU had already been sent.
 * \return       E_NOT_OK     An error occurred when requesting the cancellation of a frame to the Fr.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105574
 * \trace        SPEC-29987, SPEC-29968
 * \config       Available only if FRIF_CANCELTRANSMITSUPPORT == STD_ON. \trace SPEC-30148
 * \ingroup      PDU
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelTransmit(PduIdType FrTxPduId);
# endif /* (FRIF_CANCELTRANSMITSUPPORT == STD_ON) */

# if (FRIF_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  FrIf_GetVersionInfo
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns version information of the module.
 * \details      Returns version and vendor information of the module.
 * \param[out]   FrIf_VersionInfoPtr    Pointer to a memory location where output will be stored.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    TRUE
 * \synchronous  TRUE
 * \trace        CREQ-105564
 * \trace        SPEC-29978
 * \config       Available only if FRIF_VERSION_INFO_API == STD_ON. \trace SPEC-29951, SPEC-29847, SPEC-30072
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(void, FRIF_CODE) FrIf_GetVersionInfo(
                                            P2VAR(Std_VersionInfoType, AUTOMATIC, FRIF_APPL_DATA) FrIf_VersionInfoPtr);
# endif /* (FRIF_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
  FrIf_Transmit
**********************************************************************************************************************/
/*!
 *
 * \brief        Requests the transmission of a PDU.
 * \details      Requests the transmission of the frame containing the PDU to the Fr, if the PDU is configured as
 *               immediate. Otherwise, flags the PDU as dirty and increases its request counter (if
 *               FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF), so it's processed within the job list execution.
 * \param[in]    FrTxPduId     ID of the FlexRay PDU to be requested for transmission. It shall be used as array index
 *                             without any modifications.
 * \param[in]    PduInfoPtr    Pointer to a struct containing a pointer to the PDU's payload and its length.
 * \return       E_OK          The PDU has been successfully requested for transmission.
 * \return       E_NOT_OK      A problem occurred when requesting the transmission of the frame containing the PDU to
 *                             the Fr, or the PDU's request counter overflowed.
 * \pre          The FrIf must be in state FRIF_STATE_ONLINE.
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        SPEC-29994, SPEC-30181, SPEC-30141
 * \ingroup      PDU 
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_Transmit(PduIdType           FrTxPduId,
                                                     FRIF_P2CONSTAPPLDATA(PduInfoType) PduInfoPtr);

# if (FRIF_API_AS_MACRO == STD_OFF)

# if (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_GetNumOfStartupFrames
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the current number of startup frames seen on the cluster for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetNumOfStartupFrames.
 * \param[in]    FrIf_CtrlIdx                  Index of the FlexRay CC to address. 
 *                                             This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_NumOfStartupFramesPtr    Pointer to a memory location where the number of startup frames within
 *                                             the last even/odd cycle pair shall be stored. The pointer shall be
 *                                             forwarded by the FrIf without any modifications.
 * \return       E_OK                          The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                      The call of the FlexRay Driver's API service has returned E_NOT_OK, or
 *                                             an error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-29828
 * \config       Available only if FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON. \trace SPEC-29975
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE)FrIf_GetNumOfStartupFrames(FRIF_VCTRL_FIRST 
                                                P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NumOfStartupFramesPtr);
# endif /* (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON) */

#if (FRIF_ALLSLOTSSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_AllSlots
**********************************************************************************************************************/
/*!
 *
 * \brief        Switches from key slot only mode to all slots transmission mode for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_AllSlots.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-29935
 * \config       Available only if FRIF_ALLSLOTSSUPPORT == STD_ON. \trace SPEC-30066
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE)FrIf_AllSlots(FRIF_VCTRL_ONLY);
# endif /* (FRIF_ALLSLOTSSUPPORT == STD_ON)  */

#if (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_GetWakeupRxStatus 
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the received wake-up information for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetWakeupRxStatus.
 * \param[in]    FrIf_CtrlIdx              Index of the FlexRay CC to address.
 *                                         This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF
 * \param[in]    FrIf_WakeupRxStatusPtr    Pointer to a memory location where the bit coded wakeup reception status
 *                                         shall be stored. The pointer shall be forwarded by the FrIf without any
 *                                         modifications.
 *                                         Bit 0: Wakeup received on channel A indicator.
 *                                         Bit 1: Wakeup received on channel B indicator.
 *                                         Bit 2-7: Unused.
 * \return       E_OK                      The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                  The call of the FlexRay Driver's API service has returned E_NOT_OK, or an
 *                                         error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105569
 * \trace        SPEC-30028
 * \config       Available only if FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON. \trace SPEC-30116
 * \ingroup      Wakeup
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE)FrIf_GetWakeupRxStatus (FRIF_VCTRL_FIRST 
                                                P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_WakeupRxStatusPtr);
# endif /* (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON) */

/**********************************************************************************************************************
  FrIf_GetCycleLength
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns the duration of a FlexRay cycle in nanoseconds for a given FlexRay CC.
 * \details      Returns the configured duration of a FlexRay cycle in nanoseconds.
 * \param[in]    FrIf_CtrlIdx   Index of the FlexRay CC to address.
 *                              This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       Duration of a FlexRay cycle in nanoseconds.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105565
 * \trace        SPEC-29998
 * \ingroup      Generic
 *********************************************************************************************************************/
     extern FUNC(uint32, FRIF_CODE) FrIf_GetCycleLength(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_ControllerInit
**********************************************************************************************************************/
/*!
 *
 * \brief        Initializes a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_ControllerInit.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-29979
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ControllerInit(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_StartCommunication
**********************************************************************************************************************/
/*!
 *
 * \brief        Initiates the startup procedure for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_StartCommunication.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-30060
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_StartCommunication(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_HaltCommunication
**********************************************************************************************************************/
/*!
 *
 * \brief        Stops the communication for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_HaltCommunication.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  FALSE
 * \trace        CREQ-105567
 * \trace        SPEC-29904
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_HaltCommunication(FRIF_VCTRL_ONLY);

#  if (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF)
/**********************************************************************************************************************
  FrIf_AbortCommunication
**********************************************************************************************************************/
/*!
 *
 * \brief        Immediately aborts the communication for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_AbortCommunication.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-29867
 * \config       Available only if FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF.
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AbortCommunication(FRIF_VCTRL_ONLY);
#  endif

/**********************************************************************************************************************
  FrIf_SendWUP
**********************************************************************************************************************/
/*!
 *
 * \brief        Initiates the wake-up transmission procedure for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_SendWUP.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105569
 * \trace        SPEC-30083
 * \ingroup      Wakeup
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SendWUP(FRIF_VCTRL_ONLY);

#  if (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
/**********************************************************************************************************************
  FrIf_SetWakeupChannel
**********************************************************************************************************************/
/*!
 *
 * \brief        Sets a wake-up channel for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_SetWakeupChannel.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx    Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                               FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105569
 * \trace        SPEC-30124
 * \config       Available only if FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF.
 * \ingroup      Wakeup
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetWakeupChannel(FRIF_VCTRL_FIRST Fr_ChannelType  FrIf_ChnlIdx);
#  endif /* (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF) */

/**********************************************************************************************************************
  FrIf_AllowColdstart
**********************************************************************************************************************/
/*!
 *
 * \brief        Invokes the CC CHI command 'ALLOW_COLDSTART' for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_AllowColdstart.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-30105
 * \ingroup      ComC
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AllowColdstart(FRIF_VCTRL_ONLY);

/**********************************************************************************************************************
  FrIf_GetPOCStatus
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns the POC status for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetPOCStatus.
 * \param[in]    FrIf_CtrlIdx         Index of the FlexRay CC to address.
 *                                    This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_POCStatusPtr    Pointer to a memory location where output value will be stored. The pointer shall
 *                                    be forwarded by the FrIf without any modifications.
 * \return       E_OK                 The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK             The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                    has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105567
 * \trace        SPEC-30188
 * \ingroup      CCS
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetPOCStatus(FRIF_VCTRL_FIRST
                                                P2VAR(Fr_POCStatusType, AUTOMATIC, FRIF_APPL_DATA) FrIf_POCStatusPtr);

#  if (FRIF_CHANNEL_STATUS_ENABLE == STD_ON)
/**********************************************************************************************************************
  FrIf_GetChannelStatus
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets channel status information for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetChannelStatus.
 * \param[in]    FrIf_CtrlIdx              Index of the FlexRay CC to address.
 *                                         This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChannelAStatusPtr    Pointer to a memory location where the bit coded channel A status information
 *                                         shall be stored. The pointer shall be forwarded by the FrIf without any
 *                                         modifications.
 * \param[in]    FrIf_ChannelBStatusPtr    Pointer to a memory location where the bit coded channel B status information
                                           shall be stored. The pointer shall be forwarded by the FrIf without any
 *                                         modifications.
 * \return       E_OK                      The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                  The call of the FlexRay Driver's API service has returned E_NOT_OK, or an
 *                                         error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-30202
 * \config       Available only if FRIF_CHANNEL_STATUS_ENABLE == STD_ON. \trace SPEC-8335
 * \ingroup      CCS
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetChannelStatus(FRIF_VCTRL_FIRST
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAStatusPtr,
                                                      P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBStatusPtr);
#  endif /* (FRIF_CHANNEL_STATUS_ENABLE == STD_ON) */

#  if (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON)
/**********************************************************************************************************************
  FrIf_GetClockCorrection
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the current clock correction values for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetClockCorrection.
 * \param[in]    FrIf_CtrlIdx                Index of the FlexRay CC to address.
 *                                           This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[out]   FrIf_RateCorrectionPtr      Pointer to a memory location where output value will be stored. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \param[out]   FrIf_OffsetCorrectionPtr    Pointer to a memory location where output value will be stored. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \return       E_OK                        The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                    The call of the FlexRay Driver's API service has returned E_NOT_OK, or an
 *                                           error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-8250
 * \config       Available only if FRIF_CLOCK_CORRECTION_ENABLE == STD_ON. \trace SPEC-8412
 * \ingroup      CCS
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetClockCorrection(FRIF_VCTRL_FIRST
                                                   P2VAR(sint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_RateCorrectionPtr,
                                                   P2VAR(sint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_OffsetCorrectionPtr);
#  endif /* (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON) */

#  if (FRIF_NMVECTORSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_GetNmVector
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the network management vector for a given FlexRay CC.
 * \details      Wraps the FlexRay Driver API function Fr_GetNmVector.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[out]   FrIf_NmVectorPtr    Pointer to a memory location where output value will be stored. The pointer shall
 *                                   be forwarded by the FrIf without any modifications.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-29894
 * \config       Available only if FRIF_NMVECTORSUPPORT == STD_ON. \trace SPEC-29849
 * \ingroup      CCS
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetNmVector(FRIF_VCTRL_FIRST
                                                       P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_NmVectorPtr);
#  endif /* (FRIF_NMVECTORSUPPORT == STD_ON) */

#  if (FRIF_READCCCONFIGSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_ReadCCConfig
**********************************************************************************************************************/
/*!
 *
 * \brief        Reads a FlexRay protocol configuration parameter for a given FlexRay CC from the module configuration.
 * \details      Wraps the FlexRay Driver API function Fr_ReadCCConfig.
 * \param[in]    FrIf_CtrlIdx           Index of the FlexRay CC to address.
 *                                      This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_CCLLParamIndex    Index of the configuration parameter to read.
 * \param[out]   FrIf_CCLLParamValue    Pointer to a memory location where output value will be stored. The pointer
 *                                      shall be forwarded by the FrIf without any modifications.
 * \return       E_OK                   The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK               The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                      has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-30026
 * \config       Available only if FRIF_READCCCONFIGSUPPORT == STD_ON.
 * \ingroup      CCS
 *********************************************************************************************************************/
    extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ReadCCConfig(FRIF_VCTRL_FIRST
                                                          uint8 FrIf_CCLLParamIndex,
                                                          P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_CCLLParamValue);
#  endif /* (FRIF_READCCCONFIGSUPPORT == STD_ON) */

#  if (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_GetSyncFrameList
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets a list of sync frames received or transmitted on channel A and channel B via the even and odd
                 communication cycle.
 * \details      Wraps the FlexRay Driver API function Fr_GetSyncFrameList.
 * \param[in]    FrIf_CtrlIdx                Index of the FlexRay CC to address.
 *                                           This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF
 * \param[in]    FrIf_ListSize               Size of the arrays passed via parameters: FrIf_ChannelAEvenListPtr,
 *                                           FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr and
 *                                           FrIf_ChannelBOddListPtr. The service must ensure not to write more entries
 *                                           into those arrays than granted by this parameter.
 * \param[in]    FrIf_ChannelAEvenListPtr    Address the list of sync frames on channel A within the even communication
 *                                           cycle is written to. The exact number of elements written to the list is
 *                                           limited by parameter FrIf_ListSize. Unused list elements are filled with
 *                                           the value '0' to indicate that no more sync frame has been seen. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \param[in]    FrIf_ChannelBEvenListPtr    Address the list of sync frames on channel B within the even communication
 *                                           cycle is written to. The exact number of elements written to the list is
 *                                           limited by parameter FrIf_ListSize. Unused list elements are filled with
 *                                           the value '0' to indicate that no more sync frame has been seen. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \param[in]    FrIf_ChannelAOddListPtr     Address the list of sync frames on channel A within the odd communication
 *                                           cycle is written to. The exact number of elements written to the list is
 *                                           limited by parameter FrIf_ListSize. Unused list elements are filled with
 *                                           the value '0' to indicate that no more sync frame has been seen. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \param[in]    FrIf_ChannelBOddListPtr     Address the list of sync frames on channel B within the odd communication
 *                                           cycle is written to. The exact number of elements written to the list is
 *                                           limited by parameter FrIf_ListSize. Unused list elements are filled with
 *                                           the value '0' to indicate that no more sync frame has been seen. The
 *                                           pointer shall be forwarded by the FrIf without any modifications.
 * \return       E_OK                        The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                    The call of the FlexRay Driver's API service has returned E_NOT_OK, or an
 *                                           error has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-30191
 * \config       Available only if FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON. \trace SPEC-30187
 * \ingroup      CCS
 *********************************************************************************************************************/
      extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetSyncFrameList(FRIF_VCTRL_FIRST 
                                                  uint8 FrIf_ListSize,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAEvenListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBEvenListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelAOddListPtr,
                                                  P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_ChannelBOddListPtr );
#  endif /* (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON) */

#  if (FRIF_RECONFIGLPDUSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_ReconfigLPdu
**********************************************************************************************************************/
/*!
 *
 * \brief        Reconfigures a given LPdu at runtime.
 * \details      Wraps the FlexRay Driver API function Fr_ReconfigLPdu.
 * \param[in]    FrIf_CtrlIdx            Index of the FlexRay CC to address.
 *                                       This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF
 * \param[in]    FrIf_LPduIdx            Index of the FlexRay frame to be reconfigured.
 * \param[in]    FrIf_FrameId            FlexRay Frame ID the FrIf_LPdu shall be configured to (slot).
 * \param[in]    FrIf_ChnlIdx            FlexRay Channel the FrIf_LPdu shall be configured to. The enum value
 *                                       "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[in]    FrIf_CycleRepetition    Cycle Repetition part of the cycle filter mechanism the FrIf_LPdu shall be
 *                                       configured to.
 * \param[in]    FrIf_CycleOffset        Cycle Offset part of the cycle filter mechanism the FrIf_LPdu shall be
 *                                       configured to.
 * \param[in]    FrIf_PayloadLength      Payload length in bytes the FrIf_LPdu shall be configured to.
 * \param[in]    FrIf_HeaderCRC          Header CRC the FrIf_LPdu shall be configured to.
 * \return       E_OK                    The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK                The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                       has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105568
 * \trace        SPEC-29945
 * \config       Available only if FRIF_RECONFIGLPDUSUPPORT == STD_ON. \trace SPEC-29942
 * \ingroup      FrR
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ReconfigLPdu(FRIF_VCTRL_FIRST
                                                  uint16 FrIf_LPduIdx,
                                                  uint16 FrIf_FrameId,
                                                  Fr_ChannelType FrIf_ChnlIdx,
                                                  uint8 FrIf_CycleRepetition,
                                                  uint8 FrIf_CycleOffset,
                                                  uint8 FrIf_PayloadLength,
                                                  uint16 FrIf_HeaderCRC);
#  endif /* (FRIF_RECONFIGLPDUSUPPORT == STD_ON) */

#  if (FRIF_DISABLELPDUSUPPORT == STD_ON)
/**********************************************************************************************************************
  FrIf_DisableLPdu
**********************************************************************************************************************/
/*!
 *
 * \brief        Disables the hardware resource of a given LPdu.
 * \details      Wraps the FlexRay Driver API function Fr_DisableLPdu.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_LPduIdx    Index of the FlexRay frame to be disabled.
 * \return       E_OK            The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error has
 *                               been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105568
 * \trace        SPEC-30139
 * \config       Available only if FRIF_DISABLELPDUSUPPORT == STD_ON. \trace SPEC-30121
 * \ingroup      FrR
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableLPdu(FRIF_VCTRL_FIRST uint16 FrIf_LPduIdx);
#  endif /* (FRIF_DISABLELPDUSUPPORT == STD_ON) */

/**********************************************************************************************************************
  FrIf_GetGlobalTime
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the current global FlexRay time.
 * \details      Wraps the FlexRay Driver API function Fr_GetGlobalTime.
 * \param[in]    FrIf_CtrlIdx         Index of the FlexRay CC to address.
 *                                    This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[out]   FrIf_CyclePtr        Pointer to a memory location where the output value will be stored. The pointer
 *                                    shall be forwarded by the FrIf without any modifications.
 * \param[out]   FrIf_MacroTickPtr    Pointer to a memory location where the output value will be stored. The pointer
 *                                    shall be forwarded by the FrIf without any modifications.
 * \return       E_OK                 The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK             The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                    has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105570
 * \trace        SPEC-30103
 * \ingroup      CCS
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetGlobalTime(FRIF_VCTRL_FIRST
                                                         P2VAR(uint8, AUTOMATIC, FRIF_APPL_DATA) FrIf_CyclePtr, 
                                                         P2VAR(uint16, AUTOMATIC, FRIF_APPL_DATA) FrIf_MacroTickPtr);

#  if (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF)
/**********************************************************************************************************************
  FrIf_SetAbsoluteTimer
**********************************************************************************************************************/
/*!
 *
 * \brief        Sets a given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_SetAbsoluteTimer.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx    Index of the absolute timer to address.
 * \param[in]    FrIf_Cycle          FlexRay Cycle number to be set.
 * \param[in]    FrIf_Offset         Number of Macroticks to be set.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-30194
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetAbsoluteTimer(FRIF_VCTRL_FIRST
                                                            uint8   FrIf_AbsTimerIdx, 
                                                            uint8   FrIf_Cycle,
                                                            uint16  FrIf_Offset);

/**********************************************************************************************************************
  FrIf_CancelAbsoluteTimer
**********************************************************************************************************************/
/*!
 *
 * \brief        Cancels a given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_CancelAbsoluteTimer.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx    Index of the absolute timer to address.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-30167
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelAbsoluteTimer(FRIF_VCTRL_FIRST
                                                               uint8 FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_EnableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*!
 *
 * \brief        Enables the interrupt line of a given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_EnableAbsoluteTimerIRQ.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx    Index of the absolute timer to address.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-29970
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                                  uint8 FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_AckAbsoluteTimerIRQ
**********************************************************************************************************************/
/*!
 *
 * \brief        Resets the interrupt condition of given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_AckAbsoluteTimerIRQ.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx    Index of the absolute timer.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-29864
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_AckAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                               uint8 FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_DisableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*!
 *
 * \brief        Disables the interrupt line of a given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_DisableAbsoluteTimerIRQ.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx    Index of the absolute timer to address.
 * \return       E_OK                The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                   has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-29908
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableAbsoluteTimerIRQ(FRIF_VCTRL_FIRST
                                                                   uint8 FrIf_AbsTimerIdx);

/**********************************************************************************************************************
  FrIf_GetAbsoluteTimerIRQStatus
**********************************************************************************************************************/
/*!
 *
 * \brief        Gets the IRQ status of a given absolute timer.
 * \details      Wraps the FlexRay Driver API function Fr_GetAbsoluteTimerIRQStatus.
 * \param[in]    FrIf_CtrlIdx         Index of the FlexRay CC to address.
 *                                    This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_AbsTimerIdx     Index of the absolute timer to address.
 * \param[out]   FrIf_IRQStatusPtr    Pointer to a memory location where the output value will be stored. The pointer
 *                                    shall be forwarded by the FrIf without any modifications.
 * \return       E_OK                 The call of the FlexRay Driver's API service has returned E_OK.
 * \return       E_NOT_OK             The call of the FlexRay Driver's API service has returned E_NOT_OK, or an error
 *                                    has been detected in development mode.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105566
 * \trace        SPEC-30185
 * \config       Available only if FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF.
 * \ingroup      AbsT
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetAbsoluteTimerIRQStatus(FRIF_VCTRL_FIRST
                                                      uint8 FrIf_AbsTimerIdx,
                                                      P2VAR(boolean, AUTOMATIC, FRIF_APPL_DATA) FrIf_IRQStatusPtr);
#  endif /* (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF) */

# endif /* (FRIF_API_AS_MACRO == STD_OFF) */

#  if (FRIF_USE_FRTRCV_API == STD_ON)
/**********************************************************************************************************************
  FrIf_SetTransceiverMode
**********************************************************************************************************************/
/*!
 *
 * \brief        Sets the mode of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_SetTransceiverMode.
 * \param[in]    FrIf_CtrlIdx     Index of the FlexRay CC to address.
 *                                This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx     Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[in]    FrIf_TrcvMode    Transceiver mode to be set.
 * \return       E_OK             The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK         The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105573
 * \trace        SPEC-30101
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetTransceiverMode(FRIF_VCTRL_FIRST
                                                              Fr_ChannelType FrIf_ChnlIdx, 
                                                              FrTrcv_TrcvModeType FrIf_TrcvMode);

/**********************************************************************************************************************
  FrIf_GetTransceiverMode
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns the actual mode of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_GetTransceiverMode.
 * \param[in]    FrIf_CtrlIdx        Index of the FlexRay CC to address.
 *                                   This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx        Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                   FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[out]   FrIf_TrcvModePtr    Pointer to a memory location where the output value will be stored.
 * \return       E_OK                The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK            The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105573
 * \trace        SPEC-30154
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverMode(FRIF_VCTRL_FIRST
                                             Fr_ChannelType FrIf_ChnlIdx,
                                             P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvModePtr);

/**********************************************************************************************************************
  FrIf_GetTransceiverWUReason
**********************************************************************************************************************/
/*!
 *
 * \brief        Returns the wake-up reason of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_GetTransceiverWUReason.
 * \param[in]    FrIf_CtrlIdx            Index of the FlexRay CC to address.
 *                                       This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx            Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                       FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as
 *                                       FrIf_ChnlIdx.
 * \param[out]   FrIf_TrcvWUReasonPtr    Pointer to a memory location where the output value will be stored.
 * \return       E_OK                    The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK                The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105572
 * \trace        SPEC-29831
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverWUReason(FRIF_VCTRL_FIRST
                                     Fr_ChannelType FrIf_ChnlIdx, 
                                     P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRIF_APPL_DATA) FrIf_TrcvWUReasonPtr);

/**********************************************************************************************************************
  FrIf_EnableTransceiverBranch
**********************************************************************************************************************/
/*!
 *
 * \brief        Enables a branch of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_EnableTransceiverBranch.
 * \param[in]    FrIf_CtrlIdx      Index of the FlexRay CC to address.
 *                                 This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx      Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                 FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[in]    FrIf_BranchIdx    Index of the branch of the (active star) transceiver to which the API call has
 *                                 to be applied.
 * \return       E_OK              The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK          The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105571
 * \trace        SPEC-30126
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON. \trace SPEC-29955, SPEC-30074
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableTransceiverBranch(FRIF_VCTRL_FIRST
                                                            Fr_ChannelType FrIf_ChnlIdx,
                                                            uint8          FrIf_BranchIdx);

/**********************************************************************************************************************
  FrIf_DisableTransceiverBranch
**********************************************************************************************************************/
/*!
 *
 * \brief        Disables a branch of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_DisableTransceiverBranch.
 * \param[in]    FrIf_CtrlIdx      Index of the FlexRay CC to address.
 *                                 This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx      Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                 FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[in]    FrIf_BranchIdx    Index of the branch of the (active star) transceiver to which the API call has
 *                                 to be applied.
 * \return       E_OK              The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK          The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105571
 * \trace        SPEC-29868
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON. \trace SPEC-29955, SPEC-30074
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableTransceiverBranch(FRIF_VCTRL_FIRST
                                                             Fr_ChannelType FrIf_ChnlIdx,
                                                             uint8          FrIf_BranchIdx);

/**********************************************************************************************************************
  FrIf_ClearTransceiverWakeup
**********************************************************************************************************************/
/*!
 *
 * \brief        Clears a pending wake-up event of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_ClearTransceiverWakeup.
 * \param[in]    FrIf_CtrlIdx    Index of the FlexRay CC to address.
 *                               This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx    Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                               FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \return       E_OK            The call of the FlexRay Transceiver Driver's API service has returned E_OK.
 * \return       E_NOT_OK        The call of the FlexRay Transceiver Driver's API service has returned E_NOT_OK.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105572
 * \trace        SPEC-29844
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_ClearTransceiverWakeup(FRIF_VCTRL_FIRST
                                                                  Fr_ChannelType FrIf_ChnlIdx);

/**********************************************************************************************************************
  FrIf_GetTransceiverError
**********************************************************************************************************************/
/*!
 *
 * \brief        Retrieves the error state of a given FlexRay Transceiver.
 * \details      Wraps the FlexRay Transceiver Driver API function FrTrcv_GetTransceiverError.
 * \param[in]    FrIf_CtrlIdx          Index of the FlexRay CC to address.
 *                                     This parameter exists only if FRIF_CTRL_ENABLE_API_OPTIMIZATION = STD_OFF.
 * \param[in]    FrIf_ChnlIdx          Index of the FlexRay Channel to address in scope of the FlexRay controller
 *                                     FrIf_CtrlIdx. The enum value "FR_CHANNEL_AB" shall not be used as FrIf_ChnlIdx.
 * \param[in]    FrIf_BranchIdx        Index of the branch of the (active star) transceiver to which the API call has
 *                                     to be applied.
 * \param[out]   FrIf_BusErrorState    Pointer to the transceiver error state.
 * \return       E_OK                  API call finished successfully.
 * \return       E_NOT_OK              API call aborted due to errors.
 * \pre          -
 * \context      TASK|ISR
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \trace        CREQ-105573
 * \trace        SPEC-29863
 * \config       Available only if FRIF_USE_FRTRCV_API == STD_ON.
 * \ingroup      Trcv
 *********************************************************************************************************************/
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetTransceiverError(FRIF_VCTRL_FIRST
                                                           Fr_ChannelType FrIf_ChnlIdx,
                                                           uint8 FrIf_BranchIdx,
                                                           P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_BusErrorState);
# endif /* (FRIF_USE_FRTRCV_API == STD_ON)  */

# define FRIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (FrIf wrapper APIs as macro)
 *********************************************************************************************************************/

# if (!FrIf_IsPostbuild())
#  define FrIf_TrcvDescriptorMap                  FrIf_TransceiverDescriptors
# else
#  define FrIf_TrcvDescriptorMap                  FrIf_GetConfig(0)->pTrcvDescriptors
# endif /* (!FrIf_IsPostbuild()) */

/* PRQA S 3453 FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

# if (FRIF_USE_FRTRCV_API == STD_ON)
#  define FrIf_GetTransceiverMapIdx(ChnlIdx)      (FrIf_TrcvDescriptorMap[(ChnlIdx)].TrcvFctMapIdx)
#  define FrIf_GetTransceiverTrcvIdx(ChnlIdx)     (FrIf_TrcvDescriptorMap[(ChnlIdx)].TrcvIdx)
# endif /* (FRIF_USE_FRTRCV_API == STD_ON) */

# if (FRIF_API_AS_MACRO == STD_ON)
#  if (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON)
#  define FrIf_GetNumOfStartupFrames(CtrlIdx, NumStartupFramesPtr)                        Fr_GetNumOfStartupFrames(CtrlIdx, NumStartupFramesPtr)
#  endif /* (STD_ON == FRIF_GETNUMSTARTUPFRAMESSUPPORT) */
#  if (FRIF_ALLSLOTSSUPPORT == STD_ON)
#  define FrIf_AllSlots(CtrlIdx)                                                          Fr_AllSlots(CtrlIdx)
#  endif /* (FRIF_ALLSLOTSSUPPORT == STD_ON) */
#  if (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON)
#  define FrIf_GetWakeupRxStatus(CtrlIdx, WakeupRxStatusPtr)                              Fr_GetWakeupRxStatus(CtrlIdx, WakeupRxStatusPtr)
#  endif /* (STD_ON == FRIF_GETWAKEUPRXSTATUSSUPPORT) */
#  define FrIf_GetCycleLength(CtrlIdx)                                                    (uint32)(FrIf_GetNumberOfMacroTicksPerCycle(CtrlIdx) * FrIf_GetMacroTickLengthInNanoSeconds(CtrlIdx))
#  define FrIf_ControllerInit(CtrlIdx)                                                    Fr_ControllerInit(CtrlIdx)
#  define FrIf_StartCommunication(CtrlIdx)                                                Fr_StartCommunication(CtrlIdx)
#  define FrIf_HaltCommunication(CtrlIdx)                                                 Fr_HaltCommunication(CtrlIdx)

#  if (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF)
#   define FrIf_AbortCommunication(CtrlIdx)                                               Fr_AbortCommunication(CtrlIdx)
#  endif /* (STD_OFF == FRIF_ABORT_COMMUNICATION_DISABLE) */

#  define FrIf_SendWUP(CtrlIdx)                                                           Fr_SendWUP(CtrlIdx)

#  if (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
#   define FrIf_SetWakeupChannel(CtrlIdx, ChnlIdx)                                        Fr_SetWakeupChannel(CtrlIdx, ChnlIdx)
#  endif /* (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF) */

#  if (FRIF_READCCCONFIGSUPPORT == STD_ON)
#   define FrIf_ReadCCConfig(CtrlIdx, FrIf_CCLLParamIndex, FrIf_CCLLParamValue)           Fr_ReadCCConfig(CtrlIdx, FrIf_CCLLParamIndex, FrIf_CCLLParamValue)
#  endif /* (FRIF_READCCCONFIGSUPPORT == STD_ON) */

#  if (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON)
#   define FrIf_GetSyncFrameList(CtrlIdx, FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr) Fr_GetSyncFrameList(CtrlIdx, FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr)
#  endif /* (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON) */

#  if (FRIF_RECONFIGLPDUSUPPORT == STD_ON)
#   define FrIf_ReconfigLPdu(CtrlIdx, FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset, FrIf_PayloadLength, FrIf_HeaderCRC) Fr_ReconfigLPdu(CtrlIdx, FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset, FrIf_PayloadLength, FrIf_HeaderCRC)
#  endif /* (FRIF_RECONFIGLPDUSUPPORT == STD_ONT) */

#  if (FRIF_DISABLELPDUSUPPORT == STD_ON)
#   define FrIf_DisableLPdu(CtrlIdx, FrIf_LPduIdx)                                        Fr_DisableLPdu(CtrlIdx, FrIf_LPduIdx)
#  endif /* (FRIF_DISABLELPDUSUPPORT == STD_ON) */

#  define FrIf_AllowColdstart(CtrlIdx)                                                    Fr_AllowColdstart(CtrlIdx)
#  define FrIf_GetPOCStatus(CtrlIdx, POCStatusPtr)                                        Fr_GetPOCStatus(CtrlIdx, POCStatusPtr)

#  if (FRIF_CHANNEL_STATUS_ENABLE == STD_ON)
#   define FrIf_GetChannelStatus(CtrlIdx, ChannelAStatusPtr, ChannelBStatusPtr)           Fr_GetChannelStatus(CtrlIdx, ChannelAStatusPtr, ChannelBStatusPtr)
#  endif /* (FRIF_CHANNEL_STATUS_ENABLE == STD_ON) */

#  if (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON)
#   define FrIf_GetClockCorrection(CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr)       Fr_GetClockCorrection(CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr)
#  endif /* (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON) */

#  if (FRIF_NMVECTORSUPPORT == STD_ON)
#   define FrIf_GetNmVector(CtrlIdx, NmVectorPtr)                                         Fr_GetNmVector(CtrlIdx, NmVectorPtr)
#  endif /* (FRIF_NMVECTORSUPPORT == STD_ON) */

#  define FrIf_GetGlobalTime(CtrlIdx, CyclePtr, MacroTickPtr)                             Fr_GetGlobalTime(CtrlIdx, CyclePtr, MacroTickPtr)


#  if (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF)
#   define FrIf_SetAbsoluteTimer(CtrlIdx, AbsTimerIdx, Cycle, MacrotickOffset)            Fr_SetAbsoluteTimer(CtrlIdx, AbsTimerIdx, Cycle, MacrotickOffset)
#   define FrIf_CancelAbsoluteTimer(CtrlIdx, AbsTimerIdx)                                 Fr_CancelAbsoluteTimer(CtrlIdx, AbsTimerIdx)
#   define FrIf_AckAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                                 Fr_AckAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_EnableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                              Fr_EnableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_DisableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)                             Fr_DisableAbsoluteTimerIRQ(CtrlIdx, AbsTimerIdx)
#   define FrIf_GetAbsoluteTimerIRQStatus(CtrlIdx, AbsTimerIdx, IRQStatusPtr)             Fr_GetAbsoluteTimerIRQStatus(CtrlIdx, AbsTimerIdx, IRQStatusPtr)
#  endif /* (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF) */

# endif /* (FRIF_API_AS_MACRO == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (single controller optimization)
 *********************************************************************************************************************/

# if (FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  if (FRIF_API_AS_MACRO == STD_OFF)
#   if (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON)
#   define FrIf_GetNumOfStartupFrames(FrIf_CtrlIdx, FrIf_NumOfStartupFramesPtr)           FrIf_GetNumOfStartupFrames(FrIf_NumOfStartupFramesPtr)
#   endif /* (FRIF_GETNUMSTARTUPFRAMESSUPPORT == STD_ON) */
#   if (FRIF_ALLSLOTSSUPPORT == STD_ON)
#    if !defined( FRIF_SOURCE ) /* COV_FRIF_SOURCE */
#     define FrIf_AllSlots(FrIf_CtrlIdx)                                                  FrIf_AllSlots()
#    endif /* !defined( FRIF_SOURCE ) */
#   endif /* (FRIF_ALLSLOTSSUPPORT == STD_ON) */
#   if (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON)
#   define FrIf_GetWakeupRxStatus(FrIf_CtrlIdx, FrIf_WakeupRxStatusPtr)                   FrIf_GetWakeupRxStatus(FrIf_WakeupRxStatusPtr)
#   endif /* (FRIF_GETWAKEUPRXSTATUSSUPPORT == STD_ON) */
#   if !defined( FRIF_SOURCE ) /* COV_FRIF_SOURCE */
#   define FrIf_GetCycleLength(FrIf_CtrlIdx)                                              FrIf_GetCycleLength()
#   define FrIf_ControllerInit(FrIf_CtrlIdx)                                              FrIf_ControllerInit()
#   define FrIf_StartCommunication(FrIf_CtrlIdx)                                          FrIf_StartCommunication()
#   define FrIf_HaltCommunication(FrIf_CtrlIdx)                                           FrIf_HaltCommunication()

#   if (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF)
#    define FrIf_AbortCommunication(FrIf_CtrlIdx)                                         FrIf_AbortCommunication()
#   endif /* (FRIF_ABORT_COMMUNICATION_DISABLE == STD_OFF) */

#   define FrIf_SendWUP(FrIf_CtrlIdx)                                                     FrIf_SendWUP()
#   endif /* !defined( FRIF_SOURCE ) */

#   if (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
#    define FrIf_SetWakeupChannel(FrIf_CtrlIdx, FrIf_ChnlIdx)                             FrIf_SetWakeupChannel(FrIf_ChnlIdx)
#   endif /* (FRIF_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF) */

#   if (FRIF_READCCCONFIGSUPPORT == STD_ON)
#    define FrIf_ReadCCConfig(FrIf_CtrlIdx, FrIf_CCLLParamIndex, FrIf_CCLLParamValue)     FrIf_ReadCCConfig(FrIf_CCLLParamIndex, FrIf_CCLLParamValue)
#   endif /* (FRIF_READCCCONFIGSUPPORT == STD_ON) */

#  if (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON)
#   define FrIf_GetSyncFrameList(FrIf_CtrlIdx, FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr) FrIf_GetSyncFrameList(FrIf_ListSize, FrIf_ChannelAEvenListPtr, FrIf_ChannelBEvenListPtr, FrIf_ChannelAOddListPtr, FrIf_ChannelBOddListPtr)
#  endif /* (FRIF_GETSYNCFRAMELISTSUPPORT == STD_ON) */

#   if (FRIF_RECONFIGLPDUSUPPORT == STD_ON)
#    define FrIf_ReconfigLPdu(FrIf_CtrlIdx, FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset, FrIf_PayloadLength, FrIf_HeaderCRC) FrIf_ReconfigLPdu(FrIf_LPduIdx, FrIf_FrameId, FrIf_ChnlIdx, FrIf_CycleRepetition, FrIf_CycleOffset, FrIf_PayloadLength, FrIf_HeaderCRC)
#   endif /* (FRIF_RECONFIGLPDUSUPPORT == STD_ON) */

#   if (FRIF_DISABLELPDUSUPPORT == STD_ON)
#    define FrIf_DisableLPdu(FrIf_CtrlIdx, FrIf_LPduIdx)                                  FrIf_DisableLPdu(FrIf_LPduIdx)
#   endif /* (FRIF_DISABLELPDUSUPPORT == STD_ON) */

#   if !defined( FRIF_SOURCE ) /* COV_FRIF_SOURCE */
#    define FrIf_AllowColdstart(FrIf_CtrlIdx)                                             FrIf_AllowColdstart()
#   endif /* !defined( FRIF_SOURCE ) */
#   define FrIf_GetPOCStatus(FrIf_CtrlIdx, FrIf_POCStatusPtr)                             FrIf_GetPOCStatus(FrIf_POCStatusPtr)

#   if (FRIF_CHANNEL_STATUS_ENABLE == STD_ON)
#    define FrIf_GetChannelStatus(FrIf_CtrlIdx, FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr) FrIf_GetChannelStatus(FrIf_ChannelAStatusPtr, FrIf_ChannelBStatusPtr)
#   endif /* (FRIF_CHANNEL_STATUS_ENABLE == STD_ON) */

#   if (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON)
#    define FrIf_GetClockCorrection(FrIf_CtrlIdx, RateCorrectionPtr, OffsetCorrectionPtr) FrIf_GetClockCorrection(RateCorrectionPtr, OffsetCorrectionPtr)
#   endif /* (FRIF_CLOCK_CORRECTION_ENABLE == STD_ON) */

#   if (FRIF_NMVECTORSUPPORT == STD_ON)
#    define FrIf_GetNmVector(FrIf_CtrlIdx, FrIf_NmVectorPtr)                              FrIf_GetNmVector(FrIf_NmVectorPtr)
#   endif /* (FRIF_NMVECTORSUPPORT == STD_ON) */

#   define FrIf_GetGlobalTime(FrIf_CtrlIdx, FrIf_CyclePtr, FrIf_MacroTickPtr)             FrIf_GetGlobalTime(FrIf_CyclePtr, FrIf_MacroTickPtr)


#   if (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF)
#    define FrIf_SetAbsoluteTimer(FrIf_CtrlIdx, FrIf_AbsTimerIdx, Cycle, MacrotickOffset) FrIf_SetAbsoluteTimer(FrIf_AbsTimerIdx, Cycle, MacrotickOffset)
#    define FrIf_CancelAbsoluteTimer(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                      FrIf_CancelAbsoluteTimer(FrIf_AbsTimerIdx)
#    define FrIf_AckAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                      FrIf_AckAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_EnableAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                   FrIf_EnableAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_DisableAbsoluteTimerIRQ(FrIf_CtrlIdx, FrIf_AbsTimerIdx)                  FrIf_DisableAbsoluteTimerIRQ(FrIf_AbsTimerIdx)
#    define FrIf_GetAbsoluteTimerIRQStatus(FrIf_CtrlIdx, AbsTimerIdx, IRQStatusPtr)       FrIf_GetAbsoluteTimerIRQStatus(AbsTimerIdx, IRQStatusPtr)
#   endif /* (FRIF_ABSOLUTE_TIMER_API_DISABLE == STD_OFF) */

#  endif /* (FRIF_API_AS_MACRO == STD_OFF) */

#  if (FRIF_USE_FRTRCV_API == STD_ON)
#   define FrIf_SetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvMode)             FrIf_SetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvMode)
#   define FrIf_GetTransceiverMode(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvModePtr)          FrIf_GetTransceiverMode(FrIf_ChnlIdx, FrIf_TrcvModePtr)
#   define FrIf_GetTransceiverWUReason(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)  FrIf_GetTransceiverWUReason(FrIf_ChnlIdx, FrIf_TrcvWUReasonPtr)
#   define FrIf_EnableTransceiverBranch(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_BranchIdx)       FrIf_EnableTransceiverBranch(FrIf_ChnlIdx, FrIf_BranchIdx)
#   define FrIf_DisableTransceiverBranch(FrIf_CtrlIdx, FrIf_ChnlIdx, FrIf_BranchIdx)      FrIf_DisableTransceiverBranch(FrIf_ChnlIdx, FrIf_BranchIdx)
#   define FrIf_GetTransceiverError(FrIf_CtrlIdx, ChnlIdx, BranchIdx, BusErrorState)      FrIf_GetTransceiverError(ChnlIdx, BranchIdx, BusErrorState)
#   define FrIf_ClearTransceiverWakeup(FrIf_CtrlIdx, FrIf_ChnlIdx)                        FrIf_ClearTransceiverWakeup(FrIf_ChnlIdx)
#  endif /* (FRIF_USE_FRTRCV_API == STD_ON) */

#  define FrIf_TxConfirmation(ClstIdx, FrameDescriptorPtr, Handle)                        FrIf_TxConfirmation(FrameDescriptorPtr, Handle)
#  define FrIf_TxRollback(ClstIdx, FrameDescriptorPtr, Handle)                            FrIf_TxRollback(FrameDescriptorPtr, Handle)
#  define FrIf_PrepareFrameBuffer(ClstIdx,  FrameDescriptorPtr, FrameBuffer, CurrentPos, PduUsage, FrameLayoutElIndex, Handle, txFrameConfig) \
                                                                                          FrIf_PrepareFrameBuffer(FrameDescriptorPtr, FrameBuffer, CurrentPos, \
                                                                                                                  PduUsage, FrameLayoutElIndex, Handle, txFrameConfig)
#  define FrIf_PrepareTxPdus(ClstIdx, FrameDescriptorPtr, FrameBuffer, CurrentPos, PduUsage, FrameLayoutElIndex, FrameDirty, Handle) \
                                                                                          FrIf_PrepareTxPdus(FrameDescriptorPtr, FrameBuffer, CurrentPos, \
                                                                                                             PduUsage, FrameLayoutElIndex, FrameDirty, Handle)
#  define FrIf_IncrementTxReqCounter(ClstIdx, TxPduDescriptorPtr)                         FrIf_IncrementTxReqCounter(TxPduDescriptorPtr)

#  define FrIf_Receive(ClstIdx, FrameDescriptorPtr, Handle)                               FrIf_Receive(FrameDescriptorPtr, Handle)
#  define FrIf_HandleRedundantFrame(ClstIdx, FrameDescriptorPtr, receiveBuffer, Handle, Fr_LPduLength, HandleIsReceived) \
                                                                                          FrIf_HandleRedundantFrame(FrameDescriptorPtr, receiveBuffer, Handle, Fr_LPduLength, HandleIsReceived)
#  define FrIf_FillRedundantRxPduInfo(ClstIdx,FrameLayoutElementPtr,receiveBuffer,PduNumber,UpdateBitBytePos,Fr_LPduLength,Index,HandleIsReceived) \
                                                                                          FrIf_FillRedundantRxPduInfo(FrameLayoutElementPtr,receiveBuffer, \
                                                                                                                      PduNumber,UpdateBitBytePos,Fr_LPduLength,Index,HandleIsReceived)

#  define FrIf_DiffTime(FrIf_ClstIdx, MacroTickDiff, CycleDiff)                           FrIf_DiffTime(MacroTickDiff, CycleDiff)
#  define FrIf_SetState(FrIf_ClstIdx, FrIf_StatePtr)                                      FrIf_SetState(FrIf_StatePtr)
#  define FrIf_GetState(FrIf_ClstIdx, FrIf_StatePtr)                                      FrIf_GetState(FrIf_StatePtr)
#if !defined( FRIF_SOURCE ) /* COV_FRIF_SOURCE */
#  define FrIf_GetMacrotickDuration(FrIf_CtrlIdx)                                         FrIf_GetMacrotickDuration()
#  define FrIf_GetMacroticksPerCycle(FrIf_CtrlIdx)                                        FrIf_GetMacroticksPerCycle()
#endif /* !defined( FRIF_SOURCE ) */

# endif /* ( FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON ) */

/* PRQA L:FUNCTIONLIKEMACROS */ /*  MD_MSR_19.7 */

/*!
 * \exclusivearea  FRIF_EXCLUSIVE_AREA_0
 *                 Ensure the consistency of the flags and counters related to Tx PDUs.
 * \protects       FrIf_TxPduDirtyBits (only if FRIF_PDUDIRTYBYTE_USAGE == STD_OFF) and
 *                 FrIf_TxPduTxRequestCounters (only if FRIF_REQUEST_COUNTER_HANDLING_DISABLE == STD_OFF).
 * \usedin         FrIf_PrepareTxPdus, FrIf_CancelTransmit, FrIf_Transmit, FrIf_TxRollback
 * \exclude        Modifications to FrIf_TxPduDirtyBits and/or FrIf_TxPduTxRequestCounters from another context.
 * \length         MEDIUM    Worst case is the rollback of the flags and counters of all the PDUs contained in a frame.
 * \endexclusivearea
 */

/*!
 * \exclusivearea  FRIF_EXCLUSIVE_AREA_1
 *                 Ensure the accurate estimation and setting of the timer for the next job list execution.
 * \protects       Time-critical estimation and setting of the timer for the next job list execution.
 * \usedin         FrIf_EnableJobListExecution, FrIf_JobListExec_<ClstIdx>
 * \exclude        Any tasks or interrupts of higher priority.
 * \length         LONG    Functions Fr_GetGlobalTime and Fr_SetAbsoluteTimer from the Fr are called. However, under
 *                         normal conditions the whole processing shouldn't take long.
 * \endexclusivearea
 */

/*!
 * \exclusivearea  FRIF_EXCLUSIVE_AREA_2
 *                 Ensure the FrIf is flagged as online after enabling the job list execution during initialization.
 * \protects       Required atomicity during initialization.
 * \usedin         FrIf_SetState
 * \exclude        The execution of FrIf_JobListExec_<ClstIdx>.
 * \length         LONG    FrIf_EnableJobListExecution is called and two functions of the Fr are then called
 *                         (Fr_GetGlobalTime and Fr_SetAbsoluteTimer). However, the whole processing shouldn't take
 *                         long under normal conditions.
 * \endexclusivearea
 */

#endif /* FRIF_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf.h
 *********************************************************************************************************************/
