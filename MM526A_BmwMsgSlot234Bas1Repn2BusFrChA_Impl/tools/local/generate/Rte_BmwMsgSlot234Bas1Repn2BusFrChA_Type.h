/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_BmwMsgSlot234Bas1Repn2BusFrChA_Type.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM526A_BmwMsgSlot234Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot234Bas1Repn2BusFrChA
 *  Generated at:  Fri Apr 27 09:35:10 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwMsgSlot234Bas1Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_TYPE_H
# define _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

# ifndef ALIV_COU_4_Zaehlerstand0DotDotE
#  define ALIV_COU_4_Zaehlerstand0DotDotE (0U)
# endif

# ifndef ALIV_COU_4_SignalUngueltig
#  define ALIV_COU_4_SignalUngueltig (15U)
# endif

# ifndef BMWEPSFCTSTS_FCTINFALLBACK
#  define BMWEPSFCTSTS_FCTINFALLBACK (49U)
# endif

# ifndef BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV
#  define BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV (51U)
# endif

# ifndef BMWEPSFCTSTS_NOTAVIERR
#  define BMWEPSFCTSTS_NOTAVIERR (96U)
# endif

# ifndef BMWEPSFCTSTS_ININ
#  define BMWEPSFCTSTS_ININ (128U)
# endif

# ifndef BMWEPSFCTSTS_FCTAVIACTV12VEPS
#  define BMWEPSFCTSTS_FCTAVIACTV12VEPS (160U)
# endif

# ifndef BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV
#  define BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV (162U)
# endif

# ifndef BMWEPSFCTSTS_FCTAVIACTV12VEAS
#  define BMWEPSFCTSTS_FCTAVIACTV12VEAS (164U)
# endif

# ifndef BMWEPSFCTSTS_FCTAVIACTV24VEAS
#  define BMWEPSFCTSTS_FCTAVIACTV24VEAS (168U)
# endif

# ifndef BMWEPSFCTSTS_FCTTMPINFALLBACK
#  define BMWEPSFCTSTS_FCTTMPINFALLBACK (176U)
# endif

# ifndef BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT
#  define BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT (178U)
# endif

# ifndef BMWEPSFCTSTS_NOTAVISWDOFF
#  define BMWEPSFCTSTS_NOTAVISWDOFF (224U)
# endif

# ifndef BMWEPSFCTSTS_INVLD
#  define BMWEPSFCTSTS_INVLD (255U)
# endif

# ifndef DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG
#  define DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
# endif

# ifndef DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL
#  define DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
# endif

# ifndef DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG
#  define DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
# endif

# ifndef DRVGDYNIFST_IFACTVADDLDAMPGAVL
#  define DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
# endif

# ifndef DRVGDYNIFST_SRVNOTAVLERR
#  define DRVGDYNIFST_SRVNOTAVLERR (96U)
# endif

# ifndef DRVGDYNIFST_IFINID
#  define DRVGDYNIFST_IFINID (128U)
# endif

# ifndef DRVGDYNIFST_SRVNOTAVLSTBPMA
#  define DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
# endif

# ifndef DRVGDYNIFST_SRVNOTAVLSTBEPSSTS
#  define DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
# endif

# ifndef DRVGDYNIFST_INVLDSIG
#  define DRVGDYNIFST_INVLDSIG (255U)
# endif

# ifndef HAPTCFBST_FCTAVLNOTACTV
#  define HAPTCFBST_FCTAVLNOTACTV (1U)
# endif

# ifndef HAPTCFBST_ERR
#  define HAPTCFBST_ERR (6U)
# endif

# ifndef HAPTCFBST_FCTAVLACTV
#  define HAPTCFBST_FCTAVLACTV (9U)
# endif

# ifndef HAPTCFBST_FCTNOTAVL
#  define HAPTCFBST_FCTNOTAVL (14U)
# endif

# ifndef HAPTCFBST_INVLDSIG
#  define HAPTCFBST_INVLDSIG (15U)
# endif

