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
/**        \file  Fr.h
 *        \brief  FlexRay Driver header file
 *
 *      \details  Header file implementation of the AUTOSAR FlexRay Driver according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Sebastian Schmar              Ssr           Vctr Informatik GmbH
 *  Juergen Schaeffer             Jsr           Vctr Informatik GmbH
 *  Sebastian Gaertner            Seg           Vctr Informatik GmbH
 *  Mario Kunz                    Mkz           Vctr Informatik GmbH
 *  Alex Lunkenheimer             Alr           Vctr Informatik GmbH
 *  Roland Hocke                  Rho           Vctr Informatik GmbH
 *  Oliver Reineke                Ore           Vctr Informatik GmbH
 *  Matthias Mueller              Mmu           Vctr Informatik GmbH
 *  Christian Leder               Chl           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  03.00.00  2007-08-23  Ssr                   Adapt to AUTOSAR 3.0 (pre)
 *  03.00.01  2007-12-12  Ssr     ESCAN00023676 optimize code, Add dynamic payload support
 *  03.00.02  2008-01-16  Jsr                   Add memory mapping, compiler abstraction, compiler switches 
 *                                              added memcopy functions
 *  03.00.03  2008-02-07  Jsr                   updates after review
 *  03.00.04  2008-02-15  Jsr                   minor changes
 *  03.00.05  2008-02-21  Jsr                   Add version check for DLL
 *  03.00.06  2008-02-22  Jsr                   rename of GENY generated defines
 *  03.00.07  2008-02-19  Jsr     ESCAN00024975 Include structure
 *                                ESCAN00024950 Inconsistency version declaration
 *                                ESCAN00024946 Remove "Platform.h"
 *                                ESCAN00023416 The macro CCREG_SUCC2_LTN_SHIFT has wrong value
 *                                ESCAN00024997 Compilation error occurs by Fr_GetNmVector when FR_CONFIG_VARIANT 1 is used.
 *  03.00.08  2008-03-02  Jsr     ESCAN00025275 optimazation. DLL version changed
 *  03.00.09  2008-03-27  Alr     ESCAN00025564 missing DFI support
 *  03.00.10  2008-04-03  Jsr                   DLL version changed
 *  03.00.11  2008-04-10  Jsr     ESCAN00025999 TMS470 added
 *  03.01.00  2008-04-14  Jsr                   Rename internal variables
 *                                              Adapted code consitency check
 *                                ESCAN00026209 Extension for MSR3.0 LinkTime checks
 *                                ESCAN00026137 Use <BSW>_InitMemory
 *                                ESCAN00026259 Rename files and #include statements according coding styles
 *                                ESCAN00026284 Rename Fr_priv.h Fr_ext.h to Fr_Priv.h Fr_Ext.h
 *                                ESCAN00022574 External Rate Correction not reset
 *                                ESCAN00026448 Implement BSWGeneralRequirementsSpec [BR:012]
 *                                              Updated memmap and compiler abstraction definitions
 *  03.01.01  2008-05-20  Jsr                   Adapted revision calculation
 *                                ESCAN00026643 (Lib check)
 *  03.02.00  2008-06-14  Seg     ESCAN00027381 added Fr_VErrorStatusType and Prototypes
 *  03.02.01  2008-06-24  Jsr     ESCAN00027823 Error events can be lost in extended error checks
 *                                ESCAN00027841 location of variable Fr_VErrorStatusType
 *  03.03.00  2008-08-05  Jsr     ESCAN00028065 Wrong Det check index at LPDU length test
 *                                ESCAN00025647 Provide default implementation for FrDrv -> FrIf APIs
 *                                ESCAN00026728 Update memmap defines
 *                                ESCAN00027389 name correction for CCREG_SWNIT_TBNB in Fr_ERay.h
 *                                ESCAN00028231 Fr_ReceiveRxLPdu does not return the payload length of a received frame.
 *  03.03.01  2008-08-19  Jsr     ESCAN00029232 LibCheck update
 *                                ESCAN00029154 No Fr communication (data transfer)
 *                                ESCAN00029268 Single channel api
 *  03.04.00  2008-08-22  Seg     ESCAN00029279 Message ID filtering
 *                                ESCAN00029395 Improvements for pointer names for being ASR conform
 *                                ESCAN00029391 compiler abstractions for precompile time and postbuild variant (FR_CONST -> FR_PBCFG)
 *                                ESCAN00029620 FR_NULL_FRAME_RECEIVED is used, but not defined
 *                                ESCAN00029154 No Fr communication (optional inline optimization)
 *                                ESCAN00029711 incomplete API optimization makros for relative timer
 *  03.04.01  2008-09-11  Ssr     ESCAN00029920 Returnvalue within Fr_ReceiveRxLPdu 
 *                                ESCAN00029922 Correct Fr_LPduStatusPtr and Fr_LPduLengthPtr
 *  03.04.02  2008-09-23  Seg     ESCAN00030202 ERay module on TC1797 needs to be enabled by the driver 
 *  03.05.00  2008-10-24  Ssr     ESCAN00029733 instanceID by <MSN>_GetVersionInfo
 *                                ESCAN00029737 DET by <MSN>_GetVersionInfo as Macro
 *                                ESCAN00030041 Eray buffer reconfiguration
 *                                ESCAN00030042 DrvFr_V85xErayVx Fr_TransmitTxLPdu configuration
 *                                              check
 *                                ESCAN00030798 Warnings in Fr.c if Visual Studio 8 used
 *                                ESCAN00030416 Add MBF to CANoeemu driver
 *                                ESCAN00030821 Channel name of the simulation of the remaining bus
 *  03.05.01  2008-10-27  Ssr     ESCAN00030895 Return value of Fr_CheckTxLPduStatus
 *                                ESCAN00030896 Contend of Fr_PrepareLPdu within CANoe Driver
 *                                ESCAN00031028 Correct MTS API for CANoe Driver
 *  03.06.00  2008-11-07  Ssr     ESCAN00031133 Optimize CRC calculation
 *                                ESCAN00031238 FlexRay Driver reports DET error when Fr_PrepareLPdu is called
 *                                ESCAN00031358 Remove swap Message Id filtering CANoe driver
 *                                ESCAN00030962 Add Fr_GetClockCorrection and Fr_GetChannelStatus instead
 *                                              current Fr_GetChannelStatus
 *                                ESCAN00030456 Declaration of the postbuild arrays
 *                                ESCAN00030903 Postbuild message buffer Id filtering
 *                                ESCAN00029693 AUTOSAR Dummy Statements
 *                        Seg     ESCAN00030266 PreCompile and Linktime Crc Check
 *                                ESCAN00031774 MISRA rework
 *                        Seg     ESCAN00031903 insufficient interrupt lock
 *                                ESCAN00030543 FlexRay Driver does not always report an production error in case of CC access errors
 *  03.06.01  2009-01-14  Ssr     ESCAN00032377 Frames with dynamic payload length can be truncated
 *  03.07.00  2009-01-26  Jsr     ESCAN00031239 Status of sync frames changed from cyclic to event triggered
 *                                ESCAN00032528 No FrIf_JobListExec_0 with "Application callback at timer 0 interrupt" is switched off
 *                                ESCAN00032341 Unneccessary call of FrIf_JobListExec_0 at specific configuration
 *                                ESCAN00032152 CANoeEmu Driver does not transmit some frames in dyn segment if Buffer Reconf is enabled
 *                        Ssr     ESCAN00032825 Add tricore specific parameters
 *                                ESCAN00032943 Unnecessarary Dem event FR_E_ACCESS report
 *  03.07.01  2009-02-23  Ssr     ESCAN00033310 Clean unnecessary comments
 *  03.08.00  2009-03-31  Jsr     ESCAN00033251 FTU support
 *                                ESCAN00033647 Fr_VReadDataFromCC and Fr_VWriteDataToCC with unique lengh
 *                        Ssr     ESCAN00032560 Det check for relative timer
 *                                ESCAN00033265 Check timely pickup of Rx Frames
 *                                ESCAN00033666 Version shall be BCD coded
 *                                ESCAN00033421 Hardware Loop Check
 *                                ESCAN00033679 Simplify the include structure of Fr_Priv.h
 *                                ESCAN00033539 Add Link Time Support
 *                                ESCAN00034077 incorrect DET check for wrong channel index
 *                                ESCAN00033850 Add POLYSPACE support
 *                                ESCAN00034035 Compile warnings by extended version checks
 *                                ESCAN00034554 Timer0 optimization
 *                                ESCAN00034556 MTS on channel B
 *                                ESCAN00034658 Interrupts not enabled correctly
 *  03.08.01  2009-05-26  Ssr     ESCAN00035352 CANoeEmu. Compile errors
 *                                ESCAN00032332 CANoeEmu: FlexRay_Init should be called by Flexray Driver (CANoe)
 *                                ESCAN00033218 CANoeEmu: Register frames with half payload  
 *                                ESCAN00032680 CANoeEmu: message "FlexRay channel 2 not allowed!"
 *                                ESCAN00035403 CANoeEmu: Cycle Multiplexing
 *                                ESCAN00035406 Remove the Fr_PrepareLPdu API from source code
 *  03.08.02  2009-06-03  Jsr     ESCAN00035483 DBA: break interrupt locks over functions
 *                                ESCAN00035560 MSG ID Filtering for TMS with FTU and ISO-TP
 *  03.09.00  2009-07-30  Ssr     ESCAN00036314 FlexRay Driver shall support FIFOs (Asr 4.0)
 *                        Jsr     ESCAN00031969 update function headers
 *                                ESCAN00029731 undefined symbols with Tx/Rx-Interrupt configuration
 *                                ESCAN00036136 pre-processor checks for building the library
 *                                ESCAN00033134 Add Version-number [BR:012]
 *  03.09.01  2009-07-31  Jsr                   Update DLL Version in h file
 *  03.09.02  2009-08-06  Jsr     ESCAN00036853 Bugfix: Fifo support with CANoe Emu 
 *                                ESCAN00036973 Wrong memmap defines for SEC_PBCFG_ROOT
 *  03.10.00  2009-09-15  Ssr     ESCAN00036487 FlexRay Driver shall support FIFOs (Asr 4.0) for TMS
 *                                ESCAN00037806 Add TMS to single source
 *                        Jsr     ESCAN00037052 No memap for an variable declaration
 *                                ESCAN00036852 No FlexRay Communication with CANoe Emu and Real Bus
 *                        Mkz     ESCAN00037911 Enable access to internal E-Ray registers
 *                        Ssr     ESCAN00037988 Partially data lost FTU
 *  03.10.01  2009-10-16  Jsr     ESCAN00038534 v_def.h should be included to import VGEN_ENABLE_IF_ASRIFFR
 *  03.10.02  2009-11-11  Jsr     ESCAN00039062 CANoe EMU driver does not stop transmitting frames after Fr_HaltCommunication
 *                                ESCAN00035703 Similar DET Usage
 *  03.10.03  2009-11-12  Jsr     ESCAN00039130 CANoe emu driver shall handle FrameIds with illegal values
 *  03.10.04  2009-11-13  Jsr     ESCAN00039150 EXTENDED_VERSION_CHECK produces compiler error at link time variant
 *  03.11.00  2009-11-13  Jsr     ESCAN00037153 Read and verification of the FlexRay configuration
 *                                ESCAN00039056 FlexRay CANoe emu driver shall not includes "FrTrcv.h"
 *  03.11.01  2009-11-27  Jsr                   Update CCConfig
 *                                ESCAN00037929 Use of FR_PROCESSOR_FX4 instead of C_PROCESSOR_FX4
 *                                ESCAN00039750 Compile Error at SW-Fifo Configuration
 *                        Ssr     ESCAN00037153 Add the verification part
 *                                ESCAN00035423 Compiler errors
 *                                ESCAN00033431 Missing compiler abstraction in the CC register access macros
 *                                ESCAN00039804 Compiler errors CRC check
 *  03.12.00  2010-01-27  Jsr     ESCAN00039795 Wrong comparison in Extended Version Check at 16bit micro controller
 *                                ESCAN00040412 Resource Improvement of Link Time Configuration Variant 
 *                                ESCAN00039986 Compiler Errors
 *                                ESCAN00039487 Solve MISRA finding in Fr_ERay.h
 *                                ESCAN00039511 Compatibility with 16bit host
 *                                ESCAN00041307 Wrong Er_GetGlobalTime values
 *                                ESCAN00041447 Callback to get configuration data of application for hardware initialization of CANoe before stack is started.
 *                                ESCAN00040287 Disable cycle start interrupt if not required
 *                                ESCAN00042203 Workaround Errata No.35
 *                                ESCAN00042207 Missing Rx Frame
 *                                ESCAN00042574 Optimization Eray access
 *                                ESCAN00039952 Similar DET Usage 
 *                        Seg     ESCAN00041418 Support multi identity configurations
 *                                ESCAN00041422 Det Error Check returns wrong API ID value
 *                                ESCAN00041423 Compile Error 
 *            2010-04-07  Ssr     ESCAN00041910 Add one handle room for frames
 *                                ESCAN00041911 Compiler Errors
 *                                ESCAN00041912 Compiler Errors
 *                                ESCAN00041921 Compiler Errors  
 *                                ESCAN00041307 Wrong Er_GetGlobalTime values
 *                                ESCAN00042040 Remove include "v_def.h"
 *  03.13.00  2010-05-18  Jsr     ESCAN00042985 Wrong value of Service ID FR_API_ID_READCCCONFIG
 *                                ESCAN00041681 Support Generic derivative
 *                                ESCAN00042889 Null Frame reception
 *                                ESCAN00043529 data loss due to insufficient compiler abstraction
 *                                ESCAN00043905 Add support Fr_GetClockCorrection switch and synchronize it with FrIf
 *                                ESCAN00043670 Remove FR_E_INV_MBUF_IDX
 *                                ESCAN00043748 No reset of FTU when FTU is not used
 *                                ESCAN00043899 Delete SPI code of the derivate XMB88121B
 *                                ESCAN00043901 Add Fr_DeInit function
 *                                ESCAN00043913 Remove compiler warning of 'statement is unreachable' if DET is enabled
 *                                ESCAN00044818 Wrong return value in Fr_ControllerInit if CCconfiguration does not fit in CC 
 *                                ESCAN00044851 Compiler warning at configuration with enabled "Read and Verify FlexRay Parameters" and "Amount of reconfiguration"=0 
 *                                ESCAN00044858 Generate data for NmVectorLength only if Fr-NM is enabled 
 *                                ESCAN00042899 Optimization NFI check 
 *                                ESCAN00039656 optimization of Fr_ISR_Timer0 and Fr_IrqTimer0 to reduce resources 
 *                                ESCAN00039987 Missing DET checks 
 *                                ESCAN00044292 check compiler abstractions  
 *                                ESCAN00041157 DEM usage configurable   
 *                                ESCAN00044449 check memory abstraction 
 *                                ESCAN00045055 Compile error 
 *                                ESCAN00045084 [CANoeEmu] Compile Error  
 *  03.13.01  2010-09-20  Ssr     ESCAN00045507 Missing DET check for Null_Ptr at ReadCCConfig
 *                                ESCAN00046009 Add additional DET check for incorrect channel name configuration
 *                                ESCAN00046022 Remove unused code
 *                                ESCAN00045912 Compile Error
 *  03.14.00  2010-10-25  Ssr     ESCAN00046175 Remove support of Bit5 at Fr_GetChannelStatus
 *                                ESCAN00046317 Lost of aggregated channel status information
 *                                ESCAN00046333 Add bidirectional routing
 *                                ESCAN00046366 Adapt AUTOSAR version check
 *                                ESCAN00046939 Remove exclusive area at Fr_ReceiveLpdu
 *                                ESCAN00046514 Include dem.h only if used
 *                                ESCAN00046516 Optimize Fr_DisableLpdu
 *                                ESCAN00046638 Unbalanced calls of enter/leave critical section
 *                                ESCAN00046648 Remove pragma at void Irq(void) function
 *                                ESCAN00046448 Fr_ReadCCConfig shall return E_NOT_OK if parameter out of bounds
 *                                ESCAN00046945 Remove unused feature
 *                                ESCAN00047062 Missing include of FrIf.h at Fr_Irq.c
 *                                ESCAN00048216 Correct history
 *                                ESCAN00048386 Adjusted of DEM macros access
 *                                ESCAN00048614 Move checks of feature support
 *                                ESCAN00047950 Update include structure
 *                                ESCAN00048664 Optimize implementation of Fr_VReadDataFromCC
 *  03.14.01  2011-02-22  Ssr     ESCAN00048824 Premature locking of the FTU
 *                                ESCAN00048825 Fail Key Slot check  
 *                                ESCAN00047733 add compiler abstractions
 *                                ESCAN00048829 Add new FR_EXCLUSIVE_AREA for the FTU locking
 *  03.14.02  2011-03-09  Ssr     ESCAN00049160 Add support for Sh2 derivat
 *  03.15.00  2011-04-06  Ssr     ESCAN00048662 Fr_Lcfg.h redefines Fr_ConfigType
 *                                ESCAN00049211 Optimize interrupt liquidation deletion
 *                                ESCAN00049252 All define shall be start with Fr_
 *                                ESCAN00049507 Reception of empty Frame
 *                                ESCAN00050078 Correct placement of Fr_ConfigPtr DET check
 *                                ESCAN00050572 remove ApplFr_ISR_Rx &  ApplFr_ISR_Tx
 *                                ESCAN00050751 AR3-1330: Remove E_PENDING for ASR3
 *                                ESCAN00051038 Check for feature availability
 *                                ESCAN00051037 unexpected behaviour in POC state normal_passive
 *                                ESCAN00051244 Unresolved external symbol _Fr_IrqLine0
 *                                ESCAN00050911 Add ASR3.2 feature
 *                                ESCAN00052588 Add support for Px4
 *  03.15.01  2011-08-11  Seg     ESCAN00049261 Add DET check for FlexRay Memory placement
 *  03.15.02  2011-08-25  Seg     ESCAN00053033 Compile Error for TMS at Postbuild variant
 *  03.15.03  2011-09-08  Seg     ESCAN00047971 Similar handling of endinit-protected registers like CLC
 *  03.15.04  2011-09-19  Ssr     ESCAN00053676 Directly access to Dem Error events for External Generator
 *  03.16.00  2011-11-08  Seg     ESCAN00054515 Compile Error Feature "ReadBack Support", Fr_GetCtrlTestCount is undefined
 *                                ESCAN00053409 AR3-2069: Remove non-SchM code for critical section handling
 *                                ESCAN00054310 Remove not required variable initialization
 *                                ESCAN00054800 add MISRA justifications in html report / code
 *                                ESCAN00055050 Add POLYSPACE support
 *                                ESCAN00055003 wrong Flexray data or nullframes instead of data frames
 *                                ESCAN00055232 code optimization
 *                                ESCAN00055233 remove filter for CHANNEL_STATUS_EXT
 *                                ESCAN00055309 correct return value for relative timer functions
 *  03.16.01  2012-12-27  Ssr     ESCAN00057282 Add OS End-Init protections for Tricore
 *  03.17.00  2012-03-12  Ssr     ESCAN00056158 Use GenTool_GenyVcfgNameDecorator to Generate Common Defines
 *                                ESCAN00055233 Remove filter for CHANNEL_STATUS_EXT
 *                                ESCAN00056300 Add checks for readiness of the input and output message buffers
 *                                ESCAN00056333 Remove warning (Canoe)
 *                                ESCAN00058565 Wakeup channel doesn't change
 * 03.17.01   2012-06-21  Ssr     ESCAN00057357 AR3-2383: Implement handling of call to Dem_ReportErrorStatus
 * 03.17.02   2012-06-28  Ssr     ESCAN00059740 Adjust to GeneratorMSR generator
 * 03.18.00   2012-07-03  Ssr     ESCAN00059873 Extents for ASR4
 * 03.18.01   2012-09-05  Rho     ESCAN00061184 Fr_AllSlots API
 * 03.19.00   2012-09-28  Rho     ESCAN00061817 API-ID ReadCCConfig is wrong
 *            2012-10-02  Rho     ESCAN00061941 Add source defines according to MICROSAR template source file
 *            2012-10-04  Rho     ESCAN00061939 Compiler error: re-declaration of Fr_AllSlots() macro
 *                                ESCAN00061948 Cfg5 and GENy Derivative name defines inconsistent
 *                                ESCAN00061943 Compiler error: undefined symbol tmpVal16
 *            2012-10-10  Rho     ESCAN00062065 DEM call not in FR_PROD_ERROR_DETECT #if-branch
 *            2012-10-25  Rho     ESCAN00062518 AR3-2378: Implement AMD timemeasurement support
 *                                ESCAN00058235 Inactive CRC check at postbuild configuration
 *            2012-10-26  Rho     ESCAN00061983 Implement handling of call to Dem_ReportErrorStatus is not correct
 *            2012-10-31  Rho     ESCAN00062665 "Media Access Test symbol received"-flag is always zero
 *            2012-11-12  Rho     ESCAN00062958 Compiler error: Memmap-Section not properly closed
 *            2012-11-15  Rho     ESCAN00061427 Misra violations are not justified according to [WI_MISRAC2004_PES]
 *            2012-11-15  Rho     ESCAN00062884 Wrong preprocessor condition according to Autosar requirement [FR520] 
 * 03.19.01   2012-11-28  Rho     ESCAN00063291 Compiler error: 'void' cannot be an argument type, except for '(void)'
 *            2012-11-28  Rho     ESCAN00063290 Compiler warning: not enough actual parameters for macro 'Fr_GetNumOfStartupFrames'
 * 03.19.02   2012-12-06  Rho     ESCAN00061825 AR4-91: Support Fr_CancelTxLPdu() API
 *            2013-01-08  Rho     ESCAN00063990 Compiler error: wrong DRVFR_TMS470ERAYASR_DLL_VERSION
 *            2013-02-22  Rho     ESCAN00057819 BETA version
 *            2013-01-14  Rho     ESCAN00063720 Wrong version define in header-file.
 * 03.20.00   2013-02-20  Rho     ESCAN00065248 Eray operation not enabled
 *            2013-02-27  Ore     ESCAN00065215 Incorrect signature for Fr_ControllerInit (has only one parameter in AR4)
 *            2013-03-28  Ore     ESCAN00066222 Compiler error: function Fr_VCCRead() declared implicitly
 *            2013-03-21  Rho     ESCAN00065939 FrIf_JobListExec_0 is not called if /Fr/FrGeneral/FrTimer0Interrupt is disabled
 *            2013-03-01  Rho     ESCAN00065509 Wrong receive indications are given for frames within FIFO range
 *            2013-03-12  Rho     ESCAN00065804 RH850 Timer ISR is not called
 *            2013-03-21  Rho     ESCAN00065841 CanoeEmu: Missing DETcheck for offset at Fr_SetAbsoluteTimer
 *            2013-04-12  Rho     ESCAN00066148 Fr_GetChannelStatus API can be encapsulated with FR_VCHANNEL_STATUS_EXT to reduce code size
 *                                ESCAN00065941 Remove obsolete AR3 API Fr_GetSyncState()
 *                                ESCAN00065221 Missing processor defines 
 *            2013-04-23  Rho     ESCAN00066008 Instead of FR_DEM_E_CTRLTESTRESULT Autosar 4 uses FrDemCtrlTestResultRef
 *            2013-05-06  Rho     ESCAN00067152 Implementation errors at Fr_GetNumOfStartupFrames
 *            2013-05-08  Rho     ESCAN00067249 Fr_GetNumOfStartupFrames() uses invalid DET service ID
 *                                ESCAN00067250 Fr_ReadCCConfig() uses invalid DET error ID to report an invalid Fr_ConfigParamIdx
 * 03.20.01   2013-06-04  Rho     ESCAN00067476 Fix revision history
 *            2013-06-05  Rho     ESCAN00064374 Compiler warning: cast increases required alignment of target type
 * 03.20.02   2013-06-26  Rho     ESCAN00067477 consistency check for GENy dll versions outdated
 *            2013-07-02  Rho     ESCAN00067410 Remove obsolete MTS APIs
 *            2013-07-05  Mmu     ESCAN00068787 RxIndication at Nm messages with FIFO
 * 03.20.03   2013-07-25  Rho     ESCAN00069343 Compiler error: Missing define FR_SIZE_MB_ARRAY at CanoeEmu
 * 03.20.04   2013-07-31  Rho     ESCAN00069432 MTS APIs missing 
 * 03.21.00   2013-08-02  Rho     ESCAN00067640 FrRxStringentCheck not implemented
 *                        Rho     ESCAN00068482 AR4-355: Support VIP/Dual Target
 *            2013-09-03  Rho     ESCAN00070199 RH850 wrong processor define
 *            2013-09-24  Rho     ESCAN00070620 AR4-328: Predefined Runtime Measurement Points
 *            2013-10-08  Rho     ESCAN00070805 AR4-569: Fr_ReceiveRxLPdu return value when FrRxStringentLengthCheck is true
 *            2013-10-09  Rho     ESCAN00070995 Invalid DET error ID at Fr_ReadCCConfig() 
 *            2013-10-31  Mmu     ESCAN00071532 Frames not transmitted in configurations where Buffer Reconfiguration is enabled
 * 03.21.01   2013-11-14  Rho     ESCAN00071957 identifier Fr_RxLPduStatusPtr is undefined
 *            2013-11-28  Rho     ESCAN00072491 API Change in VIP FR Controller
 * 03.21.02   2013-12-06  Rho     ESCAN00072485 FlexRay frames are not registered correctly in CANoe 8.0 SP5 or later
 * 03.21.03   2013-12-09  Rho     ESCAN00072504 Compiler error: Dependencies missing
 * 03.21.04   2013-12-10  Rho     ESCAN00072536 Use Dummy_Statements instead of Dummy_Functions
 *                                ESCAN00072848 Missing Interrupt configuration for Aurix
 * 03.21.05   2014-02-12  Rho     ESCAN00073634 Compiler error: Fr_CtrlIdx is undeclared
 * 03.21.06   2014-03-03  Rho     ESCAN00074014 Wrong register address at FR_MHDS, FR_MHDF
 *            2014-03-17  Rho     ESCAN00074172 Aurix: Interrupt Configuration must use osdEndInit API
 *            2014-03-24  Rho     ESCAN00073085 Tricore Aurix: Reset after Start-Up
 *            2014-06-12  Ore     ESCAN00075926 Compiler error: Errors in Fr_VWriteDataToCC when using feature for aligning unaligned messages
 *            2014-06-15  Ore     ESCAN00076300 Compiler warning: undefined preprocessing identifier FR_TX_CONFLICT_STATUS
 * 03.21.07   2014-07-07  Ore     ESCAN00076357 FR Driver is not accepting received Frames on CHB due to stringent check algorithm.
 * 03.22.00   2014-07-08  Ore     ESCAN00076818 Compiler error: "error LNK2019: unresolved external symbol Fr_InitMemory"
 *            2014-07-31  Ore     ESCAN00073080 Misalignment error with 8Bit-aligned memory at immediate transmits
 *            2014-09-12  Mmu     ESCAN00067905 Implement missing DET check for POC state
 *            2014-09-26  Mmu     ESCAN00079153 AR4-698: Post-Build Selectable (Identity Manager)
 * 03.22.01   2014-12-18  Ore     ESCAN00080371 Add support for FR81 derivat
 * 04.00.00   2015-01-14  Mmu     ESCAN00080342 Fr_GetWakeupRxStatus returns incorrect value for channel B
 *            2015-01-30  Mmu     ESCAN00080974 Fr_GetWakeupRxStatus returns always wakeup received on channel A if it was received once
 *            2015-03-12  Ore     ESCAN00081746 Missing Interrupt configuration for FR81
 *            2015-03-12  Ore     ESCAN00082568 Missing DET check implementation in several FR driver API services
 *            2015-03-12  Ore     ESCAN00082570 Wrong behaviour when calling Fr_GetGlobalTime and Fr_SetAbsoluteAlarmTimer while bus is not synchronous 
 *            2015-03-12  Ore     ESCAN00082571 Fr_GetSyncFrameList does not return a valid sync frame list
 *            2015-03-12  Ore     ESCAN00082567 FlexRay frames are not registered correctly and cannot be transmitted or received by the FR driver when 
 *                                              buffer reconfiguration is enabled
 *            2015-05-20  Ore     ESCAN00083083 Support Direct Buffer Access in CANoeEmu
 *            2015-05-20  Mmu     ESCAN00073879 Aurix Erratum: RateCorrection may be wrong at Fr_GetClockCorrection
 *            2015-07-01  Ore     ESCAN00083749 Compiler error: Unresolved symbol 'Fr_VTimeoutDuration'
 *            2015-07-30  Ore     ESCAN00083076 Wrong endianess used in copy function for FR81
 * 04.00.01   2015-08-14  Mmu     ESCAN00084558 Fr_ReceiveRxLPdu returns NOT_RECEIVED for a correctly received dual channel frame 
 *            2015-11-27  Mmu     ESCAN00085520 Support Safecontext / Usermode for TriCore
 *            2015-11-27  Mmu     ESCAN00085975 compiler error: due to missing define osdEndInitAPISupported
 *            2015-11-27  Ore     ESCAN00085224 FEAT-1486.33: Support simulated reset with VTT
 *            2015-11-27  Mmu     ESCAN00085957 FrRxStringentCheck is too generous
 *            2015-12-15  Mmu     ESCAN00087171 No FlexRay communication if FrIfReadCCConfigApi is enabled and ECU is integration node
 * 04.00.02   2016-02-11  Mmu     ESCAN00088310 Fr_AllowColdstart does not check POCstate properly
 *            2016-02-19  Mmu     ESCAN00088423 Fr_GetWakeupRxStatus indicates the occurrence of too many wakeup events
 * 04.00.03   2016-04-07  Mmu     -             Finalized SafeBSW
 * 04.00.04   2016-06-28  Mmu     ESCAN00090701 Compiler error: Unknown symbol 'int32'
 * 04.00.05   2016-11-07  Ore     -             Added XMb88121b support
 * 04.00.06   2016-12-13  Ore     ESCAN00091586 compiler warning: [13492] redundant redeclaration of 'Appl_UnlockInit' and 'Appl_LockInit' 
 -                                              with option [-Wredundant-decls]
 *            2016-12-13  Ore     ESCAN00093224 Compiler error: Linkage conflict with previous declaration Fr_VExecutePOCCommand
 *            2017-02-01  Mmu     ESCAN00093807 Abortion of FlexRay initialization sequence results in no communication
 * 04.01.00   2017-03-27  Mmu     FEATC-406: Dynamic configuration of PlatestTx
 *            2017-03-27  Mmu     FEATC-1076: Support two separate FR controllers
 * 05.00.00   2017-04-25  Chl     STORYC-38: Fr: Implement two controller support for CANoeEmu & VTTFr
 * 05.00.01   2017-06-22  Ore     ESCAN00095601 Compiler error C2008: '[' : unexpected in macro definition
 *            2017-06-22  Ore     ESCAN00095602 Compiler error C2065: 'Fr_BaseAddrOfCc' : undeclared identifier
 *            2017-06-22  Ore     ESCAN00095603 Compiler warning C4305: 'type cast' : truncation from 'const uint16 *const ' to 'uint16'
 *            2017-06-26  Ore     ESCAN00095638 Variables Fr_Params32Bit[], Fr_Params16Bit[] and Fr_Params8Bit[] are in wrong memory section
 *            2017-07-07  Ore     ESCAN00095803 Compiler warning: warning C4100: 'Fr_CtrlIdx' : unreferenced formal parameter
 *********************************************************************************************************************/

