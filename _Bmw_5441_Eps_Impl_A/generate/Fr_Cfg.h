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
 *            Module: Fr
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fr_Cfg.h
 *   Generation Time: 2018-07-30 19:49:07
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



#ifndef FR_CFG_H
#define FR_CFG_H

#ifndef FR_USE_DUMMY_FUNCTIONS
#define FR_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FR_USE_DUMMY_STATEMENT
#define FR_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FR_DUMMY_STATEMENT
#define FR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FR_DUMMY_STATEMENT_CONST
#define FR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FR_ATOMIC_VARIABLE_ACCESS
#define FR_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FR_PROCESSOR_RH850_1363
#define FR_PROCESSOR_RH850_1363
#endif
#ifndef FR_COMP_GREENHILLS
#define FR_COMP_GREENHILLS
#endif
#ifndef FR_GEN_GENERATOR_MSR
#define FR_GEN_GENERATOR_MSR
#endif
#ifndef FR_CPUTYPE_BITORDER_LSB2MSB
#define FR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FR_CONFIGURATION_VARIANT_PRECOMPILE
#define FR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FR_CONFIGURATION_VARIANT_LINKTIME
#define FR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FR_CONFIGURATION_VARIANT
#define FR_CONFIGURATION_VARIANT FR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FR_POSTBUILD_VARIANT_SUPPORT
#define FR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define FR_DEV_ERROR_DETECT       STD_ON
#define FR_DEV_ERROR_REPORT       STD_ON

#define FR_AUTOSARVERSION4 
#define FR_FrCtrlIdx                                   0U 
#define FR_FrAbsTimerIdx                               0U 
#define FR_FrRelTimerIdx                               0U 
#define FR_CFG_ISR_TYPE                                0U 
#define FR_CFG_APPL_CALLBACK_CYCLE_START               STD_ON 
#define FR_CFG_APPL_CALLBACK_TIMER0                    STD_OFF 
#define FR_PROD_ERROR_DETECT                           STD_OFF 
#define FR_VEXTENDED_CC_STATUS                         STD_OFF 
#define FR_ABORT_COMMUNICATION_DISABLE                 STD_OFF 
#define FR_SET_EXT_SYNC_DISABLE                        STD_ON 
#define FR_SET_WAKEUP_CHANNEL_DISABLE                  STD_OFF 
#define FR_ABSOLUTE_TIMER_DISABLE                      STD_OFF 
#define FR_VENABLE_MID_FILTERING                       STD_OFF 
#define FR_VCHANNEL_STATUS_EXT                         STD_OFF 
#define FR_GET_CLOCK_CORRECTION_EXT                    STD_OFF 
#define FR_RELATIVE_TIMER_ENABLE                       STD_OFF 
#define FR_VERSION_INFO_API                            STD_OFF 
#define FR_NMVECTOR_ENABLE                             STD_OFF 
#define FR_GETSYNCFRAMELIST_API                        STD_OFF 
#define FR_RECONFIGLPDUSUPPORT                         STD_OFF 
#define FR_DISABLELPDUSUPPORT                          STD_OFF 
#define FR_CANCELTRANSMITSUPPORT                       STD_OFF 
#define FR_RX_STRINGENT_CHECK                          STD_OFF 
#define FR_RX_STRINGENT_LENGTH_CHECK                   STD_OFF 
#define FR_BUFFER_RECONFIG                             STD_OFF 
#define FR_FIFO_SUPPORT                                STD_OFF 
#define FR_INDEX                                       0U 
#define FR_NUM_CTRL_SUPPORTED                          1U 
#define FR_NUM_CTRL_USED                               1U 
#define FR_CTRL_ENABLE_API_OPTIMIZATION                STD_OFF 
#define FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION STD_OFF 
#define FR_ENABLE_BIDIRECTIONALROUTING                 STD_OFF 
#define FR_VHARDWARE_CANCELLATION                      STD_OFF 
#define FR_DFI_MULTI_USER_EXT                          STD_OFF 
#define FR_READ_CC_CONFIGURATION                       STD_OFF 
#define FR_CC_READ_BACK_SUPPORT                        STD_OFF 
#define FR_AMD_RUNTIME_MEASUREMENT                     STD_OFF 
#define FR_MULTI_ID_CONFIG                             STD_OFF 
#define FR_MIRROR_EXTENSION                            STD_OFF 
#define FR_STATUS_COUNTER_EXT                          STD_OFF 
#define FrMultipleConfiguration                        Fr_Config 
#define FR_VCC_REG_START_ADDR                          0x10020000UL 
#define FR_HWFIFO_SUPPORT                              STD_OFF 


