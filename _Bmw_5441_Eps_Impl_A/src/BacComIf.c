/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BacComIf.c
 *        Config:  C:/Component/FAAR_WE_Synergy/_Bmw_5441_Eps_Impl_A/autosar/EPS.dpa
 *     SW-C Type:  BacComIf
 *  Generated at:  Thu Oct 26 14:51:43 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.15.0
 *                 RTE Core Version 1.15.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BacComIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Stm_VehicleStateSP2015Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BacComIf.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ALIV_CON_VEH: Integer in interval [0...255]
 * CON_VEH_dummy_56_63: Integer in interval [0...255]
 * CRC_CON_VEH: Integer in interval [0...255]
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CTR_BS_PRTNT: Enumeration of integer in interval [0...255] with enumerators
 *   CTR_BS_PRTNT_KeineKommunikation (0U)
 *   CTR_BS_PRTNT_Kom_Parken_BN_niO (1U)
 *   CTR_BS_PRTNT_Kom_Parken_BN_iO (2U)
 *   CTR_BS_PRTNT_Kom_Standfunktionen_Kunde_nicht_im_FZG (3U)
 *   CTR_BS_PRTNT_reserviert (4U)
 *   CTR_BS_PRTNT_Kom_Wohnen (5U)
 *   CTR_BS_PRTNT_reserviert_bne_95F305A59796464C872A83A9688DA49E_6 (6U)
 *   CTR_BS_PRTNT_Kom_Pruefen_Analyse_Diagnose (7U)
 *   CTR_BS_PRTNT_Kom_Fahrbereitschaft_herstellen (8U)
 *   CTR_BS_PRTNT_reserviert_bne_95F305A59796464C872A83A9688DA49E_9 (9U)
 *   CTR_BS_PRTNT_Kom_Fahren (10U)
 *   CTR_BS_PRTNT_reserviert_bne_95F305A59796464C872A83A9688DA49E_11 (11U)
 *   CTR_BS_PRTNT_Kom_Fahrbereitschaft_beenden (12U)
 *   CTR_BS_PRTNT_reserviert_bne_95F305A59796464C872A83A9688DA49E_13 (13U)
 *   CTR_BS_PRTNT_reserviert_bne_95F305A59796464C872A83A9688DA49E_14 (14U)
 *   CTR_BS_PRTNT_Signal_unbefuellt (15U)
 * CTR_FKTN_PRTNT: Enumeration of integer in interval [0...4294967295] with enumerators
 *   FKTN_PRTNT_KonfigurationAus (0U)
 *   KonfigurationAus_BflMask 2147483649U (0b10000000000000000000000000000001)
 *   FKTN_PRTNT_KonfigurationEin (1U)
 *   KonfigurationEin_BflMask 2147483649U (0b10000000000000000000000000000001)
 *   FKTN_PRTNT_EthernetInfrastrukturAus (0U)
 *   EthernetInfrastrukturAus_BflMask 2147483650U (0b10000000000000000000000000000010)
 *   FKTN_PRTNT_EthernetInfrastrukturEin (2U)
 *   EthernetInfrastrukturEin_BflMask 2147483650U (0b10000000000000000000000000000010)
 *   FKTN_PRTNT_Datenkommunikation_aus (0U)
 *   Datenkommunikation_aus_BflMask 2147483652U (0b10000000000000000000000000000100)
 *   FKTN_PRTNT_Datenkommunikation_ein (4U)
 *   Datenkommunikation_ein_BflMask 2147483652U (0b10000000000000000000000000000100)
 *   FKTN_PRTNT_KlimabetriebAus (0U)
 *   KlimabetriebAus_BflMask 2147483904U (0b10000000000000000000000100000000)
 *   FKTN_PRTNT_KlimabetriebEin (256U)
 *   KlimabetriebEin_BflMask 2147483904U (0b10000000000000000000000100000000)
 *   FKTN_PRTNT_EntertainmentbetriebAus (0U)
 *   EntertainmentbetriebAus_BflMask 2147484160U (0b10000000000000000000001000000000)
 *   FKTN_PRTNT_EntertainmentbetriebEin (512U)
 *   EntertainmentbetriebEin_BflMask 2147484160U (0b10000000000000000000001000000000)
 *   FKTN_PRTNT_Externe_KommunikationAus (0U)
 *   Externe_KommunikationAus_BflMask 2147484672U (0b10000000000000000000010000000000)
 *   FKTN_PRTNT_Externe_KommunikationEin (1024U)
 *   Externe_KommunikationEin_BflMask 2147484672U (0b10000000000000000000010000000000)
 *   FKTN_PRTNT_Entertainmentbetrieb_Fond_aus (0U)
 *   Entertainmentbetrieb_Fond_aus_BflMask 2147485696U (0b10000000000000000000100000000000)
 *   FKTN_PRTNT_Entertainmentbetrieb_Fond_ein (2048U)
 *   Entertainmentbetrieb_Fond_ein_BflMask 2147485696U (0b10000000000000000000100000000000)
 *   FKTN_PRTNT_Assistenz_Parken_highAus (0U)
 *   Assistenz_Parken_highAus_BflMask 2147487744U (0b10000000000000000001000000000000)
 *   FKTN_PRTNT_Assistenz_Parken_highEin (4096U)
 *   Assistenz_Parken_highEin_BflMask 2147487744U (0b10000000000000000001000000000000)
 *   FKTN_PRTNT_LadenAus (0U)
 *   LadenAus_BflMask 2147516416U (0b10000000000000001000000000000000)
 *   FKTN_PRTNT_LadenEin (32768U)
 *   LadenEin_BflMask 2147516416U (0b10000000000000001000000000000000)
 *   FKTN_PRTNT_FahrzeugInfrastrukturAus (0U)
 *   FahrzeugInfrastrukturAus_BflMask 2147549184U (0b10000000000000010000000000000000)
 *   FKTN_PRTNT_FahrzeugInfrastrukturEin (65536U)
 *   FahrzeugInfrastrukturEin_BflMask 2147549184U (0b10000000000000010000000000000000)
 *   FKTN_PRTNT_Licht_aus (0U)
 *   Licht_aus_BflMask 2148007936U (0b10000000000010000000000000000000)
 *   FKTN_PRTNT_Licht_ein (524288U)
 *   Licht_ein_BflMask 2148007936U (0b10000000000010000000000000000000)
 *   FKTN_PRTNT_TN_48V_aus (0U)
 *   TN_48V_aus_BflMask 2148532224U (0b10000000000100000000000000000000)
 *   FKTN_PRTNT_TN_48V_ein (1048576U)
 *   TN_48V_ein_BflMask 2148532224U (0b10000000000100000000000000000000)
 *   FKTN_PRTNT_Signal_unbefuellt (4294967295U)
 *   Signal_unbefuellt_BflMask 4294967295U (0b11111111111111111111111111111111)
 *   Signal_unbefuellt_BflPn 0
 *   Signal_unbefuellt_BflLn 32
 * QU_ST_CON_VEH: Enumeration of integer in interval [0...255] with enumerators
 *   QU_ST_CON_VEH_SignalwertGueltig (2U)
 *   QU_ST_CON_VEH_SignalwertEingeschraenktGueltig (3U)
 *   QU_ST_CON_VEH_ReserviertFuerDieNichtUmgesetzteKennung_Fehler_ (6U)
 *   QU_ST_CON_VEH_Wert_nicht_verfuegbar (14U)
 *   QU_ST_CON_VEH_SignalUnbefuellt (15U)
 * ST_CON_VEH: Enumeration of integer in interval [0...255] with enumerators
 *   ST_CON_VEH_reserviert (0U)
 *   ST_CON_VEH_Parken_BN_niO (1U)
 *   ST_CON_VEH_Parken_BN_iO (2U)
 *   ST_CON_VEH_Standfunktionen_Kunde_nicht_im_FZG (3U)
 *   ST_CON_VEH_Wohnen (5U)
 *   ST_CON_VEH_Pruefen_Analyse_Diagnose (7U)
 *   ST_CON_VEH_Fahrbereitschaft_herstellen (8U)
 *   ST_CON_VEH_Fahren (10U)
 *   ST_CON_VEH_Fahrbereitschaft_beenden (12U)
 *   ST_CON_VEH_reserviert_bne_E673DEE4F91F432391662F6004C0175A_13 (13U)
 *   ST_CON_VEH_reserviert_bne_E673DEE4F91F432391662F6004C0175A_14 (14U)
 *   ST_CON_VEH_Signal_unbefuellt (15U)
 * Stm_VehicleStateSP2015Type: Enumeration of integer in interval [0...255] with enumerators
 *   STM_VEHICLE_STATE_SP2015_PARKING_BN_NOK (1U)
 *   STM_VEHICLE_STATE_SP2015_PARKING_BN_OK (2U)
 *   STM_VEHICLE_STATE_SP2015_CUSTOMER_ABSENT (3U)
 *   STM_VEHICLE_STATE_SP2015_LIVING (5U)
 *   STM_VEHICLE_STATE_SP2015_CHECK_ANALYS_DIAGNOSTICS (7U)
 *   STM_VEHICLE_STATE_SP2015_READINESS_TO_DRIVE_INIT (8U)
 *   STM_VEHICLE_STATE_SP2015_DRIVE (10U)
 *   STM_VEHICLE_STATE_SP2015_READINESS_TO_DRIVE_STOP (12U)
 *   STM_VEHICLE_STATE_SP2015_UNAVAILABLE (14U)
 *   STM_VEHICLE_STATE_SP2015_INVALID (15U)
 *
 * Record Types:
 * =============
 * Vin_ComVinType: Record with elements
 *   Vin1 of type uint8
 *   Vin2 of type uint8
 *   Vin3 of type uint8
 *   Vin4 of type uint8
 *   Vin5 of type uint8
 *   Vin6 of type uint8
 *   Vin7 of type uint8
 * sigGroup_CON_VEH: Record with elements
 *   ST_CON_VEH of type ST_CON_VEH
 *   QU_ST_CON_VEH of type QU_ST_CON_VEH
 *   ALIV_CON_VEH of type ALIV_CON_VEH
 *   CRC_CON_VEH of type CRC_CON_VEH
 *   CON_VEH_dummy_56_63 of type CON_VEH_dummy_56_63
 *   CTR_BS_PRTNT of type CTR_BS_PRTNT
 *   CTR_FKTN_PRTNT of type CTR_FKTN_PRTNT
 *
 *********************************************************************************************************************/