#ifndef FR_H
# define FR_H

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e537 */ /* Suppress ID537 due to MD_MSR_14.1 */

/**********************************************************************************************************************
* Filtered for DrvFr_V85xErayAsr 
**********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Fr_Ext.h"
#  include "Fr_ERay.h"
# if (FR_PROD_ERROR_DETECT == STD_ON)
#  include "Dem.h"
# endif
# if (FR_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif

/* ESCAN00070620 */
# if (FR_AMD_RUNTIME_MEASUREMENT == STD_ON)
#  include "Rtm.h"
# endif

/** \defgroup IF Embedded Interfaces
* \brief Module Fr offers hardware independent interfaces to a FlexRay Communication Controller.
* \{
*/
/** \defgroup LHAL LocalHardwareAbstractionLayer
* \brief Internally visible functions that are used independently from the hardware platform.
*/
/** \defgroup Fr_General Fr_General
*/
/** \defgroup Startup Startup
* \brief Provides functionality to startup a FlexRay Communication Controller and a FlexRay network.
*/
/** \defgroup Communication Communication
* \brief Provides functionality to communicate with a FlexRay network.
*/
/** \defgroup Timer Timer
* \brief Provides services to control absolute timers.
*/
/** \defgroup Status Status
* \brief Provides services to get status information from the FlexRay Communication Controller.
*/
/** \defgroup Shutdown Shutdown
* \brief Provides services to disconnect from a FlexRay network.
*/
/** \defgroup DBA DBA
* \brief The Direct Buffer Access services are non-AUTOSAR functions which allow an optimized RAM access to message 
*        buffer payload. This is only supported for MFR-based platforms and on CANoeEmu.
*/
/** \} */ 


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject :   DrvFr_XErayAsr CQComponent : Implementation */
# define DRVFR_XERAYASR_VERSION                                       0x0500u /* BCD coded version number */
# define DRVFR_XERAYASR_RELEASE_VERSION                               0x01u   /* BCD coded release version number  */

