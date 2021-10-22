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
 *          File:  Rte_MemMap.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  RTE Memory Mapping header file
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_Rte_0883 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODE
# undef RTE_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
# undef RTE_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_APPL_CODE
# undef RTE_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CODE
# undef RTE_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_APPL_CODE
# undef RTE_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE
# undef RTE_START_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BACCOMIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BACCOMIF_APPL_CODE
# undef RTE_START_SEC_BACCOMIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BATTVLTG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BATTVLTG_APPL_CODE
# undef RTE_START_SEC_BATTVLTG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BATTVLTGCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BATTVLTGCORRLN_APPL_CODE
# undef RTE_START_SEC_BATTVLTGCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
# undef RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWDRVGDYNSTMAC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWDRVGDYNSTMAC_APPL_CODE
# undef RTE_START_SEC_BMWDRVGDYNSTMAC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWFLTHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWFLTHNDLG_APPL_CODE
# undef RTE_START_SEC_BMWFLTHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWHAPTCFB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWHAPTCFB_APPL_CODE
# undef RTE_START_SEC_BMWHAPTCFB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
# undef RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWHWTQOVRLARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWHWTQOVRLARBN_APPL_CODE
# undef RTE_START_SEC_BMWHWTQOVRLARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMOTTQOVRLARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMOTTQOVRLARBN_APPL_CODE
# undef RTE_START_SEC_BMWMOTTQOVRLARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_START_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWPWRPRKGDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWPWRPRKGDAMPG_APPL_CODE
# undef RTE_START_SEC_BMWPWRPRKGDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWSPLYCURRLIM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWSPLYCURRLIM_APPL_CODE
# undef RTE_START_SEC_BMWSPLYCURRLIM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWSTREQMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWSTREQMGR_APPL_CODE
# undef RTE_START_SEC_BMWSTREQMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWSWFCTDI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWSWFCTDI_APPL_CODE
# undef RTE_START_SEC_BMWSWFCTDI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE
# undef RTE_START_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE
# undef RTE_START_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE
# undef RTE_START_SEC_BMWTUNSETHNDLR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BMWVEHSPD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BMWVEHSPD_APPL_CODE
# undef RTE_START_SEC_BMWVEHSPD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BSWM_APPL_CODE
# undef RTE_START_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_ADC0CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_ADC0CFGANDUSE_APPL_CODE
# undef RTE_START_SEC_CDD_ADC0CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
# undef RTE_START_SEC_CDD_ADC1CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_ADCDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_ADCDIAGC_APPL_CODE
# undef RTE_START_SEC_CDD_ADCDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_BATTRTNCURR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_BATTRTNCURR_APPL_CODE
# undef RTE_START_SEC_CDD_BATTRTNCURR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_BMW5441MCUCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_BMW5441MCUCFG_APPL_CODE
# undef RTE_START_SEC_CDD_BMW5441MCUCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CHKPTAPPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CHKPTAPPL10_APPL_CODE
# undef RTE_START_SEC_CDD_CHKPTAPPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CHKPTAPPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CHKPTAPPL7_APPL_CODE
# undef RTE_START_SEC_CDD_CHKPTAPPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CHKPTAPPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CHKPTAPPL8_APPL_CODE
# undef RTE_START_SEC_CDD_CHKPTAPPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CHKPTAPPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CHKPTAPPL9_APPL_CODE
# undef RTE_START_SEC_CDD_CHKPTAPPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_COREVLTGMONR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_COREVLTGMONR_APPL_CODE
# undef RTE_START_SEC_CDD_COREVLTGMONR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CURRMEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CURRMEAS_APPL_CODE
# undef RTE_START_SEC_CDD_CURRMEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_CURRMEASARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_CURRMEASARBN_APPL_CODE
# undef RTE_START_SEC_CDD_CURRMEASARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_DATAANDADRPAR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_DATAANDADRPAR_APPL_CODE
# undef RTE_START_SEC_CDD_DATAANDADRPAR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE
# undef RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE
# undef RTE_START_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_EXCPNHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_EXCPNHNDLG_APPL_CODE
# undef RTE_START_SEC_CDD_EXCPNHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_FLSMEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_FLSMEM_APPL_CODE
# undef RTE_START_SEC_CDD_FLSMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE
# undef RTE_START_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_HWTQ4MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_HWTQ4MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_HWTQ4MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_HWTQ5MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_HWTQ5MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_HWTQ5MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE
# undef RTE_START_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MCUDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MCUDIAGC_APPL_CODE
# undef RTE_START_SEC_CDD_MCUDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTAG0MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTAG0MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_MOTAG0MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTAG1MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTAG1MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_MOTAG1MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTAG3MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTAG3MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_MOTAG3MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTAG4MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTAG4MEAS_APPL_CODE
# undef RTE_START_SEC_CDD_MOTAG4MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTAGCMP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTAGCMP_APPL_CODE
# undef RTE_START_SEC_CDD_MOTAGCMP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTCTRLMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTCTRLMGR_APPL_CODE
# undef RTE_START_SEC_CDD_MOTCTRLMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE
# undef RTE_START_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_MOTVEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_MOTVEL_APPL_CODE
# undef RTE_START_SEC_CDD_MOTVEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_NVMPROXY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_NVMPROXY_APPL_CODE
# undef RTE_START_SEC_CDD_NVMPROXY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_NXTRTI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_NXTRTI_APPL_CODE
# undef RTE_START_SEC_CDD_NXTRTI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_RAMMEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_RAMMEM_APPL_CODE
# undef RTE_START_SEC_CDD_RAMMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_SINVLTGGENN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_SINVLTGGENN_APPL_CODE
# undef RTE_START_SEC_CDD_SINVLTGGENN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_SYNCCRC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_SYNCCRC_APPL_CODE
# undef RTE_START_SEC_CDD_SYNCCRC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_TSG31CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_TSG31CFGANDUSE_APPL_CODE
# undef RTE_START_SEC_CDD_TSG31CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE
# undef RTE_START_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_VRFYCRITREG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_VRFYCRITREG_APPL_CODE
# undef RTE_START_SEC_CDD_VRFYCRITREG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_XCPIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_XCPIF_APPL_CODE
# undef RTE_START_SEC_CDD_XCPIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE
# undef RTE_START_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CLSDLOOPDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CLSDLOOPDAMPG_APPL_CODE
# undef RTE_START_SEC_CLSDLOOPDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CLSDLOOPHYS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CLSDLOOPHYS_APPL_CODE
# undef RTE_START_SEC_CLSDLOOPHYS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CMNMFGSRV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CMNMFGSRV_APPL_CODE
# undef RTE_START_SEC_CMNMFGSRV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CMNMFGSRVIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CMNMFGSRVIF_APPL_CODE
# undef RTE_START_SEC_CMNMFGSRVIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CMPLNCERR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CMPLNCERR_APPL_CODE
# undef RTE_START_SEC_CMPLNCERR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CODING_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODING_APPL_CODE
# undef RTE_START_SEC_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMM_APPL_CODE
# undef RTE_START_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CTRLDVELRTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CTRLDVELRTN_APPL_CODE
# undef RTE_START_SEC_CTRLDVELRTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CURRMEASCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CURRMEASCORRLN_APPL_CODE
# undef RTE_START_SEC_CURRMEASCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DARH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DARH_APPL_CODE
# undef RTE_START_SEC_DARH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DCM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DCM_APPL_CODE
# undef RTE_START_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DEMMASTER_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DEMMASTER_0_APPL_CODE
# undef RTE_START_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
# undef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DEMWRAPPER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DEMWRAPPER_APPL_CODE
# undef RTE_START_SEC_DEMWRAPPER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DET_APPL_CODE
# undef RTE_START_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGR_APPL_CODE
# undef RTE_START_SEC_DIAGCMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
# undef RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
# undef RTE_START_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
# undef RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
# undef RTE_START_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIAGCMGRSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIAGCMGRSTUB_APPL_CODE
# undef RTE_START_SEC_DIAGCMGRSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DLOG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DLOG_APPL_CODE
# undef RTE_START_SEC_DLOG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DUTYCYCTHERMPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DUTYCYCTHERMPROTN_APPL_CODE
# undef RTE_START_SEC_DUTYCYCTHERMPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ECUM_APPL_CODE
# undef RTE_START_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ECUTMEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ECUTMEAS_APPL_CODE
# undef RTE_START_SEC_ECUTMEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_EFFORT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_EFFORT_APPL_CODE
# undef RTE_START_SEC_EFFORT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ELECPWRCNS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ELECPWRCNS_APPL_CODE
# undef RTE_START_SEC_ELECPWRCNS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_EOTPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_EOTPROTN_APPL_CODE
# undef RTE_START_SEC_EOTPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_EPSSTESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_EPSSTESTIMN_APPL_CODE
# undef RTE_START_SEC_EPSSTESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_FALBCKASSI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_FALBCKASSI_APPL_CODE
# undef RTE_START_SEC_FALBCKASSI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_FLTINJ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_FLTINJ_APPL_CODE
# undef RTE_START_SEC_FLTINJ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_GATEDRV0CTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_GATEDRV0CTRL_APPL_CODE
# undef RTE_START_SEC_GATEDRV0CTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_GLBLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_GLBLIMR_APPL_CODE
# undef RTE_START_SEC_GLBLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HILOADSTALLLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HILOADSTALLLIMR_APPL_CODE
# undef RTE_START_SEC_HILOADSTALLLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HWREFTQSUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HWREFTQSUM_APPL_CODE
# undef RTE_START_SEC_HWREFTQSUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HWTQARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HWTQARBN_APPL_CODE
# undef RTE_START_SEC_HWTQARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HWTQCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HWTQCORRLN_APPL_CODE
# undef RTE_START_SEC_HWTQCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HWTQTRAKGCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HWTQTRAKGCTRL_APPL_CODE
# undef RTE_START_SEC_HWTQTRAKGCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_INERTIACMPVEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_INERTIACMPVEL_APPL_CODE
# undef RTE_START_SEC_INERTIACMPVEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_IOHWAB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_IOHWAB_APPL_CODE
# undef RTE_START_SEC_IOHWAB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LIMRCDNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LIMRCDNG_APPL_CODE
# undef RTE_START_SEC_LIMRCDNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LOAMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LOAMGR_APPL_CODE
# undef RTE_START_SEC_LOAMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LRNPINIONCENTR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LRNPINIONCENTR_APPL_CODE
# undef RTE_START_SEC_LRNPINIONCENTR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LRNDRACKCENTR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LRNDRACKCENTR_APPL_CODE
# undef RTE_START_SEC_LRNDRACKCENTR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MCALERRHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MCALERRHNDLG_APPL_CODE
# undef RTE_START_SEC_MCALERRHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MCUERRINJ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MCUERRINJ_APPL_CODE
# undef RTE_START_SEC_MCUERRINJ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTAGCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTAGCORRLN_APPL_CODE
# undef RTE_START_SEC_MOTAGCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTCTRLPRMESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTCTRLPRMESTIMN_APPL_CODE
# undef RTE_START_SEC_MOTCTRLPRMESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTCURRPEAKESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTCURRPEAKESTIMN_APPL_CODE
# undef RTE_START_SEC_MOTCURRPEAKESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTCURRREGCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTCURRREGCFG_APPL_CODE
# undef RTE_START_SEC_MOTCURRREGCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTQUADDETN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTQUADDETN_APPL_CODE
# undef RTE_START_SEC_MOTQUADDETN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTREFMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTREFMDL_APPL_CODE
# undef RTE_START_SEC_MOTREFMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTTQCALCD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTTQCALCD_APPL_CODE
# undef RTE_START_SEC_MOTTQCALCD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTTQCMDSCA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTTQCMDSCA_APPL_CODE
# undef RTE_START_SEC_MOTTQCMDSCA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTTQTRANLDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTTQTRANLDAMPG_APPL_CODE
# undef RTE_START_SEC_MOTTQTRANLDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MOTVELCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MOTVELCTRL_APPL_CODE
# undef RTE_START_SEC_MOTVELCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NVM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NVM_APPL_CODE
# undef RTE_START_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NVMPROXY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NVMPROXY_APPL_CODE
# undef RTE_START_SEC_NVMPROXY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NXTRCALIDS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NXTRCALIDS_APPL_CODE
# undef RTE_START_SEC_NXTRCALIDS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NXTRMATH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NXTRMATH_APPL_CODE
# undef RTE_START_SEC_NXTRMATH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NXTRSWIDS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NXTRSWIDS_APPL_CODE
# undef RTE_START_SEC_NXTRSWIDS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OMC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OMC_APPL_CODE
# undef RTE_START_SEC_OMC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PHADISCNCT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PHADISCNCT_APPL_CODE
# undef RTE_START_SEC_PHADISCNCT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POLARITYCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POLARITYCFG_APPL_CODE
# undef RTE_START_SEC_POLARITYCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POSNTRAKGSERVO_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POSNTRAKGSERVO_APPL_CODE
# undef RTE_START_SEC_POSNTRAKGSERVO_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PROGMFGSRV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PROGMFGSRV_APPL_CODE
# undef RTE_START_SEC_PROGMFGSRV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PULLCMPACTV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PULLCMPACTV_APPL_CODE
# undef RTE_START_SEC_PULLCMPACTV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PWRDISCNCT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PWRDISCNCT_APPL_CODE
# undef RTE_START_SEC_PWRDISCNCT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PWRLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PWRLIMR_APPL_CODE
# undef RTE_START_SEC_PWRLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PWRSPLY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PWRSPLY_APPL_CODE
# undef RTE_START_SEC_PWRSPLY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PWRUPSEQ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PWRUPSEQ_APPL_CODE
# undef RTE_START_SEC_PWRUPSEQ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_RMH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_RMH_APPL_CODE
# undef RTE_START_SEC_RMH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_RMH_CDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_RMH_CDD_APPL_CODE
# undef RTE_START_SEC_RMH_CDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_RVSBATTPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_RVSBATTPROTN_APPL_CODE
# undef RTE_START_SEC_RVSBATTPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SHTDWNMECH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SHTDWNMECH_APPL_CODE
# undef RTE_START_SEC_SHTDWNMECH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_STOUTPCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_STOUTPCTRL_APPL_CODE
# undef RTE_START_SEC_STOUTPCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_STDDIAG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_STDDIAG_APPL_CODE
# undef RTE_START_SEC_STDDIAG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_STEERCMDARBNANDLIM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_STEERCMDARBNANDLIM_APPL_CODE
# undef RTE_START_SEC_STEERCMDARBNANDLIM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_STM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_STM_APPL_CODE
# undef RTE_START_SEC_STM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SWP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SWP_APPL_CODE
# undef RTE_START_SEC_SWP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SYSFRICLRNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SYSFRICLRNG_APPL_CODE
# undef RTE_START_SEC_SYSFRICLRNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SYSKINEANDEFF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SYSKINEANDEFF_APPL_CODE
# undef RTE_START_SEC_SYSKINEANDEFF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SYSSTMOD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SYSSTMOD_APPL_CODE
# undef RTE_START_SEC_SYSSTMOD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SYSTIME_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SYSTIME_APPL_CODE
# undef RTE_START_SEC_SYSTIME_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TESTIMN_APPL_CODE
# undef RTE_START_SEC_TESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TMPLMONR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TMPLMONR_APPL_CODE
# undef RTE_START_SEC_TMPLMONR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TQOSCN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TQOSCN_APPL_CODE
# undef RTE_START_SEC_TQOSCN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TUNSELNAUTHY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TUNSELNAUTHY_APPL_CODE
# undef RTE_START_SEC_TUNSELNAUTHY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TUNSELNMNGT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TUNSELNMNGT_APPL_CODE
# undef RTE_START_SEC_TUNSELNMNGT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TURNCNTRCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TURNCNTRCORRLN_APPL_CODE
# undef RTE_START_SEC_TURNCNTRCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VEHSIGCDNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VEHSIGCDNG_APPL_CODE
# undef RTE_START_SEC_VEHSIGCDNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VEHSPDLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VEHSPDLIMR_APPL_CODE
# undef RTE_START_SEC_VEHSPDLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VIN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VIN_APPL_CODE
# undef RTE_START_SEC_VIN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WDGM_APPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WDGM_APPL10_APPL_CODE
# undef RTE_START_SEC_WDGM_APPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WDGM_APPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WDGM_APPL7_APPL_CODE
# undef RTE_START_SEC_WDGM_APPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WDGM_APPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WDGM_APPL8_APPL_CODE
# undef RTE_START_SEC_WDGM_APPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WDGM_APPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WDGM_APPL9_APPL_CODE
# undef RTE_START_SEC_WDGM_APPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN01ININ01GROUPA_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN01ININ01GROUPC_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN01ININ01GROUPD_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN01ININ01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN01ININOPTSETA01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN02RT01GROUPA_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN02RT01GROUPC_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN02RT01GROUPD_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE
# undef RTE_STOP_SEC_AAACALREGN02RT01_DUMMY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BACCOMIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BACCOMIF_APPL_CODE
# undef RTE_STOP_SEC_BACCOMIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BATTVLTG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BATTVLTG_APPL_CODE
# undef RTE_STOP_SEC_BATTVLTG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BATTVLTGCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BATTVLTGCORRLN_APPL_CODE
# undef RTE_STOP_SEC_BATTVLTGCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
# undef RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWDRVGDYNSTMAC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWDRVGDYNSTMAC_APPL_CODE
# undef RTE_STOP_SEC_BMWDRVGDYNSTMAC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWFLTHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWFLTHNDLG_APPL_CODE
# undef RTE_STOP_SEC_BMWFLTHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWHAPTCFB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWHAPTCFB_APPL_CODE
# undef RTE_STOP_SEC_BMWHAPTCFB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
# undef RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWHWTQOVRLARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWHWTQOVRLARBN_APPL_CODE
# undef RTE_STOP_SEC_BMWHWTQOVRLARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMOTTQOVRLARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMOTTQOVRLARBN_APPL_CODE
# undef RTE_STOP_SEC_BMWMOTTQOVRLARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT276BAS4REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT315BAS0REPN1BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT56BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE
# undef RTE_STOP_SEC_BMWMSGSLOT68BAS1REPN2BUSFRCHA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWPWRPRKGDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWPWRPRKGDAMPG_APPL_CODE
# undef RTE_STOP_SEC_BMWPWRPRKGDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWSPLYCURRLIM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWSPLYCURRLIM_APPL_CODE
# undef RTE_STOP_SEC_BMWSPLYCURRLIM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWSTREQMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWSTREQMGR_APPL_CODE
# undef RTE_STOP_SEC_BMWSTREQMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWSWFCTDI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWSWFCTDI_APPL_CODE
# undef RTE_STOP_SEC_BMWSWFCTDI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE
# undef RTE_STOP_SEC_BMWTQOVRLCDNGANDDRVGDYNFAC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE
# undef RTE_STOP_SEC_BMWTRFCJAMASSIDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE
# undef RTE_STOP_SEC_BMWTUNSETHNDLR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BMWVEHSPD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BMWVEHSPD_APPL_CODE
# undef RTE_STOP_SEC_BMWVEHSPD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BSWM_APPL_CODE
# undef RTE_STOP_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_ADC0CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_ADC0CFGANDUSE_APPL_CODE
# undef RTE_STOP_SEC_CDD_ADC0CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
# undef RTE_STOP_SEC_CDD_ADC1CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_ADCDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_ADCDIAGC_APPL_CODE
# undef RTE_STOP_SEC_CDD_ADCDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_BATTRTNCURR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_BATTRTNCURR_APPL_CODE
# undef RTE_STOP_SEC_CDD_BATTRTNCURR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_BMW5441MCUCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_BMW5441MCUCFG_APPL_CODE
# undef RTE_STOP_SEC_CDD_BMW5441MCUCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CHKPTAPPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CHKPTAPPL10_APPL_CODE
# undef RTE_STOP_SEC_CDD_CHKPTAPPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CHKPTAPPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CHKPTAPPL7_APPL_CODE
# undef RTE_STOP_SEC_CDD_CHKPTAPPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CHKPTAPPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CHKPTAPPL8_APPL_CODE
# undef RTE_STOP_SEC_CDD_CHKPTAPPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CHKPTAPPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CHKPTAPPL9_APPL_CODE
# undef RTE_STOP_SEC_CDD_CHKPTAPPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_COREVLTGMONR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_COREVLTGMONR_APPL_CODE
# undef RTE_STOP_SEC_CDD_COREVLTGMONR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CURRMEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CURRMEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_CURRMEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_CURRMEASARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_CURRMEASARBN_APPL_CODE
# undef RTE_STOP_SEC_CDD_CURRMEASARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_DATAANDADRPAR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_DATAANDADRPAR_APPL_CODE
# undef RTE_STOP_SEC_CDD_DATAANDADRPAR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE
# undef RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE
# undef RTE_STOP_SEC_CDD_ECMOUTPANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_EXCPNHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_EXCPNHNDLG_APPL_CODE
# undef RTE_STOP_SEC_CDD_EXCPNHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_FLSMEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_FLSMEM_APPL_CODE
# undef RTE_STOP_SEC_CDD_FLSMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE
# undef RTE_STOP_SEC_CDD_GUARDCFGANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_HWTQ4MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_HWTQ4MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_HWTQ4MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_HWTQ5MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_HWTQ5MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_HWTQ5MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE
# undef RTE_STOP_SEC_CDD_MCUCORECFGANDDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MCUDIAGC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MCUDIAGC_APPL_CODE
# undef RTE_STOP_SEC_CDD_MCUDIAGC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTAG0MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTAG0MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTAG0MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTAG1MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTAG1MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTAG1MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTAG3MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTAG3MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTAG3MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTAG4MEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTAG4MEAS_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTAG4MEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTAGCMP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTAGCMP_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTAGCMP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTCTRLMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTCTRLMGR_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTCTRLMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTCURRREGVLTGLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_MOTVEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_MOTVEL_APPL_CODE
# undef RTE_STOP_SEC_CDD_MOTVEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_NVMPROXY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_NVMPROXY_APPL_CODE
# undef RTE_STOP_SEC_CDD_NVMPROXY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
# undef RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_RAMMEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_RAMMEM_APPL_CODE
# undef RTE_STOP_SEC_CDD_RAMMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_SINVLTGGENN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_SINVLTGGENN_APPL_CODE
# undef RTE_STOP_SEC_CDD_SINVLTGGENN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_SYNCCRC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_SYNCCRC_APPL_CODE
# undef RTE_STOP_SEC_CDD_SYNCCRC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_TSG31CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_TSG31CFGANDUSE_APPL_CODE
# undef RTE_STOP_SEC_CDD_TSG31CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE
# undef RTE_STOP_SEC_CDD_TAUJ0CFGANDUSE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_VRFYCRITREG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_VRFYCRITREG_APPL_CODE
# undef RTE_STOP_SEC_CDD_VRFYCRITREG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_XCPIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_XCPIF_APPL_CODE
# undef RTE_STOP_SEC_CDD_XCPIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE
# undef RTE_STOP_SEC_CDD_XCPIFXCPEVE2MILLISECDATAACQN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CLSDLOOPDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CLSDLOOPDAMPG_APPL_CODE
# undef RTE_STOP_SEC_CLSDLOOPDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CLSDLOOPHYS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CLSDLOOPHYS_APPL_CODE
# undef RTE_STOP_SEC_CLSDLOOPHYS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CMNMFGSRV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CMNMFGSRV_APPL_CODE
# undef RTE_STOP_SEC_CMNMFGSRV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CMNMFGSRVIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CMNMFGSRVIF_APPL_CODE
# undef RTE_STOP_SEC_CMNMFGSRVIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CMPLNCERR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CMPLNCERR_APPL_CODE
# undef RTE_STOP_SEC_CMPLNCERR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CODING_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CODING_APPL_CODE
# undef RTE_STOP_SEC_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMM_APPL_CODE
# undef RTE_STOP_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CTRLDVELRTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CTRLDVELRTN_APPL_CODE
# undef RTE_STOP_SEC_CTRLDVELRTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CURRMEASCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CURRMEASCORRLN_APPL_CODE
# undef RTE_STOP_SEC_CURRMEASCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DARH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DARH_APPL_CODE
# undef RTE_STOP_SEC_DARH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DCM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DCM_APPL_CODE
# undef RTE_STOP_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
# undef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
# undef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
# undef RTE_STOP_SEC_DEMWRAPPER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DET_APPL_CODE
# undef RTE_STOP_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGR_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIAGCMGRSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIAGCMGRSTUB_APPL_CODE
# undef RTE_STOP_SEC_DIAGCMGRSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DLOG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DLOG_APPL_CODE
# undef RTE_STOP_SEC_DLOG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DUTYCYCTHERMPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DUTYCYCTHERMPROTN_APPL_CODE
# undef RTE_STOP_SEC_DUTYCYCTHERMPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ECUM_APPL_CODE
# undef RTE_STOP_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ECUTMEAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ECUTMEAS_APPL_CODE
# undef RTE_STOP_SEC_ECUTMEAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_EFFORT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_EFFORT_APPL_CODE
# undef RTE_STOP_SEC_EFFORT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ELECPWRCNS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ELECPWRCNS_APPL_CODE
# undef RTE_STOP_SEC_ELECPWRCNS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_EOTPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_EOTPROTN_APPL_CODE
# undef RTE_STOP_SEC_EOTPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_EPSSTESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_EPSSTESTIMN_APPL_CODE
# undef RTE_STOP_SEC_EPSSTESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_FALBCKASSI_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_FALBCKASSI_APPL_CODE
# undef RTE_STOP_SEC_FALBCKASSI_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_FLTINJ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_FLTINJ_APPL_CODE
# undef RTE_STOP_SEC_FLTINJ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_GATEDRV0CTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_GATEDRV0CTRL_APPL_CODE
# undef RTE_STOP_SEC_GATEDRV0CTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_GLBLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_GLBLIMR_APPL_CODE
# undef RTE_STOP_SEC_GLBLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HILOADSTALLLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HILOADSTALLLIMR_APPL_CODE
# undef RTE_STOP_SEC_HILOADSTALLLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HWREFTQSUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HWREFTQSUM_APPL_CODE
# undef RTE_STOP_SEC_HWREFTQSUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HWTQARBN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HWTQARBN_APPL_CODE
# undef RTE_STOP_SEC_HWTQARBN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HWTQCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HWTQCORRLN_APPL_CODE
# undef RTE_STOP_SEC_HWTQCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HWTQTRAKGCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HWTQTRAKGCTRL_APPL_CODE
# undef RTE_STOP_SEC_HWTQTRAKGCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_INERTIACMPVEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_INERTIACMPVEL_APPL_CODE
# undef RTE_STOP_SEC_INERTIACMPVEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_IOHWAB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_IOHWAB_APPL_CODE
# undef RTE_STOP_SEC_IOHWAB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LIMRCDNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LIMRCDNG_APPL_CODE
# undef RTE_STOP_SEC_LIMRCDNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LOAMGR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LOAMGR_APPL_CODE
# undef RTE_STOP_SEC_LOAMGR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LRNPINIONCENTR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LRNPINIONCENTR_APPL_CODE
# undef RTE_STOP_SEC_LRNPINIONCENTR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE
# undef RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MCALERRHNDLG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MCALERRHNDLG_APPL_CODE
# undef RTE_STOP_SEC_MCALERRHNDLG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MCUERRINJ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MCUERRINJ_APPL_CODE
# undef RTE_STOP_SEC_MCUERRINJ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTAGCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTAGCORRLN_APPL_CODE
# undef RTE_STOP_SEC_MOTAGCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTCTRLPRMESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTCTRLPRMESTIMN_APPL_CODE
# undef RTE_STOP_SEC_MOTCTRLPRMESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTCURRPEAKESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTCURRPEAKESTIMN_APPL_CODE
# undef RTE_STOP_SEC_MOTCURRPEAKESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTCURRREGCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTCURRREGCFG_APPL_CODE
# undef RTE_STOP_SEC_MOTCURRREGCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTQUADDETN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTQUADDETN_APPL_CODE
# undef RTE_STOP_SEC_MOTQUADDETN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTREFMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTREFMDL_APPL_CODE
# undef RTE_STOP_SEC_MOTREFMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTTQCALCD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTTQCALCD_APPL_CODE
# undef RTE_STOP_SEC_MOTTQCALCD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTTQCMDSCA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTTQCMDSCA_APPL_CODE
# undef RTE_STOP_SEC_MOTTQCMDSCA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTTQTRANLDAMPG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTTQTRANLDAMPG_APPL_CODE
# undef RTE_STOP_SEC_MOTTQTRANLDAMPG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MOTVELCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MOTVELCTRL_APPL_CODE
# undef RTE_STOP_SEC_MOTVELCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NVM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NVM_APPL_CODE
# undef RTE_STOP_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NVMPROXY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NVMPROXY_APPL_CODE
# undef RTE_STOP_SEC_NVMPROXY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NXTRCALIDS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NXTRCALIDS_APPL_CODE
# undef RTE_STOP_SEC_NXTRCALIDS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NXTRMATH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NXTRMATH_APPL_CODE
# undef RTE_STOP_SEC_NXTRMATH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NXTRSWIDS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NXTRSWIDS_APPL_CODE
# undef RTE_STOP_SEC_NXTRSWIDS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OMC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OMC_APPL_CODE
# undef RTE_STOP_SEC_OMC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PHADISCNCT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PHADISCNCT_APPL_CODE
# undef RTE_STOP_SEC_PHADISCNCT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POLARITYCFG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POLARITYCFG_APPL_CODE
# undef RTE_STOP_SEC_POLARITYCFG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POSNTRAKGSERVO_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POSNTRAKGSERVO_APPL_CODE
# undef RTE_STOP_SEC_POSNTRAKGSERVO_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PROGMFGSRV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PROGMFGSRV_APPL_CODE
# undef RTE_STOP_SEC_PROGMFGSRV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PULLCMPACTV_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PULLCMPACTV_APPL_CODE
# undef RTE_STOP_SEC_PULLCMPACTV_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PWRDISCNCT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PWRDISCNCT_APPL_CODE
# undef RTE_STOP_SEC_PWRDISCNCT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PWRLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PWRLIMR_APPL_CODE
# undef RTE_STOP_SEC_PWRLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PWRSPLY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PWRSPLY_APPL_CODE
# undef RTE_STOP_SEC_PWRSPLY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PWRUPSEQ_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PWRUPSEQ_APPL_CODE
# undef RTE_STOP_SEC_PWRUPSEQ_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_RMH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_RMH_APPL_CODE
# undef RTE_STOP_SEC_RMH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_RMH_CDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_RMH_CDD_APPL_CODE
# undef RTE_STOP_SEC_RMH_CDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_RVSBATTPROTN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_RVSBATTPROTN_APPL_CODE
# undef RTE_STOP_SEC_RVSBATTPROTN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SHTDWNMECH_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SHTDWNMECH_APPL_CODE
# undef RTE_STOP_SEC_SHTDWNMECH_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_STOUTPCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_STOUTPCTRL_APPL_CODE
# undef RTE_STOP_SEC_STOUTPCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_STDDIAG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_STDDIAG_APPL_CODE
# undef RTE_STOP_SEC_STDDIAG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_STEERCMDARBNANDLIM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_STEERCMDARBNANDLIM_APPL_CODE
# undef RTE_STOP_SEC_STEERCMDARBNANDLIM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_STM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_STM_APPL_CODE
# undef RTE_STOP_SEC_STM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SWP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SWP_APPL_CODE
# undef RTE_STOP_SEC_SWP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SYSFRICLRNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SYSFRICLRNG_APPL_CODE
# undef RTE_STOP_SEC_SYSFRICLRNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SYSKINEANDEFF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SYSKINEANDEFF_APPL_CODE
# undef RTE_STOP_SEC_SYSKINEANDEFF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SYSSTMOD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SYSSTMOD_APPL_CODE
# undef RTE_STOP_SEC_SYSSTMOD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SYSTIME_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SYSTIME_APPL_CODE
# undef RTE_STOP_SEC_SYSTIME_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TESTIMN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TESTIMN_APPL_CODE
# undef RTE_STOP_SEC_TESTIMN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TMPLMONR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TMPLMONR_APPL_CODE
# undef RTE_STOP_SEC_TMPLMONR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TQOSCN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TQOSCN_APPL_CODE
# undef RTE_STOP_SEC_TQOSCN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TUNSELNAUTHY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TUNSELNAUTHY_APPL_CODE
# undef RTE_STOP_SEC_TUNSELNAUTHY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TUNSELNMNGT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TUNSELNMNGT_APPL_CODE
# undef RTE_STOP_SEC_TUNSELNMNGT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TURNCNTRCORRLN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TURNCNTRCORRLN_APPL_CODE
# undef RTE_STOP_SEC_TURNCNTRCORRLN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VEHSIGCDNG_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VEHSIGCDNG_APPL_CODE
# undef RTE_STOP_SEC_VEHSIGCDNG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VEHSPDLIMR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VEHSPDLIMR_APPL_CODE
# undef RTE_STOP_SEC_VEHSPDLIMR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VIN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VIN_APPL_CODE
# undef RTE_STOP_SEC_VIN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WDGM_APPL10_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WDGM_APPL10_APPL_CODE
# undef RTE_STOP_SEC_WDGM_APPL10_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WDGM_APPL7_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WDGM_APPL7_APPL_CODE
# undef RTE_STOP_SEC_WDGM_APPL7_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WDGM_APPL8_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WDGM_APPL8_APPL_CODE
# undef RTE_STOP_SEC_WDGM_APPL8_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WDGM_APPL9_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WDGM_APPL9_APPL_CODE
# undef RTE_STOP_SEC_WDGM_APPL9_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * OS Application specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl10_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl10_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl10_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl10_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl10_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl10_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl7_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl7_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl7_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl7_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl7_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl7_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl8_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl8_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl8_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl8_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl8_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl8_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl9_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl9_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl9_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl9_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl9_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl9_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl10_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl10_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl10_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl10_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl10_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl10_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl10_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl7_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl7_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl7_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl7_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl7_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl7_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl7_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl8_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl8_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl8_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl8_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl8_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl8_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl8_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl9_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl9_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl9_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl9_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl9_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl9_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl9_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Calibration Parameter specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# undef RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    /* NXTR PATCH START
     * The following code was patched from the generated file to support calibration personalities*/
	#define Rte_CalprmRom_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01")))  Rte_CalprmRom_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP )   
	#define Rte_CalprmRom_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP)	
	
	#define Rte_CalprmRom_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP)
	
	#define Rte_CalprmRom_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP)
	
	#define Rte_CalprmRom_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP)
	
	#define Rte_CalprmRom_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP)

	#define Rte_CalprmRom_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP)
	
	#define Rte_CalprmRom_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP)
	#define Rte_CalprmRom_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP (__attribute__((section(".CalRegn01"))) Rte_CalprmRom_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP)
	

    #undef MEMMAP_ERROR
	/* NXTR PATCH END */
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# undef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    /* NXTR PATCH START
     * The following code was patched from the generated file to support calibration personalities*/
	#undef Rte_CalprmRom_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP     
	#undef Rte_CalprmRom_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP
	#undef Rte_CalprmRom_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP

	#undef MEMMAP_ERROR
    /* NXTR PATCH END */
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
# undef RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
# undef RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl7_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
# undef RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl8_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
# undef RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_Appl9_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl10_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl7_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl8_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_Appl9_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!        << Start of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OS_MEMMAP_INCLUDE
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0883:  MISRA rule: 19.15
     Reason:     AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                 select appropriate #pragma directives.
     Risk:       MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                 the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