#define BacComIf_START_SEC_CODE
#include "BacComIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehicleState
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_CON_VEH> of PortPrototype <sigGroup_CON_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_VehicleStateSP2015SignalInterface_vehicleStateSP2015(Stm_VehicleStateSP2015Type data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VehicleState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BacComIf_CODE) VehicleState(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehicleState
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VinUpdate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_NO_VECH_1_NO_VECH_1(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_2_NO_VECH_2(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_3_NO_VECH_3(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_4_NO_VECH_4(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_5_NO_VECH_5(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_6_NO_VECH_6(uint8 *data)
 *   Std_ReturnType Rte_Read_NO_VECH_7_NO_VECH_7(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ComVin_ComVin(const Vin_ComVinType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: VinUpdate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BacComIf_CODE) VinUpdate(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VinUpdate
 *********************************************************************************************************************/
	Vin_ComVinType data;
	Rte_Read_NO_VECH_1_NO_VECH_1(&data.Vin1);
	Rte_Read_NO_VECH_2_NO_VECH_2(&data.Vin2);
	Rte_Read_NO_VECH_3_NO_VECH_3(&data.Vin3);
	Rte_Read_NO_VECH_4_NO_VECH_4(&data.Vin4);
	Rte_Read_NO_VECH_5_NO_VECH_5(&data.Vin5);
	Rte_Read_NO_VECH_6_NO_VECH_6(&data.Vin6);
	Rte_Read_NO_VECH_7_NO_VECH_7(&data.Vin7);

	Rte_Write_ComVin_ComVin(&data);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BacComIf_STOP_SEC_CODE
#include "BacComIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