/* FR ModuleId */
# define FR_VENDOR_ID                                                 30u /* Vctr ID */
# define FR_MODULE_ID                                                 81u /* FlexRay Driver ID */

/* Implemented AUTOSAR Document Version */
# define FR_AR_VERSION                                                0x0204u
# define FR_AR_RELEASE_VERSION                                        0x00u

# define FR_GENERATOR_COMPATIBILITY_VERSION                           (uint16)0x0001u /* UREQ00035482 */
# define FR_FINAL_MAGICNUMBER                                         (uint16)0x5123U /* UREQ00035483 */

/* supported Autosar version */
# define FR_AR_MAJOR_VERSION                                          4u
# define FR_AR_MINOR_VERSION                                          0u
# define FR_AR_PATCH_VERSION                                          3u

# define FR_SW_MAJOR_VERSION                                          (DRVFR_XERAYASR_VERSION >> 8u)
# define FR_SW_MINOR_VERSION                                          (DRVFR_XERAYASR_VERSION & 0xFF)
# define FR_SW_PATCH_VERSION                                          (DRVFR_XERAYASR_RELEASE_VERSION)

/* Bit coding states */
# define FR_WAKEUPRX_ON_CHANNEL_A                                     ((uint8)(0x01U << 0))
# define FR_WAKEUPRX_ON_CHANNEL_B                                     ((uint8)(0x01U << 1))