# ifndef QU_FN_EST_Initialisierung
#  define QU_FN_EST_Initialisierung (128U)
# endif

# ifndef QU_FN_EST_FunktionVerfuegbar_Aktiv12VEPS
#  define QU_FN_EST_FunktionVerfuegbar_Aktiv12VEPS (160U)
# endif

# ifndef QU_FN_EST_FunktionVerfuegbar_Aktiv12VEAS
#  define QU_FN_EST_FunktionVerfuegbar_Aktiv12VEAS (164U)
# endif

# ifndef QU_FN_EST_FunktionVerfuegbar_Aktiv24VEAS
#  define QU_FN_EST_FunktionVerfuegbar_Aktiv24VEAS (168U)
# endif

# ifndef QU_FN_EST_FunktionVerfuegbar_AktivNotfallfunktionUmwelteinfluesse_Aktiv
#  define QU_FN_EST_FunktionVerfuegbar_AktivNotfallfunktionUmwelteinfluesse_Aktiv (162U)
# endif

# ifndef QU_FN_EST_FunktionInRueckfallebene
#  define QU_FN_EST_FunktionInRueckfallebene (49U)
# endif

# ifndef QU_FN_EST_FunktionInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv
#  define QU_FN_EST_FunktionInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (51U)
# endif

# ifndef QU_FN_EST_FunktionTemporaerInRueckfallebene
#  define QU_FN_EST_FunktionTemporaerInRueckfallebene (176U)
# endif

# ifndef QU_FN_EST_FunktionTemporaerInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv
#  define QU_FN_EST_FunktionTemporaerInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (178U)
# endif

# ifndef QU_FN_EST_FunktionNichtVerfuegbar_Fehler
#  define QU_FN_EST_FunktionNichtVerfuegbar_Fehler (96U)
# endif

# ifndef QU_FN_EST_FunktionNichtVerfuegbar_Ausgeschaltet
#  define QU_FN_EST_FunktionNichtVerfuegbar_Ausgeschaltet (224U)
# endif

# ifndef QU_FN_EST_SignalUngueltig
#  define QU_FN_EST_SignalUngueltig (255U)
# endif

# ifndef QU_FN_VIB_EPS_Funktion_verfuegbar_nicht_aktiv
#  define QU_FN_VIB_EPS_Funktion_verfuegbar_nicht_aktiv (1U)
# endif

# ifndef QU_FN_VIB_EPS_Funktion_verfuegbar_aktiv
#  define QU_FN_VIB_EPS_Funktion_verfuegbar_aktiv (9U)
# endif

# ifndef QU_FN_VIB_EPS_Funktion_nicht_verfuegbar
#  define QU_FN_VIB_EPS_Funktion_nicht_verfuegbar (14U)
# endif

# ifndef QU_FN_VIB_EPS_Fehler
#  define QU_FN_VIB_EPS_Fehler (6U)
# endif

# ifndef QU_FN_VIB_EPS_Signal_unbefuellt
#  define QU_FN_VIB_EPS_Signal_unbefuellt (15U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleWirdInitialisiert
#  define QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleWirdInitialisiert (128U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitOhneZusatzdaempfung
#  define QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitOhneZusatzdaempfung (32U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitMitZusatzdaempfung
#  define QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitMitZusatzdaempfung (34U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungNichtVerfuegbar
#  define QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungNichtVerfuegbar (33U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungVerfuegbar
#  define QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungVerfuegbar (35U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Fehler
#  define QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Fehler (96U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_PMA
#  define QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_PMA (224U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_EPSStatus
#  define QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_EPSStatus (225U)
# endif

# ifndef QU_SER_STMOM_STMOM_DV_ACT_SignalUngueltig
#  define QU_SER_STMOM_STMOM_DV_ACT_SignalUngueltig (255U)
# endif


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_TYPE_H */
