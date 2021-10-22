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
 *          File:  Rte_BmwMsgSlot51Bas0Repn2BusFrChA_Type.h
 *        Config:  C:/_Synergy_Projects/Working/MM523A_BmwMsgSlot51Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot51Bas0Repn2BusFrChA
 *  Generated at:  Tue Mar 27 17:52:25 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwMsgSlot51Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_TYPE_H
# define _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_TYPE_H

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

# ifndef PinionAgQlfrSigValVldAndPlaus
#  define PinionAgQlfrSigValVldAndPlaus (1U)
# endif

# ifndef PinionAgQlfrSigValVld
#  define PinionAgQlfrSigValVld (2U)
# endif

# ifndef PinionAgQlfrSubValSetInUsrSig
#  define PinionAgQlfrSubValSetInUsrSig (4U)
# endif

# ifndef PinionAgQlfrInit
#  define PinionAgQlfrInit (8U)
# endif

# ifndef PinionAgQlfrSigValVldAndTmpOfAvrgQly
#  define PinionAgQlfrSigValVldAndTmpOfAvrgQly (9U)
# endif

# ifndef PinionAgQlfrSigValVldAndTmpOfLoQly
#  define PinionAgQlfrSigValVldAndTmpOfLoQly (10U)
# endif

# ifndef PinionAgQlfrAdjmtValSetInUsrSig
#  define PinionAgQlfrAdjmtValSetInUsrSig (12U)
# endif

# ifndef PinionAgQlfrSigValInvldButStTmp
#  define PinionAgQlfrSigValInvldButStTmp (14U)
# endif

# ifndef PinionAgQlfrInvldSig
#  define PinionAgQlfrInvldSig (15U)
# endif

# ifndef BMWSELDPOSNUNIT_PINIONIF
#  define BMWSELDPOSNUNIT_PINIONIF (0U)
# endif

# ifndef BMWSELDPOSNUNIT_TOOTHEDRACKSTROKEIF
#  define BMWSELDPOSNUNIT_TOOTHEDRACKSTROKEIF (1U)
# endif

# ifndef BMWSELDPOSNUNIT_INVLDSIG
#  define BMWSELDPOSNUNIT_INVLDSIG (3U)
# endif

# ifndef BMWTQSNSRIDX_INIT
#  define BMWTQSNSRIDX_INIT (0U)
# endif

# ifndef BMWTQSNSRIDX_NOIDXEDGE
#  define BMWTQSNSRIDX_NOIDXEDGE (1U)
# endif

# ifndef BMWTQSNSRIDX_IDXEDGE
#  define BMWTQSNSRIDX_IDXEDGE (2U)
# endif

# ifndef BMWTQSNSRIDX_INVLDSIG
#  define BMWTQSNSRIDX_INVLDSIG (3U)
# endif

# ifndef IDX_TORQ_SEN_Initialisierung
#  define IDX_TORQ_SEN_Initialisierung (0U)
# endif

# ifndef IDX_TORQ_SEN_KeineIndexFlanke
#  define IDX_TORQ_SEN_KeineIndexFlanke (1U)
# endif

# ifndef IDX_TORQ_SEN_IndexFlanke
#  define IDX_TORQ_SEN_IndexFlanke (2U)
# endif

# ifndef IDX_TORQ_SEN_SignalUngueltig
#  define IDX_TORQ_SEN_SignalUngueltig (3U)
# endif

# ifndef QU_AVL_PINA_EPS_Initialisierung
#  define QU_AVL_PINA_EPS_Initialisierung (8U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert
#  define QU_AVL_PINA_EPS_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert (1U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalwertIstGueltig
#  define QU_AVL_PINA_EPS_SignalwertIstGueltig (2U)
# endif

# ifndef QU_AVL_PINA_EPS_ErsatzwertIstImNutzsignalGesetzt
#  define QU_AVL_PINA_EPS_ErsatzwertIstImNutzsignalGesetzt (4U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_mittlereSignalqualitaet_
#  define QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_mittlereSignalqualitaet_ (9U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_geringeSignalqualitaet_
#  define QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_geringeSignalqualitaet_ (10U)
# endif

# ifndef QU_AVL_PINA_EPS_AbgleichwertIstImNutzsignalGesetztZustandSlashStatusTemporaer
#  define QU_AVL_PINA_EPS_AbgleichwertIstImNutzsignalGesetztZustandSlashStatusTemporaer (12U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalwertIstUngueltigZustandSlashStatusTemporaer
#  define QU_AVL_PINA_EPS_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
# endif

# ifndef QU_AVL_PINA_EPS_SignalUngueltig
#  define QU_AVL_PINA_EPS_SignalUngueltig (15U)
# endif

# ifndef UN_PO_EPS_Ritzelschnittstelle
#  define UN_PO_EPS_Ritzelschnittstelle (0U)
# endif

# ifndef UN_PO_EPS_Zahnstangenhubschnittstelle
#  define UN_PO_EPS_Zahnstangenhubschnittstelle (1U)
# endif

# ifndef UN_PO_EPS_SignalUngueltig
#  define UN_PO_EPS_SignalUngueltig (3U)
# endif


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_TYPE_H */