/* Driver limitations */
# define FR_MAX_NUM_LPDU_LENGTH
# define FR_MAX_NUM_ABS_TIMER                                         1u
# define FR_MAX_NUM_REL_TIMER                                         1u

/* FR ApiIds */
# define FR_SID_CONTROLLER_INIT                                       0x00u
# define FR_SID_START_COMMUNICATION                                   0x03u
# define FR_SID_HALT_COMMUNICATION                                    0x04u
# define FR_SID_ABORT_COMMUNICATION                                   0x05u
# define FR_SID_SEND_WUP                                              0x06u
# define FR_SID_SET_WAKEUP_CHANNEL                                    0x07u
# define FR_SID_SET_EXT_SYNC                                          0x08u
# define FR_SID_GET_SYNC_STATE                                        0x09u
# define FR_SID_GET_POC_STATUS                                        0x0Au
# define FR_SID_CHECK_TX_LPDU_STATUS                                  0x0Du
# define FR_SID_GET_GLOBAL_TIME                                       0x10u
# define FR_SID_SET_ABSOLUTE_TIMER                                    0x11u
# define FR_SID_SET_RELATIVE_TIMER                                    0x12u
# define FR_SID_CANCEL_RELATIVE_TIMER                                 0x14u
# define FR_SID_CANCEL_ABSOLUTE_TIMER                                 0x13u
# define FR_SID_ENABLE_ABSOLUTE_TIMER_IRQ                             0x15u
# define FR_SID_ENABLE_RELATIVE_TIMER_IRQ                             0x16u
# define FR_SID_ACK_ABSOLUTE_TIMER_IRQ                                0x17u
# define FR_SID_ACK_RELATIVE_TIMER_IRQ                                0x18u
# define FR_SID_DISABLE_ABSOLUTE_TIMER_IRQ                            0x19u
# define FR_SID_DISABLE_RELATIVE_TIMER_IRQ                            0x1Au
# define FR_SID_GET_VERSION_INFO                                      0x1Bu
# define FR_SID_INIT                                                  0x1Cu
# define FR_SID_PREPARE_LPDU                                          0x1Fu
# define FR_SID_GET_ABSOLUTE_TIMER_IRQ_STATUS                         0x20u
# define FR_SID_GET_RELATIVE_TIMER_IRQ_STATUS                         0x21u
# define FR_SID_GET_NM_VECTOR                                         0x22u
# define FR_SID_ALLOW_COLDSTART                                       0x23u
# define FR_SID_RECONFIG_LPDU                                         0x25u
# define FR_SID_DISABLE_LPDU                                          0x26u
# define FR_SID_GET_CHANNEL_STATUS                                    0x28u
# define FR_SID_GET_CLOCK_CORRECTION                                  0x29u
# define FR_SID_GET_SYNC_FRAME_LIST                                   0x2Au
# define FR_SID_READCCCONFIG                                          0x2Eu
# define FR_SID_ALLSLOTS                                              0x24U
# define FR_SID_CANCELTXLPDU                                          0x2DU
# define FR_SID_GETNUMOFSTARTUPFRAMES                                 0x27u /* ESCAN00067249 */
# define FR_SID_GETWAKEUPRXSTATUS                                     0x2BU

#  define FR_SID_TRANSMIT_TX_LPDU                                     0x0Bu
#  define FR_SID_RECEIVE_RX_LPDU                                      0x0Cu

/* FR DET errors */
# define FR_E_NO_ERROR                                                0xFFu
# define FR_E_INV_TIMER_IDX                                           0x01u
# define FR_E_INV_POINTER                                             0x02u
# define FR_E_INV_OFFSET                                              0x03u
# define FR_E_INV_CTRL_IDX                                            0x04u
# define FR_E_INV_CHNL_IDX                                            0x05u
# define FR_E_INV_CYCLE                                               0x06u
# define FR_E_INV_CONFIG                                              0x07u
# define FR_E_NOT_INITIALIZED                                         0x08u
# define FR_E_INV_POCSTATE                                            0x09u
# define FR_E_INV_LENGTH                                              0x0Au
# define FR_E_INV_LPDU_IDX                                            0x0Bu
# define FR_E_INV_HEADERCRC                                           0x0Cu  /* ASR 4.0 */
# define FR_E_INV_CONFIG_IDX                                          0x0Du  /* ESCAN00067250 */
# define FR_E_INV_LISTSIZE                                            0x40u
# define FR_E_INV_SPACE_ALLOC                                         0x60u

/* Single Controller API optimization */
# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  define FR_VCTRL_SYSTEMTYPE_ONLY                                    void  /* PRQA S 3460 */ /* MD_MSR_19.4 */
#  define FR_VCTRL_SYSTEMTYPE_FIRST
# else
#  define FR_VCTRL_SYSTEMTYPE_ONLY                                    uint8 Fr_CtrlIdx
#  define FR_VCTRL_SYSTEMTYPE_FIRST                                   uint8 Fr_CtrlIdx,
# endif
  /* FR_CTRL_ENABLE_API_OPTIMIZATION */
# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  define FR_VTIMER_SYSTEMTYPE_ONLY                                   void  /* PRQA S 3460 */ /* MD_MSR_19.4 */
#  define FR_VTIMER_SYSTEMTYPE_FIRST
# else
#  define FR_VTIMER_SYSTEMTYPE_ONLY                                   uint8 Fr_TimerIdx
#  define FR_VTIMER_SYSTEMTYPE_FIRST                                  uint8 Fr_TimerIdx,
# endif
  /* FR_CTRL_ENABLE_API_OPTIMIZATION */

# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  define FR_VCTRL_IDX                                                0u
# else
#  define FR_VCTRL_IDX                                                Fr_CtrlIdx
# endif /* FR_ENABLE_API_OPTIMIZATION */

# define FR_ISR_CAT2                                                  0x00u
# define FR_ISR_CAT1                                                  0x01u
# define FR_ISR_VOID                                                  0x02u

/* communication controller ids, for all functions that need a controller id as input parameter */
# define FR_COM_CONTROLLER_0                                          (0)
# define FR_COM_CONTROLLER_1                                          (1)

#if !defined (STATIC) /* COV_FR_MSR_COMPATIBILITY */
# define STATIC static
#endif

#if !defined (LOCAL_INLINE) /* COV_FR_MSR_COMPATIBILITY */
# define LOCAL_INLINE INLINE STATIC
#endif

#if !defined (FR_LOCAL) /* COV_FR_MSR_COMPATIBILITY */
# define FR_LOCAL STATIC
#endif

#if !defined (FR_LOCAL_INLINE) /* COV_FR_MSR_COMPATIBILITY */
# define FR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

# if (FR_READ_CC_CONFIGURATION == STD_ON)
#  define FR_SIZEOF_LLPARM(index)                                     (((index) < FR_CC_CONFIG_PARAM_MAX32BIT) ? 4 :  \
                                                                      ((index) < (FR_CC_CONFIG_PARAM_MAX32BIT +       \
                                                                      FR_CC_CONFIG_PARAM_MAX16BIT)) ? 2 : 1)
# endif

# define Fr_VCCWriteRegister(Base, Reg, Val)                          (*((Fr_RegisterPtrType)((uint32)(Base)+(Reg))) = (Val))

/** \ingroup LHAL
* \{
*/
#if (FR_NUM_CTRL_USED > 1)
# define Fr_VCCGetRegStartAddr(Ctrl)                                  (uint32)Fr_BaseAddrOfCc[(Ctrl)]
#else
# define Fr_VCCGetRegStartAddr(Ctrl)                                  (uint32)FR_VCC_REG_START_ADDR
#endif

/* CC register access */
#  define Fr_VCCWriteValue(Ctrl, Reg, Val)                            (*((Fr_RegisterPtrType)(Fr_VCCGetRegStartAddr(Ctrl)+(Reg))) = (Val))
#  define Fr_VCCReadValue(Ctrl, Reg)                                  (*((Fr_RegisterPtrType)(Fr_VCCGetRegStartAddr(Ctrl)+(Reg))))
#  define Fr_VCCSetBits(Ctrl, Reg, Bits)                              (*((Fr_RegisterPtrType)(Fr_VCCGetRegStartAddr(Ctrl)+(Reg))) |= (Bits))
#  define Fr_VCCResetBits(Ctrl, Reg, Bits)                            (*((Fr_RegisterPtrType)(Fr_VCCGetRegStartAddr(Ctrl)+(Reg))) &= (~(Bits)))