/* ---------------------------------------------------------------
   &&&~ Frame Triggerings - 
 --------------------------------------------------------------- */
#define FR_Trig_Tx_FR_DBG_EPS_315_0_1_0                                            0x0000U 
#define FR_Trig_Tx_xcpdynamic254_8_301_0_1_0                                       0x0001U 
#define FR_Trig_Tx_xcpdynamic254_7_300_0_1_0                                       0x0002U 
#define FR_Trig_Tx_xcpdynamic254_6_299_0_1_0                                       0x0003U 
#define FR_Trig_Tx_xcpdynamic254_5_298_0_1_0                                       0x0004U 
#define FR_Trig_Tx_xcpdynamic254_4_297_0_1_0                                       0x0005U 
#define FR_Trig_Tx_xcpdynamic254_3_296_0_1_0                                       0x0006U 
#define FR_Trig_Tx_xcpdynamic254_2_295_0_1_0                                       0x0007U 
#define FR_Trig_Tx_xcpdynamic254_1_294_0_1_0                                       0x0008U 
#define FR_Trig_Tx_DISP_CC_EPS_274_2_4_0                                           0x0009U 
#define FR_Trig_Tx_SU_EPS_274_0_8_0                                                0x000AU 
#define FR_Trig_Tx_ST_DIAG_OBD_3_DRDY_248_10_32_0                                  0x000BU 
#define FR_Trig_Tx_ST_EST_234_1_2_0                                                0x000CU 
#define FR_Trig_Tx_xcpslave_220_0_1_0                                              0x000DU 
#define FR_Trig_Tx_SVC_0142fcf7_Out_216_9_16_0                                     0x000EU 
#define FR_Trig_Tx_TL_ECU_TRNSM_FR_32_183_0_1_0                                    0x000FU 
#define FR_Trig_Tx_AVL_PO_EPS_ENGTORQ_EPS_51_0_2_0                                 0x0010U 
#define FR_Trig_Tx_DT_EST_49_1_2_0                                                 0x0011U 
#define FR_Trig_Tx_AVL_STMOM_DV_ACT_AVL_FORC_GRD_49_0_2_0                          0x0012U 
#define FR_Trig_Tx_xcpstatic_a931915e_Out_12_0_1_0                                 0x0013U 
#define FR_Trig_Tx_xcpstatic_ab772f07_Out_11_0_1_0                                 0x0014U 
#define FR_Trig_Tx_xcpstatic_aab54530_Out_10_0_1_0                                 0x0015U 
#define FR_Trig_Tx_xcpstatic_c9777e57_Out_9_0_1_0                                  0x0016U 
#define FR_Trig_Tx_xcpstatic_c8b51460_Out_8_0_1_0                                  0x0017U 
#define FR_Trig_Rx_RELATIVZEIT_276_2_8_0                                           0x0000U 
#define FR_Trig_Rx_KILOMETERSTAND_276_4_8_0                                        0x0001U 
#define FR_Trig_Rx_FZZSTD_275_1_8_0                                                0x0002U 
#define FR_Trig_Rx_FAHRGESTELLNUMMER_275_7_8_0                                     0x0003U 
#define FR_Trig_Rx_CTR_VIB_STW_DISP_EXMI_SP2015_FDBK_VIB_STW_DISP_EXMI_269_2_4_0   0x0004U 
#define FR_Trig_Rx_A_TEMP_252_1_4_0                                                0x0005U 
#define FR_Trig_Rx_CTR_DIAG_OBD_DRDY_247_0_2_0                                     0x0006U 
#define FR_Trig_Rx_DIAG_OBD_ENG_247_1_2_0                                          0x0007U 
#define FR_Trig_Rx_SECU_FAHRGESTELLNUMMER_244_0_4_0                                0x0008U 
#define FR_Trig_Rx_ST_ENERG_GEN_232_1_2_0                                          0x0009U 
#define FR_Trig_Rx_xcpmaster_219_0_1_0                                             0x000AU 
#define FR_Trig_Rx_SVC_0a1ebbca_In_216_6_16_0                                      0x000BU 
#define FR_Trig_Rx_SVC_0bdcd1fd_In_216_7_16_0                                      0x000CU 
#define FR_Trig_Rx_SVC_b5578b48_In_216_10_16_0                                     0x000DU 
#define FR_Trig_Rx_SVC_b6d35f26_In_216_12_16_0                                     0x000EU 
#define FR_Trig_Rx_SVC_b7113511_In_216_13_16_0                                     0x000FU 
#define FR_Trig_Rx_SVC_b25e2394_In_216_14_16_0                                     0x0010U 
#define FR_Trig_Rx_SVC_b39c49a3_In_216_15_16_0                                     0x0011U 
#define FR_Trig_Rx_SVC_1fa2bcf8_In_215_2_16_0                                      0x0012U 
#define FR_Trig_Rx_SVC_1aedaa7d_In_215_5_16_0                                      0x0013U 
#define FR_Trig_Rx_SVC_18ab1424_In_215_6_16_0                                      0x0014U 
#define FR_Trig_Rx_SVC_13f75319_In_215_9_16_0                                      0x0015U 
#define FR_Trig_Rx_SVC_f2f7f198_In_215_10_16_0                                     0x0016U 
#define FR_Trig_Rx_SVC_1fe6493a_In_214_3_4_0                                       0x0017U 
#define FR_Trig_Rx_TL_BRC_FR_32_41eef8f3_In_213_0_1_0                              0x0018U 
#define FR_Trig_Rx_TL_BRC_FR_32_402c92c4_In_212_0_1_0                              0x0019U 
#define FR_Trig_Rx_TL_BRC_FR_32_426a2c9d_In_211_0_1_0                              0x001AU 
#define FR_Trig_Rx_TL_BRC_FR_32_43a846aa_In_210_0_1_0                              0x001BU 
#define FR_Trig_Rx_TL_BRC_FR_32_f4c51a40_In_209_0_1_0                              0x001CU 
#define FR_Trig_Rx_TL_MST_GW_TRNSM_FR_254_147_0_1_0                                0x001DU 
#define FR_Trig_Rx_CON_VEH_121_1_2_0                                               0x001EU 
#define FR_Trig_Rx_ENSU_SFY_119_1_2_0                                              0x001FU 
#define FR_Trig_Rx_ST_CENG_117_0_2_0                                               0x0020U 
#define FR_Trig_Rx_STEA_OFFS_108_0_2_0                                             0x0021U 
#define FR_Trig_Rx_OFFS_QUAD_EPS_107_0_1_0                                         0x0022U 
#define FR_Trig_Rx_ERRM_BN_U_104_0_1_0                                             0x0023U 
#define FR_Trig_Rx_TAR_QTA_STRMOM_DV_TAR_STMOM_DV_ACT_68_0_2_0                     0x0024U 
#define FR_Trig_Rx_ENERG_DGR_DRDY_68_1_2_0                                         0x0025U 
#define FR_Trig_Rx_TAR_ESTP_VIRT_FTAX_65_1_2_0                                     0x0026U 
#define FR_Trig_Rx_DT_DRDYSEN_EXT_VYAW_VEH_56_0_2_0                                0x0027U 
#define FR_Trig_Rx_ACLNX_MASSCNTR_ACLNY_MASSCNTR_55_0_2_0                          0x0028U 
#define FR_Trig_Rx_V_VEH_V_VEH_2_55_3_4_0                                          0x0029U 
#define FR_Trig_Rx_SU_CLE_DRDY_DXP_SPEC_ADPT_MOD_DXP_ST_IDLV_COOD_DBE_DXP_53_3_8_0 0x002AU 
#define FR_Trig_Rx_ST_STAB_DSC_ST_STAB_DSC_2_47_1_2_0                              0x002BU 
#define FR_Trig_Rx_AVL_RPM_WHL_46_0_1_0                                            0x002CU 


 

/* ---------------------------------------------------------------
   &&&~ Controller0 dependent defines - 
 --------------------------------------------------------------- */
#define FR_SIZE_RXVIRTBUF2PHAYBUFMAP 45UL 
#define FR_SIZE_TXVIRTBUF2PHAYBUFMAP 24UL 
#define FR_CFG_STATUS_ISR_LINE       0UL 
#define FR_SIZE_MB_ARRAY             54UL 


 
 

/* ---------------------------------------------------------------
   &&&~ Independent defines
 --------------------------------------------------------------- */
#define FR_CTRL_TEST_COUNT             1UL 
#define FR_SIZE_CONTROLREGCONFARRAY    34UL 
#define FR_DIRECT_BUFFER_ACCESS_ENABLE STD_OFF 


    





#define FR_CPU_RH850



#endif /* FR_CFG_H */