/** \} */

# define Fr_VCCClearIrqStatusFlag(Ctrl, Flag)                         Fr_VCCWriteValue((Ctrl), FR_SIR, (Flag))

/* ESCAN00070620 */
# if (FR_AMD_RUNTIME_MEASUREMENT == STD_ON)
#  define Fr_Rtm_Start(measurement)                                   Rtm_Start(RtmConf_RtmMeasurementPoint_##measurement) /* PRQA S 0342 */ /* MD_Fr_0342 */
#  define Fr_Rtm_Stop(measurement)                                    Rtm_Stop(RtmConf_RtmMeasurementPoint_##measurement)  /* PRQA S 0342 */ /* MD_Fr_0342 */
# else
#  define Fr_Rtm_Start(measurement)
#  define Fr_Rtm_Stop(measurement)
# endif

# if !defined (FR_DUMMY_STATEMENT_CONST) /* COV_FR_MSR_COMPATIBILITY */
#  define FR_DUMMY_STATEMENT_CONST(statement)
# endif

# if !defined (FR_DUMMY_STATEMENT) /* COV_FR_MSR_COMPATIBILITY */
#  define FR_DUMMY_STATEMENT(statement)
# endif

# if !defined (FR_DEV_ERROR_REPORT) /* COV_FR_MSR_COMPATIBILITY */
#  define FR_DEV_ERROR_REPORT                                         FR_DEV_ERROR_DETECT
# endif

/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! \typedef Used to access memory mapped registers double wordwise */
typedef volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE) Fr_RegisterPtrType;

# if Fr_IsPreCompile() || (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) 
typedef uint8   Fr_VConfigType; /*!< \typedef Variables of this type are used to represent the Fr config structure */
typedef uint32  Fr_VCcRegValType; /*!< \typedef Variables of this type are used to represent the register values */
typedef uint16  Fr_VCcRegAddrType; /*!< \typedef Variables of this type are used to represent the register addresses */

typedef struct
{
  uint32 WRHS1; /*<! Write header section 1 */
  uint32 WRHS2; /*<! Write header section 2 */
  uint16 WRHS3; /*<! Write header section 3 */
  uint8  IBCR;  /*<! Target message buffer */
  uint8  Info;  /*<! BufferInfo */
} Fr_VCcBufType;

typedef struct
{
  uint16 crc;   /*<! First part of header CRC */
  uint8 mbIdx;  /*<! Refers to VCcBufs */
  uint8 Info;   /*<! Bit0=dynamicPayload, Bit1=mbReconfigureBuffer, Bit2=ReconfigLPdu */
} Fr_VTxVirtBuf2PhysBufMapType;

typedef struct
{
  uint8 mbIdx;      /*<! Refers to VCcBufs */
  uint8 cycleMask;  /*<! Cycle counter filter */
  uint8 cycleBase;  /*<! Cycle counter filter */
} Fr_VRxVirtBuf2PhysBufMapType;
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define FR_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* PRQA S 3684 ARRAYSIZE */ /* MD_Fr_8.12 */
extern CONST(uint32, FR_CONST)                          Fr_BaseAddrOfCc[];


# if ((FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE ) || (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME))
#  if (FR_PROD_ERROR_DETECT == STD_ON)
extern CONST(Dem_EventIdType, FR_CONST)                 Fr_DEM_E_Access;
extern CONST(Dem_EventIdType, FR_CONST)                 Fr_DEM_E_CtrlTestResult;
#  endif
# endif

#  define FR_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# if !(Fr_IsPostbuild())
# define FR_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

extern CONST(Fr_VConfigType, FR_CONST)                  Fr_Config;
extern CONST(Fr_VCcRegValType, FR_CONST)                Fr_VCcRegVals[];  /*<! CC register values */
extern CONST(Fr_VCcRegAddrType, FR_CONST)               Fr_VCcRegAddrs[]; /*<! CC register addresses */
extern CONST(Fr_VCcBufType, FR_CONST)                   Fr_VCcBufs[];     /*<! physical buffer configuration */
extern CONST(Fr_VRxVirtBuf2PhysBufMapType, FR_CONST)    Fr_VRxVirtBuf2PhysBufMap[]; /*<! virtual Rx buffer mapping */
extern CONST(Fr_VTxVirtBuf2PhysBufMapType, FR_CONST)    Fr_VTxVirtBuf2PhysBufMap[]; /*<! virtual Tx buffer mapping */

#  define FR_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#  if (FR_READ_CC_CONFIGURATION == STD_ON)
#   define FR_START_SEC_CONST_8BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint8, FR_CONST)                           Fr_VCCConfigParam8Bit[]; /*<! configuration parameters of size byte */
extern CONST(uint8, FR_CONST)                           Fr_VCCConfigParam8Bit_1[]; /*<! configuration parameters of size byte */
#   define FR_STOP_SEC_CONST_8BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_16BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint16, FR_CONST)                          Fr_VCCConfigParam16Bit[]; /*<! configuration parameters of size word */
extern CONST(uint16, FR_CONST)                          Fr_VCCConfigParam16Bit_1[]; /*<! configuration parameters of size word */
#   define FR_STOP_SEC_CONST_16BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_32BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint32, FR_CONST)                          Fr_VCCConfigParam32Bit[]; /*<! configuration parameters of size double word */
extern CONST(uint32, FR_CONST)                          Fr_VCCConfigParam32Bit_1[]; /*<! configuration parameters of size double word */
#   define FR_STOP_SEC_CONST_32BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
#  endif /* (FR_READ_CC_CONFIGURATION == STD_ON) */

#  if ( FR_VENABLE_MID_FILTERING == STD_ON )
#   define FR_START_SEC_CONST_16BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint16, FR_CONST)                          Fr_VMsgIdFilterMap[]; /*<! message ID filter values */
#   define FR_STOP_SEC_CONST_16BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
#  endif
#  if (FR_NUM_CTRL_USED > 1)
#   define FR_START_SEC_CONST_UNSPECIFIED
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint32*, FR_CONST)                         Fr_CtrlRegs[];
extern CONST(Fr_VCcBufType*, FR_CONST)                  Fr_CcBufs[];
extern CONST(Fr_VTxVirtBuf2PhysBufMapType*, FR_CONST)   Fr_TxVirt2PhysBuf[];
extern CONST(Fr_VRxVirtBuf2PhysBufMapType*, FR_CONST)   Fr_RxVirt2PhysBuf[];
#   define FR_STOP_SEC_CONST_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_8BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint8, FR_CONST)                           Fr_VNumCcRegs[];  /*<! number of registers */
extern CONST(uint8, FR_CONST)                           Fr_VNumCcBufs[];  /*<! number of physical buffers */
#   if ( FR_NMVECTOR_ENABLE == STD_ON )
extern CONST(uint8, FR_CONST)                           Fr_NmVectorLength[];  /*<! length of Nm vector */
#   endif
#   define FR_STOP_SEC_CONST_8BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_UNSPECIFIED
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
#   if (FR_READ_CC_CONFIGURATION == STD_ON)
extern CONST(uint8*, FR_CONST)                          Fr_Params8Bit[];
#   endif
#   define FR_STOP_SEC_CONST_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_16BIT
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint16, FR_CONST)                          Fr_VNumRxVirtBuf2PhysBufs[];  /*<! number of Rx triggerings */
extern CONST(uint16, FR_CONST)                          Fr_VNumTxVirtBuf2PhysBufs[];  /*<! number of Tx triggerings */
#   if ( FR_VENABLE_MID_FILTERING == STD_ON )
extern CONST(uint16, FR_CONST)                          Fr_VNumMIDs;  /*<! number of message IDs */
extern CONST(uint16, FR_CONST)                          Fr_VLastStaticFrameID[];  /*<! ID of last static frame */
#   endif
#   define FR_STOP_SEC_CONST_16BIT
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#   define FR_START_SEC_CONST_UNSPECIFIED
#   include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
#   if (FR_READ_CC_CONFIGURATION == STD_ON)
extern CONST(uint16*, FR_CONST)                         Fr_Params16Bit[];
#   endif

#   if (FR_READ_CC_CONFIGURATION == STD_ON)
extern CONST(uint32*, FR_CONST)                         Fr_Params32Bit[];
#   endif
#   define FR_STOP_SEC_CONST_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#  else /* Single Controller */

#   if (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) /* && (FR_NUM_CTRL_USED > 1) */ /* COV_FR_UNSUPPORTED_SAFEBSW_FEATURE */
#    define FR_START_SEC_CONST_8BIT
#    include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint8, FR_CONST)                           Fr_VNumCcRegs;  /*<! number of registers */
extern CONST(uint8, FR_CONST)                           Fr_VNumCcBufs;  /*<! number of physical buffers */
#    if (FR_NMVECTOR_ENABLE == STD_ON)
extern CONST(uint8, FR_CONST)                           Fr_NmVectorLength;  /*<! length of Nm vector */
#    endif
#    if (FR_CC_READ_BACK_SUPPORT == STD_ON)
extern CONST(uint8, FR_CONST)                           Fr_CtrlTestCount; /*<! max number of ReadBackSupport runs */
#    endif
#    define FR_STOP_SEC_CONST_8BIT
#    include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#    define FR_START_SEC_CONST_16BIT
#    include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
extern CONST(uint16, FR_CONST)                          Fr_VNumRxVirtBuf2PhysBufs;  /*<! number of Rx triggerings */
extern CONST(uint16, FR_CONST)                          Fr_VNumTxVirtBuf2PhysBufs;  /*<! number of Tx triggerings */
#    if ( FR_VENABLE_MID_FILTERING == STD_ON )
extern CONST(uint16, FR_CONST)                          Fr_VNumMIDs;  /*<! number of message IDs */
extern CONST(uint16, FR_CONST)                          Fr_VLastStaticFrameID;  /*<! ID of last static frame */
#    endif /* ( FR_VENABLE_MID_FILTERING == STD_ON ) */
#    define FR_STOP_SEC_CONST_16BIT
#    include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */
#   endif /* (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME) */
#  endif /* Single Controller */

# endif /* ((FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_PRECOMPILE) && (FR_POSTBUILD_VARIANT_SUPPORT == STD_OFF)) || (FR_CONFIGURATION_VARIANT == FR_CONFIGURATION_VARIANT_LINKTIME)  */


/* PRQA L:ARRAYSIZE */ /* MD_Fr_8.12 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FR_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  Fr_Init()
 *********************************************************************************************************************/
/*! \brief        Initializes component.
 *  \details      This API call stores the start address of the post build time configuration of the FlexRay driver, 
 *                resets all FlexRay CCs controlled by the driver and initializes the data structures of the FlexRay 
 *                driver.
 *  \param[in]    Fr_ConfigPtr            Configuration structure for initializing the module
 *  \pre          Fr_InitMemory has been called unless Fr_VFrDrvState is initialized by start-up code.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Fr_General
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_Init(P2CONST(Fr_ConfigType, AUTOMATIC, FR_PBCFG) Fr_ConfigPtr);

/**********************************************************************************************************************
 *  Fr_ControllerInit()
 *********************************************************************************************************************/
/*! \brief        Initializes a FlexRay CC.
 *  \details      Switches CC into POCstate CONFIG, configures all FlexRay cluster and node configuration parameters, 
 *                configures all physical message buffers according to FrIf frame triggerings and finally switches CC 
 *                into POCstate READY.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - controller initialization failed (CC parameter readback failed)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         Contrary to AUTOSAR spec, disabling of timers is not guaranteed,
 *                as the configuration of the timers is part of the Fr_LowLevelConfSetIdx
 *                in the current solution. Additionally, Fr_LowLevelConfSetIdx contains
 *                initial values for interrupt configuration
 *  \ingroup      Startup
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(FR_VCTRL_SYSTEMTYPE_ONLY);


/**********************************************************************************************************************
 *  Fr_StartCommunication()
 *********************************************************************************************************************/
/*! \brief        Start communication.
 *  \details      Triggers transition from POCstate READY to POCstate STARTUP which is a transitional state. 
 *                In the case when communication startup succeeds, the CC will change the POCstate to NORMAL_ACTIVE 
 *                or NORMAL_PASSIVE.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         It is not guaranteed that the FlexRay CC will reside in the POCstate NORMAL_ACTIVE or PASSIVE after 
 *                a call of this function.
 *  \ingroup      Startup
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_AllowColdstart()
 *********************************************************************************************************************/
/*! \brief        Invokes the CC CHI command 'ALLOW_COLDSTART'.
 *  \details      Trigger transition from POCstate READY to STARTUP using coldstart node path.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Startup
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_HaltCommunication()
 *********************************************************************************************************************/
/*! \brief        Invokes the CC CHI command 'DEFERRED_HALT'.
 *  \details      Requests the halt state which is reached at the latest by the end of the current FlexRay communication 
 *                cycle.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Shutdown
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_AbortCommunication()
 *********************************************************************************************************************/
/*! \brief        Invokes the CC CHI command 'FREEZE'.
 *  \details      Invokes the CC CHI command 'FREEZE', which immediately aborts communication (if active) and waits until
 *                CC is in POCstate HALT.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Shutdown
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_SendWUP()
 *********************************************************************************************************************/
/*! \brief        Invokes the CC CHI command 'WAKEUP'.
 *  \details      Initiates the wakeup transmission procedure on the configured FlexRay channel.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         The function Fr_SendWUP changes the CC Fr_CtrlIdx POCState to WAKEUP, which is a transitional 
 *                state. After completion of wakeup procedure, the CC will reach POCstate READY again.
 *  \ingroup      Startup
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(FR_VCTRL_SYSTEMTYPE_ONLY);

/**********************************************************************************************************************
 *  Fr_SetWakeupChannel()
 *********************************************************************************************************************/
/*! \brief        Sets a wakeup channel.
 *  \details      Changes the CC's POCstate to CONFIG, configures the wakeup channel according to parameter Fr_ChnlIdx 
 *                and changes back to POCstate READY.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_ChnlIdx              FlexRay channel [FR_CHANNEL_A, FR_CHANNEL_B]
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Startup
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  Fr_ChannelType Fr_ChnlIdx
);

/**********************************************************************************************************************
 *  Fr_GetPOCStatus()
 *********************************************************************************************************************/
/*! \brief        Gets the POC status.
 *  \details      Queries the CC's current POC status and writes the result to parameter Fr_POCStatusPtr.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[out]   Fr_POCStatusPtr         Pointer to POC status structure
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr
);

/**********************************************************************************************************************
 *  Fr_TransmitTxLPdu()
 *********************************************************************************************************************/
/*! \brief        Transmits data on the FlexRay network.
 *  \details      Figures out the physical message buffer mapped to the tranmission of the FlexRay frame identified by 
 *                Fr_LPduIdx and activates it for transmission.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame. 
 *  \param[in]    Fr_LPduPtr              This reference points to a buffer where the assembled LSdu to be transmitted 
 *                                        within this LPdu is stored at. 
 *  \param[in]    Fr_LPduLength           Determines the length of the data (in Bytes) to be transmitted. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (register access failed)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint16 Fr_LPduIdx,
  P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LPduPtr,
  uint8 Fr_LPduLength
);




/**********************************************************************************************************************
 *  Fr_ReceiveRxLPdu()
 *********************************************************************************************************************/
/*! \brief          Receives data from the FlexRay network.
 *  \details        Figures out the physical message buffer or FIFO mapped to the reception of the FlexRay frame 
 *                  identified by Fr_LPduIdx. Copies the payload data to Fr_LPduPtr if new data has been received, 
 *                  stores the number of bytes to Fr_LPduLengthPtr and the status to Fr_LPduStatusPtr.
 *  \param[in]      Fr_CtrlIdx            Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]      Fr_LPduIdx            This index is used to uniquely identify a FlexRay frame.
 *  \param[in]      Fr_LPduPtr            This reference points to the buffer where the LSdu to be received shall be 
 *                                        stored. 
 *  \param[out]     Fr_LPduStatusPtr      This reference points to the memory location where the status of the LPdu 
 *                                        shall be stored.
 *  \param[in,out]  Fr_LPduLengthPtr      This reference points to the memory location where the length of the LSdu 
 *                                        (in bytes) shall be stored. This length represents the number of bytes copied 
 *                                        to Fr_LSduPtr. 
 *  \return         E_OK                  - success
 *  \return         E_NOT_OK              - API aborted due to errors (register access failed)
 *  \pre            -
 *  \context        TASK|ISR1|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Contrary to the AUTOSAR spec, this functions expects Fr_LPduLengthPtr to contain the frame length. 
 *                  Only the number of bytes given by Fr_LPduLengthPtr is copied. At the end of the function 
 *                  Fr_LPduLengthPtr returns the amount of copied bytes.
 *  \ingroup        Communication
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint16 Fr_LPduIdx,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr,
  P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduLengthPtr
);



/**********************************************************************************************************************
 *  Fr_CheckTxLPduStatus()
 *********************************************************************************************************************/
/*! \brief        Checks the transmit status of a FlexRay frame.
 *  \details      Figures out the physical message buffer mapped to the transmission of the FlexRay frame identified by 
 *                Fr_LPduIdx, checks whether the transmission is pending and stores the status to Fr_TxLPduStatusPtr.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame.
 *  \param[out]   Fr_TxLPduStatusPtr      This reference is used to store the transmit status of the LPdu.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (register access failed)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint16 Fr_LPduIdx,
  P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr
);

/**********************************************************************************************************************
 *  Fr_PrepareLPdu()
 *********************************************************************************************************************/
/*! \brief        Prepares a frame.
 *  \details      Figures out the physical message buffer mapped to the processing of the FlexRay frame identified by 
 *                Fr_LPduIdx, configures the buffer appropriate for Fr_LPduIdx operation
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame.
 *  \return       E_OK                    - success
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
# define Fr_PrepareLPdu(Fr_CtrlIdx, Fr_LPduIdx)                      ((Std_ReturnType) E_OK)  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  Fr_GetGlobalTime()
 *********************************************************************************************************************/
/*! \brief        Gets the current global FlexRay time.
 *  \details      Read the current global FlexRay time and write it to the output parameters Fr_CyclePtr and 
 *                Fr_MacrotickPtr.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[out]   Fr_CyclePtr             Pointer to the address where the current FlexRay communication cycle value 
 *                                        shall be stored. 
 *  \param[out]   Fr_MacroTickPtr         Pointer to the address where the current macrotick value shall be stored. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \synchronous  TRUE
 *  \reentrant    FALSE
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8,  AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr
);

/**********************************************************************************************************************
 *  Fr_GetNmVector()
 *********************************************************************************************************************/
/*! \brief        Gets the network management vector of the last communication cycle.
 *  \details      Reads the current accrued network management vector out of the FlexRay CC and then write it to the 
 *                output parameter Fr_NmVectorPtr. The number of bytes written to the output parameter is known at
 *                configuration time (-> FrIfGNetworkManagementVectorLength)
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[out]   Fr_NmVectorPtr          Pointer to the address where the NmVector of the last communication cycle 
 *                                        shall be stored. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \synchronous  TRUE
 *  \reentrant    FALSE
 *  \config       FR_NMVECTOR_ENABLE
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
# if (FR_NMVECTOR_ENABLE == STD_ON)
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr
);
# endif

/***********************************************************************************************************************
 *  Fr_SetAbsoluteTimer
 **********************************************************************************************************************/
/*! \brief        Configures and starts an absolute timer interrupt.
 *  \details      Configures the absolute timer interrupt according the given Fr_Cycle and Fr_Offset and starts the absolute
 *                timer.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \param[in]    Fr_Cycle                Absolute cycle the timer shall elapse in. 
 *  \param[in]    Fr_Offset               Offset within cycle Fr_Cycle in units of macrotick the timer shall elapse at. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         This method does not turn "on" or "off" the affected timer IRQ!!!
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx, uint8 Fr_Cycle, uint16 Fr_Offset);

/***********************************************************************************************************************
 *  Fr_CancelAbsoluteTimer
 **********************************************************************************************************************/
/*! \brief        Cancels the absolute timer.
 *  \details      Cancels and stops the absolute timer by clearing the timer run flag.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);

/***********************************************************************************************************************
 *  Fr_EnableAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief        Enables the absolute timer interrupt.
 *  \details      Do actually nothing because absolute timer is already enabled by Fr_ControllerInit().
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);

/***********************************************************************************************************************
 *  Fr_AckAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief        Acknowledges the absolute timer interrupt.
 *  \details      Clears the absolute timer status flag to acknowledge the timer interrupt.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_ABSOLUTE_TIMER_DISABLE
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
# if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);
# endif
      /* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_DisableAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief        Disables the absolute timer interrupt.
 *  \details      Do nothing because absolute timer it may not be disabled at runtime. Otherwise the FRIF job list 
 *                execution would not work.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_ABSOLUTE_TIMER_DISABLE
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
# if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);
# endif
      /* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_GetAbsoluteTimerIRQStatus
 **********************************************************************************************************************/
/*! \brief        Returns the absolut timer interrupt status flag.
 *  \details      Returns the status flag of the absolute timer to indicate whether an timer interrupt occurred or not.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_AbsTimerIdx          Index of absolute timer within the context of the FlexRay CC. 
 *  \param[out]   Fr_IRQStatusPtr         Pointer to the address where the IRQ-status value is stored to. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_ABSOLUTE_TIMER_DISABLE
 *  \ingroup      Timer
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
# if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint8 Fr_AbsTimerIdx,
  P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr
);
# endif
/* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief        Returns the version information.
 *  \details      Fr_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]   Fr_VersionInfoPtr       Pointer to where to store the version information. Parameter must not be NULL.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_VERSION_INFO_API 
 *  \ingroup      Fr_General
 *  \trace        SPEC-9544, SPEC-42543
 *  \trace        CREQ-108238
 **********************************************************************************************************************/
# if (FR_VERSION_INFO_API == STD_ON)
extern FUNC(void, FR_CODE) Fr_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) Fr_VersionInfoPtr);
# endif



# if (FR_READ_CC_CONFIGURATION == STD_ON)
/***********************************************************************************************************************
 *  Fr_ReadCCConfig
 **********************************************************************************************************************/
/*! \brief        Reads a CC configuration parameter.
 *  \details      Reads a FlexRay protocol configuration parameter for a particular FlexRay controller out of the 
 *                module's configuration. 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_ConfigParamIdx       Index that identifies the configuration parameter to read. 
 *                                        See macros FR_CIDX_<config_parameter_name>. 
 *  \param[out]   Fr_ConfigParamValuePtr  Pointer to the address where the configuration parameter value is stored to. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_READ_CC_CONFIGURATION
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_ConfigParamIdx,
                                                     P2VAR(uint32, AUTOMATIC, FR_APPL_DATA) Fr_ConfigParamValuePtr);
# endif

/***********************************************************************************************************************
 *  Fr_CancelTxLPdu
 **********************************************************************************************************************/
/*! \brief        Cancels a pending transmission of a L-PDU.
 *  \details      Cancels the already pending transmission of a L-PDU contained in a controllers physical 
 *                transmit resource (e.g. message buffer). 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (transmission flag not pending or register access failed)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu(FR_VCTRL_SYSTEMTYPE_FIRST uint16 Fr_LPduIdx);

/***********************************************************************************************************************
 *  Fr_AllSlots
 **********************************************************************************************************************/
/*! \brief        Triggers the transition from single-slot to all-slot mode.
 *  \details      Triggers the transition from single slot to all slot mode. As consequence all frames (not only the 
 *                frame in the key-slot) will be transmitted calling this API service.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate or POC command not accepted)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE)Fr_AllSlots(FR_VCTRL_SYSTEMTYPE_ONLY);

# if (FR_VCHANNEL_STATUS_EXT == STD_ON)
/***********************************************************************************************************************
 *  Fr_GetChannelStatus
 **********************************************************************************************************************/
/*! \brief        Reads the aggregated channel status information.
 *  \details      Reads the aggregated channel status information of the given CC. 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out]   Fr_ChannelAStatusPtr    Address where the bitcoded aggregated channel status information shall be stored.
 *  \param[out]   Fr_ChannelBStatusPtr    Address where the bitcoded aggregated channel status information shall be stored.
 *                                            Bit 0: Channel A/B aggregated channel status vSS!ValidFrame
 *                                            Bit 1: Channel A/B aggregated channel status vSS!SyntaxError
 *                                            Bit 2: Channel A/B aggregated channel status vSS!ContentError
 *                                            Bit 3: Channel A/B aggregated channel status additional communication
 *                                            Bit 4: Channel A/B aggregated channel status vSS!Bviolation
 *                                            Bit 5: Channel A/B aggregated channel status vSS!TxConflict
 *                                            Bit 6: Not used (0)
 *                                            Bit 7: Not used (0)
 *                                            Bit 8: Channel A/B symbol window status data vSS!ValidMTS
 *                                            Bit 9: Channel A/B symbol window status data vSS!SyntaxError
 *                                            Bit 10: Channel A/B symbol window status data vSS!Bviolation
 *                                            Bit 11: Channel A/B symbol window status data vSS!TxConflict
 *                                            Bit 12: Channel A/B NIT status data vSS!SyntaxError
 *                                            Bit 13: Channel A/B NIT status data vSS!Bviolation
 *                                            Bit 14: Not used (0)
 *                                            Bit 15: Not used (0)
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_VCHANNEL_STATUS_EXT
 *  \note         Calling this API service resets the aggregated channel status information of the CC for this FR cycle. 
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr
);
# endif /* (FR_VCHANNEL_STATUS_EXT == STD_ON) */

# if ( FR_GET_CLOCK_CORRECTION_EXT == STD_ON )
/***********************************************************************************************************************
 *  Fr_GetClockCorrection
 **********************************************************************************************************************/
/*! \brief        Gets the current clock correction values.
 *  \details      Reads the Rate and Offset Correction values the given communication controller.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out]   Fr_RateCorrectionPtr    Pointer to the address where the current rate correction value shall be stored.
 *  \param[out]   Fr_OffsetCorrectionPtr  Pointer to the address where the current offset correction value shall be stored.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_GET_CLOCK_CORRECTION_EXT
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr,
  P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr
);
# endif

# if ( FR_GETSYNCFRAMELIST_API == STD_ON )
/***********************************************************************************************************************
 *  Fr_GetSyncFrameList
 **********************************************************************************************************************/
/*! \brief        Gets a list of syncframes.
 *  \details      Gets a list of syncframes received or transmitted on channel A and channel B via the even and odd 
 *                communication cycle.  
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[in]    Fr_ListSize             Size of the arrays passed via parameters: 
 *                                          Fr_ChannelAEvenListPtr 
 *                                          Fr_ChannelBEvenListPtr 
 *                                          Fr_ChannelAOddListPtr 
 *                                          Fr_ChannelBOddListPtr. 
 *                                        The service must ensure to not write more entries into those arrays than granted 
 *                                        by this parameter. range: 1..15
 *  \param[out]   Fr_ChannelAEvenListPtr  Pointer to list of syncframes on channel A within the even communication cycle
 *                                        is written to.
 *  \param[out]   Fr_ChannelBEvenListPtr  Pointer to list of syncframes on channel B within the even communication cycle 
 *                                        is written to.
 *  \param[out]   Fr_ChannelAOddListPtr   Pointer to list of syncframes on channel A within the odd communication cycle 
 *                                        is written to.
 *  \param[out]   Fr_ChannelBOddListPtr   Pointer to list of syncframes on channel B within the odd communication cycle 
 *                                        is written to.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong parameters)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_GETSYNCFRAMELIST_API
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint8 Fr_ListSize,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAEvenListPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBEvenListPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAOddListPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBOddListPtr
);
# endif

# if (FR_DISABLELPDUSUPPORT == STD_ON)
/***********************************************************************************************************************
 *  Fr_DisableLPdu
 **********************************************************************************************************************/
/*! \brief        Disables the L-PDU.
 *  \details      Disables the hardware resource of a L-PDU for transmission/reception. 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (register access failed or L-PDU not reconfigurable)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_DISABLELPDUSUPPORT
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu(FR_VCTRL_SYSTEMTYPE_FIRST uint16 Fr_LPduIdx);
# endif

# if (FR_RECONFIGLPDUSUPPORT == STD_ON)
/***********************************************************************************************************************
 *  Fr_ReconfigLPdu
 **********************************************************************************************************************/
/*! \brief        Reconfigures and enables the L-PDU.
 *  \details      Reconfigures a given L-PDU according to the parameters (FrameId, Channel, CycleRepetition, CycleOffset, 
 *                PayloadLength, HeaderCRC) at runtime. 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver. range: 0
 *  \param[in]    Fr_LPduIdx              This index is used to uniquely identify a FlexRay frame.
 *  \param[in]    Fr_FrameId              FlexRay Frame ID the FrIf_LPdu shall be configured to.
 *  \param[in]    Fr_ChnlIdx              FlexRay Channel the FrIf_LPdu shall be configured to.
 *  \param[in]    Fr_CycleRepetition      Cycle Repetition part of the cycle filter mechanism FrIf_LPdu shall be configured to. range: 2^x, x={0..6}
 *  \param[in]    Fr_CycleOffset          Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall be configured to. range: 0..63, 
 *                                        but Fr_CycleOffset < Fr_CycleRepetition
 *  \param[in]    Fr_PayloadLength        Payloadlength in units of bytes the FrIf_LPduIdx shall be configured to. range: 0..254, 
 *                                        but always less equal than the initially configured length for this FrIf_LPduIdx
 *  \param[in]    Fr_HeaderCRC            Header CRC the FrIf_LPdu shall be configured to.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (register access failed or L-PDU not reconfigurable)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_RECONFIGLPDUSUPPORT
 *  \ingroup      Communication
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu(FR_VCTRL_SYSTEMTYPE_FIRST
   uint16 Fr_LPduIdx,
   uint16 Fr_FrameId,
   Fr_ChannelType Fr_ChnlIdx,
   uint8 Fr_CycleRepetition,
   uint8 Fr_CycleOffset,
   uint8 Fr_PayloadLength,
   uint16 Fr_HeaderCRC );

# endif

/***********************************************************************************************************************
 *  Fr_GetNumOfStartupFrames 
 **********************************************************************************************************************/
/*! \brief        Gets the current number of startup frames seen on the cluster. 
 *  \details      Returns the number of received startup frames. The driver returns only the value two in case the
 *                hardware doesn't support accumulating the number of startup frames. 
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out]   Fr_NumOfStartupFramesPtr Pointer to the address where the number of startup frames seen within the last 
 *                                        even/odd cycle pair shall be stored.
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (wrong POCstate)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NumOfStartupFramesPtr
);

/***********************************************************************************************************************
 *  Fr_GetWakeupRxStatus
 **********************************************************************************************************************/
/*! \brief        Gets the wakeup received information from the FlexRay CC.
 *  \details      Reads and resets the wakeup status flags of the interrupt status register to indicate whether a wakeup
 *                event occured on either FlexRay channel A or channel B.
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out]   Fr_WakeupRxStatusPtr    Address where bitcoded wakeup reception status shall be stored. 
 *                                          Bit 0: Wakeup received on channel A indicator 
 *                                          Bit 1: Wakeup received on channel B indicator 
 *                                          Bit 2-7: Unused 
 *  \return       E_OK                    - success
 *  \return       E_NOT_OK                - API aborted due to errors (register access failed)
 *  \pre          -
 *  \context      TASK|ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Status
 *  \trace        SPEC-9544, SPEC-42543
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_WakeupRxStatusPtr
);


/***********************************************************************************************************************
 *  Fr_InitMemory
 **********************************************************************************************************************/
/*! \brief        Initializes global variables at startup.
 *  \details      Service to initialize module global variables at power up. This function initializes the variables in 
 *                *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Fr_General
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_InitMemory(void);


#  if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)  /* COV_FR_TESTSUITE_INSTRUMENTATION */
/***********************************************************************************************************************
 *  Fr_ISR_Status
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine.
 *  \details      FlexRay interrupt handles that processes:
 *                  - RX-Irq: get BufferIdx and map it to FrIf buffer and call FrIfRx function
 *                  - TX-Irq: get BufferIdx and map it to FrIf buffer and call FrIfTx function
 *                  - CycleStart-Irq: call FrIfc CycleStart function
 *  \param[in]    Fr_CtrlIdx              Index of FlexRay CC within the context of the FlexRay Driver.
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_APPL_CALLBACK_CYCLE_START
 *  \note         Called by Fr_IrqLine0 in fr_irq.c
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_ISR_Status(FR_VCTRL_SYSTEMTYPE_ONLY);
#  endif


# define FR_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**************************************************************************************************
*                ISR EXTENSION
**************************************************************************************************/
# define FR_START_SEC_CODE_ISR
# include "MemMap.h"



#   if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )  /* COV_FR_UNSUPPORTED_ISR_TYPE */
#    if(FR_CFG_STATUS_ISR_LINE == 0)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
/***********************************************************************************************************************
 *  Fr_IrqLine0
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for interrupt line 0.
 *  \details      Executes the status interrupts of ERay. By default cycle start interrupt are used by Fr ERay to synchronize 
 *                Application with callback function ApplFr_ISR_CycleStart.  
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_STATUS_ISR_LINE == 0
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine0(void);
#    else
/***********************************************************************************************************************
 *  Fr_IrqLine1
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for interrupt line 1.
 *  \details      Executes the status interrupts of ERay. By default cycle start interrupt are used by Fr ERay to synchronize 
 *                Application with callback function ApplFr_ISR_CycleStart.  
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_STATUS_ISR_LINE == 1
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine1(void);
#    endif /*FR_CFG_STATUS_ISR_LINE == 0*/
#   endif /*( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )*/

#   if (FR_NUM_CTRL_USED > 1)
#    if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )  /* COV_FR_UNSUPPORTED_ISR_TYPE */
#     if(FR_CFG_STATUS_ISR_LINE_1 == 0)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
/***********************************************************************************************************************
 *  Fr_IrqLine0_1
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for interrupt line 0.
 *  \details      Executes the status interrupts of ERay. By default cycle start interrupt are used by Fr ERay to synchronize 
 *                Application with callback function ApplFr_ISR_CycleStart_1.  
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_STATUS_ISR_LINE == 0
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine0_1(void);
#    else
/***********************************************************************************************************************
 *  Fr_IrqLine1_1
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for interrupt line 1.
 *  \details      Executes the status interrupts of ERay. By default cycle start interrupt are used by Fr ERay to synchronize 
 *                Application with callback function ApplFr_ISR_CycleStart_1.  
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       FR_CFG_STATUS_ISR_LINE == 1
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine1_1(void);
#     endif
#    endif
#   endif

#   if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )  /* COV_FR_UNSUPPORTED_ISR_TYPE */
/***********************************************************************************************************************
 *  Fr_IrqTimer0
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for the absolute timer.
 *  \details      Executes the Timer0 interrupt of ERay. By default this interrupt is used by Fr ERay to indicate the the 
 *                absolute timer expired. It also acknowledges the absolute timer interrupt. 
 *                A separate interrupt for Timer0 is called by hardware and interrupt splitting is used. 
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqTimer0(void);


#    if (FR_NUM_CTRL_USED > 1)
/***********************************************************************************************************************
 *  Fr_IrqTimer0_1
 **********************************************************************************************************************/
/*! \brief        Interrupt Handler Routine for the absolute timer.
 *  \details      Executes the Timer0 interrupt of ERay. By default this interrupt is used by Fr ERay to indicate the the 
 *                absolute timer expired. It also acknowledges the absolute timer interrupt. 
 *                A separate interrupt for Timer0 is called by hardware and interrupt splitting is used. 
 *  \pre          -
 *  \context      ISR1|ISR2
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \ingroup      Communication
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE_ISR) Fr_IrqTimer0_1(void);
#    endif
#   endif /*( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )*/


# define FR_STOP_SEC_CODE_ISR
# include "MemMap.h"

/** \} */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 MISRA_SINGLE_API */ /* MD_MSR_19.7 */

/* Single Controller API optimization */
# if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON)
#  define Fr_ControllerInit(Fr_CtrlIdx)                               Fr_ControllerInit()      

#  if !defined (FR_SOURCE) /* COV_FR_SOURCE */
#   define Fr_StartCommunication(Fr_CtrlIdx)                          Fr_StartCommunication()  
#   define Fr_AllowColdstart(Fr_CtrlIdx)                              Fr_AllowColdstart()      
#   define Fr_HaltCommunication(Fr_CtrlIdx)                           Fr_HaltCommunication()   
#   define Fr_AbortCommunication(Fr_CtrlIdx)                          Fr_AbortCommunication()  
#   define Fr_SendWUP(Fr_CtrlIdx)                                     Fr_SendWUP()             
#   define Fr_ISR(Fr_CtrlIdx)                                         Fr_ISR()                 
#   define Fr_ISR_Status(Fr_CtrlIdx)                                  Fr_ISR_Status() 
#   define Fr_ISR_Timer1(Fr_CtrlIdx)                                  Fr_ISR_Timer1() 
#  endif /* #if !defined (FR_SOURCE) */

#  define Fr_VExecutePOCCommand(Fr_CtrlIdx, Fr_PocCommand)            Fr_VExecutePOCCommand(Fr_PocCommand)
#  define Fr_VSetReg(Fr_CtrlIdx, regAddr, mask, operator)             Fr_VSetReg(regAddr, mask, operator)
#  define Fr_SetWakeupChannel(Fr_CtrlIdx, Fr_ChnlIdx)                 Fr_SetWakeupChannel(Fr_ChnlIdx)    
#  define Fr_GetPOCStatus(Fr_CtrlIdx, Fr_POCStatusPtr)                Fr_GetPOCStatus(Fr_POCStatusPtr)  
#  define Fr_TransmitTxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength) \
                                                                      Fr_TransmitTxLPdu(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength)
#  define Fr_ReceiveRxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr) \
                                                                      Fr_ReceiveRxLPdu(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr)
#  define Fr_CheckTxLPduStatus(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduStatusPtr) \
                                                                      Fr_CheckTxLPduStatus(Fr_LPduIdx, Fr_LPduStatusPtr)
#  define Fr_GetSyncFrameList( Fr_CtrlIdx, Fr_ListSize, Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr, Fr_ChannelBOddListPtr) \
                                                                      Fr_GetSyncFrameList( Fr_ListSize, Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr, Fr_ChannelBOddListPtr)

#  define Fr_GetGlobalTime(Fr_CtrlIdx, Fr_CyclePtr, Fr_MacroTickPtr)  Fr_GetGlobalTime(Fr_CyclePtr, Fr_MacroTickPtr)

#  if (FR_RECONFIGLPDUSUPPORT == STD_ON)
#   define Fr_ReconfigLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_FrameId, Fr_ChnlIdx, Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC ) \
                                                                      Fr_ReconfigLPdu( Fr_LPduIdx, Fr_FrameId, Fr_ChnlIdx, Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC )
#  endif
#  if (FR_DISABLELPDUSUPPORT == STD_ON)
#   define Fr_DisableLPdu(Fr_CtrlIdx,Fr_LPduIdx)                      Fr_DisableLPdu(Fr_LPduIdx)
#  endif


#  if ( FR_NMVECTOR_ENABLE == STD_ON )
#   define Fr_GetNmVector(Fr_CtrlIdx, Fr_NmVectorPtr)                 Fr_GetNmVector(Fr_NmVectorPtr)                 
#  endif

#  define Fr_GetChannelStatus(Fr_CtrlIdx, Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr) \
                                                                      Fr_GetChannelStatus(Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr)                          
#  define Fr_GetClockCorrection(Fr_CtrlIdx, Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr) \
                                                                      Fr_GetClockCorrection(Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr)                  

#  define Fr_GetNumOfStartupFrames(Fr_CtrlIdx, Fr_ChannelAEvenListPtr) Fr_GetNumOfStartupFrames(Fr_ChannelAEvenListPtr) 
#  define Fr_GetWakeupRxStatus(Fr_CtrlIdx, Fr_WakeupRxStatusPtr)      Fr_GetWakeupRxStatus(Fr_WakeupRxStatusPtr) 

#  define Fr_AllSlots(Fr_CtrlIdx)                                     Fr_AllSlots() 
#  define Fr_CancelTxLPdu(Fr_CtrlIdx, LPduIdx)                        Fr_CancelTxLPdu(LPduIdx) 

#  if (FR_READ_CC_CONFIGURATION == STD_ON)
#   define Fr_ReadCCConfig(Fr_CtrlIdx, Fr_ConfigParamIdx, Fr_ConfigParamValuePtr) Fr_ReadCCConfig(Fr_ConfigParamIdx, Fr_ConfigParamValuePtr)  
#  endif
# endif
/* FR_CTRL_ENABLE_API_OPTIMIZATION */

# if ( FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON )
#  define Fr_SetAbsoluteTimer(Fr_CtrlIdx, Fr_TimerIdx, Fr_Cycle, Fr_Offset) Fr_SetAbsoluteTimer(Fr_TimerIdx, Fr_Cycle, Fr_Offset) 
#  define Fr_CancelAbsoluteTimer(Fr_CtrlIdx, Fr_TimerIdx)             Fr_CancelAbsoluteTimer(Fr_TimerIdx)                
#  define Fr_EnableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)          Fr_EnableAbsoluteTimerIRQ(Fr_TimerIdx)             

#  if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
#   define Fr_AckAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)            Fr_AckAbsoluteTimerIRQ(Fr_TimerIdx)                
#   define Fr_DisableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)        Fr_DisableAbsoluteTimerIRQ(Fr_TimerIdx)            
#   define Fr_GetAbsoluteTimerIRQStatus(Fr_CtrlIdx, Fr_AbsTimerIdx, Fr_IRQStatusPtr) Fr_GetAbsoluteTimerIRQStatus(Fr_AbsTimerIdx, Fr_IRQStatusPtr)   
#  endif

# endif
  /* FR_CTRL_ENABLE_API_OPTIMIZATION */

/* PRQA L:MISRA_SINGLE_API */ /* MD_MSR_19.7 */

/*!
 * \exclusivearea  FR_EXCLUSIVE_AREA_0
 *                 Ensure the consistency of the message buffer configuration registers.
 * \protects       Write Header Section (WRHSn), Input Buffer Command Request register (IBCR) and Input Buffer Command Mask
                   (IBCM) registers.
 * \usedin         Fr_TransmitTxLPdu, Fr_DisableLPdu, Fr_ReconfigLPdu, Fr_CancelTxLPdu
 * \exclude        Modifications of the WRHSn, IBCR and IBCM registers from another context.
 * \length         LONG    Worst case is that a register access fails endlessly and FR_VHARDWARE_CANCELLATION is disabled.
 * \endexclusivearea
 */

/***** end of header file ************************************************************************/
#endif
  /* FR_H */

